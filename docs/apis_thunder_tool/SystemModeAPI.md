<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_SystemMode_API"></a>
# SystemMode API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

SystemMode interface for Thunder framework.

(Defined with ISystemMode in [ISystemMode.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ISystemMode.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the SystemMode interface (version 1.0.0). It includes detailed specification about its methods provided.

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

SystemMode JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the SystemMode interface:

SystemMode interface methods:

| Method | Description |
| :-------- | :-------- |
| [requestState](#method_requestState) | Requests a new system mode state in the device |
| [getState](#method_getState) | Gets the current state for a given system property |
| [clientActivated](#method_clientActivated) | To put client plugin entry in map |
| [clientDeactivated](#method_clientDeactivated) | To put client plugin entry in map |

<a id="method_requestState"></a>
## *requestState [<sup>method</sup>](#head_Methods)*

Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.systemMode | string | mandatory |  (must be one of the following: *device_optimize*) |
| params.state | string | mandatory |  (must be one of the following: *game, video*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.requestState",
  "params": {
    "systemMode": "device_optimize",
    "state": "game"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_getState"></a>
## *getState [<sup>method</sup>](#head_Methods)*

Gets the current state for a given system property.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.systemMode | string | mandatory |  (must be one of the following: *device_optimize*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.state | string | mandatory |  (must be one of the following: *game, video*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getState",
  "params": {
    "systemMode": "device_optimize"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "state": "game"
  }
}
```

<a id="method_clientActivated"></a>
## *clientActivated [<sup>method</sup>](#head_Methods)*

To put client plugin entry in map.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.callsign | string | mandatory |  |
| params.systemMode | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.clientActivated",
  "params": {
    "callsign": "...",
    "systemMode": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_clientDeactivated"></a>
## *clientDeactivated [<sup>method</sup>](#head_Methods)*

To put client plugin entry in map.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.callsign | string | mandatory |  |
| params.systemMode | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.clientDeactivated",
  "params": {
    "callsign": "...",
    "systemMode": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

