<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_FrameRate_API"></a>
# FrameRate API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

FrameRate interface for Thunder framework.

(Defined with IFrameRate in [IFrameRate.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IFrameRate.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the FrameRate interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

FrameRate JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the FrameRate interface:

FrameRate interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDisplayFrameRate](#method_getDisplayFrameRate) | Gets the current display frame rate values |
| [getFrmMode](#method_getFrmMode) | Gets the current auto framerate mode |
| [setCollectionFrequency](#method_setCollectionFrequency) | Sets the FPS data collection interval |
| [setDisplayFrameRate](#method_setDisplayFrameRate) | Sets the display framerate values |
| [setFrmMode](#method_setFrmMode) | Set the Frm mode |
| [startFpsCollection](#method_startFpsCollection) | Starts the FPS data collection |
| [stopFpsCollection](#method_stopFpsCollection) | Stops the FPS data collection |
| [updateFps](#method_updateFps) | Update the FPS value |

<a id="method_getDisplayFrameRate"></a>
## *getDisplayFrameRate [<sup>method</sup>](#head_Methods)*

Gets the current display frame rate values.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.framerate | string | mandatory | - out - string |
| result.success | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getDisplayFrameRate"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "framerate": "...",
    "success": false
  }
}
```

<a id="method_getFrmMode"></a>
## *getFrmMode [<sup>method</sup>](#head_Methods)*

Gets the current auto framerate mode.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.auto-frm-mode | integer | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFrmMode"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "auto-frm-mode": 0,
    "success": false
  }
}
```

<a id="method_setCollectionFrequency"></a>
## *setCollectionFrequency [<sup>method</sup>](#head_Methods)*

Sets the FPS data collection interval.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.frequency | integer | mandatory | - in -  int |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setCollectionFrequency",
  "params": {
    "frequency": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_setDisplayFrameRate"></a>
## *setDisplayFrameRate [<sup>method</sup>](#head_Methods)*

Sets the display framerate values.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.framerate | string | mandatory | - in - string |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setDisplayFrameRate",
  "params": {
    "framerate": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_setFrmMode"></a>
## *setFrmMode [<sup>method</sup>](#head_Methods)*

Set the Frm mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.frmmode | integer | mandatory | - in - int |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setFrmMode",
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
  "result": false
}
```

<a id="method_startFpsCollection"></a>
## *startFpsCollection [<sup>method</sup>](#head_Methods)*

Starts the FPS data collection. Starts the FPS data collection.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.startFpsCollection"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_stopFpsCollection"></a>
## *stopFpsCollection [<sup>method</sup>](#head_Methods)*

Stops the FPS data collection.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stopFpsCollection"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_updateFps"></a>
## *updateFps [<sup>method</sup>](#head_Methods)*

Update the FPS value.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.newFpsValue | integer | mandatory | - in - int |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.updateFps",
  "params": {
    "newFpsValue": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the FrameRate interface:

FrameRate interface events:

| Notification | Description |
| :-------- | :-------- |
| [onFpsEvent](#notification_onFpsEvent) | Triggered by callback from FrameRate after onFpsEvent |
| [onDisplayFrameRateChanging](#notification_onDisplayFrameRateChanging) | Triggered when the framerate changes started |
| [onDisplayFrameRateChanged](#notification_onDisplayFrameRateChanged) | Triggered when the framerate changed |

<a id="notification_onFpsEvent"></a>
## *onFpsEvent [<sup>notification</sup>](#head_Notifications)*

Triggered by callback from FrameRate after onFpsEvent.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.average | integer | mandatory | - in - int |
| params.min | integer | mandatory | - in - int |
| params.max | integer | mandatory | - in - int |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFpsEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFpsEvent",
  "params": {
    "average": 0,
    "min": 0,
    "max": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFpsEvent``.

<a id="notification_onDisplayFrameRateChanging"></a>
## *onDisplayFrameRateChanging [<sup>notification</sup>](#head_Notifications)*

Triggered when the framerate changes started.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.displayFrameRate | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDisplayFrameRateChanging",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDisplayFrameRateChanging",
  "params": {
    "displayFrameRate": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDisplayFrameRateChanging``.

<a id="notification_onDisplayFrameRateChanged"></a>
## *onDisplayFrameRateChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the framerate changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.displayFrameRate | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDisplayFrameRateChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDisplayFrameRateChanged",
  "params": {
    "displayFrameRate": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDisplayFrameRateChanged``.

