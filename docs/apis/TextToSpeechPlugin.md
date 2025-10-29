<!-- Generated automatically, DO NOT EDIT! -->
<a id="TextToSpeech_Plugin"></a>
# TextToSpeech Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/TextToSpeech/ITextToSpeech.h)**

A TextToSpeech plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
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
    "id": 0,
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
    "id": 1,
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
    "id": 2,
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
    "id": 3,
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
    "id": 4,
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
    "id": 5,
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
    "id": 6,
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
    "id": 7,
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
    "id": 8,
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
    "id": 9,
    "method": "org.rdk.TextToSpeech.willSpeak",
    "params": {
        "speechid": 0
    }
}
```
