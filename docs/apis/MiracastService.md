<!-- Generated automatically, DO NOT EDIT! -->
<a id="MiracastService_Module"></a>
# MiracastService Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/MiracastService/IMiracastService.h)**

A MiracastService module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IMiracastService](#IMiracastService)
    - [Methods](#IMiracastService-Methods)
    - [Notifications](#IMiracastService-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `MiracastService` module provides the following interface(s):

- IMiracastService

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MiracastService) |
| classname | string | Class name: *MiracastService* |
| locator | string | Library name: *libWPEFrameworkMiracastService.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IMiracastService"></a>
## IMiracastService Interface

<a id="IMiracastService-Methods"></a>
### Methods

The following methods are provided by the IMiracastService Interface:

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

Accepts or rejects new client connection requests for the Miracast feature. If accepted, the Miracast Service plugin will establish a connection with the client device and start streaming. If rejected, the Miracast Service plugin will send a rejection response to the client device.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestStatus | string | It should be "Accept" or "Reject" |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Contains the result of the operation, including a message and a success flag |
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
        "requestStatus": "Accept"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.MiracastService.acceptClientConnection", "params": {"requestStatus": "Accept"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": "{ message: \"Backend discovery status updated\", success: true }"
}
```

<a id="getEnable"></a>
## *getEnable*

Retrieves the enable status of the Miracast feature on the device. If enabled, the device is discoverable by other Miracast devices and can accept connection requests. If disabled, the device is not discoverable and will reject any incoming connection requests.

### Events Triggered
None
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
    "method": "org.rdk.MiracastService.getEnable"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.MiracastService.getEnable"}' http://127.0.0.1:9998/jsonrpc
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

<a id="setEnable"></a>
## *setEnable*

Enables or disables the Miracast feature on the device. When enabled, the device will be discoverable by other Miracast devices and can accept connection requests. When disabled, the device will not be discoverable and will reject any incoming connection requests.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Result of the set enable operation |
| result.result.message | string | reason for success or failure |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.MiracastService.setEnable",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.MiracastService.setEnable", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": "{ message: \"Backend discovery status updated\", success: true }"
}
```

<a id="setP2PBackendDiscovery"></a>
## *setP2PBackendDiscovery*

Sets the status of the MiracastService backend discovery. When enabled, the MiracastService will perform backend discovery to find available Miracast devices. When disabled, the backend discovery will be turned off.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService backend discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Contains the result of the operation, including a message and a success flag |
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
    "result": "{ message: \"Backend discovery status updated\", success: true }"
}
```

<a id="stopClientConnection"></a>
## *stopClientConnection*

Aborts the ongoing connection after accepted connection request. This can be used to stop the streaming from the source device to the sink device.

### Events Triggered
None
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
| result.result | object | Contains the result of the operation, including a message and a success flag |
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
        "mac": "00:11:22:33:44:55",
        "name": "John's iPhone"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.MiracastService.stopClientConnection", "params": {"mac": "00:11:22:33:44:55", "name": "John's iPhone"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": "{ message: \"Backend discovery status updated\", success: true }"
}
```

<a id="updatePlayerState"></a>
## *updatePlayerState*

Updates the Miracast Player State to the Miracast Service Plugin. This can be used to inform the plugin about the current state of the player, such as whether it is playing, paused, or stopped.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.state | string | Player state to be updated. Possible values: IDLE, INITIATED, INPROGRESS, PLAYING, STOPPED |
| params.reason_code | int | Reason code for the player state update |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Contains the result of the operation, including a message and a success flag |
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
        "mac": "00:11:22:33:44:55",
        "state": "PLAYER_STATE_PLAYING",
        "reason_code": 200
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.MiracastService.updatePlayerState", "params": {"mac": "00:11:22:33:44:55", "state": "PLAYER_STATE_PLAYING", "reason_code": 200}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": "{ message: \"Backend discovery status updated\", success: true }"
}
```

<a id="IMiracastService-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IMiracastService Interface:

| Event | Description |
| :-------- | :-------- |
| [onClientConnectionError](#onClientConnectionError) | It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming |
| [onClientConnectionRequest](#onClientConnectionRequest) | Triggered when the Miracast Service plugin receives a new connection request from a client |
| [onLaunchRequest](#onLaunchRequest) | Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player |

<a id="onClientConnectionError"></a>
## *onClientConnectionError*

Notifies listeners that the connection to the source streaming device could not be established, providing the failing client's identity along with a reason code and description of the underlying P2P or streaming error.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
| params.error_code | string | Error code for the connection failure |
| params.reason | string | Description of the reason for the connection failure. Possible values: SUCCESS, P2P_CONNECT_FAILURE, P2P_GROUP_NEGOTIATION_FAILURE, P2P_GROUP_FORMATION_FAILURE, GENERIC_FAILURE |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.MiracastService.onClientConnectionError",
    "params": {
        "mac": "00:11:22:33:44:55",
        "name": "John's iPhone",
        "error_code": 1001,
        "reason": "Authentication failed"
    }
}
```

<a id="onClientConnectionRequest"></a>
## *onClientConnectionRequest*

Notifies listeners of an incoming Miracast connection request, identifying the requesting client so the application can prompt the user to accept or reject it via acceptClientConnection.

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
        "mac": "00:11:22:33:44:55",
        "name": "John's iPhone"
    }
}
```

<a id="onLaunchRequest"></a>
## *onLaunchRequest*

Triggered when the Miracast Service plugin needs the Resident Application or MiracastWidget to launch the Miracast Player, providing the source and sink device parameters required to start streaming.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device_parameters | object | Contains Source and Sink Device related properties |
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
    "params": "{ sourceDeviceIP: \"192.168.1.2\", sinkDeviceIP: \"192.168.1.3\" }"
}
```

