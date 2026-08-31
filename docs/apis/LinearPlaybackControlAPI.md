<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Linear_Playback_Control_API"></a>
# Linear Playback Control API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

LinearPlaybackControl interface for Thunder framework.

(Defined by [LinearPlaybackControl.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the LinearPlaybackControl interface (version 1.0.0). It includes detailed specification about its properties provided and notifications sent.

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

Linear Playback Control JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the LinearPlaybackControl interface:

LinearPlaybackControl interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [channel](#property_channel) | read/write | Current channel |
| [seek](#property_seek) | read/write | TSB seek position offset, from live position, in seconds |
| [trickPlay](#property_trickPlay) | read/write | Trick play speed and direction |
| [status](#property_status) | read-only | Current TSB status information containing buffer size, seek position and health status |
| [tracing](#property_tracing) | read/write | Tracing enable/disable flag |

<a id="property_channel"></a>
## *channel [<sup>property</sup>](#head_Properties)*

Provides access to the current channel.

> The *muxid* parameter shall be passed as the index to the property, i.e. ``channel@<muxid>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| muxid | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Current channel |
| (property).channel | string | mandatory | Channel address |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Current channel |
| (property).channel | string | mandatory | Channel address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_BAD_REQUEST``` | Bad JSON param data format. |
| ```ERROR_READ_ERROR``` | Error reading file or parsing one or more values. |
| ```ERROR_WRITE_ERROR``` | Error writing to file. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.channel@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "channel": "chan_select"
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.channel@0",
  "params": {
    "channel": "chan_select"
  }
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

<a id="property_seek"></a>
## *seek [<sup>property</sup>](#head_Properties)*

Provides access to the TSB seek position offset, from live position, in seconds.

> The *muxid* parameter shall be passed as the index to the property, i.e. ``seek@<muxid>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| muxid | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | TSB seek position offset, from live position, in seconds |
| (property).seekPosInSeconds | integer | mandatory | TSB seek position offset from live in seconds. The value must be an unsigned integer. If the value exceeds the current TSB size, the seek position will be reduced accordingly |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | TSB seek position offset, from live position, in seconds |
| (property).seekPosInSeconds | integer | mandatory | TSB seek position offset from live in seconds. The value must be an unsigned integer. If the value exceeds the current TSB size, the seek position will be reduced accordingly |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_BAD_REQUEST``` | Bad JSON param data format. |
| ```ERROR_READ_ERROR``` | Error reading file or parsing one or more values. |
| ```ERROR_WRITE_ERROR``` | Error writing to file. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.seek@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "seekPosInSeconds": 0
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.seek@0",
  "params": {
    "seekPosInSeconds": 0
  }
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

<a id="property_trickPlay"></a>
## *trickPlay [<sup>property</sup>](#head_Properties)*

Provides access to the trick play speed and direction.

> The *muxid* parameter shall be passed as the index to the property, i.e. ``trickPlay@<muxid>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| muxid | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Trick play speed and direction |
| (property).speed | integer | mandatory | Trick play speed. The direction is defined by the sign of speed, where a negative value means rewind and positive value means fast forward |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Trick play speed and direction |
| (property).speed | integer | mandatory | Trick play speed. The direction is defined by the sign of speed, where a negative value means rewind and positive value means fast forward |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_BAD_REQUEST``` | Bad JSON param data format. |
| ```ERROR_READ_ERROR``` | Error reading file or parsing one or more values. |
| ```ERROR_WRITE_ERROR``` | Error writing to file. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.trickPlay@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "speed": -4
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.trickPlay@0",
  "params": {
    "speed": -4
  }
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

<a id="property_status"></a>
## *status [<sup>property</sup>](#head_Properties)*

Provides access to the current TSB status information containing buffer size, seek position and health status.

> This property is **read-only**.

> The *muxid* parameter shall be passed as the index to the property, i.e. ``status@<muxid>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| muxid | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Current TSB status information containing buffer size, seek position and health status |
| (property).maxSizeInBytes | integer | mandatory | Maximum TSB size in bytes |
| (property).currentSizeInBytes | integer | mandatory | Current TSB size in bytes |
| (property).currentSizeInSeconds | integer | mandatory | Current TSB size in seconds |
| (property).seekPosInBytes | integer | mandatory | Current TSB seek position offset from live in bytes. The value is an unsigned integer and cannot exceed the current TSB size in bytes |
| (property).seekPosInSeconds | integer | mandatory | Current TSB seek position offset from live in seconds. The value is an unsigned integer and cannot exceed the current TSB size in seconds |
| (property).trickPlaySpeed | integer | mandatory | Current trick play speed and direction. The direction is defined by the sign of speed, where a negative value means rewind and positive value means fast forward |
| (property).streamSourceLost | boolean | mandatory | Boolean indicating if the buffer source is lost (true) as a result of e.g. network connectivity issues or not (false) |
| (property).streamSourceLossCount | integer | mandatory | Number of times the streaming is lost and the TSB stopped receiving data from the stream source, during a valid channel selected |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_READ_ERROR``` | Error reading file or parsing one or more values. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.status@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "maxSizeInBytes": 0,
    "currentSizeInBytes": 0,
    "currentSizeInSeconds": 0,
    "seekPosInBytes": 0,
    "seekPosInSeconds": 0,
    "trickPlaySpeed": -4,
    "streamSourceLost": false,
    "streamSourceLossCount": 0
  }
}
```

<a id="property_tracing"></a>
## *tracing [<sup>property</sup>](#head_Properties)*

Provides access to the tracing enable/disable flag.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Tracing enable/disable flag |
| (property).tracing | boolean | mandatory | Tracing enable (true) / disable (false) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Tracing enable/disable flag |
| (property).tracing | boolean | mandatory | Tracing enable (true) / disable (false) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | General failure. |
| ```ERROR_BAD_REQUEST``` | Bad JSON param data format. |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.tracing"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "tracing": true
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.tracing",
  "params": {
    "tracing": true
  }
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

The following events are provided by the LinearPlaybackControl interface:

LinearPlaybackControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [speedchanged](#notification_speedchanged) | Indicates that the trick play speed has changed |

<a id="notification_speedchanged"></a>
## *speedchanged [<sup>notification</sup>](#head_Notifications)*

Indicates that the trick play speed has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.speed | integer | mandatory | New trick play speed. The direction is defined by the sign of speed, where a negative value means rewind and positive value means fast forward |
| params.muxId | integer | mandatory | Stream muxId |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "speedchanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.speedchanged",
  "params": {
    "speed": -4,
    "muxId": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.speedchanged``.

