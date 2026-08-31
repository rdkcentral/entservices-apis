<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DTV_API"></a>
# DTV API

**Version: 1.0**

**Status: :black_circle::white_circle::white_circle:**

DTV plugin for Thunder framework.

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Configuration](#head_Configuration)
- [Interfaces](#head_Interfaces)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DTV plugin. It includes detailed specification about its configuration, methods and properties as well as sent notifications.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

The `DTV` plugin provides access to DVB services provided by a DVB stack.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head_Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| classname | string | mandatory | Class name: *DTV* |
| startmode | string | mandatory | Determines in which state the plugin should be moved to at startup of the framework |

<a id="head_Interfaces"></a>
# Interfaces

This plugin implements the following interfaces:

- [DTV.json](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/DTV.json) (version 1.0.0) (uncompliant-collapsed format)

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DTV plugin:

DTV interface methods:

| Method | Description |
| :-------- | :-------- |
| [addLnb](#method_addLnb) | Add a new LNB to the database |
| [addSatellite](#method_addSatellite) | Add a new satellite to the database |
| [startServiceSearch](#method_startServiceSearch) | Starts a service search |
| [finishServiceSearch](#method_finishServiceSearch) | Finishes a service search |
| [startPlaying](#method_startPlaying) | Starts playing the specified service |
| [stopPlaying](#method_stopPlaying) | Stops playing the specified service |

<a id="method_addLnb"></a>
## *addLnb [<sup>method</sup>](#head_Methods)*

Add a new LNB to the database.
  
### Events 

 No Events.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.name | string | mandatory | User specified name for the LNB settings |
| params.type | string | mandatory | *...* (must be one of the following: *single, unicable, universal*) |
| params.power | string | mandatory | *...* (must be one of the following: *auto, off, on*) |
| params.diseqc_tone | string | mandatory | *...* (must be one of the following: *a, b, off*) |
| params.diseqc_cswitch | string | mandatory | *...* (must be one of the following: *a, b, c, d, off*) |
| params.is22k | boolean | mandatory | 22kHz tone on/off |
| params.is12v | boolean | mandatory | 12 volts on/off |
| params.ispulseposition | boolean | mandatory | Pulse position motor used to control dish position |
| params.isdiseqcposition | boolean | mandatory | Dish positioning is controlled by DiSEqC |
| params.issmatv | boolean | mandatory | SMATV switcher on/off |
| params.diseqcrepeats | integer | mandatory | Number of times to send a DiSEqC message to make sure it's been received |
| params.u_switch | integer | mandatory | DiSEqC uncommitted switch selector |
| params.unicablechannel | integer | mandatory | Unicable channel |
| params?.unicablefreq | integer | optional | Unicable frequency |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | True if the LNB is added, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.addLnb",
  "params": {
    "name": "Universal",
    "type": "universal",
    "power": "auto",
    "diseqc_tone": "off",
    "diseqc_cswitch": "off",
    "is22k": false,
    "is12v": false,
    "ispulseposition": false,
    "isdiseqcposition": false,
    "issmatv": false,
    "diseqcrepeats": 0,
    "u_switch": 0,
    "unicablechannel": 0,
    "unicablefreq": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": true
}
```

<a id="method_addSatellite"></a>
## *addSatellite [<sup>method</sup>](#head_Methods)*

Add a new satellite to the database.
  
### Events 

 No Events.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.name | string | mandatory | User specified name for the satellite settings |
| params.longitude | integer | mandatory | Longitudinal location of the satellite in 1/10ths of a degree, with an east coordinate given as a positive value and a west coordinate as negative. Astra 28.2E would be defined as 282 and Eutelsat 5.0W would be -50 |
| params.lnb | string | mandatory | Name of the LNB settings to be used when tuning to this satellite |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | True if the satellite is added, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.addSatellite",
  "params": {
    "name": "Astra 28.2E",
    "longitude": 282,
    "lnb": "Universal"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": true
}
```

<a id="method_startServiceSearch"></a>
## *startServiceSearch [<sup>method</sup>](#head_Methods)*

Starts a service search.
 
### Events  
| Event | Description | 
| :----------- | :----------- | 
|`searchstatus`|Triggered during the course of a service search.|
 |`serviceupdated`|Triggered when a service is added|.

Also see: [searchstatus](#event_searchstatus), [serviceupdated](#event_serviceupdated)

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.tunertype | string | mandatory | Tuner type (must be one of the following: *dvbc, dvbs, dvbt, none*) |
| params.searchtype | string | mandatory | *...* (must be one of the following: *frequency, network*) |
| params.retune | boolean | mandatory | True if current services are to be replaced in the database, false if the scan is to update the existing services |
| params.usetuningparams | boolean | mandatory | Set to true if the optional tuning parameters are defined |
| params?.dvbstuningparams | object | optional | Parameters required to tune to a DVB-S/S2 signal |
| params?.dvbstuningparams.satellite | string | mandatory | Name of the satellite settings to be used |
| params?.dvbstuningparams.frequency | integer | mandatory | Frequency of the transponder, in kHz |
| params?.dvbstuningparams.polarity | string | mandatory | *...* (must be one of the following: *horizontal, left, right, vertical*) |
| params?.dvbstuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| params?.dvbstuningparams.fec | string | mandatory | Forward error correction setting (must be one of the following: *fec1_2, fec1_3, fec1_4, fec2_3, fec2_5, fec3_4, fec3_5, fec4_5, fec5_6, fec7_8, fec8_9, fec9_10, fecauto*) |
| params?.dvbstuningparams.modulation | string | mandatory | *...* (must be one of the following: *16qam, 8psk, auto, qpsk*) |
| params?.dvbstuningparams.dvbs2 | boolean | mandatory | True when tuning to a DVB-S2 signal |
| params?.dvbctuningparams | object | optional | Parameters required to tune to a DVB-C signal |
| params?.dvbctuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| params?.dvbctuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| params?.dvbctuningparams.modulation | string | mandatory | *...* (must be one of the following: *128qam, 16qam, 256qam, 32qam, 4qam, 64qam, 8qam, auto*) |
| params?.dvbttuningparams | object | optional | Parameters required to tune to a DVB-T/T2 signal |
| params?.dvbttuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| params?.dvbttuningparams.bandwidth | string | mandatory | Channel bandwidth (must be one of the following: *10MHz, 5MHz, 6MHz, 7MHz, 8MHz, undefined*) |
| params?.dvbttuningparams.mode | string | mandatory | OFDM mode (must be one of the following: *ofdm_16K, ofdm_1K, ofdm_2K, ofdm_32K, ofdm_4K, ofdm_8K, undefined*) |
| params?.dvbttuningparams.dvbt2 | boolean | mandatory | True when tuning to a DVB-T2 signal |
| params?.dvbttuningparams?.plpid | integer | optional | PLP ID for tuning to a DVB-T2 signal |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | True if the search is started, false otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.startServiceSearch",
  "params": {
    "tunertype": "dvbs",
    "searchtype": "network",
    "retune": false,
    "usetuningparams": true,
    "dvbstuningparams": {
      "satellite": "Astra 28.2",
      "frequency": 10714000,
      "polarity": "horizontal",
      "symbolrate": 22000,
      "fec": "fec5_6",
      "modulation": "qpsk",
      "dvbs2": false
    },
    "dvbctuningparams": {
      "frequency": 474000000,
      "symbolrate": 6900,
      "modulation": "128qam"
    },
    "dvbttuningparams": {
      "frequency": 474000000,
      "bandwidth": "8MHz",
      "mode": "ofdm_32K",
      "dvbt2": false,
      "plpid": 0
    }
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": true
}
```

<a id="method_finishServiceSearch"></a>
## *finishServiceSearch [<sup>method</sup>](#head_Methods)*

Finishes a service search.
  
### Events 

 No Events.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.tunertype | string | mandatory | Tuner type (must be one of the following: *dvbc, dvbs, dvbt, none*) |
| params.savechanges | boolean | mandatory | True if the services found during the search should be saved |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | False if the tunertype isn't valid, true otherwise |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.finishServiceSearch",
  "params": {
    "tunertype": "dvbs",
    "savechanges": true
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": true
}
```

<a id="method_startPlaying"></a>
## *startPlaying [<sup>method</sup>](#head_Methods)*

Starts playing the specified service.
  
### Events
| Event | Description |
| :----------- | :----------- |
|`serviceupdated`|Triggered when info for a service changes|
|`eventchanged`|Triggered when the EIT 'now' event changes|
|`videochanged`|Triggered when the video PID or codec are changed|
|`audiochanged`|Triggered when the audio PID or codec are changed|
|`subtitleschanged`|Triggered when the subtitle PID or details are changed| .

Also see: [serviceupdated](#event_serviceupdated), [eventchanged](#event_eventchanged), [videochanged](#event_videochanged), [audiochanged](#event_audiochanged), [subtitleschanged](#event_subtitleschanged)

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params?.dvburi | string | optional | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params?.lcn | integer | optional | LCN of the service to be tuned to |
| params?.monitoronly | boolean | optional | (Version 2) set to 'true' to monitor SI/PSI data only. Will default to 'false' if not defined |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | The play handle assigned to play the given service. Will be -1 if the service can't be played |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.startPlaying",
  "params": {
    "dvburi": "2.2041.9212",
    "lcn": 0,
    "monitoronly": true
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_stopPlaying"></a>
## *stopPlaying [<sup>method</sup>](#head_Methods)*

Stops playing the specified service.
  
### Events 

 No Events.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | integer | mandatory | The play handle returned by startPlaying |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null (default: *None*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.stopPlaying",
  "params": 0
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the DTV plugin:

DTV interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [numberOfCountries](#property_numberOfCountries) | read-only | Number of country configurations available |
| [countryList](#property_countryList) | read-only | Array containing the name and 3 character ISO country code for all the available country configurations |
| [country](#property_country) | read/write | Country configuration using the ISO 3-character country code |
| [lnbList](#property_lnbList) | read-only | Array of LNBs defined in the database |
| [satelliteList](#property_satelliteList) | read-only | Array of satellites defined in the database |
| [numberOfServices](#property_numberOfServices) | read-only | Total number of services in the service database |
| [serviceList](#property_serviceList) | read-only | List of services for the given type of tuner, transport (version 2), or all services if neither is given |
| [serviceInfo](#property_serviceInfo) | read-only | Information for the given service as defined by its DVB triplet URI |
| [serviceComponents](#property_serviceComponents) | read-only | (Version 2) array of components for the given service defined by its URI |
| [transportInfo](#property_transportInfo) | read-only | Information for the given transport as defined by its DVB doublet URI |
| [nowNextEvents](#property_nowNextEvents) | read-only | Now and next events (EITp/f) for the given service |
| [scheduleEvents](#property_scheduleEvents) | read-only | Events which are scheduled (EITsched) for the given service |
| [extendedEventInfo](#property_extendedEventInfo) | read-only | Extended event info for the given service and event ID (version 2) |
| [status](#property_status) | read-only | Information related to the play handle defined by the index |
| [signalInfo](#property_signalInfo) | read-only | strength and quality of the currently tuned signal for the given play handle (version 2) |

<a id="property_numberOfCountries"></a>
## *numberOfCountries [<sup>property</sup>](#head_Properties)*

Provides access to the number of country configurations available.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Number of country configurations available |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.numberOfCountries"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 5
}
```

<a id="property_countryList"></a>
## *countryList [<sup>property</sup>](#head_Properties)*

Provides access to the array containing the name and 3 character ISO country code for all the available country configurations.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | List of available country configurations |
| (property)[#] | object | mandatory | *...* |
| (property)[#].name | string | mandatory | Name of the country as a UTF-8 string |
| (property)[#].code | integer | mandatory | 3-character ISO code for the country |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.countryList"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "UK",
      "code": 6775410
    }
  ]
}
```

<a id="property_country"></a>
## *country [<sup>property</sup>](#head_Properties)*

Provides access to the country configuration using the ISO 3-character country code.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | 3-character ISO code for the country |

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | 3-character ISO code for the country |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.country"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 6775410
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.country",
  "params": 6775410
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_lnbList"></a>
## *lnbList [<sup>property</sup>](#head_Properties)*

Provides access to the array of LNBs defined in the database.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Array of LNBs defined in the database |
| (property)[#] | object | mandatory | *...* |
| (property)[#].name | string | mandatory | User specified name for the LNB settings |
| (property)[#].type | string | mandatory | *...* (must be one of the following: *single, unicable, universal*) |
| (property)[#].power | string | mandatory | *...* (must be one of the following: *auto, off, on*) |
| (property)[#].diseqc_tone | string | mandatory | *...* (must be one of the following: *a, b, off*) |
| (property)[#].diseqc_cswitch | string | mandatory | *...* (must be one of the following: *a, b, c, d, off*) |
| (property)[#].is22k | boolean | mandatory | 22kHz tone on/off |
| (property)[#].is12v | boolean | mandatory | 12 volts on/off |
| (property)[#].ispulseposition | boolean | mandatory | Pulse position motor used to control dish position |
| (property)[#].isdiseqcposition | boolean | mandatory | Dish positioning is controlled by DiSEqC |
| (property)[#].issmatv | boolean | mandatory | SMATV switcher on/off |
| (property)[#].diseqcrepeats | integer | mandatory | Number of times to send a DiSEqC message to make sure it's been received |
| (property)[#].u_switch | integer | mandatory | DiSEqC uncommitted switch selector |
| (property)[#].unicablechannel | integer | mandatory | Unicable channel |
| (property)[#]?.unicablefreq | integer | optional | Unicable frequency |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.lnbList"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "Universal",
      "type": "universal",
      "power": "auto",
      "diseqc_tone": "off",
      "diseqc_cswitch": "off",
      "is22k": false,
      "is12v": false,
      "ispulseposition": false,
      "isdiseqcposition": false,
      "issmatv": false,
      "diseqcrepeats": 0,
      "u_switch": 0,
      "unicablechannel": 0,
      "unicablefreq": 0
    }
  ]
}
```

<a id="property_satelliteList"></a>
## *satelliteList [<sup>property</sup>](#head_Properties)*

Provides access to the array of satellites defined in the database.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Array of satellites defined in the database |
| (property)[#] | object | mandatory | *...* |
| (property)[#].name | string | mandatory | User specified name for the satellite settings |
| (property)[#].longitude | integer | mandatory | Longitudinal location of the satellite in 1/10ths of a degree, with an east coordinate given as a positive value and a west coordinate as negative. Astra 28.2E would be defined as 282 and Eutelsat 5.0W would be -50 |
| (property)[#].lnb | string | mandatory | Name of the LNB settings to be used when tuning to this satellite |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.satelliteList"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "Astra 28.2E",
      "longitude": 282,
      "lnb": "Universal"
    }
  ]
}
```

<a id="property_numberOfServices"></a>
## *numberOfServices [<sup>property</sup>](#head_Properties)*

Provides access to the total number of services in the service database.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Total number of services in the service database |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.numberOfServices"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 145
}
```

<a id="property_serviceList"></a>
## *serviceList [<sup>property</sup>](#head_Properties)*

Provides access to the list of services for the given type of tuner, transport (version 2), or all services if neither is given.

> This property is **read-only**.

> The *optional tuner type, or transport dvb doublet* parameter shall be passed as the index to the property, i.e. ``serviceList@<optional-tuner-type,-or-transport-dvb-doublet>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| optional-tuner-type,-or-transport-dvb-doublet | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | List of services for the given type of tuner, transport (version 2), or all services if neither is given |
| (property)[#] | object | mandatory | Service information |
| (property)[#].fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| (property)[#].shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| (property)[#].dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| (property)[#].servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| (property)[#].lcn | integer | mandatory | Logical channel number |
| (property)[#].scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| (property)[#].hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| (property)[#].hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| (property)[#].selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| (property)[#].runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.serviceList@dvbs or 9018.4161"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  ]
}
```

<a id="property_serviceInfo"></a>
## *serviceInfo [<sup>property</sup>](#head_Properties)*

Provides access to the information for the given service as defined by its DVB triplet URI.

> This property is **read-only**.

> The *service uri string* parameter shall be passed as the index to the property, i.e. ``serviceInfo@<service-uri-string>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| service-uri-string | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| (property).fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| (property).shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| (property).dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| (property).servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| (property).lcn | integer | mandatory | Logical channel number |
| (property).scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| (property).hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| (property).hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| (property).selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| (property).runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.serviceInfo@9018.4161.1001"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "fullname": "Channel 4",
    "shortname": "C4",
    "dvburi": "2.2041.9212",
    "servicetype": "tv",
    "lcn": 1001,
    "scrambled": false,
    "hascadescriptor": false,
    "hidden": false,
    "selectable": false,
    "runningstatus": "running"
  }
}
```

<a id="property_serviceComponents"></a>
## *serviceComponents [<sup>property</sup>](#head_Properties)*

Provides access to the (Version 2) array of components for the given service defined by its URI.

> This property is **read-only**.

> The *service uri string* parameter shall be passed as the index to the property, i.e. ``serviceComponents@<service-uri-string>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| service-uri-string | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | (Version 2) array of components for the given service defined by its URI |
| (property)[#] | object | mandatory | Video, audio, subtitle, teletext or data component info |
| (property)[#].type | string | mandatory | Type of data contained in this component (must be one of the following: *audio, data, subtitles, teletext, video*) |
| (property)[#]?.tags | array | optional | Array of component tags |
| (property)[#]?.tags[#] | integer | optional | *...* |
| (property)[#].pid | integer | mandatory | PID of the component |
| (property)[#]?.video | object | optional | Video related information for a video component |
| (property)[#]?.video.codec | string | mandatory | Video or audio codec type (must be one of the following: *aac, ac3, avs, eac3, h264, h265, heaac, heaacv2, mpeg1, mpeg2*) |
| (property)[#]?.audio | object | optional | Audio related information for an audio component |
| (property)[#]?.audio?.codec | string | optional | Video or audio codec type (must be one of the following: *aac, ac3, avs, eac3, h264, h265, heaac, heaacv2, mpeg1, mpeg2*) |
| (property)[#]?.audio.language | string | mandatory | ISO 3-char language code |
| (property)[#]?.audio.type | string | mandatory | Type of the audio contained in the component (must be one of the following: *clean, hearingimpaired, undefined, unknown, visuallyimpaired*) |
| (property)[#]?.audio.mode | string | mandatory | Audio mode (must be one of the following: *left, mono, multichannel, right, stereo, undefined*) |
| (property)[#]?.subtitles | object | optional | DVB subtitle related information for a subtitle component |
| (property)[#]?.subtitles.language | string | mandatory | ISO 3-char language code |
| (property)[#]?.subtitles.format | string | mandatory | Intended TV format for the subtitles (must be one of the following: *16_9, 221_1, 4_3, default, hardofhearing, hardofhearing16_9, hardofhearing221_1, hardofhearing4_3, hardofhearinghd, hd*) |
| (property)[#]?.subtitles.compositionpage | integer | mandatory | Composition page to be used for subtitles in this component |
| (property)[#]?.subtitles.ancillarypage | integer | mandatory | Ancillary page to be used for subtitles in this component |
| (property)[#]?.teletext | object | optional | Teletext related information for a teletext component |
| (property)[#]?.teletext.language | string | mandatory | ISO 3-char language code |
| (property)[#]?.teletext.type | integer | mandatory | Type of teletext data |
| (property)[#]?.teletext.magazine | integer | mandatory | Magazine number for this type and language |
| (property)[#]?.teletext.page | integer | mandatory | Page number for this type and language |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.serviceComponents@9018.4161.1001"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "type": "video",
      "tags": [
        0
      ],
      "pid": 1100,
      "video": {
        "codec": "h264"
      },
      "audio": {
        "codec": "h264",
        "language": "eng",
        "type": "normal",
        "mode": "left"
      },
      "subtitles": {
        "language": "eng",
        "format": "4_3",
        "compositionpage": 0,
        "ancillarypage": 0
      },
      "teletext": {
        "language": "eng",
        "type": 0,
        "magazine": 0,
        "page": 0
      }
    }
  ]
}
```

<a id="property_transportInfo"></a>
## *transportInfo [<sup>property</sup>](#head_Properties)*

Provides access to the information for the given transport as defined by its DVB doublet URI.

> This property is **read-only**.

> The *transport uri string* parameter shall be passed as the index to the property, i.e. ``transportInfo@<transport-uri-string>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| transport-uri-string | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Information for the given transport as defined by its DVB doublet URI |
| (property).tunertype | string | mandatory | Tuner type (must be one of the following: *dvbc, dvbs, dvbt, none*) |
| (property).originalnetworkid | integer | mandatory | Original network ID of the transport |
| (property).transportid | integer | mandatory | Transport ID of the transport |
| (property).strength | integer | mandatory | Signal strength as a percentage |
| (property).quality | integer | mandatory | Signal quality as a percentage |
| (property)?.dvbctuningparams | object | optional | Parameters required to tune to a DVB-C signal |
| (property)?.dvbctuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| (property)?.dvbctuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| (property)?.dvbctuningparams.modulation | string | mandatory | *...* (must be one of the following: *128qam, 16qam, 256qam, 32qam, 4qam, 64qam, 8qam, auto*) |
| (property)?.dvbstuningparams | object | optional | Parameters required to tune to a DVB-S/S2 signal |
| (property)?.dvbstuningparams.satellite | string | mandatory | Name of the satellite settings to be used |
| (property)?.dvbstuningparams.frequency | integer | mandatory | Frequency of the transponder, in kHz |
| (property)?.dvbstuningparams.polarity | string | mandatory | *...* (must be one of the following: *horizontal, left, right, vertical*) |
| (property)?.dvbstuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| (property)?.dvbstuningparams.fec | string | mandatory | Forward error correction setting (must be one of the following: *fec1_2, fec1_3, fec1_4, fec2_3, fec2_5, fec3_4, fec3_5, fec4_5, fec5_6, fec7_8, fec8_9, fec9_10, fecauto*) |
| (property)?.dvbstuningparams.modulation | string | mandatory | *...* (must be one of the following: *16qam, 8psk, auto, qpsk*) |
| (property)?.dvbstuningparams.dvbs2 | boolean | mandatory | True when tuning to a DVB-S2 signal |
| (property)?.dvbttuningparams | object | optional | Parameters required to tune to a DVB-T/T2 signal |
| (property)?.dvbttuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| (property)?.dvbttuningparams.bandwidth | string | mandatory | Channel bandwidth (must be one of the following: *10MHz, 5MHz, 6MHz, 7MHz, 8MHz, undefined*) |
| (property)?.dvbttuningparams.mode | string | mandatory | OFDM mode (must be one of the following: *ofdm_16K, ofdm_1K, ofdm_2K, ofdm_32K, ofdm_4K, ofdm_8K, undefined*) |
| (property)?.dvbttuningparams.dvbt2 | boolean | mandatory | True when tuning to a DVB-T2 signal |
| (property)?.dvbttuningparams?.plpid | integer | optional | PLP ID for tuning to a DVB-T2 signal |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.transportInfo@9018.4161"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "tunertype": "dvbt",
    "originalnetworkid": 8204,
    "transportid": 8204,
    "strength": 76,
    "quality": 95,
    "dvbctuningparams": {
      "frequency": 474000000,
      "symbolrate": 6900,
      "modulation": "128qam"
    },
    "dvbstuningparams": {
      "satellite": "Astra 28.2",
      "frequency": 10714000,
      "polarity": "horizontal",
      "symbolrate": 22000,
      "fec": "fec5_6",
      "modulation": "qpsk",
      "dvbs2": false
    },
    "dvbttuningparams": {
      "frequency": 474000000,
      "bandwidth": "8MHz",
      "mode": "ofdm_32K",
      "dvbt2": false,
      "plpid": 0
    }
  }
}
```

<a id="property_nowNextEvents"></a>
## *nowNextEvents [<sup>property</sup>](#head_Properties)*

Provides access to the now and next events (EITp/f) for the given service.

> This property is **read-only**.

> The *service uri string* parameter shall be passed as the index to the property, i.e. ``nowNextEvents@<service-uri-string>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| service-uri-string | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Now and next events (EITp/f) for the given service |
| (property)?.now | object | optional | EIT event information |
| (property)?.now.name | string | mandatory | Name of the DVB event as defined in the short event descriptor |
| (property)?.now.starttime | integer | mandatory | UTC start time of the event in seconds |
| (property)?.now.duration | integer | mandatory | Duration of the event in seconds |
| (property)?.now.eventid | integer | mandatory | ID of the event from the event information table |
| (property)?.now.shortdescription | string | mandatory | Event description from the EIT short event descriptor |
| (property)?.now.hassubtitles | boolean | mandatory | (Version 2) True if subtitles are available |
| (property)?.now.hasaudiodescription | boolean | mandatory | (Version 2) True if audio description is available |
| (property)?.now.parentalrating | integer | mandatory | (Version 2) Parental rating for the event, will be 0 if undefined |
| (property)?.now.contentdata | array | mandatory | (Version 2) The first 2 4-bit values from the content descriptor as separate bytes |
| (property)?.now.contentdata[#] | integer | mandatory | *...* |
| (property)?.now.hasextendedinfo | boolean | mandatory | (Version 2) True if there's extended event information available |
| (property)?.next | object | optional | EIT event information |
| (property)?.next.name | string | mandatory | Name of the DVB event as defined in the short event descriptor |
| (property)?.next.starttime | integer | mandatory | UTC start time of the event in seconds |
| (property)?.next.duration | integer | mandatory | Duration of the event in seconds |
| (property)?.next.eventid | integer | mandatory | ID of the event from the event information table |
| (property)?.next.shortdescription | string | mandatory | Event description from the EIT short event descriptor |
| (property)?.next.hassubtitles | boolean | mandatory | (Version 2) True if subtitles are available |
| (property)?.next.hasaudiodescription | boolean | mandatory | (Version 2) True if audio description is available |
| (property)?.next.parentalrating | integer | mandatory | (Version 2) Parental rating for the event, will be 0 if undefined |
| (property)?.next.contentdata | array | mandatory | (Version 2) The first 2 4-bit values from the content descriptor as separate bytes |
| (property)?.next.contentdata[#] | integer | mandatory | *...* |
| (property)?.next.hasextendedinfo | boolean | mandatory | (Version 2) True if there's extended event information available |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.nowNextEvents@9018.4161.1001"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "now": {
      "name": "Channel 4 News",
      "starttime": 1587562065,
      "duration": 1800,
      "eventid": 3012,
      "shortdescription": "The current national and world news",
      "hassubtitles": false,
      "hasaudiodescription": false,
      "parentalrating": 12,
      "contentdata": [
        0
      ],
      "hasextendedinfo": false
    },
    "next": {
      "name": "Channel 4 News",
      "starttime": 1587562065,
      "duration": 1800,
      "eventid": 3012,
      "shortdescription": "The current national and world news",
      "hassubtitles": false,
      "hasaudiodescription": false,
      "parentalrating": 12,
      "contentdata": [
        0
      ],
      "hasextendedinfo": false
    }
  }
}
```

<a id="property_scheduleEvents"></a>
## *scheduleEvents [<sup>property</sup>](#head_Properties)*

Provides access to the events which are scheduled (EITsched) for the given service.

> This property is **read-only**.

> The *service uri string, with optional start and end times as number of seconds utc* parameter shall be passed as the index to the property, i.e. ``scheduleEvents@<service-uri-string,-with-optional-start-and-end-times-as-number-of-seconds-utc>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| service-uri-string,-with-optional-start-and-end-times-as-number-of-seconds-utc | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Events which are scheduled (EITsched) for the given service |
| (property)[#] | object | mandatory | EIT event information |
| (property)[#].name | string | mandatory | Name of the DVB event as defined in the short event descriptor |
| (property)[#].starttime | integer | mandatory | UTC start time of the event in seconds |
| (property)[#].duration | integer | mandatory | Duration of the event in seconds |
| (property)[#].eventid | integer | mandatory | ID of the event from the event information table |
| (property)[#].shortdescription | string | mandatory | Event description from the EIT short event descriptor |
| (property)[#].hassubtitles | boolean | mandatory | (Version 2) True if subtitles are available |
| (property)[#].hasaudiodescription | boolean | mandatory | (Version 2) True if audio description is available |
| (property)[#].parentalrating | integer | mandatory | (Version 2) Parental rating for the event, will be 0 if undefined |
| (property)[#].contentdata | array | mandatory | (Version 2) The first 2 4-bit values from the content descriptor as separate bytes |
| (property)[#].contentdata[#] | integer | mandatory | *...* |
| (property)[#].hasextendedinfo | boolean | mandatory | (Version 2) True if there's extended event information available |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.scheduleEvents@9018.4161.1001:12345000,12346000"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "Channel 4 News",
      "starttime": 1587562065,
      "duration": 1800,
      "eventid": 3012,
      "shortdescription": "The current national and world news",
      "hassubtitles": false,
      "hasaudiodescription": false,
      "parentalrating": 12,
      "contentdata": [
        0
      ],
      "hasextendedinfo": false
    }
  ]
}
```

<a id="property_extendedEventInfo"></a>
## *extendedEventInfo [<sup>property</sup>](#head_Properties)*

Provides access to the extended event info for the given service and event ID (version 2).

> This property is **read-only**.

> The *service uri string and event id* parameter shall be passed as the index to the property, i.e. ``extendedEventInfo@<service-uri-string-and-event-id>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| service-uri-string-and-event-id | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Extended event info for the given service and event ID (version 2) |
| (property)?.description | string | optional | Extended event description text |
| (property)?.items | array | optional |  |
| (property)?.items[#] | object | optional | *...* |
| (property)?.items[#]?.description | string | optional | Description of the item |
| (property)?.items[#]?.item | string | optional | Item text |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.extendedEventInfo@9018.4161.1001:3012"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "description": "A long event description",
    "items": [
      {
        "description": "Actor 1",
        "item": "Kermit The Frog"
      }
    ]
  }
}
```

<a id="property_status"></a>
## *status [<sup>property</sup>](#head_Properties)*

Provides access to the information related to the play handle defined by the index.

> This property is **read-only**.

> The *play handle* parameter shall be passed as the index to the property, i.e. ``status@<play-handle>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| play-handle | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Information related to the play handle defined by the index |
| (property).tuner | integer | mandatory | The tuner id used by the play handle |
| (property).demux | integer | mandatory | The demux id used by the play handle |
| (property).pmtpid | integer | mandatory | The PMT PID of the service being played |
| (property).dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| (property).lcn | integer | mandatory | LCN of the service being played |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.status@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "tuner": 0,
    "demux": 0,
    "pmtpid": 1100,
    "dvburi": "2.2041.9212",
    "lcn": 1001
  }
}
```

<a id="property_signalInfo"></a>
## *signalInfo [<sup>property</sup>](#head_Properties)*

Provides access to the strength and quality of the currently tuned signal for the given play handle (version 2).

> This property is **read-only**.

> The *play handle* parameter shall be passed as the index to the property, i.e. ``signalInfo@<play-handle>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| play-handle | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Strength and quality of the currently tuned signal for the given play handle (version 2) |
| (property).locked | boolean | mandatory | Tuned locked status |
| (property).strength | integer | mandatory | The signal strength as a percentage |
| (property).quality | integer | mandatory | The signal quality as a percentage |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.signalInfo@0"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "locked": false,
    "strength": 76,
    "quality": 95
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the DTV plugin:

DTV interface events:

| Notification | Description |
| :-------- | :-------- |
| [searchstatus](#notification_searchstatus) | Triggered during the course of a service search |
| [serviceupdated](#notification_serviceupdated) | (Version 2) Notification sent when details of a service have changed, such as its name, service type, running or scrambled state |
| [serviceadded](#notification_serviceadded) | (Version 2) Notification sent when a new service has been dynamically added to the service list |
| [servicedeleted](#notification_servicedeleted) | (Version 2) Notification sent when a service has been deleted from the service list |
| [videochanged](#notification_videochanged) | (Version 2) Notification sent when the video PID or codec has changed |
| [audiochanged](#notification_audiochanged) | (Version 2) Notification sent when the audio PID or codec has changed |
| [subtitleschanged](#notification_subtitleschanged) | (Version 2) Notification sent when the subtitles have changed |
| [eventchanged](#notification_eventchanged) | (Version 2) Notification sent when the EIT 'now' event is received when starting to play a service and when the 'now' event changes |

<a id="notification_searchstatus"></a>
## *searchstatus [<sup>notification</sup>](#head_Notifications)*

Triggered during the course of a service search.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.handle | integer | mandatory | The handle assigned for the search and to which this information is relevant |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.finished | boolean | mandatory | True if the service search has finished, false otherwise |
| params.progress | integer | mandatory | Progress of the search expressed as a percentage |
| params?.transport | object | optional | Information for the given transport as defined by its DVB doublet URI |
| params?.transport.tunertype | string | mandatory | Tuner type (must be one of the following: *dvbc, dvbs, dvbt, none*) |
| params?.transport.originalnetworkid | integer | mandatory | Original network ID of the transport |
| params?.transport.transportid | integer | mandatory | Transport ID of the transport |
| params?.transport.strength | integer | mandatory | Signal strength as a percentage |
| params?.transport.quality | integer | mandatory | Signal quality as a percentage |
| params?.transport?.dvbctuningparams | object | optional | Parameters required to tune to a DVB-C signal |
| params?.transport?.dvbctuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| params?.transport?.dvbctuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| params?.transport?.dvbctuningparams.modulation | string | mandatory | *...* (must be one of the following: *128qam, 16qam, 256qam, 32qam, 4qam, 64qam, 8qam, auto*) |
| params?.transport?.dvbstuningparams | object | optional | Parameters required to tune to a DVB-S/S2 signal |
| params?.transport?.dvbstuningparams.satellite | string | mandatory | Name of the satellite settings to be used |
| params?.transport?.dvbstuningparams.frequency | integer | mandatory | Frequency of the transponder, in kHz |
| params?.transport?.dvbstuningparams.polarity | string | mandatory | *...* (must be one of the following: *horizontal, left, right, vertical*) |
| params?.transport?.dvbstuningparams.symbolrate | integer | mandatory | Symbol rate in Ksymb/sec |
| params?.transport?.dvbstuningparams.fec | string | mandatory | Forward error correction setting (must be one of the following: *fec1_2, fec1_3, fec1_4, fec2_3, fec2_5, fec3_4, fec3_5, fec4_5, fec5_6, fec7_8, fec8_9, fec9_10, fecauto*) |
| params?.transport?.dvbstuningparams.modulation | string | mandatory | *...* (must be one of the following: *16qam, 8psk, auto, qpsk*) |
| params?.transport?.dvbstuningparams.dvbs2 | boolean | mandatory | True when tuning to a DVB-S2 signal |
| params?.transport?.dvbttuningparams | object | optional | Parameters required to tune to a DVB-T/T2 signal |
| params?.transport?.dvbttuningparams.frequency | integer | mandatory | Frequency of the transport, in Hz |
| params?.transport?.dvbttuningparams.bandwidth | string | mandatory | Channel bandwidth (must be one of the following: *10MHz, 5MHz, 6MHz, 7MHz, 8MHz, undefined*) |
| params?.transport?.dvbttuningparams.mode | string | mandatory | OFDM mode (must be one of the following: *ofdm_16K, ofdm_1K, ofdm_2K, ofdm_32K, ofdm_4K, ofdm_8K, undefined*) |
| params?.transport?.dvbttuningparams.dvbt2 | boolean | mandatory | True when tuning to a DVB-T2 signal |
| params?.transport?.dvbttuningparams?.plpid | integer | optional | PLP ID for tuning to a DVB-T2 signal |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "searchstatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.searchstatus",
  "params": {
    "handle": 0,
    "eventtype": "ServiceSearchStatus",
    "finished": false,
    "progress": 65,
    "transport": {
      "tunertype": "dvbt",
      "originalnetworkid": 8204,
      "transportid": 8204,
      "strength": 76,
      "quality": 95,
      "dvbctuningparams": {
        "frequency": 474000000,
        "symbolrate": 6900,
        "modulation": "128qam"
      },
      "dvbstuningparams": {
        "satellite": "Astra 28.2",
        "frequency": 10714000,
        "polarity": "horizontal",
        "symbolrate": 22000,
        "fec": "fec5_6",
        "modulation": "qpsk",
        "dvbs2": false
      },
      "dvbttuningparams": {
        "frequency": 474000000,
        "bandwidth": "8MHz",
        "mode": "ofdm_32K",
        "dvbt2": false,
        "plpid": 0
      }
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.searchstatus``.

<a id="notification_serviceupdated"></a>
## *serviceupdated [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when details of a service have changed, such as its name, service type, running or scrambled state.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "serviceupdated",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.serviceupdated",
  "params": {
    "eventtype": "ServiceUpdated",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.serviceupdated``.

<a id="notification_serviceadded"></a>
## *serviceadded [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when a new service has been dynamically added to the service list.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "serviceadded",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.serviceadded",
  "params": {
    "eventtype": "ServiceAdded",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.serviceadded``.

<a id="notification_servicedeleted"></a>
## *servicedeleted [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when a service has been deleted from the service list.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "servicedeleted",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.servicedeleted",
  "params": {
    "eventtype": "ServiceDeleted",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.servicedeleted``.

<a id="notification_videochanged"></a>
## *videochanged [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when the video PID or codec has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "videochanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.videochanged",
  "params": {
    "eventtype": "VideoChanged",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.videochanged``.

<a id="notification_audiochanged"></a>
## *audiochanged [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when the audio PID or codec has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "audiochanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.audiochanged",
  "params": {
    "eventtype": "AudioChanged",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.audiochanged``.

<a id="notification_subtitleschanged"></a>
## *subtitleschanged [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when the subtitles have changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "subtitleschanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.subtitleschanged",
  "params": {
    "eventtype": "SubtitlesChanged",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.subtitleschanged``.

<a id="notification_eventchanged"></a>
## *eventchanged [<sup>notification</sup>](#head_Notifications)*

(Version 2) Notification sent when the EIT 'now' event is received when starting to play a service and when the 'now' event changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.eventtype | string | mandatory | Event type that's sent as an asynchronous notification (must be one of the following: *ServiceSearchStatus, audiochanged, eventchanged, serviceadded, servicedeleted, serviceupdated, subtitleschanged, videochanged*) |
| params.service | object | mandatory | Information for the given service as defined by its DVB triplet URI |
| params.service.fullname | string | mandatory | (Version 2) Full service name as given by the service descriptor in the SDT |
| params.service.shortname | string | mandatory | Short service name as given by the service descriptor in the SDT |
| params.service.dvburi | string | mandatory | DVB triplet of the form a.b.c, where 'a' is the original network ID, 'b' is the transport ID and 'c' is the service ID, in decimal |
| params.service.servicetype | string | mandatory | (Version 2) Service type as given by the service descriptor in the SDT (must be one of the following: *avc_hd_nvod, avc_hd_nvod_timeshift, avc_mosaic, avc_radio, avc_sd_nvod, avc_sd_nvod_timeshift, avc_sd_tv, data, hd_tv, mosaic, mpeg2_hd, nvod, nvod_timeshift, radio, teletext, tv, uhd_tv, unknown*) |
| params.service.lcn | integer | mandatory | Logical channel number |
| params.service.scrambled | boolean | mandatory | (Version 2) True if the service is marked as scrambled in the SDT |
| params.service.hascadescriptor | boolean | mandatory | (Version 2) True if there is at least one CA descriptor in the service's PMT |
| params.service.hidden | boolean | mandatory | (Version 2) True if the service should be hidden |
| params.service.selectable | boolean | mandatory | (Version 2) True if the service should be user selectable |
| params.service.runningstatus | string | mandatory | (Version 2) The running status as given by the service descriptor in the SDT (must be one of the following: *notrunning, offair, pausing, running, startssoon, undefined*) |
| params.event | object | mandatory | EIT event information |
| params.event.name | string | mandatory | Name of the DVB event as defined in the short event descriptor |
| params.event.starttime | integer | mandatory | UTC start time of the event in seconds |
| params.event.duration | integer | mandatory | Duration of the event in seconds |
| params.event.eventid | integer | mandatory | ID of the event from the event information table |
| params.event.shortdescription | string | mandatory | Event description from the EIT short event descriptor |
| params.event.hassubtitles | boolean | mandatory | (Version 2) True if subtitles are available |
| params.event.hasaudiodescription | boolean | mandatory | (Version 2) True if audio description is available |
| params.event.parentalrating | integer | mandatory | (Version 2) Parental rating for the event, will be 0 if undefined |
| params.event.contentdata | array | mandatory | (Version 2) The first 2 4-bit values from the content descriptor as separate bytes |
| params.event.contentdata[#] | integer | mandatory | *...* |
| params.event.hasextendedinfo | boolean | mandatory | (Version 2) True if there's extended event information available |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "DTV.register",
  "params": {
    "event": "eventchanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.eventchanged",
  "params": {
    "eventtype": "EventChanged",
    "service": {
      "fullname": "Channel 4",
      "shortname": "C4",
      "dvburi": "2.2041.9212",
      "servicetype": "tv",
      "lcn": 1001,
      "scrambled": false,
      "hascadescriptor": false,
      "hidden": false,
      "selectable": false,
      "runningstatus": "running"
    },
    "event": {
      "name": "Channel 4 News",
      "starttime": 1587562065,
      "duration": 1800,
      "eventid": 3012,
      "shortdescription": "The current national and world news",
      "hassubtitles": false,
      "hasaudiodescription": false,
      "parentalrating": 12,
      "contentdata": [
        0
      ],
      "hasextendedinfo": false
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.eventchanged``.

