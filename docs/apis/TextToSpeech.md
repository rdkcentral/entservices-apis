<!-- Generated automatically, DO NOT EDIT! -->
<a id="TextToSpeech_Plugin"></a>
# TextToSpeech Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/TextToSpeech/ITextToSpeech.h)**

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
| [resume](#resume) | Resume the speech |
| [setACL](#setACL) | Set the access control list for TTS |
| [setAPIKey](#setAPIKey) | Set the api key for TTS endpoint |
| [setConfiguration](#setConfiguration) | Set the tts configuration attributes |
| [setFallbackText](#setFallbackText) | Set the tts fallback text |
| [setPrimaryVolDuck](#setPrimaryVolDuck) | Set the primary volume ducking level |
| [speak](#speak) | Speaks text provided |

<a id="cancel"></a>
## *cancel*

Cancel the speech

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | returns id for the text |
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
Event details will be updated soon.
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
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | returns id for the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | speech state @retval Core::NONE: Indicates successful retrieval of speech state @retval Core::ERROR_GENERAL: Indicates retrieval of speech state got failed |

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
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | input |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.voices | IStringIterator | list of voices @retval Core::NONE: Indicates successful retrieval of voices list @retval Core::ERROR_GENERAL: Indicates retrieval of voices list got failed |

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
    "result": {
        "voices": ""
    }
}
```

<a id="pause"></a>
## *pause*

Pause the speech

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | returns id for the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | string | return status @retval Core::NONE: Indicates successful configuration set @retval Core::ERROR_GENERAL: Indicates configuration set got failed |

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

<a id="resume"></a>
## *resume*

Resume the speech

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | integer | returns id for the text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | string | return status @retval Core::NONE: Indicates successful configuration set @retval Core::ERROR_GENERAL: Indicates configuration set got failed |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.TextToSpeech.resume",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.TextToSpeech.resume", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="setACL"></a>
## *setACL*

Set the access control list for TTS

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.method | string | method name |
| params.apps | string | applications allowed @retval Core::NONE: Indicates successful update of access control list @retval Core::ERROR_GENERAL: Indicates update of access control list got failed |
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
    "method": "org.rdk.TextToSpeech.setACL",
    "params": {
        "method": "",
        "apps": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.TextToSpeech.setACL", "params": {"method": "", "apps": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="setAPIKey"></a>
## *setAPIKey*

Set the api key for TTS endpoint

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.apikey | string | api key for TTS @retval Core::NONE: Indicates successful set of api key |
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
    "method": "org.rdk.TextToSpeech.setAPIKey",
    "params": {
        "apikey": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.TextToSpeech.setAPIKey", "params": {"apikey": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="setConfiguration"></a>
## *setConfiguration*

Set the tts configuration attributes

### Events
Event details will be updated soon.
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
| result.status | string | return status @retval Core::NONE: Indicates successful configuration set @retval Core::ERROR_GENERAL: Indicates configuration set got failed |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.TextToSpeech.setConfiguration", "params": {"ttsEndPoint": "", "ttsEndPointSecured": "", "language": "", "voice": "", "speechRate": "", "volume": 0, "rate": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="setFallbackText"></a>
## *setFallbackText*

Set the tts fallback text

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.scenario | string | scenario for fallback text |
| params.value | string | fallback text @retval Core::NONE: Indicates successful set of fallback text |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.TextToSpeech.setFallbackText",
    "params": {
        "scenario": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.TextToSpeech.setFallbackText", "params": {"scenario": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="setPrimaryVolDuck"></a>
## *setPrimaryVolDuck*

Set the primary volume ducking level

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.prim | integer | primary volume ducking level @retval Core::NONE: Indicates successful configuration set of primary vol duck @retval Core::ERROR_GENERAL: Indicates configuration set of primary vol duck got failed |
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
    "method": "org.rdk.TextToSpeech.setPrimaryVolDuck",
    "params": {
        "prim": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.TextToSpeech.setPrimaryVolDuck", "params": {"prim": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="speak"></a>
## *speak*

Speaks text provided

### Events
Event details will be updated soon.
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
| result.speechid | integer | returns id for the text |
| result.status | string | return status @retval Core::NONE: Indicates successful configuration set @retval Core::ERROR_GENERAL: Indicates configuration set got failed |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.TextToSpeech.speak",
    "params": {
        "callsign": "",
        "text": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.TextToSpeech.speak", "params": {"callsign": "", "text": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
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

| Property | Description |
| :-------- | :-------- |
| [enable](#enable) | enable/disable tts |

<a id="Enable"></a>
## *Enable*

enable/disable tts

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).enable | bool | flag to enable/disable tts @retval Core::NONE: Indicates successful state change @retval Core::ERROR_GENERAL: Indicates state change got failed |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.TextToSpeech.enable"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.TextToSpeech.enable"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "enable": true
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.TextToSpeech.enable",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.TextToSpeech.enable", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
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
| [onnetworkerror](#onnetworkerror) | Notify that network connection is lost |
| [onspeechcomplete](#onspeechcomplete) | Notify that speech is completed |
| [onspeechinterrupted](#onspeechinterrupted) | Notify that speech is interrupted |
| [onspeechpause](#onspeechpause) | Notify that speech is paused |
| [onWillSpeak](#onWillSpeak) | Notify that speech is possible |
| [onspeechresume](#onspeechresume) | Notify that speech is continued |
| [onspeechstart](#onspeechstart) | Notify that speech is started |
| [onttsstatechanged](#onttsstatechanged) | Notify TTS enabled/disabled |
| [onvoicechanged](#onvoicechanged) | Notify change in voice used for speaking |
| [onplaybackerror](#onplaybackerror) | Notify that there is a playback failure |

<a id="networkError"></a>
## *networkError*

Notify that network connection is lost

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.TextToSpeech.networkError"
}
```

<a id="onSpeechComplete"></a>
## *onSpeechComplete*

Notify that speech is completed

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.TextToSpeech.onSpeechComplete"
}
```

<a id="onSpeechInterrupted"></a>
## *onSpeechInterrupted*

Notify that speech is interrupted

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.TextToSpeech.onSpeechInterrupted"
}
```

<a id="onSpeechPaused"></a>
## *onSpeechPaused*

Notify that speech is paused

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.TextToSpeech.onSpeechPaused"
}
```

<a id="onSpeechReady"></a>
## *onSpeechReady*

Notify that speech is possible

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.TextToSpeech.onSpeechReady"
}
```

<a id="onSpeechResumed"></a>
## *onSpeechResumed*

Notify that speech is continued

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.TextToSpeech.onSpeechResumed"
}
```

<a id="onSpeechStarted"></a>
## *onSpeechStarted*

Notify that speech is started

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.TextToSpeech.onSpeechStarted"
}
```

<a id="onTTSStateChanged"></a>
## *onTTSStateChanged*

Notify TTS enabled/disabled

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.TextToSpeech.onTTSStateChanged"
}
```

<a id="onVoiceChanged"></a>
## *onVoiceChanged*

Notify change in voice used for speaking

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.TextToSpeech.onVoiceChanged"
}
```

<a id="playbackError"></a>
## *playbackError*

Notify that there is a playback failure

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.TextToSpeech.playbackError"
}
```
