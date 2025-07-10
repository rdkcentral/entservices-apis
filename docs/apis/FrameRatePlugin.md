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

This plugin allows to collect FPS related data on TV profile stack.

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
| [getDisplayFrameRate](#method.getDisplayFrameRate) | Retrieves the current display frame rate as a string in the format "WIDTHxHEIGHTpxFPS" |
| [getFrmMode](#method.getFrmMode) | Retrieves the current auto framerate mode as an integer. Expeted values are 0 or 1. |
| [setCollectionFrequency](#method.setCollectionFrequency) | Sets the interval for FPS data collection in milliseconds. Default is 10000ms and min is 100ms |
| [setDisplayFrameRate](#method.setDisplayFrameRate) | Sets the display framerate to the specified value in the format "WIDTHxHEIGHTpxFPS". |
| [setFrmMode](#method.setFrmMode) | Sets the auto framerate mode to the specified value. Expected values are 0(disable) or 1(enable). |
| [startFpsCollection](#method.startFpsCollection) | Starts collecting FPS data at the configured interval set by the method `SetCollectionFrequency`. |
| [stopFpsCollection](#method.stopFpsCollection) | Stops the FPS data collection. |
| [updateFps](#method.updateFps) | Updates the current FPS value to the specified value represented as integer. |

<a id="method.getDisplayFrameRate"></a>
## *getDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Retrieves the current display frame rate as a string in the format "WIDTHxHEIGHTpxFPS"

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.framerate | string | The current display frame rate.  |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FrameRate.getDisplayFrameRate"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "framerate": "3840x2160px60",
        "success": true
    }
}
```

<a id="method.getFrmMode"></a>
## *getFrmMode [<sup>method</sup>](#head.Methods)*

Retrieves the current auto framerate mode as an integer. Expeted values are 0 or 1.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.auto-frm-mode | int | The current auto framerate mode. e.g. 1 |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FrameRate.getFrmMode"
}
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

Sets the interval for FPS data collection in milliseconds. Default is 10000ms and min is 100ms

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frequency | int | The collection frequency in ms.  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FrameRate.setCollectionFrequency",
    "params": {
        "frequency": 1000
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": true
}
```

<a id="method.setDisplayFrameRate"></a>
## *setDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Sets the display framerate to the specified value in the format "WIDTHxHEIGHTpxFPS".

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framerate | string | The current display frame rate.  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FrameRate.setDisplayFrameRate",
    "params": {
        "framerate": "3840x2160px60"
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": true
}
```

<a id="method.setFrmMode"></a>
## *setFrmMode [<sup>method</sup>](#head.Methods)*

Sets the auto framerate mode to the specified value. Expected values are 0(disable) or 1(enable).

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frmmode | int | The framerate mode to set.  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.FrameRate.setFrmMode",
    "params": {
        "frmmode": 1
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": true
}
```

<a id="method.startFpsCollection"></a>
## *startFpsCollection [<sup>method</sup>](#head.Methods)*

Starts collecting FPS data at the configured interval set by the method `SetCollectionFrequency`.

### Events
- [onFpsEvent](#event.onFpsEvent)
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.FrameRate.startFpsCollection"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": true
}
```

<a id="method.stopFpsCollection"></a>
## *stopFpsCollection [<sup>method</sup>](#head.Methods)*

Stops the FPS data collection.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.FrameRate.stopFpsCollection"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```

<a id="method.updateFps"></a>
## *updateFps [<sup>method</sup>](#head.Methods)*

Updates the current FPS value to the specified value represented as integer.

### Events
- [onFpsEvent](#event.onFpsEvent)
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.newFpsValue | int | The new FPS value.  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Indicates if the operation was successful  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.FrameRate.updateFps",
    "params": {
        "newFpsValue": 60
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": true
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the FrameRate plugin:

FrameRate interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanged](#event.onDisplayFrameRateChanged) | This event is triggered after the display frame rate has changed and represented as "WIDTHxHEIGHTxFPS". |
| [onDisplayFrameRateChanging](#event.onDisplayFrameRateChanging) | This event is triggered when the display frame rate is about to change and represented as "WIDTHxHEIGHTxFPS". |
| [onFpsEvent](#event.onFpsEvent) | Triggered at the end of each interval as defined by the `setCollectionFrequency` method after `startFpsCollection` method and once after the `stopFpsCollection` method is invoked |

<a id="event.onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged [<sup>event</sup>](#head.Notifications)*

This event is triggered after the display frame rate has changed and represented as "WIDTHxHEIGHTxFPS".

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | The new display frame rate  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.FrameRate.onDisplayFrameRateChanged",
    "params": {
        "displayFrameRate": "1920x1080x60"
    }
}
```

<a id="event.onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging [<sup>event</sup>](#head.Notifications)*

This event is triggered when the display frame rate is about to change and represented as "WIDTHxHEIGHTxFPS".

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | The new display frame rate  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.FrameRate.onDisplayFrameRateChanging",
    "params": {
        "displayFrameRate": "1920x1080x60"
    }
}
```

<a id="event.onFpsEvent"></a>
## *onFpsEvent [<sup>event</sup>](#head.Notifications)*

Triggered at the end of each interval as defined by the `setCollectionFrequency` method after `startFpsCollection` method and once after the `stopFpsCollection` method is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.average | int | The average FPS  |
| params.min | int | The minimum FPS  |
| params.max | int | The maximum FPS  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.FrameRate.onFpsEvent",
    "params": {
        "average": 60,
        "min": 30,
        "max": 120
    }
}
```
