<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.FirmwareUpdate_Plugin"></a>
# FirmwareUpdate Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/FirmwareUpdate/CHANGELOG.md)**

A FirmwareUpdate plugin for Thunder framework.

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

The `FirmwareUpdate` plugin provides an interface for FirmwareUpdate.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FirmwareUpdate) |
| classname | string | Class name: *FirmwareUpdate* |
| locator | string | Library name: *libWPEFrameworkFirmwareUpdate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the FirmwareUpdate plugin:

FirmwareUpdate interface methods:

| Method | Description |
| :-------- | :-------- |
| [getUpdateState](#method.getUpdateState) | Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method. |
| [updateFirmware](#method.updateFirmware) | Initiates a firmware update. |

<a id="method.getUpdateState"></a>
## *getUpdateState [<sup>method</sup>](#head.Methods)*

Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method.

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.getUpdateStateResult | GetUpdateStateResult |  |
| result.getUpdateStateResult.state | string | state |
| result.getUpdateStateResult.substate | string | substate |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FirmwareUpdate.getUpdateState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.FirmwareUpdate.getUpdateState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "state": "VALIDATION_FAILED",
        "substate": "NOT_APPLICABLE"
    }
}
```

<a id="method.updateFirmware"></a>
## *updateFirmware [<sup>method</sup>](#head.Methods)*

Initiates a firmware update.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareFilepath | string | The complete path of the firmware file to which the device needs to be updated to. |
| params.firmwareType | string | Type of firmware. One of the following (PCI,DRI) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FirmwareUpdate.updateFirmware",
    "params": {
        "firmwareFilepath": "",
        "firmwareType": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.FirmwareUpdate.updateFirmware", "params": {"firmwareFilepath": "", "firmwareType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true
    }
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the FirmwareUpdate plugin:

FirmwareUpdate interface events:

| Event | Description |
| :-------- | :-------- |
| [onFlashingStateChange](#event.onFlashingStateChange) | This notification is raised between flashing started state and flashing succeeded/failed. |
| [onUpdateStateChange](#event.onUpdateStateChange) | notify Firmware update state change. |

<a id="event.onFlashingStateChange"></a>
## *onFlashingStateChange [<sup>event</sup>](#head.Notifications)*

This notification is raised between flashing started state and flashing succeeded/failed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.percentageComplete | integer | Number between 0 and 100 indicating the "percentage complete" of the flashing process. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FirmwareUpdate.onFlashingStateChange",
    "params": {
        "percentageComplete": 0
    }
}
```

<a id="event.onUpdateStateChange"></a>
## *onUpdateStateChange [<sup>event</sup>](#head.Notifications)*

notify Firmware update state change.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | string | state |
| params.substate | string | substate |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FirmwareUpdate.onUpdateStateChange",
    "params": {
        "state": "VALIDATION_FAILED",
        "substate": "NOT_APPLICABLE"
    }
}
```
