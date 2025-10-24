<!-- Generated automatically, DO NOT EDIT! -->
<a id="PlayerInfo_Plugin"></a>
# PlayerInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PlayerInfo)**

A PlayerInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PlayerInfo` plugin provides an interface for PlayerInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PlayerInfo) |
| classname | string | Class name: *PlayerInfo* |
| locator | string | Library name: *libWPEFrameworkPlayerInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |


<a id="Properties"></a>
# Properties
The following properties are provided by the PlayerInfo plugin:

PlayerInfo interface properties:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [dolby_atmosmetadata](#dolby_atmosmetadata)<sup>RO</sup> | Atmos capabilities of Sink | NA |
| [dolby_enableatmosoutput](#dolby_enableatmosoutput)<sup>WO</sup> | Enable Atmos Audio Output | NA |
| [dolby_mode](#dolby_mode) | Dolby Mode | NA |
| [dolby_soundmode](#dolby_soundmode)<sup>RO</sup> | Sound Mode - Mono/Stereo/Surround | NA |
| [audioCodecs](#audioCodecs)<sup>RO</sup> |  | NA |
| [isAudioEquivalenceEnabled](#isAudioEquivalenceEnabled)<sup>RO</sup> | Checks Loudness Equivalence in platform | NA |
| [resolution](#resolution)<sup>RO</sup> | Current Video playback resolution | NA |
| [videoCodecs](#videoCodecs)<sup>RO</sup> |  | NA |

<a id="AtmosMetadata"></a>
## *AtmosMetadata [<sup>property</sup>](#Properties)*

Atmos capabilities of Sink

> This property is read-only.
### Events
No Events are associated with this method.
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
    "method": "org.rdk.PlayerInfo.atmosMetadata"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PlayerInfo.atmosMetadata"}' http://127.0.0.1:9998/jsonrpc
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

<a id="EnableAtmosOutput"></a>
## *EnableAtmosOutput [<sup>property</sup>](#Properties)*

Enable Atmos Audio Output

> This property is write-only.
### Events
No Events are associated with this method.
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
    "method": "org.rdk.PlayerInfo.enableAtmosOutput",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PlayerInfo.enableAtmosOutput", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="Mode"></a>
## *Mode [<sup>property</sup>](#Properties)*

Dolby Mode

### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | Dolby::IOutput::Type | dolby mode type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.mode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlayerInfo.mode"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "mode": ""
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlayerInfo.mode",
    "params": {
        "mode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlayerInfo.mode", "params": {"mode": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="SoundMode"></a>
## *SoundMode [<sup>property</sup>](#Properties)*

Sound Mode - Mono/Stereo/Surround

> This property is read-only.
### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | Dolby::IOutput::SoundModes |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PlayerInfo.soundMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PlayerInfo.soundMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "mode": ""
    }
}
```

<a id="AudioCodecs"></a>
## *AudioCodecs [<sup>property</sup>](#Properties)*



> This property is read-only.
### Events
No Events are associated with this method.
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

<a id="IsAudioEquivalenceEnabled"></a>
## *IsAudioEquivalenceEnabled [<sup>property</sup>](#Properties)*

Checks Loudness Equivalence in platform

> This property is read-only.
### Events
No Events are associated with this method.
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

<a id="Resolution"></a>
## *Resolution [<sup>property</sup>](#Properties)*

Current Video playback resolution

> This property is read-only.
### Events
No Events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).res | string | resolution |

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

<a id="VideoCodecs"></a>
## *VideoCodecs [<sup>property</sup>](#Properties)*



> This property is read-only.
### Events
No Events are associated with this method.
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


<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PlayerInfo plugin:

PlayerInfo interface events:

| Event | Description |
| :-------- | :-------- |
| [dolby_audiomodechanged](#dolby_audiomodechanged) |  |

<a id="audioModeChanged"></a>
## *audioModeChanged [<sup>event</sup>](#Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | Dolby::IOutput::SoundModes |  |
| params.enabled | bool |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PlayerInfo.audioModeChanged",
    "params": {
        "mode": "",
        "enabled": true
    }
}
```
