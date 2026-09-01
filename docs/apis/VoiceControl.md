<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_VoiceControl_API"></a>
# VoiceControl API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

VoiceControl interface for Thunder framework.

(Defined with IVoiceControl in [IVoiceControl.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IVoiceControl.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the VoiceControl interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

VoiceControl JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the VoiceControl interface:

VoiceControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [getApiVersionNumber](#method_getApiVersionNumber) | Get the API version number |
| [voiceStatus](#method_voiceStatus) | Returns the current status of the RDK voice stack |
| [sendVoiceMessage](#method_sendVoiceMessage) | Sends a message to the Voice Server |
| [voiceSessionByText](#method_voiceSessionByText) | Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED) |
| [voiceSessionTypes](#method_voiceSessionTypes) | Retrieves the types of voice sessions which are supported by the platform |
| [voiceSessionTerminate](#method_voiceSessionTerminate) | Terminates a voice session using the specified session identifier |
| [voiceSessionAudioStreamStart](#method_voiceSessionAudioStreamStart) | Starts a subsequent audio stream for the voice session indicated by the session identifier |

<a id="method_getApiVersionNumber"></a>
## *getApiVersionNumber [<sup>method</sup>](#head_Methods)*

Get the API version number.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The API version response |
| result.version | integer | mandatory | The API version number ex: 1 |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Operation completed successfully. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getApiVersionNumber"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "version": 0,
    "success": false
  }
}
```

<a id="method_voiceStatus"></a>
## *voiceStatus [<sup>method</sup>](#head_Methods)*

Returns the current status of the RDK voice stack.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | The typed voice status fields including urlPtt, urlHf, urlMicTap, maskPii, prv, wwFeedback, ptt, ff, mic, optional mic_tap, capabilities, and success |
| result.maskPii | boolean | mandatory | Indicates if PII should be masked (1 - mask PII, 0 - display PII) |
| result.urlPtt | string | mandatory | The PTT URL e.g. "ws://voice.example.com/ptt" |
| result.urlHf | string | mandatory | The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" |
| result.urlMicTap | string | mandatory | The microphone tap URL e.g. "ws://voice.example.com/mictap" |
| result.prv | boolean | mandatory | The Press & Release Voice feature (true for enable, false for disable) |
| result.wwFeedback | boolean | mandatory | The Wake Word Feedback feature (true for enable, false for disable) |
| result.ptt | object | mandatory | The status information for the PTT device type |
| result.ptt.status | string | mandatory | The status of the device e.g. "ready" |
| result.ff | object | mandatory | The status information for the FF device type |
| result.ff.status | string | mandatory | The status of the device e.g. "ready" |
| result.mic | object | mandatory | The status information for the MIC device type |
| result.mic.status | string | mandatory | The status of the device e.g. "ready" |
| result?.mic_tap | object | optional | The status information for the MIC TAP device type, present only when MIC TAP capability is available |
| result?.mic_tap.status | string | mandatory | The status of the device e.g. "ready" |
| result.capabilities | opaque object | mandatory | JSON array of capability strings returned by the voice stack |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice status retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve voice status. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.voiceStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "maskPii": false,
    "urlPtt": "...",
    "urlHf": "...",
    "urlMicTap": "...",
    "prv": false,
    "wwFeedback": false,
    "ptt": {
      "status": "..."
    },
    "ff": {
      "status": "..."
    },
    "mic": {
      "status": "..."
    },
    "mic_tap": {
      "status": "..."
    },
    "capabilities": {},
    "success": false
  }
}
```

<a id="method_sendVoiceMessage"></a>
## *sendVoiceMessage [<sup>method</sup>](#head_Methods)*

Sends a message to the Voice Server.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.msgType | string | mandatory | Message type from the server e.g. "asr" |
| params?.trx | string | optional | *...* |
| params?.created | integer | optional | *...* |
| params?.msgPayload | opaque object | optional | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice message sent successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to send voice message. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.sendVoiceMessage",
  "params": {
    "msgType": "...",
    "trx": "...",
    "created": 0,
    "msgPayload": {}
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

<a id="method_voiceSessionByText"></a>
## *voiceSessionByText [<sup>method</sup>](#head_Methods)*

Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.transcription | string | mandatory | The transcription text to be sent to the voice server e.g. "turn on the lights" |
| params?.type | string | optional | *...* (must be one of the following: *ff, mic, ptt*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice session by text executed successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to execute voice session by text. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.voiceSessionByText",
  "params": {
    "transcription": "...",
    "type": "ff"
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

<a id="method_voiceSessionTypes"></a>
## *voiceSessionTypes [<sup>method</sup>](#head_Methods)*

Retrieves the types of voice sessions which are supported by the platform.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.types | array | mandatory | Array of strings indicating the voice session request types which are valid e.g. "ptt_transcription" |
| result.types[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice session types retrieved successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to retrieve voice session types. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.voiceSessionTypes"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false,
    "types": [
      "..."
    ]
  }
}
```

<a id="method_voiceSessionTerminate"></a>
## *voiceSessionTerminate [<sup>method</sup>](#head_Methods)*

Terminates a voice session using the specified session identifier.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | string | mandatory | The session identifier of the session from the onSessionBegin event e.g. "session-12345" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice session terminated successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to terminate voice session. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.voiceSessionTerminate",
  "params": {
    "sessionId": "..."
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

<a id="method_voiceSessionAudioStreamStart"></a>
## *voiceSessionAudioStreamStart [<sup>method</sup>](#head_Methods)*

Starts a subsequent audio stream for the voice session indicated by the session identifier.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | string | mandatory | The session identifier of the session from the onSessionBegin event e.g. "session-12345" |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Whether the request succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::NONE``` | Voice session audio stream started successfully. |
| ```ErrorCode::RPC_CALL_FAILED``` | IARM bus call failed. |
| ```ErrorCode::GENERAL``` | Failed to start voice session audio stream. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.voiceSessionAudioStreamStart",
  "params": {
    "sessionId": "..."
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the VoiceControl interface:

VoiceControl interface events:

| Notification | Description |
| :-------- | :-------- |
| [onSessionBegin](#notification_onSessionBegin) | Triggered when a voice session begins |
| [onStreamBegin](#notification_onStreamBegin) | Triggered when a device starts streaming voice data to the RDK |
| [onKeywordVerification](#notification_onKeywordVerification) | Triggered when a keyword verification result is received |
| [onServerMessage](#notification_onServerMessage) | Triggered when a message is received from the Voice Server |
| [onStreamEnd](#notification_onStreamEnd) | Triggered when the device has stopped streaming audio |
| [onSessionEnd](#notification_onSessionEnd) | Triggered when the interaction with the server has concluded |

<a id="notification_onSessionBegin"></a>
## *onSessionBegin [<sup>notification</sup>](#head_Notifications)*

Triggered when a voice session begins.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The voice device identifier ex: 1 |
| params.sessionId | string | mandatory | The unique identifier for the voice session e.g. "session-12345" |
| params.deviceType | string | mandatory | The type of voice device starting the session. Possible values: ptt, ff, mic (must be one of the following: *ff, mic, ptt*) |
| params.keywordVerification | boolean | mandatory | True if the session uses keyword verification, otherwise false |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onSessionBegin",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSessionBegin",
  "params": {
    "remoteId": 0,
    "sessionId": "...",
    "deviceType": "ff",
    "keywordVerification": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSessionBegin``.

<a id="notification_onStreamBegin"></a>
## *onStreamBegin [<sup>notification</sup>](#head_Notifications)*

Triggered when a device starts streaming voice data to the RDK.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The voice device identifier ex: 1 |
| params.sessionId | string | mandatory | The unique identifier for the voice session e.g. "session-12345" |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onStreamBegin",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onStreamBegin",
  "params": {
    "remoteId": 0,
    "sessionId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onStreamBegin``.

<a id="notification_onKeywordVerification"></a>
## *onKeywordVerification [<sup>notification</sup>](#head_Notifications)*

Triggered when a keyword verification result is received.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The voice device identifier ex: 1 |
| params.sessionId | string | mandatory | The unique identifier for the voice session e.g. "session-12345" |
| params.verified | boolean | mandatory | True if the keyword was verified, otherwise false |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onKeywordVerification",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onKeywordVerification",
  "params": {
    "remoteId": 0,
    "sessionId": "...",
    "verified": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onKeywordVerification``.

<a id="notification_onServerMessage"></a>
## *onServerMessage [<sup>notification</sup>](#head_Notifications)*

Triggered when a message is received from the Voice Server.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.msgType | string | mandatory | Message type from the server e.g. "asr" |
| params.trx | string | mandatory | The unique id of the voice session e.g. "12345-abc" |
| params.created | integer | mandatory | The timestamp for server information in milliseconds since epoch |
| params.msgPayload | opaque object | mandatory | Vrex server information<br>*String length must be at most 262144 chars.* |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onServerMessage",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onServerMessage",
  "params": {
    "msgType": "...",
    "trx": "...",
    "created": 0,
    "msgPayload": {}
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onServerMessage``.

<a id="notification_onStreamEnd"></a>
## *onStreamEnd [<sup>notification</sup>](#head_Notifications)*

Triggered when the device has stopped streaming audio.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The voice device identifier ex: 1 |
| params.sessionId | string | mandatory | The unique identifier for the voice session e.g. "session-12345" |
| params.reason | integer | mandatory | The reason code for why the device stopped streaming audio. 0: End of Stream (Mic Key Released / EOS detected), 1: First Packet Timeout, 2: Inter-packet Timeout, 3: Max Utterance Length, 4: Adjacent Key Press, 5: Other Key Press, 6: Other / Unknown ex: 0 |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onStreamEnd",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onStreamEnd",
  "params": {
    "remoteId": 0,
    "sessionId": "...",
    "reason": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onStreamEnd``.

<a id="notification_onSessionEnd"></a>
## *onSessionEnd [<sup>notification</sup>](#head_Notifications)*

Triggered when the interaction with the server has concluded.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.remoteId | integer | mandatory | The voice device identifier ex: 1 |
| params.sessionId | string | mandatory | The unique identifier for the voice session e.g. "session-12345" |
| params.result | string | mandatory | The result of the voice session. Possible values: success, error, abort, shortUtterance (must be one of the following: *abort, error, shortUtterance, success*) |
| params.serverStats | object | mandatory | The voice server stats |
| params.serverStats.dnsTime | number | mandatory | The DNS time of the voice server in milliseconds ex: 0.5 |
| params.serverStats.serverIp | string | mandatory | The IP of the voice server e.g. "192.168.1.100" |
| params.serverStats.connectTime | number | mandatory | The connection time of the voice server in milliseconds ex: 10.2 |
| params?.success | opaque object | optional | Result data for a successful voice session containing transcription |
| params?.error | opaque object | optional | Result data for a failed voice session containing error codes |
| params?.abort | opaque object | optional | Result data for an aborted voice session containing reason |
| params?.shortUtterance | opaque object | optional | Result data for a short utterance voice session containing reason |
| params?.stbStats | opaque object | optional | STB statistics including device type, firmware, and controller info |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onSessionEnd",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSessionEnd",
  "params": {
    "remoteId": 0,
    "sessionId": "...",
    "result": "error",
    "serverStats": {
      "dnsTime": 0.0,
      "serverIp": "...",
      "connectTime": 0.0
    },
    "success": {},
    "error": {},
    "abort": {},
    "shortUtterance": {},
    "stbStats": {}
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSessionEnd``.

