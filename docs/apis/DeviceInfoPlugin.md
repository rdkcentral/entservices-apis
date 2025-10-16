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
| [imagename](#method.imagename) |  |
| [mediarite](#method.mediarite) |  |
| [sdk](#method.sdk) |  |
| [yocto](#method.yocto) |  |

<a id="method.audioCapabilities"></a>
## *audioCapabilities [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.audioCapabilities | IAudioCapabilityIterator |  |
| result.audioCapabilities[#] | string |  |

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
    "result": [
        "AUDIOCAPABILITY_NONE"
    ]
}
```

<a id="method.brand"></a>
## *brand [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.brand | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceInfo.brand"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DeviceInfo.brand"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "brand": ""
    }
}
```

<a id="method.chipSet"></a>
## *chipSet [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.chipSet | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceInfo.chipSet"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DeviceInfo.chipSet"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "chipSet": ""
    }
}
```

<a id="method.defaultResolution"></a>
## *defaultResolution [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string |  |
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
    "id": 3,
    "method": "org.rdk.DeviceInfo.defaultResolution",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DeviceInfo.defaultResolution", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "defaultResolution": ""
    }
}
```

<a id="method.deviceType"></a>
## *deviceType [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.deviceType | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DeviceInfo.deviceType"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.DeviceInfo.deviceType"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "deviceType": ""
    }
}
```

<a id="method.distributorId"></a>
## *distributorId [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.distributorId | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DeviceInfo.distributorId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DeviceInfo.distributorId"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "distributorId": ""
    }
}
```

<a id="method.hostEDID"></a>
## *hostEDID [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.edid | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DeviceInfo.hostEDID"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DeviceInfo.hostEDID"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "edid": ""
    }
}
```

<a id="method.mS12Capabilities"></a>
## *mS12Capabilities [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.ms12Capabilities | IMS12CapabilityIterator |  |
| result.ms12Capabilities[#] | string |  |

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.DeviceInfo.mS12Capabilities", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
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
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.make | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DeviceInfo.make"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.DeviceInfo.make"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "make": ""
    }
}
```

<a id="method.model"></a>
## *model [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.model | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DeviceInfo.model"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.DeviceInfo.model"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "model": ""
    }
}
```

<a id="method.releaseVersion"></a>
## *releaseVersion [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.releaseVersion | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DeviceInfo.releaseVersion"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.DeviceInfo.releaseVersion"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "releaseVersion": ""
    }
}
```

<a id="method.serialNumber"></a>
## *serialNumber [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.serialNumber | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DeviceInfo.serialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DeviceInfo.serialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "serialNumber": ""
    }
}
```

<a id="method.sku"></a>
## *sku [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sku | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DeviceInfo.sku"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DeviceInfo.sku"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "sku": ""
    }
}
```

<a id="method.socName"></a>
## *socName [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.socName | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DeviceInfo.socName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.DeviceInfo.socName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "socName": ""
    }
}
```

<a id="method.supportedAudioPorts"></a>
## *supportedAudioPorts [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedAudioPorts | RPC::IStringIterator |  |
| result.supportedAudioPorts[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DeviceInfo.supportedAudioPorts"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.DeviceInfo.supportedAudioPorts"}' http://127.0.0.1:9998/jsonrpc
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
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string |  |
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
    "id": 15,
    "method": "org.rdk.DeviceInfo.supportedHdcp",
    "params": {
        "videoDisplay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.DeviceInfo.supportedHdcp", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "supportedHDCPVersion": "HDCP_UNAVAILABLE"
    }
}
```

<a id="method.supportedMS12AudioProfiles"></a>
## *supportedMS12AudioProfiles [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioPort | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedMS12AudioProfiles | RPC::IStringIterator |  |
| result.supportedMS12AudioProfiles[#] | string |  |

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.DeviceInfo.supportedMS12AudioProfiles", "params": {"audioPort": ""}}' http://127.0.0.1:9998/jsonrpc
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
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoDisplay | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedResolutions | RPC::IStringIterator |  |
| result.supportedResolutions[#] | string |  |

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.DeviceInfo.supportedResolutions", "params": {"videoDisplay": ""}}' http://127.0.0.1:9998/jsonrpc
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
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedVideoDisplays | RPC::IStringIterator |  |
| result.supportedVideoDisplays[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DeviceInfo.supportedVideoDisplays"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.DeviceInfo.supportedVideoDisplays"}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.imagename"></a>
## *imagename [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.imagename | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceInfo.imagename"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DeviceInfo.imagename"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "imagename": ""
    }
}
```

<a id="method.mediarite"></a>
## *mediarite [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mediarite | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceInfo.mediarite"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DeviceInfo.mediarite"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "mediarite": ""
    }
}
```

<a id="method.sdk"></a>
## *sdk [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sdk | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceInfo.sdk"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DeviceInfo.sdk"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "sdk": ""
    }
}
```

<a id="method.yocto"></a>
## *yocto [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.yocto | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DeviceInfo.yocto"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DeviceInfo.yocto"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "yocto": ""
    }
}
```


