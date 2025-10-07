<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.FrontPanel_Plugin"></a>
# FrontPanel Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/FrontPanel/CHANGELOG.md)**

A FrontPanel plugin for Thunder framework.

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

The `FrontPanel` plugin provides an interface for FrontPanel.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.FrontPanel*) |
| classname | string | Class name: *org.rdk.FrontPanel* |
| locator | string | Library name: *libWPEFrameworkFrontPanel.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.FrontPanel plugin:

FrontPanel interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetBrightness](#method.GetBrightness) | Gets the status of the Front Panel |
| [GetFrontPanelLights](#method.GetFrontPanelLights) | Gets the front panel lights |
| [PowerLedOff](#method.PowerLedOff) | Switches the specified LED off |
| [PowerLedOn](#method.PowerLedOn) | Switches the specified LED on |
| [SetBlink](#method.SetBlink) | Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) |
| [SetBrightness](#method.SetBrightness) | Sets the brightness of the specified LED |
| [SetLED](#method.SetLED) | Sets the LED with the specified color and brightness |

<a id="method.getBrightness"></a>
## *GetBrightness [<sup>method</sup>](#head.Methods)*

Gets the status of the Front Panel

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.index | string | Index of the brightness level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.brightness | uint32_t | Brightness level |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.getBrightness",
    "params": {
        "index": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "brightness": "0",
        "success": "true"
    }
}
```
<a id="method.getFrontPanelLights"></a>
## *GetFrontPanelLights [<sup>method</sup>](#head.Methods)*

Gets the front panel lights

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedLights | FrontPanelLightsListIterator | List of supported front panel lights |
| result.supportedLights[#] | string |  |
| result.supportedLightsInfo | string | Information about the supported front panel lights |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.getFrontPanelLights"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedLights": [
            "power_led"
        ],
        "supportedLightsInfo": {
            "power_led": {
                "range": "int",
                "min": 0,
                "max": 100,
                "step": 10,
                "colorMode": 2,
                "colors": [
                    "red"
                ]
            }
        },
        "success": "true"
    }
}
```
<a id="method.PowerLedOff"></a>
## *PowerLedOff [<sup>method</sup>](#head.Methods)*

Switches the specified LED off

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.index | string | Index of the brightness level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.powerLedOff",
    "params": {
        "index": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.PowerLedOn"></a>
## *PowerLedOn [<sup>method</sup>](#head.Methods)*

Switches the specified LED on

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.index | string | Index of the brightness level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.powerLedOn",
    "params": {
        "index": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetBlink"></a>
## *SetBlink [<sup>method</sup>](#head.Methods)*

Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string)

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.blinkInfo | string | JSON string with blink pattern information containing ledIndicator, iterations, and pattern array with brightness, duration(milliseconds), and optional color and red/green/blue values. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.setBlink",
    "params": {
        "blinkInfo": {
            "ledIndicator": "power_led",
            "iterations": 10,
            "pattern": [
                {
                    "brightness": 50,
                    "duration": 100,
                    "color": "red",
                    "red": 0,
                    "green": 0,
                    "blue": 0
                }
            ]
        },
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetBrightness"></a>
## *SetBrightness [<sup>method</sup>](#head.Methods)*

Sets the brightness of the specified LED

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.index | string | Index of the brightness level |
| params.brightness | uint32_t | Brightness level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.setBrightness",
    "params": {
        "index": "",
        "brightness": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```
<a id="method.SetLED"></a>
## *SetLED [<sup>method</sup>](#head.Methods)*

Sets the LED with the specified color and brightness

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.ledIndicator | string | LED indicator to set |
| params.brightness | uint32_t | Brightness level |
| params.color | string | Color of the LED |
| params.red | uint32_t | Red component of the LED color |
| params.green | uint32_t | Green component of the LED color |
| params.blue | uint32_t | Blue component of the LED color |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.FrontPanel.setLED",
    "params": {
        "ledIndicator": "",
        "brightness": "0",
        "color": "",
        "red": "0",
        "green": "0",
        "blue": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": {
            "success": "true"
        }
    }
}
```

