<!-- Generated automatically, DO NOT EDIT! -->
<a id="StorageManager_Plugin"></a>
# StorageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/StorageManager)**

A StorageManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `StorageManager` plugin provides an interface for StorageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.StorageManager) |
| classname | string | Class name: *StorageManager* |
| locator | string | Library name: *libWPEFrameworkStorageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the StorageManager plugin:

StorageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [clear](#clear) | Called by IUI.  This also clears device storage as well |
| [clearAll](#clearAll) | Called by IUI.  This also clears device storage as well |

<a id="clear"></a>
## *clear*

Called by IUI.  This also clears device storage as well

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | string App identifier for the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.errorReason | string | string error reason string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.StorageManager.clear",
    "params": {
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.StorageManager.clear", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "errorReason": ""
    }
}
```

<a id="clearAll"></a>
## *clearAll*

Called by IUI.  This also clears device storage as well

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.exemptionAppIds | string | string Clears all app data except for the exempt app ids as a json format |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.errorReason | string | string error reason string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.StorageManager.clearAll",
    "params": {
        "exemptionAppIds": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.StorageManager.clearAll", "params": {"exemptionAppIds": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "errorReason": ""
    }
}
```


