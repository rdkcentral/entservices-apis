<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.FrameRate_Plugin"></a>
# FrameRate Plugin

**Version: [1.0.0]()**

A org.rdk.FrameRate plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `FrameRate` plugin allows you to collect FPS data.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.FrameRate*) |
| classname | string | Class name: *org.rdk.FrameRate* |
| locator | string | Library name: *libWPEFrameworkFrameRate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.FrameRate plugin:

FrameRate interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDisplayFrameRate](#method.getDisplayFrameRate) | Returns the current display frame rate values |
| [getFrmMode](#method.getFrmMode) | Returns the current auto framerate mode |
| [setCollectionFrequency](#method.setCollectionFrequency) | Sets the FPS data collection interval |
| [setDisplayFrameRate](#method.setDisplayFrameRate) | Sets the display framerate values |
| [setFrmMode](#method.setFrmMode) | Sets the auto framerate mode |
| [startFpsCollection](#method.startFpsCollection) | Starts the FPS data collection |
| [stopFpsCollection](#method.stopFpsCollection) | Stops the FPS data collection |
| [updateFps](#method.updateFps) | Updates Fps values |


<a name="method.getDisplayFrameRate"></a>
## *getDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Returns the current display frame rate values.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.framerate | string | The display framerate setting (width x height x framerate) |
| result.success | boolean | Indicates success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.getDisplayFrameRate"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "framerate": "3840x2160px48",
        "success": true
    }
}
```

<a name="method.getFrmMode"></a>
## *getFrmMode [<sup>method</sup>](#head.Methods)*

Returns the current auto framerate mode.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.auto-frm-mode | integer | `0` for auto framerate mode disabled, `1` for auto framerate mode enabled (must be one of the following: *0*, *1*) |
| result.success | boolean | Indicates success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.getFrmMode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "auto-frm-mode": 0,
        "success": true
    }
}
```

<a name="method.setCollectionFrequency"></a>
## *setCollectionFrequency [<sup>method</sup>](#head.Methods)*

Sets the FPS data collection interval.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frequency | integer | The amount of time in milliseconds. The default frequency is 10000 milliseconds |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.setCollectionFrequency",
    "params": {
        "frequency": 1000
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="method.setDisplayFrameRate"></a>
## *setDisplayFrameRate [<sup>method</sup>](#head.Methods)*

Sets the display framerate values.

### Events

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanging](#event.onDisplayFrameRateChanging) | Triggered when the framerate changes started. |
| [onDisplayFrameRateChanged](#event.onDisplayFrameRateChanged) | Triggered when the framerate changed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framerate | string | The display framerate setting (width x height x framerate) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.setDisplayFrameRate",
    "params": {
        "framerate": "3840x2160px48"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="method.setFrmMode"></a>
## *setFrmMode [<sup>method</sup>](#head.Methods)*

Sets the auto framerate mode.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.frmmode | integer | `0` for auto framerate mode disabled, `1` for auto framerate mode enabled (must be one of the following: *0*, *1*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.setFrmMode",
    "params": {
        "frmmode": 0
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="method.startFpsCollection"></a>
## *startFpsCollection [<sup>method</sup>](#head.Methods)*

Starts the FPS data collection.

### Events

| Event | Description |
| :-------- | :-------- |
| [onFpsEvent](#event.onFpsEvent) | Triggered at the end of each interval as defined by the setCollectionFrequency |
### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.startFpsCollection"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="method.stopFpsCollection"></a>
## *stopFpsCollection [<sup>method</sup>](#head.Methods)*

Stops the FPS data collection.

### Events

| Event | Description |
| :-------- | :-------- |
| [onFpsEvent](#event.onFpsEvent) | Triggered once after the stopFpsCollection method is invoked. |
### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.stopFpsCollection"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="method.updateFps"></a>
## *updateFps [<sup>method</sup>](#head.Methods)*

Updates Fps values.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.newFpsValue | integer | New Frames per Second (Fps) value |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Always true |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrameRate.updateFps",
    "params": {
        "newFpsValue": 60
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": true
}
```

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.FrameRate plugin:

FrameRate interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayFrameRateChanging](#event.onDisplayFrameRateChanging) | Triggered when the framerate changes started |
| [onDisplayFrameRateChanged](#event.onDisplayFrameRateChanged) | Triggered when the framerate changed |
| [onFpsEvent](#event.onFpsEvent) | Triggered at the end of each interval as defined by the `setCollectionFrequency` method and once after the `stopFpsCollection` method is invoked |


<a name="event.onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging [<sup>event</sup>](#head.Notifications)*

Triggered when the framerate changes started.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | Video Display FrameRate changing |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDisplayFrameRateChanging",
    "params": {
        "displayFrameRate": "1920x1080x60"
    }
}
```

<a name="event.onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the framerate changed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayFrameRate | string | Video Display FrameRate changed |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDisplayFrameRateChanged",
    "params": {
        "displayFrameRate": "1920x1080x60"
    }
}
```

<a name="event.onFpsEvent"></a>
## *onFpsEvent [<sup>event</sup>](#head.Notifications)*

Triggered at the end of each interval as defined by the `setCollectionFrequency` method and once after the `stopFpsCollection` method is invoked.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.average | integer | The average FPS |
| params.min | integer | The minimum FPS |
| params.max | integer | The maximum FPS |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFpsEvent",
    "params": {
        "average": 0,
        "min": 0,
        "max": 0
    }
}
```

