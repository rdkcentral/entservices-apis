<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.DeviceInfo_Plugin"></a>
# DeviceInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/DeviceInfo/CHANGELOG.md)**

A DeviceInfo plugin for Thunder framework.

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

The `DeviceInfo` plugin provides an interface for DeviceInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceInfo) |
| classname | string | Class name: *DeviceInfo* |
| locator | string | Library name: *libWPEFrameworkDeviceInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the DeviceInfo plugin:

DeviceInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [audioCapabilities](#method.audioCapabilities) |  |
| [brand](#method.brand) |  |
| [chipSet](#method.chipSet) |  |
| [defaultResolution](#method.defaultResolution) |  |
| [deviceType](#method.deviceType) |  |
| [distributorId](#method.distributorId) |  |
| [hostEDID](#method.hostEDID) |  |
| [mS12Capabilities](#method.mS12Capabilities) |  |
| [make](#method.make) |  |
| [model](#method.model) |  |
| [releaseVersion](#method.releaseVersion) |  |
| [serialNumber](#method.serialNumber) |  |
| [sku](#method.sku) |  |
| [socName](#method.socName) |  |
| [supportedAudioPorts](#method.supportedAudioPorts) |  |
| [supportedHdcp](#method.supportedHdcp) |  |
| [supportedMS12AudioProfiles](#method.supportedMS12AudioProfiles) |  |
| [supportedResolutions](#method.supportedResolutions) |  |
| [supportedVideoDisplays](#method.supportedVideoDisplays) |  |

<a id="method.audioCapabilities"></a>
## *audioCapabilities [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.audioCapabilities | IAudioCapabilityIterator | - |
| result.audioCapabilities[#] | string | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": [
        "AUDIOCAPABILITY_NONE"
    ]
}
```

<a id="method.brand"></a>
## *brand [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.brand | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceInfo.brand"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": ""
}
```

<a id="method.chipSet"></a>
## *chipSet [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.chipSet | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceInfo.chipSet"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
}
```

<a id="method.defaultResolution"></a>
## *defaultResolution [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.defaultResolution | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DeviceInfo.defaultResolution",
    "params": {
        "videoDisplay": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```

<a id="method.deviceType"></a>
## *deviceType [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.deviceType | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DeviceInfo.deviceType"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```

<a id="method.distributorId"></a>
## *distributorId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.distributorId | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DeviceInfo.distributorId"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": ""
}
```

<a id="method.hostEDID"></a>
## *hostEDID [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.edid | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DeviceInfo.hostEDID"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": ""
}
```

<a id="method.mS12Capabilities"></a>
## *mS12Capabilities [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.ms12Capabilities | IMS12CapabilityIterator | - |
| result.ms12Capabilities[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DeviceInfo.mS12Capabilities",
    "params": {
        "audioPort": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": [
        "MS12CAPABILITY_NONE"
    ]
}
```

<a id="method.make"></a>
## *make [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.make | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DeviceInfo.make"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": ""
}
```

<a id="method.model"></a>
## *model [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.model | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DeviceInfo.model"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": ""
}
```

<a id="method.releaseVersion"></a>
## *releaseVersion [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.releaseVersion | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DeviceInfo.releaseVersion"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": ""
}
```

<a id="method.serialNumber"></a>
## *serialNumber [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.serialNumber | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DeviceInfo.serialNumber"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": ""
}
```

<a id="method.sku"></a>
## *sku [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.sku | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DeviceInfo.sku"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": ""
}
```

<a id="method.socName"></a>
## *socName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.socName | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DeviceInfo.socName"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": ""
}
```

<a id="method.supportedAudioPorts"></a>
## *supportedAudioPorts [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedAudioPorts | RPC::IStringIterator | - |
| result.supportedAudioPorts[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DeviceInfo.supportedAudioPorts"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": [
        ""
    ]
}
```

<a id="method.supportedHdcp"></a>
## *supportedHdcp [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedHDCPVersion | CopyProtection | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.DeviceInfo.supportedHdcp",
    "params": {
        "videoDisplay": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": "HDCP_UNAVAILABLE"
}
```

<a id="method.supportedMS12AudioProfiles"></a>
## *supportedMS12AudioProfiles [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedMS12AudioProfiles | RPC::IStringIterator | - |
| result.supportedMS12AudioProfiles[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DeviceInfo.supportedMS12AudioProfiles",
    "params": {
        "audioPort": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": [
        ""
    ]
}
```

<a id="method.supportedResolutions"></a>
## *supportedResolutions [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedResolutions | RPC::IStringIterator | - |
| result.supportedResolutions[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.DeviceInfo.supportedResolutions",
    "params": {
        "videoDisplay": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": [
        ""
    ]
}
```

<a id="method.supportedVideoDisplays"></a>
## *supportedVideoDisplays [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedVideoDisplays | RPC::IStringIterator | - |
| result.supportedVideoDisplays[#] | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DeviceInfo.supportedVideoDisplays"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": [
        ""
    ]
}
```


