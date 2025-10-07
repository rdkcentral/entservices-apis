<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_OCIContainer_API"></a>
# OCIContainer API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

OCIContainer interface for Thunder framework.

(Defined with IOCIContainer in [IOCIContainer.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IOCIContainer.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the OCIContainer interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

OCIContainer JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the OCIContainer interface:

OCIContainer interface methods:

| Method | Description |
| :-------- | :-------- |
| [listContainers](#method_listContainers) |  |
| [getContainerInfo](#method_getContainerInfo) |  |
| [getContainerState](#method_getContainerState) |  |
| [startContainer](#method_startContainer) |  |
| [startContainerFromDobbySpec](#method_startContainerFromDobbySpec) |  |
| [stopContainer](#method_stopContainer) |  |
| [pauseContainer](#method_pauseContainer) |  |
| [resumeContainer](#method_resumeContainer) |  |
| [hibernateContainer](#method_hibernateContainer) |  |
| [wakeupContainer](#method_wakeupContainer) |  |
| [executeCommand](#method_executeCommand) |  |
| [annotate](#method_annotate) |  |
| [removeAnnotation](#method_removeAnnotation) |  |
| [mount](#method_mount) |  |
| [unmount](#method_unmount) |  |

<a id="method_listContainers"></a>
## *listContainers [<sup>method</sup>](#head_Methods)*

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.containers | opaque object | mandatory | - out/json - string |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.listContainers"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "containers": {},
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_getContainerInfo"></a>
## *getContainerInfo [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.info | opaque object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getContainerInfo",
  "params": {
    "containerId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "info": {},
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_getContainerState"></a>
## *getContainerState [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.state | string | mandatory |  (must be one of the following: *AWAKENING, HIBERNATED, HIBERNATING, INVALID, PAUSED, RUNNING, STARTING, STOPPED, STOPPING*) |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getContainerState",
  "params": {
    "containerId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "state": "STARTING",
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_startContainer"></a>
## *startContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.bundlePath | string | mandatory | Path of application bundle |
| params.command | string | mandatory |  |
| params.westerosSocket | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.descriptor | integer | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.startContainer",
  "params": {
    "containerId": "...",
    "bundlePath": "...",
    "command": "...",
    "westerosSocket": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "descriptor": 0,
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_startContainerFromDobbySpec"></a>
## *startContainerFromDobbySpec [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.dobbySpec | string | mandatory | Dobby specification as json string |
| params.command | string | mandatory |  |
| params.westerosSocket | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.descriptor | integer | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.startContainerFromDobbySpec",
  "params": {
    "containerId": "...",
    "dobbySpec": "...",
    "command": "...",
    "westerosSocket": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "descriptor": 0,
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_stopContainer"></a>
## *stopContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.force | boolean | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stopContainer",
  "params": {
    "containerId": "...",
    "force": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_pauseContainer"></a>
## *pauseContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.pauseContainer",
  "params": {
    "containerId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_resumeContainer"></a>
## *resumeContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.resumeContainer",
  "params": {
    "containerId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_hibernateContainer"></a>
## *hibernateContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.options | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.hibernateContainer",
  "params": {
    "containerId": "...",
    "options": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_wakeupContainer"></a>
## *wakeupContainer [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.wakeupContainer",
  "params": {
    "containerId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_executeCommand"></a>
## *executeCommand [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.options | string | mandatory |  |
| params.command | string | mandatory | Command to run in container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.executeCommand",
  "params": {
    "containerId": "...",
    "options": "...",
    "command": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_annotate"></a>
## *annotate [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.key | string | mandatory | Name of property |
| params.value | string | mandatory | Property data |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.annotate",
  "params": {
    "containerId": "...",
    "key": "...",
    "value": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_removeAnnotation"></a>
## *removeAnnotation [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.key | string | mandatory | Name of property |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.removeAnnotation",
  "params": {
    "containerId": "...",
    "key": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_mount"></a>
## *mount [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.source | string | mandatory | Path source to mount |
| params.target | string | mandatory | Mount target inside container |
| params.type | string | mandatory | Type of mounting |
| params.options | string | mandatory | Options for mounting |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.mount",
  "params": {
    "containerId": "...",
    "source": "...",
    "target": "...",
    "type": "...",
    "options": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="method_unmount"></a>
## *unmount [<sup>method</sup>](#head_Methods)*

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory | Identifier of container |
| params.target | string | mandatory | Path to unmount from container |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.errorReason | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unmount",
  "params": {
    "containerId": "...",
    "target": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "errorReason": "..."
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the OCIContainer interface:

OCIContainer interface events:

| Notification | Description |
| :-------- | :-------- |
| [onContainerStarted](#notification_onContainerStarted) | Notifies container is started |
| [onContainerStopped](#notification_onContainerStopped) | Notifies container is stopped |
| [onContainerFailed](#notification_onContainerFailed) | Notifies failure in container execution |
| [onContainerStateChanged](#notification_onContainerStateChanged) | Notifies state change of container |

<a id="notification_onContainerStarted"></a>
## *onContainerStarted [<sup>notification</sup>](#head_Notifications)*

Notifies container is started.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory |  |
| params.name | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onContainerStarted",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onContainerStarted",
  "params": {
    "containerId": "...",
    "name": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onContainerStarted``.

<a id="notification_onContainerStopped"></a>
## *onContainerStopped [<sup>notification</sup>](#head_Notifications)*

Notifies container is stopped.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory |  |
| params.name | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onContainerStopped",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onContainerStopped",
  "params": {
    "containerId": "...",
    "name": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onContainerStopped``.

<a id="notification_onContainerFailed"></a>
## *onContainerFailed [<sup>notification</sup>](#head_Notifications)*

Notifies failure in container execution.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory |  |
| params.name | string | mandatory |  |
| params.error | integer | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onContainerFailed",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onContainerFailed",
  "params": {
    "containerId": "...",
    "name": "...",
    "error": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onContainerFailed``.

<a id="notification_onContainerStateChanged"></a>
## *onContainerStateChanged [<sup>notification</sup>](#head_Notifications)*

Notifies state change of container.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.containerId | string | mandatory |  |
| params.state | string | mandatory |  (must be one of the following: *AWAKENING, HIBERNATED, HIBERNATING, INVALID, PAUSED, RUNNING, STARTING, STOPPED, STOPPING*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onContainerStateChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onContainerStateChanged",
  "params": {
    "containerId": "...",
    "state": "STARTING"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onContainerStateChanged``.

