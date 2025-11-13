<!-- Generated automatically, DO NOT EDIT! -->
<a name="USBDevice_Plugin"></a>
# USBDevice Plugin

A org.rdk.UsbDevice plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `USBDevice`Plugin is responsible for notifying and providing information about USB devices attached to the host system.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.UsbDevice*) |
| classname | string | Class name: *org.rdk.UsbDevice* |
| locator | string | Library name: *libWPEFrameworkUSBDevice.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.UsbDevice plugin:

org.rdk.UsbDevice interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceList](#getDeviceList) | Gets the device information of the connected USB Devices |
| [getDeviceInfo](#getDeviceInfo) | Gets detailed device information for the given device name |
| [bindDriver](#bindDriver) | Binds the respective driver for the device |
| [unbindDriver](#unbindDriver) | Unbinds the respective driver for the device |


<a name="getDeviceList"></a>
## *getDeviceList*

Gets the device information of the connected USB Devices.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array |  |
| result[#] | object |  |
| result[#].deviceClass | integer | USB class of the device |
| result[#].deviceSubclass | integer | USB Sub class of the device |
| result[#].deviceName | string | Name of the USB device |
| result[#].devicePath | string | The path to be used for the USB device |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbDevice.getDeviceList"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "deviceClass": 8,
            "deviceSubclass": 6,
            "deviceName": "001/006",
            "devicePath": "/dev/sda"
        }
    ]
}
```

<a name="getDeviceInfo"></a>
## *getDeviceInfo*

Gets detailed device information for the given device name.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Get the extended USB device information for the provided device name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.parentId | integer | Parent Node ID of the device |
| result.deviceStatus | integer | Current device status |
| result.deviceLevel | integer | Device level |
| result.portNumber | integer | Port number of USB on which the device is attached |
| result.vendorId | integer | Vendor ID of the device |
| result.productid | integer | Product ID of the device |
| result.protocol | integer | Protocol supported by the device |
| result.serialnumber | string | Serial number of the device |
| result.device | object |  |
| result.device.deviceClass | integer | USB class of the device |
| result.device.deviceSubclass | integer | USB Sub class of the device |
| result.device.deviceName | string | Name of the USB device |
| result.device.devicePath | string | The path to be used for the USB device |
| result.flags | string | Flags of the device |
| result?.features | integer | <sup>*(optional)*</sup> Features supported by the device - reserved |
| result.busSpeed | string | Speed of the device |
| result?.numLanguageIds | integer | <sup>*(optional)*</sup> Number of language IDs present on the device |
| result?.productInfo1 | object | <sup>*(optional)*</sup>  |
| result?.productInfo1.languageId | integer | Language ID present on the device |
| result?.productInfo1.serialNumber | string | Unicode string representing the serial number of the device |
| result?.productInfo1.manufacturer | string | Unicode string representing the manufacturer of the device |
| result?.productInfo1.product | string | Unicode string representing the product |
| result?.productInfo2 | object | <sup>*(optional)*</sup>  |
| result?.productInfo2.languageId | integer | Language ID present on the device |
| result?.productInfo2.serialNumber | string | Unicode string representing the serial number of the device |
| result?.productInfo2.manufacturer | string | Unicode string representing the manufacturer of the device |
| result?.productInfo2.product | string | Unicode string representing the product |
| result?.productInfo3 | object | <sup>*(optional)*</sup>  |
| result?.productInfo3.languageId | integer | Language ID present on the device |
| result?.productInfo3.serialNumber | string | Unicode string representing the serial number of the device |
| result?.productInfo3.manufacturer | string | Unicode string representing the manufacturer of the device |
| result?.productInfo3.product | string | Unicode string representing the product |
| result?.productInfo4 | object | <sup>*(optional)*</sup>  |
| result?.productInfo4.languageId | integer | Language ID present on the device |
| result?.productInfo4.serialNumber | string | Unicode string representing the serial number of the device |
| result?.productInfo4.manufacturer | string | Unicode string representing the manufacturer of the device |
| result?.productInfo4.product | string | Unicode string representing the product |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbDevice.getDeviceInfo",
    "params": {
        "deviceName": "001/012"
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
        "deviceStatus": 1,
        "deviceLevel": 1,
        "portNumber": 1,
        "vendorId": 1921,
        "productid": 21889,
        "protocol": 0,
        "serialnumber": "4C530000120309105565",
        "device": {
            "deviceClass": 8,
            "deviceSubclass": 6,
            "deviceName": "001/006",
            "devicePath": "/dev/sda"
        },
        "flags": "AVAILABLE",
        "features": 0,
        "busSpeed": "Super",
        "numLanguageIds": 1,
        "productInfo1": {
            "languageId": 1033,
            "serialNumber": "04011a1ac241414372e459026efb4429e88c8b51d9f5d101fb0c73505a872c1cc9ae0000000000000000000020c9773500885a1881558107882f26a7",
            "manufacturer": "USB",
            "product": "SanDisk 3.2Gen1"
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

<a name="bindDriver"></a>
## *bindDriver*

Binds the respective driver for the device.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the device |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbDevice.bindDriver",
    "params": {
        "deviceName": "001/012"
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

<a name="unbindDriver"></a>
## *unbindDriver*

Unbinds the respective driver for the device.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the device |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UsbDevice.unbindDriver",
    "params": {
        "deviceName": "001/012"
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

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.UsbDevice plugin:

org.rdk.UsbDevice interface events:

| Event | Description |
| :-------- | :-------- |
| [onDevicePluggedIn](#onDevicePluggedIn) | Device Plugged in notification |
| [onDevicePluggedOut](#onDevicePluggedOut) | Device Plugged out notification |


<a name="onDevicePluggedIn"></a>
## *onDevicePluggedIn*

Device Plugged in notification.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | object |  |
| params.device.deviceClass | integer | USB class of the device |
| params.device.deviceSubclass | integer | USB Sub class of the device |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | The path to be used for the USB device |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDevicePluggedIn",
    "params": {
        "device": {
            "deviceClass": 8,
            "deviceSubclass": 6,
            "deviceName": "001/006",
            "devicePath": "/dev/sda"
        }
    }
}
```

<a name="onDevicePluggedOut"></a>
## *onDevicePluggedOut*

Device Plugged out notification.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | object |  |
| params.device.deviceClass | integer | USB class of the device |
| params.device.deviceSubclass | integer | USB Sub class of the device |
| params.device.deviceName | string | Name of the USB device |
| params.device.devicePath | string | The path to be used for the USB device |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDevicePluggedOut",
    "params": {
        "device": {
            "deviceClass": 8,
            "deviceSubclass": 6,
            "deviceName": "001/006",
            "devicePath": "/dev/sda"
        }
    }
}
```

