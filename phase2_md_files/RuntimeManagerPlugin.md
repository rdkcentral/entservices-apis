<!-- Generated automatically, DO NOT EDIT! -->
<a id="RuntimeManager_Plugin"></a>
# RuntimeManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RuntimeManager)**

A RuntimeManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
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

<a id="Methods"></a>
# Methods

The following methods are provided by the RuntimeManager plugin:

RuntimeManager interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [annotate](#annotate) | annotates are sent to Dobby for recording | NA |
| [getInfo](#getInfo) | get info of the application | NA |
| [hibernate](#hibernate) | Hibernate the application | NA |
| [kill](#kill) | Kill the application | NA |
| [mount](#mount) | mounts a new host directory/device inside container | NA |
| [resume](#resume) | Resume the application | NA |
| [run](#run) | Run the application | NA |
| [suspend](#suspend) | Suspend the application | NA |
| [terminate](#terminate) | Terminate the application | NA |
| [unmount](#unmount) | unmounts a new host directory/device inside container | NA |
| [wake](#wake) | Wake the application to given state | NA |

<a id="annotate"></a>
## *annotate [<sup>method</sup>](#Methods)*

annotates are sent to Dobby for recording

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
| params.key | string | set a dictionary of value of key for running containers |
| params.value | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.RuntimeManager.annotate",
    "params": {
        "appInstanceId": "",
        "key": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RuntimeManager.annotate", "params": {"appInstanceId": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="getInfo"></a>
## *getInfo [<sup>method</sup>](#Methods)*

get info of the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.info | string | This should contain information like RAM, CPU usage, GPU memory, and other stats, come as json string format |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.RuntimeManager.getInfo",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RuntimeManager.getInfo", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "info": ""
    }
}
```

<a id="hibernate"></a>
## *hibernate [<sup>method</sup>](#Methods)*

Hibernate the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.RuntimeManager.hibernate",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RuntimeManager.hibernate", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="kill"></a>
## *kill [<sup>method</sup>](#Methods)*

Kill the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.RuntimeManager.kill",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.RuntimeManager.kill", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="mount"></a>
## *mount [<sup>method</sup>](#Methods)*

mounts a new host directory/device inside container

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.RuntimeManager.mount"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RuntimeManager.mount"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="resume"></a>
## *resume [<sup>method</sup>](#Methods)*

Resume the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.RuntimeManager.resume",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.RuntimeManager.resume", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="run"></a>
## *run [<sup>method</sup>](#Methods)*

Run the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | App identifier for the application/container |
| params.appInstanceId | string | App identifier for the application/container |
| params.userId | integer | groupid used to represent a group |
| params.groupId | integer |  |
| params?.ports | IValueIterator | <sup>(optional)</sup>array of socket ports to allow |
| params?.ports[#] | uint32_t | <sup>(optional)</sup> |
| params?.paths | IStringIterator | <sup>(optional)</sup>paths contains an additional set of files and directories to map into the container |
| params?.paths[#] | string | <sup>(optional)</sup> |
| params?.debugSettings | IStringIterator | <sup>(optional)</sup>can include additional ports to open for gdb and other settings for debugging |
| params?.debugSettings[#] | string | <sup>(optional)</sup> |
| params.runtimeConfigObject | RuntimeConfig |  |
| params.runtimeConfigObject.dial | bool |  |
| params.runtimeConfigObject.wanLanAccess | bool |  |
| params.runtimeConfigObject.thunder | bool |  |
| params.runtimeConfigObject.systemMemoryLimit | integer |  |
| params.runtimeConfigObject.gpuMemoryLimit | integer |  |
| params.runtimeConfigObject.envVariables | std::string |  |
| params.runtimeConfigObject.userId | integer |  |
| params.runtimeConfigObject.groupId | integer |  |
| params.runtimeConfigObject.dataImageSize | integer |  |
| params.runtimeConfigObject.resourceManagerClientEnabled | bool |  |
| params.runtimeConfigObject.dialId | std::string |  |
| params.runtimeConfigObject.command | std::string |  |
| params.runtimeConfigObject.appType | std::string |  |
| params.runtimeConfigObject.appPath | std::string |  |
| params.runtimeConfigObject.runtimePath | std::string |  |
| params.runtimeConfigObject.logFilePath | std::string |  |
| params.runtimeConfigObject.logFileMaxSize | integer |  |
| params.runtimeConfigObject.logLevels | std::string | json array of strings |
| params.runtimeConfigObject.mapi | bool |  |
| params.runtimeConfigObject.fkpsFiles | std::string | json array of strings |
| params.runtimeConfigObject.fireboltVersion | std::string |  |
| params.runtimeConfigObject.enableDebugger | bool |  |
| params.runtimeConfigObject.unpackedPath | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RuntimeManager.run",
    "params": {
        "appId": "",
        "appInstanceId": "",
        "userId": 0,
        "groupId": 0,
        "ports": [
            0
        ],
        "paths": [
            ""
        ],
        "debugSettings": [
            ""
        ],
        "runtimeConfigObject": {
            "dial": true,
            "wanLanAccess": true,
            "thunder": true,
            "systemMemoryLimit": 0,
            "gpuMemoryLimit": 0,
            "envVariables": "",
            "userId": 0,
            "groupId": 0,
            "dataImageSize": 0,
            "resourceManagerClientEnabled": true,
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": 0,
            "logLevels": "",
            "mapi": true,
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": true,
            "unpackedPath": ""
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RuntimeManager.run", "params": {"appId": "", "appInstanceId": "", "userId": 0, "groupId": 0, "ports": [0], "paths": [""], "debugSettings": [""], "runtimeConfigObject": {"dial": true, "wanLanAccess": true, "thunder": true, "systemMemoryLimit": 0, "gpuMemoryLimit": 0, "envVariables": "", "userId": 0, "groupId": 0, "dataImageSize": 0, "resourceManagerClientEnabled": true, "dialId": "", "command": "", "appType": "", "appPath": "", "runtimePath": "", "logFilePath": "", "logFileMaxSize": 0, "logLevels": "", "mapi": true, "fkpsFiles": "", "fireboltVersion": "", "enableDebugger": true, "unpackedPath": ""}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="suspend"></a>
## *suspend [<sup>method</sup>](#Methods)*

Suspend the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RuntimeManager.suspend",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RuntimeManager.suspend", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="terminate"></a>
## *terminate [<sup>method</sup>](#Methods)*

Terminate the application

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RuntimeManager.terminate",
    "params": {
        "appInstanceId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RuntimeManager.terminate", "params": {"appInstanceId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="unmount"></a>
## *unmount [<sup>method</sup>](#Methods)*

unmounts a new host directory/device inside container

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RuntimeManager.unmount"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RuntimeManager.unmount"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="wake"></a>
## *wake [<sup>method</sup>](#Methods)*

Wake the application to given state

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | App identifier for the application/container |
| params.runtimeState | string | state of runtime application/container |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.RuntimeManager.wake",
    "params": {
        "appInstanceId": "",
        "runtimeState": "RUNTIME_STATE_UNKNOWN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.RuntimeManager.wake", "params": {"appInstanceId": "", "runtimeState": "RUNTIME_STATE_UNKNOWN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```



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
## *onFailure [<sup>event</sup>](#Notifications)*

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
    "id": 11,
    "method": "org.rdk.RuntimeManager.onFailure",
    "params": {
        "appInstanceId": "",
        "error": ""
    }
}
```

<a id="onStarted"></a>
## *onStarted [<sup>event</sup>](#Notifications)*

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
    "id": 12,
    "method": "org.rdk.RuntimeManager.onStarted",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onStateChanged"></a>
## *onStateChanged [<sup>event</sup>](#Notifications)*

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
    "id": 13,
    "method": "org.rdk.RuntimeManager.onStateChanged",
    "params": {
        "appInstanceId": "",
        "state": "RUNTIME_STATE_UNKNOWN"
    }
}
```

<a id="onTerminated"></a>
## *onTerminated [<sup>event</sup>](#Notifications)*

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
    "id": 14,
    "method": "org.rdk.RuntimeManager.onTerminated",
    "params": {
        "appInstanceId": ""
    }
}
```
