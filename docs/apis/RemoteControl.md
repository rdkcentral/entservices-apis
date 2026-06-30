<!-- Generated automatically, DO NOT EDIT! -->
<a id="RemoteControl_Module"></a>
# RemoteControl Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RemoteControl/IRemoteControl.h)**

A RemoteControl module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IRemoteControl](#IRemoteControl)
    - [Methods](#IRemoteControl-Methods)
    - [Notifications](#IRemoteControl-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `RemoteControl` module provides the following interface(s):

- IRemoteControl

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RemoteControl) |
| classname | string | Class name: *RemoteControl* |
| locator | string | Library name: *libWPEFrameworkRemoteControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IRemoteControl"></a>
## IRemoteControl Interface

### Description

Interface for the Remote Control JSONRPC API in WPEFramework.  This interface defines the JSONRPC methods and events for remote control management, including pairing, IRDB operations, firmware updates, and related notifications. Implementations of this interface are expected to be registered with the Thunder framework.

<a id="IRemoteControl-Methods"></a>
### Methods

The following methods are provided by the IRemoteControl Interface:

| Method | Description |
| :-------- | :-------- |
| [cancelFirmwareUpdate](#cancelFirmwareUpdate) | Cancels an active firmware image update session |
| [clearIRCodes](#clearIRCodes) | Clears the IR codes from the specified remote |
| [configureWakeupKeys](#configureWakeupKeys) | Configures which keys on the remote will wake the target from deepsleep |
| [factoryReset](#factoryReset) | Tells all paired and connected remotes to factory reset |
| [findMyRemote](#findMyRemote) | Tells the most recently used remote to beep |
| [getApiVersionNumber](#getApiVersionNumber) | Gets the current API version number. |
| [getIRCodesByAutoLookup](#getIRCodesByAutoLookup) | Returns a list of available IR codes for the TV and AVRs specified by the input parameters |
| [getIRCodesByNames](#getIRCodesByNames) | Returns a list of IR codes for the AV device specified by the input parameters |
| [getIRDBManufacturers](#getIRDBManufacturers) | Returns a list of manufacturer names based on the specified input parameters |
| [getIRDBModels](#getIRDBModels) | Returns a list of model names based on the specified input parameters |
| [getLastKeypressSource](#getLastKeypressSource) | Returns last key press source data |
| [getNetStatus](#getNetStatus) | Returns the status information provided by the last `onStatus` event for the specified network. |
| [initializeIRDB](#initializeIRDB) | Initializes the IR database |
| [setIRCode](#setIRCode) | Programs an IR code into the specified remote control |
| [startFirmwareUpdate](#startFirmwareUpdate) | Starts a firmware image update session for the specified remote(s) |
| [statusFirmwareUpdate](#statusFirmwareUpdate) | Returns the status of an active firmware image update session |
| [unpair](#unpair) | Unpairs all remotes from the STB |

<a id="cancelFirmwareUpdate"></a>
## *cancelFirmwareUpdate*

Cancels an active firmware image update session

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.RemoteControl.cancelFirmwareUpdate",
    "params": {
        "sessionId": "12345-abc-def"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RemoteControl.cancelFirmwareUpdate", "params": {"sessionId": "12345-abc-def"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```

<a id="clearIRCodes"></a>
## *clearIRCodes*

Clears the IR codes from the specified remote

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The remote ID of the target remote on the specified network  |
| params.netType | integer | The type of network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.RemoteControl.clearIRCodes",
    "params": {
        "remoteId": 1,
        "netType": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RemoteControl.clearIRCodes", "params": {"remoteId": 1, "netType": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true
    }
}
```

<a id="configureWakeupKeys"></a>
## *configureWakeupKeys*

Configures which keys on the remote will wake the target from deepsleep

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.wakeupConfig | string | The deepsleep wakeup key configuration of the remote. Possible values: all (all keys on the remote will wake target from deepsleep), none (no keys will wake target), custom (the custom list of Linux key codes in customKeys will wake target) |
| params.customKeys | string | List of Linux key codes that can wake the target from deepsleep. Mandatory if wakeupConfig is custom, otherwise should be omitted  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.RemoteControl.configureWakeupKeys",
    "params": {
        "wakeupConfig": "INVALID",
        "customKeys": "195,199"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RemoteControl.configureWakeupKeys", "params": {"wakeupConfig": "INVALID", "customKeys": "195,199"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```

<a id="factoryReset"></a>
## *factoryReset*

Tells all paired and connected remotes to factory reset

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.RemoteControl.factoryReset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.RemoteControl.factoryReset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="findMyRemote"></a>
## *findMyRemote*

Tells the most recently used remote to beep

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.level | string | The level at which the remote will beep. Possible values: INVALID, off, mid, high |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.RemoteControl.findMyRemote",
    "params": {
        "level": "INVALID"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RemoteControl.findMyRemote", "params": {"level": "INVALID"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="getApiVersionNumber"></a>
## *getApiVersionNumber*

Gets the current API version number.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | object | The API version response |
| result.response.version | integer | The API version number  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.RemoteControl.getApiVersionNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.RemoteControl.getApiVersionNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "version": 1,
        "success": true
    }
}
```

<a id="getIRCodesByAutoLookup"></a>
## *getIRCodesByAutoLookup*

Returns a list of available IR codes for the TV and AVRs specified by the input parameters

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.tvManufacturer | string | The TV manufacturer for which codes are provided  |
| result.tvModel | string | The TV model for which codes are provided  |
| result.avrManufacturer | string | The AVR manufacturer for which codes are provided  |
| result.avrModel | string | The AVR model for which codes are provided  |
| result.success | bool | Whether the request succeeded |
| result.tvCodes | array | A list of TV IR codes  |
| result.tvCodes[#] | string |  |
| result.avrCodes | array | A list of AVR IR codes  |
| result.avrCodes[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup",
    "params": {
        "netType": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup", "params": {"netType": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "tvManufacturer": "Samsung",
        "tvModel": "UN65JU750",
        "avrManufacturer": "Denon",
        "avrModel": "AVR-S750H",
        "success": true,
        "tvCodes": [
            1156
        ],
        "avrCodes": [
            "R2467"
        ]
    }
}
```

<a id="getIRCodesByNames"></a>
## *getIRCodesByNames*

Returns a list of IR codes for the AV device specified by the input parameters

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| params.manufacturer | string | The manufacturer name of the AV device  |
| params.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| result.manufacturer | string | The manufacturer name of the AV device  |
| result.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
| result.success | bool | Whether the request succeeded |
| result.codes | string | A list of IR codes as a string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RemoteControl.getIRCodesByNames",
    "params": {
        "avDevType": "INVALID",
        "manufacturer": "Samsung",
        "model": "UN6"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RemoteControl.getIRCodesByNames", "params": {"avDevType": "INVALID", "manufacturer": "Samsung", "model": "UN6"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "avDevType": "INVALID",
        "manufacturer": "Samsung",
        "model": "UN6",
        "success": true,
        "codes": ""
    }
}
```

<a id="getIRDBManufacturers"></a>
## *getIRDBManufacturers*

Returns a list of manufacturer names based on the specified input parameters

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| params.manufacturer | string | A part of the name of the manufacturer of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| result.success | bool | Whether the request succeeded |
| result.manufacturers | array | A list of manufacturer names  |
| result.manufacturers[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RemoteControl.getIRDBManufacturers",
    "params": {
        "avDevType": "INVALID",
        "manufacturer": "Sam"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RemoteControl.getIRDBManufacturers", "params": {"avDevType": "INVALID", "manufacturer": "Sam"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "avDevType": "INVALID",
        "success": true,
        "manufacturers": [
            "Samsung"
        ]
    }
}
```

<a id="getIRDBModels"></a>
## *getIRDBModels*

Returns a list of model names based on the specified input parameters

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| params.manufacturer | string | The manufacturer name of the AV device  |
| params.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| result.manufacturer | string | The manufacturer name of the AV device  |
| result.success | bool | Whether the request succeeded |
| result.models | array | A list of model names  |
| result.models[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RemoteControl.getIRDBModels",
    "params": {
        "avDevType": "INVALID",
        "manufacturer": "Samsung",
        "model": "UN6"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RemoteControl.getIRDBModels", "params": {"avDevType": "INVALID", "manufacturer": "Samsung", "model": "UN6"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "avDevType": "INVALID",
        "manufacturer": "Samsung",
        "success": true,
        "models": [
            "AH5901068L"
        ]
    }
}
```

<a id="getLastKeypressSource"></a>
## *getLastKeypressSource*

Returns last key press source data

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | object | The last keypress source response |
| result.response.controllerId | integer | The controller ID of the target remote on the specified network  |
| result.response.timestamp | integer | The time of the last key press in milliseconds since epoch |
| result.response.sourceName | string | The source of the last key press  |
| result.response.sourceType | string | The source type of the last key press  |
| result.response.sourceKeyCode | integer | The source key code  |
| result.response.bIsScreenBindMode | bool | True if in screen bind mode, otherwise false |
| result.response.remoteKeypadConfig | integer | The configuration of the remote keypad  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.RemoteControl.getLastKeypressSource"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.RemoteControl.getLastKeypressSource"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "controllerId": 1,
        "timestamp": 0,
        "sourceName": "IR",
        "sourceType": "REMOTE",
        "sourceKeyCode": 195,
        "bIsScreenBindMode": true,
        "remoteKeypadConfig": 0,
        "success": true
    }
}
```

<a id="getNetStatus"></a>
## *getNetStatus*

Returns the status information provided by the last `onStatus` event for the specified network.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | object | The network status result containing success and a nested status object with netType, pairingState, irProgState, netTypesSupported, and remoteData. remoteData is carried as opaque JSON to preserve the nested JSON response shape across COM-RPC |
| result.result.success | bool | Whether the request succeeded |
| result.result.status | object | The network status data |
| result.result.status.netType | integer | The type of remote control network  |
| result.result.status.pairingState | string | The pairing state. Possible values: INITIALISING, IDLE, SEARCHING, PAIRING, COMPLETE, FAILED |
| result.result.status.irProgState | string | The IR programming state. Possible values: IDLE, WAITING, COMPLETE, FAILED |
| result.result.status.netTypesSupported | string | JSON array of supported network types e.g. [1] |
| result.result.status.remoteData | string | JSON array of paired remote information. Kept as opaque JSON because of limitations of nesting COM-RPC iterators within struct data which does not preserve the desired status.remoteData response shape |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.RemoteControl.getNetStatus",
    "params": {
        "netType": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.RemoteControl.getNetStatus", "params": {"netType": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "success": true,
        "status": {
            "netType": 1,
            "pairingState": "INITIALISING",
            "irProgState": "IDLE",
            "netTypesSupported": "",
            "remoteData": ""
        }
    }
}
```

<a id="initializeIRDB"></a>
## *initializeIRDB*

Initializes the IR database

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.RemoteControl.initializeIRDB",
    "params": {
        "netType": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.RemoteControl.initializeIRDB", "params": {"netType": 1}}' http://127.0.0.1:9998/jsonrpc
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

<a id="setIRCode"></a>
## *setIRCode*

Programs an IR code into the specified remote control

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The remote ID of the target remote on the specified network  |
| params.netType | integer | The type of network  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device. Possible values: INVALID, TV, AMP |
| params.code | string | The IR code being programmed into the remote  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.RemoteControl.setIRCode",
    "params": {
        "remoteId": 1,
        "netType": 1,
        "avDevType": "INVALID",
        "code": "PANASONIC_3DTV"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.RemoteControl.setIRCode", "params": {"remoteId": 1, "netType": 1, "avDevType": "INVALID", "code": "PANASONIC_3DTV"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "success": true
    }
}
```

<a id="startFirmwareUpdate"></a>
## *startFirmwareUpdate*

Starts a firmware image update session for the specified remote(s)

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.macAddress | string | The MAC address of the target remote in hex-colon format  |
| params.fileName | string | The full path and filename for the firmware image  |
| params.fileType | string | The type of firmware image file  |
| params.percentIncrement | integer | The increment change of a firmware update to notify. Valid range 1-100 percent  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |
| result.sessionIdList | array | List of session IDs created for the firmware update(s) |
| result.sessionIdList[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.RemoteControl.startFirmwareUpdate",
    "params": {
        "macAddress": "AA:BB:CC:DD:EE:FF",
        "fileName": "/tmp/remote_firmware.bin",
        "fileType": "mfg",
        "percentIncrement": 10
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.RemoteControl.startFirmwareUpdate", "params": {"macAddress": "AA:BB:CC:DD:EE:FF", "fileName": "/tmp/remote_firmware.bin", "fileType": "mfg", "percentIncrement": 10}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "success": true,
        "sessionIdList": [
            ""
        ]
    }
}
```

<a id="statusFirmwareUpdate"></a>
## *statusFirmwareUpdate*

Returns the status of an active firmware image update session

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | object | The firmware update status with success at top level and details nested under status (upgradeSessionId, macAddress, upgradeState, percentComplete, optional errorString) |
| result.response.success | bool | Whether the request succeeded |
| result.response.status | object | The firmware update status details including session ID, MAC address, upgrade state, and percent complete |
| result.response.status.upgradeSessionId | string | The firmware update session identifier  |
| result.response.status.macAddress | string | The MAC address of the remote in hex-colon format  |
| result.response.status.upgradeState | string | The firmware update state. Possible values: success, idle, pending, canceled, retrying, error, invalid |
| result.response.status.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100)  |
| result.response.status.errorString | string | The firmware update error string, only present on failure |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "sessionId": "12345-abc-def"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"sessionId": "12345-abc-def"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "success": true,
        "status": {
            "upgradeSessionId": "12345-abc-def",
            "macAddress": "AA:BB:CC:DD:EE:FF",
            "upgradeState": "success",
            "percentComplete": 50,
            "errorString": ""
        }
    }
}
```

<a id="unpair"></a>
## *unpair*

Unpairs all remotes from the STB

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.macAddressList | array | <sup>(optional)</sup>Optional list of MAC addresses to unpair (if empty, unpairs all remotes) |
| params?.macAddressList[#] | string | <sup>(optional)</sup> |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RemoteControl.unpair",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RemoteControl.unpair", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "success": true
    }
}
```

<a id="IRemoteControl-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IRemoteControl Interface:

| Event | Description |
| :-------- | :-------- |
| [onFirmwareUpdateProgress](#onFirmwareUpdateProgress) | Generated at 0 and 100 percent and each time a download percent increment is reached |
| [onStatus](#onStatus) | Triggered at any time when the status of any one of the supported STB remote networks changes |
| [onValidation](#onValidation) | Generated for manual pairing validation |

<a id="onFirmwareUpdateProgress"></a>
## *onFirmwareUpdateProgress*

Generated at 0 and 100 percent and each time a download percent increment is reached

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | object | Firmware update status including session ID, MAC address, upgrade state, and percent complete |
| params.status.upgradeSessionId | string | The firmware update session identifier  |
| params.status.macAddress | string | The MAC address of the remote in hex-colon format  |
| params.status.upgradeState | string | The firmware update state. Possible values: success, idle, pending, canceled, retrying, error, invalid |
| params.status.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100)  |
| params.status.errorString | string | The firmware update error string, only present on failure |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.RemoteControl.onFirmwareUpdateProgress",
    "params": {
        "upgradeSessionId": "12345-abc-def",
        "macAddress": "AA:BB:CC:DD:EE:FF",
        "upgradeState": "success",
        "percentComplete": 50,
        "errorString": ""
    }
}
```

<a id="onStatus"></a>
## *onStatus*

Triggered at any time when the status of any one of the supported STB remote networks changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | object | Network status information including network type, pairing state, and IR programming state |
| params.status.netType | integer | The type of remote control network  |
| params.status.pairingState | string | The pairing state. Possible values: INITIALISING, IDLE, SEARCHING, PAIRING, COMPLETE, FAILED |
| params.status.irProgState | string | The IR programming state. Possible values: IDLE, WAITING, COMPLETE, FAILED |
| params.status.netTypesSupported | string | JSON array of supported network types e.g. [1] |
| params.status.remoteData | string | JSON array of paired remote information. Kept as opaque JSON because of limitations of nesting COM-RPC iterators within struct data which does not preserve the desired status.remoteData response shape |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.RemoteControl.onStatus",
    "params": {
        "netType": 1,
        "pairingState": "INITIALISING",
        "irProgState": "IDLE",
        "netTypesSupported": "",
        "remoteData": ""
    }
}
```

<a id="onValidation"></a>
## *onValidation*

Generated for manual pairing validation

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | object | Validation information including network type and validation digits for manual pairing |
| params.status.netType | integer | The type of remote control network  |
| params.status.validationDigit1 | integer | The first validation digit  |
| params.status.validationDigit2 | integer | The second validation digit  |
| params.status.validationDigit3 | integer | The third validation digit  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RemoteControl.onValidation",
    "params": {
        "netType": 1,
        "validationDigit1": 1,
        "validationDigit2": 2,
        "validationDigit3": 3
    }
}
```
