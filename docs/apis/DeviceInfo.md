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
| callsign | string | Plugin instance name (default: DeviceInfo) |
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

<a id="audiocapabilities"></a>
## *audiocapabilities*

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
    "method": "DeviceInfo.audiocapabilities",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "DeviceInfo.audiocapabilities", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="defaultresolution"></a>
## *defaultresolution*

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
    "method": "DeviceInfo.defaultresolution",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "DeviceInfo.defaultresolution", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="ms12capabilities"></a>
## *ms12capabilities*

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
    "method": "DeviceInfo.ms12capabilities",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "DeviceInfo.ms12capabilities", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="supportedaudioports"></a>
## *supportedaudioports*

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
    "method": "DeviceInfo.supportedaudioports"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "DeviceInfo.supportedaudioports"}' http://127.0.0.1:9998/jsonrpc
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

<a id="supportedhdcp"></a>
## *supportedhdcp*

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
    "method": "DeviceInfo.supportedhdcp",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "DeviceInfo.supportedhdcp", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="supportedms12audioprofiles"></a>
## *supportedms12audioprofiles*

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
    "method": "DeviceInfo.supportedms12audioprofiles",
    "params": {
        "audioPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "DeviceInfo.supportedms12audioprofiles", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="supportedresolutions"></a>
## *supportedresolutions*

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
    "method": "DeviceInfo.supportedresolutions",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "DeviceInfo.supportedresolutions", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="supportedvideodisplays"></a>
## *supportedvideodisplays*

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
    "method": "DeviceInfo.supportedvideodisplays"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "DeviceInfo.supportedvideodisplays"}' http://127.0.0.1:9998/jsonrpc
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

<a id="addresses"></a>
## *addresses*

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
    "method": "DeviceInfo.addresses"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "DeviceInfo.addresses"}' http://127.0.0.1:9998/jsonrpc
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

<a id="brandname"></a>
## *brandname*

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
    "method": "DeviceInfo.brandname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "DeviceInfo.brandname"}' http://127.0.0.1:9998/jsonrpc
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

<a id="chipset"></a>
## *chipset*

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
    "method": "DeviceInfo.chipset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "DeviceInfo.chipset"}' http://127.0.0.1:9998/jsonrpc
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

<a id="devicetype"></a>
## *devicetype*

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
    "method": "DeviceInfo.devicetype"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "DeviceInfo.devicetype"}' http://127.0.0.1:9998/jsonrpc
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

<a id="distributorid"></a>
## *distributorid*

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
    "method": "DeviceInfo.distributorid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "DeviceInfo.distributorid"}' http://127.0.0.1:9998/jsonrpc
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

<a id="estbip"></a>
## *estbip*

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
    "method": "DeviceInfo.estbip"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "DeviceInfo.estbip"}' http://127.0.0.1:9998/jsonrpc
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

<a id="estbmac"></a>
## *estbmac*

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
    "method": "DeviceInfo.estbmac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "DeviceInfo.estbmac"}' http://127.0.0.1:9998/jsonrpc
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

<a id="ethmac"></a>
## *ethmac*

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
    "method": "DeviceInfo.ethmac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "DeviceInfo.ethmac"}' http://127.0.0.1:9998/jsonrpc
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

<a id="firmwareversion"></a>
## *firmwareversion*

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
    "method": "DeviceInfo.firmwareversion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "DeviceInfo.firmwareversion"}' http://127.0.0.1:9998/jsonrpc
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

<a id="hostedid"></a>
## *hostedid*

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
    "method": "DeviceInfo.hostedid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "DeviceInfo.hostedid"}' http://127.0.0.1:9998/jsonrpc
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

<a id="make"></a>
## *make*

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
    "method": "DeviceInfo.make"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "DeviceInfo.make"}' http://127.0.0.1:9998/jsonrpc
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

<a id="modelname"></a>
## *modelname*

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
    "method": "DeviceInfo.modelname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "DeviceInfo.modelname"}' http://127.0.0.1:9998/jsonrpc
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

<a id="releaseversion"></a>
## *releaseversion*

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
    "method": "DeviceInfo.releaseversion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "DeviceInfo.releaseversion"}' http://127.0.0.1:9998/jsonrpc
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

<a id="serialnumber"></a>
## *serialnumber*

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
    "method": "DeviceInfo.serialnumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "DeviceInfo.serialnumber"}' http://127.0.0.1:9998/jsonrpc
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

<a id="modelid"></a>
## *modelid*

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
    "method": "DeviceInfo.modelid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "DeviceInfo.modelid"}' http://127.0.0.1:9998/jsonrpc
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

<a id="socname"></a>
## *socname*

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
    "method": "DeviceInfo.socname"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "DeviceInfo.socname"}' http://127.0.0.1:9998/jsonrpc
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

<a id="systeminfo"></a>
## *systeminfo*

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
    "method": "DeviceInfo.systeminfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "DeviceInfo.systeminfo"}' http://127.0.0.1:9998/jsonrpc
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

<a id="wifimac"></a>
## *wifimac*

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
    "method": "DeviceInfo.wifimac"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "DeviceInfo.wifimac"}' http://127.0.0.1:9998/jsonrpc
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

