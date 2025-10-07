<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_HdmiCecSink_API"></a>
# HdmiCecSink API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

HdmiCecSink interface for Thunder framework.

(Defined with IHdmiCecSink in [IHdmiCecSink.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IHdmiCecSink.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the HdmiCecSink interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

HdmiCecSink JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the HdmiCecSink interface:

HdmiCecSink interface methods:

| Method | Description |
| :-------- | :-------- |
| [getActiveRoute](#method_getActiveRoute) | Gets the Active Route(s) of the HDMI CEC Sink |
| [getActiveSource](#method_getActiveSource) | Gets the status of the current active source |
| [getAudioDeviceConnectedStatus](#method_getAudioDeviceConnectedStatus) | Gets audio device connected status |
| [getDeviceList](#method_getDeviceList) | Gets the list of devices connected to the HDMI CEC sink |
| [getEnabled](#method_getEnabled) | Gets the status of the HDMI CEC Sink |
| [getOSDName](#method_getOSDName) | Gets the OSD name of the HDMI CEC Sink |
| [getVendorId](#method_getVendorId) | Gets the vendor ID of the HDMI CEC Sink |
| [printDeviceList](#method_printDeviceList) | This is a helper debug command for developers |
| [requestActiveSource](#method_requestActiveSource) | Request the active source in the network |
| [requestShortAudioDescriptor](#method_requestShortAudioDescriptor) | Sends the CEC Request Short Audio Descriptor (SAD) message as an |
| [sendAudioDevicePowerOnMessage](#method_sendAudioDevicePowerOnMessage) | This message is used to power on the connected audio device |
| [sendGetAudioStatusMessage](#method_sendGetAudioStatusMessage) | Sends the CEC <Give Audio Status> message to request the audio status |
| [sendKeyPressEvent](#method_sendKeyPressEvent) | Sends the CEC <User Control Pressed> message when TV remote key is pressed |
| [sendUserControlPressed](#method_sendUserControlPressed) | Sends the CEC <User Control Pressed> message when TV remote key is pressed |
| [sendUserControlReleased](#method_sendUserControlReleased) | Sends the CEC <User Control Released> message when TV remote key is released |
| [sendStandbyMessage](#method_sendStandbyMessage) | Sends the CEC <Standby> message to another CEC device |
| [setActivePath](#method_setActivePath) | Sets the source device to active (setStreamPath) |
| [setActiveSource](#method_setActiveSource) | Sets the current active source as TV (physical address 0 |
| [setEnabled](#method_setEnabled) | Sets the status of the HDMI CEC Sink |
| [setMenuLanguage](#method_setMenuLanguage) | Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message |
| [setOSDName](#method_setOSDName) | Sets the OSD name of the HDMI CEC Sink |
| [setRoutingChange](#method_setRoutingChange) | Changes routing while switching between HDMI inputs and TV |
| [setupARCRouting](#method_setupARCRouting) | Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing |
| [setVendorId](#method_setVendorId) | Sets the vendor ID of the HDMI CEC Sink |
| [setLatencyInfo](#method_setLatencyInfo) | Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature |
| [requestAudioDevicePowerStatus](#method_requestAudioDevicePowerStatus) | Requests the audio device power status |

<a id="method_getActiveRoute"></a>
## *getActiveRoute [<sup>method</sup>](#head_Methods)*

Gets the Active Route(s) of the HDMI CEC Sink.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.available | boolean | mandatory | Is the active route available or not |
| result.length | integer | mandatory | Length of the active route |
| result.pathList | array | mandatory | List of active path |
| result.pathList[#] | object | mandatory |  |
| result.pathList[#].logicalAddress | integer | mandatory |  |
| result.pathList[#].physicalAddress | string | mandatory |  |
| result.pathList[#].deviceType | string | mandatory |  |
| result.pathList[#].vendorID | string | mandatory |  |
| result.pathList[#].osdName | string | mandatory |  |
| result.ActiveRoute | string | mandatory | Active route of the device |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getActiveRoute"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "available": false,
    "length": 0,
    "pathList": [
      {
        "logicalAddress": 0,
        "physicalAddress": "...",
        "deviceType": "...",
        "vendorID": "...",
        "osdName": "..."
      }
    ],
    "ActiveRoute": "...",
    "success": false
  }
}
```

<a id="method_getActiveSource"></a>
## *getActiveSource [<sup>method</sup>](#head_Methods)*

Gets the status of the current active source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.available | boolean | mandatory | Is the active source available or not |
| result.logicalAddress | integer | mandatory | Logical address of the active source |
| result.physicalAddress | string | mandatory | Physical address of the active source |
| result.deviceType | string | mandatory | Device type of the active source |
| result.cecVersion | string | mandatory | CEC version of the active source |
| result.osdName | string | mandatory | OSD name of the active source |
| result.vendorID | string | mandatory | Vendor ID of the active source |
| result.powerStatus | string | mandatory | Power status of the active source |
| result.port | string | mandatory |  |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getActiveSource"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "available": false,
    "logicalAddress": 0,
    "physicalAddress": "...",
    "deviceType": "...",
    "cecVersion": "...",
    "osdName": "...",
    "vendorID": "...",
    "powerStatus": "...",
    "port": "...",
    "success": false
  }
}
```

<a id="method_getAudioDeviceConnectedStatus"></a>
## *getAudioDeviceConnectedStatus [<sup>method</sup>](#head_Methods)*

Gets audio device connected status.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.connected | boolean | mandatory | Is the audio device connected or not |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getAudioDeviceConnectedStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "connected": false,
    "success": false
  }
}
```

<a id="method_getDeviceList"></a>
## *getDeviceList [<sup>method</sup>](#head_Methods)*

Gets the list of devices connected to the HDMI CEC sink.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.numberofdevices | integer | mandatory | Number of devices connected to the HDMI CEC sink |
| result.deviceList | array | mandatory | List of devices connected to the HDMI CEC sink |
| result.deviceList[#] | object | mandatory |  |
| result.deviceList[#].logicalAddress | integer | mandatory |  |
| result.deviceList[#].physicalAddress | string | mandatory |  |
| result.deviceList[#].deviceType | string | mandatory |  |
| result.deviceList[#].cecVersion | string | mandatory |  |
| result.deviceList[#].osdName | string | mandatory |  |
| result.deviceList[#].vendorID | string | mandatory |  |
| result.deviceList[#].powerStatus | string | mandatory |  |
| result.deviceList[#].portNumber | string | mandatory |  |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getDeviceList"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "numberofdevices": 0,
    "deviceList": [
      {
        "logicalAddress": 0,
        "physicalAddress": "...",
        "deviceType": "...",
        "cecVersion": "...",
        "osdName": "...",
        "vendorID": "...",
        "powerStatus": "...",
        "portNumber": "..."
      }
    ],
    "success": false
  }
}
```

<a id="method_getEnabled"></a>
## *getEnabled [<sup>method</sup>](#head_Methods)*

Gets the status of the HDMI CEC Sink.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.enabled | boolean | mandatory | Is the HDMI CEC Sink enabled or not |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getEnabled"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "enabled": false,
    "success": false
  }
}
```

<a id="method_getOSDName"></a>
## *getOSDName [<sup>method</sup>](#head_Methods)*

Gets the OSD name of the HDMI CEC Sink.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.name | string | mandatory | OSD name of the HDMI CEC Sink |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getOSDName"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "name": "...",
    "success": false
  }
}
```

<a id="method_getVendorId"></a>
## *getVendorId [<sup>method</sup>](#head_Methods)*

Gets the vendor ID of the HDMI CEC Sink.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.vendorid | string | mandatory | Vendor ID of the HDMI CEC Sink |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVendorId"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "vendorid": "...",
    "success": false
  }
}
```

<a id="method_printDeviceList"></a>
## *printDeviceList [<sup>method</sup>](#head_Methods)*

This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.printed | boolean | mandatory | Is the device list printed or not |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.printDeviceList"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "printed": false,
    "success": false
  }
}
```

<a id="method_requestActiveSource"></a>
## *requestActiveSource [<sup>method</sup>](#head_Methods)*

Request the active source in the network.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.requestActiveSource"
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

<a id="method_requestShortAudioDescriptor"></a>
## *requestShortAudioDescriptor [<sup>method</sup>](#head_Methods)*

Sends the CEC Request Short Audio Descriptor (SAD) message as an.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.requestShortAudioDescriptor"
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

<a id="method_sendAudioDevicePowerOnMessage"></a>
## *sendAudioDevicePowerOnMessage [<sup>method</sup>](#head_Methods)*

This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendAudioDevicePowerOnMessage"
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

<a id="method_sendGetAudioStatusMessage"></a>
## *sendGetAudioStatusMessage [<sup>method</sup>](#head_Methods)*

Sends the CEC <Give Audio Status> message to request the audio status.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendGetAudioStatusMessage"
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

<a id="method_sendKeyPressEvent"></a>
## *sendKeyPressEvent [<sup>method</sup>](#head_Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |
| params.keyCode | integer | mandatory | Key code of the key press event |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendKeyPressEvent",
  "params": {
    "logicalAddress": 0,
    "keyCode": 0
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

<a id="method_sendUserControlPressed"></a>
## *sendUserControlPressed [<sup>method</sup>](#head_Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |
| params.keyCode | integer | mandatory | Key code of the key press event |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendUserControlPressed",
  "params": {
    "logicalAddress": 0,
    "keyCode": 0
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

<a id="method_sendUserControlReleased"></a>
## *sendUserControlReleased [<sup>method</sup>](#head_Methods)*

Sends the CEC <User Control Released> message when TV remote key is released.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendUserControlReleased",
  "params": {
    "logicalAddress": 0
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

<a id="method_sendStandbyMessage"></a>
## *sendStandbyMessage [<sup>method</sup>](#head_Methods)*

Sends the CEC <Standby> message to another CEC device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.sendStandbyMessage"
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

<a id="method_setActivePath"></a>
## *setActivePath [<sup>method</sup>](#head_Methods)*

Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.activePath | string | mandatory | Active path of the device |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setActivePath",
  "params": {
    "activePath": "..."
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

<a id="method_setActiveSource"></a>
## *setActiveSource [<sup>method</sup>](#head_Methods)*

Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setActiveSource"
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

<a id="method_setEnabled"></a>
## *setEnabled [<sup>method</sup>](#head_Methods)*

Sets the status of the HDMI CEC Sink.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the HDMI CEC Sink enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setEnabled",
  "params": {
    "enabled": false
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

<a id="method_setMenuLanguage"></a>
## *setMenuLanguage [<sup>method</sup>](#head_Methods)*

Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.language | string | mandatory | Menu language to be set |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setMenuLanguage",
  "params": {
    "language": "..."
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

<a id="method_setOSDName"></a>
## *setOSDName [<sup>method</sup>](#head_Methods)*

Sets the OSD name of the HDMI CEC Sink.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.name | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setOSDName",
  "params": {
    "name": "..."
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

<a id="method_setRoutingChange"></a>
## *setRoutingChange [<sup>method</sup>](#head_Methods)*

Changes routing while switching between HDMI inputs and TV.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.oldPort | string | mandatory | Old port number |
| params.newPort | string | mandatory | New port number |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setRoutingChange",
  "params": {
    "oldPort": "...",
    "newPort": "..."
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

<a id="method_setupARCRouting"></a>
## *setupARCRouting [<sup>method</sup>](#head_Methods)*

Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the HDMI-CEC ARC routing enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setupARCRouting",
  "params": {
    "enabled": false
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

<a id="method_setVendorId"></a>
## *setVendorId [<sup>method</sup>](#head_Methods)*

Sets the vendor ID of the HDMI CEC Sink.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.vendorid | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setVendorId",
  "params": {
    "vendorid": "..."
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

<a id="method_setLatencyInfo"></a>
## *setLatencyInfo [<sup>method</sup>](#head_Methods)*

Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.videoLatency | string | mandatory | Video Latency value |
| params.lowLatencyMode | string | mandatory | Low Latency Mode value |
| params.audioOutputCompensated | string | mandatory | Audio Output Compensated value |
| params.audioOutputDelay | string | mandatory | Audio Output Delay value |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setLatencyInfo",
  "params": {
    "videoLatency": "...",
    "lowLatencyMode": "...",
    "audioOutputCompensated": "...",
    "audioOutputDelay": "..."
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

<a id="method_requestAudioDevicePowerStatus"></a>
## *requestAudioDevicePowerStatus [<sup>method</sup>](#head_Methods)*

Requests the audio device power status.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.requestAudioDevicePowerStatus"
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HdmiCecSink interface:

HdmiCecSink interface events:

| Notification | Description |
| :-------- | :-------- |
| [arcInitiationEvent](#notification_arcInitiationEvent) | Triggered when routing though the HDMI ARC port is successfully established |
| [arcTerminationEvent](#notification_arcTerminationEvent) | Triggered when routing though the HDMI ARC port terminates |
| [onActiveSourceChange](#notification_onActiveSourceChange) | Triggered when the active source device changes |
| [onDeviceAdded](#notification_onDeviceAdded) | Triggered when a new device is added to the CEC network |
| [onDeviceInfoUpdated](#notification_onDeviceInfoUpdated) | Triggered when device information changes |
| [onDeviceRemoved](#notification_onDeviceRemoved) | Triggered when a device is removed from the CEC network |
| [onImageViewOnMsg](#notification_onImageViewOnMsg) | Triggered when an <Image View ON> CEC message is received from the source device |
| [onInActiveSource](#notification_onInActiveSource) | Triggered when the source is no longer active |
| [onTextViewOnMsg](#notification_onTextViewOnMsg) | Triggered when a <Text View ON> CEC message is received from the source device |
| [onWakeupFromStandby](#notification_onWakeupFromStandby) | Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device |
| [reportAudioDeviceConnectedStatus](#notification_reportAudioDeviceConnectedStatus) | Triggered when an audio device is added or removed |
| [reportAudioStatusEvent](#notification_reportAudioStatusEvent) | Triggered when CEC <Report Audio Status> message of device is received |
| [reportFeatureAbortEvent](#notification_reportFeatureAbortEvent) | Triggered when CEC <Feature Abort> message of device is received |
| [reportCecEnabledEvent](#notification_reportCecEnabledEvent) | Triggered when the HDMI-CEC is enabled |
| [setSystemAudioModeEvent](#notification_setSystemAudioModeEvent) | Triggered when CEC <Set System Audio Mode> message of device is received |
| [shortAudiodescriptorEvent](#notification_shortAudiodescriptorEvent) | Triggered when SAD is received from the connected audio device |
| [standbyMessageReceived](#notification_standbyMessageReceived) | Triggered when the source device changes status to STANDBY |
| [reportAudioDevicePowerStatus](#notification_reportAudioDevicePowerStatus) | Triggered when the source device changes |

<a id="notification_arcInitiationEvent"></a>
## *arcInitiationEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when routing though the HDMI ARC port is successfully established.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | string | mandatory | Is the operation successful or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "arcInitiationEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.arcInitiationEvent",
  "params": {
    "status": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.arcInitiationEvent``.

<a id="notification_arcTerminationEvent"></a>
## *arcTerminationEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when routing though the HDMI ARC port terminates.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | string | mandatory | Is the operation successful or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "arcTerminationEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.arcTerminationEvent",
  "params": {
    "status": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.arcTerminationEvent``.

<a id="notification_onActiveSourceChange"></a>
## *onActiveSourceChange [<sup>notification</sup>](#head_Notifications)*

Triggered when the active source device changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the active source |
| params.physicalAddress | string | mandatory | Physical address of the active source |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onActiveSourceChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onActiveSourceChange",
  "params": {
    "logicalAddress": 0,
    "physicalAddress": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onActiveSourceChange``.

<a id="notification_onDeviceAdded"></a>
## *onDeviceAdded [<sup>notification</sup>](#head_Notifications)*

Triggered when a new device is added to the CEC network.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the added device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDeviceAdded",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDeviceAdded",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDeviceAdded``.

<a id="notification_onDeviceInfoUpdated"></a>
## *onDeviceInfoUpdated [<sup>notification</sup>](#head_Notifications)*

Triggered when device information changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDeviceInfoUpdated",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDeviceInfoUpdated",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDeviceInfoUpdated``.

<a id="notification_onDeviceRemoved"></a>
## *onDeviceRemoved [<sup>notification</sup>](#head_Notifications)*

Triggered when a device is removed from the CEC network.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the removed device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDeviceRemoved",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDeviceRemoved",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDeviceRemoved``.

<a id="notification_onImageViewOnMsg"></a>
## *onImageViewOnMsg [<sup>notification</sup>](#head_Notifications)*

Triggered when an <Image View ON> CEC message is received from the source device.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onImageViewOnMsg",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onImageViewOnMsg",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onImageViewOnMsg``.

<a id="notification_onInActiveSource"></a>
## *onInActiveSource [<sup>notification</sup>](#head_Notifications)*

Triggered when the source is no longer active.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the source |
| params.physicalAddress | string | mandatory | Physical address of the source |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onInActiveSource",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onInActiveSource",
  "params": {
    "logicalAddress": 0,
    "physicalAddress": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onInActiveSource``.

<a id="notification_onTextViewOnMsg"></a>
## *onTextViewOnMsg [<sup>notification</sup>](#head_Notifications)*

Triggered when a <Text View ON> CEC message is received from the source device.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onTextViewOnMsg",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTextViewOnMsg",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTextViewOnMsg``.

<a id="notification_onWakeupFromStandby"></a>
## *onWakeupFromStandby [<sup>notification</sup>](#head_Notifications)*

Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onWakeupFromStandby",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onWakeupFromStandby",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onWakeupFromStandby``.

<a id="notification_reportAudioDeviceConnectedStatus"></a>
## *reportAudioDeviceConnectedStatus [<sup>notification</sup>](#head_Notifications)*

Triggered when an audio device is added or removed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | string | mandatory | Status of the audio device |
| params.audioDeviceConnected | string | mandatory | Audio device connected or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "reportAudioDeviceConnectedStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.reportAudioDeviceConnectedStatus",
  "params": {
    "status": "...",
    "audioDeviceConnected": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.reportAudioDeviceConnectedStatus``.

<a id="notification_reportAudioStatusEvent"></a>
## *reportAudioStatusEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when CEC <Report Audio Status> message of device is received.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.muteStatus | integer | mandatory | Mute status of the device |
| params.volumeLevel | integer | mandatory | Volume level of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "reportAudioStatusEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.reportAudioStatusEvent",
  "params": {
    "muteStatus": 0,
    "volumeLevel": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.reportAudioStatusEvent``.

<a id="notification_reportFeatureAbortEvent"></a>
## *reportFeatureAbortEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when CEC <Feature Abort> message of device is received.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |
| params.opcode | integer | mandatory | Opcode of the message |
| params.FeatureAbortReason | integer | mandatory | Reason for the feature abort |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "reportFeatureAbortEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.reportFeatureAbortEvent",
  "params": {
    "logicalAddress": 0,
    "opcode": 0,
    "FeatureAbortReason": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.reportFeatureAbortEvent``.

<a id="notification_reportCecEnabledEvent"></a>
## *reportCecEnabledEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when the HDMI-CEC is enabled.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.cecEnable | string | mandatory | HDMI-CEC enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "reportCecEnabledEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.reportCecEnabledEvent",
  "params": {
    "cecEnable": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.reportCecEnabledEvent``.

<a id="notification_setSystemAudioModeEvent"></a>
## *setSystemAudioModeEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when CEC <Set System Audio Mode> message of device is received.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.audioMode | string | mandatory | Audio mode of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "setSystemAudioModeEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.setSystemAudioModeEvent",
  "params": {
    "audioMode": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.setSystemAudioModeEvent``.

<a id="notification_shortAudiodescriptorEvent"></a>
## *shortAudiodescriptorEvent [<sup>notification</sup>](#head_Notifications)*

Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.jsonresponse | string | mandatory | JSON response containing the Short Audio Descriptor (SAD) information |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "shortAudiodescriptorEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.shortAudiodescriptorEvent",
  "params": {
    "jsonresponse": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.shortAudiodescriptorEvent``.

<a id="notification_standbyMessageReceived"></a>
## *standbyMessageReceived [<sup>notification</sup>](#head_Notifications)*

Triggered when the source device changes status to STANDBY.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "standbyMessageReceived",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.standbyMessageReceived",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.standbyMessageReceived``.

<a id="notification_reportAudioDevicePowerStatus"></a>
## *reportAudioDevicePowerStatus [<sup>notification</sup>](#head_Notifications)*

Triggered when the source device changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.powerStatus | integer | mandatory | Power status of the device |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "reportAudioDevicePowerStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.reportAudioDevicePowerStatus",
  "params": {
    "powerStatus": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.reportAudioDevicePowerStatus``.

