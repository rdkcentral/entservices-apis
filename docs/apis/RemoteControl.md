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
| params.sessionId | integer | The session identifier for the firmware update e.g. 12345 |
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
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RemoteControl.cancelFirmwareUpdate", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | ClearIRCodesRequest | The clear IR codes request parameters |
| params.request.remoteId | integer | The remote ID of the target remote on the specified network e.g. 1 |
| params.request.netType | integer | The type of network e.g. 1 |
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
        "remoteId": 0,
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RemoteControl.clearIRCodes", "params": {"remoteId": 0, "netType": 0}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | ConfigureWakeupKeysRequest | The configure wakeup keys request parameters |
| params.request.wakeupConfig | string | The deepsleep wakeup key configuration of the remote. Possible values: "all" (all keys on the remote will wake target from deepsleep), "none" (no keys will wake target), "custom" (the custom list of Linux key codes in customKeys will wake target) |
| params.request.customKeys | string | List of Linux key codes that can wake the target from deepsleep. Mandatory if wakeupConfig is "custom", otherwise should be omitted  |
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
        "wakeupConfig": "",
        "customKeys": "195,199"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RemoteControl.configureWakeupKeys", "params": {"wakeupConfig": "", "customKeys": "195,199"}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.level | string | The level at which the remote will beep , "mid", "high" |
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
        "level": "off"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RemoteControl.findMyRemote", "params": {"level": "off"}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetApiVersionNumberResponse | The API version response @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
| result.response.version | integer | The API version number e.g. 1 |
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
        "version": 0,
        "success": true
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
| params.netType | integer | The type of network e.g. 1 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRCodesByAutoLookupResponse | The get IR codes by auto lookup response @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup. |
| result.response.tvCodes | IStringIterator* | A list of TV IR codes |
| result.response.avrCodes | IStringIterator* | A list of AVR IR codes |
| result.response.tvManufacturer | string | The TV manufacturer for which codes are provided  |
| result.response.tvModel | string | The TV model for which codes are provided  |
| result.response.avrManufacturer | string | The AVR manufacturer for which codes are provided  |
| result.response.avrModel | string | The AVR model for which codes are provided  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup",
    "params": {
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "tvCodes": "",
        "avrCodes": "",
        "tvManufacturer": "Samsung",
        "tvModel": "UN65JU750",
        "avrManufacturer": "Denon",
        "avrModel": "AVR-S750H",
        "success": true
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
| params.request | GetIRCodesByNamesRequest | The get IR codes by names request parameters |
| params.request.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| params.request.manufacturer | string | The manufacturer name of the AV device  |
| params.request.model | string | The model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRCodesByNamesResponse | The get IR codes by names response @retval ErrorCode::NONE: IR codes retrieved successfully by names. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names. |
| result.response.codes | IStringIterator* | A list of IR codes for the specified device |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| result.response.manufacturer | string | The manufacturer name of the AV device  |
| result.response.model | string | The model name of the AV device  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RemoteControl.getIRCodesByNames",
    "params": {
        "avDevType": "TV",
        "manufacturer": "Samsung",
        "model": "UN65JU750"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RemoteControl.getIRCodesByNames", "params": {"avDevType": "TV", "manufacturer": "Samsung", "model": "UN65JU750"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "codes": "",
        "avDevType": "TV",
        "manufacturer": "Samsung",
        "model": "UN65JU750",
        "success": true
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
| params.request | GetIRDBManufacturersRequest | The get IRDB manufacturers request parameters |
| params.request.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| params.request.manufacturer | string | A part of the name of the manufacturer of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRDBManufacturersResponse | The get IRDB manufacturers response @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers. |
| result.response.manufacturers | IStringIterator* | A list of manufacturer names |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RemoteControl.getIRDBManufacturers",
    "params": {
        "avDevType": "TV",
        "manufacturer": "Sam"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RemoteControl.getIRDBManufacturers", "params": {"avDevType": "TV", "manufacturer": "Sam"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "manufacturers": "",
        "avDevType": "TV",
        "success": true
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
| params.request | GetIRDBModelsRequest | The get IRDB models request parameters |
| params.request.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| params.request.manufacturer | string | The manufacturer name of the AV device  |
| params.request.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRDBModelsResponse | The get IRDB models response @retval ErrorCode::NONE: IRDB models retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB models. |
| result.response.models | IStringIterator* | A list of model names |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| result.response.manufacturer | string | The manufacturer name of the AV device  |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RemoteControl.getIRDBModels",
    "params": {
        "avDevType": "TV",
        "manufacturer": "Samsung",
        "model": "UN6"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RemoteControl.getIRDBModels", "params": {"avDevType": "TV", "manufacturer": "Samsung", "model": "UN6"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "models": "",
        "avDevType": "TV",
        "manufacturer": "Samsung",
        "success": true
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
| result.response | GetLastKeypressSourceResponse | The last keypress source response @retval ErrorCode::NONE: Last keypress source retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve last keypress source. |
| result.response.controllerId | integer | The controller ID of the target remote on the specified network e.g. 1 |
| result.response.timestamp | integer | The time of the last key press in milliseconds since epoch |
| result.response.sourceName | string | The source of the last key press  |
| result.response.sourceType | string | The source type of the last key press  |
| result.response.sourceKeyCode | integer | The source key code e.g. 195 |
| result.response.isScreenBindMode | bool | True if in screen bind mode, otherwise false |
| result.response.remoteKeypadConfig | integer | The configuration of the remote keypad e.g. 0 |
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
        "controllerId": 0,
        "timestamp": 0,
        "sourceName": "IR",
        "sourceType": "REMOTE",
        "sourceKeyCode": 0,
        "isScreenBindMode": true,
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
| params.netType | integer | The type of network e.g. 1 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetNetStatusResponse | The network status response @retval ErrorCode::NONE: Network status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve network status. |
| result.response.netType | integer | The type of network e.g. 1 |
| result.response.netTypeSupported | IUint32Iterator* | A list of the network types that the STB supports |
| result.response.pairingState | string | The current overall pairing state of the specified network |
| result.response.irProgState | string | The current state of the IR code programming request to the remote |
| result.response.remoteData | IRemoteDataIterator* | Remote information for each paired remote control |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.RemoteControl.getNetStatus",
    "params": {
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.RemoteControl.getNetStatus", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "netType": 0,
        "netTypeSupported": "",
        "pairingState": "INITIALISING",
        "irProgState": "IDLE",
        "remoteData": "",
        "success": true
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
| params.netType | integer | The type of network e.g. 1 |
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
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.RemoteControl.initializeIRDB", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | SetIRCodeRequest | The set IR code request parameters |
| params.request.remoteId | integer | The remote ID of the target remote on the specified network e.g. 1 |
| params.request.netType | integer | The type of network e.g. 1 |
| params.request.avDevType | string | Whether the device is a video (TV) or audio (AMP) device  |
| params.request.code | string | The IR code being programmed into the remote  |
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
        "remoteId": 0,
        "netType": 0,
        "avDevType": "TV",
        "code": "PANASONIC_3DTV"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.RemoteControl.setIRCode", "params": {"remoteId": 0, "netType": 0, "avDevType": "TV", "code": "PANASONIC_3DTV"}}' http://127.0.0.1:9998/jsonrpc
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

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | StartFirmwareUpdateRequest | The start firmware update request parameters |
| params.request.macAddress | string | The MAC address of the target remote in hex-colon format  |
| params.request.fileName | string | The full path and filename for the firmware image e.g. " |
| params.request.fileType | string | The type of firmware image file  |
| params.request.percentIncrement | integer | The increment change of a firmware update to notify. Valid range 1-100 percent e.g. 10 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StartFirmwareUpdateResponse | The start firmware update response @retval ErrorCode::NONE: Firmware update started successfully. @retval ErrorCode::GENERAL: Failed to start firmware update. |
| result.response.sessionId | integer | The session identifier for the firmware update e.g. 12345 |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.RemoteControl.startFirmwareUpdate",
    "params": {
        "macAddress": "AA:BB:CC:DD:EE:FF",
        "fileName": "",
        "fileType": "mfg",
        "percentIncrement": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.RemoteControl.startFirmwareUpdate", "params": {"macAddress": "AA:BB:CC:DD:EE:FF", "fileName": "", "fileType": "mfg", "percentIncrement": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "sessionId": 0,
        "success": true
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
| params.request | StartPairingRequest | The pairing request parameters |
| params.request.netType | integer | The type of network e.g. 1 |
| params.request.timeout | integer | The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout) e.g. 30 |
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
    "id": 15,
    "method": "org.rdk.RemoteControl.startPairing",
    "params": {
        "netType": 0,
        "timeout": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RemoteControl.startPairing", "params": {"netType": 0, "timeout": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "success": true
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
| params.sessionId | integer | The session identifier for the firmware update e.g. 12345 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StatusFirmwareUpdateResponse | The status firmware update response @retval ErrorCode::NONE: Firmware update status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve firmware update status. |
| result.response.result | FirmwareUpdateStatus | The firmware update status |
| result.response.result.state | string | The firmware update state. Possible values: "DOWNLOADING", "COMPLETE", "FAILED"  |
| result.response.result.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100) e.g. 50 |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "result": {
            "state": "DOWNLOADING",
            "percentComplete": 0
        },
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
| params.request | StopPairingRequest | The stop pairing request parameters |
| params.request.screenBindDisable | bool | Whether to disable screen bind mode (default: true) |
| params.request.scanDisable | bool | Whether to disable scanning for remotes (default: true) |
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
        "success": true
    }
}
```

<a id="unpair"></a>
## *unpair*

Unpairs all remotes from the STB

### Events
Event details will be updated soon.
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
    "id": 18,
    "method": "org.rdk.RemoteControl.unpair"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.RemoteControl.unpair"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "success": true
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
| params.progress | FirmwareUpdateProgressEvent |  |
| params.progress.sessionId | integer | The session identifier e.g. 12345 |
| params.progress.status | FirmwareUpdateStatus | The firmware update status |
| params.progress.status.state | string | The firmware update state. Possible values: "DOWNLOADING", "COMPLETE", "FAILED"  |
| params.progress.status.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100) e.g. 50 |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RemoteControl.onFirmwareUpdateProgress",
    "params": {
        "sessionId": 0,
        "status": {
            "state": "DOWNLOADING",
            "percentComplete": 0
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
| params.status | StatusEventData |  |
| params.status.netType | integer | The type of remote control network e.g. 1 |
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
        "netType": 0,
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
| params.status | ValidationStatusObject |  |
| params.status.netType | integer | The type of remote control network e.g. 1 |
| params.status.validationDigit1 | integer | The first validation digit e.g. 1 |
| params.status.validationDigit2 | integer | The second validation digit e.g. 2 |
| params.status.validationDigit3 | integer | The third validation digit e.g. 3 |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.RemoteControl.onValidation",
    "params": {
        "netType": 0,
        "validationDigit1": 0,
        "validationDigit2": 0,
        "validationDigit3": 0
    }
}
```
