<!-- Generated automatically, DO NOT EDIT! -->
<a id="DeviceInfo_Module"></a>
# DeviceInfo Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DeviceInfo/IDeviceInfo.h)**

A DeviceInfo module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IDeviceInfo](#IDeviceInfo)
    - [Methods](#IDeviceInfo-Methods)
    - [Properties](#IDeviceInfo-Properties)
  - [IDeviceAudioCapabilities](#IDeviceAudioCapabilities)
    - [Methods](#IDeviceAudioCapabilities-Methods)
  - [IDeviceVideoCapabilities](#IDeviceVideoCapabilities)
    - [Methods](#IDeviceVideoCapabilities-Methods)
    - [Properties](#IDeviceVideoCapabilities-Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DeviceInfo` module provides the following interface(s):

- IDeviceInfo
- IDeviceAudioCapabilities
- IDeviceVideoCapabilities

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceInfo) |
| classname | string | Class name: *DeviceInfo* |
| locator | string | Library name: *libWPEFrameworkDeviceInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IDeviceInfo"></a>
## IDeviceInfo Interface

<a id="IDeviceInfo-Methods"></a>
### Methods

The following methods are provided by the IDeviceInfo Interface:

| Method | Description |
| :-------- | :-------- |
| [supportedaudioports](#supportedaudioports) | Provides access to the audio ports supported on the device. |

<a id="supportedaudioports"></a>
## *supportedaudioports*

Retrieves the audio ports supported on the device.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedAudioPorts | array | Audio ports supported on the device. |
| result.supportedAudioPorts[#] | string |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DeviceInfo.supportedaudioports"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DeviceInfo.supportedaudioports"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "supportedAudioPorts": [
            "AUDIO_ANALOG",
            "AUDIO_HDMI0"
        ],
        "success": true
    }
}
```

<a id="IDeviceInfo-Properties"></a>
### Properties

The following properties are provided by the IDeviceInfo Interface:

| Property | Description |
| :-------- | :-------- |
| [addresses](#addresses)<sup>RO</sup> | Provides access to the network interface addresses. |
| [brandname](#brandname)<sup>RO</sup> | Provides access to device brand name |
| [chipset](#chipset)<sup>RO</sup> | Provides access to the chipset of the device |
| [deviceId](#deviceId)<sup>RO</sup> | Provides the Device ID info. |
| [devicetype](#devicetype)<sup>RO</sup> | Provides access to the device type. |
| [distributorid](#distributorid)<sup>RO</sup> | Provides access to the partner ID or distributor ID for device. |
| [estbip](#estbip)<sup>RO</sup> | Provides access to the STB IP addresses. |
| [estbmac](#estbmac)<sup>RO</sup> | Provides access to the STB MAC addresses. |
| [ethmac](#ethmac)<sup>RO</sup> | Provides access to the Ethernet MAC addresses. |
| [firmwareversion](#firmwareversion)<sup>RO</sup> | Provides access to the versions maintained in version.txt. |
| [hardwareId](#hardwareId)<sup>RO</sup> | Provides the Hardware ID (first 6 characters of Device ID). |
| [make](#make)<sup>RO</sup> | Provides access to the device manufacturer. |
| [modelname](#modelname)<sup>RO</sup> | Provides access to the friendly device model name. |
| [osname](#osname) | Provides access to the operating system name. |
| [osversion](#osversion) | Provides access to the operating system version. |
| [releaseversion](#releaseversion)<sup>RO</sup> | Provides access to the ReleaseVersion of the Image |
| [serialnumber](#serialnumber)<sup>RO</sup> | Provides access to the serial number set by manufacture |
| [modelid](#modelid)<sup>RO</sup> | Provides access to the device model number |
| [socname](#socname)<sup>RO</sup> | Provides access to the SOC Name. |
| [systeminfo](#systeminfo)<sup>RO</sup> | Provides access to the system general information |
| [wifimac](#wifimac)<sup>RO</sup> | Provides access to the WIFI MAC addresses. |

<a id="addresses"></a>
## *addresses*

Retrieves the network interface addresses of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).addressesInfo | array | Network interface addresses |
| (property).addressesInfo[#].name | string | Interface name |
| (property).addressesInfo[#].mac | string | Interface MAC address |
| (property).addressesInfo[#].ip | string | Interface IP address |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DeviceInfo.addresses"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.DeviceInfo.addresses"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": [
        {
            "name": "eth0",
            "mac": "00:11:22:33:44:55",
            "ip": "192.168.1.2"
        }
    ]
}
```

<a id="brandname"></a>
## *brandname*

Retrieves the brand name of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).brand | string | Device brand name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DeviceInfo.brandname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.DeviceInfo.brandname"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "brand": "Technicolor"
    }
}
```

<a id="chipset"></a>
## *chipset*

Retrieves the chipset of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).chipset | string | Chipset of the device |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DeviceInfo.chipset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.DeviceInfo.chipset"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "chipset": "BCM72180"
    }
}
```

<a id="deviceId"></a>
## *deviceId*

Retrieves the Device ID of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).deviceId | string | Device ID of the device |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DeviceInfo.deviceId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DeviceInfo.deviceId"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "deviceId": "1234567890abcdef"
    }
}
```

<a id="devicetype"></a>
## *devicetype*

Retrieves the type of the device (must be one of the following: IpTv, IpStb, QamIpStb).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).devicetype | string | Device Type. Possible values: IpTv, IpStb, QamIpStb |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DeviceInfo.devicetype"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DeviceInfo.devicetype"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "devicetype": "IpStb"
    }
}
```

<a id="distributorid"></a>
## *distributorid*

Retrieves the partner ID or distributor ID assigned to the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).distributorid | string | Partner ID or distributor ID for device |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DeviceInfo.distributorid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.DeviceInfo.distributorid"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "distributorid": 123456
    }
}
```

<a id="estbip"></a>
## *estbip*

Retrieves the STB IP addresses of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).estb_ip | string | STB IP addresses |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DeviceInfo.estbip"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.DeviceInfo.estbip"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "estb_ip": "192.168.1.10"
    }
}
```

<a id="estbmac"></a>
## *estbmac*

Retrieves the STB MAC addresses of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).estb_mac | string | STB MAC addresses |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.DeviceInfo.estbmac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.DeviceInfo.estbmac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "estbMac": "00:11:22:33:44:55"
    }
}
```

<a id="ethmac"></a>
## *ethmac*

Retrieves the Ethernet MAC addresses of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).eth_mac | string | Ethernet MAC addresses |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DeviceInfo.ethmac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.DeviceInfo.ethmac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "ethMac": "00:11:22:33:44:55"
    }
}
```

<a id="firmwareversion"></a>
## *firmwareversion*

Retrieves the versions maintained in version.txt.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).firmwareVersionInfo | object | Version information |
| (property).firmwareVersionInfo.imagename | string | Image name |
| (property).firmwareVersionInfo.rdk | string | rdk version |
| (property).firmwareVersionInfo.sdk | string | sdk version |
| (property).firmwareVersionInfo.mediarite | string | mediarite |
| (property).firmwareVersionInfo.yocto | string | yocto version |
| (property).firmwareVersionInfo.pdri | string | pdri version |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.DeviceInfo.firmwareversion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.DeviceInfo.firmwareversion"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "imagename": "image1",
        "middleware": "middleware1",
        "sdk": "sdk1",
        "mediarite": "mediarite1",
        "yocto": "yocto1",
        "pdri": "pdri1"
    }
}
```

<a id="hardwareId"></a>
## *hardwareId*

Retrieves the Hardware ID of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).hardwareId | string | Hardware ID of the device |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DeviceInfo.hardwareId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.DeviceInfo.hardwareId"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "hardwareId": 123456
    }
}
```

<a id="make"></a>
## *make*

Retrieves the manufacturer of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).make | string | Device manufacturer |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.DeviceInfo.make"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.DeviceInfo.make"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "make": "Technicolor"
    }
}
```

<a id="modelname"></a>
## *modelname*

Retrieves the friendly model name of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).model | string | Device model name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DeviceInfo.modelname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.DeviceInfo.modelname"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "model": "Technicolor XG1A"
    }
}
```

<a id="osname"></a>
## *osname*

Reads and writes OsName to /opt/persistent/osdetails.info and returns empty string if unset.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).osName | string | Operating system name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.DeviceInfo.osname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.DeviceInfo.osname"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": "RDK-E"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.DeviceInfo.osname",
    "params": "RDK-E"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.DeviceInfo.osname", "params": "RDK-E"}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="osversion"></a>
## *osversion*

Reads and writes OsVersion to /opt/persistent/osdetails.info and returns empty string if unset.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).osVersion | string | Operating system version |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.DeviceInfo.osversion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.DeviceInfo.osversion"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": 8.3
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.DeviceInfo.osversion",
    "params": 8.3
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.DeviceInfo.osversion", "params": 8.3}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="releaseversion"></a>
## *releaseversion*

Retrieves the release version of the image running on the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).releaseversion | string | ReleaseVersion of the Image |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.DeviceInfo.releaseversion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.DeviceInfo.releaseversion"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "releaseversion": "1.0.0"
    }
}
```

<a id="serialnumber"></a>
## *serialnumber*

Retrieves the serial number assigned to the device by the manufacturer.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).serialnumber | string | Serial number set by manufacturer |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.DeviceInfo.serialnumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.DeviceInfo.serialnumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "serialnumber": "XG1A2300012345"
    }
}
```

<a id="modelid"></a>
## *modelid*

Retrieves the model number or SKU assigned to the device by the manufacturer.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).sku | string | device model number |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.DeviceInfo.modelid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.DeviceInfo.modelid"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "sku": "X1234"
    }
}
```

<a id="socname"></a>
## *socname*

Retrieves the name of the system on chip (SOC).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).socname | string | Name of the SOC |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.DeviceInfo.socname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.DeviceInfo.socname"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": {
        "socname": "BCM72180"
    }
}
```

<a id="systeminfo"></a>
## *systeminfo*

Retrieves the system general information such as software version, uptime, total RAM, free RAM, total swap, free swap, host name, CPU load, CPU load average, serial number, and current system date and time.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).systemInfo | object | System general information |
| (property).systemInfo.version | string | Software version (in form version#hashtag) |
| (property).systemInfo.uptime | integer | System uptime (in seconds) |
| (property).systemInfo.totalram | integer | Total installed system RAM memory (in bytes) |
| (property).systemInfo.freeram | integer | Free system RAM memory (in bytes) |
| (property).systemInfo.totalswap | integer | Total swap space (in bytes) |
| (property).systemInfo.freeswap | integer | Swap space still available (in bytes) |
| (property).systemInfo.devicename | string | Host name |
| (property).systemInfo.cpuload | string | Current CPU load (percentage) |
| (property).systemInfo.cpuloadavg | object | CPU load average |
| (property).systemInfo.cpuloadavg.avg1min | integer | 1min cpuload average |
| (property).systemInfo.cpuloadavg.avg5min | integer | 5min cpuload average |
| (property).systemInfo.cpuloadavg.avg15min | integer | 15min cpuload average |
| (property).systemInfo.serialnumber | string | Device serial number |
| (property).systemInfo.time | string | Current system date and time |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.DeviceInfo.systeminfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.DeviceInfo.systeminfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": {
        "version": "1.0.0#123456",
        "uptime": 3600,
        "totalram": 2147483648,
        "freeram": 1073741824,
        "totalswap": 1073741824,
        "freeswap": 536870912,
        "devicename": "device1",
        "cpuload": "50%",
        "cpuloadavg": {
            "avg1min": 30,
            "avg5min": 40,
            "avg15min": 50
        },
        "serialnumber": "XG1A2300012345",
        "time": "2024-06-01T12:00:00Z"
    }
}
```

<a id="wifimac"></a>
## *wifimac*

Retrieves the WIFI MAC addresses of the device.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).wifi_mac | string | WIFI MAC addresses |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.DeviceInfo.wifimac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.DeviceInfo.wifimac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": {
        "wifiMac": "00:11:22:33:44:55"
    }
}
```

---

<a id="IDeviceAudioCapabilities"></a>
## IDeviceAudioCapabilities Interface

<a id="IDeviceAudioCapabilities-Methods"></a>
### Methods

The following methods are provided by the IDeviceAudioCapabilities Interface:

| Method | Description |
| :-------- | :-------- |
| [audiocapabilities](#audiocapabilities)<sup>deprecated</sup> | Audio capabilities for the specified audio port. |
| [ms12capabilities](#ms12capabilities)<sup>deprecated</sup> | MS12 audio capabilities for the specified audio port. |
| [supportedms12audioprofiles](#supportedms12audioprofiles)<sup>deprecated</sup> | Supported MS12 audio profiles for the specified audio port. |

<a id="audiocapabilities"></a>
## *audiocapabilities*

Retrieves the audio capabilities for the specified audio port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.AudioCapabilities | array | Audio capability |
| result.AudioCapabilities[#] | string | Possible values: none, ATMOS, DOLBY_DIGITAL, DOLBY_DIGITAL_PLUS, Dual_Audio_Decode, DAPv2, MS12 |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceInfo.audiocapabilities",
    "params": {
        "audioPort": "AUDIO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DeviceInfo.audiocapabilities", "params": {"audioPort": "AUDIO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "AudioCapabilities": [
            "ATMOS",
            "DOLBY_DIGITAL",
            "DOLBY_DIGITAL_PLUS"
        ],
        "success": true
    }
}
```

<a id="ms12capabilities"></a>
## *ms12capabilities*

Retrieves the MS12 audio capabilities for the specified audio port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.MS12Capabilities | array | MS12 audio capability |
| result.MS12Capabilities[#] | string | Possible values: none, Dolby_Volume, Inteligent_Equalizer, Dialogue_Enhancer |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceInfo.ms12capabilities",
    "params": {
        "audioPort": "AUDIO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DeviceInfo.ms12capabilities", "params": {"audioPort": "AUDIO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "MS12Capabilities": [
            "Dolby_Volume",
            "Inteligent_Equalizer",
            "Dialogue_Enhancer"
        ],
        "success": true
    }
}
```

<a id="supportedms12audioprofiles"></a>
## *supportedms12audioprofiles*

Retrieves the supported MS12 audio profiles for the specified audio port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedMS12AudioProfiles | array | MS12 audio profiles |
| result.supportedMS12AudioProfiles[#] | string |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceInfo.supportedms12audioprofiles",
    "params": {
        "audioPort": "AUDIO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DeviceInfo.supportedms12audioprofiles", "params": {"audioPort": "AUDIO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "supportedMS12AudioProfiles": [
            "MUSIC",
            "MOVIE",
            "VOICE"
        ],
        "success": true
    }
}
```

---

<a id="IDeviceVideoCapabilities"></a>
## IDeviceVideoCapabilities Interface

<a id="IDeviceVideoCapabilities-Methods"></a>
### Methods

The following methods are provided by the IDeviceVideoCapabilities Interface:

| Method | Description |
| :-------- | :-------- |
| [defaultresolution](#defaultresolution)<sup>deprecated</sup> | Default resolution on the selected video display port. |
| [supportedhdcp](#supportedhdcp)<sup>deprecated</sup> | Supported hdcp version on the selected video display port. |
| [supportedresolutions](#supportedresolutions)<sup>deprecated</sup> | Supported resolutions on the selected video display port. |
| [supportedvideodisplays](#supportedvideodisplays)<sup>deprecated</sup> | Provides access to the video ports supported on the device. |

<a id="defaultresolution"></a>
## *defaultresolution*

Retrieves the default resolution on the selected video display port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.defaultResolution | string | Default Resolutions |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DeviceInfo.defaultresolution",
    "params": {
        "videoDisplay": "VIDEO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.DeviceInfo.defaultresolution", "params": {"videoDisplay": "VIDEO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "defaultResolution": "1080p60"
    }
}
```

<a id="supportedhdcp"></a>
## *supportedhdcp*

Retrieves the supported hdcp version on the selected video display port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedHDCPVersion | string | HDCP support. Possible values: unavailable, 1.4, 2.0, 2.1, 2.2 |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DeviceInfo.supportedhdcp",
    "params": {
        "videoDisplay": "VIDEO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DeviceInfo.supportedhdcp", "params": {"videoDisplay": "VIDEO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "supportedHDCPVersion": 2.2
    }
}
```

<a id="supportedresolutions"></a>
## *supportedresolutions*

Retrieves the supported resolutions on the selected video display port.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedResolutions | array | Supported Resolutions |
| result.supportedResolutions[#] | string |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DeviceInfo.supportedresolutions",
    "params": {
        "videoDisplay": "VIDEO_HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DeviceInfo.supportedresolutions", "params": {"videoDisplay": "VIDEO_HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "supportedResolutions": [
            "1080p60",
            "1080p50",
            "720p60"
        ],
        "success": true
    }
}
```

<a id="supportedvideodisplays"></a>
## *supportedvideodisplays*

Retrieves the video ports supported on the device.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedVideoDisplays | array | Video ports supported on the device |
| result.supportedVideoDisplays[#] | string |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DeviceInfo.supportedvideodisplays"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.DeviceInfo.supportedvideodisplays"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "supportedVideoDisplays": [
            "VIDEO_HDMI0",
            "VIDEO_HDMI1"
        ],
        "success": true
    }
}
```

<a id="IDeviceVideoCapabilities-Properties"></a>
### Properties

The following properties are provided by the IDeviceVideoCapabilities Interface:

| Property | Description |
| :-------- | :-------- |
| [hostedid](#hostedid)<sup>RO</sup><sup>deprecated</sup> | Provides access to the EDID of the host. |

<a id="hostedid"></a>
## *hostedid*

Retrieves the base64 encoded Extended Display Identification Data (EDID) reported by the host device.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).EDID | string | EDID of the host |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.DeviceInfo.hostedid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.DeviceInfo.hostedid"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "EDID": "base64encodedstring"
    }
}
```

