<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.FirmwareVersion_Plugin"></a>
# FirmwareVersion Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/FirmwareVersion/CHANGELOG.md)**

A FirmwareVersion plugin for Thunder framework.

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

The `FirmwareVersion` plugin provides an interface for FirmwareVersion.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FirmwareVersion) |
| classname | string | Class name: *FirmwareVersion* |
| locator | string | Library name: *libWPEFrameworkFirmwareVersion.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the FirmwareVersion plugin:

FirmwareVersion interface methods:

| Method | Description |
| :-------- | :-------- |
| [imagename](#method.imagename) |  |
| [mediarite](#method.mediarite) |  |
| [sdk](#method.sdk) |  |
| [yocto](#method.yocto) |  |

<a id="method.imagename"></a>
## *imagename [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.imagename | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FirmwareVersion.imagename"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": ""
}
```

<a id="method.mediarite"></a>
## *mediarite [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.mediarite | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FirmwareVersion.mediarite"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": ""
}
```

<a id="method.sdk"></a>
## *sdk [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.sdk | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FirmwareVersion.sdk"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
}
```

<a id="method.yocto"></a>
## *yocto [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.yocto | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FirmwareVersion.yocto"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```


