<!-- Generated automatically, DO NOT EDIT! -->
<a id="Migration_Plugin"></a>
# Migration Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Migration/IMigration.h)**

A Migration plugin for Thunder framework.

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

The `Migration` plugin provides an interface for Migration.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Migration) |
| classname | string | Class name: *Migration* |
| locator | string | Library name: *libWPEFrameworkMigration.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the Migration plugin:

Migration interface methods:

| Method | Description |
| :-------- | :-------- |
| [getBootTypeInfo](#getBootTypeInfo) | query the BootType details |
| [getMigrationStatus](#getMigrationStatus) | get the MigrationStatus details |
| [setMigrationStatus](#setMigrationStatus) | sets the tr181 MigrationStatus parameter |

<a id="getBootTypeInfo"></a>
## *getBootTypeInfo*

query the BootType details

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.bootType | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Migration.getBootTypeInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Migration.getBootTypeInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "bootType": "BOOT_TYPE_INIT"
    }
}
```

<a id="getMigrationStatus"></a>
## *getMigrationStatus*

get the MigrationStatus details

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.migrationStatus | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Migration.getMigrationStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Migration.getMigrationStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "migrationStatus": "MIGRATION_STATUS_NOT_STARTED"
    }
}
```

<a id="setMigrationStatus"></a>
## *setMigrationStatus*

sets the tr181 MigrationStatus parameter

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | enum |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Migration.setMigrationStatus",
    "params": {
        "status": "MIGRATION_STATUS_NOT_STARTED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Migration.setMigrationStatus", "params": {"status": "MIGRATION_STATUS_NOT_STARTED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```


