<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.PersistentStore_Plugin"></a>
# PersistentStore Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/PersistentStore/CHANGELOG.md)**

A PersistentStore plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `PersistentStore` plugin provides an interface for PersistentStore.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PersistentStore) |
| classname | string | Class name: *PersistentStore* |
| locator | string | Library name: *libWPEFrameworkPersistentStore.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the PersistentStore plugin:

PersistentStore interface methods:

| Method | Description |
| :-------- | :-------- |
| [flushCache](#method.flushCache) |  |
| [deleteKey](#method.deleteKey) |  |
| [deleteNamespace](#method.deleteNamespace) |  |
| [getValue](#method.getValue) |  |
| [setValue](#method.setValue) |  |
| [getKeys](#method.getKeys) |  |
| [getNamespaceStorageLimit](#method.getNamespaceStorageLimit) |  |
| [getNamespaces](#method.getNamespaces) |  |
| [getStorageSizes](#method.getStorageSizes) |  |
| [setNamespaceStorageLimit](#method.setNamespaceStorageLimit) |  |

<a id="method.flushCache"></a>
## *flushCache [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
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
    "method": "org.rdk.PersistentStore.flushCache"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PersistentStore.flushCache"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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

<a id="method.deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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

<a id="method.getValue"></a>
## *getValue [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 6,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PersistentStore.getValue", "params": {"scope": "DEVICE", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "value": "",
        "ttl": 0
    }
}
```

<a id="method.setValue"></a>
## *setValue [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 8,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PersistentStore.setValue", "params": {"scope": "DEVICE", "namespace": "", "key": "", "value": "", "ttl": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.getKeys"></a>
## *getKeys [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
| params.namespace | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keys | IStringIterator |  |
| result.keys[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PersistentStore.getKeys",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PersistentStore.getKeys", "params": {"scope": "DEVICE", "ns": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": [
        ""
    ]
}
```

<a id="method.getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
| params.namespace | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.size | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PersistentStore.getNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PersistentStore.getNamespaceStorageLimit", "params": {"scope": "DEVICE", "ns": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "size": 0
    }
}
```

<a id="method.getNamespaces"></a>
## *getNamespaces [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.namespaces | IStringIterator |  |
| result.namespaces[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PersistentStore.getNamespaces",
    "params": {
        "scope": "DEVICE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PersistentStore.getNamespaces", "params": {"scope": "DEVICE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": [
        ""
    ]
}
```

<a id="method.getStorageSizes"></a>
## *getStorageSizes [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageList | INamespaceSizeIterator |  |
| result.storageList[#].ns | string |  |
| result.storageList[#].size | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PersistentStore.getStorageSizes",
    "params": {
        "scope": "DEVICE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PersistentStore.getStorageSizes", "params": {"scope": "DEVICE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": [
        {
            "ns": "",
            "size": 0
        }
    ]
}
```

<a id="method.setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string |  |
| params.namespace | string |  |
| params.size | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PersistentStore.setNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "size": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PersistentStore.setNamespaceStorageLimit", "params": {"scope": "DEVICE", "ns": "", "size": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PersistentStore plugin:

PersistentStore interface events:

| Event | Description |
| :-------- | :-------- |
| [storageExceeded](#event.storageExceeded) |  |
| [onValueChanged](#event.onValueChanged) |  |

<a id="event.storageExceeded"></a>
## *storageExceeded [<sup>event</sup>](#head.Notifications)*



### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PersistentStore.storageExceeded"
}
```

<a id="event.valueChanged"></a>
## *valueChanged [<sup>event</sup>](#head.Notifications)*



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
    "id": 9,
    "method": "org.rdk.PersistentStore.valueChanged",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": "",
        "value": ""
    }
}
```
