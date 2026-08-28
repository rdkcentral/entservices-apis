<!-- Generated automatically, DO NOT EDIT! -->
<a id="XCast_Module"></a>
# XCast Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/XCast/IXCast.h)**

A XCast module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IXCast](#IXCast)
    - [Methods](#IXCast-Methods)
    - [Notifications](#IXCast-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `XCast` module provides the following interface(s):

- IXCast

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.XCast) |
| classname | string | Class name: *XCast* |
| locator | string | Library name: *libWPEFrameworkXCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IXCast"></a>
## IXCast Interface

<a id="IXCast-Methods"></a>
### Methods

The following methods are provided by the IXCast Interface:

| Method | Description |
| :-------- | :-------- |
| [getEnabled](#getEnabled) | Check XCAST service operational status |
| [getFriendlyName](#getFriendlyName) | Fetch device display name |
| [getManufacturerName](#getManufacturerName) | Query current device manufacturer |
| [getModelName](#getModelName) | Retrieve configured device model |
| [getProtocolVersion](#getProtocolVersion) | Retrieve DIAL protocol version information |
| [getStandbyBehavior](#getStandbyBehavior) | Retrieve current standby mode configuration |
| [registerApplications](#registerApplications) | Register one or more castable applications |
| [setApplicationState](#setApplicationState) | Update application state with status notification |
| [setEnabled](#setEnabled) | Control XCAST service activation state |
| [setFriendlyName](#setFriendlyName) | Assign user-readable device name |
| [setManufacturerName](#setManufacturerName) | Configure device manufacturer identity |
| [setModelName](#setModelName) | Update device model identifier |
| [setStandbyBehavior](#setStandbyBehavior) | Configure XCAST service standby mode behavior |
| [unregisterApplications](#unregisterApplications) | Deregister applications from casting support |

<a id="getEnabled"></a>
## *getEnabled*

Queries the current operational state of the XCAST service. Returns whether the service is active and accepting client requests, or inactive and rejecting all requests.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | true for enabled or false for disabled |
| result.success | bool | Whether the request succeeded |

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve XCAST service enabled/disabled"
    }
}
```

<a id="getFriendlyName"></a>
## *getFriendlyName*

Obtains the friendly name currently assigned to the device. Returns the value previously configured via setFriendlyName, which is shown to users in casting client applications.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.friendlyname | string | The friendly name of the device which used to display on the client device list |
| result.success | bool | Whether the request succeeded |

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getManufacturerName"></a>
## *getManufacturerName*

Retrieves the manufacturer name currently stored in the device description (dd.xml) file. This reflects the last value set via setManufacturerName or the factory default if not yet configured.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.manufacturer | string | The Manufacturer name of the device which used to update in dd.xml |
| result.success | bool | Whether the request succeeded |

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
        "manufacturer": "MyCompany",
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve the manufacturer name."
    }
}
```

<a id="getModelName"></a>
## *getModelName*

Fetches the device model name from the device description (dd.xml) file. Returns the previously configured model identifier set via setModelName, or the factory default if unconfigured.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.model | string | The Model name of the device which used to update in dd.xml |
| result.success | bool | Whether the request succeeded |

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
        "model": "MyModel",
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve the model name."
    }
}
```

<a id="getProtocolVersion"></a>
## *getProtocolVersion*

Queries the DIAL protocol version that the server supports and implements. The version is returned as a semantic version string in major.minor format.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | string | DIAL protocol version |
| result.success | bool | Whether the request succeeded |

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
        "version": 1.7,
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve the protocol version."
    }
}
```

<a id="getStandbyBehavior"></a>
## *getStandbyBehavior*

Returns the standby behavior setting currently in effect. The value reflects either a previously configured setting via setStandbyBehavior or the system default. Indicates whether the service remains active or suspended during standby.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.standbybehavior | string | whether to remain active or inactive during standby mode (must be one of the following: active, inactive). Possible values: active, inactive |
| result.success | bool | Whether the request succeeded |

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
        "standbybehavior": "active",
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="registerApplications"></a>
## *registerApplications*

Registers applications that can be launched via casting. Each application entry specifies its name, launch prefixes, CORS policy, launch parameters, and whether it can be stopped by remote clients.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applications | array | Json array with one or more application details to register |
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
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.XCast.registerApplications",
    "params": [
        {
            "appName": "YouTube",
            "prefixes": "yt",
            "cors": "*",
            "query": "autoplay=true",
            "payload": "videoId=abcd1234",
            "allowStop": true
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.XCast.registerApplications", "params": [{"appName": "YouTube", "prefixes": "yt", "cors": "*", "query": "autoplay=true", "payload": "videoId=abcd1234", "allowStop": true}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setApplicationState"></a>
## *setApplicationState*

Communicates a state change for a running application instance back to the system. Includes the application identifier, new state, error code if applicable, and success status for the operation.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applicationName | string | Registered application name |
| params.state | string | Application state. Possible values: running, stopped, suspended |
| params.applicationId | string | Application instance ID |
| params.error | string | Error string, if any. Possible values: none, forbidden, unavailable, invalid, internal |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.XCast.setApplicationState",
    "params": {
        "applicationName": "YouTube",
        "state": "running",
        "applicationId": "abcd1234",
        "error": "Application not found"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.XCast.setApplicationState", "params": {"applicationName": "YouTube", "state": "running", "applicationId": "abcd1234", "error": "Application not found"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "error": {
        "code": 1,
        "message": "- Application state change notification processing failed."
    }
}
```

<a id="setEnabled"></a>
## *setEnabled*

Activates or deactivates the XCAST service. When disabled, all incoming client requests are rejected and the service remains dormant. Enable to activate service functionality.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | true for enabled or false for disabled |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

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
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "error": {
        "code": 1,
        "message": "- Failed to enable/disable XCAST service."
    }
}
```

<a id="setFriendlyName"></a>
## *setFriendlyName*

Sets a human-friendly name for the device that will be displayed in casting client interfaces and device discovery lists. This name enhances user experience by providing an identifiable label.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyname | string | The friendly name of the device which used to display on the client device list |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

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
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setManufacturerName"></a>
## *setManufacturerName*

Updates the manufacturer field in the device description (dd.xml) file with the provided manufacturer identifier. This value is exposed to casting clients for device identification purposes.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.manufacturer | string | The Manufacturer name of the device which used to update in dd.xml |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.XCast.setManufacturerName",
    "params": {
        "manufacturer": "MyCompany"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.XCast.setManufacturerName", "params": {"manufacturer": "MyCompany"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "error": {
        "code": 1,
        "message": "- Failed to set the manufacturer name."
    }
}
```

<a id="setModelName"></a>
## *setModelName*

Assigns a model name to the device and persists it in the device description (dd.xml) file. Casting clients use this identifier to recognize and manage device capabilities.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.model | string | The Model name of the device which used to update in dd.xml |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.XCast.setModelName",
    "params": {
        "model": "MyModel"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.XCast.setModelName", "params": {"model": "MyModel"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "error": {
        "code": 1,
        "message": "- Failed to set the model name."
    }
}
```

<a id="setStandbyBehavior"></a>
## *setStandbyBehavior*

Defines how the XCAST service should operate when the device enters standby mode. Active mode allows continued service operation for casting, while inactive mode suspends the service to conserve power.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.standbybehavior | string | whether to remain active or inactive during standby mode (must be one of the following: active, inactive). Possible values: active, inactive |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.XCast.setStandbyBehavior",
    "params": {
        "standbybehavior": "active"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.XCast.setStandbyBehavior", "params": {"standbybehavior": "active"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="unregisterApplications"></a>
## *unregisterApplications*

Removes one or more previously registered applications from the castable application list. The application names must match registered application names or their prefixes.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applications | array | One or more application name to unregister |
| params.applications[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.XCast.unregisterApplications",
    "params": [
        "YouTube",
        "yt"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.XCast.unregisterApplications", "params": ["YouTube", "yt"]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IXCast-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IXCast Interface:

| Event | Description |
| :-------- | :-------- |
| [onApplicationHideRequest](#onApplicationHideRequest) | Request to conceal active application |
| [onApplicationLaunchRequest](#onApplicationLaunchRequest) | Basic application launch directive received |
| [onApplicationLaunchRequestWithParam](#onApplicationLaunchRequestWithParam) | Incoming application launch request with extended parameters |
| [onApplicationResumeRequest](#onApplicationResumeRequest) | Request to restore backgrounded application |
| [onApplicationStateRequest](#onApplicationStateRequest) | Query for running application state update |
| [onApplicationStopRequest](#onApplicationStopRequest) | Application termination request from client |

<a id="onApplicationHideRequest"></a>
## *onApplicationHideRequest*

Notifies that a casting client has requested to hide or background a currently running application instance. The application continues execution but is not visible to the user.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.XCast.onApplicationHideRequest",
    "params": {
        "applicationName": "YouTube",
        "applicationId": "abcd1234"
    }
}
```

<a id="onApplicationLaunchRequest"></a>
## *onApplicationLaunchRequest*

Notifies that a casting client has requested application launch with combined launch parameters in a single string. This simpler variant contains app identification and launch arguments in unified format.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
| params.parameter | string | Application launch string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.XCast.onApplicationLaunchRequest",
    "params": {
        "applicationName": "YouTube",
        "parameter": "videoId=abcd1234&autoplay=true"
    }
}
```

<a id="onApplicationLaunchRequestWithParam"></a>
## *onApplicationLaunchRequestWithParam*

Signals an incoming launch directive from a casting client containing comprehensive launch data including payload, query parameters, and additional data URL. The receiver must parse and route this request to the appropriate application instance.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
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
        "applicationName": "YouTube",
        "strPayLoad": "videoId=abcd1234",
        "strQuery": "autoplay=true",
        "strAddDataUrl": "https://example.com/additionalData"
    }
}
```

<a id="onApplicationResumeRequest"></a>
## *onApplicationResumeRequest*

Signals that a casting client wants to resume a previously hidden or backgrounded application instance. The application should become visible and active again.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.XCast.onApplicationResumeRequest",
    "params": {
        "applicationName": "YouTube",
        "applicationId": "abcd1234"
    }
}
```

<a id="onApplicationStateRequest"></a>
## *onApplicationStateRequest*

Requests the current state of a running application instance. The service must retrieve and report the application's operational state in response to this query.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.XCast.onApplicationStateRequest",
    "params": {
        "applicationName": "YouTube",
        "applicationId": "abcd1234"
    }
}
```

<a id="onApplicationStopRequest"></a>
## *onApplicationStopRequest*

Indicates that a casting client has issued a request to stop a running application instance. The notification includes the application name and instance ID to identify which running application should be terminated.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | Registered application name |
| params.applicationId | string | Application instance ID |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.XCast.onApplicationStopRequest",
    "params": {
        "applicationName": "YouTube",
        "applicationId": "abcd1234"
    }
}
```

