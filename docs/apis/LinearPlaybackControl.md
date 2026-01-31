<!-- Generated automatically, DO NOT EDIT! -->
<a id="LinearPlaybackControl_Plugin"></a>
# LinearPlaybackControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/LinearPlaybackControl/ILinearPlaybackControl.h)**

A LinearPlaybackControl plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `LinearPlaybackControl` plugin provides an interface for LinearPlaybackControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LinearPlaybackControl) |
| classname | string | Class name: *LinearPlaybackControl* |
| locator | string | Library name: *libWPEFrameworkLinearPlaybackControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the LinearPlaybackControl plugin:

LinearPlaybackControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getChannel](#getChannel) | Gets channel URI for a certain demuxer ID |
| [getSeek](#getSeek) | Gets seek position for current stream for a certain demuxer ID |
| [getStatus](#getStatus) | Gets TSB status (seek position, TSB size and health info) for a certain demuxer ID |
| [getTracing](#getTracing) | Gets tracing enabled/disabled |
| [getTrickPlay](#getTrickPlay) | Gets trick play speed and direction for current stream for a certain demuxer ID |
| [setChannel](#setChannel) | Sets channel URI for a certain demuxer ID |
| [setSeek](#setSeek) | Sets seek position for current stream for a certain demuxer ID |
| [setTracing](#setTracing) | Sets tracing enabled/disabled |
| [setTrickPlay](#setTrickPlay) | Sets trick play speed and direction for current stream for a certain demuxer ID |

<a id="getChannel"></a>
## *getChannel*

Gets channel URI for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.channel | string | Channel address |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LinearPlaybackControl.getChannel",
    "params": {
        "demuxerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.LinearPlaybackControl.getChannel", "params": {"demuxerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "channel": "",
        "result": 0
    }
}
```

<a id="getSeek"></a>
## *getSeek*

Gets seek position for current stream for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.seekPosInSeconds | integer | TSB seek position offset from live in seconds |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LinearPlaybackControl.getSeek",
    "params": {
        "demuxerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.LinearPlaybackControl.getSeek", "params": {"demuxerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "seekPosInSeconds": 0,
        "result": 0
    }
}
```

<a id="getStatus"></a>
## *getStatus*

Gets TSB status (seek position, TSB size and health info) for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.maxSizeInBytes | integer | Maximum TSB size in bytes |
| result.currentSizeInBytes | integer | Current TSB size in bytes |
| result.currentSizeInSeconds | integer | Current TSB size in seconds |
| result.seekPosInBytes | integer | Current TSB seek position offset from live in bytes |
| result.seekPosInSeconds | integer | TSB seek position offset from live in seconds |
| result.trickPlaySpeed | integer | Current trick play speed and direction |
| result.streamSourceLost | bool | Boolean indicating if the buffer source is lost |
| result.streamSourceLossCount | integer | Number of times streaming was lost |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.LinearPlaybackControl.getStatus",
    "params": {
        "demuxerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.LinearPlaybackControl.getStatus", "params": {"demuxerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "maxSizeInBytes": 0,
        "currentSizeInBytes": 0,
        "currentSizeInSeconds": 0,
        "seekPosInBytes": 0,
        "seekPosInSeconds": 0,
        "trickPlaySpeed": 0,
        "streamSourceLost": true,
        "streamSourceLossCount": 0,
        "result": 0
    }
}
```

<a id="getTracing"></a>
## *getTracing*

Gets tracing enabled/disabled

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.tracing | bool | Tracing enable (true) / disable (false) |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.LinearPlaybackControl.getTracing"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.LinearPlaybackControl.getTracing"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "tracing": true,
        "result": 0
    }
}
```

<a id="getTrickPlay"></a>
## *getTrickPlay*

Gets trick play speed and direction for current stream for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speed | integer | New trick play speed (negative=rewind, positive=fast forward) |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.LinearPlaybackControl.getTrickPlay",
    "params": {
        "demuxerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.LinearPlaybackControl.getTrickPlay", "params": {"demuxerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "speed": 0,
        "result": 0
    }
}
```

<a id="setChannel"></a>
## *setChannel*

Sets channel URI for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
| params.channel | string | Channel address |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.LinearPlaybackControl.setChannel",
    "params": {
        "demuxerId": "",
        "channel": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.LinearPlaybackControl.setChannel", "params": {"demuxerId": "", "channel": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "result": 0
    }
}
```

<a id="setSeek"></a>
## *setSeek*

Sets seek position for current stream for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
| params.seekPosInSeconds | integer | TSB seek position offset from live in seconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.LinearPlaybackControl.setSeek",
    "params": {
        "demuxerId": "",
        "seekPosInSeconds": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.LinearPlaybackControl.setSeek", "params": {"demuxerId": "", "seekPosInSeconds": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "result": 0
    }
}
```

<a id="setTracing"></a>
## *setTracing*

Sets tracing enabled/disabled

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.tracing | bool | Tracing enable (true) / disable (false) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.LinearPlaybackControl.setTracing",
    "params": {
        "tracing": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.LinearPlaybackControl.setTracing", "params": {"tracing": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "result": 0
    }
}
```

<a id="setTrickPlay"></a>
## *setTrickPlay*

Sets trick play speed and direction for current stream for a certain demuxer ID

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.demuxerId | string | Demuxer ID (default is "0") |
| params.speed | integer | New trick play speed (negative=rewind, positive=fast forward) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | integer | Result code @retval ERROR_NONE: Success @retval ERROR_BAD_REQUEST: Bad request |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.LinearPlaybackControl.setTrickPlay",
    "params": {
        "demuxerId": "",
        "speed": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.LinearPlaybackControl.setTrickPlay", "params": {"demuxerId": "", "speed": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "result": 0
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the LinearPlaybackControl plugin:

LinearPlaybackControl interface events:

| Event | Description |
| :-------- | :-------- |
| [onSpeedChanged](#onSpeedChanged) | Triggered when the trick play speed has changed |

<a id="onSpeedChanged"></a>
## *onSpeedChanged*

Triggered when the trick play speed has changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speed | integer | New trick play speed (negative=rewind, positive=fast forward) |
| params.muxId | integer | Stream muxId |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.LinearPlaybackControl.onSpeedChanged",
    "params": {
        "speed": 0,
        "muxId": 0
    }
}
```
