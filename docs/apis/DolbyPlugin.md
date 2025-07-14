<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Dolby_Plugin"></a>
# Dolby Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Dolby/CHANGELOG.md)**

A Dolby plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Properties](#head.Properties)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `Dolby` plugin provides an interface for Dolby.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Dolby) |
| classname | string | Class name: *Dolby* |
| locator | string | Library name: *libWPEFrameworkDolby.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |


<a id="head.Properties"></a>
# Properties
The following properties are provided by the Dolby plugin:

Dolby interface properties:

| Method | Description |
| :-------- | :-------- |
| [AtmosMetadata](#property.AtmosMetadata)<sup>RO</sup> | Atmos capabilities of Sink |
| [EnableAtmosOutput](#property.EnableAtmosOutput)<sup>WO</sup> | Enable Atmos Audio Output |
| [Mode](#property.Mode) | Dolby Mode |
| [SoundMode](#property.SoundMode)<sup>RO</sup> | Sound Mode - Mono/Stereo/Surround |

<a id="property.AtmosMetadata"></a>
## *AtmosMetadata [<sup>property</sup>](#head.Properties)*

Atmos capabilities of Sink

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).supported | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Dolby.atmosMetadata"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": true
}
```

<a id="property.EnableAtmosOutput"></a>
## *EnableAtmosOutput [<sup>property</sup>](#head.Properties)*

Enable Atmos Audio Output

> This property is write-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enable | bool | enable/disable |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Dolby.enableAtmosOutput",
    "params": {
        "enable": true
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="property.Mode"></a>
## *Mode [<sup>property</sup>](#head.Properties)*

Dolby Mode

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | Dolby::IOutput::Type | dolby mode type |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Dolby.mode"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Dolby.mode",
    "params": {
        "mode": ""
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="property.SoundMode"></a>
## *SoundMode [<sup>property</sup>](#head.Properties)*

Sound Mode - Mono/Stereo/Surround

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).mode | Dolby::IOutput::SoundModes |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Dolby.soundMode"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Dolby plugin:

Dolby interface events:

| Event | Description |
| :-------- | :-------- |
| [audioModeChanged](#event.audioModeChanged) |  |

<a id="event.audioModeChanged"></a>
## *audioModeChanged [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | Dolby::IOutput::SoundModes | - |
| params.enabled | bool | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Dolby.audioModeChanged",
    "params": {
        "mode": "",
        "enabled": true
    }
}
```
