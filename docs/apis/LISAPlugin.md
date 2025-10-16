<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.LISA_Plugin"></a>
# LISA Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/LISA/CHANGELOG.md)**

A LISA plugin for Thunder framework.

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

The `LISA` plugin provides an interface for LISA.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LISA) |
| classname | string | Class name: *LISA* |
| locator | string | Library name: *libWPEFrameworkLISA.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the LISA plugin:

LISA interface methods:

| Method | Description |
| :-------- | :-------- |
| [appName](#method.appName) |  |
| [apps](#method.apps) |  |
| [auxMetadata](#method.auxMetadata) |  |
| [cancel](#method.cancel) | Cancel asynchronous request. |
| [category](#method.category) |  |
| [clearAuxMetadata](#method.clearAuxMetadata) | Clears an arbitrary metadata. |
| [configure](#method.configure) |  |
| [current](#method.current) |  |
| [download](#method.download) | Download arbitrary application's resource file. |
| [getList](#method.getList) | List installed applications. |
| [getLockInfo](#method.getLockInfo) | Get lock info. |
| [getMetadata](#method.getMetadata) | Get application metadata. |
| [getProgress](#method.getProgress) | Estimated progress of a request. |
| [getStorageDetails](#method.getStorageDetails) | Information on the storage usage. |
| [handle](#method.handle) |  |
| [id](#method.id) |  |
| [install](#method.install) | Download the application bundle. |
| [installed](#method.installed) |  |
| [isValid](#method.isValid) |  |
| [key](#method.key) |  |
| [lock](#method.lock) | Lock the application. Preventing uninstallation. |
| [next](#method.next) |  |
| [owner](#method.owner) |  |
| [path](#method.path) |  |
| [persistent](#method.persistent) |  |
| [quotaKB](#method.quotaKB) |  |
| [reason](#method.reason) |  |
| [reset](#method.reset) |  |
| [resources](#method.resources) |  |
| [setAuxMetadata](#method.setAuxMetadata) | Set an arbitrary metadata. |
| [type](#method.type) |  |
| [uninstall](#method.uninstall) | Uninstall the application. |
| [unlock](#method.unlock) | Unlock application. |
| [url](#method.url) |  |
| [usedKB](#method.usedKB) |  |
| [value](#method.value) |  |
| [version](#method.version) |  |

<a id="method.appName"></a>
## *appName [<sup>method</sup>](#head.Methods)*



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

<a id="method.apps"></a>
## *apps [<sup>method</sup>](#head.Methods)*



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

<a id="method.auxMetadata"></a>
## *auxMetadata [<sup>method</sup>](#head.Methods)*



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

<a id="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

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

<a id="method.category"></a>
## *category [<sup>method</sup>](#head.Methods)*



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

<a id="method.clearAuxMetadata"></a>
## *clearAuxMetadata [<sup>method</sup>](#head.Methods)*

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

<a id="method.configure"></a>
## *configure [<sup>method</sup>](#head.Methods)*



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

<a id="method.current"></a>
## *current [<sup>method</sup>](#head.Methods)*



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

<a id="method.download"></a>
## *download [<sup>method</sup>](#head.Methods)*

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

<a id="method.getList"></a>
## *getList [<sup>method</sup>](#head.Methods)*

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

<a id="method.getLockInfo"></a>
## *getLockInfo [<sup>method</sup>](#head.Methods)*

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

<a id="method.getMetadata"></a>
## *getMetadata [<sup>method</sup>](#head.Methods)*

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

<a id="method.getProgress"></a>
## *getProgress [<sup>method</sup>](#head.Methods)*

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

<a id="method.getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head.Methods)*

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

<a id="method.handle"></a>
## *handle [<sup>method</sup>](#head.Methods)*



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

<a id="method.id"></a>
## *id [<sup>method</sup>](#head.Methods)*



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

<a id="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*

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

<a id="method.installed"></a>
## *installed [<sup>method</sup>](#head.Methods)*



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

<a id="method.isValid"></a>
## *isValid [<sup>method</sup>](#head.Methods)*



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

<a id="method.key"></a>
## *key [<sup>method</sup>](#head.Methods)*



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

<a id="method.lock"></a>
## *lock [<sup>method</sup>](#head.Methods)*

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

<a id="method.next"></a>
## *next [<sup>method</sup>](#head.Methods)*



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

<a id="method.owner"></a>
## *owner [<sup>method</sup>](#head.Methods)*



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

<a id="method.path"></a>
## *path [<sup>method</sup>](#head.Methods)*



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

<a id="method.persistent"></a>
## *persistent [<sup>method</sup>](#head.Methods)*



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

<a id="method.quotaKB"></a>
## *quotaKB [<sup>method</sup>](#head.Methods)*



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

<a id="method.reason"></a>
## *reason [<sup>method</sup>](#head.Methods)*



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

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*



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

<a id="method.resources"></a>
## *resources [<sup>method</sup>](#head.Methods)*



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

<a id="method.setAuxMetadata"></a>
## *setAuxMetadata [<sup>method</sup>](#head.Methods)*

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

<a id="method.type"></a>
## *type [<sup>method</sup>](#head.Methods)*



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

<a id="method.uninstall"></a>
## *uninstall [<sup>method</sup>](#head.Methods)*

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

<a id="method.unlock"></a>
## *unlock [<sup>method</sup>](#head.Methods)*

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

<a id="method.url"></a>
## *url [<sup>method</sup>](#head.Methods)*



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

<a id="method.usedKB"></a>
## *usedKB [<sup>method</sup>](#head.Methods)*



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

<a id="method.value"></a>
## *value [<sup>method</sup>](#head.Methods)*



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

<a id="method.version"></a>
## *version [<sup>method</sup>](#head.Methods)*



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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the LISA plugin:

LISA interface events:

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
