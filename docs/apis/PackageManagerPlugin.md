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
| [cancel](#method.cancel) | Cancel asynchronous request. |
| [clearAuxMetadata](#method.clearAuxMetadata) | Clears an arbitrary metadata. |
| [download](#method.download) | Download arbitrary application's resource file. |
| [getList](#method.getList) | List installed applications. |
| [getLockInfo](#method.getLockInfo) | Get lock info. |
| [getMetadata](#method.getMetadata) | Get application metadata. |
| [getProgress](#method.getProgress) | Estimated progress of a request. |
| [getStorageDetails](#method.getStorageDetails) | Information on the storage usage. |
| [install](#method.install) | Download the application bundle. |
| [lock](#method.lock) | Lock the application. Preventing uninstallation. |
| [offer](#method.offer) |  |
| [operationStatusUpdate](#method.operationStatusUpdate) |  |
| [reset](#method.reset) | Delete persistent data stored locally. |
| [revoke](#method.revoke) |  |
| [setAuxMetadata](#method.setAuxMetadata) | Set an arbitrary metadata. |
| [uninstall](#method.uninstall) | Uninstall the application. |
| [unlock](#method.unlock) | Unlock application. |

<a id="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

Cancel asynchronous request.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PackageManager.cancel",
    "params": {
        "handle": ""
    }
}
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

Clears an arbitrary metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.key | string | - |
### Results
This method returns no results.

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

Download arbitrary application's resource file.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.resKey | string | - |
| params.url | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PackageManager.download",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resKey": "",
        "url": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
}
```

<a id="method.getList"></a>
## *getList [<sup>method</sup>](#head.Methods)*

List installed applications.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.appName | string | - |
| params.category | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.installedIds | IPackageKeyIterator | - |
| result.installedIds[#].id | string | - |
| result.installedIds[#].version | string | - |

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

Get lock info.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | LockInfo | - |
| result.result.reason | string | - |
| result.result.owner | string | - |

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

Get application metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.metadata | MetadataPayload | - |
| result.metadata.appName | string | - |
| result.metadata.type | string | - |
| result.metadata.category | string | - |
| result.metadata.url | string | - |
| result.resources | IPackageManager::IKeyValueIterator | - |
| result.auxMetadata | IPackageManager::IKeyValueIterator | - |

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

Estimated progress of a request.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.progress | uint32_t | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": 0
}
```

<a id="method.getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head.Methods)*

Information on the storage usage.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storageinfo | StorageInfo | - |
| result.storageinfo.EXTERNAL | struct | - |
| result.storageinfo.path | string | - |
| result.storageinfo.quotaKB | string | - |
| result.storageinfo.usedKB | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PackageManager.getStorageDetails",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "EXTERNAL": "",
        "path": "",
        "quotaKB": "",
        "usedKB": ""
    }
}
```

<a id="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*

Download the application bundle.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.url | string | - |
| params.appName | string | - |
| params.category | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.PackageManager.install",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "url": "",
        "appName": "",
        "category": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": ""
}
```

<a id="method.lock"></a>
## *lock [<sup>method</sup>](#head.Methods)*

Lock the application. Preventing uninstallation.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.reason | string | - |
| params.owner | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.PackageManager.lock",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "reason": "",
        "owner": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": ""
}
```

<a id="method.offer"></a>
## *offer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packagemanager | IPackageManager | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | - |
| params.operation | string | - |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.status | string | - |
| params.details | string | - |
### Results
This method returns no results.

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

Delete persistent data stored locally.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.resetType | string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packagemanager | IPackageManager | - |
### Results
This method returns no results.

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

Set an arbitrary metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.key | string | - |
| params.value | string | - |
### Results
This method returns no results.

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

Uninstall the application.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.uninstallType | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "uninstallType": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": ""
}
```

<a id="method.unlock"></a>
## *unlock [<sup>method</sup>](#head.Methods)*

Unlock application.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.PackageManager.unlock",
    "params": {
        "handle": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
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
| [operationStatus](#event.operationStatus) | Completion of asynchronous operation. |

<a id="event.operationStatus"></a>
## *operationStatus [<sup>event</sup>](#head.Notifications)*

Completion of asynchronous operation.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | - |
| params.operation | string | - |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.status | string | - |
| params.details | string | - |

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
