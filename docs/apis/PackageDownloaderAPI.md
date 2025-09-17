<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PackageDownloader_API"></a>
# PackageDownloader API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PackageDownloader interface for Thunder framework.

(Defined with IPackageDownloader in [IAppPackageManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppPackageManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PackageDownloader interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

PackageDownloader JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PackageDownloader interface:

PackageDownloader interface methods:

| Method | Description |
| :-------- | :-------- |
| [download](#method_download) | Download |
| [pause](#method_pause) | Pause |
| [resume](#method_resume) | Resume |
| [cancel](#method_cancel) | Cancel |
| [delete](#method_delete) | Delete |
| [progress](#method_progress) | Delete |
| [getStorageDetails](#method_getStorageDetails) | GetStorageDetails |
| [rateLimit](#method_rateLimit) | RateLimit |

<a id="method_download"></a>
## *download [<sup>method</sup>](#head_Methods)*

Download.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.url | string | mandatory | Download url |
| params.options | object | mandatory | Download options |
| params.options.priority | boolean | mandatory | Priority |
| params.options.retries | integer | mandatory | Retries |
| params.options.rateLimit | integer | mandatory | RateLimit |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.downloadId | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.download",
  "params": {
    "url": "...",
    "options": {
      "priority": false,
      "retries": 0,
      "rateLimit": 0
    }
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "downloadId": "..."
  }
}
```

<a id="method_pause"></a>
## *pause [<sup>method</sup>](#head_Methods)*

Pause.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.downloadId | string | mandatory | Download id |

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
  "method": "<callsign>.1.pause",
  "params": {
    "downloadId": "..."
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

<a id="method_resume"></a>
## *resume [<sup>method</sup>](#head_Methods)*

Resume.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.downloadId | string | mandatory | Download id |

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
  "method": "<callsign>.1.resume",
  "params": {
    "downloadId": "..."
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

<a id="method_cancel"></a>
## *cancel [<sup>method</sup>](#head_Methods)*

Cancel.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.downloadId | string | mandatory | Download id |

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
  "method": "<callsign>.1.cancel",
  "params": {
    "downloadId": "..."
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

<a id="method_delete"></a>
## *delete [<sup>method</sup>](#head_Methods)*

Delete.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.fileLocator | string | mandatory | FileLocator |

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
  "method": "<callsign>.1.delete",
  "params": {
    "fileLocator": "..."
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

<a id="method_progress"></a>
## *progress [<sup>method</sup>](#head_Methods)*

Delete.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.downloadId | string | mandatory | Download id |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.progress | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.progress",
  "params": {
    "downloadId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "progress": 0
  }
}
```

<a id="method_getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head_Methods)*

GetStorageDetails.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.quotaKb | string | mandatory |  |
| result.usedKb | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getStorageDetails"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "quotaKb": "...",
    "usedKb": "..."
  }
}
```

<a id="method_rateLimit"></a>
## *rateLimit [<sup>method</sup>](#head_Methods)*

RateLimit.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.downloadId | string | mandatory | Download id |
| params.limit | integer | mandatory | Limit |

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
  "method": "<callsign>.1.rateLimit",
  "params": {
    "downloadId": "...",
    "limit": 0
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PackageDownloader interface:

PackageDownloader interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppDownloadStatus](#notification_onAppDownloadStatus) | Signal changes on the status |

<a id="notification_onAppDownloadStatus"></a>
## *onAppDownloadStatus [<sup>notification</sup>](#head_Notifications)*

Signal changes on the status.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.jsonresponse | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppDownloadStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppDownloadStatus",
  "params": {
    "jsonresponse": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppDownloadStatus``.

