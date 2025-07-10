<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Capture_Plugin"></a>
# Capture Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Capture/CHANGELOG.md)**

A Capture plugin for Thunder framework.

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

The `Capture` plugin provides an interface for Capture.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Capture) |
| classname | string | Class name: *Capture* |
| locator | string | Library name: *libWPEFrameworkCapture.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Capture plugin:

Capture interface methods:

| Method | Description |
| :-------- | :-------- |
| [capture](#method.capture) |  |
| [r8_G8_B8_A8](#method.r8_G8_B8_A8) |  |

<a id="method.capture"></a>
## *capture [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.storer | ICapture::IStore | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Capture.capture",
    "params": {
        "storer": ""
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

<a id="method.r8_G8_B8_A8"></a>
## *r8_G8_B8_A8 [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.char | unsigned | - |
| params.int | unsigned | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Capture.r8_G8_B8_A8",
    "params": {
        "char": "",
        "int": ""
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


