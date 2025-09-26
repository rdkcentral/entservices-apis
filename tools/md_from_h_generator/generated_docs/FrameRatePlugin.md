<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.FrameRate_Plugin"></a>
# FrameRate Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/FrameRate/CHANGELOG.md)**

A FrameRate plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `FrameRate` plugin provides an interface for FrameRate.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FrameRate) |
| classname | string | Class name: *FrameRate* |
| locator | string | Library name: *libWPEFrameworkFrameRate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the FrameRate plugin:

FrameRate interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDisplayFrameRate](#method.getDisplayFrameRate) | Gets the current display frame rate values. |
| [getFrmMode](#method.getFrmMode) | Gets the current auto framerate mode. |
| [setCollectionFrequency](#method.setCollectionFrequency) | Sets the FPS data collection interval. |
| [setDisplayFrameRate](#method.setDisplayFrameRate) | Sets the display framerate values. |
| [setFrmMode](#method.setFrmMode) | Set the Frm mode. |
| [startFpsCollection](#method.startFpsCollection) | Starts the FPS data collection. Starts the FPS data collection |
| [stopFpsCollection](#method.stopFpsCollection) | Stops the FPS data collection |
| [updateFps](#method.updateFps) | Update the FPS value |

<a id="method.getDisplayFrameRate"></a>
## *getDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Gets the current display frame rate values.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.framerate | string | string |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FrameRate.getDisplayFrameRate"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.FrameRate.getDisplayFrameRate"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "framerate": "",
        "success": true
    }
}
```

<a id="method.getFrmMode"></a>
## *getFrmMode [<sup>method</sup>](#head.Methods)*

Gets the current auto framerate mode.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.auto-frm-mode | int |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FrameRate.getFrmMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.FrameRate.getFrmMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "auto-frm-mode": 0,
        "success": true
    }
}
```

<a id="method.setCollectionFrequency"></a>
## *setCollectionFrequency [<sup>method</sup>](#head.Methods)*

Sets the FPS data collection interval.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frequency | int | int |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FrameRate.setCollectionFrequency",
    "params": {
        "frequency": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.FrameRate.setCollectionFrequency", "params": {"frequency": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```

<a id="method.setDisplayFrameRate"></a>
## *setDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Sets the display framerate values.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framerate | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FrameRate.setDisplayFrameRate",
    "params": {
        "framerate": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.FrameRate.setDisplayFrameRate", "params": {"framerate": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="method.setFrmMode"></a>
## *setFrmMode [<sup>method</sup>](#head.Methods)*

Set the Frm mode.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frmmode | int | int |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.FrameRate.setFrmMode",
    "params": {
        "frmmode": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.FrameRate.setFrmMode", "params": {"frmmode": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="method.startFpsCollection"></a>
## *startFpsCollection [<sup>method</sup>](#head.Methods)*

Starts the FPS data collection. Starts the FPS data collection

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.FrameRate.startFpsCollection"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.FrameRate.startFpsCollection"}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.stopFpsCollection"></a>
## *stopFpsCollection [<sup>method</sup>](#head.Methods)*

Stops the FPS data collection

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.FrameRate.stopFpsCollection"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.FrameRate.stopFpsCollection"}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.updateFps"></a>
## *updateFps [<sup>method</sup>](#head.Methods)*

Update the FPS value

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.newFpsValue | int | int |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.FrameRate.updateFps",
    "params": {
        "newFpsValue": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.FrameRate.updateFps", "params": {"newFpsValue": 0}}' http://127.0.0.1:9998/jsonrpc
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the FrameRate plugin:

FrameRate interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanged](#event.onDisplayFrameRateChanged) | Triggered when the framerate changed. |
| [onDisplayFrameRateChanging](#event.onDisplayFrameRateChanging) | Triggered when the framerate changes started |
| [onFpsEvent](#event.onFpsEvent) | Triggered by callback from FrameRate after onFpsEvent |

<a id="event.onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the framerate changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.FrameRate.onDisplayFrameRateChanged",
    "params": {
        "displayFrameRate": ""
    }
}
```

<a id="event.onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging [<sup>event</sup>](#head.Notifications)*

Triggered when the framerate changes started

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.FrameRate.onDisplayFrameRateChanging",
    "params": {
        "displayFrameRate": ""
    }
}
```

<a id="event.onFpsEvent"></a>
## *onFpsEvent [<sup>event</sup>](#head.Notifications)*

Triggered by callback from FrameRate after onFpsEvent

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.average | int | int |
| params.min | int | int |
| params.max | int | int |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.FrameRate.onFpsEvent",
    "params": {
        "average": 0,
        "min": 0,
        "max": 0
    }
}
```
