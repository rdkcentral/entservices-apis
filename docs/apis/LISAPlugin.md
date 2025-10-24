<!-- Generated automatically, DO NOT EDIT! -->
<a id="LISA_Plugin"></a>
# LISA Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/LISA)**

A LISA plugin for Thunder framework.

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

The `LISA` plugin provides an interface for LISA.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LISA) |
| classname | string | Class name: *LISA* |
| locator | string | Library name: *libWPEFrameworkLISA.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the LISA plugin:

LISA interface methods:

| Method | Description |
| :-------- | :-------- |
| [appName](#appName) |  |
| [apps](#apps) |  |
| [auxMetadata](#auxMetadata) |  |
| [cancel](#cancel) | Cancel asynchronous request. |
| [category](#category) |  |
| [clearAuxMetadata](#clearAuxMetadata) | Clears an arbitrary metadata. |
| [configure](#configure) |  |
| [current](#current) |  |
| [download](#download) | Download arbitrary application's resource file. |
| [getList](#getList) | List installed applications. |
| [getLockInfo](#getLockInfo) | Get lock info. |
| [getMetadata](#getMetadata) | Get application metadata. |
| [getProgress](#getProgress) | Estimated progress of a request. |
| [getStorageDetails](#getStorageDetails) | Information on the storage usage. |
| [handle](#handle) |  |
| [id](#id) |  |
| [install](#install) | Download the application bundle. |
| [installed](#installed) |  |
| [isValid](#isValid) |  |
| [key](#key) |  |
| [lock](#lock) | Lock the application. Preventing uninstallation. |
| [next](#next) |  |
| [owner](#owner) |  |
| [path](#path) |  |
| [persistent](#persistent) |  |
| [quotaKB](#quotaKB) |  |
| [reason](#reason) |  |
| [reset](#reset) |  |
| [resources](#resources) |  |
| [setAuxMetadata](#setAuxMetadata) | Set an arbitrary metadata. |
| [type](#type) |  |
| [uninstall](#uninstall) | Uninstall the application. |
| [unlock](#unlock) | Unlock application. |
| [url](#url) |  |
| [usedKB](#usedKB) |  |
| [value](#value) |  |
| [version](#version) |  |

<a id="appName"></a>
## *appName*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.appName | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LISA.appName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.LISA.appName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "appName": ""
    }
}
```

<a id="apps"></a>
## *apps*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.apps | ILISA::IApp::IIterator |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LISA.apps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.LISA.apps"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "apps": ""
    }
}
```

<a id="auxMetadata"></a>
## *auxMetadata*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.auxMetadata | ILISA::IKeyValueIterator |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.LISA.auxMetadata"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.LISA.auxMetadata"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "auxMetadata": ""
    }
}
```

<a id="cancel"></a>
## *cancel*

Cancel asynchronous request.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.LISA.cancel",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.LISA.cancel", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="category"></a>
## *category*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.category | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.LISA.category"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.LISA.category"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "category": ""
    }
}
```

<a id="clearAuxMetadata"></a>
## *clearAuxMetadata*

Clears an arbitrary metadata.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.key | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.LISA.clearAuxMetadata",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.LISA.clearAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="configure"></a>
## *configure*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.config | std::string |  |
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
    "method": "org.rdk.LISA.configure",
    "params": {
        "config": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.LISA.configure", "params": {"config": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="current"></a>
## *current*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.app | ILISA::IApp |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.LISA.current"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.LISA.current"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "app": ""
    }
}
```

<a id="download"></a>
## *download*

Download arbitrary application's resource file.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.resKey | std::string |  |
| params.url | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.LISA.download",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.LISA.download", "params": {"type": "", "id": "", "version": "", "resKey": "", "url": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="getList"></a>
## *getList*

List installed applications.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.appName | std::string |  |
| params.category | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | IAppsPayload |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.LISA.getList",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.LISA.getList", "params": {"type": "", "id": "", "version": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "result": ""
    }
}
```

<a id="getLockInfo"></a>
## *getLockInfo*

Get lock info.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | ILISA::ILockInfo |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.LISA.getLockInfo",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.LISA.getLockInfo", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "result": ""
    }
}
```

<a id="getMetadata"></a>
## *getMetadata*

Get application metadata.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | ILISA::IMetadataPayload |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.LISA.getMetadata",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.LISA.getMetadata", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "result": ""
    }
}
```

<a id="getProgress"></a>
## *getProgress*

Estimated progress of a request.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string |  |
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
    "id": 12,
    "method": "org.rdk.LISA.getProgress",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.LISA.getProgress", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "progress": 0
    }
}
```

<a id="getStorageDetails"></a>
## *getStorageDetails*

Information on the storage usage.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | ILISA::IStoragePayload |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.LISA.getStorageDetails",
    "params": {
        "type": "",
        "id": "",
        "version": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.LISA.getStorageDetails", "params": {"type": "", "id": "", "version": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "result": ""
    }
}
```

<a id="handle"></a>
## *handle*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.LISA.handle"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.LISA.handle"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "handle": ""
    }
}
```

<a id="id"></a>
## *id*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.id | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.LISA.id"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.LISA.id"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "id": ""
    }
}
```

<a id="install"></a>
## *install*

Download the application bundle.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.url | std::string |  |
| params.appName | std::string |  |
| params.category | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.LISA.install",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.LISA.install", "params": {"type": "", "id": "", "version": "", "url": "", "appName": "", "category": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "handle": ""
    }
}
```

<a id="installed"></a>
## *installed*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.versions | ILISA::IAppVersion::IIterator |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.LISA.installed"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.LISA.installed"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "versions": ""
    }
}
```

<a id="isValid"></a>
## *isValid*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.isValid | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.LISA.isValid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.LISA.isValid"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "isValid": true
    }
}
```

<a id="key"></a>
## *key*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.key | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.LISA.key"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.LISA.key"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "key": ""
    }
}
```

<a id="lock"></a>
## *lock*

Lock the application. Preventing uninstallation.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.reason | std::string |  |
| params.owner | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | ILISA::IHandleResult |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.LISA.lock",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.LISA.lock", "params": {"type": "", "id": "", "version": "", "reason": "", "owner": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "result": ""
    }
}
```

<a id="next"></a>
## *next*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hasNext | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.LISA.next"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.LISA.next"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "hasNext": true
    }
}
```

<a id="owner"></a>
## *owner*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.owner | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.LISA.owner"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.LISA.owner"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "owner": ""
    }
}
```

<a id="path"></a>
## *path*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.path | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.LISA.path"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.LISA.path"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "path": ""
    }
}
```

<a id="persistent"></a>
## *persistent*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.storage | ILISA::IStorage |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.LISA.persistent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.LISA.persistent"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "storage": ""
    }
}
```

<a id="quotaKB"></a>
## *quotaKB*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.quotaKB | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.LISA.quotaKB"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.LISA.quotaKB"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "quotaKB": ""
    }
}
```

<a id="reason"></a>
## *reason*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.reason | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.LISA.reason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.LISA.reason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "reason": ""
    }
}
```

<a id="reset"></a>
## *reset*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.LISA.reset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.LISA.reset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="resources"></a>
## *resources*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.resources | ILISA::IKeyValueIterator |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.LISA.resources"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.LISA.resources"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": {
        "resources": ""
    }
}
```

<a id="setAuxMetadata"></a>
## *setAuxMetadata*

Set an arbitrary metadata.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.key | std::string |  |
| params.value | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.LISA.setAuxMetadata",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.LISA.setAuxMetadata", "params": {"type": "", "id": "", "version": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="type"></a>
## *type*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.type | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.LISA.type"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.LISA.type"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": {
        "type": ""
    }
}
```

<a id="uninstall"></a>
## *uninstall*

Uninstall the application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string |  |
| params.id | std::string |  |
| params.version | std::string |  |
| params.uninstallType | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.handle | std::string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.LISA.uninstall",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.LISA.uninstall", "params": {"type": "", "id": "", "version": "", "uninstallType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": {
        "handle": ""
    }
}
```

<a id="unlock"></a>
## *unlock*

Unlock application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.LISA.unlock",
    "params": {
        "handle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.LISA.unlock", "params": {"handle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="url"></a>
## *url*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.url | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.LISA.url"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.LISA.url"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": {
        "url": ""
    }
}
```

<a id="usedKB"></a>
## *usedKB*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.usedKB | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.LISA.usedKB"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.LISA.usedKB"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": {
        "usedKB": ""
    }
}
```

<a id="value"></a>
## *value*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.LISA.value"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.LISA.value"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": {
        "value": ""
    }
}
```

<a id="version"></a>
## *version*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.LISA.version"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.LISA.version"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": {
        "version": ""
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the LISA plugin:

LISA interface events:

| Event | Description |
| :-------- | :-------- |
| [operationStatus](#operationStatus) | Completion of asynchronous operation. |

<a id="operationStatus"></a>
## *operationStatus*

Completion of asynchronous operation.

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
    "id": 37,
    "method": "org.rdk.LISA.operationStatus",
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
