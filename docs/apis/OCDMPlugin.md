<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.OCDM_Plugin"></a>
# OCDM Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/OCDM/CHANGELOG.md)**

A OCDM plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `OCDM` plugin provides an interface for OCDM.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.OCDM) |
| classname | string | Class name: *OCDM* |
| locator | string | Library name: *libWPEFrameworkOCDM.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the OCDM plugin:

OCDM interface methods:

| Method | Description |
| :-------- | :-------- |
| [bufferId](#method.bufferId) |  |
| [bufferIdExt](#method.bufferIdExt) |  |
| [cancelChallengeDataExt](#method.cancelChallengeDataExt) |  |
| [cleanDecryptContext](#method.cleanDecryptContext) |  |
| [close](#method.close) |  |
| [createSessionBuffer](#method.createSessionBuffer) |  |
| [deleteKeyStore](#method.deleteKeyStore) |  |
| [deleteSecureStore](#method.deleteSecureStore) |  |
| [getDrmSystemTime](#method.getDrmSystemTime) |  |
| [getLdlSessionLimit](#method.getLdlSessionLimit) |  |
| [getVersionExt](#method.getVersionExt) |  |
| [isSecureStopEnabled](#method.isSecureStopEnabled) |  |
| [isTypeSupported](#method.isTypeSupported) |  |
| [load](#method.load) |  |
| [metadata](#method.metadata) |  |
| [onError](#method.onError) |  |
| [onKeyMessage](#method.onKeyMessage) |  |
| [onKeyStatusUpdate](#method.onKeyStatusUpdate) |  |
| [onKeyStatusesUpdated](#method.onKeyStatusesUpdated) |  |
| [remove](#method.remove) |  |
| [resetOutputProtection](#method.resetOutputProtection) |  |
| [resetSecureStops](#method.resetSecureStops) |  |
| [revoke](#method.revoke) |  |
| [sessionId](#method.sessionId) |  |
| [sessionIdExt](#method.sessionIdExt) |  |
| [setParameter](#method.setParameter) |  |
| [status](#method.status) |  |

<a id="method.bufferId"></a>
## *bufferId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.OCDM.bufferId"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.bufferIdExt"></a>
## *bufferIdExt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.OCDM.bufferIdExt"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.cancelChallengeDataExt"></a>
## *cancelChallengeDataExt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.OCDM.cancelChallengeDataExt"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.cleanDecryptContext"></a>
## *cleanDecryptContext [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.OCDM.cleanDecryptContext"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="method.close"></a>
## *close [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.OCDM.close"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="method.createSessionBuffer"></a>
## *createSessionBuffer [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.bufferID | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.OCDM.createSessionBuffer"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": ""
}
```

<a id="method.deleteKeyStore"></a>
## *deleteKeyStore [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.OCDM.deleteKeyStore",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="method.deleteSecureStore"></a>
## *deleteSecureStore [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.OCDM.deleteSecureStore",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.getDrmSystemTime"></a>
## *getDrmSystemTime [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.OCDM.getDrmSystemTime",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.getLdlSessionLimit"></a>
## *getLdlSessionLimit [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.OCDM.getLdlSessionLimit",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.getVersionExt"></a>
## *getVersionExt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.OCDM.getVersionExt",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.isSecureStopEnabled"></a>
## *isSecureStopEnabled [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.OCDM.isSecureStopEnabled",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.isTypeSupported"></a>
## *isTypeSupported [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
| params.mimeType | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.OCDM.isTypeSupported",
    "params": {
        "keySystem": "",
        "mimeType": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.load"></a>
## *load [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.OCDM.load"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.metadata"></a>
## *metadata [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.metadata | std::string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.OCDM.metadata",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": ""
}
```

<a id="method.onError"></a>
## *onError [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.error | int16_t | - |
| params.sysError | OCDM_RESULT | - |
| params.errorMessage | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.OCDM.onError",
    "params": {
        "error": "",
        "sysError": "OCDM_SUCCESS",
        "errorMessage": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="method.onKeyMessage"></a>
## *onKeyMessage [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyMessage | uint8_t | - |
| params.keyLength | uint16_t | - |
| params.URL | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.OCDM.onKeyMessage",
    "params": {
        "keyMessage": "",
        "keyLength": "",
        "URL": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="method.onKeyStatusUpdate"></a>
## *onKeyStatusUpdate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyID[] | uint8_t | - |
| params.keyIDLength | uint8_t | - |
| params.status | ISession::KeyStatus | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.OCDM.onKeyStatusUpdate",
    "params": {
        "keyID[]": "",
        "keyIDLength": "",
        "status": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="method.onKeyStatusesUpdated"></a>
## *onKeyStatusesUpdated [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.OCDM.onKeyStatusesUpdated"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="method.remove"></a>
## *remove [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.OCDM.remove"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="method.resetOutputProtection"></a>
## *resetOutputProtection [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.OCDM.resetOutputProtection"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="method.resetSecureStops"></a>
## *resetSecureStops [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keySystem | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.OCDM.resetSecureStops",
    "params": {
        "keySystem": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="method.revoke"></a>
## *revoke [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callback | ISession::ICallback | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.OCDM.revoke",
    "params": {
        "callback": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="method.sessionId"></a>
## *sessionId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.OCDM.sessionId"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="method.sessionIdExt"></a>
## *sessionIdExt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.OCDM.sessionIdExt"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="method.setParameter"></a>
## *setParameter [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.name | std::string | - |
| params.value | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.OCDM.setParameter",
    "params": {
        "name": "",
        "value": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="method.status"></a>
## *status [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyID[] | uint8_t | - |
| params.keyIDLength | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.OCDM.status",
    "params": {
        "keyID[]": "",
        "keyIDLength": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```


