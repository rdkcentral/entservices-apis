<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_NativeJS_API"></a>
# NativeJS API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

NativeJS interface for Thunder framework.

(Defined with INativeJS in [INativeJS.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/INativeJS.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the NativeJS interface (version 1.0.0). It includes detailed specification about its methods provided.

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

NativeJS JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the NativeJS interface:

NativeJS interface methods:

| Method | Description |
| :-------- | :-------- |
| [createApplication](#method_createApplication) | Create a NativeJS application |
| [runApplication](#method_runApplication) | run a NativeJS application |
| [runJavaScript](#method_runJavaScript) | run a NativeJS code |
| [getApplications](#method_getApplications) | Get details of existing plugin |
| [terminateApplication](#method_terminateApplication) | Destroy a running NativeJS application |

<a id="method_createApplication"></a>
## *createApplication [<sup>method</sup>](#head_Methods)*

Create a NativeJS application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.options | string | mandatory | Additional options for creating the application |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | This should have the id of the created application |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.createApplication",
  "params": {
    "options": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_runApplication"></a>
## *runApplication [<sup>method</sup>](#head_Methods)*

run a NativeJS application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | The ID for the application to run |
| params.url | string | mandatory | URL for the application to run |

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
  "method": "<callsign>.1.runApplication",
  "params": {
    "id": 0,
    "url": "..."
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

<a id="method_runJavaScript"></a>
## *runJavaScript [<sup>method</sup>](#head_Methods)*

run a NativeJS code.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | The ID for the code to run |
| params.code | string | mandatory |  |

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
  "method": "<callsign>.1.runJavaScript",
  "params": {
    "id": 0,
    "code": "..."
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

<a id="method_getApplications"></a>
## *getApplications [<sup>method</sup>](#head_Methods)*

Get details of existing plugin.

### Parameters

This method takes no parameters.

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
  "method": "<callsign>.1.getApplications"
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

<a id="method_terminateApplication"></a>
## *terminateApplication [<sup>method</sup>](#head_Methods)*

Destroy a running NativeJS application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | The ID of the application to destroy |

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
  "method": "<callsign>.1.terminateApplication",
  "params": {
    "id": 0
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

