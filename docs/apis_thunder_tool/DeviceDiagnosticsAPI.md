<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DeviceDiagnostics_API"></a>
# DeviceDiagnostics API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DeviceDiagnostics interface for Thunder framework.

(Defined with IDeviceDiagnostics in [IDeviceDiagnostics.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDeviceDiagnostics.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DeviceDiagnostics interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

DeviceDiagnostics JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DeviceDiagnostics interface:

DeviceDiagnostics interface methods:

| Method | Description |
| :-------- | :-------- |
| [getConfiguration](#method_getConfiguration) | Gets the values associated with the corresponding property names |
| [getMilestones](#method_getMilestones) | Returns the list of milestones |
| [logMilestone](#method_logMilestone) | Log marker string to rdk milestones log |
| [getAVDecoderStatus](#method_getAVDecoderStatus) | Gets the most active status of audio/video decoder/pipeline |

<a id="method_getConfiguration"></a>
## *getConfiguration [<sup>method</sup>](#head_Methods)*

Gets the values associated with the corresponding property names.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.names | array | mandatory | - in - String array of property names |
| params.names[#] | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.paramList | array | mandatory | - out - specified properties and their values |
| result.paramList[#] | object | mandatory |  |
| result.paramList[#].name | string | mandatory |  |
| result.paramList[#].value | string | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getConfiguration",
  "params": {
    "names": [
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
    "paramList": [
      {
        "name": "...",
        "value": "..."
      }
    ],
    "success": false
  }
}
```

<a id="method_getMilestones"></a>
## *getMilestones [<sup>method</sup>](#head_Methods)*

Returns the list of milestones.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.milestones | array | mandatory | - out - A string [] of milestones |
| result.milestones[#] | string | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMilestones"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "milestones": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_logMilestone"></a>
## *logMilestone [<sup>method</sup>](#head_Methods)*

Log marker string to rdk milestones log.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.marker | string | mandatory | - in - string |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | - out - boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.logMilestone",
  "params": {
    "marker": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_getAVDecoderStatus"></a>
## *getAVDecoderStatus [<sup>method</sup>](#head_Methods)*

Gets the most active status of audio/video decoder/pipeline.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | - out |
| result.avDecoderStatus | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getAVDecoderStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "avDecoderStatus": "..."
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the DeviceDiagnostics interface:

DeviceDiagnostics interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAVDecoderStatusChanged](#notification_onAVDecoderStatusChanged) | Triggered when the most active status of audio/video decoder/pipeline changes |

<a id="notification_onAVDecoderStatusChanged"></a>
## *onAVDecoderStatusChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the most active status of audio/video decoder/pipeline changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.avDecoderStatusChange | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAVDecoderStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAVDecoderStatusChanged",
  "params": {
    "avDecoderStatusChange": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAVDecoderStatusChanged``.

