<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_FrontPanel_API"></a>
# FrontPanel API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

FrontPanel interface for Thunder framework.

(Defined with IFrontPanel in [IFrontPanel.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IFrontPanel.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the FrontPanel interface (version 1.0.0). It includes detailed specification about its methods provided.

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

FrontPanel JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the FrontPanel interface:

FrontPanel interface methods:

| Method | Description |
| :-------- | :-------- |
| [getBrightness](#method_getBrightness) | Gets the status of the Front Panel |
| [getFrontPanelLights](#method_getFrontPanelLights) | Gets the front panel lights |
| [powerLedOff](#method_powerLedOff) | Switches the specified LED off |
| [powerLedOn](#method_powerLedOn) | Switches the specified LED on |
| [setBlink](#method_setBlink) | Sets a blink pattern for the specified LED |
| [setBrightness](#method_setBrightness) | Sets the brightness of the specified LED |
| [setLED](#method_setLED) | Sets the LED with the specified color and brightness |

<a id="method_getBrightness"></a>
## *getBrightness [<sup>method</sup>](#head_Methods)*

Gets the status of the Front Panel.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.index | string | mandatory | Index of the brightness level |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.brightness | integer | mandatory | Brightness level |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getBrightness",
  "params": {
    "index": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "brightness": 0,
    "success": false
  }
}
```

<a id="method_getFrontPanelLights"></a>
## *getFrontPanelLights [<sup>method</sup>](#head_Methods)*

Gets the front panel lights.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.supportedLights | array | mandatory | List of supported front panel lights |
| result.supportedLights[#] | string | mandatory |  |
| result.supportedLightsInfo | opaque object | mandatory | Information about the supported front panel lights |
| result.success | boolean | mandatory | Is the operation successful or not |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFrontPanelLights"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedLights": [
      "..."
    ],
    "supportedLightsInfo": {},
    "success": false
  }
}
```

<a id="method_powerLedOff"></a>
## *powerLedOff [<sup>method</sup>](#head_Methods)*

Switches the specified LED off.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.index | string | mandatory | Index of the LED to switch off |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.powerLedOff",
  "params": {
    "index": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_powerLedOn"></a>
## *powerLedOn [<sup>method</sup>](#head_Methods)*

Switches the specified LED on.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.index | string | mandatory | Index of the LED to switch on |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.powerLedOn",
  "params": {
    "index": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setBlink"></a>
## *setBlink [<sup>method</sup>](#head_Methods)*

Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.blinkInfo | opaque object | mandatory | JSON string with blink pattern information containing ledIndicator, iterations, and pattern array with brightness, duration(milliseconds), and optional color and red/green/blue values |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setBlink",
  "params": {
    "blinkInfo": {}
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setBrightness"></a>
## *setBrightness [<sup>method</sup>](#head_Methods)*

Sets the brightness of the specified LED.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.index | string | mandatory | Index of the brightness level |
| params.brightness | integer | mandatory | Brightness level to set |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setBrightness",
  "params": {
    "index": "...",
    "brightness": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setLED"></a>
## *setLED [<sup>method</sup>](#head_Methods)*

Sets the LED with the specified color and brightness.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.ledIndicator | string | mandatory | LED indicator to set |
| params.brightness | integer | mandatory | Brightness level of the LED |
| params.color | string | mandatory | Color of the LED |
| params.red | integer | mandatory | Red component of the LED color |
| params.green | integer | mandatory | Green component of the LED color |
| params.blue | integer | mandatory | Blue component of the LED color |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Is the operation successful or not |
| result.success | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setLED",
  "params": {
    "ledIndicator": "...",
    "brightness": 0,
    "color": "...",
    "red": 0,
    "green": 0,
    "blue": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

