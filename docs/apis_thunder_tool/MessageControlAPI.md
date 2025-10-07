<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_MessageControl_API"></a>
# MessageControl API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

MessageControl interface for Thunder framework.

(Defined with IMessageControl in [IMessageControl.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IMessageControl.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the MessageControl interface (version 1.0.0). It includes detailed specification about its methods and properties provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

MessageControl JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the MessageControl interface:

MessageControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [enable](#method_enable) | Enables/disables a message control |

<a id="method_enable"></a>
## *enable [<sup>method</sup>](#head_Methods)*

Enables/disables a message control.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory | Message type (must be one of the following: *Logging, Reporting, StandardError, StandardOut, Tracing*) |
| params.category | string | mandatory | Name of the message category |
| params.module | string | mandatory | Name of the module the message is originating from |
| params.enabled | boolean | mandatory | Denotes if control should be enabled (true) or disabled (false) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.enable",
  "params": {
    "type": "Logging",
    "category": "Information",
    "module": "Plugin_BluetoothControl",
    "enabled": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the MessageControl interface:

MessageControl interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [controls](#property_controls) | read-only | Retrieves a list of current message controls |

<a id="property_controls"></a>
## *controls [<sup>property</sup>](#head_Properties)*

Provides access to the retrieves a list of current message controls.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Retrieves a list of current message controls |
| (property)[#] | object | mandatory |  |
| (property)[#].type | string | mandatory | Type of message (must be one of the following: *Logging, Reporting, StandardError, StandardOut, Tracing*) |
| (property)[#].category | string | mandatory | Name of the message category |
| (property)[#].module | string | mandatory | Name of the module the message is originating from |
| (property)[#].enabled | boolean | mandatory | Denotes if the control is enabled (true) or disabled (false) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.controls"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "type": "Logging",
      "category": "Information",
      "module": "Plugin_BluetoothControl",
      "enabled": false
    }
  ]
}
```

