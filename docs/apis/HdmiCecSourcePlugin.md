<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IHdmiCecSource_Plugin"></a>
# IHdmiCecSource Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IHdmiCecSource/CHANGELOG.md)**

A IHdmiCecSource plugin for Thunder framework.

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

The `IHdmiCecSource` plugin provides an interface for IHdmiCecSource.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IHdmiCecSource*) |
| classname | string | Class name: *IHdmiCecSource* |
| locator | string | Library name: *libWPEFrameworkIHdmiCecSource.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IHdmiCecSource plugin:

IHdmiCecSource interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetActiveSourceStatus](#method.GetActiveSourceStatus) | Gets the status if the device is the current active source |
| [GetDeviceList](#method.GetDeviceList) | Gets the list of devices connected to the HDMI CEC source |
| [GetEnabled](#method.GetEnabled) | Gets the status of the HDMI CEC source |
| [GetOSDName](#method.GetOSDName) | Gets the OSD name of the HDMI CEC source |
| [GetOTPEnabled](#method.GetOTPEnabled) | Gets the OTP enabled status of the HDMI CEC source |
| [GetVendorId](#method.GetVendorId) | Gets the vendor ID of the HDMI CEC source |
| [PerformOTPAction](#method.PerformOTPAction) | Performs the OTP action |
| [SendKeyPressEvent](#method.SendKeyPressEvent) | Sends a key press event to the HDMI CEC device. |
| [SendStandbyMessage](#method.SendStandbyMessage) | Sends a standby message to another CEC device |
| [SetEnabled](#method.SetEnabled) | Sets the status of the HDMI CEC source |
| [SetOSDName](#method.SetOSDName) | Sets the OSD name of the HDMI CEC source |
| [SetOTPEnabled](#method.SetOTPEnabled) | Sets the OTP enabled status of the HDMI CEC source |
| [SetVendorId](#method.SetVendorId) | Sets the vendor ID of the HDMI CEC source |

<a id="method.GetActiveSourceStatus"></a>
## *GetActiveSourceStatus [<sup>method</sup>](#head.Methods)*

Gets the status if the device is the current active source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.status | bool | Is the active source active or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getActiveSourceStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "status": "true",
        "success": "true"
    }
}
```
<a id="method.GetDeviceList"></a>
## *GetDeviceList [<sup>method</sup>](#head.Methods)*

Gets the list of devices connected to the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.numberofdevices | uint32_t | Number of devices connected to the HDMI CEC source |
| result.deviceList | IHdmiCecSourceDeviceListIterator | List of devices connected to the HDMI CEC source |
| result.deviceList[#].logicalAddress | uint8_t |  |
| result.deviceList[#].vendorID | string |  |
| result.deviceList[#].osdName | string |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getDeviceList"
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
                "vendorID": "",
                "osdName": ""
            }
        ],
        "success": "true"
    }
}
```
<a id="method.GetEnabled"></a>
## *GetEnabled [<sup>method</sup>](#head.Methods)*

Gets the status of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.enabled | bool | Is the HDMI CEC source enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getEnabled"
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

Gets the OSD name of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.name | string | OSD name of the HDMI CEC source |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getOSDName"
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
<a id="method.GetOTPEnabled"></a>
## *GetOTPEnabled [<sup>method</sup>](#head.Methods)*

Gets the OTP enabled status of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.enabled | bool | Is the HDMI CEC source enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getOTPEnabled"
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
<a id="method.GetVendorId"></a>
## *GetVendorId [<sup>method</sup>](#head.Methods)*

Gets the vendor ID of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.vendorid | string |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.getVendorId"
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
<a id="method.PerformOTPAction"></a>
## *PerformOTPAction [<sup>method</sup>](#head.Methods)*

Performs the OTP action

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.performOTPAction"
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

Sends a key press event to the HDMI CEC device.

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
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.sendKeyPressEvent",
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

Sends a standby message to another CEC device

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.sendStandbyMessage"
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

Sets the status of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | Is the HDMI CEC source enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.setEnabled",
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
<a id="method.SetOSDName"></a>
## *SetOSDName [<sup>method</sup>](#head.Methods)*

Sets the OSD name of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.name | string | OSD name of the HDMI CEC source |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.setOSDName",
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
<a id="method.SetOTPEnabled"></a>
## *SetOTPEnabled [<sup>method</sup>](#head.Methods)*

Sets the OTP enabled status of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | Is the HDMI CEC source enabled or not |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.setOTPEnabled",
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
<a id="method.SetVendorId"></a>
## *SetVendorId [<sup>method</sup>](#head.Methods)*

Sets the vendor ID of the HDMI CEC source

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.vendorid | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | HdmiCecSourceSuccess | Is the operation successful or not |
| result.success.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.HdmiCecSource.setVendorId",
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


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IHdmiCecSource plugin:

IHdmiCecSource interface events:

| Method | Description |
| :-------- | :-------- |
| [OnActiveSourceStatusUpdated](#event.OnActiveSourceStatusUpdated) | Notifies when the active source status is updated |
| [OnDeviceAdded](#event.OnDeviceAdded) | Notifies when CEC device added to CEC network |
| [OnDeviceInfoUpdated](#event.OnDeviceInfoUpdated) | Notifies when CEC device info updated |
| [OnDeviceRemoved](#event.OnDeviceRemoved) | Notifies when CEC device removed from CEC network |
| [OnKeyPressEvent](#event.OnKeyPressEvent) | Notifies when a key press CEC message is received from other CEC device |
| [OnKeyReleaseEvent](#event.OnKeyReleaseEvent) | Notifies when a key release CEC message is received from other CEC device |
| [StandbyMessageReceived](#event.StandbyMessageReceived) | Notifies when CEC standby message received from the other CEC device |

<a id="event.OnActiveSourceStatusUpdated"></a>
## *OnActiveSourceStatusUpdated [<sup>event</sup>](#head.Notifications)*

Notifies when the active source status is updated

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.status | bool | Is the active source active or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onActiveSourceStatusUpdated",
    "params": {
        "status": "true"
    }
}
```
<a id="event.OnDeviceAdded"></a>
## *OnDeviceAdded [<sup>event</sup>](#head.Notifications)*

Notifies when CEC device added to CEC network

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onDeviceAdded",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnDeviceInfoUpdated"></a>
## *OnDeviceInfoUpdated [<sup>event</sup>](#head.Notifications)*

Notifies when CEC device info updated

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onDeviceInfoUpdated",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnDeviceRemoved"></a>
## *OnDeviceRemoved [<sup>event</sup>](#head.Notifications)*

Notifies when CEC device removed from CEC network

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onDeviceRemoved",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.OnKeyPressEvent"></a>
## *OnKeyPressEvent [<sup>event</sup>](#head.Notifications)*

Notifies when a key press CEC message is received from other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |
| params.keyCode | int | Key code of the key press event |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onKeyPressEvent",
    "params": {
        "logicalAddress": "0",
        "keyCode": "0"
    }
}
```
<a id="event.OnKeyReleaseEvent"></a>
## *OnKeyReleaseEvent [<sup>event</sup>](#head.Notifications)*

Notifies when a key release CEC message is received from other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.onKeyReleaseEvent",
    "params": {
        "logicalAddress": "0"
    }
}
```
<a id="event.StandbyMessageReceived"></a>
## *StandbyMessageReceived [<sup>event</sup>](#head.Notifications)*

Notifies when CEC standby message received from the other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.logicalAddress | int | Logical address of the added device |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "client.events.standbyMessageReceived",
    "params": {
        "logicalAddress": "0"
    }
}
```