<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Dictionary_Plugin"></a>
# Dictionary Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Dictionary/CHANGELOG.md)**

A Dictionary plugin for Thunder framework.

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

The `Dictionary` plugin provides an interface for Dictionary.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Dictionary) |
| classname | string | Class name: *Dictionary* |
| locator | string | Library name: *libWPEFrameworkDictionary.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Dictionary plugin:

Dictionary interface methods:

| Method | Description |
| :-------- | :-------- |
| [get](#method.get) |  |
| [isValid](#method.isValid) |  |
| [next](#method.next) |  |
| [reset](#method.reset) |  |
| [set](#method.set) |  |

<a id="method.get"></a>
## *get [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string | - |
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
    "id": 0,
    "method": "org.rdk.Dictionary.get",
    "params": {
        "nameSpace": "",
        "key": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": ""
}
```

<a id="method.isValid"></a>
## *isValid [<sup>method</sup>](#head.Methods)*



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
    "id": 1,
    "method": "org.rdk.Dictionary.isValid"
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

<a id="method.next"></a>
## *next [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Dictionary.next"
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

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*



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
    "id": 3,
    "method": "org.rdk.Dictionary.reset"
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

<a id="method.set"></a>
## *set [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string | - |
| params.key | string | - |
| params.value | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Dictionary.set",
    "params": {
        "nameSpace": "",
        "key": "",
        "value": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Dictionary plugin:

Dictionary interface events:

| Event | Description |
| :-------- | :-------- |
| [modified](#event.modified) |  |

<a id="event.modified"></a>
## *modified [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string | - |
| params.key | string | - |
| params.value | string | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Dictionary.modified",
    "params": {
        "nameSpace": "",
        "key": "",
        "value": ""
    }
}
```
