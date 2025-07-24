<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IXCast_Plugin"></a>
# IXCast Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IXCast/CHANGELOG.md)**

A IXCast plugin for Thunder framework.

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

The `IXCast` plugin provides an interface for IXCast.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IXCast*) |
| classname | string | Class name: *IXCast* |
| locator | string | Library name: *libWPEFrameworkIXCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IXCast plugin:

IXCast interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetEnabled](#method.GetEnabled) | Reports whether xcast plugin is enabled or disabled |
| [GetFriendlyName](#method.GetFriendlyName) | Returns the friendly name set by setFriendlyName API |
| [GetManufacturerName](#method.GetManufacturerName) | Returns the manufacturer name set by setManufacturerName API |
| [GetModelName](#method.GetModelName) | Returns the model name set by setModelName API |
| [GetProtocolVersion](#method.GetProtocolVersion) | Returns the DIAL protocol version supported by the server |
| [GetStandbyBehavior](#method.GetStandbyBehavior) | Return current standby behavior option string set uisng setStandbyBehavior or default value |
| [RegisterApplications](#method.RegisterApplications) | Registers an application |
| [SetApplicationState](#method.SetApplicationState) | Triggered when the cast service receives an application state change notification from a client |
| [SetEnabled](#method.SetEnabled) | Enable or disable XCAST service @parm enabled: true for enabled or false for disabled |
| [SetFriendlyName](#method.SetFriendlyName) | Sets the friendly name of the device |
| [SetManufacturerName](#method.SetManufacturerName) | Sets the manufacturer name of the device |
| [SetModelName](#method.SetModelName) | Sets the model name of the device |
| [SetStandbyBehavior](#method.SetStandbyBehavior) | Sets the expected xcast behavior in standby mode |
| [UnregisterApplications](#method.UnregisterApplications) | Unregisters an application |

<a id="method.GetEnabled"></a>
## *GetEnabled [<sup>method</sup>](#head.Methods)*

Reports whether xcast plugin is enabled or disabled

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.enabled | bool | true for enabled or false for disabled |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetEnabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true",
        "success": "true"
    }
}
```
<a id="method.GetFriendlyName"></a>
## *GetFriendlyName [<sup>method</sup>](#head.Methods)*

Returns the friendly name set by setFriendlyName API

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.friendlyname | string | The friendly name of the device which used to display on the client device list |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetFriendlyName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "friendlyname": "",
        "success": "true"
    }
}
```
<a id="method.GetManufacturerName"></a>
## *GetManufacturerName [<sup>method</sup>](#head.Methods)*

Returns the manufacturer name set by setManufacturerName API

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.manufacturername | string |  |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetManufacturerName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "manufacturername": "",
        "success": "true"
    }
}
```
<a id="method.GetModelName"></a>
## *GetModelName [<sup>method</sup>](#head.Methods)*

Returns the model name set by setModelName API

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.modelname | string |  |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetModelName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "modelname": "",
        "success": "true"
    }
}
```
<a id="method.GetProtocolVersion"></a>
## *GetProtocolVersion [<sup>method</sup>](#head.Methods)*

Returns the DIAL protocol version supported by the server

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.protocolVersion | string |  |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetProtocolVersion"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "protocolVersion": "",
        "success": "true"
    }
}
```
<a id="method.GetStandbyBehavior"></a>
## *GetStandbyBehavior [<sup>method</sup>](#head.Methods)*

Return current standby behavior option string set uisng setStandbyBehavior or default value

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.standbybehavior | StandbyBehavior | whether to remain active or inactive during standby mode (must be one of the following: active, inactive) |
| result.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.GetStandbyBehavior"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "standbybehavior": "ACTIVE",
        "success": "true"
    }
}
```
<a id="method.RegisterApplications"></a>
## *RegisterApplications [<sup>method</sup>](#head.Methods)*

Registers an application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appInfoList | IApplicationInfoIterator |  |
| params.appInfoList[#].appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.appInfoList[#].prefixes | string | prefix */ /* @brief  If the application name in request URI does not match the appname given here, it must contain some prefix.If the application name in request URI does not match the appnames or prefix, then the request shall fail |
| params.appInfoList[#].cors | string | cors */ /* @brief origin allowed for the application. This must not be empty |
| params.appInfoList[#].query | string | query */ /* @brief query string that need to be appended in launch request |
| params.appInfoList[#].payload | string | payload */ /* @brief optional payload string that need to be appended in launch request |
| params.appInfoList[#].allowStop | int | allowStop */ /* @brief 	is the application (matching name list or prefix list) allowed to stop (no PID presence) after launched |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.RegisterApplications",
    "params": {
        "appInfoList": [
            {
                "appName": "",
                "prefixes": "",
                "cors": "",
                "query": "",
                "payload": "",
                "allowStop": "0"
            }
        ]
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetApplicationState"></a>
## *SetApplicationState [<sup>method</sup>](#head.Methods)*

Triggered when the cast service receives an application state change notification from a client

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.applicationName | string | Registered application name |
| params.state | State | Application state |
| params.applicationId | string | Application instance ID |
| params.error | ErrorCode | Error string, if any |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetApplicationState",
    "params": {
        "applicationName": "",
        "state": "RUNNING",
        "applicationId": "",
        "error": "NONE"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetEnabled"></a>
## *SetEnabled [<sup>method</sup>](#head.Methods)*

Enable or disable XCAST service @parm enabled: true for enabled or false for disabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | true for enabled or false for disabled |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetEnabled",
    "params": {
        "enabled": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetFriendlyName"></a>
## *SetFriendlyName [<sup>method</sup>](#head.Methods)*

Sets the friendly name of the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.friendlyname | string | The friendly name of the device which used to display on the client device list |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetFriendlyName",
    "params": {
        "friendlyname": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetManufacturerName"></a>
## *SetManufacturerName [<sup>method</sup>](#head.Methods)*

Sets the manufacturer name of the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.manufacturername | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetManufacturerName",
    "params": {
        "manufacturername": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetModelName"></a>
## *SetModelName [<sup>method</sup>](#head.Methods)*

Sets the model name of the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.modelname | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetModelName",
    "params": {
        "modelname": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetStandbyBehavior"></a>
## *SetStandbyBehavior [<sup>method</sup>](#head.Methods)*

Sets the expected xcast behavior in standby mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.standbybehavior | StandbyBehavior | whether to remain active or inactive during standby mode (must be one of the following: active, inactive) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.SetStandbyBehavior",
    "params": {
        "standbybehavior": "ACTIVE"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.UnregisterApplications"></a>
## *UnregisterApplications [<sup>method</sup>](#head.Methods)*

Unregisters an application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.applications | IStringIterator | One or more application name to unregister |
| params.applications[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | XCastSuccess | Whether the request succeeded |
| result.success.success | bool | success */ /* @brief  true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.UnregisterApplications",
    "params": {
        "applications": [
            ""
        ]
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IXCast plugin:

IXCast interface events:

| Method | Description |
| :-------- | :-------- |
| [OnApplicationHideRequest](#event.OnApplicationHideRequest) | Triggered when the cast service receives a hide request from a client |
| [OnApplicationLaunchRequest](#event.OnApplicationLaunchRequest) | Triggered when the cast service receives a launch request from a client with launch params |
| [OnApplicationLaunchRequestWithParam](#event.OnApplicationLaunchRequestWithParam) | Triggered when the cast service receives a launch request from a client with launch params |
| [OnApplicationResumeRequest](#event.OnApplicationResumeRequest) | Triggered when the cast service receives a resume request from a client |
| [OnApplicationStateRequest](#event.OnApplicationStateRequest) | Triggered when the cast service needs an update of the application state |
| [OnApplicationStopRequest](#event.OnApplicationStopRequest) | Triggered when the cast service receives a stop request from a client |

<a id="event.OnApplicationHideRequest"></a>
## *OnApplicationHideRequest [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service receives a hide request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.appID | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationHideRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```
<a id="event.OnApplicationLaunchRequest"></a>
## *OnApplicationLaunchRequest [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service receives a launch request from a client with launch params

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.parameter | string | Application launch string |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationLaunchRequest",
    "params": {
        "appName": "",
        "parameter": ""
    }
}
```
<a id="event.OnApplicationLaunchRequestWithParam"></a>
## *OnApplicationLaunchRequestWithParam [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service receives a launch request from a client with launch params

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.strPayLoad | string | Payload string to be passed to the application |
| params.strQuery | string | Query string to be appended in launch request |
| params.strAddDataUrl | string | Additional data URL to be passed to the application |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationLaunchRequestWithParam",
    "params": {
        "appName": "",
        "strPayLoad": "",
        "strQuery": "",
        "strAddDataUrl": ""
    }
}
```
<a id="event.OnApplicationResumeRequest"></a>
## *OnApplicationResumeRequest [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service receives a resume request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.appID | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationResumeRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```
<a id="event.OnApplicationStateRequest"></a>
## *OnApplicationStateRequest [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service needs an update of the application state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.appID | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationStateRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```
<a id="event.OnApplicationStopRequest"></a>
## *OnApplicationStopRequest [<sup>event</sup>](#head.Notifications)*

Triggered when the cast service receives a stop request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string | name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.appID | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.OnApplicationStopRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```