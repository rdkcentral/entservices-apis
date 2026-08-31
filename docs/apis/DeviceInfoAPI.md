<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DeviceInfo_API"></a>
# DeviceInfo API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DeviceInfo interface for Thunder framework.

(Defined with IDeviceInfo in [IDeviceInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDeviceInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DeviceInfo interface (version 1.0.0). It includes detailed specification about its methods and properties provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

DeviceInfo JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DeviceInfo interface:

DeviceInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [supportedaudioports](#method_supportedaudioports) | Provides access to the audio ports supported on the device |

<a id="method_supportedaudioports"></a>
## *supportedaudioports [<sup>method</sup>](#head_Methods)*

Provides access to the audio ports supported on the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.supportedAudioPorts | array | mandatory | Audio ports supported on the device |
| result.supportedAudioPorts[#] | string | mandatory | *...* |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.supportedaudioports"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedAudioPorts": [
      "..."
    ],
    "success": false
  }
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the DeviceInfo interface:

DeviceInfo interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [serialnumber](#property_serialnumber) | read-only | Provides access to the serial number set by manufacture |
| [modelid](#property_modelid) | read-only | Provides access to the device model number |
| [make](#property_make) | read-only | Provides access to the device manufacturer |
| [modelname](#property_modelname) | read-only | Provides access to the friendly device model name |
| [devicetype](#property_devicetype) | read-only | Provides access to the device type |
| [socname](#property_socname) | read-only | Provides access to the SOC Name |
| [distributorid](#property_distributorid) | read-only | Provides access to the partner ID or distributor ID for device |
| [brandname](#property_brandname) | read-only | Provides access to device brand name |
| [releaseversion](#property_releaseversion) | read-only | Provides access to the ReleaseVersion of the Image |
| [chipset](#property_chipset) | read-only | Provides access to the chipset of the device |
| [firmwareversion](#property_firmwareversion) | read-only | Provides access to the versions maintained in version |
| [systeminfo](#property_systeminfo) | read-only | Provides access to the system general information |
| [addresses](#property_addresses) | read-only | Provides access to the network interface addresses |
| [ethmac](#property_ethmac) | read-only | Provides access to the Ethernet MAC addresses |
| [estbmac](#property_estbmac) | read-only | Provides access to the STB MAC addresses |
| [wifimac](#property_wifimac) | read-only | Provides access to the WIFI MAC addresses |
| [estbip](#property_estbip) | read-only | Provides access to the STB IP addresses |
| [deviceId](#property_deviceId) | read-only | Provides the Device ID info |
| [hardwareId](#property_hardwareId) | read-only | Provides the Hardware ID (first 6 characters of Device ID) |
| [osname](#property_osname) | read/write | Provides access to the operating system name |
| [osversion](#property_osversion) | read/write | Provides access to the operating system version |

<a id="property_serialnumber"></a>
## *serialnumber [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the serial number set by manufacture.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the serial number set by manufacture |
| (property).serialnumber | string | mandatory | Serial number set by manufacturer |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.serialnumber"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "serialnumber": "..."
  }
}
```

<a id="property_modelid"></a>
## *modelid [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the device model number.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the device model number |
| (property).sku | string | mandatory | Device model number or SKU |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.modelid"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "sku": "..."
  }
}
```

<a id="property_make"></a>
## *make [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the device manufacturer.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the device manufacturer |
| (property).make | string | mandatory | Device manufacturer |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.make"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "make": "..."
  }
}
```

<a id="property_modelname"></a>
## *modelname [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the friendly device model name.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the friendly device model name |
| (property).model | string | mandatory | Friendly device model name |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.modelname"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "model": "..."
  }
}
```

<a id="property_devicetype"></a>
## *devicetype [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the device type.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the device type |
| (property).devicetype | string | mandatory | Device type (must be one of the following: tv, IpStb, QamIpStb) (must be one of the following: *IpStb, IpTv, QamIpStb*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.devicetype"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "devicetype": "IpStb"
  }
}
```

<a id="property_socname"></a>
## *socname [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the SOC Name.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the SOC Name |
| (property).socname | string | mandatory | SOC Name |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.socname"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "socname": "..."
  }
}
```

<a id="property_distributorid"></a>
## *distributorid [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the partner ID or distributor ID for device.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the partner ID or distributor ID for device |
| (property).distributorid | string | mandatory | Partner ID or distributor ID for device |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.distributorid"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "distributorid": "..."
  }
}
```

<a id="property_brandname"></a>
## *brandname [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to device brand name.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to device brand name |
| (property).brand | string | mandatory | Brand Name |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.brandname"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "brand": "..."
  }
}
```

<a id="property_releaseversion"></a>
## *releaseversion [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the ReleaseVersion of the Image.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the ReleaseVersion of the Image |
| (property).releaseversion | string | mandatory | Release version |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.releaseversion"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "releaseversion": "..."
  }
}
```

<a id="property_chipset"></a>
## *chipset [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the chipset of the device.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the chipset of the device |
| (property).chipset | string | mandatory | Device chip set Name |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.chipset"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "chipset": "..."
  }
}
```

<a id="property_firmwareversion"></a>
## *firmwareversion [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the versions maintained in version.txt.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Version information |
| (property).imagename | string | mandatory | Image name |
| (property).rdk | string | mandatory | Rdk version |
| (property).sdk | string | mandatory | Sdk version |
| (property).mediarite | string | mandatory | Mediarite |
| (property).yocto | string | mandatory | Yocto version |
| (property).pdri | string | mandatory | Pdri version |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.firmwareversion"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "imagename": "...",
    "rdk": "...",
    "sdk": "...",
    "mediarite": "...",
    "yocto": "...",
    "pdri": "..."
  }
}
```

<a id="property_systeminfo"></a>
## *systeminfo [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the system general information.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the system general information |
| (property).version | string | mandatory | Software version (in form version#hashtag) |
| (property).uptime | integer | mandatory | System uptime (in seconds) |
| (property).totalram | integer | mandatory | Total installed system RAM memory (in bytes) |
| (property).freeram | integer | mandatory | Free system RAM memory (in bytes) |
| (property).totalswap | integer | mandatory | Total swap space (in bytes) |
| (property).freeswap | integer | mandatory | Swap space still available (in bytes) |
| (property).devicename | string | mandatory | Host name |
| (property).cpuload | string | mandatory | Current CPU load (percentage) |
| (property).cpuloadavg | object | mandatory | CPU load average |
| (property).cpuloadavg.avg1min | integer | mandatory | 1min cpuload average |
| (property).cpuloadavg.avg5min | integer | mandatory | 5min cpuload average |
| (property).cpuloadavg.avg15min | integer | mandatory | 15min cpuload average |
| (property).serialnumber | string | mandatory | Device serial number |
| (property).time | string | mandatory | Current system date and time |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.systeminfo"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "version": "...",
    "uptime": 0,
    "totalram": 0,
    "freeram": 0,
    "totalswap": 0,
    "freeswap": 0,
    "devicename": "...",
    "cpuload": "...",
    "cpuloadavg": {
      "avg1min": 0,
      "avg5min": 0,
      "avg15min": 0
    },
    "serialnumber": "...",
    "time": "..."
  }
}
```

<a id="property_addresses"></a>
## *addresses [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the network interface addresses.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Network interface addresses |
| (property)[#] | object | mandatory | *...* |
| (property)[#].name | string | mandatory | Interface name |
| (property)[#].mac | string | mandatory | Interface MAC address |
| (property)[#].ip | string | mandatory | Interface IP address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.addresses"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "...",
      "mac": "...",
      "ip": "..."
    }
  ]
}
```

<a id="property_ethmac"></a>
## *ethmac [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the Ethernet MAC addresses.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the Ethernet MAC addresses |
| (property).eth_mac | string | mandatory | Ethernet Mac Address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.ethmac"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "eth_mac": "..."
  }
}
```

<a id="property_estbmac"></a>
## *estbmac [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the STB MAC addresses.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the STB MAC addresses |
| (property).estb_mac | string | mandatory | STB Mac Address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.estbmac"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "estb_mac": "..."
  }
}
```

<a id="property_wifimac"></a>
## *wifimac [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the WIFI MAC addresses.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the WIFI MAC addresses |
| (property).wifi_mac | string | mandatory | Wifi Mac Address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.wifimac"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "wifi_mac": "..."
  }
}
```

<a id="property_estbip"></a>
## *estbip [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the STB IP addresses.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the STB IP addresses |
| (property).estb_ip | string | mandatory | STB IP Address |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.estbip"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "estb_ip": "..."
  }
}
```

<a id="property_deviceId"></a>
## *deviceId [<sup>property</sup>](#head_Properties)*

Provides access to the provides the Device ID info.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides the Device ID info |
| (property).deviceId | string | mandatory | Device ID |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.deviceId"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "deviceId": "..."
  }
}
```

<a id="property_hardwareId"></a>
## *hardwareId [<sup>property</sup>](#head_Properties)*

Provides access to the provides the Hardware ID (first 6 characters of Device ID).

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides the Hardware ID (first 6 characters of Device ID) |
| (property).hardwareId | string | mandatory | Hardware ID (first 6 characters of Device ID) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.hardwareId"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "hardwareId": "..."
  }
}
```

<a id="property_osname"></a>
## *osname [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the operating system name.

### Description

Reads and writes OsName to /opt/persistent/osdetails.info and returns empty string if unset.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the operating system name |
| (property).osName | string | mandatory | *...* |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the operating system name |
| (property).osName | string | mandatory | Operating system name |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.osname"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "osName": "..."
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.osname",
  "params": {
    "osName": "..."
  }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_osversion"></a>
## *osversion [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the operating system version.

### Description

Reads and writes OsVersion to /opt/persistent/osdetails.info and returns empty string if unset.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the operating system version |
| (property).osVersion | string | mandatory | *...* |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the operating system version |
| (property).osVersion | string | mandatory | Operating system version |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.osversion"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "osVersion": "..."
  }
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.osversion",
  "params": {
    "osVersion": "..."
  }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

