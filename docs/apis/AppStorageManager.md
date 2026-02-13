<!-- Generated automatically, DO NOT EDIT! -->
<a id="AppStorageManager_Plugin"></a>
# AppStorageManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AppStorageManager/IAppStorageManager.h)**

A AppStorageManager plugin for Thunder framework.

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

The `AppStorageManager` plugin provides an interface for AppStorageManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppStorageManager) |
| classname | string | Class name: *AppStorageManager* |
| locator | string | Library name: *libWPEFrameworkAppStorageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the AppStorageManager plugin:

AppStorageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [clear](#clear) | Called by IUI.  This also clears device storage as well |
| [clearAll](#clearAll) | Called by IUI.  This also clears device storage as well |

<a id="clear"></a>
## *clear*

Called by IUI.  This also clears device storage as well

### Events
Event details will be updated soon.
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
    "method": "org.rdk.AppStorageManager.clear",
    "params": {
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AppStorageManager.clear", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
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
Event details will be updated soon.
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
    "method": "org.rdk.AppStorageManager.clearAll",
    "params": {
        "exemptionAppIds": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AppStorageManager.clearAll", "params": {"exemptionAppIds": ""}}' http://127.0.0.1:9998/jsonrpc
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


