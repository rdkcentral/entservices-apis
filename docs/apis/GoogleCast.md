<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_GoogleCast_API"></a>
# GoogleCast API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

GoogleCast interface for Thunder framework.

(Defined with IGoogleCast in [IGoogleCast.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IGoogleCast.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the GoogleCast interface (version 1.0.0). It includes detailed specification about its properties provided and notifications sent.

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

GoogleCast JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the GoogleCast interface:

GoogleCast interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [getCastStatus](#property_getCastStatus) / [cast_status](#property_getCastStatus) | read-only | Status of cast shell interfacing via Cast control API |

<a id="property_getCastStatus"></a>
## *getCastStatus [<sup>property</sup>](#head_Properties)*

Provides access to the status of cast shell interfacing via Cast control API.

> This property is **read-only**.

> ``cast_status`` is an alternative name for this 

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Status of cast shell interfacing via Cast control API |
| (property).cast_build_number | string | mandatory | Build number of the currently running Cast shell |
| (property).cast_state | string | mandatory | Current cast shell state. (must be one of the following: *FORCED_UPDATE, NOT_SETUP, OFFLINE, READY_TO_CAST, STARTING, SUSPENDED, UNKNOWN*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Indicates successful retrieval of cast status. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getCastStatus"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "cast_build_number": "...",
    "cast_state": "STARTING"
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the GoogleCast interface:

GoogleCast interface events:

| Notification | Description |
| :-------- | :-------- |
| [onStatusChanged](#notification_onStatusChanged) / [onStatusChange](#notification_onStatusChanged) | Notifies that the GoogleCast status changed |

<a id="notification_onStatusChanged"></a>
## *onStatusChanged [<sup>notification</sup>](#head_Notifications)*

Notifies that the GoogleCast status changed.

> ``onStatusChange`` is an alternative name for this notification.

### Notification Parameters

This notification carries no parameters.

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onStatusChanged"
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onStatusChanged``.

