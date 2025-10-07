<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Store2_API"></a>
# Store2 API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Store2 interface for Thunder framework.

(Defined with IStore2 in [IStore2.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IStore2.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Store2 interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

Store2 JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Store2 interface:

Store2 interface methods:

| Method | Description |
| :-------- | :-------- |
| [setvalue](#method_setvalue) / [setValue](#method_setvalue) |  |
| [getvalue](#method_getvalue) / [getValue](#method_getvalue) |  |
| [deletekey](#method_deletekey) / [deleteKey](#method_deletekey) |  |
| [deletenamespace](#method_deletenamespace) / [deleteNamespace](#method_deletenamespace) |  |

<a id="method_setvalue"></a>
## *setvalue [<sup>method</sup>](#head_Methods)*

> ``setValue`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory |  (must be one of the following: *Account, Device*) |
| params.namespace | string | mandatory |  |
| params.key | string | mandatory |  |
| params.value | string | mandatory |  |
| params.ttl | integer | mandatory |  |

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
  "method": "<callsign>.1.setvalue",
  "params": {
    "scope": "Account",
    "namespace": "...",
    "key": "...",
    "value": "...",
    "ttl": 0
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

<a id="method_getvalue"></a>
## *getvalue [<sup>method</sup>](#head_Methods)*

> ``getValue`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory |  (must be one of the following: *Account, Device*) |
| params.namespace | string | mandatory |  |
| params.key | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.value | string | mandatory |  |
| result.ttl | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getvalue",
  "params": {
    "scope": "Account",
    "namespace": "...",
    "key": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "value": "...",
    "ttl": 0
  }
}
```

<a id="method_deletekey"></a>
## *deletekey [<sup>method</sup>](#head_Methods)*

> ``deleteKey`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory |  (must be one of the following: *Account, Device*) |
| params.namespace | string | mandatory |  |
| params.key | string | mandatory |  |

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
  "method": "<callsign>.1.deletekey",
  "params": {
    "scope": "Account",
    "namespace": "...",
    "key": "..."
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

<a id="method_deletenamespace"></a>
## *deletenamespace [<sup>method</sup>](#head_Methods)*

> ``deleteNamespace`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory |  (must be one of the following: *Account, Device*) |
| params.namespace | string | mandatory |  |

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
  "method": "<callsign>.1.deletenamespace",
  "params": {
    "scope": "Account",
    "namespace": "..."
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

The following events are provided by the Store2 interface:

Store2 interface events:

| Notification | Description |
| :-------- | :-------- |
| [valuechanged](#notification_valuechanged) / [onValueChanged](#notification_valuechanged) |  |

<a id="notification_valuechanged"></a>
## *valuechanged [<sup>notification</sup>](#head_Notifications)*

> ``onValueChanged`` is an alternative name for this notification.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory |  (must be one of the following: *Account, Device*) |
| params.namespace | string | mandatory |  |
| params.key | string | mandatory |  |
| params.value | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "valuechanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.valuechanged",
  "params": {
    "scope": "Account",
    "namespace": "...",
    "key": "...",
    "value": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.valuechanged``.

