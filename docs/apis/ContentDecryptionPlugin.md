<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ContentDecryption_Plugin"></a>
# ContentDecryption Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/ContentDecryption/CHANGELOG.md)**

A ContentDecryption plugin for Thunder framework.

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

The `ContentDecryption` plugin provides an interface for ContentDecryption.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.ContentDecryption) |
| classname | string | Class name: *ContentDecryption* |
| locator | string | Library name: *libWPEFrameworkContentDecryption.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the ContentDecryption plugin:

ContentDecryption interface methods:

| Method | Description |
| :-------- | :-------- |
| [deinitialize](#method.deinitialize) |  |
| [initialize](#method.initialize) |  |
| [reset](#method.reset) |  |

<a id="method.deinitialize"></a>
## *deinitialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | PluginHost::IShell | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.ContentDecryption.deinitialize",
    "params": {
        "service": ""
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

<a id="method.initialize"></a>
## *initialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | PluginHost::IShell | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.ContentDecryption.initialize",
    "params": {
        "service": ""
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
    "id": 2,
    "method": "org.rdk.ContentDecryption.reset"
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the ContentDecryption plugin:

ContentDecryption interface events:

| Event | Description |
| :-------- | :-------- |
| [initializationStatus](#event.initializationStatus) | initialization status. |

<a id="event.initializationStatus"></a>
## *initializationStatus [<sup>event</sup>](#head.Notifications)*

initialization status.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.drm | std::string | - |
| params.status | Status | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.ContentDecryption.initializationStatus",
    "params": {
        "drm": "",
        "status": "BUSY"
    }
}
```
