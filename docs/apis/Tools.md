<!-- Generated automatically, DO NOT EDIT! -->
<a id="Tools_Module"></a>
# Tools Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Tools/ITools.h)**

A Tools module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ITools](#ITools)
    - [Methods](#ITools-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Tools` module provides the following interface(s):

- ITools

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Tools) |
| classname | string | Class name: *Tools* |
| locator | string | Library name: *libWPEFrameworkTools.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ITools"></a>
## ITools Interface

<a id="ITools-Methods"></a>
### Methods

The following methods are provided by the ITools Interface:

| Method | Description |
| :-------- | :-------- |
| [generateKeys](#generateKeys) | Generates local key events for each key entry. |
| [generateRemoteKeys](#generateRemoteKeys) | Generates remote key events for each key entry. |

<a id="generateKeys"></a>
## *generateKeys*

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | array | List of keys to generate in order. Each entry supports delay and optional duration. |
| params.keys[#].code | int | Linux key code as defined in linux/include/uapi/linux/input-event-codes.h. The full Linux key code list is supported. |
| params.keys[#].modifier | string | Key modifier. Possible values: NONE, CTRL, ALT, ALT_CTRL, SHIFT, SHIFT_CTRL, SHIFT_ALT, SHIFT_ALT_CTRL |
| params.keys[#].delay | integer | Seconds to wait before sending the key event |
| params.keys[#].duration | integer | Seconds between key press and key release; use 0 if not required |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.Tools.generateKeys",
    "params": {
        "keys": [
            {
                "code": 0,
                "modifier": "NONE",
                "delay": 0,
                "duration": 0
            }
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.Tools.generateKeys", "params": {"keys": [{"code": 0, "modifier": "NONE", "delay": 0, "duration": 0}]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "Failed to generate one or more key events"
    }
}
```


#### Error Response (Core::ERROR_INVALID_INPUT_LENGTH)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 14,
        "message": "Input key list is empty"
    }
}
```

<a id="generateRemoteKeys"></a>
## *generateRemoteKeys*

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | array | List of remote keys to generate in order. Each entry supports delay and optional duration. |
| params.keys[#].code | string | Remote key code. Possible values: KED_MENU, KED_GUIDE, KED_INFO, KED_STAR, KED_TVPOWER, KED_INPUTKEY, KED_OK, KED_SELECT, KED_ENTER, KED_EXIT, KED_BACK, KED_PERIOD, KED_PUSH_TO_TALK, KED_POWER, KED_CHANNELUP, KED_CHANNELDOWN, KED_VOLUMEUP, KED_VOLUMEDOWN, KED_MUTE, KED_DIGIT1, KED_DIGIT2, KED_DIGIT3, KED_DIGIT4, KED_DIGIT5, KED_DIGIT6, KED_DIGIT7, KED_DIGIT8, KED_DIGIT9, KED_DIGIT0, KED_FASTFORWARD, KED_REWIND, KED_PAUSE, KED_PLAY, KED_STOP, KED_RECORD, KED_ARROWUP, KED_ARROWDOWN, KED_ARROWLEFT, KED_ARROWRIGHT, KED_PAGEUP, KED_PAGEDOWN, KED_LAST, KED_FAVORITE, KED_KEYA, KED_KEYB, KED_KEYC, KED_KEYD, KED_HELP, KED_SETUP, KED_NEXT, KED_PREVIOUS, KED_ONDEMAND, KED_POUND, KED_AUDIO, KED_CLOSED_CAPTIONING, KED_REPLAY, KED_SEARCH, KED_RF_PAIR_GHOST, KED_UNDEFINEDKEY           KEY_UNKNOWN |
| params.keys[#].delay | integer | Seconds to wait before sending the key event |
| params.keys[#].duration | integer | Seconds between key press and key release; use 0 if not required |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.Tools.generateRemoteKeys",
    "params": {
        "keys": [
            {
                "code": "KED_MENU",
                "delay": 0,
                "duration": 0
            }
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.Tools.generateRemoteKeys", "params": {"keys": [{"code": "KED_MENU", "delay": 0, "duration": 0}]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": {
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "Failed to generate one or more remote key events"
    }
}
```


#### Error Response (Core::ERROR_INVALID_INPUT_LENGTH)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 14,
        "message": "Input key list is empty"
    }
}
```

