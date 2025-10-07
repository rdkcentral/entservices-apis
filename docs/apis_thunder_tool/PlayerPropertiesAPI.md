<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PlayerProperties_API"></a>
# PlayerProperties API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PlayerProperties interface for Thunder framework.

(Defined with IPlayerProperties in [IPlayerInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IPlayerInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PlayerProperties interface (version 1.0.0). It includes detailed specification about its properties provided.

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

PlayerProperties JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the PlayerProperties interface:

PlayerProperties interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [audiocodecs](#property_audiocodecs) | read-only |  |
| [videocodecs](#property_videocodecs) | read-only |  |
| [resolution](#property_resolution) | read-only | Current Video playback resolution |
| [isaudioequivalenceenabled](#property_isaudioequivalenceenabled) | read-only | Checks Loudness Equivalence in platform |

<a id="property_audiocodecs"></a>
## *audiocodecs [<sup>property</sup>](#head_Properties)*

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory |  |
| (property)[#] | string | mandatory |  (must be one of the following: *AudioAac, AudioAc3, AudioAc3Plus, AudioDts, AudioMpeg1, AudioMpeg2, AudioMpeg3, AudioMpeg4, AudioOpus, AudioUndefined, AudioVorbisOgg, AudioWav*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.audiocodecs"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "AudioAac"
  ]
}
```

<a id="property_videocodecs"></a>
## *videocodecs [<sup>property</sup>](#head_Properties)*

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory |  |
| (property)[#] | string | mandatory |  (must be one of the following: *VideoAv1, VideoH263, VideoH264, VideoH265, VideoH26510, VideoMpeg, VideoMpeg2, VideoMpeg4, VideoUndefined, VideoVp10, VideoVp8, VideoVp9*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.videocodecs"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "VideoH263"
  ]
}
```

<a id="property_resolution"></a>
## *resolution [<sup>property</sup>](#head_Properties)*

Provides access to the current Video playback resolution.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Resolution (must be one of the following: *Resolution1080I, Resolution1080I24, Resolution1080I25, Resolution1080I30, Resolution1080I50, Resolution1080P, Resolution1080P24, Resolution1080P25, Resolution1080P30, Resolution1080P50, Resolution2160P, Resolution2160P24, Resolution2160P25, Resolution2160P30, Resolution2160P50, Resolution2160P60, Resolution480I, Resolution480I24, Resolution480I25, Resolution480I30, Resolution480I50, Resolution480P, Resolution480P24, Resolution480P25, Resolution480P30, Resolution480P50, Resolution576I, Resolution576I24, Resolution576I25, Resolution576I30, Resolution576I50, Resolution576P, Resolution576P24, Resolution576P25, Resolution576P30, Resolution576P50, Resolution720P, Resolution720P24, Resolution720P25, Resolution720P30, Resolution720P50, ResolutionUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.resolution"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Resolution480I24"
}
```

<a id="property_isaudioequivalenceenabled"></a>
## *isaudioequivalenceenabled [<sup>property</sup>](#head_Properties)*

Provides access to the checks Loudness Equivalence in platform.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Enabled/disabled |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.isaudioequivalenceenabled"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

