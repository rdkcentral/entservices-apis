<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Migration_API"></a>
# Migration API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Migration interface for Thunder framework.

(Defined with IMigration in [IMigration.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IMigration.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Migration interface (version 1.0.0). It includes detailed specification about its methods provided.

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

Migration JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Migration interface:

Migration interface methods:

| Method | Description |
| :-------- | :-------- |
| [getBootTypeInfo](#method_getBootTypeInfo) | query the BootType details |
| [setMigrationStatus](#method_setMigrationStatus) | sets the tr181 MigrationStatus parameter |
| [getMigrationStatus](#method_getMigrationStatus) | get the MigrationStatus details |

<a id="method_getBootTypeInfo"></a>
## *getBootTypeInfo [<sup>method</sup>](#head_Methods)*

query the BootType details.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.bootType | string | mandatory | *...* (must be one of the following: *BOOT_INIT, BOOT_MIGRATION, BOOT_NORMAL, BOOT_UPDATE*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBootTypeInfo"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "bootType": "BOOT_NORMAL"
  }
}
```

<a id="method_setMigrationStatus"></a>
## *setMigrationStatus [<sup>method</sup>](#head_Methods)*

sets the tr181 MigrationStatus parameter.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | string | mandatory | - in - enum (must be one of the following: *APP_DATA_MIGRATED, CLOUD_SETTINGS_MIGRATED, DEVICE_SETTINGS_MIGRATED, MIGRATION_COMPLETED, NOT_NEEDED, NOT_STARTED, PRIORITY_SETTINGS_MIGRATED, STARTED*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | - out - struct |
| result.success | boolean | mandatory | *...* |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setMigrationStatus",
  "params": {
    "status": "NOT_NEEDED"
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

<a id="method_getMigrationStatus"></a>
## *getMigrationStatus [<sup>method</sup>](#head_Methods)*

get the MigrationStatus details.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.migrationStatus | string | mandatory | *...* (must be one of the following: *APP_DATA_MIGRATED, CLOUD_SETTINGS_MIGRATED, DEVICE_SETTINGS_MIGRATED, MIGRATION_COMPLETED, NOT_NEEDED, NOT_STARTED, PRIORITY_SETTINGS_MIGRATED, STARTED*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getMigrationStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "migrationStatus": "NOT_NEEDED"
  }
}
```

