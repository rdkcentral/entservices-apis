<!-- Generated automatically, DO NOT EDIT! -->
<a id="MiracastPlayer_Module"></a>
# MiracastPlayer Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/MiracastPlayer/IMiracastPlayer.h)**

A MiracastPlayer module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IMiracastPlayer](#IMiracastPlayer)
    - [Methods](#IMiracastPlayer-Methods)
    - [Notifications](#IMiracastPlayer-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `MiracastPlayer` module provides the following interface(s):

- IMiracastPlayer

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MiracastPlayer) |
| classname | string | Class name: *MiracastPlayer* |
| locator | string | Library name: *libWPEFrameworkMiracastPlayer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IMiracastPlayer"></a>
## IMiracastPlayer Interface

<a id="IMiracastPlayer-Methods"></a>
### Methods

The following methods are provided by the IMiracastPlayer Interface:

| Method | Description |
| :-------- | :-------- |
| [playRequest](#playRequest) | To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback |
| [setEnvArguments](#setEnvArguments) | To configure the environment arguments for the Miracast Player |
| [setVideoRectangle](#setVideoRectangle) | Set the Video Rectangle. |
| [setWesterosEnvironment](#setWesterosEnvironment) | To configure the westeros environment arguments for the Miracast Player. This will be deprecated and SetEnvArguments will be used instead. |
| [stopRequest](#stopRequest) | To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state |
| [unsetEnvArguments](#unsetEnvArguments) | To reset the environment arguments for the Miracast Player |
| [unsetWesterosEnvironment](#unsetWesterosEnvironment) | To reset the westeros environment arguments for the Miracast Player. This will be deprecated and UnsetEnvArguments will be used instead. |

<a id="playRequest"></a>
## *playRequest*

Initiates a Miracast session using the supplied source and sink device information, configures the display region, and starts media streaming.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device_parameters | object | Contains Source and Sink Device related properties |
| params.device_parameters.source_dev_ip | string | IP Address of Source Device |
| params.device_parameters.source_dev_mac | string | MAC Address of Source Device |
| params.device_parameters.source_dev_name | string | Name of Source Device |
| params.device_parameters.sink_dev_ip | string | IP Address of Sink Device |
| params.video_rectangle | object | Video rectangle to be used for Miracast playback (x, y, width, height) |
| params.video_rectangle.X | int | X coordinate of the rectangle |
| params.video_rectangle.Y | int | Y coordinate of the rectangle |
| params.video_rectangle.W | int | Width of the rectangle |
| params.video_rectangle.H | int | Height of the rectangle |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the play request operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.MiracastPlayer.playRequest",
    "params": {
        "device_parameters": "{ sourceDeviceIP: \"192.168.1.2\", sinkDeviceIP: \"192.168.1.3\" }",
        "video_rectangle": "{ x: 0, y: 0, width: 1920, height: 1080 }"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.MiracastPlayer.playRequest", "params": {"device_parameters": "{ sourceDeviceIP: \"192.168.1.2\", sinkDeviceIP: \"192.168.1.3\" }", "video_rectangle": "{ x: 0, y: 0, width: 1920, height: 1080 }"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": "{ success: true }"
}
```

<a id="setEnvArguments"></a>
## *setEnvArguments*

Applies the specified environment variables that influence the behavior and execution environment of the Miracast player.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.envArgs | array | environment arguments to be set |
| params.envArgs[#].argName | string | environment argument name |
| params.envArgs[#].argValue | string | environment argument value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the set environment arguments operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.MiracastPlayer.setEnvArguments",
    "params": [
        "[{ argName: \"WESTEROS_DISPLAY\", argValue: \"HDMI0\" }, { argName: \"WESTEROS_FULLSCREEN\", argValue: \"1\" }]"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.MiracastPlayer.setEnvArguments", "params": ["[{ argName: \"WESTEROS_DISPLAY\", argValue: \"HDMI0\" }, { argName: \"WESTEROS_FULLSCREEN\", argValue: \"1\" }]"]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": "{ success: true }"
}
```

<a id="setVideoRectangle"></a>
## *setVideoRectangle*

Sets the Video Rectangle for the Miracast Player.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.X | int | X coordinate of the rectangle |
| params.Y | int | Y coordinate of the rectangle |
| params.W | int | Width of the rectangle |
| params.H | int | Height of the rectangle |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the set video rectangle operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.MiracastPlayer.setVideoRectangle",
    "params": {
        "X": 0,
        "Y": 0,
        "W": 1920,
        "H": 1080
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.MiracastPlayer.setVideoRectangle", "params": {"X": 0, "Y": 0, "W": 1920, "H": 1080}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": "{ success: true }"
}
```

<a id="setWesterosEnvironment"></a>
## *setWesterosEnvironment*

Applies the specified westeros environment settings required for Miracast playback. This API is deprecated in favor of SetEnvArguments.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.westerosArgs | array | Westeros environment arguments to be set |
| params.westerosArgs[#].argName | string | environment argument name |
| params.westerosArgs[#].argValue | string | environment argument value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the set westeros environment operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.MiracastPlayer.setWesterosEnvironment",
    "params": [
        "[{ argName: \"WESTEROS_DISPLAY\", argValue: \"HDMI0\" }, { argName: \"WESTEROS_FULLSCREEN\", argValue: \"1\" }]"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.MiracastPlayer.setWesterosEnvironment", "params": ["[{ argName: \"WESTEROS_DISPLAY\", argValue: \"HDMI0\" }, { argName: \"WESTEROS_FULLSCREEN\", argValue: \"1\" }]"]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": "{ success: true }"
}
```

<a id="stopRequest"></a>
## *stopRequest*

Terminates the current streaming session, releases playback resources, and resets the player to an idle state.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
| params.reason_code | int | Reason code for the player stop request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the stop request |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.MiracastPlayer.stopRequest",
    "params": {
        "mac": "00:1A:2B:3C:4D:5E",
        "name": "Miracast Source Device",
        "reason_code": 200
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.MiracastPlayer.stopRequest", "params": {"mac": "00:1A:2B:3C:4D:5E", "name": "Miracast Source Device", "reason_code": 200}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": "{ success: true }"
}
```

<a id="unsetEnvArguments"></a>
## *unsetEnvArguments*

Clears all previously configured environment variables and restores the Miracast player to its default environment settings.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the unset environment arguments operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.MiracastPlayer.unsetEnvArguments"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.MiracastPlayer.unsetEnvArguments"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": "{ success: true }"
}
```

<a id="unsetWesterosEnvironment"></a>
## *unsetWesterosEnvironment*

Removes all Westeros-specific environment settings and restores the default playback environment. This API is deprecated in favor of UnsetEnvArguments.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the unset westeros environment operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.MiracastPlayer.unsetWesterosEnvironment"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.MiracastPlayer.unsetWesterosEnvironment"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": "{ success: true }"
}
```

<a id="IMiracastPlayer-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IMiracastPlayer Interface:

| Event | Description |
| :-------- | :-------- |
| [onStateChange](#onStateChange) | Notifies when a Miracast source device wants to connect |

<a id="onStateChange"></a>
## *onStateChange*

Triggered whenever the Miracast player changes state. The event provides the source device information, the current player state, and the associated reason for the state update.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Name of the client device |
| params.mac | string | MacAddress of the client device |
| params.state | string | Current state of the player (e.g., INITIATED | INPROGRESS | PLAYING | STOPPED/IDLE(Default State).). Possible values: IDLE, INITIATED, INPROGRESS, PLAYING, STOPPED, PAUSED |
| params.reason_code | string | Reason code for the player state update |
| params.reason | string | Reason for the player state update. Possible values: SUCCESS, APP_REQ_TO_STOP, SRC_DEV_REQ_TO_STOP, RTSP_FAILURE, RTSP_TIMEOUT, RTSP_NOT_SUPPORTED, GST_FAILURE, INTERNAL_FAILURE, NEW_SRC_DEV_CONNECT_REQ |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.MiracastPlayer.onStateChange",
    "params": {
        "name": "Miracast Source Device",
        "mac": "00:1A:2B:3C:4D:5E",
        "state": "PLAYING",
        "reason_code": 200,
        "reason": "SUCCESS"
    }
}
```

