<!-- Generated automatically, DO NOT EDIT! -->
<a id="PlaybackSync_Plugin"></a>
# PlaybackSync Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PlaybackSync/IPlaybackSync.h)**

A PlaybackSync plugin for Thunder framework.

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

The `PlaybackSync` plugin provides an interface for PlaybackSync.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PlaybackSync) |
| classname | string | Class name: *PlaybackSync* |
| locator | string | Library name: *libWPEFrameworkPlaybackSync.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the PlaybackSync plugin:

PlaybackSync interface methods:

| Method | Description |
| :-------- | :-------- |
| [connect](#connect) | Connects a client to a pub/sub Linchpin service |
| [getDevice](#getDevice) | Retrieves device related information |
| [getPlaybackServiceKey](#getPlaybackServiceKey) | Retrieves the currently shared content's service key |
| [getPlaybackURL](#getPlaybackURL) | Retrieves the currently shared content's URL |
| [getRoom](#getRoom) | Retrieves the current room code |
| [publishMessage](#publishMessage) | Publishes chat/text message to room participants |
| [publishPause](#publishPause) | Publishes content's playback pause action with the room participants |
| [publishPlaybackError](#publishPlaybackError) | Publishes any session errors with room participants |
| [publishPlaybackPosition](#publishPlaybackPosition) | Publishes the content's playback position with the room participants |
| [publishPlaybackStarted](#publishPlaybackStarted) | Publishes the content's playback action with the room participants |
| [publishSpeed](#publishSpeed) | Publishes the content's playback speed action with the room participants |
| [publishStop](#publishStop) | Publishes the content's playback stop action with the room participants |
| [requestLeadership](#requestLeadership) | Negotiates room leadership status |
| [setDevice](#setDevice) | Sets device-related information for sharing with session participants |
| [setPlaybackServiceKey](#setPlaybackServiceKey) | Sets and shares the playback content's service key |
| [setPlaybackURL](#setPlaybackURL) | Sets the playback content URL for room participants |
| [setRoom](#setRoom) | Creates and joins a room that provides participants a synchronization session |

<a id="connect"></a>
## *connect*

Connects a client to a pub/sub Linchpin service

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.stringEndpoint | string | A fully qualified domain name (FQDN) of a Linchpin server |
| params.stringClientName | string | A Linchpin server client name |
| params.numberClientType | integer | The Linchpin server client payload type |
| params.stringToken | string | A secure access token (SAT) for Linchpin client authorization |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PlaybackSync.connect",
    "params": {
        "stringEndpoint": "",
        "stringClientName": "",
        "numberClientType": 0,
        "stringToken": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PlaybackSync.connect", "params": {"stringEndpoint": "", "stringClientName": "", "numberClientType": 0, "stringToken": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```

<a id="getDevice"></a>
## *getDevice*

Retrieves device related information

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PlaybackSync.getDevice"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PlaybackSync.getDevice"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "jsonDeviceDetails": "",
        "success": true
    }
}
```

<a id="getPlaybackServiceKey"></a>
## *getPlaybackServiceKey*

Retrieves the currently shared content's service key

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.stringServiceKey | string | The service key of the shared playback content |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PlaybackSync.getPlaybackServiceKey"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PlaybackSync.getPlaybackServiceKey"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "stringServiceKey": "",
        "success": true
    }
}
```

<a id="getPlaybackURL"></a>
## *getPlaybackURL*

Retrieves the currently shared content's URL

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.stringURL | string | The URL of the shared playback content |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PlaybackSync.getPlaybackURL"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PlaybackSync.getPlaybackURL"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "stringURL": "",
        "success": true
    }
}
```

<a id="getRoom"></a>
## *getRoom*

Retrieves the current room code

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.stringRoomCode | string | A room code that identifies the room |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PlaybackSync.getRoom"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PlaybackSync.getRoom"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "stringRoomCode": "",
        "success": true
    }
}
```

<a id="publishMessage"></a>
## *publishMessage*

Publishes chat/text message to room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.stringMessage | string | The chat message string |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PlaybackSync.publishMessage",
    "params": {
        "stringMessage": "",
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PlaybackSync.publishMessage", "params": {"stringMessage": "", "numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "success": true
    }
}
```

<a id="publishPause"></a>
## *publishPause*

Publishes content's playback pause action with the room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.PlaybackSync.publishPause",
    "params": {
        "numberPosition": 0,
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PlaybackSync.publishPause", "params": {"numberPosition": 0, "numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "success": true
    }
}
```

<a id="publishPlaybackError"></a>
## *publishPlaybackError*

Publishes any session errors with room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberErrorCode | integer | An application defined error number |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PlaybackSync.publishPlaybackError",
    "params": {
        "numberErrorCode": 0,
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PlaybackSync.publishPlaybackError", "params": {"numberErrorCode": 0, "numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "success": true
    }
}
```

<a id="publishPlaybackPosition"></a>
## *publishPlaybackPosition*

Publishes the content's playback position with the room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.PlaybackSync.publishPlaybackPosition",
    "params": {
        "numberPosition": 0,
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PlaybackSync.publishPlaybackPosition", "params": {"numberPosition": 0, "numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "success": true
    }
}
```

<a id="publishPlaybackStarted"></a>
## *publishPlaybackStarted*

Publishes the content's playback action with the room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |
| params.numberSetupOverhead | integer | The total amount of time in milliseconds from receiving position to starting play |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.PlaybackSync.publishPlaybackStarted",
    "params": {
        "numberPosition": 0,
        "numberTimestamp": 0,
        "numberSetupOverhead": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PlaybackSync.publishPlaybackStarted", "params": {"numberPosition": 0, "numberTimestamp": 0, "numberSetupOverhead": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "success": true
    }
}
```

<a id="publishSpeed"></a>
## *publishSpeed*

Publishes the content's playback speed action with the room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberSpeed | integer | Content playback speed (positive for forward, negative for rewind) |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.PlaybackSync.publishSpeed",
    "params": {
        "numberSpeed": 0,
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PlaybackSync.publishSpeed", "params": {"numberSpeed": 0, "numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "success": true
    }
}
```

<a id="publishStop"></a>
## *publishStop*

Publishes the content's playback stop action with the room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.numberTimestamp | integer | Reference timestamp of the request |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.PlaybackSync.publishStop",
    "params": {
        "numberTimestamp": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PlaybackSync.publishStop", "params": {"numberTimestamp": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "success": true
    }
}
```

<a id="requestLeadership"></a>
## *requestLeadership*

Negotiates room leadership status

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.booleanRoomLeader | bool | Room leadership status to be solicited |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.PlaybackSync.requestLeadership",
    "params": {
        "booleanRoomLeader": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PlaybackSync.requestLeadership", "params": {"booleanRoomLeader": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "success": true
    }
}
```

<a id="setDevice"></a>
## *setDevice*

Sets device-related information for sharing with session participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.PlaybackSync.setDevice",
    "params": {
        "jsonDeviceDetails": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PlaybackSync.setDevice", "params": {"jsonDeviceDetails": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "success": true
    }
}
```

<a id="setPlaybackServiceKey"></a>
## *setPlaybackServiceKey*

Sets and shares the playback content's service key

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.stringServiceKey | string | The service key of the shared playback content |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.PlaybackSync.setPlaybackServiceKey",
    "params": {
        "stringServiceKey": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PlaybackSync.setPlaybackServiceKey", "params": {"stringServiceKey": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "success": true
    }
}
```

<a id="setPlaybackURL"></a>
## *setPlaybackURL*

Sets the playback content URL for room participants

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.stringURL | string | The URL of the shared playback content |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.PlaybackSync.setPlaybackURL",
    "params": {
        "stringURL": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.PlaybackSync.setPlaybackURL", "params": {"stringURL": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "success": true
    }
}
```

<a id="setRoom"></a>
## *setRoom*

Creates and joins a room that provides participants a synchronization session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.stringRoomCode | string | A room code that identifies the room |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation succeeded @retval Core::ERROR_NONE: Room code retrieved successfully |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.PlaybackSync.setRoom",
    "params": {
        "stringRoomCode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.PlaybackSync.setRoom", "params": {"stringRoomCode": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PlaybackSync plugin:

PlaybackSync interface events:

| Event | Description |
| :-------- | :-------- |
| [onDeviceDetails](#onDeviceDetails) | Triggered when session participants device details change |
| [onDeviceJoined](#onDeviceJoined) | Triggered when new participants join the room |
| [onDeviceLeft](#onDeviceLeft) | Triggered when a room participant exits |
| [onDisconnect](#onDisconnect) | Triggered when connection to the service is lost |
| [onError](#onError) | Triggered on error |
| [onLeaderRequest](#onLeaderRequest) | Triggered when the session leadership solicitation action is invoked |
| [onMessage](#onMessage) | Triggered when the chat message action is invoked |
| [onPause](#onPause) | Triggered when the content playback pause action is invoked |
| [onPosition](#onPosition) | Triggered when the content playback position is being published |
| [onPlaybackServiceKey](#onPlaybackServiceKey) | Triggered when the service key of shared playback content is specified |
| [onSpeed](#onSpeed) | Triggered when the content playback speed action is invoked |
| [onPlay](#onPlay) | Triggered when the content playback action is invoked |
| [onStopped](#onStopped) | Triggered when the content playback stop action is invoked |
| [onPlaybackURL](#onPlaybackURL) | Triggered when the URL of shared playback content is specified |

<a id="onDeviceDetails"></a>
## *onDeviceDetails*

Triggered when session participants device details change

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.PlaybackSync.onDeviceDetails",
    "params": {
        "jsonDeviceDetails": "",
        "numberTimestamp": 0
    }
}
```

<a id="onDeviceJoined"></a>
## *onDeviceJoined*

Triggered when new participants join the room

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.PlaybackSync.onDeviceJoined",
    "params": {
        "jsonDeviceDetails": "",
        "numberTimestamp": 0
    }
}
```

<a id="onDeviceLeft"></a>
## *onDeviceLeft*

Triggered when a room participant exits

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.PlaybackSync.onDeviceLeft",
    "params": {
        "jsonDeviceDetails": "",
        "numberTimestamp": 0
    }
}
```

<a id="onDisconnect"></a>
## *onDisconnect*

Triggered when connection to the service is lost

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.PlaybackSync.onDisconnect"
}
```

<a id="onError"></a>
## *onError*

Triggered on error

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberErrorCode | integer | An application defined error number |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.PlaybackSync.onError",
    "params": {
        "jsonDeviceDetails": "",
        "numberErrorCode": 0,
        "numberTimestamp": 0
    }
}
```

<a id="onLeaderRequest"></a>
## *onLeaderRequest*

Triggered when the session leadership solicitation action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.booleanRoomLeader | bool | Room leadership status to be solicited |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.PlaybackSync.onLeaderRequest",
    "params": {
        "jsonDeviceDetails": "",
        "booleanRoomLeader": true,
        "numberTimestamp": 0
    }
}
```

<a id="onMessage"></a>
## *onMessage*

Triggered when the chat message action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.stringMessage | string | The chat message string |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.PlaybackSync.onMessage",
    "params": {
        "jsonDeviceDetails": "",
        "stringMessage": "",
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackPaused"></a>
## *onPlaybackPaused*

Triggered when the content playback pause action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.PlaybackSync.onPlaybackPaused",
    "params": {
        "jsonDeviceDetails": "",
        "numberPosition": 0,
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackPositionUpdated"></a>
## *onPlaybackPositionUpdated*

Triggered when the content playback position is being published

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.PlaybackSync.onPlaybackPositionUpdated",
    "params": {
        "jsonDeviceDetails": "",
        "numberPosition": 0,
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackServiceKey"></a>
## *onPlaybackServiceKey*

Triggered when the service key of shared playback content is specified

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.stringServiceKey | string | The service key of the shared playback content |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.PlaybackSync.onPlaybackServiceKey",
    "params": {
        "jsonDeviceDetails": "",
        "stringServiceKey": "",
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackSpeedChanged"></a>
## *onPlaybackSpeedChanged*

Triggered when the content playback speed action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberSpeed | integer | Content playback speed (positive for forward, negative for rewind) |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.PlaybackSync.onPlaybackSpeedChanged",
    "params": {
        "jsonDeviceDetails": "",
        "numberSpeed": 0,
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackStarted"></a>
## *onPlaybackStarted*

Triggered when the content playback action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberPosition | integer | Playback position of the content to be shared with room participants |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.PlaybackSync.onPlaybackStarted",
    "params": {
        "jsonDeviceDetails": "",
        "numberPosition": 0,
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackStopped"></a>
## *onPlaybackStopped*

Triggered when the content playback stop action is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.PlaybackSync.onPlaybackStopped",
    "params": {
        "jsonDeviceDetails": "",
        "numberTimestamp": 0
    }
}
```

<a id="onPlaybackURL"></a>
## *onPlaybackURL*

Triggered when the URL of shared playback content is specified

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonDeviceDetails | string | A valid JSON object string with application defined device detail(s) |
| params.stringURL | string | The URL of the shared playback content |
| params.numberTimestamp | integer | Reference timestamp of the request |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.PlaybackSync.onPlaybackURL",
    "params": {
        "jsonDeviceDetails": "",
        "stringURL": "",
        "numberTimestamp": 0
    }
}
```
