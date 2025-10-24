<!-- Generated automatically, DO NOT EDIT! -->
<a id="HdmiCecSink_Plugin"></a>
# HdmiCecSink Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HdmiCecSink)**

A HdmiCecSink plugin for Thunder framework.

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

The `HdmiCecSink` plugin provides an interface for HdmiCecSink.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdmiCecSink) |
| classname | string | Class name: *HdmiCecSink* |
| locator | string | Library name: *libWPEFrameworkHdmiCecSink.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the HdmiCecSink plugin:

HdmiCecSink interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getActiveRoute](#getActiveRoute) | Gets the Active Route(s) of the HDMI CEC Sink | NA |
| [getActiveSource](#getActiveSource) | Gets the status of the current active source | NA |
| [getAudioDeviceConnectedStatus](#getAudioDeviceConnectedStatus) | Gets audio device connected status | NA |
| [getDeviceList](#getDeviceList) | Gets the list of devices connected to the HDMI CEC sink | NA |
| [getEnabled](#getEnabled) | Gets the status of the HDMI CEC Sink | NA |
| [getOSDName](#getOSDName) | Gets the OSD name of the HDMI CEC Sink | NA |
| [getVendorId](#getVendorId) | Gets the vendor ID of the HDMI CEC Sink | NA |
| [printDeviceList](#printDeviceList) | This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices | NA |
| [requestActiveSource](#requestActiveSource) | Request the active source in the network | onActiveSourceChange, onDeviceAdded, onDeviceInfoUpdated |
| [requestAudioDevicePowerStatus](#requestAudioDevicePowerStatus) | Requests the audio device power status. | reportAudioDevicePowerStatus |
| [requestShortAudioDescriptor](#requestShortAudioDescriptor) | Sends the CEC Request Short Audio Descriptor (SAD) message as an | shortAudiodescriptorEvent |
| [sendAudioDevicePowerOnMessage](#sendAudioDevicePowerOnMessage) | This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network. | setSystemAudioModeEvent |
| [sendGetAudioStatusMessage](#sendGetAudioStatusMessage) | Sends the CEC <Give Audio Status> message to request the audio status. | reportAudioStatusEvent |
| [sendKeyPressEvent](#sendKeyPressEvent) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. | NA |
| [sendStandbyMessage](#sendStandbyMessage) | Sends the CEC <Standby> message to another CEC device | NA |
| [sendUserControlPressed](#sendUserControlPressed) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. | NA |
| [sendUserControlReleased](#sendUserControlReleased) | Sends the CEC <User Control Released> message when TV remote key is released. | NA |
| [setActivePath](#setActivePath) | Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state. | NA |
| [setActiveSource](#setActiveSource) | Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps. | NA |
| [setEnabled](#setEnabled) | Sets the status of the HDMI CEC Sink | reportCecEnabledEvent |
| [setLatencyInfo](#setLatencyInfo) | Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature. | NA |
| [setMenuLanguage](#setMenuLanguage) | Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message. | NA |
| [setOSDName](#setOSDName) | Sets the OSD name of the HDMI CEC Sink | NA |
| [setRoutingChange](#setRoutingChange) | Changes routing while switching between HDMI inputs and TV. | NA |
| [setVendorId](#setVendorId) | Sets the vendor ID of the HDMI CEC Sink | NA |
| [setupARCRouting](#setupARCRouting) | Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent. | arcInitiationEvent, arcTerminationEvent |

<a id="getActiveRoute"></a>
## *getActiveRoute [<sup>method</sup>](#Methods)*

Gets the Active Route(s) of the HDMI CEC Sink

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.available | bool | Is the active route available or not |
| result.length | integer | Length of the active route |
| result.pathList | IHdmiCecSinkActivePathIterator | List of active path |
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
        "length": 0,
        "pathList": [
            {
                "logicalAddress": 0,
                "physicalAddress": "",
                "deviceType": "",
                "vendorID": "",
                "osdName": ""
            }
        ],
        "ActiveRoute": "",
        "success": true
    }
}
```

<a id="getActiveSource"></a>
## *getActiveSource [<sup>method</sup>](#Methods)*

Gets the status of the current active source

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.available | bool | Is the active route available or not |
| result.logicalAddress | integer | Logical address of the active source |
| result.physicalAddress | string | Physical address of the active source |
| result.deviceType | string | Device type of the active source |
| result.cecVersion | string | CEC version of the active source |
| result.osdName | string | OSD name of the active source |
| result.vendorID | string | Vendor ID of the active source |
| result.powerStatus | string | Power status of the active source |
| result.port | string |  |
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
        "logicalAddress": 0,
        "physicalAddress": "",
        "deviceType": "",
        "cecVersion": "",
        "osdName": "",
        "vendorID": "",
        "powerStatus": "",
        "port": "",
        "success": true
    }
}
```

<a id="getAudioDeviceConnectedStatus"></a>
## *getAudioDeviceConnectedStatus [<sup>method</sup>](#Methods)*

Gets audio device connected status

### Events
No Events are associated with this method.
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
## *getDeviceList [<sup>method</sup>](#Methods)*

Gets the list of devices connected to the HDMI CEC sink

### Events
No Events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberofdevices | integer | Number of devices connected to the HDMI CEC sink |
| result.deviceList | IHdmiCecSinkDeviceListIterator | List of devices connected to the HDMI CEC sink |
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
        "numberofdevices": 0,
        "deviceList": [
            {
                "logicalAddress": 0,
                "physicalAddress": "",
                "deviceType": "",
                "cecVersion": "",
                "osdName": "",
                "vendorID": "",
                "powerStatus": "",
                "portNumber": ""
            }
        ],
        "success": true
    }
}
```

<a id="getEnabled"></a>
## *getEnabled [<sup>method</sup>](#Methods)*

Gets the status of the HDMI CEC Sink

### Events
No Events are associated with this method.
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
## *getOSDName [<sup>method</sup>](#Methods)*

Gets the OSD name of the HDMI CEC Sink

### Events
No Events are associated with this method.
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
        "name": "",
        "success": true
    }
}
```

<a id="getVendorId"></a>
## *getVendorId [<sup>method</sup>](#Methods)*

Gets the vendor ID of the HDMI CEC Sink

### Events
No Events are associated with this method.
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
        "vendorid": "",
        "success": true
    }
}
```

<a id="printDeviceList"></a>
## *printDeviceList [<sup>method</sup>](#Methods)*

This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices

### Events
No Events are associated with this method.
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
## *requestActiveSource [<sup>method</sup>](#Methods)*

Request the active source in the network

### Events
| Event | Description |
| :-------- | :-------- |
| [onActiveSourceChange ](#onActiveSourceChange ) |  Triggered with the active source device changes. |
| [onDeviceAdded ](#onDeviceAdded ) |  Triggered when an HDMI cable is physically connected to the HDMI port on a TV, or the power cable is connected to the source device. |
| [onDeviceInfoUpdated ](#onDeviceInfoUpdated ) |  Triggered when device information changes (physicalAddress, deviceType, vendorID, osdName, cecVersion, powerStatus). |
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
    "result": {
        "success": true
    }
}
```

<a id="requestAudioDevicePowerStatus"></a>
## *requestAudioDevicePowerStatus [<sup>method</sup>](#Methods)*

Requests the audio device power status.

### Events
| Event | Description |
| :-------- | :-------- |
| [reportAudioDevicePowerStatus ](#reportAudioDevicePowerStatus ) |  Triggered when the audio device power status is received. |
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
    "result": {
        "success": true
    }
}
```

<a id="requestShortAudioDescriptor"></a>
## *requestShortAudioDescriptor [<sup>method</sup>](#Methods)*

Sends the CEC Request Short Audio Descriptor (SAD) message as an

### Events
| Event | Description |
| :-------- | :-------- |
| [shortAudiodescriptorEvent ](#shortAudiodescriptorEvent ) |  Triggered when SAD is received from the connected audio device. |
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
    "result": {
        "success": true
    }
}
```

<a id="sendAudioDevicePowerOnMessage"></a>
## *sendAudioDevicePowerOnMessage [<sup>method</sup>](#Methods)*

This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.

### Events
| Event | Description |
| :-------- | :-------- |
| [setSystemAudioModeEvent ](#setSystemAudioModeEvent ) |  Triggered when CEC <Set System Audio Mode> message of device is received. |
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
    "result": {
        "success": true
    }
}
```

<a id="sendGetAudioStatusMessage"></a>
## *sendGetAudioStatusMessage [<sup>method</sup>](#Methods)*

Sends the CEC <Give Audio Status> message to request the audio status.

### Events
| Event | Description |
| :-------- | :-------- |
| [reportAudioStatusEvent ](#reportAudioStatusEvent ) |  Triggered when CEC <Report Audio Status> message of device is received. |
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
    "result": {
        "success": true
    }
}
```

<a id="sendKeyPressEvent"></a>
## *sendKeyPressEvent [<sup>method</sup>](#Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the active source |
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
        "logicalAddress": 0,
        "keyCode": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.HdmiCecSink.sendKeyPressEvent", "params": {"logicalAddress": 0, "keyCode": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "success": true
    }
}
```

<a id="sendStandbyMessage"></a>
## *sendStandbyMessage [<sup>method</sup>](#Methods)*

Sends the CEC <Standby> message to another CEC device

### Events
No Events are associated with this method.
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
    "result": {
        "success": true
    }
}
```

<a id="sendUserControlPressed"></a>
## *sendUserControlPressed [<sup>method</sup>](#Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the active source |
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
        "logicalAddress": 0,
        "keyCode": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.HdmiCecSink.sendUserControlPressed", "params": {"logicalAddress": 0, "keyCode": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="sendUserControlReleased"></a>
## *sendUserControlReleased [<sup>method</sup>](#Methods)*

Sends the CEC <User Control Released> message when TV remote key is released.

### Events
No Events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | integer | Logical address of the active source |
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
        "logicalAddress": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.HdmiCecSink.sendUserControlReleased", "params": {"logicalAddress": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setActivePath"></a>
## *setActivePath [<sup>method</sup>](#Methods)*

Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.

### Events
No Events are associated with this method.
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
        "activePath": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.HdmiCecSink.setActivePath", "params": {"activePath": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setActiveSource"></a>
## *setActiveSource [<sup>method</sup>](#Methods)*

Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.

### Events
No Events are associated with this method.
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
    "result": {
        "success": true
    }
}
```

<a id="setEnabled"></a>
## *setEnabled [<sup>method</sup>](#Methods)*

Sets the status of the HDMI CEC Sink

### Events
| Event | Description |
| :-------- | :-------- |
| [reportCecEnabledEvent ](#reportCecEnabledEvent ) |  Triggered when the HDMI-CEC is enabled. |
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
    "result": {
        "success": true
    }
}
```

<a id="setLatencyInfo"></a>
## *setLatencyInfo [<sup>method</sup>](#Methods)*

Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.

### Events
No Events are associated with this method.
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
    "result": {
        "success": true
    }
}
```

<a id="setMenuLanguage"></a>
## *setMenuLanguage [<sup>method</sup>](#Methods)*

Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.

### Events
No Events are associated with this method.
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
        "language": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.HdmiCecSink.setMenuLanguage", "params": {"language": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setOSDName"></a>
## *setOSDName [<sup>method</sup>](#Methods)*

Sets the OSD name of the HDMI CEC Sink

### Events
No Events are associated with this method.
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
        "name": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.HdmiCecSink.setOSDName", "params": {"name": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setRoutingChange"></a>
## *setRoutingChange [<sup>method</sup>](#Methods)*

Changes routing while switching between HDMI inputs and TV.

### Events
No Events are associated with this method.
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
        "oldPort": "",
        "newPort": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.HdmiCecSink.setRoutingChange", "params": {"oldPort": "", "newPort": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setVendorId"></a>
## *setVendorId [<sup>method</sup>](#Methods)*

Sets the vendor ID of the HDMI CEC Sink

### Events
No Events are associated with this method.
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
        "vendorid": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.HdmiCecSink.setVendorId", "params": {"vendorid": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setupARCRouting"></a>
## *setupARCRouting [<sup>method</sup>](#Methods)*

Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.

### Events
| Event | Description |
| :-------- | :-------- |
| [arcInitiationEvent ](#arcInitiationEvent ) |  Triggered when routing though the HDMI ARC port is successfully established. |
| [arcTerminationEvent ](#arcTerminationEvent ) |  Triggered when routing though the HDMI ARC port terminates. |
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
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the HdmiCecSink plugin:

HdmiCecSink interface events:

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
## *arcInitiationEvent [<sup>event</sup>](#Notifications)*

Triggered when routing though the HDMI ARC port is successfully established.

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
        "status": ""
    }
}
```

<a id="arcTerminationEvent"></a>
## *arcTerminationEvent [<sup>event</sup>](#Notifications)*

Triggered when routing though the HDMI ARC port terminates.

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
        "status": ""
    }
}
```

<a id="onActiveSourceChange"></a>
## *onActiveSourceChange [<sup>event</sup>](#Notifications)*

Triggered when the active source device changes.

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
        "logicalAddress": 0,
        "physicalAddress": ""
    }
}
```

<a id="onDeviceAdded"></a>
## *onDeviceAdded [<sup>event</sup>](#Notifications)*

Triggered when a new device is added to the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.HdmiCecSink.onDeviceAdded",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onDeviceInfoUpdated"></a>
## *onDeviceInfoUpdated [<sup>event</sup>](#Notifications)*

Triggered when device information changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.HdmiCecSink.onDeviceInfoUpdated",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onDeviceRemoved"></a>
## *onDeviceRemoved [<sup>event</sup>](#Notifications)*

Triggered when a device is removed from the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.HdmiCecSink.onDeviceRemoved",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onImageViewOnMsg"></a>
## *onImageViewOnMsg [<sup>event</sup>](#Notifications)*

Triggered when an <Image View ON> CEC message is received from the source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.HdmiCecSink.onImageViewOnMsg",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onInActiveSource"></a>
## *onInActiveSource [<sup>event</sup>](#Notifications)*

Triggered when the source is no longer active.

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
    "id": 33,
    "method": "org.rdk.HdmiCecSink.onInActiveSource",
    "params": {
        "logicalAddress": 0,
        "physicalAddress": ""
    }
}
```

<a id="onTextViewOnMsg"></a>
## *onTextViewOnMsg [<sup>event</sup>](#Notifications)*

Triggered when a <Text View ON> CEC message is received from the source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.HdmiCecSink.onTextViewOnMsg",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onWakeupFromStandby"></a>
## *onWakeupFromStandby [<sup>event</sup>](#Notifications)*

Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.HdmiCecSink.onWakeupFromStandby",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="reportAudioDeviceConnectedStatus"></a>
## *reportAudioDeviceConnectedStatus [<sup>event</sup>](#Notifications)*

Triggered when an audio device is added or removed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Is the operation successful or not |
| params.audioDeviceConnected | string | Audio device connected or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.HdmiCecSink.reportAudioDeviceConnectedStatus",
    "params": {
        "status": "",
        "audioDeviceConnected": ""
    }
}
```

<a id="reportAudioDevicePowerStatus"></a>
## *reportAudioDevicePowerStatus [<sup>event</sup>](#Notifications)*

Triggered when the source device changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerStatus | int | Power status of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "method": "org.rdk.HdmiCecSink.reportAudioDevicePowerStatus",
    "params": {
        "powerStatus": 0
    }
}
```

<a id="reportAudioStatusEvent"></a>
## *reportAudioStatusEvent [<sup>event</sup>](#Notifications)*

Triggered when CEC <Report Audio Status> message of device is received.

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
    "id": 38,
    "method": "org.rdk.HdmiCecSink.reportAudioStatusEvent",
    "params": {
        "muteStatus": 0,
        "volumeLevel": 0
    }
}
```

<a id="reportCecEnabledEvent"></a>
## *reportCecEnabledEvent [<sup>event</sup>](#Notifications)*

Triggered when the HDMI-CEC is enabled.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.cecEnable | string | HDMI-CEC enabled or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.HdmiCecSink.reportCecEnabledEvent",
    "params": {
        "cecEnable": ""
    }
}
```

<a id="reportFeatureAbortEvent"></a>
## *reportFeatureAbortEvent [<sup>event</sup>](#Notifications)*

Triggered when CEC <Feature Abort> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |
| params.opcode | int | Opcode of the message |
| params.FeatureAbortReason | int | Reason for the feature abort |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.HdmiCecSink.reportFeatureAbortEvent",
    "params": {
        "logicalAddress": 0,
        "opcode": 0,
        "FeatureAbortReason": 0
    }
}
```

<a id="setSystemAudioModeEvent"></a>
## *setSystemAudioModeEvent [<sup>event</sup>](#Notifications)*

Triggered when CEC <Set System Audio Mode> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.audioMode | string | Audio mode of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.HdmiCecSink.setSystemAudioModeEvent",
    "params": {
        "audioMode": ""
    }
}
```

<a id="shortAudiodescriptorEvent"></a>
## *shortAudiodescriptorEvent [<sup>event</sup>](#Notifications)*

Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonresponse | string | JSON response containing the Short Audio Descriptor (SAD) information |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.HdmiCecSink.shortAudiodescriptorEvent",
    "params": {
        "jsonresponse": ""
    }
}
```

<a id="standbyMessageReceived"></a>
## *standbyMessageReceived [<sup>event</sup>](#Notifications)*

Triggered when the source device changes status to STANDBY.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the active source |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.HdmiCecSink.standbyMessageReceived",
    "params": {
        "logicalAddress": 0
    }
}
```
