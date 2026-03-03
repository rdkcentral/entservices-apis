<!-- Generated automatically, DO NOT EDIT! -->
<a id="VoiceControl_Plugin"></a>
# VoiceControl Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/VoiceControl/IVoiceControl.h)**

A VoiceControl plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `VoiceControl` plugin provides an interface for VoiceControl.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.VoiceControl) |
| classname | string | Class name: *VoiceControl* |
| locator | string | Library name: *libWPEFrameworkVoiceControl.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the VoiceControl plugin:

VoiceControl interface methods:

| Method | Description |
| :-------- | :-------- |
| [configureVoice](#configureVoice) | Configures the RDK's voice stack |
| [getApiVersionNumber](#getApiVersionNumber) | Get the API version number |
| [sendNotify_](#sendNotify_) | Send a notification event |
| [sendVoiceMessage](#sendVoiceMessage) | Sends a message to the Voice Server |
| [setVoiceInit](#setVoiceInit) | Sets the application metadata in the INIT message that gets sent to the Voice Server |
| [voiceSessionAudioStreamStart](#voiceSessionAudioStreamStart) | Starts a subsequent audio stream for the voice session indicated by the session identifier |
| [voiceSessionByText](#voiceSessionByText) | Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED) |
| [voiceSessionRequest](#voiceSessionRequest) | Requests a voice session using the specified request type and optional parameters |
| [voiceSessionTerminate](#voiceSessionTerminate) | Terminates a voice session using the specified session identifier |
| [voiceSessionTypes](#voiceSessionTypes) | Retrieves the types of voice sessions which are supported by the platform |
| [voiceStatus](#voiceStatus) | Returns the current status of the RDK voice stack |

<a id="configureVoice"></a>
## *configureVoice*

Configures the RDK's voice stack

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | ConfigureVoiceRequest | The configure voice request parameters @retval ErrorCode::NONE: Voice settings configured successfully. @retval ErrorCode::GENERAL: Failed to configure voice settings. |
| params.request.urlAll | string | Specifies the URL for all devices instead of individually specifying the URL for each device e.g. "ws: |
| params.request.urlPtt | string | The PTT URL e.g. "ws: |
| params.request.urlHf | string | The HF (ff and mic) URL e.g. "ws: |
| params.request.urlMicTap | string | The microphone tap URL e.g. "ws: |
| params.request.enable | bool | Enables or disables all of the voice devices instead of individually enabling or disabling each device |
| params.request.prv | bool | The Press & Release Voice feature (true for enable, false for disable) |
| params.request.wwFeedback | bool | The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable) |
| params.request.ptt | DeviceSettings | The settings for PTT devices |
| params.request.ptt.enable | bool | Enable (true) or disable (false) the device |
| params.request.ff | DeviceSettings | The settings for FF devices |
| params.request.ff.enable | bool | Enable (true) or disable (false) the device |
| params.request.mic | DeviceSettings | The settings for MIC devices |
| params.request.mic.enable | bool | Enable (true) or disable (false) the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.VoiceControl.configureVoice",
    "params": {
        "urlAll": "ws:",
        "urlPtt": "ws:",
        "urlHf": "ws:",
        "urlMicTap": "ws:",
        "enable": true,
        "prv": true,
        "wwFeedback": true,
        "ptt": {
            "enable": true
        },
        "ff": {
            "enable": true
        },
        "mic": {
            "enable": true
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.VoiceControl.configureVoice", "params": {"urlAll": "ws:", "urlPtt": "ws:", "urlHf": "ws:", "urlMicTap": "ws:", "enable": true, "prv": true, "wwFeedback": true, "ptt": {"enable": true}, "ff": {"enable": true}, "mic": {"enable": true}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="getApiVersionNumber"></a>
## *getApiVersionNumber*

Get the API version number

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | integer | The API version number e.g. 1 |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.VoiceControl.getApiVersionNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.VoiceControl.getApiVersionNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "version": 0
    }
}
```

<a id="sendNotify_"></a>
## *sendNotify_*

Send a notification event

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | Name of the event |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.parameters | string | JSON parameters for the event @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.VoiceControl.sendNotify_",
    "params": {
        "eventName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.VoiceControl.sendNotify_", "params": {"eventName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "parameters": ""
    }
}
```

<a id="sendVoiceMessage"></a>
## *sendVoiceMessage*

Sends a message to the Voice Server

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | SendVoiceMessageRequest | The voice message request parameters @retval ErrorCode::NONE: Voice message sent successfully. @retval ErrorCode::GENERAL: Failed to send voice message. |
| params.request.msgType | string | Message type expected from server  |
| params.request.trx | string | The unique id of the voice session  |
| params.request.created | integer | The timestamp for server information in milliseconds since epoch |
| params.request.msgPayload | string | Message payload (opaque object) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.VoiceControl.sendVoiceMessage",
    "params": {
        "msgType": "query",
        "trx": "12345-abc",
        "created": 0,
        "msgPayload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.VoiceControl.sendVoiceMessage", "params": {"msgType": "query", "trx": "12345-abc", "created": 0, "msgPayload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="setVoiceInit"></a>
## *setVoiceInit*

Sets the application metadata in the INIT message that gets sent to the Voice Server

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | Preferred user interface language  |
| params.capabilities | IStringIterator | A list of capabilities |
| params.capabilities[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.VoiceControl.setVoiceInit",
    "params": {
        "language": "en-US",
        "capabilities": [
            ""
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.VoiceControl.setVoiceInit", "params": {"language": "en-US", "capabilities": [""]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="voiceSessionAudioStreamStart"></a>
## *voiceSessionAudioStreamStart*

Starts a subsequent audio stream for the voice session indicated by the session identifier

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier of the session from the onSessionBegin event  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="voiceSessionByText"></a>
## *voiceSessionByText*

Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | VoiceSessionByTextRequest | The voice session by text request parameters @retval ErrorCode::NONE: Voice session by text executed successfully. @retval ErrorCode::GENERAL: Failed to execute voice session by text. |
| params.request.transcription | string | The transcription text to be sent to the voice server  |
| params.request.type | string | The device type to simulate the voice session from , "FF", "MIC" |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.VoiceControl.voiceSessionByText",
    "params": {
        "transcription": "turn on the lights",
        "type": "PTT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.VoiceControl.voiceSessionByText", "params": {"transcription": "turn on the lights", "type": "PTT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="voiceSessionRequest"></a>
## *voiceSessionRequest*

Requests a voice session using the specified request type and optional parameters

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.request | VoiceSessionRequestParams | The voice session request parameters @retval ErrorCode::NONE: Voice session requested successfully. @retval ErrorCode::GENERAL: Failed to request voice session. |
| params.request.transcription | string | The transcription text to be sent to the voice server (for ptt_transcription and mic_transcription types)  |
| params.request.audioFile | string | The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file types) e.g. " |
| params.request.type | string | The request type to initiate the voice session  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.VoiceControl.voiceSessionRequest",
    "params": {
        "transcription": "what's the weather",
        "audioFile": "",
        "type": "ptt_transcription"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.VoiceControl.voiceSessionRequest", "params": {"transcription": "what's the weather", "audioFile": "", "type": "ptt_transcription"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="voiceSessionTerminate"></a>
## *voiceSessionTerminate*

Terminates a voice session using the specified session identifier

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | string | The session identifier of the session from the onSessionBegin event  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.VoiceControl.voiceSessionTerminate",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.VoiceControl.voiceSessionTerminate", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="voiceSessionTypes"></a>
## *voiceSessionTypes*

Retrieves the types of voice sessions which are supported by the platform

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.types | IStringIterator | Array of strings indicating the voice session request types which are valid @retval ErrorCode::NONE: Voice session types retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve voice session types. |
| result.types[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.VoiceControl.voiceSessionTypes"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.VoiceControl.voiceSessionTypes"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": [
        ""
    ]
}
```

<a id="voiceStatus"></a>
## *voiceStatus*

Returns the current status of the RDK voice stack

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.maskPii | bool | Indicates if PII should be masked (1 - mask PII, 0 - display PII) |
| result.capabilities | IStringIterator | A list of capabilities |
| result.capabilities[#] | string |  |
| result.urlPtt | string | The PTT URL e.g. "ws: |
| result.urlHf | string | The HF (ff and mic) URL e.g. "ws: |
| result.prv | bool | The Press & Release Voice feature (true for enable, false for disable) |
| result.wwFeedback | bool | The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable) |
| result.status | string | The status of the device  |
| result.status | string | The status of the device  |
| result.status | string | The status of the device  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.VoiceControl.voiceStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.VoiceControl.voiceStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "maskPii": true,
        "capabilities": [
            ""
        ],
        "urlPtt": "ws:",
        "urlHf": "ws:",
        "prv": true,
        "wwFeedback": true,
        "pttStatus": {
            "status": "ready"
        },
        "ffStatus": {
            "status": "ready"
        },
        "micStatus": {
            "status": "ready"
        }
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the VoiceControl plugin:

VoiceControl interface events:

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
| params.params | KeywordVerificationEvent | Event data containing keyword verification information. |
| params.params.remoteId | integer | The voice device identifier e.g. 1 |
| params.params.sessionId | string | The unique identifier for the voice session  |
| params.params.verified | bool | True if the keyword was verified, otherwise false |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.VoiceControl.onKeywordVerification",
    "params": {
        "remoteId": 0,
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
| params.params | ServerMessageEvent | Event data containing server message information. |
| params.params.msgType | string | Message type from the server  |
| params.params.trx | string | The unique id of the voice session  |
| params.params.created | integer | The timestamp for server information in milliseconds since epoch |
| params.params.msgPayload | string | Vrex server information |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
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
| params.params | SessionBeginEvent | Event data containing session begin information. |
| params.params.remoteId | integer | The voice device identifier e.g. 1 |
| params.params.sessionId | string | The unique identifier for the voice session  |
| params.params.deviceType | string | The type of voice device starting the session , "ff", "mic" |
| params.params.keywordVerification | bool | True if the session uses keyword verification, otherwise false |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.VoiceControl.onSessionBegin",
    "params": {
        "remoteId": 0,
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
| params.params | SessionEndEvent | Event data containing session end information. |
| params.params.serverStats | ServerStats | Returns the voice server stats |
| params.params.serverStats.dnsTime | double | The DNS time of the voice server in milliseconds e.g. 0.5 |
| params.params.serverStats.serverIp | string | The IP of the voice server  |
| params.params.serverStats.connectTime | double | The connection time of the voice server in milliseconds e.g. 10.2 |
| params.params.remoteId | integer | The voice device identifier e.g. 1 |
| params.params.sessionId | string | The unique identifier for the voice session  |
| params.params.result | string | The result of the voice session , "error", "abort", "shortUtterance" |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.VoiceControl.onSessionEnd",
    "params": {
        "serverStats": {
            "dnsTime": 0.0,
            "serverIp": "192.168.1.100",
            "connectTime": 0.0
        },
        "remoteId": 0,
        "sessionId": "session-12345",
        "result": "success"
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
| params.params | StreamBeginEvent | Event data containing stream begin information. |
| params.params.remoteId | integer | The voice device identifier e.g. 1 |
| params.params.sessionId | string | The unique identifier for the voice session  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.VoiceControl.onStreamBegin",
    "params": {
        "remoteId": 0,
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
| params.params | StreamEndEvent | Event data containing stream end information. |
| params.params.remoteId | integer | The voice device identifier e.g. 1 |
| params.params.sessionId | string | The unique identifier for the voice session  |
| params.params.reason | integer | The reason code for why the device stopped streaming audio (0-6) e.g. 0 |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.VoiceControl.onStreamEnd",
    "params": {
        "remoteId": 0,
        "sessionId": "session-12345",
        "reason": 0
    }
}
```
