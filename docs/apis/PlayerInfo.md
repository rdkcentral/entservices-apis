<!-- Generated automatically, DO NOT EDIT! -->
<a id="PlayerInfo_Module"></a>
# PlayerInfo Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PlayerInfo/IPlayerInfo.h)**

A PlayerInfo module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IPlayerProperties](#IPlayerProperties)
    - [Properties](#IPlayerProperties-Properties)
  - [IOutput](#IOutput)
    - [Notifications](#IOutput-Notifications)
    - [Properties](#IOutput-Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PlayerInfo` module provides the following interface(s):

- IPlayerProperties
- IOutput

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PlayerInfo) |
| classname | string | Class name: *PlayerInfo* |
| locator | string | Library name: *libWPEFrameworkPlayerInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IPlayerProperties"></a>
## IPlayerProperties Interface

<a id="IPlayerProperties-Properties"></a>
### Properties

The following properties are provided by the IPlayerProperties Interface:

| Property | Description |
| :-------- | :-------- |
| [audioCodecs](#audioCodecs)<sup>RO</sup> |  |
| [isAudioEquivalenceEnabled](#isAudioEquivalenceEnabled)<sup>RO</sup> | Checks Loudness Equivalence in platform |
| [resolution](#resolution)<sup>RO</sup> | Current Video playback resolution |
| [videoCodecs](#videoCodecs)<sup>RO</sup> |  |

<a id="audioCodecs"></a>
## *audioCodecs*



> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).codec | array |  |
| (property).codec[#] | string | Possible values: AUDIO_UNDEFINED, AUDIO_AAC, AUDIO_AC3, AUDIO_AC3_PLUS, AUDIO_DTS, AUDIO_MPEG1, AUDIO_MPEG2, AUDIO_MPEG3, AUDIO_MPEG4, AUDIO_OPUS, AUDIO_VORBIS_OGG, AUDIO_WAV |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PlayerInfo.audioCodecs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PlayerInfo.audioCodecs"}' http://127.0.0.1:9998/jsonrpc
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

<a id="isAudioEquivalenceEnabled"></a>
## *isAudioEquivalenceEnabled*

Checks Loudness Equivalence in platform

> This property is read-only.
### Events
Event details will be updated soon.
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PlayerInfo.isAudioEquivalenceEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "ae": true
    }
}
```

<a id="resolution"></a>
## *resolution*

Current Video playback resolution

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).res | string | resolution. Possible values: RESOLUTION_UNKNOWN, RESOLUTION_480I24, RESOLUTION_480I25, RESOLUTION_480I30, RESOLUTION_480I50, RESOLUTION_480I, RESOLUTION_480P24, RESOLUTION_480P25, RESOLUTION_480P30, RESOLUTION_480P50, RESOLUTION_480P, RESOLUTION_576I24, RESOLUTION_576I25, RESOLUTION_576I30, RESOLUTION_576I50, RESOLUTION_576I, RESOLUTION_576P24, RESOLUTION_576P25, RESOLUTION_576P30, RESOLUTION_576P50, RESOLUTION_576P, RESOLUTION_720P24, RESOLUTION_720P25, RESOLUTION_720P30, RESOLUTION_720P50, RESOLUTION_720P, RESOLUTION_768P, RESOLUTION_1080I24, RESOLUTION_1080I25, RESOLUTION_1080I30, RESOLUTION_1080I50, RESOLUTION_1080I, RESOLUTION_1080P24, RESOLUTION_1080P25, RESOLUTION_1080P30, RESOLUTION_1080P50, RESOLUTION_1080P, RESOLUTION_2160P24, RESOLUTION_2160P25, RESOLUTION_2160P30, RESOLUTION_2160P50, RESOLUTION_2160P60, RESOLUTION_2160P |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PlayerInfo.resolution"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PlayerInfo.resolution"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "res": "RESOLUTION_UNKNOWN"
    }
}
```

<a id="videoCodecs"></a>
## *videoCodecs*



> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).codec | array |  |
| (property).codec[#] | string | Possible values: VIDEO_UNDEFINED, VIDEO_H263, VIDEO_H264, VIDEO_H265, VIDEO_H265_10, VIDEO_MPEG, VIDEO_MPEG2, VIDEO_MPEG4, VIDEO_VP8, VIDEO_VP9, VIDEO_VP10, VIDEO_AV1 |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.videoCodecs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlayerInfo.videoCodecs"}' http://127.0.0.1:9998/jsonrpc
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

---

<a id="IOutput"></a>
## IOutput Interface

<a id="IOutput-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IOutput Interface:

| Event | Description |
| :-------- | :-------- |
| [dolby_audiomodechanged](#dolby_audiomodechanged) |  |

<a id="dolby_audiomodechanged"></a>
## *dolby_audiomodechanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | string | Possible values: UNKNOWN, MONO, STEREO, SURROUND, PASSTHRU, DOLBYDIGITAL, DOLBYDIGITALPLUS, SOUNDMODE_AUTO |
| params.enabled | bool |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PlayerInfo.dolby_audiomodechanged",
    "params": {
        "mode": "UNKNOWN",
        "enabled": true
    }
}
```

<a id="IOutput-Properties"></a>
### Properties

The following properties are provided by the IOutput Interface:

| Property | Description |
| :-------- | :-------- |
| [dolby_atmosmetadata](#dolby_atmosmetadata)<sup>RO</sup> | Atmos capabilities of Sink |
| [dolby_enableatmosoutput](#dolby_enableatmosoutput)<sup>WO</sup> | Enable Atmos Audio Output |
| [dolby_mode](#dolby_mode) | Dolby Mode |
| [dolby_soundmode](#dolby_soundmode)<sup>RO</sup> | Sound Mode - Mono/Stereo/Surround |

<a id="dolby_atmosmetadata"></a>
## *dolby_atmosmetadata*

Atmos capabilities of Sink

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).supported | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PlayerInfo.dolby_atmosmetadata"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PlayerInfo.dolby_atmosmetadata"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "supported": true
    }
}
```

<a id="dolby_enableatmosoutput"></a>
## *dolby_enableatmosoutput*

Enable Atmos Audio Output

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enable | bool | enable/disable |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PlayerInfo.dolby_enableatmosoutput",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PlayerInfo.dolby_enableatmosoutput", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="dolby_mode"></a>
## *dolby_mode*

Dolby Mode

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | string | dolby mode type. Possible values: DIGITAL_PCM, DIGITAL_PLUS, DIGITAL_AC3, AUTO, DIGITAL_PASSTHROUGH, MS12 |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.dolby_mode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlayerInfo.dolby_mode"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "mode": "DIGITAL_PCM"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.dolby_mode",
    "params": {
        "mode": "DIGITAL_PCM"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlayerInfo.dolby_mode", "params": {"mode": "DIGITAL_PCM"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="dolby_soundmode"></a>
## *dolby_soundmode*

Sound Mode - Mono/Stereo/Surround

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | string | Possible values: UNKNOWN, MONO, STEREO, SURROUND, PASSTHRU, DOLBYDIGITAL, DOLBYDIGITALPLUS, SOUNDMODE_AUTO |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PlayerInfo.dolby_soundmode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PlayerInfo.dolby_soundmode"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "mode": "UNKNOWN"
    }
}
```

