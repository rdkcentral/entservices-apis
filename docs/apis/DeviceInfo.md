<!-- Generated automatically, DO NOT EDIT! -->
<a id="DeviceInfo_Plugin"></a>
# DeviceInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DeviceInfo/IDeviceInfo.h)**

A DeviceInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DeviceInfo` plugin provides an interface for DeviceInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceInfo) |
| classname | string | Class name: *DeviceInfo* |
| locator | string | Library name: *libWPEFrameworkDeviceInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the DeviceInfo plugin:

DeviceInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [audiocapabilities](#audiocapabilities) | Audio capabilities for the specified audio port. |
| [defaultresolution](#defaultresolution) | Default resolution on the selected video display port. |
| [ms12capabilities](#ms12capabilities) | MS12 audio capabilities for the specified audio port. |
| [supportedaudioports](#supportedaudioports) | Provides access to the audio ports supported on the device. |
| [supportedhdcp](#supportedhdcp) | Supported hdcp version on the selected video display port. |
| [supportedms12audioprofiles](#supportedms12audioprofiles) | Supported MS12 audio profiles for the specified audio port. |
| [supportedresolutions](#supportedresolutions) | Supported resolutions on the selected video display port. |
| [supportedvideodisplays](#supportedvideodisplays) | Provides access to the video ports supported on the device. |

<a id="audioCapabilities"></a>
## *audioCapabilities*

Audio capabilities for the specified audio port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.AudioCapabilities | IAudioCapabilityIterator | Audio capability @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure @deprecated |
| result.AudioCapabilities[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceInfo.audioCapabilities",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DeviceInfo.audioCapabilities", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "AudioCapabilities": [
            "AUDIOCAPABILITY_NONE"
        ],
        "success": true
    }
}
```

<a id="defaultResolution"></a>
## *defaultResolution*

Default resolution on the selected video display port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.defaultResolution | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceInfo.defaultResolution",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DeviceInfo.defaultResolution", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "defaultResolution": ""
    }
}
```

<a id="mS12Capabilities"></a>
## *mS12Capabilities*

MS12 audio capabilities for the specified audio port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.MS12Capabilities | IMS12CapabilityIterator | MS12 audio capability @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure @deprecated |
| result.MS12Capabilities[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceInfo.mS12Capabilities",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DeviceInfo.mS12Capabilities", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "MS12Capabilities": [
            "MS12CAPABILITY_NONE"
        ],
        "success": true
    }
}
```

<a id="supportedAudioPorts"></a>
## *supportedAudioPorts*

Provides access to the audio ports supported on the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedAudioPorts | IStringIterator | Audio ports supported on the device. @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |
| result.supportedAudioPorts[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DeviceInfo.supportedAudioPorts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DeviceInfo.supportedAudioPorts"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "supportedAudioPorts": [
            ""
        ],
        "success": true
    }
}
```

<a id="supportedHdcp"></a>
## *supportedHdcp*

Supported hdcp version on the selected video display port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedHDCPVersion | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DeviceInfo.supportedHdcp",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.DeviceInfo.supportedHdcp", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "supportedHDCPVersion": "HDCP_UNAVAILABLE"
    }
}
```

<a id="supportedMS12AudioProfiles"></a>
## *supportedMS12AudioProfiles*

Supported MS12 audio profiles for the specified audio port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedMS12AudioProfiles | IStringIterator | MS12 audio profiles @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure @deprecated |
| result.supportedMS12AudioProfiles[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DeviceInfo.supportedMS12AudioProfiles",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DeviceInfo.supportedMS12AudioProfiles", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "supportedMS12AudioProfiles": [
            ""
        ],
        "success": true
    }
}
```

<a id="supportedResolutions"></a>
## *supportedResolutions*

Supported resolutions on the selected video display port.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedResolutions | IStringIterator | Supported Resolutions @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure @deprecated |
| result.supportedResolutions[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DeviceInfo.supportedResolutions",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DeviceInfo.supportedResolutions", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "supportedResolutions": [
            ""
        ],
        "success": true
    }
}
```

<a id="supportedVideoDisplays"></a>
## *supportedVideoDisplays*

Provides access to the video ports supported on the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedVideoDisplays | IStringIterator | Video ports supported on the device @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure @deprecated |
| result.supportedVideoDisplays[#] | string |  |
| result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DeviceInfo.supportedVideoDisplays"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.DeviceInfo.supportedVideoDisplays"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "supportedVideoDisplays": [
            ""
        ],
        "success": true
    }
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the DeviceInfo plugin:

DeviceInfo interface properties:

| Property | Description |
| :-------- | :-------- |
| [addresses](#addresses)<sup>RO</sup> | Provides access to the network interface addresses. |
| [brandname](#brandname)<sup>RO</sup> | Provides access to device brand name |
| [chipset](#chipset)<sup>RO</sup> | Provides access to the chipset of the device |
| [devicetype](#devicetype)<sup>RO</sup> | Provides access to the device type. |
| [distributorid](#distributorid)<sup>RO</sup> | Provides access to the partner ID or distributor ID for device. |
| [estbip](#estbip)<sup>RO</sup> | Provides access to the STB IP addresses. |
| [estbmac](#estbmac)<sup>RO</sup> | Provides access to the STB MAC addresses. |
| [ethmac](#ethmac)<sup>RO</sup> | Provides access to the Ethernet MAC addresses. |
| [firmwareversion](#firmwareversion)<sup>RO</sup> | Provides access to the versions maintained in version.txt. |
| [hostedid](#hostedid)<sup>RO</sup> | Provides access to the EDID of the host. |
| [make](#make)<sup>RO</sup> | Provides access to the device manufacturer. |
| [modelname](#modelname)<sup>RO</sup> | Provides access to the friendly device model name. |
| [releaseversion](#releaseversion)<sup>RO</sup> | Provides access to the ReleaseVersion of the Image |
| [serialnumber](#serialnumber)<sup>RO</sup> | Provides access to the serial number set by manufacture |
| [modelid](#modelid)<sup>RO</sup> | Provides access to the device model number |
| [socname](#socname)<sup>RO</sup> | Provides access to the SOC Name. |
| [systeminfo](#systeminfo)<sup>RO</sup> | Provides access to the system general information |
| [wifimac](#wifimac)<sup>RO</sup> | Provides access to the WIFI MAC addresses. |

<a id="Addresses"></a>
## *Addresses*

Provides access to the network interface addresses.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).addressesInfo | IAddressesInfoIterator | Network interface addresses @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |
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
            "name": "",
            "mac": "",
            "ip": ""
        }
    ]
}
```

<a id="Brand"></a>
## *Brand*

Provides access to device brand name

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).brand | string | Brand Name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DeviceInfo.brand"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.DeviceInfo.brand"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "brand": ""
    }
}
```

<a id="ChipSet"></a>
## *ChipSet*

Provides access to the chipset of the device

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).chipset | string | Device chip set Name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DeviceInfo.chipSet"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.DeviceInfo.chipSet"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "chipset": ""
    }
}
```

<a id="DeviceType"></a>
## *DeviceType*

Provides access to the device type.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).devicetype | string | Device type (must be one of the following: tv, IpStb, QamIpStb) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DeviceInfo.deviceType"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DeviceInfo.deviceType"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "devicetype": "DEVICE_TYPE_IPTV"
    }
}
```

<a id="DistributorId"></a>
## *DistributorId*

Provides access to the partner ID or distributor ID for device.

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
    "id": 12,
    "method": "org.rdk.DeviceInfo.distributorId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DeviceInfo.distributorId"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "distributorid": ""
    }
}
```

<a id="EstbIp"></a>
## *EstbIp*

Provides access to the STB IP addresses.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).estb_ip | string | STB IP Address |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DeviceInfo.estbIp"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.DeviceInfo.estbIp"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "estb_ip": ""
    }
}
```

<a id="EstbMac"></a>
## *EstbMac*

Provides access to the STB MAC addresses.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).estb_mac | string | STB Mac Address |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DeviceInfo.estbMac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.DeviceInfo.estbMac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "estb_mac": ""
    }
}
```

<a id="EthMac"></a>
## *EthMac*

Provides access to the Ethernet MAC addresses.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).eth_mac | string | Ethernet Mac Address |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.DeviceInfo.ethMac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.DeviceInfo.ethMac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "eth_mac": ""
    }
}
```

<a id="FirmwareVersion"></a>
## *FirmwareVersion*

Provides access to the versions maintained in version.txt.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).firmwareVersionInfo | FirmwareversionInfo | Version information @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |
| (property).firmwareVersionInfo.imagename | string | Image name |
| (property).firmwareVersionInfo.sdk | string | sdk version |
| (property).firmwareVersionInfo.mediarite | string | mediarite |
| (property).firmwareVersionInfo.yocto | string | yocto version |
| (property).firmwareVersionInfo.pdri | string | pdri version |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DeviceInfo.firmwareVersion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.DeviceInfo.firmwareVersion"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "imagename": "",
        "sdk": "",
        "mediarite": "",
        "yocto": "",
        "pdri": ""
    }
}
```

<a id="HostEDID"></a>
## *HostEDID*

Provides access to the EDID of the host.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).EDID | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.DeviceInfo.hostEDID"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.DeviceInfo.hostEDID"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "EDID": ""
    }
}
```

<a id="Make"></a>
## *Make*

Provides access to the device manufacturer.

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
    "id": 18,
    "method": "org.rdk.DeviceInfo.make"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.DeviceInfo.make"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "make": ""
    }
}
```

<a id="Model"></a>
## *Model*

Provides access to the friendly device model name.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).model | string | Friendly device model name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.DeviceInfo.model"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.DeviceInfo.model"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "model": ""
    }
}
```

<a id="ReleaseVersion"></a>
## *ReleaseVersion*

Provides access to the ReleaseVersion of the Image

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).releaseversion | string | Release version |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.DeviceInfo.releaseVersion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.DeviceInfo.releaseVersion"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "releaseversion": ""
    }
}
```

<a id="SerialNumber"></a>
## *SerialNumber*

Provides access to the serial number set by manufacture

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).serialnumber | string | Device serial number |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DeviceInfo.serialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.DeviceInfo.serialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "serialnumber": ""
    }
}
```

<a id="Sku"></a>
## *Sku*

Provides access to the device model number

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).sku | string | Device model number or SKU |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.DeviceInfo.sku"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.DeviceInfo.sku"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "sku": ""
    }
}
```

<a id="SocName"></a>
## *SocName*

Provides access to the SOC Name.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).socname | string | SOC Name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.DeviceInfo.socName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.DeviceInfo.socName"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "socname": ""
    }
}
```

<a id="SystemInfo"></a>
## *SystemInfo*

Provides access to the system general information

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).systemInfo | SystemInfos |  |
| (property).systemInfo.version | string | Software version (in form version#hashtag) |
| (property).systemInfo.uptime | integer | System uptime (in seconds) |
| (property).systemInfo.totalram | integer | Total installed system RAM memory (in bytes) |
| (property).systemInfo.freeram | integer | Free system RAM memory (in bytes) |
| (property).systemInfo.totalswap | integer | Total swap space (in bytes) |
| (property).systemInfo.freeswap | integer | Swap space still available (in bytes) |
| (property).systemInfo.devicename | string | Host name |
| (property).systemInfo.cpuload | string | Current CPU load (percentage) |
| (property).systemInfo.cpuloadavg | CpuLoadAvg | CPU load average |
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
    "id": 24,
    "method": "org.rdk.DeviceInfo.systemInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.DeviceInfo.systemInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "version": "",
        "uptime": 0,
        "totalram": 0,
        "freeram": 0,
        "totalswap": 0,
        "freeswap": 0,
        "devicename": "",
        "cpuload": "",
        "cpuloadavg": {
            "avg1min": 0,
            "avg5min": 0,
            "avg15min": 0
        },
        "serialnumber": "",
        "time": ""
    }
}
```

<a id="WifiMac"></a>
## *WifiMac*

Provides access to the WIFI MAC addresses.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).wifi_mac | string | Wifi Mac Address |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.DeviceInfo.wifiMac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.DeviceInfo.wifiMac"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "wifi_mac": ""
    }
}
```

