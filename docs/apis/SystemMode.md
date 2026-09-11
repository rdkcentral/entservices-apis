<!-- Generated automatically, DO NOT EDIT! -->
<a id="SystemMode_Module"></a>
# SystemMode Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SystemMode/ISystemMode.h)**

A SystemMode module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ISystemMode](#ISystemMode)
    - [Methods](#ISystemMode-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `SystemMode` module provides the following interface(s):

- ISystemMode

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemMode) |
| classname | string | Class name: *SystemMode* |
| locator | string | Library name: *libWPEFrameworkSystemMode.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ISystemMode"></a>
## ISystemMode Interface

<a id="ISystemMode-Methods"></a>
### Methods

The following methods are provided by the ISystemMode Interface:

| Method | Description |
| :-------- | :-------- |
| [clientActivated](#clientActivated) | Records the activation of a client plugin for a specific system mode. |
| [clientDeactivated](#clientDeactivated) | Records the deactivation of a client plugin for a specific system mode. |
| [getState](#getState) | Gets the current state for a given system property |
| [requestState](#requestState) | Requests a new system mode state in the device. Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return. |

<a id="clientActivated"></a>
## *clientActivated*

Invoked by the SystemMode service to notify that a client plugin has been activated. Components implementing this interface should record the activation of the client plugin for the specified system mode.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The callsign of the client plugin being activated. |
| params.systemMode | string | The system mode for which the client plugin is being activated. |
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
    "method": "org.rdk.SystemMode.clientActivated",
    "params": {
        "callsign": "com.example.client",
        "systemMode": "device_optimize"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SystemMode.clientActivated", "params": {"callsign": "com.example.client", "systemMode": "device_optimize"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="clientDeactivated"></a>
## *clientDeactivated*

Invoked by the SystemMode service to notify that a client plugin has been deactivated. Components implementing this interface should remove the activation record of the client plugin for the specified system mode.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The callsign of the client plugin being deactivated. |
| params.systemMode | string | The system mode for which the client plugin is being deactivated. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SystemMode.clientDeactivated",
    "params": {
        "callsign": "com.example.client",
        "systemMode": "device_optimize"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SystemMode.clientDeactivated", "params": {"callsign": "com.example.client", "systemMode": "device_optimize"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="getState"></a>
## *getState*

Invoked by the SystemMode service to retrieve the current state of a given system mode. Components implementing this interface should return the current state of the requested system mode.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.systemMode | string | Indicates the system mode whose current state is being queried. Possible values: device_optimize |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | The current state of the specified system mode. Possible values: video, game |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SystemMode.getState",
    "params": {
        "systemMode": "device_optimize"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SystemMode.getState", "params": {"systemMode": "device_optimize"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "state": "video"
    }
}
```

<a id="requestState"></a>
## *requestState*

Invoked by the SystemMode service to request a new state for a given system mode. Components implementing this interface should asynchronously adjust their internal behavior, resource usage, or performance characteristics to match the requested optimization state.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.systemMode | string | Indicates the system mode for which the state is being requested. Possible values: device_optimize |
| params.state | string | Indicates the requested state. Possible values: video, game |
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
    "method": "org.rdk.SystemMode.requestState",
    "params": {
        "systemMode": "device_optimize",
        "state": "video"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SystemMode.requestState", "params": {"systemMode": "device_optimize", "state": "video"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

