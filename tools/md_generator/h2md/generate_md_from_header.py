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
from collections import Counter
from header_file_parser import HeaderFileParser
from logger import Logger
from markdown_templates import (
    generate_header_description_markdown,
    generate_header_toc,
    generate_method_markdown,
    generate_notification_markdown,
    generate_property_markdown,
    generate_configuration_options_section
)


def _to_camel_case(name):
    return name[0].lower() + name[1:] if name and name[0].isupper() else name


def annotate_method_display_metadata(header_structure):
    """Annotate methods with stable display and anchor names for combined docs."""
    base_names = []
    for method_key, method_info in header_structure.methods.items():
        base_names.append(method_info.get('text') or _to_camel_case(method_info.get('cpp_name', method_key.split('::')[-1])))

    duplicate_counts = Counter(base_names)

    for method_key, method_info in header_structure.methods.items():
        base_name = method_info.get('text') or _to_camel_case(method_info.get('cpp_name', method_key.split('::')[-1]))
        owner_interface = method_info.get('owner_interface', '')
        if duplicate_counts[base_name] > 1 and owner_interface:
            method_info['display_name'] = f"{base_name} ({owner_interface})"
            method_info['anchor_name'] = f"{owner_interface}::{base_name}"
        else:
            method_info['display_name'] = base_name
            method_info['anchor_name'] = base_name


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

    additional_interfaces = getattr(additional_structure, 'interfaces', {})
    main_interfaces = getattr(main_structure, 'interfaces', {})
    for interface_name, interface_info in additional_interfaces.items():
        if interface_name not in main_interfaces:
            main_interfaces[interface_name] = interface_info
        elif not main_interfaces[interface_name].get('description') and interface_info.get('description'):
            main_interfaces[interface_name]['description'] = interface_info['description']
        elif interface_info.get('has_json') and not main_interfaces[interface_name].get('has_json'):
            main_interfaces[interface_name]['has_json'] = True
    main_structure.interfaces = main_interfaces

    if main_structure.plugindescription == '':
        main_structure.plugindescription = additional_structure.plugindescription


def _is_notification_interface_name(interface_name):
    return bool(interface_name) and (
        interface_name == 'INotification' or
        interface_name.endswith('Notification')
    )


def _ordered_interfaces_from_structure(header_structure):
    """Return interface names in stable order from parser metadata and members ownership."""
    ordered = []
    seen = set()

    for interface_name in getattr(header_structure, 'interfaces', {}).keys():
        interface_info = getattr(header_structure, 'interfaces', {}).get(interface_name, {})
        is_json_interface = interface_info.get('has_json', False)
        if interface_name and interface_name not in seen and not _is_notification_interface_name(interface_name) and is_json_interface:
            seen.add(interface_name)
            ordered.append(interface_name)

    for registry in (header_structure.methods, header_structure.events, header_structure.properties):
        for info in registry.values():
            interface_name = info.get('owner_interface', '')
            if interface_name and interface_name not in seen and not _is_notification_interface_name(interface_name):
                seen.add(interface_name)
                ordered.append(interface_name)

    if not ordered:
        ordered.append(f"I{header_structure.classname}")

    return ordered


def _interface_sections_from_structure(header_structure, interfaces=None):
    """Return interface section availability for TOC generation."""
    interfaces = interfaces or _ordered_interfaces_from_structure(header_structure)
    sections = []

    for interface_name in interfaces:
        has_methods = any(
            method_info.get('owner_interface', '') == interface_name
            for method_info in header_structure.methods.values()
        )
        has_notifications = any(
            event_info.get('owner_interface', '') == interface_name
            for event_info in header_structure.events.values()
        )
        has_properties = any(
            prop_info.get('owner_interface', '') == interface_name
            for prop_info in header_structure.properties.values()
        )

        if not has_methods and not has_notifications and not has_properties:
            continue

        sections.append({
            'name': interface_name,
            'has_methods': has_methods,
            'has_notifications': has_notifications,
            'has_properties': has_properties,
        })

    return sections


def _render_interface_methods_section(file, methods, header_structure, classname, interface_name):
    """Write methods table and method details for a single interface."""
    if not methods:
        return

    file.write(f"\n<a id=\"{interface_name}-Methods\"></a>\n### Methods\n\n")
    file.write(f"The following methods are provided by the {interface_name} Interface:\n\n")
    file.write("| Method | Description |\n| :-------- | :-------- |\n")
    for method_name, method_info in methods.items():
        display_name = method_info.get('display_name') or method_info.get('text') or _to_camel_case(method_name.split('::')[-1])
        anchor_name = method_info.get('anchor_name') or method_info.get('text') or _to_camel_case(method_name.split('::')[-1])
        deprecated_sup = "<sup>deprecated</sup>" if 'deprecated' in method_info else ""
        file.write(f"| [{display_name}](#{anchor_name}){deprecated_sup} | {method_info['brief'] or method_info['details']} |\n")

    for method_name, method_info in methods.items():
        file.write(generate_method_markdown(
            method_name, method_info, header_structure.symbols_registry,
            classname, header_structure.events))


def _render_interface_notifications_section(file, events, header_structure, classname, interface_name):
    """Write notifications table and event details for a single interface."""
    if not events:
        return

    file.write(f"\n<a id=\"{interface_name}-Notifications\"></a>\n### Notifications\n\n")
    file.write("Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.\n\n")
    file.write(f"The following events are provided by the {interface_name} Interface:\n\n")
    file.write("| Event | Description |\n| :-------- | :-------- |\n")
    for event_name, event_info in events.items():
        display_name = event_info.get('text') or _to_camel_case(event_name)
        deprecated_sup = "<sup>deprecated</sup>" if 'deprecated' in event_info else ""
        file.write(f"| [{display_name}](#{display_name}){deprecated_sup} | {event_info['brief'] or event_info['details']} |\n")

    for event_name, event_info in events.items():
        file.write(generate_notification_markdown(
            event_name, event_info, header_structure.symbols_registry, classname))


def _render_interface_properties_section(file, properties, header_structure, classname, interface_name):
    """Write properties table and property details for a single interface."""
    if not properties:
        return

    file.write(f"\n<a id=\"{interface_name}-Properties\"></a>\n### Properties\n\n")
    file.write(f"The following properties are provided by the {interface_name} Interface:\n\n")
    file.write("| Property | Description |\n| :-------- | :-------- |\n")

    for prop_name, prop_info in properties.items():
        property_name = prop_info.get('text') or _to_camel_case(prop_name)
        superscript = ""
        if prop_info['property'] == 'read':
            superscript = "<sup>RO</sup>"
        elif prop_info['property'] == 'write':
            superscript = "<sup>WO</sup>"
        if 'deprecated' in prop_info:
            superscript += "<sup>deprecated</sup>"
        file.write(f"| [{property_name}](#{property_name}){superscript} | {prop_info['brief'] or prop_info['details']} |\n")

    for prop_name, prop_info in properties.items():
        file.write(generate_property_markdown(
            prop_name, prop_info, header_structure.symbols_registry, classname))


def get_header_files(folder_path):
    """Get all .h files from the specified folder."""
    return [f for f in os.listdir(folder_path) if f.endswith('.h')]


def create_logger(classname, logfile_path=None):
    """Create and return a logger instance, or None if logfile_path is not provided."""
    if logfile_path is None:
        return None
    log_file_path = os.path.join(logfile_path, f'{classname}.txt')
    return Logger(log_file_path)


def find_main_header_file(header_files, plugin_name):
    """Find the main header file, preferring I{plugin_name}.h, then {plugin_name}.h, then the first file."""
    for candidate in (f'I{plugin_name}.h', f'{plugin_name}.h'):
        if candidate in header_files:
            return candidate
    return header_files[0]


def parse_header_file(header_file_path, classname, logger):
    """Parse a header file and return the structure."""
    return HeaderFileParser(header_file_path, classname, logger)


def write_markdown_sections(file, header_structure, classname):
    """Write all markdown sections to the file."""
    interfaces = _ordered_interfaces_from_structure(header_structure)

    if header_structure.methods or header_structure.events or header_structure.properties:
        file.write("\n<a id=\"Interfaces\"></a>\n# Interfaces\n")

        first_interface = True
        for interface_name in interfaces:
            interface_methods = {
                method_name: method_info
                for method_name, method_info in header_structure.methods.items()
                if method_info.get('owner_interface', '') == interface_name
            }
            interface_events = {
                event_name: event_info
                for event_name, event_info in header_structure.events.items()
                if event_info.get('owner_interface', '') == interface_name
            }
            interface_properties = {
                prop_name: prop_info
                for prop_name, prop_info in header_structure.properties.items()
                if prop_info.get('owner_interface', '') == interface_name
            }

            if not interface_methods and not interface_events and not interface_properties:
                continue

            if not first_interface:
                file.write("\n---\n")

            file.write(f"\n<a id=\"{interface_name}\"></a>\n## {interface_name} Interface\n")
            interface_description = getattr(header_structure, 'interfaces', {}).get(interface_name, {}).get('description', '')
            if interface_description:
                file.write("\n### Description\n\n")
                file.write(f"{interface_description}\n")

            _render_interface_methods_section(file, interface_methods, header_structure, classname, interface_name)
            _render_interface_notifications_section(file, interface_events, header_structure, classname, interface_name)
            _render_interface_properties_section(file, interface_properties, header_structure, classname, interface_name)
            first_interface = False

    file.write("\n")


def generate_md_from_individual_header_file(header_structure, output_doc_folder_path, classname, logger, header_file_path):
    """Generate markdown file from a single header structure."""
    plugin_version = getattr(header_structure, 'plugin_version', '')
    # if no @json tag present in the header file
    # if plugin_version == '':
    #     return
    output_file_path = os.path.join(output_doc_folder_path, f'{classname}.md')
    os.makedirs(os.path.dirname(output_file_path), exist_ok=True)
    if not header_structure.methods and not header_structure.properties and not header_structure.events:
        return

    annotate_method_display_metadata(header_structure)
    interfaces = _ordered_interfaces_from_structure(header_structure)
    interface_sections = _interface_sections_from_structure(header_structure, interfaces)

    with open(output_file_path, 'w', encoding='utf-8') as file:
        # Write header sections
        file.write(generate_header_toc(
            classname, header_structure, plugin_version, header_file_path, interface_sections))
        file.write(generate_header_description_markdown(
            classname,
            getattr(header_structure, 'plugindescription', ''),
            interfaces
        ))
        file.write(generate_configuration_options_section(header_structure.configuration_options))

        # Write main content sections
        write_markdown_sections(file, header_structure, classname)

    if logger is not None:
        logger.write_log()
        logger.close()


def process_individual_headers(input_plugin_folder_path, output_doc_folder_path, logfile_path=None):
    """Process each header file individually."""
    header_files = get_header_files(input_plugin_folder_path)

    for header_file in header_files:
        header_file_path = os.path.join(input_plugin_folder_path, header_file)
        classname = os.path.splitext(header_file)[0][1:]  # Remove leading 'I'
        logger = create_logger(classname, logfile_path)
        header_structure = parse_header_file(header_file_path, classname, logger)
        generate_md_from_individual_header_file(header_structure, output_doc_folder_path, classname, logger, header_file_path)


def process_combined_headers(input_plugin_folder_path, output_doc_folder_path, logfile_path=None):
    """Process all header files combined into one output."""
    header_files = get_header_files(input_plugin_folder_path)
    if not header_files:
        return

    plugin_name = os.path.basename(os.path.normpath(input_plugin_folder_path))
    classname = plugin_name
    logger = create_logger(classname, logfile_path)

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


def generate_md_from_header(input_plugin_folder_path, output_doc_folder_path, individual=False, logfile_path=None):
    """
    Writes the markdown documentation from the header file.

    Args:
        input_plugin_folder_path (str): Path to the plugin folder containing header files.
        output_doc_folder_path (str): Path to the output documentation folder.
        individual (bool): Whether to generate separate files for each header.
        logfile_path (str): Optional path to the log file directory.
    """
    if individual:
        process_individual_headers(input_plugin_folder_path, output_doc_folder_path, logfile_path)
    else:
        process_combined_headers(input_plugin_folder_path, output_doc_folder_path, logfile_path)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Process header file.')
    parser.add_argument('-o', '--output_doc_folder', type=str, required=True,
                       help='Path to desired output folder')
    parser.add_argument('-i', '--input_plugin_folder', type=str, required=True,
                       help='Path to plugin folder')
    parser.add_argument('-l', '--logfile', type=str, required=False, default=None,
                       help='Path to log file directory')
    parser.add_argument('--individual', action='store_true',
                       help='Generate individual docs for each header file')
    args = parser.parse_args()

    generate_md_from_header(args.input_plugin_folder, args.output_doc_folder, args.individual, args.logfile)
