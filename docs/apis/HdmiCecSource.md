<!-- Generated automatically, DO NOT EDIT! -->
<a id="HdmiCecSource_Module"></a>
# HdmiCecSource Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HdmiCecSource/IHdmiCecSource.h)**

A HdmiCecSource module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IHdmiCecSource](#IHdmiCecSource)
    - [Methods](#IHdmiCecSource-Methods)
    - [Notifications](#IHdmiCecSource-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `HdmiCecSource` module provides the following interface(s):

- IHdmiCecSource

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdmiCecSource) |
| classname | string | Class name: *HdmiCecSource* |
| locator | string | Library name: *libWPEFrameworkHdmiCecSource.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IHdmiCecSource"></a>
## IHdmiCecSource Interface

<a id="IHdmiCecSource-Methods"></a>
### Methods

The following methods are provided by the IHdmiCecSource Interface:

| Method | Description |
| :-------- | :-------- |
| [getActiveSourceStatus](#getActiveSourceStatus) | Gets the status if the device is the current active source |
| [getDeviceList](#getDeviceList) | Gets the list of devices connected to the HDMI CEC source |
| [getEnabled](#getEnabled) | Gets the status of the HDMI CEC source |
| [getOSDName](#getOSDName) | Gets the OSD name of the HDMI CEC source |
| [getOTPEnabled](#getOTPEnabled) | Gets the OTP enabled status of the HDMI CEC source |
| [getVendorId](#getVendorId) | Gets the vendor ID of the HDMI CEC source |
| [performOTPAction](#performOTPAction) | Performs the OTP action |
| [sendKeyPressEvent](#sendKeyPressEvent) | Sends a key press event to the HDMI CEC device. |
| [sendStandbyMessage](#sendStandbyMessage) | Sends a standby message to another CEC device |
| [setEnabled](#setEnabled) | Sets the status of the HDMI CEC source |
| [setOSDName](#setOSDName) | Sets the OSD name of the HDMI CEC source |
| [setOTPEnabled](#setOTPEnabled) | Sets the OTP enabled status of the HDMI CEC source |
| [setVendorId](#setVendorId) | Sets the vendor ID of the HDMI CEC source |

<a id="getActiveSourceStatus"></a>
## *getActiveSourceStatus*

Retrieves the current active source status of the HDMI CEC source device

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | bool | Is the active source active or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.HdmiCecSource.getActiveSourceStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.HdmiCecSource.getActiveSourceStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "status": true,
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getDeviceList"></a>
## *getDeviceList*

Retrieves information about all devices currently connected to the HDMI CEC network

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberofdevices | integer | Number of devices connected to the HDMI CEC source |
| result.deviceList | array | List of devices connected to the HDMI CEC source |
| result.deviceList[#].logicalAddress | integer |  |
| result.deviceList[#].vendorID | string |  |
| result.deviceList[#].osdName | string |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.HdmiCecSource.getDeviceList"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.HdmiCecSource.getDeviceList"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "numberofdevices": 2,
        "deviceList": [
            "[{ logicalAddress: 1, vendorID: \"123456\", osdName: \"Device1\" }, { logicalAddress: 2, vendorID: \"654321\", osdName: \"Device2\" }]"
        ],
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getEnabled"></a>
## *getEnabled*

Retrieves whether the HDMI CEC source is currently enabled or disabled

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Is the HDMI CEC source enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.HdmiCecSource.getEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.HdmiCecSource.getEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "enabled": true,
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getOSDName"></a>
## *getOSDName*

Retrieves the On-Screen Display (OSD) name configured for the HDMI CEC source device

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.name | string | OSD name of the HDMI CEC source |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.HdmiCecSource.getOSDName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.HdmiCecSource.getOSDName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "name": "My CEC Source",
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getOTPEnabled"></a>
## *getOTPEnabled*

Retrieves whether One-Touch Play (OTP) is enabled for the HDMI CEC source

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.otpEnabled | bool | Is the OTP enabled or not |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.HdmiCecSource.getOTPEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.HdmiCecSource.getOTPEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "otpEnabled": true,
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getVendorId"></a>
## *getVendorId*

Retrieves the vendor ID assigned to the HDMI CEC source device

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.vendorid | string |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.HdmiCecSource.getVendorId"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.HdmiCecSource.getVendorId"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "vendorid": "",
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="performOTPAction"></a>
## *performOTPAction*

Triggers the One-Touch Play (OTP) action on the HDMI CEC source device

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
    "id": 6,
    "method": "org.rdk.HdmiCecSource.performOTPAction"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.HdmiCecSource.performOTPAction"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="sendKeyPressEvent"></a>
## *sendKeyPressEvent*

Transmits a key press event to the specified HDMI CEC device with the given key code

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
    "id": 7,
    "method": "org.rdk.HdmiCecSource.sendKeyPressEvent",
    "params": {
        "logicalAddress": 1,
        "keyCode": 123
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.HdmiCecSource.sendKeyPressEvent", "params": {"logicalAddress": 1, "keyCode": 123}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="sendStandbyMessage"></a>
## *sendStandbyMessage*

Transmits a standby request to all devices on the CEC network

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
    "method": "org.rdk.HdmiCecSource.sendStandbyMessage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.HdmiCecSource.sendStandbyMessage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setEnabled"></a>
## *setEnabled*

Enables or disables the HDMI CEC source functionality

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the HDMI CEC source enabled or not |
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
    "method": "org.rdk.HdmiCecSource.setEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.HdmiCecSource.setEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setOSDName"></a>
## *setOSDName*

Configures the On-Screen Display (OSD) name for the HDMI CEC source device

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | string | OSD name of the HDMI CEC source |
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
    "method": "org.rdk.HdmiCecSource.setOSDName",
    "params": {
        "name": "My CEC Source"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.HdmiCecSource.setOSDName", "params": {"name": "My CEC Source"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setOTPEnabled"></a>
## *setOTPEnabled*

Enables or disables One-Touch Play (OTP) functionality for the HDMI CEC source

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Is the OTP enabled or not |
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
    "method": "org.rdk.HdmiCecSource.setOTPEnabled",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.HdmiCecSource.setOTPEnabled", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setVendorId"></a>
## *setVendorId*

Configures the vendor ID for the HDMI CEC source device

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.vendorid | string |  |
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
    "method": "org.rdk.HdmiCecSource.setVendorId",
    "params": {
        "vendorid": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.HdmiCecSource.setVendorId", "params": {"vendorid": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": true
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IHdmiCecSource-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IHdmiCecSource Interface:

| Event | Description |
| :-------- | :-------- |
| [onActiveSourceStatusUpdated](#onActiveSourceStatusUpdated) | Notifies when the active source status is updated |
| [onDeviceAdded](#onDeviceAdded) | Notifies when CEC device added to CEC network |
| [onDeviceInfoUpdated](#onDeviceInfoUpdated) | Notifies when CEC device info updated |
| [onDeviceRemoved](#onDeviceRemoved) | Notifies when CEC device removed from CEC network |
| [onKeyPressEvent](#onKeyPressEvent) | Notifies when a key press CEC message is received from other CEC device |
| [onKeyReleaseEvent](#onKeyReleaseEvent) | Notifies when a key release CEC message is received from other CEC device |
| [standbyMessageReceived](#standbyMessageReceived) | Notifies when CEC standby message received from the other CEC device |

<a id="onActiveSourceStatusUpdated"></a>
## *onActiveSourceStatusUpdated*

This event is triggered when the active source status changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | bool | Indicates whether the active source is active. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.HdmiCecSource.onActiveSourceStatusUpdated",
    "params": {
        "status": true
    }
}
```

<a id="onDeviceAdded"></a>
## *onDeviceAdded*

Notifies when CEC device added to CEC network

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.HdmiCecSource.onDeviceAdded",
    "params": {
        "logicalAddress": 1
    }
}
```

<a id="onDeviceInfoUpdated"></a>
## *onDeviceInfoUpdated*

Notifies when CEC device info updated

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the updated device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.HdmiCecSource.onDeviceInfoUpdated",
    "params": {
        "logicalAddress": 1
    }
}
```

<a id="onDeviceRemoved"></a>
## *onDeviceRemoved*

Notifies when CEC device removed from CEC network

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the removed device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.HdmiCecSource.onDeviceRemoved",
    "params": {
        "logicalAddress": 1
    }
}
```

<a id="onKeyPressEvent"></a>
## *onKeyPressEvent*

This event is triggered when a key press event is detected from a remote CEC device

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
    "id": 17,
    "method": "org.rdk.HdmiCecSource.onKeyPressEvent",
    "params": {
        "logicalAddress": 1,
        "keyCode": 123
    }
}
```

<a id="onKeyReleaseEvent"></a>
## *onKeyReleaseEvent*

This event is triggered when a key release event is detected from a remote CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.HdmiCecSource.onKeyReleaseEvent",
    "params": {
        "logicalAddress": 1
    }
}
```

<a id="standbyMessageReceived"></a>
## *standbyMessageReceived*

This event is triggered when a standby message is received from another CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.HdmiCecSource.standbyMessageReceived",
    "params": {
        "logicalAddress": 1
    }
}
```

