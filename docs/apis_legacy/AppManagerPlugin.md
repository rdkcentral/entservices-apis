<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.AppManager_Plugin"></a>
# AppManager Plugin

A org.rdk.AppManager plugin for Thunder framework.

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

The `AppManager` that is responsible for providing the Resident App APIs for running and managing applications, and notifying listeners of any app lifecycle events or state changes.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.AppManager*) |
| classname | string | Class name: *org.rdk.AppManager* |
| locator | string | Library name: *libWPEFrameworkAppManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.AppManager plugin:

org.rdk.AppManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [getInstalledApps](#method.getInstalledApps) | Function fetches the details of all applications currently installed |
| [isInstalled](#method.isInstalled) | Check whether a specific application is installed on the system |
| [getLoadedApps](#method.getLoadedApps) | Retrieves a list of applications currently loaded on the system |
| [launchApp](#method.launchApp) | Launch an Application and app will be in ACTIVE state |
| [preloadApp](#method.preloadApp) | Preloads an Application |
| [closeApp](#method.closeApp) | closeApp moves the state from ACTIVE to PAUSED state, then transitions it to SUSPENDED, HIBERNATED, or UNLOADED based on system policies |
| [terminateApp](#method.terminateApp) | terminateApp terminates an Application gracefully |
| [startSystemApp](#method.startSystemApp) | startSystemApp starts the system Application  |
| [stopSystemApp](#method.stopSystemApp) | stopSystemApp stops the system Application  |
| [killApp](#method.killApp) | killApp kills an application forcefully |
| [sendIntent](#method.sendIntent) | Sends an intent to a loaded app |
| [clearAppData](#method.clearAppData) | Clears all persistent data for a given appId |
| [clearAllAppData](#method.clearAllAppData) | Clears all persistent data for all apps |
| [getAppMetadata](#method.getAppMetadata) | Retrieves meta data about an installed app |
| [setAppProperty](#method.setAppProperty) | Sets a property for a given app |
| [getAppProperty](#method.getAppProperty) | Gets a property for a given app |
| [getMaxRunningApps](#method.getMaxRunningApps) | Gets the maximum number of apps to maintain in the running or suspended state |


<a name="method.getInstalledApps"></a>
## *getInstalledApps [<sup>method</sup>](#head.Methods)*

Function fetches the details of all applications currently installed.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array | List of installed applications (returned as a JSON string in actual API, shown here as parsed for clarity) |
| result[#] | object |  |
| result[#].appId | string | The unique identifier of the application to check |
| result[#].versionString | string | The version number of the application in string format |
| result[#].type | string |  |
| result[#]?.lastActiveTime | string | <sup>*(optional)*</sup>  |
| result[#]?.lastActiveIndex | string | <sup>*(optional)*</sup>  |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.getInstalledApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "appId": "YouTube",
            "versionString": "2.3.9",
            "type": "APPLICATION_TYPE_INTERACTIVE",
            "lastActiveTime": "...",
            "lastActiveIndex": "..."
        }
    ]
}
```

<a name="method.isInstalled"></a>
## *isInstalled [<sup>method</sup>](#head.Methods)*

Check whether a specific application is installed on the system.

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
| result | boolean | Returns true if the application is installed, false otherwise |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.isInstalled",
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
    "result": true
}
```

<a name="method.getLoadedApps"></a>
## *getLoadedApps [<sup>method</sup>](#head.Methods)*

Retrieves a list of applications currently loaded on the system.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array | List of loaded applications |
| result[#] | object | Details of a loaded application |
| result[#].appId | string | The unique identifier of the application to check |
| result[#].type | integer | Application type |
| result[#].lifecycleState | integer | Current lifecycle state of the application |
| result[#].targetLifecycleState | integer | Target lifecycle state of the application |
| result[#].activeSessionId | string | Active session identifier |
| result[#].appInstanceId | string | Instance identifier of the application |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.getLoadedApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "appId": "YouTube",
            "type": 1,
            "lifecycleState": 0,
            "targetLifecycleState": 2,
            "activeSessionId": "...",
            "appInstanceId": "80df148e-b52e-4c0f-8964-0de4c090426f"
        }
    ]
}
```

<a name="method.launchApp"></a>
## *launchApp [<sup>method</sup>](#head.Methods)*

Launch an Application and app will be in ACTIVE state.

### Events

| Event | Description |
| :-------- | :-------- |
| [OnAppLaunchRequest](#event.OnAppLaunchRequest) | Triggered whenever there is a request for App Launch. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params?.intent | string | <sup>*(optional)*</sup> Specifies the intent or message to be executed |
| params?.launchArgs | string | <sup>*(optional)*</sup> Additional parameters passed to the application |

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
    "method": "org.rdk.AppManager.launchApp",
    "params": {
        "appId": "YouTube",
        "intent": "start",
        "launchArgs": "{}"
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

<a name="method.preloadApp"></a>
## *preloadApp [<sup>method</sup>](#head.Methods)*

Preloads an Application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params?.launchArgs | string | <sup>*(optional)*</sup> Additional parameters passed to the application |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | Returns an empty string on success or an error message if preload failed |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.preloadApp",
    "params": {
        "appId": "YouTube",
        "launchArgs": "{}"
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

<a name="method.closeApp"></a>
## *closeApp [<sup>method</sup>](#head.Methods)*

closeApp moves the state from ACTIVE to PAUSED state, then transitions it to SUSPENDED, HIBERNATED, or UNLOADED based on system policies.

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
    "method": "org.rdk.AppManager.closeApp",
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

<a name="method.terminateApp"></a>
## *terminateApp [<sup>method</sup>](#head.Methods)*

terminateApp terminates an Application gracefully.

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
    "method": "org.rdk.AppManager.terminateApp",
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

<a name="method.startSystemApp"></a>
## *startSystemApp [<sup>method</sup>](#head.Methods)*

startSystemApp starts the system Application .

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
    "method": "org.rdk.AppManager.startSystemApp",
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

<a name="method.stopSystemApp"></a>
## *stopSystemApp [<sup>method</sup>](#head.Methods)*

stopSystemApp stops the system Application .

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
    "method": "org.rdk.AppManager.stopSystemApp",
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

<a name="method.killApp"></a>
## *killApp [<sup>method</sup>](#head.Methods)*

killApp kills an application forcefully.

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
    "method": "org.rdk.AppManager.killApp",
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

<a name="method.sendIntent"></a>
## *sendIntent [<sup>method</sup>](#head.Methods)*

Sends an intent to a loaded app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.intent | string | Specifies the intent or message to be executed |

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
    "method": "org.rdk.AppManager.sendIntent",
    "params": {
        "appId": "YouTube",
        "intent": "start"
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

<a name="method.clearAppData"></a>
## *clearAppData [<sup>method</sup>](#head.Methods)*

Clears all persistent data for a given appId.

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
    "method": "org.rdk.AppManager.clearAppData",
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

<a name="method.clearAllAppData"></a>
## *clearAllAppData [<sup>method</sup>](#head.Methods)*

Clears all persistent data for all apps.

### Events

No Events

### Parameters

This method takes no parameters.

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
    "method": "org.rdk.AppManager.clearAllAppData"
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

<a name="method.getAppMetadata"></a>
## *getAppMetadata [<sup>method</sup>](#head.Methods)*

Retrieves meta data about an installed app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.metaData | string | the name of the meta-data to retrieve |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | The string holding json formatted app metadata |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.getAppMetadata",
    "params": {
        "appId": "YouTube",
        "metaData": "xyz"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "{'xyz': 'value1'}"
}
```

<a name="method.setAppProperty"></a>
## *setAppProperty [<sup>method</sup>](#head.Methods)*

Sets a property for a given app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.key | string | The name of the property to get or set |
| params.value | string | The property value to set, can be boolean, number, string or object |

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
    "method": "org.rdk.AppManager.setAppProperty",
    "params": {
        "appId": "YouTube",
        "key": "delay",
        "value": "10"
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

<a name="method.getAppProperty"></a>
## *getAppProperty [<sup>method</sup>](#head.Methods)*

Gets a property for a given app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.key | string | The name of the property to get or set |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | The property value as a JSON string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.getAppProperty",
    "params": {
        "appId": "YouTube",
        "key": "delay"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "10"
}
```

<a name="method.getMaxRunningApps"></a>
## *getMaxRunningApps [<sup>method</sup>](#head.Methods)*

Gets the maximum number of apps to maintain in the running or suspended state.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.maxRunningApps | integer | Maximum number of apps to maintain in the running or suspended state |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.AppManager.getMaxRunningApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "maxRunningApps": 5
    }
}
```

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.AppManager plugin:

org.rdk.AppManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppInstalled](#event.onAppInstalled) | Triggered whenever the App is installed |
| [onAppUninstalled](#event.onAppUninstalled) | Triggered whenever the App is uninstalled |
| [onAppLifecycleStateChanged](#event.onAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app |
| [onAppLaunchRequest](#event.onAppLaunchRequest) | Triggered whenever there is a request for App Launch |
| [onAppUnloaded](#event.onAppUnloaded) | Triggered whenever the App is unloaded (terminated) |


<a name="event.onAppInstalled"></a>
## *onAppInstalled [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is installed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.version | string | The version number of the application in string format |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppInstalled",
    "params": {
        "appId": "YouTube",
        "version": "2.3.9"
    }
}
```

<a name="event.onAppUninstalled"></a>
## *onAppUninstalled [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is uninstalled.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppUninstalled",
    "params": {
        "appId": "YouTube"
    }
}
```

<a name="event.onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered whenever there is a change in the lifecycle state of a running app.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.appInstanceId | string | Instance identifier of the application |
| params.newState | string | Possible lifecycle states of an application (must be one of the following: *APP_STATE_UNKNOWN*, *APP_STATE_UNLOADED*, *APP_STATE_LOADING*, *APP_STATE_INITIALIZING*, *APP_STATE_PAUSED*, *APP_STATE_RUNNING*, *APP_STATE_ACTIVE*, *APP_STATE_SUSPENDED*, *APP_STATE_HIBERNATED*, *APP_STATE_TERMINATING*) |
| params.oldState | string | Possible lifecycle states of an application (must be one of the following: *APP_STATE_UNKNOWN*, *APP_STATE_UNLOADED*, *APP_STATE_LOADING*, *APP_STATE_INITIALIZING*, *APP_STATE_PAUSED*, *APP_STATE_RUNNING*, *APP_STATE_ACTIVE*, *APP_STATE_SUSPENDED*, *APP_STATE_HIBERNATED*, *APP_STATE_TERMINATING*) |
| params.errorReason | string | Possible error reasons during app lifecycle state transitions (must be one of the following: *APP_ERROR_NONE*, *APP_ERROR_UNKNOWN*, *APP_ERROR_STATE_TIMEOUT*, *APP_ERROR_ABORT*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppLifecycleStateChanged",
    "params": {
        "appId": "YouTube",
        "appInstanceId": "80df148e-b52e-4c0f-8964-0de4c090426f",
        "newState": "APP_STATE_UNKNOWN",
        "oldState": "APP_STATE_UNKNOWN",
        "errorReason": "APP_ERROR_NONE"
    }
}
```

<a name="event.onAppLaunchRequest"></a>
## *onAppLaunchRequest [<sup>event</sup>](#head.Notifications)*

Triggered whenever there is a request for App Launch.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.intent | string | Specifies the intent or message to be executed |
| params.source | string | A string indicating the source of the intent |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppLaunchRequest",
    "params": {
        "appId": "YouTube",
        "intent": "start",
        "source": "..."
    }
}
```

<a name="event.onAppUnloaded"></a>
## *onAppUnloaded [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is unloaded (terminated).

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application to check |
| params.appInstanceId | string | Instance identifier of the application |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppUnloaded",
    "params": {
        "appId": "YouTube",
        "appInstanceId": "80df148e-b52e-4c0f-8964-0de4c090426f"
    }
}
```

