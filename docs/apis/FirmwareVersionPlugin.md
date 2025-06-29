<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IFirmwareVersion_Plugin"></a>
# IFirmwareVersion Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IFirmwareVersion/CHANGELOG.md)**

A IFirmwareVersion plugin for Thunder framework.

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

The `IFirmwareVersion` plugin provides an interface for IFirmwareVersion.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IFirmwareVersion*) |
| classname | string | Class name: *IFirmwareVersion* |
| locator | string | Library name: *libWPEFrameworkIFirmwareVersion.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IFirmwareVersion plugin:

IFirmwareVersion interface methods:

| Method | Description |
| :-------- | :-------- |
| [Imagename](#method.Imagename) |  |
| [Mediarite](#method.Mediarite) |  |
| [Sdk](#method.Sdk) |  |
| [Yocto](#method.Yocto) |  |

<a id="method.Imagename"></a>
## *Imagename [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.imagename | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareVersion.Imagename"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "imagename": ""
    }
}
```
<a id="method.Mediarite"></a>
## *Mediarite [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.mediarite | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareVersion.Mediarite"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "mediarite": ""
    }
}
```
<a id="method.Sdk"></a>
## *Sdk [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.sdk | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareVersion.Sdk"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "sdk": ""
    }
}
```
<a id="method.Yocto"></a>
## *Yocto [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.yocto | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IFirmwareVersion.Yocto"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "yocto": ""
    }
}
```

