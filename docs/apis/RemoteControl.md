<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_RemoteControl_API"></a>
# RemoteControl API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

RemoteControl interface for Thunder framework.

(Defined with IRemoteControl in [IRemoteControl.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IRemoteControl.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the RemoteControl interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

RemoteControl JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the RemoteControl interface:

RemoteControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getApiVersionNumber](#method_getApiVersionNumber) | Gets the current API version number |
| [getNetStatus](#method_getNetStatus) | Returns the status information provided by the last `onStatus` event for the specified network |
| [getIRDBManufacturers](#method_getIRDBManufacturers) | Returns a list of manufacturer names based on the specified input parameters |
| [getIRDBModels](#method_getIRDBModels) | Returns a list of model names based on the specified input parameters |
| [getIRCodesByAutoLookup](#method_getIRCodesByAutoLookup) | Returns a list of available IR codes for the TV and AVRs specified by the input parameters |
| [getIRCodesByNames](#method_getIRCodesByNames) | Returns a list of IR codes for the AV device specified by the input parameters |
| [setIRCode](#method_setIRCode) | Programs an IR code into the specified remote control |
| [clearIRCodes](#method_clearIRCodes) | Clears the IR codes from the specified remote |
| [getLastKeypressSource](#method_getLastKeypressSource) | Returns last key press source data |
| [configureWakeupKeys](#method_configureWakeupKeys) | Configures which keys on the remote will wake the target from deepsleep |
| [initializeIRDB](#method_initializeIRDB) | Initializes the IR database |
| [findMyRemote](#method_findMyRemote) | Tells the most recently used remote to beep |
| [factoryReset](#method_factoryReset) | Tells all paired and connected remotes to factory reset |
| [unpair](#method_unpair) | Unpairs all remotes from the STB |
| [startFirmwareUpdate](#method_startFirmwareUpdate) | Starts a firmware image update session for the specified remote(s) |
| [cancelFirmwareUpdate](#method_cancelFirmwareUpdate) | Cancels an active firmware image update session |
| [statusFirmwareUpdate](#method_statusFirmwareUpdate) | Returns the status of an active firmware image update session |

<a id="method_getApiVersionNumber"></a>
## *getApiVersionNumber [<sup>method</sup>](#head_Methods)*

Gets the current API version number.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The API version response |
| result.version | integer | mandatory | The API version number ex: 1 |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Operation completed successfully. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getApiVersionNumber"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "version": 0,
    "success": false
  }
}
```

<a id="method_getNetStatus"></a>
## *getNetStatus [<sup>method</sup>](#head_Methods)*

Returns the status information provided by the last `onStatus` event for the specified network.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.netType | integer | mandatory | The type of network ex: 1 |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The network status result containing success and a nested status object with netType, pairingState, irProgState, netTypesSupported, and remoteData. remoteData is carried as opaque JSON to preserve the nested JSON response shape across COM-RPC |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.status | object | mandatory | The network status data |
| result.status.netType | integer | mandatory | The type of remote control network ex: 1 |
| result.status.pairingState | string | mandatory | The pairing state (must be one of the following: *COMPLETE, FAILED, IDLE, INITIALISING, PAIRING, SEARCHING*) |
| result.status.irProgState | string | mandatory | The IR programming state (must be one of the following: *COMPLETE, FAILED, IDLE, WAITING*) |
| result.status.netTypesSupported | opaque object | mandatory | JSON array of supported network types e.g. [1] |
| result.status.remoteData | opaque object | mandatory | JSON array of paired remote information. Kept as opaque JSON because of limitations of nesting COM-RPC iterators within struct data which does not preserve the desired status.remoteData response shape |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Network status retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve network status. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getNetStatus",
  "params": {
    "netType": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "status": {
      "netType": 0,
      "pairingState": "IDLE",
      "irProgState": "WAITING",
      "netTypesSupported": {},
      "remoteData": {}
    }
  }
}
```

<a id="method_getIRDBManufacturers"></a>
## *getIRDBManufacturers [<sup>method</sup>](#head_Methods)*

Returns a list of manufacturer names based on the specified input parameters.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| params.manufacturer | string | mandatory | A part of the name of the manufacturer of the AV device e.g. "Sam" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.manufacturers | array | mandatory | A list of manufacturer names e.g. "Samsung" |
| result.manufacturers[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IRDB manufacturers retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve IRDB manufacturers. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getIRDBManufacturers",
  "params": {
    "avDevType": "TV",
    "manufacturer": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "avDevType": "TV",
    "success": false,
    "manufacturers": [
      "..."
    ]
  }
}
```

<a id="method_getIRDBModels"></a>
## *getIRDBModels [<sup>method</sup>](#head_Methods)*

Returns a list of model names based on the specified input parameters.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| params.manufacturer | string | mandatory | The manufacturer name of the AV device e.g. "Samsung" |
| params.model | string | mandatory | A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| result.manufacturer | string | mandatory | The manufacturer name of the AV device e.g. "Samsung" |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.models | array | mandatory | A list of model names e.g. "AH5901068L" |
| result.models[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IRDB models retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve IRDB models. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getIRDBModels",
  "params": {
    "avDevType": "TV",
    "manufacturer": "...",
    "model": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "avDevType": "TV",
    "manufacturer": "...",
    "success": false,
    "models": [
      "..."
    ]
  }
}
```

<a id="method_getIRCodesByAutoLookup"></a>
## *getIRCodesByAutoLookup [<sup>method</sup>](#head_Methods)*

Returns a list of available IR codes for the TV and AVRs specified by the input parameters.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.netType | integer | mandatory | The type of network ex: 1 |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.tvManufacturer | string | mandatory | The TV manufacturer for which codes are provided e.g. "Samsung" |
| result.tvModel | string | mandatory | The TV model for which codes are provided e.g. "UN65JU750" |
| result.avrManufacturer | string | mandatory | The AVR manufacturer for which codes are provided e.g. "Denon" |
| result.avrModel | string | mandatory | The AVR model for which codes are provided e.g. "AVR-S750H" |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.tvCodes | array | mandatory | A list of TV IR codes e.g. "1156" |
| result.tvCodes[#] | string | mandatory | *...* |
| result.avrCodes | array | mandatory | A list of AVR IR codes e.g. "R2467" |
| result.avrCodes[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IR codes retrieved successfully by auto lookup. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve IR codes by auto lookup. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getIRCodesByAutoLookup",
  "params": {
    "netType": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "tvManufacturer": "...",
    "tvModel": "...",
    "avrManufacturer": "...",
    "avrModel": "...",
    "success": false,
    "tvCodes": [
      "..."
    ],
    "avrCodes": [
      "..."
    ]
  }
}
```

<a id="method_getIRCodesByNames"></a>
## *getIRCodesByNames [<sup>method</sup>](#head_Methods)*

Returns a list of IR codes for the AV device specified by the input parameters.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| params.manufacturer | string | mandatory | The manufacturer name of the AV device e.g. "Samsung" |
| params.model | string | mandatory | A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| result.manufacturer | string | mandatory | The manufacturer name of the AV device e.g. "Samsung" |
| result.model | string | mandatory | A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6" |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.codes | opaque object | mandatory | A list of IR codes as a string |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IR codes retrieved successfully by names. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve IR codes by names. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getIRCodesByNames",
  "params": {
    "avDevType": "TV",
    "manufacturer": "...",
    "model": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "avDevType": "TV",
    "manufacturer": "...",
    "model": "...",
    "success": false,
    "codes": {}
  }
}
```

<a id="method_setIRCode"></a>
## *setIRCode [<sup>method</sup>](#head_Methods)*

Programs an IR code into the specified remote control.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The remote ID of the target remote on the specified network ex: 1 |
| params.netType | integer | mandatory | The type of network ex: 1 |
| params.avDevType | string | mandatory | Whether the device is a video (TV) or audio (AMP) device (must be one of the following: *AMP, INVALID, TV*) |
| params.code | string | mandatory | The IR code being programmed into the remote e.g. "PANASONIC_3DTV" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IR code set successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to set IR code. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setIRCode",
  "params": {
    "remoteId": 0,
    "netType": 0,
    "avDevType": "TV",
    "code": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_clearIRCodes"></a>
## *clearIRCodes [<sup>method</sup>](#head_Methods)*

Clears the IR codes from the specified remote.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The remote ID of the target remote on the specified network ex: 1 |
| params.netType | integer | mandatory | The type of network ex: 1 |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IR codes cleared successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to clear IR codes. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.clearIRCodes",
  "params": {
    "remoteId": 0,
    "netType": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getLastKeypressSource"></a>
## *getLastKeypressSource [<sup>method</sup>](#head_Methods)*

Returns last key press source data.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The last keypress source response |
| result.controllerId | integer | mandatory | The controller ID of the target remote on the specified network ex: 1 |
| result.timestamp | integer | mandatory | The time of the last key press in milliseconds since epoch |
| result.sourceName | string | mandatory | The source of the last key press e.g. "IR" |
| result.sourceType | string | mandatory | The source type of the last key press e.g. "REMOTE" |
| result.sourceKeyCode | integer | mandatory | The source key code ex: 195 |
| result.bIsScreenBindMode | boolean | mandatory | True if in screen bind mode, otherwise false |
| result.remoteKeypadConfig | integer | mandatory | The configuration of the remote keypad ex: 0 |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Last keypress source retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve last keypress source. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getLastKeypressSource"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "controllerId": 0,
    "timestamp": 0,
    "sourceName": "...",
    "sourceType": "...",
    "sourceKeyCode": 0,
    "bIsScreenBindMode": false,
    "remoteKeypadConfig": 0,
    "success": false
  }
}
```

<a id="method_configureWakeupKeys"></a>
## *configureWakeupKeys [<sup>method</sup>](#head_Methods)*

Configures which keys on the remote will wake the target from deepsleep.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.wakeupConfig | string | mandatory | The deepsleep wakeup key configuration of the remote. Possible values: all (all keys on the remote will wake target from deepsleep), none (no keys will wake target), custom (the custom list of Linux key codes in customKeys will wake target) (must be one of the following: *INVALID, all, custom, none*) |
| params?.customKeys | string | optional | List of Linux key codes that can wake the target from deepsleep. Mandatory if wakeupConfig is custom, otherwise should be omitted e.g. "195,199" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Wakeup keys configured successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to configure wakeup keys. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.configureWakeupKeys",
  "params": {
    "wakeupConfig": "all",
    "customKeys": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_initializeIRDB"></a>
## *initializeIRDB [<sup>method</sup>](#head_Methods)*

Initializes the IR database.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.netType | integer | mandatory | The type of network ex: 1 |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | IRDB initialized successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to initialize IRDB. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.initializeIRDB",
  "params": {
    "netType": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_findMyRemote"></a>
## *findMyRemote [<sup>method</sup>](#head_Methods)*

Tells the most recently used remote to beep.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.level | string | mandatory | The level at which the remote will beep (must be one of the following: *INVALID, high, mid, off*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Find my remote executed successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to execute find my remote. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.findMyRemote",
  "params": {
    "level": "off"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_factoryReset"></a>
## *factoryReset [<sup>method</sup>](#head_Methods)*

Tells all paired and connected remotes to factory reset.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Factory reset executed successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to execute factory reset. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.factoryReset"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_unpair"></a>
## *unpair [<sup>method</sup>](#head_Methods)*

Unpairs all remotes from the STB.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.macAddressList | array | optional | *...* |
| params?.macAddressList[#] | string | optional | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Unpair executed successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to execute unpair. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.unpair",
  "params": {
    "macAddressList": [
      "..."
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_startFirmwareUpdate"></a>
## *startFirmwareUpdate [<sup>method</sup>](#head_Methods)*

Starts a firmware image update session for the specified remote(s).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.macAddress | string | optional | *...* |
| params.fileName | string | mandatory | The full path and filename for the firmware image e.g. "/tmp/remote_firmware.bin" |
| params?.fileType | string | optional | *...* |
| params?.percentIncrement | integer | optional | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.sessionIdList | array | mandatory | List of session IDs created for the firmware update(s) |
| result.sessionIdList[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Firmware update started successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to start firmware update. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.startFirmwareUpdate",
  "params": {
    "macAddress": "...",
    "fileName": "...",
    "fileType": "...",
    "percentIncrement": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "sessionIdList": [
      "..."
    ]
  }
}
```

<a id="method_cancelFirmwareUpdate"></a>
## *cancelFirmwareUpdate [<sup>method</sup>](#head_Methods)*

Cancels an active firmware image update session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | string | mandatory | The session identifier e.g. "12345-abc-def" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Firmware update cancelled successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to cancel firmware update. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.cancelFirmwareUpdate",
  "params": {
    "sessionId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_statusFirmwareUpdate"></a>
## *statusFirmwareUpdate [<sup>method</sup>](#head_Methods)*

Returns the status of an active firmware image update session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | string | mandatory | The session identifier e.g. "12345-abc-def" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The firmware update status with success at top level and details nested under status (upgradeSessionId, macAddress, upgradeState, percentComplete, optional errorString) |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.status | object | mandatory | The firmware update status details including session ID, MAC address, upgrade state, and percent complete |
| result.status.upgradeSessionId | string | mandatory | The firmware update session identifier ex: 12345-abc-def |
| result.status.macAddress | string | mandatory | The MAC address of the remote in hex-colon format e.g. "AA:BB:CC:DD:EE:FF" |
| result.status.upgradeState | string | mandatory | The firmware update state (must be one of the following: *canceled, error, idle, invalid, pending, retrying, success*) |
| result.status.percentComplete | integer | mandatory | The estimated percentage of the firmware update that has completed (0-100) ex: 50 |
| result.status?.errorString | string | optional | The firmware update error string, only present on failure |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Firmware update status retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve firmware update status. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.statusFirmwareUpdate",
  "params": {
    "sessionId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "status": {
      "upgradeSessionId": "...",
      "macAddress": "...",
      "upgradeState": "idle",
      "percentComplete": 0,
      "errorString": "..."
    }
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the RemoteControl interface:

RemoteControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [onStatus](#notification_onStatus) | Triggered at any time when the status of any one of the supported STB remote networks changes |
| [onValidation](#notification_onValidation) | Generated for manual pairing validation |
| [onFirmwareUpdateProgress](#notification_onFirmwareUpdateProgress) | Generated at 0 and 100 percent and each time a download percent increment is reached |

<a id="notification_onStatus"></a>
## *onStatus [<sup>notification</sup>](#head_Notifications)*

Triggered at any time when the status of any one of the supported STB remote networks changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | object | mandatory | Network status information including network type, pairing state, and IR programming state |
| params.status.netType | integer | mandatory | The type of remote control network ex: 1 |
| params.status.pairingState | string | mandatory | The pairing state (must be one of the following: *COMPLETE, FAILED, IDLE, INITIALISING, PAIRING, SEARCHING*) |
| params.status.irProgState | string | mandatory | The IR programming state (must be one of the following: *COMPLETE, FAILED, IDLE, WAITING*) |
| params.status.netTypesSupported | opaque object | mandatory | JSON array of supported network types e.g. [1] |
| params.status.remoteData | opaque object | mandatory | JSON array of paired remote information. Kept as opaque JSON because of limitations of nesting COM-RPC iterators within struct data which does not preserve the desired status.remoteData response shape |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onStatus",
  "params": {
    "status": {
      "netType": 0,
      "pairingState": "IDLE",
      "irProgState": "WAITING",
      "netTypesSupported": {},
      "remoteData": {}
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onStatus``.

<a id="notification_onValidation"></a>
## *onValidation [<sup>notification</sup>](#head_Notifications)*

Generated for manual pairing validation.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | object | mandatory | Validation information including network type and validation digits for manual pairing |
| params.status.netType | integer | mandatory | The type of remote control network ex: 1 |
| params.status.validationDigit1 | integer | mandatory | The first validation digit ex: 1 |
| params.status.validationDigit2 | integer | mandatory | The second validation digit ex: 2 |
| params.status.validationDigit3 | integer | mandatory | The third validation digit ex: 3 |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onValidation",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onValidation",
  "params": {
    "status": {
      "netType": 0,
      "validationDigit1": 0,
      "validationDigit2": 0,
      "validationDigit3": 0
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onValidation``.

<a id="notification_onFirmwareUpdateProgress"></a>
## *onFirmwareUpdateProgress [<sup>notification</sup>](#head_Notifications)*

Generated at 0 and 100 percent and each time a download percent increment is reached.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | object | mandatory | Firmware update status including session ID, MAC address, upgrade state, and percent complete |
| params.status.upgradeSessionId | string | mandatory | The firmware update session identifier ex: 12345-abc-def |
| params.status.macAddress | string | mandatory | The MAC address of the remote in hex-colon format e.g. "AA:BB:CC:DD:EE:FF" |
| params.status.upgradeState | string | mandatory | The firmware update state (must be one of the following: *canceled, error, idle, invalid, pending, retrying, success*) |
| params.status.percentComplete | integer | mandatory | The estimated percentage of the firmware update that has completed (0-100) ex: 50 |
| params.status?.errorString | string | optional | The firmware update error string, only present on failure |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFirmwareUpdateProgress",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFirmwareUpdateProgress",
  "params": {
    "status": {
      "upgradeSessionId": "...",
      "macAddress": "...",
      "upgradeState": "idle",
      "percentComplete": 0,
      "errorString": "..."
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFirmwareUpdateProgress``.

