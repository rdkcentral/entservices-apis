<!-- Generated automatically, DO NOT EDIT! -->
<a id="FrameRate_Plugin"></a>
# FrameRate Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FrameRate/IFrameRate.h)**

A FrameRate plugin for Thunder framework.

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

The `FrameRate` plugin provides an interface for FrameRate.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FrameRate) |
| classname | string | Class name: *FrameRate* |
| locator | string | Library name: *libWPEFrameworkFrameRate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the FrameRate plugin:

FrameRate interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getDisplayFrameRate](#getDisplayFrameRate) | Gets the current display frame rate values. | NA |
| [getFrmMode](#getFrmMode) | Gets the current auto framerate mode. | NA |
| [setCollectionFrequency](#setCollectionFrequency) | Sets the FPS data collection interval. | NA |
| [setDisplayFrameRate](#setDisplayFrameRate) | Sets the display framerate values. | onDisplayFrameRateChanging, onDisplayFrameRateChanged |
| [setFrmMode](#setFrmMode) | Set the Frm mode. | NA |
| [startFpsCollection](#startFpsCollection) | Starts the FPS data collection. Starts the FPS data collection | onFpsEvent |
| [stopFpsCollection](#stopFpsCollection) | Stops the FPS data collection | onFpsEvent |
| [updateFps](#updateFps) | Update the FPS value | NA |

<a id="getDisplayFrameRate"></a>
## *getDisplayFrameRate*

Gets the current display frame rate values.

### Events
Event details will be updated soon.
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

<a id="getFrmMode"></a>
## *getFrmMode*

Gets the current auto framerate mode.

### Events
Event details will be updated soon.
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

<a id="setCollectionFrequency"></a>
## *setCollectionFrequency*

Sets the FPS data collection interval.

### Events
Event details will be updated soon.
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

<a id="setDisplayFrameRate"></a>
## *setDisplayFrameRate*

Sets the display framerate values.

### Events
| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanging ](#event.onDisplayFrameRateChanging ) |  Triggered when the framerate changes started. |
| [onDisplayFrameRateChanged ](#event.onDisplayFrameRateChanged ) |  Triggered when the framerate changed |
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

<a id="setFrmMode"></a>
## *setFrmMode*

Set the Frm mode.

### Events
Event details will be updated soon.
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

<a id="startFpsCollection"></a>
## *startFpsCollection*

Starts the FPS data collection. Starts the FPS data collection

### Events
| Event | Description |
| :-------- | :-------- |
| [onFpsEvent ](#event.onFpsEvent ) |  Triggered at the end of each interval as defined by the setCollectionFrequency |
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

<a id="stopFpsCollection"></a>
## *stopFpsCollection*

Stops the FPS data collection

### Events
| Event | Description |
| :-------- | :-------- |
| [onFpsEvent ](#event.onFpsEvent ) |  Triggered once after the stopFpsCollection method is invoked. |
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

<a id="updateFps"></a>
## *updateFps*

Update the FPS value

### Events
Event details will be updated soon.
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



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the FrameRate plugin:

FrameRate interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanged](#onDisplayFrameRateChanged) | Triggered when the framerate changed. |
| [onDisplayFrameRateChanging](#onDisplayFrameRateChanging) | Triggered when the framerate changes started |
| [onFpsEvent](#onFpsEvent) | Triggered by callback from FrameRate after onFpsEvent |

<a id="onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged*

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

<a id="onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging*

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

<a id="onFpsEvent"></a>
## *onFpsEvent*

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
