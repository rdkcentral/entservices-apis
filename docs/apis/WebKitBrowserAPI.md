<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_WebKit_Browser_API"></a>
# WebKit Browser API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

WebKitBrowser interface for Thunder framework.

(Defined by [WebKitBrowser.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the WebKitBrowser interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

WebKitBrowser JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the WebKitBrowser interface:

WebKitBrowser interface methods:

| Method | Description |
| :-------- | :-------- |
| [delete](#method_delete) | Removes contents of a directory from the persistent storage |

<a id="method_delete"></a>
## *delete [<sup>method</sup>](#head_Methods)*

Removes contents of a directory from the persistent storage.

### Description

Use this method to recursively delete contents of a directory

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.path | string | mandatory | Path to directory (within the persistent storage) to delete contents of |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_UNKNOWN_KEY``` | The given path was incorrect |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.delete",
  "params": {
    "path": ".cache/wpe/disk-cache"
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

<a id="head_Properties"></a>
# Properties

The following properties are provided by the WebKitBrowser interface:

WebKitBrowser interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [languages](#property_languages) | read/write | User preferred languages |
| [headers](#property_headers) | read/write | Headers to send on all requests that the browser makes |

StateControl interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [state](#property_state) | read/write | Running state of the service |

<a id="property_languages"></a>
## *languages [<sup>property</sup>](#head_Properties)*

Provides access to the user preferred languages.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | User preferred languages |
| (property)[#] | string | mandatory | *...* |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | User preferred languages |
| (property)[#] | string | mandatory | *...* |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.languages"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "en-US"
  ]
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.languages",
  "params": [
    "en-US"
  ]
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_headers"></a>
## *headers [<sup>property</sup>](#head_Properties)*

Provides access to the headers to send on all requests that the browser makes.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Headers to send on all requests that the browser makes |
| (property)[#] | object | mandatory | *...* |
| (property)[#]?.name | string | optional | Header name |
| (property)[#]?.value | string | optional | Header value |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Headers to send on all requests that the browser makes |
| (property)[#] | object | mandatory | *...* |
| (property)[#]?.name | string | optional | Header name |
| (property)[#]?.value | string | optional | Header value |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.headers"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "X-Forwarded-For",
      "value": "::1"
    }
  ]
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.headers",
  "params": [
    {
      "name": "X-Forwarded-For",
      "value": "::1"
    }
  ]
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_state"></a>
## *state [<sup>property</sup>](#head_Properties)*

Provides access to the running state of the service.

Also see: [statechange](#event_statechange)

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Running state of the service (must be one of the following: *resumed, suspended*) |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Running state of the service (must be one of the following: *resumed, suspended*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "suspended"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.state",
  "params": "suspended"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the WebKitBrowser interface:

WebKitBrowser interface events:

| Notification | Description |
| :-------- | :-------- |
| [bridgequery](#notification_bridgequery) <sup>obsolete</sup> | A Base64 encoded JSON message from legacy $badger bridge |

StateControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [statechange](#notification_statechange) | Signals a state change of the service |

<a id="notification_bridgequery"></a>
## *bridgequery [<sup>notification</sup>](#head_Notifications)*

A Base64 encoded JSON message from legacy $badger bridge.

> ``bridgequery`` is an alternative name for this notification. This name is **obsolete**. It is not recommended for use in new implementations.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | string | mandatory | *...* |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "bridgequery",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.bridgequery",
  "params": "..."
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.bridgequery``.

<a id="notification_statechange"></a>
## *statechange [<sup>notification</sup>](#head_Notifications)*

Signals a state change of the service.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.suspended | boolean | mandatory | Determines if the service has entered suspended state (true) or resumed state (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "statechange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.statechange",
  "params": {
    "suspended": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.statechange``.

