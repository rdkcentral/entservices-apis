<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.SharedStorage_Plugin"></a>
# SharedStorage Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/SharedStorage/CHANGELOG.md)**

A SharedStorage plugin for Thunder framework.

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

The `SharedStorage` plugin provides an interface for SharedStorage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SharedStorage) |
| classname | string | Class name: *SharedStorage* |
| locator | string | Library name: *libWPEFrameworkSharedStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the SharedStorage plugin:

SharedStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#method.deleteKey) | Deletes a key from the specified namespace |
| [deleteNamespace](#method.deleteNamespace) | Deletes the specified namespace |
| [flushCache](#method.flushCache) | Flushes the device cache |
| [getKeys](#method.getKeys) | Returns the keys that are stored in the specified namespace |
| [getNamespaceStorageLimit](#method.getNamespaceStorageLimit) | Returns the storage limit for a given namespace |
| [getNamespaces](#method.getNamespaces) | Returns the namespaces |
| [getStorageSizes](#method.getStorageSizes) | Returns the size occupied by each namespace |
| [getValue](#method.getValue) | Returns the value of a key from the specified namespace. |
| [setNamespaceStorageLimit](#method.setNamespaceStorageLimit) | Sets the storage limit for a given namespace |
| [setValue](#method.setValue) | Sets the value of a key in the the specified namespace |

<a id="method.deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head.Methods)*

Deletes a key from the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.SharedStorage.deleteKey",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "key": ""
    }
}
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

<a id="method.deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#head.Methods)*

Deletes the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SharedStorage.deleteNamespace",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
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

<a id="method.flushCache"></a>
## *flushCache [<sup>method</sup>](#head.Methods)*

Flushes the device cache

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SharedStorage.flushCache"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.getKeys"></a>
## *getKeys [<sup>method</sup>](#head.Methods)*

Returns the keys that are stored in the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.keys | IStringIterator | keys list |
| result.keys[#] | string | - |
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
        "ns": ""
    }
}
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

<a id="method.getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*

Returns the storage limit for a given namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageLimit | StorageLimit | Size in bytes |
| result.storageLimit.storageLimit | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.SharedStorage.getNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
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

<a id="method.getNamespaces"></a>
## *getNamespaces [<sup>method</sup>](#head.Methods)*

Returns the namespaces

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.namespaces | IStringIterator | namespaces list |
| result.namespaces[#] | string | - |
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

<a id="method.getStorageSizes"></a>
## *getStorageSizes [<sup>method</sup>](#head.Methods)*

Returns the size occupied by each namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageList | INamespaceSizeIterator | list of namespaces and their sizes |
| result.storageList[#].ns | string | - |
| result.storageList[#].size | uint32_t | - |
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

<a id="method.getValue"></a>
## *getValue [<sup>method</sup>](#head.Methods)*

Returns the value of a key from the specified namespace.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.value | string | value |
| result.ttl | uint32_t | time to live (optional) |
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
        "ns": "",
        "key": ""
    }
}
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

<a id="method.setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*

Sets the storage limit for a given namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
| params.storageLimit | uint32_t | size |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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
        "ns": "",
        "storageLimit": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": true
}
```

<a id="method.setValue"></a>
## *setValue [<sup>method</sup>](#head.Methods)*

Sets the value of a key in the the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
| params.namespace | string | name space |
| params.key | string | key |
| params.value | string | value |
| params.ttl | uint32_t | time to live (optional) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SharedStorage.setValue",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "key": "",
        "value": "",
        "ttl": 0
    }
}
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the SharedStorage plugin:

SharedStorage interface events:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#event.onValueChanged) | Values stored are changed using setValue |

<a id="event.onValueChanged"></a>
## *onValueChanged [<sup>event</sup>](#head.Notifications)*

Values stored are changed using setValue

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | must be device or account |
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
        "ns": "",
        "key": "",
        "value": ""
    }
}
```
