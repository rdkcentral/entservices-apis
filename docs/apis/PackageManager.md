<!-- Generated automatically, DO NOT EDIT! -->
<a id="PackageManager_Module"></a>
# PackageManager Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PackageManager/IPackageManager.h)**

A PackageManager module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IPackageManager](#IPackageManager)
    - [Methods](#IPackageManager-Methods)
    - [Notifications](#IPackageManager-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PackageManager` module provides the following interface(s):

- IPackageManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PackageManager) |
| classname | string | Class name: *PackageManager* |
| locator | string | Library name: *libWPEFrameworkPackageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IPackageManager"></a>
## IPackageManager Interface

<a id="IPackageManager-Methods"></a>
### Methods

The following methods are provided by the IPackageManager Interface:

| Method | Description |
| :-------- | :-------- |
| [cancel](#cancel) | Cancels a previously issued asynchronous request. |
| [clearAuxMetadata](#clearAuxMetadata) | Clears the specified metadata key. |
| [download](#download) | Downloads a resource file for an application. |
| [getList](#getList) | Retrieves list of installed apps matching given filters. |
| [getLockInfo](#getLockInfo) | Provides lock reason and owner for an app. |
| [getMetadata](#getMetadata) | Retrieves metadata and auxiliary resource list for an application. |
| [getProgress](#getProgress) | Provides the current progress of an ongoing operation. |
| [getStorageDetails](#getStorageDetails) | Retrieves details about app and persistent storage usage. |
| [install](#install) | Downloads and installs an application bundle. |
| [lock](#lock) | Locks an application to prevent uninstallation. |
| [reset](#reset) | Deletes all persistent local data of the application. |
| [setAuxMetadata](#setAuxMetadata) | Sets a key-value pair of metadata for the application. |
| [uninstall](#uninstall) | Uninstalls an application. |
| [unlock](#unlock) | Unlocks a previously locked application. |

<a id="cancel"></a>
## *cancel*

Requests cancellation of an operation identified by its handle.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | Handle returned when the asynchronous operation was started. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.PackageManager.cancel",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.PackageManager.cancel", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "The operation could not be cancelled."
    }
}
```

<a id="clearAuxMetadata"></a>
## *clearAuxMetadata*

Removes the specified auxiliary metadata key for the identified application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
| params.key | string | Auxiliary metadata key to remove. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.PackageManager.clearAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": "customKey"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.PackageManager.clearAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "customKey"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "The auxiliary metadata key could not be cleared."
    }
}
```

<a id="download"></a>
## *download*

Starts an asynchronous download of the resource identified by resKey for the specified application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
| params.resKey | string | Key identifying the resource to download. |
| params.url | string | URL from which the resource is downloaded. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string | Output handle identifying the asynchronous download request. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.PackageManager.download",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resKey": "resource-key-123",
        "url": "http://example.com/resource"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.PackageManager.download", "params": {"type": "", "id": "", "version": "", "resKey": "resource-key-123", "url": "http://example.com/resource"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": {
        "handle": ""
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 1,
        "message": "The download request could not be started."
    }
}
```

<a id="getList"></a>
## *getList*

Returns the identifiers and versions of installed applications matching the supplied filters.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type filter; an empty value does not restrict by type. |
| params.id | string | Application identifier filter; an empty value does not restrict by identifier. |
| params.version | string | Application version filter; an empty value does not restrict by version. |
| params.appName | string | Application name filter; an empty value does not restrict by name. |
| params.category | string | Application category filter; an empty value does not restrict by category. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.installedIds | array | Output iterator over matching application identifiers and versions. |
| result.installedIds[#].id | string |  |
| result.installedIds[#].version | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.PackageManager.getList", "params": {"type": "", "id": "", "version": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": [
        {
            "id": "",
            "version": ""
        }
    ]
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "error": {
        "code": 1,
        "message": "The installed application list could not be retrieved."
    }
}
```

<a id="getLockInfo"></a>
## *getLockInfo*

Retrieves the reason and owner recorded for the specified application's lock.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | Output containing the lock reason and owner. |
| result.result.reason | string |  |
| result.result.owner | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.PackageManager.getLockInfo", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "reason": "",
        "owner": ""
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "error": {
        "code": 1,
        "message": "Lock details could not be retrieved."
    }
}
```

<a id="getMetadata"></a>
## *getMetadata*

Returns the application's base metadata together with its resource and auxiliary metadata key-value entries.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.metadata | object | Output containing the application's name, type, category, and URL. |
| result.metadata.appName | string |  |
| result.metadata.type | string |  |
| result.metadata.category | string |  |
| result.metadata.url | string |  |
| result.resources | array | Output iterator over the application's resource key-value pairs. |
| result.resources[#].key | string |  |
| result.resources[#].value | string |  |
| result.auxMetadata | array | Output iterator over the application's auxiliary metadata key-value pairs. |
| result.auxMetadata[#].key | string |  |
| result.auxMetadata[#].value | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.PackageManager.getMetadata", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": {
        "metadata": {
            "appName": "Example App",
            "type": "apk",
            "category": "Utilities",
            "url": "https://example.com/app"
        },
        "resources": [
            {
                "key": "icon",
                "value": "https://example.com/icon.png"
            }
        ],
        "auxMetadata": [
            {
                "key": "customKey",
                "value": "customValue"
            }
        ]
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "error": {
        "code": 1,
        "message": "Metadata or resource lists could not be retrieved."
    }
}
```

<a id="getProgress"></a>
## *getProgress*

Queries the current progress percentage for the asynchronous operation represented by the handle.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | Handle returned when the asynchronous operation was started. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.progress | integer | Output progress value for the operation. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.PackageManager.getProgress",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.PackageManager.getProgress", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": {
        "progress": 50
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "error": {
        "code": 1,
        "message": "Progress could not be retrieved."
    }
}
```

<a id="getStorageDetails"></a>
## *getStorageDetails*

Returns storage paths and usage information for the application's app and persistent storage areas.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storageinfo | object | Output containing storage details for app and persistent data. |
| result.storageinfo.EXTERNAL | string |  |
| result.storageinfo.path | string |  |
| result.storageinfo.quotaKB | string |  |
| result.storageinfo.usedKB | string |  |
| result.storageinfo.apps | string |  |
| result.storageinfo.persistent | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.PackageManager.getStorageDetails",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.PackageManager.getStorageDetails", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": {
        "apps": {
            "path": "",
            "quotaKB": "",
            "usedKB": ""
        },
        "persistent": {
            "path": "",
            "quotaKB": "",
            "usedKB": ""
        }
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "error": {
        "code": 1,
        "message": "Storage details could not be retrieved."
    }
}
```

<a id="install"></a>
## *install*

Starts an asynchronous installation using the supplied package identity and bundle metadata. The returned handle can be used to query progress or cancel the operation; completion is reported through operationStatus.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application bundle. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application to install. |
| params.url | string | URL from which the application bundle is downloaded. |
| params.appName | string | Display name of the application. |
| params.category | string | Application category. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string | Output handle identifying the asynchronous installation request. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.PackageManager.install",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "url": "http://example.com/resource",
        "appName": "",
        "category": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.PackageManager.install", "params": {"type": "", "id": "", "version": "", "url": "http://example.com/resource", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": {
        "handle": ""
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "error": {
        "code": 1,
        "message": "The installation request could not be started."
    }
}
```

<a id="lock"></a>
## *lock*

Creates a lock for the specified application so it cannot be uninstalled; the returned handle identifies the lock request.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
| params.reason | string | Explanation for the lock. |
| params.owner | string | Owner requesting the lock. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string | Output handle identifying the lock. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.PackageManager.lock", "params": {"type": "", "id": "", "version": "", "reason": "", "owner": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": {
        "handle": ""
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "error": {
        "code": 1,
        "message": "The application could not be locked."
    }
}
```

<a id="reset"></a>
## *reset*

Resets the persistent local state associated with the specified application using the requested reset mode.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
| params.resetType | string | Reset mode to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.PackageManager.reset",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resetType": "full"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.PackageManager.reset", "params": {"type": "", "id": "", "version": "", "resetType": "full"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "error": {
        "code": 1,
        "message": "The application state could not be reset."
    }
}
```

<a id="setAuxMetadata"></a>
## *setAuxMetadata*

Stores or replaces the auxiliary metadata value associated with the specified application and key.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application. |
| params.key | string | Auxiliary metadata key to set. |
| params.value | string | Value to associate with the key. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.PackageManager.setAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": "customKey",
        "value": "customValue"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.PackageManager.setAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "customKey", "value": "customValue"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "error": {
        "code": 1,
        "message": "The auxiliary metadata could not be set."
    }
}
```

<a id="uninstall"></a>
## *uninstall*

Starts an asynchronous uninstall request for the specified application and uninstall mode. Completion is reported through operationStatus.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string | Package type used to identify the application. |
| params.id | string | Unique identifier of the application. |
| params.version | string | Version of the application to uninstall. |
| params.uninstallType | string | Uninstall mode to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string | Output handle identifying the asynchronous uninstall request. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "uninstallType": "full"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.PackageManager.uninstall", "params": {"type": "", "id": "", "version": "", "uninstallType": "full"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "result": {
        "handle": ""
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "error": {
        "code": 1,
        "message": "The uninstall request could not be started."
    }
}
```

<a id="unlock"></a>
## *unlock*

Removes the lock identified by the supplied handle, allowing the application to be uninstalled again.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | Handle identifying the lock to remove. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "method": "org.rdk.PackageManager.unlock",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.PackageManager.unlock", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "error": {
        "code": 1,
        "message": "The application lock could not be removed."
    }
}
```

<a id="IPackageManager-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IPackageManager Interface:

| Event | Description |
| :-------- | :-------- |
| [operationStatus](#operationStatus) | Notifies completion of an asynchronous operation. |

<a id="operationStatus"></a>
## *operationStatus*

Broadcasts the outcome and identifying information for a completed package operation to registered observers.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string | Handle identifying the asynchronous operation. |
| params.operation | string | Name of the operation that completed. |
| params.type | string | Package type associated with the operation. |
| params.id | string | Unique application identifier. |
| params.version | string | Application version associated with the operation. |
| params.status | string | Completion status of the operation. |
| params.details | string | Additional status details, if available. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.PackageManager.operationStatus",
    "params": {
        "handle": "",
        "operation": "install",
        "type": "",
        "id": "",
        "version": "",
        "status": "success",
        "details": "Operation completed without errors."
    }
}
```

