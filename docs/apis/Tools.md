<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Tools_API"></a>
# Tools API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Tools interface for Thunder framework.

(Defined with ITools in [ITools.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITools.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Tools interface (version 1.0.0). It includes detailed specification about its methods provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

Tools JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Tools interface:

Tools interface methods:

| Method | Description |
| :-------- | :-------- |
| [generateKeys](#method_generateKeys) | Generates local key events for each key entry |
| [generateRemoteKeys](#method_generateRemoteKeys) | Generates remote key events for each key entry |

<a id="method_generateKeys"></a>
## *generateKeys [<sup>method</sup>](#head_Methods)*

Generates local key events for each key entry.

### Description

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.keys | array | mandatory | List of keys to generate in order. Each entry supports delay and optional duration<br>*Array length must be at most 100 elements.* |
| params.keys[#] | object | mandatory | *...* |
| params.keys[#].code | integer | mandatory | Linux key code as defined in linux/include/uapi/linux/input-event-codes.h. The full Linux key code list is supported |
| params.keys[#].modifier | string | mandatory | Key modifier (must be one of the following: *ALT, ALT_CTRL, CTRL, NONE, SHIFT, SHIFT_ALT, SHIFT_ALT_CTRL, SHIFT_CTRL*) |
| params.keys[#].delay | integer | mandatory | Seconds to wait before sending the key event |
| params.keys[#].duration | integer | mandatory | Seconds between key press and key release; use 0 if not required |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Indicates whether the operation was successful |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Keys generated successfully |
| ```Core::ERROR_GENERAL``` | Failed to generate one or more key events |
| ```Core::ERROR_INVALID_INPUT_LENGTH``` | Input key list is empty |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.generateKeys",
  "params": {
    "keys": [
      {
        "code": 0,
        "modifier": "CTRL",
        "delay": 0,
        "duration": 0
      }
    ]
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

<a id="method_generateRemoteKeys"></a>
## *generateRemoteKeys [<sup>method</sup>](#head_Methods)*

Generates remote key events for each key entry.

### Description

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.keys | array | mandatory | List of remote keys to generate in order. Each entry supports delay and optional duration<br>*Array length must be at most 100 elements.* |
| params.keys[#] | object | mandatory | *...* |
| params.keys[#].code | string | mandatory | Remote key code (must be one of the following: *KED_ARROWDOWN, KED_ARROWLEFT, KED_ARROWRIGHT, KED_ARROWUP, KED_AUDIO, KED_BACK, KED_CHANNELDOWN, KED_CHANNELUP, KED_CLOSED_CAPTIONING, KED_DIGIT0, KED_DIGIT1, KED_DIGIT2, KED_DIGIT3, KED_DIGIT4, KED_DIGIT5, KED_DIGIT6, KED_DIGIT7, KED_DIGIT8, KED_DIGIT9, KED_ENTER, KED_EXIT, KED_FASTFORWARD, KED_FAVORITE, KED_GUIDE, KED_HELP, KED_INFO, KED_INPUTKEY, KED_KEYA, KED_KEYB, KED_KEYC, KED_KEYD, KED_LAST, KED_MENU, KED_MUTE, KED_NEXT, KED_OK, KED_ONDEMAND, KED_PAGEDOWN, KED_PAGEUP, KED_PAUSE, KED_PERIOD, KED_PLAY, KED_POUND, KED_POWER, KED_PREVIOUS, KED_PUSH_TO_TALK, KED_RECORD, KED_REPLAY, KED_REWIND, KED_RF_PAIR_GHOST, KED_SEARCH, KED_SELECT, KED_SETUP, KED_STAR, KED_STOP, KED_TVPOWER, KED_UNDEFINEDKEY, KED_VOLUMEDOWN, KED_VOLUMEUP*) |
| params.keys[#].delay | integer | mandatory | Seconds to wait before sending the key event |
| params.keys[#].duration | integer | mandatory | Seconds between key press and key release; use 0 if not required |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Indicates whether the operation was successful |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Remote keys generated successfully |
| ```Core::ERROR_GENERAL``` | Failed to generate one or more remote key events |
| ```Core::ERROR_INVALID_INPUT_LENGTH``` | Input key list is empty |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.generateRemoteKeys",
  "params": {
    "keys": [
      {
        "code": "KED_GUIDE",
        "delay": 0,
        "duration": 0
      }
    ]
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

