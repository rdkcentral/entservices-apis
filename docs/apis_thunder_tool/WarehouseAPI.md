<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Warehouse_API"></a>
# Warehouse API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Warehouse interface for Thunder framework.

(Defined with IWarehouse in [IWarehouse.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IWarehouse.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Warehouse interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

Warehouse JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Warehouse interface:

Warehouse interface methods:

| Method | Description |
| :-------- | :-------- |
| [executeHardwareTest](#method_executeHardwareTest) | Starts a hardware test on the device |
| [getHardwareTestResults](#method_getHardwareTestResults) | Returns the results of the last hardware test |
| [internalReset](#method_internalReset) | Invokes the internal reset script, which reboots the Warehouse service |
| [isClean](#method_isClean) | Checks the locations on the device where customer data may be stored |
| [lightReset](#method_lightReset) | Resets the application data |
| [resetDevice](#method_resetDevice) | Resets the STB to the warehouse state |

<a id="method_executeHardwareTest"></a>
## *executeHardwareTest [<sup>method</sup>](#head_Methods)*

Starts a hardware test on the device.

### Parameters

This method takes no parameters.

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
  "method": "<callsign>.1.executeHardwareTest"
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

<a id="method_getHardwareTestResults"></a>
## *getHardwareTestResults [<sup>method</sup>](#head_Methods)*

Returns the results of the last hardware test.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |
| result.testResults | string | mandatory | - out - string |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getHardwareTestResults"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "testResults": "..."
  }
}
```

<a id="method_internalReset"></a>
## *internalReset [<sup>method</sup>](#head_Methods)*

Invokes the internal reset script, which reboots the Warehouse service.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.passPhrase | string | mandatory | - in - string |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.error | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.internalReset",
  "params": {
    "passPhrase": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "error": "..."
  }
}
```

<a id="method_isClean"></a>
## *isClean [<sup>method</sup>](#head_Methods)*

Checks the locations on the device where customer data may be stored.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.age | integer | mandatory | - in - integer |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.clean | boolean | mandatory | - out - boolean |
| result.files | array | mandatory | - out - string [] of file locations for each file |
| result.files[#] | string | mandatory |  |
| result.success | boolean | mandatory | - out - boolean |
| result.error | string | mandatory | -out - string |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.isClean",
  "params": {
    "age": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "clean": false,
    "files": [
      "..."
    ],
    "success": false,
    "error": "..."
  }
}
```

<a id="method_lightReset"></a>
## *lightReset [<sup>method</sup>](#head_Methods)*

Resets the application data.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.error | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.lightReset"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "error": "..."
  }
}
```

<a id="method_resetDevice"></a>
## *resetDevice [<sup>method</sup>](#head_Methods)*

Resets the STB to the warehouse state.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.suppressReboot | boolean | mandatory | - in - bool |
| params.resetType | string | mandatory | - in - string |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |
| result.error | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.resetDevice",
  "params": {
    "suppressReboot": false,
    "resetType": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "error": "..."
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Warehouse interface:

Warehouse interface events:

| Notification | Description |
| :-------- | :-------- |
| [resetDone](#notification_resetDone) | Notifies subscribers about the status of the warehouse reset operation |

<a id="notification_resetDone"></a>
## *resetDone [<sup>notification</sup>](#head_Notifications)*

Notifies subscribers about the status of the warehouse reset operation.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.success | boolean | mandatory | - in - boolean |
| params.error | string | mandatory | - in - string |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "resetDone",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.resetDone",
  "params": {
    "success": false,
    "error": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.resetDone``.

