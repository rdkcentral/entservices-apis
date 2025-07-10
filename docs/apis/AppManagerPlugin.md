<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.AppManager_Plugin"></a>
# AppManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/AppManager/CHANGELOG.md)**

A AppManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `AppManager` plugin provides an interface for AppManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppManager) |
| classname | string | Class name: *AppManager* |
| locator | string | Library name: *libWPEFrameworkAppManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the AppManager plugin:

AppManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [clearAllAppData](#method.clearAllAppData) | Clears all persistent data for all apps. |
| [clearAppData](#method.clearAppData) | Clears all persistent data for a given appId. |
| [closeApp](#method.closeApp) | closeApp moves the state from Active to Running state |
| [getAppMetadata](#method.getAppMetadata) | Retrieves meta data about an installed app |
| [getAppProperty](#method.getAppProperty) | Gets a property for a given app. |
| [getInstalledApps](#method.getInstalledApps) | Function fetches the details of all applications currently installed |
| [getLoadedApps](#method.getLoadedApps) | Retrieves a list of applications currently loaded on the system. |
| [isInstalled](#method.isInstalled) | check whether the Application is installed or not |
| [killApp](#method.killApp) | killApp will terminate forcefully |
| [launchApp](#method.launchApp) | Launch an Application and app will be in ACTIVE state. |
| [preloadApp](#method.preloadApp) | Preloads an Application and app will be in the RUNNING state (hidden). |
| [sendIntent](#method.sendIntent) | Sends an intent to a loaded app. |
| [setAppProperty](#method.setAppProperty) | Sets a property for a given app |
| [startSystemApp](#method.startSystemApp) | Start the System Application |
| [stopSystemApp](#method.stopSystemApp) | Stop the System Application |
| [terminateApp](#method.terminateApp) | TerminateApp will terminate gracefully |

<a id="method.clearAllAppData"></a>
## *clearAllAppData [<sup>method</sup>](#head.Methods)*

Clears all persistent data for all apps.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.AppManager.clearAllAppData"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.clearAppData"></a>
## *clearAppData [<sup>method</sup>](#head.Methods)*

Clears all persistent data for a given appId.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.closeApp"></a>
## *closeApp [<sup>method</sup>](#head.Methods)*

closeApp moves the state from Active to Running state

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.getAppMetadata"></a>
## *getAppMetadata [<sup>method</sup>](#head.Methods)*

Retrieves meta data about an installed app

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.metaData | string | the name of the meta-data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```

<a id="method.getAppProperty"></a>
## *getAppProperty [<sup>method</sup>](#head.Methods)*

Gets a property for a given app.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```

<a id="method.getInstalledApps"></a>
## *getInstalledApps [<sup>method</sup>](#head.Methods)*

Function fetches the details of all applications currently installed

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": ""
}
```

<a id="method.getLoadedApps"></a>
## *getLoadedApps [<sup>method</sup>](#head.Methods)*

Retrieves a list of applications currently loaded on the system.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.apps | string | A list containing the details of installed applications. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.AppManager.getLoadedApps"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": ""
}
```

<a id="method.isInstalled"></a>
## *isInstalled [<sup>method</sup>](#head.Methods)*

check whether the Application is installed or not

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": true
}
```

<a id="method.killApp"></a>
## *killApp [<sup>method</sup>](#head.Methods)*

killApp will terminate forcefully

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.launchApp"></a>
## *launchApp [<sup>method</sup>](#head.Methods)*

Launch an Application and app will be in ACTIVE state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.intent | string | <sup>(optional)</sup>A reference to the intent string that specifies the action or request to be processed. |
| params?.launchArgs | string | <sup>(optional)</sup>Additional parameters passed to the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.preloadApp"></a>
## *preloadApp [<sup>method</sup>](#head.Methods)*

Preloads an Application and app will be in the RUNNING state (hidden).

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params?.launchArgs | string | <sup>(optional)</sup>Additional parameters passed to the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": ""
}
```

<a id="method.sendIntent"></a>
## *sendIntent [<sup>method</sup>](#head.Methods)*

Sends an intent to a loaded app.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.setAppProperty"></a>
## *setAppProperty [<sup>method</sup>](#head.Methods)*

Sets a property for a given app

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
| params.value | string | the value of the key |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.startSystemApp"></a>
## *startSystemApp [<sup>method</sup>](#head.Methods)*

Start the System Application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.stopSystemApp"></a>
## *stopSystemApp [<sup>method</sup>](#head.Methods)*

Stop the System Application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.terminateApp"></a>
## *terminateApp [<sup>method</sup>](#head.Methods)*

TerminateApp will terminate gracefully

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the AppManager plugin:

AppManager interface properties:

| Method | Description |
| :-------- | :-------- |
| [GetMaxHibernatedApps](#property.GetMaxHibernatedApps)<sup>RO</sup> | Get the maximum number of apps to maintain in the hibernated state |
| [GetMaxHibernatedFlashUsage](#property.GetMaxHibernatedFlashUsage)<sup>RO</sup> | Gets the max size of flash to use for hibernated apps (in mebibytes) |
| [GetMaxInactiveRamUsage](#property.GetMaxInactiveRamUsage)<sup>RO</sup> | Gets the max amount of ram available for inactive apps (in mebibytes) |
| [GetMaxRunningApps](#property.GetMaxRunningApps)<sup>RO</sup> | Gets the maximum number of apps to maintain in the running or suspended state |

<a id="property.GetMaxHibernatedApps"></a>
## *GetMaxHibernatedApps [<sup>property</sup>](#head.Properties)*

Get the maximum number of apps to maintain in the hibernated state

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxHibernatedApps | int32_t | max number of apps to maintain in the hibernated state |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.AppManager.getMaxHibernatedApps"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": 0
}
```

<a id="property.GetMaxHibernatedFlashUsage"></a>
## *GetMaxHibernatedFlashUsage [<sup>property</sup>](#head.Properties)*

Gets the max size of flash to use for hibernated apps (in mebibytes)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxHibernatedFlashUsage | int32_t | max size of flash to use for hibernated apps (in mebibytes) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.AppManager.getMaxHibernatedFlashUsage"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": 0
}
```

<a id="property.GetMaxInactiveRamUsage"></a>
## *GetMaxInactiveRamUsage [<sup>property</sup>](#head.Properties)*

Gets the max amount of ram available for inactive apps (in mebibytes)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxInactiveRamUsage | int32_t | max ram available for inactive apps (in mebibytes) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.AppManager.getMaxInactiveRamUsage"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": 0
}
```

<a id="property.GetMaxRunningApps"></a>
## *GetMaxRunningApps [<sup>property</sup>](#head.Properties)*

Gets the maximum number of apps to maintain in the running or suspended state

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).maxRunningApps | int32_t | max number of apps to maintain in the running or suspended state |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.AppManager.getMaxRunningApps"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": 0
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the AppManager plugin:

AppManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppInstalled](#event.onAppInstalled) | Triggered whenever the App is installed. |
| [onAppLaunchRequest](#event.onAppLaunchRequest) | Triggered whenever there is a request for App Launch. |
| [onAppLifecycleStateChanged](#event.onAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app. |
| [onAppUninstalled](#event.onAppUninstalled) | Triggered whenever the App is uninstalled. |
| [onAppUnloaded](#event.onAppUnloaded) | Triggered whenever the App is unloaded(terminated). |

<a id="event.onAppInstalled"></a>
## *onAppInstalled [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onAppLaunchRequest"></a>
## *onAppLaunchRequest [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onAppLifecycleStateChanged"></a>
## *onAppLifecycleStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered whenever there is a change in the lifecycle state of a running app.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |
| params.newState | AppLifecycleState | The new state to transition the application. |
| params.oldState | AppLifecycleState | The previous state of the application instance before the update. |
| params.errorReason | AppErrorReason | The reason for any error encountered during the state transition |

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

<a id="event.onAppUninstalled"></a>
## *onAppUninstalled [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onAppUnloaded"></a>
## *onAppUnloaded [<sup>event</sup>](#head.Notifications)*

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
