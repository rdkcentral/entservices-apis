<!-- Generated automatically, DO NOT EDIT! -->
<a id="SystemAudioPlayer_Plugin"></a>
# SystemAudioPlayer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SystemAudioPlayer)**

A SystemAudioPlayer plugin for Thunder framework.

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

The `SystemAudioPlayer` plugin provides an interface for SystemAudioPlayer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemAudioPlayer) |
| classname | string | Class name: *SystemAudioPlayer* |
| locator | string | Library name: *libWPEFrameworkSystemAudioPlayer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the SystemAudioPlayer plugin:

SystemAudioPlayer interface methods:

| Method | Description |
| :-------- | :-------- |
| [close](#close) |  |
| [config](#config) |  |
| [configure](#configure) |  |
| [getPlayerSessionId](#getPlayerSessionId) |  |
| [isPlaying](#isPlaying) |  |
| [open](#open) |  |
| [pause](#pause) |  |
| [play](#play) |  |
| [playBuffer](#playBuffer) |  |
| [resume](#resume) |  |
| [setMixerLevels](#setMixerLevels) |  |
| [setSmartVolControl](#setSmartVolControl) |  |
| [stop](#stop) |  |

<a id="close"></a>
## *close*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.SystemAudioPlayer.close",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SystemAudioPlayer.close", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "output": ""
    }
}
```

<a id="config"></a>
## *config*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SystemAudioPlayer.config",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SystemAudioPlayer.config", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "output": ""
    }
}
```

<a id="configure"></a>
## *configure*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | PluginHost::IShell |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SystemAudioPlayer.configure",
    "params": {
        "service": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SystemAudioPlayer.configure", "params": {"service": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="getPlayerSessionId"></a>
## *getPlayerSessionId*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.SystemAudioPlayer.getPlayerSessionId",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SystemAudioPlayer.getPlayerSessionId", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "output": ""
    }
}
```

<a id="isPlaying"></a>
## *isPlaying*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.SystemAudioPlayer.isPlaying",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.SystemAudioPlayer.isPlaying", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "output": ""
    }
}
```

<a id="open"></a>
## *open*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SystemAudioPlayer.open",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.SystemAudioPlayer.open", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "output": ""
    }
}
```

<a id="pause"></a>
## *pause*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SystemAudioPlayer.pause",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.SystemAudioPlayer.pause", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "output": ""
    }
}
```

<a id="play"></a>
## *play*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SystemAudioPlayer.play",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.SystemAudioPlayer.play", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "output": ""
    }
}
```

<a id="playBuffer"></a>
## *playBuffer*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SystemAudioPlayer.playBuffer",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.SystemAudioPlayer.playBuffer", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "output": ""
    }
}
```

<a id="resume"></a>
## *resume*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SystemAudioPlayer.resume",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.SystemAudioPlayer.resume", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "output": ""
    }
}
```

<a id="setMixerLevels"></a>
## *setMixerLevels*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.SystemAudioPlayer.setMixerLevels",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.SystemAudioPlayer.setMixerLevels", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "output": ""
    }
}
```

<a id="setSmartVolControl"></a>
## *setSmartVolControl*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.SystemAudioPlayer.setSmartVolControl",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.SystemAudioPlayer.setSmartVolControl", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "output": ""
    }
}
```

<a id="stop"></a>
## *stop*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.output | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.SystemAudioPlayer.stop",
    "params": {
        "input": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.SystemAudioPlayer.stop", "params": {"input": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "output": ""
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the SystemAudioPlayer plugin:

SystemAudioPlayer interface events:

| Event | Description |
| :-------- | :-------- |
| [onSAPEvents](#onSAPEvents) |  |

<a id="onSAPEvents"></a>
## *onSAPEvents*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.data | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.SystemAudioPlayer.onSAPEvents",
    "params": {
        "data": ""
    }
}
```
