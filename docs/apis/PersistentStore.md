<!-- Generated automatically, DO NOT EDIT! -->
<a id="PersistentStore_Module"></a>
# PersistentStore Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PersistentStore/IStoreCache.h)**

A PersistentStore module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IStore2](#IStore2)
    - [Methods](#IStore2-Methods)
    - [Notifications](#IStore2-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PersistentStore` module provides the following interface(s):

- IStore2

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PersistentStore) |
| classname | string | Class name: *PersistentStore* |
| locator | string | Library name: *libWPEFrameworkPersistentStore.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IStore2"></a>
## IStore2 Interface

<a id="IStore2-Methods"></a>
### Methods

The following methods are provided by the IStore2 Interface:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#deleteKey) | Deletes a key-value pair. |
| [deleteNamespace](#deleteNamespace) | Deletes an entire namespace. |
| [getValue](#getValue) | Retrieves a value from the persistent store. |
| [setValue](#setValue) | Stores a value in the persistent store. |

<a id="deleteKey"></a>
## *deleteKey*

Removes the specified key and its associated value from the given namespace and scope.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Storage scope. Possible values: DEVICE, ACCOUNT |
| params.namespace | string | Namespace containing the key. |
| params.key | string | Key to be removed. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PersistentStore.deleteKey",
    "params": {
        "scope": "- DEVICE",
        "namespace": "- \"application",
        "key": "- \"language"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PersistentStore.deleteKey", "params": {"scope": "- DEVICE", "namespace": "- \"application", "key": "- \"language"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "- Failed to delete the key."
    }
}
```

<a id="deleteNamespace"></a>
## *deleteNamespace*

Removes the specified namespace and all associated key-value pairs from the selected storage scope.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Storage scope. Possible values: DEVICE, ACCOUNT |
| params.namespace | string | Namespace to remove. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PersistentStore.deleteNamespace",
    "params": {
        "scope": "- DEVICE",
        "namespace": "- \"application"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PersistentStore.deleteNamespace", "params": {"scope": "- DEVICE", "namespace": "- \"application"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "- Failed to delete the namespace."
    }
}
```

<a id="getValue"></a>
## *getValue*

Returns the value associated with the specified key together with its remaining TTL information.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Storage scope (DEVICE or ACCOUNT). Possible values: DEVICE, ACCOUNT |
| params.namespace | string | Namespace containing the key. |
| params.key | string | Key identifier. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string | Retrieved value. |
| result.ttl | integer | Remaining TTL value in seconds. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PersistentStore.getValue",
    "params": {
        "scope": "- DEVICE",
        "namespace": "- \"application",
        "key": "- \"language"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PersistentStore.getValue", "params": {"scope": "- DEVICE", "namespace": "- \"application", "key": "- \"language"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "value": "- \"en-US",
        "ttl": "- 3580"
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
        "message": "- Failed to retrieve the value."
    }
}
```

<a id="setValue"></a>
## *setValue*

Creates or updates a key-value pair within the specified scope and namespace. A time-to-live (TTL) value may be supplied to control automatic expiration of the stored entry.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Storage scope (DEVICE or ACCOUNT). Possible values: DEVICE, ACCOUNT |
| params.namespace | string | Namespace used to group related entries. |
| params.key | string | Key identifier. |
| params.value | string | Value associated with the key. |
| params.ttl | integer | Time-to-live of the value in seconds. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PersistentStore.setValue",
    "params": {
        "scope": "- DEVICE",
        "namespace": "- \"application",
        "key": "- \"language",
        "value": "- \"en-US",
        "ttl": "- 3580"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PersistentStore.setValue", "params": {"scope": "- DEVICE", "namespace": "- \"application", "key": "- \"language", "value": "- \"en-US", "ttl": "- 3580"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "- Failed to store the value."
    }
}
```

<a id="IStore2-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IStore2 Interface:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#onValueChanged) |  |

<a id="onValueChanged"></a>
## *onValueChanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Storage scope (DEVICE or ACCOUNT). Possible values: DEVICE, ACCOUNT |
| params.namespace | string | Namespace used to group related entries. |
| params.key | string | Key identifier. |
| params.value | string | Value associated with the key. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PersistentStore.onValueChanged",
    "params": {
        "scope": "- DEVICE",
        "namespace": "- \"application",
        "key": "- \"language",
        "value": "- \"en-US"
    }
}
```

