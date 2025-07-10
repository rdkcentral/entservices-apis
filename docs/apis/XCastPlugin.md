<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.XCast_Plugin"></a>
# XCast Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/XCast/CHANGELOG.md)**

A XCast plugin for Thunder framework.

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

The `XCast` plugin provides an interface for XCast.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.XCast) |
| classname | string | Class name: *XCast* |
| locator | string | Library name: *libWPEFrameworkXCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the XCast plugin:

XCast interface methods:

| Method | Description |
| :-------- | :-------- |
| [deinitialize](#method.deinitialize) |  |
| [initialize](#method.initialize) |  |
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

<a id="method.deinitialize"></a>
## *deinitialize [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.XCast.deinitialize"
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

<a id="method.initialize"></a>
## *initialize [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.networkStandbyMode | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.XCast.initialize",
    "params": {
        "networkStandbyMode": true
    }
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

<a id="method.applicationStateChanged"></a>
## *applicationStateChanged [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.applicationName | string | - |
| params.state | string | - |
| params.applicationId | string | - |
| params.error | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.XCast.applicationStateChanged",
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
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.enableCastService"></a>
## *enableCastService [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyname | string | - |
| params.enableService | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.XCast.enableCastService",
    "params": {
        "friendlyname": "",
        "enableService": true
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

<a id="method.getManufacturerName"></a>
## *getManufacturerName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.manufacturername | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.XCast.getManufacturerName"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
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
| result.modelname | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.XCast.getModelName"
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

<a id="method.getProtocolVersion"></a>
## *getProtocolVersion [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.protocolVersion | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.XCast.getProtocolVersion"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": ""
}
```

<a id="method.onApplicationHideRequest"></a>
## *onApplicationHideRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.appID | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.XCast.onApplicationHideRequest",
    "params": {
        "appName": "",
        "appID": ""
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

<a id="method.onApplicationLaunchRequest"></a>
## *onApplicationLaunchRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.parameter | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.XCast.onApplicationLaunchRequest",
    "params": {
        "appName": "",
        "parameter": ""
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

<a id="method.onApplicationLaunchRequestWithLaunchParam"></a>
## *onApplicationLaunchRequestWithLaunchParam [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.strPayLoad | string | - |
| params.strQuery | string | - |
| params.strAddDataUrl | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.XCast.onApplicationLaunchRequestWithLaunchParam",
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
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.onApplicationResumeRequest"></a>
## *onApplicationResumeRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.appID | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.XCast.onApplicationResumeRequest",
    "params": {
        "appName": "",
        "appID": ""
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

<a id="method.onApplicationStateRequest"></a>
## *onApplicationStateRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.appID | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.XCast.onApplicationStateRequest",
    "params": {
        "appName": "",
        "appID": ""
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

<a id="method.onApplicationStopRequest"></a>
## *onApplicationStopRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appName | string | - |
| params.appID | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.XCast.onApplicationStopRequest",
    "params": {
        "appName": "",
        "appID": ""
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

<a id="method.onUpdatePowerStateRequest"></a>
## *onUpdatePowerStateRequest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.XCast.onUpdatePowerStateRequest",
    "params": {
        "powerState": ""
    }
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

<a id="method.registerApplications"></a>
## *registerApplications [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInfoList | IApplicationInfoIterator | - |
| params.appInfoList[#].appName | string | - |
| params.appInfoList[#].prefixes | string | - |
| params.appInfoList[#].cors | string | - |
| params.appInfoList[#].query | string | - |
| params.appInfoList[#].payload | string | - |
| params.appInfoList[#].allowStop | int | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.XCast.registerApplications",
    "params": {
        "appInfoList": [
            {
                "appName": "",
                "prefixes": "",
                "cors": "",
                "query": "",
                "payload": "",
                "allowStop": 0
            }
        ]
    }
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

<a id="method.setManufacturerName"></a>
## *setManufacturerName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.manufacturername | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.XCast.setManufacturerName",
    "params": {
        "manufacturername": ""
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

<a id="method.setModelName"></a>
## *setModelName [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.modelname | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.XCast.setModelName",
    "params": {
        "modelname": ""
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

<a id="method.setNetworkStandbyMode"></a>
## *setNetworkStandbyMode [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.networkStandbyMode | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.XCast.setNetworkStandbyMode",
    "params": {
        "networkStandbyMode": true
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


