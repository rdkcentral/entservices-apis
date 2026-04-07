<!-- Generated automatically, DO NOT EDIT! -->
<a id="RemoteControl_Plugin"></a>
# RemoteControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RemoteControl/IRemoteControl.h)**

A RemoteControl plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `RemoteControl` plugin provides an interface for RemoteControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RemoteControl) |
| classname | string | Class name: *RemoteControl* |
| locator | string | Library name: *libWPEFrameworkRemoteControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the RemoteControl plugin:

RemoteControl interface methods:

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
| [startPairing](#startPairing) | Initiates pairing a remote with the STB on the specified network. |
| [statusFirmwareUpdate](#statusFirmwareUpdate) | Returns the status of an active firmware image update session |
| [stopPairing](#stopPairing) | Cancels pairing a remote with the STB on the specified network. |
| [unpair](#unpair) | Unpairs all remotes from the STB |

<a id="cancelFirmwareUpdate"></a>
## *cancelFirmwareUpdate*

Cancels an active firmware image update session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The firmware update session identifier  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="clearIRCodes"></a>
## *clearIRCodes*

Clears the IR codes from the specified remote

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The remote ID of the target remote on the specified network  |
| params.netType | integer | The type of remote control network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="configureWakeupKeys"></a>
## *configureWakeupKeys*

Configures which keys on the remote will wake the target from deepsleep

### Events
Event details will be updated soon.
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
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="factoryReset"></a>
## *factoryReset*

Tells all paired and connected remotes to factory reset

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="findMyRemote"></a>
## *findMyRemote*

Tells the most recently used remote to beep

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.level | string | The level at which the remote will beep |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="getApiVersionNumber"></a>
## *getApiVersionNumber*

Gets the current API version number.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetApiVersionNumberResponse | The API version response @retval ErrorCode::NONE: Operation completed successfully. |

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
        "response": ""
    }
}
```

<a id="getIRCodesByAutoLookup"></a>
## *getIRCodesByAutoLookup*

Returns a list of available IR codes for the TV and AVRs specified by the input parameters

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of remote control network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.tvManufacturer | string | The TV manufacturer for which codes are provided  |
| result.tvModel | string | The TV model for which codes are provided  |
| result.avrManufacturer | string | The AVR manufacturer for which codes are provided  |
| result.avrModel | string | The AVR model for which codes are provided  |
| result.success | bool | Whether the request succeeded |
| result.tvCodes | IStringIterator | A list of TV IR codes  |
| result.tvCodes[#] | string |  |
| result.avrCodes | IStringIterator | A list of AVR IR codes  @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup. |
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| params.manufacturer | string | A part of the name of the manufacturer of the AV device  |
| params.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.manufacturer | string | A part of the name of the manufacturer of the AV device  |
| result.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
| result.success | bool | Whether the request succeeded |
| result.codes | IStringIterator | A list of IR codes for the specified device  @retval ErrorCode::NONE: IR codes retrieved successfully by names. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names. |
| result.codes[#] | string |  |

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
        "codes": [
            "R2467"
        ]
    }
}
```

<a id="getIRDBManufacturers"></a>
## *getIRDBManufacturers*

Returns a list of manufacturer names based on the specified input parameters

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| params.manufacturer | string | A part of the name of the manufacturer of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.success | bool | Whether the request succeeded |
| result.manufacturers | IStringIterator | A list of manufacturer names  @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers. |
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| params.manufacturer | string | A part of the name of the manufacturer of the AV device  |
| params.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.manufacturer | string | A part of the name of the manufacturer of the AV device  |
| result.success | bool | Whether the request succeeded |
| result.models | IStringIterator | A list of model names  @retval ErrorCode::NONE: IRDB models retrieved successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve IRDB models. |
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

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetLastKeypressSourceResponse | The last keypress source response @retval ErrorCode::NONE: Last keypress source retrieved successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve last keypress source. |
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of remote control network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | GetNetStatusResult | The network status result containing success and a nested status object with netType, pairingState, irProgState, netTypesSupported, and remoteData @retval ErrorCode::NONE: Network status retrieved successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve network status. |
| result.result.success | bool | Whether the request succeeded |
| result.result.status | NetStatusData | The network status data |
| result.result.status.netType | integer | The type of remote control network  |
| result.result.status.pairingState | string | The pairing state |
| result.result.status.irProgState | string | The IR programming state |
| result.result.status.netTypesSupported | string | JSON array of supported network types e.g. [1] |
| result.result.status.remoteData | string | JSON array of paired remote information |

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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of remote control network  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="setIRCode"></a>
## *setIRCode*

Programs an IR code into the specified remote control

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The remote ID of the target remote on the specified network  |
| params.netType | integer | The type of remote control network  |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| params.code | string | The IR code being programmed into the remote  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

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
        "result": ""
    }
}
```

<a id="startFirmwareUpdate"></a>
## *startFirmwareUpdate*

Starts a firmware image update session for the specified remote(s)

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.macAddress | string | The MAC address of the remote in hex-colon format  |
| params.fileName | string | The full path and filename for the firmware image  |
| params.fileType | string | The type of firmware image file  |
| params.percentIncrement | integer | The increment change of a firmware update to notify. Valid range 1-100 percent  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |
| result.sessionIdList | IStringIterator | List of session IDs created for the firmware update(s) @retval ErrorCode::NONE: Firmware update started successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to start firmware update. |
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

<a id="startPairing"></a>
## *startPairing*

Initiates pairing a remote with the STB on the specified network.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.netType | integer | The type of remote control network  |
| params.timeout | integer | The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout)  |
| params.screenBindEnable | bool | Whether to enable screen bind mode (default: true) |
| params.scanEnable | bool | Whether to enable scanning for remotes (default: true) |
| params?.macAddressList | IStringIterator | <sup>(optional)</sup>Optional list of MAC addresses to pair with (only used if scanEnable is true) @retval ErrorCode::NONE: Pairing started successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to start pairing. |
| params?.macAddressList[#] | string | <sup>(optional)</sup> |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.RemoteControl.startPairing",
    "params": {
        "netType": 1,
        "timeout": 30,
        "screenBindEnable": true,
        "scanEnable": true,
        "macAddressList": [
            ""
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RemoteControl.startPairing", "params": {"netType": 1, "timeout": 30, "screenBindEnable": true, "scanEnable": true, "macAddressList": [""]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "result": ""
    }
}
```

<a id="statusFirmwareUpdate"></a>
## *statusFirmwareUpdate*

Returns the status of an active firmware image update session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The firmware update session identifier  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StatusFirmwareUpdateResponse | The firmware update status fields including sessionId, macAddress, state, percentComplete, optional error, and success @retval ErrorCode::NONE: Firmware update status retrieved successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to retrieve firmware update status. |
| result.response.sessionId | string | The firmware update session identifier  |
| result.response.macAddress | string | The MAC address of the remote in hex-colon format  |
| result.response.state | string | The firmware update state |
| result.response.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100)  |
| result.response.error | string | The firmware update error string, only present on failure |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "sessionId": "12345-abc-def"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"sessionId": "12345-abc-def"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "sessionId": "12345-abc-def",
        "macAddress": "AA:BB:CC:DD:EE:FF",
        "state": "DOWNLOADING",
        "percentComplete": 50,
        "error": "",
        "success": true
    }
}
```

<a id="stopPairing"></a>
## *stopPairing*

Cancels pairing a remote with the STB on the specified network.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.screenBindDisable | bool | Whether to disable screen bind mode (default: true) |
| params.scanDisable | bool | Whether to disable scanning for remotes (default: true) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.RemoteControl.stopPairing",
    "params": {
        "screenBindDisable": true,
        "scanDisable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.RemoteControl.stopPairing", "params": {"screenBindDisable": true, "scanDisable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "result": ""
    }
}
```

<a id="unpair"></a>
## *unpair*

Unpairs all remotes from the STB

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.macAddressList | IStringIterator | <sup>(optional)</sup>Optional list of MAC addresses to pair with (only used if scanEnable is true) @retval ErrorCode::NONE: Pairing started successfully. @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed. @retval ErrorCode::GENERAL: Failed to start pairing. |
| params?.macAddressList[#] | string | <sup>(optional)</sup> |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | SuccessResult |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.RemoteControl.unpair",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.RemoteControl.unpair", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "result": ""
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the RemoteControl plugin:

RemoteControl interface events:

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
| params.progress | FirmwareUpdateProgressEvent | Firmware update progress information including session ID and current status |
| params.progress.sessionId | string | The session identifier  |
| params.progress.status | FirmwareUpdateStatus | The firmware update status |
| params.progress.status.state | string | The firmware update state |
| params.progress.status.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100)  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RemoteControl.onFirmwareUpdateProgress",
    "params": {
        "sessionId": "12345-abc-def",
        "status": {
            "state": "DOWNLOADING",
            "percentComplete": 50
        }
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
| params.status | StatusEventData | Network status information including network type, pairing state, and IR programming state |
| params.status.netType | integer | The type of remote control network  |
| params.status.netTypeSupported | bool | Whether the network type is supported |
| params.status.pairingState | string | The pairing state |
| params.status.irProgState | string | The IR programming state |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.RemoteControl.onStatus",
    "params": {
        "netType": 1,
        "netTypeSupported": true,
        "pairingState": "INITIALISING",
        "irProgState": "IDLE"
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
| params.status | ValidationStatusObject | Validation information including network type and validation digits for manual pairing |
| params.status.netType | integer | The type of remote control network  |
| params.status.validationDigit1 | integer | The first validation digit  |
| params.status.validationDigit2 | integer | The second validation digit  |
| params.status.validationDigit3 | integer | The third validation digit  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.RemoteControl.onValidation",
    "params": {
        "netType": 1,
        "validationDigit1": 1,
        "validationDigit2": 2,
        "validationDigit3": 3
    }
}
```
