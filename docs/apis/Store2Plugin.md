<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Store2_Plugin"></a>
# Store2 Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Store2/CHANGELOG.md)**

A Store2 plugin for Thunder framework.

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

The `Store2` plugin provides an interface for Store2.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Store2) |
| classname | string | Class name: *Store2* |
| locator | string | Library name: *libWPEFrameworkStore2.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Store2 plugin:

Store2 interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#method.deleteKey) |  |
| [deleteNamespace](#method.deleteNamespace) |  |
| [getKeys](#method.getKeys) |  |
| [getNamespaceStorageLimit](#method.getNamespaceStorageLimit) |  |
| [getNamespaces](#method.getNamespaces) |  |
| [getStorageSizes](#method.getStorageSizes) |  |
| [getValue](#method.getValue) |  |
| [setNamespaceStorageLimit](#method.setNamespaceStorageLimit) |  |
| [setValue](#method.setValue) |  |

<a id="method.deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.namespace | string | - |
| params.key | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Store2.deleteKey",
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
    "result": null
}
```

<a id="method.deleteNamespace"></a>
## *deleteNamespace [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.namespace | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Store2.deleteNamespace",
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
    "result": null
}
```

<a id="method.getKeys"></a>
## *getKeys [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.ns | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.keys | IStringIterator | - |
| result.keys[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Store2.getKeys",
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
    "id": 2,
    "result": [
        ""
    ]
}
```

<a id="method.getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.ns | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.size | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Store2.getNamespaceStorageLimit",
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
    "result": 0
}
```

<a id="method.getNamespaces"></a>
## *getNamespaces [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.namespaces | IStringIterator | - |
| result.namespaces[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Store2.getNamespaces",
    "params": {
        "scope": "DEVICE"
    }
}
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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageList | INamespaceSizeIterator | - |
| result.storageList[#].ns | string | - |
| result.storageList[#].size | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Store2.getStorageSizes",
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
    "result": [
        {
            "ns": "",
            "size": 0
        }
    ]
}
```

<a id="method.getValue"></a>
## *getValue [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.namespace | string | - |
| params.key | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.value | string | - |
| result.ttl | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Store2.getValue",
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
    "id": 6,
    "result": {
        "value": "",
        "ttl": 0
    }
}
```

<a id="method.setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.ns | string | - |
| params.size | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.Store2.setNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "size": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.setValue"></a>
## *setValue [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.namespace | string | - |
| params.key | string | - |
| params.value | string | - |
| params.ttl | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.Store2.setValue",
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
    "id": 8,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Store2 plugin:

Store2 interface events:

| Event | Description |
| :-------- | :-------- |
| [valueChanged](#event.valueChanged) |  |

<a id="event.valueChanged"></a>
## *valueChanged [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scope | ScopeType | - |
| params.namespace | string | - |
| params.key | string | - |
| params.value | string | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.Store2.valueChanged",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "key": "",
        "value": ""
    }
}
```
