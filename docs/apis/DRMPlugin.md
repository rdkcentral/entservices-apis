<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.DRM_Plugin"></a>
# DRM Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/DRM/CHANGELOG.md)**

A DRM plugin for Thunder framework.

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

The `DRM` plugin provides an interface for DRM.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DRM) |
| classname | string | Class name: *DRM* |
| locator | string | Library name: *libWPEFrameworkDRM.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the DRM plugin:

DRM interface methods:

| Method | Description |
| :-------- | :-------- |
| [cancelChallengeDataExt](#method.cancelChallengeDataExt) |  |
| [cleanDecryptContext](#method.cleanDecryptContext) |  |
| [close](#method.close) |  |
| [deinitialize](#method.deinitialize) |  |
| [deleteKeyStore](#method.deleteKeyStore) |  |
| [deleteSecureStore](#method.deleteSecureStore) |  |
| [disable](#method.disable) |  |
| [enable](#method.enable) |  |
| [enableSecureStop](#method.enableSecureStop) |  |
| [getChallengeDataExt](#method.getChallengeDataExt) |  |
| [getDrmSystemTime](#method.getDrmSystemTime) |  |
| [getHeight](#method.getHeight) |  |
| [getLdlSessionLimit](#method.getLdlSessionLimit) |  |
| [getMediaType](#method.getMediaType) |  |
| [getSessionIdExt](#method.getSessionIdExt) |  |
| [getVersionExt](#method.getVersionExt) |  |
| [getWidth](#method.getWidth) |  |
| [initLength](#method.initLength) |  |
| [initialize](#method.initialize) |  |
| [isSecureStopEnabled](#method.isSecureStopEnabled) |  |
| [load](#method.load) |  |
| [metrics](#method.metrics) |  |
| [onKeyStatusUpdate](#method.onKeyStatusUpdate) |  |
| [onKeyStatusesUpdated](#method.onKeyStatusesUpdated) |  |
| [remove](#method.remove) |  |
| [resetSecureStops](#method.resetSecureStops) |  |
| [selectKeyId](#method.selectKeyId) |  |
| [setDrmHeader](#method.setDrmHeader) |  |
| [storeLicenseData](#method.storeLicenseData) |  |

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
    "id": 0,
    "method": "org.rdk.DRM.cancelChallengeDataExt"
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
    "id": 1,
    "method": "org.rdk.DRM.cleanDecryptContext"
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
    "id": 2,
    "method": "org.rdk.DRM.close"
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

<a id="method.deinitialize"></a>
## *deinitialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.shell | WPEFramework::PluginHost::IShell | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DRM.deinitialize",
    "params": {
        "shell": ""
    }
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

<a id="method.deleteKeyStore"></a>
## *deleteKeyStore [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.DRM.deleteKeyStore"
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

<a id="method.deleteSecureStore"></a>
## *deleteSecureStore [<sup>method</sup>](#head.Methods)*



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
    "id": 5,
    "method": "org.rdk.DRM.deleteSecureStore"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.disable"></a>
## *disable [<sup>method</sup>](#head.Methods)*



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
    "id": 6,
    "method": "org.rdk.DRM.disable"
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

<a id="method.enable"></a>
## *enable [<sup>method</sup>](#head.Methods)*



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
    "id": 7,
    "method": "org.rdk.DRM.enable"
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

<a id="method.enableSecureStop"></a>
## *enableSecureStop [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DRM.enableSecureStop",
    "params": {
        "enable": true
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

<a id="method.getChallengeDataExt"></a>
## *getChallengeDataExt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.challenge | uint8_t | - |
| params.challengeSize | uint32_t | - |
| params.isLDL | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DRM.getChallengeDataExt",
    "params": {
        "challenge": "",
        "challengeSize": 0,
        "isLDL": 0
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

<a id="method.getDrmSystemTime"></a>
## *getDrmSystemTime [<sup>method</sup>](#head.Methods)*



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
    "id": 10,
    "method": "org.rdk.DRM.getDrmSystemTime"
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

<a id="method.getHeight"></a>
## *getHeight [<sup>method</sup>](#head.Methods)*



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
    "id": 11,
    "method": "org.rdk.DRM.getHeight"
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

<a id="method.getLdlSessionLimit"></a>
## *getLdlSessionLimit [<sup>method</sup>](#head.Methods)*



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
    "id": 12,
    "method": "org.rdk.DRM.getLdlSessionLimit"
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

<a id="method.getMediaType"></a>
## *getMediaType [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.DRM.getMediaType"
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

<a id="method.getSessionIdExt"></a>
## *getSessionIdExt [<sup>method</sup>](#head.Methods)*



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
    "id": 14,
    "method": "org.rdk.DRM.getSessionIdExt"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.getVersionExt"></a>
## *getVersionExt [<sup>method</sup>](#head.Methods)*



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
    "id": 15,
    "method": "org.rdk.DRM.getVersionExt"
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

<a id="method.getWidth"></a>
## *getWidth [<sup>method</sup>](#head.Methods)*



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
    "id": 16,
    "method": "org.rdk.DRM.getWidth"
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

<a id="method.initLength"></a>
## *initLength [<sup>method</sup>](#head.Methods)*



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
    "id": 17,
    "method": "org.rdk.DRM.initLength"
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

<a id="method.initialize"></a>
## *initialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.shell | WPEFramework::PluginHost::IShell | - |
| params.configline | std::string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DRM.initialize",
    "params": {
        "shell": "",
        "configline": ""
    }
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

<a id="method.isSecureStopEnabled"></a>
## *isSecureStopEnabled [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.DRM.isSecureStopEnabled"
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
    "id": 20,
    "method": "org.rdk.DRM.load"
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

<a id="method.metrics"></a>
## *metrics [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.bufferLength | uint32_t | - |
| params.buffer[] | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DRM.metrics",
    "params": {
        "bufferLength": 0,
        "buffer[]": ""
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

<a id="method.onKeyStatusUpdate"></a>
## *onKeyStatusUpdate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyMessage | char | - |
| params.buffer | uint8_t | - |
| params.length | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.DRM.onKeyStatusUpdate",
    "params": {
        "keyMessage": "a",
        "buffer": "",
        "length": ""
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
    "id": 23,
    "method": "org.rdk.DRM.onKeyStatusesUpdated"
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
    "id": 24,
    "method": "org.rdk.DRM.remove"
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

<a id="method.resetSecureStops"></a>
## *resetSecureStops [<sup>method</sup>](#head.Methods)*



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
    "id": 25,
    "method": "org.rdk.DRM.resetSecureStops"
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

<a id="method.selectKeyId"></a>
## *selectKeyId [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyLength | uint8_t | - |
| params.keyId[] | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.DRM.selectKeyId",
    "params": {
        "keyLength": "",
        "keyId[]": ""
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

<a id="method.setDrmHeader"></a>
## *setDrmHeader [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.drmHeader[] | uint8_t | - |
| params.drmHeaderLength | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.DRM.setDrmHeader",
    "params": {
        "drmHeader[]": "",
        "drmHeaderLength": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="method.storeLicenseData"></a>
## *storeLicenseData [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.licenseData[] | uint8_t | - |
| params.licenseDataSize | uint32_t | - |
| params.secureStopId | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.DRM.storeLicenseData",
    "params": {
        "licenseData[]": "",
        "licenseDataSize": 0,
        "secureStopId": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```


