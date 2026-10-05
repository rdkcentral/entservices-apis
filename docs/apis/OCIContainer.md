<!-- Generated automatically, DO NOT EDIT! -->
<a id="OCIContainer_Module"></a>
# OCIContainer Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/OCIContainer/IOCIContainer.h)**

A OCIContainer module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IOCIContainer](#IOCIContainer)
    - [Methods](#IOCIContainer-Methods)
    - [Notifications](#IOCIContainer-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `OCIContainer` module provides the following interface(s):

- IOCIContainer

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.OCIContainer) |
| classname | string | Class name: *OCIContainer* |
| locator | string | Library name: *libWPEFrameworkOCIContainer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IOCIContainer"></a>
## IOCIContainer Interface

<a id="IOCIContainer-Methods"></a>
### Methods

The following methods are provided by the IOCIContainer Interface:

| Method | Description |
| :-------- | :-------- |
| [annotate](#annotate) | Update container properties |
| [executeCommand](#executeCommand) | Execute the command in container |
| [getContainerInfo](#getContainerInfo) | Get the information about a specific container |
| [getContainerState](#getContainerState) | Get the state of container |
| [hibernateContainer](#hibernateContainer) | Hibernate the container |
| [listContainers](#listContainers) | Provide list of containers |
| [mount](#mount) | Mount a path in container |
| [pauseContainer](#pauseContainer) | Pause the container |
| [removeAnnotation](#removeAnnotation) | Remove container property |
| [resumeContainer](#resumeContainer) | Resume the container |
| [startContainer](#startContainer) | Start the container from bundle |
| [startContainerFromDobbySpec](#startContainerFromDobbySpec) | Start the container from dobby specification |
| [stopContainer](#stopContainer) | Stop the container |
| [unmount](#unmount) | Unmount a path in container |
| [wakeupContainer](#wakeupContainer) | Wakeup the container |

<a id="annotate"></a>
## *annotate*

Updates the specified property of the container

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.key | string | name of property |
| params.value | string | property data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | indicates whether the annotate operation was successful |
| result.errorReason | string | provides the reason for failure if any |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.OCIContainer.annotate",
    "params": {
        "containerId": "container123",
        "key": "propertyName",
        "value": "propertyValue"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.OCIContainer.annotate", "params": {"containerId": "container123", "key": "propertyName", "value": "propertyValue"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="executeCommand"></a>
## *executeCommand*

Executes the specified command within the container

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
| params.options | string | Options to be passed to the command |
| params.command | string | Command to run in the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.OCIContainer.executeCommand",
    "params": {
        "containerId": "container123",
        "options": "rw",
        "command": "/bin/bash"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.OCIContainer.executeCommand", "params": {"containerId": "container123", "options": "rw", "command": "/bin/bash"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="getContainerInfo"></a>
## *getContainerInfo*

This API retrieves detailed information about a specific container identified by its container ID.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.info | string | Detailed information about the container in JSON format |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.OCIContainer.getContainerInfo",
    "params": {
        "containerId": "container123"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.OCIContainer.getContainerInfo", "params": {"containerId": "container123"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": {
        "info": "{\\\"containerId\\\": \\\"container123\\\", \\\"name\\\": \\\"myContainer\\\", \\\"state\\\": \\\"running\\\"}",
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="getContainerState"></a>
## *getContainerState*

This API retrieves the current state of a specific container identified by its container ID.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | Current state of the container. Possible values: INVALID, STARTING, RUNNING, STOPPING, PAUSED, STOPPED, HIBERNATING, HIBERNATED, AWAKENING |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.OCIContainer.getContainerState",
    "params": {
        "containerId": "container123"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.OCIContainer.getContainerState", "params": {"containerId": "container123"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": {
        "state": "running",
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="hibernateContainer"></a>
## *hibernateContainer*

This API hibernates the specified container, saving its state and freeing up system resources.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
| params.options | string | Options to be passed to the hibernate command |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.OCIContainer.hibernateContainer",
    "params": {
        "containerId": "container123",
        "options": "rw"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.OCIContainer.hibernateContainer", "params": {"containerId": "container123", "options": "rw"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="listContainers"></a>
## *listContainers*

This API provides the list of all containers managed by the system.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.containers | string | Output list of containers in JSON format |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.OCIContainer.listContainers"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.OCIContainer.listContainers"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": {
        "containers": "[{\\\"containerId\\\": \\\"container123\\\", \\\"name\\\": \\\"myContainer\\\", \\\"state\\\": \\\"running\\\"}]",
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="mount"></a>
## *mount*

Mounts the specified source path to the target path inside the container

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.source | string | path source to mount |
| params.target | string | mount target inside container |
| params.type | string | type of mounting |
| params.options | string | options for mounting |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | indicates whether the mount operation was successful |
| result.errorReason | string | provides the reason for failure if any |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.OCIContainer.mount",
    "params": {
        "containerId": "container123",
        "source": "/host/path",
        "target": "/container/path",
        "type": "bind",
        "options": "rw"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.OCIContainer.mount", "params": {"containerId": "container123", "source": "/host/path", "target": "/container/path", "type": "bind", "options": "rw"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="pauseContainer"></a>
## *pauseContainer*

This API pauses the specified container, temporarily halting its execution.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.OCIContainer.pauseContainer",
    "params": {
        "containerId": "container123"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.OCIContainer.pauseContainer", "params": {"containerId": "container123"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="removeAnnotation"></a>
## *removeAnnotation*

Removes the specified property from the container

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.key | string | name of property |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | indicates whether the remove annotation operation was successful |
| result.errorReason | string | provides the reason for failure if any |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.OCIContainer.removeAnnotation",
    "params": {
        "containerId": "container123",
        "key": "propertyName"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.OCIContainer.removeAnnotation", "params": {"containerId": "container123", "key": "propertyName"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="resumeContainer"></a>
## *resumeContainer*

This API resumes the specified container, allowing it to continue execution.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.OCIContainer.resumeContainer",
    "params": {
        "containerId": "container123"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.OCIContainer.resumeContainer", "params": {"containerId": "container123"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="startContainer"></a>
## *startContainer*

This API starts a container using the specified application bundle.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
| params.bundlePath | string | Path of the application bundle |
| params.command | string | Command to run in the container |
| params.westerosSocket | string | Westeros socket the container needs to connect to |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer | File descriptor associated with the container |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.OCIContainer.startContainer",
    "params": {
        "containerId": "container123",
        "bundlePath": "/path/to/bundle",
        "command": "/bin/bash",
        "westerosSocket": "/tmp/westeros.sock"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.OCIContainer.startContainer", "params": {"containerId": "container123", "bundlePath": "/path/to/bundle", "command": "/bin/bash", "westerosSocket": "/tmp/westeros.sock"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "result": {
        "descriptor": 5,
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="startContainerFromDobbySpec"></a>
## *startContainerFromDobbySpec*

This API starts a container using the specified dobby specification.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
| params.dobbySpec | string | Dobby specification as a JSON string |
| params.command | string | Command to run in the container |
| params.westerosSocket | string | Westeros socket the container needs to connect to |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer | File descriptor associated with the container |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.OCIContainer.startContainerFromDobbySpec",
    "params": {
        "containerId": "container123",
        "dobbySpec": "{\\\"containerId\\\": \\\"container123\\\", \\\"name\\\": \\\"myContainer\\\"}",
        "command": "/bin/bash",
        "westerosSocket": "/tmp/westeros.sock"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.OCIContainer.startContainerFromDobbySpec", "params": {"containerId": "container123", "dobbySpec": "{\\\"containerId\\\": \\\"container123\\\", \\\"name\\\": \\\"myContainer\\\"}", "command": "/bin/bash", "westerosSocket": "/tmp/westeros.sock"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": {
        "descriptor": 5,
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="stopContainer"></a>
## *stopContainer*

This API stops the specified container, either forcefully or gracefully based on the 'force' parameter.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
| params.force | bool | Mention forceful or graceful termination of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.OCIContainer.stopContainer",
    "params": {
        "containerId": "container123",
        "force": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.OCIContainer.stopContainer", "params": {"containerId": "container123", "force": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="unmount"></a>
## *unmount*

Unmounts the specified target path from the container

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.target | string | path to unmount from container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | indicates whether the unmount operation was successful |
| result.errorReason | string | provides the reason for failure if any |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "method": "org.rdk.OCIContainer.unmount",
    "params": {
        "containerId": "container123",
        "target": "/container/path"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.OCIContainer.unmount", "params": {"containerId": "container123", "target": "/container/path"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="wakeupContainer"></a>
## *wakeupContainer*

This API wakes up the specified container, restoring it from a hibernated state.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |
| result.errorReason | string | Provides the reason for failure if the operation was not successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.OCIContainer.wakeupContainer",
    "params": {
        "containerId": "container123"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.OCIContainer.wakeupContainer", "params": {"containerId": "container123"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": {
        "success": true,
        "errorReason": "Failed to unmount path"
    }
}
```

<a id="IOCIContainer-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IOCIContainer Interface:

| Event | Description |
| :-------- | :-------- |
| [onContainerFailed](#onContainerFailed) | Notifies failure in container execution, only triggered for states start, stop, hibernate, wakeup. |
| [onContainerStarted](#onContainerStarted) | Notifies container is started |
| [onContainerStateChanged](#onContainerStateChanged) | Notifies state change of container |
| [onContainerStopped](#onContainerStopped) | Notifies container is stopped |

<a id="onContainerFailed"></a>
## *onContainerFailed*

This event is triggered when the container has failed during execution.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container that failed |
| params.name | string | Name of the container |
| params.error | integer | Error code indicating the failure reason |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.OCIContainer.onContainerFailed",
    "params": {
        "containerId": "container123",
        "name": "myContainer",
        "error": 1
    }
}
```

<a id="onContainerStarted"></a>
## *onContainerStarted*

This event is triggered when the container has successfully started.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container that started |
| params.name | string | Name of the container |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.OCIContainer.onContainerStarted",
    "params": {
        "containerId": "container123",
        "name": "myContainer"
    }
}
```

<a id="onContainerStateChanged"></a>
## *onContainerStateChanged*

This event is triggered when the state of the container changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container whose state changed |
| params.state | string | New state of the container. Possible values: INVALID, STARTING, RUNNING, STOPPING, PAUSED, STOPPED, HIBERNATING, HIBERNATED, AWAKENING |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "method": "org.rdk.OCIContainer.onContainerStateChanged",
    "params": {
        "containerId": "container123",
        "state": "running"
    }
}
```

<a id="onContainerStopped"></a>
## *onContainerStopped*

This event is triggered when the container has successfully stopped.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of the container that stopped |
| params.name | string | Name of the container |
| params.exitCode | integer | Exit code of the container process |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.OCIContainer.onContainerStopped",
    "params": {
        "containerId": "container123",
        "name": "myContainer",
        "exitCode": 0
    }
}
```

