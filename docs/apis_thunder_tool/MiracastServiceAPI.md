<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_MiracastService_API"></a>
# MiracastService API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

MiracastService interface for Thunder framework.

(Defined with IMiracastService in [IMiracastService.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IMiracastService.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the MiracastService interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

MiracastService JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the MiracastService interface:

MiracastService interface methods:

| Method | Description |
| :-------- | :-------- |
| [setEnable](#method_setEnable) | To enable or disable the Miracast feature |
| [getEnable](#method_getEnable) | To get the enable status of the Miracast feature |
| [acceptClientConnection](#method_acceptClientConnection) | To accept or reject new client connection requests for the Miracast feature |
| [stopClientConnection](#method_stopClientConnection) | To abort the ongoing connection after accepted connection request |
| [updatePlayerState](#method_updatePlayerState) | Update the Miracast Player State to the Miracast Service Plugin |
| [setP2PBackendDiscovery](#method_setP2PBackendDiscovery) | Sets the status of the MiracastService backend discovery |

<a id="method_setEnable"></a>
## *setEnable [<sup>method</sup>](#head_Methods)*

To enable or disable the Miracast feature.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the MiracastService discovery enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEnable",
  "params": {
    "enabled": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_getEnable"></a>
## *getEnable [<sup>method</sup>](#head_Methods)*

To get the enable status of the Miracast feature.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.enabled | boolean | mandatory | Is the MiracastService discovery enabled or not |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getEnable"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "enabled": false,
    "success": false
  }
}
```

<a id="method_acceptClientConnection"></a>
## *acceptClientConnection [<sup>method</sup>](#head_Methods)*

To accept or reject new client connection requests for the Miracast feature.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.requestStatus | string | mandatory | It should be "Accept" or "Reject" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.acceptClientConnection",
  "params": {
    "requestStatus": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_stopClientConnection"></a>
## *stopClientConnection [<sup>method</sup>](#head_Methods)*

To abort the ongoing connection after accepted connection request.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mac | string | mandatory | MacAddress of the client device |
| params.name | string | mandatory | Name of the client device |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stopClientConnection",
  "params": {
    "mac": "...",
    "name": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_updatePlayerState"></a>
## *updatePlayerState [<sup>method</sup>](#head_Methods)*

Update the Miracast Player State to the Miracast Service Plugin.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mac | string | mandatory | MacAddress of the client device |
| params.state | string | mandatory | Player state to be updated (must be one of the following: *IDLE, INITIATED, INPROGRESS, PLAYING, STOPPED*) |
| params.reason_code | integer | mandatory | Reason code for the player state update |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.updatePlayerState",
  "params": {
    "mac": "...",
    "state": "INITIATED",
    "reason_code": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="method_setP2PBackendDiscovery"></a>
## *setP2PBackendDiscovery [<sup>method</sup>](#head_Methods)*

Sets the status of the MiracastService backend discovery.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the MiracastService backend discovery enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.message | string | mandatory | Reason for success or failure |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setP2PBackendDiscovery",
  "params": {
    "enabled": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "message": "...",
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the MiracastService interface:

MiracastService interface events:

| Notification | Description |
| :-------- | :-------- |
| [onClientConnectionRequest](#notification_onClientConnectionRequest) | Triggered when the Miracast Service plugin receives a new connection request from a client |
| [onClientConnectionError](#notification_onClientConnectionError) | It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming |
| [onLaunchRequest](#notification_onLaunchRequest) | Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player |

<a id="notification_onClientConnectionRequest"></a>
## *onClientConnectionRequest [<sup>notification</sup>](#head_Notifications)*

Triggered when the Miracast Service plugin receives a new connection request from a client.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mac | string | mandatory | MacAddress of the client device |
| params.name | string | mandatory | Name of the client device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onClientConnectionRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onClientConnectionRequest",
  "params": {
    "mac": "...",
    "name": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onClientConnectionRequest``.

<a id="notification_onClientConnectionError"></a>
## *onClientConnectionError [<sup>notification</sup>](#head_Notifications)*

It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mac | string | mandatory | MacAddress of the client device |
| params.name | string | mandatory | Name of the client device |
| params.error_code | string | mandatory |  |
| params.reason | string | mandatory |  (must be one of the following: *GENERIC_FAILURE, P2P_CONNECT_FAILURE, P2P_GROUP_FORMATION_FAILURE, P2P_GROUP_NEGOTIATION_FAILURE, SUCCESS*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onClientConnectionError",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onClientConnectionError",
  "params": {
    "mac": "...",
    "name": "...",
    "error_code": "...",
    "reason": "P2P_CONNECT_FAILURE"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onClientConnectionError``.

<a id="notification_onLaunchRequest"></a>
## *onLaunchRequest [<sup>notification</sup>](#head_Notifications)*

Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.device_parameters | object | mandatory |  |
| params.device_parameters.source_dev_ip | string | mandatory | IP Address of Source Device |
| params.device_parameters.source_dev_mac | string | mandatory | MAC Address of Source Device |
| params.device_parameters.source_dev_name | string | mandatory | Name of Source Device |
| params.device_parameters.sink_dev_ip | string | mandatory | IP Address of Sink Device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onLaunchRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onLaunchRequest",
  "params": {
    "device_parameters": {
      "source_dev_ip": "...",
      "source_dev_mac": "...",
      "source_dev_name": "...",
      "sink_dev_ip": "..."
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onLaunchRequest``.

