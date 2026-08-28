<!-- Generated automatically, DO NOT EDIT! -->
<a id="FrameRate_Module"></a>
# FrameRate Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FrameRate/IFrameRate.h)**

A FrameRate module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IFrameRate](#IFrameRate)
    - [Methods](#IFrameRate-Methods)
    - [Notifications](#IFrameRate-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `FrameRate` module provides the following interface(s):

- IFrameRate

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FrameRate) |
| classname | string | Class name: *FrameRate* |
| locator | string | Library name: *libWPEFrameworkFrameRate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IFrameRate"></a>
## IFrameRate Interface

<a id="IFrameRate-Methods"></a>
### Methods

The following methods are provided by the IFrameRate Interface:

| Method | Description |
| :-------- | :-------- |
| [getDisplayFrameRate](#getDisplayFrameRate) | Gets the current display frame rate values. |
| [getFrmMode](#getFrmMode) | Gets the current auto framerate mode. |
| [setCollectionFrequency](#setCollectionFrequency) | Sets the FPS data collection interval. |
| [setDisplayFrameRate](#setDisplayFrameRate) | Sets the display framerate values. |
| [setFrmMode](#setFrmMode) | Set the Frm mode. |
| [startFpsCollection](#startFpsCollection) | Starts the FPS data collection. Starts the FPS data collection |
| [stopFpsCollection](#stopFpsCollection) | Stops the FPS data collection |
| [updateFps](#updateFps) | Update the FPS value |

<a id="getDisplayFrameRate"></a>
## *getDisplayFrameRate*

Obtains the display framerate values currently configured for the system. The returned information can be used to determine the active display framerate settings.

### Events Triggered
None
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
        "framerate": 60,
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getFrmMode"></a>
## *getFrmMode*

Returns the auto framerate mode currently configured in the system. The retrieved value indicates the active framerate management setting.

### Events Triggered
None
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setCollectionFrequency"></a>
## *setCollectionFrequency*

Specifies how frequently FPS metrics are collected during an active monitoring session. The configured interval determines the time gap between consecutive FPS measurements.

### Events Triggered
None
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
        "frequency": 1000
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.FrameRate.setCollectionFrequency", "params": {"frequency": 1000}}' http://127.0.0.1:9998/jsonrpc
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setDisplayFrameRate"></a>
## *setDisplayFrameRate*

Updates the display framerate setting using the specified value. The new framerate is applied to subsequent display operations if the request is processed successfully.

### Events Triggered
None
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
        "framerate": 60
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.FrameRate.setDisplayFrameRate", "params": {"framerate": 60}}' http://127.0.0.1:9998/jsonrpc
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setFrmMode"></a>
## *setFrmMode*

Updates the auto framerate mode to the specified value. The operation applies the new mode setting and indicates whether the update was completed successfully.

### Events Triggered
None
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
        "frmmode": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.FrameRate.setFrmMode", "params": {"frmmode": 1}}' http://127.0.0.1:9998/jsonrpc
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="startFpsCollection"></a>
## *startFpsCollection*

Starts gathering FPS metrics for monitoring and analysis. Once enabled, FPS samples are collected until the collection process is explicitly stopped.

### Events Triggered
None
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="stopFpsCollection"></a>
## *stopFpsCollection*

Terminates the ongoing FPS data collection process and prevents any additional FPS metrics from being captured until data collection is started again.

### Events Triggered
None
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="updateFps"></a>
## *updateFps*

Allows a client to specify a new FPS value to be used by the service. On successful completion, the updated setting becomes active and the success parameter is set accordingly.

### Events Triggered
None
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
        "newFpsValue": 60
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.FrameRate.updateFps", "params": {"newFpsValue": 60}}' http://127.0.0.1:9998/jsonrpc
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IFrameRate-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IFrameRate Interface:

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanged](#onDisplayFrameRateChanged) | Triggered when the framerate changed. |
| [onDisplayFrameRateChanging](#onDisplayFrameRateChanging) | Triggered when the framerate changes started |
| [onFpsEvent](#onFpsEvent) | Triggered by callback from FrameRate after onFpsEvent |

<a id="onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged*

This event is triggered after a display framerate transition is completed and the new framerate value becomes active.

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
        "displayFrameRate": 60
    }
}
```

<a id="onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging*

This notification is raised when a display frame rate change has started and before the new frame rate is applied.

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
        "displayFrameRate": 60
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
        "average": 60,
        "min": 30,
        "max": 120
    }
}
```

