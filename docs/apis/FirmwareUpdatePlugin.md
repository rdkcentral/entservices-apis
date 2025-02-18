<!-- Generated automatically, DO NOT EDIT! -->
<a name="Firmware_Update_Plugin"></a>
# Firmware Update Plugin

**Version: [1.0.0]()**

A org.rdk.FirmwareUpdate plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `FirmwareUpdate` plugin provides APIs to update (i.e., flash) the device with already downloaded and locally kept firmware image.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.FirmwareUpdate*) |
| classname | string | Class name: *org.rdk.FirmwareUpdate* |
| locator | string | Library name: *libWPEFrameworkFirmwareUpdate.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.FirmwareUpdate plugin:

org.rdk.FirmwareUpdate interface methods:

| Method | Description |
| :-------- | :-------- |
| [updateFirmware](#updateFirmware) | Update the device firmware with a previously downloaded image (using methods provided by components outside of this plugin) or with an image present in the attached USB mass storage device |
| [getUpdateState](#getUpdateState) | Firmware update consists of 2 major steps: 1 |


<a name="updateFirmware"></a>
## *updateFirmware*

Update the device firmware with a previously downloaded image (using methods provided by components outside of this plugin) or with an image present in the attached USB mass storage device. FirmwareUpdate is an asynchronous process. Status of the firmware update would be notified through onUpdateStateChange notification.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareFilepath | string | The complete path with firmware file to which the device needs to be updated |
| params.firmwareType | string | Type of firmware(must be one of the following: PCI,DRI) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FirmwareUpdate.updateFirmware",
    "params": {
        "firmwareFilepath": "/tmp/usbmnt/sda1/firmware/HSTP11MWR_4.11p5s1_VBN_sdy.bin",
        "firmwareType": "PCI"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="getUpdateState"></a>
## *getUpdateState*

Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the status of these steps in the firmware update process that was triggered by updateFirmware 

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
