<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.PlayerInfo_Plugin"></a>
# PlayerInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/PlayerInfo/CHANGELOG.md)**

A PlayerInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Properties](#head.Properties)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `PlayerInfo` plugin provides an interface for PlayerInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PlayerInfo) |
| classname | string | Class name: *PlayerInfo* |
| locator | string | Library name: *libWPEFrameworkPlayerInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |


<a id="head.Properties"></a>
# Properties
The following properties are provided by the PlayerInfo plugin:

PlayerInfo interface properties:

| Method | Description |
| :-------- | :-------- |
| [AudioCodecs](#property.AudioCodecs)<sup>RO</sup> |  |
| [IsAudioEquivalenceEnabled](#property.IsAudioEquivalenceEnabled)<sup>RO</sup> | Checks Loudness Equivalence in platform |
| [Resolution](#property.Resolution)<sup>RO</sup> | Current Video playback resolution |
| [VideoCodecs](#property.VideoCodecs)<sup>RO</sup> |  |

<a id="property.AudioCodecs"></a>
## *AudioCodecs [<sup>property</sup>](#head.Properties)*



> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).codec | IAudioCodecIterator |  |
| (property).codec[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PlayerInfo.audioCodecs"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": [
        "AUDIO_UNDEFINED"
    ]
}
```

<a id="property.IsAudioEquivalenceEnabled"></a>
## *IsAudioEquivalenceEnabled [<sup>property</sup>](#head.Properties)*

Checks Loudness Equivalence in platform

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).ae | bool | enabled/disabled |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PlayerInfo.isAudioEquivalenceEnabled"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": true
}
```

<a id="property.Resolution"></a>
## *Resolution [<sup>property</sup>](#head.Properties)*

Current Video playback resolution

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).res | PlaybackResolution | resolution |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PlayerInfo.resolution"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": "RESOLUTION_UNKNOWN"
}
```

<a id="property.VideoCodecs"></a>
## *VideoCodecs [<sup>property</sup>](#head.Properties)*



> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).codec | IVideoCodecIterator |  |
| (property).codec[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.videoCodecs"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": [
        "VIDEO_UNDEFINED"
    ]
}
```

