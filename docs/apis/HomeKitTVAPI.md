<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_HomeKitTV_API"></a>
# HomeKitTV API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

HomeKitTVJSONRPC interface for Thunder framework.

(Defined by [HomeKitTVJSONRPC.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

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

This document describes purpose and functionality of the HomeKitTVJSONRPC interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

HomeKitTV service JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the HomeKitTVJSONRPC interface:

HomeKitTVJSONRPC interface methods:

| Method | Description |
| :-------- | :-------- |
| [setCurrentInputSource](#method_setCurrentInputSource) | Request Airplay to set the current Input-Source |
| [getEnabledStatus](#method_getEnabledStatus) | Return the status of Airplay On/Off |
| [getConnectionStatus](#method_getConnectionStatus) | Request whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device |
| [requestAppLaunch](#method_requestAppLaunch) | Requests Airplay Daemon to launch specific page of Airplay App |

<a id="method_setCurrentInputSource"></a>
## *setCurrentInputSource [<sup>method</sup>](#head_Methods)*

Request Airplay to set the current Input-Source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sourceName | string | mandatory | Selected Input-Source using IR Remote |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNAVAILABLE``` | Airplay is unavailable |
| ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setCurrentInputSource",
  "params": {
    "sourceName": "HDMI1,AirPlay,ImmersiveUI"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": true
  }
}
```

<a id="method_getEnabledStatus"></a>
## *getEnabledStatus [<sup>method</sup>](#head_Methods)*

Return the status of Airplay On/Off.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.enabled | boolean | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getEnabledStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "enabled": true,
    "success": true
  }
}
```

<a id="method_getConnectionStatus"></a>
## *getConnectionStatus [<sup>method</sup>](#head_Methods)*

Request whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.paired | boolean | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getConnectionStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "paired": true,
    "success": true
  }
}
```

<a id="method_requestAppLaunch"></a>
## *requestAppLaunch [<sup>method</sup>](#head_Methods)*

Requests Airplay Daemon to launch specific page of Airplay App.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.origin | string | mandatory | Origin of the launch Request |
| params.reason | string | mandatory | Reason to request Airplay app UI, e.g., to display Airplay curtain page or Airlay & HomeKit settings |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNAVAILABLE``` | Airplay is unavailable |
| ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.requestAppLaunch",
  "params": {
    "origin": "EPG",
    "reason": "HomeScreenButton"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": true
  }
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the HomeKitTVJSONRPC interface:

HomeKitTVJSONRPC interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [setAppContainerIPAddress](#property_setAppContainerIPAddress) | read/write | Set the Airplay Application containers IP address to Daemon side |

StateControl interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [state](#property_state) | read/write | Running state of the service |

<a id="property_setAppContainerIPAddress"></a>
## *setAppContainerIPAddress [<sup>property</sup>](#head_Properties)*

Provides access to the set the Airplay Application containers IP address to Daemon side.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Set the Airplay Application containers IP address to Daemon side |
| (property).ipaddress | string | mandatory | IP Address of Application container |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Set the Airplay Application containers IP address to Daemon side |
| (property).ipaddress | string | mandatory | IP Address of Application container |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setAppContainerIPAddress"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "ipaddress": "127.0.0.1"
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setAppContainerIPAddress",
  "params": {
    "ipaddress": "127.0.0.1"
  }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_state"></a>
## *state [<sup>property</sup>](#head_Properties)*

Provides access to the running state of the service.

Also see: [statechange](#event_statechange)

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Running state of the service |
| (property).value | string | mandatory | *...* (must be one of the following: *resumed, suspended*) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Running state of the service (must be one of the following: *resumed, suspended*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "suspended"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state",
  "params": {
    "value": "suspended"
  }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HomeKitTVJSONRPC interface:

HomeKitTVJSONRPC interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppStateChangeRequest](#notification_onAppStateChangeRequest) | Event raised to request state change of the Airplay Application to starting-section, resuming-section, suspending-close, and stopping-destroy |
| [onEnabledStatusChanged](#notification_onEnabledStatusChanged) | Event raised to send Airplay status changed to On or Off |
| [onInputSourceChanged](#notification_onInputSourceChanged) | Event raised to send selected Inputsource details |
| [onairplayerror](#notification_onairplayerror) | Event raised to send failure events |
| [onConnectionStatusChanged](#notification_onConnectionStatusChanged) | Event raised to notify pairing status changed |

StateControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [statechange](#notification_statechange) | Signals a state change of the service |

<a id="notification_onAppStateChangeRequest"></a>
## *onAppStateChangeRequest [<sup>notification</sup>](#head_Notifications)*

Event raised to request state change of the Airplay Application to starting-section, resuming-section, suspending-close, and stopping-destroy.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.origin | string | mandatory | Origin of app state change request |
| params.intent | object | mandatory | App State change intent object |
| params.intent?.action | string | optional | Intent action |
| params.intent?.data | object | optional | Intent's data |
| params.intent?.data.sectionName | string | mandatory | String representing launch parameters |
| params.intent?.context | object | optional | App State Change Intent Context Object |
| params.intent?.context.source | string | mandatory | String representing the reason for triggering the section |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onAppStateChangeRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppStateChangeRequest",
  "params": {
    "origin": "EPG, Airplay",
    "intent": {
      "action": "section",
      "data": {
        "sectionName": "argv0:--cwd=/tmp"
      },
      "context": {
        "source": "HomeScreenButton, InputSourceSelected"
      }
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppStateChangeRequest``.

<a id="notification_onEnabledStatusChanged"></a>
## *onEnabledStatusChanged [<sup>notification</sup>](#head_Notifications)*

Event raised to send Airplay status changed to On or Off.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.enabled | boolean | mandatory | Airplay setting status changed between On or Off |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onEnabledStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onEnabledStatusChanged",
  "params": {
    "enabled": true
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onEnabledStatusChanged``.

<a id="notification_onInputSourceChanged"></a>
## *onInputSourceChanged [<sup>notification</sup>](#head_Notifications)*

Event raised to send selected Inputsource details.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sourceType | string | mandatory | Type of inputsource hdmi, composite, Airplay |
| params.portId | integer | mandatory | Port ID of Input source |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onInputSourceChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onInputSourceChanged",
  "params": {
    "sourceType": "HDMI, COMPOSITE, AIRPLAY",
    "portId": 1
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onInputSourceChanged``.

<a id="notification_onairplayerror"></a>
## *onairplayerror [<sup>notification</sup>](#head_Notifications)*

Event raised to send failure events.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.errordata | string | mandatory | Details of the failure |
| params.errorid | integer | mandatory | Failure code |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onairplayerror",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onairplayerror",
  "params": {
    "errordata": "Network lost",
    "errorid": 10
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onairplayerror``.

<a id="notification_onConnectionStatusChanged"></a>
## *onConnectionStatusChanged [<sup>notification</sup>](#head_Notifications)*

Event raised to notify pairing status changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.paired | boolean | mandatory | HomeKit Pairing status |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onConnectionStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
Failed to generate JSON example for onConnectionStatusChanged
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onConnectionStatusChanged``.

<a id="notification_statechange"></a>
## *statechange [<sup>notification</sup>](#head_Notifications)*

Signals a state change of the service.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.suspended | boolean | mandatory | Determines if the service has entered suspended state (true) or resumed state (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "statechange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.statechange",
  "params": {
    "suspended": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.statechange``.

