<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IFirmwareUpdate_Plugin"></a>
# IFirmwareUpdate Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IFirmwareUpdate/CHANGELOG.md)**

A IFirmwareUpdate plugin for Thunder framework.

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

The `IFirmwareUpdate` plugin provides an interface for IFirmwareUpdate.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IFirmwareUpdate*) |
| classname | string | Class name: *IFirmwareUpdate* |
| locator | string | Library name: *libWPEFrameworkIFirmwareUpdate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IFirmwareUpdate plugin:

IFirmwareUpdate interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetUpdateState](#method.GetUpdateState) | Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method. |
| [UpdateFirmware](#method.UpdateFirmware) | Initiates a firmware update. |

<a id="method.GetUpdateState"></a>
## *GetUpdateState [<sup>method</sup>](#head.Methods)*

Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.getUpdateStateResult | GetUpdateStateResult |  |
| result.getUpdateStateResult.state | State | state |
| result.getUpdateStateResult.substate | SubState | substate |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareUpdate.GetUpdateState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "getUpdateStateResult": {
            "state": "VALIDATION_FAILED",
            "substate": "NOT_APPLICABLE"
        }
    }
}
```
<a id="method.UpdateFirmware"></a>
## *UpdateFirmware [<sup>method</sup>](#head.Methods)*

Initiates a firmware update.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.firmwareFilepath | string | The complete path of the firmware file to which the device needs to be updated to. |
| params.firmwareType | string | Type of firmware. One of the following (PCI,DRI) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | Result |  |
| result.result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareUpdate.UpdateFirmware",
    "params": {
        "firmwareFilepath": "",
        "firmwareType": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "result": {
            "success": "true"
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IFirmwareUpdate plugin:

IFirmwareUpdate interface events:

| Method | Description |
| :-------- | :-------- |
| [OnFlashingStateChange](#event.OnFlashingStateChange) | This notification is raised between flashing started state and flashing succeeded/failed. |
| [OnUpdateStateChange](#event.OnUpdateStateChange) | notify Firmware update state change. |

<a id="event.OnFlashingStateChange"></a>
## *OnFlashingStateChange [<sup>event</sup>](#head.Notifications)*

This notification is raised between flashing started state and flashing succeeded/failed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.percentageComplete | uint32_t | Number between 0 and 100 indicating the "percentage complete" of the flashing process. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareUpdate.OnFlashingStateChange",
    "params": {
        "percentageComplete": "0"
    }
}
```
<a id="event.OnUpdateStateChange"></a>
## *OnUpdateStateChange [<sup>event</sup>](#head.Notifications)*

notify Firmware update state change.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.state | State | state |
| params.substate | SubState | substate |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareUpdate.OnUpdateStateChange",
    "params": {
        "state": "VALIDATION_FAILED",
        "substate": "NOT_APPLICABLE"
    }
}
```