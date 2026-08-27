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
| [getAudioConfig](#getAudioConfig) | Gets an audio configuration state. |
| [getSupportedAudioConfigs](#getSupportedAudioConfigs) | Returns list of supported audio configurations. |
| [setAudioConfig](#setAudioConfig) | Sets an audio configuration state. |

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
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.AudioOutput.dolbyAtmosExperience"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AudioOutput.dolbyAtmosExperience"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "enabled": true
    }
}
```

<a id="getAudioConfig"></a>
## *getAudioConfig*

Returns whether the specified AudioConfig is currently enabled.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioConfig | string | Audio configuration. e.g. `CONTINUOUS_AUDIO_OUTPUT` |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | true if the configuration is currently enabled, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.AudioOutput.getAudioConfig",
    "params": {
        "audioConfig": "CONTINUOUS_AUDIO_OUTPUT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AudioOutput.getAudioConfig", "params": {"audioConfig": "CONTINUOUS_AUDIO_OUTPUT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "enabled": true
    }
}
```


#### Error Response (Core::ERROR_BAD_REQUEST)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 240,
        "message": "for unsupported configuration"
    }
}
```

<a id="getSupportedAudioConfigs"></a>
## *getSupportedAudioConfigs*

Returns the list of audio configuration available for this device that the clients can enable or disable.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.audioConfigs | array | List of supported audio configurations |
| result.audioConfigs[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.AudioOutput.getSupportedAudioConfigs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AudioOutput.getSupportedAudioConfigs"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": [
        "CONTINUOUS_AUDIO_OUTPUT"
    ]
}
```

<a id="setAudioConfig"></a>
## *setAudioConfig*

Enables or disables the specified audio configuration based on the `enabled` parameter.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioConfig | string | Audio configuration. e.g. `CONTINUOUS_AUDIO_OUTPUT` |
| params.enabled | bool | true to enable the configuration, false to disable it |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AudioOutput.setAudioConfig",
    "params": {
        "audioConfig": "CONTINUOUS_AUDIO_OUTPUT",
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AudioOutput.setAudioConfig", "params": {"audioConfig": "CONTINUOUS_AUDIO_OUTPUT", "enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_BAD_REQUEST)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 240,
        "message": "for unsupported configuration"
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
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.AudioOutput.onDolbyAtmosExperienceChanged",
    "params": {
        "dolbyAtmosExperience": true
    }
}
```

