<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_AudioOutput_API"></a>
# AudioOutput API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

AudioOutput interface for Thunder framework.

(Defined with IAudioOutput in [IAudioOutput.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAudioOutput.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the AudioOutput interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

AudioOutput JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the AudioOutput interface:

AudioOutput interface methods:

| Method | Description |
| :-------- | :-------- |
| [dolbyAtmosExperience](#method_dolbyAtmosExperience) | Returns whether Dolby Atmos Experience is currently enabled |

<a id="method_dolbyAtmosExperience"></a>
## *dolbyAtmosExperience [<sup>method</sup>](#head_Methods)*

Returns whether Dolby Atmos Experience is currently enabled.

### Description

Combines AtmosMetadata capability (must be ATMOS_METADATA) and current sound mode (must be PASSTHRU, DOLBYDIGITALPLUS, or SOUNDMODE_AUTO) to determine the Dolby Atmos Experience state.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | True if Dolby Atmos Experience is enabled, false otherwise |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.dolbyAtmosExperience"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the AudioOutput interface:

AudioOutput interface events:

| Notification | Description |
| :-------- | :-------- |
| [onDolbyAtmosExperienceChanged](#notification_onDolbyAtmosExperienceChanged) | Notifies subscribers when the Dolby Atmos Experience state changes |

<a id="notification_onDolbyAtmosExperienceChanged"></a>
## *onDolbyAtmosExperienceChanged [<sup>notification</sup>](#head_Notifications)*

Notifies subscribers when the Dolby Atmos Experience state changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.dolbyAtmosExperience | boolean | mandatory | True if Dolby Atmos Experience is now enabled |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onDolbyAtmosExperienceChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDolbyAtmosExperienceChanged",
  "params": {
    "dolbyAtmosExperience": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDolbyAtmosExperienceChanged``.

