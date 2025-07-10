<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.MiracastService_Plugin"></a>
# MiracastService Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/MiracastService/CHANGELOG.md)**

A MiracastService plugin for Thunder framework.

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

The `MiracastService` plugin provides an interface for MiracastService.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.MiracastService) |
| classname | string | Class name: *MiracastService* |
| locator | string | Library name: *libWPEFrameworkMiracastService.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the MiracastService plugin:

MiracastService interface methods:

| Method | Description |
| :-------- | :-------- |
| [acceptClientConnection](#method.acceptClientConnection) | To accept or reject new client connection requests for the Miracast feature |
| [getEnabled](#method.getEnabled) | To get the enable status of the Miracast feature |
| [setEnabled](#method.setEnabled) | To enable or disable the Miracast feature |
| [setP2PBackendDiscovery](#method.setP2PBackendDiscovery) | Sets the status of the MiracastService backend discovery |
| [stopClientConnection](#method.stopClientConnection) | To abort the ongoing connection after accepted connection request |
| [updatePlayerState](#method.updatePlayerState) | Update the Miracast Player State to the Miracast Service Plugin |

<a id="method.acceptClientConnection"></a>
## *acceptClientConnection [<sup>method</sup>](#head.Methods)*

To accept or reject new client connection requests for the Miracast feature

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestStatus | string | It should be "Accept" or "Reject" |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result | - |
| result.result.message | string | message */ /* @brief reason for success or failure |
| result.result.success | bool | - |

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

<a id="method.getEnabled"></a>
## *getEnabled [<sup>method</sup>](#head.Methods)*

To get the enable status of the Miracast feature

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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

<a id="method.setEnabled"></a>
## *setEnabled [<sup>method</sup>](#head.Methods)*

To enable or disable the Miracast feature

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result | - |
| result.result.message | string | message */ /* @brief reason for success or failure |
| result.result.success | bool | - |

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

<a id="method.setP2PBackendDiscovery"></a>
## *setP2PBackendDiscovery [<sup>method</sup>](#head.Methods)*

Sets the status of the MiracastService backend discovery

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the MiracastService discovery enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result | - |
| result.result.message | string | message */ /* @brief reason for success or failure |
| result.result.success | bool | - |

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

<a id="method.stopClientConnection"></a>
## *stopClientConnection [<sup>method</sup>](#head.Methods)*

To abort the ongoing connection after accepted connection request

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result | - |
| result.result.message | string | message */ /* @brief reason for success or failure |
| result.result.success | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.MiracastService.stopClientConnection",
    "params": {
        "clientMac": "",
        "clientName": ""
    }
}
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

<a id="method.updatePlayerState"></a>
## *updatePlayerState [<sup>method</sup>](#head.Methods)*

Update the Miracast Player State to the Miracast Service Plugin

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.state | PlayerState | Player state to be updated |
| params.reason_code | int | Reason code for the player state update |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result | - |
| result.result.message | string | message */ /* @brief reason for success or failure |
| result.result.success | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.MiracastService.updatePlayerState",
    "params": {
        "clientMac": "",
        "playerState": "PLAYER_STATE_IDLE",
        "reasonCode": 0
    }
}
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the MiracastService plugin:

MiracastService interface events:

| Event | Description |
| :-------- | :-------- |
| [onClientConnectionError](#event.onClientConnectionError) | It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming |
| [onClientConnectionRequest](#event.onClientConnectionRequest) | Triggered when the Miracast Service plugin receives a new connection request from a client |
| [onLaunchRequest](#event.onLaunchRequest) | Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player |

<a id="event.onClientConnectionError"></a>
## *onClientConnectionError [<sup>event</sup>](#head.Notifications)*

It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mac | string | MacAddress of the client device |
| params.name | string | Name of the client device |
| params.error_code | string | - |
| params.reason | ReasonCode | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.MiracastService.onClientConnectionError",
    "params": {
        "clientMac": "",
        "clientName": "",
        "reasonCode": "",
        "reasonDescription": "REASON_CODE_SUCCESS"
    }
}
```

<a id="event.onClientConnectionRequest"></a>
## *onClientConnectionRequest [<sup>event</sup>](#head.Notifications)*

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
        "clientMac": "",
        "clientName": ""
    }
}
```

<a id="event.onLaunchRequest"></a>
## *onLaunchRequest [<sup>event</sup>](#head.Notifications)*

Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device_parameters | DeviceParameters | - |
| params.device_parameters.sourceDeviceIP | string | source_dev_ip */ /* @brief IP Address of Source Device |
| params.device_parameters.sourceDeviceMac | string | source_dev_mac */ /* @brief MAC Address of Source Device |
| params.device_parameters.sourceDeviceName | string | source_dev_name */ /* @brief Name of Source Device |
| params.device_parameters.sinkDeviceIP | string | sink_dev_ip */ /* @brief IP Address of Sink Device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.MiracastService.onLaunchRequest",
    "params": {
        "deviceParameters": {
            "sourceDeviceIP": "",
            "sourceDeviceMac": "",
            "sourceDeviceName": "",
            "sinkDeviceIP": ""
        }
    }
}
```
