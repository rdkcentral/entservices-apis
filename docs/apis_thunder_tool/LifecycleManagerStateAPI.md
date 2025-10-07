<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_LifecycleManagerState_API"></a>
# LifecycleManagerState API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

LifecycleManagerState interface for Thunder framework.

(Defined with ILifecycleManagerState in [ILifecycleManagerState.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ILifecycleManagerState.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the LifecycleManagerState interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

LifecycleManagerState JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the LifecycleManagerState interface:

LifecycleManagerState interface methods:

| Method | Description |
| :-------- | :-------- |
| [appReady](#method_appReady) | Response api call to appInitializing API |
| [stateChangeComplete](#method_stateChangeComplete) | Response api call to appLifecycleStateChanged API |
| [closeApp](#method_closeApp) | close the app |

<a id="method_appReady"></a>
## *appReady [<sup>method</sup>](#head_Methods)*

Response api call to appInitializing API.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.appReady",
  "params": {
    "appId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_stateChangeComplete"></a>
## *stateChangeComplete [<sup>method</sup>](#head_Methods)*

Response api call to appLifecycleStateChanged API.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.stateChangedId | integer | mandatory | State changed identifier |
| params.success | boolean | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stateChangeComplete",
  "params": {
    "appId": "...",
    "stateChangedId": 0,
    "success": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_closeApp"></a>
## *closeApp [<sup>method</sup>](#head_Methods)*

close the app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.closeReason | string | mandatory | Closed reason for application (must be one of the following: *ERROR, KILL_AND_ACTIVATE, KILL_AND_RUN, USER_EXIT*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.closeApp",
  "params": {
    "appId": "...",
    "closeReason": "ERROR"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the LifecycleManagerState interface:

LifecycleManagerState interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppLifecycleStateChanged](#notification_onAppLifecycleStateChanged) | Notifies the new state |

<a id="notification_onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>notification</sup>](#head_Notifications)*

Notifies the new state.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.appInstanceId | string | mandatory |  |
| params.oldState | string | mandatory |  (must be one of the following: *ACTIVE, HIBERNATED, INITIALIZING, LOADING, PAUSED, SUSPENDED, TERMINATING, UNLOADED*) |
| params.newState | string | mandatory |  (must be one of the following: *ACTIVE, HIBERNATED, INITIALIZING, LOADING, PAUSED, SUSPENDED, TERMINATING, UNLOADED*) |
| params.navigationIntent | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppLifecycleStateChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppLifecycleStateChanged",
  "params": {
    "appId": "...",
    "appInstanceId": "...",
    "oldState": "LOADING",
    "newState": "LOADING",
    "navigationIntent": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppLifecycleStateChanged``.

