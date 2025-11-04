<!-- Generated automatically, DO NOT EDIT! -->
<a id="USBMassStorage_Plugin"></a>
# USBMassStorage Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/USBMassStorage/IUSBMassStorage.h)**

A USBMassStorage plugin for Thunder framework.

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

The `USBMassStorage` plugin provides an interface for USBMassStorage.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.USBMassStorage) |
| classname | string | Class name: *USBMassStorage* |
| locator | string | Library name: *libWPEFrameworkUSBMassStorage.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the USBMassStorage plugin:

USBMassStorage interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getDeviceList](#getDeviceList) | Get list of devices that are currently mounted in the system | NA |
| [getMountPoints](#getMountPoints) | Get mount points information for a specified device | NA |
| [getPartitionInfo](#getPartitionInfo) | Get partition information for a given partition | NA |

<a id="getDeviceList"></a>
## *getDeviceList*

Get list of devices that are currently mounted in the system

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.deviceInfo | IUSBStorageDeviceInfoIterator | Device info for devices that are currently mounted. |
| result.deviceInfo[#].devicePath | string | Device path in the file system (sysfs) |
| result.deviceInfo[#].deviceName | string | Device name identifying the device |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.USBMassStorage.getDeviceList"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.USBMassStorage.getDeviceList"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": [
        {
            "devicePath": "",
            "deviceName": ""
        }
    ]
}
```

<a id="getMountPoints"></a>
## *getMountPoints*

Get mount points information for a specified device

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Device name identifying the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| result.mountPoints[#].partitionName | string | name of the partition |
| result.mountPoints[#].mountFlags | string | Mount flags used for mounting the device |
| result.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| result.mountPoints[#].fileSystem | string | file system of the partition |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.USBMassStorage.getMountPoints",
    "params": {
        "deviceName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.USBMassStorage.getMountPoints", "params": {"deviceName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": [
        {
            "partitionName": "",
            "mountFlags": "READ_ONLY",
            "mountPath": "",
            "fileSystem": "UNKNOWN"
        }
    ]
}
```

<a id="getPartitionInfo"></a>
## *getPartitionInfo*

Get partition information for a given partition

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mountPath | string | path at which the partition is mounted on |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.partitionInfo | USBStoragePartitionInfo | partition info details |
| result.partitionInfo.fileSystem | string | file system of the partition |
| result.partitionInfo.size | integer | total size of the partition in MB |
| result.partitionInfo.startSector | integer | start sector of the partition |
| result.partitionInfo.numSectors | integer | number of sectors in the partition |
| result.partitionInfo.sectorSize | integer | size of the sector in the partition in bytes |
| result.partitionInfo.totalSpace | integer | total space of the partition in MB |
| result.partitionInfo.usedSpace | integer | used space in the partition in MB |
| result.partitionInfo.availableSpace | integer | available space in the partition in MB |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.USBMassStorage.getPartitionInfo",
    "params": {
        "mountPath": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.USBMassStorage.getPartitionInfo", "params": {"mountPath": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "fileSystem": "UNKNOWN",
        "size": 0,
        "startSector": 0,
        "numSectors": 0,
        "sectorSize": 0,
        "totalSpace": 0,
        "usedSpace": 0,
        "availableSpace": 0
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the USBMassStorage plugin:

USBMassStorage interface events:

| Event | Description |
| :-------- | :-------- |
| [onDeviceMounted](#onDeviceMounted) | Device Mounted notification @@iterator |
| [onDeviceUnMounted](#onDeviceUnMounted) | Device Unmounted notification @@iterator |

<a id="onDeviceMounted"></a>
## *onDeviceMounted*

Device Mounted notification @@iterator

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceInfo | USBStorageDeviceInfo | name and device path of the mounted device. |
| params.deviceInfo.devicePath | string | Device path in the file system (sysfs) |
| params.deviceInfo.deviceName | string | Device name identifying the device |
| params.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| params.mountPoints[#].partitionName | string | name of the partition |
| params.mountPoints[#].mountFlags | string | Mount flags used for mounting the device |
| params.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| params.mountPoints[#].fileSystem | string | file system of the partition |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.USBMassStorage.onDeviceMounted",
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

<a id="onDeviceUnmounted"></a>
## *onDeviceUnmounted*

Device Unmounted notification @@iterator

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceInfo | USBStorageDeviceInfo | name and device path of the mounted device. |
| params.deviceInfo.devicePath | string | Device path in the file system (sysfs) |
| params.deviceInfo.deviceName | string | Device name identifying the device |
| params.mountPoints | IUSBStorageMountInfoIterator | List of mountpoints information for the device mounted. |
| params.mountPoints[#].partitionName | string | name of the partition |
| params.mountPoints[#].mountFlags | string | Mount flags used for mounting the device |
| params.mountPoints[#].mountPath | string | path at which the partition is mounted on |
| params.mountPoints[#].fileSystem | string | file system of the partition |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.USBMassStorage.onDeviceUnmounted",
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
