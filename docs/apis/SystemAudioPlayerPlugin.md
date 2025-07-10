<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.SystemAudioPlayer_Plugin"></a>
# SystemAudioPlayer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/SystemAudioPlayer/CHANGELOG.md)**

A SystemAudioPlayer plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `SystemAudioPlayer` plugin provides an interface for SystemAudioPlayer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemAudioPlayer) |
| classname | string | Class name: *SystemAudioPlayer* |
| locator | string | Library name: *libWPEFrameworkSystemAudioPlayer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the SystemAudioPlayer plugin:

SystemAudioPlayer interface methods:

| Method | Description |
| :-------- | :-------- |
| [close](#method.close) |  |
| [config](#method.config) |  |
| [configure](#method.configure) |  |
| [getPlayerSessionId](#method.getPlayerSessionId) |  |
| [isPlaying](#method.isPlaying) |  |
| [onSAPEvents](#method.onSAPEvents) |  |
| [open](#method.open) |  |
| [pause](#method.pause) |  |
| [play](#method.play) |  |
| [playBuffer](#method.playBuffer) |  |
| [resume](#method.resume) |  |
| [setMixerLevels](#method.setMixerLevels) |  |
| [setSmartVolControl](#method.setSmartVolControl) |  |
| [stop](#method.stop) |  |

<a id="method.close"></a>
## *close [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": ""
}
```

<a id="method.config"></a>
## *config [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": ""
}
```

<a id="method.configure"></a>
## *configure [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | PluginHost::IShell | - |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.getPlayerSessionId"></a>
## *getPlayerSessionId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```

<a id="method.isPlaying"></a>
## *isPlaying [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```

<a id="method.onSAPEvents"></a>
## *onSAPEvents [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.data | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SystemAudioPlayer.onSAPEvents",
    "params": {
        "data": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.open"></a>
## *open [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SystemAudioPlayer.open",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": ""
}
```

<a id="method.pause"></a>
## *pause [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SystemAudioPlayer.pause",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": ""
}
```

<a id="method.play"></a>
## *play [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SystemAudioPlayer.play",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": ""
}
```

<a id="method.playBuffer"></a>
## *playBuffer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SystemAudioPlayer.playBuffer",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": ""
}
```

<a id="method.resume"></a>
## *resume [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.SystemAudioPlayer.resume",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": ""
}
```

<a id="method.setMixerLevels"></a>
## *setMixerLevels [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.SystemAudioPlayer.setMixerLevels",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": ""
}
```

<a id="method.setSmartVolControl"></a>
## *setSmartVolControl [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.SystemAudioPlayer.setSmartVolControl",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": ""
}
```

<a id="method.stop"></a>
## *stop [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.SystemAudioPlayer.stop",
    "params": {
        "input": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": ""
}
```


