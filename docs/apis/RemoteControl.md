<!-- Generated automatically, DO NOT EDIT! -->
<a id="RemoteControl_Plugin"></a>
# RemoteControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RemoteControl/IRemoteControlStructs.h)**

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
| [factoryReset @retval ErrorCode::NONE: Factory reset executed successfully. @retval ErrorCode::GENERAL: Failed to execute factory reset.](#factoryReset @retval ErrorCode::NONE: Factory reset executed successfully. @retval ErrorCode::GENERAL: Failed to execute factory reset.) | Tells all paired and connected remotes to factory reset |
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
| [unpair](#unpair) | Unpairs a given or all remote(s) from the STB |

<a id="cancelFirmwareUpdate"></a>
## *cancelFirmwareUpdate*

Cancels an active firmware image update session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | CancelFirmwareUpdateRequest | The cancel firmware update request parameters @retval ErrorCode::NONE: Firmware update cancelled successfully. @retval ErrorCode::GENERAL: Failed to cancel firmware update. |
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
    "method": "org.rdk.RemoteControl.cancelFirmwareUpdate",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RemoteControl.cancelFirmwareUpdate", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
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
| params.request | ClearIRCodesRequest | The clear IR codes request parameters @retval ErrorCode::NONE: IR codes cleared successfully. @retval ErrorCode::GENERAL: Failed to clear IR codes. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.RemoteControl.clearIRCodes",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RemoteControl.clearIRCodes", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
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
| params.request | ConfigureWakeupKeysRequest | The configure wakeup keys request parameters @retval ErrorCode::NONE: Wakeup keys configured successfully. @retval ErrorCode::GENERAL: Failed to configure wakeup keys. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.RemoteControl.configureWakeupKeys",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RemoteControl.configureWakeupKeys", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
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
| result | null | On success null will be returned. |

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
    "result": null
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
| params.request | FindMyRemoteRequest | The find my remote request parameters @retval ErrorCode::NONE: Find my remote executed successfully. @retval ErrorCode::GENERAL: Failed to execute find my remote. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.RemoteControl.findMyRemote",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RemoteControl.findMyRemote", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
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
| params.request | GetIRCodesByAutoLookupRequest | The get IR codes by auto lookup request parameters |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRCodesByAutoLookupResponse | The IR codes by auto lookup response @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "response": ""
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
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRCodesByNamesResponse | The get IR codes by names response @retval ErrorCode::NONE: IR codes retrieved successfully by names. @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RemoteControl.getIRCodesByNames",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RemoteControl.getIRCodesByNames", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "response": ""
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
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRDBManufacturersResponse | The get IRDB manufacturers response @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RemoteControl.getIRDBManufacturers",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RemoteControl.getIRDBManufacturers", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "response": ""
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
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetIRDBModelsResponse | The get IRDB models response @retval ErrorCode::NONE: IRDB models retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve IRDB models. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RemoteControl.getIRDBModels",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RemoteControl.getIRDBModels", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "response": ""
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
        "response": ""
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
| params.request | GetNetStatusRequest | The network status request parameters |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | GetNetStatusResponse | The network status response @retval ErrorCode::NONE: Network status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve network status. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.RemoteControl.getNetStatus",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.RemoteControl.getNetStatus", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "response": ""
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
| params.request | InitializeIRDBRequest | The initialize IRDB request parameters @retval ErrorCode::NONE: IRDB initialized successfully. @retval ErrorCode::GENERAL: Failed to initialize IRDB. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.RemoteControl.initializeIRDB",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.RemoteControl.initializeIRDB", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
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
| params.request | SetIRCodeRequest | The set IR code request parameters @retval ErrorCode::NONE: IR code set successfully. @retval ErrorCode::GENERAL: Failed to set IR code. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.RemoteControl.setIRCode",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.RemoteControl.setIRCode", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
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
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StartFirmwareUpdateResponse | The start firmware update response @retval ErrorCode::NONE: Firmware update started successfully. @retval ErrorCode::GENERAL: Failed to start firmware update. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.RemoteControl.startFirmwareUpdate",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.RemoteControl.startFirmwareUpdate", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "response": ""
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
| params.request | StartPairingRequest | The pairing request parameters @retval ErrorCode::NONE: Pairing started successfully. @retval ErrorCode::GENERAL: Failed to start pairing. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.RemoteControl.startPairing",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RemoteControl.startPairing", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
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
| params.request | StatusFirmwareUpdateRequest | The status firmware update request parameters |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | StatusFirmwareUpdateResponse | The status firmware update response @retval ErrorCode::NONE: Firmware update status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve firmware update status. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "response": ""
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
| params.request | StopPairingRequest | The stop pairing request parameters @retval ErrorCode::NONE: Pairing stopped successfully. @retval ErrorCode::GENERAL: Failed to stop pairing. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.RemoteControl.stopPairing",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.RemoteControl.stopPairing", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="unpair"></a>
## *unpair*

Unpairs a given or all remote(s) from the STB

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | UnpairRequest | The unpair request parameters @retval ErrorCode::NONE: Remote unpaired successfully. @retval ErrorCode::GENERAL: Failed to unpair remote. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.RemoteControl.unpair",
    "params": {
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.RemoteControl.unpair", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
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
| params.progress | FirmwareUpdateProgressEvent | Event data containing firmware update progress information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RemoteControl.onFirmwareUpdateProgress",
    "params": {
        "progress": ""
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
| params.status | StatusEventData | Event data containing remote control status information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.RemoteControl.onStatus",
    "params": {
        "status": ""
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
| params.status | ValidationStatusObject | Event data containing remote control validation information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.RemoteControl.onValidation",
    "params": {
        "status": ""
    }
}
```
