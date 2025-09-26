<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.TextToSpeech_Plugin"></a>
# TextToSpeech Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/TextToSpeech/CHANGELOG.md)**

A TextToSpeech plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `TextToSpeech` plugin provides an interface for TextToSpeech.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TextToSpeech) |
| classname | string | Class name: *TextToSpeech* |
| locator | string | Library name: *libWPEFrameworkTextToSpeech.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the TextToSpeech plugin:

TextToSpeech interface methods:

| Method | Description |
| :-------- | :-------- |
| [cancel](#method.cancel) | Cancel the speech |
| [enabled](#method.enabled) | Notify TTS enabled/disabled |
| [getConfiguration](#method.getConfiguration) | Retrieve tts configuration attributes |
| [getSpeechState](#method.getSpeechState) | Get speech status |
| [listVoices](#method.listVoices) | List voices available |
| [networkError](#method.networkError) |  |
| [pause](#method.pause) | Pause the speech |
| [playbackError](#method.playbackError) |  |
| [registerWithCallsign](#method.registerWithCallsign) |  |
| [resume](#method.resume) | Resume the speech |
| [setACL](#method.setACL) |  |
| [setAPIKey](#method.setAPIKey) |  |
| [setConfiguration](#method.setConfiguration) | Set the tts configuration attributes |
| [setFallbackText](#method.setFallbackText) |  |
| [setPrimaryVolDuck](#method.setPrimaryVolDuck) |  |
| [speak](#method.speak) | Speaks text provided |
| [speechComplete](#method.speechComplete) |  |
| [speechInterrupted](#method.speechInterrupted) |  |
| [speechPause](#method.speechPause) |  |
| [speechResume](#method.speechResume) |  |
| [speechStart](#method.speechStart) |  |
| [voiceChanged](#method.voiceChanged) | Notify change in voice used for speaking |
| [willSpeak](#method.willSpeak) | Notify speechid based on the speech state(eg: start,pause,..etc) |

<a id="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

Cancel the speech

### Events
No events are associated with this method.
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

<a id="method.enabled"></a>
## *enabled [<sup>method</sup>](#head.Methods)*

Notify TTS enabled/disabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | bool | enabled/disabled |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.TextToSpeech.enabled",
    "params": {
        "state": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.TextToSpeech.enabled", "params": {"state": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.getConfiguration"></a>
## *getConfiguration [<sup>method</sup>](#head.Methods)*

Retrieve tts configuration attributes

### Events
No events are associated with this method.
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
    "id": 2,
    "method": "org.rdk.TextToSpeech.getConfiguration"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.TextToSpeech.getConfiguration"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
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

<a id="method.getSpeechState"></a>
## *getSpeechState [<sup>method</sup>](#head.Methods)*

Get speech status

### Events
No events are associated with this method.
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
    "id": 3,
    "method": "org.rdk.TextToSpeech.getSpeechState",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.TextToSpeech.getSpeechState", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "state": "SPEECH_PENDING"
    }
}
```

<a id="method.listVoices"></a>
## *listVoices [<sup>method</sup>](#head.Methods)*

List voices available

### Events
No events are associated with this method.
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
    "id": 4,
    "method": "org.rdk.TextToSpeech.listVoices",
    "params": {
        "language": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.TextToSpeech.listVoices", "params": {"language": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": [
        ""
    ]
}
```

<a id="method.networkError"></a>
## *networkError [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 5,
    "method": "org.rdk.TextToSpeech.networkError",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.TextToSpeech.networkError", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.pause"></a>
## *pause [<sup>method</sup>](#head.Methods)*

Pause the speech

### Events
No events are associated with this method.
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
    "method": "org.rdk.TextToSpeech.pause",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.TextToSpeech.pause", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.playbackError"></a>
## *playbackError [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 7,
    "method": "org.rdk.TextToSpeech.playbackError",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.TextToSpeech.playbackError", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.registerWithCallsign"></a>
## *registerWithCallsign [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 8,
    "method": "org.rdk.TextToSpeech.registerWithCallsign",
    "params": {
        "callsign": "",
        "sink": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.TextToSpeech.registerWithCallsign", "params": {"callsign": "", "sink": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.resume"></a>
## *resume [<sup>method</sup>](#head.Methods)*

Resume the speech

### Events
No events are associated with this method.
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
    "id": 9,
    "method": "org.rdk.TextToSpeech.resume",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.TextToSpeech.resume", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
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

<a id="method.setACL"></a>
## *setACL [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 10,
    "method": "org.rdk.TextToSpeech.setACL",
    "params": {
        "method": "",
        "apps": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.TextToSpeech.setACL", "params": {"method": "", "apps": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.setAPIKey"></a>
## *setAPIKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 11,
    "method": "org.rdk.TextToSpeech.setAPIKey",
    "params": {
        "apikey": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.TextToSpeech.setAPIKey", "params": {"apikey": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.setConfiguration"></a>
## *setConfiguration [<sup>method</sup>](#head.Methods)*

Set the tts configuration attributes

### Events
No events are associated with this method.
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
    "id": 12,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.TextToSpeech.setConfiguration", "params": {"ttsEndPoint": "", "ttsEndPointSecured": "", "language": "", "voice": "", "speechRate": "", "volume": 0, "rate": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "status": "TTS_OK"
    }
}
```

<a id="method.setFallbackText"></a>
## *setFallbackText [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 13,
    "method": "org.rdk.TextToSpeech.setFallbackText",
    "params": {
        "scenario": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.TextToSpeech.setFallbackText", "params": {"scenario": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.setPrimaryVolDuck"></a>
## *setPrimaryVolDuck [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 14,
    "method": "org.rdk.TextToSpeech.setPrimaryVolDuck",
    "params": {
        "prim": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.TextToSpeech.setPrimaryVolDuck", "params": {"prim": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.speak"></a>
## *speak [<sup>method</sup>](#head.Methods)*

Speaks text provided

### Events
No events are associated with this method.
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
    "id": 15,
    "method": "org.rdk.TextToSpeech.speak",
    "params": {
        "callsign": "",
        "text": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.TextToSpeech.speak", "params": {"callsign": "", "text": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "speechid": 0,
        "status": "TTS_OK"
    }
}
```

<a id="method.speechComplete"></a>
## *speechComplete [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 16,
    "method": "org.rdk.TextToSpeech.speechComplete",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.TextToSpeech.speechComplete", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="method.speechInterrupted"></a>
## *speechInterrupted [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 17,
    "method": "org.rdk.TextToSpeech.speechInterrupted",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.TextToSpeech.speechInterrupted", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="method.speechPause"></a>
## *speechPause [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 18,
    "method": "org.rdk.TextToSpeech.speechPause",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.TextToSpeech.speechPause", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="method.speechResume"></a>
## *speechResume [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 19,
    "method": "org.rdk.TextToSpeech.speechResume",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.TextToSpeech.speechResume", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="method.speechStart"></a>
## *speechStart [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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
    "id": 20,
    "method": "org.rdk.TextToSpeech.speechStart",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.TextToSpeech.speechStart", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="method.voiceChanged"></a>
## *voiceChanged [<sup>method</sup>](#head.Methods)*

Notify change in voice used for speaking

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.voice | string | voice changed |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.TextToSpeech.voiceChanged", "params": {"voice": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="method.willSpeak"></a>
## *willSpeak [<sup>method</sup>](#head.Methods)*

Notify speechid based on the speech state(eg: start,pause,..etc)

### Events
No events are associated with this method.
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
    "id": 22,
    "method": "org.rdk.TextToSpeech.willSpeak",
    "params": {
        "speechid": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.TextToSpeech.willSpeak", "params": {"speechid": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the TextToSpeech plugin:

TextToSpeech interface properties:

| Method | Description |
| :-------- | :-------- |
| [enable](#property.enable) | Query the status/enable tts |

<a id="property.Enable"></a>
## *Enable [<sup>property</sup>](#head.Properties)*

Query the status/enable tts

### Events
No events are associated with this method.
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

