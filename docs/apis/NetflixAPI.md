<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Netflix_API"></a>
# Netflix API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Netflix interface for Thunder framework.

(Defined by [Netflix.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Netflix interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

Netflix JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Netflix interface:

Netflix interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryreset](#method_factoryreset) <sup>deprecated</sup> | Performs a reset to factory defaults |
| [systemcommand](#method_systemcommand) | Does Netflix system command |

<a id="method_factoryreset"></a>
## *factoryreset [<sup>method</sup>](#head_Methods)*

Performs a reset to factory defaults.

> ``factoryreset`` is an alternative name for this method. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNAVAILABLE``` | Netflix is unavailable |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.factoryreset"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_systemcommand"></a>
## *systemcommand [<sup>method</sup>](#head_Methods)*

Does Netflix system command.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.command | string | mandatory | Command to send to Netflix |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNAVAILABLE``` | Netflix is unavailable |
| ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.systemcommand",
  "params": {
    "command": "config"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the Netflix interface:

Netflix interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [esn](#property_esn) | read-only | ESN value |
| [visibility](#property_visibility) | write-only | Current Netflix visibility |
| [nfrstatus](#property_nfrstatus) | read/write | native frame rate status |

StateControl interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [state](#property_state) | read/write | Running state of the service |

<a id="property_esn"></a>
## *esn [<sup>property</sup>](#head_Properties)*

Provides access to the ESN value.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | ESN value |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNAVAILABLE``` | Netflix is unavailable |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.esn"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "DADDAUFV2=00000000000000000000000000000001"
}
```

<a id="property_visibility"></a>
## *visibility [<sup>property</sup>](#head_Properties)*

Provides access to the current Netflix visibility.

> This property is **write-only**.

Also see: [visibilitychange](#event_visibilitychange)

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Current Netflix visibility (must be one of the following: *hidden, visible*) |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.visibility",
  "params": "hidden"
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

<a id="property_nfrstatus"></a>
## *nfrstatus [<sup>property</sup>](#head_Properties)*

Provides access to the native frame rate status.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Native frame rate status (must be one of the following: *disable, enable*) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Native frame rate status (must be one of the following: *disable, enable*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.nfrstatus"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "disable"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.nfrstatus",
  "params": "disable"
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

<a id="property_state"></a>
## *state [<sup>property</sup>](#head_Properties)*

Provides access to the running state of the service.

Also see: [statechange](#event_statechange)

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Running state of the service (must be one of the following: *resumed, suspended*) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Running state of the service (must be one of the following: *resumed, suspended*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "suspended"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state",
  "params": "suspended"
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

The following events are provided by the Netflix interface:

Netflix interface events:

| Notification | Description |
| :-------- | :-------- |
| [visibilitychange](#notification_visibilitychange) | Signals a visibility change of the Netflix |
| [playbackchange](#notification_playbackchange) | Signals a playback change of the Netflix |

StateControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [statechange](#notification_statechange) | Signals a state change of the service |

<a id="notification_visibilitychange"></a>
## *visibilitychange [<sup>notification</sup>](#head_Notifications)*

Signals a visibility change of the Netflix.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.hidden | boolean | mandatory | Determines if the Netflix has been hidden (true) or made visible (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "visibilitychange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.visibilitychange",
  "params": {
    "hidden": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.visibilitychange``.

<a id="notification_playbackchange"></a>
## *playbackchange [<sup>notification</sup>](#head_Notifications)*

Signals a playback change of the Netflix.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.playing | boolean | mandatory | Determines if the Netflix is in playing mode (true) or not playing (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "playbackchange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.playbackchange",
  "params": {
    "playing": true
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.playbackchange``.

<a id="notification_statechange"></a>
## *statechange [<sup>notification</sup>](#head_Notifications)*

Signals a state change of the service.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.suspended | boolean | mandatory | Determines if the service has entered suspended state (true) or resumed state (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "statechange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.statechange",
  "params": {
    "suspended": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.statechange``.

