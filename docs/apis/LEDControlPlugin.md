<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.LEDControl_Plugin"></a>
# LEDControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/LEDControl/CHANGELOG.md)**

A LEDControl plugin for Thunder framework.

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

The `LEDControl` plugin provides an interface for LEDControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LEDControl) |
| classname | string | Class name: *LEDControl* |
| locator | string | Library name: *libWPEFrameworkLEDControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the LEDControl plugin:

LEDControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getLEDState](#method.getLEDState) | Returns current LED state. |
| [getSupportedLEDStates](#method.getSupportedLEDStates) | Returns all the LED states supported by the platform |
| [setLEDState](#method.setLEDState) | Change the device LED state to one mentioned in the input argument. |

<a id="method.getLEDState"></a>
## *getLEDState [<sup>method</sup>](#head.Methods)*

Returns current LED state.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.ledState | LEDControlState | - |
| result.ledState.state | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LEDControl.getLEDState"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "state": ""
    }
}
```

<a id="method.getSupportedLEDStates"></a>
## *getSupportedLEDStates [<sup>method</sup>](#head.Methods)*

Returns all the LED states supported by the platform

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedLEDStates | IStringIterator | - out - string [] of supported LED states |
| result.supportedLEDStates[#] | string | - |
| result.success | bool | - out - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LEDControl.getSupportedLEDStates"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "supportedLEDStates": [
            ""
        ],
        "success": true
    }
}
```

<a id="method.setLEDState"></a>
## *setLEDState [<sup>method</sup>](#head.Methods)*

Change the device LED state to one mentioned in the input argument.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | string | - in - string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | - out - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.LEDControl.setLEDState",
    "params": {
        "state": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": true
}
```


