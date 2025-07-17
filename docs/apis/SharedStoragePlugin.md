<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ISharedStorage_Plugin"></a>
# ISharedStorage Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/ISharedStorage/CHANGELOG.md)**

A ISharedStorage plugin for Thunder framework.

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

The `ISharedStorage` plugin provides an interface for ISharedStorage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *ISharedStorage*) |
| classname | string | Class name: *ISharedStorage* |
| locator | string | Library name: *libWPEFrameworkISharedStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the ISharedStorage plugin:

ISharedStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [DeleteKey](#method.DeleteKey) | Deletes a key from the specified namespace |
| [DeleteNamespace](#method.DeleteNamespace) | Deletes the specified namespace |
| [FlushCache](#method.FlushCache) | Flushes the device cache |
| [GetKeys](#method.GetKeys) | Returns the keys that are stored in the specified namespace |
| [GetNamespaceStorageLimit](#method.GetNamespaceStorageLimit) | Returns the storage limit for a given namespace |
| [GetNamespaces](#method.GetNamespaces) | Returns the namespaces |
| [GetStorageSizes](#method.GetStorageSizes) | Returns the size occupied by each namespace |
| [GetValue](#method.GetValue) | Returns the value of a key from the specified namespace. |
| [SetNamespaceStorageLimit](#method.SetNamespaceStorageLimit) | Sets the storage limit for a given namespace |
| [SetValue](#method.SetValue) | Sets the value of a key in the the specified namespace |

<a id="method.DeleteKey"></a>
## *DeleteKey [<sup>method</sup>](#head.Methods)*

Deletes a key from the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
| params.key | string | key |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.DeleteKey",
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
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.DeleteNamespace"></a>
## *DeleteNamespace [<sup>method</sup>](#head.Methods)*

Deletes the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.DeleteNamespace",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.FlushCache"></a>
## *FlushCache [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.FlushCache"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetKeys"></a>
## *GetKeys [<sup>method</sup>](#head.Methods)*

Returns the keys that are stored in the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.keys | IStringIterator | keys list |
| result.keys[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.GetKeys",
    "params": {
        "scope": "DEVICE",
        "ns": ""
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
            ""
        ],
        "success": "true"
    }
}
```
<a id="method.GetNamespaceStorageLimit"></a>
## *GetNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*

Returns the storage limit for a given namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageLimit | StorageLimit | Size in bytes |
| result.storageLimit.storageLimit | uint32_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.GetNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "storageLimit": {
            "storageLimit": "0"
        }
    }
}
```
<a id="method.GetNamespaces"></a>
## *GetNamespaces [<sup>method</sup>](#head.Methods)*

Returns the namespaces

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.namespaces | IStringIterator | namespaces list |
| result.namespaces[#] | string |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.GetNamespaces",
    "params": {
        "scope": "DEVICE"
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
            ""
        ],
        "success": "true"
    }
}
```
<a id="method.GetStorageSizes"></a>
## *GetStorageSizes [<sup>method</sup>](#head.Methods)*

Returns the size occupied by each namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageList | INamespaceSizeIterator | list of namespaces and their sizes |
| result.storageList[#].ns | string |  |
| result.storageList[#].size | uint32_t |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.GetStorageSizes",
    "params": {
        "scope": "DEVICE"
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
                "ns": "",
                "size": "0"
            }
        ],
        "success": "true"
    }
}
```
<a id="method.GetValue"></a>
## *GetValue [<sup>method</sup>](#head.Methods)*

Returns the value of a key from the specified namespace.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.GetValue",
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
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "value": "",
        "ttl": "0",
        "success": "true"
    }
}
```
<a id="method.SetNamespaceStorageLimit"></a>
## *SetNamespaceStorageLimit [<sup>method</sup>](#head.Methods)*

Sets the storage limit for a given namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
| params.storageLimit | uint32_t | size |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.SetNamespaceStorageLimit",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "storageLimit": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true"
    }
}
```
<a id="method.SetValue"></a>
## *SetValue [<sup>method</sup>](#head.Methods)*

Sets the value of a key in the the specified namespace

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
| params.key | string | key |
| params.value | string | value |
| params.ttl | uint32_t | time to live (optional) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | Success | success |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.SetValue",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "key": "",
        "value": "",
        "ttl": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the ISharedStorage plugin:

ISharedStorage interface events:

| Method | Description |
| :-------- | :-------- |
| [OnValueChanged](#event.OnValueChanged) | Values stored are changed using setValue |

<a id="event.OnValueChanged"></a>
## *OnValueChanged [<sup>event</sup>](#head.Notifications)*

Values stored are changed using setValue

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.scope | ScopeType | must be device or account |
| params.ns | string | name space |
| params.key | string | key |
| params.value | string | value |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISharedStorage.OnValueChanged",
    "params": {
        "scope": "DEVICE",
        "ns": "",
        "key": "",
        "value": ""
    }
}
```