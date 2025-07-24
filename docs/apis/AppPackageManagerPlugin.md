<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IAppPackageManager_Plugin"></a>
# IAppPackageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IAppPackageManager/CHANGELOG.md)**

A IAppPackageManager plugin for Thunder framework.

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

The `IAppPackageManager` plugin provides an interface for IAppPackageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IAppPackageManager*) |
| classname | string | Class name: *IAppPackageManager* |
| locator | string | Library name: *libWPEFrameworkIAppPackageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IAppPackageManager plugin:

IAppPackageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [Cancel](#method.Cancel) | Cancel |
| [Config](#method.Config) | Config |
| [Delete](#method.Delete) | Delete |
| [Download](#method.Download) | Download |
| [GetLockedInfo](#method.GetLockedInfo) | GetLockedInfo |
| [GetStorageDetails](#method.GetStorageDetails) | GetStorageDetails |
| [Install](#method.Install) | Install |
| [ListPackages](#method.ListPackages) | ListPackages |
| [Lock](#method.Lock) | Lock |
| [PackageState](#method.PackageState) | PackageState |
| [Pause](#method.Pause) | Pause |
| [Progress](#method.Progress) | Delete |
| [RateLimit](#method.RateLimit) | RateLimit |
| [Resume](#method.Resume) | Resume |
| [Uninstall](#method.Uninstall) | Uninstall |
| [Unlock](#method.Unlock) | Unlock |

<a id="method.Cancel"></a>
## *Cancel [<sup>method</sup>](#head.Methods)*

Cancel

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.downloadId | string | Download id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Cancel",
    "params": {
        "downloadId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Config"></a>
## *Config [<sup>method</sup>](#head.Methods)*

Config

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | int32_t |  |
| result.configMetadata.gpuMemoryLimit | int32_t |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | uint32_t |  |
| result.configMetadata.groupId | uint32_t |  |
| result.configMetadata.dataImageSize | uint32_t |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | uint32_t |  |
| result.configMetadata.logLevels | std::string |  |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string |  |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Config",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "configMetadata": {
            "dial": "true",
            "wanLanAccess": "true",
            "thunder": "true",
            "systemMemoryLimit": "0",
            "gpuMemoryLimit": "0",
            "envVariables": "",
            "userId": "0",
            "groupId": "0",
            "dataImageSize": "0",
            "resourceManagerClientEnabled": "true",
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": "0",
            "logLevels": "",
            "mapi": "true",
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": "true"
        }
    }
}
```
<a id="method.Delete"></a>
## *Delete [<sup>method</sup>](#head.Methods)*

Delete

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.fileLocator | string | FileLocator |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Delete",
    "params": {
        "fileLocator": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Download"></a>
## *Download [<sup>method</sup>](#head.Methods)*

Download

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.url | string | Download url |
| params.options | Options | Download options |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.downloadId | DownloadId |  |
| result.downloadId.downloadId | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Download",
    "params": {
        "url": "",
        "options": {}
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "downloadId": {
            "downloadId": ""
        }
    }
}
```
<a id="method.GetLockedInfo"></a>
## *GetLockedInfo [<sup>method</sup>](#head.Methods)*

GetLockedInfo

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.unpackedPath | string | Unpacked Path |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | int32_t |  |
| result.configMetadata.gpuMemoryLimit | int32_t |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | uint32_t |  |
| result.configMetadata.groupId | uint32_t |  |
| result.configMetadata.dataImageSize | uint32_t |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | uint32_t |  |
| result.configMetadata.logLevels | std::string |  |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string |  |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |
| result.gatewayMetadataPath | string |  |
| result.locked | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.GetLockedInfo",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "unpackedPath": "",
        "configMetadata": {
            "dial": "true",
            "wanLanAccess": "true",
            "thunder": "true",
            "systemMemoryLimit": "0",
            "gpuMemoryLimit": "0",
            "envVariables": "",
            "userId": "0",
            "groupId": "0",
            "dataImageSize": "0",
            "resourceManagerClientEnabled": "true",
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": "0",
            "logLevels": "",
            "mapi": "true",
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": "true"
        },
        "gatewayMetadataPath": "",
        "locked": "true"
    }
}
```
<a id="method.GetStorageDetails"></a>
## *GetStorageDetails [<sup>method</sup>](#head.Methods)*

GetStorageDetails

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.quotaKb | uint32_t |  |
| result.usedKb | uint32_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.GetStorageDetails"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "quotaKb": "0",
        "usedKb": "0"
    }
}
```
<a id="method.Install"></a>
## *Install [<sup>method</sup>](#head.Methods)*

Install

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.additionalMetadata | IPackageInstaller::IKeyValueIterator | Additional Metadata |
| params.fileLocator | string | FileLocator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.failReason | FailReason |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Install",
    "params": {
        "packageId": "",
        "version": "",
        "additionalMetadata": "",
        "fileLocator": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "failReason": "NONE"
    }
}
```
<a id="method.ListPackages"></a>
## *ListPackages [<sup>method</sup>](#head.Methods)*

ListPackages

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.packages | IPackageIterator |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.ListPackages"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "packages": [
            {}
        ]
    }
}
```
<a id="method.Lock"></a>
## *Lock [<sup>method</sup>](#head.Methods)*

Lock

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.lockReason | LockReason | LockReason |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.lockId | uint32_t | Lock Id |
| result.unpackedPath | string | Unpacked Path |
| result.configMetadata | RuntimeConfig | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | int32_t |  |
| result.configMetadata.gpuMemoryLimit | int32_t |  |
| result.configMetadata.envVariables | std::string |  |
| result.configMetadata.userId | uint32_t |  |
| result.configMetadata.groupId | uint32_t |  |
| result.configMetadata.dataImageSize | uint32_t |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | std::string |  |
| result.configMetadata.command | std::string |  |
| result.configMetadata.appType | std::string |  |
| result.configMetadata.appPath | std::string |  |
| result.configMetadata.runtimePath | std::string |  |
| result.configMetadata.logFilePath | std::string |  |
| result.configMetadata.logFileMaxSize | uint32_t |  |
| result.configMetadata.logLevels | std::string |  |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | std::string |  |
| result.configMetadata.fireboltVersion | std::string |  |
| result.configMetadata.enableDebugger | bool |  |
| result.appMetadata | IPackageHandler::ILockIterator | App Metadata XXX: appContextPath ?! |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Lock",
    "params": {
        "packageId": "",
        "version": "",
        "lockReason": "SYSTEM_APP"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "lockId": "0",
        "unpackedPath": "",
        "configMetadata": {
            "dial": "true",
            "wanLanAccess": "true",
            "thunder": "true",
            "systemMemoryLimit": "0",
            "gpuMemoryLimit": "0",
            "envVariables": "",
            "userId": "0",
            "groupId": "0",
            "dataImageSize": "0",
            "resourceManagerClientEnabled": "true",
            "dialId": "",
            "command": "",
            "appType": "",
            "appPath": "",
            "runtimePath": "",
            "logFilePath": "",
            "logFileMaxSize": "0",
            "logLevels": "",
            "mapi": "true",
            "fkpsFiles": "",
            "fireboltVersion": "",
            "enableDebugger": "true"
        },
        "appMetadata": ""
    }
}
```
<a id="method.PackageState"></a>
## *PackageState [<sup>method</sup>](#head.Methods)*

PackageState

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.state | InstallState |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.PackageState",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "state": "INSTALLING"
    }
}
```
<a id="method.Pause"></a>
## *Pause [<sup>method</sup>](#head.Methods)*

Pause

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.downloadId | string | Download id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Pause",
    "params": {
        "downloadId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Progress"></a>
## *Progress [<sup>method</sup>](#head.Methods)*

Delete

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.downloadId | string | Download id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.percent | Percent |  |
| result.percent.percent | uint8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Progress",
    "params": {
        "downloadId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "percent": {
            "percent": ""
        }
    }
}
```
<a id="method.RateLimit"></a>
## *RateLimit [<sup>method</sup>](#head.Methods)*

RateLimit

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.downloadId | string | Download id |
| params.limit | uint64_t | Limit |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.RateLimit",
    "params": {
        "downloadId": "",
        "limit": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Resume"></a>
## *Resume [<sup>method</sup>](#head.Methods)*

Resume

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.downloadId | string | Download id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Resume",
    "params": {
        "downloadId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Uninstall"></a>
## *Uninstall [<sup>method</sup>](#head.Methods)*

Uninstall

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.errorReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Uninstall",
    "params": {
        "packageId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "errorReason": ""
    }
}
```
<a id="method.Unlock"></a>
## *Unlock [<sup>method</sup>](#head.Methods)*

Unlock

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.packageId | string | Package Id |
| params.version | string | Version |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IAppPackageManager.Unlock",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

