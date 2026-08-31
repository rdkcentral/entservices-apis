<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_LISA_API"></a>
# LISA API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

LISA interface for Thunder framework.

(Defined by [LISA.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the LISA interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

LISA JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the LISA interface:

LISA interface methods:

| Method | Description |
| :-------- | :-------- |
| [install](#method_install) | Download the application bundle |
| [uninstall](#method_uninstall) | Uninstall the application |
| [download](#method_download) | Download arbitrary application resource file |
| [reset](#method_reset) | Delete persistent data stored locally |
| [getStorageDetails](#method_getStorageDetails) | Information on the storage usage |
| [getList](#method_getList) | Gets the list of installed applications |
| [setAuxMetadata](#method_setAuxMetadata) | Set an arbitrary metadata |
| [clearAuxMetadata](#method_clearAuxMetadata) | Clears a single metadata, removing its key |
| [getMetadata](#method_getMetadata) | Get application metadata |
| [cancel](#method_cancel) | Cancel asynchronous request |
| [getProgress](#method_getProgress) | Estimated progress of a request |
| [lock](#method_lock) | Lock an application |
| [unlock](#method_unlock) | Unlock an application |
| [getLockInfo](#method_getLockInfo) | Get lock info |

<a id="method_install"></a>
## *install [<sup>method</sup>](#head_Methods)*

Download the application bundle.

Also see: [operationStatus](#event_operationStatus)

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.url | string | mandatory | Application url |
| params.appName | string | mandatory | Application name |
| params.category | string | mandatory | Application category |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Operation handle |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress or other operation pending |
| ```ERROR_BAD_REQUEST``` | Invalid params |
| ```ERROR_ILLEGAL_STATE``` | App already installed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.install",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "url": "http://download.com/bundle1.tgz",
    "appName": "Player",
    "category": "Web browser"
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

Uninstall the application.

Also see: [operationStatus](#event_operationStatus)

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.uninstallType | string | mandatory | Type of the uninstall to perform |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Operation handle |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress or other operation pending |
| ```ERROR_BAD_REQUEST``` | Invalid params |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.uninstall",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "uninstallType": "full"
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

Download arbitrary application resource file.

Also see: [operationStatus](#event_operationStatus)

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.resKey | string | mandatory | Key to access given resource file from db entry |
| params.resUrl | string | mandatory | Url where to download a resource from |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Operation handle |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress or other operation pending |
| ```ERROR_BAD_REQUEST``` | Invalid params |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.download",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "resKey": "...",
    "resUrl": "..."
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

Delete persistent data stored locally.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.resetType | string | mandatory | Type of the reset to perform |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |
| ```ERROR_GENERAL``` | Filesystem Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.reset",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "resetType": "full"
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

Information on the storage usage.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.type | string | optional | Application type (mime-type) |
| params?.id | string | optional | Application ID |
| params?.version | string | optional | Application version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Storage payload - returned as GetStorageDetails method result |
| result.apps | object | mandatory | Storage entry - used in results |
| result.apps.path | string | mandatory | Path in local filesystem |
| result.apps?.quotaKB | string | optional | Number of used kilobytes of storage |
| result.apps.usedKB | string | mandatory | Number of used kilobytes of storage |
| result.persistent | object | mandatory | Storage entry - used in results |
| result.persistent.path | string | mandatory | Path in local filesystem |
| result.persistent?.quotaKB | string | optional | Number of used kilobytes of storage |
| result.persistent.usedKB | string | mandatory | Number of used kilobytes of storage |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |
| ```ERROR_GENERAL``` | Filesystem Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getStorageDetails",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0"
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

<a id="method_getList"></a>
## *getList [<sup>method</sup>](#head_Methods)*

Gets the list of installed applications.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params?.appName | string | optional | Application name |
| params?.category | string | optional | Application category |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Applications payload - returned as GetList method result |
| result.apps | array | mandatory | *...* |
| result.apps[#] | object | mandatory | Application entry - used in results |
| result.apps[#].id | string | mandatory | Application ID |
| result.apps[#].type | string | mandatory | Application type (mime-type) |
| result.apps[#].installed | array | mandatory | *...* |
| result.apps[#].installed[#] | object | mandatory | Installed application variant |
| result.apps[#].installed[#].version | string | mandatory | Application version |
| result.apps[#].installed[#].appName | string | mandatory | Application name |
| result.apps[#].installed[#]?.category | string | optional | Application category |
| result.apps[#].installed[#].url | string | mandatory | Application url |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getList",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "appName": "Player",
    "category": "Web browser"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "apps": [
      {
        "id": "com.lgi.app",
        "type": "application/vnd.rdk-app.dac.native",
        "installed": [
          {
            "version": "1.0",
            "appName": "Player",
            "category": "Web browser",
            "url": "http://download.com/bundle1.tgz"
          }
        ]
      }
    ]
  }
}
```

<a id="method_setAuxMetadata"></a>
## *setAuxMetadata [<sup>method</sup>](#head_Methods)*

Set an arbitrary metadata.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.key | string | mandatory | Metadata key |
| params.value | string | mandatory | Metadata value |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |
| ```ERROR_GENERAL``` | Metadata Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setAuxMetadata",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
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

Clears a single metadata, removing its key.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.key | string | mandatory | Metadata key |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |
| ```ERROR_GENERAL``` | Metadata Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.clearAuxMetadata",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
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

Get application metadata.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Metadata payload - returned as GetMetadata method result |
| result?.appName | string | optional | Application name |
| result?.category | string | optional | Application category |
| result?.url | string | optional | Application url |
| result.resources | array | mandatory | List of key-value entries |
| result.resources[#] | object | mandatory | Struct holding key and value |
| result.resources[#].key | string | mandatory | Key property |
| result.resources[#].value | string | mandatory | Value property |
| result.auxMetadata | array | mandatory | List of key-value entries |
| result.auxMetadata[#] | object | mandatory | Struct holding key and value |
| result.auxMetadata[#].key | string | mandatory | Key property |
| result.auxMetadata[#].value | string | mandatory | Value property |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid params |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getMetadata",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "appName": "Player",
    "category": "Web browser",
    "url": "http://download.com/bundle1.tgz",
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

Cancel asynchronous request.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.handle | string | mandatory | Operation handle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Operation status |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid handle |
| ```ERROR_GENERAL``` | Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.cancel",
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
  "result": "Success"
}
```

<a id="method_getProgress"></a>
## *getProgress [<sup>method</sup>](#head_Methods)*

Estimated progress of a request.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.handle | string | mandatory | Operation handle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Operation progress |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_INPROGRESS``` | LISA initialization in progress |
| ```ERROR_BAD_REQUEST``` | Invalid handle |
| ```ERROR_GENERAL``` | Error |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getProgress",
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

<a id="method_lock"></a>
## *lock [<sup>method</sup>](#head_Methods)*

Lock an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params?.reason | string | optional | Reason for lock |
| params?.owner | string | optional | Owner of lock |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Struct holding handle |
| result.handle | string | mandatory | Operation handle |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_TOO_MANY_REQUESTS``` | LISA initialization in progress or other operation pending |
| ```ERROR_WRONG_PARAMS``` | Invalid params or app not unstalled |
| ```ERROR_APP_UNINSTALLING``` | App is currently being uninstalled |
| ```ERROR_APP_LOCKED``` | App is already locked |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.lock",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "reason": "active",
    "owner": "awc"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "handle": "..."
  }
}
```

<a id="method_unlock"></a>
## *unlock [<sup>method</sup>](#head_Methods)*

Unlock an application.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.handle | string | mandatory | Operation handle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_WRONG_HANDLE``` | Wrong handle or app not locked anymore |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.unlock",
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

Get lock info.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Struct holding lock info |
| result?.reason | string | optional | Reason for lock |
| result?.owner | string | optional | Owner of lock |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_WRONG_PARAMS``` | Invalid params or app not unstalled |
| ```ERROR_WRONG_HANDLE``` | Wrong handle or app not locked anymore |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getLockInfo",
  "params": {
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "reason": "active",
    "owner": "awc"
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the LISA interface:

LISA interface events:

| Notification | Description |
| :-------- | :-------- |
| [operationStatus](#notification_operationStatus) | Notifies about currently pending operation status |

<a id="notification_operationStatus"></a>
## *operationStatus [<sup>notification</sup>](#head_Notifications)*

Notifies about currently pending operation status.

### Description

Register to this event to be notified about current state of the pending operation

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.handle | string | mandatory | Operation handle |
| params.operation | string | mandatory | Operation |
| params.type | string | mandatory | Application type (mime-type) |
| params.id | string | mandatory | Application ID |
| params.version | string | mandatory | Application version |
| params.status | string | mandatory | Operation status |
| params?.details | string | optional | If error occurred this property contains details on what happened |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "operation": "Installing",
    "type": "application/vnd.rdk-app.dac.native",
    "id": "com.lgi.app",
    "version": "1.0",
    "status": "Success",
    "details": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.operationStatus``.

