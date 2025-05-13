<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IUSBDevice_Plugin"></a>
# IUSBDevice Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IUSBDevice/CHANGELOG.md)**

A IUSBDevice plugin for Thunder framework.

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

The `IUSBDevice` plugin provides an interface for IUSBDevice.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IUSBDevice*) |
| classname | string | Class name: *IUSBDevice* |
| locator | string | Library name: *libWPEFrameworkIUSBDevice.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IUSBDevice plugin:

IUSBDevice interface methods:

| Method | Description |
| :-------- | :-------- |
| [BindDriver](#method.BindDriver) | Bind the respective driver for the device |
| [GetDeviceInfo](#method.GetDeviceInfo) | Get the extended USB device information for the provided device name |
| [GetDeviceList](#method.GetDeviceList) | Get the basic information about list of devices connected with the system. |
| [UnbindDriver](#method.UnbindDriver) | Unbind the respective driver for the device |

<a id="method.BindDriver"></a>
## *BindDriver [<sup>method</sup>](#head.Methods)*

Bind the respective driver for the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceName | string | Name of the USB device |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.BindDriver",
    "params": {
        "deviceName": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetDeviceInfo"></a>
## *GetDeviceInfo [<sup>method</sup>](#head.Methods)*

Get the extended USB device information for the provided device name

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceName | string | Name of the USB device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.deviceInfo | USBDeviceInfo | Detailed device information |
| result.deviceInfo.parentId | uint32_t | Parent Node ID of the device |
| result.deviceInfo.deviceStatus | uint8_t | current device status |
| result.deviceInfo.deviceLevel | uint8_t | device level |
| result.deviceInfo.portNumber | uint8_t | port number of USB on which the device is attached |
| result.deviceInfo.vendorId | uint16_t | Vendor ID of the device |
| result.deviceInfo.productId | uint16_t | Product ID of the device |
| result.deviceInfo.protocol | uint8_t | Protocol supported by the device |
| result.deviceInfo.serialNumber | string | Serial number of the device |
| result.deviceInfo.device | USBDevice | Basic device information included |
| result.deviceInfo.device.deviceClass | uint8_t | USB class of the device as per USB specificiation |
| result.deviceInfo.device.deviceSubclass | uint8_t | USB sub class of the device as per USB specificiation |
| result.deviceInfo.device.deviceName | string | Name of the USB device |
| result.deviceInfo.device.devicePath | string | the path to be used for the USB device  |
| result.deviceInfo.flags | USBDeviceFlags | Flags of the device |
| result.deviceInfo.features | uint32_t | Features supported by the device - reserved |
| result.deviceInfo.busSpeed | USBDeviceSpeed | Speed of the device |
| result.deviceInfo.numLanguageIds | uint8_t | number of language ids present on the device |
| result.deviceInfo.productInfo1 | USBProductInfo |  |
| result.deviceInfo.productInfo1.languageId | uint16_t | language id present on the device |
| result.deviceInfo.productInfo1.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo1.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo1.product | string | unicode string representing the product |
| result.deviceInfo.productInfo2 | USBProductInfo |  |
| result.deviceInfo.productInfo2.languageId | uint16_t | language id present on the device |
| result.deviceInfo.productInfo2.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo2.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo2.product | string | unicode string representing the product |
| result.deviceInfo.productInfo3 | USBProductInfo |  |
| result.deviceInfo.productInfo3.languageId | uint16_t | language id present on the device |
| result.deviceInfo.productInfo3.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo3.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo3.product | string | unicode string representing the product |
| result.deviceInfo.productInfo4 | USBProductInfo |  |
| result.deviceInfo.productInfo4.languageId | uint16_t | language id present on the device |
| result.deviceInfo.productInfo4.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo4.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo4.product | string | unicode string representing the product |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.GetDeviceInfo",
    "params": {
        "deviceName": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "deviceInfo": {
            "parentId": "0",
            "deviceStatus": "",
            "deviceLevel": "",
            "portNumber": "",
            "vendorId": "",
            "productId": "",
            "protocol": "",
            "serialNumber": "",
            "device": {
                "deviceClass": "",
                "deviceSubclass": "",
                "deviceName": "",
                "devicePath": "/dev/sdX"
            },
            "flags": "DEVICE_FLAGS_DRIVER_AVAILABLE",
            "features": "0",
            "busSpeed": "DEVICE_SPEED_LOW",
            "numLanguageIds": "",
            "productInfo1": {
                "languageId": "",
                "serialNumber": "",
                "manufacturer": "",
                "product": ""
            },
            "productInfo2": {
                "languageId": "",
                "serialNumber": "",
                "manufacturer": "",
                "product": ""
            },
            "productInfo3": {
                "languageId": "",
                "serialNumber": "",
                "manufacturer": "",
                "product": ""
            },
            "productInfo4": {
                "languageId": "",
                "serialNumber": "",
                "manufacturer": "",
                "product": ""
            }
        }
    }
}
```
<a id="method.GetDeviceList"></a>
## *GetDeviceList [<sup>method</sup>](#head.Methods)*

Get the basic information about list of devices connected with the system.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.devices | IUSBDeviceIterator | List of USB devices along with basic info. |
| result.devices[#].deviceClass | uint8_t | USB class of the device as per USB specificiation |
| result.devices[#].deviceSubclass | uint8_t | USB sub class of the device as per USB specificiation |
| result.devices[#].deviceName | string | Name of the USB device |
| result.devices[#].devicePath | string | the path to be used for the USB device  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.GetDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "devices": [
            {
                "deviceClass": "",
                "deviceSubclass": "",
                "deviceName": "",
                "devicePath": "/dev/sdX"
            }
        ]
    }
}
```
<a id="method.UnbindDriver"></a>
## *UnbindDriver [<sup>method</sup>](#head.Methods)*

Unbind the respective driver for the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.deviceName | string | Name of the USB device |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.UnbindDriver",
    "params": {
        "deviceName": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IUSBDevice plugin:

IUSBDevice interface events:

| Method | Description |
| :-------- | :-------- |
| [OnDevicePluggedIn](#event.OnDevicePluggedIn) | Device Plugged in notification |
| [OnDevicePluggedOut](#event.OnDevicePluggedOut) | Device Plugged out notification |

<a id="event.OnDevicePluggedIn"></a>
## *OnDevicePluggedIn [<sup>event</sup>](#head.Notifications)*

Device Plugged in notification

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.device | USBDevice | Basic device information included |
| params.device.deviceClass | uint8_t | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | uint8_t | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | the path to be used for the USB device  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.OnDevicePluggedIn",
    "params": {
        "device": {
            "deviceClass": "",
            "deviceSubclass": "",
            "deviceName": "",
            "devicePath": "/dev/sdX"
        }
    }
}
```
<a id="event.OnDevicePluggedOut"></a>
## *OnDevicePluggedOut [<sup>event</sup>](#head.Notifications)*

Device Plugged out notification

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.device | USBDevice | Basic device information included |
| params.device.deviceClass | uint8_t | USB class of the device as per USB specificiation |
| params.device.deviceSubclass | uint8_t | USB sub class of the device as per USB specificiation |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | the path to be used for the USB device  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUSBDevice.OnDevicePluggedOut",
    "params": {
        "device": {
            "deviceClass": "",
            "deviceSubclass": "",
            "deviceName": "",
            "devicePath": "/dev/sdX"
        }
    }
}
```