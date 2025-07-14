<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.MessageControl_Plugin"></a>
# MessageControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/MessageControl/CHANGELOG.md)**

A MessageControl plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `MessageControl` plugin provides an interface for MessageControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MessageControl) |
| classname | string | Class name: *MessageControl* |
| locator | string | Library name: *libWPEFrameworkMessageControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the MessageControl plugin:

MessageControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [enable](#method.enable) | Enables/disables a message control |

<a id="method.enable"></a>
## *enable [<sup>method</sup>](#head.Methods)*

Enables/disables a message control

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | messagetype | Type of message |
| params.category | string | Name of the message category (e.g. Information) |
| params.module | string | Name of the module the message is originating from (e.g. Plugin_BluetoothControl) |
| params.enabled | bool | Denotes if the control is enabled (true) or disabled (false) |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the MessageControl plugin:

MessageControl interface properties:

| Method | Description |
| :-------- | :-------- |
| [Controls](#property.Controls)<sup>RO</sup> | Retrieves a list of current message controls |

<a id="property.Controls"></a>
## *Controls [<sup>property</sup>](#head.Properties)*

Retrieves a list of current message controls

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).control | IControlIterator |  |
| (property).control[#].type | messagetype | Type of message |
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

