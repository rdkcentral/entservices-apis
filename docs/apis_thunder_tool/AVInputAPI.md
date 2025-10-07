<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_AVInput_API"></a>
# AVInput API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

AVInput interface for Thunder framework.

(Defined with IAVInput in [IAVInput.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAVInput.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the AVInput interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

AVInput JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the AVInput interface:

AVInput interface methods:

| Method | Description |
| :-------- | :-------- |
| [numberOfInputs](#method_numberOfInputs) | Returns an integer that specifies the number of available inputs |
| [writeEDID](#method_writeEDID) | Changes a current EDID value |
| [readEDID](#method_readEDID) | Returns the current EDID value |
| [getRawSPD](#method_getRawSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits |
| [getSPD](#method_getSPD) | Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device |
| [setEdidVersion](#method_setEdidVersion) | Sets an HDMI EDID version |
| [getEdidVersion](#method_getEdidVersion) | Returns the EDID version |
| [setEdid2AllmSupport](#method_setEdid2AllmSupport) | Sets an HDMI ALLM bit in EDID |
| [getEdid2AllmSupport](#method_getEdid2AllmSupport) | Returns the ALLM bit in EDID |
| [setVRRSupport](#method_setVRRSupport) | Sets an HDMI VRR support bit in EDID |
| [getVRRSupport](#method_getVRRSupport) | Returns the VRR support bit in EDID |
| [getHdmiVersion](#method_getHdmiVersion) | Gets the maximum hdmi compatibility version supported for the given port |
| [setMixerLevels](#method_setMixerLevels) | Sets the audio mixer level for given audio input |
| [startInput](#method_startInput) | Activates the specified HDMI/Composite Input port as the primary video source |
| [stopInput](#method_stopInput) | Deactivates the HDMI/Composite Input port currently selected as the primary video source |
| [setVideoRectangle](#method_setVideoRectangle) | Sets an HDMI/Composite Input video window |
| [currentVideoMode](#method_currentVideoMode) | Returns the current video mode for the specified input device |
| [contentProtected](#method_contentProtected) | Returns whether the content is protected for the specified input device |
| [getSupportedGameFeatures](#method_getSupportedGameFeatures) | Returns the list of supported game features |
| [getGameFeatureStatus](#method_getGameFeatureStatus) | Returns the Game Feature Status |
| [getVRRFrameRate](#method_getVRRFrameRate) | Returns the current VRR frame rate for the specified input device |

<a id="method_numberOfInputs"></a>
## *numberOfInputs [<sup>method</sup>](#head_Methods)*

Returns an integer that specifies the number of available inputs.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.numberOfInputs | integer | mandatory | - out - The number of inputs that are available for selection |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.numberOfInputs"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "numberOfInputs": 0,
    "success": false
  }
}
```

<a id="method_writeEDID"></a>
## *writeEDID [<sup>method</sup>](#head_Methods)*

Changes a current EDID value.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.message | string | mandatory | - in - A new EDID value |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.writeEDID",
  "params": {
    "portId": "...",
    "message": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_readEDID"></a>
## *readEDID [<sup>method</sup>](#head_Methods)*

Returns the current EDID value.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.EDID | string | mandatory | - out - The EDID Value |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.readEDID",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "EDID": "...",
    "success": false
  }
}
```

<a id="method_getRawSPD"></a>
## *getRawSPD [<sup>method</sup>](#head_Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device as raw bits.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.HDMISPD | string | mandatory | - out - The SPD information as raw bits |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getRawSPD",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "HDMISPD": "...",
    "success": false
  }
}
```

<a id="method_getSPD"></a>
## *getSPD [<sup>method</sup>](#head_Methods)*

Returns the Source Data Product Descriptor (SPD) infoFrame packet information for the specified HDMI Input device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.HDMISPD | string | mandatory | - out - The SPD information |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getSPD",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "HDMISPD": "...",
    "success": false
  }
}
```

<a id="method_setEdidVersion"></a>
## *setEdidVersion [<sup>method</sup>](#head_Methods)*

Sets an HDMI EDID version.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.edidVersion | string | mandatory | - in - The EDID version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEdidVersion",
  "params": {
    "portId": "...",
    "edidVersion": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getEdidVersion"></a>
## *getEdidVersion [<sup>method</sup>](#head_Methods)*

Returns the EDID version.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.edidVersion | string | mandatory | - out - The EDID version |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getEdidVersion",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "edidVersion": "...",
    "success": false
  }
}
```

<a id="method_setEdid2AllmSupport"></a>
## *setEdid2AllmSupport [<sup>method</sup>](#head_Methods)*

Sets an HDMI ALLM bit in EDID.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.allmSupport | boolean | mandatory | - in - The ALLM support in EDID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEdid2AllmSupport",
  "params": {
    "portId": "...",
    "allmSupport": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getEdid2AllmSupport"></a>
## *getEdid2AllmSupport [<sup>method</sup>](#head_Methods)*

Returns the ALLM bit in EDID.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - The ID of the input device to get the ALLM |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.allmSupport | boolean | mandatory | - out - The ALLM bit value in edid |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getEdid2AllmSupport",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "allmSupport": false,
    "success": false
  }
}
```

<a id="method_setVRRSupport"></a>
## *setVRRSupport [<sup>method</sup>](#head_Methods)*

Sets an HDMI VRR support bit in EDID.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory |  |
| params.vrrSupport | boolean | mandatory | - in - The VRR support bit value to set |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setVRRSupport",
  "params": {
    "portId": "...",
    "vrrSupport": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getVRRSupport"></a>
## *getVRRSupport [<sup>method</sup>](#head_Methods)*

Returns the VRR support bit in EDID.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.vrrSupport | boolean | mandatory | - out - The VRR support bit value |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVRRSupport",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "vrrSupport": false,
    "success": false
  }
}
```

<a id="method_getHdmiVersion"></a>
## *getHdmiVersion [<sup>method</sup>](#head_Methods)*

Gets the maximum hdmi compatibility version supported for the given port.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.HdmiCapabilityVersion | string | mandatory | - out - The Maximum Hdmi compatibility version supported by the given port |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getHdmiVersion",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "HdmiCapabilityVersion": "...",
    "success": false
  }
}
```

<a id="method_setMixerLevels"></a>
## *setMixerLevels [<sup>method</sup>](#head_Methods)*

Sets the audio mixer level for given audio input.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.primaryVolume | integer | mandatory | - in - Primary audio input volume |
| params.inputVolume | integer | mandatory | - in - System audio input volume |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setMixerLevels",
  "params": {
    "primaryVolume": 0,
    "inputVolume": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_startInput"></a>
## *startInput [<sup>method</sup>](#head_Methods)*

Activates the specified HDMI/Composite Input port as the primary video source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI/Composite Input port as returned by the getInputDevices method |
| params.typeOfInput | string | mandatory | - in - The type of Input - HDMI/COMPOSITE |
| params.requestAudioMix | boolean | mandatory | - in - Defines whether the Audio mixing is true or false, This is an optional argument |
| params.plane | integer | mandatory | - in - Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid - This is an optional argument |
| params.topMost | boolean | mandatory | - in - Defines whether the Hdmi Input should be over or under the other video plane |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.startInput",
  "params": {
    "portId": "...",
    "typeOfInput": "...",
    "requestAudioMix": false,
    "plane": 0,
    "topMost": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_stopInput"></a>
## *stopInput [<sup>method</sup>](#head_Methods)*

Deactivates the HDMI/Composite Input port currently selected as the primary video source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.typeOfInput | string | mandatory | - in - The type of Input - HDMI/COMPOSITE |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.stopInput",
  "params": {
    "typeOfInput": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setVideoRectangle"></a>
## *setVideoRectangle [<sup>method</sup>](#head_Methods)*

Sets an HDMI/Composite Input video window.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.x | integer | mandatory | - in - The x-coordinate of the video rectangle |
| params.y | integer | mandatory | - in - The y-coordinate of the video rectangle |
| params.w | integer | mandatory | - in - The width of the video rectangle |
| params.h | integer | mandatory | - in - The height of the video rectangle |
| params.typeOfInput | string | mandatory | - in - The type of Input - HDMI/COMPOSITE |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setVideoRectangle",
  "params": {
    "x": 0,
    "y": 0,
    "w": 0,
    "h": 0,
    "typeOfInput": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_currentVideoMode"></a>
## *currentVideoMode [<sup>method</sup>](#head_Methods)*

Returns the current video mode for the specified input device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.currentVideoMode | string | mandatory | - out - The current video mode |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.currentVideoMode"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "currentVideoMode": "...",
    "success": false
  }
}
```

<a id="method_contentProtected"></a>
## *contentProtected [<sup>method</sup>](#head_Methods)*

Returns whether the content is protected for the specified input device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.isContentProtected | boolean | mandatory | - out - Whether the HDMI input is protected |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.contentProtected"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "isContentProtected": false,
    "success": false
  }
}
```

<a id="method_getSupportedGameFeatures"></a>
## *getSupportedGameFeatures [<sup>method</sup>](#head_Methods)*

Returns the list of supported game features.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.supportedGameFeatures | array | mandatory | - out - The supported game Features |
| result.supportedGameFeatures[#] | string | mandatory |  |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getSupportedGameFeatures"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedGameFeatures": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_getGameFeatureStatus"></a>
## *getGameFeatureStatus [<sup>method</sup>](#head_Methods)*

Returns the Game Feature Status. For example: ALLM.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI Input port as returned by the getInputDevices method |
| params.gameFeature | string | mandatory | - in - Game Feature to which current status requested |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.mode | boolean | mandatory | - out - The current game feature status. Mode is required only for ALLM. Need to add support for future game features |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getGameFeatureStatus",
  "params": {
    "portId": "...",
    "gameFeature": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "mode": false,
    "success": false
  }
}
```

<a id="method_getVRRFrameRate"></a>
## *getVRRFrameRate [<sup>method</sup>](#head_Methods)*

Returns the current VRR frame rate for the specified input device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.portId | string | mandatory | - in - An ID of an HDMI Input port as returned by the getInputDevices method |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.currentVRRVideoFrameRate | number | mandatory | - out - The current VRR frame rate |
| result.success | boolean | mandatory | - out - Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVRRFrameRate",
  "params": {
    "portId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "currentVRRVideoFrameRate": 0.0,
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the AVInput interface:

AVInput interface events:

| Notification | Description |
| :-------- | :-------- |
| [videoStreamInfoUpdate](#notification_videoStreamInfoUpdate) | Triggered whenever there is an update in HDMI/Composite Input video stream info |
| [onInputStatusChanged](#notification_onInputStatusChanged) | Triggered whenever the status changes for an HDMI/Composite Input |
| [aviContentTypeUpdate](#notification_aviContentTypeUpdate) | Triggered whenever AV Infoframe content type changes for an HDMI Input |
| [onSignalChanged](#notification_onSignalChanged) | Triggered whenever the signal status changes for an HDMI/Composite Input |
| [gameFeatureStatusUpdate](#notification_gameFeatureStatusUpdate) | Triggered whenever game feature(ALLM) status changes for an HDMI Input |

<a id="notification_videoStreamInfoUpdate"></a>
## *videoStreamInfoUpdate [<sup>notification</sup>](#head_Notifications)*

Triggered whenever there is an update in HDMI/Composite Input video stream info.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | - in - The port identifier for the HDMI/Composite Input |
| params.locator | string | mandatory | - in - A URL corresponding to the HDMI/Composite Input port |
| params.width | integer | mandatory | - in - Width of the Video Stream |
| params.height | integer | mandatory | - in - Height of the Video Stream |
| params.progressive | boolean | mandatory | - in - Whether the Video Stream is progressive or not |
| params.frameRateN | integer | mandatory | - in - FrameRate Numerator |
| params.frameRateD | integer | mandatory | - in - FrameRate Denominator |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "videoStreamInfoUpdate",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.videoStreamInfoUpdate",
  "params": {
    "id": 0,
    "locator": "...",
    "width": 0,
    "height": 0,
    "progressive": false,
    "frameRateN": 0,
    "frameRateD": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.videoStreamInfoUpdate``.

<a id="notification_onInputStatusChanged"></a>
## *onInputStatusChanged [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the status changes for an HDMI/Composite Input.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | - in - The port identifier for the HDMI/Composite Input |
| params.locator | string | mandatory | - in - A URL corresponding to the HDMI/Composite Input port |
| params.status | string | mandatory | - in - Status of the HDMI/Composite Input. Valid values are started or stopped |
| params.plane | integer | mandatory | - in - Defines whether the video plane type, 0 - Primary video plane, 1 - Secondary Video Plane, Other values - Invalid |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onInputStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onInputStatusChanged",
  "params": {
    "id": 0,
    "locator": "...",
    "status": "...",
    "plane": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onInputStatusChanged``.

<a id="notification_aviContentTypeUpdate"></a>
## *aviContentTypeUpdate [<sup>notification</sup>](#head_Notifications)*

Triggered whenever AV Infoframe content type changes for an HDMI Input.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | - in - Hdmi Input port ID for which content type change event received and possible values are port id 0, 1 and 2 for three Hdmi Input ports |
| params.aviContentType | integer | mandatory | - in - new Content type received for the active hdmi input port and the possible integer values indicates following accordingly 0 - Graphics, 1 - Photo, 2 - Cinema, 3 - Game, 4 - Invalid data |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "aviContentTypeUpdate",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.aviContentTypeUpdate",
  "params": {
    "id": 0,
    "aviContentType": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.aviContentTypeUpdate``.

<a id="notification_onSignalChanged"></a>
## *onSignalChanged [<sup>notification</sup>](#head_Notifications)*

Triggered whenever the signal status changes for an HDMI/Composite Input.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | - in - The port identifier for the HDMI/Composite Input |
| params.locator | string | mandatory | - in - A URL corresponding to the HDMI/Composite Input port |
| params.signalStatus | string | mandatory | - in - Signal Status of the HDMI/Composite Input. Valid values are noSignal, unstableSignal, notSupportedSignal, stableSignal |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onSignalChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSignalChanged",
  "params": {
    "id": 0,
    "locator": "...",
    "signalStatus": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSignalChanged``.

<a id="notification_gameFeatureStatusUpdate"></a>
## *gameFeatureStatusUpdate [<sup>notification</sup>](#head_Notifications)*

Triggered whenever game feature(ALLM) status changes for an HDMI Input.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.id | integer | mandatory | - in - The port identifier for the HDMI Input |
| params.gameFeature | string | mandatory | - in - Game Feature to which current status requested |
| params.mode | boolean | mandatory | - in - The current game feature status. Mode is required only for ALLM. Need to add support for future game features |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "gameFeatureStatusUpdate",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.gameFeatureStatusUpdate",
  "params": {
    "id": 0,
    "gameFeature": "...",
    "mode": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.gameFeatureStatusUpdate``.

