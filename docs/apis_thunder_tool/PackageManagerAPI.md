<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PackageManager_API"></a>
# PackageManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PackageManager interface for Thunder framework.

(Defined with IPackageManager in [IPackageManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IPackageManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PackageManager interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

PackageManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PackageManager interface:

PackageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [install](#method_install) | Downloads and installs an application bundle |
| [uninstall](#method_uninstall) | Uninstalls an application |
| [download](#method_download) | Downloads a resource file for an application |
| [reset](#method_reset) | Deletes all persistent local data of the application |
| [getStorageDetails](#method_getStorageDetails) | Retrieves details about app and persistent storage usage |
| [setAuxMetadata](#method_setAuxMetadata) | Sets a key-value pair of metadata for the application |
| [clearAuxMetadata](#method_clearAuxMetadata) | Clears the specified metadata key |
| [getMetadata](#method_getMetadata) | Retrieves metadata and auxiliary resource list for an application |
| [cancel](#method_cancel) | Cancels a previously issued asynchronous request |
| [getProgress](#method_getProgress) | Provides the current progress of an ongoing operation |
| [getList](#method_getList) | Retrieves list of installed apps matching given filters |
| [lock](#method_lock) | Locks an application to prevent uninstallation |
| [unlock](#method_unlock) | Unlocks a previously locked application |
| [getLockInfo](#method_getLockInfo) | Provides lock reason and owner for an app |

<a id="method_install"></a>
## *install [<sup>method</sup>](#head_Methods)*

Downloads and installs an application bundle.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.url | string | mandatory |  |
| params.appName | string | mandatory |  |
| params.category | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.install",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "url": "...",
    "appName": "...",
    "category": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_uninstall"></a>
## *uninstall [<sup>method</sup>](#head_Methods)*

Uninstalls an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.uninstallType | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.uninstall",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "uninstallType": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_download"></a>
## *download [<sup>method</sup>](#head_Methods)*

Downloads a resource file for an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.resKey | string | mandatory |  |
| params.url | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.download",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "resKey": "...",
    "url": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_reset"></a>
## *reset [<sup>method</sup>](#head_Methods)*

Deletes all persistent local data of the application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.resetType | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.reset",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "resetType": "..."
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

<a id="method_getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head_Methods)*

Retrieves details about app and persistent storage usage.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.apps | object | mandatory |  |
| result.apps.path | string | mandatory |  |
| result.apps.quotaKB | string | mandatory |  |
| result.apps.usedKB | string | mandatory |  |
| result.persistent | object | mandatory |  |
| result.persistent.path | string | mandatory |  |
| result.persistent.quotaKB | string | mandatory |  |
| result.persistent.usedKB | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getStorageDetails",
  "params": {
    "type": "...",
    "id": "...",
    "version": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "apps": {
      "path": "...",
      "quotaKB": "...",
      "usedKB": "..."
    },
    "persistent": {
      "path": "...",
      "quotaKB": "...",
      "usedKB": "..."
    }
  }
}
```

<a id="method_setAuxMetadata"></a>
## *setAuxMetadata [<sup>method</sup>](#head_Methods)*

Sets a key-value pair of metadata for the application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.key | string | mandatory |  |
| params.value | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setAuxMetadata",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "key": "...",
    "value": "..."
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

<a id="method_clearAuxMetadata"></a>
## *clearAuxMetadata [<sup>method</sup>](#head_Methods)*

Clears the specified metadata key.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.key | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.clearAuxMetadata",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "key": "..."
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

<a id="method_getMetadata"></a>
## *getMetadata [<sup>method</sup>](#head_Methods)*

Retrieves metadata and auxiliary resource list for an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.metadata | object | mandatory |  |
| result.metadata.appName | string | mandatory |  |
| result.metadata.type | string | mandatory |  |
| result.metadata.category | string | mandatory |  |
| result.metadata.url | string | mandatory |  |
| result.resources | array | mandatory |  |
| result.resources[#] | object | mandatory |  |
| result.resources[#].key | string | mandatory |  |
| result.resources[#].value | string | mandatory |  |
| result.auxMetadata | array | mandatory |  |
| result.auxMetadata[#] | object | mandatory |  |
| result.auxMetadata[#].key | string | mandatory |  |
| result.auxMetadata[#].value | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMetadata",
  "params": {
    "type": "...",
    "id": "...",
    "version": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "metadata": {
      "appName": "...",
      "type": "...",
      "category": "...",
      "url": "..."
    },
    "resources": [
      {
        "key": "...",
        "value": "..."
      }
    ],
    "auxMetadata": [
      {
        "key": "...",
        "value": "..."
      }
    ]
  }
}
```

<a id="method_cancel"></a>
## *cancel [<sup>method</sup>](#head_Methods)*

Cancels a previously issued asynchronous request.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.handle | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.cancel",
  "params": {
    "handle": "..."
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

<a id="method_getProgress"></a>
## *getProgress [<sup>method</sup>](#head_Methods)*

Provides the current progress of an ongoing operation.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.handle | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getProgress",
  "params": {
    "handle": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_getList"></a>
## *getList [<sup>method</sup>](#head_Methods)*

Retrieves list of installed apps matching given filters.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.appName | string | mandatory |  |
| params.category | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory |  |
| result[#] | object | mandatory |  |
| result[#].id | string | mandatory |  |
| result[#].version | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getList",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "appName": "...",
    "category": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "id": "...",
      "version": "..."
    }
  ]
}
```

<a id="method_lock"></a>
## *lock [<sup>method</sup>](#head_Methods)*

Locks an application to prevent uninstallation.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.reason | string | mandatory |  |
| params.owner | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.lock",
  "params": {
    "type": "...",
    "id": "...",
    "version": "...",
    "reason": "...",
    "owner": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_unlock"></a>
## *unlock [<sup>method</sup>](#head_Methods)*

Unlocks a previously locked application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.handle | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unlock",
  "params": {
    "handle": "..."
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

<a id="method_getLockInfo"></a>
## *getLockInfo [<sup>method</sup>](#head_Methods)*

Provides lock reason and owner for an app.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.reason | string | mandatory |  |
| result.owner | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLockInfo",
  "params": {
    "type": "...",
    "id": "...",
    "version": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "reason": "...",
    "owner": "..."
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PackageManager interface:

PackageManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [operationStatus](#notification_operationStatus) | Notifies completion of an asynchronous operation |

<a id="notification_operationStatus"></a>
## *operationStatus [<sup>notification</sup>](#head_Notifications)*

Notifies completion of an asynchronous operation.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.handle | string | mandatory |  |
| params.operation | string | mandatory |  |
| params.type | string | mandatory |  |
| params.id | string | mandatory |  |
| params.version | string | mandatory |  |
| params.status | string | mandatory |  |
| params.details | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "operationStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.operationStatus",
  "params": {
    "handle": "...",
    "operation": "...",
    "type": "...",
    "id": "...",
    "version": "...",
    "status": "...",
    "details": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.operationStatus``.

