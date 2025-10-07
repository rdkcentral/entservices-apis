<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_HDRProperties_API"></a>
# HDRProperties API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

HDRProperties interface for Thunder framework.

(Defined with IHDRProperties in [IDisplayInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDisplayInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the HDRProperties interface (version 1.0.0). It includes detailed specification about its properties provided.

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

HDRProperties JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the HDRProperties interface:

HDRProperties interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [tvcapabilities](#property_tvcapabilities) | read-only | HDR formats supported by TV |
| [stbcapabilities](#property_stbcapabilities) | read-only | HDR formats supported by STB |
| [hdrsetting](#property_hdrsetting) | read-only | HDR format in use |

<a id="property_tvcapabilities"></a>
## *tvcapabilities [<sup>property</sup>](#head_Properties)*

Provides access to the HDR formats supported by TV.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | HDR formats supported by TV |
| (property)[#] | string | mandatory |  (must be one of the following: *Hdr10, Hdr10Plus, HdrDolbyvision, HdrHlg, HdrOff, HdrSdr, HdrTechnicolor*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.tvcapabilities"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "Hdr10"
  ]
}
```

<a id="property_stbcapabilities"></a>
## *stbcapabilities [<sup>property</sup>](#head_Properties)*

Provides access to the HDR formats supported by STB.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | HDR formats supported by STB |
| (property)[#] | string | mandatory |  (must be one of the following: *Hdr10, Hdr10Plus, HdrDolbyvision, HdrHlg, HdrOff, HdrSdr, HdrTechnicolor*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stbcapabilities"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "Hdr10"
  ]
}
```

<a id="property_hdrsetting"></a>
## *hdrsetting [<sup>property</sup>](#head_Properties)*

Provides access to the HDR format in use.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | HDR format (must be one of the following: *Hdr10, Hdr10Plus, HdrDolbyvision, HdrHlg, HdrOff, HdrSdr, HdrTechnicolor*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.hdrsetting"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Hdr10"
}
```

