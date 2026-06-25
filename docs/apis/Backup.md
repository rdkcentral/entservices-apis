<!-- Generated automatically, DO NOT EDIT! -->
<a id="Backup_Module"></a>
# Backup Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Backup/IBackup.h)**

A Backup module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IBackupManager](#IBackupManager)
    - [Methods](#IBackupManager-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Backup` module provides the following interface(s):

- IBackupManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Backup) |
| classname | string | Class name: *Backup* |
| locator | string | Library name: *libWPEFrameworkBackup.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IBackupManager"></a>
## IBackupManager Interface

### Description

Filesystem path where backup data is stored persistently

<a id="IBackupManager-Methods"></a>
### Methods

The following methods are provided by the IBackupManager Interface:

| Method | Description |
| :-------- | :-------- |
| [backupSettings](#backupSettings) | Backup settings across the system |
| [deleteBackup](#deleteBackup) | Deletes the previously backed up settings across the system |
| [restoreSettings](#restoreSettings) | Restore settings across the system |

<a id="backupSettings"></a>
## *backupSettings*

Backup settings across the system

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.context | object | Context for which the backup to happen |
| params.context.scenario | string | scenario. Possible values: HOSPITALITY_RESET |
| params.context.variant | string | variant |
| params.context.persistentPath | string | persistentPath |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Backup.backupSettings",
    "params": {
        "scenario": "HOSPITALITY_RESET",
        "variant": "",
        "persistentPath": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Backup.backupSettings", "params": {"scenario": "HOSPITALITY_RESET", "variant": "", "persistentPath": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="deleteBackup"></a>
## *deleteBackup*

Deletes the previously backed up settings across the system

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.context | object | Context for which the backup to be deleted |
| params.context.scenario | string | scenario. Possible values: HOSPITALITY_RESET |
| params.context.variant | string | variant |
| params.context.persistentPath | string | persistentPath |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Backup.deleteBackup",
    "params": {
        "scenario": "HOSPITALITY_RESET",
        "variant": "",
        "persistentPath": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Backup.deleteBackup", "params": {"scenario": "HOSPITALITY_RESET", "variant": "", "persistentPath": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="restoreSettings"></a>
## *restoreSettings*

Restore settings across the system

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.context | object | Context for which the restore to happen |
| params.context.scenario | string | scenario. Possible values: HOSPITALITY_RESET |
| params.context.variant | string | variant |
| params.context.persistentPath | string | persistentPath |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Backup.restoreSettings",
    "params": {
        "scenario": "HOSPITALITY_RESET",
        "variant": "",
        "persistentPath": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Backup.restoreSettings", "params": {"scenario": "HOSPITALITY_RESET", "variant": "", "persistentPath": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

