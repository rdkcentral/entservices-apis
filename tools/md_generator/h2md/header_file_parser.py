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
import json
from logger import Logger

class HeaderFileParser:
    """
    Parses a C++ header file to extract methods, properties, events, structs, enums, and iterators.
    It also generates request and response JSONs for each method and event, and fills in missing
    symbol information.
    """
    # List of regexes to match different components of the header file
    REGEX_LINE_LIST = [
        ('plugindesc', 'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@docs:plugindesc\s+(.*?)(?=\s*\*\/|$)')),
        ('config',      'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@docs:config\s*\|?\s*([\w\.\?]+)\s*\|\s*(\w+)\s*\|\s*(.*?)\|?(?=\s*\*\/|$)')),
        ('text',        'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*(?:@text|@alt)\s+(.*?)(?=\s*\*\/|$)')),
        ('brief',       'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@brief\s+(.*?)(?=\s*\*\/|$)')),
        ('details',     'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@details\s+(.*?)(?=\s*\*\/|$)')),
        ('params',      'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@param(\[\w+\])?\s+([^\s:(]+)(?:\(([^)]*)\))?\s*:?\s*(.*?)(?=\s*\*\/|$)')),
        ('errors',      'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@errors\s+(\w+)\s*\[(\d+?)\]\s+(.*?)?(?=\s*\*\/|$)')),
        ('return',      'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@return(?:s)?\s+(.*?)(?=\s+\*\/|$)')),
        ('see',         'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@see\s+(.*?)(?=\s*\*\/|$)')),
        ('omit',        'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*(@json:omit|@omit|@docs:omit)')),
        ('json',        'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*(@json)(?:\s+|$)([\d\.]+)?(?:.*)')),
        ('property',    'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@property\s*(.*)')),
        ('event',       'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*@event\s*(.*)')),
        ('comment',     'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*(.*)')),
        ('stubgenomit',  'doxygen', re.compile(r'(?:\/\*+|\*|\/\/)\s*(@stubgen:omit)')),
        ('enum',        'cpp_obj', re.compile(r'enum\s+(?:class\s)?([\w\d]+)\s*(?:\:\s*([\w\d\:\*]*))?\s*\{?')),
        ('struct',      'cpp_obj', re.compile(r'struct\s+(EXTERNAL\s+)?([\w\d]+)\s*(?:\{)?(?!.*:)')),
        ('method',      'cpp_obj', re.compile(r'virtual\s+([\w\d\:]+)\s+([\w\d\:]+)\s*\((.*)')),
        ('iterator',    'cpp_obj', re.compile(r'(.*)\s+RPC::IIteratorType\s*(.*)'))
        
    ]
    # Basic type examples for generating missing symbol examples
    BASIC_TYPE_EXAMPLES = {
        'integer':  '0',
        'int16_t':  '0',
        'uint16_t': '0',
        'int32_t':  '0',
        'uint32_t': '0',
        'int64_t':  '0',
        'uint64_t': '0',
        'int':      '0',
        'float':    '0.0',
        'double':   '0.0',
        'bool':     True,
        'char':     'a',
        'string':   ''
    }
    # List of regexes to match different cpp components of the header file
    CPP_COMPONENT_REGEX = {
        'iter_using':   re.compile(r'using\s+([\w\d]+)\s*=\s*RPC::IIteratorType\s*\<\s*([\w\d\:]+)\s*\,\s*(?:[\w\d\:]+)\s*\>\s*;'),
        'iter_typedef': re.compile(r'typedef\s+RPC::IIteratorType\s*\<\s*([\w\d\:]+)\s*\,\s*(?:[\w\d\:]+)\s*\>\s*([\w\d]+)\s*;'),
        'enum':         re.compile(r'enum\s+(?:class\s)?\s*([\w\d]+)\s*(?:\:\s*([\w\d\:\*]*))?\s*\{(.*)\}\;?'),
        'enum_mem':     re.compile(r'([\w\d\[\]]+)\s*(?:\=\s*([\w\d]+))?\s*(?:(?:(?:\/\*)|(?:\/\/))(.*)(?:\*\/)?)?'),
        'struct':       re.compile(r'struct\s+(?:EXTERNAL\s+)?([\w\d]+)\s*\{([\s\S]*?)\}\;?'),
        'struct_mem':   re.compile(r'([\w\d\:\*]+)\s+([\w\d\[\]]+)\;?\s*(?:(?:(?:\/\*)|(?:\/\/))(.*)(?:\*\/)?)?'),
        'method':       re.compile(r'virtual\s+([\w\d\:]+)\s+([\w\d\:]+)\s*\((.*)\)\s*(?:(?:(?:const\s*)?\=\s*0)|(?:{\s*})\s*)\;?'),
        'method_param': re.compile(r'([\w\d\:\*]+)\s+([\w\d\[\]]+)\s*(?:\/\*(.*)\*\/)?')
    }

    def __init__(self, header_file_path: str, plugin_name: str, logger: Logger):
        """
        Initializes data structures to track different components of a C++ header file, then
        parses said header file to extract methods, structs, enums, and iterators.

        Args:
            header_file_path (str): path to the header file
            plugin_name (str): name of the plugin, used to derive the classname
            logger (Logger): logger instance for logging warnings and errors
        """
        # objects to hold the different components and properties of the header file
        self.header_file_path = header_file_path
        # All the header files will begin with "I", strip it to get the classname.
        self.classname = plugin_name
        self.methods = {}
        self.properties = {}
        self.events = {}
        self.structs_registry = {}
        self.iterators_registry = {}
        self.enums_registry = {}
        self.symbols_registry = {}
        self.configuration_options = {}
        self.logger = logger
        self.notification_names = ['INotification']

        # helper objects for holding doxygen tag information while parsing
        self.doxy_tags = {}
        self.latest_param = ''
        self.latest_tag = ''
        self.in_event = False
        self.plugindescription = ''
        self.plugin_version = ''
        self.in_json_tag = False
        self.in_omit_tag = False

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

                if line_tag == None:
                    self.latest_tag = ''
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
            line = self.clean_and_validate_cpp_obj_line(line, '\n', curr_line_num, 'Struct member')
            struct_object += (line + '\n')
        elif struct_braces_count <= 0:
            struct_object += (line + '\n')
            self.register_struct(struct_object)
            # reset the struct helper object once the struct is registered
            within_struct_def = False
            struct_object = ''
        return struct_object, struct_braces_count, within_struct_def

    def update_doxy_tags(self, groups, line_tag):
        """
        Updates the doxygen tag object with the given line's information.
        Supports multiline for all tags by accumulating lines until a new tag is found.
        """
        if line_tag == 'plugindesc':
            self.plugindescription = groups[0]
            self.latest_tag = 'plugindesc'
        elif line_tag == 'version':
            self.plugin_version = groups[0]
            self.latest_tag = ''
        elif line_tag == 'event':
            self.in_event = True
            self.latest_tag = ''
        elif line_tag == 'json':
            self.in_json_tag = True
            if groups[1]:
                self.plugin_version = groups[1]
            self.latest_tag = ''
        elif line_tag == 'omit':
            self.doxy_tags['omit'] = 'omit'
            self.latest_tag = ''
        elif line_tag == 'config':
            type = groups[1]
            description = groups[2]
            self.configuration_options[groups[0]] = {'type': type, 'description': description}
            self.latest_tag = 'config'
        elif line_tag == 'text':
            self.doxy_tags['text'] = groups[0]
            self.latest_tag = ''
        elif line_tag == 'params':
            self.latest_param = groups[1]
            self.latest_tag = 'params'
            description = re.sub(r'\- in \-|\- out \-|\- in|\- out', '', groups[3])
            direction = groups[0]
            optionality = groups[2]
            self.doxy_tags.setdefault('params', {})[self.latest_param] = {'description': description, 
                                                                          'direction': direction, 
                                                                          'optionality': optionality}
        elif line_tag == 'see':
            self.doxy_tags.setdefault('see', {})[groups[0]] = ''
            self.latest_tag = 'see'
        elif line_tag == 'errors':
            error_code = groups[1]
            description = groups[2]
            self.doxy_tags.setdefault('errors', {})[groups[0]] = {'code': error_code,
                                                                  'description': description}
            self.latest_tag = 'errors'
        elif line_tag == 'comment':
            # if we encounter a comment that is not associated with a tag, skip it
            if self.latest_tag == '':
                return
            if groups[0] == '/':
                return
            # Multiline support: append to last tag
            if self.latest_tag == 'params':
                description = re.sub(r'\- in \-|\- out \-|\- in|\- out', '', groups[0])
                self.doxy_tags['params'][self.latest_param]['description'] += (' ' + description)
            elif self.latest_tag == 'plugindesc':
                self.plugindescription += (' ' + groups[0])
            elif self.latest_tag == 'config':
                # Multiline support for config description
                last_key = list(self.configuration_options.keys())[-1]
                self.configuration_options[last_key]['description'] += (' ' + groups[0])
            elif self.latest_tag and self.latest_tag in self.doxy_tags:
                self.doxy_tags[self.latest_tag] += (' ' + groups[0])
            line_tag = self.latest_tag
        else:
            self.doxy_tags[line_tag] = groups[0]
        self.latest_tag = line_tag
        # if line_tag != 'plugindesc':
        #     self.latest_tag = line_tag

    def clean_and_validate_cpp_obj_line(self, line, delimiter, line_num, data_type):
        """
        Validates a line of a multi-line cpp object by checking that data members are defined on
        separate lines and that comments are formed before the delimiter.
        """
        delim_index = line.find(delimiter)
        # if a comment is defined after the delimiter, log a warning
        if delim_index != -1 and ('//' in line[delim_index:] or '/*' in line[delim_index:]):
            line = self.remove_inline_comments(line)
            if self.logger:
                self.logger.log("WARNING",
                                f"Comment on line {line_num + 1} should come before comma/semicolon.")
        # if the delimiter is found more than once, log a warning
        if line.count(delimiter) > 1:
            line = self.remove_inline_comments(line)
            if self.logger:
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
            if self.logger:
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
            if self.logger:
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
            for member_def in struct_body.split('\n'):
                member_def = member_def.strip()
                member_match = self.CPP_COMPONENT_REGEX['struct_mem'].match(member_def)
                if member_match:
                    member_type, member_name, description = member_match.groups()
                    interger_regex_pattern = r'u?int(8|16|32|64)_t'
                    if re.match(interger_regex_pattern, member_type):
                        member_type = 'integer'
                    text_tag_pattern = r'@text\s+([^\*/]+)'
                    text_tag_match = re.search(text_tag_pattern, description) if description else None
                    custom_name = text_tag_match.group(1) if text_tag_match else ''
                    brief_tag_pattern = r'@brief\s+([^\*/]+)'
                    brief_tag_match = re.search(brief_tag_pattern, description) if description else None
                    description = brief_tag_match.group(1) if brief_tag_match else self.clean_description(description)
                    self.structs_registry[struct_name][member_name] = {
                        'type': member_type,
                        'description': description.strip() if description else '',
                        'custom_name': custom_name.strip() if custom_name else member_name
                    }
                    # register each data member in the global symbol registry
                    self.register_symbol(member_name, custom_name, member_type, description, False)
        else:
            if self.logger:
                self.logger.log("ERROR", f"Could not register struct: {struct_object}")

    def register_method(self, method_object, doxy_tags, scope):
        """
        Registers a method, property, or event.
        """
        if doxy_tags == {}:
            if self.logger:
                self.logger.log("WARNING", f"{method_object} has no doxygen tags.")

        match = self.CPP_COMPONENT_REGEX['method'].match(method_object)
        if match:
            method_return_type, method_name, method_parameters = match.groups()

            method_info = self.build_method_info(method_return_type, method_parameters, doxy_tags)
            # ignore these methods
            if method_name in ['Register', 'Unregister'] or 'omit' in doxy_tags:
                return
            # if the interface struct does not have a @json tag, skip registering the methods
            if '_HasJsonTag' not in scope[-1]:
                return
            if '_HasEventTag' in scope[-1] or 'INotification' in scope[-1]:
                self.events[method_name] = method_info
            # if we are parsing a method that has the same name as a property we have already
            # encountered/parsed, that means we are encountering the getter/setter version definition
            # of a property, thus the property is read & write
            elif method_name in self.properties:
                self.properties[method_name]['property'] = 'read write'
                return
            elif 'property' in doxy_tags:
                self.properties[method_name] = method_info
            else:
                self.methods[method_name] = method_info
        else:
            if self.logger:
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
            'errors': doxy_tags.get('errors', {}),
            'return_type': method_return_type
        }
        if 'property' in doxy_tags:
            if 'const' in method_parameters or '@in' in method_parameters:
                method_info['property'] = 'write'
            else:
                method_info['property'] = 'read'
        return method_info

    def normalize_key(self, key):
            return key#.replace('_', '-').strip()

    def process_and_register_params(self, method_parameters, doxy_tag_param_info):
        """
        Helper to build params and results data structures, using the parameter declaration list
        and doxygen tags.
        """

        # doxy_tag_param_info has info from doxygen @param tags, while param_info_list has info from the parameter declaration
        normalized_param_info = {self.normalize_key(k): v for k, v in doxy_tag_param_info.items()}
        param_info_list = self.get_info_from_param_declaration(method_parameters)

        params = []
        results = []
        for symbol_name, (symbol_type, symbol_inline_comment, custom_name, unwrapped, keep_key, direction) in param_info_list.items():
            if self.logger:
                self.logger.log("INFO", f"Processing param: symbol_name={symbol_name}, symbol_type={symbol_type}, custom_name={custom_name}, direction={direction}, symbol_inline_comment={symbol_inline_comment}")
            if '::' in symbol_type:
                symbol_type = self.sanitize_resolution_operator_from_type(symbol_type)
            if symbol_type == 'IStringIterator':
                self.register_iterator(symbol_type)
            if symbol_type in self.notification_names:
                self.doxy_tags['omit'] = 'omit'
            overridden_name = symbol_name
            if custom_name and custom_name != symbol_name and custom_name in normalized_param_info:
                overridden_name = custom_name
                if self.logger:
                    self.logger.log("INFO", f"Overridden name for param {symbol_name} found in doxy tags as {overridden_name}")
            symbol_description = doxy_tag_param_info.get(overridden_name, {}).get('description', '')
            symbol_optionality = doxy_tag_param_info.get(overridden_name, {}).get('optionality', '')
            symbol_direction = doxy_tag_param_info.get(overridden_name, {}).get('direction', '') or direction

            self.register_symbol(symbol_name, custom_name, symbol_type, symbol_description, unwrapped)
            symbol_info = {
                'name': symbol_name,
                'type': symbol_type,
                'description': symbol_description,
                'custom_name': custom_name,
                'direction': symbol_direction,
                'optionality': symbol_optionality,
                'unwrapped': unwrapped,
                'keep_key': keep_key
            }

            if direction == 'inout':
                params.append(symbol_info)
                results.append(symbol_info)
            elif direction == 'out':
                results.append(symbol_info)
            else:
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
                interger_regex_pattern = r'u?int(8|16|32|64)_t'
                if re.match(interger_regex_pattern, param_type):
                    param_type = 'integer'
                if '[]' in param_name:
                    param_name = param_name.replace('[]', '')
                    param_type = 'string'
                custom_name = None
                unwrapped = False
                keep_key = False
                direction = None
                if param_inline_comment:
                    text_match = re.search(r'@text\s*:?\s*([\w\-]+)', param_inline_comment)
                    if text_match:
                        custom_name = self.normalize_key(text_match.group(1))
                    if '@keep_key' in param_inline_comment:
                        keep_key = True
                    if '@unwrapped' in param_inline_comment:
                        unwrapped = True
                    if '@out' in param_inline_comment:
                        direction = 'out'
                    elif '@inout' in param_inline_comment:
                        direction = 'inout'
                    else:
                        direction = 'in'
                param_info[param_name] = (param_type, param_inline_comment, custom_name, unwrapped, keep_key, direction)
            else:
                if self.logger:
                    self.logger.log("ERROR", f"Could not extract parameter information from: {param}")
        return param_info

    def register_symbol(self, symbol_name, symbol_custom_name, symbol_type, description, unwrapped=False):
        """
        Registers a symbol by incrementally adding information to the symbols registry, as
        information is discovered while parsing.
        """
        unique_id = f"{symbol_name}-{symbol_type}"
        if unique_id not in self.symbols_registry:
            self.symbols_registry[unique_id] = {'type': symbol_type}
        if not self.symbols_registry[unique_id].get('custom_name'):
            self.symbols_registry[unique_id]['custom_name'] = symbol_custom_name.strip() if symbol_custom_name else symbol_name
        if not self.symbols_registry[unique_id].get('description'):
            self.symbols_registry[unique_id]['description'] = description.strip() if description else ''
        if not self.symbols_registry[unique_id].get('unwrapped'):
            self.symbols_registry[unique_id]['unwrapped'] = unwrapped
        if not self.symbols_registry[unique_id].get('example') and symbol_type not in self.iterators_registry:
            self.symbols_registry[unique_id]['example'] = self.generate_example_from_description(description)

    def external_struct_tracker(self, line, scope, brace_count):
        """
        Tracks the current scope of the line being processed. Currently used to determine when
        the notification section is parsed.
        """
        external_struct_tracker_regex = re.compile(r'struct(?:\s+EXTERNAL)?\s+([\w\d]+?)\s*\:\s*virtual\s+public\s+Core\:\:IUnknown.*\{?')
        external_struct_tracker_match = external_struct_tracker_regex.match(line)
        # if this line contains the declaration of an external structure, update it as the scope
        if external_struct_tracker_match:
            scope_name = external_struct_tracker_match.group(1)
            if self.in_event:
                if scope_name not in self.notification_names:
                    self.notification_names.append(scope_name)
                scope_name = scope_name + '_HasEventTag'
                self.in_event = False
            if self.in_json_tag or '_HasJsonTag' in scope[-1]:
                scope_name = scope_name + '_HasJsonTag'
                self.in_json_tag = False
            scope.append(scope_name)
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
        Generates request and response JSONs for each method and event. Directly modifies the
        methods, properties, and events registries.
        """
        id_num = 0
        for method_name, method_info in self.methods.items():
            method_info['request'] = self.generate_request_object(method_name, method_info, id_num)
            method_info['response'] = self.generate_response_object(method_info, id_num)
            id_num += 1
        for event_name, event_info in self.events.items():
            event_info['request'] = self.generate_request_object(event_name, event_info, id_num)
            id_num += 1
        for prop_name, prop_info in self.properties.items():
            # properties can have both get and set requests and responses
            if 'read' in prop_info['property']:
                if prop_info['params'] != []:
                    prop_info['results'] = prop_info['params']
                    prop_info['params'] = []
                prop_info['get_request'] = self.generate_request_object(prop_name, prop_info, id_num)
                prop_info['get_response'] = self.generate_response_object(prop_info, id_num)
            if 'write' in prop_info['property']:
                if prop_info['results'] != []:
                    prop_info['params'] = prop_info['results']
                    prop_info['results'] = []
                prop_info['set_request'] = self.generate_request_object(prop_name, prop_info, id_num)
                prop_info['set_response'] = self.generate_response_object(prop_info, id_num)
            id_num += 1

    def to_camel_case(self, name):
        """Convert UpperCamelCase to lowerCamelCase."""
        return name[0].lower() + name[1:] if name and name[0].isupper() else name

    def generate_request_object(self, method_name, method_info, id_num):
        """
        Makes a request JSON. Creates an example dynamically.
        """
        camel_method_name = self.to_camel_case(method_name)
        request = {
            "jsonrpc": "2.0",
            "id": id_num,
            "method": f"org.rdk.{self.classname}.{camel_method_name}",
        }
        if method_info['params'] != []:
            if len(method_info['params']) == 1:
                param = next(iter(method_info['params']))
                if param.get('unwrapped'):
                    param_name = param.get('name')
                    param_type = param.get('type')
                    param_desc = param.get('description')
                    request['params'] = self.get_symbol_example(
                    f"{param_name}-{param_type}", param_desc)
                    return request
            request["params"] = {}
            for param in method_info['params']:
                keep_key = param.get('keep_key')
                param_name = param.get('name')
                param_custom_name = param.get('custom_name')
                # in case there is a custom name, use it as the key in the response JSON. But, we still use the original name to get the example.
                overridden_name = param_custom_name if param_custom_name else param_name
                param_type = param.get('type')
                param_desc = param.get('description')
                if not keep_key and len(method_info['params']) == 1 and (param_type in self.structs_registry or param_type in self.iterators_registry):
                    request["params"] = self.get_symbol_example(
                        f"{param_name}-{param_type}", param_desc)
                else:
                    request["params"][overridden_name] = self.get_symbol_example(
                        f"{param_name}-{param_type}", param_desc)
        return request

    def generate_response_object(self, method_info, id_num):
        """
        Makes a response JSON. Creates an example dynamically.
        Pattern:
        1. If no @out, result: null
        2. If one @out, result: <type example> (key is override name if present)
        3. If multiple @out, result: { key: <type example>, ... } (keys are override names if present)
        """
        response = {
            "jsonrpc": "2.0",
            "id": id_num,
            "result": None
        }
        # Only consider @out results
        if method_info['results'] != []:
            if len(method_info['results']) == 1:
                result = next(iter(method_info['results']))
                if result.get('unwrapped'):
                    param_name = result.get('name')
                    param_type = result.get('type')
                    param_desc = result.get('description')
                    response['result'] = self.get_symbol_example(
                    f"{param_name}-{param_type}", param_desc)
                    return response
            response['result'] = {}
            for result in method_info['results']:
                keep_key = result.get('keep_key')
                result_name = result.get('name')
                result_custom_name = result.get('custom_name')
                # in case there is a custom name, use it as the key in the response JSON. But, we still use the original name to get the example.
                overridden_name = result_custom_name if result_custom_name and result_custom_name != result_name else result_name
                result_type = result.get('type')
                result_desc = result.get('description')
                if not keep_key and len(method_info['results']) == 1 and (result_type in self.structs_registry or result_type in self.iterators_registry):
                    response['result'] = self.get_symbol_example(
                        f"{result_name}-{result_type}", result_desc)
                else:
                    response['result'][overridden_name] = self.get_symbol_example(
                        f"{result_name}-{result_type}", result_desc)
        return response

    def get_symbol_example(self, unique_id, description):
        """
        Used in generating request/response JSONs. Pulls an example from either the @param tag
        description or the symbols registry.
        """
        example_from_param_description = self.generate_example_from_description(description)
        if example_from_param_description:
            return self.wrap_example_if_iterator(unique_id, example_from_param_description)
        # if no example in the param description, pull from the symbols registry
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
                symbol_data['example'] = self.generate_example_for_individual_symbol(
                    unique_id, description)
                if self.logger:
                    self.logger.log("INFO", f"Generated missing example for {unique_id}")

    def generate_example_for_individual_symbol(self, unique_id, description):
        """
        Generate an example for an individual symbol based on its description or type. Used as a
        helper to populate the symbols registry.
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
        Creates an example parameter based on the symbol type. Used as a
        helper to populate the symbols registry.
        """
        if symbol_type in self.structs_registry:
            struct = self.structs_registry[symbol_type]
            # if len(struct) == 1:
            #     first_member = next(iter(struct))
            #     if first_member not in self.structs_registry and first_member not in self.iterators_registry:
            #         return self.generate_example_for_individual_symbol(f"{first_member}-{struct[first_member]['type']}", struct[first_member]['description'])

            return {struct[member_name]['custom_name']: self.generate_example_for_individual_symbol(f"{member_name}-{struct[member_name]['type']}", struct[member_name]['description']) for member_name in struct}
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
        Wrap the example in a list if the symbol is an iterator, otherwise simply return the
        example.
        """
        if self.symbols_registry[unique_id]['type'] in self.iterators_registry:
            return [example]
        return example

    def link_method_to_event(self):
        """
        Links methods to their associated events. Directly modifies the methods dictionary.
        """
        for method_name, method_info in self.methods.items():
            method_events = method_info['events']
            for event in method_events:
                if event in self.events:
                    self.methods[method_name]['events'][event] = self.events[event].get('brief')
                    self.events[event]['associated_method'] = method_name
                else:
                    if self.logger:
                        self.logger.log("ERROR",
                                        f"Event {event} tagged with {method_name} does not exist.")

    def log_unassociated_events(self):
        """
        Logs events that are not associated with any method.
        """
        for event_name, event_info in self.events.items():
            if not event_info.get('associated_method'):
                if self.logger:
                    self.logger.log("WARNING", f"Event {event_name} is not associated with a method.")

    def fill_and_log_missing_symbol_descriptions(self):
        """
        Fills missing symbol information for methods, events, and properties.
        """
        for method_name, method_info in self.methods.items():
            for param in method_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                                f"Filled missing desc for {param['name']} in method {method_name}")
            for result in method_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                            f"Filled missing desc for {result['name']} in method {method_name}")
        for event_name, event_info in self.events.items():
            for param in event_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                                f"Filled missing desc for {param['name']} in event {event_name}")
            for result in event_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                            f"Filled missing desc for {result['name']} in event {event_name}")
        for prop_name, prop_info in self.properties.items():
            for param in prop_info['params']:
                if not param.get('description'):
                    param['description'] = self.symbols_registry[f"{param['name']}-{param['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                                f"Filled missing desc for {param['name']} in property {prop_name}")
            for result in prop_info['results']:
                if not result.get('description'):
                    result['description'] = self.symbols_registry[f"{result['name']}-{result['type']}"].get('description', '')
                    if self.logger:
                        self.logger.log("INFO",
                            f"Filled missing desc for {result['name']} in property {prop_name}")

    def log_missing_method_info(self):
        """
        At the end of parsing, if there is still information missing for methods, events, and
        symbols, log it.
        """
        for method_name, method_info in self.methods.items():
            if not method_info.get('brief') and not method_info.get('details'):
                if self.logger:
                    self.logger.log("INFO", f"Missing description: {method_name}")
        for event_name, event_info in self.events.items():
            if not event_info.get('brief') and not event_info.get('details'):
                if self.logger:
                    self.logger.log("INFO", f"Missing description: {event_name}")
        for prop_name, prop_info in self.properties.items():
            if not prop_info.get('brief') and not prop_info.get('details'):
                if self.logger:
                    self.logger.log("INFO", f"Missing description: {prop_name}")
        for symbol_name, symbol_info in self.symbols_registry.items():
            if not symbol_info.get('description'):
                if self.logger:
                    self.logger.log("INFO", f"Missing description: {symbol_name}")
            if symbol_info.get('example') == "":
                if self.logger:
                    self.logger.log("INFO", f"Missing example: {symbol_name}")

    def sanitize_resolution_operator_from_type(self, type):
        return type.split('::')[-1]

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
        for symbol_unique_id, symbol_info in self.symbols_registry.items():
            symbol_info['flattened_description'] = self.get_description_from_individual_symbol('', symbol_unique_id)

    def get_description_from_individual_symbol(self, parent_key, unqiue_id):
        """
        Used to flatten descriptions for params/results/values in the symbol registry.
        """
        flattened_descriptions = {}
        if unqiue_id in self.symbols_registry:
            symbol_name = unqiue_id.split('-')[0]
            symbol_type = self.symbols_registry[unqiue_id].get('type')
            symbol_desc = self.symbols_registry[unqiue_id].get('description')
            symbol_custom_name = self.symbols_registry[unqiue_id].get('custom_name', '')
            overridden_name = symbol_custom_name if symbol_custom_name else symbol_name
            symbol_type_override = symbol_type
            if symbol_type in self.enums_registry:
                symbol_type_override = 'string'
            curr_key = f"{parent_key}.{overridden_name}"
            if symbol_type in self.structs_registry:
                struct = self.structs_registry[symbol_type]
                if len(struct) == 1:
                    first_member = next(iter(struct))
                    if first_member not in self.structs_registry and first_member not in self.iterators_registry:
                        flattened_descriptions.update(
                            self.get_description_from_individual_symbol('', f"{first_member}-{struct[first_member]['type']}"))
                        return flattened_descriptions
            flattened_descriptions = {curr_key: {'type': symbol_type_override, 'description': symbol_desc}}
            flattened_descriptions.update(self.flatten_description(curr_key, symbol_type))
        return flattened_descriptions

    def flatten_description(self, parent_key, symbol_type):
        """
        Mirrors logic in generate_example_from_symbol_type.
        """
        flattened_descriptions = {}
        if symbol_type in self.structs_registry:
            struct = self.structs_registry[symbol_type]
            # if len(struct) == 1:
            #     first_member = next(iter(struct))
            #     if first_member not in self.structs_registry and first_member not in self.iterators_registry:
            #         flattened_descriptions.update(
            #             self.get_description_from_individual_symbol('', f"{first_member}-{struct[first_member]['type']}"))
            # else:
            for member_name in struct:
                member_type = struct[member_name]['type']
                member_desc = struct[member_name]['description']
                member_custom_name = struct[member_name].get('custom_name', '')
                overridden_name = member_custom_name if member_custom_name and member_custom_name != member_name else member_name
                curr_key = f"{parent_key}.{overridden_name}"
                member_type_override = member_type
                if member_type in self.enums_registry:
                    member_type_override = 'string'
                flattened_descriptions[curr_key] = {'type': member_type_override, 'description': member_desc}
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
            description = re.sub(r'@\S+', '', description)
            description = re.sub(r'\- in \-|\- out \-|\- in|\- out', '', description)
            description = description[:-1] if description.endswith(';') else description
            description = description[:-2] if description.endswith("*/") else description
            description = re.sub(r'\*/', ' ', description)
            description = re.sub(r'/\*', ' ', description)
        return description
