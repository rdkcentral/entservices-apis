<!-- Generated automatically, DO NOT EDIT! -->
<a id="LifecycleManager_Plugin"></a>
# LifecycleManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/LifecycleManager/ILifecycleManagerState.h)**

A LifecycleManager plugin for Thunder framework.

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

The `LifecycleManager` plugin provides an interface for LifecycleManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LifecycleManager) |
| classname | string | Class name: *LifecycleManager* |
| locator | string | Library name: *libWPEFrameworkLifecycleManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the LifecycleManager plugin:

LifecycleManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [appReady](#appReady) | Response api call to appInitializing API |
| [closeApp](#closeApp) | close the app |
| [stateChangeComplete](#stateChangeComplete) | Response api call to appLifecycleStateChanged API |

<a id="appReady"></a>
## *appReady*

Response api call to appInitializing API

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string |  |
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

<a id="closeApp"></a>
## *closeApp*

close the app

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string |  |
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

<a id="stateChangeComplete"></a>
## *stateChangeComplete*

Response api call to appLifecycleStateChanged API

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string |  |
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



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the LifecycleManager plugin:

LifecycleManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppLifecycleStateChanged](#onAppLifecycleStateChanged) | Notifies the new state |

<a id="onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged*

Notifies the new state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string |  |
| params.appInstanceId | string |  |
| params.oldLifecycleState | LifecycleState | The previous state of the application instance before the update. |
| params.newLifecycleState | LifecycleState | The new state to transition the application. |
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
        "oldLifecycleState": "",
        "newLifecycleState": "",
        "navigationIntent": ""
    }
}
```
