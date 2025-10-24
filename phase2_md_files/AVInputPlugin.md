<!-- Generated automatically, DO NOT EDIT! -->
<a id="AVInput_Plugin"></a>
# AVInput Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AVInput)**

A AVInput plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AVInput` plugin provides an interface for AVInput.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AVInput) |
| classname | string | Class name: *AVInput* |
| locator | string | Library name: *libWPEFrameworkAVInput.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the AVInput plugin:

AVInput interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [contentProtected](#contentProtected) | Returns whether the content is protected for the specified input device | NA |
| [currentVideoMode](#currentVideoMode) | Returns the current video mode for the specified input device | NA |
| [getEdid2AllmSupport](#getEdid2AllmSupport) | Returns the ALLM bit in EDID | NA |
| [getEdidVersion](#getEdidVersion) | Returns the EDID version | NA |
| [getGameFeatureStatus](#getGameFeatureStatus) | Returns the Game Feature Status. For example: ALLM. | NA |
| [getHdmiVersion](#getHdmiVersion) | Gets the maximum hdmi compatibility version supported for the given port. | NA |
| [getRawSPD](#getRawSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits | NA |
| [getSPD](#getSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device | NA |
| [getSupportedGameFeatures](#getSupportedGameFeatures) | Returns the list of supported game features. | NA |
| [getVRRFrameRate](#getVRRFrameRate) | Returns the current VRR frame rate for the specified input device | NA |
| [getVRRSupport](#getVRRSupport) | Returns the VRR support bit in EDID | NA |
| [numberOfInputs](#numberOfInputs) | Returns an integer that specifies the number of available inputs | NA |
| [onDevicesChanged](#onDevicesChanged) | Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input | NA |
| [readEDID](#readEDID) | Returns the current EDID value. | NA |
| [registerAviContentTypeUpdateNotification](#registerAviContentTypeUpdateNotification) |  | NA |
| [registerGameFeatureStatusUpdateNotification](#registerGameFeatureStatusUpdateNotification) |  | NA |
| [registerInputStatusChangedNotification](#registerInputStatusChangedNotification) |  | NA |
| [registerSignalChangedNotification](#registerSignalChangedNotification) |  | NA |
| [registerVideoStreamInfoUpdateNotification](#registerVideoStreamInfoUpdateNotification) |  | NA |
| [setEdid2AllmSupport](#setEdid2AllmSupport) | Sets an HDMI ALLM bit in EDID. | NA |
| [setEdidVersion](#setEdidVersion) | Sets an HDMI EDID version | NA |
| [setMixerLevels](#setMixerLevels) | Sets the audio mixer level for given audio input. | NA |
| [setVRRSupport](#setVRRSupport) | Sets an HDMI VRR support bit in EDID | NA |
| [setVideoRectangle](#setVideoRectangle) | Sets an HDMI/Composite Input video window. | NA |
| [startInput](#startInput) | Activates the specified HDMI/Composite Input port as the primary video source. | onInputStatusChanged, onSignalChanged |
| [stopInput](#stopInput) | Deactivates the HDMI/Composite Input port currently selected as the primary video source. | onInputStatusChanged |
| [unregisterAviContentTypeUpdateNotification](#unregisterAviContentTypeUpdateNotification) |  | NA |
| [unregisterGameFeatureStatusUpdateNotification](#unregisterGameFeatureStatusUpdateNotification) |  | NA |
| [unregisterInputStatusChangedNotification](#unregisterInputStatusChangedNotification) |  | NA |
| [unregisterSignalChangedNotification](#unregisterSignalChangedNotification) |  | NA |
| [unregisterVideoStreamInfoUpdateNotification](#unregisterVideoStreamInfoUpdateNotification) |  | NA |
| [writeEDID](#writeEDID) | Changes a current EDID value. | NA |

<a id="contentProtected"></a>
## *contentProtected [<sup>method</sup>](#Methods)*

Returns whether the content is protected for the specified input device

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.isContentProtected | bool | Whether the HDMI input is protected |
| result.success | bool | success |

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
## *currentVideoMode [<sup>method</sup>](#Methods)*

Returns the current video mode for the specified input device

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentVideoMode | string | The current video mode |
| result.success | bool | success |

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
        "currentVideoMode": "",
        "success": true
    }
}
```

<a id="getEdid2AllmSupport"></a>
## *getEdid2AllmSupport [<sup>method</sup>](#Methods)*

Returns the ALLM bit in EDID

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.allmSupport | bool | The ALLM support in EDID |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.AVInput.getEdid2AllmSupport",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AVInput.getEdid2AllmSupport", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "allmSupport": true,
        "success": true
    }
}
```

<a id="getEdidVersion"></a>
## *getEdidVersion [<sup>method</sup>](#Methods)*

Returns the EDID version

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AVInput.getEdidVersion",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AVInput.getEdidVersion", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "edidVersion": "",
        "success": true
    }
}
```

<a id="getGameFeatureStatus"></a>
## *getGameFeatureStatus [<sup>method</sup>](#Methods)*

Returns the Game Feature Status. For example: ALLM.

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.gameFeature | string | Game Feature to which current status requested |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mode | bool | The current game feature status. Mode is required only for ALLM. Need to add support for future game features |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.AVInput.getGameFeatureStatus",
    "params": {
        "portId": "",
        "gameFeature": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AVInput.getGameFeatureStatus", "params": {"portId": "", "gameFeature": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "mode": true,
        "success": true
    }
}
```

<a id="getHdmiVersion"></a>
## *getHdmiVersion [<sup>method</sup>](#Methods)*

Gets the maximum hdmi compatibility version supported for the given port.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.AVInput.getHdmiVersion",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.AVInput.getHdmiVersion", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "HdmiCapabilityVersion": "",
        "success": true
    }
}
```

<a id="getRawSPD"></a>
## *getRawSPD [<sup>method</sup>](#Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.AVInput.getRawSPD",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.AVInput.getRawSPD", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "HDMISPD": "",
        "success": true
    }
}
```

<a id="getSPD"></a>
## *getSPD [<sup>method</sup>](#Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.AVInput.getSPD",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AVInput.getSPD", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "HDMISPD": "",
        "success": true
    }
}
```

<a id="getSupportedGameFeatures"></a>
## *getSupportedGameFeatures [<sup>method</sup>](#Methods)*

Returns the list of supported game features.

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedGameFeatures | WPEFramework::Exchange::IAVInput::IStringIterator | The supported game Features |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.AVInput.getSupportedGameFeatures"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AVInput.getSupportedGameFeatures"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "supportedGameFeatures": "",
        "success": true
    }
}
```

<a id="getVRRFrameRate"></a>
## *getVRRFrameRate [<sup>method</sup>](#Methods)*

Returns the current VRR frame rate for the specified input device

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentVRRVideoFrameRate | double | The current VRR frame rate |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.AVInput.getVRRFrameRate",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AVInput.getVRRFrameRate", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "currentVRRVideoFrameRate": 0.0,
        "success": true
    }
}
```

<a id="getVRRSupport"></a>
## *getVRRSupport [<sup>method</sup>](#Methods)*

Returns the VRR support bit in EDID

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.vrrSupport | bool | The VRR support bit value to set |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.AVInput.getVRRSupport",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AVInput.getVRRSupport", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "vrrSupport": true,
        "success": true
    }
}
```

<a id="numberOfInputs"></a>
## *numberOfInputs [<sup>method</sup>](#Methods)*

Returns an integer that specifies the number of available inputs

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberOfInputs | integer | The number of inputs that are available for selection |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.AVInput.numberOfInputs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AVInput.numberOfInputs"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "numberOfInputs": 0,
        "success": true
    }
}
```

<a id="onDevicesChanged"></a>
## *onDevicesChanged [<sup>method</sup>](#Methods)*

Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.devices | IInputDeviceIterator |  |
| params.devices[#].id | int | id |
| params.devices[#].locator | string | locator |
| params.devices[#].connected | bool | connected |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.AVInput.onDevicesChanged",
    "params": [
        {
            "id": 0,
            "locator": "",
            "connected": true
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AVInput.onDevicesChanged", "params": [{"id": 0, "locator": "", "connected": true}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="readEDID"></a>
## *readEDID [<sup>method</sup>](#Methods)*

Returns the current EDID value.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.AVInput.readEDID",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AVInput.readEDID", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "EDID": "",
        "success": true
    }
}
```

<a id="registerAviContentTypeUpdateNotification"></a>
## *registerAviContentTypeUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IAviContentTypeUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.AVInput.registerAviContentTypeUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.AVInput.registerAviContentTypeUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="registerGameFeatureStatusUpdateNotification"></a>
## *registerGameFeatureStatusUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IGameFeatureStatusUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.AVInput.registerGameFeatureStatusUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.AVInput.registerGameFeatureStatusUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="registerInputStatusChangedNotification"></a>
## *registerInputStatusChangedNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IInputStatusChangedNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.AVInput.registerInputStatusChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.AVInput.registerInputStatusChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="registerSignalChangedNotification"></a>
## *registerSignalChangedNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | ISignalChangedNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.AVInput.registerSignalChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.AVInput.registerSignalChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="registerVideoStreamInfoUpdateNotification"></a>
## *registerVideoStreamInfoUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IVideoStreamInfoUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.AVInput.registerVideoStreamInfoUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.AVInput.registerVideoStreamInfoUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="setEdid2AllmSupport"></a>
## *setEdid2AllmSupport [<sup>method</sup>](#Methods)*

Sets an HDMI ALLM bit in EDID.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.AVInput.setEdid2AllmSupport",
    "params": {
        "portId": "",
        "allmSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.AVInput.setEdid2AllmSupport", "params": {"portId": "", "allmSupport": true}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setEdidVersion"></a>
## *setEdidVersion [<sup>method</sup>](#Methods)*

Sets an HDMI EDID version

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.AVInput.setEdidVersion",
    "params": {
        "portId": "",
        "edidVersion": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.AVInput.setEdidVersion", "params": {"portId": "", "edidVersion": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setMixerLevels"></a>
## *setMixerLevels [<sup>method</sup>](#Methods)*

Sets the audio mixer level for given audio input.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.AVInput.setMixerLevels",
    "params": {
        "primaryVolume": 0,
        "inputVolume": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.AVInput.setMixerLevels", "params": {"primaryVolume": 0, "inputVolume": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setVRRSupport"></a>
## *setVRRSupport [<sup>method</sup>](#Methods)*

Sets an HDMI VRR support bit in EDID

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.vrrSupport | bool | The VRR support bit value to set |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.AVInput.setVRRSupport",
    "params": {
        "portId": "",
        "vrrSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.AVInput.setVRRSupport", "params": {"portId": "", "vrrSupport": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "success": true
    }
}
```

<a id="setVideoRectangle"></a>
## *setVideoRectangle [<sup>method</sup>](#Methods)*

Sets an HDMI/Composite Input video window.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.AVInput.setVideoRectangle",
    "params": {
        "x": 0,
        "y": 0,
        "w": 0,
        "h": 0,
        "typeOfInput": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.AVInput.setVideoRectangle", "params": {"x": 0, "y": 0, "w": 0, "h": 0, "typeOfInput": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "success": true
    }
}
```

<a id="startInput"></a>
## *startInput [<sup>method</sup>](#Methods)*

Activates the specified HDMI/Composite Input port as the primary video source.

### Events
| Event | Description |
| :-------- | :-------- |
| [onInputStatusChanged ](#onInputStatusChanged ) |  Triggers the event when HDMI/Composite Input source is activated and Input status changes to `started` |
| [onSignalChanged ](#onSignalChanged ) |  Triggers the event when HDMI/Composite Input signal changes (must be one of the following:noSignal, unstableSignal, notSupportedSignal, stableSignal) |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.portId | string | An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.typeOfInput | string | The type of Input - HDMI/COMPOSITE |
| params.requestAudioMix | bool | Defines whether the Audio mixing is true or false, This is an optional argument |
| params.plane | int | Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid |
| params.topMost | bool | Defines whether the Hdmi Input should be over or under the other video plane |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.AVInput.startInput",
    "params": {
        "portId": "",
        "typeOfInput": "",
        "requestAudioMix": true,
        "plane": 0,
        "topMost": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.AVInput.startInput", "params": {"portId": "", "typeOfInput": "", "requestAudioMix": true, "plane": 0, "topMost": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "success": true
    }
}
```

<a id="stopInput"></a>
## *stopInput [<sup>method</sup>](#Methods)*

Deactivates the HDMI/Composite Input port currently selected as the primary video source.

### Events
| Event | Description |
| :-------- | :-------- |
| [onInputStatusChanged ](#onInputStatusChanged ) |  Triggers the event when HDMI/Composite Input source is deactivated and Input status changes to `stopped` |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.typeOfInput | string | The type of Input - HDMI/COMPOSITE |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.AVInput.stopInput",
    "params": {
        "typeOfInput": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.AVInput.stopInput", "params": {"typeOfInput": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "success": true
    }
}
```

<a id="unregisterAviContentTypeUpdateNotification"></a>
## *unregisterAviContentTypeUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IAviContentTypeUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.AVInput.unregisterAviContentTypeUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.AVInput.unregisterAviContentTypeUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="unregisterGameFeatureStatusUpdateNotification"></a>
## *unregisterGameFeatureStatusUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IGameFeatureStatusUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.AVInput.unregisterGameFeatureStatusUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.AVInput.unregisterGameFeatureStatusUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="unregisterInputStatusChangedNotification"></a>
## *unregisterInputStatusChangedNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IInputStatusChangedNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.AVInput.unregisterInputStatusChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.AVInput.unregisterInputStatusChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="unregisterSignalChangedNotification"></a>
## *unregisterSignalChangedNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | ISignalChangedNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.AVInput.unregisterSignalChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.AVInput.unregisterSignalChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="unregisterVideoStreamInfoUpdateNotification"></a>
## *unregisterVideoStreamInfoUpdateNotification [<sup>method</sup>](#Methods)*



### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.notification | IVideoStreamInfoUpdateNotification |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.AVInput.unregisterVideoStreamInfoUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.AVInput.unregisterVideoStreamInfoUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="writeEDID"></a>
## *writeEDID [<sup>method</sup>](#Methods)*

Changes a current EDID value.

### Events
No Events are associated with this method.
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
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.AVInput.writeEDID",
    "params": {
        "portId": "",
        "message": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.AVInput.writeEDID", "params": {"portId": "", "message": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the AVInput plugin:

AVInput interface events:

| Event | Description |
| :-------- | :-------- |
| [aviContentTypeUpdate](#aviContentTypeUpdate) | Triggered whenever AV Infoframe content type changes for an HDMI Input |
| [gameFeatureStatusUpdate](#gameFeatureStatusUpdate) | Triggered whenever game feature(ALLM) status changes for an HDMI Input |
| [onInputStatusChanged](#onInputStatusChanged) | Triggered whenever the status changes for an HDMI/Composite Input |
| [onSignalChanged](#onSignalChanged) | Triggered whenever the signal status changes for an HDMI/Composite Input |
| [videoStreamInfoUpdate](#videoStreamInfoUpdate) | Triggered whenever there is an update in HDMI/Composite Input video stream info |

<a id="aviContentTypeUpdate"></a>
## *aviContentTypeUpdate [<sup>event</sup>](#Notifications)*

Triggered whenever AV Infoframe content type changes for an HDMI Input

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.aviContentType | int | new Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.AVInput.aviContentTypeUpdate",
    "params": {
        "id": 0,
        "aviContentType": 0
    }
}
```

<a id="gameFeatureStatusUpdate"></a>
## *gameFeatureStatusUpdate [<sup>event</sup>](#Notifications)*

Triggered whenever game feature(ALLM) status changes for an HDMI Input

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.gameFeature | string | Game Feature to which current status requested |
| params.mode | bool | The current game feature status. Mode is required only for ALLM. Need to add support for future game features |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.AVInput.gameFeatureStatusUpdate",
    "params": {
        "id": 0,
        "gameFeature": "",
        "mode": true
    }
}
```

<a id="onInputStatusChanged"></a>
## *onInputStatusChanged [<sup>event</sup>](#Notifications)*

Triggered whenever the status changes for an HDMI/Composite Input

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.locator | string | locator |
| params.status | string | Status of the HDMI/Composite Input. Valid values are started or stopped |
| params.plane | int | Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.AVInput.onInputStatusChanged",
    "params": {
        "id": 0,
        "locator": "",
        "status": "",
        "plane": 0
    }
}
```

<a id="onSignalChanged"></a>
## *onSignalChanged [<sup>event</sup>](#Notifications)*

Triggered whenever the signal status changes for an HDMI/Composite Input

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.locator | string | locator |
| params.signalStatus | string | Signal Status of the HDMI/Composite Input. Valid values are noSignal, unstableSignal, notSupportedSignal, stableSignal |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.AVInput.onSignalChanged",
    "params": {
        "id": 0,
        "locator": "",
        "signalStatus": ""
    }
}
```

<a id="videoStreamInfoUpdate"></a>
## *videoStreamInfoUpdate [<sup>event</sup>](#Notifications)*

Triggered whenever there is an update in HDMI/Composite Input video stream info

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.locator | string | locator |
| params.width | int | Width of the Video Stream |
| params.height | int | Height of the Video Stream |
| params.progressive | bool | Whether the Video Stream is progressive or not |
| params.frameRateN | int | FrameRate Numerator |
| params.frameRateD | int | FrameRate Denominator |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.AVInput.videoStreamInfoUpdate",
    "params": {
        "id": 0,
        "locator": "",
        "width": 0,
        "height": 0,
        "progressive": true,
        "frameRateN": 0,
        "frameRateD": 0
    }
}
```
