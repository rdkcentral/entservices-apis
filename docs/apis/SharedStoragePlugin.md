<!-- Generated automatically, DO NOT EDIT! -->
<a name="SharedStorage_Plugin"></a>
# SharedStorage Plugin

**Version: [1.0.0]()**

A org.rdk.SharedStorage plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `SharedStorage` plugin allows you to persist key/value pairs by namespace.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.SharedStorage*) |
| classname | string | Class name: *org.rdk.SharedStorage* |
| locator | string | Library name: *libWPEFrameworkSharedStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.SharedStorage plugin:

SharedStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#deleteKey) | Deletes a key from the specified namespace |
| [deleteNamespace](#deleteNamespace) | Deletes the specified namespace |
| [flushCache](#flushCache) | Flushes the device cache |
| [getKeys](#getKeys) | Returns the keys that are stored in the specified namespace |
| [getNamespaces](#getNamespaces) | Returns the namespaces |
| [getStorageSizes](#getStorageSizes) | Returns the size occupied by each namespace |
| [getValue](#getValue) | Returns the value of a key from the specified namespace |
| [setValue](#setValue) | Sets the value of a key in the the specified namespace |
| [setNamespaceStorageLimit](#setNamespaceStorageLimit) | Sets the storage limit for a given namespace |
| [getNamespaceStorageLimit](#getNamespaceStorageLimit) | Returns the storage limit for a given namespace |


<a name="deleteKey"></a>
## *deleteKey*

Deletes a key from the specified namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params.key | string | Key |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.deleteKey",
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

<a name="deleteNamespace"></a>
## *deleteNamespace*

Deletes the specified namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.deleteNamespace",
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

<a name="flushCache"></a>
## *flushCache*

Flushes the device cache.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.flushCache"
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

<a name="getKeys"></a>
## *getKeys*

Returns the keys that are stored in the specified namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keys | array |  |
| result.keys[#] | string | Key |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.getKeys",
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

<a name="getNamespaces"></a>
## *getNamespaces*

Returns the namespaces.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.namespaces | array |  |
| result.namespaces[#] | string | Namespace |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.getNamespaces",
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

<a name="getStorageSizes"></a>
## *getStorageSizes*

Returns the size occupied by each namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageList | array |  |
| result.storageList[#] | object |  |
| result.storageList[#].namespace | string | Namespace |
| result.storageList[#].size | number | Size in bytes |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.getStorageSizes",
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
        ],
        "success": true
    }
}
```

<a name="getValue"></a>
## *getValue*

Returns the value of a key from the specified namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params.key | string | Key |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string | Value |
| result.success | boolean | Whether the request succeeded |
| result?.ttl | number | <sup>*(optional)*</sup> Time in seconds |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 31 | ```ERROR_PENDING_CONDITIONS``` | Time is not synced |
| 43 | ```ERROR_NOT_EXIST``` | Unknown namespace |
| 22 | ```ERROR_UNKNOWN_KEY``` | Unknown key |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.getValue",
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

<a name="setValue"></a>
## *setValue*

Sets the value of a key in the the specified namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params.key | string | Key |
| params.value | string | Value |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |
| params?.ttl | number | <sup>*(optional)*</sup> Time in seconds |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 31 | ```ERROR_PENDING_CONDITIONS``` | Time is not synced |
| 16 | ```ERROR_INVALID_INPUT_LENGTH``` | Empty/too large namespace or key, or the storage doesn't have enough space |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.setValue",
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

<a name="setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit*

Sets the storage limit for a given namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params.storageLimit | number | Size in bytes |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | Whether the request succeeded |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 16 | ```ERROR_INVALID_INPUT_LENGTH``` | Empty/too large namespace, or the storage doesn't have enough space |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.setNamespaceStorageLimit",
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
    "result": true
}
```

<a name="getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit*

Returns the storage limit for a given namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params?.scope | string | <sup>*(optional)*</sup> Scope (must be one of the following: *device*, *account*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageLimit | number | Size in bytes |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 43 | ```ERROR_NOT_EXIST``` | Unknown namespace |
| 1 | ```ERROR_GENERAL``` | Unknown error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.SharedStorage.getNamespaceStorageLimit",
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

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.SharedStorage plugin:

SharedStorage interface events:

| Event | Description |
| :-------- | :-------- |
| [onValueChanged](#onValueChanged) | Triggered whenever any of the values stored are changed using setValue |


<a name="onValueChanged"></a>
## *onValueChanged*

Triggered whenever any of the values stored are changed using setValue.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.namespace | string | Namespace |
| params.key | string | Key |
| params.value | string | Value |
| params.scope | string | Scope (must be one of the following: *device*, *account*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onValueChanged",
    "params": {
        "namespace": "ns1",
        "key": "key1",
        "value": "value1",
        "scope": "device"
    }
}
```

