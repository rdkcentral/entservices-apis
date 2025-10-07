<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Telemetry_API"></a>
# Telemetry API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Telemetry interface for Thunder framework.

(Defined with ITelemetry in [ITelemetry.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITelemetry.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Telemetry interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

Telemetry JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Telemetry interface:

Telemetry interface methods:

| Method | Description |
| :-------- | :-------- |
| [setReportProfileStatus](#method_setReportProfileStatus) | Sets the status of telemetry reporting |
| [logApplicationEvent](#method_logApplicationEvent) | Logs an application |
| [uploadReport](#method_uploadReport) | Uploading of telemetry report |
| [abortReport](#method_abortReport) | Abort report upload |
| [setOptOutTelemetry](#method_setOptOutTelemetry) | Sets the telemetry opt-out status |
| [isOptOutTelemetry](#method_isOptOutTelemetry) | Checks the telemetry opt-out status |

<a id="method_setReportProfileStatus"></a>
## *setReportProfileStatus [<sup>method</sup>](#head_Methods)*

Sets the status of telemetry reporting.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | string | mandatory | - in - string |

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
  "method": "<callsign>.1.setReportProfileStatus",
  "params": {
    "status": "..."
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

<a id="method_logApplicationEvent"></a>
## *logApplicationEvent [<sup>method</sup>](#head_Methods)*

Logs an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.eventName | string | mandatory | - in - string |
| params.eventValue | string | mandatory | - in - string |

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
  "method": "<callsign>.1.logApplicationEvent",
  "params": {
    "eventName": "...",
    "eventValue": "..."
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

<a id="method_uploadReport"></a>
## *uploadReport [<sup>method</sup>](#head_Methods)*

Uploading of telemetry report.

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
  "method": "<callsign>.1.uploadReport"
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

<a id="method_abortReport"></a>
## *abortReport [<sup>method</sup>](#head_Methods)*

Abort report upload.

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
  "method": "<callsign>.1.abortReport"
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

<a id="method_setOptOutTelemetry"></a>
## *setOptOutTelemetry [<sup>method</sup>](#head_Methods)*

Sets the telemetry opt-out status.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.Opt-Out | boolean | mandatory |  |

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
  "method": "<callsign>.1.setOptOutTelemetry",
  "params": {
    "Opt-Out": false
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

<a id="method_isOptOutTelemetry"></a>
## *isOptOutTelemetry [<sup>method</sup>](#head_Methods)*

Checks the telemetry opt-out status.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.Opt-Out | boolean | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.isOptOutTelemetry"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "Opt-Out": false,
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Telemetry interface:

Telemetry interface events:

| Notification | Description |
| :-------- | :-------- |
| [onReportUpload](#notification_onReportUpload) | Triggered by callback from Telemetry after report uploading |

<a id="notification_onReportUpload"></a>
## *onReportUpload [<sup>notification</sup>](#head_Notifications)*

Triggered by callback from Telemetry after report uploading.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.telemetryUploadStatus | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onReportUpload",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onReportUpload",
  "params": {
    "telemetryUploadStatus": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onReportUpload``.

