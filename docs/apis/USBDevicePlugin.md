<!-- Generated automatically, DO NOT EDIT! -->
<a name="USBDevice_Plugin"></a>
# USBDevice Plugin

**Version: [1.0.0]()**

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

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.devices | array | An array of USBDevice |
| result.devices[#] | object |  |
| result.devices[#].deviceClass | integer | USB class of the device |
| result.devices[#].deviceSubclass | integer | USB Sub class of the device |
| result.devices[#].deviceName | string | Name of the USB device |
| result.devices[#].devicePath | string | The path to be used for the USB device |

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
    "method": "org.rdk.UsbDevice.getDeviceList",
    "params": {}
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
                "deviceClass": 8,
                "deviceSubclass": 6,
                "deviceName": "001/003",
                "devicePath": "/dev/sdb"
            }
        ]
    }
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
| result.deviceInfo | array | An array of USBDeviceInfo |
| result.deviceInfo[#] | object |  |
| result.deviceInfo[#].parentId | integer | Parent Node ID of the device |
| result.deviceInfo[#].deviceStatus | integer | Current device status |
| result.deviceInfo[#].deviceLevel | integer | Device level |
| result.deviceInfo[#].portNumber | integer | Port number of USB on which the device is attached |
| result.deviceInfo[#].vendorId | integer | Vendor ID of the device |
| result.deviceInfo[#].productid | integer | Product ID of the device |
| result.deviceInfo[#].protocol | integer | Protocol supported by the device |
| result.deviceInfo[#].serialnumber | string | Serial number of the device |
| result.deviceInfo[#].device | object |  |
| result.deviceInfo[#].device.deviceClass | integer | USB class of the device |
| result.deviceInfo[#].device.deviceSubclass | integer | USB Sub class of the device |
| result.deviceInfo[#].device.deviceName | string | Name of the USB device |
| result.deviceInfo[#].device.devicePath | string | The path to be used for the USB device |
| result.deviceInfo[#].flags | string | Flags of the device |
| result.deviceInfo[#]?.features | integer | <sup>*(optional)*</sup> Features supported by the device - reserved |
| result.deviceInfo[#].busSpeed | string | Speed of the device |
| result.deviceInfo[#]?.numLanguageIds | integer | <sup>*(optional)*</sup> Number of language IDs present on the device |
| result.deviceInfo[#]?.productInfo1 | object | <sup>*(optional)*</sup>  |
| result.deviceInfo[#]?.productInfo1?.languageId | integer | <sup>*(optional)*</sup> Language ID present on the device |
| result.deviceInfo[#]?.productInfo1?.serialNumber | string | <sup>*(optional)*</sup> Unicode string representing the serial number of the device |
| result.deviceInfo[#]?.productInfo1?.manufacturer | string | <sup>*(optional)*</sup> Unicode string representing the manufacturer of the device |
| result.deviceInfo[#]?.productInfo1?.product | string | <sup>*(optional)*</sup> Unicode string representing the product |
| result.deviceInfo[#]?.productInfo2 | object | <sup>*(optional)*</sup>  |
| result.deviceInfo[#]?.productInfo2?.languageId | integer | <sup>*(optional)*</sup> Language ID present on the device |
| result.deviceInfo[#]?.productInfo2?.serialNumber | string | <sup>*(optional)*</sup> Unicode string representing the serial number of the device |
| result.deviceInfo[#]?.productInfo2?.manufacturer | string | <sup>*(optional)*</sup> Unicode string representing the manufacturer of the device |
| result.deviceInfo[#]?.productInfo2?.product | string | <sup>*(optional)*</sup> Unicode string representing the product |
| result.deviceInfo[#]?.productInfo3 | object | <sup>*(optional)*</sup>  |
| result.deviceInfo[#]?.productInfo3?.languageId | integer | <sup>*(optional)*</sup> Language ID present on the device |
| result.deviceInfo[#]?.productInfo3?.serialNumber | string | <sup>*(optional)*</sup> Unicode string representing the serial number of the device |
| result.deviceInfo[#]?.productInfo3?.manufacturer | string | <sup>*(optional)*</sup> Unicode string representing the manufacturer of the device |
| result.deviceInfo[#]?.productInfo3?.product | string | <sup>*(optional)*</sup> Unicode string representing the product |
| result.deviceInfo[#]?.productInfo4 | object | <sup>*(optional)*</sup>  |
| result.deviceInfo[#]?.productInfo4?.languageId | integer | <sup>*(optional)*</sup> Language ID present on the device |
| result.deviceInfo[#]?.productInfo4?.serialNumber | string | <sup>*(optional)*</sup> Unicode string representing the serial number of the device |
| result.deviceInfo[#]?.productInfo4?.manufacturer | string | <sup>*(optional)*</sup> Unicode string representing the manufacturer of the device |
| result.deviceInfo[#]?.productInfo4?.product | string | <sup>*(optional)*</sup> Unicode string representing the product |

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
        "deviceInfo": [
            {
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
                    "deviceName": "001/003",
                    "devicePath": "/dev/sdb"
                },
                "flags": "AVAILABLE",
                "features": 0,
                "busSpeed": "Super",
                "numLanguageIds": 2,
                "productInfo1": {
                    "languageId": 10,
                    "serialNumber": "B32FD507",
                    "manufacturer": "Alcor Micro Corp",
                    "product": "Flash Drive"
                },
                "productInfo2": {
                    "languageId": 10,
                    "serialNumber": "B32FD507",
                    "manufacturer": "Alcor Micro Corp",
                    "product": "Flash Drive"
                },
                "productInfo3": {
                    "languageId": 10,
                    "serialNumber": "B32FD507",
                    "manufacturer": "Alcor Micro Corp",
                    "product": "Flash Drive"
                },
                "productInfo4": {
                    "languageId": 10,
                    "serialNumber": "B32FD507",
                    "manufacturer": "Alcor Micro Corp",
                    "product": "Flash Drive"
                }
            }
        ]
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
| result | string | On success null will be returned |

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
    "result": "null"
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
| result | string | On success null will be returned |

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
    "result": "null"
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
            "deviceName": "001/003",
            "devicePath": "/dev/sdb"
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
            "deviceName": "001/003",
            "devicePath": "/dev/sdb"
        }
    }
}
```

