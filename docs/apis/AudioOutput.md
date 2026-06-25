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
| [DolbyAtmosExperience](#DolbyAtmosExperience) | Returns whether Dolby Atmos Experience is currently enabled |

<a id="DolbyAtmosExperience"></a>
## *DolbyAtmosExperience*

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
    "method": "org.rdk.AudioOutput.DolbyAtmosExperience"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AudioOutput.DolbyAtmosExperience"}' http://127.0.0.1:9998/jsonrpc
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "on failure"
    }
}
```

<a id="IAudioOutput-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IAudioOutput Interface:

| Event | Description |
| :-------- | :-------- |
| [OnDolbyAtmosExperienceChanged](#OnDolbyAtmosExperienceChanged) | Notifies subscribers when the Dolby Atmos Experience state changes |

<a id="OnDolbyAtmosExperienceChanged"></a>
## *OnDolbyAtmosExperienceChanged*

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
    "id": 1,
    "method": "org.rdk.AudioOutput.OnDolbyAtmosExperienceChanged",
    "params": {
        "dolbyAtmosExperience": true
    }
}
```

