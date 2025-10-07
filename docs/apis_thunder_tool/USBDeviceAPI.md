<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_USBDevice_API"></a>
# USBDevice API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

USBDevice interface for Thunder framework.

(Defined with IUSBDevice in [IUSBDevice.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IUSBDevice.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the USBDevice interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

USBDevice JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the USBDevice interface:

USBDevice interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceList](#method_getDeviceList) | Get the basic information about list of devices connected with the system |
| [getDeviceInfo](#method_getDeviceInfo) | Get the extended USB device information for the provided device name |
| [bindDriver](#method_bindDriver) | Bind the respective driver for the device |
| [unbindDriver](#method_unbindDriver) | Unbind the respective driver for the device |

<a id="method_getDeviceList"></a>
## *getDeviceList [<sup>method</sup>](#head_Methods)*

Get the basic information about list of devices connected with the system.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | : List of USB devices along with basic info |
| result[#] | object | mandatory |  |
| result[#].deviceClass | integer | mandatory | USB class of the device as per USB specificiation |
| result[#].deviceSubclass | integer | mandatory | USB sub class of the device as per USB specificiation |
| result[#].deviceName | string | mandatory | Name of the USB device |
| result[#].devicePath | string | mandatory | The path to be used for the USB device ex: /dev/sdX |

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
  "result": [
    {
      "deviceClass": 0,
      "deviceSubclass": 0,
      "deviceName": "...",
      "devicePath": "..."
    }
  ]
}
```

<a id="method_getDeviceInfo"></a>
## *getDeviceInfo [<sup>method</sup>](#head_Methods)*

Get the extended USB device information for the provided device name.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.deviceName | string | mandatory | Device name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Detailed device information |
| result.parentId | integer | mandatory | Parent Node ID of the device |
| result.deviceStatus | integer | mandatory |  |
| result.deviceLevel | integer | mandatory | Device level |
| result.portNumber | integer | mandatory | Port number of USB on which the device is attached |
| result.vendorId | integer | mandatory | Vendor ID of the device |
| result.productId | integer | mandatory | Product ID of the device |
| result.protocol | integer | mandatory | Protocol supported by the device |
| result.serialNumber | string | mandatory | Serial number of the device |
| result.device | object | mandatory | Basic device information included |
| result.device.deviceClass | integer | mandatory | USB class of the device as per USB specificiation |
| result.device.deviceSubclass | integer | mandatory | USB sub class of the device as per USB specificiation |
| result.device.deviceName | string | mandatory | Name of the USB device |
| result.device.devicePath | string | mandatory | The path to be used for the USB device ex: /dev/sdX |
| result.flags | string | mandatory | Flags of the device (must be one of the following: *AVAILABLE, SWITCHABLE*) |
| result.features | integer | mandatory | Features supported by the device - reserved |
| result.busSpeed | string | mandatory | Speed of the device (must be one of the following: *Full, High, Low, Super*) |
| result.numLanguageIds | integer | mandatory | Number of language ids present on the device |
| result.productInfo1 | object | mandatory |  |
| result.productInfo1.languageId | integer | mandatory | Language id present on the device |
| result.productInfo1.serialNumber | string | mandatory | Unicode string representing the serial number of the device |
| result.productInfo1.manufacturer | string | mandatory | Unicode string representing the manufacturer of the device |
| result.productInfo1.product | string | mandatory | Unicode string representing the product |
| result.productInfo2 | object | mandatory |  |
| result.productInfo2.languageId | integer | mandatory | Language id present on the device |
| result.productInfo2.serialNumber | string | mandatory | Unicode string representing the serial number of the device |
| result.productInfo2.manufacturer | string | mandatory | Unicode string representing the manufacturer of the device |
| result.productInfo2.product | string | mandatory | Unicode string representing the product |
| result.productInfo3 | object | mandatory |  |
| result.productInfo3.languageId | integer | mandatory | Language id present on the device |
| result.productInfo3.serialNumber | string | mandatory | Unicode string representing the serial number of the device |
| result.productInfo3.manufacturer | string | mandatory | Unicode string representing the manufacturer of the device |
| result.productInfo3.product | string | mandatory | Unicode string representing the product |
| result.productInfo4 | object | mandatory |  |
| result.productInfo4.languageId | integer | mandatory | Language id present on the device |
| result.productInfo4.serialNumber | string | mandatory | Unicode string representing the serial number of the device |
| result.productInfo4.manufacturer | string | mandatory | Unicode string representing the manufacturer of the device |
| result.productInfo4.product | string | mandatory | Unicode string representing the product |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getDeviceInfo",
  "params": {
    "deviceName": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "parentId": 0,
    "deviceStatus": 0,
    "deviceLevel": 0,
    "portNumber": 0,
    "vendorId": 0,
    "productId": 0,
    "protocol": 0,
    "serialNumber": "...",
    "device": {
      "deviceClass": 0,
      "deviceSubclass": 0,
      "deviceName": "...",
      "devicePath": "..."
    },
    "flags": "SWITCHABLE",
    "features": 0,
    "busSpeed": "Full",
    "numLanguageIds": 0,
    "productInfo1": {
      "languageId": 0,
      "serialNumber": "...",
      "manufacturer": "...",
      "product": "..."
    },
    "productInfo2": {
      "languageId": 0,
      "serialNumber": "...",
      "manufacturer": "...",
      "product": "..."
    },
    "productInfo3": {
      "languageId": 0,
      "serialNumber": "...",
      "manufacturer": "...",
      "product": "..."
    },
    "productInfo4": {
      "languageId": 0,
      "serialNumber": "...",
      "manufacturer": "...",
      "product": "..."
    }
  }
}
```

<a id="method_bindDriver"></a>
## *bindDriver [<sup>method</sup>](#head_Methods)*

Bind the respective driver for the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.deviceName | string | mandatory | Name of the device |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.bindDriver",
  "params": {
    "deviceName": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_unbindDriver"></a>
## *unbindDriver [<sup>method</sup>](#head_Methods)*

Unbind the respective driver for the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.deviceName | string | mandatory | Name of the device |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.unbindDriver",
  "params": {
    "deviceName": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the USBDevice interface:

USBDevice interface events:

| Notification | Description |
| :-------- | :-------- |
| [onDevicePluggedIn](#notification_onDevicePluggedIn) | Device Plugged in notification |
| [onDevicePluggedOut](#notification_onDevicePluggedOut) | Device Plugged out notification |

<a id="notification_onDevicePluggedIn"></a>
## *onDevicePluggedIn [<sup>notification</sup>](#head_Notifications)*

Device Plugged in notification.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.device | object | mandatory |  |
| params.device.deviceClass | integer | mandatory | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | integer | mandatory | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | mandatory | Name of the USB device |
| params.device.devicePath | string | mandatory | The path to be used for the USB device ex: /dev/sdX |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDevicePluggedIn",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDevicePluggedIn",
  "params": {
    "device": {
      "deviceClass": 0,
      "deviceSubclass": 0,
      "deviceName": "...",
      "devicePath": "..."
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDevicePluggedIn``.

<a id="notification_onDevicePluggedOut"></a>
## *onDevicePluggedOut [<sup>notification</sup>](#head_Notifications)*

Device Plugged out notification.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.device | object | mandatory |  |
| params.device.deviceClass | integer | mandatory | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | integer | mandatory | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | mandatory | Name of the USB device |
| params.device.devicePath | string | mandatory | The path to be used for the USB device ex: /dev/sdX |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDevicePluggedOut",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDevicePluggedOut",
  "params": {
    "device": {
      "deviceClass": 0,
      "deviceSubclass": 0,
      "deviceName": "...",
      "devicePath": "..."
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDevicePluggedOut``.

