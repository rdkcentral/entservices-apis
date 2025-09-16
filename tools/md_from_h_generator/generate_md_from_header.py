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
from markdown_templates import generate_header_description_markdown, generate_header_toc, generate_methods_toc, generate_method_markdown, generate_notifications_toc, generate_notification_markdown, generate_properties_toc, generate_property_markdown, generate_configuration_options_section

def combine_header_structures(main_structure, additional_structure):
    main_structure.methods.update(additional_structure.methods)
    main_structure.properties.update(additional_structure.properties)
    main_structure.events.update(additional_structure.events)
    main_structure.symbols_registry.update(additional_structure.symbols_registry)
    # Concerned about the below registries having collisions ... do i need to rename the keys to
    # reference the HF struct it belongs to?
    main_structure.iterators_registry.update(additional_structure.iterators_registry)
    main_structure.enums_registry.update(additional_structure.enums_registry)
    main_structure.structs_registry.update(additional_structure.structs_registry)

def generate_md_from_header(plugin_folder_path, individual=False):
    """
    Writes the markdown documentation from the header file.

    Args:
        header_file (str): Path to the header file.
    """
    header_files = [f for f in os.listdir(plugin_folder_path) if f.endswith('.h')]
    plugin_name = os.path.basename(plugin_folder_path)

    # if individual flag, then we generate a separate markdown file for each header file in folder
    if individual:
        for header_file in header_files:
            header_file_path = os.path.join(plugin_folder_path, header_file)
            classname = os.path.splitext(header_file)[0][1:]
            log_file_path = f'./tools/md_from_h_generator/logs/{classname}.txt'
            logger = Logger(log_file_path)
            header_structure = HeaderFileParser(header_file_path, classname, logger)
            generate_md_from_individual_header_file(header_structure, classname, logger)
    else:
        classname = plugin_name
        log_file_path = f'./tools/md_from_h_generator/logs/{classname}.txt'
        logger = Logger(log_file_path)
        main_header_file = ""
        for header_file in header_files:
            if header_file == plugin_name + '.h':
                main_header_file = header_file
                break
        if main_header_file:
            main_header_file_path = os.path.join(plugin_folder_path, main_header_file)
        else:
            main_header_file_path = os.path.join(plugin_folder_path, header_files[0])
        main_structure = HeaderFileParser(main_header_file_path, classname, logger)
        # if folder contains more than one header files, combine their structures
        for header_file in (header_files.remove(main_header_file) if main_header_file else header_files):
            header_file_path = os.path.join(plugin_folder_path, header_file)
            additional_structure = HeaderFileParser(header_file_path, classname, logger)
            combine_header_structures(main_structure, additional_structure)
        generate_md_from_individual_header_file(main_structure, classname, logger)

def generate_md_from_individual_header_file(header_structure, classname, logger):
    output_file_path = './tools/md_from_h_generator/generated_docs/' + classname + 'Plugin.md'
    os.makedirs(os.path.dirname(output_file_path), exist_ok=True)
    with open(output_file_path, 'w', encoding='utf-8') as file:
        file.write(generate_header_toc(classname, header_structure))
        file.write(generate_header_description_markdown(classname, getattr(header_structure, 'plugindescription', '')))
        file.write(generate_configuration_options_section(header_structure.configuration_options))
        if len(header_structure.methods.values()) > 0:
            file.write(generate_methods_toc(header_structure.methods, classname))
            for method_name, method_info in header_structure.methods.items():
                file.write(generate_method_markdown(
                    method_name, method_info, header_structure.symbols_registry, classname, header_structure.events))
        file.write("\n")
        if len(header_structure.properties.values()) > 0:
            file.write(generate_properties_toc(header_structure.properties, classname))
            for prop_name, prop_info in header_structure.properties.items():
                file.write(generate_property_markdown(
                    prop_name, prop_info, header_structure.symbols_registry, classname))
        file.write("\n")
        if len(header_structure.events.values()) > 0:
            file.write(generate_notifications_toc(header_structure.events, classname))
            for event_name, event_info in header_structure.events.items():
                file.write(generate_notification_markdown(
                    event_name, event_info, header_structure.symbols_registry, classname))
    logger.write_log()
    logger.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Process header file.')
    parser.add_argument('plugin_folder', type=str, help='Path to plugin folder')
    parser.add_argument('--individual', action='store_true', help='Specify if output doc should be generated for all headers in folder or if they should be generated individually')
    args = parser.parse_args()
    generate_md_from_header(args.plugin_folder, args.individual)
