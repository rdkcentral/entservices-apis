<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Packager_Plugin"></a>
# Packager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Packager/CHANGELOG.md)**

A Packager plugin for Thunder framework.

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

The `Packager` plugin provides an interface for Packager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Packager) |
| classname | string | Class name: *Packager* |
| locator | string | Library name: *libWPEFrameworkPackager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Packager plugin:

Packager interface methods:

| Method | Description |
| :-------- | :-------- |
| [abort](#method.abort) |  |
| [appName](#method.appName) |  |
| [architecture](#method.architecture) |  |
| [configure](#method.configure) |  |
| [errorCode](#method.errorCode) |  |
| [install](#method.install) |  |
| [name](#method.name) |  |
| [progress](#method.progress) |  |
| [state](#method.state) |  |
| [synchronizeRepository](#method.synchronizeRepository) |  |
| [version](#method.version) |  |

<a id="method.abort"></a>
## *abort [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Packager.abort"
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

<a id="method.appName"></a>
## *appName [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Packager.appName"
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

<a id="method.architecture"></a>
## *architecture [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Packager.architecture"
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

<a id="method.configure"></a>
## *configure [<sup>method</sup>](#head.Methods)*



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
    "id": 3,
    "method": "org.rdk.Packager.configure",
    "params": {
        "service": ""
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

<a id="method.errorCode"></a>
## *errorCode [<sup>method</sup>](#head.Methods)*



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
    "id": 4,
    "method": "org.rdk.Packager.errorCode"
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

<a id="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | - |
| params.version | string | - |
| params.arch | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Packager.install",
    "params": {
        "name": "",
        "version": "",
        "arch": ""
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

<a id="method.name"></a>
## *name [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.Packager.name"
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

<a id="method.progress"></a>
## *progress [<sup>method</sup>](#head.Methods)*



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
    "id": 7,
    "method": "org.rdk.Packager.progress"
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

<a id="method.state"></a>
## *state [<sup>method</sup>](#head.Methods)*



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
    "id": 8,
    "method": "org.rdk.Packager.state"
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

<a id="method.synchronizeRepository"></a>
## *synchronizeRepository [<sup>method</sup>](#head.Methods)*



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
    "id": 9,
    "method": "org.rdk.Packager.synchronizeRepository"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.version"></a>
## *version [<sup>method</sup>](#head.Methods)*



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
    "id": 10,
    "method": "org.rdk.Packager.version"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Packager plugin:

Packager interface events:

| Event | Description |
| :-------- | :-------- |
| [repositorySynchronize](#event.repositorySynchronize) |  |
| [stateChange](#event.stateChange) |  |

<a id="event.repositorySynchronize"></a>
## *repositorySynchronize [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | uint32_t | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.Packager.repositorySynchronize",
    "params": {
        "status": 0
    }
}
```

<a id="event.stateChange"></a>
## *stateChange [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.package | IPackageInfo | - |
| params.install | IInstallationInfo | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.Packager.stateChange",
    "params": {
        "package": "",
        "install": ""
    }
}
```
