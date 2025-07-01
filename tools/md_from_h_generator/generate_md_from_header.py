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

# Generates the .md files from the .h files, and logs any warnings or errors.

import os
import argparse
from header_file_parser import HeaderFileParser
from logger import Logger
from markdown_templates import generate_header_description_markdown, generate_header_toc, generate_methods_toc, generate_method_markdown, generate_notifications_toc, generate_notification_markdown, generate_properties_toc, generate_property_markdown

def generate_md_from_header(header_file):
    """
    Writes the markdown documentation from the header file.

    Args:
        header_file (str): Path to the header file.
    """
    filename = os.path.basename(header_file)
    classname, _ = os.path.splitext(filename)

    log_file_path = './tools/md_from_h_generator/logs/' + classname + '.txt'
    logger = Logger(log_file_path)

    header_structure = HeaderFileParser(header_file, logger)

    # Remove the leading 'I' from the api's class name
    output_file_path = './tools/md_from_h_generator/generated_docs/' + header_structure.classname + 'Plugin.md'

    with open(output_file_path, 'w', encoding='utf-8') as file:
        file.write(generate_header_toc(header_structure.classname, header_structure))
        file.write(generate_header_description_markdown(header_structure.classname, getattr(header_structure, 'plugindescription', '')))
        if len(header_structure.methods.values()) > 0:
            file.write(generate_methods_toc(header_structure.methods, header_structure.classname))
            for idx, (method_name, method_info) in enumerate(header_structure.methods.items(), start=1):
                file.write(generate_method_markdown(
                    method_name, method_info, header_structure.symbols_registry, header_structure.classname, idx))
        file.write("\n")
        if len(header_structure.properties.values()) > 0:
            file.write(generate_properties_toc(header_structure.properties, header_structure.classname))
            for idx, (prop_name, prop_info) in enumerate(header_structure.properties.items(), start=1):
                file.write(generate_property_markdown(
                    prop_name, prop_info, header_structure.symbols_registry, header_structure.classname))
        file.write("\n")
        if len(header_structure.events.values()) > 0:
            file.write(generate_notifications_toc(header_structure.events, header_structure.classname))
            for idx, (event_name, event_info) in enumerate(header_structure.events.items(), start=1):
                file.write(generate_notification_markdown(
                    event_name, event_info, header_structure.symbols_registry, header_structure.classname, idx))
    logger.write_log()
    logger.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Process header file.')
    parser.add_argument('header_file', type=str, help='Path to header file')
    args = parser.parse_args()
    generate_md_from_header(args.header_file)
