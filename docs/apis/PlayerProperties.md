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

PlayerProperties JSON-RPC interface.

> This interface uses legacy ```lowercase``` naming convention. With the next major release the naming convention will change to ```camelCase```.

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
| (property) | array | mandatory | *...* |
| (property)[#] | string | mandatory | *...* (must be one of the following: *AudioAac, AudioAc3, AudioAc3Plus, AudioDts, AudioMpeg1, AudioMpeg2, AudioMpeg3, AudioMpeg4, AudioOpus, AudioUndefined, AudioVorbisOgg, AudioWav*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.audiocodecs"
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
| (property) | array | mandatory | *...* |
| (property)[#] | string | mandatory | *...* (must be one of the following: *VideoAv1, VideoH263, VideoH264, VideoH265, VideoH26510, VideoMpeg, VideoMpeg2, VideoMpeg4, VideoUndefined, VideoVp10, VideoVp8, VideoVp9*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.videocodecs"
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
| (property) | string | mandatory | Resolution (must be one of the following: *Resolution1080i, Resolution1080i24, Resolution1080i25, Resolution1080i30, Resolution1080i50, Resolution1080p, Resolution1080p24, Resolution1080p25, Resolution1080p30, Resolution1080p50, Resolution2160p, Resolution2160p24, Resolution2160p25, Resolution2160p30, Resolution2160p50, Resolution2160p60, Resolution480i, Resolution480i24, Resolution480i25, Resolution480i30, Resolution480i50, Resolution480p, Resolution480p24, Resolution480p25, Resolution480p30, Resolution480p50, Resolution576i, Resolution576i24, Resolution576i25, Resolution576i30, Resolution576i50, Resolution576p, Resolution576p24, Resolution576p25, Resolution576p30, Resolution576p50, Resolution720p, Resolution720p24, Resolution720p25, Resolution720p30, Resolution720p50, Resolution768p, ResolutionUnknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.resolution"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Resolution480i24"
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
  "method": "<callsign>.isaudioequivalenceenabled"
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

