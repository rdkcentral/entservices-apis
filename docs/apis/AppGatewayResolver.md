<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_AppGatewayResolver_API"></a>
# AppGatewayResolver API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

AppGatewayResolver interface for Thunder framework.

(Defined with IAppGatewayResolver in [IAppGateway.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppGateway.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the AppGatewayResolver interface (version 1.0.0). It includes detailed specification about its methods provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

AppGatewayResolver JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the AppGatewayResolver interface:

AppGatewayResolver interface methods:

| Method | Description |
| :-------- | :-------- |
| [configure](#method_configure) | Adds additional Resolution paths to the gateway |

<a id="method_configure"></a>
## *configure [<sup>method</sup>](#head_Methods)*

Adds additional Resolution paths to the gateway.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.paths | array | mandatory | Adds set of paths in the order of override to be used by gateway to update the resolutions |
| params.paths[#] | string | mandatory | *...* |

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
  "method": "<callsign>.configure",
  "params": {
    "paths": [
      "..."
    ]
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

