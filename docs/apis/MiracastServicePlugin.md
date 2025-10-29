<!-- Generated automatically, DO NOT EDIT! -->
<a id="MiracastService_Plugin"></a>
# MiracastService Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Miracast/IMiracastService.h)**

A MiracastService plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `MiracastService` plugin provides an interface for MiracastService.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MiracastService) |
| classname | string | Class name: *MiracastService* |
| locator | string | Library name: *libWPEFrameworkMiracastService.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the MiracastService plugin:

MiracastService interface methods:

| Method | Description |
| :-------- | :-------- |
| [acceptClientConnection](#acceptClientConnection) | To accept or reject new client connection requests for the Miracast feature |
| [getEnable](#getEnable) | To get the enable status of the Miracast feature |
| [setEnable](#setEnable) | To enable or disable the Miracast feature |
| [setP2PBackendDiscovery](#setP2PBackendDiscovery) | Sets the status of the MiracastService backend discovery |
| [stopClientConnection](#stopClientConnection) | To abort the ongoing connection after accepted connection request |
| [updatePlayerState](#updatePlayerState) | Update the Miracast Player State to the Miracast Service Plugin |

<a id="acceptClientConnection"></a>
## *acceptClientConnection*

To accept or reject new client connection requests for the Miracast feature

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestStatus | string | It should be "Accept" or "Reject" |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.MiracastService.acceptClientConnection",
    "params": {
        "requestStatus": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.MiracastService.acceptClientConnection", "params": {"requestStatus": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="getEnabled"></a>
## *getEnabled*

To get the enable status of the Miracast feature

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Is the MiracastService discovery enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.MiracastService.getEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.MiracastService.getEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "enabled": true,
        "success": true
    }
}
```

<a id="setEnabled"></a>
## *setEnabled*

To enable or disable the Miracast feature

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.MiracastService.setEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.MiracastService.setEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="setP2PBackendDiscovery"></a>
## *setP2PBackendDiscovery*

Sets the status of the MiracastService backend discovery

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.MiracastService.setP2PBackendDiscovery",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.MiracastService.setP2PBackendDiscovery", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="stopClientConnection"></a>
## *stopClientConnection*

To abort the ongoing connection after accepted connection request

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.MiracastService.stopClientConnection",
    "params": {
        "mac": "",
        "name": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.MiracastService.stopClientConnection", "params": {"mac": "", "name": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "message": "",
        "success": true
    }
}
```

<a id="updatePlayerState"></a>
## *updatePlayerState*

Update the Miracast Player State to the Miracast Service Plugin

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.state | string | Player state to be updated |
| params.reason_code | int | Reason code for the player state update |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | Result |  |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.MiracastService.updatePlayerState",
    "params": {
        "mac": "",
        "state": "PLAYER_STATE_IDLE",
        "reason_code": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.MiracastService.updatePlayerState", "params": {"mac": "", "state": "PLAYER_STATE_IDLE", "reason_code": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "message": "",
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the MiracastService plugin:

MiracastService interface events:

| Event | Description |
| :-------- | :-------- |
| [onClientConnectionError](#onClientConnectionError) | It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming |
| [onClientConnectionRequest](#onClientConnectionRequest) | Triggered when the Miracast Service plugin receives a new connection request from a client |
| [onLaunchRequest](#onLaunchRequest) | Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player |

<a id="onClientConnectionError"></a>
## *onClientConnectionError*

It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
| params.error_code | string |  |
| params.reason | string | Reason for the connection failure |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.MiracastService.onClientConnectionError",
    "params": {
        "mac": "",
        "name": "",
        "error_code": "",
        "reason": "REASON_CODE_SUCCESS"
    }
}
```

<a id="onClientConnectionRequest"></a>
## *onClientConnectionRequest*

Triggered when the Miracast Service plugin receives a new connection request from a client

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.MiracastService.onClientConnectionRequest",
    "params": {
        "mac": "",
        "name": ""
    }
}
```

<a id="onLaunchRequest"></a>
## *onLaunchRequest*

Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device_parameters | DeviceParameters |  |
| params.device_parameters.source_dev_ip | string | IP Address of Source Device |
| params.device_parameters.source_dev_mac | string | MAC Address of Source Device |
| params.device_parameters.source_dev_name | string | Name of Source Device |
| params.device_parameters.sink_dev_ip | string | IP Address of Sink Device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.MiracastService.onLaunchRequest",
    "params": {
        "source_dev_ip": "",
        "source_dev_mac": "",
        "source_dev_name": "",
        "sink_dev_ip": ""
    }
}
```
