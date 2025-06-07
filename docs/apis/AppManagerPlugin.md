<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IAppManager_Plugin"></a>
# IAppManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IAppManager/CHANGELOG.md)**

A IAppManager plugin for Thunder framework.

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

The `IAppManager` plugin provides an interface for IAppManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IAppManager*) |
| classname | string | Class name: *IAppManager* |
| locator | string | Library name: *libWPEFrameworkIAppManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IAppManager plugin:

IAppManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [ClearAllAppData](#method.ClearAllAppData) | Clears all persistent data for all apps. |
| [ClearAppData](#method.ClearAppData) | Clears all persistent data for a given appId. |
| [CloseApp](#method.CloseApp) | closeApp moves the state from Active to Running state |
| [GetAppMetadata](#method.GetAppMetadata) | Retrieves meta data about an installed app |
| [GetAppProperty](#method.GetAppProperty) | Gets a property for a given app. |
| [GetInstalledApps](#method.GetInstalledApps) | Function fetches the details of all applications currently installed |
| [GetLoadedApps](#method.GetLoadedApps) | Retrieves a list of applications currently loaded on the system. |
| [IsInstalled](#method.IsInstalled) | check whether the Application is installed or not |
| [KillApp](#method.KillApp) | killApp will terminate forcefully |
| [LaunchApp](#method.LaunchApp) | Launch an Application and app will be in ACTIVE state. |
| [PreloadApp](#method.PreloadApp) | Preloads an Application and app will be in the RUNNING state (hidden). |
| [SendIntent](#method.SendIntent) | Sends an intent to a loaded app. |
| [SetAppProperty](#method.SetAppProperty) | Sets a property for a given app |
| [StartSystemApp](#method.StartSystemApp) | Start the System Application |
| [StopSystemApp](#method.StopSystemApp) | Stop the System Application |
| [TerminateApp](#method.TerminateApp) | TerminateApp will terminate gracefully |

<a id="method.ClearAllAppData"></a>
## *ClearAllAppData [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.ClearAllAppData"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.ClearAppData"></a>
## *ClearAppData [<sup>method</sup>](#head.Methods)*

Clears all persistent data for a given appId.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.ClearAppData",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.CloseApp"></a>
## *CloseApp [<sup>method</sup>](#head.Methods)*

closeApp moves the state from Active to Running state

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.CloseApp",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetAppMetadata"></a>
## *GetAppMetadata [<sup>method</sup>](#head.Methods)*

Retrieves meta data about an installed app

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetAppMetadata",
    "params": {
        "appId": "",
        "metaData": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "result": ""
    }
}
```
<a id="method.GetAppProperty"></a>
## *GetAppProperty [<sup>method</sup>](#head.Methods)*

Gets a property for a given app.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetAppProperty",
    "params": {
        "appId": "",
        "key": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "value": ""
    }
}
```
<a id="method.GetInstalledApps"></a>
## *GetInstalledApps [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetInstalledApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "apps": ""
    }
}
```
<a id="method.GetLoadedApps"></a>
## *GetLoadedApps [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetLoadedApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "apps": ""
    }
}
```
<a id="method.IsInstalled"></a>
## *IsInstalled [<sup>method</sup>](#head.Methods)*

check whether the Application is installed or not

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.installed | bool | if it is installed then return true otherwise false |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.IsInstalled",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "installed": "true"
    }
}
```
<a id="method.KillApp"></a>
## *KillApp [<sup>method</sup>](#head.Methods)*

killApp will terminate forcefully

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.KillApp",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.LaunchApp"></a>
## *LaunchApp [<sup>method</sup>](#head.Methods)*

Launch an Application and app will be in ACTIVE state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
| params.launchArgs | string | (optional) Additional parameters passed to the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.LaunchApp",
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
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.PreloadApp"></a>
## *PreloadApp [<sup>method</sup>](#head.Methods)*

Preloads an Application and app will be in the RUNNING state (hidden).

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.launchArgs | string | (optional) Additional parameters passed to the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.error | string | if success = false it holds the appropriate error reason. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.PreloadApp",
    "params": {
        "appId": "",
        "launchArgs": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "error": ""
    }
}
```
<a id="method.SendIntent"></a>
## *SendIntent [<sup>method</sup>](#head.Methods)*

Sends an intent to a loaded app.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.SendIntent",
    "params": {
        "appId": "",
        "intent": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetAppProperty"></a>
## *SetAppProperty [<sup>method</sup>](#head.Methods)*

Sets a property for a given app

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.key | string | the name of the property to get |
| params.value | string | the value of the key |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.SetAppProperty",
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
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.StartSystemApp"></a>
## *StartSystemApp [<sup>method</sup>](#head.Methods)*

Start the System Application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.StartSystemApp",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.StopSystemApp"></a>
## *StopSystemApp [<sup>method</sup>](#head.Methods)*

Stop the System Application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.StopSystemApp",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.TerminateApp"></a>
## *TerminateApp [<sup>method</sup>](#head.Methods)*

TerminateApp will terminate gracefully

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.TerminateApp",
    "params": {
        "appId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="head.Properties"></a>
# Properties
The following properties are provided by the IAppManager plugin:

IAppManager interface properties:

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetMaxHibernatedApps"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "maxHibernatedApps": "0"
    }
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetMaxHibernatedFlashUsage"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "maxHibernatedFlashUsage": "0"
    }
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetMaxInactiveRamUsage"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "maxInactiveRamUsage": "0"
    }
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.GetMaxRunningApps"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "maxRunningApps": "0"
    }
}
```

<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IAppManager plugin:

IAppManager interface events:

| Method | Description |
| :-------- | :-------- |
| [OnAppInstalled](#event.OnAppInstalled) | Triggered whenever the App is installed. |
| [OnAppLaunchRequest](#event.OnAppLaunchRequest) | Triggered whenever there is a request for App Launch. |
| [OnAppLifecycleStateChanged](#event.OnAppLifecycleStateChanged) | Triggered whenever there is a change in the lifecycle state of a running app. |
| [OnAppUninstalled](#event.OnAppUninstalled) | Triggered whenever the App is uninstalled. |
| [OnAppUnloaded](#event.OnAppUnloaded) | Triggered whenever the App is unloaded(terminated). |

<a id="event.OnAppInstalled"></a>
## *OnAppInstalled [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is installed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.version | string | The version number of the application in string format |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.OnAppInstalled",
    "params": {
        "appId": "",
        "version": ""
    }
}
```
<a id="event.OnAppLaunchRequest"></a>
## *OnAppLaunchRequest [<sup>event</sup>](#head.Notifications)*

Triggered whenever there is a request for App Launch.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.intent | string | A reference to the intent string that specifies the action or request to be processed. |
| params.source | string | A string indicating the source of the intent |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.OnAppLaunchRequest",
    "params": {
        "appId": "",
        "intent": "",
        "source": ""
    }
}
```
<a id="event.OnAppLifecycleStateChanged"></a>
## *OnAppLifecycleStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered whenever there is a change in the lifecycle state of a running app.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |
| params.newState | AppLifecycleState | The new state to transition the application. |
| params.oldState | AppLifecycleState | The previous state of the application instance before the update. |
| params.errorReason | AppErrorReason | The reason for any error encountered during the state transition |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.OnAppLifecycleStateChanged",
    "params": {
        "appId": "",
        "appInstanceId": "",
        "newState": "APP_STATE_UNKNOWN",
        "oldState": "APP_STATE_UNKNOWN",
        "errorReason": "APP_ERROR_UNKNOWN"
    }
}
```
<a id="event.OnAppUninstalled"></a>
## *OnAppUninstalled [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is uninstalled.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.OnAppUninstalled",
    "params": {
        "appId": ""
    }
}
```
<a id="event.OnAppUnloaded"></a>
## *OnAppUnloaded [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is unloaded(terminated).

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appId | string | App identifier for the application. |
| params.appInstanceId | string | A numerical identifier for a specific instance of the application. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppManager.OnAppUnloaded",
    "params": {
        "appId": "",
        "appInstanceId": ""
    }
}
```