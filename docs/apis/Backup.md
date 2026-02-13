<!-- Generated automatically, DO NOT EDIT! -->
<a id="Backup_Plugin"></a>
# Backup Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Backup/IBackup.h)**

A Backup plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Backup` plugin provides an interface for Backup.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Backup) |
| classname | string | Class name: *Backup* |
| locator | string | Library name: *libWPEFrameworkBackup.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the Backup plugin:

Backup interface methods:

| Method | Description |
| :-------- | :-------- |
| [backup](#backup) | Backup settings that belong to this component. |
| [backupSettings](#backupSettings) | Backup settings across the system |
| [restore](#restore) | Restore settings that belong to this component. |
| [restoreSettings](#restoreSettings) | Restore settings across the system |

<a id="backup"></a>
## *backup*

Backup settings that belong to this component.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string | Scenario for which the backup to happen @retval Core::ERROR_NONE Successfully backed up the settings |
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
    "method": "org.rdk.Backup.backup",
    "params": {
        "scenario": "HOSPITALITY_RESET"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Backup.backup", "params": {"scenario": "HOSPITALITY_RESET"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="backupSettings"></a>
## *backupSettings*

Backup settings across the system

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string | Scenario for which the backup to happen @retval Core::ERROR_NONE Successfully backed up the settings |
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
    "method": "org.rdk.Backup.backupSettings",
    "params": {
        "scenario": "HOSPITALITY_RESET"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Backup.backupSettings", "params": {"scenario": "HOSPITALITY_RESET"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="restore"></a>
## *restore*

Restore settings that belong to this component.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string | Scenario for which the backup to happen @retval Core::ERROR_NONE Successfully backed up the settings |
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
    "method": "org.rdk.Backup.restore",
    "params": {
        "scenario": "HOSPITALITY_RESET"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Backup.restore", "params": {"scenario": "HOSPITALITY_RESET"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="restoreSettings"></a>
## *restoreSettings*

Restore settings across the system

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string | Scenario for which the backup to happen @retval Core::ERROR_NONE Successfully backed up the settings |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Backup.restoreSettings",
    "params": {
        "scenario": "HOSPITALITY_RESET"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Backup.restoreSettings", "params": {"scenario": "HOSPITALITY_RESET"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


