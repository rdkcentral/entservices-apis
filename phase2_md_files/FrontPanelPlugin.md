<!-- Generated automatically, DO NOT EDIT! -->
<a id="FrontPanel_Plugin"></a>
# FrontPanel Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FrontPanel/IFrontPanel.h)**

A FrontPanel plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `FrontPanel` plugin provides an interface for FrontPanel.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FrontPanel) |
| classname | string | Class name: *FrontPanel* |
| locator | string | Library name: *libWPEFrameworkFrontPanel.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the FrontPanel plugin:

FrontPanel interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getBrightness](#getBrightness) | Gets the status of the Front Panel | NA |
| [getFrontPanelLights](#getFrontPanelLights) | Gets the front panel lights | NA |
| [powerLedOff](#powerLedOff) | Switches the specified LED off | NA |
| [powerLedOn](#powerLedOn) | Switches the specified LED on | NA |
| [setBlink](#setBlink) | Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) | NA |
| [setBrightness](#setBrightness) | Sets the brightness of the specified LED | NA |
| [setLED](#setLED) | Sets the LED with the specified color and brightness | NA |

<a id="getBrightness"></a>
## *getBrightness [<sup>method</sup>](#Methods)*

Gets the status of the Front Panel

### Events
Event details will be updated soon.
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
        "brightness": 0,
        "success": true
    }
}
```

<a id="getFrontPanelLights"></a>
## *getFrontPanelLights [<sup>method</sup>](#Methods)*

Gets the front panel lights

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedLights | IFrontPanelLightsListIterator | List of supported front panel lights |
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
            ""
        ],
        "supportedLightsInfo": "",
        "success": true
    }
}
```

<a id="powerLedOff"></a>
## *powerLedOff [<sup>method</sup>](#Methods)*

Switches the specified LED off

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the brightness level |
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
    "result": {
        "success": true
    }
}
```

<a id="powerLedOn"></a>
## *powerLedOn [<sup>method</sup>](#Methods)*

Switches the specified LED on

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the brightness level |
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
    "result": {
        "success": true
    }
}
```

<a id="setBlink"></a>
## *setBlink [<sup>method</sup>](#Methods)*

Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string)

### Events
Event details will be updated soon.
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
        "blinkInfo": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.FrontPanel.setBlink", "params": {"blinkInfo": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="setBrightness"></a>
## *setBrightness [<sup>method</sup>](#Methods)*

Sets the brightness of the specified LED

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.index | string | Index of the brightness level |
| params.brightness | integer | Brightness level |
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
        "brightness": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.FrontPanel.setBrightness", "params": {"index": "", "brightness": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "success": true
    }
}
```

<a id="setLED"></a>
## *setLED [<sup>method</sup>](#Methods)*

Sets the LED with the specified color and brightness

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ledIndicator | string | LED indicator to set |
| params.brightness | integer | Brightness level |
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
        "ledIndicator": "",
        "brightness": 0,
        "color": "",
        "red": 0,
        "green": 0,
        "blue": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.FrontPanel.setLED", "params": {"ledIndicator": "", "brightness": 0, "color": "", "red": 0, "green": 0, "blue": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "success": true
    }
}
```


