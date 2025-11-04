<!-- Generated automatically, DO NOT EDIT! -->
<a id="SystemMode_Plugin"></a>
# SystemMode Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SystemMode/ISystemMode.h)**

A SystemMode plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `SystemMode` plugin provides an interface for SystemMode.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemMode) |
| classname | string | Class name: *SystemMode* |
| locator | string | Library name: *libWPEFrameworkSystemMode.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the SystemMode plugin:

SystemMode interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [clientActivated](#clientActivated) | To put client plugin entry in map. | NA |
| [clientDeactivated](#clientDeactivated) | To put client plugin entry in map. | NA |
| [getState](#getState) | Gets the current state for a given system property | NA |
| [requestState](#requestState) | Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return. | NA |

<a id="clientActivated"></a>
## *clientActivated*

To put client plugin entry in map.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | callsign of client. |
| params.systemMode | string | The system mode. |
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
        "callsign": "",
        "systemMode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SystemMode.clientActivated", "params": {"callsign": "", "systemMode": ""}}' http://127.0.0.1:9998/jsonrpc
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

To put client plugin entry in map.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | callsign of client. |
| params.systemMode | string | The system mode. |
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
        "callsign": "",
        "systemMode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SystemMode.clientDeactivated", "params": {"callsign": "", "systemMode": ""}}' http://127.0.0.1:9998/jsonrpc
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

Gets the current state for a given system property

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.systemMode | string | The system mode. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | state |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SystemMode.getState",
    "params": {
        "systemMode": "DEVICE_OPTIMIZE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SystemMode.getState", "params": {"systemMode": "DEVICE_OPTIMIZE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "state": "GAME"
    }
}
```

<a id="requestState"></a>
## *requestState*

Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.systemMode | string | The system mode. |
| params.state | string | state |
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
        "systemMode": "DEVICE_OPTIMIZE",
        "state": "GAME"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SystemMode.requestState", "params": {"systemMode": "DEVICE_OPTIMIZE", "state": "GAME"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


