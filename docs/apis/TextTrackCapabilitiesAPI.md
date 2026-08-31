<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_TextTrackCapabilities_API"></a>
# TextTrackCapabilities API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

TextTrackCapabilities interface for Thunder framework.

(Defined with ITextTrackCapabilities in [ITextTrack.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITextTrack.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the TextTrackCapabilities interface (version 1.0.0). It includes detailed specification about its methods provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

TextTrackCapabilities JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the TextTrackCapabilities interface:

TextTrackCapabilities interface methods:

| Method | Description |
| :-------- | :-------- |
| [getCapability](#method_getCapability) | Queries whether a specific TextTrack capability is supported by the implementation |
| [getCapabilities](#method_getCapabilities) | Retrieves an iterator over all supported TextTrack capabilities |

<a id="method_getCapability"></a>
## *getCapability [<sup>method</sup>](#head_Methods)*

Queries whether a specific TextTrack capability is supported by the implementation.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.capability | string | mandatory | The capability to query ex: FIREBOLT_MIGRATION (must be one of the following: *FIREBOLT_MIGRATION, UNSET*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Indicates whether the queried capability is supported |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | The capability query completed successfully. |
| ```Core::ERROR_NOT_SUPPORTED``` | Capability querying is not supported. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getCapability",
  "params": {
    "capability": "FIREBOLT_MIGRATION"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_getCapabilities"></a>
## *getCapabilities [<sup>method</sup>](#head_Methods)*

Retrieves an iterator over all supported TextTrack capabilities.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | Iterator providing the list of supported capabilities |
| result[#] | string | mandatory | *...* (must be one of the following: *FIREBOLT_MIGRATION, UNSET*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | The list of capabilities was retrieved successfully. |
| ```Core::ERROR_NOT_SUPPORTED``` | Retrieving capabilities is not supported. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getCapabilities"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "FIREBOLT_MIGRATION"
  ]
}
```

