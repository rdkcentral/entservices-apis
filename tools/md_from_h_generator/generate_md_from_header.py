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

# Templates
HEADER_TOC_TEMPLATE = """<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.{classname}_Plugin"></a>
# {classname} Plugin

**Version: [{version}](https://github.com/rdkcentral/rdkservices/blob/main/{classname}/CHANGELOG.md)**

A {classname} plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
"""

HEADER_DESCRIPTION_TEMPLATE = """
<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `{classname}` plugin provides an interface for {classname}.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
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
<a id="head.Methods"></a>
# Methods

The following methods are provided by the {classname} plugin:

{classname} interface methods:

| Method | Description |
| :-------- | :-------- |
"""

METHOD_MARKDOWN_TEMPLATE = """
<a id="method.{method_name}"></a>
## *{method_name} [<sup>method</sup>](#head.Methods)*

{method_description}

"""

PROPERTIES_TOC_TEMPLATE = """
<a id="head.Properties"></a>
# Properties
The following properties are provided by the {classname} plugin:

{classname} interface properties:

| Method | Description |
| :-------- | :-------- |
"""

PROPERTY_MARKDOWN_TEMPLATE = """
<a id="property.{property_name}"></a>
## *{property_name} [<sup>property</sup>](#head.Properties)*

{property_description}

"""

EVENTS_TOC_TEMPLATE = """
<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the {classname} plugin:

{classname} interface events:

| Event | Description |
| :-------- | :-------- |
"""

EVENT_MARKDOWN_TEMPLATE = """
<a id="event.{event_name}"></a>
## *{event_name} [<sup>event</sup>](#head.Notifications)*

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

def to_camel_case(name):
    """Convert UpperCamelCase to lowerCamelCase."""
    return name[0].lower() + name[1:] if name and name[0].isupper() else name

def generate_header_toc(classname, document_object, version="1.0.0"):
    """
    Generate the header table of contents for the markdown file.
    """
    toc = HEADER_TOC_TEMPLATE.format(classname=classname, version=version)
    if len(document_object.methods.values()) > 0:
        toc += "- [Methods](#head.Methods)\n"
    if len(document_object.properties.values()) > 0:
        toc += "- [Properties](#head.Properties)\n"
    if len(document_object.events.values()) > 0:
        toc += "- [Notifications](#head.Notifications)\n"
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

def generate_methods_toc(methods, classname):
    """
    Generate the methods table of contents for the markdown file.
    """
    toc = METHODS_TOC_TEMPLATE.format(classname=classname)
    for method in methods:
        method_info = methods[method]
        method_name = method_info.get('text') or to_camel_case(method)
        toc += f"| [{method_name}](#method.{method_name}) | {method_info['brief'] or method_info['details']} |\n"
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
            flattened_params = symbol_registry[param_key]['flattened_description']
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
            result_info = symbol_registry[f"{results[0]['name']}-{results[0]['type']}"]
            if 'unwrapped' in result_info and result_info['unwrapped']:
                markdown += f"| result | {result_info['type']} | {result_info['description']} |\n"
                return markdown
        markdown += f"| result | object |  |\n"
        for result in results:
            flattened_results = symbol_registry[f"{result['name']}-{result['type']}"]['flattened_description']
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
    method_name = to_camel_case(method_name)
    markdown = METHOD_MARKDOWN_TEMPLATE.format(method_name=method_name, method_description=method_info['details'] or method_info['brief'])
    markdown += generate_events_section(method_info['events'], all_events)
    markdown += generate_parameters_section(method_info['params'], symbol_registry)
    markdown += generate_results_section(method_info['results'], symbol_registry)
    markdown += generate_errors_section(method_info['errors'])
    markdown += "\n### Examples\n"
    markdown += generate_request_section(method_info['request'], '', classname)
    markdown += generate_curl_request_section(method_info['request'],'',classname)
    markdown += generate_response_section(method_info['response'], '', classname)
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
            markdown += f"- [{camel_event}](#event.{camel_event})\n"
    else:
        markdown += "No events are associated with this method.\n"
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
        toc += f"| [{property_name}](#property.{property_name}){super_script} | {property_info['brief'] or property_info['details']} |\n"
    return toc

def generate_property_markdown(property_name, property_info, symbol_registry, classname):
    """
    Generate the markdown for a specific property.
    """
    markdown = PROPERTY_MARKDOWN_TEMPLATE.format(property_name=property_name, property_description=property_info['details'] or property_info['brief'])
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
    return markdown

def generate_values_section(values, symbol_registry):
    """
    Generate the values section for a property.
    """
    markdown = "### Values\n"
    if values:
        markdown += """| Name | Type | Description |\n| :-------- | :-------- | :-------- |\n"""
        for value in values:
            flattened_values = symbol_registry[f"{value['name']}-{value['type']}"]['flattened_description']
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
        toc += f"| [{event_name}](#event.{event_name}) | {event_info['brief'] or event_info['details']} |\n"
    return toc

def generate_notification_markdown(event_name, event_info, symbol_registry, classname):
    """
    Generate the markdown for a specific event.
    """
    camel_event = to_camel_case(event_name)
    markdown = EVENT_MARKDOWN_TEMPLATE.format(event_name=camel_event, event_description=event_info['details'] or event_info['brief'])
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
