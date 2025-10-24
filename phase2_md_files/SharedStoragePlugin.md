<!-- Generated automatically, DO NOT EDIT! -->
<a id="SharedStorage_Plugin"></a>
# SharedStorage Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SharedStorage)**

A SharedStorage plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `SharedStorage` plugin provides an interface for SharedStorage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SharedStorage) |
| classname | string | Class name: *SharedStorage* |
| locator | string | Library name: *libWPEFrameworkSharedStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the SharedStorage plugin:

SharedStorage interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [deleteKey](#deleteKey) | Deletes a key from the specified namespace | NA |
| [deleteNamespace](#deleteNamespace) | Deletes the specified namespace | NA |
| [flushCache](#flushCache) | Flushes the device cache | NA |
| [getKeys](#getKeys) | Returns the keys that are stored in the specified namespace | NA |
| [getNamespaceStorageLimit](#getNamespaceStorageLimit) | Returns the storage limit for a given namespace | NA |
| [getNamespaces](#getNamespaces) | Returns the namespaces | NA |
| [getStorageSizes](#getStorageSizes) | Returns the size occupied by each namespace | NA |
| [getValue](#getValue) | Returns the value of a key from the specified namespace. | NA |
| [setNamespaceStorageLimit](#setNamespaceStorageLimit) | Sets the storage limit for a given namespace | NA |
| [setValue](#setValue) | Sets the value of a key in the the specified namespace | NA |

<a id="deleteKey"></a>
## *deleteKey [<sup>method</sup>](#Methods)*

Deletes a key from the specified namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.SharedStorage.deleteKey",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SharedStorage.deleteKey", "params": {"scope": "DEVICE", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```

<a id="deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#Methods)*

Deletes the specified namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SharedStorage.deleteNamespace",
    "params": {
        "scope": "DEVICE",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SharedStorage.deleteNamespace", "params": {"scope": "DEVICE", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true
    }
}
```

<a id="flushCache"></a>
## *flushCache [<sup>method</sup>](#Methods)*

Flushes the device cache

### Events
No Events are associated with this method.
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
    "id": 2,
    "method": "org.rdk.SharedStorage.flushCache"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SharedStorage.flushCache"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="getKeys"></a>
## *getKeys [<sup>method</sup>](#Methods)*

Returns the keys that are stored in the specified namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keys | IStringIterator | keys list |
| result.keys[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.SharedStorage.getKeys",
    "params": {
        "scope": "DEVICE",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SharedStorage.getKeys", "params": {"scope": "DEVICE", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "keys": [
            ""
        ],
        "success": true
    }
}
```

<a id="getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#Methods)*

Returns the storage limit for a given namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageLimit | integer | size |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.SharedStorage.getNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.SharedStorage.getNamespaceStorageLimit", "params": {"scope": "DEVICE", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "storageLimit": 0
    }
}
```

<a id="getNamespaces"></a>
## *getNamespaces [<sup>method</sup>](#Methods)*

Returns the namespaces

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.namespaces | IStringIterator | namespaces list |
| result.namespaces[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SharedStorage.getNamespaces",
    "params": {
        "scope": "DEVICE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.SharedStorage.getNamespaces", "params": {"scope": "DEVICE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "namespaces": [
            ""
        ],
        "success": true
    }
}
```

<a id="getStorageSizes"></a>
## *getStorageSizes [<sup>method</sup>](#Methods)*

Returns the size occupied by each namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageList | INamespaceSizeIterator | list of namespaces and their sizes |
| result.storageList[#].ns | string |  |
| result.storageList[#].size | integer |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SharedStorage.getStorageSizes",
    "params": {
        "scope": "DEVICE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.SharedStorage.getStorageSizes", "params": {"scope": "DEVICE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "storageList": [
            {
                "ns": "",
                "size": 0
            }
        ],
        "success": true
    }
}
```

<a id="getValue"></a>
## *getValue [<sup>method</sup>](#Methods)*

Returns the value of a key from the specified namespace.

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string | value |
| result.ttl | integer | time to live (optional) |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SharedStorage.getValue",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.SharedStorage.getValue", "params": {"scope": "DEVICE", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "value": "",
        "ttl": 0,
        "success": true
    }
}
```

<a id="setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#Methods)*

Sets the storage limit for a given namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
| params.storageLimit | integer | size |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SharedStorage.setNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "storageLimit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.SharedStorage.setNamespaceStorageLimit", "params": {"scope": "DEVICE", "namespace": "", "storageLimit": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "success": true
    }
}
```

<a id="setValue"></a>
## *setValue [<sup>method</sup>](#Methods)*

Sets the value of a key in the the specified namespace

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
| params.value | string | value |
| params.ttl | integer | time to live (optional) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SharedStorage.setValue",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.SharedStorage.setValue", "params": {"scope": "DEVICE", "namespace": "", "key": "", "value": "", "ttl": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the SharedStorage plugin:

SharedStorage interface events:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#onValueChanged) | Values stored are changed using setValue |

<a id="onValueChanged"></a>
## *onValueChanged [<sup>event</sup>](#Notifications)*

Values stored are changed using setValue

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
| params.value | string | value |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.SharedStorage.onValueChanged",
    "params": {
        "scope": "DEVICE",
        "namespace": "",
        "key": "",
        "value": ""
    }
}
```
