<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PackageInstaller_API"></a>
# PackageInstaller API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PackageInstaller interface for Thunder framework.

(Defined with IPackageInstaller in [IAppPackageManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAppPackageManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PackageInstaller interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

PackageInstaller JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PackageInstaller interface:

PackageInstaller interface methods:

| Method | Description |
| :-------- | :-------- |
| [install](#method_install) | Install |
| [uninstall](#method_uninstall) | Uninstall |
| [listPackages](#method_listPackages) | ListPackages |
| [config](#method_config) | Config |
| [packageState](#method_packageState) | PackageState |

<a id="method_install"></a>
## *install [<sup>method</sup>](#head_Methods)*

Install.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |
| params.version | string | mandatory | Version |
| params.additionalMetadata | array | mandatory | Additional Metadata |
| params.additionalMetadata[#] | object | mandatory |  |
| params.additionalMetadata[#].name | string | mandatory | Name |
| params.additionalMetadata[#].value | string | mandatory | Value |
| params.fileLocator | string | mandatory | File Locator |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  (must be one of the following: *INVALID_METADATA_FAILURE, NONE, PACKAGE_MISMATCH_FAILURE, PERSISTENCE_FAILURE, SIGNATURE_VERIFICATION_FAILURE*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.install",
  "params": {
    "packageId": "...",
    "version": "...",
    "additionalMetadata": [
      {
        "name": "...",
        "value": "..."
      }
    ],
    "fileLocator": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "SIGNATURE_VERIFICATION_FAILURE"
}
```

<a id="method_uninstall"></a>
## *uninstall [<sup>method</sup>](#head_Methods)*

Uninstall.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |

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
    "packageId": "..."
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

<a id="method_listPackages"></a>
## *listPackages [<sup>method</sup>](#head_Methods)*

ListPackages.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory |  |
| result[#] | object | mandatory |  |
| result[#].packageId | string | mandatory | PackageId |
| result[#].version | string | mandatory | Version |
| result[#].state | string | mandatory | State (must be one of the following: *INSTALLATION_BLOCKED, INSTALLED, INSTALLING, INSTALL_FAILURE, UNINSTALLED, UNINSTALLING, UNINSTALL_FAILURE*) |
| result[#].digest | string | mandatory | Digest |
| result[#].sizeKb | integer | mandatory | SizeKb |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.listPackages"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "packageId": "...",
      "version": "...",
      "state": "INSTALLATION_BLOCKED",
      "digest": "...",
      "sizeKb": 0
    }
  ]
}
```

<a id="method_config"></a>
## *config [<sup>method</sup>](#head_Methods)*

Config.

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
| result.dial | boolean | mandatory |  |
| result.wanLanAccess | boolean | mandatory |  |
| result.thunder | boolean | mandatory |  |
| result.systemMemoryLimit | integer | mandatory |  |
| result.gpuMemoryLimit | integer | mandatory |  |
| result.envVariables | string | mandatory |  |
| result.userId | integer | mandatory |  |
| result.groupId | integer | mandatory |  |
| result.dataImageSize | integer | mandatory |  |
| result.resourceManagerClientEnabled | boolean | mandatory |  |
| result.dialId | string | mandatory |  |
| result.command | string | mandatory |  |
| result.appType | string | mandatory |  |
| result.appPath | string | mandatory |  |
| result.runtimePath | string | mandatory |  |
| result.logFilePath | string | mandatory |  |
| result.logFileMaxSize | integer | mandatory |  |
| result.logLevels | string | mandatory |  |
| result.mapi | boolean | mandatory |  |
| result.fkpsFiles | string | mandatory |  |
| result.fireboltVersion | string | mandatory |  |
| result.enableDebugger | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.config",
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
  }
}
```

<a id="method_packageState"></a>
## *packageState [<sup>method</sup>](#head_Methods)*

PackageState.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.packageId | string | mandatory | Package Id |
| params.version | string | mandatory | Version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  (must be one of the following: *INSTALLATION_BLOCKED, INSTALLED, INSTALLING, INSTALL_FAILURE, UNINSTALLED, UNINSTALLING, UNINSTALL_FAILURE*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.packageState",
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
  "result": "INSTALLATION_BLOCKED"
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PackageInstaller interface:

PackageInstaller interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppInstallationStatus](#notification_onAppInstallationStatus) | Signal changes on the status |

<a id="notification_onAppInstallationStatus"></a>
## *onAppInstallationStatus [<sup>notification</sup>](#head_Notifications)*

Signal changes on the status.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.jsonresponse | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAppInstallationStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppInstallationStatus",
  "params": {
    "jsonresponse": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppInstallationStatus``.

