<!-- Generated automatically, DO NOT EDIT! -->
<a id="USBDevice_Module"></a>
# USBDevice Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/USBDevice/IUSBDevice.h)**

A USBDevice module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IUSBDevice](#IUSBDevice)
    - [Methods](#IUSBDevice-Methods)
    - [Notifications](#IUSBDevice-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `USBDevice` module provides the following interface(s):

- IUSBDevice

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.USBDevice) |
| classname | string | Class name: *USBDevice* |
| locator | string | Library name: *libWPEFrameworkUSBDevice.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IUSBDevice"></a>
## IUSBDevice Interface

<a id="IUSBDevice-Methods"></a>
### Methods

The following methods are provided by the IUSBDevice Interface:

| Method | Description |
| :-------- | :-------- |
| [bindDriver](#bindDriver) | Bind the respective driver for the device |
| [getDeviceInfo](#getDeviceInfo) | Get the extended USB device information for the provided device name |
| [getDeviceList](#getDeviceList) | Get the basic information about list of devices connected with the system. |
| [unbindDriver](#unbindDriver) | Unbind the respective driver for the device |

<a id="bindDriver"></a>
## *bindDriver*

Associates the appropriate driver with the specified USB device. This operation enables driver functionality for devices that support dynamic driver binding.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the device |
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
    "method": "org.rdk.USBDevice.bindDriver",
    "params": {
        "deviceName": "USB Serial Adapter"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.USBDevice.bindDriver", "params": {"deviceName": "USB Serial Adapter"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "- Failed to bind the driver."
    }
}
```

<a id="getDeviceInfo"></a>
## *getDeviceInfo*

Retrieves detailed information about a USB device including vendor ID, product ID, device status, bus speed, serial number, supported features, and product information strings.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | device name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.deviceInfo | object | Detailed device information |
| result.deviceInfo.parentId | integer | Parent Node ID of the device |
| result.deviceInfo.deviceStatus | integer | current device status |
| result.deviceInfo.deviceLevel | integer | device level |
| result.deviceInfo.portNumber | integer | port number of USB on which the device is attached |
| result.deviceInfo.vendorId | integer | Vendor ID of the device |
| result.deviceInfo.productId | integer | Product ID of the device |
| result.deviceInfo.protocol | integer | Protocol supported by the device |
| result.deviceInfo.serialNumber | string | Serial number of the device |
| result.deviceInfo.device | object | Basic device information included |
| result.deviceInfo.device.deviceClass | integer | USB class of the device as per USB specificiation |
| result.deviceInfo.device.deviceSubclass | integer | USB sub class of the device as per USB specificiation |
| result.deviceInfo.device.deviceName | string | Name of the USB device |
| result.deviceInfo.device.devicePath | string | the path to be used for the USB device  |
| result.deviceInfo.flags | string | Flags of the device. Possible values: AVAILABLE, SWITCHABLE |
| result.deviceInfo.features | integer | Features supported by the device - reserved |
| result.deviceInfo.busSpeed | string | Speed of the device. Possible values: Low, Full, High, Super |
| result.deviceInfo.numLanguageIds | integer | number of language ids present on the device |
| result.deviceInfo.productInfo1 | object |  |
| result.deviceInfo.productInfo1.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo1.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo1.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo1.product | string | unicode string representing the product |
| result.deviceInfo.productInfo2 | object |  |
| result.deviceInfo.productInfo2.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo2.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo2.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo2.product | string | unicode string representing the product |
| result.deviceInfo.productInfo3 | object |  |
| result.deviceInfo.productInfo3.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo3.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo3.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo3.product | string | unicode string representing the product |
| result.deviceInfo.productInfo4 | object |  |
| result.deviceInfo.productInfo4.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo4.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo4.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo4.product | string | unicode string representing the product |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.USBDevice.getDeviceInfo",
    "params": {
        "deviceName": "USB Serial Adapter"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.USBDevice.getDeviceInfo", "params": {"deviceName": "USB Serial Adapter"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "parentId": 0,
        "deviceStatus": 0,
        "deviceLevel": 0,
        "portNumber": 0,
        "vendorId": 0,
        "productId": 0,
        "protocol": 0,
        "serialNumber": "",
        "device": {
            "deviceClass": 0,
            "deviceSubclass": 0,
            "deviceName": "",
            "devicePath": ""
        },
        "flags": "AVAILABLE",
        "features": 0,
        "busSpeed": "Low",
        "numLanguageIds": 0,
        "productInfo1": {
            "languageId": 0,
            "serialNumber": "",
            "manufacturer": "",
            "product": ""
        },
        "productInfo2": {
            "languageId": 0,
            "serialNumber": "",
            "manufacturer": "",
            "product": ""
        },
        "productInfo3": {
            "languageId": 0,
            "serialNumber": "",
            "manufacturer": "",
            "product": ""
        },
        "productInfo4": {
            "languageId": 0,
            "serialNumber": "",
            "manufacturer": "",
            "product": ""
        }
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
        "message": "- Failed to retrieve device information."
    }
}
```

<a id="getDeviceList"></a>
## *getDeviceList*

Retrieves a list of USB devices currently connected to the device. Each entry contains basic device information such as device name, class, subclass, and device path.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.devices | array | List of USB devices along with basic info. |
| result.devices[#].deviceClass | integer | USB class of the device as per USB specificiation |
| result.devices[#].deviceSubclass | integer | USB sub class of the device as per USB specificiation |
| result.devices[#].deviceName | string | Name of the USB device |
| result.devices[#].devicePath | string | the path to be used for the USB device  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.USBDevice.getDeviceList"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.USBDevice.getDeviceList"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": [
        "USB Flash Drive"
    ]
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve the device list."
    }
}
```

<a id="unbindDriver"></a>
## *unbindDriver*

Detaches the currently associated driver from the specified USB device. This operation is typically used before switching drivers or disabling device functionality.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the device |
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
    "method": "org.rdk.USBDevice.unbindDriver",
    "params": {
        "deviceName": "USB Serial Adapter"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.USBDevice.unbindDriver", "params": {"deviceName": "USB Serial Adapter"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "- Failed to unbind the driver."
    }
}
```

<a id="IUSBDevice-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IUSBDevice Interface:

| Event | Description |
| :-------- | :-------- |
| [onDevicePluggedIn](#onDevicePluggedIn) | Device Plugged in notification |
| [onDevicePluggedOut](#onDevicePluggedOut) | Device Plugged out notification |

<a id="onDevicePluggedIn"></a>
## *onDevicePluggedIn*

Triggered when a USB device is connected to the system and successfully detected by the USB subsystem. The event provides basic information about the newly connected device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | object | Basic device information included |
| params.device.deviceClass | integer | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | integer | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | the path to be used for the USB device  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.USBDevice.onDevicePluggedIn",
    "params": {
        "deviceName": "USB Flash Drive"
    }
}
```

<a id="onDevicePluggedOut"></a>
## *onDevicePluggedOut*

Triggered when a USB device is disconnected from the system. The event provides basic information about the disconnected device.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | object | Basic device information included |
| params.device.deviceClass | integer | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | integer | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | the path to be used for the USB device  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.USBDevice.onDevicePluggedOut",
    "params": {
        "deviceName": "USB Flash Drive"
    }
}
```

