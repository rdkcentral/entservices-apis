<!-- Generated automatically, DO NOT EDIT! -->
<a id="TextToSpeech_Plugin"></a>
# TextToSpeech Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/TextToSpeech)**

A TextToSpeech plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `TextToSpeech` plugin provides an interface for TextToSpeech.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TextToSpeech) |
| classname | string | Class name: *TextToSpeech* |
| locator | string | Library name: *libWPEFrameworkTextToSpeech.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the TextToSpeech plugin:

TextToSpeech interface methods:

| Method | Description |
| :-------- | :-------- |
| [cancel](#cancel) | Cancel the speech |
| [getConfiguration](#getConfiguration) | Retrieve tts configuration attributes |
| [getSpeechState](#getSpeechState) | Get speech status |
| [listVoices](#listVoices) | List voices available |
| [pause](#pause) | Pause the speech |
| [registerWithCallsign](#registerWithCallsign) |  |
| [resume](#resume) | Resume the speech |
| [setACL](#setACL) |  |
| [setAPIKey](#setAPIKey) |  |
| [setConfiguration](#setConfiguration) | Set the tts configuration attributes |
| [setFallbackText](#setFallbackText) |  |
| [setPrimaryVolDuck](#setPrimaryVolDuck) |  |
| [speak](#speak) | Speaks text provided |

<a id="cancel"></a>
## *cancel*

Cancel the speech

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |
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
    "method": "org.rdk.TextToSpeech.cancel",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.TextToSpeech.cancel", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="getConfiguration"></a>
## *getConfiguration*

Retrieve tts configuration attributes

### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.config | Configuration | tts configuration |
| result.config.ttsEndPoint | std::string |  |
| result.config.ttsEndPointSecured | std::string |  |
| result.config.language | std::string |  |
| result.config.voice | std::string |  |
| result.config.speechRate | std::string |  |
| result.config.volume | integer |  |
| result.config.rate | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.TextToSpeech.getConfiguration"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.TextToSpeech.getConfiguration"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "ttsEndPoint": "",
        "ttsEndPointSecured": "",
        "language": "",
        "voice": "",
        "speechRate": "",
        "volume": 0,
        "rate": 0
    }
}
```

<a id="getSpeechState"></a>
## *getSpeechState*

Get speech status

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | speech state |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.TextToSpeech.getSpeechState",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.TextToSpeech.getSpeechState", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "state": "SPEECH_PENDING"
    }
}
```

<a id="listVoices"></a>
## *listVoices*

List voices available

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | input |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.voices | RPC::IStringIterator | list of voices |
| result.voices[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.TextToSpeech.listVoices",
    "params": {
        "language": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.TextToSpeech.listVoices", "params": {"language": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": [
        ""
    ]
}
```

<a id="pause"></a>
## *pause*

Pause the speech

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | string | return status |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.TextToSpeech.pause",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.TextToSpeech.pause", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="registerWithCallsign"></a>
## *registerWithCallsign*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string |  |
| params.sink | ITextToSpeech::INotification |  |
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
    "method": "org.rdk.TextToSpeech.registerWithCallsign",
    "params": {
        "callsign": "",
        "sink": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.TextToSpeech.registerWithCallsign", "params": {"callsign": "", "sink": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="resume"></a>
## *resume*

Resume the speech

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | string | return status |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.TextToSpeech.resume",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.TextToSpeech.resume", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="setACL"></a>
## *setACL*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.method | string |  |
| params.apps | string |  |
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
    "method": "org.rdk.TextToSpeech.setACL",
    "params": {
        "method": "",
        "apps": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.TextToSpeech.setACL", "params": {"method": "", "apps": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="setAPIKey"></a>
## *setAPIKey*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.apikey | string |  |
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
    "method": "org.rdk.TextToSpeech.setAPIKey",
    "params": {
        "apikey": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.TextToSpeech.setAPIKey", "params": {"apikey": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="setConfiguration"></a>
## *setConfiguration*

Set the tts configuration attributes

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.config | Configuration | tts configuration |
| params.config.ttsEndPoint | std::string |  |
| params.config.ttsEndPointSecured | std::string |  |
| params.config.language | std::string |  |
| params.config.voice | std::string |  |
| params.config.speechRate | std::string |  |
| params.config.volume | integer |  |
| params.config.rate | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | string | return status |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.TextToSpeech.setConfiguration",
    "params": {
        "ttsEndPoint": "",
        "ttsEndPointSecured": "",
        "language": "",
        "voice": "",
        "speechRate": "",
        "volume": 0,
        "rate": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.TextToSpeech.setConfiguration", "params": {"ttsEndPoint": "", "ttsEndPointSecured": "", "language": "", "voice": "", "speechRate": "", "volume": 0, "rate": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="setFallbackText"></a>
## *setFallbackText*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string |  |
| params.value | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.TextToSpeech.setFallbackText",
    "params": {
        "scenario": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.TextToSpeech.setFallbackText", "params": {"scenario": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="setPrimaryVolDuck"></a>
## *setPrimaryVolDuck*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.prim | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.TextToSpeech.setPrimaryVolDuck",
    "params": {
        "prim": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.TextToSpeech.setPrimaryVolDuck", "params": {"prim": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="speak"></a>
## *speak*

Speaks text provided

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string |  |
| params.text | string | for conversion |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speechid | integer | id of the text |
| result.status | string | return status |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.TextToSpeech.speak",
    "params": {
        "callsign": "",
        "text": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.TextToSpeech.speak", "params": {"callsign": "", "text": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "speechid": 0,
        "status": "TTS_OK"
    }
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the TextToSpeech plugin:

TextToSpeech interface properties:

| Method | Description |
| :-------- | :-------- |
| [enable](#enable) | Query the status/enable tts |

<a id="Enable"></a>
## *Enable*

Query the status/enable tts

### Events
Event details are missing in the header file documentation.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enable | bool | status/enable |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.TextToSpeech.enable"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.TextToSpeech.enable"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "enable": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.TextToSpeech.enable",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.TextToSpeech.enable", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```


<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the TextToSpeech plugin:

TextToSpeech interface events:

| Event | Description |
| :-------- | :-------- |
| [enabled](#enabled) | Notify TTS enabled/disabled |
| [networkError](#networkError) |  |
| [playbackError](#playbackError) |  |
| [speechComplete](#speechComplete) |  |
| [speechInterrupted](#speechInterrupted) |  |
| [speechPause](#speechPause) |  |
| [speechResume](#speechResume) |  |
| [speechStart](#speechStart) |  |
| [voiceChanged](#voiceChanged) | Notify change in voice used for speaking |
| [willSpeak](#willSpeak) | Notify speechid based on the speech state(eg: start,pause,..etc) |

<a id="enabled"></a>
## *enabled*

Notify TTS enabled/disabled

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | bool | enabled/disabled |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.TextToSpeech.enabled",
    "params": {
        "state": true
    }
}
```

<a id="networkError"></a>
## *networkError*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.TextToSpeech.networkError",
    "params": {
        "speechid": 0
    }
}
```

<a id="playbackError"></a>
## *playbackError*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.TextToSpeech.playbackError",
    "params": {
        "speechid": 0
    }
}
```

<a id="speechComplete"></a>
## *speechComplete*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.TextToSpeech.speechComplete",
    "params": {
        "speechid": 0
    }
}
```

<a id="speechInterrupted"></a>
## *speechInterrupted*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.TextToSpeech.speechInterrupted",
    "params": {
        "speechid": 0
    }
}
```

<a id="speechPause"></a>
## *speechPause*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.TextToSpeech.speechPause",
    "params": {
        "speechid": 0
    }
}
```

<a id="speechResume"></a>
## *speechResume*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.TextToSpeech.speechResume",
    "params": {
        "speechid": 0
    }
}
```

<a id="speechStart"></a>
## *speechStart*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.TextToSpeech.speechStart",
    "params": {
        "speechid": 0
    }
}
```

<a id="voiceChanged"></a>
## *voiceChanged*

Notify change in voice used for speaking

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.voice | string | voice changed |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.TextToSpeech.voiceChanged",
    "params": {
        "voice": ""
    }
}
```

<a id="willSpeak"></a>
## *willSpeak*

Notify speechid based on the speech state(eg: start,pause,..etc)

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | id of the text |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.TextToSpeech.willSpeak",
    "params": {
        "speechid": 0
    }
}
```
