<!-- Generated automatically, DO NOT EDIT! -->
<a id="PackageManager_Plugin"></a>
# PackageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PackageManager/IAppPackageManager.h)**

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

**IPackageManager methods**

| Method | Description |
| :-------- | :-------- |
<<<<<<< CPESP-8423
| [cancel (IPackageManager)](#IPackageManager::cancel) | Cancels a previously issued asynchronous request. |
| [clearAuxMetadata](#clearAuxMetadata) | Clears the specified metadata key. |
| [download (IPackageManager)](#IPackageManager::download) | Downloads a resource file for an application. |
| [getList](#getList) | Retrieves list of installed apps matching given filters. |
| [getLockInfo](#getLockInfo) | Provides lock reason and owner for an app. |
| [getMetadata](#getMetadata) | Retrieves metadata and auxiliary resource list for an application. |
| [getProgress](#getProgress) | Provides the current progress of an ongoing operation. |
| [getStorageDetails](#getStorageDetails) | Retrieves details about app and persistent storage usage. |
| [install (IPackageManager)](#IPackageManager::install) | Downloads and installs an application bundle. |
| [lock](#lock) | Locks an application to prevent uninstallation. |
| [reset](#reset) | Deletes all persistent local data of the application. |
| [setAuxMetadata](#setAuxMetadata) | Sets a key-value pair of metadata for the application. |
| [uninstall (IPackageManager)](#IPackageManager::uninstall) | Uninstalls an application. |
| [unlock](#unlock) | Unlocks a previously locked application. |

---

**IPackageDownloader methods**

| Method | Description |
| :-------- | :-------- |
| [cancel (IPackageDownloader)](#IPackageDownloader::cancel) | Cancel |
| [delete](#delete) | Delete |
| [download (IPackageDownloader)](#IPackageDownloader::download) | Download |
| [getStorageInformation](#getStorageInformation) | GetStorageInformation |
=======
| [cancel](#cancel) | Cancels a previously issued asynchronous request. |
| [config](#config) | Config |
| [delete](#delete) | Delete |
| [download](#download) | Downloads a resource file for an application. |
| [getConfigForPackage](#getConfigForPackage) | getConfigForPackage |
| [getStorageInformation](#getStorageInformation) | GetStorageInformation |
| [install](#install) | Downloads and installs an application bundle. |
| [listPackages](#listPackages) | ListPackages |
| [packageState](#packageState) | PackageState |
>>>>>>> develop
| [pause](#pause) | Pause |
| [progress](#progress) | Progress |
| [rateLimit](#rateLimit) | RateLimit |
| [resume](#resume) | Resume |
| [uninstall](#uninstall) | Uninstalls an application. |
| [clearAuxMetadata](#clearAuxMetadata) | Clears the specified metadata key. |
| [getList](#getList) | Retrieves list of installed apps matching given filters. |
| [getLockInfo](#getLockInfo) | Provides lock reason and owner for an app. |
| [getMetadata](#getMetadata) | Retrieves metadata and auxiliary resource list for an application. |
| [getProgress](#getProgress) | Provides the current progress of an ongoing operation. |
| [getStorageDetails](#getStorageDetails) | Retrieves details about app and persistent storage usage. |
| [lock](#lock) | Locks an application to prevent uninstallation. |
| [reset](#reset) | Deletes all persistent local data of the application. |
| [setAuxMetadata](#setAuxMetadata) | Sets a key-value pair of metadata for the application. |
| [unlock](#unlock) | Unlocks a previously locked application. |

---

<<<<<<< CPESP-8423
**IPackageInstaller methods**

| Method | Description |
| :-------- | :-------- |
| [config](#config) | Config |
| [getConfigForPackage](#getConfigForPackage) | getConfigForPackage |
| [install (IPackageInstaller)](#IPackageInstaller::install) | Install |
| [listPackages](#listPackages) | ListPackages |
| [packageState](#packageState) | PackageState |
| [uninstall (IPackageInstaller)](#IPackageInstaller::uninstall) | Uninstall |

<a id="IPackageManager-methods"></a>
### IPackageManager Methods

<a id="IPackageManager::cancel"></a>
## *cancel (IPackageManager)*
=======
Cancels a previously issued asynchronous request.
>>>>>>> develop

Cancels a previously issued asynchronous request.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | string |  |
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
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PackageManager.cancel", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

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
| params.version | string |  |
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
| result.configMetadata.capabilities | std::string | Comma-separated lowercase runtime capability tokens supported by the application runtime |
| result.configMetadata.ralfPkgPath | std::string | Filesystem path containing metadata information for RALF packages |
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
        "capabilities": "",
        "ralfPkgPath": "",
        "fireboltVersion": "",
        "enableDebugger": true
    }
}
```

<<<<<<< CPESP-8423
<a id="IPackageManager::download"></a>
## *download (IPackageManager)*

Downloads a resource file for an application.
=======
<a id="delete"></a>
## *delete*

Delete
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.resKey | string |  |
| params.url | string | Download url |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string |  |
=======
| params.fileLocator | string | File Locator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
<<<<<<< CPESP-8423
    "method": "org.rdk.PackageManager.download",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resKey": "",
        "url": ""
=======
    "method": "org.rdk.PackageManager.delete",
    "params": {
        "fileLocator": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PackageManager.download", "params": {"type": "", "id": "", "version": "", "resKey": "", "url": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PackageManager.delete", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
<<<<<<< CPESP-8423
    "result": {
        "handle": ""
    }
=======
    "result": null
>>>>>>> develop
}
```

<a id="download"></a>
## *download*

Downloads a resource file for an application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.resKey | string |  |
| params.url | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
| result.installedIds | array |  |
| result.installedIds[#].id | string |  |
| result.installedIds[#].version | string |  |
=======
| result.handle | string |  |
>>>>>>> develop

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PackageManager.download", "params": {"type": "", "id": "", "version": "", "resKey": "", "url": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "handle": ""
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
| params.fileLocator | string | File Locator |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
| result.result | object |  |
| result.result.reason | string |  |
| result.result.owner | string |  |
=======
| result.id | string |  |
| result.version | string |  |
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
| result.config.capabilities | std::string | Comma-separated lowercase runtime capability tokens supported by the application runtime |
| result.config.ralfPkgPath | std::string | Filesystem path containing metadata information for RALF packages |
| result.config.fireboltVersion | std::string |  |
| result.config.enableDebugger | bool |  |
>>>>>>> develop

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
            "capabilities": "",
            "ralfPkgPath": "",
            "fireboltVersion": "",
            "enableDebugger": true
        }
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
<<<<<<< CPESP-8423
| result.metadata | object |  |
| result.metadata.appName | string |  |
| result.metadata.type | string |  |
| result.metadata.category | string |  |
| result.metadata.url | string |  |
| result.resources | array |  |
| result.resources[#].key | string |  |
| result.resources[#].value | string |  |
| result.auxMetadata | array |  |
| result.auxMetadata[#].key | string |  |
| result.auxMetadata[#].value | string |  |
=======
| result.quotaKb | integer | Storage quota in kilobytes |
| result.usedKb | integer | Used storage in kilobytes |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PackageManager.getStorageInformation"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.getStorageInformation"}' http://127.0.0.1:9998/jsonrpc
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

<a id="install"></a>
## *install*

Downloads and installs an application bundle.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.url | string |  |
| params.appName | string |  |
| params.category | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string |  |

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.install", "params": {"type": "", "id": "", "version": "", "url": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "handle": ""
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
<<<<<<< CPESP-8423
| result.storageinfo | object |  |
| result.storageinfo.EXTERNAL | string |  |
| result.storageinfo.path | string |  |
| result.storageinfo.quotaKB | string |  |
| result.storageinfo.usedKB | string |  |
=======
| result.packages | IPackageIterator |  |
| result.packages[#].packageId | string |  |
| result.packages[#].version | string |  |
| result.packages[#].state | string |  |
| result.packages[#].digest | string |  |
| result.packages[#].sizeKb | integer |  |
>>>>>>> develop

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

<<<<<<< CPESP-8423
<a id="IPackageManager::install"></a>
## *install (IPackageManager)*

Downloads and installs an application bundle.
=======
<a id="packageState"></a>
## *packageState*

PackageState
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.url | string | Download url |
| params.appName | string |  |
| params.category | string |  |
=======
| params.packageId | string | Package Id |
| params.version | string |  |
>>>>>>> develop
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
| result.handle | string |  |
=======
| result.state | string |  |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
<<<<<<< CPESP-8423
    "method": "org.rdk.PackageManager.install",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "url": "",
        "appName": "",
        "category": ""
=======
    "method": "org.rdk.PackageManager.packageState",
    "params": {
        "packageId": "",
        "version": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.install", "params": {"type": "", "id": "", "version": "", "url": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.packageState", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
<<<<<<< CPESP-8423
        "handle": ""
=======
        "state": "INSTALLING"
>>>>>>> develop
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
    "id": 9,
    "method": "org.rdk.PackageManager.pause",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PackageManager.pause", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
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
    "id": 10,
    "method": "org.rdk.PackageManager.progress",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.progress", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
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
    "id": 11,
    "method": "org.rdk.PackageManager.rateLimit",
    "params": {
        "downloadId": "",
        "limit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.rateLimit", "params": {"downloadId": "", "limit": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<<<<<<< CPESP-8423
<a id="IPackageManager::uninstall"></a>
## *uninstall (IPackageManager)*

Uninstalls an application.
=======
<a id="resume"></a>
## *resume*

Resume
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.type | string |  |
| params.id | string | package id |
| params.version | string | Version |
| params.uninstallType | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string |  |
=======
| params.downloadId | string | Download ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
<<<<<<< CPESP-8423
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "uninstallType": ""
=======
    "method": "org.rdk.PackageManager.resume",
    "params": {
        "downloadId": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.uninstall", "params": {"type": "", "id": "", "version": "", "uninstallType": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.resume", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
<<<<<<< CPESP-8423
    "result": {
        "handle": ""
    }
=======
    "result": null
>>>>>>> develop
}
```

<a id="uninstall"></a>
## *uninstall*

Uninstalls an application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.uninstallType | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "uninstallType": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.uninstall", "params": {"type": "", "id": "", "version": "", "uninstallType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "handle": ""
    }
}
```

<<<<<<< CPESP-8423
---

<a id="IPackageDownloader-methods"></a>
### IPackageDownloader Methods
=======
<a id="clearAuxMetadata"></a>
## *clearAuxMetadata*

Clears the specified metadata key.
>>>>>>> develop

<a id="IPackageDownloader::cancel"></a>
## *cancel (IPackageDownloader)*

Cancel

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.downloadId | string | Download id |
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.key | string |  |
>>>>>>> develop
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 0,
    "method": "org.rdk.PackageManager.cancel",
    "params": {
        "downloadId": ""
=======
    "id": 1,
    "method": "org.rdk.PackageManager.clearAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PackageManager.cancel", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PackageManager.clearAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 0,
=======
    "id": 1,
>>>>>>> develop
    "result": null
}
```

<a id="getList"></a>
## *getList*

Retrieves list of installed apps matching given filters.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.fileLocator | string | FileLocator |
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.appName | string |  |
| params.category | string |  |
>>>>>>> develop
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
<<<<<<< CPESP-8423
    "id": 1,
    "method": "org.rdk.PackageManager.delete",
=======
    "id": 3,
    "method": "org.rdk.PackageManager.getList",
>>>>>>> develop
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
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PackageManager.delete", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PackageManager.getList", "params": {"type": "", "id": "", "version": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 1,
    "result": null
}
```

<a id="IPackageDownloader::download"></a>
## *download (IPackageDownloader)*

Download
=======
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
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.url | string | Download url |
| params.options | object | Download options |
| params.options.priority | bool |  |
| params.options.retries | integer |  |
| params.options.rateLimit | integer |  |
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
>>>>>>> develop
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
| result.downloadId | string | Download ID |
=======
| result.result | LockInfo |  |
| result.result.reason | string |  |
| result.result.owner | string |  |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 2,
    "method": "org.rdk.PackageManager.download",
    "params": {
        "url": "",
        "options": {
            "priority": true,
            "retries": 0,
            "rateLimit": 0
        }
=======
    "id": 4,
    "method": "org.rdk.PackageManager.getLockInfo",
    "params": {
        "type": "",
        "id": "",
        "version": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PackageManager.download", "params": {"url": "", "options": {"priority": true, "retries": 0, "rateLimit": 0}}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PackageManager.getLockInfo", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
<<<<<<< CPESP-8423
        "downloadId": ""
=======
        "reason": "",
        "owner": ""
>>>>>>> develop
    }
}
```

<a id="getMetadata"></a>
## *getMetadata*

Retrieves metadata and auxiliary resource list for an application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
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
<<<<<<< CPESP-8423
    "id": 3,
    "method": "org.rdk.PackageManager.getStorageInformation"
=======
    "id": 5,
    "method": "org.rdk.PackageManager.getMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
>>>>>>> develop
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PackageManager.getStorageInformation"}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.getMetadata", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
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

<<<<<<< CPESP-8423
<a id="pause"></a>
## *pause*

Pause
=======
<a id="getProgress"></a>
## *getProgress*

Provides the current progress of an ongoing operation.
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.downloadId | string | Download id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |
=======
| params.handle | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.progress | integer |  |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 4,
    "method": "org.rdk.PackageManager.pause",
    "params": {
        "downloadId": ""
=======
    "id": 6,
    "method": "org.rdk.PackageManager.getProgress",
    "params": {
        "handle": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PackageManager.pause", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PackageManager.getProgress", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 4,
    "result": null
}
```

<a id="progress"></a>
## *progress*

Progress
=======
    "id": 6,
    "result": {
        "progress": 0
    }
}
```

<a id="getStorageDetails"></a>
## *getStorageDetails*

Retrieves details about app and persistent storage usage.
>>>>>>> develop

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
    "method": "org.rdk.PackageManager.progress",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PackageManager.progress", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
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
    "method": "org.rdk.PackageManager.rateLimit",
    "params": {
        "downloadId": "",
        "limit": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PackageManager.rateLimit", "params": {"downloadId": "", "limit": 0}}' http://127.0.0.1:9998/jsonrpc
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
    "method": "org.rdk.PackageManager.resume",
    "params": {
        "downloadId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PackageManager.resume", "params": {"downloadId": ""}}' http://127.0.0.1:9998/jsonrpc
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
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
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
| result.configMetadata.ralfPkgPath | string | Filesystem path holding metadata info of ralf packages |
| result.configMetadata.fireboltVersion | string |  |
| result.configMetadata.enableDebugger | bool |  |
=======
| result.storageinfo | StorageInfo |  |
| result.storageinfo.EXTERNAL | struct |  |
| result.storageinfo.path | string |  |
| result.storageinfo.quotaKB | string |  |
| result.storageinfo.usedKB | string |  |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
<<<<<<< CPESP-8423
    "id": 8,
    "method": "org.rdk.PackageManager.config",
=======
    "id": 7,
    "method": "org.rdk.PackageManager.getStorageDetails",
>>>>>>> develop
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PackageManager.config", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PackageManager.getStorageDetails", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
<<<<<<< CPESP-8423
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
        "ralfPkgPath": "",
        "fireboltVersion": "",
        "enableDebugger": true
    }
}
```

<a id="getConfigForPackage"></a>
## *getConfigForPackage*

getConfigForPackage
=======
        "EXTERNAL": "",
        "path": "",
        "quotaKB": "",
        "usedKB": ""
    }
}
```

<a id="lock"></a>
## *lock*

Locks an application to prevent uninstallation.
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.fileLocator | string | locator of package |
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.reason | string |  |
| params.owner | string |  |
>>>>>>> develop
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
<<<<<<< CPESP-8423
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
| result.config.ralfPkgPath | string | Filesystem path holding metadata info of ralf packages |
| result.config.fireboltVersion | string |  |
| result.config.enableDebugger | bool |  |
=======
| result.handle | string |  |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
<<<<<<< CPESP-8423
    "method": "org.rdk.PackageManager.getConfigForPackage",
    "params": {
        "fileLocator": ""
=======
    "method": "org.rdk.PackageManager.lock",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "reason": "",
        "owner": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PackageManager.getConfigForPackage", "params": {"fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PackageManager.lock", "params": {"type": "", "id": "", "version": "", "reason": "", "owner": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
<<<<<<< CPESP-8423
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
            "ralfPkgPath": "",
            "fireboltVersion": "",
            "enableDebugger": true
        }
    }
}
```

<a id="IPackageInstaller::install"></a>
## *install (IPackageInstaller)*

Install
=======
        "handle": ""
    }
}
```

<a id="reset"></a>
## *reset*

Deletes all persistent local data of the application.
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
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
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.resetType | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |
>>>>>>> develop

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
<<<<<<< CPESP-8423
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
=======
    "method": "org.rdk.PackageManager.reset",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "resetType": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.install", "params": {"packageId": "", "version": "", "additionalMetadata": [{"name": "", "value": ""}], "fileLocator": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PackageManager.reset", "params": {"type": "", "id": "", "version": "", "resetType": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
<<<<<<< CPESP-8423
    "result": {
        "failReason": "NONE"
    }
}
```

<a id="listPackages"></a>
## *listPackages*

ListPackages
=======
    "result": null
}
```

<a id="setAuxMetadata"></a>
## *setAuxMetadata*

Sets a key-value pair of metadata for the application.
>>>>>>> develop

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
    "method": "org.rdk.PackageManager.listPackages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.listPackages"}' http://127.0.0.1:9998/jsonrpc
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
<<<<<<< CPESP-8423
| params.packageId | string | Package Id |
| params.version | string | Version |
=======
| params.type | string |  |
| params.id | string |  |
| params.version | string |  |
| params.key | string |  |
| params.value | string |  |
>>>>>>> develop
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
<<<<<<< CPESP-8423
    "id": 12,
    "method": "org.rdk.PackageManager.packageState",
    "params": {
        "packageId": "",
        "version": ""
=======
    "id": 11,
    "method": "org.rdk.PackageManager.setAuxMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": "",
        "key": "",
        "value": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PackageManager.packageState", "params": {"packageId": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PackageManager.setAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
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

<<<<<<< CPESP-8423
<a id="IPackageInstaller::uninstall"></a>
## *uninstall (IPackageInstaller)*

Uninstall
=======
<a id="unlock"></a>
## *unlock*

Unlocks a previously locked application.
>>>>>>> develop

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
<<<<<<< CPESP-8423
| params.packageId | string | Package Id |
=======
| params.handle | string |  |
>>>>>>> develop
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
<<<<<<< CPESP-8423
    "method": "org.rdk.PackageManager.uninstall",
    "params": {
        "packageId": ""
=======
    "method": "org.rdk.PackageManager.unlock",
    "params": {
        "handle": ""
>>>>>>> develop
    }
}
```


#### CURL Command

```curl
<<<<<<< CPESP-8423
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PackageManager.uninstall", "params": {"packageId": ""}}' http://127.0.0.1:9998/jsonrpc
=======
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PackageManager.unlock", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
>>>>>>> develop
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
<<<<<<< CPESP-8423
    "result": {
        "errorReason": ""
    }
=======
    "result": null
>>>>>>> develop
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
| params.id | string |  |
| params.version | string |  |
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
