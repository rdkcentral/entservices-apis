<!-- Generated automatically, DO NOT EDIT! -->
<a id="HdmiCecSink_Module"></a>
# HdmiCecSink Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HdmiCecSink/IHdmiCecSink.h)**

A HdmiCecSink module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IHdmiCecSink](#IHdmiCecSink)
    - [Methods](#IHdmiCecSink-Methods)
    - [Notifications](#IHdmiCecSink-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `HdmiCecSink` module provides the following interface(s):

- IHdmiCecSink

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdmiCecSink) |
| classname | string | Class name: *HdmiCecSink* |
| locator | string | Library name: *libWPEFrameworkHdmiCecSink.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IHdmiCecSink"></a>
## IHdmiCecSink Interface

<a id="IHdmiCecSink-Methods"></a>
### Methods

The following methods are provided by the IHdmiCecSink Interface:

| Method | Description |
| :-------- | :-------- |
| [getActiveRoute](#getActiveRoute) | Gets the Active Route(s) of the HDMI CEC Sink |
| [getActiveSource](#getActiveSource) | Gets the status of the current active source |
| [getAudioDeviceConnectedStatus](#getAudioDeviceConnectedStatus) | Gets audio device connected status |
| [getDeviceList](#getDeviceList) | Gets the list of devices connected to the HDMI CEC sink |
| [getEnabled](#getEnabled) | Gets the status of the HDMI CEC Sink |
| [getOSDName](#getOSDName) | Gets the OSD name of the HDMI CEC Sink |
| [getVendorId](#getVendorId) | Gets the vendor ID of the HDMI CEC Sink |
| [printDeviceList](#printDeviceList) | This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices |
| [requestActiveSource](#requestActiveSource) | Request the active source in the network |
| [requestAudioDevicePowerStatus](#requestAudioDevicePowerStatus) | Requests the audio device power status. |
| [requestShortAudioDescriptor](#requestShortAudioDescriptor) | Sends the CEC Request Short Audio Descriptor (SAD) message as an inquiry to the audio device. |
| [sendAudioDevicePowerOnMessage](#sendAudioDevicePowerOnMessage) | This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network. |
| [sendGetAudioStatusMessage](#sendGetAudioStatusMessage) | Sends the CEC <Give Audio Status> message to request the audio status. |
| [sendKeyPressEvent](#sendKeyPressEvent) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. |
| [sendStandbyMessage](#sendStandbyMessage) | Sends the CEC <Standby> message to another CEC device |
| [sendUserControlPressed](#sendUserControlPressed) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. |
| [sendUserControlReleased](#sendUserControlReleased) | Sends the CEC <User Control Released> message when TV remote key is released. |
| [setActivePath](#setActivePath) | Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state. |
| [setActiveSource](#setActiveSource) | Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps. |
| [setEnabled](#setEnabled) | Sets the status of the HDMI CEC Sink |
| [setLatencyInfo](#setLatencyInfo) | Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature. |
| [setMenuLanguage](#setMenuLanguage) | Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message. |
| [setOSDName](#setOSDName) | Sets the OSD name of the HDMI CEC Sink |
| [setRoutingChange](#setRoutingChange) | Changes routing while switching between HDMI inputs and TV. |
| [setVendorId](#setVendorId) | Sets the vendor ID of the HDMI CEC Sink |
| [setupARCRouting](#setupARCRouting) | Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent. |

<a id="getActiveRoute"></a>
## *getActiveRoute*

Provides the routing path from the active source device through any intermediate CEC devices to the HDMI CEC sink.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.available | bool | Is the active route available or not |
| result.length | integer | Length of the active route |
| result.pathList | array | List of active path |
| result.pathList[#].logicalAddress | integer |  |
| result.pathList[#].physicalAddress | string |  |
| result.pathList[#].deviceType | string |  |
| result.pathList[#].vendorID | string |  |
| result.pathList[#].osdName | string |  |
| result.ActiveRoute | string | Active route of the device |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.HdmiCecSink.getActiveRoute"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.HdmiCecSink.getActiveRoute"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "available": true,
        "length": 2,
        "pathList": [
            "[{logicalAddress: 4, physicalAddress: \"1.0.0.0\"}]"
        ],
        "ActiveRoute": "1.0.0.0",
        "success": true
    }
}
```

<a id="getActiveSource"></a>
## *getActiveSource*

Provides detailed information about the current active source device in the HDMI-CEC network, including its address, type, and power state.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.available | bool | Is the active source available or not |
| result.logicalAddress | integer | Logical address of the active source |
| result.physicalAddress | string | Physical address of the active source |
| result.deviceType | string | Device type of the active source |
| result.cecVersion | string | CEC version of the active source |
| result.osdName | string | OSD name of the active source |
| result.vendorID | string | Vendor ID of the active source |
| result.powerStatus | string | Power status of the active source |
| result.port | string | Port number of the active source |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.HdmiCecSink.getActiveSource"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.HdmiCecSink.getActiveSource"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "available": true,
        "logicalAddress": 4,
        "physicalAddress": "1.0.0.0",
        "deviceType": "Playback Device",
        "cecVersion": 1.4,
        "osdName": "STB",
        "vendorID": "0x0000",
        "powerStatus": "On",
        "port": "HDMI0",
        "success": true
    }
}
```

<a id="getAudioDeviceConnectedStatus"></a>
## *getAudioDeviceConnectedStatus*

Gets the connected status of the audio device

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.connected | bool | Is the audio device connected or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.HdmiCecSink.getAudioDeviceConnectedStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.HdmiCecSink.getAudioDeviceConnectedStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "connected": true,
        "success": true
    }
}
```

<a id="getDeviceList"></a>
## *getDeviceList*

Provides detailed information about all devices currently connected to the HDMI CEC sink.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberofdevices | integer | Number of devices connected to the HDMI CEC sink |
| result.deviceList | array | List of devices connected to the HDMI CEC sink |
| result.deviceList[#].logicalAddress | integer |  |
| result.deviceList[#].physicalAddress | string |  |
| result.deviceList[#].deviceType | string |  |
| result.deviceList[#].cecVersion | string |  |
| result.deviceList[#].osdName | string |  |
| result.deviceList[#].vendorID | string |  |
| result.deviceList[#].powerStatus | string |  |
| result.deviceList[#].portNumber | string |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.HdmiCecSink.getDeviceList"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.HdmiCecSink.getDeviceList"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "numberofdevices": 2,
        "deviceList": [
            "[{logicalAddress: 4, physicalAddress: \"1.0.0.0\", deviceType: \"Playback Device\", cecVersion: \"1.4\", osdName: \"STB\", vendorID: \"0x0000\", powerStatus: \"On\", port: \"HDMI0\"}]"
        ],
        "success": true
    }
}
```

<a id="getEnabled"></a>
## *getEnabled*

Provides the current enabled status of the HDMI CEC Sink.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Is the HDMI CEC Sink enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.HdmiCecSink.getEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.HdmiCecSink.getEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "enabled": true,
        "success": true
    }
}
```

<a id="getOSDName"></a>
## *getOSDName*

Provides the current OSD name of the HDMI CEC Sink.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.name | string | OSD name of the HDMI CEC Sink |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.HdmiCecSink.getOSDName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.HdmiCecSink.getOSDName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "name": "My TV",
        "success": true
    }
}
```

<a id="getVendorId"></a>
## *getVendorId*

Provides the current vendor ID of the HDMI CEC Sink.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.vendorid | string | Vendor ID of the HDMI CEC Sink |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.HdmiCecSink.getVendorId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.HdmiCecSink.getVendorId"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "vendorid": "0x0000",
        "success": true
    }
}
```

<a id="printDeviceList"></a>
## *printDeviceList*

This is a helper debug command for developers. It provides a detailed printout of the list of connected devices and their properties.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.printed | bool | Is the device list printed or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.HdmiCecSink.printDeviceList"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.HdmiCecSink.printDeviceList"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "printed": true,
        "success": true
    }
}
```

<a id="requestActiveSource"></a>
## *requestActiveSource*

Requests the current active source in the HDMI CEC network.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.HdmiCecSink.requestActiveSource"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.HdmiCecSink.requestActiveSource"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": "{ success: true }"
}
```

<a id="requestAudioDevicePowerStatus"></a>
## *requestAudioDevicePowerStatus*

Sends a request to retrieve the current power status of the connected audio device.The response is expected to provide information about whether the audio device is powered on, powered off, or in a standby state.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.HdmiCecSink.requestAudioDevicePowerStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.HdmiCecSink.requestAudioDevicePowerStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": "{ success: true }"
}
```

<a id="requestShortAudioDescriptor"></a>
## *requestShortAudioDescriptor*

Sends the CEC Request Short Audio Descriptor (SAD) message as an inquiry to the audio device to obtain its supported audio formats.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.HdmiCecSink.requestShortAudioDescriptor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.HdmiCecSink.requestShortAudioDescriptor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": "{ success: true }"
}
```

<a id="sendAudioDevicePowerOnMessage"></a>
## *sendAudioDevicePowerOnMessage*

Sends a CEC <Image View On>/<Text View On> message to power on the connected audio device, typically triggered when the TV exits standby and detects an audio device on the network.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.HdmiCecSink.sendAudioDevicePowerOnMessage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.HdmiCecSink.sendAudioDevicePowerOnMessage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": "{ success: true }"
}
```

<a id="sendGetAudioStatusMessage"></a>
## *sendGetAudioStatusMessage*

Sends a <Give Audio Status> HDMI-CEC message to the connected audio device to query its current mute status and volume level. The response is delivered via the reportAudioStatusEvent notification.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.HdmiCecSink.sendGetAudioStatusMessage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.HdmiCecSink.sendGetAudioStatusMessage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": "{ success: true }"
}
```

<a id="sendKeyPressEvent"></a>
## *sendKeyPressEvent*

Notifies the connected CEC device of a remote key press event by sending a <User Control Pressed> HDMI-CEC message identifying the pressed key.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the device |
| params.keyCode | integer | Key code of the key press event |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.HdmiCecSink.sendKeyPressEvent",
    "params": {
        "logicalAddress": 4,
        "keyCode": "0x44"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.HdmiCecSink.sendKeyPressEvent", "params": {"logicalAddress": 4, "keyCode": "0x44"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": "{ success: true }"
}
```

<a id="sendStandbyMessage"></a>
## *sendStandbyMessage*

Broadcasts a <Standby> HDMI-CEC command to the connected CEC network, requesting other CEC-enabled devices to enter standby mode.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.HdmiCecSink.sendStandbyMessage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.HdmiCecSink.sendStandbyMessage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": "{ success: true }"
}
```

<a id="sendUserControlPressed"></a>
## *sendUserControlPressed*

Notifies the connected CEC device of a remote key press by sending a <User Control Pressed> HDMI-CEC message identifying the pressed key.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the device |
| params.keyCode | integer | Key code of the key press event |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.HdmiCecSink.sendUserControlPressed",
    "params": {
        "logicalAddress": 4,
        "keyCode": "0x44"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.HdmiCecSink.sendUserControlPressed", "params": {"logicalAddress": 4, "keyCode": "0x44"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": "{ success: true }"
}
```

<a id="sendUserControlReleased"></a>
## *sendUserControlReleased*

Notifies the connected CEC device that a previously pressed remote key has been released, by sending a <User Control Released> HDMI-CEC message.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.HdmiCecSink.sendUserControlReleased",
    "params": {
        "logicalAddress": 4
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.HdmiCecSink.sendUserControlReleased", "params": {"logicalAddress": 4}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": "{ success: true }"
}
```

<a id="setActivePath"></a>
## *setActivePath*

Sends a <Set Stream Path> command to make the specified source device the active source. If the target source device is in standby mode, it is requested to wake up and become the active source for audio/video playback.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.activePath | string | Active path of the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.HdmiCecSink.setActivePath",
    "params": {
        "activePath": "1.0.0.0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.HdmiCecSink.setActivePath", "params": {"activePath": "1.0.0.0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": "{ success: true }"
}
```

<a id="setActiveSource"></a>
## *setActiveSource*

Marks the TV as the active source with the physical address `0.0.0.0`. This method should be invoked when the TV switches to an internal source, such as the built-in tuner or an application, ensuring that connected HDMI-CEC devices are notified of the active source change.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.HdmiCecSink.setActiveSource"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.HdmiCecSink.setActiveSource"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": "{ success: true }"
}
```

<a id="setEnabled"></a>
## *setEnabled*

Updates the operational status of the HDMI CEC sink. When enabled, the sink can participate in HDMI-CEC communication and respond to CEC commands. When disabled, HDMI-CEC functionality for the sink is turned off.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the HDMI CEC Sink enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.HdmiCecSink.setEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.HdmiCecSink.setEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": "{ success: true }"
}
```

<a id="setLatencyInfo"></a>
## *setLatencyInfo*

Sends a <Report Current Latency> message containing the current latency values used by the Dynamic Auto LipSync feature. The reported information includes video latency, latency flags, audio output compensated value, and audio output delay.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.videoLatency | string | Video Latency value |
| params.lowLatencyMode | string | Low Latency Mode value |
| params.audioOutputCompensated | string | Audio Output Compensated value |
| params.audioOutputDelay | string | Audio Output Delay value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.HdmiCecSink.setLatencyInfo",
    "params": {
        "videoLatency": "",
        "lowLatencyMode": "",
        "audioOutputCompensated": "",
        "audioOutputDelay": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.HdmiCecSink.setLatencyInfo", "params": {"videoLatency": "", "lowLatencyMode": "", "audioOutputCompensated": "", "audioOutputDelay": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": "{ success: true }"
}
```

<a id="setMenuLanguage"></a>
## *setMenuLanguage*

Updates the internal data structure with the specified menu language and broadcasts a <Set Menu Language> HDMI-CEC message to notify connected HDMI-CEC devices of the language change.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | Menu language to be set |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.HdmiCecSink.setMenuLanguage",
    "params": {
        "language": "eng"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.HdmiCecSink.setMenuLanguage", "params": {"language": "eng"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": "{ success: true }"
}
```

<a id="setOSDName"></a>
## *setOSDName*

Configures the OSD name of the connected HDMI CEC sink. The OSD name is used to identify the device and may be displayed by other HDMI CEC devices during device discovery and source selection.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | OSD name of the HDMI CEC Sink |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.HdmiCecSink.setOSDName",
    "params": {
        "name": "My TV"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.HdmiCecSink.setOSDName", "params": {"name": "My TV"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": "{ success: true }"
}
```

<a id="setRoutingChange"></a>
## *setRoutingChange*

This method is used to notify the HDMI CEC Sink about a routing change between HDMI inputs and the TV.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.oldPort | string | Old port number |
| params.newPort | string | New port number |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.HdmiCecSink.setRoutingChange",
    "params": {
        "oldPort": "HDMI1",
        "newPort": "HDMI2"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.HdmiCecSink.setRoutingChange", "params": {"oldPort": "HDMI1", "newPort": "HDMI2"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": "{ success: true }"
}
```

<a id="setVendorId"></a>
## *setVendorId*

Configures the Vendor ID of the connected HDMI CEC sink. The Vendor ID is used to identify the manufacturer of the HDMI CEC device during CEC communication.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.vendorid | string | Vendor ID of the HDMI CEC Sink |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.HdmiCecSink.setVendorId",
    "params": {
        "vendorid": "0x0000"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.HdmiCecSink.setVendorId", "params": {"vendorid": "0x0000"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": "{ success: true }"
}
```

<a id="setupARCRouting"></a>
## *setupARCRouting*

Configures HDMI-CEC Audio Return Channel (ARC) routing between connected devices. When ARC routing is enabled, an `arcInitiationEvent` is triggered. When ARC routing is disabled, an `arcTerminationEvent` is triggered.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the HDMI-CEC ARC routing enabled or |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.HdmiCecSink.setupARCRouting",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.HdmiCecSink.setupARCRouting", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": "{ success: true }"
}
```

<a id="IHdmiCecSink-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IHdmiCecSink Interface:

| Event | Description |
| :-------- | :-------- |
| [arcInitiationEvent](#arcInitiationEvent) | Triggered when routing though the HDMI ARC port is successfully established. |
| [arcTerminationEvent](#arcTerminationEvent) | Triggered when routing though the HDMI ARC port terminates. |
| [onActiveSourceChange](#onActiveSourceChange) | Triggered when the active source device changes. |
| [onDeviceAdded](#onDeviceAdded) | Triggered when a new device is added to the CEC network. |
| [onDeviceInfoUpdated](#onDeviceInfoUpdated) | Triggered when device information changes. |
| [onDeviceRemoved](#onDeviceRemoved) | Triggered when a device is removed from the CEC network. |
| [onImageViewOnMsg](#onImageViewOnMsg) | Triggered when an <Image View ON> CEC message is received from the source device. |
| [onInActiveSource](#onInActiveSource) | Triggered when the source is no longer active. |
| [onKeyPressEvent](#onKeyPressEvent) | Notifies when a key press CEC message is received from other CEC device |
| [onKeyReleaseEvent](#onKeyReleaseEvent) | Notifies when a key release CEC message is received from other CEC device |
| [onTextViewOnMsg](#onTextViewOnMsg) | Triggered when a <Text View ON> CEC message is received from the source device. |
| [onWakeupFromStandby](#onWakeupFromStandby) | Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device. |
| [reportAudioDeviceConnectedStatus](#reportAudioDeviceConnectedStatus) | Triggered when an audio device is added or removed. |
| [reportAudioDevicePowerStatus](#reportAudioDevicePowerStatus) | Triggered when the source device changes. |
| [reportAudioStatusEvent](#reportAudioStatusEvent) | Triggered when CEC <Report Audio Status> message of device is received. |
| [reportCecEnabledEvent](#reportCecEnabledEvent) | Triggered when the HDMI-CEC is enabled. |
| [reportFeatureAbortEvent](#reportFeatureAbortEvent) | Triggered when CEC <Feature Abort> message of device is received. |
| [setSystemAudioModeEvent](#setSystemAudioModeEvent) | Triggered when CEC <Set System Audio Mode> message of device is received. |
| [shortAudiodescriptorEvent](#shortAudiodescriptorEvent) | Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor. |
| [standbyMessageReceived](#standbyMessageReceived) | Triggered when the source device changes status to STANDBY. |

<a id="arcInitiationEvent"></a>
## *arcInitiationEvent*

This event is generated when ARC routing through the HDMI ARC port has been successfully initiated and the ARC connection is active. It notifies clients that audio can be routed through the ARC channel.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Is the operation successful or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.HdmiCecSink.arcInitiationEvent",
    "params": {
        "status": "AUDIO_DEVICE_CONNECTED"
    }
}
```

<a id="arcTerminationEvent"></a>
## *arcTerminationEvent*

This event is generated when ARC routing through the HDMI ARC port has been terminated and the ARC connection is no longer active. It notifies clients that audio can no longer be routed through the ARC channel.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Is the operation successful or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.HdmiCecSink.arcTerminationEvent",
    "params": {
        "status": "AUDIO_DEVICE_CONNECTED"
    }
}
```

<a id="onActiveSourceChange"></a>
## *onActiveSourceChange*

Provides the logical and physical addresses of the new active source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |
| params.physicalAddress | string | Physical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.HdmiCecSink.onActiveSourceChange",
    "params": {
        "logicalAddress": 4,
        "physicalAddress": "1.0.0.0"
    }
}
```

<a id="onDeviceAdded"></a>
## *onDeviceAdded*

Provides the logical address of the newly added device in the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.HdmiCecSink.onDeviceAdded",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onDeviceInfoUpdated"></a>
## *onDeviceInfoUpdated*

Provides the logical address of the device whose information has been updated.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.HdmiCecSink.onDeviceInfoUpdated",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onDeviceRemoved"></a>
## *onDeviceRemoved*

Provides the logical address of the device that has been removed from the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the removed device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.HdmiCecSink.onDeviceRemoved",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onImageViewOnMsg"></a>
## *onImageViewOnMsg*

Provides the logical address of the source device that sent the <Image View ON> CEC message.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.HdmiCecSink.onImageViewOnMsg",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onInActiveSource"></a>
## *onInActiveSource*

Provides the logical and physical addresses of the source device that is no longer active.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the source |
| params.physicalAddress | string | Physical address of the source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.HdmiCecSink.onInActiveSource",
    "params": {
        "logicalAddress": 4,
        "physicalAddress": "1.0.0.0"
    }
}
```

<a id="onKeyPressEvent"></a>
## *onKeyPressEvent*

Provides the logical address and key code of the device when a key press CEC message is received from other CEC device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |
| params.keyCode | int | Key code of the key press event |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.HdmiCecSink.onKeyPressEvent",
    "params": {
        "logicalAddress": 4,
        "keyCode": "0x44"
    }
}
```

<a id="onKeyReleaseEvent"></a>
## *onKeyReleaseEvent*

Provides the logical address of the device when a key release CEC message is received from other CEC device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.HdmiCecSink.onKeyReleaseEvent",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onTextViewOnMsg"></a>
## *onTextViewOnMsg*

Provides the logical address of the source device that sent the <Text View ON> CEC message.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.HdmiCecSink.onTextViewOnMsg",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="onWakeupFromStandby"></a>
## *onWakeupFromStandby*

Provides the logical address of the connected source device that sent the <Image View ON>/ <Text View ON>/ <Active Source> CEC message while the TV is in standby mode.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "method": "org.rdk.HdmiCecSink.onWakeupFromStandby",
    "params": {
        "logicalAddress": 4
    }
}
```

<a id="reportAudioDeviceConnectedStatus"></a>
## *reportAudioDeviceConnectedStatus*

Provides the status and connection state of the audio device when it is added or removed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Status of the audio device |
| params.audioDeviceConnected | string | Audio device connected or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "method": "org.rdk.HdmiCecSink.reportAudioDeviceConnectedStatus",
    "params": {
        "status": "AUDIO_DEVICE_CONNECTED",
        "audioDeviceConnected": true
    }
}
```

<a id="reportAudioDevicePowerStatus"></a>
## *reportAudioDevicePowerStatus*

Provides the power status of the source device when it changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerStatus | int | Power status of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.HdmiCecSink.reportAudioDevicePowerStatus",
    "params": {
        "powerStatus": 0
    }
}
```

<a id="reportAudioStatusEvent"></a>
## *reportAudioStatusEvent*

Provides the mute status and volume level of the device when CEC <Report Audio Status> message is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.muteStatus | int | Mute status of the device |
| params.volumeLevel | int | Volume level of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.HdmiCecSink.reportAudioStatusEvent",
    "params": {
        "muteStatus": 0,
        "volumeLevel": 50
    }
}
```

<a id="reportCecEnabledEvent"></a>
## *reportCecEnabledEvent*

Provides the HDMI-CEC enabled status.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.cecEnable | string | HDMI-CEC enabled or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.HdmiCecSink.reportCecEnabledEvent",
    "params": {
        "cecEnable": true
    }
}
```

<a id="reportFeatureAbortEvent"></a>
## *reportFeatureAbortEvent*

Provides the logical address, opcode, and reason for the feature abort when CEC <Feature Abort> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |
| params.opcode | int | Opcode of the message |
| params.FeatureAbortReason | int | Reason for the feature abort |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.HdmiCecSink.reportFeatureAbortEvent",
    "params": {
        "logicalAddress": 4,
        "opcode": "0x44",
        "FeatureAbortReason": "0x01"
    }
}
```

<a id="setSystemAudioModeEvent"></a>
## *setSystemAudioModeEvent*

Provides the audio mode when CEC <Set System Audio Mode> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioMode | string | Audio mode of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.HdmiCecSink.setSystemAudioModeEvent",
    "params": {
        "audioMode": "AUDIO_MODE_ON"
    }
}
```

<a id="shortAudiodescriptorEvent"></a>
## *shortAudiodescriptorEvent*

Provides the Short Audio Descriptor (SAD) information when it is received from the connected audio device. See requestShortAudioDescriptor.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.shortAudioDescriptor | string | JSON response containing the Short Audio Descriptor (SAD) information |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "method": "org.rdk.HdmiCecSink.shortAudiodescriptorEvent",
    "params": {
        "shortAudioDescriptor": {
            "shortAudioDescriptor": "0x09, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00"
        }
    }
}
```

<a id="standbyMessageReceived"></a>
## *standbyMessageReceived*

Provides the logical address of the source device when it changes status to STANDBY.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "method": "org.rdk.HdmiCecSink.standbyMessageReceived",
    "params": {
        "logicalAddress": 4
    }
}
```

