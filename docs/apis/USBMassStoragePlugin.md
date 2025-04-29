<!-- Generated automatically, DO NOT EDIT! -->
<a name="USBMassStorage_Plugin"></a>
# USBMassStorage Plugin

**Version: [1.0.0]()**

A org.rdk.UsbMassStorage plugin for Thunder framework.

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

The `USBMassStorage` plugin is using For mounting the file system on mass storage and enumeration of mount points.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.UsbMassStorage*) |
| classname | string | Class name: *org.rdk.UsbMassStorage* |
| locator | string | Library name: *libWPEFrameworkUSBMassStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.UsbMassStorage plugin:

org.rdk.UsbMassStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceList](#getDeviceList) | Retrieve the list of connected USB storage devices |
| [getMountPoints](#getMountPoints) | Retrieve the mount info list by given USB storage device name |
| [getPartitionInfo](#getPartitionInfo) | Get the partition information for the given mount path |


<a name="getDeviceList"></a>
## *getDeviceList*

Retrieve the list of connected USB storage devices.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array | On success, a list of USB storage devices will be returned |
| result[#] | object | Information about a USB storage device |
| result[#].devicePath | string | The path to the USB device |
| result[#].deviceName | string | The name of the USB device |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbMassStorage.getDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "devicePath": "/dev/sda",
            "deviceName": "001/006"
        }
    ]
}
```

<a name="getMountPoints"></a>
## *getMountPoints*

Retrieve the mount info list by given USB storage device name.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the USB storage device |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array | On success, mount info list of a USB storage device will be returned |
| result[#] | object |  |
| result[#].partitionName | string | The name of the partition being mounted |
| result[#].mountFlags | string | Flags indicating how the partition is mounted |
| result[#].mountPath | string | The mount point path in the file system |
| result[#]?.fileSystem | string | <sup>*(optional)*</sup> File system |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbMassStorage.getMountPoints",
    "params": {
        "deviceName": "001/006"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "partitionName": "/dev/sda1",
            "mountFlags": "READ_ONLY",
            "mountPath": "/tmp/media/usb2",
            "fileSystem": "VFAT"
        }
    ]
}
```

<a name="getPartitionInfo"></a>
## *getPartitionInfo*

Get the partition information for the given mount path.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mountPath | string | Name of the USB storage device |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.fileSystem | string | The file system of the partition |
| result.size | integer | Total size of the partition in MB |
| result.startSector | integer | The starting sector of the partition |
| result.numSectors | integer | The number of sectors in the partition |
| result.sectorSize | integer | The size of each sector in bytes |
| result.totalSpace | integer | Total space of the partition in MB |
| result.usedSpace | integer | Used space of the partition in MB |
| result.availableSpace | integer | Available space in the partition in MB |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbMassStorage.getPartitionInfo",
    "params": {
        "mountPath": "/tmp/media/usb2"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "fileSystem": "VFAT",
        "size": 1024,
        "startSector": 2048,
        "numSectors": 4096,
        "sectorSize": 512,
        "totalSpace": 1024,
        "usedSpace": 512,
        "availableSpace": 512
    }
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.UsbMassStorage plugin:

org.rdk.UsbMassStorage interface events:

| Event | Description |
| :-------- | :-------- |
| [onDeviceMounted](#onDeviceMounted) | Triggered after the device partitions are mounted |
| [onDeviceUnmounted](#onDeviceUnmounted) | Triggered after the device partitions are unmounted |


<a name="onDeviceMounted"></a>
## *onDeviceMounted*

Triggered after the device partitions are mounted.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceinfo | object |  |
| params.deviceinfo.devicePath | string | The device path |
| params.deviceinfo.deviceName | string | The name of the device |
| params.mountPoints | array | mount info list of a USB storage device will be returned |
| params.mountPoints[#] | object |  |
| params.mountPoints[#].partitionName | string | The name of the partition being mounted |
| params.mountPoints[#].mountFlags | string | Flags indicating how the partition is mounted |
| params.mountPoints[#].mountPath | string | The mount point path in the file system |
| params.mountPoints[#]?.fileSystem | string | <sup>*(optional)*</sup> File system |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceMounted",
    "params": {
        "deviceinfo": {
            "devicePath": "/dev/sda",
            "deviceName": "001/022"
        },
        "mountPoints": [
            {
                "partitionName": "/dev/sda1",
                "mountFlags": "READ_ONLY",
                "mountPath": "/tmp/media/usb2",
                "fileSystem": "VFAT"
            }
        ]
    }
}
```

<a name="onDeviceUnmounted"></a>
## *onDeviceUnmounted*

Triggered after the device partitions are unmounted.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceinfo | object |  |
| params.deviceinfo.devicePath | string | The device path |
| params.deviceinfo.deviceName | string | The name of the device |
| params.mountPoints | array | mount info list of a USB storage device will be returned |
| params.mountPoints[#] | object |  |
| params.mountPoints[#].partitionName | string | The name of the partition being mounted |
| params.mountPoints[#].mountFlags | string | Flags indicating how the partition is mounted |
| params.mountPoints[#].mountPath | string | The mount point path in the file system |
| params.mountPoints[#]?.fileSystem | string | <sup>*(optional)*</sup> File system |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceUnmounted",
    "params": {
        "deviceinfo": {
            "devicePath": "/dev/sda",
            "deviceName": "001/022"
        },
        "mountPoints": [
            {
                "partitionName": "/dev/sda1",
                "mountFlags": "READ_ONLY",
                "mountPath": "/tmp/media/usb2",
                "fileSystem": "VFAT"
            }
        ]
    }
}
```

