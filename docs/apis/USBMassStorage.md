<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IUSBMassStorage_Plugin"></a>
# IUSBMassStorage Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IUSBMassStorage/CHANGELOG.md)**

A IUSBMassStorage plugin for Thunder framework.

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

The `IUSBMassStorage` plugin provides an interface for IUSBMassStorage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IUSBMassStorage*) |
| classname | string | Class name: *IUSBMassStorage* |
| locator | string | Library name: *libWPEFrameworkIUSBMassStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IUSBMassStorage plugin:

IUSBMassStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetDeviceList](#method.GetDeviceList) | Get list of devices that are currently mounted in the system |
| [GetMountPoints](#method.GetMountPoints) | Get mount points information for a specified device |
| [GetPartitionInfo](#method.GetPartitionInfo) | Get partition information for a given partition |

<a id="method.GetDeviceList"></a>
## *GetDeviceList [<sup>method</sup>](#head.Methods)*

Get list of devices that are currently mounted in the system

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.deviceInfo | IUSBStorageDeviceInfoIterator | Device info for devices that are currently mounted. |
| result.deviceInfo[#].devicePath | string | Device path in the file system (sysfs) |
| result.deviceInfo[#].deviceName | string | Device name identifying the device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBMassStorage.GetDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "deviceInfo": [
            {
                "devicePath": "",
                "deviceName": ""
            }
        ]
    }
}
```
<a id="method.GetMountPoints"></a>
## *GetMountPoints [<sup>method</sup>](#head.Methods)*

Get mount points information for a specified device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceName | string | Device name identifying the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| result.mountPoints[#].partitionName | string | name of the partition |
| result.mountPoints[#].mountFlags | USBStorageMountFlags | Mount flags used for mounting the device / partition |
| result.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| result.mountPoints[#].fileSystem | USBStorageFileSystem | file system of the partition |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBMassStorage.GetMountPoints",
    "params": {
        "deviceName": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "mountPoints": [
            {
                "partitionName": "",
                "mountFlags": "READ_ONLY",
                "mountPath": "",
                "fileSystem": "UNKNOWN"
            }
        ]
    }
}
```
<a id="method.GetPartitionInfo"></a>
## *GetPartitionInfo [<sup>method</sup>](#head.Methods)*

Get partition information for a given partition

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.mountPath | string | path at which the partition is mounted on |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.partitionInfo | USBStoragePartitionInfo | partition info details |
| result.partitionInfo.fileSystem | USBStorageFileSystem | file system of the partition |
| result.partitionInfo.size | uint32_t | total size of the partition in MB |
| result.partitionInfo.startSector | uint64_t | start sector of the partition |
| result.partitionInfo.numSectors | uint64_t | number of sectors in the partition |
| result.partitionInfo.sectorSize | uint32_t | size of the sector in the partition in bytes |
| result.partitionInfo.totalSpace | uint32_t | total space of the partition in MB |
| result.partitionInfo.usedSpace | uint32_t | used space in the partition in MB |
| result.partitionInfo.availableSpace | uint32_t | available space in the partition in MB |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBMassStorage.GetPartitionInfo",
    "params": {
        "mountPath": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "partitionInfo": {
            "fileSystem": "UNKNOWN",
            "size": "0",
            "startSector": "0",
            "numSectors": "0",
            "sectorSize": "0",
            "totalSpace": "0",
            "usedSpace": "0",
            "availableSpace": "0"
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IUSBMassStorage plugin:

IUSBMassStorage interface events:

| Method | Description |
| :-------- | :-------- |
| [OnDeviceMounted](#event.OnDeviceMounted) | Device Mounted notification @@iterator |
| [OnDeviceUnmounted](#event.OnDeviceUnmounted) | Device Unmounted notification @@iterator |

<a id="event.OnDeviceMounted"></a>
## *OnDeviceMounted [<sup>event</sup>](#head.Notifications)*

Device Mounted notification @@iterator

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceInfo | USBStorageDeviceInfo | name and device path of the mounted device. |
| params.deviceInfo.devicePath | string | Device path in the file system (sysfs) |
| params.deviceInfo.deviceName | string | Device name identifying the device |
| params.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| params.mountPoints[#].partitionName | string | name of the partition |
| params.mountPoints[#].mountFlags | USBStorageMountFlags | Mount flags used for mounting the device / partition |
| params.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| params.mountPoints[#].fileSystem | USBStorageFileSystem | file system of the partition |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBMassStorage.OnDeviceMounted",
    "params": {
        "deviceInfo": {
            "devicePath": "",
            "deviceName": ""
        },
        "mountPoints": [
            {
                "partitionName": "",
                "mountFlags": "READ_ONLY",
                "mountPath": "",
                "fileSystem": "UNKNOWN"
            }
        ]
    }
}
```
<a id="event.OnDeviceUnmounted"></a>
## *OnDeviceUnmounted [<sup>event</sup>](#head.Notifications)*

Device Unmounted notification @@iterator

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceInfo | USBStorageDeviceInfo | name and device path of the mounted device. |
| params.deviceInfo.devicePath | string | Device path in the file system (sysfs) |
| params.deviceInfo.deviceName | string | Device name identifying the device |
| params.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| params.mountPoints[#].partitionName | string | name of the partition |
| params.mountPoints[#].mountFlags | USBStorageMountFlags | Mount flags used for mounting the device / partition |
| params.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| params.mountPoints[#].fileSystem | USBStorageFileSystem | file system of the partition |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBMassStorage.OnDeviceUnmounted",
    "params": {
        "deviceInfo": {
            "devicePath": "",
            "deviceName": ""
        },
        "mountPoints": [
            {
                "partitionName": "",
                "mountFlags": "READ_ONLY",
                "mountPath": "",
                "fileSystem": "UNKNOWN"
            }
        ]
    }
}
```