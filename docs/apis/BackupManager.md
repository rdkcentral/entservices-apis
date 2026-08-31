<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_BackupManager_API"></a>
# BackupManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

BackupManager interface for Thunder framework.

(Defined with IBackupManager in [IBackup.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IBackup.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the BackupManager interface (version 1.0.0). It includes detailed specification about its methods provided.

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

BackupManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the BackupManager interface:

BackupManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [backupSettings](#method_backupSettings) | Backup settings across the system |
| [restoreSettings](#method_restoreSettings) | Restore settings across the system |
| [deleteBackup](#method_deleteBackup) | Deletes the previously backed up settings across the system |

<a id="method_backupSettings"></a>
## *backupSettings [<sup>method</sup>](#head_Methods)*

Backup settings across the system.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.context | object | mandatory | Context for which the backup to happen |
| params.context.scenario | string | mandatory | The scenario for which the backup operations are done (must be one of the following: *HOSPITALITY_RESET*) |
| params.context.variant | string | mandatory | Variant label for the backup context (for example, user profile for which the backup operations are done) |
| params.context.persistentPath | string | mandatory | Filesystem path where backup data is stored persistently |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Successfully backed up the settings |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.backupSettings",
  "params": {
    "context": {
      "scenario": "HOSPITALITY_RESET",
      "variant": "...",
      "persistentPath": "..."
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

<a id="method_restoreSettings"></a>
## *restoreSettings [<sup>method</sup>](#head_Methods)*

Restore settings across the system.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.context | object | mandatory | Context for which the restore to happen |
| params.context.scenario | string | mandatory | The scenario for which the backup operations are done (must be one of the following: *HOSPITALITY_RESET*) |
| params.context.variant | string | mandatory | Variant label for the backup context (for example, user profile for which the backup operations are done) |
| params.context.persistentPath | string | mandatory | Filesystem path where backup data is stored persistently |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Successfully restored the settings |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.restoreSettings",
  "params": {
    "context": {
      "scenario": "HOSPITALITY_RESET",
      "variant": "...",
      "persistentPath": "..."
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

<a id="method_deleteBackup"></a>
## *deleteBackup [<sup>method</sup>](#head_Methods)*

Deletes the previously backed up settings across the system.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.context | object | mandatory | Context for which the backup to be deleted |
| params.context.scenario | string | mandatory | The scenario for which the backup operations are done (must be one of the following: *HOSPITALITY_RESET*) |
| params.context.variant | string | mandatory | Variant label for the backup context (for example, user profile for which the backup operations are done) |
| params.context.persistentPath | string | mandatory | Filesystem path where backup data is stored persistently |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Successfully deleted the backup |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.deleteBackup",
  "params": {
    "context": {
      "scenario": "HOSPITALITY_RESET",
      "variant": "...",
      "persistentPath": "..."
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

