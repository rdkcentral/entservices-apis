<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Player_Info_API"></a>
# Player Info API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PlayerInfo interface for Thunder framework.

(Defined by [PlayerInfo.json](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/PlayerInfo.json))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PlayerInfo interface (version 1.0.0). It includes detailed specification about its properties provided.

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

PlayerInfo JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the PlayerInfo interface:

PlayerInfo interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [playerinfo](#property_playerinfo) | read-only | Player general information |
| [dolbymode](#property_dolbymode) | read/write | Dolby output mode |

<a id="property_playerinfo"></a>
## *playerinfo [<sup>property</sup>](#head_Properties)*

Provides access to the player general information.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Player general information |
| (property)?.audio | array | optional | *...* |
| (property)?.audio[#] | string | optional | Audio Codec supported by the platform (must be one of the following: *AAC, AC3, AC3Plus, DTS, MPEG1, MPEG2, MPEG3, MPEG4, OPUS, Undefined, VorbisOGG, WAV*) |
| (property)?.video | array | optional | *...* |
| (property)?.video[#] | string | optional | Video Codec supported by the platform (must be one of the following: *AV1, H263, H264, H265, H26510, MPEG, Undefined, VP10, VP8, VP9*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.playerinfo"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "audio": [
      "AudioAAC"
    ],
    "video": [
      "VideoH264"
    ]
  }
}
```

<a id="property_dolbymode"></a>
## *dolbymode [<sup>property</sup>](#head_Properties)*

Provides access to the dolby output mode.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Dolby output mode |
| (property).value | string | mandatory | *...* (must be one of the following: *AUTO, DIGITAL_AC3, DIGITAL_PCM, DIGITAL_PLUS*) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Dolby output mode (must be one of the following: *AUTO, DIGITAL_AC3, DIGITAL_PCM, DIGITAL_PLUS*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.dolbymode"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "DIGITAL_PLUS"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.dolbymode",
  "params": {
    "value": "DIGITAL_PLUS"
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

