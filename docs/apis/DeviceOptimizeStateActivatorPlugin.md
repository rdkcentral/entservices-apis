<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.DeviceOptimizeStateActivator_Plugin"></a>
# DeviceOptimizeStateActivator Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/DeviceOptimizeStateActivator/CHANGELOG.md)**

A DeviceOptimizeStateActivator plugin for Thunder framework.

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

The `DeviceOptimizeStateActivator` plugin provides an interface for DeviceOptimizeStateActivator.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceOptimizeStateActivator) |
| classname | string | Class name: *DeviceOptimizeStateActivator* |
| locator | string | Library name: *libWPEFrameworkDeviceOptimizeStateActivator.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the DeviceOptimizeStateActivator plugin:

DeviceOptimizeStateActivator interface methods:

| Method | Description |
| :-------- | :-------- |
| [request](#method.request) |  |

<a id="method.request"></a>
## *request [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.newState | string | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceOptimizeStateActivator.request",
    "params": {
        "newState": ""
    }
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


