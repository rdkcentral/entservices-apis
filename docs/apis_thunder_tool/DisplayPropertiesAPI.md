<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DisplayProperties_API"></a>
# DisplayProperties API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DisplayProperties interface for Thunder framework.

(Defined with IDisplayProperties in [IDisplayInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDisplayInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DisplayProperties interface (version 1.0.0). It includes detailed specification about its properties provided.

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

DisplayProperties JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the DisplayProperties interface:

DisplayProperties interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [colorspace](#property_colorspace) | read-only | Provides access to the display's Colour space (chroma subsampling format) |
| [framerate](#property_framerate) | read-only | Provides access to Frame Rate |
| [colourdepth](#property_colourdepth) | read-only | Provides access to display's colour Depth |
| [colorimetry](#property_colorimetry) | read-only | Provides access to display's colorimetry |
| [quantizationrange](#property_quantizationrange) | read-only | Provides access to display's Qauntization Range |
| [eotf](#property_eotf) | read-only | Provides access to display's Electro optical transfer function |

<a id="property_colorspace"></a>
## *colorspace [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the display's Colour space (chroma subsampling format).

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Colour space (must be one of the following: *FormatOther, FormatRgb444, FormatUnknown, FormatYcbcr420, FormatYcbcr422, FormatYcbcr444*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.colorspace"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "FormatOther"
}
```

<a id="property_framerate"></a>
## *framerate [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to Frame Rate.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Frame rate (must be one of the following: *Framerate11988, Framerate120, Framerate144, Framerate23976, Framerate24, Framerate25, Framerate2997, Framerate30, Framerate47952, Framerate48, Framerate50, Framerate5994, Framerate60, FramerateUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.framerate"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Framerate23976"
}
```

<a id="property_colourdepth"></a>
## *colourdepth [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to display's colour Depth.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Colour depth (must be one of the following: *Colordepth10Bit, Colordepth12Bit, Colordepth8Bit, ColordepthUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.colourdepth"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Colordepth8Bit"
}
```

<a id="property_colorimetry"></a>
## *colorimetry [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to display's colorimetry.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Display colorimetry |
| (property)[#] | string | mandatory |  (must be one of the following: *ColorimetryBt2020RgbYcbcr, ColorimetryBt2020Yccbcbrc, ColorimetryBt709, ColorimetryOprgb, ColorimetryOpycc601, ColorimetryOther, ColorimetrySmpte170M, ColorimetrySycc601, ColorimetryUnknown, ColorimetryXvycc601, ColorimetryXvycc709*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.colorimetry"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "ColorimetryOther"
  ]
}
```

<a id="property_quantizationrange"></a>
## *quantizationrange [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to display's Qauntization Range.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Quantization range (must be one of the following: *QuantizationrangeFull, QuantizationrangeLimited, QuantizationrangeUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.quantizationrange"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "QuantizationrangeLimited"
}
```

<a id="property_eotf"></a>
## *eotf [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to display's Electro optical transfer function.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Display's EOTF (must be one of the following: *EotfBt1886, EotfBt2100, EotfOther, EotfSmpteSt2084, EotfUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.eotf"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "EotfOther"
}
```

