<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.SystemMode_Plugin"></a>
# SystemMode Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/SystemMode/CHANGELOG.md)**

A SystemMode plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `SystemMode` plugin provides an interface for SystemMode.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemMode) |
| classname | string | Class name: *SystemMode* |
| locator | string | Library name: *libWPEFrameworkSystemMode.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the SystemMode plugin:

SystemMode interface methods:

| Method | Description |
| :-------- | :-------- |
| [clientActivated](#method.clientActivated) | To put client plugin entry in map. |
| [clientDeactivated](#method.clientDeactivated) | To put client plugin entry in map. |
| [getState](#method.getState) | Gets the current state for a given system property |
| [requestState](#method.requestState) | Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return. |
| [request](#method.request) |  |

<a id="method.clientActivated"></a>
## *clientActivated [<sup>method</sup>](#head.Methods)*

To put client plugin entry in map.

### Events
No events are associated with this method.
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

<a id="method.clientDeactivated"></a>
## *clientDeactivated [<sup>method</sup>](#head.Methods)*

To put client plugin entry in map.

### Events
No events are associated with this method.
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

<a id="method.getState"></a>
## *getState [<sup>method</sup>](#head.Methods)*

Gets the current state for a given system property

### Events
No events are associated with this method.
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

<a id="method.requestState"></a>
## *requestState [<sup>method</sup>](#head.Methods)*

Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return.

### Events
No events are associated with this method.
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

<a id="method.request"></a>
## *request [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.newState | string |  |
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
    "method": "org.rdk.SystemMode.request",
    "params": {
        "newState": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SystemMode.request", "params": {"newState": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


