<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_SharedStorage_API"></a>
# SharedStorage API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

SharedStorage interface for Thunder framework.

(Defined with ISharedStorage in [ISharedStorage.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ISharedStorage.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the SharedStorage interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

SharedStorage JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the SharedStorage interface:

SharedStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [setValue](#method_setValue) | Sets the value of a key in the the specified namespace |
| [getValue](#method_getValue) | Returns the value of a key from the specified namespace |
| [deleteKey](#method_deleteKey) | Deletes a key from the specified namespace |
| [deleteNamespace](#method_deleteNamespace) | Deletes the specified namespace |

<a id="method_setValue"></a>
## *setValue [<sup>method</sup>](#head_Methods)*

Sets the value of a key in the the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |
| params.key | string | mandatory | Key |
| params.value | string | mandatory | Value |
| params.ttl | integer | mandatory | Time to live (optional) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Success |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setValue",
  "params": {
    "scope": "account",
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
  "result": {
    "success": false
  }
}
```

<a id="method_getValue"></a>
## *getValue [<sup>method</sup>](#head_Methods)*

Returns the value of a key from the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |
| params.key | string | mandatory | Key |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.value | string | mandatory | Value out |
| result.ttl | integer | mandatory | Time to live (optional) |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getValue",
  "params": {
    "scope": "account",
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
    "ttl": 0,
    "success": false
  }
}
```

<a id="method_deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head_Methods)*

Deletes a key from the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |
| params.key | string | mandatory | Key |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Success |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.deleteKey",
  "params": {
    "scope": "account",
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
    "success": false
  }
}
```

<a id="method_deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#head_Methods)*

Deletes the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Success |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.deleteNamespace",
  "params": {
    "scope": "account",
    "namespace": "..."
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

The following events are provided by the SharedStorage interface:

SharedStorage interface events:

| Notification | Description |
| :-------- | :-------- |
| [onValueChanged](#notification_onValueChanged) | Values stored are changed using setValue |

<a id="notification_onValueChanged"></a>
## *onValueChanged [<sup>notification</sup>](#head_Notifications)*

Values stored are changed using setValue.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory |  |
| params.key | string | mandatory | Key |
| params.value | string | mandatory | Value |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onValueChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onValueChanged",
  "params": {
    "scope": "account",
    "namespace": "...",
    "key": "...",
    "value": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onValueChanged``.

