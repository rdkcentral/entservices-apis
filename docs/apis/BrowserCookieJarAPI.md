<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Browser_CookieJar_API"></a>
# Browser CookieJar API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

BrowserCookieJar interface for Thunder framework.

(Defined by [BrowserCookieJar.json](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/BrowserCookieJar.json))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the BrowserCookieJar interface (version 1.0.0). It includes detailed specification about its properties provided.

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

Browser CookieJar JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the BrowserCookieJar interface:

BrowserCookieJar interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [cookiejar](#property_cookiejar) | read/write | User preferred languages |

<a id="property_cookiejar"></a>
## *cookiejar [<sup>property</sup>](#head_Properties)*

Provides access to the user preferred languages.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | User preferred languages |
| (property).version | integer | mandatory | Version of payload format |
| (property).checksum | integer | mandatory | The checksum of the string used for payload creation |
| (property).payload | string | mandatory | Base64 string representation of compressed and encrypted cookies |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | User preferred languages |
| (property).version | integer | mandatory | Version of payload format |
| (property).checksum | integer | mandatory | The checksum of the string used for payload creation |
| (property).payload | string | mandatory | Base64 string representation of compressed and encrypted cookies |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.cookiejar"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "version": 0,
    "checksum": 0,
    "payload": "..."
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.cookiejar",
  "params": {
    "version": 0,
    "checksum": 0,
    "payload": "..."
  }
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

