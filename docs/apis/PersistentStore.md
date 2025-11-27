<!-- Generated automatically, DO NOT EDIT! -->
<a id="PersistentStore_Plugin"></a>
# PersistentStore Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PersistentStore/IStore.h)**

A PersistentStore plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PersistentStore` plugin provides an interface for PersistentStore.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PersistentStore) |
| classname | string | Class name: *PersistentStore* |
| locator | string | Library name: *libWPEFrameworkPersistentStore.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the PersistentStore plugin:

PersistentStore interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#deleteKey) |  |
| [deleteNamespace](#deleteNamespace) |  |
| [getValue](#getValue) |  |
| [setValue](#setValue) |  |

<a id="deleteKey"></a>
## *deleteKey*



### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
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



### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
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



### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
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



### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
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



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PersistentStore plugin:

PersistentStore interface events:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#onValueChanged) |  |

<a id="valueChanged"></a>
## *valueChanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
| params.namespace | string |  |
| params.key | string |  |
| params.value | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PersistentStore.valueChanged",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": "",
        "value": ""
    }
}
```
