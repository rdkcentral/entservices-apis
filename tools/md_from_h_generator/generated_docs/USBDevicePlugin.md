<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.USBDevice_Plugin"></a>
# USBDevice Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/USBDevice/CHANGELOG.md)**

A USBDevice plugin for Thunder framework.

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

The `USBDevice` plugin provides an interface for USBDevice.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.USBDevice) |
| classname | string | Class name: *USBDevice* |
| locator | string | Library name: *libWPEFrameworkUSBDevice.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the USBDevice plugin:

USBDevice interface methods:

| Method | Description |
| :-------- | :-------- |
| [bindDriver](#method.bindDriver) | Bind the respective driver for the device |
| [getDeviceInfo](#method.getDeviceInfo) | Get the extended USB device information for the provided device name |
| [getDeviceList](#method.getDeviceList) | Get the basic information about list of devices connected with the system. |
| [unbindDriver](#method.unbindDriver) | Unbind the respective driver for the device |

<a id="method.bindDriver"></a>
## *bindDriver [<sup>method</sup>](#head.Methods)*

Bind the respective driver for the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the USB device |
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
        "deviceName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.USBDevice.bindDriver", "params": {"deviceName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.getDeviceInfo"></a>
## *getDeviceInfo [<sup>method</sup>](#head.Methods)*

Get the extended USB device information for the provided device name

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the USB device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.deviceInfo | USBDeviceInfo | Detailed device information |
| result.deviceInfo.parentId | integer | Parent Node ID of the device |
| result.deviceInfo.deviceStatus | integer | current device status |
| result.deviceInfo.deviceLevel | integer | device level |
| result.deviceInfo.portNumber | integer | port number of USB on which the device is attached |
| result.deviceInfo.vendorId | integer | Vendor ID of the device |
| result.deviceInfo.productId | integer | Product ID of the device |
| result.deviceInfo.protocol | integer | Protocol supported by the device |
| result.deviceInfo.serialNumber | string | Serial number of the device |
| result.deviceInfo.device | USBDevice | Basic device information included |
| result.deviceInfo.device.deviceClass | integer | USB class of the device as per USB specificiation |
| result.deviceInfo.device.deviceSubclass | integer | USB sub class of the device as per USB specificiation |
| result.deviceInfo.device.deviceName | string | Name of the USB device |
| result.deviceInfo.device.devicePath | string | the path to be used for the USB device  |
| result.deviceInfo.flags | string | Flags of the device |
| result.deviceInfo.features | integer | Features supported by the device - reserved |
| result.deviceInfo.busSpeed | string | Speed of the device |
| result.deviceInfo.numLanguageIds | integer | number of language ids present on the device |
| result.deviceInfo.productInfo1 | USBProductInfo |  |
| result.deviceInfo.productInfo1.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo1.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo1.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo1.product | string | unicode string representing the product |
| result.deviceInfo.productInfo2 | USBProductInfo |  |
| result.deviceInfo.productInfo2.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo2.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo2.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo2.product | string | unicode string representing the product |
| result.deviceInfo.productInfo3 | USBProductInfo |  |
| result.deviceInfo.productInfo3.languageId | integer | language id present on the device |
| result.deviceInfo.productInfo3.serialNumber | string | unicode string representing the serial number of the device |
| result.deviceInfo.productInfo3.manufacturer | string | unicode string representing the manufacturer of the device |
| result.deviceInfo.productInfo3.product | string | unicode string representing the product |
| result.deviceInfo.productInfo4 | USBProductInfo |  |
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
        "deviceName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.USBDevice.getDeviceInfo", "params": {"deviceName": ""}}' http://127.0.0.1:9998/jsonrpc
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
        "flags": "DEVICE_FLAGS_DRIVER_AVAILABLE",
        "features": 0,
        "busSpeed": "DEVICE_SPEED_LOW",
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

<a id="method.getDeviceList"></a>
## *getDeviceList [<sup>method</sup>](#head.Methods)*

Get the basic information about list of devices connected with the system.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.devices | IUSBDeviceIterator | List of USB devices along with basic info. |
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
        {
            "deviceClass": 0,
            "deviceSubclass": 0,
            "deviceName": "",
            "devicePath": ""
        }
    ]
}
```

<a id="method.unbindDriver"></a>
## *unbindDriver [<sup>method</sup>](#head.Methods)*

Unbind the respective driver for the device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.deviceName | string | Name of the USB device |
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
        "deviceName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.USBDevice.unbindDriver", "params": {"deviceName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the USBDevice plugin:

USBDevice interface events:

| Event | Description |
| :-------- | :-------- |
| [onDevicePluggedIn](#event.onDevicePluggedIn) | Device Plugged in notification |
| [onDevicePluggedOut](#event.onDevicePluggedOut) | Device Plugged out notification |

<a id="event.onDevicePluggedIn"></a>
## *onDevicePluggedIn [<sup>event</sup>](#head.Notifications)*

Device Plugged in notification

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | USBDevice | Basic device information included |
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
        "deviceClass": 0,
        "deviceSubclass": 0,
        "deviceName": "",
        "devicePath": ""
    }
}
```

<a id="event.onDevicePluggedOut"></a>
## *onDevicePluggedOut [<sup>event</sup>](#head.Notifications)*

Device Plugged out notification

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.device | USBDevice | Basic device information included |
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
        "deviceClass": 0,
        "deviceSubclass": 0,
        "deviceName": "",
        "devicePath": ""
    }
}
```
