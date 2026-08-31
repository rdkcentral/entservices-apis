<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_UnifiedCASManagement_API"></a>
# UnifiedCASManagement API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

UnifiedCASManagement interface for Thunder framework.

(Defined with IUnifiedCASManagement in [IUnifiedCASManagement.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IUnifiedCASManagement.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the UnifiedCASManagement interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

UnifiedCASManagement JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the UnifiedCASManagement interface:

UnifiedCASManagement interface methods:

| Method | Description |
| :-------- | :-------- |
| [manage](#method_manage) | Manage a well-known CAS (setup CAS management session) |
| [unmanage](#method_unmanage) | Destroy a management session |
| [send](#method_send) | Sends data to the remote CAS |

<a id="method_manage"></a>
## *manage [<sup>method</sup>](#head_Methods)*

Manage a well-known CAS (setup CAS management session).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.mediaurl | string | mandatory | The URL to tune to (tune://, ocap://, http://, https://) |
| params.mode | string | mandatory | The use of the tune request (must be one of the following: *MODE_LIVE, MODE_NONE, MODE_PLAYBACK, MODE_RECORD*) |
| params.managementType | string | mandatory | Type of CAS management (must be one of the following: *MANAGE_FULL, MANAGE_NO_PSI, MANAGE_NO_TUNER*) |
| params.casinitdata | string | mandatory | CAS specific initdata for the selected media |
| params.casocdmid | string | mandatory | The well-known OCDM ID of the CAS to use |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Returns true if the operation succeeded, false otherwise |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Operation successful |
| ```Core::ERROR_GENERAL``` | Operation failed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.manage",
  "params": {
    "mediaurl": "...",
    "mode": "MODE_LIVE",
    "managementType": "MANAGE_NO_PSI",
    "casinitdata": "...",
    "casocdmid": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_unmanage"></a>
## *unmanage [<sup>method</sup>](#head_Methods)*

Destroy a management session.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Returns true if the operation succeeded, false otherwise |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Operation successful |
| ```Core::ERROR_GENERAL``` | Operation failed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.unmanage"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_send"></a>
## *send [<sup>method</sup>](#head_Methods)*

Sends data to the remote CAS.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.payload | string | mandatory | Data to transfer. Can be base64 coded if required |
| params.source | string | mandatory | Origin of the data (must be one of the following: *PRIVATE, PUBLIC*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Returns true if the operation succeeded, false otherwise |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Operation successful |
| ```Core::ERROR_GENERAL``` | Operation failed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.send",
  "params": {
    "payload": "...",
    "source": "PRIVATE"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the UnifiedCASManagement interface:

UnifiedCASManagement interface events:

| Notification | Description |
| :-------- | :-------- |
| [onDataReceived](#notification_onDataReceived) / [data](#notification_onDataReceived) | Sent when the CAS needs to send data to the caller |

<a id="notification_onDataReceived"></a>
## *onDataReceived [<sup>notification</sup>](#head_Notifications)*

Sent when the CAS needs to send data to the caller.

> ``data`` is an alternative name for this notification.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.payload | string | mandatory | Data to transfer. Can be base64 coded if required |
| params.source | string | mandatory | Origin of the data (must be one of the following: *PRIVATE, PUBLIC*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onDataReceived",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDataReceived",
  "params": {
    "payload": "...",
    "source": "PRIVATE"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDataReceived``.

