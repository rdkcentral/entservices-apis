<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DownloadManager_API"></a>
# DownloadManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DownloadManager interface for Thunder framework.

(Defined with IDownloadManager in [IDownloadManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDownloadManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DownloadManager interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

DownloadManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DownloadManager interface:

DownloadManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [download](#method_download) | Download Start downloading a file from a specified URL with custom options |
| [pause](#method_pause) | Pause an active download session |
| [resume](#method_resume) | Resume a paused download session |
| [cancel](#method_cancel) | Cancel an ongoing download session |
| [delete](#method_delete) | Delete a downloaded file from the system using its locator path |
| [progress](#method_progress) | Progress Query current download progress |
| [rateLimit](#method_rateLimit) | RateLimit Set rate limiting for a specific download session |

<a id="method_download"></a>
## *download [<sup>method</sup>](#head_Methods)*

Download Start downloading a file from a specified URL with custom options.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.url | string | mandatory | URL from which the file is to be downloaded |
| params.options | object | mandatory | Options controlling download behavior |
| params.options.priority | boolean | mandatory | Adds the download request to either a priority queue (true) or regular queue (false) |
| params.options.retries | integer | mandatory | Retries Number of retry attempts allowed for failed downloads (the default retries is 2) |
| params.options.rateLimit | integer | mandatory | RateLimit Maximum bandwidth allowed for the download (bytes per second) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Output parameter that returns the assigned download ID |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.download",
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
  "result": "..."
}
```

<a id="method_pause"></a>
## *pause [<sup>method</sup>](#head_Methods)*

Pause an active download session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadId | string | mandatory | Unique identifier of the download to pause |

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
  "method": "<callsign>.pause",
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

Resume a paused download session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadId | string | mandatory | Unique identifier of the download to resume |

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
  "method": "<callsign>.resume",
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

Cancel an ongoing download session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadId | string | mandatory | Unique identifier of the download to cancel |

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
  "method": "<callsign>.cancel",
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

Delete a downloaded file from the system using its locator path.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.fileLocator | string | mandatory | File path or locator of the file to be deleted |

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
  "method": "<callsign>.delete",
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

Progress Query current download progress.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadId | string | mandatory | Unique identifier of the download |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Output parameter returning percentage completed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.progress",
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
  "result": 0
}
```

<a id="method_rateLimit"></a>
## *rateLimit [<sup>method</sup>](#head_Methods)*

RateLimit Set rate limiting for a specific download session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadId | string | mandatory | Unique identifier of the download |
| params.limit | integer | mandatory | Maximum bandwidth in bytes per second (0 = unlimited) |

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
  "method": "<callsign>.rateLimit",
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

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the DownloadManager interface:

DownloadManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppDownloadStatus](#notification_onAppDownloadStatus) | OnAppDownloadStatus Callback for status changes of app downloads |

<a id="notification_onAppDownloadStatus"></a>
## *onAppDownloadStatus [<sup>notification</sup>](#head_Notifications)*

OnAppDownloadStatus Callback for status changes of app downloads.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.downloadStatus | string | mandatory | : [JSON string] Download status of a queued download request, includes downloadId, fileLocator, failReason (enum) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "downloadStatus": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppDownloadStatus``.

