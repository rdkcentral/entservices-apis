<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_AppActions_API"></a>
# AppActions API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

AppActions interface for Thunder framework.

(Defined with IAppActions in [IAppActions.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppActions.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the AppActions interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

AppActions JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the AppActions interface:

AppActions interface methods:

| Method | Description |
| :-------- | :-------- |
| [actionStart](#method_actionStart) | Starts an action for the given intent and handler app |

<a id="method_actionStart"></a>
## *actionStart [<sup>method</sup>](#head_Methods)*

Starts an action for the given intent and handler app.

### Description

Initiates an action from the initiator to the AppActions with the specified intent.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.initiator | string | mandatory | The ID of the app/ module initiating the action |
| params.intent | string | mandatory | The intent string describing the action |
| params.handlerAppId | string | mandatory | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Success |
| ```Core::ERROR_GENERAL``` | Failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.actionStart",
  "params": {
    "initiator": "...",
    "intent": "...",
    "handlerAppId": "..."
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

The following events are provided by the AppActions interface:

AppActions interface events:

| Notification | Description |
| :-------- | :-------- |
| [onActionStartRequest](#notification_onActionStartRequest) | Notifies when an action start event occurs |

<a id="notification_onActionStartRequest"></a>
## *onActionStartRequest [<sup>notification</sup>](#head_Notifications)*

Notifies when an action start event occurs.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.initiator | string | mandatory | The ID of the app/ module initiating the action |
| params.intent | string | mandatory | The intent string describing the action |
| params.handlerAppId | string | mandatory | *...* |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onActionStartRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onActionStartRequest",
  "params": {
    "initiator": "...",
    "intent": "...",
    "handlerAppId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onActionStartRequest``.

