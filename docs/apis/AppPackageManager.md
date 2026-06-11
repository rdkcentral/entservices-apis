<!-- Generated automatically, DO NOT EDIT! -->
<a id="AppPackageManager_Plugin"></a>
# AppPackageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AppPackageManager/IAppPackageManager.h)**

A AppPackageManager plugin for Thunder framework.

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

The `AppPackageManager` plugin provides an interface for AppPackageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppPackageManager) |
| classname | string | Class name: *AppPackageManager* |
| locator | string | Library name: *libWPEFrameworkAppPackageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the AppPackageManager plugin:

AppPackageManager interface methods:

**IPackageDownloader methods**

| Method | Description |
| :-------- | :-------- |
| [cancel](#cancel) | Cancel |
| [delete](#delete) | Delete |
| [download](#download) | Download |
| [getStorageInformation](#getStorageInformation) | GetStorageInformation |
| [pause](#pause) | Pause |
| [progress](#progress) | Progress |
| [rateLimit](#rateLimit) | RateLimit |
| [resume](#resume) | Resume |

---

**IPackageInstaller methods**

| Method | Description |
| :-------- | :-------- |
| [config](#config) | Config |
| [getConfigForPackage](#getConfigForPackage) | getConfigForPackage |
| [install](#install) | Install |
| [listPackages](#listPackages) | ListPackages |
| [packageState](#packageState) | PackageState |
| [uninstall](#uninstall) | Uninstall |

<a id="IPackageDownloader-methods"></a>
### IPackageDownloader Methods

<a id="cancel"></a>
## *cancel*

Cancel

### Events Triggered
None
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
    "method": "org.rdk.AppPackageManager.cancel",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AppPackageManager.cancel", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="delete"></a>
## *delete*

Delete

### Events Triggered
None
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
    "id": 1,
    "method": "org.rdk.AppPackageManager.delete",
    "params": {
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AppPackageManager.delete", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
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

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.url | string | Download url |
| params.options | object | Download options |
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
    "id": 2,
    "method": "org.rdk.AppPackageManager.download",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AppPackageManager.download", "params": {"url": "", "options": {"priority": true, "retries": 0, "rateLimit": 0}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "downloadId": ""
    }
}
```

<a id="getStorageInformation"></a>
## *getStorageInformation*

GetStorageInformation

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.quotaKb | integer | Storage quota in kilobytes |
| result.usedKb | integer | Used storage in kilobytes |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AppPackageManager.getStorageInformation"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AppPackageManager.getStorageInformation"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "quotaKb": 0,
        "usedKb": 0
    }
}
```

<a id="pause"></a>
## *pause*

Pause

### Events Triggered
None
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
    "id": 4,
    "method": "org.rdk.AppPackageManager.pause",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AppPackageManager.pause", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="progress"></a>
## *progress*

Progress

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download id |
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
    "id": 5,
    "method": "org.rdk.AppPackageManager.progress",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.AppPackageManager.progress", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "progress": 0
    }
}
```

<a id="rateLimit"></a>
## *rateLimit*

RateLimit

### Events Triggered
None
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
    "id": 6,
    "method": "org.rdk.AppPackageManager.rateLimit",
    "params": {
        "downloadId": "",
        "limit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.AppPackageManager.rateLimit", "params": {"downloadId": "", "limit": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="resume"></a>
## *resume*

Resume

### Events Triggered
None
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
    "id": 7,
    "method": "org.rdk.AppPackageManager.resume",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AppPackageManager.resume", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

---

<a id="IPackageInstaller-methods"></a>
### IPackageInstaller Methods

<a id="config"></a>
## *config*

Config

### Events Triggered
None
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
| result.configMetadata | object | Config Metadata |
| result.configMetadata.dial | bool |  |
| result.configMetadata.wanLanAccess | bool |  |
| result.configMetadata.thunder | bool |  |
| result.configMetadata.systemMemoryLimit | integer |  |
| result.configMetadata.gpuMemoryLimit | integer |  |
| result.configMetadata.envVariables | string |  |
| result.configMetadata.userId | integer |  |
| result.configMetadata.groupId | integer |  |
| result.configMetadata.dataImageSize | integer |  |
| result.configMetadata.resourceManagerClientEnabled | bool |  |
| result.configMetadata.dialId | string |  |
| result.configMetadata.command | string |  |
| result.configMetadata.appType | string |  |
| result.configMetadata.appPath | string |  |
| result.configMetadata.runtimePath | string |  |
| result.configMetadata.logFilePath | string |  |
| result.configMetadata.logFileMaxSize | integer |  |
| result.configMetadata.logLevels | string | json array of strings |
| result.configMetadata.mapi | bool |  |
| result.configMetadata.fkpsFiles | string | json array of strings |
| result.configMetadata.capabilities | string | Comma-separated lowercase runtime capability tokens supported by the application runtime |
| result.configMetadata.ralfPkgPath | string | Filesystem path containing metadata information for RALF packages |
| result.configMetadata.fireboltVersion | string |  |
| result.configMetadata.enableDebugger | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.AppPackageManager.config",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AppPackageManager.config", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
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
        "capabilities": "",
        "ralfPkgPath": "",
        "fireboltVersion": "",
        "enableDebugger": true
    }
}
```

<a id="getConfigForPackage"></a>
## *getConfigForPackage*

getConfigForPackage

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | locator of package |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.id | string | package id |
| result.version | string | version of package |
| result.config | object | metadata of package |
| result.config.dial | bool |  |
| result.config.wanLanAccess | bool |  |
| result.config.thunder | bool |  |
| result.config.systemMemoryLimit | integer |  |
| result.config.gpuMemoryLimit | integer |  |
| result.config.envVariables | string |  |
| result.config.userId | integer |  |
| result.config.groupId | integer |  |
| result.config.dataImageSize | integer |  |
| result.config.resourceManagerClientEnabled | bool |  |
| result.config.dialId | string |  |
| result.config.command | string |  |
| result.config.appType | string |  |
| result.config.appPath | string |  |
| result.config.runtimePath | string |  |
| result.config.logFilePath | string |  |
| result.config.logFileMaxSize | integer |  |
| result.config.logLevels | string | json array of strings |
| result.config.mapi | bool |  |
| result.config.fkpsFiles | string | json array of strings |
| result.config.capabilities | string | Comma-separated lowercase runtime capability tokens supported by the application runtime |
| result.config.ralfPkgPath | string | Filesystem path containing metadata information for RALF packages |
| result.config.fireboltVersion | string |  |
| result.config.enableDebugger | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.AppPackageManager.getConfigForPackage",
    "params": {
        "fileLocator": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AppPackageManager.getConfigForPackage", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
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
            "capabilities": "",
            "ralfPkgPath": "",
            "fireboltVersion": "",
            "enableDebugger": true
        }
    }
}
```

<a id="install"></a>
## *install*

Install

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Version |
| params.additionalMetadata | array | Additional Metadata |
| params.additionalMetadata[#].name | string |  |
| params.additionalMetadata[#].value | string |  |
| params.fileLocator | string | File Locator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.failReason | string | Possible values: NONE, GENERAL_FAILURE, SIGNATURE_VERIFICATION_FAILURE, PACKAGE_MISMATCH_FAILURE, INVALID_METADATA_FAILURE, PERSISTENCE_FAILURE |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.AppPackageManager.install",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AppPackageManager.install", "params": {"packageId": "", "version": "", "additionalMetadata": [{"name": "", "value": ""}], "fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "failReason": "NONE"
    }
}
```

<a id="listPackages"></a>
## *listPackages*

ListPackages

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.packages | array |  |
| result.packages[#].packageId | string |  |
| result.packages[#].version | string |  |
| result.packages[#].state | string | Possible values: INSTALLING, INSTALLATION_BLOCKED, INSTALL_FAILURE, INSTALLED, UNINSTALLING, UNINSTALL_BLOCKED, UNINSTALL_FAILURE, UNINSTALLED |
| result.packages[#].digest | string |  |
| result.packages[#].sizeKb | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.AppPackageManager.listPackages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AppPackageManager.listPackages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
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

### Events Triggered
None
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
| result.state | string | Possible values: INSTALLING, INSTALLATION_BLOCKED, INSTALL_FAILURE, INSTALLED, UNINSTALLING, UNINSTALL_BLOCKED, UNINSTALL_FAILURE, UNINSTALLED |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.AppPackageManager.packageState",
    "params": {
        "packageId": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AppPackageManager.packageState", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "state": "INSTALLING"
    }
}
```

<a id="uninstall"></a>
## *uninstall*

Uninstall

### Events Triggered
None
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
    "id": 13,
    "method": "org.rdk.AppPackageManager.uninstall",
    "params": {
        "packageId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AppPackageManager.uninstall", "params": {"packageId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "errorReason": ""
    }
}
```


