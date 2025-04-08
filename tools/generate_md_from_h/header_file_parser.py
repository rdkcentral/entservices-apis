# header_file_parser.py

import re
import os
from logger import Logger

class HeaderFileParser:
    # List of regexes to match different components of the header file
    REGEX_LINE_LIST = [
        ('text',     'doxygen', re.compile(r'(?:\/\*+|\*|//) (?:@text|@alt)\s+(.*?)(?=\s*\*\/|$)')),
        ('brief',    'doxygen', re.compile(r'(?:\/\*+|\*|//) @brief\s*(.*?)(?=\s*\*\/|$)')),
        ('details',  'doxygen', re.compile(r'(?:\/\*+|\*|//) @details\s*(.*?)(?=\s*\*\/|$)')),
        ('params',   'doxygen', re.compile(r'(?:\/\*+|\*|//) @param(?:\[.*\])?\s+(\w+)\s*\:?\s*(.*?)(?=\s*\*\/|$)')),
        ('return',   'doxygen', re.compile(r'(?:\/\*+|\*|//) @returns\s*(.*?)(?=\s*\*\/|$)')),
        ('see',      'doxygen', re.compile(r'(?:\/\*+|\*|//) @see\s*(.*?)(?=\s*\*\/|$)')),
        ('omit',     'doxygen', re.compile(r'(?:\/\*+|\*|//)\s*(@json:omit|@omit)')),
        ('property', 'doxygen', re.compile(r'(?:\/\*+|\*|//) @property\s*(.*)')), 
        ('comment',  'doxygen', re.compile(r'(?:\/\*+|\*|//)\s*(.*)')),
        ('enum',     'cpp_obj', re.compile(r'enum\s+([\w\d]+)\s*(?:\:\s*([\w\d\:\*]*))?\s*\{?')),
        ('struct',   'cpp_obj', re.compile(r'struct\s+(EXTERNAL\s+)?([\w\d]+)\s*(?:\{)?(?!.*:)')),
        ('method',   'cpp_obj', re.compile(r'virtual\s+([\w\d\:]+)\s+([\w\d\:]+)\s*\((.*)')),
        ('iterator', 'cpp_obj', re.compile(r'(.*)\s+RPC::IIteratorType\s*(.*)'))
    ]
    # Basic type examples for generating missing symbol examples
    BASIC_TYPE_EXAMPLES = {
            'int32_t': '0', 
            'uint32_t': '0', 
            'int64_t': '0', 
            'uint64_t': '0',
            'int': '0',
            'float': '0.0', 
            'double': '0.0', 
            'bool': 'true', 
            'char': 'a', 
            'string': ''
    }
    # List of regexes to match different cpp components of the header file
    CPP_COMPONENT_REGEX = {
        'iter_using':   re.compile(r'using\s+([\w\d]+)\s*=\s*RPC::IIteratorType\s*\<\s*([\w\d\:]+)\s*\,\s*(?:[\w\d\:]+)\s*\>\s*;'),
        'iter_typedef': re.compile(r'typedef\s+RPC::IIteratorType\s*\<\s*([\w\d\:]+)\s*\,\s*(?:[\w\d\:]+)\s*\>\s*([\w\d]+)\s*;'),
        'enum': re.compile(r'enum\s+([\w\d]+)\s*(?:\:\s*([\w\d\:\*]*))?\s*\{(.*)\}\;?'),
        'enum_mem': re.compile(r'([\w\d\[\]]+)\s*(?:\=\s*([\w\d]+))?\s*(?:(?:(?:\/\*)|(?:\/\/))(.*)(?:\*\/)?)?'),
        'struct': re.compile(r'struct\s+(?:EXTERNAL\s+)?([\w\d]+)\s*\{(.*)\}\;?'),
        'struct_mem': re.compile(r'([\w\d\:\*]+)\s+([\w\d\[\]]+)\s*(?:(?:(?:\/\*)|(?:\/\/))(.*)(?:\*\/)?)?'),
        'method': re.compile(r'virtual\s+([\w\d\:]+)\s+([\w\d\:]+)\s*\((.*)\)\s*(?:(?:(?:const\s*)?\=\s*0)|(?:{\s*})\s*)\;?'),
        'method_param': re.compile(r'([\w\d\:\*]+)\s+([\w\d\[\]]+)\s*(?:\/\*(.*)\*\/)?')
    }

    def __init__(self, header_file_path: str, logger: Logger):
        """
        Initializes data structures to track different components of a C++ header file, then 
        parses said header file to extract methods, structs, enums, and iterators.

        Parameters: 
            header_file_path (str): path to the header file
            logger (Logger): list of regex matching different components of the header file
        """
        # objects to hold the different components and properties of the header file
        self.header_file_path = header_file_path
        self.classname = os.path.splitext(os.path.basename(self.header_file_path))[0]
        self.methods = {}
        self.properties = {}
        self.events = {}
        self.structs_registry = {}
        self.iterators_registry = {}
        self.enums_registry = {}
        self.symbols_registry = {}
        self.logger = logger

        # helper objects for holding doxygen tag information while parsing
        self.doxy_tags = {}
        self.latest_param = ''
        self.latest_tag = ''

        # main logic to create header file structure
        self.process_header_file()
        self.post_process()


    def process_header_file(self):
        """
        Processes the header file by parsing it, sorting methods/properties/events alphabetically,
        and linking methods to events.
        """
        self.parse_header_file()
        # self.methods = self.sort_dict(self.methods)
        # self.properties = self.sort_dict(self.properties)
        # self.events = self.sort_dict(self.events)
        self.link_method_to_event()


    def post_process(self):
        """
        Post-processes the header file structure by generating missing symbol examples, request &
        response examples, and logging which information is missing from the headerfile.
        """
        self.generate_missing_examples_for_symbol_registry()
        self.generate_flattened_descriptions_for_symbol_registry()
        self.generate_request_response_objects()
        self.fill_and_log_missing_symbol_descriptions()
        self.log_unassociated_events()
        self.log_missing_method_info()

    def parse_header_file(self):
        """
        Parses the header file line-by-line to track and record the file's components, such as 
        methods, properties, events, structs, enums, and iterators. Keeps track of these components'
        associated doxygen tags.
        """
        # flags and structures to help track the current state of the parser
        within_enum_def = False
        enum_braces_count = 0
        enum_object = ''
        within_struct_def = False
        struct_braces_count = 0
        struct_object = ''
        within_method_def = False
        method_parenthesis_count = 0
        method_object = ''

        scope = ['Exchange']
        brace_count = [1]

        with open(self.header_file_path, 'r') as header_file:
            line_number = 0
            for line in header_file:
                line_number += 1
                line = line.strip()
                # keeps track of the current scope (the nested/external struct) of the current line
                scope, brace_count = self.external_struct_tracker(line, scope, brace_count)
                groups, line_tag, line_type = self.match_line_with_regex(line, self.REGEX_LINE_LIST)

                if line_type == 'doxygen':
                    self.update_doxy_tags(groups, line_tag)
                if line_type == 'cpp_obj':
                    if line_tag == 'enum':   
                        within_enum_def = True
                    elif line_tag == 'struct':
                        within_struct_def = True
                    elif line_tag == 'method':
                         within_method_def = True
                    elif line_tag == 'iterator':
                        self.register_iterator(line)

                if within_enum_def:
                    enum_object, enum_braces_count, within_enum_def = self.process_enum(
                    line, enum_object, within_enum_def, enum_braces_count, line_number)
                if within_struct_def:
                    struct_object, struct_braces_count, within_struct_def = self.process_struct(
                    line, struct_object, within_struct_def, struct_braces_count, line_number)
                if within_method_def:
                    method_object, method_parenthesis_count, within_method_def = self.process_method(
                    line, method_object, within_method_def, method_parenthesis_count, line_number, scope)

    def match_line_with_regex(self, line, line_regex_list):
        """
        Matches a line with a regex from the line_regex_list.
        """
        for (tag, l_type, regex) in line_regex_list:
            match = regex.match(line)
            if match:
                return match.groups(), tag, l_type
        return None, None, None
        
    def process_method(self, line, method_object, within_method_def, method_paren_count, curr_line_num, scope):
        """
        Processes a line within a method definition.
        """
        method_paren_count += self.count_parentheses(line)
        # accumulate the method's parameters until the closing parenthesis is reached
        if method_paren_count != 0:
            line = self.clean_and_validate_cpp_obj_line(line, ',', curr_line_num, 'Method parameter')
            method_object += line
        elif method_paren_count == 0:
            method_object += line
            self.register_method(method_object, self.doxy_tags, scope)
            # reset the method object and doxygen tag helper objects once the method is registered
            within_method_def = False
            method_object = ''
            self.doxy_tags = {}
            self.latest_param = ''
            self.latest_tag = ''
        return method_object, method_paren_count, within_method_def
    
    def process_enum(self, line, enum_object, within_enum_def, enum_braces_count, curr_line_num):
        """
        Processes a line within an enum definition.
        """
        enum_braces_count += self.count_braces(line)
        if 'enum' in line and enum_braces_count == 0:
            return line, 0, within_enum_def
        # accumulate the enum's data members until the closing brace is reached
        if enum_braces_count > 0:
            line = self.clean_and_validate_cpp_obj_line(line, ',', curr_line_num, 'Enumerator')
            enum_object += line
        elif enum_braces_count <= 0:
            enum_object += line
            self.register_enum(enum_object)
            # reset the enum helper object once the enum is registered
            within_enum_def = False
            enum_object = ''
        return enum_object, enum_braces_count, within_enum_def
    
    def process_struct(self, line, struct_object, within_struct_def, struct_braces_count, curr_line_num):
        """
        Processes a line within a struct definition.
        """
        struct_braces_count += self.count_braces(line)
        if 'struct' in line and struct_braces_count == 0:
            return line, 0, within_struct_def
        # accumulate the struct's data members until the closing brace is reached
        if struct_braces_count > 0:
            line = self.clean_and_validate_cpp_obj_line(line, ';', curr_line_num, 'Struct member')
            struct_object += line
        elif struct_braces_count <= 0:
            struct_object += line
            self.register_struct(struct_object)
            # reset the struct helper object once the struct is registered
            within_struct_def = False
            struct_object = ''
        return struct_object, struct_braces_count, within_struct_def

    def update_doxy_tags(self, groups, line_tag):
        """
        Updates the doxygen tag object with the given line's information. 
        """
        if line_tag == 'text':
            # self.doxy_tags = {}
            self.doxy_tags['text'] = groups[0]
        elif line_tag == 'params':
            self.latest_param = groups[0]
            self.latest_tag = 'params'
            self.doxy_tags.setdefault('params', {})[self.latest_param] = groups[1]
        elif line_tag == 'see':
            self.doxy_tags.setdefault('see', {})[groups[0]] = ''
        elif line_tag == 'comment':
            if groups[0] == '/':
                return
            elif self.latest_tag == 'params':
                self.doxy_tags['params'][self.latest_param] += (' ' + groups[0])
            elif self.latest_tag:
                self.doxy_tags[self.latest_tag] += (' ' + groups[0])
            line_tag = self.latest_tag
        else:
            self.doxy_tags[line_tag] = groups[0]
        self.latest_tag = line_tag

    def clean_and_validate_cpp_obj_line(self, line, delimiter, line_num, data_type):
        """
        Validates a line of a multi-line cpp object by checking that data members are defined on 
        separate lines and that comments are formed before the delimiter.
        """
        delimiter_index = line.find(delimiter)
        # if a comment is defined after the delimiter, log a warning
        if delimiter_index != -1 and ('//' in line[delimiter_index:] or '/*' in line[delimiter_index:]):
            line = self.remove_inline_comments(line)
            self.logger.log("WARNING", f"Comment on line {line_num + 1} should come before comma/semicolon.")
        # if the delimiter is found more than once, log a warning
        if line.count(delimiter) > 1:
            line = self.remove_inline_comments(line)
            self.logger.log("WARNING", f"Line {line_num + 1} should have only one {data_type} per line.")
        return line
    
    def remove_inline_comments(self, line):
        """
        Removes inline comments from a line.
        """
        line = re.sub(r"/\*.*?\*/", "", line)
        line = re.sub(r"//.*", "", line)
        return line.strip()

    def register_iterator(self, iterator_object):
        """
        Registers an iterator.
        """
        match_typedef = self.CPP_COMPONENT_REGEX['iter_typedef'].match(iterator_object)
        match_using = self.CPP_COMPONENT_REGEX['iter_using'].match(iterator_object)

        if iterator_object == "RPC::IStringIterator":
            self.iterators_registry[iterator_object] = 'string'
        elif match_typedef:
            groups = match_typedef.groups()
            iterator_name = groups[1]
            self.iterators_registry[iterator_name] = groups[0]
        elif match_using:
            groups = match_using.groups()
            iterator_name = groups[0]
            self.iterators_registry[iterator_name] = groups[1]
        else:
            self.logger.log("ERROR", f"Could not register iterator: {iterator_object}")

    def register_enum(self, enum_object):
        """
        Registers an enum by processing the enum's enumerator definitions.
        """
        match = self.CPP_COMPONENT_REGEX['enum'].match(enum_object)
        if match:
            enum_name, enum_type, enum_body = match.groups()
            self.enums_registry[enum_name] = {}
            # process each enumerator definition
            for enumerator_def in enum_body.split(','):
                enumerator_def = enumerator_def.strip()
                enumerator_match = self.CPP_COMPONENT_REGEX['enum_mem'].match(enumerator_def)
                if enumerator_match:
                    enumerator_name, enumerator_value, description = enumerator_match.groups()
                    description = self.clean_description(description)
                    enumerator_value = enumerator_value or len(self.enums_registry[enum_name])
                    self.enums_registry[enum_name][enumerator_name] = {
                        'value': enumerator_value, 
                        'description': description.strip() if description else ''
                    }
        else:
            self.logger.log("ERROR", f"Could not register enum: {enum_object}")

    def register_struct(self, struct_object):
        """
        Registers a struct by processing the struct's data members.
        """
        match = self.CPP_COMPONENT_REGEX['struct'].match(struct_object) 
        if match:
            struct_name, struct_body = match.groups()
            self.structs_registry[struct_name] = {}
            # process each data member
            for member_def in struct_body.split(';'):
                member_def = member_def.strip()
                member_match = self.CPP_COMPONENT_REGEX['struct_mem'].match(member_def)
                if member_match:
                    member_type, member_name, description = member_match.groups()
                    description = self.clean_description(description)
                    self.structs_registry[struct_name][member_name] = {
                        'type': member_type, 
                        'description': description.strip() if description else ''
                    }
                    # register each data member in the global symbol registry
                    self.register_symbol(member_name, member_type, description)
        else:
            self.logger.log("ERROR", f"Could not register struct: {struct_object}")

    def register_method(self, method_object, doxy_tags, scope):
        """
        Registers a method, property, or event.
        """
        if doxy_tags == {}:
            self.logger.log("WARNING",f"{method_object} has no doxygen tags.")
        match = self.CPP_COMPONENT_REGEX['method'].match(method_object)
        if match:
            method_return_type, method_name, method_parameters = match.groups()
            # ignore these methods
            if method_name in ['Register', 'Unregister'] or 'omit' in doxy_tags:
                return
            # encountering the getter/setter version definition of a property
            if method_name in self.properties:
                self.properties[method_name]['property'] = 'read write'
                return
            
            method_info = self.build_method_info(method_return_type, method_parameters, doxy_tags)
            if 'property' in doxy_tags:
                self.properties[method_name] = method_info
            elif scope[-1] == 'INotification':
                self.events[method_name] = method_info
            else:
                self.methods[method_name] = method_info
        else:
            self.logger.log("ERROR", f"Could not register method: {method_object}")

    def build_method_info(self, method_return_type, method_parameters, doxy_tags):
        """
        Helper to build a method info object. Also registers method parameters in the symbol registry.
        """
        doxy_tag_param_info = doxy_tags.get('params', {})
        params, results = self.process_and_register_params(method_parameters, doxy_tag_param_info)
        method_info = {
            'text': doxy_tags.get('text', ''), 
            'brief': doxy_tags.get('brief', ''), 
            'details': doxy_tags.get('details', ''),
            'events': doxy_tags.get('see', {}),
            'params': params,
            'results': results,
            'return_type': method_return_type
        }
        if 'property' in doxy_tags:
            if 'const' in method_parameters or '@in' in method_parameters:
                method_info['property'] = 'write'
            else:
                method_info['property'] = 'read'
        return method_info
    
    def process_and_register_params(self, method_parameters, doxy_tag_param_info):
        """
        Helper to build params and results data structures, using the parameter declaration list and 
        doxygen tags.
        """
        param_list_info = self.get_info_from_param_declaration(method_parameters)
        params = []
        results = []
        # build the params and results lists using the parameter delcaration list and doxygen tags
        for symbol_name, (symbol_type, symbol_inline_comment) in param_list_info.items():
            # register string iterators here b/c they are seldom defined outside of a method parameter list
            if symbol_type == 'RPC::IStringIterator':
                self.register_iterator(symbol_type)
            symbol_description = doxy_tag_param_info.get(symbol_name, '')
            self.register_symbol(symbol_name, symbol_type, symbol_description)
            symbol_info = {
                'name': symbol_name,
                'type': symbol_type,
                'description': symbol_description
            }
            # determine whether the symbol is a result or a parameter
            if symbol_inline_comment and '@inout' in symbol_inline_comment:
                params.append(symbol_info)
                results.append(symbol_info)
            elif symbol_inline_comment and '@out' in symbol_inline_comment:
                results.append(symbol_info)
            else:  # Includes '@in', other, or empty
                params.append(symbol_info)
        return params, results

    def get_info_from_param_declaration(self, parameters):
        """
        Helper to extract parameter information from a parameter list string.
        """
        parameters = parameters.strip('()')
        param_info = {}
        for param in parameters.split(','):
            # clean up the parameter string
            param = param.strip().replace('&', '').replace('const ', '')
            param = re.sub(r'(?<!\/)\*(?!\/)', '', param)
            # check if the cleaned parameter string matches the expected format
            match = self.CPP_COMPONENT_REGEX['method_param'].match(param)
            if match:
                param_type, param_name, param_inline_comment = match.groups()
                param_info[param_name] = (param_type, param_inline_comment)
            else:
                self.logger.log("ERROR", f"Could not extract parameter information from: {param}")
        return param_info
    
    def register_symbol(self, symbol_name, symbol_type, description):
        """
        Registers a symbol by incrementally adding information to the symbols registry, as 
        information is discovered while parsing.
        """
        unique_id = f"{symbol_name}-{symbol_type}"
        if unique_id not in self.symbols_registry:
            self.symbols_registry[unique_id] = {'type': symbol_type}
        if not self.symbols_registry[unique_id].get('description'):
            self.symbols_registry[unique_id]['description'] = description.strip() if description else ''
        if not self.symbols_registry[unique_id].get('example') and symbol_type not in self.iterators_registry:
            self.symbols_registry[unique_id]['example'] = self.generate_example_from_description(description)

    def external_struct_tracker(self, line, scope, brace_count):
        """
        Tracks the current scope of the line being processed.
        """
        external_struct_tracker_regex = re.compile(r'struct\s+EXTERNAL\s+([\w\d]+).*\{?')
        external_struct_tracker_match = external_struct_tracker_regex.match(line)
        # if this line contains the declaration of an external structure, update it as the scope
        if external_struct_tracker_match:
            scope.append(external_struct_tracker_match.group(1))
            brace_count.append(0)
            brace_count[-1] += self.count_braces(line)
        else:
            brace_count[-1] += self.count_braces(line)
            # keep track of braces to determine the end of the current scope
            while brace_count and brace_count[-1] <= 0:
                if brace_count[-1] < 0 and len(brace_count) > 1:
                    brace_count[-2] += brace_count[-1]
                scope.pop()
                brace_count.pop()
        return scope, brace_count
    
    def generate_request_response_objects(self):
        """
        Generates request and response JSONs for each method and event. Directly modifies the methods,
        properties, and events registries.
        """
        for method in self.methods:
            method_info = self.methods[method]
            method_info['request'] = self.generate_request_object(method, method_info)
            method_info['response'] = self.generate_response_object(method_info)
        for event in self.events:
            event_info = self.events[event]
            event_info['request'] = self.generate_request_object(event, event_info)
        for prop in self.properties:
            prop_info = self.properties[prop]
            # properties can have both get and set requests and responses
            if 'read' in prop_info['property']:
                if prop_info['params'] != []:
                    prop_info['results'] = prop_info['params']
                    prop_info['params'] = []
                prop_info['get_request'] = self.generate_request_object(prop, prop_info)
                prop_info['get_response'] = self.generate_response_object(prop_info)
            if 'write' in prop_info['property']:
                if prop_info['results'] != []:
                    prop_info['params'] = prop_info['results']
                    prop_info['results'] = []
                prop_info['set_request'] = self.generate_request_object(prop, prop_info)
                prop_info['set_response'] = self.generate_response_object(prop_info)

    def generate_request_object(self, method_name, method_info):
        """
        Makes a request JSON. Creates an example dynamically.
        """
        request = {
            "jsonrpc": "2.0",
            "id": 42,
            "method": f"org.rdk.{self.classname}.{method_name}",
        }
        if method_info['params'] != []:
            request["params"] = {}
            for param in method_info['params']:
                param_name = param.get('name')
                param_type = param.get('type')
                param_desc = param.get('description')
                request["params"][param_name] = self.get_symbol_example(f"{param_name}-{param_type}", param_desc)
        return request

    def generate_response_object(self, method_info):
        """
        Makes a response JSON. Creates an example dynamically.
        """
        response = {
            "jsonrpc": "2.0",
            "id": 42,
            "result": "null"
        }
        if method_info['results'] != []:
            response['result'] = {}
            for result in method_info['results']:
                result_name = result.get('name')
                result_type = result.get('type')
                result_desc = result.get('description')
                response['result'][result_name] = self.get_symbol_example(f"{result_name}-{result_type}", result_desc)
        return response
    
    def get_symbol_example(self, unique_id, description):
        """
        Used in generating request/response JSONs. Pulls an example from either the @param tag 
        description or the symbols registry.
        """
        example_from_description = self.generate_example_from_description(description)
        if example_from_description:
            return self.wrap_example_if_iterator(unique_id, example_from_description)
        if unique_id in self.symbols_registry:
            return self.symbols_registry[unique_id].get('example')
        return None
    
    def generate_missing_examples_for_symbol_registry(self):
        """
        Generate examples for symbols in the symbols registry that lack examples.
        """
        for unique_id, symbol_data in self.symbols_registry.items():
            if not symbol_data.get('example'):
                description = symbol_data.get('description')
                symbol_data['example'] = self.generate_example_for_individual_symbol(unique_id, description)
                self.logger.log("INFO", f"Generated missing example for {unique_id}")

    def generate_example_for_individual_symbol(self, unique_id, description):
        """
        Generate an example for an individual symbol based on its description or type.
        """
        example = self.generate_example_from_description(description)
        if example:
            return self.wrap_example_if_iterator(unique_id, example)
        if unique_id in self.symbols_registry:
            symbol_type = self.symbols_registry[unique_id]['type']
            return self.generate_example_from_symbol_type(symbol_type)
        return None
    
    def generate_example_from_description(self, param_description):
        """
        Extracts an example from a parameter description.
        """
        if param_description is None:
            return None
        match = re.search(r'e\.g\.\s*\"([^\"]+)', param_description) or re.search(r'ex:\s*(.*)', param_description)
        return match.group(1) if match else None

    def generate_example_from_symbol_type(self, symbol_type):
        """
        Creates an example parameter based on the symbol type
        """
        if symbol_type in self.structs_registry:
            struct = self.structs_registry[symbol_type]
            return {member_name: self.generate_example_for_individual_symbol(f"{member_name}-{struct[member_name]['type']}", struct[member_name]['description']) for member_name in struct}
        if symbol_type in self.enums_registry:
            return list(self.enums_registry[symbol_type])[0]
        if symbol_type in self.BASIC_TYPE_EXAMPLES:
            return self.BASIC_TYPE_EXAMPLES[symbol_type]
        if symbol_type in self.iterators_registry:
            underlying_type = self.iterators_registry[symbol_type]
            return [self.generate_example_from_symbol_type(underlying_type)]  
        return ''
    
    def wrap_example_if_iterator(self, unique_id, example):
        """
        Wrap the example in a list if the symbol is an iterator, otherwise simply return the example.
        """
        if self.symbols_registry[unique_id]['type'] in self.iterators_registry:
            return [example]
        return example
    
    def link_method_to_event(self):
        """
        Links methods to their associated events. Directly modifies the methods dictionary.
        """
        for method in self.methods:
            method_events = self.methods[method]['events']
            for event in method_events:
                if event in self.events:
                    self.methods[method]['events'][event] = self.events[event].get('brief')
                    self.events[event]['associated_method'] = method
                else:
                    self.logger.log("ERROR", f"Event {event} tagged with method {method} does not exist.")
    
    def log_unassociated_events(self):
        """
        Logs events that are not associated with any method.
        """
        for event in self.events:
            if not self.events[event].get('associated_method'):
                self.logger.log("WARNING", f"Event {event} is not associated with any method.")
    
    def fill_and_log_missing_symbol_descriptions(self):
        """
        Fills missing symbol information for methods, events, and properties.
        """
        for method in self.methods:
            method_info = self.methods[method]
            for param in method_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in method {method}")
            for result in method_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in method {method}")
        for event in self.events:
            event_info = self.events[event]
            for param in event_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in event {event}")
            for result in event_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in event {event}")
        for property in self.properties:
            prop_info = self.properties[property]
            for param in prop_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in property {property}")
            for result in prop_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in property {property}")
        
    def log_missing_method_info(self):
        """
        At the end of parsing, if there is still information missing for methods, events, and symbols,
        log it. 
        """
        for method in self.methods:
            method_info = self.methods[method]
            if not method_info.get('brief') and not method_info.get('details'):
                self.logger.log("INFO", f"Missing description: {method}")
        for event in self.events:
            event_info = self.events[event]
            if not event_info.get('brief') and not event_info.get('details'):
                self.logger.log("INFO", f"Missing description: {event}")
        for property in self.properties:
            property_info = self.properties[property]
            if not property_info.get('brief') and not property_info.get('details'):
                self.logger.log("INFO", f"Missing description: {property}")
        for symbol in self.symbols_registry:
            if not self.symbols_registry[symbol].get('description'):
                self.logger.log("INFO", f"Missing description: {symbol}")
            if self.symbols_registry[symbol].get('example') == "":
                self.logger.log("INFO", f"Missing example: {symbol}")

    def count_parentheses(self, line):
        """
        Counts the number of opening and closing parentheses in a line.
        """
        return line.count('(') - line.count(')')

    def count_braces(self, line):
        """
        Counts the number of opening and closing braces in a line.
        """
        return line.count('{') - line.count('}')
    
    def sort_dict(self, dictionary):
        """
        Sorts a dictionary by its keys and returns a new dictionary.
        """
        return dict(sorted(dictionary.items()))

    def generate_flattened_descriptions_for_symbol_registry(self):
        """
        Builds flattened descriptions for all symbols in the symbols registry.
        """
        for symbol in self.symbols_registry:
            self.symbols_registry[symbol]['flattened_description'] = self.get_description_from_individual_symbol('', symbol)
    
    def get_description_from_individual_symbol(self, parent_key, unqiue_id):
        """
        Used to flatten descriptions for params/results/values in the symbol registry.
        """
        if unqiue_id in self.symbols_registry:
            symbol_name = unqiue_id.split('-')[0]
            symbol_type = self.symbols_registry[unqiue_id]['type']
            symbol_desc = self.symbols_registry[unqiue_id]['description']
            curr_key = f"{parent_key}.{symbol_name}"
            flattened_descriptions = {curr_key: {'type': symbol_type, 'description': symbol_desc}}
            flattened_descriptions.update(self.flatten_description(curr_key, symbol_type))
            return flattened_descriptions
        return {}

    def flatten_description(self, parent_key, symbol_type):
        """
        Mirrors logic in generate_example_from_symbol_type.
        """
        flattened_descriptions = {}
        if symbol_type in self.structs_registry:
            struct = self.structs_registry[symbol_type]
            for member_name in struct:
                member_type = struct[member_name]['type']
                member_desc = struct[member_name]['description']
                curr_key = f"{parent_key}.{member_name}"
                flattened_descriptions[curr_key] = {'type': member_type, 'description': member_desc}
                flattened_descriptions.update(self.flatten_description(curr_key, member_type))
            return flattened_descriptions
        elif symbol_type in self.enums_registry:
            if parent_key[-3:] == '[#]':
                flattened_descriptions.update({parent_key: {'type': 'string', 'description': ''}})
            return flattened_descriptions
        elif symbol_type in self.BASIC_TYPE_EXAMPLES:
            if parent_key[-3:] == '[#]':
                flattened_descriptions.update({parent_key: {'type': symbol_type, 'description': ''}})
            return flattened_descriptions
        elif symbol_type in self.iterators_registry:
            underlying_type = self.iterators_registry[symbol_type]
            flattened_descriptions.update(self.flatten_description(f"{parent_key}[#]", underlying_type))
            return flattened_descriptions
        return {}
    
    def clean_description(self, description):
        """
        Cleans a description by removing doxygen tag and unnecessary characters.
        """
        if description:
            description = description.strip()
            description = re.sub(r'^@\S+', '', description)
            description = description[:-2] if description.endswith("*/") else description
        return description