<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Amazon_API"></a>
# Amazon API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Amazon interface for Thunder framework.

(Defined with IAmazon in [IAmazonPrime.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAmazonPrime.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Amazon interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

Amazon JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Amazon interface:

Amazon interface methods:

| Method | Description |
| :-------- | :-------- |
| [setDeepLink](#method_setDeepLink) | Set the deeplink command for amazon prime |
| [personalInfoRequest](#method_personalInfoRequest) | Request for personal access token to amazon prime app |
| [factoryResetRequest](#method_factoryResetRequest) | Factory reset amazon prime app data |
| [SetLaunchReason](#method_SetLaunchReason) | Set launch reason for amazon prime app |

<a id="method_setDeepLink"></a>
## *setDeepLink [<sup>method</sup>](#head_Methods)*

Set the deeplink command for amazon prime.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.command | string | mandatory | : app Deeplink command |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setDeepLink",
  "params": {
    "command": "..."
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

<a id="method_personalInfoRequest"></a>
## *personalInfoRequest [<sup>method</sup>](#head_Methods)*

Request for personal access token to amazon prime app.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.personalInfoRequest"
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

<a id="method_factoryResetRequest"></a>
## *factoryResetRequest [<sup>method</sup>](#head_Methods)*

Factory reset amazon prime app data.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.factoryResetRequest"
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

<a id="method_SetLaunchReason"></a>
## *SetLaunchReason [<sup>method</sup>](#head_Methods)*

Set launch reason for amazon prime app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.command | string | mandatory | : app launch reason |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.SetLaunchReason",
  "params": {
    "command": "..."
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Amazon interface:

Amazon interface events:

| Notification | Description |
| :-------- | :-------- |
| [StateChange](#notification_StateChange) | Triggered whenever the App state changes |

<a id="notification_StateChange"></a>
## *StateChange [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the App state changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.state | string | mandatory | Current state of amazon prime (must be one of the following: *PLAYING, STOPPED, SUSPENDING*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "StateChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.StateChange",
  "params": {
    "state": "STOPPED"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.StateChange``.

