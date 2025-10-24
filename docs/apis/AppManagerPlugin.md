<!-- Generated automatically, DO NOT EDIT! -->
<a id="AppManager_Plugin"></a>
# AppManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AppManager)**

A AppManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AppManager` plugin provides an interface for AppManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppManager) |
| classname | string | Class name: *AppManager* |
| locator | string | Library name: *libWPEFrameworkAppManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the AppManager plugin:

AppManager interface methods:

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

Clears all persistent data for all apps.

### Events
Event details are missing in the header file documentation.
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

Clears all persistent data for a given appId.

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AppManager.clearAppData", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

closeApp moves the state from Active to Running state

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AppManager.closeApp", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

Retrieves meta data about an installed app

### Events
Event details are missing in the header file documentation.
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
        "appId": "",
        "metaData": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AppManager.getAppMetadata", "params": {"appId": "", "metaData": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "result": ""
    }
}
```

<a id="getAppProperty"></a>
## *getAppProperty*

Gets a property for a given app.

### Events
Event details are missing in the header file documentation.
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
        "appId": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AppManager.getAppProperty", "params": {"appId": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "value": ""
    }
}
```

<a id="getInstalledApps"></a>
## *getInstalledApps*

Function fetches the details of all applications currently installed

### Events
Event details are missing in the header file documentation.
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
        "apps": ""
    }
}
```

<a id="getLoadedApps"></a>
## *getLoadedApps*

Retrieves a list of applications currently loaded on the system.

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.apps | ILoadedAppInfoIterator | A list containing the details of loaded applications |
| result.apps[#].appId | string |  |
| result.apps[#].appInstanceId | string |  |
| result.apps[#].activeSessionId | string |  |
| result.apps[#].targetLifecycleState | string |  |
| result.apps[#].currentLifecycleState | string |  |

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
            "appId": "",
            "appInstanceId": "",
            "activeSessionId": "",
            "targetLifecycleState": "APP_STATE_UNKNOWN",
            "currentLifecycleState": "APP_STATE_UNKNOWN"
        }
    ]
}
```

<a id="isInstalled"></a>
## *isInstalled*

check whether the Application is installed or not

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.installed | bool | if it is installed then return true otherwise false |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.AppManager.isInstalled",
    "params": {
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AppManager.isInstalled", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

killApp will terminate forcefully

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AppManager.killApp", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

Launch an Application and app will be in ACTIVE state.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.intent | string | <sup>(optional)</sup>A reference to the intent string that specifies the action or request to be processed. |
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
        "appId": "",
        "intent": "",
        "launchArgs": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AppManager.launchApp", "params": {"appId": "", "intent": "", "launchArgs": ""}}' http://127.0.0.1:9998/jsonrpc
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

Preloads an Application and app will be in the RUNNING state (hidden).

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.launchArgs | string | <sup>(optional)</sup>Additional parameters passed to the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.error | string | if success = false it holds the appropriate error reason. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.AppManager.preloadApp",
    "params": {
        "appId": "",
        "launchArgs": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AppManager.preloadApp", "params": {"appId": "", "launchArgs": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "error": ""
    }
}
```

<a id="sendIntent"></a>
## *sendIntent*

Sends an intent to a loaded app.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
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
        "appId": "",
        "intent": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AppManager.sendIntent", "params": {"appId": "", "intent": ""}}' http://127.0.0.1:9998/jsonrpc
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

Sets a property for a given app

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
| params.value | string | the value of the key |
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
        "appId": "",
        "key": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AppManager.setAppProperty", "params": {"appId": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
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

Start the System Application

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AppManager.startSystemApp", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

Stop the System Application

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.AppManager.stopSystemApp", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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

TerminateApp will terminate gracefully

### Events
Event details are missing in the header file documentation.
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
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.AppManager.terminateApp", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the AppManager plugin:

AppManager interface properties:

| Method | Description |
| :-------- | :-------- |
| [getMaxHibernatedApps](#getMaxHibernatedApps)<sup>RO</sup> | Get the maximum number of apps to maintain in the hibernated state |
| [getMaxHibernatedFlashUsage](#getMaxHibernatedFlashUsage)<sup>RO</sup> | Gets the max size of flash to use for hibernated apps (in mebibytes) |
| [getMaxInactiveRamUsage](#getMaxInactiveRamUsage)<sup>RO</sup> | Gets the max amount of ram available for inactive apps (in mebibytes) |
| [getMaxRunningApps](#getMaxRunningApps)<sup>RO</sup> | Gets the maximum number of apps to maintain in the running or suspended state |

<a id="GetMaxHibernatedApps"></a>
## *GetMaxHibernatedApps*

Get the maximum number of apps to maintain in the hibernated state

> This property is read-only.
### Events
Event details are missing in the header file documentation.
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
        "maxHibernatedApps": 0
    }
}
```

<a id="GetMaxHibernatedFlashUsage"></a>
## *GetMaxHibernatedFlashUsage*

Gets the max size of flash to use for hibernated apps (in mebibytes)

> This property is read-only.
### Events
Event details are missing in the header file documentation.
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
        "maxHibernatedFlashUsage": 0
    }
}
```

<a id="GetMaxInactiveRamUsage"></a>
## *GetMaxInactiveRamUsage*

Gets the max amount of ram available for inactive apps (in mebibytes)

> This property is read-only.
### Events
Event details are missing in the header file documentation.
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
        "maxInactiveRamUsage": 0
    }
}
```

<a id="GetMaxRunningApps"></a>
## *GetMaxRunningApps*

Gets the maximum number of apps to maintain in the running or suspended state

> This property is read-only.
### Events
Event details are missing in the header file documentation.
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
        "maxRunningApps": 0
    }
}
```


<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the AppManager plugin:

AppManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppInstalled](#onAppInstalled) | Triggered whenever the App is installed. |
| [onAppLaunchRequest](#onAppLaunchRequest) | Triggered whenever there is a request for App Launch. |
| [onAppLifecycleStateChanged](#onAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app. |
| [onAppUninstalled](#onAppUninstalled) | Triggered whenever the App is uninstalled. |
| [onAppUnloaded](#onAppUnloaded) | Triggered whenever the App is unloaded(terminated). |

<a id="onAppInstalled"></a>
## *onAppInstalled*

Triggered whenever the App is installed.

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
        "appId": "",
        "version": ""
    }
}
```

<a id="onAppLaunchRequest"></a>
## *onAppLaunchRequest*

Triggered whenever there is a request for App Launch.

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
        "appId": "",
        "intent": "",
        "source": ""
    }
}
```

<a id="onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged*

Triggered whenever there is a change in the lifecycle state of a running app.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |
| params.newState | string | The new state to transition the application. |
| params.oldState | string | The previous state of the application instance before the update. |
| params.errorReason | string | The reason for any error encountered during the state transition |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.AppManager.onAppLifecycleStateChanged",
    "params": {
        "appId": "",
        "appInstanceId": "",
        "newState": "APP_STATE_UNKNOWN",
        "oldState": "APP_STATE_UNKNOWN",
        "errorReason": "APP_ERROR_NONE"
    }
}
```

<a id="onAppUninstalled"></a>
## *onAppUninstalled*

Triggered whenever the App is uninstalled.

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
        "appId": ""
    }
}
```

<a id="onAppUnloaded"></a>
## *onAppUnloaded*

Triggered whenever the App is unloaded(terminated).

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
        "appId": "",
        "appInstanceId": ""
    }
}
```
