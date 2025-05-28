<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IOCIContainer_Plugin"></a>
# IOCIContainer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IOCIContainer/CHANGELOG.md)**

A IOCIContainer plugin for Thunder framework.

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

The `IOCIContainer` plugin provides an interface for IOCIContainer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IOCIContainer*) |
| classname | string | Class name: *IOCIContainer* |
| locator | string | Library name: *libWPEFrameworkIOCIContainer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IOCIContainer plugin:

IOCIContainer interface methods:

| Method | Description |
| :-------- | :-------- |
| [Annotate](#method.Annotate) |  |
| [ExecuteCommand](#method.ExecuteCommand) |  |
| [GetContainerInfo](#method.GetContainerInfo) |  |
| [GetContainerState](#method.GetContainerState) |  |
| [HibernateContainer](#method.HibernateContainer) |  |
| [ListContainers](#method.ListContainers) |  |
| [Mount](#method.Mount) |  |
| [PauseContainer](#method.PauseContainer) |  |
| [RemoveAnnotation](#method.RemoveAnnotation) |  |
| [ResumeContainer](#method.ResumeContainer) |  |
| [StartContainer](#method.StartContainer) |  |
| [StartContainerFromDobbySpec](#method.StartContainerFromDobbySpec) |  |
| [StopContainer](#method.StopContainer) |  |
| [Unmount](#method.Unmount) |  |
| [WakeupContainer](#method.WakeupContainer) |  |

<a id="method.Annotate"></a>
## *Annotate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.key | string | name of property |
| params.value | string | property data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.Annotate",
    "params": {
        "containerId": "",
        "key": "",
        "value": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.ExecuteCommand"></a>
## *ExecuteCommand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.options | string | (optional) options to be passed to command |
| params.command | string | (optional) command to run in container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.ExecuteCommand",
    "params": {
        "containerId": "",
        "options": "",
        "command": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.GetContainerInfo"></a>
## *GetContainerInfo [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.info | string |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.GetContainerInfo",
    "params": {
        "containerId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "info": "",
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.GetContainerState"></a>
## *GetContainerState [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.state | ContainerState |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.GetContainerState",
    "params": {
        "containerId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "state": "INVALID",
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.HibernateContainer"></a>
## *HibernateContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.options | string | (optional) options to be passed to command |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.HibernateContainer",
    "params": {
        "containerId": "",
        "options": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.ListContainers"></a>
## *ListContainers [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.containers | string | - out/json - string |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.ListContainers"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "containers": "",
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.Mount"></a>
## *Mount [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.source | string | path source to mount |
| params.target | string | mount target inside container |
| params.type | string | type of mounting |
| params.options | string | (optional) options to be passed to command |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.Mount",
    "params": {
        "containerId": "",
        "source": "",
        "target": "",
        "type": "",
        "options": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.PauseContainer"></a>
## *PauseContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.PauseContainer",
    "params": {
        "containerId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.RemoveAnnotation"></a>
## *RemoveAnnotation [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.key | string | name of property |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.RemoveAnnotation",
    "params": {
        "containerId": "",
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
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.ResumeContainer"></a>
## *ResumeContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.ResumeContainer",
    "params": {
        "containerId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.StartContainer"></a>
## *StartContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.bundlePath | string | path of application bundle |
| params.command | string | (optional) command to run in container |
| params.westerosSocket | string | (optional) Westeros socket container need to connect |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.descriptor | int32_t |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.StartContainer",
    "params": {
        "containerId": "",
        "bundlePath": "",
        "command": "",
        "westerosSocket": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "descriptor": "0",
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.StartContainerFromDobbySpec"></a>
## *StartContainerFromDobbySpec [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.dobbySpec | string | dobby specification as json string |
| params.command | string | (optional) command to run in container |
| params.westerosSocket | string | (optional) Westeros socket container need to connect |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.descriptor | int32_t |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.StartContainerFromDobbySpec",
    "params": {
        "containerId": "",
        "dobbySpec": "",
        "command": "",
        "westerosSocket": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "descriptor": "0",
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.StopContainer"></a>
## *StopContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.force | bool | (optional) Metion forceful or graceful termination of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.StopContainer",
    "params": {
        "containerId": "",
        "force": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.Unmount"></a>
## *Unmount [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.target | string | mount target inside container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.Unmount",
    "params": {
        "containerId": "",
        "target": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```
<a id="method.WakeupContainer"></a>
## *WakeupContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.WakeupContainer",
    "params": {
        "containerId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "errorReason": ""
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IOCIContainer plugin:

IOCIContainer interface events:

| Method | Description |
| :-------- | :-------- |
| [OnContainerFailed](#event.OnContainerFailed) | Notifies failure in container execution |
| [OnContainerStarted](#event.OnContainerStarted) | Notifies container is started |
| [OnContainerStateChanged](#event.OnContainerStateChanged) | Notifies state change of container |
| [OnContainerStopped](#event.OnContainerStopped) | Notifies container is stopped |

<a id="event.OnContainerFailed"></a>
## *OnContainerFailed [<sup>event</sup>](#head.Notifications)*

Notifies failure in container execution

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.name | string |  |
| params.error | uint32_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.OnContainerFailed",
    "params": {
        "containerId": "",
        "name": "",
        "error": "0"
    }
}
```
<a id="event.OnContainerStarted"></a>
## *OnContainerStarted [<sup>event</sup>](#head.Notifications)*

Notifies container is started

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.name | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.OnContainerStarted",
    "params": {
        "containerId": "",
        "name": ""
    }
}
```
<a id="event.OnContainerStateChanged"></a>
## *OnContainerStateChanged [<sup>event</sup>](#head.Notifications)*

Notifies state change of container

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.state | ContainerState |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.OnContainerStateChanged",
    "params": {
        "containerId": "",
        "state": "INVALID"
    }
}
```
<a id="event.OnContainerStopped"></a>
## *OnContainerStopped [<sup>event</sup>](#head.Notifications)*

Notifies container is stopped

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.containerId | string | Identifier of container |
| params.name | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IOCIContainer.OnContainerStopped",
    "params": {
        "containerId": "",
        "name": ""
    }
}
```