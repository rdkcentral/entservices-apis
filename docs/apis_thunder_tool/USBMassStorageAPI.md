<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_USBMassStorage_API"></a>
# USBMassStorage API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

USBMassStorage interface for Thunder framework.

(Defined with IUSBMassStorage in [IUSBMassStorage.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IUSBMassStorage.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the USBMassStorage interface (version 1.0.0). It includes detailed specification about its methods provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

USBMassStorage JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the USBMassStorage interface:

USBMassStorage interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceList](#method_getDeviceList) | Get list of devices that are currently mounted in the system |
| [getMountPoints](#method_getMountPoints) | Get mount points information for a specified device |
| [getPartitionInfo](#method_getPartitionInfo) | Get partition information for a given partition |

<a id="method_getDeviceList"></a>
## *getDeviceList [<sup>method</sup>](#head_Methods)*

Get list of devices that are currently mounted in the system.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | Device info for devices that are currently mounted |
| result[#] | object | mandatory |  |
| result[#].devicePath | string | mandatory | Device path in the file system (sysfs) |
| result[#].deviceName | string | mandatory | Device name identifying the device |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getDeviceList"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "devicePath": "...",
      "deviceName": "..."
    }
  ]
}
```

<a id="method_getMountPoints"></a>
## *getMountPoints [<sup>method</sup>](#head_Methods)*

Get mount points information for a specified device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.deviceName | string | mandatory | Name of the device for which mount points are to be retrieved |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | List of mountpoints information for a given device |
| result[#] | object | mandatory |  |
| result[#].partitionName | string | mandatory | Name of the partition |
| result[#].mountFlags | string | mandatory | Mount flags used for mounting the device / partition (must be one of the following: *READ_ONLY, READ_WRITE*) |
| result[#].mountPath | string | mandatory | Path at which the partition is mounted on |
| result[#].fileSystem | string | mandatory | File system of the partition (must be one of the following: *EXFAT, EXT4, MSDOS, UNKNOWN, VFAT*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMountPoints",
  "params": {
    "deviceName": "..."
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
      "partitionName": "...",
      "mountFlags": "READ_WRITE",
      "mountPath": "...",
      "fileSystem": "MSDOS"
    }
  ]
}
```

<a id="method_getPartitionInfo"></a>
## *getPartitionInfo [<sup>method</sup>](#head_Methods)*

Get partition information for a given partition.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.mountPath | string | mandatory | : mount path of the partition for which more info is required |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Partition info details |
| result.fileSystem | string | mandatory |  (must be one of the following: *EXFAT, EXT4, MSDOS, UNKNOWN, VFAT*) |
| result.size | integer | mandatory |  |
| result.startSector | integer | mandatory |  |
| result.numSectors | integer | mandatory |  |
| result.sectorSize | integer | mandatory |  |
| result.totalSpace | integer | mandatory |  |
| result.usedSpace | integer | mandatory |  |
| result.availableSpace | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPartitionInfo",
  "params": {
    "mountPath": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "fileSystem": "MSDOS",
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

