<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ILEDControl_Plugin"></a>
# LEDControl Plugin

A org.rdk.LEDControl plugin for Thunder framework.

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

The `LEDControl` plugin allows you to control brightness and power state for LEDs on a device.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.LEDControl*) |
| classname | string | Class name: *org.rdk.LEDControl* |
| locator | string | Library name: *libWPEFrameworkLEDControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the LEDControl plugin:

LEDControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetLEDState](#method.GetLEDState) | Retrieves current state of the LED. e.g. "WPS_CONNECTING" |
| [GetSupportedLEDStates](#method.GetSupportedLEDStates) | Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`. |
| [SetLEDState](#method.SetLEDState) | Changes the device LED state to mentioned input state. |

<a id="method.GetLEDState"></a>
## *GetLEDState [<sup>method</sup>](#head.Methods)*

Retrieves current state of the LED. e.g. "WPS_CONNECTING"

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.state | LEDControlState | LEDControlState |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ILEDControl.GetLEDState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "state": "FACTORY_RESET"
    }
}
```
<a id="method.GetSupportedLEDStates"></a>
## *GetSupportedLEDStates [<sup>method</sup>](#head.Methods)*

Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedLEDStates | IStringIterator | string [] of supported LED states.  |
| result.supportedLEDStates[#] | string |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ILEDControl.GetSupportedLEDStates"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedLEDStates": [
            "ACTIVE", "STANDBY", "WPS_CONNECTING", "WPS_CONNECTED", "WPS_ERROR", "FACTORY_RESET", "USB_UPGRADE", "DOWNLOAD_ERROR"
        ],
        "success": "true"
    }
}
```
<a id="method.SetLEDState"></a>
## *SetLEDState [<sup>method</sup>](#head.Methods)*

Changes the device LED state to mentioned input state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.state | LEDControlState | LEDControlState |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ILEDControl.SetLEDState",
    "params": {
        "state": "FACTORY_RESET"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": "true"
    }
}
```
