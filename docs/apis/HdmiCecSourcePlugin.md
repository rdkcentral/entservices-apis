<!-- Generated automatically, DO NOT EDIT! -->
<a id="HdmiCecSource_Plugin"></a>
# HdmiCecSource Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HdmiCecSource)**

A HdmiCecSource plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `HdmiCecSource` plugin provides an interface for HdmiCecSource.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdmiCecSource) |
| classname | string | Class name: *HdmiCecSource* |
| locator | string | Library name: *libWPEFrameworkHdmiCecSource.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the HdmiCecSource plugin:

HdmiCecSource interface methods:

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

Gets the status if the device is the current active source

### Events
Event details are missing in the header file documentation.
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

<a id="getDeviceList"></a>
## *getDeviceList*

Gets the list of devices connected to the HDMI CEC source

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.numberofdevices | integer | Number of devices connected to the HDMI CEC source |
| result.deviceList | IHdmiCecSourceDeviceListIterator | List of devices connected to the HDMI CEC source |
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
        "numberofdevices": 0,
        "deviceList": [
            {
                "logicalAddress": 0,
                "vendorID": "",
                "osdName": ""
            }
        ],
        "success": true
    }
}
```

<a id="getEnabled"></a>
## *getEnabled*

Gets the status of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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

<a id="getOSDName"></a>
## *getOSDName*

Gets the OSD name of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
        "name": "",
        "success": true
    }
}
```

<a id="getOTPEnabled"></a>
## *getOTPEnabled*

Gets the OTP enabled status of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
        "enabled": true,
        "success": true
    }
}
```

<a id="getVendorId"></a>
## *getVendorId*

Gets the vendor ID of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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

<a id="performOTPAction"></a>
## *performOTPAction*

Performs the OTP action

### Events
Event details are missing in the header file documentation.
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
    "result": {
        "success": true
    }
}
```

<a id="sendKeyPressEvent"></a>
## *sendKeyPressEvent*

Sends a key press event to the HDMI CEC device.

### Events
Event details are missing in the header file documentation.
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
        "logicalAddress": 0,
        "keyCode": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.HdmiCecSource.sendKeyPressEvent", "params": {"logicalAddress": 0, "keyCode": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "success": true
    }
}
```

<a id="sendStandbyMessage"></a>
## *sendStandbyMessage*

Sends a standby message to another CEC device

### Events
Event details are missing in the header file documentation.
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
    "result": {
        "success": true
    }
}
```

<a id="setEnabled"></a>
## *setEnabled*

Sets the status of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
    "result": {
        "success": true
    }
}
```

<a id="setOSDName"></a>
## *setOSDName*

Sets the OSD name of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
        "name": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.HdmiCecSource.setOSDName", "params": {"name": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "success": true
    }
}
```

<a id="setOTPEnabled"></a>
## *setOTPEnabled*

Sets the OTP enabled status of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
    "result": {
        "success": true
    }
}
```

<a id="setVendorId"></a>
## *setVendorId*

Sets the vendor ID of the HDMI CEC source

### Events
Event details are missing in the header file documentation.
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
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the HdmiCecSource plugin:

HdmiCecSource interface events:

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

Notifies when the active source status is updated

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | bool | Is the active source active or not |

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
        "logicalAddress": 0
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
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.HdmiCecSource.onDeviceInfoUpdated",
    "params": {
        "logicalAddress": 0
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
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.HdmiCecSource.onDeviceRemoved",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="onKeyPressEvent"></a>
## *onKeyPressEvent*

Notifies when a key press CEC message is received from other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the added device |
| params.keyCode | int | Key code of the key press event |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.HdmiCecSource.onKeyPressEvent",
    "params": {
        "logicalAddress": 0,
        "keyCode": 0
    }
}
```

<a id="onKeyReleaseEvent"></a>
## *onKeyReleaseEvent*

Notifies when a key release CEC message is received from other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.HdmiCecSource.onKeyReleaseEvent",
    "params": {
        "logicalAddress": 0
    }
}
```

<a id="standbyMessageReceived"></a>
## *standbyMessageReceived*

Notifies when CEC standby message received from the other CEC device

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logicalAddress | int | Logical address of the added device |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.HdmiCecSource.standbyMessageReceived",
    "params": {
        "logicalAddress": 0
    }
}
```
