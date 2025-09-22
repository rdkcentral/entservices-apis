<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PackageHandler_API"></a>
# PackageHandler API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PackageHandler interface for Thunder framework.

(Defined with IPackageHandler in [IAppPackageManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppPackageManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PackageHandler interface (version 1.0.0). It includes detailed specification about its methods provided.

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

PackageHandler JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PackageHandler interface:

PackageHandler interface methods:

| Method | Description |
| :-------- | :-------- |
| [lock](#method_lock) | Lock |
| [unlock](#method_unlock) | Unlock |
| [getLockedInfo](#method_getLockedInfo) | GetLockedInfo |

<a id="method_lock"></a>
## *lock [<sup>method</sup>](#head_Methods)*

Lock.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |
| params.version | string | mandatory | Version |
| params.lockReason | string | mandatory | LockReason (must be one of the following: *LAUNCH, SYSTEM_APP*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.lockId | integer | mandatory | Lock Id |
| result.unpackedPath | string | mandatory | Unpacked Path |
| result.configMetadata | object | mandatory | Config Metadata |
| result.configMetadata.dial | boolean | mandatory |  |
| result.configMetadata.wanLanAccess | boolean | mandatory |  |
| result.configMetadata.thunder | boolean | mandatory |  |
| result.configMetadata.systemMemoryLimit | integer | mandatory |  |
| result.configMetadata.gpuMemoryLimit | integer | mandatory |  |
| result.configMetadata.envVariables | string | mandatory |  |
| result.configMetadata.userId | integer | mandatory |  |
| result.configMetadata.groupId | integer | mandatory |  |
| result.configMetadata.dataImageSize | integer | mandatory |  |
| result.configMetadata.resourceManagerClientEnabled | boolean | mandatory |  |
| result.configMetadata.dialId | string | mandatory |  |
| result.configMetadata.command | string | mandatory |  |
| result.configMetadata.appType | string | mandatory |  |
| result.configMetadata.appPath | string | mandatory |  |
| result.configMetadata.runtimePath | string | mandatory |  |
| result.configMetadata.logFilePath | string | mandatory |  |
| result.configMetadata.logFileMaxSize | integer | mandatory |  |
| result.configMetadata.logLevels | string | mandatory |  |
| result.configMetadata.mapi | boolean | mandatory |  |
| result.configMetadata.fkpsFiles | string | mandatory |  |
| result.configMetadata.fireboltVersion | string | mandatory |  |
| result.configMetadata.enableDebugger | boolean | mandatory |  |
| result.appMetadata | array | mandatory | App Metadata |
| result.appMetadata[#] | object | mandatory |  |
| result.appMetadata[#].packageId | string | mandatory | PackageId |
| result.appMetadata[#].version | string | mandatory | Version |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.lock",
  "params": {
    "packageId": "...",
    "version": "...",
    "lockReason": "LAUNCH"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "lockId": 0,
    "unpackedPath": "...",
    "configMetadata": {
      "dial": false,
      "wanLanAccess": false,
      "thunder": false,
      "systemMemoryLimit": 0,
      "gpuMemoryLimit": 0,
      "envVariables": "...",
      "userId": 0,
      "groupId": 0,
      "dataImageSize": 0,
      "resourceManagerClientEnabled": false,
      "dialId": "...",
      "command": "...",
      "appType": "...",
      "appPath": "...",
      "runtimePath": "...",
      "logFilePath": "...",
      "logFileMaxSize": 0,
      "logLevels": "...",
      "mapi": false,
      "fkpsFiles": "...",
      "fireboltVersion": "...",
      "enableDebugger": false
    },
    "appMetadata": [
      {
        "packageId": "...",
        "version": "..."
      }
    ]
  }
}
```

<a id="method_unlock"></a>
## *unlock [<sup>method</sup>](#head_Methods)*

Unlock.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |
| params.version | string | mandatory | Version |

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
    "packageId": "...",
    "version": "..."
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

<a id="method_getLockedInfo"></a>
## *getLockedInfo [<sup>method</sup>](#head_Methods)*

GetLockedInfo.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |
| params.version | string | mandatory | Version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.unpackedPath | string | mandatory |  |
| result.configMetadata | object | mandatory |  |
| result.configMetadata.dial | boolean | mandatory |  |
| result.configMetadata.wanLanAccess | boolean | mandatory |  |
| result.configMetadata.thunder | boolean | mandatory |  |
| result.configMetadata.systemMemoryLimit | integer | mandatory |  |
| result.configMetadata.gpuMemoryLimit | integer | mandatory |  |
| result.configMetadata.envVariables | string | mandatory |  |
| result.configMetadata.userId | integer | mandatory |  |
| result.configMetadata.groupId | integer | mandatory |  |
| result.configMetadata.dataImageSize | integer | mandatory |  |
| result.configMetadata.resourceManagerClientEnabled | boolean | mandatory |  |
| result.configMetadata.dialId | string | mandatory |  |
| result.configMetadata.command | string | mandatory |  |
| result.configMetadata.appType | string | mandatory |  |
| result.configMetadata.appPath | string | mandatory |  |
| result.configMetadata.runtimePath | string | mandatory |  |
| result.configMetadata.logFilePath | string | mandatory |  |
| result.configMetadata.logFileMaxSize | integer | mandatory |  |
| result.configMetadata.logLevels | string | mandatory |  |
| result.configMetadata.mapi | boolean | mandatory |  |
| result.configMetadata.fkpsFiles | string | mandatory |  |
| result.configMetadata.fireboltVersion | string | mandatory |  |
| result.configMetadata.enableDebugger | boolean | mandatory |  |
| result.gatewayMetadataPath | string | mandatory |  |
| result.locked | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLockedInfo",
  "params": {
    "packageId": "...",
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
    "unpackedPath": "...",
    "configMetadata": {
      "dial": false,
      "wanLanAccess": false,
      "thunder": false,
      "systemMemoryLimit": 0,
      "gpuMemoryLimit": 0,
      "envVariables": "...",
      "userId": 0,
      "groupId": 0,
      "dataImageSize": 0,
      "resourceManagerClientEnabled": false,
      "dialId": "...",
      "command": "...",
      "appType": "...",
      "appPath": "...",
      "runtimePath": "...",
      "logFilePath": "...",
      "logFileMaxSize": 0,
      "logLevels": "...",
      "mapi": false,
      "fkpsFiles": "...",
      "fireboltVersion": "...",
      "enableDebugger": false
    },
    "gatewayMetadataPath": "...",
    "locked": false
  }
}
```

