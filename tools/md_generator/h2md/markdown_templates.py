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

import json
import re
import os

# Templates
HEADER_TOC_TEMPLATE = """<!-- Generated automatically, DO NOT EDIT! -->
<a id="{classname}_Plugin"></a>
# {classname} Plugin

**Version: [{version}](https://github.com/rdkcentral/entservices-apis/tree/main/apis/{foldername})**

A {classname} plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
"""

HEADER_DESCRIPTION_TEMPLATE = """
<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `{classname}` plugin provides an interface for {classname}.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.{classname}) |
| classname | string | Class name: *{classname}* |
| locator | string | Library name: *libWPEFramework{classname}.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |
"""

METHODS_TOC_TEMPLATE = """
<a id="Methods"></a>
# Methods

The following methods are provided by the {classname} plugin:

{classname} interface methods:

| Method | Description |
| :-------- | :-------- |
"""

METHODS_INTRO_TEMPLATE = """
<a id="Methods"></a>
# Methods

The following methods are provided by the {classname} plugin:

{classname} interface methods:
"""

METHOD_MARKDOWN_TEMPLATE = """
<a id="{method_name}"></a>
## *{method_name}*

{method_description}

"""

PROPERTIES_TOC_TEMPLATE = """
<a id="Properties"></a>
# Properties
The following properties are provided by the {classname} plugin:

{classname} interface properties:

| Property | Description |
| :-------- | :-------- |
"""

PROPERTY_MARKDOWN_TEMPLATE = """
<a id="{property_name}"></a>
## *{property_name}*

{property_description}

"""

EVENTS_TOC_TEMPLATE = """
<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the {classname} plugin:

{classname} interface events:

| Event | Description |
| :-------- | :-------- |
"""

EVENT_MARKDOWN_TEMPLATE = """
<a id="{event_name}"></a>
## *{event_name}*

{event_description}

"""

EXAMPLE_REQUEST_TEMPLATE = """

#### {method_type}Request

```json
{request_json}
```
"""

EXAMPLE_CURL_REQUEST_TEMPLATE = """

#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{request_json}' http://127.0.0.1:9998/jsonrpc
```
"""

EXAMPLE_RESPONSE_TEMPLATE = """

#### {method_type}Response

```json
{response_json}
```
"""

EXAMPLE_NOTIFICATION_TEMPLATE = """
```json
{request_json}
```
"""

DEPRECATED_NOTICE = "> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations."

def to_camel_case(name):
    """Convert UpperCamelCase to lowerCamelCase."""
    return name[0].lower() + name[1:] if name and name[0].isupper() else name

def generate_deprecated_notice(deprecated_text):
    """
    Generate a standard deprecated notice block, optionally followed by custom guidance.
    """
    markdown = f"{DEPRECATED_NOTICE}"
    if deprecated_text:
        markdown += f" {deprecated_text.strip()}"
    return markdown + "\n\n"

def generate_error_examples_section(retvals, request_id):
    """
    Generate JSON error response examples for each non-ERROR_NONE retval entry.
    Appended to the Examples section after the success response.
    """
    if not retvals:
        return ''
    markdown = ''
    for retval in retvals:
        error_response = {
            "jsonrpc": "2.0",
            "id": request_id,
            "error": {
                "code": retval['code'],
                "message": retval['message']
            }
        }
        enum_name = retval['enum_name']
        markdown += f"\n\n#### Error Response ({enum_name})\n"
        markdown += f"\n```json\n{json.dumps(_convert_json_types(error_response), indent=4)}\n```\n"
    return markdown

def generate_header_toc(classname, document_object, version, foldername):
    """
    Generate the header table of contents for the markdown file.
    """
    version = version if version else "1.0.0"
    interface_name = os.path.basename(foldername)
    directory_name = os.path.dirname(foldername)
    parent_name = os.path.basename(directory_name)
    toc = HEADER_TOC_TEMPLATE.format(classname=classname, version=version, foldername=os.path.join(parent_name,interface_name))
    if len(document_object.methods.values()) > 0:
        toc += "- [Methods](#Methods)\n"
    if len(document_object.properties.values()) > 0:
        toc += "- [Properties](#Properties)\n"
    if len(document_object.events.values()) > 0:
        toc += "- [Notifications](#Notifications)\n"
    return toc

def generate_header_description_markdown(classname, plugindescription=None):
    """
    Generate the header description markdown for the file.
    """
    description_line = (
        plugindescription.strip() if plugindescription else f'The `{classname}` plugin provides an interface for {classname}.'
    )
    return HEADER_DESCRIPTION_TEMPLATE.replace(
        'The `{classname}` plugin provides an interface for {classname}.',
        description_line
    ).format(classname=classname)

def generate_configuration_options_section(configuration_options):
    """
    Generate the configuration options section for the markdown file.
    """
    markdown = ''
    if configuration_options:
        # markdown += "| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"
        for option_name, option_type_and_desc in configuration_options.items():
            option_type = option_type_and_desc['type']
            option_desc = option_type_and_desc['description']
            markdown += f"| {option_name} | {option_type} | {option_desc} |\n"
    return markdown

def _ordered_interfaces(methods):
    """Return a list of unique owner_interface values in insertion order."""
    seen = set()
    result = []
    for method_info in methods.values():
        iface = method_info.get('owner_interface', '')
        if iface and iface not in seen:
            seen.add(iface)
            result.append(iface)
    return result


def generate_methods_toc(methods, classname):
    """
    Generate the methods table of contents for the markdown file.
    When methods span multiple interfaces, each interface gets its own
    labelled sub-table separated by a horizontal rule.
    """
    interfaces = _ordered_interfaces(methods)

    if len(interfaces) > 1:
        toc = METHODS_INTRO_TEMPLATE.format(classname=classname)
        first = True
        for iface in interfaces:
            if not first:
                toc += "\n---\n"
            toc += f"\n**{iface} methods**\n\n"
            toc += "| Method | Description |\n| :-------- | :-------- |\n"
            for method, method_info in methods.items():
                if method_info.get('owner_interface', '') == iface:
                    method_name = method_info.get('display_name') or method_info.get('text') or to_camel_case(method.split('::')[-1])
                    method_anchor = method_info.get('anchor_name') or method_info.get('text') or to_camel_case(method.split('::')[-1])
                    deprecated_sup = "<sup>deprecated</sup>" if 'deprecated' in method_info else ""
                    toc += f"| [{method_name}](#{method_anchor}){deprecated_sup} | {method_info['brief'] or method_info['details']} |\n"
            first = False
        return toc

    toc = METHODS_TOC_TEMPLATE.format(classname=classname)
    for method, method_info in methods.items():
        method_name = method_info.get('display_name') or method_info.get('text') or to_camel_case(method.split('::')[-1])
        method_anchor = method_info.get('anchor_name') or method_info.get('text') or to_camel_case(method.split('::')[-1])
        deprecated_sup = "<sup>deprecated</sup>" if 'deprecated' in method_info else ""
        toc += f"| [{method_name}](#{method_anchor}){deprecated_sup} | {method_info['brief'] or method_info['details']} |\n"
    return toc

def flatten_canonical_dict(canonical_dict, parent_prefix):
    """
    Flatten a canonical dict for table output. Returns a list of (name, type, description) tuples.
    """
    rows = []
    for name, info in canonical_dict.items():
        # Only add if description is not empty, else fallback to type if both are empty
        desc = info['description'] if info['description'] else ''
        rows.append((f"{parent_prefix}.{name}", info['type'], desc))
    return rows

def generate_request_section(request, method_type, classname=None):
    """
    Generate the request section for a method.
    """
    if classname and isinstance(request, dict) and 'method' in request:
        parts = request['method'].split('.')
        if len(parts) > 2:
            parts[2] = classname
            request['method'] = '.'.join(parts)
    # Set the id
    if isinstance(request, dict):
        request = dict(request)  # shallow copy
    request_json = json.dumps(_convert_json_types(request), indent=4)
    markdown = EXAMPLE_REQUEST_TEMPLATE.format(request_json=request_json, method_type=method_type)
    return markdown

def generate_curl_request_section(request, method_type, classname=None):
    """
    Generate the curl request section for a method.
    """
    if classname and isinstance(request, dict) and 'method' in request:
        parts = request['method'].split('.')
        if len(parts) > 2:
            parts[2] = classname
            request['method'] = '.'.join(parts)
    # Set the id
    if isinstance(request, dict):
        request = dict(request)  # shallow copy
    request_json = json.dumps(_convert_json_types(request))
    markdown = EXAMPLE_CURL_REQUEST_TEMPLATE.format(request_json=request_json, method_type=method_type)  
    return markdown

def generate_response_section(response, method_type, classname=None):
    """
    Generate the response section for a method.
    """
    if isinstance(response, dict):
        response = dict(response)
    response_json = json.dumps(_convert_json_types(response), indent=4)
    markdown = EXAMPLE_RESPONSE_TEMPLATE.format(response_json=response_json, method_type=method_type)
    return markdown

def generate_parameters_section(params, symbol_registry):
    """
    Generate the parameters section for a method, showing the parent object and all fields for all params, using override names and descriptions if present.
    """
    markdown = "### Parameters\n"
    if params:
        markdown += "| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"
        markdown += f"| params | object |  |\n"
        for param in params:
            param_key = f"{param['name']}-{param['type']}"
            flattened_params = dict(symbol_registry[param_key]['flattened_description'])
            if param['description']:
                first_key = next(iter(flattened_params))
                flattened_params[first_key] = {**flattened_params[first_key], 'description': param['description']}
            for param_name, param_data in flattened_params.items():
                cleaned_description = re.sub(r'e\.g\.\s*\".*?(?<!\\)\"|ex\:\s*.*?(?=\.|$)', '', param_data['description'])
                if param['custom_name']:
                    param_name = param_name.replace(param['name'], param['custom_name'])
                optionality = f"<sup>({param['optionality']})</sup>" if param['optionality'] == 'optional' else ''
                markdown += f"| params{'?' if optionality else ''}{param_name} | {param_data['type']} | {optionality}{cleaned_description if cleaned_description else ''} |\n"
    else:
        markdown += "This method takes no parameters.\n"
    return markdown

def generate_results_section(results, symbol_registry):
    """
    Generate the results section for a method.
    """
    markdown = "### Results\n"
    if results:
        markdown += """| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"""
        if len(results) == 1:
            result_info = results[0]
            if result_info.get('unwrapped'):
                result_type = result_info.get('type', '')
                result_description = result_info.get('description', '')
                markdown += f"| result | {result_type} | {result_description} |\n"
                return markdown
        markdown += f"| result | object |  |\n"
        for result in results:
            result_key = f"{result['name']}-{result['type']}"
            flattened_results = dict(symbol_registry[result_key]['flattened_description'])
            if result['description']:
                first_key = next(iter(flattened_results))
                flattened_results[first_key] = {**flattened_results[first_key], 'description': result['description']}
            for result_name, result_data in flattened_results.items():
                cleaned_description = re.sub(r'e\.g\.\s*\".*?(?<!\\)\"|ex\:\s*.*?(?=\.|$)', '', result_data['description'])
                if result['custom_name']:
                    result_name = result_name.replace(result['name'], result['custom_name'])
                optionality = f"<sup>({result['optionality']})</sup>" if result['optionality'] == 'optional' else ''
                markdown += f"| result{'?' if optionality else ''}{result_name} | {result_data['type']} | {optionality}{cleaned_description if cleaned_description else ''} |\n"
    else:
        markdown += """| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"""
        markdown += f"| result | null | On success null will be returned. |\n"
    return markdown

def generate_errors_section(errors):
    """
    Generate the errors section for a method.
    """
    markdown = ''
    if errors:
        markdown = "### Errors\n"
        markdown += """| Code | Message | Description |\n| :-------- | :-------- | :-------- |\n"""
        for error_name, error_code_and_desc in errors.items():
            markdown += f"| {error_code_and_desc['code']} | {error_name} | {error_code_and_desc['description'] if error_code_and_desc['description'] else ''} |\n"
    return markdown

def generate_method_markdown(method_name, method_info, symbol_registry, classname, all_events=None):
    """
    Generate the markdown for a specific method.
    """
    display_name = method_info.get('display_name') or method_info.get('text') or to_camel_case(method_name.split('::')[-1])
    anchor_name = method_info.get('anchor_name') or method_info.get('text') or to_camel_case(method_name.split('::')[-1])
    markdown = METHOD_MARKDOWN_TEMPLATE.format(method_name=anchor_name, method_description=method_info['details'] or method_info['brief'])
    markdown = markdown.replace(f"## *{anchor_name}*", f"## *{display_name}*")
    if 'deprecated' in method_info:
        markdown += generate_deprecated_notice(method_info.get('deprecated', ''))
    markdown += generate_async_events_section(method_info.get('async_events', []), all_events)
    markdown += generate_parameters_section(method_info['params'], symbol_registry)
    markdown += generate_results_section(method_info['results'], symbol_registry)
    markdown += generate_errors_section(method_info['errors'])
    markdown += "\n### Examples\n"
    markdown += generate_request_section(method_info['request'], '', classname)
    markdown += generate_curl_request_section(method_info['request'],'',classname)
    markdown += generate_response_section(method_info['response'], '', classname)
    retvals = method_info.get('retvals', [])
    if retvals:
        request_id = method_info.get('request', {}).get('id', 0)
        markdown += generate_error_examples_section(retvals, request_id)
    return markdown

def generate_events_section(events, all_events=None):
    """
    Generate the events section for a method.
    all_events: dict of all event definitions (from document_object.events)
    """
    markdown = "### Events\n"
    if events:
        # Only show a list of links to events, not a table
        for event in events:
            camel_event = to_camel_case(event)
            markdown += f"- [{camel_event}](#{camel_event})\n"
    else:
        markdown += "Event details will be updated soon.\n"
    return markdown

def generate_async_events_section(async_events, all_events=None):
    """
    Generate the Events Triggered section for a method.
    Links each @asyncevents entry to the matching notification anchor when available.
    """
    markdown = "### Events Triggered\n"
    if not async_events:
        markdown += "None\n"
        return markdown

    event_lookup = {}
    if all_events:
        for event_name, event_info in all_events.items():
            display_name = event_info.get('text') or to_camel_case(event_name)
            event_lookup[event_name] = display_name
            event_lookup[to_camel_case(event_name)] = display_name
            event_lookup[display_name] = display_name

    for async_event in async_events:
        display_name = event_lookup.get(async_event, async_event)
        markdown += f"- [{display_name}](#{display_name})\n"
    return markdown

def generate_properties_toc(properties, classname):
    """
    Generate the properties table of contents for the markdown file.
    """
    toc = PROPERTIES_TOC_TEMPLATE.format(classname=classname)
    for prop in properties:
        property_info = properties[prop]
        property_name = property_info.get('text') or to_camel_case(prop)
        super_script = ""
        if property_info['property'] == 'read':
            super_script = "<sup>RO</sup>"
        elif property_info['property'] == 'write':
            super_script = "<sup>WO</sup>"
        if 'deprecated' in property_info:
            super_script += "<sup>deprecated</sup>"
        toc += f"| [{property_name}](#{property_name}){super_script} | {property_info['brief'] or property_info['details']} |\n"
    return toc

def generate_property_markdown(property_name, property_info, symbol_registry, classname):
    """
    Generate the markdown for a specific property.
    """
    display_name = property_info.get('text') or to_camel_case(property_name)
    markdown = PROPERTY_MARKDOWN_TEMPLATE.format(property_name=display_name, property_description=property_info['details'] or property_info['brief'])
    if 'deprecated' in property_info:
        markdown += generate_deprecated_notice(property_info.get('deprecated', ''))
    if property_info['property'] == 'read':
        markdown += "> This property is read-only.\n"
    elif property_info['property'] == 'write':
        markdown += "> This property is write-only.\n"
    markdown += generate_events_section(property_info['events'])
    markdown += generate_values_section((property_info['results'] + property_info['params']), symbol_registry)
    markdown += "\n### Examples\n"
    if 'read' in property_info['property']:
        markdown += generate_request_section(property_info['get_request'], 'Get ', classname)
        markdown += generate_curl_request_section(property_info['get_request'],'Get ', classname)
        markdown += generate_response_section(property_info['get_response'], 'Get ', classname)
    if 'write' in property_info['property']:
        markdown += generate_request_section(property_info['set_request'], 'Set ', classname)
        markdown += generate_curl_request_section(property_info['set_request'], 'Set ',classname)
        markdown += generate_response_section(property_info['set_response'], 'Set ', classname)
    retvals = property_info.get('retvals', [])
    if retvals:
        if 'read' in property_info['property']:
            request_id = property_info.get('get_request', {}).get('id', 0)
        else:
            request_id = property_info.get('set_request', {}).get('id', 0)
        markdown += generate_error_examples_section(retvals, request_id)
    return markdown

def generate_values_section(values, symbol_registry):
    """
    Generate the values section for a property.
    """
    markdown = "### Values\n"
    if values:
        markdown += """| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"""
        for value in values:
            value_key = f"{value['name']}-{value['type']}"
            flattened_values = dict(symbol_registry[value_key]['flattened_description'])
            if value['description']:
                first_key = next(iter(flattened_values))
                flattened_values[first_key] = {**flattened_values[first_key], 'description': value['description']}
            for value_name, value_data in flattened_values.items():
                cleaned_description = re.sub(r'e\.g\.\s*\".*?(?<!\\)\"|ex\:\s*.*?(?=\.|$)', '', value_data['description'])
                markdown += f"| (property){value_name} | {value_data['type']} | {cleaned_description} |\n"
    else:
        markdown += "This property has no values.\n"
    return markdown

def generate_notifications_toc(events, classname):
    """
    Generate the notifications table of contents for the markdown file.
    """
    toc = EVENTS_TOC_TEMPLATE.replace('| Method |', '| Event |').format(classname=classname)
    for event in events:
        event_info = events[event]
        event_name = event_info.get('text') or to_camel_case(event)
        deprecated_sup = "<sup>deprecated</sup>" if 'deprecated' in event_info else ""
        toc += f"| [{event_name}](#{event_name}){deprecated_sup} | {event_info['brief'] or event_info['details']} |\n"
    return toc

def generate_notification_markdown(event_name, event_info, symbol_registry, classname):
    """
    Generate the markdown for a specific event.
    """
    camel_event = event_info.get('text') or to_camel_case(event_name)
    markdown = EVENT_MARKDOWN_TEMPLATE.format(event_name=camel_event, event_description=event_info['details'] or event_info['brief'])
    if 'deprecated' in event_info:
        markdown += generate_deprecated_notice(event_info.get('deprecated', ''))
    markdown += generate_parameters_section(event_info['params'], symbol_registry)
    markdown += "\n### Examples\n"
    request = event_info['request']
    if classname and isinstance(request, dict) and 'method' in request:
        parts = request['method'].split('.')
        if len(parts) > 2:
            parts[2] = classname
            request['method'] = '.'.join(parts)
    if isinstance(request, dict):
        request = dict(request)
    request_json = json.dumps(_convert_json_types(request), indent=4)
    markdown += EXAMPLE_NOTIFICATION_TEMPLATE.format(request_json=request_json)
    return markdown

def _convert_json_types(obj):
    """
    Recursively convert string numbers and 'true'/'false' strings to int/float/bool in a dict or list.
    """
    if isinstance(obj, dict):
        return {k: _convert_json_types(v) for k, v in obj.items()}
    elif isinstance(obj, list):
        return [_convert_json_types(i) for i in obj]
    elif isinstance(obj, str):
        if obj.lower() == 'true':
            return True
        if obj.lower() == 'false':
            return False
        try:
            if '.' in obj:
                return float(obj)
            return int(obj)
        except ValueError:
            return obj
    else:
        return obj
