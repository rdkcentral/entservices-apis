<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_FirmwareUpdate_API"></a>
# FirmwareUpdate API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

FirmwareUpdate interface for Thunder framework.

(Defined with IFirmwareUpdate in [IFirmwareUpdate.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IFirmwareUpdate.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the FirmwareUpdate interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

FirmwareUpdate JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the FirmwareUpdate interface:

FirmwareUpdate interface methods:

| Method | Description |
| :-------- | :-------- |
| [updateFirmware](#method_updateFirmware) | Initiates a firmware update |
| [getUpdateState](#method_getUpdateState) | Firmware update consists of 2 major steps: 1 |

<a id="method_updateFirmware"></a>
## *updateFirmware [<sup>method</sup>](#head_Methods)*

Initiates a firmware update.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.firmwareFilepath | string | mandatory |  |
| params.firmwareType | string | mandatory |  |

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
  "method": "<callsign>.1.updateFirmware",
  "params": {
    "firmwareFilepath": "...",
    "firmwareType": "..."
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

<a id="method_getUpdateState"></a>
## *getUpdateState [<sup>method</sup>](#head_Methods)*

Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.state | string | mandatory |  (must be one of the following: *FLASHING_FAILED, FLASHING_STARTED, FLASHING_SUCCEEDED, VALIDATION_FAILED, WAITING_FOR_REBOOT*) |
| result.substate | string | mandatory |  (must be one of the following: *FIRMWARE_INCOMPATIBLE, FIRMWARE_INVALID, FIRMWARE_NOT_FOUND, FIRMWARE_OUTDATED, FIRMWARE_UPTODATE, FLASH_WRITE_FAILED, NOT_APPLICABLE, POSTWRITE_FIRMWARE_CHECK_FAILED, POSTWRITE_SIGNATURE_CHECK_FAILED, PREWRITE_SIGNATURE_CHECK_FAILED*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getUpdateState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "state": "FLASHING_STARTED",
    "substate": "FIRMWARE_NOT_FOUND"
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the FirmwareUpdate interface:

FirmwareUpdate interface events:

| Notification | Description |
| :-------- | :-------- |
| [onUpdateStateChange](#notification_onUpdateStateChange) | notify Firmware update state change |
| [onFlashingStateChange](#notification_onFlashingStateChange) | This notification is raised between flashing started state and flashing succeeded/failed |

<a id="notification_onUpdateStateChange"></a>
## *onUpdateStateChange [<sup>notification</sup>](#head_Notifications)*

notify Firmware update state change.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.state | string | mandatory |  (must be one of the following: *FLASHING_FAILED, FLASHING_STARTED, FLASHING_SUCCEEDED, VALIDATION_FAILED, WAITING_FOR_REBOOT*) |
| params.substate | string | mandatory |  (must be one of the following: *FIRMWARE_INCOMPATIBLE, FIRMWARE_INVALID, FIRMWARE_NOT_FOUND, FIRMWARE_OUTDATED, FIRMWARE_UPTODATE, FLASH_WRITE_FAILED, NOT_APPLICABLE, POSTWRITE_FIRMWARE_CHECK_FAILED, POSTWRITE_SIGNATURE_CHECK_FAILED, PREWRITE_SIGNATURE_CHECK_FAILED*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onUpdateStateChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onUpdateStateChange",
  "params": {
    "state": "FLASHING_STARTED",
    "substate": "FIRMWARE_NOT_FOUND"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onUpdateStateChange``.

<a id="notification_onFlashingStateChange"></a>
## *onFlashingStateChange [<sup>notification</sup>](#head_Notifications)*

This notification is raised between flashing started state and flashing succeeded/failed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.percentageComplete | integer | mandatory | : Number between 0 and 100 indicating the "percentage complete" of the flashing process |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFlashingStateChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFlashingStateChange",
  "params": {
    "percentageComplete": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFlashingStateChange``.

