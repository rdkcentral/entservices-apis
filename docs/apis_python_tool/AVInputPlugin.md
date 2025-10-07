<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.AVInput_Plugin"></a>
# AVInput Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/AVInput/CHANGELOG.md)**

A AVInput plugin for Thunder framework.

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

The `AVInput` plugin provides an interface for AVInput.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AVInput) |
| classname | string | Class name: *AVInput* |
| locator | string | Library name: *libWPEFrameworkAVInput.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the AVInput plugin:

AVInput interface methods:

| Method | Description |
| :-------- | :-------- |
| [aviContentTypeUpdate](#method.aviContentTypeUpdate) | Triggered whenever AV Infoframe content type changes for an HDMI Input |
| [contentProtected](#method.contentProtected) | Returns whether the content is protected for the specified input device |
| [currentVideoMode](#method.currentVideoMode) | Returns the current video mode for the specified input device |
| [gameFeatureStatusUpdate](#method.gameFeatureStatusUpdate) | Triggered whenever game feature(ALLM) status changes for an HDMI Input |
| [getEdid2AllmSupport](#method.getEdid2AllmSupport) | Returns the ALLM bit in EDID |
| [getEdidVersion](#method.getEdidVersion) | Returns the EDID version |
| [getGameFeatureStatus](#method.getGameFeatureStatus) | Returns the Game Feature Status. For example: ALLM. |
| [getHdmiVersion](#method.getHdmiVersion) | Gets the maximum hdmi compatibility version supported for the given port. |
| [getRawSPD](#method.getRawSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits |
| [getSPD](#method.getSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device |
| [getSupportedGameFeatures](#method.getSupportedGameFeatures) | Returns the list of supported game features. |
| [getVRRFrameRate](#method.getVRRFrameRate) | Returns the current VRR frame rate for the specified input device |
| [getVRRSupport](#method.getVRRSupport) | Returns the VRR support bit in EDID |
| [numberOfInputs](#method.numberOfInputs) | Returns an integer that specifies the number of available inputs |
| [onDevicesChanged](#method.onDevicesChanged) | Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input |
| [onInputStatusChanged](#method.onInputStatusChanged) | Triggered whenever the status changes for an HDMI/Composite Input |
| [onSignalChanged](#method.onSignalChanged) | Triggered whenever the signal status changes for an HDMI/Composite Input |
| [readEDID](#method.readEDID) | Returns the current EDID value. |
| [registerAviContentTypeUpdateNotification](#method.registerAviContentTypeUpdateNotification) |  |
| [registerGameFeatureStatusUpdateNotification](#method.registerGameFeatureStatusUpdateNotification) |  |
| [registerInputStatusChangedNotification](#method.registerInputStatusChangedNotification) |  |
| [registerSignalChangedNotification](#method.registerSignalChangedNotification) |  |
| [registerVideoStreamInfoUpdateNotification](#method.registerVideoStreamInfoUpdateNotification) |  |
| [setEdid2AllmSupport](#method.setEdid2AllmSupport) | Sets an HDMI ALLM bit in EDID. |
| [setEdidVersion](#method.setEdidVersion) | Sets an HDMI EDID version |
| [setMixerLevels](#method.setMixerLevels) | Sets the audio mixer level for given audio input. |
| [setVRRSupport](#method.setVRRSupport) | Sets an HDMI VRR support bit in EDID |
| [setVideoRectangle](#method.setVideoRectangle) | Sets an HDMI/Composite Input video window. |
| [startInput](#method.startInput) | Activates the specified HDMI/Composite Input port as the primary video source. |
| [stopInput](#method.stopInput) | Deactivates the HDMI/Composite Input port currently selected as the primary video source. |
| [unregisterAviContentTypeUpdateNotification](#method.unregisterAviContentTypeUpdateNotification) |  |
| [unregisterGameFeatureStatusUpdateNotification](#method.unregisterGameFeatureStatusUpdateNotification) |  |
| [unregisterInputStatusChangedNotification](#method.unregisterInputStatusChangedNotification) |  |
| [unregisterSignalChangedNotification](#method.unregisterSignalChangedNotification) |  |
| [unregisterVideoStreamInfoUpdateNotification](#method.unregisterVideoStreamInfoUpdateNotification) |  |
| [videoStreamInfoUpdate](#method.videoStreamInfoUpdate) | Triggered whenever there is an update in HDMI/Composite Input video stream info |
| [writeEDID](#method.writeEDID) | Changes a current EDID value. |

<a id="method.aviContentTypeUpdate"></a>
## *aviContentTypeUpdate [<sup>method</sup>](#head.Methods)*

Triggered whenever AV Infoframe content type changes for an HDMI Input

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.aviContentType | int | new Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.AVInput.aviContentTypeUpdate",
    "params": {
        "id": 0,
        "aviContentType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AVInput.aviContentTypeUpdate", "params": {"id": 0, "aviContentType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.contentProtected"></a>
## *contentProtected [<sup>method</sup>](#head.Methods)*

Returns whether the content is protected for the specified input device

### Events
Event details are missing in the header file documentation.
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
    "id": 1,
    "method": "org.rdk.AVInput.contentProtected"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AVInput.contentProtected"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "isContentProtected": true,
        "success": true
    }
}
```

<a id="method.currentVideoMode"></a>
## *currentVideoMode [<sup>method</sup>](#head.Methods)*

Returns the current video mode for the specified input device

### Events
Event details are missing in the header file documentation.
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
    "id": 2,
    "method": "org.rdk.AVInput.currentVideoMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AVInput.currentVideoMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "currentVideoMode": "",
        "success": true
    }
}
```

<a id="method.gameFeatureStatusUpdate"></a>
## *gameFeatureStatusUpdate [<sup>method</sup>](#head.Methods)*

Triggered whenever game feature(ALLM) status changes for an HDMI Input

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.gameFeature | string | Game Feature to which current status requested |
| params.mode | bool | The current game feature status. Mode is required only for ALLM. Need to add support for future game features |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.AVInput.gameFeatureStatusUpdate",
    "params": {
        "id": 0,
        "gameFeature": "",
        "mode": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AVInput.gameFeatureStatusUpdate", "params": {"id": 0, "gameFeature": "", "mode": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="method.getEdid2AllmSupport"></a>
## *getEdid2AllmSupport [<sup>method</sup>](#head.Methods)*

Returns the ALLM bit in EDID

### Events
Event details are missing in the header file documentation.
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
    "id": 4,
    "method": "org.rdk.AVInput.getEdid2AllmSupport",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AVInput.getEdid2AllmSupport", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "allmSupport": true,
        "success": true
    }
}
```

<a id="method.getEdidVersion"></a>
## *getEdidVersion [<sup>method</sup>](#head.Methods)*

Returns the EDID version

### Events
Event details are missing in the header file documentation.
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
    "id": 5,
    "method": "org.rdk.AVInput.getEdidVersion",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.AVInput.getEdidVersion", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "edidVersion": "",
        "success": true
    }
}
```

<a id="method.getGameFeatureStatus"></a>
## *getGameFeatureStatus [<sup>method</sup>](#head.Methods)*

Returns the Game Feature Status. For example: ALLM.

### Events
Event details are missing in the header file documentation.
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
    "id": 6,
    "method": "org.rdk.AVInput.getGameFeatureStatus",
    "params": {
        "portId": "",
        "gameFeature": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.AVInput.getGameFeatureStatus", "params": {"portId": "", "gameFeature": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "mode": true,
        "success": true
    }
}
```

<a id="method.getHdmiVersion"></a>
## *getHdmiVersion [<sup>method</sup>](#head.Methods)*

Gets the maximum hdmi compatibility version supported for the given port.

### Events
Event details are missing in the header file documentation.
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
    "id": 7,
    "method": "org.rdk.AVInput.getHdmiVersion",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.AVInput.getHdmiVersion", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "HdmiCapabilityVersion": "",
        "success": true
    }
}
```

<a id="method.getRawSPD"></a>
## *getRawSPD [<sup>method</sup>](#head.Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits

### Events
Event details are missing in the header file documentation.
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
    "id": 8,
    "method": "org.rdk.AVInput.getRawSPD",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.AVInput.getRawSPD", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "HDMISPD": "",
        "success": true
    }
}
```

<a id="method.getSPD"></a>
## *getSPD [<sup>method</sup>](#head.Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device

### Events
Event details are missing in the header file documentation.
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
    "id": 9,
    "method": "org.rdk.AVInput.getSPD",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.AVInput.getSPD", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "HDMISPD": "",
        "success": true
    }
}
```

<a id="method.getSupportedGameFeatures"></a>
## *getSupportedGameFeatures [<sup>method</sup>](#head.Methods)*

Returns the list of supported game features.

### Events
Event details are missing in the header file documentation.
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
    "id": 10,
    "method": "org.rdk.AVInput.getSupportedGameFeatures"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.AVInput.getSupportedGameFeatures"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "supportedGameFeatures": "",
        "success": true
    }
}
```

<a id="method.getVRRFrameRate"></a>
## *getVRRFrameRate [<sup>method</sup>](#head.Methods)*

Returns the current VRR frame rate for the specified input device

### Events
Event details are missing in the header file documentation.
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
    "id": 11,
    "method": "org.rdk.AVInput.getVRRFrameRate",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.AVInput.getVRRFrameRate", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "currentVRRVideoFrameRate": 0.0,
        "success": true
    }
}
```

<a id="method.getVRRSupport"></a>
## *getVRRSupport [<sup>method</sup>](#head.Methods)*

Returns the VRR support bit in EDID

### Events
Event details are missing in the header file documentation.
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
    "id": 12,
    "method": "org.rdk.AVInput.getVRRSupport",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.AVInput.getVRRSupport", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "vrrSupport": true,
        "success": true
    }
}
```

<a id="method.numberOfInputs"></a>
## *numberOfInputs [<sup>method</sup>](#head.Methods)*

Returns an integer that specifies the number of available inputs

### Events
Event details are missing in the header file documentation.
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
    "id": 13,
    "method": "org.rdk.AVInput.numberOfInputs"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.AVInput.numberOfInputs"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "numberOfInputs": 0,
        "success": true
    }
}
```

<a id="method.onDevicesChanged"></a>
## *onDevicesChanged [<sup>method</sup>](#head.Methods)*

Triggered whenever a new HDMI/Composite device is connected to an HDMI/Composite Input

### Events
Event details are missing in the header file documentation.
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
    "id": 14,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.AVInput.onDevicesChanged", "params": [{"id": 0, "locator": "", "connected": true}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.onInputStatusChanged"></a>
## *onInputStatusChanged [<sup>method</sup>](#head.Methods)*

Triggered whenever the status changes for an HDMI/Composite Input

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.locator | string | locator |
| params.status | string | Status of the HDMI/Composite Input. Valid values are started or stopped |
| params.plane | int | Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid |
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
    "method": "org.rdk.AVInput.onInputStatusChanged",
    "params": {
        "id": 0,
        "locator": "",
        "status": "",
        "plane": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.AVInput.onInputStatusChanged", "params": {"id": 0, "locator": "", "status": "", "plane": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="method.onSignalChanged"></a>
## *onSignalChanged [<sup>method</sup>](#head.Methods)*

Triggered whenever the signal status changes for an HDMI/Composite Input

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | int | id |
| params.locator | string | locator |
| params.signalStatus | string | Signal Status of the HDMI/Composite Input. Valid values are noSignal, unstableSignal, notSupportedSignal, stableSignal |
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
    "method": "org.rdk.AVInput.onSignalChanged",
    "params": {
        "id": 0,
        "locator": "",
        "signalStatus": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.AVInput.onSignalChanged", "params": {"id": 0, "locator": "", "signalStatus": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="method.readEDID"></a>
## *readEDID [<sup>method</sup>](#head.Methods)*

Returns the current EDID value.

### Events
Event details are missing in the header file documentation.
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
    "id": 17,
    "method": "org.rdk.AVInput.readEDID",
    "params": {
        "portId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.AVInput.readEDID", "params": {"portId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "EDID": "",
        "success": true
    }
}
```

<a id="method.registerAviContentTypeUpdateNotification"></a>
## *registerAviContentTypeUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 18,
    "method": "org.rdk.AVInput.registerAviContentTypeUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.AVInput.registerAviContentTypeUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="method.registerGameFeatureStatusUpdateNotification"></a>
## *registerGameFeatureStatusUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 19,
    "method": "org.rdk.AVInput.registerGameFeatureStatusUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.AVInput.registerGameFeatureStatusUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="method.registerInputStatusChangedNotification"></a>
## *registerInputStatusChangedNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 20,
    "method": "org.rdk.AVInput.registerInputStatusChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.AVInput.registerInputStatusChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="method.registerSignalChangedNotification"></a>
## *registerSignalChangedNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 21,
    "method": "org.rdk.AVInput.registerSignalChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.AVInput.registerSignalChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="method.registerVideoStreamInfoUpdateNotification"></a>
## *registerVideoStreamInfoUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 22,
    "method": "org.rdk.AVInput.registerVideoStreamInfoUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.AVInput.registerVideoStreamInfoUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="method.setEdid2AllmSupport"></a>
## *setEdid2AllmSupport [<sup>method</sup>](#head.Methods)*

Sets an HDMI ALLM bit in EDID.

### Events
Event details are missing in the header file documentation.
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
    "id": 23,
    "method": "org.rdk.AVInput.setEdid2AllmSupport",
    "params": {
        "portId": "",
        "allmSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.AVInput.setEdid2AllmSupport", "params": {"portId": "", "allmSupport": true}}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.setEdidVersion"></a>
## *setEdidVersion [<sup>method</sup>](#head.Methods)*

Sets an HDMI EDID version

### Events
Event details are missing in the header file documentation.
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
    "id": 24,
    "method": "org.rdk.AVInput.setEdidVersion",
    "params": {
        "portId": "",
        "edidVersion": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.AVInput.setEdidVersion", "params": {"portId": "", "edidVersion": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.setMixerLevels"></a>
## *setMixerLevels [<sup>method</sup>](#head.Methods)*

Sets the audio mixer level for given audio input.

### Events
Event details are missing in the header file documentation.
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
    "id": 25,
    "method": "org.rdk.AVInput.setMixerLevels",
    "params": {
        "primaryVolume": 0,
        "inputVolume": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.AVInput.setMixerLevels", "params": {"primaryVolume": 0, "inputVolume": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.setVRRSupport"></a>
## *setVRRSupport [<sup>method</sup>](#head.Methods)*

Sets an HDMI VRR support bit in EDID

### Events
Event details are missing in the header file documentation.
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
    "id": 26,
    "method": "org.rdk.AVInput.setVRRSupport",
    "params": {
        "portId": "",
        "vrrSupport": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.AVInput.setVRRSupport", "params": {"portId": "", "vrrSupport": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "success": true
    }
}
```

<a id="method.setVideoRectangle"></a>
## *setVideoRectangle [<sup>method</sup>](#head.Methods)*

Sets an HDMI/Composite Input video window.

### Events
Event details are missing in the header file documentation.
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
    "id": 27,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.AVInput.setVideoRectangle", "params": {"x": 0, "y": 0, "w": 0, "h": 0, "typeOfInput": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": {
        "success": true
    }
}
```

<a id="method.startInput"></a>
## *startInput [<sup>method</sup>](#head.Methods)*

Activates the specified HDMI/Composite Input port as the primary video source.

### Events
Event details are missing in the header file documentation.
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
    "id": 28,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.AVInput.startInput", "params": {"portId": "", "typeOfInput": "", "requestAudioMix": true, "plane": 0, "topMost": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": {
        "success": true
    }
}
```

<a id="method.stopInput"></a>
## *stopInput [<sup>method</sup>](#head.Methods)*

Deactivates the HDMI/Composite Input port currently selected as the primary video source.

### Events
Event details are missing in the header file documentation.
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
    "id": 29,
    "method": "org.rdk.AVInput.stopInput",
    "params": {
        "typeOfInput": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.AVInput.stopInput", "params": {"typeOfInput": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": {
        "success": true
    }
}
```

<a id="method.unregisterAviContentTypeUpdateNotification"></a>
## *unregisterAviContentTypeUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 30,
    "method": "org.rdk.AVInput.unregisterAviContentTypeUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.AVInput.unregisterAviContentTypeUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="method.unregisterGameFeatureStatusUpdateNotification"></a>
## *unregisterGameFeatureStatusUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 31,
    "method": "org.rdk.AVInput.unregisterGameFeatureStatusUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.AVInput.unregisterGameFeatureStatusUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```

<a id="method.unregisterInputStatusChangedNotification"></a>
## *unregisterInputStatusChangedNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 32,
    "method": "org.rdk.AVInput.unregisterInputStatusChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.AVInput.unregisterInputStatusChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="method.unregisterSignalChangedNotification"></a>
## *unregisterSignalChangedNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 33,
    "method": "org.rdk.AVInput.unregisterSignalChangedNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.AVInput.unregisterSignalChangedNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```

<a id="method.unregisterVideoStreamInfoUpdateNotification"></a>
## *unregisterVideoStreamInfoUpdateNotification [<sup>method</sup>](#head.Methods)*



### Events
Event details are missing in the header file documentation.
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
    "id": 34,
    "method": "org.rdk.AVInput.unregisterVideoStreamInfoUpdateNotification",
    "params": {
        "notification": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.AVInput.unregisterVideoStreamInfoUpdateNotification", "params": {"notification": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```

<a id="method.videoStreamInfoUpdate"></a>
## *videoStreamInfoUpdate [<sup>method</sup>](#head.Methods)*

Triggered whenever there is an update in HDMI/Composite Input video stream info

### Events
Event details are missing in the header file documentation.
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
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.AVInput.videoStreamInfoUpdate", "params": {"id": 0, "locator": "", "width": 0, "height": 0, "progressive": true, "frameRateN": 0, "frameRateD": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```

<a id="method.writeEDID"></a>
## *writeEDID [<sup>method</sup>](#head.Methods)*

Changes a current EDID value.

### Events
Event details are missing in the header file documentation.
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
    "id": 36,
    "method": "org.rdk.AVInput.writeEDID",
    "params": {
        "portId": "",
        "message": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.AVInput.writeEDID", "params": {"portId": "", "message": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": {
        "success": true
    }
}
```


