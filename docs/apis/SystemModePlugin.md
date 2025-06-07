<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ISystemMode_Plugin"></a>
# ISystemMode Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/ISystemMode/CHANGELOG.md)**

A ISystemMode plugin for Thunder framework.

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

The `ISystemMode` plugin provides an interface for ISystemMode.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *ISystemMode*) |
| classname | string | Class name: *ISystemMode* |
| locator | string | Library name: *libWPEFrameworkISystemMode.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the ISystemMode plugin:

ISystemMode interface methods:

| Method | Description |
| :-------- | :-------- |
| [ClientActivated](#method.ClientActivated) | To put client plugin entry in map. |
| [ClientDeactivated](#method.ClientDeactivated) | To put client plugin entry in map. |
| [GetState](#method.GetState) | Gets the current state for a given system property |
| [RequestState](#method.RequestState) | Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return. |

<a id="method.ClientActivated"></a>
## *ClientActivated [<sup>method</sup>](#head.Methods)*

To put client plugin entry in map.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.callsign | string | callsign of client. |
| params.systemMode | string | The system mode. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISystemMode.ClientActivated",
    "params": {
        "callsign": "",
        "systemMode": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.ClientDeactivated"></a>
## *ClientDeactivated [<sup>method</sup>](#head.Methods)*

To put client plugin entry in map.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.callsign | string | callsign of client. |
| params.systemMode | string | The system mode. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISystemMode.ClientDeactivated",
    "params": {
        "callsign": "",
        "systemMode": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetState"></a>
## *GetState [<sup>method</sup>](#head.Methods)*

Gets the current state for a given system property

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.systemMode | SystemMode | The system mode. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.getStateResult | GetStateResult |  |
| result.getStateResult.state | State | state |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISystemMode.GetState",
    "params": {
        "systemMode": "DEVICE_OPTIMIZE"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "getStateResult": {
            "state": "GAME"
        }
    }
}
```
<a id="method.RequestState"></a>
## *RequestState [<sup>method</sup>](#head.Methods)*

Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.systemMode | SystemMode | The system mode. |
| params.state | State | state |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ISystemMode.RequestState",
    "params": {
        "systemMode": "DEVICE_OPTIMIZE",
        "state": "GAME"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

