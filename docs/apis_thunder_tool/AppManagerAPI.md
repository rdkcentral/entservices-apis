<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_AppManager_API"></a>
# AppManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

AppManager interface for Thunder framework.

(Defined with IAppManager in [IAppManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the AppManager interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

AppManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the AppManager interface:

AppManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [getInstalledApps](#method_getInstalledApps) | Function fetches the details of all applications currently installed |
| [isInstalled](#method_isInstalled) | check whether the Application is installed or not |
| [getLoadedApps](#method_getLoadedApps) | Retrieves a list of applications currently loaded on the system |
| [launchApp](#method_launchApp) | Launch an Application and app will be in ACTIVE state |
| [preloadApp](#method_preloadApp) | Preloads an Application and app will be in the RUNNING state (hidden) |
| [closeApp](#method_closeApp) | closeApp moves the state from Active to Running state |
| [terminateApp](#method_terminateApp) | TerminateApp will terminate gracefully |
| [startSystemApp](#method_startSystemApp) | Start the System Application |
| [stopSystemApp](#method_stopSystemApp) | Stop the System Application |
| [killApp](#method_killApp) | killApp will terminate forcefully |
| [sendIntent](#method_sendIntent) | Sends an intent to a loaded app |
| [clearAppData](#method_clearAppData) | Clears all persistent data for a given appId |
| [clearAllAppData](#method_clearAllAppData) | Clears all persistent data for all apps |
| [getAppMetadata](#method_getAppMetadata) | Retrieves meta data about an installed app |
| [getAppProperty](#method_getAppProperty) | Gets a property for a given app |
| [setAppProperty](#method_setAppProperty) | Sets a property for a given app |

<a id="method_getInstalledApps"></a>
## *getInstalledApps [<sup>method</sup>](#head_Methods)*

Function fetches the details of all applications currently installed.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | opaque object | mandatory | A list containing the details of installed applications |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getInstalledApps"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {}
}
```

<a id="method_isInstalled"></a>
## *isInstalled [<sup>method</sup>](#head_Methods)*

check whether the Application is installed or not.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | : if it is installed then return true otherwise false |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.isInstalled",
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
  "result": false
}
```

<a id="method_getLoadedApps"></a>
## *getLoadedApps [<sup>method</sup>](#head_Methods)*

Retrieves a list of applications currently loaded on the system.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | A list containing the details of loaded applications |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLoadedApps"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_launchApp"></a>
## *launchApp [<sup>method</sup>](#head_Methods)*

Launch an Application and app will be in ACTIVE state.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.intent | string | mandatory |  |
| params.launchArgs | string | mandatory |  |

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
  "method": "<callsign>.1.launchApp",
  "params": {
    "appId": "...",
    "intent": "...",
    "launchArgs": "..."
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

<a id="method_preloadApp"></a>
## *preloadApp [<sup>method</sup>](#head_Methods)*

Preloads an Application and app will be in the RUNNING state (hidden).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.launchArgs | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | If success = false it holds the appropriate error reason |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.preloadApp",
  "params": {
    "appId": "...",
    "launchArgs": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_closeApp"></a>
## *closeApp [<sup>method</sup>](#head_Methods)*

closeApp moves the state from Active to Running state.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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

<a id="method_terminateApp"></a>
## *terminateApp [<sup>method</sup>](#head_Methods)*

TerminateApp will terminate gracefully.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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
  "method": "<callsign>.1.terminateApp",
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

<a id="method_startSystemApp"></a>
## *startSystemApp [<sup>method</sup>](#head_Methods)*

Start the System Application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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
  "method": "<callsign>.1.startSystemApp",
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

<a id="method_stopSystemApp"></a>
## *stopSystemApp [<sup>method</sup>](#head_Methods)*

Stop the System Application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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
  "method": "<callsign>.1.stopSystemApp",
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

<a id="method_killApp"></a>
## *killApp [<sup>method</sup>](#head_Methods)*

killApp will terminate forcefully.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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
  "method": "<callsign>.1.killApp",
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

<a id="method_sendIntent"></a>
## *sendIntent [<sup>method</sup>](#head_Methods)*

Sends an intent to a loaded app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.intent | string | mandatory | Specifies the intent or message to be executed |

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
  "method": "<callsign>.1.sendIntent",
  "params": {
    "appId": "...",
    "intent": "..."
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

<a id="method_clearAppData"></a>
## *clearAppData [<sup>method</sup>](#head_Methods)*

Clears all persistent data for a given appId.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |

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
  "method": "<callsign>.1.clearAppData",
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

<a id="method_clearAllAppData"></a>
## *clearAllAppData [<sup>method</sup>](#head_Methods)*

Clears all persistent data for all apps.

### Parameters

This method takes no parameters.

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
  "method": "<callsign>.1.clearAllAppData"
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

<a id="method_getAppMetadata"></a>
## *getAppMetadata [<sup>method</sup>](#head_Methods)*

Retrieves meta data about an installed app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.metaData | string | mandatory | The name of the meta-data |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | String holding json formatted app metadata |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getAppMetadata",
  "params": {
    "appId": "...",
    "metaData": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_getAppProperty"></a>
## *getAppProperty [<sup>method</sup>](#head_Methods)*

Gets a property for a given app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.key | string | mandatory | The name of the property to get |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | The value of the key |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getAppProperty",
  "params": {
    "appId": "...",
    "key": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_setAppProperty"></a>
## *setAppProperty [<sup>method</sup>](#head_Methods)*

Sets a property for a given app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory | App identifier for the application |
| params.key | string | mandatory | The name of the property to get |
| params.value | string | mandatory | The property value to set, this can be a boolean,number, string or object type |

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
  "method": "<callsign>.1.setAppProperty",
  "params": {
    "appId": "...",
    "key": "...",
    "value": "..."
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

<a id="head_Properties"></a>
# Properties

The following properties are provided by the AppManager interface:

AppManager interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [getMaxRunningApps](#property_getMaxRunningApps) | read-only | Gets the maximum number of apps to maintain in the running or suspended state |
| [getMaxHibernatedApps](#property_getMaxHibernatedApps) | read-only | Get the maximum number of apps to maintain in the hibernated state |
| [getMaxHibernatedFlashUsage](#property_getMaxHibernatedFlashUsage) | read-only | Gets the max size of flash to use for hibernated apps (in mebibytes) |
| [getMaxInactiveRamUsage](#property_getMaxInactiveRamUsage) | read-only | Gets the max amount of ram available for inactive apps (in mebibytes) |

<a id="property_getMaxRunningApps"></a>
## *getMaxRunningApps [<sup>property</sup>](#head_Properties)*

Provides access to the gets the maximum number of apps to maintain in the running or suspended state.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Max number of apps to maintain in the running or suspended state |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMaxRunningApps"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_getMaxHibernatedApps"></a>
## *getMaxHibernatedApps [<sup>property</sup>](#head_Properties)*

Provides access to the get the maximum number of apps to maintain in the hibernated state.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Max number of apps to maintain in the hibernated state |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMaxHibernatedApps"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_getMaxHibernatedFlashUsage"></a>
## *getMaxHibernatedFlashUsage [<sup>property</sup>](#head_Properties)*

Provides access to the gets the max size of flash to use for hibernated apps (in mebibytes).

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Max size of flash to use for hibernated apps (in mebibytes) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMaxHibernatedFlashUsage"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_getMaxInactiveRamUsage"></a>
## *getMaxInactiveRamUsage [<sup>property</sup>](#head_Properties)*

Provides access to the gets the max amount of ram available for inactive apps (in mebibytes).

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Max ram available for inactive apps (in mebibytes) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMaxInactiveRamUsage"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the AppManager interface:

AppManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppInstalled](#notification_onAppInstalled) | Triggered whenever the App is installed |
| [onAppUninstalled](#notification_onAppUninstalled) | Triggered whenever the App is uninstalled |
| [onAppLifecycleStateChanged](#notification_onAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app |
| [onAppLaunchRequest](#notification_onAppLaunchRequest) | Triggered whenever there is a request for App Launch |
| [onAppUnloaded](#notification_onAppUnloaded) | Triggered whenever the App is unloaded(terminated) |

<a id="notification_onAppInstalled"></a>
## *onAppInstalled [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the App is installed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.version | string | mandatory | The version number of the application in string format |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppInstalled",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppInstalled",
  "params": {
    "appId": "...",
    "version": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppInstalled``.

<a id="notification_onAppUninstalled"></a>
## *onAppUninstalled [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the App is uninstalled.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppUninstalled",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppUninstalled",
  "params": {
    "appId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppUninstalled``.

<a id="notification_onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>notification</sup>](#head_Notifications)*

Triggered whenever there is a change in the lifecycle state of a running app.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.appInstanceId | string | mandatory |  |
| params.newState | string | mandatory |  (must be one of the following: *APP_STATE_ACTIVE, APP_STATE_HIBERNATED, APP_STATE_INITIALIZING, APP_STATE_LOADING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_SUSPENDED, APP_STATE_TERMINATING, APP_STATE_UNKNOWN, APP_STATE_UNLOADED*) |
| params.oldState | string | mandatory |  (must be one of the following: *APP_STATE_ACTIVE, APP_STATE_HIBERNATED, APP_STATE_INITIALIZING, APP_STATE_LOADING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_SUSPENDED, APP_STATE_TERMINATING, APP_STATE_UNKNOWN, APP_STATE_UNLOADED*) |
| params.errorReason | string | mandatory |  (must be one of the following: *APP_ERROR_ABORT, APP_ERROR_CREATE_DISPLAY, APP_ERROR_DOBBY_SPEC, APP_ERROR_INVALID_PARAM, APP_ERROR_NONE, APP_ERROR_NOT_INSTALLED, APP_ERROR_PACKAGE_LOCK, APP_ERROR_STATE_TIMEOUT, APP_ERROR_UNKNOWN*) |

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
    "newState": "APP_STATE_UNLOADED",
    "oldState": "APP_STATE_UNLOADED",
    "errorReason": "APP_ERROR_UNKNOWN"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppLifecycleStateChanged``.

<a id="notification_onAppLaunchRequest"></a>
## *onAppLaunchRequest [<sup>notification</sup>](#head_Notifications)*

Triggered whenever there is a request for App Launch.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.intent | string | mandatory |  |
| params.source | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppLaunchRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppLaunchRequest",
  "params": {
    "appId": "...",
    "intent": "...",
    "source": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppLaunchRequest``.

<a id="notification_onAppUnloaded"></a>
## *onAppUnloaded [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the App is unloaded(terminated).

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appId | string | mandatory |  |
| params.appInstanceId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppUnloaded",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppUnloaded",
  "params": {
    "appId": "...",
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppUnloaded``.

