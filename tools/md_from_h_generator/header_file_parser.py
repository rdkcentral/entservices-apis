#!/usr/bin/env python3

# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:

# Copyright 2024 RDK Management

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# header_file_parser.py

import re
import os
from logger import Logger

class HeaderFileParser:
    """
    Parses a C++ header file to extract methods, properties, events, structs, enums, and iterators.
    It also generates request and response JSONs for each method and event, and fills in missing
    symbol information.
    """
    # List of regexes to match different components of the header file
    REGEX_LINE_LIST = [
        ('text',    'doxygen', re.compile(r'(?:\/\*+|\*|//) (?:@text|@alt)\s+(.*?)(?=\s*\*\/|$)')),
        ('brief',   'doxygen', re.compile(r'(?:\/\*+|\*|//) @brief\s*(.*?)(?=\s*\*\/|$)')),
        ('details', 'doxygen', re.compile(r'(?:\/\*+|\*|//) @details\s*(.*?)(?=\s*\*\/|$)')),
        ('params',  'doxygen', re.compile(r'(?:\/\*+|\*|//) @param(?:\[.*\])?\s+(\w+)\s*\:?\s*(.*?)(?=\s*\*\/|$)')),
        ('return',  'doxygen', re.compile(r'(?:\/\*+|\*|//) @return(?:s)?\s*(.*?)(?=\s*\*\/|$)')),
        ('see',     'doxygen', re.compile(r'(?:\/\*+|\*|//) @see\s*(.*?)(?=\s*\*\/|$)')),
        ('omit',    'doxygen', re.compile(r'(?:\/\*+|\*|//)\s*(@json:omit|@omit)')),
        ('property','doxygen', re.compile(r'(?:\/\*+|\*|//) @property\s*(.*)')),
        ('comment', 'doxygen', re.compile(r'(?:\/\*+|\*|//)\s*(.*)')),
        ('enum',    'cpp_obj', re.compile(r'enum\s+([\w\d]+)\s*(?:\:\s*([\w\d\:\*]*))?\s*\{?')),
        ('struct',  'cpp_obj', re.compile(r'struct\s+(EXTERNAL\s+)?([\w\d]+)\s*(?:\{)?(?!.*:)')),
        ('method',  'cpp_obj', re.compile(r'virtual\s+([\w\d\:]+)\s+([\w\d\:]+)\s*\((.*)')),
        ('iterator','cpp_obj', re.compile(r'(.*)\s+RPC::IIteratorType\s*(.*)'))
    ]
    # Basic type examples for generating missing symbol examples
    BASIC_TYPE_EXAMPLES = {
        'int32_t': 'int',
        'uint32_t': 'int',
        'int64_t': 'int',
        'uint64_t': 'int',
        'int': 'int',
        'float': 'float',
        'double': 'float',
        'bool': 'boolean',
        'char': 'string',
        'string': 'string'
    }

    # Smart defaults based on very generic parameter names for better examples
    # Only includes the most generic parameter names - fallback to type-based examples otherwise
    PARAMETER_NAME_EXAMPLES = {
        # Generic identifiers
        'id': {
            'string': '"12345"',
            'number': 42,
            'default': 42
        },

        # Names and labels
        'name': {
            'string': '"example"',
            'default': '"example"'
        },

        # URLs and paths
        'url': {
            'string': '"https://example.com"',
            'default': '"https://example.com"'
        },
        'path': {
            'string': '"/path/to/file"',
            'default': '"/path/to/file"'
        },

        # Status and state
        'status': {
            'boolean': True,
            'string': '"active"',
            'default': True
        },
        'state': {
            'string': '"enabled"',
            'boolean': True,
            'default': '"enabled"'
        },

        # Configuration
        'type': {
            'string': '"standard"',
            'default': '"standard"'
        },
        'mode': {
            'string': '"auto"',
            'default': '"auto"'
        },

        # Generic values
        'value': {
            'string': '"sample"',
            'number': 100,
            'boolean': True,
            'default': '"sample"'
        },
        'key': {
            'string': '"key"',
            'default': '"key"'
        },

        # Boolean states
        'enabled': {
            'boolean': True,
            'default': True
        },
        'success': {
            'boolean': True,
            'default': True
        },
        'visible': {
            'boolean': True,
            'default': True
        },

        # Common numeric values
        'port': {
            'number': 8080,
            'string': '"8080"',
            'default': 8080
        },
        'timeout': {
            'number': 5000,
            'string': '"5000"',
            'default': 5000
        },
        'count': {
            'number': 10,
            'string': '"10"',
            'default': 10
        },
        'size': {
            'number': 1024,
            'string': '"1024"',
            'default': 1024
        },
        'index': {
            'number': 0,
            'string': '"0"',
            'default': 0
        }
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

        Args:
            header_file_path (str): path to the header file
            logger (Logger): list of regex matching different components of the header file
        """
        # objects to hold the different components and properties of the header file
        self.header_file_path = header_file_path
        self.classname = os.path.splitext(os.path.basename(self.header_file_path))[0]
        # Derive plugin name by removing 'I' prefix from interface name for JSON-RPC calls
        self.plugin_name = self.classname[1:] if self.classname.startswith('I') else self.classname
        self.request_id_counter = 0  # Counter for generating unique request IDs
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
        self.methods = self.sort_dict(self.methods)
        self.properties = self.sort_dict(self.properties)
        self.events = self.sort_dict(self.events)
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
        method_parens_count = 0
        method_object = ''

        scope = ['Exchange']
        brace_count = [1]

        with open(self.header_file_path, 'r', encoding='utf-8') as header_file:
            line_num = 0
            for line in header_file:
                line_num += 1
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
                    line, enum_object, within_enum_def, enum_braces_count, line_num)
                if within_struct_def:
                    struct_object, struct_braces_count, within_struct_def = self.process_struct(
                    line, struct_object, within_struct_def, struct_braces_count, line_num)
                if within_method_def:
                    method_object, method_parens_count, within_method_def = self.process_method(
                    line, method_object, within_method_def, method_parens_count, line_num, scope)

    def match_line_with_regex(self, line, line_regex_list):
        """
        Matches a line with a regex from the line_regex_list.
        """
        for (tag, l_type, regex) in line_regex_list:
            match = regex.match(line)
            if match:
                return match.groups(), tag, l_type
        return None, None, None

    def process_method(self, line, method_object, within_method_def, method_paren_count,
                       curr_line_num, scope):
        """
        Processes a line within a method definition.
        """
        method_paren_count += self.count_parentheses(line)
        # accumulate the method's parameters until the closing parenthesis is reached
        if method_paren_count != 0:
            line = self.clean_and_validate_cpp_obj_line(line, ',', curr_line_num, 'Method param')
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

    def process_struct(self, line, struct_object, within_struct_def, struct_braces_count,
                       curr_line_num):
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
        delim_index = line.find(delimiter)
        # if a comment is defined after the delimiter, log a warning
        if delim_index != -1 and ('//' in line[delim_index:] or '/*' in line[delim_index:]):
            line = self.remove_inline_comments(line)
            self.logger.log("WARNING",
                            f"Comment on line {line_num + 1} should come before comma/semicolon.")
        # if the delimiter is found more than once, log a warning
        if line.count(delimiter) > 1:
            line = self.remove_inline_comments(line)
            self.logger.log("WARNING",
                            f"Line {line_num + 1} should have only one {data_type} per line.")
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
            enum_name, _, enum_body = match.groups()
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
        Helper to build a method info object. Also registers method parameters in the symbol
        registry.
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
        Processes method parameters, cleans descriptions, and uses @text as the JSON key if present.
        Returns (params, results) lists.
        """
        params = []
        results = []
        # Split parameters by comma, handle empty
        param_list = [p.strip() for p in method_parameters.split(',') if p.strip()]
        for param in param_list:
            # Try to extract type and name
            match = re.match(r'(?:const\s+)?([\w:]+)\s*[&*]?\s*(\w+)', param)
            if not match:
                continue
            param_type, param_name = match.groups()
            doxy_desc = doxy_tag_param_info.get(param_name, '')
            # Look for @text override in param or doxy
            text_match = re.search(r'@text:([\w-]+)', param)
            if not text_match and doxy_desc:
                text_match = re.search(r'@text:([\w-]+)', doxy_desc)
            json_key = text_match.group(1) if text_match else param_name
            # Clean description
            description = self.clean_param_description(doxy_desc)
            # Determine direction (in/out) from param or doxy
            direction = 'in'
            if '@out' in param or '- out -' in doxy_desc:
                direction = 'out'
            # Register symbol
            self.register_symbol(param_name, param_type, description)
            param_info = {
                'name': json_key,
                'type': param_type,
                'description': description,
                'orig_name': param_name  # Store original C++ name for registry lookups
            }
            if direction == 'out':
                results.append(param_info)
            else:
                params.append(param_info)
        return params, results

    def clean_param_description(self, description):
        """
        Remove '- in -', '- out -', and type info from param description, leaving only the real description.
        Handles extra spaces and formatting.
        """
        if not description:
            return ''
        # Remove leading '- in - type', '- out - type', etc. (robust to extra spaces)
        desc = re.sub(r'^-\s*(in|out|inout)\s*-\s*\w+\s*', '', description, flags=re.IGNORECASE)
        # Remove any remaining '- in -', '- out -', etc. (robust to extra spaces)
        desc = re.sub(r'-\s*(in|out|inout)\s*-', '', desc, flags=re.IGNORECASE)
        # Remove leading type info if present (e.g., 'int ', 'bool ', etc.)
        desc = re.sub(r'^(int|bool|boolean|float|double|string|uint32_t|int32_t|uint64_t|int64_t)\s*', '', desc, flags=re.IGNORECASE)
        return desc.strip()

    def fill_and_log_missing_symbol_descriptions(self):
        """
        Fills missing symbol information for methods, events, and properties.
        """
        for method_name, method_info in self.methods.items():
            for param in method_info['params']:
                orig = param.get('orig_name', param['name'])
                key = f"{orig}-{param['type']}"
                if not param.get('description'):
                    param['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in method {method_name}")
            for result in method_info['results']:
                orig = result.get('orig_name', result['name'])
                key = f"{orig}-{result['type']}"
                if not result.get('description'):
                    result['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in method {method_name}")
        for event_name, event_info in self.events.items():
            for param in event_info['params']:
                orig = param.get('orig_name', param['name'])
                key = f"{orig}-{param['type']}"
                if not param.get('description'):
                    param['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in event {event_name}")
            for result in event_info['results']:
                orig = result.get('orig_name', result['name'])
                key = f"{orig}-{result['type']}"
                if not result.get('description'):
                    result['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in event {event_name}")
        for prop_name, prop_info in self.properties.items():
            for param in prop_info['params']:
                orig = param.get('orig_name', param['name'])
                key = f"{orig}-{param['type']}"
                if not param.get('description'):
                    param['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {param['name']} in property {prop_name}")
            for result in prop_info['results']:
                orig = result.get('orig_name', result['name'])
                key = f"{orig}-{result['type']}"
                if not result.get('description'):
                    result['description'] = self.symbols_registry.get(key, {}).get('description', '')
                    self.logger.log("INFO", f"Filled missing desc for {result['name']} in property {prop_name}")

    def log_missing_method_info(self):
        """
        At the end of parsing, if there is still information missing for methods, events, and
        symbols, log it.
        """
        for method_name, method_info in self.methods.items():
            if not method_info.get('brief') and not method_info.get('details'):
                self.logger.log("INFO", f"Missing description: {method_name}")
        for event_name, event_info in self.events.items():
            if not event_info.get('brief') and not event_info.get('details'):
                self.logger.log("INFO", f"Missing description: {event_name}")
        for prop_name, prop_info in self.properties.items():
            if not prop_info.get('brief') and not prop_info.get('details'):
                self.logger.log("INFO", f"Missing description: {prop_name}")
        for symbol_name, symbol_info in self.symbols_registry.items():
            if not symbol_info.get('description'):
                self.logger.log("INFO", f"Missing description: {symbol_name}")
            if symbol_info.get('example') == "":
                self.logger.log("INFO", f"Missing example: {symbol_name}")

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
        for symbol_name, symbol_info in self.symbols_registry.items():
            symbol_info['flattened_description'] = self.get_description_from_individual_symbol('', symbol_name)

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
                flattened_descriptions.update(
                    self.flatten_description(curr_key, member_type))
            return flattened_descriptions
        elif symbol_type in self.enums_registry:
            if parent_key[-3:] == '[#]':
                flattened_descriptions.update(
                    {parent_key: {'type': 'string', 'description': ''}})
            return flattened_descriptions
        elif symbol_type in self.BASIC_TYPE_EXAMPLES:
            if parent_key[-3:] == '[#]':
                flattened_descriptions.update(
                    {parent_key: {'type': symbol_type, 'description': ''}})
            return flattened_descriptions
        elif symbol_type in self.iterators_registry:
            underlying_type = self.iterators_registry[symbol_type]
            flattened_descriptions.update(
                self.flatten_description(f"{parent_key}[#]", underlying_type))
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

    def external_struct_tracker(self, line, scope, brace_count):
        """
        Tracks the current C++ scope and brace count for struct/class parsing.
        """
        # Entering a new struct/class scope
        struct_match = re.match(r'(struct|class)\s+(\w+)', line)
        if struct_match:
            scope.append(struct_match.group(2))
            brace_count.append(0)
        # Update brace count for current scope
        if '{' in line:
            brace_count[-1] += line.count('{')
        if '}' in line:
            brace_count[-1] -= line.count('}')
            # Exiting a scope if braces are balanced
            if brace_count[-1] <= 0 and len(scope) > 1:
                scope.pop()
                brace_count.pop()
        return scope, brace_count

    def register_symbol(self, symbol_name, symbol_type, description):
        """
        Registers a symbol by adding it to the symbols registry if not already present.
        """
        unique_id = f"{symbol_name}-{symbol_type}"
        if unique_id not in self.symbols_registry:
            self.symbols_registry[unique_id] = {'type': symbol_type, 'description': description.strip() if description else ''}
        else:
            # Only update description if not already set
            if not self.symbols_registry[unique_id].get('description') and description:
                self.symbols_registry[unique_id]['description'] = description.strip()

    def link_method_to_event(self):
        """
        Associates methods with events (notifications) based on @see tags in Doxygen comments.
        Adds 'triggers' to methods and 'triggered_by' to events for documentation cross-referencing.
        """
        # Map event names to the methods that reference them
        event_to_methods = {event: [] for event in self.events}
        for method_name, method_info in self.methods.items():
            # 'events' is a dict of event names from @see tags
            referenced_events = method_info.get('events', {})
            for event_name in referenced_events:
                if event_name in self.events:
                    # Add event reference to method
                    method_info.setdefault('triggers', []).append(event_name)
                    # Add method reference to event
                    event_to_methods[event_name].append(method_name)
        # Update each event with the list of methods that trigger it
        for event_name, method_list in event_to_methods.items():
            if method_list:
                self.events[event_name].setdefault('triggered_by', []).extend(method_list)

    def generate_missing_examples_for_symbol_registry(self):
        """
        Fills in example values for all symbols in the registry, using name-based or type-based logic.
        """
        for symbol_name, symbol_info in self.symbols_registry.items():
            # Skip if already has an example
            if 'example' in symbol_info and symbol_info['example']:
                continue
            # Prefer name-based example if available and generic
            name = symbol_name.split('-')[0]
            typ = symbol_info['type']
            example = None
            # Use PARAMETER_NAME_EXAMPLES if name is generic
            if name in self.PARAMETER_NAME_EXAMPLES:
                exmap = self.PARAMETER_NAME_EXAMPLES[name]
                if typ in self.BASIC_TYPE_EXAMPLES:
                    type_key = self.BASIC_TYPE_EXAMPLES[typ]
                    example = exmap.get(type_key, exmap.get('default'))
                else:
                    example = exmap.get('default')
            # Fallback to type-based example
            if example is None and typ in self.BASIC_TYPE_EXAMPLES:
                type_key = self.BASIC_TYPE_EXAMPLES[typ]
                if type_key == 'int':
                    example = 42
                elif type_key == 'float':
                    example = 3.14
                elif type_key == 'boolean':
                    example = True
                elif type_key == 'string':
                    example = '"example"'
            # Fallback to empty string
            if example is None:
                example = ''
            symbol_info['example'] = example

    def generate_request_response_objects(self):
        """
        Generates example request and response objects for each method, property, and event.
        Uses parameter/result info and example values from the symbol registry.
        """
        def build_example_obj(param_list):
            obj = {}
            for param in param_list:
                key = param['name']
                orig = param.get('orig_name', key)
                typ = param['type']
                example = self.symbols_registry.get(f"{orig}-{typ}", {}).get('example', None)
                obj[key] = example
            return obj

        for method in list(self.methods.values()) + list(self.properties.values()) + list(self.events.values()):
            # Example request: all 'params' (inputs)
            method['example_request'] = build_example_obj(method.get('params', []))
            # Example response: all 'results' (outputs)
            method['example_response'] = build_example_obj(method.get('results', []))

    def log_unassociated_events(self):
        """
        Logs events that are not referenced by any method (not cross-linked via @see).
        """
        for event_name, event_info in self.events.items():
            if not event_info.get('triggered_by'):
                self.logger.log("INFO", f"Event '{event_name}' is not referenced by any method (@see).")
