<!-- Generated automatically, DO NOT EDIT! -->
<a id="FirmwareUpdate_Plugin"></a>
# FirmwareUpdate Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FirmwareUpdate)**

A FirmwareUpdate plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `FirmwareUpdate` plugin provides an interface for FirmwareUpdate.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FirmwareUpdate) |
| classname | string | Class name: *FirmwareUpdate* |
| locator | string | Library name: *libWPEFrameworkFirmwareUpdate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the FirmwareUpdate plugin:

FirmwareUpdate interface methods:

| Method | Description |
| :-------- | :-------- |
| [getUpdateState](#getUpdateState) | Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method. |
| [setAutoReboot](#setAutoReboot) | Enable or disable the AutoReboot feature. |
| [updateFirmware](#updateFirmware) | Initiates a firmware update. |

<a id="getUpdateState"></a>
## *getUpdateState*

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

<a id="setAutoReboot"></a>
## *setAutoReboot*

Enable or disable the AutoReboot feature.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | Boolean to enable or disable AutoReboot |
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
    "method": "org.rdk.FirmwareUpdate.setAutoReboot",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.FirmwareUpdate.setAutoReboot", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
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

<a id="updateFirmware"></a>
## *updateFirmware*

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
    "id": 2,
    "method": "org.rdk.FirmwareUpdate.updateFirmware",
    "params": {
        "firmwareFilepath": "",
        "firmwareType": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.FirmwareUpdate.updateFirmware", "params": {"firmwareFilepath": "", "firmwareType": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the FirmwareUpdate plugin:

FirmwareUpdate interface events:

| Event | Description |
| :-------- | :-------- |
| [onFlashingStateChange](#onFlashingStateChange) | This notification is raised between flashing started state and flashing succeeded/failed. |
| [onUpdateStateChange](#onUpdateStateChange) | notify Firmware update state change. |

<a id="onFlashingStateChange"></a>
## *onFlashingStateChange*

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
    "id": 3,
    "method": "org.rdk.FirmwareUpdate.onFlashingStateChange",
    "params": {
        "percentageComplete": 0
    }
}
```

<a id="onUpdateStateChange"></a>
## *onUpdateStateChange*

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
    "id": 4,
    "method": "org.rdk.FirmwareUpdate.onUpdateStateChange",
    "params": {
        "state": "VALIDATION_FAILED",
        "substate": "NOT_APPLICABLE"
    }
}
```
