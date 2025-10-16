<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Migration_Plugin"></a>
# Migration Plugin

A org.rdk.Migration plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `Migration` plugin provides the status of the migration.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.Migration*) |
| classname | string | Class name: *org.rdk.Migration* |
| locator | string | Library name: *libWPEFrameworkMigration.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Migration plugin:

IMigration interface methods:

| Method | Description |
| :-------- | :-------- |
| [getBootTypeInfo](#getBootTypeInfo) | Getting Boot Type |
| [getMigrationStatus](#getMigrationStatus) | Getting the device Migration Status |
| [setMigrationStatus](#method.setMigrationStatus) | Setting the device Migration Status |

<a name="getBootTypeInfo"></a>
## *getBootTypeInfo*

Getting Boot Type.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.bootType | string | BOOT Type Info. one of the following "BOOT_INIT", "BOOT_NORMAL", "BOOT_MIGRATION", "BOOT_UPDATE", "BOOT_INCONCLUSIVE" |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_NONE``` | Success |
| ```ERROR_FILE_IO``` | File Read or Write error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Migration.getBootTypeInfo"
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

<a name="getMigrationStatus"></a>
## *getMigrationStatus*

Getting the device Migration Status.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.migrationStatus | string |  Migration Status  One of the following: "NOT_STARTED","NOT_NEEDED","STARTED","PRIORITY_SETTINGS_MIGRATED","DEVICE_SETTINGS_MIGRATED","CLOUD_SETTINGS_MIGRATED","APP_DATA_MIGRATED","MIGRATION_COMPLETED" |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_NONE``` | Success |
| ```ERROR_FILE_IO``` | File Read or Write error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Migration.getMigrationStatus"
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

<a name="setMigrationStatus"></a>
## *setMigrationStatus*

Setting the device Migration Status.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Status of Migration process One of the following: "NOT_STARTED","NOT_NEEDED","STARTED","PRIORITY_SETTINGS_MIGRATED","DEVICE_SETTINGS_MIGRATED","CLOUD_SETTINGS_MIGRATED","APP_DATA_MIGRATED","MIGRATION_COMPLETED" |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_NONE``` | Success |
| ```ERROR_FILE_IO``` | File Read or Write error |
| ```ERROR_INVALID_PARAMETER``` | Invalid Request |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean |  Whether the request succeeded|

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Migration.setMigrationStatus",
    "params": {
        "status": "NOT_STARTED"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```
