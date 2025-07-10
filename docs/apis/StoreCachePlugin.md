<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.StoreCache_Plugin"></a>
# StoreCache Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/StoreCache/CHANGELOG.md)**

A StoreCache plugin for Thunder framework.

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

The `StoreCache` plugin provides an interface for StoreCache.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.StoreCache) |
| classname | string | Class name: *StoreCache* |
| locator | string | Library name: *libWPEFrameworkStoreCache.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the StoreCache plugin:

StoreCache interface methods:

| Method | Description |
| :-------- | :-------- |
| [flushCache](#method.flushCache) |  |

<a id="method.flushCache"></a>
## *flushCache [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.StoreCache.flushCache"
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


