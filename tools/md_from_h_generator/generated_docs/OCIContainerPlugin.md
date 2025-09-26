<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.OCIContainer_Plugin"></a>
# OCIContainer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/OCIContainer/CHANGELOG.md)**

A OCIContainer plugin for Thunder framework.

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

The `OCIContainer` plugin provides an interface for OCIContainer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.OCIContainer) |
| classname | string | Class name: *OCIContainer* |
| locator | string | Library name: *libWPEFrameworkOCIContainer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the OCIContainer plugin:

OCIContainer interface methods:

| Method | Description |
| :-------- | :-------- |
| [annotate](#method.annotate) |  |
| [executeCommand](#method.executeCommand) |  |
| [getContainerInfo](#method.getContainerInfo) |  |
| [getContainerState](#method.getContainerState) |  |
| [hibernateContainer](#method.hibernateContainer) |  |
| [listContainers](#method.listContainers) |  |
| [mount](#method.mount) |  |
| [pauseContainer](#method.pauseContainer) |  |
| [removeAnnotation](#method.removeAnnotation) |  |
| [resumeContainer](#method.resumeContainer) |  |
| [startContainer](#method.startContainer) |  |
| [startContainerFromDobbySpec](#method.startContainerFromDobbySpec) |  |
| [stopContainer](#method.stopContainer) |  |
| [unmount](#method.unmount) |  |
| [wakeupContainer](#method.wakeupContainer) |  |

<a id="method.annotate"></a>
## *annotate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.OCIContainer.annotate",
    "params": {
        "containerId": "",
        "key": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.OCIContainer.annotate", "params": {"containerId": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.executeCommand"></a>
## *executeCommand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params?.options | string | <sup>(optional)</sup>options to be passed to command |
| params.command | string | command to run in container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.OCIContainer.executeCommand",
    "params": {
        "containerId": "",
        "options": "",
        "command": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.OCIContainer.executeCommand", "params": {"containerId": "", "options": "", "command": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.getContainerInfo"></a>
## *getContainerInfo [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.info | string |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.OCIContainer.getContainerInfo",
    "params": {
        "containerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.OCIContainer.getContainerInfo", "params": {"containerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "info": "",
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.getContainerState"></a>
## *getContainerState [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.OCIContainer.getContainerState",
    "params": {
        "containerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.OCIContainer.getContainerState", "params": {"containerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "state": "INVALID",
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.hibernateContainer"></a>
## *hibernateContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.options | string | options to be passed to command |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.OCIContainer.hibernateContainer",
    "params": {
        "containerId": "",
        "options": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.OCIContainer.hibernateContainer", "params": {"containerId": "", "options": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.listContainers"></a>
## *listContainers [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.containers | string | /json - string |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.OCIContainer.listContainers"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.OCIContainer.listContainers"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "containers": "",
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.mount"></a>
## *mount [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.source | string | path source to mount |
| params.target | string | mount target inside container |
| params.type | string | type of mounting |
| params.options | string | options to be passed to command |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.OCIContainer.mount",
    "params": {
        "containerId": "",
        "source": "",
        "target": "",
        "type": "",
        "options": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.OCIContainer.mount", "params": {"containerId": "", "source": "", "target": "", "type": "", "options": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.pauseContainer"></a>
## *pauseContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.OCIContainer.pauseContainer",
    "params": {
        "containerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.OCIContainer.pauseContainer", "params": {"containerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.removeAnnotation"></a>
## *removeAnnotation [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.OCIContainer.removeAnnotation",
    "params": {
        "containerId": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.OCIContainer.removeAnnotation", "params": {"containerId": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.resumeContainer"></a>
## *resumeContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.OCIContainer.resumeContainer",
    "params": {
        "containerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.OCIContainer.resumeContainer", "params": {"containerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.startContainer"></a>
## *startContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.bundlePath | string | path of application bundle |
| params?.command | string | <sup>(optional)</sup>command to run in container |
| params?.westerosSocket | string | <sup>(optional)</sup>Westeros socket container need to connect |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.OCIContainer.startContainer",
    "params": {
        "containerId": "",
        "bundlePath": "",
        "command": "",
        "westerosSocket": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.OCIContainer.startContainer", "params": {"containerId": "", "bundlePath": "", "command": "", "westerosSocket": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "descriptor": 0,
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.startContainerFromDobbySpec"></a>
## *startContainerFromDobbySpec [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.dobbySpec | string | dobby specification as json string |
| params?.command | string | <sup>(optional)</sup>command to run in container |
| params?.westerosSocket | string | <sup>(optional)</sup>Westeros socket container need to connect |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.descriptor | integer |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.OCIContainer.startContainerFromDobbySpec",
    "params": {
        "containerId": "",
        "dobbySpec": "",
        "command": "",
        "westerosSocket": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.OCIContainer.startContainerFromDobbySpec", "params": {"containerId": "", "dobbySpec": "", "command": "", "westerosSocket": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "descriptor": 0,
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.stopContainer"></a>
## *stopContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params?.force | bool | <sup>(optional)</sup>Metion forceful or graceful termination of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.OCIContainer.stopContainer",
    "params": {
        "containerId": "",
        "force": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.OCIContainer.stopContainer", "params": {"containerId": "", "force": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.unmount"></a>
## *unmount [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.target | string | mount target inside container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.OCIContainer.unmount",
    "params": {
        "containerId": "",
        "target": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.OCIContainer.unmount", "params": {"containerId": "", "target": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```

<a id="method.wakeupContainer"></a>
## *wakeupContainer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.OCIContainer.wakeupContainer",
    "params": {
        "containerId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.OCIContainer.wakeupContainer", "params": {"containerId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "success": true,
        "errorReason": ""
    }
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the OCIContainer plugin:

OCIContainer interface events:

| Event | Description |
| :-------- | :-------- |
| [onContainerFailed](#event.onContainerFailed) | Notifies failure in container execution |
| [onContainerStarted](#event.onContainerStarted) | Notifies container is started |
| [onContainerStateChanged](#event.onContainerStateChanged) | Notifies state change of container |
| [onContainerStopped](#event.onContainerStopped) | Notifies container is stopped |

<a id="event.onContainerFailed"></a>
## *onContainerFailed [<sup>event</sup>](#head.Notifications)*

Notifies failure in container execution

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.name | string |  |
| params.error | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.OCIContainer.onContainerFailed",
    "params": {
        "containerId": "",
        "name": "",
        "error": 0
    }
}
```

<a id="event.onContainerStarted"></a>
## *onContainerStarted [<sup>event</sup>](#head.Notifications)*

Notifies container is started

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.name | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.OCIContainer.onContainerStarted",
    "params": {
        "containerId": "",
        "name": ""
    }
}
```

<a id="event.onContainerStateChanged"></a>
## *onContainerStateChanged [<sup>event</sup>](#head.Notifications)*

Notifies state change of container

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.state | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.OCIContainer.onContainerStateChanged",
    "params": {
        "containerId": "",
        "state": "INVALID"
    }
}
```

<a id="event.onContainerStopped"></a>
## *onContainerStopped [<sup>event</sup>](#head.Notifications)*

Notifies container is stopped

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.containerId | string | Identifier of container |
| params.name | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.OCIContainer.onContainerStopped",
    "params": {
        "containerId": "",
        "name": ""
    }
}
```
