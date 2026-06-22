<!-- Generated automatically, DO NOT EDIT! -->
<a id="SharedStorage_Module"></a>
# SharedStorage Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SharedStorage/ISharedStorage.h)**

A SharedStorage module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ISharedStorage](#ISharedStorage)
    - [Methods](#ISharedStorage-Methods)
    - [Notifications](#ISharedStorage-Notifications)
  - [ISharedStorageInspector](#ISharedStorageInspector)
    - [Methods](#ISharedStorageInspector-Methods)
  - [ISharedStorageLimit](#ISharedStorageLimit)
    - [Methods](#ISharedStorageLimit-Methods)
  - [ISharedStorageCache](#ISharedStorageCache)
    - [Methods](#ISharedStorageCache-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `SharedStorage` module provides the following interface(s):

- ISharedStorage
- ISharedStorageInspector
- ISharedStorageLimit
- ISharedStorageCache

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SharedStorage) |
| classname | string | Class name: *SharedStorage* |
| locator | string | Library name: *libWPEFrameworkSharedStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ISharedStorage"></a>
## ISharedStorage Interface

<a id="ISharedStorage-Methods"></a>
### Methods

The following methods are provided by the ISharedStorage Interface:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#deleteKey) | Deletes a key from the specified namespace |
| [deleteNamespace](#deleteNamespace) | Deletes the specified namespace |
| [getValue](#getValue) | Returns the value of a key from the specified namespace. |
| [setValue](#setValue) | Sets the value of a key in the the specified namespace |

<a id="deleteKey"></a>
## *deleteKey*

Deletes a key from the specified namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
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
        "scope": "device",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SharedStorage.deleteKey", "params": {"scope": "device", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
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
## *deleteNamespace*

Deletes the specified namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
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
        "scope": "device",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SharedStorage.deleteNamespace", "params": {"scope": "device", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="getValue"></a>
## *getValue*

Returns the value of a key from the specified namespace.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
| params.namespace | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string | value out |
| result.ttl | integer | time to live (optional) |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SharedStorage.getValue",
    "params": {
        "scope": "device",
        "namespace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SharedStorage.getValue", "params": {"scope": "device", "namespace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "value": "",
        "ttl": 0,
        "success": true
    }
}
```

<a id="setValue"></a>
## *setValue*

Sets the value of a key in the the specified namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
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
    "id": 3,
    "method": "org.rdk.SharedStorage.setValue",
    "params": {
        "scope": "device",
        "namespace": "",
        "key": "",
        "value": "",
        "ttl": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SharedStorage.setValue", "params": {"scope": "device", "namespace": "", "key": "", "value": "", "ttl": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="ISharedStorage-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the ISharedStorage Interface:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#onValueChanged) | Values stored are changed using setValue |

<a id="onValueChanged"></a>
## *onValueChanged*

Values stored are changed using setValue

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
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
        "scope": "device",
        "namespace": "",
        "key": "",
        "value": ""
    }
}
```

---

<a id="ISharedStorageInspector"></a>
## ISharedStorageInspector Interface

<a id="ISharedStorageInspector-Methods"></a>
### Methods

The following methods are provided by the ISharedStorageInspector Interface:

| Method | Description |
| :-------- | :-------- |
| [getKeys](#getKeys) | Returns the keys that are stored in the specified namespace |
| [getNamespaces](#getNamespaces) | Returns the namespaces |
| [getStorageSizes](#getStorageSizes) | Returns the size occupied by each namespace |

<a id="getKeys"></a>
## *getKeys*

Returns the keys that are stored in the specified namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keys | array | keys list |
| result.keys[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SharedStorage.getKeys",
    "params": {
        "scope": "device",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.SharedStorage.getKeys", "params": {"scope": "device", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "keys": [
            ""
        ],
        "success": true
    }
}
```

<a id="getNamespaces"></a>
## *getNamespaces*

Returns the namespaces

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.namespaces | array | namespaces list |
| result.namespaces[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SharedStorage.getNamespaces",
    "params": {
        "scope": "device"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.SharedStorage.getNamespaces", "params": {"scope": "device"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "namespaces": [
            ""
        ],
        "success": true
    }
}
```

<a id="getStorageSizes"></a>
## *getStorageSizes*

Returns the size occupied by each namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageList | array | list of namespaces and their sizes |
| result.storageList[#].ns | string |  |
| result.storageList[#].size | integer |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SharedStorage.getStorageSizes",
    "params": {
        "scope": "device"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.SharedStorage.getStorageSizes", "params": {"scope": "device"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
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

---

<a id="ISharedStorageLimit"></a>
## ISharedStorageLimit Interface

<a id="ISharedStorageLimit-Methods"></a>
### Methods

The following methods are provided by the ISharedStorageLimit Interface:

| Method | Description |
| :-------- | :-------- |
| [getNamespaceStorageLimit](#getNamespaceStorageLimit) | Returns the storage limit for a given namespace |
| [setNamespaceStorageLimit](#setNamespaceStorageLimit) | Sets the storage limit for a given namespace |

<a id="getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit*

Returns the storage limit for a given namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageLimit | integer | Size in bytes |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SharedStorage.getNamespaceStorageLimit",
    "params": {
        "scope": "device",
        "namespace": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.SharedStorage.getNamespaceStorageLimit", "params": {"scope": "device", "namespace": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "storageLimit": 0
    }
}
```

<a id="setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit*

Sets the storage limit for a given namespace

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | string | must be device or account. Possible values: device, account |
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
    "id": 9,
    "method": "org.rdk.SharedStorage.setNamespaceStorageLimit",
    "params": {
        "scope": "device",
        "namespace": "",
        "storageLimit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.SharedStorage.setNamespaceStorageLimit", "params": {"scope": "device", "namespace": "", "storageLimit": 0}}' http://127.0.0.1:9998/jsonrpc
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

---

<a id="ISharedStorageCache"></a>
## ISharedStorageCache Interface

<a id="ISharedStorageCache-Methods"></a>
### Methods

The following methods are provided by the ISharedStorageCache Interface:

| Method | Description |
| :-------- | :-------- |
| [flushCache](#flushCache) | Flushes the device cache |

<a id="flushCache"></a>
## *flushCache*

Flushes the device cache

### Events Triggered
None
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
    "id": 4,
    "method": "org.rdk.SharedStorage.flushCache"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.SharedStorage.flushCache"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

