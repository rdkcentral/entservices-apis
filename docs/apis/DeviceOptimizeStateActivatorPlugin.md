<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IDeviceOptimizeStateActivator_Plugin"></a>
# IDeviceOptimizeStateActivator Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IDeviceOptimizeStateActivator/CHANGELOG.md)**

A IDeviceOptimizeStateActivator plugin for Thunder framework.

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

The `IDeviceOptimizeStateActivator` plugin provides an interface for IDeviceOptimizeStateActivator.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IDeviceOptimizeStateActivator*) |
| classname | string | Class name: *IDeviceOptimizeStateActivator* |
| locator | string | Library name: *libWPEFrameworkIDeviceOptimizeStateActivator.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IDeviceOptimizeStateActivator plugin:

IDeviceOptimizeStateActivator interface methods:

| Method | Description |
| :-------- | :-------- |
| [Request](#method.Request) |  |

<a id="method.Request"></a>
## *Request [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.newState | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IDeviceOptimizeStateActivator.Request",
    "params": {
        "newState": ""
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

