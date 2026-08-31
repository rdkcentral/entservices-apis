<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_FirmwareDownload_API"></a>
# FirmwareDownload API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

FirmwareDownload interface for Thunder framework.

(Defined with IFirmwareDownload in [IFirmwareDownload.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IFirmwareDownload.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the FirmwareDownload interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

FirmwareDownload JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the FirmwareDownload interface:

FirmwareDownload interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDownloadedFirmwareInfo](#method_getDownloadedFirmwareInfo) | Returns information about firmware downloads |
| [getFirmwareDownloadPercent](#method_getFirmwareDownloadPercent) | Gets the current download percentage |
| [searchFirmware](#method_searchFirmware) | Search for any available firmware ( in the remote server - for ex |
| [getDownloadState](#method_getDownloadState) | Retrieve the current state of the download process |
| [getDownloadFailureReason](#method_getDownloadFailureReason) | Gets the last firmware download failure reason |

<a id="method_getDownloadedFirmwareInfo"></a>
## *getDownloadedFirmwareInfo [<sup>method</sup>](#head_Methods)*

Returns information about firmware downloads.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.currentFWVersion | string | mandatory | The current firmware version |
| result.downloadedFWVersion | string | mandatory | The downloaded firmware version |
| result.downloadedFWLocation | string | mandatory | The location of the downloaded firmware |
| result.isRebootDeferred | boolean | mandatory | Whether the device should be rebooted |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getDownloadedFirmwareInfo"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "currentFWVersion": "...",
    "downloadedFWVersion": "...",
    "downloadedFWLocation": "...",
    "isRebootDeferred": false
  }
}
```

<a id="method_getFirmwareDownloadPercent"></a>
## *getFirmwareDownloadPercent [<sup>method</sup>](#head_Methods)*

Gets the current download percentage.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Current download percentage |
| result.downloadPercent | integer | mandatory | Current download percentage (0-100) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFirmwareDownloadPercent"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "downloadPercent": 0
  }
}
```

<a id="method_searchFirmware"></a>
## *searchFirmware [<sup>method</sup>](#head_Methods)*

Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to.

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
  "method": "<callsign>.searchFirmware"
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

<a id="method_getDownloadState"></a>
## *getDownloadState [<sup>method</sup>](#head_Methods)*

Retrieve the current state of the download process.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.downloadState | string | mandatory | Current state of the download process |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getDownloadState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "downloadState": "..."
  }
}
```

<a id="method_getDownloadFailureReason"></a>
## *getDownloadFailureReason [<sup>method</sup>](#head_Methods)*

Gets the last firmware download failure reason.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.failureReason | string | mandatory | Firmware download failure reason |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getDownloadFailureReason"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "failureReason": "..."
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the FirmwareDownload interface:

FirmwareDownload interface events:

| Notification | Description |
| :-------- | :-------- |
| [onFirmwareAvailable](#notification_onFirmwareAvailable) | Triggered when the SearchFirmware asynchronous method is invoked |

<a id="notification_onFirmwareAvailable"></a>
## *onFirmwareAvailable [<sup>notification</sup>](#head_Notifications)*

Triggered when the SearchFirmware asynchronous method is invoked.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.searchStatus | integer | mandatory | Status of the firmware search operation |
| params.serverResponse | string | mandatory | Response message from the server |
| params.firmwareAvailable | boolean | mandatory | Indicates whether new firmware is available |
| params.firmwareVersion | string | mandatory | Version string of the available firmware |
| params.rebootImmediately | boolean | mandatory | Indicates whether immediate reboot is required |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFirmwareAvailable",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFirmwareAvailable",
  "params": {
    "searchStatus": 0,
    "serverResponse": "...",
    "firmwareAvailable": false,
    "firmwareVersion": "...",
    "rebootImmediately": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFirmwareAvailable``.

