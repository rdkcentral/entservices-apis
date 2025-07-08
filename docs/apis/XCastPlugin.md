<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IXCast_Plugin"></a>
# IXCast Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IXCast/CHANGELOG.md)**

A IXCast plugin for Thunder framework.

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

The `IXCast` plugin provides an interface for IXCast.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IXCast*) |
| classname | string | Class name: *IXCast* |
| locator | string | Library name: *libWPEFrameworkIXCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IXCast plugin:

IXCast interface methods:

| Method | Description |
| :-------- | :-------- |
| [Deinitialize](#method.Deinitialize) |  |
| [Initialize](#method.Initialize) |  |
| [applicationStateChanged](#method.applicationStateChanged) |  |
| [enableCastService](#method.enableCastService) |  |
| [getManufacturerName](#method.getManufacturerName) |  |
| [getModelName](#method.getModelName) |  |
| [getProtocolVersion](#method.getProtocolVersion) |  |
| [onApplicationHideRequest](#method.onApplicationHideRequest) |  |
| [onApplicationLaunchRequest](#method.onApplicationLaunchRequest) |  |
| [onApplicationLaunchRequestWithLaunchParam](#method.onApplicationLaunchRequestWithLaunchParam) |  |
| [onApplicationResumeRequest](#method.onApplicationResumeRequest) |  |
| [onApplicationStateRequest](#method.onApplicationStateRequest) |  |
| [onApplicationStopRequest](#method.onApplicationStopRequest) |  |
| [onUpdatePowerStateRequest](#method.onUpdatePowerStateRequest) |  |
| [registerApplications](#method.registerApplications) |  |
| [setManufacturerName](#method.setManufacturerName) |  |
| [setModelName](#method.setModelName) |  |
| [setNetworkStandbyMode](#method.setNetworkStandbyMode) |  |

<a id="method.Deinitialize"></a>
## *Deinitialize [<sup>method</sup>](#head.Methods)*



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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.Deinitialize"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.Initialize"></a>
## *Initialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.networkStandbyMode | bool |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.Initialize",
    "params": {
        "networkStandbyMode": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.applicationStateChanged"></a>
## *applicationStateChanged [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.applicationName | string |  |
| params.state | string |  |
| params.applicationId | string |  |
| params.error | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.applicationStateChanged",
    "params": {
        "applicationName": "",
        "state": "",
        "applicationId": "",
        "error": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.enableCastService"></a>
## *enableCastService [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.friendlyname | string |  |
| params.enableService | bool |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.enableCastService",
    "params": {
        "friendlyname": "",
        "enableService": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.getManufacturerName"></a>
## *getManufacturerName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.manufacturername | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.getManufacturerName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "manufacturername": ""
    }
}
```
<a id="method.getModelName"></a>
## *getModelName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.modelname | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.getModelName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "modelname": ""
    }
}
```
<a id="method.getProtocolVersion"></a>
## *getProtocolVersion [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.protocolVersion | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.getProtocolVersion"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "protocolVersion": ""
    }
}
```
<a id="method.onApplicationHideRequest"></a>
## *onApplicationHideRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.appID | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationHideRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onApplicationLaunchRequest"></a>
## *onApplicationLaunchRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.parameter | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationLaunchRequest",
    "params": {
        "appName": "",
        "parameter": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onApplicationLaunchRequestWithLaunchParam"></a>
## *onApplicationLaunchRequestWithLaunchParam [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.strPayLoad | string |  |
| params.strQuery | string |  |
| params.strAddDataUrl | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationLaunchRequestWithLaunchParam",
    "params": {
        "appName": "",
        "strPayLoad": "",
        "strQuery": "",
        "strAddDataUrl": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onApplicationResumeRequest"></a>
## *onApplicationResumeRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.appID | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationResumeRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onApplicationStateRequest"></a>
## *onApplicationStateRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.appID | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationStateRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onApplicationStopRequest"></a>
## *onApplicationStopRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appName | string |  |
| params.appID | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onApplicationStopRequest",
    "params": {
        "appName": "",
        "appID": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.onUpdatePowerStateRequest"></a>
## *onUpdatePowerStateRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.powerState | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.onUpdatePowerStateRequest",
    "params": {
        "powerState": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.registerApplications"></a>
## *registerApplications [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.appInfoList | IApplicationInfoIterator |  |
| params.appInfoList[#].appName | string |  |
| params.appInfoList[#].prefixes | string |  |
| params.appInfoList[#].cors | string |  |
| params.appInfoList[#].query | string |  |
| params.appInfoList[#].payload | string |  |
| params.appInfoList[#].allowStop | int |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.registerApplications",
    "params": {
        "appInfoList": [
            {
                "appName": "",
                "prefixes": "",
                "cors": "",
                "query": "",
                "payload": "",
                "allowStop": "0"
            }
        ]
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.setManufacturerName"></a>
## *setManufacturerName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.manufacturername | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.setManufacturerName",
    "params": {
        "manufacturername": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.setModelName"></a>
## *setModelName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.modelname | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.setModelName",
    "params": {
        "modelname": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.setNetworkStandbyMode"></a>
## *setNetworkStandbyMode [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.networkStandbyMode | bool |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IXCast.setNetworkStandbyMode",
    "params": {
        "networkStandbyMode": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

