<!-- Generated automatically, DO NOT EDIT! -->
<a id="MiracastPlayer_Plugin"></a>
# MiracastPlayer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Miracast)**

A MiracastPlayer plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `MiracastPlayer` plugin provides an interface for MiracastPlayer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MiracastPlayer) |
| classname | string | Class name: *MiracastPlayer* |
| locator | string | Library name: *libWPEFrameworkMiracastPlayer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the MiracastPlayer plugin:

MiracastPlayer interface methods:

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

To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device_parameters | DeviceParameters | Contains Source and Sink Device related properties |
| params.device_parameters.source_dev_ip | string | IP Address of Source Device |
| params.device_parameters.source_dev_mac | string | MAC Address of Source Device |
| params.device_parameters.source_dev_name | string | Name of Source Device |
| params.device_parameters.sink_dev_ip | string | IP Address of Sink Device |
| params.video_rectangle | VideoRectangle | Video rectangle to be used for Miracast playback (x, y, width, height) |
| params.video_rectangle.X | int | X coordinate of the rectangle |
| params.video_rectangle.Y | int | Y coordinate of the rectangle |
| params.video_rectangle.W | int | Width of the rectangle |
| params.video_rectangle.H | int | Height of the rectangle |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
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
        "device_parameters": {
            "source_dev_ip": "",
            "source_dev_mac": "",
            "source_dev_name": "",
            "sink_dev_ip": ""
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.MiracastPlayer.playRequest", "params": {"device_parameters": {"source_dev_ip": "", "source_dev_mac": "", "source_dev_name": "", "sink_dev_ip": ""}, "video_rectangle": {"X": 0, "Y": 0, "W": 0, "H": 0}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="setEnvArguments"></a>
## *setEnvArguments*

To configure the environment arguments for the Miracast Player

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.envArgs | IEnvArgumentsIterator | environment arguments to be set |
| params.envArgs[#].argName | string | environment argument name |
| params.envArgs[#].argValue | string | environment argument value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
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
        {
            "argName": "",
            "argValue": ""
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.MiracastPlayer.setEnvArguments", "params": [{"argName": "", "argValue": ""}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="setVideoRectangle"></a>
## *setVideoRectangle*

Set the Video Rectangle.

### Events
Event details are missing in the header file documentation.
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
| result.result | Result |  |
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
        "W": 0,
        "H": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.MiracastPlayer.setVideoRectangle", "params": {"X": 0, "Y": 0, "W": 0, "H": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="setWesterosEnvironment"></a>
## *setWesterosEnvironment*

To configure the westeros environment arguments for the Miracast Player. This will be deprecated and SetEnvArguments will be used instead.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.westerosArgs | IEnvArgumentsIterator | Westeros environment arguments to be set |
| params.westerosArgs[#].argName | string | environment argument name |
| params.westerosArgs[#].argValue | string | environment argument value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
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
        {
            "argName": "",
            "argValue": ""
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.MiracastPlayer.setWesterosEnvironment", "params": [{"argName": "", "argValue": ""}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="stopRequest"></a>
## *stopRequest*

To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state

### Events
Event details are missing in the header file documentation.
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
| result.result | Result |  |
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
        "mac": "",
        "name": "",
        "reason_code": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.MiracastPlayer.stopRequest", "params": {"mac": "", "name": "", "reason_code": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="unsetEnvArguments"></a>
## *unsetEnvArguments*

To reset the environment arguments for the Miracast Player

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
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
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="unsetWesterosEnvironment"></a>
## *unsetWesterosEnvironment*

To reset the westeros environment arguments for the Miracast Player. This will be deprecated and UnsetEnvArguments will be used instead.

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
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
    "result": {
        "message": "",
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the MiracastPlayer plugin:

MiracastPlayer interface events:

| Event | Description |
| :-------- | :-------- |
| [onStateChange](#onStateChange) | Notifies when a Miracast source device wants to connect |

<a id="onStateChange"></a>
## *onStateChange*

Notifies when a Miracast source device wants to connect

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Name of the client device |
| params.mac | string | MacAddress of the client device |
| params.state | string | Current state of the player (e.g., INITIATED | INPROGRESS | PLAYING | STOPPED/IDLE(Default State).) |
| params.reason_code | string | Reason code for the player state update |
| params.reason | string | reason code Decription |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.MiracastPlayer.onStateChange",
    "params": {
        "name": "",
        "mac": "",
        "state": "STATE_IDLE",
        "reason_code": "",
        "reason": "REASON_CODE_SUCCESS"
    }
}
```
