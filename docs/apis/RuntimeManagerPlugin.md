<!-- Generated automatically, DO NOT EDIT! -->
<a id="RuntimeManager_Plugin"></a>
# RuntimeManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RuntimeManager/IRuntimeManager.h)**

A RuntimeManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `RuntimeManager` plugin provides an interface for RuntimeManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RuntimeManager) |
| classname | string | Class name: *RuntimeManager* |
| locator | string | Library name: *libWPEFrameworkRuntimeManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the RuntimeManager plugin:

RuntimeManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onFailure](#onFailure) | Notifies failure in container execution |
| [onStarted](#onStarted) | Notifies container is started |
| [onStateChanged](#onStateChanged) | Notifies state of container |
| [onTerminated](#onTerminated) | Notifies container is shutdown |

<a id="onFailure"></a>
## *onFailure*

Notifies failure in container execution

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
| params.error | string | error string will send if there is failure |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.RuntimeManager.onFailure",
    "params": {
        "appInstanceId": "",
        "error": ""
    }
}
```

<a id="onStarted"></a>
## *onStarted*

Notifies container is started

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.RuntimeManager.onStarted",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onStateChanged"></a>
## *onStateChanged*

Notifies state of container

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
| params.state | string | state of the application/container |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.RuntimeManager.onStateChanged",
    "params": {
        "appInstanceId": "",
        "state": "RUNTIME_STATE_UNKNOWN"
    }
}
```

<a id="onTerminated"></a>
## *onTerminated*

Notifies container is shutdown

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.RuntimeManager.onTerminated",
    "params": {
        "appInstanceId": ""
    }
}
```
