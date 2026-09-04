<!-- Generated automatically, DO NOT EDIT! -->
<a id="PersistentStore_Module"></a>
# PersistentStore Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PersistentStore/IStore.h)**

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
| configuration | object |  |
| configuration.MaxStoreSize | num | 1MB (Maximum size of the store in bytes) |
| configuration.MaxValue | num | 3KB (Maximum size of a single value in bytes) |
| configuration.Limit | num | 10KB (Maximum size of a namespace in bytes) |

<a id="Interfaces"></a>
# Interfaces

<a id="IStore2"></a>
## IStore2 Interface

<a id="IStore2-Methods"></a>
### Methods

The following methods are provided by the IStore2 Interface:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#deleteKey) |  |
| [deleteNamespace](#deleteNamespace) |  |
| [getValue](#getValue) |  |
| [setValue](#setValue) |  |

<a id="deleteKey"></a>
## *deleteKey*



### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Possible values: DEVICE, ACCOUNT |
| params.namespace | string |  |
| params.key | string |  |
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
        "scope": "DEVICE",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PersistentStore.deleteKey", "params": {"scope": "DEVICE", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="deleteNamespace"></a>
## *deleteNamespace*



### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Possible values: DEVICE, ACCOUNT |
| params.namespace | string |  |
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
        "scope": "DEVICE",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PersistentStore.deleteNamespace", "params": {"scope": "DEVICE", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="getValue"></a>
## *getValue*



### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Possible values: DEVICE, ACCOUNT |
| params.namespace | string |  |
| params.key | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string |  |
| result.ttl | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PersistentStore.getValue",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PersistentStore.getValue", "params": {"scope": "DEVICE", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "value": "",
        "ttl": 0
    }
}
```

<a id="setValue"></a>
## *setValue*



### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | Possible values: DEVICE, ACCOUNT |
| params.namespace | string |  |
| params.key | string |  |
| params.value | string |  |
| params.ttl | integer |  |
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
        "scope": "DEVICE",
        "namespace": "",
        "key": "",
        "value": "",
        "ttl": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PersistentStore.setValue", "params": {"scope": "DEVICE", "namespace": "", "key": "", "value": "", "ttl": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
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
| params.scope | string | Possible values: DEVICE, ACCOUNT |
| params.namespace | string |  |
| params.key | string |  |
| params.value | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PersistentStore.onValueChanged",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": "",
        "value": ""
    }
}
```

