<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_XCast_API"></a>
# XCast API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

XCast interface for Thunder framework.

(Defined with IXCast in [IXCast.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IXCast.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the XCast interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

XCast JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the XCast interface:

XCast interface methods:

| Method | Description |
| :-------- | :-------- |
| [setApplicationState](#method_setApplicationState) | Triggered when the cast service receives an application state change notification from a client |
| [getProtocolVersion](#method_getProtocolVersion) | Returns the DIAL protocol version supported by the server |
| [setManufacturerName](#method_setManufacturerName) | Sets the manufacturer name of the device |
| [getManufacturerName](#method_getManufacturerName) | Returns the manufacturer name set by setManufacturerName API |
| [setModelName](#method_setModelName) | Sets the model name of the device |
| [getModelName](#method_getModelName) | Returns the model name set by setModelName API |
| [setEnabled](#method_setEnabled) | Enable or disable XCAST service |
| [getEnabled](#method_getEnabled) | Reports whether xcast plugin is enabled or disabled |
| [setStandbyBehavior](#method_setStandbyBehavior) | Sets the expected xcast behavior in standby mode |
| [getStandbyBehavior](#method_getStandbyBehavior) | Return current standby behavior option string set uisng setStandbyBehavior or default value |
| [setFriendlyName](#method_setFriendlyName) | Sets the friendly name of the device |
| [getFriendlyName](#method_getFriendlyName) | Returns the friendly name set by setFriendlyName API |
| [registerApplications](#method_registerApplications) | Registers an application |
| [unregisterApplications](#method_unregisterApplications) | Unregisters an application |

<a id="method_setApplicationState"></a>
## *setApplicationState [<sup>method</sup>](#head_Methods)*

Triggered when the cast service receives an application state change notification from a client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory | Registered application name |
| params.state | string | mandatory | Application state (must be one of the following: *running, stopped, suspended*) |
| params.applicationId | string | mandatory | Application instance ID |
| params.error | string | mandatory | Error string, if any (must be one of the following: *forbidden, internal, invalid, none, unavailable*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setApplicationState",
  "params": {
    "applicationName": "...",
    "state": "stopped",
    "applicationId": "...",
    "error": "forbidden"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getProtocolVersion"></a>
## *getProtocolVersion [<sup>method</sup>](#head_Methods)*

Returns the DIAL protocol version supported by the server.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.version | string | mandatory |  |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getProtocolVersion"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "version": "...",
    "success": false
  }
}
```

<a id="method_setManufacturerName"></a>
## *setManufacturerName [<sup>method</sup>](#head_Methods)*

Sets the manufacturer name of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.manufacturer | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setManufacturerName",
  "params": {
    "manufacturer": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getManufacturerName"></a>
## *getManufacturerName [<sup>method</sup>](#head_Methods)*

Returns the manufacturer name set by setManufacturerName API.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.manufacturer | string | mandatory |  |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getManufacturerName"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "manufacturer": "...",
    "success": false
  }
}
```

<a id="method_setModelName"></a>
## *setModelName [<sup>method</sup>](#head_Methods)*

Sets the model name of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.model | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setModelName",
  "params": {
    "model": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getModelName"></a>
## *getModelName [<sup>method</sup>](#head_Methods)*

Returns the model name set by setModelName API.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.model | string | mandatory |  |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getModelName"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "model": "...",
    "success": false
  }
}
```

<a id="method_setEnabled"></a>
## *setEnabled [<sup>method</sup>](#head_Methods)*

Enable or disable XCAST service.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEnabled",
  "params": {
    "enabled": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getEnabled"></a>
## *getEnabled [<sup>method</sup>](#head_Methods)*

Reports whether xcast plugin is enabled or disabled.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.enabled | boolean | mandatory | True for enabled or false for disabled |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getEnabled"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "enabled": false,
    "success": false
  }
}
```

<a id="method_setStandbyBehavior"></a>
## *setStandbyBehavior [<sup>method</sup>](#head_Methods)*

Sets the expected xcast behavior in standby mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.standbybehavior | string | mandatory | Whether to remain active or inactive during standby mode (must be one of the following: active, inactive) (must be one of the following: *active, inactive*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setStandbyBehavior",
  "params": {
    "standbybehavior": "inactive"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getStandbyBehavior"></a>
## *getStandbyBehavior [<sup>method</sup>](#head_Methods)*

Return current standby behavior option string set uisng setStandbyBehavior or default value.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.standbybehavior | string | mandatory | Whether to remain active or inactive during standby mode (must be one of the following: active, inactive) (must be one of the following: *active, inactive*) |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getStandbyBehavior"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "standbybehavior": "inactive",
    "success": false
  }
}
```

<a id="method_setFriendlyName"></a>
## *setFriendlyName [<sup>method</sup>](#head_Methods)*

Sets the friendly name of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.friendlyname | string | mandatory | The friendly name of the device which used to display on the client device list |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setFriendlyName",
  "params": {
    "friendlyname": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getFriendlyName"></a>
## *getFriendlyName [<sup>method</sup>](#head_Methods)*

Returns the friendly name set by setFriendlyName API.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.friendlyname | string | mandatory | The friendly name of the device which used to display on the client device list |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFriendlyName"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "friendlyname": "...",
    "success": false
  }
}
```

<a id="method_registerApplications"></a>
## *registerApplications [<sup>method</sup>](#head_Methods)*

Registers an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applications | array | mandatory |  |
| params.applications[#] | object | mandatory |  |
| params.applications[#].name | string | mandatory | Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail |
| params.applications[#].prefix | string | mandatory | If the application name in request URI does not match the appname given here, it must contain some prefix.If the application name in request URI does not match the appnames or prefix, then the request shall fail |
| params.applications[#].cors | string | mandatory | Origin allowed for the application. This must not be empty |
| params.applications[#].query | string | mandatory | Query string that need to be appended in launch request |
| params.applications[#].payload | string | mandatory | Optional payload string that need to be appended in launch request |
| params.applications[#].allowStop | integer | mandatory | Is the application (matching name list or prefix list) allowed to stop (no PID presence) after launched |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.registerApplications",
  "params": {
    "applications": [
      {
        "name": "...",
        "prefix": "...",
        "cors": "...",
        "query": "...",
        "payload": "...",
        "allowStop": 0
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
    "success": false
  }
}
```

<a id="method_unregisterApplications"></a>
## *unregisterApplications [<sup>method</sup>](#head_Methods)*

Unregisters an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applications | array | mandatory | One or more application name to unregister |
| params.applications[#] | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | True if the request was successful, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unregisterApplications",
  "params": {
    "applications": [
      "..."
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
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the XCast interface:

XCast interface events:

| Notification | Description |
| :-------- | :-------- |
| [onApplicationLaunchRequest](#notification_onApplicationLaunchRequest) | Triggered when the cast service receives a launch request from a client with launch params |
| [onApplicationLaunchRequest#](#notification_onApplicationLaunchRequest#) | Triggered when the cast service receives a launch request from a client with launch params |
| [onApplicationStopRequest](#notification_onApplicationStopRequest) | Triggered when the cast service receives a stop request from a client |
| [onApplicationHideRequest](#notification_onApplicationHideRequest) | Triggered when the cast service receives a hide request from a client |
| [onApplicationStateRequest](#notification_onApplicationStateRequest) | Triggered when the cast service needs an update of the application state |
| [onApplicationResumeRequest](#notification_onApplicationResumeRequest) | Triggered when the cast service receives a resume request from a client |

<a id="notification_onApplicationLaunchRequest"></a>
## *onApplicationLaunchRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service receives a launch request from a client with launch params.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.strPayLoad | string | mandatory | Payload string to be passed to the application |
| params.strQuery | string | mandatory | Query string to be appended in launch request |
| params.strAddDataUrl | string | mandatory | Additional data URL to be passed to the application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationLaunchRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationLaunchRequest",
  "params": {
    "applicationName": "...",
    "strPayLoad": "...",
    "strQuery": "...",
    "strAddDataUrl": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationLaunchRequest``.

<a id="notification_onApplicationLaunchRequest#"></a>
## *onApplicationLaunchRequest# [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service receives a launch request from a client with launch params.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.parameter | string | mandatory | Application launch string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationLaunchRequest#",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationLaunchRequest#",
  "params": {
    "applicationName": "...",
    "parameter": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationLaunchRequest#``.

<a id="notification_onApplicationStopRequest"></a>
## *onApplicationStopRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service receives a stop request from a client.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.applicationId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationStopRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationStopRequest",
  "params": {
    "applicationName": "...",
    "applicationId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationStopRequest``.

<a id="notification_onApplicationHideRequest"></a>
## *onApplicationHideRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service receives a hide request from a client.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.applicationId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationHideRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationHideRequest",
  "params": {
    "applicationName": "...",
    "applicationId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationHideRequest``.

<a id="notification_onApplicationStateRequest"></a>
## *onApplicationStateRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service needs an update of the application state.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.applicationId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationStateRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationStateRequest",
  "params": {
    "applicationName": "...",
    "applicationId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationStateRequest``.

<a id="notification_onApplicationResumeRequest"></a>
## *onApplicationResumeRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the cast service receives a resume request from a client.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.applicationName | string | mandatory |  |
| params.applicationId | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onApplicationResumeRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onApplicationResumeRequest",
  "params": {
    "applicationName": "...",
    "applicationId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onApplicationResumeRequest``.

