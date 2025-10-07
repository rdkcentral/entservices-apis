<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_ScreenCapture_API"></a>
# ScreenCapture API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

ScreenCapture interface for Thunder framework.

(Defined with IScreenCapture in [IScreenCapture.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IScreenCapture.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the ScreenCapture interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

ScreenCapture JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the ScreenCapture interface:

ScreenCapture interface methods:

| Method | Description |
| :-------- | :-------- |
| [uploadScreenCapture](#method_uploadScreenCapture) | Takes a screenshot and uploads it to the specified URL |

<a id="method_uploadScreenCapture"></a>
## *uploadScreenCapture [<sup>method</sup>](#head_Methods)*

Takes a screenshot and uploads it to the specified URL.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.url | string | mandatory | - in - string |
| params.callGUID | string | mandatory | - in - string |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.uploadScreenCapture",
  "params": {
    "url": "...",
    "callGUID": "..."
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the ScreenCapture interface:

ScreenCapture interface events:

| Notification | Description |
| :-------- | :-------- |
| [uploadComplete](#notification_uploadComplete) | Triggered after uploading a screen capture |

<a id="notification_uploadComplete"></a>
## *uploadComplete [<sup>notification</sup>](#head_Notifications)*

Triggered after uploading a screen capture.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | boolean | mandatory | - in - boolean |
| params.message | string | mandatory | - in - string |
| params.call_guid | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "uploadComplete",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.uploadComplete",
  "params": {
    "status": false,
    "message": "...",
    "call_guid": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.uploadComplete``.

