<!-- Generated automatically, DO NOT EDIT! -->
<a name="DeviceInfo_Plugin"></a>
# DeviceInfo Plugin

A DeviceInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `DeviceInfo` plugin allows retrieving of various device-related information.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *DeviceInfo*) |
| classname | string | Class name: *DeviceInfo* |
| locator | string | Library name: *libWPEFrameworkDeviceInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the DeviceInfo plugin:

DeviceInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [supportedresolutions](#supportedresolutions) | Supported resolutions on the selected video display port |
| [defaultresolution](#defaultresolution) | Default resolution on the selected video display port |
| [supportedhdcp](#supportedhdcp) | Supported hdcp version on the selected video display port |
| [audiocapabilities](#audiocapabilities) | Audio capabilities for the specified audio port |
| [ms12capabilities](#ms12capabilities) | MS12 audio capabilities for the specified audio port |
| [supportedms12audioprofiles](#supportedms12audioprofiles) | Supported MS12 audio profiles for the specified audio port |


<a name="supportedresolutions"></a>
## *supportedresolutions*

Supported resolutions on the selected video display port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedResolutions | array |  |
| result.supportedResolutions[#] | string | Resolution supported by the device (must be one of the following: *unknown*, *480i*, *480p*, *576i*, *576p*, *576p50*, *720p*, *720p50*, *1080i*, *1080i25*, *1080i50*, *1080p*, *1080p24*, *1080p25*, *1080p30*, *1080p50*, *1080p60*, *2160p30*, *2160p50*, *2160p60*, *4320p30*, *4320p60*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.supportedresolutions",
    "params": {
        "videoDisplay": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedResolutions": [
            "1080p"
        ]
    }
}
```

<a name="defaultresolution"></a>
## *defaultresolution*

Default resolution on the selected video display port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.defaultResolution | string | Resolution supported by the device (must be one of the following: *unknown*, *480i*, *480p*, *576i*, *576p*, *576p50*, *720p*, *720p50*, *1080i*, *1080i25*, *1080i50*, *1080p*, *1080p24*, *1080p25*, *1080p30*, *1080p50*, *1080p60*, *2160p30*, *2160p50*, *2160p60*, *4320p30*, *4320p60*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.defaultresolution",
    "params": {
        "videoDisplay": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "defaultResolution": "1080p"
    }
}
```

<a name="supportedhdcp"></a>
## *supportedhdcp*

Supported hdcp version on the selected video display port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | Video display port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedHDCPVersion | string | HDCP support (must be one of the following: *unavailable*, *1.4*, *2.0*, *2.1*, *2.2*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.supportedhdcp",
    "params": {
        "videoDisplay": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedHDCPVersion": "hdcp_20"
    }
}
```

<a name="audiocapabilities"></a>
## *audiocapabilities*

Audio capabilities for the specified audio port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.AudioCapabilities | array | An array of audio capabilities |
| result.AudioCapabilities[#] | string | Audio capability (must be one of the following: *none*, *ATMOS*, *DOLBY DIGITAL*, *DOLBY DIGITAL PLUS*, *Dual Audio Decode*, *DAPv2*, *MS12*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.audiocapabilities",
    "params": {
        "audioPort": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "AudioCapabilities": [
            "none"
        ]
    }
}
```

<a name="ms12capabilities"></a>
## *ms12capabilities*

MS12 audio capabilities for the specified audio port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.MS12Capabilities | array | An array of MS12 audio capabilities |
| result.MS12Capabilities[#] | string | MS12 audio capability (must be one of the following: *none*, *Dolby Volume*, *Inteligent Equalizer*, *Dialogue Enhancer*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.ms12capabilities",
    "params": {
        "audioPort": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "MS12Capabilities": [
            "Dolby Volume"
        ]
    }
}
```

<a name="supportedms12audioprofiles"></a>
## *supportedms12audioprofiles*

Supported MS12 audio profiles for the specified audio port.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | Audio port name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedMS12AudioProfiles | array | An array of MS12 audio profiles |
| result.supportedMS12AudioProfiles[#] | string |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.supportedms12audioprofiles",
    "params": {
        "audioPort": "HDMI0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedMS12AudioProfiles": [
            "Movie"
        ]
    }
}
```

<a name="Properties"></a>
# Properties

The following properties are provided by the DeviceInfo plugin:

DeviceInfo interface properties:

| Property | Description |
| :-------- | :-------- |
| [systeminfo](#systeminfo) <sup>RO</sup> | System general information |
| [addresses](#addresses) <sup>RO</sup> | Network interface addresses |
| [socketinfo](#socketinfo) <sup>RO</sup> | Socket information |
| [firmwareversion](#firmwareversion) <sup>RO</sup> | Versions maintained in version |
| [serialnumber](#serialnumber) <sup>RO</sup> | Serial number set by manufacturer |
| [modelid](#modelid) <sup>RO</sup> | Device model number or SKU |
| [make](#make) <sup>RO</sup> | Device manufacturer |
| [modelname](#modelname) <sup>RO</sup> | Friendly device model name |
| [devicetype](#devicetype) <sup>RO</sup> | Device type |
| [socname](#socname) <sup>RO</sup> | SOC Name |
| [distributorid](#distributorid) <sup>RO</sup> | Partner ID or distributor ID for device |
| [supportedaudioports](#supportedaudioports) <sup>RO</sup> | Audio ports supported on the device (all ports that are physically present) |
| [supportedvideodisplays](#supportedvideodisplays) <sup>RO</sup> | Video ports supported on the device (all ports that are physically present) |
| [hostedid](#hostedid) <sup>RO</sup> | EDID of the host |


<a name="systeminfo"></a>
## *systeminfo*

Provides access to the system general information.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | System general information |
| (property).version | string | Software version (in form *version#hashtag*) |
| (property).uptime | number | System uptime (in seconds) |
| (property).totalram | number | Total installed system RAM memory (in bytes) |
| (property).freeram | number | Free system RAM memory (in bytes) |
| (property).totalswap | number | Total swap space (in bytes) |
| (property).freeswap | number | Swap space still available (in bytes) |
| (property).devicename | string | Host name |
| (property).cpuload | string | Current CPU load (percentage) |
| (property).cpuloadavg | object | CPU load average |
| (property).cpuloadavg.avg1min | number | 1min cpuload average |
| (property).cpuloadavg.avg5min | number | 5min cpuload average |
| (property).cpuloadavg.avg15min | number | 15min cpuload average |
| (property).serialnumber | string | Device serial number |
| (property).time | string | Current system date and time |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.systeminfo"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "version": "1.0#14452f612c3747645d54974255d11b8f3b4faa54",
        "uptime": 120,
        "totalram": 655757312,
        "freeram": 563015680,
        "totalswap": 789132680,
        "freeswap": 789132680,
        "devicename": "buildroot",
        "cpuload": "2",
        "cpuloadavg": {
            "avg1min": 789132680,
            "avg5min": 789132680,
            "avg15min": 789132680
        },
        "serialnumber": "aplhanumerical string",
        "time": "Mon, 11 Mar 2019 14:38:18"
    }
}
```

<a name="addresses"></a>
## *addresses*

Provides access to the network interface addresses.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | array | Network interface addresses |
| (property)[#] | object |  |
| (property)[#].name | string | Interface name |
| (property)[#].mac | string | Interface MAC address |
| (property)[#]?.ip | array | <sup>*(optional)*</sup>  |
| (property)[#]?.ip[#] | string | <sup>*(optional)*</sup> Interface IP address |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.addresses"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "name": "lo",
            "mac": "00:00:00:00:00",
            "ip": [
                "127.0.0.1"
            ]
        }
    ]
}
```

<a name="socketinfo"></a>
## *socketinfo*

Provides access to the socket information.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Socket information |
| (property)?.total | number | <sup>*(optional)*</sup>  |
| (property)?.open | number | <sup>*(optional)*</sup>  |
| (property)?.link | number | <sup>*(optional)*</sup>  |
| (property)?.exception | number | <sup>*(optional)*</sup>  |
| (property)?.shutdown | number | <sup>*(optional)*</sup>  |
| (property).runs | number | Number of runs |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.socketinfo"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "total": 0,
        "open": 0,
        "link": 0,
        "exception": 0,
        "shutdown": 0,
        "runs": 1
    }
}
```

<a name="firmwareversion"></a>
## *firmwareversion*

Provides access to the versions maintained in version.txt.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Versions maintained in version.txt |
| (property).imagename | string |  |
| (property)?.sdk | string | <sup>*(optional)*</sup>  |
| (property)?.mediarite | string | <sup>*(optional)*</sup>  |
| (property)?.yocto | string | <sup>*(optional)*</sup> Yocto version (must be one of the following: *kirkstone*, *dunfell*, *morty*, *daisy*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.firmwareversion"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "imagename": "alphanumerical string",
        "sdk": "17.3",
        "mediarite": "8.3.53",
        "yocto": "dunfell"
    }
}
```

<a name="serialnumber"></a>
## *serialnumber*

Provides access to the serial number set by manufacturer.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Serial number set by manufacturer |
| (property).serialnumber | string |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.serialnumber"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "serialnumber": "alphanumerical string"
    }
}
```

<a name="modelid"></a>
## *modelid*

Provides access to the device model number or SKU.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Device model number or SKU |
| (property).sku | string | Device model number or SKU |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.modelid"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "sku": "alphanumerical string"
    }
}
```

<a name="make"></a>
## *make*

Provides access to the device manufacturer.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Device manufacturer |
| (property).make | string | Device manufacturer |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.make"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "make": "alphanumerical string"
    }
}
```

<a name="modelname"></a>
## *modelname*

Provides access to the friendly device model name.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Friendly device model name |
| (property).model | string |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.modelname"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "model": "alphanumerical string"
    }
}
```

<a name="devicetype"></a>
## *devicetype*

Provides access to the device type.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Device type |
| (property).devicetype | string | Device type (must be one of the following: *tv*, *IpStb*, *QamIpStb*) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.devicetype"
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

<a name="socname"></a>
## *socname*

Provides access to the SOC Name.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | SOC Name |
| (property).socname | string | SOC Name |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.socname"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "socname": "alphanumerical string"
    }
}
```

<a name="distributorid"></a>
## *distributorid*

Provides access to the partner ID or distributor ID for device.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Partner ID or distributor ID for device |
| (property).distributorid | string | Partner ID or distributor ID for device |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.distributorid"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "distributorid": "aplhanumerical string"
    }
}
```

<a name="supportedaudioports"></a>
## *supportedaudioports*

Provides access to the audio ports supported on the device (all ports that are physically present).

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Audio ports supported on the device (all ports that are physically present) |
| (property).supportedAudioPorts | array |  |
| (property).supportedAudioPorts[#] | string |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.supportedaudioports"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedAudioPorts": [
            "HDMI0"
        ]
    }
}
```

<a name="supportedvideodisplays"></a>
## *supportedvideodisplays*

Provides access to the video ports supported on the device (all ports that are physically present).

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Video ports supported on the device (all ports that are physically present) |
| (property).supportedVideoDisplays | array |  |
| (property).supportedVideoDisplays[#] | string |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.supportedvideodisplays"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedVideoDisplays": [
            "HDMI0"
        ]
    }
}
```

<a name="hostedid"></a>
## *hostedid*

Provides access to the EDID of the host.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | EDID of the host |
| (property).EDID | string | A base64 encoded byte array string representing the EDID |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "DeviceInfo.hostedid"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "EDID": "AP///////wAQrMLQVEJTMQUdAQOANR546q11qVRNnSYPUFSlSwCBALMA0QBxT6lAgYDRwAEBVl4AoKCgKVAwIDUADighAAAaAAAA/wBNWTNORDkxVjFTQlQKAAAA/ABERUxMIFAyNDE4RAogAAAA/QAxVh1xHAAKICAgICAgARsCAxuxUJAFBAMCBxYBBhESFRMUHyBlAwwAEAACOoAYcTgtQFgsRQAOKCEAAB4BHYAYcRwWIFgsJQAOKCEAAJ6/FgCggDgTQDAgOgAOKCEAABp+OQCggDgfQDAgOgAOKCEAABoAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA2A"
    }
}
```

