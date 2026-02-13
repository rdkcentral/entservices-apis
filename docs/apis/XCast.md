<!-- Generated automatically, DO NOT EDIT! -->
<a id="XCast_Plugin"></a>
# XCast Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/XCast/IXCast.h)**

A XCast plugin for Thunder framework.

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

The `XCast` plugin provides an interface for XCast.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.XCast) |
| classname | string | Class name: *XCast* |
| locator | string | Library name: *libWPEFrameworkXCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the XCast plugin:

XCast interface methods:

| Method | Description |
| :-------- | :-------- |
| [getEnabled](#getEnabled) | Reports whether xcast plugin is enabled or disabled |
| [getFriendlyName](#getFriendlyName) | Returns the friendly name set by setFriendlyName API |
| [getManufacturerName](#getManufacturerName) | Returns the manufacturer name set by setManufacturerName API |
| [getModelName](#getModelName) | Returns the model name set by setModelName API |
| [getProtocolVersion](#getProtocolVersion) | Returns the DIAL protocol version supported by the server |
| [getStandbyBehavior](#getStandbyBehavior) | Return current standby behavior option string set uisng setStandbyBehavior or default value |
| [registerApplications](#registerApplications) | Registers an application |
| [setApplicationState](#setApplicationState) | Triggered when the cast service receives an application state change notification from a client |
| [setEnabled](#setEnabled) | Enable or disable XCAST service |
| [setFriendlyName](#setFriendlyName) | Sets the friendly name of the device |
| [setManufacturerName](#setManufacturerName) | Sets the manufacturer name of the device |
| [setModelName](#setModelName) | Sets the model name of the device |
| [setStandbyBehavior](#setStandbyBehavior) | Sets the expected xcast behavior in standby mode |
| [unregisterApplications](#unregisterApplications) | Unregisters an application |

<a id="getEnabled"></a>
## *getEnabled*

Reports whether xcast plugin is enabled or disabled

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | true for enabled or false for disabled |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.XCast.getEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.XCast.getEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "enabled": true,
        "success": true
    }
}
```

<a id="getFriendlyName"></a>
## *getFriendlyName*

Returns the friendly name set by setFriendlyName API

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.friendlyname | string | The friendly name of the device which used to display on the client device list |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.XCast.getFriendlyName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.XCast.getFriendlyName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "friendlyname": "",
        "success": true
    }
}
```

<a id="getManufacturerName"></a>
## *getManufacturerName*

Returns the manufacturer name set by setManufacturerName API

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.manufacturer | string | The Manufacturer name of the device which used to update in dd.xml |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.XCast.getManufacturerName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.XCast.getManufacturerName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "manufacturer": "",
        "success": true
    }
}
```

<a id="getModelName"></a>
## *getModelName*

Returns the model name set by setModelName API

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.model | string | The Model name of the device which used to update in dd.xml |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.XCast.getModelName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.XCast.getModelName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "model": "",
        "success": true
    }
}
```

<a id="getProtocolVersion"></a>
## *getProtocolVersion*

Returns the DIAL protocol version supported by the server

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | string | DIAL protocol version |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.XCast.getProtocolVersion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.XCast.getProtocolVersion"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "version": "",
        "success": true
    }
}
```

<a id="getStandbyBehavior"></a>
## *getStandbyBehavior*

Return current standby behavior option string set uisng setStandbyBehavior or default value

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.standbybehavior | string | whether to remain active or inactive during standby mode (must be one of the following: active, inactive) |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.XCast.getStandbyBehavior"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.XCast.getStandbyBehavior"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "standbybehavior": "ACTIVE",
        "success": true
    }
}
```

<a id="registerApplications"></a>
## *registerApplications*

Registers an application

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applications | IApplicationInfoIterator | Json array with one or more application details to register |
| params.applications[#].name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applications[#].prefix | string | If the application name in request URI does not match the appname given here, it must contain some prefix.If the application name in request URI does not match the appnames or prefix, then the request shall fail |
| params.applications[#].cors | string | origin allowed for the application. This must not be empty |
| params.applications[#].query | string | query string that need to be appended in launch request |
| params.applications[#].payload | string | optional payload string that need to be appended in launch request |
| params.applications[#].allowStop | int | is the application (matching name list or prefix list) allowed to stop (no PID presence) after launched |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.XCast.registerApplications",
    "params": [
        {
            "name": "",
            "prefix": "",
            "cors": "",
            "query": "",
            "payload": "",
            "allowStop": 0
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.XCast.registerApplications", "params": [{"name": "", "prefix": "", "cors": "", "query": "", "payload": "", "allowStop": 0}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "success": true
    }
}
```

<a id="setApplicationState"></a>
## *setApplicationState*

Triggered when the cast service receives an application state change notification from a client

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applicationName | string | Registered application name |
| params.state | string | Application state |
| params.applicationId | string | Application instance ID |
| params.error | string | Error string, if any |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.XCast.setApplicationState",
    "params": {
        "applicationName": "",
        "state": "RUNNING",
        "applicationId": "",
        "error": "NONE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.XCast.setApplicationState", "params": {"applicationName": "", "state": "RUNNING", "applicationId": "", "error": "NONE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "success": true
    }
}
```

<a id="setEnabled"></a>
## *setEnabled*

Enable or disable XCAST service

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | true for enabled or false for disabled |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.XCast.setEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.XCast.setEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "success": true
    }
}
```

<a id="setFriendlyName"></a>
## *setFriendlyName*

Sets the friendly name of the device

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyname | string | The friendly name of the device which used to display on the client device list |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.XCast.setFriendlyName",
    "params": {
        "friendlyname": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.XCast.setFriendlyName", "params": {"friendlyname": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "success": true
    }
}
```

<a id="setManufacturerName"></a>
## *setManufacturerName*

Sets the manufacturer name of the device

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.manufacturer | string | The Manufacturer name of the device which used to update in dd.xml |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.XCast.setManufacturerName",
    "params": {
        "manufacturer": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.XCast.setManufacturerName", "params": {"manufacturer": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "success": true
    }
}
```

<a id="setModelName"></a>
## *setModelName*

Sets the model name of the device

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.model | string | The Model name of the device which used to update in dd.xml |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.XCast.setModelName",
    "params": {
        "model": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.XCast.setModelName", "params": {"model": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "success": true
    }
}
```

<a id="setStandbyBehavior"></a>
## *setStandbyBehavior*

Sets the expected xcast behavior in standby mode

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.standbybehavior | string | whether to remain active or inactive during standby mode (must be one of the following: active, inactive) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.XCast.setStandbyBehavior",
    "params": {
        "standbybehavior": "ACTIVE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.XCast.setStandbyBehavior", "params": {"standbybehavior": "ACTIVE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "success": true
    }
}
```

<a id="unregisterApplications"></a>
## *unregisterApplications*

Unregisters an application

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applications | IStringIterator | One or more application name to unregister |
| params.applications[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | true if the request was successful, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.XCast.unregisterApplications",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.XCast.unregisterApplications", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the XCast plugin:

XCast interface events:

| Event | Description |
| :-------- | :-------- |
| [onApplicationHideRequest](#onApplicationHideRequest) | Triggered when the cast service receives a hide request from a client |
| [onApplicationLaunchRequest](#onApplicationLaunchRequest) | Triggered when the cast service receives a launch request from a client with launch params |
| [onApplicationLaunchRequest](#onApplicationLaunchRequest) | Triggered when the cast service receives a launch request from a client with launch params |
| [onApplicationResumeRequest](#onApplicationResumeRequest) | Triggered when the cast service receives a resume request from a client |
| [onApplicationStateRequest](#onApplicationStateRequest) | Triggered when the cast service needs an update of the application state |
| [onApplicationStopRequest](#onApplicationStopRequest) | Triggered when the cast service receives a stop request from a client |

<a id="onApplicationHideRequest"></a>
## *onApplicationHideRequest*

Triggered when the cast service receives a hide request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.XCast.onApplicationHideRequest",
    "params": {
        "applicationName": "",
        "applicationId": ""
    }
}
```

<a id="onApplicationLaunchRequest"></a>
## *onApplicationLaunchRequest*

Triggered when the cast service receives a launch request from a client with launch params

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.parameter | string | Application launch string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.XCast.onApplicationLaunchRequest",
    "params": {
        "applicationName": "",
        "parameter": ""
    }
}
```

<a id="onApplicationLaunchRequestWithParam"></a>
## *onApplicationLaunchRequestWithParam*

Triggered when the cast service receives a launch request from a client with launch params

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.strPayLoad | string | Payload string to be passed to the application |
| params.strQuery | string | Query string to be appended in launch request |
| params.strAddDataUrl | string | Additional data URL to be passed to the application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.XCast.onApplicationLaunchRequestWithParam",
    "params": {
        "applicationName": "",
        "strPayLoad": "",
        "strQuery": "",
        "strAddDataUrl": ""
    }
}
```

<a id="onApplicationResumeRequest"></a>
## *onApplicationResumeRequest*

Triggered when the cast service receives a resume request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.XCast.onApplicationResumeRequest",
    "params": {
        "applicationName": "",
        "applicationId": ""
    }
}
```

<a id="onApplicationStateRequest"></a>
## *onApplicationStateRequest*

Triggered when the cast service needs an update of the application state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.XCast.onApplicationStateRequest",
    "params": {
        "applicationName": "",
        "applicationId": ""
    }
}
```

<a id="onApplicationStopRequest"></a>
## *onApplicationStopRequest*

Triggered when the cast service receives a stop request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.XCast.onApplicationStopRequest",
    "params": {
        "applicationName": "",
        "applicationId": ""
    }
}
```
