<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_HdmiCecSource_API"></a>
# HdmiCecSource API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

HdmiCecSource interface for Thunder framework.

(Defined with IHdmiCecSource in [IHdmiCecSource.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IHdmiCecSource.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the HdmiCecSource interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

HdmiCecSource JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the HdmiCecSource interface:

HdmiCecSource interface methods:

| Method | Description |
| :-------- | :-------- |
| [getActiveSourceStatus](#method_getActiveSourceStatus) | Gets the status if the device is the current active source |
| [getEnabled](#method_getEnabled) | Gets the status of the HDMI CEC source |
| [getOSDName](#method_getOSDName) | Gets the OSD name of the HDMI CEC source |
| [getOTPEnabled](#method_getOTPEnabled) | Gets the OTP enabled status of the HDMI CEC source |
| [getVendorId](#method_getVendorId) | Gets the vendor ID of the HDMI CEC source |
| [performOTPAction](#method_performOTPAction) | Performs the OTP action |
| [sendKeyPressEvent](#method_sendKeyPressEvent) | Sends a key press event to the HDMI CEC device |
| [sendStandbyMessage](#method_sendStandbyMessage) | Sends a standby message to another CEC device |
| [setEnabled](#method_setEnabled) | Sets the status of the HDMI CEC source |
| [setOSDName](#method_setOSDName) | Sets the OSD name of the HDMI CEC source |
| [setOTPEnabled](#method_setOTPEnabled) | Sets the OTP enabled status of the HDMI CEC source |
| [setVendorId](#method_setVendorId) | Sets the vendor ID of the HDMI CEC source |
| [getDeviceList](#method_getDeviceList) | Gets the list of devices connected to the HDMI CEC source |

<a id="method_getActiveSourceStatus"></a>
## *getActiveSourceStatus [<sup>method</sup>](#head_Methods)*

Gets the status if the device is the current active source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.status | boolean | mandatory | Is the active source active or not |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getActiveSourceStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "status": false,
    "success": false
  }
}
```

<a id="method_getEnabled"></a>
## *getEnabled [<sup>method</sup>](#head_Methods)*

Gets the status of the HDMI CEC source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.enabled | boolean | mandatory | Is the HDMI CEC source enabled or not |
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

Gets the OSD name of the HDMI CEC source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.name | string | mandatory | OSD name of the HDMI CEC source |
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

<a id="method_getOTPEnabled"></a>
## *getOTPEnabled [<sup>method</sup>](#head_Methods)*

Gets the OTP enabled status of the HDMI CEC source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.enabled | boolean | mandatory |  |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getOTPEnabled"
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

<a id="method_getVendorId"></a>
## *getVendorId [<sup>method</sup>](#head_Methods)*

Gets the vendor ID of the HDMI CEC source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.vendorid | string | mandatory |  |
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

<a id="method_performOTPAction"></a>
## *performOTPAction [<sup>method</sup>](#head_Methods)*

Performs the OTP action.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.performOTPAction"
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

Sends a key press event to the HDMI CEC device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |
| params.keyCode | integer | mandatory | Key code of the key press event |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
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

<a id="method_sendStandbyMessage"></a>
## *sendStandbyMessage [<sup>method</sup>](#head_Methods)*

Sends a standby message to another CEC device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
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

<a id="method_setEnabled"></a>
## *setEnabled [<sup>method</sup>](#head_Methods)*

Sets the status of the HDMI CEC source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the HDMI CEC source enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
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

<a id="method_setOSDName"></a>
## *setOSDName [<sup>method</sup>](#head_Methods)*

Sets the OSD name of the HDMI CEC source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.name | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
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

<a id="method_setOTPEnabled"></a>
## *setOTPEnabled [<sup>method</sup>](#head_Methods)*

Sets the OTP enabled status of the HDMI CEC source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Is the OTP enabled or not |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setOTPEnabled",
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

Sets the vendor ID of the HDMI CEC source.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.vendorid | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
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

<a id="method_getDeviceList"></a>
## *getDeviceList [<sup>method</sup>](#head_Methods)*

Gets the list of devices connected to the HDMI CEC source.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.numberofdevices | integer | mandatory | Number of devices connected to the HDMI CEC source |
| result.deviceList | array | mandatory | List of devices connected to the HDMI CEC source |
| result.deviceList[#] | object | mandatory |  |
| result.deviceList[#].logicalAddress | integer | mandatory |  |
| result.deviceList[#].vendorID | string | mandatory |  |
| result.deviceList[#].osdName | string | mandatory |  |
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
        "vendorID": "...",
        "osdName": "..."
      }
    ],
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HdmiCecSource interface:

HdmiCecSource interface events:

| Notification | Description |
| :-------- | :-------- |
| [onDeviceAdded](#notification_onDeviceAdded) | Notifies when CEC device added to CEC network |
| [onDeviceRemoved](#notification_onDeviceRemoved) | Notifies when CEC device removed from CEC network |
| [onDeviceInfoUpdated](#notification_onDeviceInfoUpdated) | Notifies when CEC device info updated |
| [onActiveSourceStatusUpdated](#notification_onActiveSourceStatusUpdated) | Notifies when the active source status is updated |
| [standbyMessageReceived](#notification_standbyMessageReceived) | Notifies when CEC standby message received from the other CEC device |
| [onKeyReleaseEvent](#notification_onKeyReleaseEvent) | Notifies when a key release CEC message is received from other CEC device |
| [onKeyPressEvent](#notification_onKeyPressEvent) | Notifies when a key press CEC message is received from other CEC device |

<a id="notification_onDeviceAdded"></a>
## *onDeviceAdded [<sup>notification</sup>](#head_Notifications)*

Notifies when CEC device added to CEC network.

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

<a id="notification_onDeviceRemoved"></a>
## *onDeviceRemoved [<sup>notification</sup>](#head_Notifications)*

Notifies when CEC device removed from CEC network.

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

<a id="notification_onDeviceInfoUpdated"></a>
## *onDeviceInfoUpdated [<sup>notification</sup>](#head_Notifications)*

Notifies when CEC device info updated.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory |  |

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

<a id="notification_onActiveSourceStatusUpdated"></a>
## *onActiveSourceStatusUpdated [<sup>notification</sup>](#head_Notifications)*

Notifies when the active source status is updated.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.status | boolean | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onActiveSourceStatusUpdated",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onActiveSourceStatusUpdated",
  "params": {
    "status": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onActiveSourceStatusUpdated``.

<a id="notification_standbyMessageReceived"></a>
## *standbyMessageReceived [<sup>notification</sup>](#head_Notifications)*

Notifies when CEC standby message received from the other CEC device.

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

<a id="notification_onKeyReleaseEvent"></a>
## *onKeyReleaseEvent [<sup>notification</sup>](#head_Notifications)*

Notifies when a key release CEC message is received from other CEC device.

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
    "event": "onKeyReleaseEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onKeyReleaseEvent",
  "params": {
    "logicalAddress": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onKeyReleaseEvent``.

<a id="notification_onKeyPressEvent"></a>
## *onKeyPressEvent [<sup>notification</sup>](#head_Notifications)*

Notifies when a key press CEC message is received from other CEC device.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.logicalAddress | integer | mandatory | Logical address of the device |
| params.keyCode | integer | mandatory | Key code of the key press event |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onKeyPressEvent",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onKeyPressEvent",
  "params": {
    "logicalAddress": 0,
    "keyCode": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onKeyPressEvent``.

