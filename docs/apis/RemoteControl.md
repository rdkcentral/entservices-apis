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
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.RemoteControl.cancelFirmwareUpdate",
    "params": {
        "sessionId": "12345-abc-def"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.RemoteControl.cancelFirmwareUpdate", "params": {"sessionId": "12345-abc-def"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.remoteId | integer | The remote ID of the target remote on the specified network e.g. 1 |
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
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.RemoteControl.clearIRCodes", "params": {"remoteId": 0, "netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.RemoteControl.configureWakeupKeys",
    "params": {
        "wakeupConfig": "all",
        "customKeys": "195,199"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.RemoteControl.configureWakeupKeys", "params": {"wakeupConfig": "all", "customKeys": "195,199"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.RemoteControl.factoryReset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.RemoteControl.factoryReset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.level | string | The level at which the remote will beep |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.RemoteControl.findMyRemote",
    "params": {
        "level": "off"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.RemoteControl.findMyRemote", "params": {"level": "off"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.RemoteControl.getApiVersionNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.RemoteControl.getApiVersionNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| result.response | GetIRCodesByAutoLookupResponse | The get IR codes by auto lookup response |
| result.response.tvManufacturer | string | The TV manufacturer for which codes are provided  |
| result.response.tvModel | string | The TV model for which codes are provided  |
| result.response.avrManufacturer | string | The AVR manufacturer for which codes are provided  |
| result.response.avrModel | string | The AVR model for which codes are provided  |
| result.response.success | bool | Whether the request succeeded |
| result.tvCodes | IStringIterator | A list of TV IR codes |
| result.tvCodes[#] | string |  |
| result.avrCodes | IStringIterator | A list of AVR IR codes @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup. |
| result.avrCodes[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup",
    "params": {
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": {
        "response": {
            "tvManufacturer": "Samsung",
            "tvModel": "UN65JU750",
            "avrManufacturer": "Denon",
            "avrModel": "AVR-S750H",
            "success": true
        },
        "tvCodes": [
            ""
        ],
        "avrCodes": [
            ""
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
| params.manufacturer | string | The manufacturer name of the AV device  |
| params.model | string | The model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRCodesByNamesResponse | The get IR codes by names response |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.response.manufacturer | string | The manufacturer name of the AV device  |
| result.response.model | string | The model name of the AV device  |
| result.response.success | bool | Whether the request succeeded |
| result.codes | IStringIterator | A list of IR codes for the specified device @retval ErrorCode::NONE: IR codes retrieved successfully by names. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names. |
| result.codes[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.RemoteControl.getIRCodesByNames", "params": {"avDevType": "TV", "manufacturer": "Samsung", "model": "UN65JU750"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": {
        "response": {
            "avDevType": "TV",
            "manufacturer": "Samsung",
            "model": "UN65JU750",
            "success": true
        },
        "codes": [
            ""
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
| result.response | GetIRDBManufacturersResponse | The get IRDB manufacturers response |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.response.success | bool | Whether the request succeeded |
| result.manufacturers | IStringIterator | A list of manufacturer names @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers. |
| result.manufacturers[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.RemoteControl.getIRDBManufacturers", "params": {"avDevType": "TV", "manufacturer": "Sam"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": {
        "response": {
            "avDevType": "TV",
            "success": true
        },
        "manufacturers": [
            ""
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
| params.manufacturer | string | The manufacturer name of the AV device  |
| params.model | string | A part (minimum of 3 characters) of the model name of the AV device  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRDBModelsResponse | The get IRDB models response |
| result.response.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
| result.response.manufacturer | string | The manufacturer name of the AV device  |
| result.response.success | bool | Whether the request succeeded |
| result.models | IStringIterator | A list of model names @retval ErrorCode::NONE: IRDB models retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB models. |
| result.models[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.RemoteControl.getIRDBModels", "params": {"avDevType": "TV", "manufacturer": "Samsung", "model": "UN6"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": {
        "response": {
            "avDevType": "TV",
            "manufacturer": "Samsung",
            "success": true
        },
        "models": [
            ""
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
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.RemoteControl.getLastKeypressSource"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.RemoteControl.getLastKeypressSource"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| result.response | GetNetStatusResponse | The network status response |
| result.response.netType | integer | The type of network e.g. 1 |
| result.response.pairingState | string | The current overall pairing state of the specified network |
| result.response.irProgState | string | The current state of the IR code programming request to the remote |
| result.response.success | bool | Whether the request succeeded |
| result.netTypeSupported | IUint32Iterator | A list of the network types that the STB supports |
| result.netTypeSupported[#] | uint32_t |  |
| result.remoteData | IRemoteDataIterator | Remote information for each paired remote control @retval ErrorCode::NONE: Network status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve network status. |
| result.remoteData[#].macAddress | string | The MAC address of the remote in hex-colon format  |
| result.remoteData[#].connected | bool | True if the remote is connected, otherwise false |
| result.remoteData[#].name | string | The remote name  |
| result.remoteData[#].remoteId | integer | This integer is the remote ID number, assigned by the network |
| result.remoteData[#].deviceId | integer | The device ID number that is assigned by the network |
| result.remoteData[#].make | string | The manufacturer name of the remote  |
| result.remoteData[#].model | string | The remote model name  |
| result.remoteData[#].hwVersion | string | The remote hardware revision |
| result.remoteData[#].swVersion | string | The remote software revision |
| result.remoteData[#].btlVersion | string | The remote bootloader revision |
| result.remoteData[#].serialNumber | string | The remote serial number |
| result.remoteData[#].batteryPercent | integer | The current remote battery level as a percentage (0 to 100) |
| result.remoteData[#].tvIRCode | string | The current TV IR code that the remote is programmed with. If the remote is not presently programmed with an IR code or if the TV IR code is not known, then this field may be empty |
| result.remoteData[#].ampIRCode | string | The current AVR |
| result.remoteData[#].wakeupKeyCode | integer | The Linux key code of the last button to be pressed on the remote before wakeup from deepsleep |
| result.remoteData[#].wakeupConfig | string | The current deepsleep wakeup key configuration of the remote. Possible values: "all" (all keys on the remote will wake target from deepsleep), "none" (no keys will wake target), "custom" (the custom list of Linux key codes in wakeupCustomList will wake target) |
| result.remoteData[#].wakeupCustomList | string | List of linux keycodes that can wake the target from deepsleep. Only present if wakeupConfig is "custom" |
| result.remoteData[#].upgradeSessionId | string | The unique identifier for the firmware update session, generated by the underlying RDK stack |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.RemoteControl.getNetStatus",
    "params": {
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.RemoteControl.getNetStatus", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": {
        "response": {
            "netType": 0,
            "pairingState": "INITIALISING",
            "irProgState": "IDLE",
            "success": true
        },
        "netTypeSupported": [
            0
        ],
        "remoteData": [
            {
                "macAddress": "AA:BB:CC:DD:EE:FF",
                "connected": true,
                "name": "XR15-700",
                "remoteId": 0,
                "deviceId": 0,
                "make": "Technicolor",
                "model": "XR15",
                "hwVersion": "",
                "swVersion": "",
                "btlVersion": "",
                "serialNumber": "",
                "batteryPercent": 0,
                "tvIRCode": "",
                "ampIRCode": "",
                "wakeupKeyCode": 0,
                "wakeupConfig": "",
                "wakeupCustomList": "",
                "upgradeSessionId": ""
            }
        ]
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
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.RemoteControl.initializeIRDB",
    "params": {
        "netType": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.RemoteControl.initializeIRDB", "params": {"netType": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.remoteId | integer | The remote ID of the target remote on the specified network e.g. 1 |
| params.netType | integer | The type of network e.g. 1 |
| params.avDevType | string | Whether the device is a video (TV) or audio (AMP) device |
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
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.RemoteControl.setIRCode", "params": {"remoteId": 0, "netType": 0, "avDevType": "TV", "code": "PANASONIC_3DTV"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.macAddress | string | The MAC address of the target remote in hex-colon format  |
| params.fileName | string | The full path and filename for the firmware image e.g. " |
| params.fileType | string | The type of firmware image file  |
| params.percentIncrement | integer | The increment change of a firmware update to notify. Valid range 1-100 percent e.g. 10 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |
| result.sessionIdList | IStringIterator | List of session IDs created for the firmware update(s) @retval ErrorCode::NONE: Firmware update started successfully. @retval ErrorCode::GENERAL: Failed to start firmware update. |
| result.sessionIdList[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.RemoteControl.startFirmwareUpdate", "params": {"macAddress": "AA:BB:CC:DD:EE:FF", "fileName": "", "fileType": "mfg", "percentIncrement": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": {
        "response": {
            "success": true
        },
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
| params.request | StartPairingRequest | The pairing request parameters |
| params.request.netType | integer | The type of network e.g. 1 |
| params.request.timeout | integer | The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout) e.g. 30 |
| params.request.screenBindEnable | bool | Whether to enable screen bind mode (default: true) |
| params.request.scanEnable | bool | Whether to enable scanning for remotes (default: true) |
| params.macAddressList | IStringIterator | Optional list of MAC addresses to pair with (only used if scanEnable is true) @retval ErrorCode::NONE: Pairing started successfully. @retval ErrorCode::GENERAL: Failed to start pairing. |
| params.macAddressList[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.RemoteControl.startPairing",
    "params": {
        "request": {
            "netType": 0,
            "timeout": 0,
            "screenBindEnable": true,
            "scanEnable": true
        },
        "macAddressList": [
            ""
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 15, "method": "org.rdk.RemoteControl.startPairing", "params": {"request": {"netType": 0, "timeout": 0, "screenBindEnable": true, "scanEnable": true}, "macAddressList": [""]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.sessionId | string | The session identifier  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StatusFirmwareUpdateResponse | The status firmware update response @retval ErrorCode::NONE: Firmware update status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve firmware update status. |
| result.response.result | FirmwareUpdateStatus | The firmware update status |
| result.response.result.state | string | The firmware update state |
| result.response.result.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100) e.g. 50 |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "sessionId": "12345-abc-def"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 16, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"sessionId": "12345-abc-def"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.screenBindDisable | bool | Whether to disable screen bind mode (default: true) |
| params.scanDisable | bool | Whether to disable scanning for remotes (default: true) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 17, "method": "org.rdk.RemoteControl.stopPairing", "params": {"screenBindDisable": true, "scanDisable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.macAddressList | IStringIterator | Optional list of MAC addresses to pair with (only used if scanEnable is true) @retval ErrorCode::NONE: Pairing started successfully. @retval ErrorCode::GENERAL: Failed to start pairing. |
| params.macAddressList[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.RemoteControl.unpair",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 18, "method": "org.rdk.RemoteControl.unpair", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
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
| params.sessionId | integer | The session identifier e.g. 12345 |
| params.status | FirmwareUpdateStatus | The firmware update status |
| params.status.state | string | The firmware update state |
| params.status.percentComplete | integer | The estimated percentage of the firmware update that has completed (0-100) e.g. 50 |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "method": "client.events.onFirmwareUpdateProgress",
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
| params.netType | integer | The type of remote control network e.g. 1 |
| params.netTypeSupported | bool | Whether the network type is supported |
| params.pairingState | string | The pairing state |
| params.irProgState | string | The IR programming state |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "method": "client.events.onStatus",
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
| params.netType | integer | The type of remote control network e.g. 1 |
| params.validationDigit1 | integer | The first validation digit e.g. 1 |
| params.validationDigit2 | integer | The second validation digit e.g. 2 |
| params.validationDigit3 | integer | The third validation digit e.g. 3 |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "method": "client.events.onValidation",
    "params": {
        "netType": 0,
        "validationDigit1": 0,
        "validationDigit2": 0,
        "validationDigit3": 0
    }
}
```
