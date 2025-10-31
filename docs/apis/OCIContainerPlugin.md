<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.OCIContainer_Plugin"></a>
# OCIContainer Plugin

A org.rdk.OCIContainer plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `OCIContainer` plugin allows for control of OCI containers using the Dobby hypervisor.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.OCIContainer*) |
| classname | string | Class name: *org.rdk.OCIContainer* |
| locator | string | Library name: *libWPEFrameworkOCIContainer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.OCIContainer plugin:

OCIContainer interface methods:

| Method | Description |
| :-------- | :-------- |
| [listContainers](#method.listContainers) | Lists all running OCI containers Dobby knows about |
| [getContainerInfo](#method.getContainerInfo) | Gets information about a running container such as CPU, memory, and GPU usage (GPU not supported on some products) |
| [getContainerState](#method.getContainerState) | Gets the state of a currently running container |
| [startContainer](#method.startContainer) | Starts a new container from an existing OCI bundle |
| [startContainerFromDobbySpec](#method.startContainerFromDobbySpec) | Starts a new container from a legacy Dobby JSON specification |
| [stopContainer](#method.stopContainer) | Stops a currently running container |
| [pauseContainer](#method.pauseContainer) | Pauses a currently running container |
| [resumeContainer](#method.resumeContainer) | Resumes a previously paused container |
| [hibernateContainer](#method.hibernateContainer) | Hibernate the container |
| [wakeupContainer](#method.wakeupContainer) | Wakeup the container |
| [executeCommand](#method.executeCommand) | Executes a command inside a running container |
| [annotate](#method.annotate) | Update the container properties of running container |
| [removeAnnotation](#method.removeAnnotation) | Remove the container properties of the given container Id |
| [mount](#method.mount) | Mount a path in container |
| [unmount](#method.unmount) | Unmount a path in container |


<a name="method.listContainers"></a>
## *listContainers [<sup>method</sup>](#head.Methods)*

Lists all running OCI containers Dobby knows about.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.containers | array | A list of running containers |
| result.containers[#] | object |  |
| result.containers[#].Descriptor | integer | The container descriptor |
| result.containers[#].Id | string | The container Id |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.listContainers"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "containers": [
            {
                "Descriptor": 91,
                "Id": "com.bskyb.epgui"
            }
        ],
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.getContainerInfo"></a>
## *getContainerInfo [<sup>method</sup>](#head.Methods)*

Gets information about a running container such as CPU, memory, and GPU usage (GPU not supported on some products).

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.info | object | Information about the specified container |
| result.info.cpu | object | CPU information |
| result.info.cpu.usage | object | The amount of CPU usage |
| result.info.cpu.usage.percpu | array | The usage for each CPU |
| result.info.cpu.usage.percpu[#] | integer |  |
| result.info.cpu.usage.total | integer | The combined usage for all CPUs |
| result.info.id | string | The ID of a container as returned by `listContainers` |
| result.info.memory | object | The amount of memory being used by the container |
| result.info.memory.user | object | User memory statistics |
| result.info.memory.user.failcnt | integer | The fail count; the number of times that the usage counter hit its limit |
| result.info.memory.user.limit | integer | The memory limit |
| result.info.memory.user.max | integer | The maximum amount of memory used |
| result.info.memory.user.usage | integer | The current memory being used |
| result.info.pids | array | A list of container process IDs |
| result.info.pids[#] | integer |  |
| result.info.state | string | The container state (must be one of the following: *Invalid*, *Starting*, *Running*, *Stopping*, *Paused*, *Stopped*, *Hibernating*, *Hibernated*, *Awakening*) |
| result.info.timestamp | integer | The timestamp for container information |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.getContainerInfo",
    "params": {
        "containerId": "com.bskyb.epgui"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "info": {
            "cpu": {
                "usage": {
                    "percpu": [
                        83134464184
                    ],
                    "total": 224025108679
                }
            },
            "id": "com.bskyb.epgui",
            "memory": {
                "user": {
                    "failcnt": 0,
                    "limit": 230686720,
                    "max": 38555648,
                    "usage": 28655616
                }
            },
            "pids": [
                7644
            ],
            "state": "Running",
            "timestamp": 6849968158125
        },
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.getContainerState"></a>
## *getContainerState [<sup>method</sup>](#head.Methods)*

Gets the state of a currently running container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | The container state (must be one of the following: *Invalid*, *Starting*, *Running*, *Stopping*, *Paused*, *Stopped*, *Hibernating*, *Hibernated*, *Awakening*) |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.getContainerState",
    "params": {
        "containerId": "com.bskyb.epgui"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "state": "Running",
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.startContainer"></a>
## *startContainer [<sup>method</sup>](#head.Methods)*

Starts a new container from an existing OCI bundle.

### Events

| Event | Description |
| :-------- | :-------- |
| [onContainerStarted](#event.onContainerStarted) | Triggers when a new container starts running. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.bundlePath | string | Path to the OCI bundle containing the rootfs and config to use to create the container |
| params?.command | string | <sup>*(optional)*</sup> Command to execute |
| params?.westerosSocket | string | <sup>*(optional)*</sup> Path to a Westeros socket to mount inside the container |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer | The container descriptor |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.startContainer",
    "params": {
        "containerId": "com.bskyb.epgui",
        "bundlePath": "/containers/myBundle",
        "command": "command",
        "westerosSocket": "/usr/mySocket"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "descriptor": 91,
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.startContainerFromDobbySpec"></a>
## *startContainerFromDobbySpec [<sup>method</sup>](#head.Methods)*

Starts a new container from a legacy Dobby JSON specification.

### Events

| Event | Description |
| :-------- | :-------- |
| [onContainerStarted](#event.onContainerStarted) | Triggers when a new container starts running. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.dobbySpec | string | Dobby specification to use for the container |
| params?.command | string | <sup>*(optional)*</sup> Command to execute |
| params?.westerosSocket | string | <sup>*(optional)*</sup> Path to a Westeros socket to mount inside the container |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer | The container descriptor |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.startContainerFromDobbySpec",
    "params": {
        "containerId": "com.bskyb.epgui",
        "dobbySpec": "/containers/dobbySpec",
        "command": "command",
        "westerosSocket": "/usr/mySocket"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "descriptor": 91,
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.stopContainer"></a>
## *stopContainer [<sup>method</sup>](#head.Methods)*

Stops a currently running container.

### Events

| Event | Description |
| :-------- | :-------- |
| [onContainerStopped](#event.onContainerStopped) | Triggers when the container stops running. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params?.force | boolean | <sup>*(optional)*</sup> If `true`, force stop the container using the `SIGKILL` signal). Otherwise, use the `SIGTERM` signal. The default value if no value is specified is `false` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.stopContainer",
    "params": {
        "containerId": "com.bskyb.epgui",
        "force": true
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.pauseContainer"></a>
## *pauseContainer [<sup>method</sup>](#head.Methods)*

Pauses a currently running container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.pauseContainer",
    "params": {
        "containerId": "com.bskyb.epgui"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.resumeContainer"></a>
## *resumeContainer [<sup>method</sup>](#head.Methods)*

Resumes a previously paused container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.resumeContainer",
    "params": {
        "containerId": "com.bskyb.epgui"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.hibernateContainer"></a>
## *hibernateContainer [<sup>method</sup>](#head.Methods)*

Hibernate the container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.options | string | Hibernation options - Optional parameter |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.hibernateContainer",
    "params": {
        "containerId": "com.bskyb.epgui",
        "options": " "
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.wakeupContainer"></a>
## *wakeupContainer [<sup>method</sup>](#head.Methods)*

Wakeup the container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.wakeupContainer",
    "params": {
        "containerId": "com.bskyb.epgui"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.executeCommand"></a>
## *executeCommand [<sup>method</sup>](#head.Methods)*

Executes a command inside a running container. The path to the executable must resolve within the container's namespace.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params?.options | string | <sup>*(optional)*</sup> Global options for crun `exec` command |
| params.command | string | Command to execute |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.executeCommand",
    "params": {
        "containerId": "com.bskyb.epgui",
        "options": "--cwd=PATH",
        "command": "command"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.annotate"></a>
## *annotate [<sup>method</sup>](#head.Methods)*

Update the container properties of running container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.key | string | Updating the property key of the given container ID |
| params.value | string | Updating the value of the property key of the given container ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.annotate",
    "params": {
        "containerId": "com.bskyb.epgui",
        "key": "fireboltState",
        "value": "foreground"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.removeAnnotation"></a>
## *removeAnnotation [<sup>method</sup>](#head.Methods)*

Remove the container properties of the given container Id.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.key | string | Updating the property key of the given container ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.removeAnnotation",
    "params": {
        "containerId": "com.bskyb.epgui",
        "key": "fireboltState"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.mount"></a>
## *mount [<sup>method</sup>](#head.Methods)*

Mount a path in container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.source | string | Source path to mount |
| params.target | string | Destination path to mount |
| params.type | string | The type of mount to be performed |
| params.options | string | The options is a list of mount options that modify the behavior of the mount |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.mount",
    "params": {
        "containerId": "com.bskyb.epgui",
        "source": "/tmp/testdisplay",
        "target": "/tmp/westeros",
        "type": "bind",
        "options": "rbind, nosuid, nodev, ro"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="method.unmount"></a>
## *unmount [<sup>method</sup>](#head.Methods)*

Unmount a path in container.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.target | string | Destination path to mount |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |
| result.errorReason | string | A user-defined description explaining the reason for the failure. if success error field will be empty string |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.OCIContainer.unmount",
    "params": {
        "containerId": "com.bskyb.epgui",
        "target": "/tmp/westeros"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true,
        "errorReason": "..."
    }
}
```

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.OCIContainer plugin:

OCIContainer interface events:

| Event | Description |
| :-------- | :-------- |
| [onContainerStarted](#event.onContainerStarted) | Triggered when a new container has started running |
| [onContainerStopped](#event.onContainerStopped) | Triggered when the container has stopped running |
| [onContainerFailed](#event.onContainerFailed) | Triggered when the container execution is failed |
| [OnContainerStateChanged](#event.OnContainerStateChanged) | Triggered when the container state has changed |


<a name="event.onContainerStarted"></a>
## *onContainerStarted [<sup>event</sup>](#head.Notifications)*

Triggered when a new container has started running.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.name | string | Name of the Container |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onContainerStarted",
    "params": {
        "containerId": "com.bskyb.epgui",
        "name": "com.bskyb.epgui"
    }
}
```

<a name="event.onContainerStopped"></a>
## *onContainerStopped [<sup>event</sup>](#head.Notifications)*

Triggered when the container has stopped running.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.name | string | Name of the Container |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onContainerStopped",
    "params": {
        "containerId": "com.bskyb.epgui",
        "name": "com.bskyb.epgui"
    }
}
```

<a name="event.onContainerFailed"></a>
## *onContainerFailed [<sup>event</sup>](#head.Notifications)*

Triggered when the container execution is failed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.name | string | Name of the Container |
| params.error | integer | Failure error code |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onContainerFailed",
    "params": {
        "containerId": "com.bskyb.epgui",
        "name": "com.bskyb.epgui",
        "error": 0
    }
}
```

<a name="event.OnContainerStateChanged"></a>
## *OnContainerStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the container state has changed.This event is only fired for Started, Stopped, Hibernated, and Awoken state transitions.

**Note:** When a container is awakening, the event is triggered with the "Running" state rather than "Awakening".

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | The ID of a container as returned by `listContainers` |
| params.state | string | The container state (must be one of the following: *Running*, *Stopped*, *Hibernated*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.OnContainerStateChanged",
    "params": {
        "containerId": "com.bskyb.epgui",
        "state": "Running"
    }
}
```

