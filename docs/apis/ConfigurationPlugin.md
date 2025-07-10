<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Configuration_Plugin"></a>
# Configuration Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Configuration/CHANGELOG.md)**

A Configuration plugin for Thunder framework.

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

The `Configuration` plugin provides an interface for Configuration.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Configuration) |
| classname | string | Class name: *Configuration* |
| locator | string | Library name: *libWPEFrameworkConfiguration.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Configuration plugin:

Configuration interface methods:

| Method | Description |
| :-------- | :-------- |
| [configure](#method.configure) |  |

<a id="method.configure"></a>
## *configure [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framework | PluginHost::IShell | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Configuration.configure",
    "params": {
        "framework": ""
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


