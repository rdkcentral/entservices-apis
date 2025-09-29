<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.PackageManager_Plugin"></a>
# PackageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/PackageManager/CHANGELOG.md)**

A PackageManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `PackageManager` plugin provides an interface for PackageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PackageManager) |
| classname | string | Class name: *PackageManager* |
| locator | string | Library name: *libWPEFrameworkPackageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the PackageManager plugin:

PackageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [cancel](#method.cancel) | Cancel |
| [clearAuxMetadata](#method.clearAuxMetadata) | Clears the specified metadata key. |
| [download](#method.download) | Download |
| [getList](#method.getList) | Retrieves list of installed apps matching given filters. |
| [getLockInfo](#method.getLockInfo) | Provides lock reason and owner for an app. |
| [getMetadata](#method.getMetadata) | Retrieves metadata and auxiliary resource list for an application. |
| [getProgress](#method.getProgress) | Provides the current progress of an ongoing operation. |
| [getStorageDetails](#method.getStorageDetails) | GetStorageDetails |
| [install](#method.install) | Install |
| [lock](#method.lock) | Lock |
| [offer](#method.offer) |  |
| [operationStatusUpdate](#method.operationStatusUpdate) |  |
| [reset](#method.reset) | Deletes all persistent local data of the application. |
| [revoke](#method.revoke) |  |
| [setAuxMetadata](#method.setAuxMetadata) | Sets a key-value pair of metadata for the application. |
| [uninstall](#method.uninstall) | Uninstall |
| [unlock](#method.unlock) | Unlock |
| [config](#method.config) | Config |
| [delete](#method.delete) | Delete |
| [getLockedInfo](#method.getLockedInfo) | GetLockedInfo |
| [listPackages](#method.listPackages) | ListPackages |
| [packageState](#method.packageState) | PackageState |
| [pause](#method.pause) | Pause |
| [progress](#method.progress) | Delete |
| [rateLimit](#method.rateLimit) | RateLimit |
| [resume](#method.resume) | Resume |

<a id="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

Cancel

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
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

<a id="method.clearAuxMetadata"></a>
## *clearAuxMetadata [<sup>method</sup>](#head.Methods)*

Clears the specified metadata key.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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

<a id="method.download"></a>
## *download [<sup>method</sup>](#head.Methods)*

Download

### Events
Event details are missing in the header file documentation.
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
| result.downloadId | string | Download id |

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

<a id="method.getList"></a>
## *getList [<sup>method</sup>](#head.Methods)*

Retrieves list of installed apps matching given filters.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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

<a id="method.getLockInfo"></a>
## *getLockInfo [<sup>method</sup>](#head.Methods)*

Provides lock reason and owner for an app.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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

<a id="method.getMetadata"></a>
## *getMetadata [<sup>method</sup>](#head.Methods)*

Retrieves metadata and auxiliary resource list for an application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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
| result.resources | IPackageManager::IKeyValueIterator |  |
| result.auxMetadata | IPackageManager::IKeyValueIterator |  |

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
        "resources": "",
        "auxMetadata": ""
    }
}
```

<a id="method.getProgress"></a>
## *getProgress [<sup>method</sup>](#head.Methods)*

Provides the current progress of an ongoing operation.

### Events
Event details are missing in the header file documentation.
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

<a id="method.getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head.Methods)*

GetStorageDetails

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.quotaKb | integer |  |
| result.usedKb | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PackageManager.getStorageDetails"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.getStorageDetails"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "quotaKb": 0,
        "usedKb": 0
    }
}
```

<a id="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*

Install

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.additionalMetadata | IPackageInstaller::IKeyValueIterator | Additional Metadata |
| params.fileLocator | string | FileLocator |
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
    "id": 6,
    "method": "org.rdk.PackageManager.install",
    "params": {
        "packageId": "",
        "version": "",
        "additionalMetadata": "",
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PackageManager.install", "params": {"packageId": "", "version": "", "additionalMetadata": "", "fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "failReason": "NONE"
    }
}
```

<a id="method.lock"></a>
## *lock [<sup>method</sup>](#head.Methods)*

Lock

### Events
Event details are missing in the header file documentation.
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
| result.appMetadata | IPackageHandler::ILockIterator | App Metadata |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.lock", "params": {"packageId": "", "version": "", "lockReason": "SYSTEM_APP"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
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
        "appMetadata": ""
    }
}
```

<a id="method.offer"></a>
## *offer [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packagemanager | IPackageManager |  |
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
    "method": "org.rdk.PackageManager.offer",
    "params": {
        "packagemanager": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.offer", "params": {"packagemanager": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.operationStatusUpdate"></a>
## *operationStatusUpdate [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string |  |
| params.operation | string |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string | Version |
| params.status | string |  |
| params.details | string |  |
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
    "method": "org.rdk.PackageManager.operationStatusUpdate",
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.operationStatusUpdate", "params": {"handle": "", "operation": "", "type": "", "id": "", "version": "", "status": "", "details": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*

Deletes all persistent local data of the application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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
    "id": 12,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.reset", "params": {"type": "", "id": "", "version": "", "resetType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.revoke"></a>
## *revoke [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packagemanager | IPackageManager |  |
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
    "method": "org.rdk.PackageManager.revoke",
    "params": {
        "packagemanager": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PackageManager.revoke", "params": {"packagemanager": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.setAuxMetadata"></a>
## *setAuxMetadata [<sup>method</sup>](#head.Methods)*

Sets a key-value pair of metadata for the application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
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
    "id": 14,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PackageManager.setAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.uninstall"></a>
## *uninstall [<sup>method</sup>](#head.Methods)*

Uninstall

### Events
Event details are missing in the header file documentation.
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
    "id": 14,
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "packageId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PackageManager.uninstall", "params": {"packageId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "errorReason": ""
    }
}
```

<a id="method.unlock"></a>
## *unlock [<sup>method</sup>](#head.Methods)*

Unlock

### Events
Event details are missing in the header file documentation.
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
    "id": 15,
    "method": "org.rdk.PackageManager.unlock",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.PackageManager.unlock", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="method.config"></a>
## *config [<sup>method</sup>](#head.Methods)*

Config

### Events
Event details are missing in the header file documentation.
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

<a id="method.delete"></a>
## *delete [<sup>method</sup>](#head.Methods)*

Delete

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | FileLocator |
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

<a id="method.getLockedInfo"></a>
## *getLockedInfo [<sup>method</sup>](#head.Methods)*

GetLockedInfo

### Events
Event details are missing in the header file documentation.
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
    "id": 4,
    "method": "org.rdk.PackageManager.getLockedInfo",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PackageManager.getLockedInfo", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
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

<a id="method.listPackages"></a>
## *listPackages [<sup>method</sup>](#head.Methods)*

ListPackages

### Events
Event details are missing in the header file documentation.
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
    "id": 7,
    "method": "org.rdk.PackageManager.listPackages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PackageManager.listPackages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
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

<a id="method.packageState"></a>
## *packageState [<sup>method</sup>](#head.Methods)*

PackageState

### Events
Event details are missing in the header file documentation.
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
    "id": 9,
    "method": "org.rdk.PackageManager.packageState",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PackageManager.packageState", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "state": "INSTALLING"
    }
}
```

<a id="method.pause"></a>
## *pause [<sup>method</sup>](#head.Methods)*

Pause

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
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
    "method": "org.rdk.PackageManager.pause",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.pause", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.progress"></a>
## *progress [<sup>method</sup>](#head.Methods)*

Delete

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.percent | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.PackageManager.progress",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.progress", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "percent": 0
    }
}
```

<a id="method.rateLimit"></a>
## *rateLimit [<sup>method</sup>](#head.Methods)*

RateLimit

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
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
    "id": 12,
    "method": "org.rdk.PackageManager.rateLimit",
    "params": {
        "downloadId": "",
        "limit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.rateLimit", "params": {"downloadId": "", "limit": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.resume"></a>
## *resume [<sup>method</sup>](#head.Methods)*

Resume

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
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
    "method": "org.rdk.PackageManager.resume",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PackageManager.resume", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PackageManager plugin:

PackageManager interface events:

| Event | Description |
| :-------- | :-------- |
| [operationStatus](#event.operationStatus) | Notifies completion of an asynchronous operation. |

<a id="event.operationStatus"></a>
## *operationStatus [<sup>event</sup>](#head.Notifications)*

Notifies completion of an asynchronous operation.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string |  |
| params.operation | string |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string | Version |
| params.status | string |  |
| params.details | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
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
