<!-- Generated automatically, DO NOT EDIT! -->
<a id="AVInput_Module"></a>
# AVInput Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AVInput/IAVInput.h)**

A AVInput module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IAVInput](#IAVInput)
    - [Methods](#IAVInput-Methods)
    - [Notifications](#IAVInput-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AVInput` module provides the following interface(s):

- IAVInput

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AVInput) |
| classname | string | Class name: *AVInput* |
| locator | string | Library name: *libWPEFrameworkAVInput.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IAVInput"></a>
## IAVInput Interface

<a id="IAVInput-Methods"></a>
### Methods

The following methods are provided by the IAVInput Interface:

| Method | Description |
| :-------- | :-------- |
| [contentProtected](#contentProtected) | Returns whether the content is protected for the specified input device |
| [currentVideoMode](#currentVideoMode) | Returns the current video mode for the specified input device |
| [getARCPortId](#getARCPortId) | Returns the Arc portID of the panel |
| [getEdid2AllmSupport](#getEdid2AllmSupport) | Returns the ALLM bit in EDID |
| [getEdidVersion](#getEdidVersion) | Returns the EDID version |
| [getGameFeatureStatus](#getGameFeatureStatus) | Returns the Game Feature Status. For example: ALLM. |
| [getHdmiVersion](#getHdmiVersion) | Gets the maximum hdmi compatibility version supported for the given port. |
| [getRawSPD](#getRawSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits |
| [getSPD](#getSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device |
| [getSupportedGameFeatures](#getSupportedGameFeatures) | Returns the list of supported game features. |
| [getVRRFrameRate](#getVRRFrameRate) | Returns the current VRR frame rate for the specified input device |
| [getVRRSupport](#getVRRSupport) | Returns the VRR support bit in EDID |
| [numberOfInputs](#numberOfInputs) | Returns an integer that specifies the number of available inputs |
| [readEDID](#readEDID) | Returns the current EDID value. |
| [setEdid2AllmSupport](#setEdid2AllmSupport) | Sets an HDMI ALLM bit in EDID. |
| [setEdidVersion](#setEdidVersion) | Sets an HDMI EDID version |
| [setMixerLevels](#setMixerLevels) | Sets the audio mixer level for given audio input. |
| [setVRRSupport](#setVRRSupport) | Sets an HDMI VRR support bit in EDID |
| [setVideoRectangle](#setVideoRectangle) | Sets an HDMI/Composite Input video window. |
| [startInput](#startInput) | Activates the specified HDMI/Composite Input port as the primary video source. |
| [stopInput](#stopInput) | Deactivates the HDMI/Composite Input port currently selected as the primary video source. |
| [writeEDID](#writeEDID) | Changes a current EDID value. |

<a id="contentProtected"></a>
## *contentProtected*

Queries the AV Input subsystem to determine whether the currently active HDMI or Composite input is carrying protected content. Content protection is typically enforced using HDCP or other content protection mechanisms and can be used by applications to determine whether restricted playback or recording policies should be applied.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.isContentProtected | bool | Whether the HDMI input is protected |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.AVInput.contentProtected"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AVInput.contentProtected"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "isContentProtected": true,
        "success": true
    }
}
```

<a id="currentVideoMode"></a>
## *currentVideoMode*

Retrieves the active video resolution and refresh rate profile currently running on the specified input device pipeline.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentVideoMode | string | The current video mode |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.AVInput.currentVideoMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AVInput.currentVideoMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "currentVideoMode": "1920x1080p60",
        "success": true
    }
}
```

<a id="getARCPortId"></a>
## *getARCPortId*

Retrieves the unique hardware identifier of the active Audio Return Channel (ARC) port available on the display panel.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.portId | string | The arc port Id |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.AVInput.getARCPortId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AVInput.getARCPortId"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "portId": "HDMI0",
        "success": true
    }
}
```

<a id="getEdid2AllmSupport"></a>
## *getEdid2AllmSupport*

Retrieves the Auto Low Latency Mode (ALLM) support bit from the EDID structure for the specified HDMI input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | The ID of the input device to get the ALLM |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.allmSupport | bool | The ALLM bit value in edid |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AVInput.getEdid2AllmSupport",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AVInput.getEdid2AllmSupport", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "allmSupport": true,
        "success": true
    }
}
```

<a id="getEdidVersion"></a>
## *getEdidVersion*

Retrieves the active EDID structural standard version profile currently exposed on the specified HDMI port interface.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.edidVersion | string | The EDID version |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.AVInput.getEdidVersion",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AVInput.getEdidVersion", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "edidVersion": "HDMI_VERSION_2.0",
        "success": true
    }
}
```

<a id="getGameFeatureStatus"></a>
## *getGameFeatureStatus*

Queries the activation runtime toggle state of a specific gaming enhancement capability mapped to the active interface.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI Input port as returned by the getInputDevices method |
| params.gameFeature | string | Game Feature to which current status requested |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mode | bool | The current game feature status. Mode is required only for ALLM. Need to add support for future game features |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.AVInput.getGameFeatureStatus",
    "params": {
        "portId": "HDMI0",
        "gameFeature": "ALLM"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.AVInput.getGameFeatureStatus", "params": {"portId": "HDMI0", "gameFeature": "ALLM"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "mode": true,
        "success": true
    }
}
```

<a id="getHdmiVersion"></a>
## *getHdmiVersion*

Retrieves the highest HDMI version that the specified HDMI input port can support.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.HdmiCapabilityVersion | string | The Maximum Hdmi compatibility version supported by the given port |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.AVInput.getHdmiVersion",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.AVInput.getHdmiVersion", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "HdmiCapabilityVersion": "HDMI_VERSION_2.1",
        "success": true
    }
}
```

<a id="getRawSPD"></a>
## *getRawSPD*

Retrieves the raw binary payload of the Source Product Descriptor infoFrame transmitted from the source device connected to the specified input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.HDMISPD | string | The SPD information as raw bits |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.AVInput.getRawSPD",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AVInput.getRawSPD", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "HDMISPD": "Vendor:Comcast,Product:Xi6,Source:1",
        "success": true
    }
}
```

<a id="getSPD"></a>
## *getSPD*

Retrieves the structured Source Product Descriptor infoFrame data transmitted from the device connected to the specified input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.HDMISPD | string | The SPD information |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.AVInput.getSPD",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AVInput.getSPD", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "HDMISPD": "Vendor:Comcast,Product:Xi6,Source:1",
        "success": true
    }
}
```

<a id="getSupportedGameFeatures"></a>
## *getSupportedGameFeatures*

Retrieves the array list of advanced gaming optimization features natively supported by the hardware interface layout.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedGameFeatures | array | The supported game Features |
| result.supportedGameFeatures[#] | string |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.AVInput.getSupportedGameFeatures"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AVInput.getSupportedGameFeatures"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "supportedGameFeatures": [
            "ALLM",
            "VRR",
            "QFT"
        ],
        "success": true
    }
}
```

<a id="getVRRFrameRate"></a>
## *getVRRFrameRate*

Retrieves the active real-time rendering frame rate frequency operating on the variable refresh rate pipeline.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentVRRVideoFrameRate | double | The current VRR frame rate |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.AVInput.getVRRFrameRate",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AVInput.getVRRFrameRate", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "currentVRRVideoFrameRate": 59.94,
        "success": true
    }
}
```

<a id="getVRRSupport"></a>
## *getVRRSupport*

Retrieves the Variable Refresh Rate (VRR) support bit within the EDID structure for the specified HDMI input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | The ID of the input device to get the VRR |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.vrrSupport | bool | The VRR support bit value |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.AVInput.getVRRSupport",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AVInput.getVRRSupport", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "vrrSupport": true,
        "success": true
    }
}
```

<a id="numberOfInputs"></a>
## *numberOfInputs*

Retrieves the total count of hardware or streaming input ports currently available on the device.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberOfInputs | integer | The number of inputs that are available for selection |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.AVInput.numberOfInputs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AVInput.numberOfInputs"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "numberOfInputs": 4,
        "success": true
    }
}
```

<a id="readEDID"></a>
## *readEDID*

Retrieves the detailed EDID raw data block currently exposed by the specified active HDMI input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.EDID | string | The EDID Value |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.AVInput.readEDID",
    "params": {
        "portId": "HDMI0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AVInput.readEDID", "params": {"portId": "HDMI0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "EDID": "00FFFFFFFFFFFF0010AC44A04C5A5530",
        "success": true
    }
}
```

<a id="setEdid2AllmSupport"></a>
## *setEdid2AllmSupport*

Configures the Auto Low Latency Mode (ALLM) support bit within the EDID structure for the specified HDMI input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.allmSupport | bool | The ALLM support in EDID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.AVInput.setEdid2AllmSupport",
    "params": {
        "portId": "HDMI0",
        "allmSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.AVInput.setEdid2AllmSupport", "params": {"portId": "HDMI0", "allmSupport": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "success": true
    }
}
```

<a id="setEdidVersion"></a>
## *setEdidVersion*

Configures the active EDID structural standard version profile exposed to source transmitters on the specified HDMI port interface.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.edidVersion | string | The EDID version |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.AVInput.setEdidVersion",
    "params": {
        "portId": "HDMI0",
        "edidVersion": "HDMI_VERSION_2.0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.AVInput.setEdidVersion", "params": {"portId": "HDMI0", "edidVersion": "HDMI_VERSION_2.0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "success": true
    }
}
```

<a id="setMixerLevels"></a>
## *setMixerLevels*

Configures the dual-stream relative volume mixing levels across the main primary channel and secondary input source.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.primaryVolume | int | Primary audio input volume |
| params.inputVolume | int | System audio input volume |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.AVInput.setMixerLevels",
    "params": {
        "primaryVolume": 80,
        "inputVolume": 40
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.AVInput.setMixerLevels", "params": {"primaryVolume": 80, "inputVolume": 40}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "success": true
    }
}
```

<a id="setVRRSupport"></a>
## *setVRRSupport*

Configures the Variable Refresh Rate (VRR) support bit within the EDID structure for the specified HDMI input port.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | The ID of the input device to set the VRR |
| params.vrrSupport | bool | The VRR support bit value to set |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.AVInput.setVRRSupport",
    "params": {
        "portId": "HDMI0",
        "vrrSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.AVInput.setVRRSupport", "params": {"portId": "HDMI0", "vrrSupport": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "success": true
    }
}
```

<a id="setVideoRectangle"></a>
## *setVideoRectangle*

Sets the geometric display boundaries (x, y coordinates alongside width and height) for the active input video stream.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.x | integer | The x-coordinate of the video rectangle |
| params.y | integer | The y-coordinate of the video rectangle |
| params.w | integer | The width of the video rectangle |
| params.h | integer | The height of the video rectangle |
| params.typeOfInput | string | The type of Input - HDMI/COMPOSITE |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.AVInput.setVideoRectangle",
    "params": {
        "x": 0,
        "y": 0,
        "w": 1920,
        "h": 1080,
        "typeOfInput": "HDMI"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.AVInput.setVideoRectangle", "params": {"x": 0, "y": 0, "w": 1920, "h": 1080, "typeOfInput": "HDMI"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "success": true
    }
}
```

<a id="startInput"></a>
## *startInput*

Initializes and displays the video stream from the designated input port onto the specified display plane layer with optional audio mixing options.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.typeOfInput | string | The type of Input - HDMI/COMPOSITE |
| params.requestAudioMix | bool | Defines whether the Audio mixing is true or false, This is an optional argument |
| params.plane | int | Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid - This is an optional argument |
| params.topMost | bool | Defines whether the Hdmi Input should be over or under the other video plane |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.AVInput.startInput",
    "params": {
        "portId": "HDMI0",
        "typeOfInput": "HDMI",
        "requestAudioMix": true,
        "plane": 0,
        "topMost": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.AVInput.startInput", "params": {"portId": "HDMI0", "typeOfInput": "HDMI", "requestAudioMix": true, "plane": 0, "topMost": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "success": true
    }
}
```

<a id="stopInput"></a>
## *stopInput*

Tears down the active rendering stream pipelines for the specified input type and frees the associated display plane resources.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.typeOfInput | string | The type of Input - HDMI/COMPOSITE |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.AVInput.stopInput",
    "params": {
        "typeOfInput": "HDMI"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.AVInput.stopInput", "params": {"typeOfInput": "HDMI"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "success": true
    }
}
```

<a id="writeEDID"></a>
## *writeEDID*

Updates the EDID data exposed by the specified HDMI input.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.message | string | A new EDID value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.AVInput.writeEDID",
    "params": {
        "portId": "HDMI0",
        "message": "00FFFFFFFFFFFF0010AC44A04C5A5530"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.AVInput.writeEDID", "params": {"portId": "HDMI0", "message": "00FFFFFFFFFFFF0010AC44A04C5A5530"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "success": true
    }
}
```

<a id="IAVInput-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IAVInput Interface:

| Event | Description |
| :-------- | :-------- |
| [aviContentTypeUpdate](#aviContentTypeUpdate) | Triggered whenever AV Infoframe content type changes for an HDMI Input |
| [gameFeatureStatusUpdate](#gameFeatureStatusUpdate) | Triggered whenever game feature(ALLM) status changes for an HDMI Input |
| [onDevicesChanged](#onDevicesChanged) | Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input |
| [onInputStatusChanged](#onInputStatusChanged) | Triggered whenever the status changes for an HDMI/Composite Input |
| [onSignalChanged](#onSignalChanged) | Triggered whenever the signal status changes for an HDMI/Composite Input |
| [videoStreamInfoUpdate](#videoStreamInfoUpdate) | Triggered whenever there is an update in HDMI/Composite Input video stream info |

<a id="aviContentTypeUpdate"></a>
## *aviContentTypeUpdate*

This notification is generated when the HDMI source reports a change in the AVI InfoFrame Content Type field for an active HDMI input port. The event provides the HDMI input port identifier and the newly detected content type. Applications may use this information to optimize display processing or adjust picture settings based on the reported content type.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | Hdmi Input port ID for which content type change event received and possible values are port id 0, 1 and 2 for three Hdmi Input ports |
| params.aviContentType | int | New Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.AVInput.aviContentTypeUpdate",
    "params": {
        "id": 0,
        "aviContentType": 3
    }
}
```

<a id="gameFeatureStatusUpdate"></a>
## *gameFeatureStatusUpdate*

This notification is generated when the status of a game feature (such as ALLM) changes for an active HDMI input port.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | The port identifier for the HDMI Input |
| params.gameFeature | string | Game Feature to which current status requested |
| params.mode | bool | The current game feature status. Mode is required only for ALLM. Need to add support for future game features |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.AVInput.gameFeatureStatusUpdate",
    "params": {
        "id": 0,
        "gameFeature": "ALLM",
        "mode": true
    }
}
```

<a id="onDevicesChanged"></a>
## *onDevicesChanged*

This method is called whenever there is a change in the connected input devices.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.devices | array | An iterator over the list of currently connected input devices |
| params.devices[#].id | int | id |
| params.devices[#].locator | string | locator |
| params.devices[#].connected | bool | connected |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.AVInput.onDevicesChanged",
    "params": [
        {
            "id": 0,
            "locator": "HDMI0",
            "connected": true
        },
        {
            "id": 1,
            "locator": "HDMI1",
            "connected": false
        }
    ]
}
```

<a id="onInputStatusChanged"></a>
## *onInputStatusChanged*

This notification is generated whenever the status of an HDMI/Composite Input changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | The port identifier for the HDMI/Composite Input |
| params.locator | string | A URL corresponding to the HDMI/Composite Input port |
| params.status | string | Status of the HDMI/Composite Input. Valid values are started or stopped |
| params.plane | int | Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.AVInput.onInputStatusChanged",
    "params": {
        "id": 0,
        "locator": "HDMI0",
        "status": "started",
        "plane": 0
    }
}
```

<a id="onSignalChanged"></a>
## *onSignalChanged*

This method is called whenever there is a change in the signal status for an HDMI/Composite Input.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | The port identifier for the HDMI/Composite Input |
| params.locator | string | A URL corresponding to the HDMI/Composite Input port |
| params.signalStatus | string | Signal Status of the HDMI/Composite Input. Valid values are noSignal, unstableSignal, notSupportedSignal, stableSignal |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.AVInput.onSignalChanged",
    "params": {
        "id": 0,
        "locator": "HDMI0",
        "signalStatus": "stableSignal"
    }
}
```

<a id="videoStreamInfoUpdate"></a>
## *videoStreamInfoUpdate*

This notification is generated whenever there is an update in the video stream information for an active HDMI/Composite Input port.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | The port identifier for the HDMI/Composite Input |
| params.locator | string | A URL corresponding to the HDMI/Composite Input port |
| params.width | int | Width of the Video Stream |
| params.height | int | Height of the Video Stream |
| params.progressive | bool | Whether the Video Stream is progressive or not |
| params.frameRateN | int | FrameRate Numerator |
| params.frameRateD | int | FrameRate Denominator |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.AVInput.videoStreamInfoUpdate",
    "params": {
        "id": 0,
        "locator": "HDMI0",
        "width": 1920,
        "height": 1080,
        "progressive": true,
        "frameRateN": 60000,
        "frameRateD": 1001
    }
}
```

