<!-- Generated automatically, DO NOT EDIT! -->
<a id="AudioOutput_Module"></a>
# AudioOutput Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AudioOutput/IAudioOutput.h)**

A AudioOutput module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IAudioOutput](#IAudioOutput)
    - [Methods](#IAudioOutput-Methods)
    - [Notifications](#IAudioOutput-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AudioOutput` module provides the following interface(s):

- IAudioOutput

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AudioOutput) |
| classname | string | Class name: *AudioOutput* |
| locator | string | Library name: *libWPEFrameworkAudioOutput.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IAudioOutput"></a>
## IAudioOutput Interface

<a id="IAudioOutput-Methods"></a>
### Methods

The following methods are provided by the IAudioOutput Interface:

| Method | Description |
| :-------- | :-------- |
| [dolbyAtmosExperience](#dolbyAtmosExperience) | Returns whether Dolby Atmos Experience is currently enabled |
| [getMuted](#getMuted) | Mutes/Unmutes the volume for given audioport |
| [getVolumeLevel](#getVolumeLevel) | Gets the volumelevel for given audioport |
| [setMuted](#setMuted) | Mutes/Unmutes the volume for given audioport |
| [setVolumeLevel](#setVolumeLevel) | Sets the volumelevel for given audioport |

<a id="dolbyAtmosExperience"></a>
## *dolbyAtmosExperience*

Combines AtmosMetadata capability (must be ATMOS_METADATA) and current sound mode (must be PASSTHRU, DOLBYDIGITALPLUS, or SOUNDMODE_AUTO) to determine the Dolby Atmos Experience state.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | true if Dolby Atmos Experience is enabled, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.AudioOutput.dolbyAtmosExperience"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.AudioOutput.dolbyAtmosExperience"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "enabled": true
    }
}
```

<a id="getMuted"></a>
## *getMuted*

Mutes/Unmutes the volume for given audioport

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Any available audio port |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.affectedAudioPort | string | The current port the muted status is fetched for |
| result.muted | bool | true if the selected audiport is muted, false otherwise |
| result.success | bool | if the request succeeds returns true |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.AudioOutput.getMuted",
    "params": {
        "audioPort": "SPEAKER0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.AudioOutput.getMuted", "params": {"audioPort": "SPEAKER0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": {
        "affectedAudioPort": "SPEAKER0",
        "muted": true,
        "success": true
    }
}
```

<a id="getVolumeLevel"></a>
## *getVolumeLevel*

Gets the volumelevel for given audioport

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Any available audio port |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.affectedAudioPort | string | The current port the volume level is fetched for |
| result.volumeLevel | int | current volume level of the audioport |
| result.success | bool | if the request succeeds returns true |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.AudioOutput.getVolumeLevel",
    "params": {
        "audioPort": "SPEAKER0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.AudioOutput.getVolumeLevel", "params": {"audioPort": "SPEAKER0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": {
        "affectedAudioPort": "SPEAKER0",
        "volumeLevel": 50,
        "success": true
    }
}
```

<a id="setMuted"></a>
## *setMuted*

Mutes/Unmutes the volume for given audioport

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Any available audio port |
| params.muted | bool | true if required to mutes the audiport, false to unmute |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | if the request succeeds returns true |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.AudioOutput.setMuted",
    "params": {
        "audioPort": "SPEAKER0",
        "muted": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.AudioOutput.setMuted", "params": {"audioPort": "SPEAKER0", "muted": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="setVolumeLevel"></a>
## *setVolumeLevel*

Sets the volumelevel for given audioport

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Any available audio port |
| params.volumeLevel | integer | Audio input volume level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | if the request succeeds returns true |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.AudioOutput.setVolumeLevel",
    "params": {
        "audioPort": "SPEAKER0",
        "volumeLevel": 50
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.AudioOutput.setVolumeLevel", "params": {"audioPort": "SPEAKER0", "volumeLevel": 50}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="IAudioOutput-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IAudioOutput Interface:

| Event | Description |
| :-------- | :-------- |
| [onDolbyAtmosExperienceChanged](#onDolbyAtmosExperienceChanged) | Notifies subscribers when the Dolby Atmos Experience state changes |
| [onMuteStatusChanged](#onMuteStatusChanged) | Notifies subscribers when the Mute status changes |
| [onVolumeLevelChanged](#onVolumeLevelChanged) | Notifies subscribers when the Volume Level changes |

<a id="onDolbyAtmosExperienceChanged"></a>
## *onDolbyAtmosExperienceChanged*

Notifies subscribers when the Dolby Atmos Experience state changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.dolbyAtmosExperience | bool | true if Dolby Atmos Experience is now enabled |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.AudioOutput.onDolbyAtmosExperienceChanged",
    "params": {
        "dolbyAtmosExperience": true
    }
}
```

<a id="onMuteStatusChanged"></a>
## *onMuteStatusChanged*

Notifies subscribers when the Mute status changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | The audiport which is muted |
| params.muted | bool | true if muted |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.AudioOutput.onMuteStatusChanged",
    "params": {
        "audioPort": "SPEAKER0",
        "muted": true
    }
}
```

<a id="onVolumeLevelChanged"></a>
## *onVolumeLevelChanged*

Notifies subscribers when the Volume Level changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | The audiport for which volume is changed |
| params.volumeLevel | integer | The changed volume level |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.AudioOutput.onVolumeLevelChanged",
    "params": {
        "audioPort": "SPEAKER0",
        "volumeLevel": 50
    }
}
```

