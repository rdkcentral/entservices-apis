<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IHdmiCecSink_Plugin"></a>
# IHdmiCecSink Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IHdmiCecSink/CHANGELOG.md)**

A IHdmiCecSink plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `IHdmiCecSink` plugin provides an interface for IHdmiCecSink.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IHdmiCecSink*) |
| classname | string | Class name: *IHdmiCecSink* |
| locator | string | Library name: *libWPEFrameworkIHdmiCecSink.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IHdmiCecSink plugin:

IHdmiCecSink interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetActiveRoute](#method.GetActiveRoute) | Gets the Active Route(s) of the HDMI CEC Sink |
| [GetActiveSource](#method.GetActiveSource) | Gets the status of the current active source |
| [GetAudioDeviceConnectedStatus](#method.GetAudioDeviceConnectedStatus) | Gets audio device connected status |
| [GetDeviceList](#method.GetDeviceList) | Gets the list of devices connected to the HDMI CEC sink |
| [GetEnabled](#method.GetEnabled) | Gets the status of the HDMI CEC Sink |
| [GetOSDName](#method.GetOSDName) | Gets the OSD name of the HDMI CEC Sink |
| [GetVendorId](#method.GetVendorId) | Gets the vendor ID of the HDMI CEC Sink |
| [PrintDeviceList](#method.PrintDeviceList) | This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices |
| [RequestActiveSource](#method.RequestActiveSource) | Request the active source in the network |
| [RequestShortAudioDescriptor](#method.RequestShortAudioDescriptor) | Sends the CEC Request Short Audio Descriptor (SAD) message as an |
| [SendAudioDevicePowerOnMessage](#method.SendAudioDevicePowerOnMessage) | This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network. |
| [SendGetAudioStatusMessage](#method.SendGetAudioStatusMessage) | Sends the CEC <Give Audio Status> message to request the audio status. |
| [SendKeyPressEvent](#method.SendKeyPressEvent) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. |
| [SendStandbyMessage](#method.SendStandbyMessage) | Sends the CEC <Standby> message to another CEC device |
| [SendUserControlPressed](#method.SendUserControlPressed) | Sends the CEC <User Control Pressed> message when TV remote key is pressed. |
| [SendUserControlReleased](#method.SendUserControlReleased) | Sends the CEC <User Control Released> message when TV remote key is released. |
| [SetActivePath](#method.SetActivePath) | Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state. |
| [SetActiveSource](#method.SetActiveSource) | Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps. |
| [SetEnabled](#method.SetEnabled) | Sets the status of the HDMI CEC Sink |
| [SetLatencyInfo](#method.SetLatencyInfo) | Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature. |
| [SetMenuLanguage](#method.SetMenuLanguage) | Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message. |
| [SetOSDName](#method.SetOSDName) | Sets the OSD name of the HDMI CEC Sink |
| [SetRoutingChange](#method.SetRoutingChange) | Changes routing while switching between HDMI inputs and TV. |
| [SetVendorId](#method.SetVendorId) | Sets the vendor ID of the HDMI CEC Sink |
| [SetupARCRouting](#method.SetupARCRouting) | Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent. |

<a id="method.GetActiveRoute"></a>
## *GetActiveRoute [<sup>method</sup>](#head.Methods)*

Gets the Active Route(s) of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.available | bool | Is the active route available or not |
| result.length | uint8_t | Length of the active route |
| result.pathList | IHdmiCecSinkActivePathIterator | List of active path |
| result.pathList[#].logicalAddress | uint8_t |  |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetActiveRoute"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "available": "true",
        "length": "",
        "pathList": [
            {
                "logicalAddress": "",
                "physicalAddress": "",
                "deviceType": "",
                "vendorID": "",
                "osdName": ""
            }
        ],
        "ActiveRoute": "",
        "success": "true"
    }
}
```
<a id="method.GetActiveSource"></a>
## *GetActiveSource [<sup>method</sup>](#head.Methods)*

Gets the status of the current active source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.available | bool | Is the active route available or not |
| result.logicalAddress | uint8_t | Logical address of the active source |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetActiveSource"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "available": "true",
        "logicalAddress": "",
        "physicalAddress": "",
        "deviceType": "",
        "cecVersion": "",
        "osdName": "",
        "vendorID": "",
        "powerStatus": "",
        "port": "",
        "success": "true"
    }
}
```
<a id="method.GetAudioDeviceConnectedStatus"></a>
## *GetAudioDeviceConnectedStatus [<sup>method</sup>](#head.Methods)*

Gets audio device connected status

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.connected | bool | Is the audio device connected or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetAudioDeviceConnectedStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "connected": "true",
        "success": "true"
    }
}
```
<a id="method.GetDeviceList"></a>
## *GetDeviceList [<sup>method</sup>](#head.Methods)*

Gets the list of devices connected to the HDMI CEC sink

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.numberofdevices | uint32_t | Number of devices connected to the HDMI CEC sink |
| result.deviceList | IHdmiCecSinkDeviceListIterator | List of devices connected to the HDMI CEC sink |
| result.deviceList[#].logicalAddress | uint8_t |  |
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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "numberofdevices": "0",
        "deviceList": [
            {
                "logicalAddress": "",
                "physicalAddress": "",
                "deviceType": "",
                "cecVersion": "",
                "osdName": "",
                "vendorID": "",
                "powerStatus": "",
                "portNumber": ""
            }
        ],
        "success": "true"
    }
}
```
<a id="method.GetEnabled"></a>
## *GetEnabled [<sup>method</sup>](#head.Methods)*

Gets the status of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.enabled | bool | Is the HDMI CEC Sink enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetEnabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true",
        "success": "true"
    }
}
```
<a id="method.GetOSDName"></a>
## *GetOSDName [<sup>method</sup>](#head.Methods)*

Gets the OSD name of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.name | string | OSD name of the HDMI CEC Sink |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetOSDName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "name": "",
        "success": "true"
    }
}
```
<a id="method.GetVendorId"></a>
## *GetVendorId [<sup>method</sup>](#head.Methods)*

Gets the vendor ID of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.vendorid | string | Vendor ID of the HDMI CEC Sink |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.GetVendorId"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "vendorid": "",
        "success": "true"
    }
}
```
<a id="method.PrintDeviceList"></a>
## *PrintDeviceList [<sup>method</sup>](#head.Methods)*

This is a helper debug command for developers. It prints the list of connected devices and properties of connected devices

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.printed | bool | Is the device list printed or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.PrintDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "printed": "true",
        "success": "true"
    }
}
```
<a id="method.RequestActiveSource"></a>
## *RequestActiveSource [<sup>method</sup>](#head.Methods)*

Request the active source in the network

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.RequestActiveSource"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.RequestShortAudioDescriptor"></a>
## *RequestShortAudioDescriptor [<sup>method</sup>](#head.Methods)*

Sends the CEC Request Short Audio Descriptor (SAD) message as an

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.RequestShortAudioDescriptor"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendAudioDevicePowerOnMessage"></a>
## *SendAudioDevicePowerOnMessage [<sup>method</sup>](#head.Methods)*

This message is used to power on the connected audio device. Usually sent by the TV when it comes out of standby and detects audio device connected in the network.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendAudioDevicePowerOnMessage"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendGetAudioStatusMessage"></a>
## *SendGetAudioStatusMessage [<sup>method</sup>](#head.Methods)*

Sends the CEC <Give Audio Status> message to request the audio status.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendGetAudioStatusMessage"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendKeyPressEvent"></a>
## *SendKeyPressEvent [<sup>method</sup>](#head.Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | uint32_t | Logical address of the device |
| params.keyCode | uint32_t | Key code of the key press event |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendKeyPressEvent",
    "params": {
        "logicalAddress": "0",
        "keyCode": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendStandbyMessage"></a>
## *SendStandbyMessage [<sup>method</sup>](#head.Methods)*

Sends the CEC <Standby> message to another CEC device

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendStandbyMessage"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendUserControlPressed"></a>
## *SendUserControlPressed [<sup>method</sup>](#head.Methods)*

Sends the CEC <User Control Pressed> message when TV remote key is pressed.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | uint32_t | Logical address of the device |
| params.keyCode | uint32_t | Key code of the key press event |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendUserControlPressed",
    "params": {
        "logicalAddress": "0",
        "keyCode": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SendUserControlReleased"></a>
## *SendUserControlReleased [<sup>method</sup>](#head.Methods)*

Sends the CEC <User Control Released> message when TV remote key is released.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | uint32_t | Logical address of the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SendUserControlReleased",
    "params": {
        "logicalAddress": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetActivePath"></a>
## *SetActivePath [<sup>method</sup>](#head.Methods)*

Sets the source device to active (setStreamPath). The source wakes from standby if it’s in the standby state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.activePath | string | Active path of the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetActivePath",
    "params": {
        "activePath": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetActiveSource"></a>
## *SetActiveSource [<sup>method</sup>](#head.Methods)*

Sets the current active source as TV (physical address 0.0.0.0). This call needs to be made when the TV switches to internal tuner or any apps.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetActiveSource"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetEnabled"></a>
## *SetEnabled [<sup>method</sup>](#head.Methods)*

Sets the status of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | Is the HDMI CEC Sink enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetEnabled",
    "params": {
        "enabled": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetLatencyInfo"></a>
## *SetLatencyInfo [<sup>method</sup>](#head.Methods)*

Sets the Current Latency Values such as Video Latency, Latency Flags,Audio Output Compensated value and Audio Output Delay by sending <Report Current Latency> message for Dynamic Auto LipSync Feature.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.videoLatency | string | Video Latency value |
| params.lowLatencyMode | string | Low Latency Mode value |
| params.audioOutputCompensated | string | Audio Output Compensated value |
| params.audioOutputDelay | string | Audio Output Delay value |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetLatencyInfo",
    "params": {
        "videoLatency": "",
        "lowLatencyMode": "",
        "audioOutputCompensated": "",
        "audioOutputDelay": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetMenuLanguage"></a>
## *SetMenuLanguage [<sup>method</sup>](#head.Methods)*

Updates the internal data structure with the new menu Language and also broadcasts the <Set Menu Language> CEC message.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.language | string | Menu language to be set |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetMenuLanguage",
    "params": {
        "language": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetOSDName"></a>
## *SetOSDName [<sup>method</sup>](#head.Methods)*

Sets the OSD name of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.name | string | OSD name of the HDMI CEC Sink |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetOSDName",
    "params": {
        "name": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetRoutingChange"></a>
## *SetRoutingChange [<sup>method</sup>](#head.Methods)*

Changes routing while switching between HDMI inputs and TV.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.oldPort | string | Old port number |
| params.newPort | string | New port number |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetRoutingChange",
    "params": {
        "oldPort": "",
        "newPort": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetVendorId"></a>
## *SetVendorId [<sup>method</sup>](#head.Methods)*

Sets the vendor ID of the HDMI CEC Sink

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.vendorid | string | Vendor ID of the HDMI CEC Sink |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetVendorId",
    "params": {
        "vendorid": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetupARCRouting"></a>
## *SetupARCRouting [<sup>method</sup>](#head.Methods)*

Enable (or disable) HDMI-CEC Audio Return Channel (ARC) routing. Upon enabling, triggers arcInitiationEvent and upon disabling, triggers arcTerminationEvent.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | Is the HDMI CEC Sink enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSinkSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetupARCRouting",
    "params": {
        "enabled": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IHdmiCecSink plugin:

IHdmiCecSink interface events:

| Method | Description |
| :-------- | :-------- |
| [ArcInitiationEvent](#event.ArcInitiationEvent) | Triggered when routing though the HDMI ARC port is successfully established. |
| [ArcTerminationEvent](#event.ArcTerminationEvent) | Triggered when routing though the HDMI ARC port terminates. |
| [OnActiveSourceChange](#event.OnActiveSourceChange) | Triggered when the active source device changes. |
| [OnDeviceAdded](#event.OnDeviceAdded) | Triggered when a new device is added to the CEC network. |
| [OnDeviceInfoUpdated](#event.OnDeviceInfoUpdated) | Triggered when device information changes. |
| [OnDeviceRemoved](#event.OnDeviceRemoved) | Triggered when a device is removed from the CEC network. |
| [OnImageViewOnMsg](#event.OnImageViewOnMsg) | Triggered when an <Image View ON> CEC message is received from the source device. |
| [OnInActiveSource](#event.OnInActiveSource) | Triggered when the source is no longer active. |
| [OnTextViewOnMsg](#event.OnTextViewOnMsg) | Triggered when a <Text View ON> CEC message is received from the source device. |
| [OnWakeupFromStandby](#event.OnWakeupFromStandby) | Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device. |
| [ReportAudioDeviceConnectedStatus](#event.ReportAudioDeviceConnectedStatus) | Triggered when an audio device is added or removed. |
| [ReportAudioDevicePowerStatus](#event.ReportAudioDevicePowerStatus) | Triggered when the source device changes. |
| [ReportAudioStatusEvent](#event.ReportAudioStatusEvent) | Triggered when CEC <Report Audio Status> message of device is received. |
| [ReportCecEnabledEvent](#event.ReportCecEnabledEvent) | Triggered when the HDMI-CEC is enabled. |
| [ReportFeatureAbortEvent](#event.ReportFeatureAbortEvent) | Triggered when CEC <Feature Abort> message of device is received. |
| [SetSystemAudioModeEvent](#event.SetSystemAudioModeEvent) | Triggered when CEC <Set System Audio Mode> message of device is received. |
| [ShortAudiodescriptorEvent](#event.ShortAudiodescriptorEvent) | Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor. |
| [StandbyMessageReceived](#event.StandbyMessageReceived) | Triggered when the source device changes status to STANDBY. |

<a id="event.ArcInitiationEvent"></a>
## *ArcInitiationEvent [<sup>event</sup>](#head.Notifications)*

Triggered when routing though the HDMI ARC port is successfully established.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.success | string | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ArcInitiationEvent",
    "params": {
        "success": ""
    }
}
```
<a id="event.ArcTerminationEvent"></a>
## *ArcTerminationEvent [<sup>event</sup>](#head.Notifications)*

Triggered when routing though the HDMI ARC port terminates.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.success | string | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ArcTerminationEvent",
    "params": {
        "success": ""
    }
}
```
<a id="event.OnActiveSourceChange"></a>
## *OnActiveSourceChange [<sup>event</sup>](#head.Notifications)*

Triggered when the active source device changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |
| params.physicalAddress | string | Physical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnActiveSourceChange",
    "params": {
        "logicalAddress": "0",
        "physicalAddress": ""
    }
}
```
<a id="event.OnDeviceAdded"></a>
## *OnDeviceAdded [<sup>event</sup>](#head.Notifications)*

Triggered when a new device is added to the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnDeviceAdded",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnDeviceInfoUpdated"></a>
## *OnDeviceInfoUpdated [<sup>event</sup>](#head.Notifications)*

Triggered when device information changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnDeviceInfoUpdated",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnDeviceRemoved"></a>
## *OnDeviceRemoved [<sup>event</sup>](#head.Notifications)*

Triggered when a device is removed from the CEC network.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnDeviceRemoved",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnImageViewOnMsg"></a>
## *OnImageViewOnMsg [<sup>event</sup>](#head.Notifications)*

Triggered when an <Image View ON> CEC message is received from the source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnImageViewOnMsg",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnInActiveSource"></a>
## *OnInActiveSource [<sup>event</sup>](#head.Notifications)*

Triggered when the source is no longer active.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |
| params.physicalAddress | string | Physical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnInActiveSource",
    "params": {
        "logicalAddress": "0",
        "physicalAddress": ""
    }
}
```
<a id="event.OnTextViewOnMsg"></a>
## *OnTextViewOnMsg [<sup>event</sup>](#head.Notifications)*

Triggered when a <Text View ON> CEC message is received from the source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnTextViewOnMsg",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnWakeupFromStandby"></a>
## *OnWakeupFromStandby [<sup>event</sup>](#head.Notifications)*

Triggered when the TV is in standby mode and it receives <Image View ON>/ <Text View ON>/ <Active Source> CEC message from the connected source device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.OnWakeupFromStandby",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.ReportAudioDeviceConnectedStatus"></a>
## *ReportAudioDeviceConnectedStatus [<sup>event</sup>](#head.Notifications)*

Triggered when an audio device is added or removed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.status | string | Status of the audio device |
| params.audioDeviceConnected | string | Audio device connected or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ReportAudioDeviceConnectedStatus",
    "params": {
        "status": "",
        "audioDeviceConnected": ""
    }
}
```
<a id="event.ReportAudioDevicePowerStatus"></a>
## *ReportAudioDevicePowerStatus [<sup>event</sup>](#head.Notifications)*

Triggered when the source device changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.powerStatus | int | Power status of the device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ReportAudioDevicePowerStatus",
    "params": {
        "powerStatus": "0"
    }
}
```
<a id="event.ReportAudioStatusEvent"></a>
## *ReportAudioStatusEvent [<sup>event</sup>](#head.Notifications)*

Triggered when CEC <Report Audio Status> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.muteStatus | int | Mute status of the device |
| params.volumeLevel | int | Volume level of the device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ReportAudioStatusEvent",
    "params": {
        "muteStatus": "0",
        "volumeLevel": "0"
    }
}
```
<a id="event.ReportCecEnabledEvent"></a>
## *ReportCecEnabledEvent [<sup>event</sup>](#head.Notifications)*

Triggered when the HDMI-CEC is enabled.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.cecEnable | string | HDMI-CEC enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ReportCecEnabledEvent",
    "params": {
        "cecEnable": ""
    }
}
```
<a id="event.ReportFeatureAbortEvent"></a>
## *ReportFeatureAbortEvent [<sup>event</sup>](#head.Notifications)*

Triggered when CEC <Feature Abort> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |
| params.opcode | int | Opcode of the message |
| params.FeatureAbortReason | int | Reason for the feature abort |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ReportFeatureAbortEvent",
    "params": {
        "logicalAddress": "0",
        "opcode": "0",
        "FeatureAbortReason": "0"
    }
}
```
<a id="event.SetSystemAudioModeEvent"></a>
## *SetSystemAudioModeEvent [<sup>event</sup>](#head.Notifications)*

Triggered when CEC <Set System Audio Mode> message of device is received.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.audioMode | string | Audio mode of the device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.SetSystemAudioModeEvent",
    "params": {
        "audioMode": ""
    }
}
```
<a id="event.ShortAudiodescriptorEvent"></a>
## *ShortAudiodescriptorEvent [<sup>event</sup>](#head.Notifications)*

Triggered when SAD is received from the connected audio device. See requestShortAudioDescriptor.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.jsonresponse | string | JSON response containing the Short Audio Descriptor (SAD) information |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.ShortAudiodescriptorEvent",
    "params": {
        "jsonresponse": ""
    }
}
```
<a id="event.StandbyMessageReceived"></a>
## *StandbyMessageReceived [<sup>event</sup>](#head.Notifications)*

Triggered when the source device changes status to STANDBY.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the active source |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdmiCecSink.StandbyMessageReceived",
    "params": {
        "logicalAddress": "0"
    }
}
```