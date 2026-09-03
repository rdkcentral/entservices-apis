<!-- Generated automatically, DO NOT EDIT! -->
<a id="FrontPanel_Module"></a>
# FrontPanel Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FrontPanel/IFrontPanel.h)**

A FrontPanel module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IFrontPanel](#IFrontPanel)
    - [Methods](#IFrontPanel-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `FrontPanel` module provides the following interface(s):

- IFrontPanel

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FrontPanel) |
| classname | string | Class name: *FrontPanel* |
| locator | string | Library name: *libWPEFrameworkFrontPanel.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IFrontPanel"></a>
## IFrontPanel Interface

<a id="IFrontPanel-Methods"></a>
### Methods

The following methods are provided by the IFrontPanel Interface:

| Method | Description |
| :-------- | :-------- |
| [getBrightness](#getBrightness) | Gets the status of the Front Panel |
| [getFrontPanelLights](#getFrontPanelLights) | Gets the front panel lights |
| [powerLedOff](#powerLedOff) | Switches the specified LED off |
| [powerLedOn](#powerLedOn) | Switches the specified LED on |
| [setBlink](#setBlink) | Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) |
| [setBrightness](#setBrightness) | Sets the brightness of the specified LED |
| [setLED](#setLED) | Sets the LED with the specified color and brightness |

<a id="getBrightness"></a>
## *getBrightness*

Provides the current active brightness state or percentage value configured for the device display panel.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the brightness level |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.brightness | integer | Brightness level |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FrontPanel.getBrightness",
    "params": {
        "index": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.FrontPanel.getBrightness", "params": {"index": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "brightness": 100,
        "success": true
    }
}
```

<a id="getFrontPanelLights"></a>
## *getFrontPanelLights*

Provides a list or status bitmask of the active illumination nodes present on the physical display facade of the device.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedLights | array | List of supported front panel lights |
| result.supportedLights[#] | string |  |
| result.supportedLightsInfo | string | Information about the supported front panel lights |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FrontPanel.getFrontPanelLights"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.FrontPanel.getFrontPanelLights"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "supportedLights": [
            "POWER_LED",
            "STATUS_LED"
        ],
        "supportedLightsInfo": "The front panel supports POWER_LED and STATUS_LED.",
        "success": true
    }
}
```

<a id="powerLedOff"></a>
## *powerLedOff*

Cuts power or disables illumination for the specified light source on the device facade using its identifier.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the LED to switch off |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FrontPanel.powerLedOff",
    "params": {
        "index": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.FrontPanel.powerLedOff", "params": {"index": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": true
}
```

<a id="powerLedOn"></a>
## *powerLedOn*

Applies power or enables illumination for the specified light source on the device facade using its identifier.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the LED to switch on |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FrontPanel.powerLedOn",
    "params": {
        "index": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.FrontPanel.powerLedOn", "params": {"index": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": true
}
```

<a id="setBlink"></a>
## *setBlink*

Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) - the LED indicator to set, iterations (integer) - the number of times to repeat the pattern, and pattern (array of objects) - each object contains brightness (integer), duration (integer in milliseconds), and optional color (string) and red/green/blue (integers) values.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blinkInfo | string | JSON string with blink pattern information containing ledIndicator, iterations, and pattern array with brightness, duration(milliseconds), and optional color and red/green/blue values. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.FrontPanel.setBlink",
    "params": {
        "blinkInfo": {
            "ledIndicator": "POWER_LED",
            "iterations": 3,
            "pattern": [
                {
                    "brightness": 100,
                    "duration": 500
                },
                {
                    "brightness": 0,
                    "duration": 500
                }
            ]
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.FrontPanel.setBlink", "params": {"blinkInfo": {"ledIndicator": "POWER_LED", "iterations": 3, "pattern": [{"brightness": 100, "duration": 500}, {"brightness": 0, "duration": 500}]}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": true
}
```

<a id="setBrightness"></a>
## *setBrightness*

Adjusts the intensity of the light source corresponding to the provided index using a percentage or discrete scale value.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the brightness level |
| params.brightness | integer | Brightness level to set |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.FrontPanel.setBrightness",
    "params": {
        "index": "",
        "brightness": 100
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.FrontPanel.setBrightness", "params": {"index": "", "brightness": 100}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": true
}
```

<a id="setLED"></a>
## *setLED*

Configures the specified LED on the device facade with the provided color and brightness settings.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ledIndicator | string | LED indicator to set |
| params.brightness | integer | Brightness level of the LED |
| params.color | string | Color of the LED |
| params.red | integer | Red component of the LED color |
| params.green | integer | Green component of the LED color |
| params.blue | integer | Blue component of the LED color |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Is the operation successful or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.FrontPanel.setLED",
    "params": {
        "ledIndicator": "POWER_LED",
        "brightness": 100,
        "color": "red",
        "red": 255,
        "green": 0,
        "blue": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.FrontPanel.setLED", "params": {"ledIndicator": "POWER_LED", "brightness": 100, "color": "red", "red": 255, "green": 0, "blue": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```

