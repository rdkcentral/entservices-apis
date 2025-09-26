<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.LifecycleManager_Plugin"></a>
# LifecycleManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/LifecycleManager/CHANGELOG.md)**

A LifecycleManager plugin for Thunder framework.

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

The `LifecycleManager` plugin provides an interface for LifecycleManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LifecycleManager) |
| classname | string | Class name: *LifecycleManager* |
| locator | string | Library name: *libWPEFrameworkLifecycleManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the LifecycleManager plugin:

LifecycleManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [appReady](#method.appReady) | Response api call to appInitializing API |
| [closeApp](#method.closeApp) | close the app |
| [stateChangeComplete](#method.stateChangeComplete) | Response api call to appLifecycleStateChanged API |

<a id="method.appReady"></a>
## *appReady [<sup>method</sup>](#head.Methods)*

Response api call to appInitializing API

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LifecycleManager.appReady",
    "params": {
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.LifecycleManager.appReady", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.closeApp"></a>
## *closeApp [<sup>method</sup>](#head.Methods)*

close the app

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.closeReason | string | closed reason for application |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LifecycleManager.closeApp",
    "params": {
        "appId": "",
        "closeReason": "USER_EXIT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.LifecycleManager.closeApp", "params": {"appId": "", "closeReason": "USER_EXIT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.stateChangeComplete"></a>
## *stateChangeComplete [<sup>method</sup>](#head.Methods)*

Response api call to appLifecycleStateChanged API

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.stateChangedId | integer | state changed identifier |
| params.success | bool |  |
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
    "method": "org.rdk.LifecycleManager.stateChangeComplete",
    "params": {
        "appId": "",
        "stateChangedId": 0,
        "success": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.LifecycleManager.stateChangeComplete", "params": {"appId": "", "stateChangedId": 0, "success": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the LifecycleManager plugin:

LifecycleManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppLifecycleStateChanged](#event.onAppLifecycleStateChanged) | Notifies the new state |

<a id="event.onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>event</sup>](#head.Notifications)*

Notifies the new state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |
| params.oldState | ILifecycleManager::LifecycleState | The previous state of the application instance before the update. |
| params.newState | ILifecycleManager::LifecycleState | The new state to transition the application. |
| params.navigationIntent | string | navigation intent during active state |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.LifecycleManager.onAppLifecycleStateChanged",
    "params": {
        "appId": "",
        "appInstanceId": "",
        "oldState": "",
        "newState": "",
        "navigationIntent": ""
    }
}
```
