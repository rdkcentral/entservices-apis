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
| [generateKey](#generateKey) | Simulates key events for a list of key entries. Each entry contains parallel arrays of key codes and their corresponding modifier sets, along with timing controls. |

<a id="generateKey"></a>
## *generateKey*

Supported action to key mapping:

| Action | Linux Key Symbol | Linux Key Code | Modifiers |
| :-------- | :-------- | :-------- | :-------- |
| Menu | KEY_HOME | 102 | - |
| Guide | KEY_HOME | 102 | - |
| Info | KEY_F9 | 67 | - |
| Star | KEY_F6 | 64 | - |
| TV Power | KEY_F1 | 59 | - |
| Input | KEY_F15 | 185 | - |
| OK | KEY_OK | 352 | - |
| Select | KEY_ENTER | 28 | - |
| Enter | KEY_ENTER | 28 | - |
| Exit | KEY_ESC | 1 | - |
| Back | KEY_ESC | 1 | - |
| Period | KEY_F5 | 63 | - |
| Push To Talk | KEY_F8 | 66 | - |
| Power | KEY_POWER | 116 | - |
| Channel Up | KEY_UP | 103 | ctrl |
| Channel Down | KEY_DOWN | 108 | ctrl |
| Volume Up | KEY_KPPLUS | 78 | - |
| Volume Down | KEY_KPMINUS | 74 | - |
| Mute | KEY_KPASTERISK | 55 | - |
| Digit 1 | KEY_1 | 2 | - |
| Digit 2 | KEY_2 | 3 | - |
| Digit 3 | KEY_3 | 4 | - |
| Digit 4 | KEY_4 | 5 | - |
| Digit 5 | KEY_5 | 6 | - |
| Digit 6 | KEY_6 | 7 | - |
| Digit 7 | KEY_7 | 8 | - |
| Digit 8 | KEY_8 | 9 | - |
| Digit 9 | KEY_9 | 10 | - |
| Digit 0 | KEY_0 | 11 | - |
| Fast Forward | KEY_F12 | 88 | - |
| Rewind | KEY_F10 | 68 | - |
| Pause | KEY_F11 | 87 | - |
| Play | KEY_F11 | 87 | - |
| Stop | KEY_S | 31 | ctrl |
| Record | KEY_F7 | 65 | - |
| Arrow Up | KEY_UP | 103 | - |
| Arrow Down | KEY_DOWN | 108 | - |
| Arrow Left | KEY_LEFT | 105 | - |
| Arrow Right | KEY_RIGHT | 106 | - |
| Page Up | KEY_PAGEUP | 104 | - |
| Page Down | KEY_PAGEDOWN | 109 | - |
| Last | KEY_L | 38 | ctrl |
| Favorite | KEY_N | 49 | ctrl |
| Key A | KEY_INSERT | 110 | - |
| Key B | KEY_END | 107 | - |
| Key C | KEY_F4 | 62 | - |
| Key D | KEY_DELETE | 111 | - |
| Help | KEY_F2 | 60 | - |
| Setup | KEY_SETUP | 141 | - |
| Next | KEY_NEXT | 407 | - |
| Previous | KEY_PREVIOUS | 412 | - |
| On Demand | KEY_F5 | 63 | - |
| Pound | KEY_BATTERY | 236 | - |
| Audio | KEY_F23 | 193 | - |
| Closed Captioning | KEY_F24 | 194 | - |
| Replay | KEY_B | 48 | ctrl |
| Search | KEY_F3 | 61 | - |
| RF Pair Ghost | KEY_BLUETOOTH | 237 | - |
| Undefined | KEY_UNKNOWN | 240 | - |

### Events Triggered
None

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | string | JSON array of key entry objects. Each object contains: keyCode (array of Linux key codes), modifiers (array of arrays of modifier strings, where modifiers[i] applies to keyCode[i]; supported values: "ctrl", "alt", "shift"), delay (number, seconds to wait before sending the key event), duration (number, optional, seconds between key press and key release; omit or 0 if not used) |


### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Tools.generateKey",
    "params": {
        "keys": ""
    }
}
```


#### CURL Command

```curl
curl -d '{  "jsonrpc": "2.0",  "id": 42,  "method": "org.rdk.Tools.generateKey",  "params": {    "keys": [      {        "keyCode": 11,        "modifiers": ["ctrl", "alt"],        "delay": 0.5,        "duration": 0.1      }    ]  }}' http://127.0.0.1:9998/jsonrpc
```



#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Failed to generate keys"
    }
}
```


#### Error Response (Core::ERROR_INVALID_INPUT_LENGTH)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 14,
        "message": "The keys list is empty or invalid"
    }
}
```
