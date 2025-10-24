<!-- Generated automatically, DO NOT EDIT! -->
<a id="DeviceInfo_Plugin"></a>
# DeviceInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DeviceInfo)**

A DeviceInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

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
| [audioCapabilities](#audioCapabilities) |  |
| [brand](#brand) |  |
| [chipSet](#chipSet) |  |
| [defaultResolution](#defaultResolution) |  |
| [deviceType](#deviceType) |  |
| [distributorId](#distributorId) |  |
| [hostEDID](#hostEDID) |  |
| [mS12Capabilities](#mS12Capabilities) |  |
| [make](#make) |  |
| [model](#model) |  |
| [releaseVersion](#releaseVersion) |  |
| [serialNumber](#serialNumber) |  |
| [sku](#sku) |  |
| [socName](#socName) |  |
| [supportedAudioPorts](#supportedAudioPorts) |  |
| [supportedHdcp](#supportedHdcp) |  |
| [supportedMS12AudioProfiles](#supportedMS12AudioProfiles) |  |
| [supportedResolutions](#supportedResolutions) |  |
| [supportedVideoDisplays](#supportedVideoDisplays) |  |
| [imagename](#imagename) |  |
| [mediarite](#mediarite) |  |
| [sdk](#sdk) |  |
| [yocto](#yocto) |  |

<a id="audioCapabilities"></a>
## *audioCapabilities*



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

<a id="brand"></a>
## *brand*



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

<a id="chipSet"></a>
## *chipSet*



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

<a id="defaultResolution"></a>
## *defaultResolution*



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

<a id="deviceType"></a>
## *deviceType*



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

<a id="distributorId"></a>
## *distributorId*



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

<a id="hostEDID"></a>
## *hostEDID*



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

<a id="mS12Capabilities"></a>
## *mS12Capabilities*



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

<a id="make"></a>
## *make*



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

<a id="model"></a>
## *model*



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

<a id="releaseVersion"></a>
## *releaseVersion*



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

<a id="serialNumber"></a>
## *serialNumber*



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

<a id="sku"></a>
## *sku*



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

<a id="socName"></a>
## *socName*



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

<a id="supportedAudioPorts"></a>
## *supportedAudioPorts*



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

<a id="supportedHdcp"></a>
## *supportedHdcp*



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

<a id="supportedMS12AudioProfiles"></a>
## *supportedMS12AudioProfiles*



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

<a id="supportedResolutions"></a>
## *supportedResolutions*



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

<a id="supportedVideoDisplays"></a>
## *supportedVideoDisplays*



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

<a id="imagename"></a>
## *imagename*



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

<a id="mediarite"></a>
## *mediarite*



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

<a id="sdk"></a>
## *sdk*



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

<a id="yocto"></a>
## *yocto*



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


