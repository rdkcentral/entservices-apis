<!-- Generated automatically, DO NOT EDIT! -->
<a id="Warehouse_Module"></a>
# Warehouse Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Warehouse/IWarehouse.h)**

A Warehouse module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IWarehouse](#IWarehouse)
    - [Methods](#IWarehouse-Methods)
    - [Notifications](#IWarehouse-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Warehouse` module provides the following interface(s):

- IWarehouse

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Warehouse) |
| classname | string | Class name: *Warehouse* |
| locator | string | Library name: *libWPEFrameworkWarehouse.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IWarehouse"></a>
## IWarehouse Interface

<a id="IWarehouse-Methods"></a>
### Methods

The following methods are provided by the IWarehouse Interface:

| Method | Description |
| :-------- | :-------- |
| [internalReset](#internalReset) | Invokes the internal reset script, which reboots the Warehouse service |
| [isClean](#isClean) | Checks the locations on the device where customer data may be stored. |
| [lightReset](#lightReset) | Resets the application data. |
| [resetDevice](#resetDevice) | Resets the STB to the warehouse state. |

<a id="internalReset"></a>
## *internalReset*

Invokes the internal reset script, which reboots the Warehouse service. The internal reset script will check for a valid passphrase before proceeding with the reset operation.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.passPhrase | string | String containing the passphrase required for the internal reset operation. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | object | Result of the operation, including success state and any error details. |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Warehouse.internalReset",
    "params": {
        "passPhrase": "mySecretPassphrase"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Warehouse.internalReset", "params": {"passPhrase": "mySecretPassphrase"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true,
        "error": "Unsupported reset type"
    }
}
```

<a id="isClean"></a>
## *isClean*

Checks the locations on the device where customer data may be stored. If any of these locations contain files that are older than the specified age, the clean flag will be set to false and the file locations will be returned.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.age | int | Integer specifying the age threshold for checking files. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clean | bool | Boolean indicating whether the device is clean. |
| result.files | array | Array of strings containing the file locations for each file. |
| result.files[#] | string |  |
| result.success | bool | Boolean indicating whether the clean check operation was successful. |
| result.error | string | The error message if the clean check operation failed. Empty if the operation was successful. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Warehouse.isClean",
    "params": {
        "age": 30
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Warehouse.isClean", "params": {"age": 30}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "clean": true,
        "files": [
            "/opt/persistentStore/application/language",
            "/opt/persistentStore/network/region"
        ],
        "success": true,
        "error": ""
    }
}
```

<a id="lightReset"></a>
## *lightReset*

Resets the application data. This operation will delete all the application data and reset the application to its default state.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | object | Result of the operation, including success state and any error details. |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Warehouse.lightReset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Warehouse.lightReset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true,
        "error": "Unsupported reset type"
    }
}
```

<a id="resetDevice"></a>
## *resetDevice*

Resets the STB to the warehouse state. This operation will delete all the data on the device and reset the device to its default state.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.suppressReboot | bool | Boolean indicating whether to suppress the device reboot after the reset operation. |
| params.resetType | string | String specifying the type of reset to perform. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | object | Result of the operation, including success state and any error details. |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Warehouse.resetDevice",
    "params": {
        "suppressReboot": true,
        "resetType": "factory"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Warehouse.resetDevice", "params": {"suppressReboot": true, "resetType": "factory"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true,
        "error": "Unsupported reset type"
    }
}
```

<a id="IWarehouse-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IWarehouse Interface:

| Event | Description |
| :-------- | :-------- |
| [resetDone](#resetDone) | Notifies subscribers about the status of the warehouse reset operation |

<a id="resetDone"></a>
## *resetDone*

This event is triggered when the warehouse reset operation is completed, providing the success status and any error message if applicable.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.success | bool | Boolean indicating whether the reset operation was successful. |
| params.error | string | The error message if the reset operation failed. Empty if the operation was successful. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Warehouse.resetDone",
    "params": {
        "success": true,
        "error": ""
    }
}
```

