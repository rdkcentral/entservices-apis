<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Netflix_Plugin"></a>
# Netflix Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Netflix/CHANGELOG.md)**

A Netflix plugin for Thunder framework.

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

The `Netflix` plugin provides an interface for Netflix.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Netflix) |
| classname | string | Class name: *Netflix* |
| locator | string | Library name: *libWPEFrameworkNetflix.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Netflix plugin:

Netflix interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryReset](#method.factoryReset) |  |
| [getESN](#method.getESN) |  |
| [language](#method.language) |  |
| [setVisible](#method.setVisible) |  |
| [systemCommand](#method.systemCommand) |  |
| [voiceCommand](#method.voiceCommand) |  |
| [getNFREnabled](#method.getNFREnabled) |  |
| [setNFREnabled](#method.setNFREnabled) |  |

<a id="method.factoryReset"></a>
## *factoryReset [<sup>method</sup>](#head.Methods)*



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
    "id": 0,
    "method": "org.rdk.Netflix.factoryReset"
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

<a id="method.getESN"></a>
## *getESN [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Netflix.getESN"
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

<a id="method.language"></a>
## *language [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Netflix.language",
    "params": {
        "language": ""
    }
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

<a id="method.setVisible"></a>
## *setVisible [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.visibility | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Netflix.setVisible",
    "params": {
        "visibility": true
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

<a id="method.systemCommand"></a>
## *systemCommand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Netflix.systemCommand",
    "params": {
        "command": ""
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

<a id="method.voiceCommand"></a>
## *voiceCommand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Netflix.voiceCommand",
    "params": {
        "command": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.getNFREnabled"></a>
## *getNFREnabled [<sup>method</sup>](#head.Methods)*



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
    "id": 6,
    "method": "org.rdk.Netflix.getNFREnabled"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="method.setNFREnabled"></a>
## *setNFREnabled [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nfrEnable | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.Netflix.setNFREnabled",
    "params": {
        "nfrEnable": true
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Netflix plugin:

Netflix interface events:

| Event | Description |
| :-------- | :-------- |
| [exit](#event.exit) |  |
| [notifyClient](#event.notifyClient) |  |
| [stateChange](#event.stateChange) |  |

<a id="event.exit"></a>
## *exit [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.exitCode | uint32_t | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.Netflix.exit",
    "params": {
        "exitCode": 0
    }
}
```

<a id="event.notifyClient"></a>
## *notifyClient [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.Netflix.notifyClient",
    "params": {
        "eventName": ""
    }
}
```

<a id="event.stateChange"></a>
## *stateChange [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | INetflix::state | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.Netflix.stateChange",
    "params": {
        "state": ""
    }
}
```
