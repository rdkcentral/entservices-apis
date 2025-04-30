<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IWarehouse_Plugin"></a>
# IWarehouse Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IWarehouse/CHANGELOG.md)**

A IWarehouse plugin for Thunder framework.

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

The `IWarehouse` plugin provides an interface for IWarehouse.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IWarehouse*) |
| classname | string | Class name: *IWarehouse* |
| locator | string | Library name: *libWPEFrameworkIWarehouse.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IWarehouse plugin:

IWarehouse interface methods:

| Method | Description |
| :-------- | :-------- |
| [ExecuteHardwareTest](#method.ExecuteHardwareTest) | Starts a hardware test on the device |
| [GetHardwareTestResults](#method.GetHardwareTestResults) | Returns the results of the last hardware test. |
| [InternalReset](#method.InternalReset) | Invokes the internal reset script, which reboots the Warehouse service |
| [IsClean](#method.IsClean) | Checks the locations on the device where customer data may be stored. |
| [LightReset](#method.LightReset) | Resets the application data. |
| [ResetDevice](#method.ResetDevice) | Resets the STB to the warehouse state. |

<a id="method.ExecuteHardwareTest"></a>
## *ExecuteHardwareTest [<sup>method</sup>](#head.Methods)*

Starts a hardware test on the device

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | WarehouseSuccess |  |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.ExecuteHardwareTest"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.GetHardwareTestResults"></a>
## *GetHardwareTestResults [<sup>method</sup>](#head.Methods)*

Returns the results of the last hardware test.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | - in - boolean |
| result.testResults | string | - out - string |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.GetHardwareTestResults"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true",
        "testResults": ""
    }
}
```
<a id="method.InternalReset"></a>
## *InternalReset [<sup>method</sup>](#head.Methods)*

Invokes the internal reset script, which reboots the Warehouse service

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.passPhrase | string | - in - string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.InternalReset",
    "params": {
        "passPhrase": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "successErr": {
            "success": "true",
            "error": ""
        }
    }
}
```
<a id="method.IsClean"></a>
## *IsClean [<sup>method</sup>](#head.Methods)*

Checks the locations on the device where customer data may be stored.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.age | int | - in - integer |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.clean | bool | - out - boolean |
| result.files | IStringIterator | - out - string [] of file locations for each file |
| result.files[#] | string |  |
| result.success | bool | - in - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.IsClean",
    "params": {
        "age": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clean": "true",
        "files": [
            ""
        ],
        "success": "true"
    }
}
```
<a id="method.LightReset"></a>
## *LightReset [<sup>method</sup>](#head.Methods)*

Resets the application data.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.LightReset"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "successErr": {
            "success": "true",
            "error": ""
        }
    }
}
```
<a id="method.ResetDevice"></a>
## *ResetDevice [<sup>method</sup>](#head.Methods)*

Resets the STB to the warehouse state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.suppressReboot | bool | - in - bool |
| params.resetType | string | - in - string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.successErr | WarehouseSuccessErr |  |
| result.successErr.success | bool |  |
| result.successErr.error | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.ResetDevice",
    "params": {
        "suppressReboot": "true",
        "resetType": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "successErr": {
            "success": "true",
            "error": ""
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IWarehouse plugin:

IWarehouse interface events:

| Method | Description |
| :-------- | :-------- |
| [ResetDone](#event.ResetDone) | Notifies subscribers about the status of the warehouse reset operation |

<a id="event.ResetDone"></a>
## *ResetDone [<sup>event</sup>](#head.Notifications)*

Notifies subscribers about the status of the warehouse reset operation

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.success | bool | - in - boolean |
| params.error | string | - in - string |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IWarehouse.ResetDone",
    "params": {
        "success": "true",
        "error": ""
    }
}
```