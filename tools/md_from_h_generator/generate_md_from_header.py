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
from markdown_templates import (
    generate_header_description_markdown, 
    generate_header_toc, 
    generate_methods_toc, 
    generate_method_markdown, 
    generate_notifications_toc, 
    generate_notification_markdown, 
    generate_properties_toc, 
    generate_property_markdown, 
    generate_configuration_options_section
)


def combine_header_structures(main_structure, additional_structure):
    """Combine additional header structure into main structure."""
    main_structure.methods.update(additional_structure.methods)
    main_structure.properties.update(additional_structure.properties)
    main_structure.events.update(additional_structure.events)
    main_structure.symbols_registry.update(additional_structure.symbols_registry)
    # Concerned about the below registries having collisions ... rename the keys to
    # reference the HF struct it belongs to?
    main_structure.iterators_registry.update(additional_structure.iterators_registry)
    main_structure.enums_registry.update(additional_structure.enums_registry)
    main_structure.structs_registry.update(additional_structure.structs_registry)
    main_structure.configuration_options.update(additional_structure.configuration_options)
    if main_structure.plugindescription == '':
        main_structure.plugindescription = additional_structure.plugindescription


def get_header_files(folder_path):
    """Get all .h files from the specified folder."""
    return [f for f in os.listdir(folder_path) if f.endswith('.h')]


def create_logger(classname):
    """Create and return a logger instance."""
    log_file_path = f'./tools/md_from_h_generator/logs/{classname}.txt'
    return Logger(log_file_path)


def find_main_header_file(header_files, plugin_name):
    """Find the main header file, preferring plugin_name.h if it exists."""
    main_header = f'{plugin_name}.h'
    return main_header if main_header in header_files else header_files[0]


def parse_header_file(header_file_path, classname, logger):
    """Parse a header file and return the structure."""
    return HeaderFileParser(header_file_path, classname, logger)


def write_markdown_sections(file, header_structure, classname):
    """Write all markdown sections to the file."""
    # Write methods section
    if header_structure.methods:
        file.write(generate_methods_toc(header_structure.methods, classname))
        for method_name, method_info in header_structure.methods.items():
            file.write(generate_method_markdown(
                method_name, method_info, header_structure.symbols_registry, 
                classname, header_structure.events))
    
    file.write("\n")
    
    # Write properties section
    if header_structure.properties:
        file.write(generate_properties_toc(header_structure.properties, classname))
        for prop_name, prop_info in header_structure.properties.items():
            file.write(generate_property_markdown(
                prop_name, prop_info, header_structure.symbols_registry, classname))
    
    file.write("\n")
    
    # Write events section
    if header_structure.events:
        file.write(generate_notifications_toc(header_structure.events, classname))
        for event_name, event_info in header_structure.events.items():
            file.write(generate_notification_markdown(
                event_name, event_info, header_structure.symbols_registry, classname))


def generate_md_from_individual_header_file(header_structure, output_doc_folder_path, classname, logger, header_file_path):
    """Generate markdown file from a single header structure."""
    plugin_version = getattr(header_structure, 'plugin_version', '')
    # if no @json tag present in the header file
    # if plugin_version == '':
    #     return
    output_file_path = os.path.join(output_doc_folder_path, f'{classname}Plugin.md')
    os.makedirs(os.path.dirname(output_file_path), exist_ok=True)
    if not header_structure.methods and not header_structure.properties and not header_structure.events:
        return
    
    with open(output_file_path, 'w', encoding='utf-8') as file:
        # Write header sections
        file.write(generate_header_toc(
            classname, header_structure, plugin_version, header_file_path))
        file.write(generate_header_description_markdown(
            classname, getattr(header_structure, 'plugindescription', '')))
        file.write(generate_configuration_options_section(header_structure.configuration_options))

        # Write main content sections
        write_markdown_sections(file, header_structure, classname)

    logger.write_log()
    logger.close()


def process_individual_headers(input_plugin_folder_path, output_doc_folder_path):
    """Process each header file individually."""
    header_files = get_header_files(input_plugin_folder_path)

    for header_file in header_files:
        header_file_path = os.path.join(input_plugin_folder_path, header_file)
        classname = os.path.splitext(header_file)[0][1:]  # Remove leading 'I'
        logger = create_logger(classname)
        header_structure = parse_header_file(header_file_path, classname, logger)
        generate_md_from_individual_header_file(header_structure, output_doc_folder_path, classname, logger, header_file_path)


def process_combined_headers(input_plugin_folder_path, output_doc_folder_path):
    """Process all header files combined into one output."""
    header_files = get_header_files(input_plugin_folder_path)
    plugin_name = os.path.basename(os.path.normpath(input_plugin_folder_path))
    classname = plugin_name
    logger = create_logger(classname)

    # Find and parse main header file
    main_header_file = find_main_header_file(header_files, plugin_name)
    main_header_file_path = os.path.join(input_plugin_folder_path, main_header_file)
    main_structure = parse_header_file(main_header_file_path, classname, logger)

    # Process additional header files
    remaining_files = [f for f in header_files if f != main_header_file]
    for header_file in remaining_files:
        header_file_path = os.path.join(input_plugin_folder_path, header_file)
        additional_structure = parse_header_file(header_file_path, classname, logger)
        combine_header_structures(main_structure, additional_structure)

    generate_md_from_individual_header_file(main_structure, output_doc_folder_path, classname, logger, main_header_file_path)


def generate_md_from_header(input_plugin_folder_path, output_doc_folder_path, individual=False):
    """
    Writes the markdown documentation from the header file.

    Args:
        input_plugin_folder_path (str): Path to the plugin folder containing header files.
        output_doc_folder_path (str): Path to the output documentation folder.
        individual (bool): Whether to generate separate files for each header.
    """
    if individual:
        process_individual_headers(input_plugin_folder_path, output_doc_folder_path)
    else:
        process_combined_headers(input_plugin_folder_path, output_doc_folder_path)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Process header file.')
    parser.add_argument('-o', '--output_doc_folder', type=str, required=True, 
                       help='Path to desired output folder')
    parser.add_argument('-i', '--input_plugin_folder', type=str, required=True, 
                       help='Path to plugin folder')
    parser.add_argument('--individual', action='store_true', 
                       help='Generate individual docs for each header file')
    args = parser.parse_args()
    
    generate_md_from_header(args.input_plugin_folder, args.output_doc_folder, args.individual)
