<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_MiracastPlayer_API"></a>
# MiracastPlayer API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

MiracastPlayer interface for Thunder framework.

(Defined with IMiracastPlayer in [IMiracastPlayer.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IMiracastPlayer.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the MiracastPlayer interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

MiracastPlayer JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the MiracastPlayer interface:

MiracastPlayer interface methods:

| Method | Description |
| :-------- | :-------- |
| [playRequest](#method_playRequest) | To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback |
| [stopRequest](#method_stopRequest) | To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state |
| [setVideoRectangle](#method_setVideoRectangle) | Set the Video Rectangle |
| [setWesterosEnvironment](#method_setWesterosEnvironment) | To configure the westeros environment arguments for the Miracast Player |
| [unsetWesterosEnvironment](#method_unsetWesterosEnvironment) | To reset the westeros environment arguments for the Miracast Player |
| [setEnvArguments](#method_setEnvArguments) | To configure the environment arguments for the Miracast Player |
| [unsetEnvArguments](#method_unsetEnvArguments) | To reset the environment arguments for the Miracast Player |

<a id="method_playRequest"></a>
## *playRequest [<sup>method</sup>](#head_Methods)*

To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.device_parameters | object | mandatory | Contains Source and Sink Device related properties |
| params.device_parameters.source_dev_ip | string | mandatory | IP Address of Source Device |
| params.device_parameters.source_dev_mac | string | mandatory | MAC Address of Source Device |
| params.device_parameters.source_dev_name | string | mandatory | Name of Source Device |
| params.device_parameters.sink_dev_ip | string | mandatory | IP Address of Sink Device |
| params.video_rectangle | object | mandatory | Video rectangle to be used for Miracast playback (x, y, width, height) |
| params.video_rectangle.X | integer | mandatory | X coordinate of the rectangle |
| params.video_rectangle.Y | integer | mandatory | Y coordinate of the rectangle |
| params.video_rectangle.W | integer | mandatory | Width of the rectangle |
| params.video_rectangle.H | integer | mandatory | Height of the rectangle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.playRequest",
  "params": {
    "device_parameters": {
      "source_dev_ip": "...",
      "source_dev_mac": "...",
      "source_dev_name": "...",
      "sink_dev_ip": "..."
    },
    "video_rectangle": {
      "X": 0,
      "Y": 0,
      "W": 0,
      "H": 0
    }
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_stopRequest"></a>
## *stopRequest [<sup>method</sup>](#head_Methods)*

To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mac | string | mandatory | MacAddress of the client device |
| params.name | string | mandatory | Name of the client device |
| params.reason_code | integer | mandatory | Reason code for the player stop request |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stopRequest",
  "params": {
    "mac": "...",
    "name": "...",
    "reason_code": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_setVideoRectangle"></a>
## *setVideoRectangle [<sup>method</sup>](#head_Methods)*

Set the Video Rectangle.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.X | integer | mandatory | X coordinate of the rectangle |
| params.Y | integer | mandatory | Y coordinate of the rectangle |
| params.W | integer | mandatory | Width of the rectangle |
| params.H | integer | mandatory | Height of the rectangle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setVideoRectangle",
  "params": {
    "X": 0,
    "Y": 0,
    "W": 0,
    "H": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_setWesterosEnvironment"></a>
## *setWesterosEnvironment [<sup>method</sup>](#head_Methods)*

To configure the westeros environment arguments for the Miracast Player. This will be deprecated and SetEnvArguments will be used instead.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.westerosArgs | array | mandatory | Westeros environment arguments to be set |
| params.westerosArgs[#] | object | mandatory |  |
| params.westerosArgs[#].argName | string | mandatory | Environment argument name |
| params.westerosArgs[#].argValue | string | mandatory | Environment argument value |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setWesterosEnvironment",
  "params": {
    "westerosArgs": [
      {
        "argName": "...",
        "argValue": "..."
      }
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_unsetWesterosEnvironment"></a>
## *unsetWesterosEnvironment [<sup>method</sup>](#head_Methods)*

To reset the westeros environment arguments for the Miracast Player. This will be deprecated and UnsetEnvArguments will be used instead.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unsetWesterosEnvironment"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_setEnvArguments"></a>
## *setEnvArguments [<sup>method</sup>](#head_Methods)*

To configure the environment arguments for the Miracast Player.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.envArgs | array | mandatory | Environment arguments to be set |
| params.envArgs[#] | object | mandatory |  |
| params.envArgs[#].argName | string | mandatory | Environment argument name |
| params.envArgs[#].argValue | string | mandatory | Environment argument value |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEnvArguments",
  "params": {
    "envArgs": [
      {
        "argName": "...",
        "argValue": "..."
      }
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_unsetEnvArguments"></a>
## *unsetEnvArguments [<sup>method</sup>](#head_Methods)*

To reset the environment arguments for the Miracast Player.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unsetEnvArguments"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the MiracastPlayer interface:

MiracastPlayer interface events:

| Notification | Description |
| :-------- | :-------- |
| [onStateChange](#notification_onStateChange) | Notifies when a Miracast source device wants to connect |

<a id="notification_onStateChange"></a>
## *onStateChange [<sup>notification</sup>](#head_Notifications)*

Notifies when a Miracast source device wants to connect.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.name | string | mandatory | Name of the client device |
| params.mac | string | mandatory | MacAddress of the client device |
| params.state | string | mandatory | Current state of the player (must be one of the following: *IDLE, INITIATED, INPROGRESS, PAUSED, PLAYING, STOPPED*) |
| params.reason_code | string | mandatory | Reason code for the player state update |
| params.reason | string | mandatory |  (must be one of the following: *APP_REQ_TO_STOP, GST_FAILURE, INTERNAL_FAILURE, NEW_SRC_DEV_CONNECT_REQ, RTSP_FAILURE, RTSP_NOT_SUPPORTED, RTSP_TIMEOUT, SRC_DEV_REQ_TO_STOP, SUCCESS*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onStateChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onStateChange",
  "params": {
    "name": "...",
    "mac": "...",
    "state": ", INITIATED | INPROGRESS | PLAYING | STOPPED/IDLE(Default State).",
    "reason_code": "...",
    "reason": "APP_REQ_TO_STOP"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onStateChange``.

