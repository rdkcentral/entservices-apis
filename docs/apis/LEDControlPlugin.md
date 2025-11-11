<!-- Generated automatically, DO NOT EDIT! -->
<a id="LEDControl_Plugin"></a>
# LEDControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/LEDControl/ILEDControl.h)**

A LEDControl plugin for Thunder framework.

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

The `LEDControl` plugin provides an interface for LEDControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.LEDControl) |
| classname | string | Class name: *LEDControl* |
| locator | string | Library name: *libWPEFrameworkLEDControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the LEDControl plugin:

LEDControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getLEDState](#getLEDState) | Retrieves current state of the LED. e.g. {"state":"WPS_CONNECTING"} |
| [getSupportedLEDStates](#getSupportedLEDStates) | Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`. |
| [setLEDState](#setLEDState) | Sets the device LED to a requested state from those available in `GetSupportedLEDStates`. |

<a id="getLEDState"></a>
## *getLEDState*

Retrieves current state of the LED. e.g. {"state":"WPS_CONNECTING"}

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | LEDControlState.  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.LEDControl.getLEDState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.LEDControl.getLEDState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "state": "LEDSTATE_NONE"
    }
}
```

<a id="getSupportedLEDStates"></a>
## *getSupportedLEDStates*

Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedLEDStates | IStringIterator | string [] of supported LED states.  |
| result.supportedLEDStates[#] | string |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.LEDControl.getSupportedLEDStates"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.LEDControl.getSupportedLEDStates"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "supportedLEDStates": [
            "['ACTIVE', 'STANDBY', 'WPS_CONNECTING', 'WPS_CONNECTED', 'WPS_ERROR', 'FACTORY_RESET', 'USB_UPGRADE', 'DOWNLOAD_ERROR']"
        ],
        "success": true
    }
}
```

<a id="setLEDState"></a>
## *setLEDState*

Sets the device LED to a requested state from those available in `GetSupportedLEDStates`.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | string | LEDControlState.  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.LEDControl.setLEDState",
    "params": {
        "state": "FACTORY_RESET"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.LEDControl.setLEDState", "params": {"state": "FACTORY_RESET"}}' http://127.0.0.1:9998/jsonrpc
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


