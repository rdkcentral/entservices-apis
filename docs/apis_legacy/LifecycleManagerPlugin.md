<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.LifecycleManager_Plugin"></a>
# LifecycleManager Plugin

A org.rdk.LifecycleManager plugin for Thunder framework.

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

The `LifecycleManagerState` this is responsible for maintaining the states of Application.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.LifecycleManager*) |
| classname | string | Class name: *org.rdk.LifecycleManager* |
| locator | string | Library name: *libWPEFrameworkLifecycleManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.LifecycleManager plugin:

org.rdk.LifecycleManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [appReady](#method.appReady) | Response API call to appInitializing API |
| [stateChangeComplete](#method.stateChangeComplete) | Response API call to appLifecycleStateChanged API |
| [closeApp](#method.closeApp) | Close the app |


<a name="method.appReady"></a>
## *appReady [<sup>method</sup>](#head.Methods)*

Response API call to appInitializing API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.LifecycleManager.appReady",
    "params": {
        "appId": "YouTube"
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

<a name="method.stateChangeComplete"></a>
## *stateChangeComplete [<sup>method</sup>](#head.Methods)*

Response API call to appLifecycleStateChanged API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.stateChangedId | integer | State changed identifier |
| params.success | boolean | Indicates whether the state change was successful |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.LifecycleManager.stateChangeComplete",
    "params": {
        "appId": "YouTube",
        "stateChangedId": 101,
        "success": true
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

<a name="method.closeApp"></a>
## *closeApp [<sup>method</sup>](#head.Methods)*

Close the app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.closeReason | string | Possible close reasons of an application (must be one of the following: *USER_EXIT*, *ERROR*, *KILL_AND_RUN*, *KILL_AND_ACTIVATE*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.LifecycleManager.closeApp",
    "params": {
        "appId": "YouTube",
        "closeReason": "USER_EXIT"
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

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.LifecycleManager plugin:

org.rdk.LifecycleManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppLifecycleStateChanged](#event.onAppLifecycleStateChanged) | Triggered when the lifecycle state of an application changes |


<a name="event.onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the lifecycle state of an application changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.appInstanceId | string | Instance identifier of the application |
| params.newState | string |  (must be one of the following: *UNLOADED*, *LOADING*, *INITIALIZING*, *PAUSED*, *ACTIVE*, *SUSPENDED*, *HIBERNATED*, *TERMINATING*) |
| params.oldState | string |  (must be one of the following: *UNLOADED*, *LOADING*, *INITIALIZING*, *PAUSED*, *ACTIVE*, *SUSPENDED*, *HIBERNATED*, *TERMINATING*) |
| params?.navigationIntent | string | <sup>*(optional)*</sup> Intent string for navigation or state transition |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppLifecycleStateChanged",
    "params": {
        "appId": "YouTube",
        "appInstanceId": "80df148e-b52e-4c0f-8964-0de4c090426f",
        "newState": "ACTIVE",
        "oldState": "UNLOADED",
        "navigationIntent": "launch_home"
    }
}
```

