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
| [cancelFirmwareUpdate](#cancelFirmwareUpdate) | Cancel firmware update |
| [clearIRCodes](#clearIRCodes) | Clear IR codes |
| [configureWakeupKeys](#configureWakeupKeys) | Configure wakeup keys |
| [factoryReset](#factoryReset) | Factory reset |
| [findMyRemote](#findMyRemote) | Find my remote |
| [getApiVersionNumber](#getApiVersionNumber) | Get the API version number |
| [getIRCodesByAutoLookup](#getIRCodesByAutoLookup) | Get IR codes by auto lookup |
| [getIRCodesByNames](#getIRCodesByNames) | Get IR codes by names |
| [getIRDBManufacturers](#getIRDBManufacturers) | Get IRDB manufacturers |
| [getIRDBModels](#getIRDBModels) | Get IRDB models |
| [getLastKeypressSource](#getLastKeypressSource) | Get last keypress source |
| [getNetStatus](#getNetStatus) | Get network status |
| [initializeIRDB](#initializeIRDB) | Initialize IRDB |
| [setIRCode](#setIRCode) | Set IR code |
| [startFirmwareUpdate](#startFirmwareUpdate) | Start firmware update |
| [startPairing](#startPairing) | Start pairing process |
| [statusFirmwareUpdate](#statusFirmwareUpdate) | Get firmware update status |
| [stopPairing](#stopPairing) | Stop pairing process |
| [unpair](#unpair) | Unpair remote |

<a id="cancelFirmwareUpdate"></a>
## *cancelFirmwareUpdate*

Cancel firmware update

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RemoteControl.cancelFirmwareUpdate", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Clear IR codes

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RemoteControl.clearIRCodes", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Configure wakeup keys

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RemoteControl.configureWakeupKeys", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Factory reset

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
    "method": "org.rdk.RemoteControl.factoryReset",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.RemoteControl.factoryReset", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Find my remote

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RemoteControl.findMyRemote", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Get the API version number

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.RemoteControl.getApiVersionNumber",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.RemoteControl.getApiVersionNumber", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="getIRCodesByAutoLookup"></a>
## *getIRCodesByAutoLookup*

Get IR codes by auto lookup

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RemoteControl.getIRCodesByAutoLookup", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="getIRCodesByNames"></a>
## *getIRCodesByNames*

Get IR codes by names

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RemoteControl.getIRCodesByNames",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RemoteControl.getIRCodesByNames", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="getIRDBManufacturers"></a>
## *getIRDBManufacturers*

Get IRDB manufacturers

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RemoteControl.getIRDBManufacturers",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RemoteControl.getIRDBManufacturers", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="getIRDBModels"></a>
## *getIRDBModels*

Get IRDB models

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RemoteControl.getIRDBModels",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RemoteControl.getIRDBModels", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="getLastKeypressSource"></a>
## *getLastKeypressSource*

Get last keypress source

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.RemoteControl.getLastKeypressSource",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.RemoteControl.getLastKeypressSource", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="getNetStatus"></a>
## *getNetStatus*

Get network status

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.RemoteControl.getNetStatus",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.RemoteControl.getNetStatus", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="initializeIRDB"></a>
## *initializeIRDB*

Initialize IRDB

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.RemoteControl.initializeIRDB", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Set IR code

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.RemoteControl.setIRCode", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Start firmware update

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.RemoteControl.startFirmwareUpdate",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.RemoteControl.startFirmwareUpdate", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="startPairing"></a>
## *startPairing*

Start pairing process

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RemoteControl.startPairing", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Get firmware update status

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RemoteControl.statusFirmwareUpdate",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RemoteControl.statusFirmwareUpdate", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="stopPairing"></a>
## *stopPairing*

Stop pairing process

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.RemoteControl.stopPairing", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Unpair remote

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters |
| params.response | JsonObject | JSON response object @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.RemoteControl.unpair", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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
| [onFirmwareUpdateProgress](#onFirmwareUpdateProgress) | Firmware update progress event |
| [onStatus](#onStatus) | Status event |
| [onValidation](#onValidation) | Validation event |

<a id="onFirmwareUpdateProgress"></a>
## *onFirmwareUpdateProgress*

Firmware update progress event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_main_iarm_event_json_t | Pointer to event data containing remote control status information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RemoteControl.onFirmwareUpdateProgress",
    "params": {
        "eventData": ""
    }
}
```

<a id="onStatus"></a>
## *onStatus*

Status event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_main_iarm_event_json_t | Pointer to event data containing remote control status information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.RemoteControl.onStatus",
    "params": {
        "eventData": ""
    }
}
```

<a id="onValidation"></a>
## *onValidation*

Validation event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_main_iarm_event_json_t | Pointer to event data containing remote control status information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.RemoteControl.onValidation",
    "params": {
        "eventData": ""
    }
}
```
