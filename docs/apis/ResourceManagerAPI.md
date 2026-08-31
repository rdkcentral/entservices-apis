<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_ResourceManager_API"></a>
# ResourceManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

ResourceManager interface for Thunder framework.

(Defined with IResourceManager in [IResourceManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IResourceManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the ResourceManager interface (version 1.0.0). It includes detailed specification about its methods provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

ResourceManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the ResourceManager interface:

ResourceManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [setAVBlocked](#method_setAVBlocked) | Adds/removes the application with the given callsign to/from the AV blacklist |
| [getBlockedAVApplications](#method_getBlockedAVApplications) | Gets a list of blacklisted clients |
| [reserveTTSResource](#method_reserveTTSResource) | Reserves the Text To Speech resource for a specified client |
| [reserveTTSResourceForApps](#method_reserveTTSResourceForApps) | Reserves the Text To Speech resource for specified clients |

<a id="method_setAVBlocked"></a>
## *setAVBlocked [<sup>method</sup>](#head_Methods)*

Adds/removes the application with the given callsign to/from the AV blacklist.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.appid | string | mandatory | The application identifier (callsign) |
| params.blocked | boolean | mandatory | Whether to block (true) or unblock (false) AV access for the application |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The result of the operation |
| result.success | boolean | mandatory | *...* |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setAVBlocked",
  "params": {
    "appid": "...",
    "blocked": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getBlockedAVApplications"></a>
## *getBlockedAVApplications [<sup>method</sup>](#head_Methods)*

Gets a list of blacklisted clients.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.clients | array | mandatory | Iterator containing the list of blocked applications |
| result.clients[#] | string | mandatory | *...* |
| result.success | boolean | mandatory | Indicates whether the operation succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBlockedAVApplications"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "clients": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_reserveTTSResource"></a>
## *reserveTTSResource [<sup>method</sup>](#head_Methods)*

Reserves the Text To Speech resource for a specified client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.appid | string | mandatory | The application identifier (callsign) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The result of the reservation operation |
| result.success | boolean | mandatory | *...* |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.reserveTTSResource",
  "params": {
    "appid": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_reserveTTSResourceForApps"></a>
## *reserveTTSResourceForApps [<sup>method</sup>](#head_Methods)*

Reserves the Text To Speech resource for specified clients.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.appids | array | mandatory | Iterator containing the list of application identifiers (callsigns) |
| params.appids[#] | string | mandatory | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The result of the reservation operation |
| result.success | boolean | mandatory | *...* |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.reserveTTSResourceForApps",
  "params": {
    "appids": [
      "..."
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

