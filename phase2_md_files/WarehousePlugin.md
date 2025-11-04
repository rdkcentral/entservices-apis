<!-- Generated automatically, DO NOT EDIT! -->
<a id="Warehouse_Plugin"></a>
# Warehouse Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Warehouse/IWarehouse.h)**

A Warehouse plugin for Thunder framework.

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

The `Warehouse` plugin provides an interface for Warehouse.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Warehouse) |
| classname | string | Class name: *Warehouse* |
| locator | string | Library name: *libWPEFrameworkWarehouse.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the Warehouse plugin:

Warehouse interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [executeHardwareTest](#executeHardwareTest) | Starts a hardware test on the device | NA |
| [getHardwareTestResults](#getHardwareTestResults) | Returns the results of the last hardware test. | NA |
| [internalReset](#internalReset) | Invokes the internal reset script, which reboots the Warehouse service | NA |
| [isClean](#isClean) | Checks the locations on the device where customer data may be stored. | NA |
| [lightReset](#lightReset) | Resets the application data. | NA |
| [resetDevice](#resetDevice) | Resets the STB to the warehouse state. | resetDone |

<a id="executeHardwareTest"></a>
## *executeHardwareTest [<sup>method</sup>](#Methods)*

Starts a hardware test on the device

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Warehouse.executeHardwareTest"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Warehouse.executeHardwareTest"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```

<a id="getHardwareTestResults"></a>
## *getHardwareTestResults [<sup>method</sup>](#Methods)*

Returns the results of the last hardware test.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |
| result.testResults | string | string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Warehouse.getHardwareTestResults"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Warehouse.getHardwareTestResults"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true,
        "testResults": ""
    }
}
```

<a id="internalReset"></a>
## *internalReset [<sup>method</sup>](#Methods)*

Invokes the internal reset script, which reboots the Warehouse service

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.passPhrase | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Warehouse.internalReset",
    "params": {
        "passPhrase": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Warehouse.internalReset", "params": {"passPhrase": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true,
        "error": ""
    }
}
```

<a id="isClean"></a>
## *isClean [<sup>method</sup>](#Methods)*

Checks the locations on the device where customer data may be stored.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.age | int | integer |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clean | bool | boolean |
| result.files | IStringIterator | string [] of file locations for each file |
| result.files[#] | string |  |
| result.success | bool | boolean |
| result.error | string | string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Warehouse.isClean",
    "params": {
        "age": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Warehouse.isClean", "params": {"age": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "clean": true,
        "files": [
            ""
        ],
        "success": true,
        "error": ""
    }
}
```

<a id="lightReset"></a>
## *lightReset [<sup>method</sup>](#Methods)*

Resets the application data.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Warehouse.lightReset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.Warehouse.lightReset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true,
        "error": ""
    }
}
```

<a id="resetDevice"></a>
## *resetDevice [<sup>method</sup>](#Methods)*

Resets the STB to the warehouse state.

### Events
| Event | Description |
| :-------- | :-------- |
| [resetDone ](#event.resetDone ) |  Triggers when the device reset is finished indicating a successful reset or failure |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.suppressReboot | bool | bool |
| params.resetType | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Warehouse.resetDevice",
    "params": {
        "suppressReboot": true,
        "resetType": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.Warehouse.resetDevice", "params": {"suppressReboot": true, "resetType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "success": true,
        "error": ""
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the Warehouse plugin:

Warehouse interface events:

| Event | Description |
| :-------- | :-------- |
| [resetDone](#resetDone) | Notifies subscribers about the status of the warehouse reset operation |

<a id="resetDone"></a>
## *resetDone [<sup>event</sup>](#head.Notifications)*

Notifies subscribers about the status of the warehouse reset operation

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.success | bool | boolean |
| params.error | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Warehouse.resetDone",
    "params": {
        "success": true,
        "error": ""
    }
}
```
