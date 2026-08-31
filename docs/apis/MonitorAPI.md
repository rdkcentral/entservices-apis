<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Monitor_API"></a>
# Monitor API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Monitor interface for Thunder framework.

(Defined by [Monitor.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

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

This document describes purpose and functionality of the Monitor interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

Monitor JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Monitor interface:

Monitor interface methods:

| Method | Description |
| :-------- | :-------- |
| [restartlimits](#method_restartlimits) | Sets new restart limits for a service |
| [resetstats](#method_resetstats) | Resets memory and process statistics for a single service watched by the Monitor |

<a id="method_restartlimits"></a>
## *restartlimits [<sup>method</sup>](#head_Methods)*

Sets new restart limits for a service.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.callsign | string | mandatory | The callsign of a service to reset measurements snapshot of |
| params.restart | object | mandatory | *...* |
| params.restart.limit | integer | mandatory | Maximum number or restarts to be attempted |
| params.restart.window | integer | mandatory | Time period (in seconds) within which failures must happen for the limit to be considered crossed |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.restartlimits",
  "params": {
    "callsign": "WebServer",
    "restart": {
      "limit": 3,
      "window": 60
    }
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

<a id="method_resetstats"></a>
## *resetstats [<sup>method</sup>](#head_Methods)*

Resets memory and process statistics for a single service watched by the Monitor.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.callsign | string | mandatory | The callsign of a service to reset statistics of |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Measurements for the service before reset |
| result.measurements | object | mandatory | Measurements for the service |
| result.measurements.resident | object | mandatory | Resident memory measurement |
| result.measurements.resident.min | integer | mandatory | Minimal value measured |
| result.measurements.resident.max | integer | mandatory | Maximal value measured |
| result.measurements.resident.average | integer | mandatory | Average of all measurements |
| result.measurements.resident.last | integer | mandatory | Last measured value |
| result.measurements.allocated | object | mandatory | Allocated memory measurement |
| result.measurements.allocated.min | integer | mandatory | Minimal value measured |
| result.measurements.allocated.max | integer | mandatory | Maximal value measured |
| result.measurements.allocated.average | integer | mandatory | Average of all measurements |
| result.measurements.allocated.last | integer | mandatory | Last measured value |
| result.measurements.shared | object | mandatory | Shared memory measurement |
| result.measurements.shared.min | integer | mandatory | Minimal value measured |
| result.measurements.shared.max | integer | mandatory | Maximal value measured |
| result.measurements.shared.average | integer | mandatory | Average of all measurements |
| result.measurements.shared.last | integer | mandatory | Last measured value |
| result.measurements.process | object | mandatory | Processes measurement |
| result.measurements.process.min | integer | mandatory | Minimal value measured |
| result.measurements.process.max | integer | mandatory | Maximal value measured |
| result.measurements.process.average | integer | mandatory | Average of all measurements |
| result.measurements.process.last | integer | mandatory | Last measured value |
| result.measurements.operational | boolean | mandatory | Whether the service is up and running |
| result.measurements.count | integer | mandatory | Number of measurements |
| result.observable | string | mandatory | A callsign of the watched service |
| result.restart | object | mandatory | Restart limits for failures applying to the service |
| result.restart.limit | integer | mandatory | Maximum number or restarts to be attempted |
| result.restart.window | integer | mandatory | Time period (in seconds) within which failures must happen for the limit to be considered crossed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.resetstats",
  "params": {
    "callsign": "WebServer"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "measurements": {
      "resident": {
        "min": 0,
        "max": 100,
        "average": 50,
        "last": 100
      },
      "allocated": {
        "min": 0,
        "max": 100,
        "average": 50,
        "last": 100
      },
      "shared": {
        "min": 0,
        "max": 100,
        "average": 50,
        "last": 100
      },
      "process": {
        "min": 0,
        "max": 100,
        "average": 50,
        "last": 100
      },
      "operational": true,
      "count": 100
    },
    "observable": "callsign",
    "restart": {
      "limit": 3,
      "window": 60
    }
  }
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the Monitor interface:

Monitor interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [status](#property_status) | read-only | Service statistics |

<a id="property_status"></a>
## *status [<sup>property</sup>](#head_Properties)*

Provides access to the service statistics.

> This property is **read-only**.

> The *callsign* parameter shall be passed as the index to the property, i.e. ``status@<callsign>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| callsign | string | mandatory | If omitted then all observed objects will be returned on read |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Service statistics |
| (property)[#] | object | mandatory | *...* |
| (property)[#].measurements | object | mandatory | Measurements for the service |
| (property)[#].measurements.resident | object | mandatory | Resident memory measurement |
| (property)[#].measurements.resident.min | integer | mandatory | Minimal value measured |
| (property)[#].measurements.resident.max | integer | mandatory | Maximal value measured |
| (property)[#].measurements.resident.average | integer | mandatory | Average of all measurements |
| (property)[#].measurements.resident.last | integer | mandatory | Last measured value |
| (property)[#].measurements.allocated | object | mandatory | Allocated memory measurement |
| (property)[#].measurements.allocated.min | integer | mandatory | Minimal value measured |
| (property)[#].measurements.allocated.max | integer | mandatory | Maximal value measured |
| (property)[#].measurements.allocated.average | integer | mandatory | Average of all measurements |
| (property)[#].measurements.allocated.last | integer | mandatory | Last measured value |
| (property)[#].measurements.shared | object | mandatory | Shared memory measurement |
| (property)[#].measurements.shared.min | integer | mandatory | Minimal value measured |
| (property)[#].measurements.shared.max | integer | mandatory | Maximal value measured |
| (property)[#].measurements.shared.average | integer | mandatory | Average of all measurements |
| (property)[#].measurements.shared.last | integer | mandatory | Last measured value |
| (property)[#].measurements.process | object | mandatory | Processes measurement |
| (property)[#].measurements.process.min | integer | mandatory | Minimal value measured |
| (property)[#].measurements.process.max | integer | mandatory | Maximal value measured |
| (property)[#].measurements.process.average | integer | mandatory | Average of all measurements |
| (property)[#].measurements.process.last | integer | mandatory | Last measured value |
| (property)[#].measurements.operational | boolean | mandatory | Whether the service is up and running |
| (property)[#].measurements.count | integer | mandatory | Number of measurements |
| (property)[#].observable | string | mandatory | A callsign of the watched service |
| (property)[#].restart | object | mandatory | Restart limits for failures applying to the service |
| (property)[#].restart.limit | integer | mandatory | Maximum number or restarts to be attempted |
| (property)[#].restart.window | integer | mandatory | Time period (in seconds) within which failures must happen for the limit to be considered crossed |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.status@WebServer"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "measurements": {
        "resident": {
          "min": 0,
          "max": 100,
          "average": 50,
          "last": 100
        },
        "allocated": {
          "min": 0,
          "max": 100,
          "average": 50,
          "last": 100
        },
        "shared": {
          "min": 0,
          "max": 100,
          "average": 50,
          "last": 100
        },
        "process": {
          "min": 0,
          "max": 100,
          "average": 50,
          "last": 100
        },
        "operational": true,
        "count": 100
      },
      "observable": "callsign",
      "restart": {
        "limit": 3,
        "window": 60
      }
    }
  ]
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Monitor interface:

Monitor interface events:

| Notification | Description |
| :-------- | :-------- |
| [action](#notification_action) | Signals an action taken by the Monitor |

<a id="notification_action"></a>
## *action [<sup>notification</sup>](#head_Notifications)*

Signals an action taken by the Monitor.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.callsign | string | mandatory | Callsign of the service the Monitor acted upon |
| params.action | string | mandatory | The action executed by the Monitor on a service. One of: "Activate", "Deactivate", "StoppedRestarting" |
| params.reason | string | mandatory | A message describing the reason the action was taken |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "action",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.action",
  "params": {
    "callsign": "WebServer",
    "action": "Deactivate",
    "reason": "EXCEEDED_MEMORY"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.action``.

