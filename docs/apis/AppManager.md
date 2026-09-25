<!-- Generated automatically, DO NOT EDIT! -->
<a id="AppManager_Module"></a>
# AppManager Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AppManager/IAppManager.h)**

A AppManager module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IAppManager](#IAppManager)
    - [Methods](#IAppManager-Methods)
    - [Notifications](#IAppManager-Notifications)
    - [Properties](#IAppManager-Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AppManager` module provides the following interface(s):

- IAppManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppManager) |
| classname | string | Class name: *AppManager* |
| locator | string | Library name: *libWPEFrameworkAppManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IAppManager"></a>
## IAppManager Interface

<a id="IAppManager-Methods"></a>
### Methods

The following methods are provided by the IAppManager Interface:

| Method | Description |
| :-------- | :-------- |
| [clearAllAppData](#clearAllAppData) | Clears all persistent data for all apps. |
| [clearAppData](#clearAppData) | Clears all persistent data for a given appId. |
| [closeApp](#closeApp) | closeApp moves the state from Active to Running state |
| [getAppMetadata](#getAppMetadata) | Retrieves meta data about an installed app |
| [getAppProperty](#getAppProperty) | Gets a property for a given app. |
| [getInstalledApps](#getInstalledApps) | Function fetches the details of all applications currently installed |
| [getLoadedApps](#getLoadedApps) | Retrieves a list of applications currently loaded on the system. |
| [isInstalled](#isInstalled) | check whether the Application is installed or not |
| [killApp](#killApp) | killApp will terminate forcefully |
| [launchApp](#launchApp) | Launch an Application and app will be in ACTIVE state. |
| [preloadApp](#preloadApp) | Preloads an Application and app will be in the RUNNING state (hidden). |
| [sendIntent](#sendIntent) | Sends an intent to a loaded app. |
| [setAppProperty](#setAppProperty) | Sets a property for a given app |
| [startSystemApp](#startSystemApp) | Start the System Application |
| [stopSystemApp](#stopSystemApp) | Stop the System Application |
| [terminateApp](#terminateApp) | TerminateApp will terminate gracefully |

<a id="clearAllAppData"></a>
## *clearAllAppData*

This function clears all persistent data for all installed applications.

### Events Triggered
None
### Parameters
This method takes no parameters.
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
    "method": "org.rdk.AppManager.clearAllAppData"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AppManager.clearAllAppData"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="clearAppData"></a>
## *clearAppData*

This function clears all persistent data for the specified application.

### Events Triggered
None
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
    "id": 1,
    "method": "org.rdk.AppManager.clearAppData",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AppManager.clearAppData", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="closeApp"></a>
## *closeApp*

This function closes the specified application and moves it from the Active state to the Running state (hidden).

### Events Triggered
None
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
    "id": 2,
    "method": "org.rdk.AppManager.closeApp",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AppManager.closeApp", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="getAppMetadata"></a>
## *getAppMetadata*

This function retrieves meta data about the specified application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.metaData | string | the name of the meta-data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | string | string holding json formatted app metadata |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AppManager.getAppMetadata",
    "params": {
        "appId": "com.example.myapp",
        "metaData": "com.example.myapp.META_DATA_KEY"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AppManager.getAppMetadata", "params": {"appId": "com.example.myapp", "metaData": "com.example.myapp.META_DATA_KEY"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "result": "{\\\"key\\\":\\\"value\\\"}"
    }
}
```

<a id="getAppProperty"></a>
## *getAppProperty*

This function retrieves the value of the specified property for the given application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string | the value of the key |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.AppManager.getAppProperty",
    "params": {
        "appId": "com.example.myapp",
        "key": "com.example.myapp.PROPERTY_KEY"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AppManager.getAppProperty", "params": {"appId": "com.example.myapp", "key": "com.example.myapp.PROPERTY_KEY"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "value": "some_value"
    }
}
```

<a id="getInstalledApps"></a>
## *getInstalledApps*

This function retrieves the details of all applications currently installed on the system.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.apps | string | A list containing the details of installed applications. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.AppManager.getInstalledApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.AppManager.getInstalledApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "apps": "[{\\\"appId\\\": \\\"com.example.myapp\\\", \\\"name\\\": \\\"My App\\\"}]"
    }
}
```

<a id="getLoadedApps"></a>
## *getLoadedApps*

This function retrieves the details of all applications currently loaded on the system.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.apps | array | A list containing the details of loaded applications |
| result.apps[#].appId | string | appId |
| result.apps[#].appInstanceId | string | appInstanceId |
| result.apps[#].activeSessionId | string | activeSessionId |
| result.apps[#].type | string | type |
| result.apps[#].targetLifecycleState | string | targetLifecycleState. Possible values: APP_STATE_UNKNOWN, APP_STATE_UNLOADED, APP_STATE_LOADING, APP_STATE_INITIALIZING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_ACTIVE, APP_STATE_SUSPENDED, APP_STATE_HIBERNATED, APP_STATE_TERMINATING |
| result.apps[#].lifecycleState | string | lifecycleState. Possible values: APP_STATE_UNKNOWN, APP_STATE_UNLOADED, APP_STATE_LOADING, APP_STATE_INITIALIZING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_ACTIVE, APP_STATE_SUSPENDED, APP_STATE_HIBERNATED, APP_STATE_TERMINATING |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.AppManager.getLoadedApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.AppManager.getLoadedApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": [
        {
            "appId": "com.example.myapp",
            "appInstanceId": "instance-123",
            "activeSessionId": "session-456",
            "type": "web",
            "targetLifecycleState": "APP_STATE_RUNNING",
            "lifecycleState": "APP_STATE_RUNNING"
        }
    ]
}
```

<a id="isInstalled"></a>
## *isInstalled*

This function checks whether a specific application is installed on the system.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.installed | bool | If it is installed then return true otherwise false |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.AppManager.isInstalled",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AppManager.isInstalled", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "installed": true
    }
}
```

<a id="killApp"></a>
## *killApp*

This function forcefully terminates the specified application.

### Events Triggered
None
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
    "id": 8,
    "method": "org.rdk.AppManager.killApp",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AppManager.killApp", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="launchApp"></a>
## *launchApp*

This function launches the specified application and moves it to the ACTIVE state.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.intent | string | <sup>(optional)</sup>Specifies the intent or message to be executed. |
| params?.launchArgs | string | <sup>(optional)</sup>Additional parameters passed to the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.AppManager.launchApp",
    "params": {
        "appId": "com.example.myapp",
        "intent": "com.example.myapp.ACTION_DO_SOMETHING",
        "launchArgs": "--fullscreen"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AppManager.launchApp", "params": {"appId": "com.example.myapp", "intent": "com.example.myapp.ACTION_DO_SOMETHING", "launchArgs": "--fullscreen"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="preloadApp"></a>
## *preloadApp*

This function preloads the specified application and moves it to the RUNNING state (hidden).

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.intent | string | <sup>(optional)</sup>Specifies the intent or message to be available during preload. |
| params?.launchArgs | string | <sup>(optional)</sup>Additional parameters passed to the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.error | string | Output parameter populated with the error reason when the method returns a failure through Core::hresult |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.AppManager.preloadApp",
    "params": {
        "appId": "com.example.myapp",
        "intent": "com.example.myapp.ACTION_DO_SOMETHING",
        "launchArgs": "--fullscreen"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AppManager.preloadApp", "params": {"appId": "com.example.myapp", "intent": "com.example.myapp.ACTION_DO_SOMETHING", "launchArgs": "--fullscreen"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "error": "Failed to preload application due to missing resources."
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "error": {
        "code": 1,
        "message": "Preload failed."
    }
}
```

<a id="sendIntent"></a>
## *sendIntent*

This function sends an intent or message to the specified application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.intent | string | Specifies the intent or message to be executed. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.AppManager.sendIntent",
    "params": {
        "appId": "com.example.myapp",
        "intent": "com.example.myapp.ACTION_DO_SOMETHING"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AppManager.sendIntent", "params": {"appId": "com.example.myapp", "intent": "com.example.myapp.ACTION_DO_SOMETHING"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="setAppProperty"></a>
## *setAppProperty*

This function sets the value of the specified property for the given application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
| params.value | string | the property value to set, this can be a boolean,number, string or object type |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.AppManager.setAppProperty",
    "params": {
        "appId": "com.example.myapp",
        "key": "com.example.myapp.PROPERTY_KEY",
        "value": "some_value"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AppManager.setAppProperty", "params": {"appId": "com.example.myapp", "key": "com.example.myapp.PROPERTY_KEY", "value": "some_value"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="startSystemApp"></a>
## *startSystemApp*

This function starts the specified system application.

### Events Triggered
None
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
    "id": 13,
    "method": "org.rdk.AppManager.startSystemApp",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AppManager.startSystemApp", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="stopSystemApp"></a>
## *stopSystemApp*

This function stops the specified system application.

### Events Triggered
None
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
    "id": 14,
    "method": "org.rdk.AppManager.stopSystemApp",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.AppManager.stopSystemApp", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="terminateApp"></a>
## *terminateApp*

This function terminates the specified application gracefully.

### Events Triggered
None
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
    "id": 15,
    "method": "org.rdk.AppManager.terminateApp",
    "params": {
        "appId": "com.example.myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.AppManager.terminateApp", "params": {"appId": "com.example.myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="IAppManager-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IAppManager Interface:

| Event | Description |
| :-------- | :-------- |
| [onAppInstalled](#onAppInstalled) | Triggered whenever the App is installed. |
| [onAppLaunchRequest](#onAppLaunchRequest) | Triggered whenever there is a request for App Launch. |
| [onAppLifecycleStateChanged](#onAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app. |
| [onAppUninstalled](#onAppUninstalled) | Triggered whenever the App is uninstalled. |
| [onAppUnloaded](#onAppUnloaded) | Triggered whenever the App is unloaded(terminated). |

<a id="onAppInstalled"></a>
## *onAppInstalled*

This event is triggered whenever a new application is successfully installed on the system.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.version | string | The version number of the application in string format |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.AppManager.onAppInstalled",
    "params": {
        "appId": "com.example.myapp",
        "version": "1.0.0"
    }
}
```

<a id="onAppLaunchRequest"></a>
## *onAppLaunchRequest*

This event is triggered whenever there is a request to launch an application.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
| params.source | string | A string indicating the source of the intent |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.AppManager.onAppLaunchRequest",
    "params": {
        "appId": "com.example.myapp",
        "intent": "com.example.myapp.ACTION_DO_SOMETHING",
        "source": "com.example.myapp"
    }
}
```

<a id="onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged*

This event is triggered whenever there is a change in the lifecycle state of a running application.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |
| params.newState | string | The new state to transition the application. Possible values: APP_STATE_UNKNOWN, APP_STATE_UNLOADED, APP_STATE_LOADING, APP_STATE_INITIALIZING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_ACTIVE, APP_STATE_SUSPENDED, APP_STATE_HIBERNATED, APP_STATE_TERMINATING |
| params.oldState | string | The previous state of the application instance before the update. Possible values: APP_STATE_UNKNOWN, APP_STATE_UNLOADED, APP_STATE_LOADING, APP_STATE_INITIALIZING, APP_STATE_PAUSED, APP_STATE_RUNNING, APP_STATE_ACTIVE, APP_STATE_SUSPENDED, APP_STATE_HIBERNATED, APP_STATE_TERMINATING |
| params.errorReason | string | The reason for any error encountered during the state transition. Possible values: APP_ERROR_NONE, APP_ERROR_UNKNOWN, APP_ERROR_STATE_TIMEOUT, APP_ERROR_ABORT, APP_ERROR_INVALID_PARAM, APP_ERROR_CREATE_DISPLAY, APP_ERROR_DOBBY_SPEC, APP_ERROR_NOT_INSTALLED, APP_ERROR_PACKAGE_LOCK |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.AppManager.onAppLifecycleStateChanged",
    "params": {
        "appId": "com.example.myapp",
        "appInstanceId": 12345,
        "newState": "AppLifecycleState::Running",
        "oldState": "AppLifecycleState::Stopped",
        "errorReason": "AppErrorReason::None"
    }
}
```

<a id="onAppUninstalled"></a>
## *onAppUninstalled*

This event is triggered whenever an application is successfully uninstalled from the system.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.AppManager.onAppUninstalled",
    "params": {
        "appId": "com.example.myapp"
    }
}
```

<a id="onAppUnloaded"></a>
## *onAppUnloaded*

This event is triggered whenever an application is unloaded (terminated).

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.AppManager.onAppUnloaded",
    "params": {
        "appId": "com.example.myapp",
        "appInstanceId": 12345
    }
}
```

<a id="IAppManager-Properties"></a>
### Properties

The following properties are provided by the IAppManager Interface:

| Property | Description |
| :-------- | :-------- |
| [getMaxHibernatedApps](#getMaxHibernatedApps)<sup>RO</sup> | Get the maximum number of apps to maintain in the hibernated state |
| [getMaxHibernatedFlashUsage](#getMaxHibernatedFlashUsage)<sup>RO</sup> | Gets the max size of flash to use for hibernated apps (in mebibytes) |
| [getMaxInactiveRamUsage](#getMaxInactiveRamUsage)<sup>RO</sup> | Gets the max amount of ram available for inactive apps (in mebibytes) |
| [getMaxRunningApps](#getMaxRunningApps)<sup>RO</sup> | Gets the maximum number of apps to maintain in the running or suspended state |

<a id="getMaxHibernatedApps"></a>
## *getMaxHibernatedApps*

This function retrieves the maximum number of apps that can be maintained in the hibernated state.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxHibernatedApps | integer | max number of apps to maintain in the hibernated state |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.AppManager.getMaxHibernatedApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.AppManager.getMaxHibernatedApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "maxHibernatedApps": 5
    }
}
```

<a id="getMaxHibernatedFlashUsage"></a>
## *getMaxHibernatedFlashUsage*

This function retrieves the maximum size of flash that can be used for hibernated apps.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxHibernatedFlashUsage | integer | max size of flash to use for hibernated apps (in mebibytes) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.AppManager.getMaxHibernatedFlashUsage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.AppManager.getMaxHibernatedFlashUsage"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "maxHibernatedFlashUsage": 1024
    }
}
```

<a id="getMaxInactiveRamUsage"></a>
## *getMaxInactiveRamUsage*

This function retrieves the maximum amount of RAM that can be used for inactive apps.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxInactiveRamUsage | integer | max ram available for inactive apps (in mebibytes) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.AppManager.getMaxInactiveRamUsage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.AppManager.getMaxInactiveRamUsage"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "maxInactiveRamUsage": 512
    }
}
```

<a id="getMaxRunningApps"></a>
## *getMaxRunningApps*

This function retrieves the maximum number of apps that can be maintained in the running or suspended state.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxRunningApps | integer | max number of apps to maintain in the running or suspended state |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.AppManager.getMaxRunningApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.AppManager.getMaxRunningApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "maxRunningApps": 10
    }
}
```

