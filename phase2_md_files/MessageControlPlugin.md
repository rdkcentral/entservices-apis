<!-- Generated automatically, DO NOT EDIT! -->
<a id="MessageControl_Plugin"></a>
# MessageControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/MessageControl/IMessageControl.h)**

A MessageControl plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `MessageControl` plugin provides an interface for MessageControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MessageControl) |
| classname | string | Class name: *MessageControl* |
| locator | string | Library name: *libWPEFrameworkMessageControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the MessageControl plugin:

MessageControl interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [enable](#enable) | Enables/disables a message control | NA |

<a id="enable"></a>
## *enable [<sup>method</sup>](#Methods)*

Enables/disables a message control

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Type of message |
| params.category | string | Name of the message category (e.g. Information) |
| params.module | string | Name of the module the message is originating from (e.g. Plugin_BluetoothControl) |
| params.enabled | bool | Denotes if the control is enabled (true) or disabled (false) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.MessageControl.enable",
    "params": {
        "type": "TRACING",
        "category": "",
        "module": "",
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.MessageControl.enable", "params": {"type": "TRACING", "category": "", "module": "", "enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the MessageControl plugin:

MessageControl interface properties:

| Property | Description | Event |
| :-------- | :-------- |:-------- |
| [controls](#controls)<sup>RO</sup> | Retrieves a list of current message controls | NA |

<a id="Controls"></a>
## *Controls [<sup>property</sup>](#Properties)*

Retrieves a list of current message controls

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).control | IControlIterator |  |
| (property).control[#].type | string | Type of message |
| (property).control[#].category | string | Name of the message category (e.g. Information) |
| (property).control[#].module | string | Name of the module the message is originating from (e.g. Plugin_BluetoothControl) |
| (property).control[#].enabled | bool | Denotes if the control is enabled (true) or disabled (false) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.MessageControl.controls"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.MessageControl.controls"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": [
        {
            "type": "TRACING",
            "category": "",
            "module": "",
            "enabled": true
        }
    ]
}
```

