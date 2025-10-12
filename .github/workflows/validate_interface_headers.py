import os
import re
import glob

def load_ids(ids_file_path):
    with open(ids_file_path, 'r') as file:
        lines = file.readlines()
    return lines

def find_matching_brace(content, start_index):
    stack = []
    for i in range(start_index, len(content)):
        if content[i] == '{':
            stack.append('{')
        elif content[i] == '}':
            stack.pop()
            if not stack:
                return i
    return -1

def validate_header(file_path, issues, ids_lines):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    # Combine lines to form the content
    content = ''.join(lines)
    
    # Find all API and event declarations with preceding comments
    pattern = re.compile(r'((?:/\*[\s\S]*?\*/\s*|//.*\n\s*)?)\s*(virtual\s+)?(\w+)\s+(\w+)\s*\(([^)]*)\)\s*(?:=\s*0|{[^}]*})?;')
    declarations = pattern.findall(content)

    for declaration in declarations:
        comments, _, return_type, name, params = declaration
        
        # Check if name follows PascalCase convention, allowing underscores and numbers
        if not re.match(r'^[A-Z][a-zA-Z0-9_]*$', name):
            name_pattern = re.compile(r'\b' + re.escape(name) + r'\b')
            for i, line in enumerate(lines):
                if name_pattern.search(line):
                    issues.append(f"Line {i + 1}: API/Event Name in file '{file_path}' must follow PascalCase convention: '{name}'")
                    break
        
        # Check for annotations in the immediate preceding comment line
        if comments:
            annotation_match = re.search(r'@text (\w+)', comments)
            if annotation_match:
                annotation = annotation_match.group(1)
                # Convert both to lowercase for case-insensitive comparison
                annotation_lower = annotation.lower()
                expected_annotation = name[0].lower() + name[1:]
                # Check if the API/event name is a substring of the annotation or matches the full name
                if expected_annotation in annotation_lower or annotation_lower == expected_annotation:
                    # Check if annotation follows camelCase convention
                    if not re.match(r'^[a-z][a-zA-Z0-9_]*$', annotation):
                        annotation_pattern = re.compile(r'\b' + re.escape(annotation) + r'\b')
                        for i, line in enumerate(lines):
                            if annotation_pattern.search(line):
                                issues.append(f"Line {i + 1}: Annotation in file '{file_path}' must follow camelCase convention: '{annotation}'")
                                break
        
        # Validate parameter names if params are present
        if params:
            param_pattern = re.compile(r'(?:const\s+)?(?:[\w:]+)\s+(\w+)(?:\s*[\[\]\*&]*)[,)]')
            param_matches = param_pattern.findall(params)
            for param in param_matches:
                if not re.match(r'^[a-z][a-zA-Z0-9]*$', param):
                    param_pattern = re.compile(r'\b' + re.escape(param) + r'\b')
                    for i, line in enumerate(lines):
                        if param_pattern.search(line):
                            issues.append(f"Line {i + 1}: Parameter name of method '{name}' in file '{file_path}' must follow camelCase convention: '{param}'")
                            break
                    
    # Find all enum declarations
    enum_pattern = re.compile(r'enum\s+(class\s+)?(\w+)\s*(:\s*\w+)?\s*{\s*([^}]*)\s*}')
    enums = enum_pattern.findall(content)
    
    for enum in enums:
        enum_class, enum_name, _, enum_members = enum
        
        # Check if enum name follows PascalCase convention
        if enum_name and not re.match(r'^[A-Z][a-zA-Z0-9]*$', enum_name):
            enum_name_pattern = re.compile(r'\b' + re.escape(enum_name) + r'\b')
            for i, line in enumerate(lines):
                if enum_name_pattern.search(line):
                    issues.append(f"Line {i + 1}: Enum name in file '{file_path}' must follow PascalCase convention: '{enum_name}'")
                    break
        
        # Check if enum members follow ALL_UPPER_SNAKE_CASE convention
        members = enum_members.split(',')
        for member in members:
            member_name = member.strip().split()[0] if member.strip().split() else ""
            # Skip comment lines
            if member_name.startswith('//') or member_name.startswith('/*'):
                continue
            if member_name and not re.match(r'^[A-Z][A-Z0-9_]*$', member_name):
                member_name_pattern = re.compile(r'\b' + re.escape(member_name) + r'\b')
                for i, line in enumerate(lines):
                    if member_name_pattern.search(line):
                        issues.append(f"Line {i + 1}: Enum member in file '{file_path}' must follow ALL_UPPER_SNAKE_CASE convention: '{member_name}'")
                        break
    
    # Find all struct declarations
    struct_pattern = re.compile(r'struct\s+(EXTERNAL\s+)?(\w+)\s*(:\s*(public|private|protected)\s+[\w:]+)?\s*{')
    structs = struct_pattern.findall(content)
    
    for struct in structs:
        _, struct_name, inheritance, access_modifier = struct
        
        # Check if struct name follows PascalCase convention
        if not re.match(r'^[A-Z][a-zA-Z0-9]*$', struct_name):
            struct_name_pattern = re.compile(r'\b' + re.escape(struct_name) + r'\b')
            for i, line in enumerate(lines):
                if struct_name_pattern.search(line):
                    issues.append(f"Line {i + 1}: Struct name in file '{file_path}' does not follow PascalCase convention: '{struct_name}'")
                    break
        
        # Extract struct members
        struct_member_pattern = re.compile(r'struct\s+(EXTERNAL\s+)?' + struct_name + r'\s*(:\s*(public|private|protected)\s+[\w:]+)?\s*{([\s\S]*?)\s*};')
        struct_content = struct_member_pattern.search(content)
        if struct_content:
            struct_members = struct_content.group(4).split('\n')
            inside_multiline_comment = False
            inside_enum = False
            inside_virtual = False
            inside_inner_struct = False
            for member in struct_members:
                member = member.strip()
                if not member or member.isspace() or member == '{':
                    continue
                if member.startswith('/*'):
                    inside_multiline_comment = True
                if inside_multiline_comment:
                    if member.endswith('*/'):
                        inside_multiline_comment = False
                    continue
                if member == '*/':
                    inside_multiline_comment = False
                    continue
                if member.startswith('enum'):
                    inside_enum = True
                if inside_enum:
                    if member.endswith(';'):
                        inside_enum = False
                    continue
                if member.startswith('virtual'):
                    inside_virtual = True
                if inside_virtual:
                    if member.endswith(';'):
                        inside_virtual = False
                    continue
                if member.startswith('struct'):
                    inside_inner_struct = True
                if inside_inner_struct:
                    if member.endswith('};'):
                        inside_inner_struct = False
                    continue
                if member.startswith(('static', 'using', '~', 'template', '//')):
                    continue
                # Handle struct members with comments
                member_parts = member.split('/*')
                member_name = member_parts[0].split()[-1].rstrip(';')
                # Check if member name follows camelCase convention, including array brackets
                member_name_base = re.split(r'\[|\]', member_name)[0]
                if not re.match(r'^[a-z][a-zA-Z0-9]*$', member_name_base):
                    for i, line in enumerate(lines):
                        if member_name in line:
                            issues.append(f"Line {i + 1}: Struct member of struct '{struct_name}' in file '{file_path}' does not follow camelCase convention: '{member_name}'")
                            break
                    
    # Find the INotification interface declaration
    interface_pattern = re.compile(r'struct\s+(EXTERNAL\s+)?I\w*Notification\s*:\s*virtual\s+public\s+Core::IUnknown\s*')
    matches = interface_pattern.finditer(content)
    for match in matches:
        start_index = match.start()
        end_index = find_matching_brace(content, start_index) + 1
        interface_content = content[start_index:end_index]
        interface_lines = interface_content.split('\n')
        inside_enum = False
        for line_number, line in enumerate(interface_lines):
            if line.strip().startswith('};'):
                break
            # Skip validation for lines that start with enum or comments
            if line.strip().startswith('enum'):
                inside_enum = True
            if inside_enum:
                if line.strip().endswith(';'):
                    inside_enum = False
                continue
            if line.strip().startswith('//') or line.strip().startswith('/*') or line.strip().startswith('*') or line.strip() == '':
                continue
            # Validate method implementation
            method_pattern = re.compile(r'virtual\s+[\w:]+\s+\w+\s*\([^)]*\)\s*(const\s*)?\{\s*\}\s*;')
            pure_virtual_pattern = re.compile(r'virtual\s+[\w:]+\s+\w+\s*\([^)]*\)\s*(const\s*)?=\s*0\s*;')
            if line.strip().startswith('~'):
                continue
            if pure_virtual_pattern.search(line):
                issues.append(f"Line {line_number + 1}: Notification in file '{file_path}' SHALL not be a \"pure virtual function\" and must have empty default implementation: {line.strip()}")

    # Find all method declarations
    method_pattern = re.compile(r'virtual\s+([\w:]+)\s+\w+\s*\([^)]*\)\s*(const\s*)?\s*(\{\s*\}\s*;|=\s*0\s*;)')
    interface_ranges = []
    for match in interface_pattern.finditer(content):
        start_index = match.start()
        end_index = find_matching_brace(content, start_index) + 1
        interface_ranges.append((start_index, end_index))

    for i, line in enumerate(lines):
        is_inside_interface = False
        line_start = content.find(line)
        for start, end in interface_ranges:
            if start <= line_start < end:
                is_inside_interface = True
                break
        if is_inside_interface:
            continue

        for match in method_pattern.finditer(line):
            return_type = match.group(1)
            method_declaration = match.group(0)
            # Check if the return type is Core::hresult
            if return_type != 'Core::hresult':
                issues.append(f"Line {i + 1}: Method in file '{file_path}' SHALL return Core::hresult: {method_declaration.strip()}")

    # Find all enum declarations and extract the IDs
    id_enum_pattern = re.compile(r'enum\s*{\s*ID\s*=\s*(ID_[A-Z0-9_]+)\s*};')
    enums = id_enum_pattern.findall(content)
    
    for id_value in enums:
        id_value_pattern = re.compile(r'\b' + re.escape(id_value) + r'\b')
        if not any(id_value_pattern.search(line) for line in ids_lines):
            for i, line in enumerate(lines):
                if id_value_pattern.search(line):
                    issues.append(f"Line {i + 1}: An enum ID of file {os.path.basename(file_path)} has not been defined with offset in Ids.h file: {id_value}")
                    break
                    
    # Check for @in tag usage in method parameters
    in_tag_pattern = re.compile(r'/\*[^*]*@in[^*]*\*/')
    for i, line in enumerate(lines):
        if in_tag_pattern.search(line):
            issues.append(f"Line {i + 1}: Usage of @in tag is not allowed in file '{file_path}'. Method parameters are input by default: {line.strip()}")
    

def main():
    ids_file_path = 'apis/Ids.h'
    ids_lines = load_ids(ids_file_path)
    
    directories = glob.glob('apis/*')
    issues = []
    for directory in directories:
        for root, _, files in os.walk(directory):
            for file in files:
                if file.endswith('.h'):
                    file_path = os.path.join(root, file)
                    validate_header(file_path, issues, ids_lines)
    
    if issues:
        print("The following issues were found in the header files:")
        for issue in issues:
            print(issue)
        raise SystemExit("Validation failed")
    else:
        print("No issues found.")

if __name__ == "__main__":
    main()
