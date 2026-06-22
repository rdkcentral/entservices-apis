<!-- Generated automatically, DO NOT EDIT! -->
<a id="VoiceControl_Module"></a>
# VoiceControl Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/VoiceControl/IVoiceControl.h)**

A VoiceControl module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IVoiceControl](#IVoiceControl)
    - [Methods](#IVoiceControl-Methods)
    - [Notifications](#IVoiceControl-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `VoiceControl` module provides the following interface(s):

- IVoiceControl

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.VoiceControl) |
| classname | string | Class name: *VoiceControl* |
| locator | string | Library name: *libWPEFrameworkVoiceControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IVoiceControl"></a>
## IVoiceControl Interface

### Description

Voice Control JSONRPC interface definition for WPEFramework.  If not stated otherwise in this file or this component's LICENSE file the following copyright and licenses apply:  Copyright 2024 RDK Management  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at  http://www.apache.org/licenses/LICENSE-2.0  Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

<a id="IVoiceControl-Methods"></a>
### Methods

The following methods are provided by the IVoiceControl Interface:

| Method | Description |
| :-------- | :-------- |
| [getApiVersionNumber](#getApiVersionNumber) | Get the API version number |
| [voiceSessionTypes](#voiceSessionTypes) | Retrieves the types of voice sessions which are supported by the platform |
| [voiceStatus](#voiceStatus) | Returns the current status of the RDK voice stack |
| [sendVoiceMessage](#sendVoiceMessage) | Sends a message to the Voice Server |
| [voiceSessionAudioStreamStart](#voiceSessionAudioStreamStart) | Starts a subsequent audio stream for the voice session indicated by the session identifier |
| [voiceSessionByText](#voiceSessionByText) | Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED) |
| [voiceSessionTerminate](#voiceSessionTerminate) | Terminates a voice session using the specified session identifier |

<a id="getApiVersionNumber"></a>
## *getApiVersionNumber*

Get the API version number

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | VoiceControlGetApiVersionNumberResponse | The API version response |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.VoiceControl.getApiVersionNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.VoiceControl.getApiVersionNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "version": 1,
        "success": true
    }
}
```

<a id="voiceSessionTypes"></a>
## *voiceSessionTypes*

Retrieves the types of voice sessions which are supported by the platform

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |
| result.types | array | Array of strings indicating the voice session request types which are valid  |
| result.types[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.VoiceControl.voiceSessionTypes"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.VoiceControl.voiceSessionTypes"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true,
        "types": [
            "ptt_transcription"
        ]
    }
}
```

<a id="voiceStatus"></a>
## *voiceStatus*

Returns the current status of the RDK voice stack

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | object | The typed voice status fields including urlPtt, urlHf, urlMicTap, maskPii, prv, wwFeedback, ptt, ff, mic, optional mic_tap, capabilities, and success |
| result.response.maskPii | bool | Indicates if PII should be masked (1 - mask PII, 0 - display PII) |
| result.response.urlPtt | string | The PTT URL e.g. "ws: |
| result.response.urlHf | string | The HF (ff and mic) URL e.g. "ws: |
| result.response.urlMicTap | string | The microphone tap URL e.g. "ws: |
| result.response.prv | bool | The Press & Release Voice feature (true for enable, false for disable) |
| result.response.wwFeedback | bool | The Wake Word Feedback feature (true for enable, false for disable) |
| result.response.ptt | object | The status information for the PTT device type |
| result.response.ptt.status | string | The status of the device  |
| result.response.ff | object | The status information for the FF device type |
| result.response.ff.status | string | The status of the device  |
| result.response.mic | object | The status information for the MIC device type |
| result.response.mic.status | string | The status of the device  |
| result.response.mic_tap @brief The status information for the MIC TAP device type, present only when MIC TAP capability is available | object | The status information for the MIC TAP device type, present only when MIC TAP capability is available |
| result.response.mic_tap @brief The status information for the MIC TAP device type, present only when MIC TAP capability is available.status | string | The status of the device  |
| result.response.capabilities | string | JSON array of capability strings returned by the voice stack |
| result.response.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.VoiceControl.voiceStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.VoiceControl.voiceStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "maskPii": true,
        "urlPtt": "ws:",
        "urlHf": "ws:",
        "urlMicTap": "ws:",
        "prv": true,
        "wwFeedback": true,
        "ptt": {
            "status": "ready"
        },
        "ff": {
            "status": "ready"
        },
        "mic": {
            "status": "ready"
        },
        "mic_tap @brief The status information for the MIC TAP device type, present only when MIC TAP capability is available": {
            "status": "ready"
        },
        "capabilities": "",
        "success": true
    }
}
```

<a id="sendVoiceMessage"></a>
## *sendVoiceMessage*

Sends a message to the Voice Server

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.msgType | string | Message type from the server  |
| params?.trx | string | <sup>(optional)</sup>The unique id of the voice session  |
| params?.created | integer | <sup>(optional)</sup>The timestamp for server information in milliseconds since epoch |
| params?.msgPayload | string | <sup>(optional)</sup>Vrex server information |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.VoiceControl.sendVoiceMessage",
    "params": {
        "msgType": "asr",
        "trx": "12345-abc",
        "created": 0,
        "msgPayload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.VoiceControl.sendVoiceMessage", "params": {"msgType": "asr", "trx": "12345-abc", "created": 0, "msgPayload": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="voiceSessionAudioStreamStart"></a>
## *voiceSessionAudioStreamStart*

Starts a subsequent audio stream for the voice session indicated by the session identifier

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier of the session from the onSessionBegin event  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
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

<a id="voiceSessionByText"></a>
## *voiceSessionByText*

Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.transcription | string | The transcription text to be sent to the voice server  |
| params?.type | string | <sup>(optional)</sup>The device type to simulate the voice session from. Possible values: PTT, FF, MIC |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.VoiceControl.voiceSessionByText",
    "params": {
        "transcription": "turn on the lights",
        "type": "ptt"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.VoiceControl.voiceSessionByText", "params": {"transcription": "turn on the lights", "type": "ptt"}}' http://127.0.0.1:9998/jsonrpc
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

<a id="voiceSessionTerminate"></a>
## *voiceSessionTerminate*

Terminates a voice session using the specified session identifier

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier of the session from the onSessionBegin event  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.VoiceControl.voiceSessionTerminate",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.VoiceControl.voiceSessionTerminate", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
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

<a id="IVoiceControl-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IVoiceControl Interface:

| Event | Description |
| :-------- | :-------- |
| [onKeywordVerification](#onKeywordVerification) | Triggered when a keyword verification result is received |
| [onServerMessage](#onServerMessage) | Triggered when a message is received from the Voice Server |
| [onSessionBegin](#onSessionBegin) | Triggered when a voice session begins |
| [onSessionEnd](#onSessionEnd) | Triggered when the interaction with the server has concluded |
| [onStreamBegin](#onStreamBegin) | Triggered when a device starts streaming voice data to the RDK |
| [onStreamEnd](#onStreamEnd) | Triggered when the device has stopped streaming audio |

<a id="onKeywordVerification"></a>
## *onKeywordVerification*

Triggered when a keyword verification result is received

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.verified | bool | True if the keyword was verified, otherwise false |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.VoiceControl.onKeywordVerification",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "verified": true
    }
}
```

<a id="onServerMessage"></a>
## *onServerMessage*

Triggered when a message is received from the Voice Server

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.msgType | string | Message type from the server  |
| params.trx | string | The unique id of the voice session  |
| params.created | integer | The timestamp for server information in milliseconds since epoch |
| params.msgPayload | string | Vrex server information |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.VoiceControl.onServerMessage",
    "params": {
        "msgType": "asr",
        "trx": "12345-abc",
        "created": 0,
        "msgPayload": ""
    }
}
```

<a id="onSessionBegin"></a>
## *onSessionBegin*

Triggered when a voice session begins

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.deviceType | string | The type of voice device starting the session. Possible values: ptt, ff, mic |
| params.keywordVerification | bool | True if the session uses keyword verification, otherwise false |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.VoiceControl.onSessionBegin",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "deviceType": "ptt",
        "keywordVerification": true
    }
}
```

<a id="onSessionEnd"></a>
## *onSessionEnd*

Triggered when the interaction with the server has concluded

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.result | string | The result of the voice session. Possible values: success, error, abort, shortUtterance |
| params.serverStats | object | The voice server stats |
| params.serverStats.dnsTime | double | The DNS time of the voice server in milliseconds .5 |
| params.serverStats.serverIp | string | The IP of the voice server  |
| params.serverStats.connectTime | double | The connection time of the voice server in milliseconds .2 |
| params.success | string | Result data for a successful voice session containing transcription |
| params.error | string | Result data for a failed voice session containing error codes |
| params.abort | string | Result data for an aborted voice session containing reason |
| params.shortUtterance | string | Result data for a short utterance voice session containing reason |
| params.stbStats | string | STB statistics including device type, firmware, and controller info |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.VoiceControl.onSessionEnd",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "result": "success",
        "serverStats": {
            "dnsTime": 0.5,
            "serverIp": "192.168.1.100",
            "connectTime": 10.2
        },
        "success": "",
        "error": "",
        "abort": "",
        "shortUtterance": "",
        "stbStats": ""
    }
}
```

<a id="onStreamBegin"></a>
## *onStreamBegin*

Triggered when a device starts streaming voice data to the RDK

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.VoiceControl.onStreamBegin",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345"
    }
}
```

<a id="onStreamEnd"></a>
## *onStreamEnd*

Triggered when the device has stopped streaming audio

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.reason | integer | The reason code for why the device stopped streaming audio. 0: End of Stream (Mic Key Released / EOS detected), 1: First Packet Timeout, 2: Inter-packet Timeout, 3: Max Utterance Length, 4: Adjacent Key Press, 5: Other Key Press, 6: Other / Unknown  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.VoiceControl.onStreamEnd",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "reason": 0
    }
}
```

