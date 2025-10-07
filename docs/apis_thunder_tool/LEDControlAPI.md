<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_LEDControl_API"></a>
# LEDControl API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

LEDControl interface for Thunder framework.

(Defined with ILEDControl in [ILEDControl.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ILEDControl.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the LEDControl interface (version 1.0.0). It includes detailed specification about its methods provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

LEDControl JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the LEDControl interface:

LEDControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getSupportedLEDStates](#method_getSupportedLEDStates) |  |
| [getLEDState](#method_getLEDState) | Retrieves current state of the LED |
| [setLEDState](#method_setLEDState) | Sets the device LED to a requested state from those available in `GetSupportedLEDStates` |

<a id="method_getSupportedLEDStates"></a>
## *getSupportedLEDStates [<sup>method</sup>](#head_Methods)*

### Description

Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.supportedLEDStates | array | mandatory | String [] of supported LED states. e.g. "['ACTIVE', 'STANDBY', 'WPS_CONNECTING', 'WPS_CONNECTED', 'WPS_ERROR', 'FACTORY_RESET', 'USB_UPGRADE', 'DOWNLOAD_ERROR']" |
| result.supportedLEDStates[#] | string | mandatory |  |
| result.success | boolean | mandatory | Boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getSupportedLEDStates"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedLEDStates": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_getLEDState"></a>
## *getLEDState [<sup>method</sup>](#head_Methods)*

Retrieves current state of the LED. e.g. {"state":"WPS_CONNECTING"}.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | LEDState |
| result.state | string | mandatory |  (must be one of the following: *ACTIVE, DOWNLOAD_ERROR, FACTORY_RESET, MAX, NONE, STANDBY, USB_UPGRADE, WPS_CONNECTED, WPS_CONNECTING, WPS_ERROR*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLEDState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "state": "ACTIVE"
  }
}
```

<a id="method_setLEDState"></a>
## *setLEDState [<sup>method</sup>](#head_Methods)*

Sets the device LED to a requested state from those available in `GetSupportedLEDStates`.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.state | string | mandatory | LEDControlState. e.g. "FACTORY_RESET" (must be one of the following: *ACTIVE, DOWNLOAD_ERROR, FACTORY_RESET, MAX, NONE, STANDBY, USB_UPGRADE, WPS_CONNECTED, WPS_CONNECTING, WPS_ERROR*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Boolean |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setLEDState",
  "params": {
    "state": "ACTIVE"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

