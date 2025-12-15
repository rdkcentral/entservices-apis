<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.StorageManager_Plugin"></a>
# StorageManager Plugin

A org.rdk.StorageManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The StorageManager is responsible for maintaining the space on the flash disk needed for Web Applications to store Browser functions such as Cookies and Local Storage. It is a Thunder plugin that exposes a single Thunder interface(s) called IStorageManager.

Note: This document only describes the JSON-RPC methods exposed by the plugin, it does not cover COM-RPC interfaces or usage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.StorageManager*) |
| classname | string | Class name: *org.rdk.StorageManager* |
| locator | string | Library name: *libWPEFrameworkStorageManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.StorageManager plugin:

StorageManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [clear](#method.clear) | Clears app data for a given app id |
| [clearAll](#method.clearAll) | Clears all app data except for the exempt app ids |


<a name="method.clear"></a>
## *clear [<sup>method</sup>](#head.Methods)*

Clears app data for a given app id.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Application Identifier |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object | Returns success or error status |
| result.error | string | Error message, if any |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 0 | ```Core::ERROR_NONE``` | Success |
| 1 | ```Core::ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.StorageManager.clear",
    "params": {
        "appId": "com.example.myapp"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "error": "null"
    }
}
```

<a name="method.clearAll"></a>
## *clearAll [<sup>method</sup>](#head.Methods)*

Clears all app data except for the exempt app ids.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.exemptionAppIds | string | <sup>*(optional)*</sup> A JSON-formatted string listing app IDs exempt from clearing |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object | Returns success or error status |
| result.error | string | Error message, if any |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 0 | ```Core::ERROR_NONE``` | Success |
| 1 | ```Core::ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.StorageManager.clearAll",
    "params": {
        "exemptionAppIds": "{\"exemptionAppIds\":[\"com.example.app1\", \"com.example.app2\"]}"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "error": "null"
    }
}
```

