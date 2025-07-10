<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Store_Plugin"></a>
# Store Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Store/CHANGELOG.md)**

A Store plugin for Thunder framework.

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

The `Store` plugin provides an interface for Store.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Store) |
| classname | string | Class name: *Store* |
| locator | string | Library name: *libWPEFrameworkStore.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Store plugin:

Store interface methods:

| Method | Description |
| :-------- | :-------- |
| [deleteKey](#method.deleteKey) |  |
| [deleteNamespace](#method.deleteNamespace) |  |
| [getValue](#method.getValue) |  |
| [setValue](#method.setValue) |  |

<a id="method.deleteKey"></a>
## *deleteKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ns | string | - |
| params.key | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Store.deleteKey",
    "params": {
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
| params.ns | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Store.deleteNamespace",
    "params": {
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

<a id="method.getValue"></a>
## *getValue [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ns | string | - |
| params.key | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.value | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Store.getValue",
    "params": {
        "ns": "",
        "key": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
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
| params.ns | string | - |
| params.key | string | - |
| params.value | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Store.setValue",
    "params": {
        "ns": "",
        "key": "",
        "value": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Store plugin:

Store interface events:

| Event | Description |
| :-------- | :-------- |
| [storageExceeded](#event.storageExceeded) |  |
| [valueChanged](#event.valueChanged) |  |

<a id="event.storageExceeded"></a>
## *storageExceeded [<sup>event</sup>](#head.Notifications)*



### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Store.storageExceeded"
}
```

<a id="event.valueChanged"></a>
## *valueChanged [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ns | string | - |
| params.key | string | - |
| params.value | string | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Store.valueChanged",
    "params": {
        "ns": "",
        "key": "",
        "value": ""
    }
}
```
