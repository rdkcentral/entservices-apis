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
| [voiceSessionTypes](#voiceSessionTypes) | Retrieves the types of voice sessions which are supported by the platform |
| [voiceStatus](#voiceStatus) | Returns the current status of the RDK voice stack |
| [sendVoiceMessage](#sendVoiceMessage) | Sends a message to the Voice Server |
| [setVoiceInit](#setVoiceInit) | Sets the application metadata in the INIT message that gets sent to the Voice Server |
| [voiceSessionAudioStreamStart](#voiceSessionAudioStreamStart) | Starts a subsequent audio stream for the voice session indicated by the session identifier |
| [voiceSessionByText](#voiceSessionByText) | Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED) |
| [voiceSessionRequest](#voiceSessionRequest) | Requests a voice session using the specified request type and optional parameters |
| [voiceSessionTerminate](#voiceSessionTerminate) | Terminates a voice session using the specified session identifier |

<a id="configureVoice"></a>
## *configureVoice*

Configures the RDK's voice stack

### Events
No Events
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.urlAll | string | Specifies the URL for all devices instead of individually specifying the URL for each device. URL Scheme determines which API protocol is used (http/https: VREX Legacy HTTP API, ws/wss: VREX XR18  WS API, vrng/vrngs: VREX NextGen WS API, aows/aowss: Audio only over websockets, sdt: Simple data transfer)  |
| params.urlPtt | string | The PTT URL  |
| params.urlHf | string | The HF (ff and mic) URL  |
| params.urlMicTap | string | The microphone tap URL  |
| params.enable | bool | Enable (true) or disable (false) the device |
| params.prv | bool | The Press & Release Voice feature (true for enable, false for disable) |
| params.wwFeedback | bool | The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable) |
| params.enable | bool | Enable (true) or disable (false) the device |
| params.enable | bool | Enable (true) or disable (false) the device |
| params.enable | bool | Enable (true) or disable (false) the device |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.VoiceControl.configureVoice",
    "params": {
        "urlAll": "ws://voice.example.com",
        "urlPtt": "ws://voice.example.com/ptt",
        "urlHf": "ws://voice.example.com/hf",
        "urlMicTap": "ws://voice.example.com/mictap",
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.VoiceControl.configureVoice", "params": {"urlAll": "ws://voice.example.com", "urlPtt": "ws://voice.example.com/ptt", "urlHf": "ws://voice.example.com/hf", "urlMicTap": "ws://voice.example.com/mictap", "enable": true, "prv": true, "wwFeedback": true, "ptt": {"enable": true}, "ff": {"enable": true}, "mic": {"enable": true}}}' http://127.0.0.1:9998/jsonrpc
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

<a id="getApiVersionNumber"></a>
## *getApiVersionNumber*

Get the API version number

### Events
No Events
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | integer | The API version number  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.VoiceControl.getApiVersionNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.VoiceControl.getApiVersionNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": {
        "version": 1,
        "success": true
    }
}
```

<a id="voiceSessionTypes"></a>
## *voiceSessionTypes*

Retrieves the types of voice sessions which are supported by the platform

### Events
No Events
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |
| result.types | IStringIterator | Array of strings indicating the voice session request types which are valid  |
| result.types[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.VoiceControl.voiceSessionTypes"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.VoiceControl.voiceSessionTypes"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
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

### Events
No Events
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | VoiceStatusResponse | The voice status response |
| result.response.maskPii | bool | Indicates if PII should be masked (1 - mask PII, 0 - display PII) |
| result.response.urlPtt | string | The PTT URL  |
| result.response.urlHf | string | The HF (ff and mic) URL  |
| result.response.prv | bool | The Press & Release Voice feature (true for enable, false for disable) |
| result.response.wwFeedback | bool | The Wake Word Feedback feature (true for enable, false for disable) |
| result.response.ptt | DeviceStatus | The status information for the PTT device type |
| result.response.ptt.status | string | The status of the device  |
| result.response.ff | DeviceStatus | The status information for the FF device type |
| result.response.ff.status | string | The status of the device  |
| result.response.mic | DeviceStatus | The status information for the MIC device type |
| result.response.mic.status | string | The status of the device  |
| result.response.success | bool | Whether the request succeeded |
| result.capabilities | IStringIterator | A list of capabilities  |
| result.capabilities[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.VoiceControl.voiceStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.VoiceControl.voiceStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": {
        "response": {
            "maskPii": true,
            "urlPtt": "ws://voice.example.com/ptt",
            "urlHf": "ws://voice.example.com/hf",
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
            "success": true
        },
        "capabilities": [
            "PRV"
        ]
    }
}
```

<a id="sendVoiceMessage"></a>
## *sendVoiceMessage*

Sends a message to the Voice Server

### Events
No Events
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.msgType | string | Message type from the server  |
| params.trx | string | The unique id of the voice session  |
| params.created | integer | The timestamp for server information in milliseconds since epoch |
| params.msgPayload | string | Vrex server information |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.VoiceControl.sendVoiceMessage", "params": {"msgType": "asr", "trx": "12345-abc", "created": 0, "msgPayload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="setVoiceInit"></a>
## *setVoiceInit*

Sets the application metadata in the INIT message that gets sent to the Voice Server

### Events
No Events
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | Preferred user interface language |
| params?.capabilities | IStringIterator | <sup>(optional)</sup>A list of capabilities  |
| params?.capabilities[#] | string | <sup>(optional)</sup> |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.VoiceControl.setVoiceInit",
    "params": {
        "language": "",
        "capabilities": [
            "PRV"
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.VoiceControl.setVoiceInit", "params": {"language": "", "capabilities": ["PRV"]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": {
        "success": true
    }
}
```

<a id="voiceSessionAudioStreamStart"></a>
## *voiceSessionAudioStreamStart*

Starts a subsequent audio stream for the voice session indicated by the session identifier

### Events
No Events
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
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": {
        "success": true
    }
}
```

<a id="voiceSessionByText"></a>
## *voiceSessionByText*

Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)

### Events
No Events
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.transcription | string | The transcription text to be sent to the voice server  |
| params.type | string | The device type to simulate the voice session from. Possible values: PTT, FF, MIC |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.VoiceControl.voiceSessionByText",
    "params": {
        "transcription": "turn on the lights",
        "type": "PTT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.VoiceControl.voiceSessionByText", "params": {"transcription": "turn on the lights", "type": "PTT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": {
        "success": true
    }
}
```

<a id="voiceSessionRequest"></a>
## *voiceSessionRequest*

Requests a voice session using the specified request type and optional parameters

### Events
No Events
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.transcription | string | The transcription text to be sent to the voice server  |
| params.audioFile | string | The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file request types)  |
| params.type | string | The request type to initiate the voice session. Possible values: ptt_transcription, ptt_audio_file, ff_transcription, mic_transcription, mic_audio_file, mic_stream_default, mic_stream_single, mic_stream_multi, mic_tap_stream_single, mic_tap_stream_multi, mic_factory_test |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.VoiceControl.voiceSessionRequest",
    "params": {
        "transcription": "what's the weather",
        "audioFile": "/tmp/audio.wav",
        "type": "ptt_transcription"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.VoiceControl.voiceSessionRequest", "params": {"transcription": "what's the weather", "audioFile": "/tmp/audio.wav", "type": "ptt_transcription"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": {
        "success": true
    }
}
```

<a id="voiceSessionTerminate"></a>
## *voiceSessionTerminate*

Terminates a voice session using the specified session identifier

### Events
No Events
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
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.VoiceControl.voiceSessionTerminate",
    "params": {
        "sessionId": "session-12345"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.VoiceControl.voiceSessionTerminate", "params": {"sessionId": "session-12345"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": {
        "success": true
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
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.verified | bool | True if the keyword was verified, otherwise false |

### Examples

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onKeywordVerification",
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
    "jsonrpc": "2.0",
    "method": "client.events.onServerMessage",
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
| params.deviceType | string | The type of voice device starting the session. Possible values: PTT, FF, MIC |
| params.keywordVerification | bool | True if the session uses keyword verification, otherwise false |

### Examples

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSessionBegin",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "deviceType": "PTT",
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
| params.serverStats | ServerStats | Returns the voice server stats |
| params.serverStats.dnsTime | double | The DNS time of the voice server in milliseconds  |
| params.serverStats.serverIp | string | The IP of the voice server  |
| params.serverStats.connectTime | double | The connection time of the voice server in milliseconds  |
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |
| params.result | string | The result of the voice session. Possible values: success, error, abort, shortUtterance |

### Examples

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSessionEnd",
    "params": {
        "serverStats": {
            "dnsTime": 0.5,
            "serverIp": "192.168.1.100",
            "connectTime": 10.2
        },
        "remoteId": 1,
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
| params.remoteId | integer | The voice device identifier  |
| params.sessionId | string | The unique identifier for the voice session  |

### Examples

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onStreamBegin",
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
    "jsonrpc": "2.0",
    "method": "client.events.onStreamEnd",
    "params": {
        "remoteId": 1,
        "sessionId": "session-12345",
        "reason": 0
    }
}
```
