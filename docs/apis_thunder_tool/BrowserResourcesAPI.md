<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_BrowserResources_API"></a>
# BrowserResources API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

BrowserResources interface for Thunder framework.

(Defined with IBrowserResources in [IBrowser.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IBrowser.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the BrowserResources interface (version 1.0.0). It includes detailed specification about its properties provided.

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

BrowserResources JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the BrowserResources interface:

BrowserResources interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [userscripts](#property_userscripts) | read/write | User scripts used by the browser |
| [userstylesheets](#property_userstylesheets) | read/write | User style sheets used by the browser |

<a id="property_userscripts"></a>
## *userscripts [<sup>property</sup>](#head_Properties)*

Provides access to the user scripts used by the browser.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | User scripts used by the browser |
| (property)[#] | string | mandatory |  |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.userscripts"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "..."
  ]
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.userscripts",
  "params": [
    "..."
  ]
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_userstylesheets"></a>
## *userstylesheets [<sup>property</sup>](#head_Properties)*

Provides access to the user style sheets used by the browser.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | User style sheets used by the browser |
| (property)[#] | string | mandatory |  |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.userstylesheets"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "..."
  ]
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.userstylesheets",
  "params": [
    "..."
  ]
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

