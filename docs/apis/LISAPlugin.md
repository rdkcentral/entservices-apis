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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.appName | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LISA.appName"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": ""
}
```

<a id="method.apps"></a>
## *apps [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.apps | ILISA::IApp::IIterator | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LISA.apps"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": ""
}
```

<a id="method.auxMetadata"></a>
## *auxMetadata [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.auxMetadata | ILISA::IKeyValueIterator | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.LISA.auxMetadata"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
}
```

<a id="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

Cancel asynchronous request.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.category | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.LISA.category"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```

<a id="method.clearAuxMetadata"></a>
## *clearAuxMetadata [<sup>method</sup>](#head.Methods)*

Clears an arbitrary metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.key | std::string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.config | std::string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.app | ILISA::IApp | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.LISA.current"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": ""
}
```

<a id="method.download"></a>
## *download [<sup>method</sup>](#head.Methods)*

Download arbitrary application's resource file.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.resKey | std::string | - |
| params.url | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | std::string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": ""
}
```

<a id="method.getList"></a>
## *getList [<sup>method</sup>](#head.Methods)*

List installed applications.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.appName | std::string | - |
| params.category | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | IAppsPayload | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": ""
}
```

<a id="method.getLockInfo"></a>
## *getLockInfo [<sup>method</sup>](#head.Methods)*

Get lock info.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | ILISA::ILockInfo | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": ""
}
```

<a id="method.getMetadata"></a>
## *getMetadata [<sup>method</sup>](#head.Methods)*

Get application metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | ILISA::IMetadataPayload | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": ""
}
```

<a id="method.getProgress"></a>
## *getProgress [<sup>method</sup>](#head.Methods)*

Estimated progress of a request.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.progress | uint32_t | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": 0
}
```

<a id="method.getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head.Methods)*

Information on the storage usage.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | ILISA::IStoragePayload | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": ""
}
```

<a id="method.handle"></a>
## *handle [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | std::string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.LISA.handle"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": ""
}
```

<a id="method.id"></a>
## *id [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.id | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.LISA.id"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": ""
}
```

<a id="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*

Download the application bundle.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.url | std::string | - |
| params.appName | std::string | - |
| params.category | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | std::string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": ""
}
```

<a id="method.installed"></a>
## *installed [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.versions | ILISA::IAppVersion::IIterator | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.LISA.installed"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": ""
}
```

<a id="method.isValid"></a>
## *isValid [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.isValid | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.LISA.isValid"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": true
}
```

<a id="method.key"></a>
## *key [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.key | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.LISA.key"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": ""
}
```

<a id="method.lock"></a>
## *lock [<sup>method</sup>](#head.Methods)*

Lock the application. Preventing uninstallation.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.reason | std::string | - |
| params.owner | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | ILISA::IHandleResult | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": ""
}
```

<a id="method.next"></a>
## *next [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.hasNext | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.LISA.next"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": true
}
```

<a id="method.owner"></a>
## *owner [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.owner | std::string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.LISA.owner"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": ""
}
```

<a id="method.path"></a>
## *path [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.path | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.LISA.path"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": ""
}
```

<a id="method.persistent"></a>
## *persistent [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.storage | ILISA::IStorage | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.LISA.persistent"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": ""
}
```

<a id="method.quotaKB"></a>
## *quotaKB [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.quotaKB | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.LISA.quotaKB"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": ""
}
```

<a id="method.reason"></a>
## *reason [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.reason | std::string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.LISA.reason"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": ""
}
```

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.LISA.reset"
}
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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.resources | ILISA::IKeyValueIterator | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.LISA.resources"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": ""
}
```

<a id="method.setAuxMetadata"></a>
## *setAuxMetadata [<sup>method</sup>](#head.Methods)*

Set an arbitrary metadata.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.key | std::string | - |
| params.value | std::string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.type | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.LISA.type"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": ""
}
```

<a id="method.uninstall"></a>
## *uninstall [<sup>method</sup>](#head.Methods)*

Uninstall the application.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | std::string | - |
| params.id | std::string | - |
| params.version | std::string | - |
| params.uninstallType | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.handle | std::string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": ""
}
```

<a id="method.unlock"></a>
## *unlock [<sup>method</sup>](#head.Methods)*

Unlock application.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.handle | std::string | - |
### Results
This method returns no results.

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
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.url | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.LISA.url"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": ""
}
```

<a id="method.usedKB"></a>
## *usedKB [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.usedKB | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.LISA.usedKB"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": ""
}
```

<a id="method.value"></a>
## *value [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.value | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.LISA.value"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": ""
}
```

<a id="method.version"></a>
## *version [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.version | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.LISA.version"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": ""
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
| params.handle | string | - |
| params.operation | string | - |
| params.type | string | - |
| params.id | string | - |
| params.version | string | - |
| params.status | string | - |
| params.details | string | - |

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
