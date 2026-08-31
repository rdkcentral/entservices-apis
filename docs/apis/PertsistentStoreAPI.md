<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PertsistentStore_API"></a>
# PertsistentStore API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PersistentStore interface for Thunder framework.

(Defined by [PersistentStore.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PersistentStore interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

Persistent Store JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PersistentStore interface:

PersistentStore interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#method_deleteKey) | Deletes a key from the specified namespace |
| [deleteNamespace](#method_deleteNamespace) | Deletes the specified namespace |
| [flushCache](#method_flushCache) | Flushes the device cache |
| [getKeys](#method_getKeys) | Returns the keys that are stored in the specified namespace |
| [getNamespaces](#method_getNamespaces) | Returns the namespaces |
| [getStorageSizes](#method_getStorageSizes) | Returns the size occupied by each namespace |
| [getValue](#method_getValue) | Returns the value of a key from the specified namespace |
| [setValue](#method_setValue) | Sets the value of a key in the the specified namespace |
| [setNamespaceStorageLimit](#method_setNamespaceStorageLimit) | Sets the storage limit for a given namespace |
| [getNamespaceStorageLimit](#method_getNamespaceStorageLimit) | Returns the storage limit for a given namespace |

<a id="method_deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head_Methods)*

Deletes a key from the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params.key | string | mandatory | Key |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.deleteKey",
  "params": {
    "namespace": "ns1",
    "key": "key1",
    "scope": "device"
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

<a id="method_deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#head_Methods)*

Deletes the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.deleteNamespace",
  "params": {
    "namespace": "ns1",
    "scope": "device"
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

<a id="method_flushCache"></a>
## *flushCache [<sup>method</sup>](#head_Methods)*

Flushes the device cache.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.flushCache"
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

<a id="method_getKeys"></a>
## *getKeys [<sup>method</sup>](#head_Methods)*

Returns the keys that are stored in the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.keys | array | mandatory | *...* |
| result.keys[#] | string | mandatory | Key |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getKeys",
  "params": {
    "namespace": "ns1",
    "scope": "device"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "keys": [
      "key1"
    ],
    "success": true
  }
}
```

<a id="method_getNamespaces"></a>
## *getNamespaces [<sup>method</sup>](#head_Methods)*

Returns the namespaces.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.namespaces | array | mandatory | *...* |
| result.namespaces[#] | string | mandatory | Namespace |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getNamespaces",
  "params": {
    "scope": "device"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "namespaces": [
      "ns1"
    ],
    "success": true
  }
}
```

<a id="method_getStorageSizes"></a>
## *getStorageSizes [<sup>method</sup>](#head_Methods)*

Returns the size occupied by each namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.storageList | array | mandatory | *...* |
| result.storageList[#] | object | mandatory | *...* |
| result.storageList[#].namespace | string | mandatory | Namespace |
| result.storageList[#].size | integer | mandatory | Size in bytes |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getStorageSizes",
  "params": {
    "scope": "device"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "storageList": [
      {
        "namespace": "ns1",
        "size": 100
      }
    ]
  }
}
```

<a id="method_getValue"></a>
## *getValue [<sup>method</sup>](#head_Methods)*

Returns the value of a key from the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params.key | string | mandatory | Key |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.value | string | mandatory | Value |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |
| result?.ttl | integer | optional | Time in seconds |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_PENDING_CONDITIONS``` | Time is not synced |
| ```ERROR_NOT_EXIST``` | Unknown namespace |
| ```ERROR_UNKNOWN_KEY``` | Unknown key |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getValue",
  "params": {
    "namespace": "ns1",
    "key": "key1",
    "scope": "device"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "value": "value1",
    "success": true,
    "ttl": 100
  }
}
```

<a id="method_setValue"></a>
## *setValue [<sup>method</sup>](#head_Methods)*

Sets the value of a key in the the specified namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params.key | string | mandatory | Key |
| params.value | string | mandatory | Value |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |
| params?.ttl | integer | optional | Time in seconds |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Legacy parameter (always true) (default: *True*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_PENDING_CONDITIONS``` | Time is not synced |
| ```ERROR_INVALID_INPUT_LENGTH``` | Empty/too large namespace or key, or the storage doesn't have enough space |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setValue",
  "params": {
    "namespace": "ns1",
    "key": "key1",
    "value": "value1",
    "scope": "device",
    "ttl": 100
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

<a id="method_setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#head_Methods)*

Sets the storage limit for a given namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params.storageLimit | integer | mandatory | Size in bytes |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INVALID_INPUT_LENGTH``` | Empty/too large namespace, or the storage doesn't have enough space |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setNamespaceStorageLimit",
  "params": {
    "namespace": "ns1",
    "storageLimit": 100,
    "scope": "device"
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

<a id="method_getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#head_Methods)*

Returns the storage limit for a given namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params?.scope | string | optional | Scope (must be one of the following: *account, device*) (default: *device*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.storageLimit | integer | mandatory | Size in bytes |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_NOT_EXIST``` | Unknown namespace |
| ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getNamespaceStorageLimit",
  "params": {
    "namespace": "ns1",
    "scope": "device"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "storageLimit": 100
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PersistentStore interface:

PersistentStore interface events:

| Notification | Description |
| :-------- | :-------- |
| [onValueChanged](#notification_onValueChanged) | Triggered whenever any of the values stored are changed using setValue |

<a id="notification_onValueChanged"></a>
## *onValueChanged [<sup>notification</sup>](#head_Notifications)*

Triggered whenever any of the values stored are changed using setValue.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.namespace | string | mandatory | Namespace |
| params.key | string | mandatory | Key |
| params.value | string | mandatory | Value |
| params.scope | string | mandatory | Scope (must be one of the following: *account, device*) (default: *device*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "namespace": "ns1",
    "key": "key1",
    "value": "value1",
    "scope": "device"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onValueChanged``.

