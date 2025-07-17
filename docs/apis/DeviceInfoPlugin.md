<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IDeviceInfo_Plugin"></a>
# IDeviceInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IDeviceInfo/CHANGELOG.md)**

A IDeviceInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `IDeviceInfo` plugin provides an interface for IDeviceInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IDeviceInfo*) |
| classname | string | Class name: *IDeviceInfo* |
| locator | string | Library name: *libWPEFrameworkIDeviceInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IDeviceInfo plugin:

IDeviceInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [AudioCapabilities](#method.AudioCapabilities) |  |
| [Brand](#method.Brand) |  |
| [ChipSet](#method.ChipSet) |  |
| [DefaultResolution](#method.DefaultResolution) |  |
| [DeviceType](#method.DeviceType) |  |
| [DistributorId](#method.DistributorId) |  |
| [HostEDID](#method.HostEDID) |  |
| [MS12Capabilities](#method.MS12Capabilities) |  |
| [Make](#method.Make) |  |
| [Model](#method.Model) |  |
| [ReleaseVersion](#method.ReleaseVersion) |  |
| [SerialNumber](#method.SerialNumber) |  |
| [Sku](#method.Sku) |  |
| [SocName](#method.SocName) |  |
| [SupportedAudioPorts](#method.SupportedAudioPorts) |  |
| [SupportedHdcp](#method.SupportedHdcp) |  |
| [SupportedMS12AudioProfiles](#method.SupportedMS12AudioProfiles) |  |
| [SupportedResolutions](#method.SupportedResolutions) |  |
| [SupportedVideoDisplays](#method.SupportedVideoDisplays) |  |

<a id="method.AudioCapabilities"></a>
## *AudioCapabilities [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.audioCapabilities | IAudioCapabilityIterator |  |
| result.audioCapabilities[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.AudioCapabilities",
    "params": {
        "audioPort": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "audioCapabilities": [
            "AUDIOCAPABILITY_NONE"
        ]
    }
}
```
<a id="method.Brand"></a>
## *Brand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.brand | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.Brand"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "brand": ""
    }
}
```
<a id="method.ChipSet"></a>
## *ChipSet [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.chipSet | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.ChipSet"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "chipSet": ""
    }
}
```
<a id="method.DefaultResolution"></a>
## *DefaultResolution [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.videoDisplay | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.defaultResolution | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.DefaultResolution",
    "params": {
        "videoDisplay": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "defaultResolution": ""
    }
}
```
<a id="method.DeviceType"></a>
## *DeviceType [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.deviceType | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.DeviceType"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "deviceType": ""
    }
}
```
<a id="method.DistributorId"></a>
## *DistributorId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.distributorId | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.DistributorId"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "distributorId": ""
    }
}
```
<a id="method.HostEDID"></a>
## *HostEDID [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.edid | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.HostEDID"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "edid": ""
    }
}
```
<a id="method.MS12Capabilities"></a>
## *MS12Capabilities [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.ms12Capabilities | IMS12CapabilityIterator |  |
| result.ms12Capabilities[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.MS12Capabilities",
    "params": {
        "audioPort": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "ms12Capabilities": [
            "MS12CAPABILITY_NONE"
        ]
    }
}
```
<a id="method.Make"></a>
## *Make [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.make | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.Make"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "make": ""
    }
}
```
<a id="method.Model"></a>
## *Model [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.model | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.Model"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "model": ""
    }
}
```
<a id="method.ReleaseVersion"></a>
## *ReleaseVersion [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.releaseVersion | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.ReleaseVersion"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "releaseVersion": ""
    }
}
```
<a id="method.SerialNumber"></a>
## *SerialNumber [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.serialNumber | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SerialNumber"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "serialNumber": ""
    }
}
```
<a id="method.Sku"></a>
## *Sku [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.sku | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.Sku"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "sku": ""
    }
}
```
<a id="method.SocName"></a>
## *SocName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.socName | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SocName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "socName": ""
    }
}
```
<a id="method.SupportedAudioPorts"></a>
## *SupportedAudioPorts [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedAudioPorts | RPC::IStringIterator |  |
| result.supportedAudioPorts[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SupportedAudioPorts"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedAudioPorts": [
            ""
        ]
    }
}
```
<a id="method.SupportedHdcp"></a>
## *SupportedHdcp [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.videoDisplay | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedHDCPVersion | CopyProtection |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SupportedHdcp",
    "params": {
        "videoDisplay": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedHDCPVersion": "HDCP_UNAVAILABLE"
    }
}
```
<a id="method.SupportedMS12AudioProfiles"></a>
## *SupportedMS12AudioProfiles [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedMS12AudioProfiles | RPC::IStringIterator |  |
| result.supportedMS12AudioProfiles[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SupportedMS12AudioProfiles",
    "params": {
        "audioPort": ""
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
            ""
        ]
    }
}
```
<a id="method.SupportedResolutions"></a>
## *SupportedResolutions [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.videoDisplay | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedResolutions | RPC::IStringIterator |  |
| result.supportedResolutions[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SupportedResolutions",
    "params": {
        "videoDisplay": ""
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
            ""
        ]
    }
}
```
<a id="method.SupportedVideoDisplays"></a>
## *SupportedVideoDisplays [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedVideoDisplays | RPC::IStringIterator |  |
| result.supportedVideoDisplays[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceInfo.SupportedVideoDisplays"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedVideoDisplays": [
            ""
        ]
    }
}
```

