<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Output_API"></a>
# Output API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Output interface for Thunder framework.

(Defined with Dolby::IOutput in [IDolby.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDolby.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Output interface (version 1.0.0). It includes detailed specification about its properties provided and notifications sent.

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

Output JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the Output interface:

Dolby Output interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [dolby atmosmetadata](#property_dolby_atmosmetadata) | read-only | Atmos capabilities of Sink |
| [dolby soundmode](#property_dolby_soundmode) | read-only | Sound Mode - Mono/Stereo/Surround |
| [dolby enableatmosoutput](#property_dolby_enableatmosoutput) | write-only | Enable Atmos Audio Output |
| [dolby mode](#property_dolby_mode) | read/write | Dolby Mode |

<a id="property_dolby_atmosmetadata"></a>
## *dolby_atmosmetadata [<sup>property</sup>](#head_Properties)*

Provides access to the atmos capabilities of Sink.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Atmos capabilities of Sink |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.dolby_atmosmetadata"
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

<a id="property_dolby_soundmode"></a>
## *dolby_soundmode [<sup>property</sup>](#head_Properties)*

Provides access to the sound Mode - Mono/Stereo/Surround.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Sound Mode - Mono/Stereo/Surround (must be one of the following: *Dolbydigital, Dolbydigitalplus, Mono, Passthru, SoundmodeAuto, Stereo, Surround, Unknown*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.dolby_soundmode"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Mono"
}
```

<a id="property_dolby_enableatmosoutput"></a>
## *dolby_enableatmosoutput [<sup>property</sup>](#head_Properties)*

Provides access to the enable Atmos Audio Output.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Enable/disable |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.dolby_enableatmosoutput",
  "params": false
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

<a id="property_dolby_mode"></a>
## *dolby_mode [<sup>property</sup>](#head_Properties)*

Provides access to the dolby Mode.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Dolby mode type (must be one of the following: *Auto, DigitalAc3, DigitalPassthrough, DigitalPcm, DigitalPlus, Ms12*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.dolby_mode"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "DigitalPlus"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.dolby_mode",
  "params": "DigitalPlus"
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Output interface:

Dolby Output interface events:

| Notification | Description |
| :-------- | :-------- |
| [dolby audiomodechanged](#notification_dolby_audiomodechanged) |  |

<a id="notification_dolby_audiomodechanged"></a>
## *dolby_audiomodechanged [<sup>notification</sup>](#head_Notifications)*

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mode | string | mandatory |  (must be one of the following: *Dolbydigital, Dolbydigitalplus, Mono, Passthru, SoundmodeAuto, Stereo, Surround, Unknown*) |
| params.enabled | boolean | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "dolby_audiomodechanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.dolby_audiomodechanged",
  "params": {
    "mode": "Mono",
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.dolby_audiomodechanged``.

