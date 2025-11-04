<!-- Generated automatically, DO NOT EDIT! -->
<a id="PackageManager_Plugin"></a>
# PackageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PackageManager/IPackageManager.h)**

A PackageManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PackageManager` plugin provides an interface for PackageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PackageManager) |
| classname | string | Class name: *PackageManager* |
| locator | string | Library name: *libWPEFrameworkPackageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the PackageManager plugin:

PackageManager interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [cancel](#cancel) | Cancel | NA |
| [clearAuxMetadata](#clearAuxMetadata) | Clears the specified metadata key. | NA |
| [download](#download) | Download | NA |
| [getList](#getList) | Retrieves list of installed apps matching given filters. | NA |
| [getLockInfo](#getLockInfo) | Provides lock reason and owner for an app. | NA |
| [getMetadata](#getMetadata) | Retrieves metadata and auxiliary resource list for an application. | NA |
| [getProgress](#getProgress) | Provides the current progress of an ongoing operation. | NA |
| [getStorageDetails](#getStorageDetails) | GetStorageDetails | NA |
| [install](#install) | Install | NA |
| [lock](#lock) | Lock | NA |
| [reset](#reset) | Deletes all persistent local data of the application. | NA |
| [setAuxMetadata](#setAuxMetadata) | Sets a key-value pair of metadata for the application. | NA |
| [uninstall](#uninstall) | Uninstall | NA |
| [unlock](#unlock) | Unlock | NA |
| [config](#config) | Config | NA |
| [delete](#delete) | Delete | NA |
| [getConfigForPackage](#getConfigForPackage) | getConfigForPackage | NA |
| [getLockedInfo](#getLockedInfo) | GetLockedInfo | NA |
| [listPackages](#listPackages) | ListPackages | NA |
| [packageState](#packageState) | PackageState | NA |
| [pause](#pause) | Pause | NA |
| [progress](#progress) | Progress | NA |
| [rateLimit](#rateLimit) | RateLimit | NA |
| [resume](#resume) | Resume | NA |

<a id="cancel"></a>
## *cancel*

Cancel

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download ID |
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
    "method": "org.rdk.PackageManager.cancel",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PackageManager.cancel", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="clearAuxMetadata"></a>
## *clearAuxMetadata*

Clears the specified metadata key.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.key | string |  |
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
    "method": "org.rdk.PackageManager.clearAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PackageManager.clearAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="download"></a>
## *download*

Download

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.url | string | Download url |
| params.options | Options | Download options |
| params.options.priority | bool |  |
| params.options.retries | integer |  |
| params.options.rateLimit | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.downloadId | string | Download ID |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PackageManager.download",
    "params": {
        "url": "",
        "options": {
            "priority": true,
            "retries": 0,
            "rateLimit": 0
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PackageManager.download", "params": {"url": "", "options": {"priority": true, "retries": 0, "rateLimit": 0}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "downloadId": ""
    }
}
```

<a id="getList"></a>
## *getList*

Retrieves list of installed apps matching given filters.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.appName | string |  |
| params.category | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.installedIds | IPackageKeyIterator |  |
| result.installedIds[#].id | string |  |
| result.installedIds[#].version | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PackageManager.getList",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "appName": "",
        "category": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PackageManager.getList", "params": {"type": "", "id": "", "version": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": [
        {
            "id": "",
            "version": ""
        }
    ]
}
```

<a id="getLockInfo"></a>
## *getLockInfo*

Provides lock reason and owner for an app.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | LockInfo |  |
| result.result.reason | string |  |
| result.result.owner | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PackageManager.getLockInfo",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PackageManager.getLockInfo", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "reason": "",
        "owner": ""
    }
}
```

<a id="getMetadata"></a>
## *getMetadata*

Retrieves metadata and auxiliary resource list for an application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.metadata | MetadataPayload |  |
| result.metadata.appName | string |  |
| result.metadata.type | string |  |
| result.metadata.category | string |  |
| result.metadata.url | string |  |
| result.resources | IKeyValueIterator |  |
| result.resources[#].key | string |  |
| result.resources[#].value | string |  |
| result.auxMetadata | IKeyValueIterator |  |
| result.auxMetadata[#].key | string |  |
| result.auxMetadata[#].value | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PackageManager.getMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.getMetadata", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "metadata": {
            "appName": "",
            "type": "",
            "category": "",
            "url": ""
        },
        "resources": [
            {
                "key": "",
                "value": ""
            }
        ],
        "auxMetadata": [
            {
                "key": "",
                "value": ""
            }
        ]
    }
}
```

<a id="getProgress"></a>
## *getProgress*

Provides the current progress of an ongoing operation.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.progress | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.PackageManager.getProgress",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PackageManager.getProgress", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "progress": 0
    }
}
```

<a id="getStorageDetails"></a>
## *getStorageDetails*

GetStorageDetails

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.quotaKb | string |  |
| result.usedKb | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.PackageManager.getStorageDetails"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PackageManager.getStorageDetails"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "quotaKb": "",
        "usedKb": ""
    }
}
```

<a id="install"></a>
## *install*

Install

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.additionalMetadata | IKeyValueIterator | Additional Metadata |
| params.additionalMetadata[#].name | string |  |
| params.additionalMetadata[#].value | string |  |
| params.fileLocator | string | File Locator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.failReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PackageManager.install",
    "params": {
        "packageId": "",
        "version": "",
        "additionalMetadata": [
            {
                "name": "",
                "value": ""
            }
        ],
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PackageManager.install", "params": {"packageId": "", "version": "", "additionalMetadata": [{"name": "", "value": ""}], "fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "failReason": "NONE"
    }
}
```

<a id="lock"></a>
## *lock*

Lock

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.lockReason | string | LockReason |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.lockId | integer | Lock Id |
| result.unpackedPath | string | Unpacked Path |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | integer |  |
| result.configMetadata.gpuMemoryLimit | integer |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | integer |  |
| result.configMetadata.groupId | integer |  |
| result.configMetadata.dataImageSize | integer |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | integer |  |
| result.configMetadata.logLevels | std::string | json array of strings |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string | json array of strings |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |
| result.appMetadata | ILockIterator | App Metadata |
| result.appMetadata[#].packageId | string |  |
| result.appMetadata[#].version | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.PackageManager.lock",
    "params": {
        "packageId": "",
        "version": "",
        "lockReason": "SYSTEM_APP"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PackageManager.lock", "params": {"packageId": "", "version": "", "lockReason": "SYSTEM_APP"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "lockId": 0,
        "unpackedPath": "",
        "configMetadata": {
            "dial": true,
            "wanLanAccess": true,
            "thunder": true,
            "systemMemoryLimit": 0,
            "gpuMemoryLimit": 0,
            "envVariables": "",
            "userId": 0,
            "groupId": 0,
            "dataImageSize": 0,
            "resourceManagerClientEnabled": true,
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": 0,
            "logLevels": "",
            "mapi": true,
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": true
        },
        "appMetadata": [
            {
                "packageId": "",
                "version": ""
            }
        ]
    }
}
```

<a id="reset"></a>
## *reset*

Deletes all persistent local data of the application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.resetType | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.PackageManager.reset",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resetType": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.reset", "params": {"type": "", "id": "", "version": "", "resetType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="setAuxMetadata"></a>
## *setAuxMetadata*

Sets a key-value pair of metadata for the application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.key | string |  |
| params.value | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.PackageManager.setAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.setAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="uninstall"></a>
## *uninstall*

Uninstall

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "packageId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.PackageManager.uninstall", "params": {"packageId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "errorReason": ""
    }
}
```

<a id="unlock"></a>
## *unlock*

Unlock

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.PackageManager.unlock",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.PackageManager.unlock", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="config"></a>
## *config*

Config

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | integer |  |
| result.configMetadata.gpuMemoryLimit | integer |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | integer |  |
| result.configMetadata.groupId | integer |  |
| result.configMetadata.dataImageSize | integer |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | integer |  |
| result.configMetadata.logLevels | std::string | json array of strings |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string | json array of strings |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PackageManager.config",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PackageManager.config", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "dial": true,
        "wanLanAccess": true,
        "thunder": true,
        "systemMemoryLimit": 0,
        "gpuMemoryLimit": 0,
        "envVariables": "",
        "userId": 0,
        "groupId": 0,
        "dataImageSize": 0,
        "resourceManagerClientEnabled": true,
        "dialId": "",
        "command": "",
        "appType": "",
        "appPath": "",
        "runtimePath": "",
        "logFilePath": "",
        "logFileMaxSize": 0,
        "logLevels": "",
        "mapi": true,
        "fkpsFiles": "",
        "fireboltVersion": "",
        "enableDebugger": true
    }
}
```

<a id="delete"></a>
## *delete*

Delete

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | File Locator |
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
    "method": "org.rdk.PackageManager.delete",
    "params": {
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PackageManager.delete", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="getConfigForPackage"></a>
## *getConfigForPackage*

getConfigForPackage

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | File Locator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.id | string | package id |
| result.version | string | Version |
| result.config | RuntimeConfig | metadata of package |
| result.config.dial | bool |  |
| result.config.wanLanAccess | bool |  |
| result.config.thunder | bool |  |
| result.config.systemMemoryLimit | integer |  |
| result.config.gpuMemoryLimit | integer |  |
| result.config.envVariables | std::string |  |
| result.config.userId | integer |  |
| result.config.groupId | integer |  |
| result.config.dataImageSize | integer |  |
| result.config.resourceManagerClientEnabled | bool |  |
| result.config.dialId | std::string |  |
| result.config.command | std::string |  |
| result.config.appType | std::string |  |
| result.config.appPath | std::string |  |
| result.config.runtimePath | std::string |  |
| result.config.logFilePath | std::string |  |
| result.config.logFileMaxSize | integer |  |
| result.config.logLevels | std::string | json array of strings |
| result.config.mapi | bool |  |
| result.config.fkpsFiles | std::string | json array of strings |
| result.config.fireboltVersion | std::string |  |
| result.config.enableDebugger | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PackageManager.getConfigForPackage",
    "params": {
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PackageManager.getConfigForPackage", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "id": "",
        "version": "",
        "config": {
            "dial": true,
            "wanLanAccess": true,
            "thunder": true,
            "systemMemoryLimit": 0,
            "gpuMemoryLimit": 0,
            "envVariables": "",
            "userId": 0,
            "groupId": 0,
            "dataImageSize": 0,
            "resourceManagerClientEnabled": true,
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": 0,
            "logLevels": "",
            "mapi": true,
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": true
        }
    }
}
```

<a id="getLockedInfo"></a>
## *getLockedInfo*

GetLockedInfo

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.unpackedPath | string | Unpacked Path |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | integer |  |
| result.configMetadata.gpuMemoryLimit | integer |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | integer |  |
| result.configMetadata.groupId | integer |  |
| result.configMetadata.dataImageSize | integer |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | integer |  |
| result.configMetadata.logLevels | std::string | json array of strings |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string | json array of strings |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |
| result.gatewayMetadataPath | string |  |
| result.locked | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PackageManager.getLockedInfo",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.getLockedInfo", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "unpackedPath": "",
        "configMetadata": {
            "dial": true,
            "wanLanAccess": true,
            "thunder": true,
            "systemMemoryLimit": 0,
            "gpuMemoryLimit": 0,
            "envVariables": "",
            "userId": 0,
            "groupId": 0,
            "dataImageSize": 0,
            "resourceManagerClientEnabled": true,
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": 0,
            "logLevels": "",
            "mapi": true,
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": true
        },
        "gatewayMetadataPath": "",
        "locked": true
    }
}
```

<a id="listPackages"></a>
## *listPackages*

ListPackages

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.packages | IPackageIterator |  |
| result.packages[#].packageId | string |  |
| result.packages[#].version | string |  |
| result.packages[#].state | string |  |
| result.packages[#].digest | string |  |
| result.packages[#].sizeKb | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.PackageManager.listPackages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.listPackages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": [
        {
            "packageId": "",
            "version": "",
            "state": "INSTALLING",
            "digest": "",
            "sizeKb": 0
        }
    ]
}
```

<a id="packageState"></a>
## *packageState*

PackageState

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.PackageManager.packageState",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.packageState", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "state": "INSTALLING"
    }
}
```

<a id="pause"></a>
## *pause*

Pause

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.PackageManager.pause",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.pause", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="progress"></a>
## *progress*

Progress

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.progress | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.PackageManager.progress",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.progress", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "progress": 0
    }
}
```

<a id="rateLimit"></a>
## *rateLimit*

RateLimit

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download ID |
| params.limit | integer | Limit |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.PackageManager.rateLimit",
    "params": {
        "downloadId": "",
        "limit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PackageManager.rateLimit", "params": {"downloadId": "", "limit": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="resume"></a>
## *resume*

Resume

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.PackageManager.resume",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PackageManager.resume", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PackageManager plugin:

PackageManager interface events:

| Event | Description |
| :-------- | :-------- |
| [operationStatus](#operationStatus) | Notifies completion of an asynchronous operation. |

<a id="operationStatus"></a>
## *operationStatus*

Notifies completion of an asynchronous operation.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string |  |
| params.operation | string |  |
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.status | string |  |
| params.details | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.PackageManager.operationStatus",
    "params": {
        "handle": "",
        "operation": "",
        "type": "",
        "id": "",
        "version": "",
        "status": "",
        "details": ""
    }
}
```
