<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_RuntimeManagerDelegate_API"></a>
# RuntimeManagerDelegate API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

RuntimeManagerDelegate interface for Thunder framework.

(Defined with IGoogleCast::IRuntimeManagerDelegate in [IGoogleCast.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IGoogleCast.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the RuntimeManagerDelegate interface (version 1.0.0). It includes detailed specification about its notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

RuntimeManagerDelegate JSON-RPC interface.

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the RuntimeManagerDelegate interface:

GoogleCast RuntimeManagerDelegate interface events:

| Notification | Description |
| :-------- | :-------- |
| [onIntentChanged](#notification_onIntentChanged) | Notifies about GoogleCast intent to launch/close/destroy cast application runtime |

<a id="notification_onIntentChanged"></a>
## *onIntentChanged [<sup>notification</sup>](#head_Notifications)*

Notifies about GoogleCast intent to launch/close/destroy cast application runtime.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.appId | string | mandatory | Durable application id |
| params.inactive | boolean | mandatory | Indicates pre-launch(off screen) request |
| params.intent | object | mandatory | A Firebolt compliant navigation intent |
| params.intent.action | string | mandatory | Specifies the intent action to launch, close or destroy the app runtime instance. (must be one of the following: *LAUNCH, close, destroy*) |
| params.intent.context | object | mandatory | Intent context |
| params.intent.context.source | string | mandatory | Source of the intent |
| params.intent.data | opaque object | mandatory | An array of launch arguments to forward to app runtime instance as is |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onIntentChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onIntentChanged",
  "params": {
    "appId": "...",
    "inactive": false,
    "intent": {
      "action": "close",
      "context": {
        "source": "..."
      },
      "data": {}
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onIntentChanged``.

