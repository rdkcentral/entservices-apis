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
| [configureVoice](#configureVoice) | Configure voice settings |
| [getApiVersionNumber](#getApiVersionNumber) | Get the API version number |
| [sendNotify_](#sendNotify_) | Send a notification event |
| [sendVoiceMessage](#sendVoiceMessage) | Send a voice message |
| [setVoiceInit](#setVoiceInit) | Set voice initialization |
| [voiceSessionAudioStreamStart](#voiceSessionAudioStreamStart) | Start audio stream for voice session |
| [voiceSessionByText](#voiceSessionByText) | Voice session by text (DEPRECATED) |
| [voiceSessionRequest](#voiceSessionRequest) | Request a voice session |
| [voiceSessionTerminate](#voiceSessionTerminate) | Terminate a voice session |
| [voiceSessionTypes](#voiceSessionTypes) | Get voice session types |
| [voiceStatus](#voiceStatus) | Get voice status |

<a id="configureVoice"></a>
## *configureVoice*

Configure voice settings

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.VoiceControl.configureVoice", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
    "method": "org.rdk.VoiceControl.getApiVersionNumber",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.VoiceControl.getApiVersionNumber", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
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
| params.eventName | char | Name of the event |
| params.parameters | JsonObject | Input parameters (unused) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.VoiceControl.sendNotify_",
    "params": {
        "eventName": "a",
        "parameters": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.VoiceControl.sendNotify_", "params": {"eventName": "a", "parameters": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="sendVoiceMessage"></a>
## *sendVoiceMessage*

Send a voice message

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.VoiceControl.sendVoiceMessage", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Set voice initialization

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.VoiceControl.setVoiceInit", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Start audio stream for voice session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Voice session by text (DEPRECATED)

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.VoiceControl.voiceSessionByText", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Request a voice session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.VoiceControl.voiceSessionRequest", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Terminate a voice session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.VoiceControl.voiceSessionTerminate", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
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

Get voice session types

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
    "method": "org.rdk.VoiceControl.voiceSessionTypes",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.VoiceControl.voiceSessionTypes", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="voiceStatus"></a>
## *voiceStatus*

Get voice status

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | JsonObject | Input parameters (unused) |
| params.response | JsonObject | JSON response object @retval 0: Success |
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
    "method": "org.rdk.VoiceControl.voiceStatus",
    "params": {
        "parameters": "",
        "response": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.VoiceControl.voiceStatus", "params": {"parameters": "", "response": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the VoiceControl plugin:

VoiceControl interface events:

| Event | Description |
| :-------- | :-------- |
| [onKeywordVerification](#onKeywordVerification) | Keyword verification event |
| [onServerMessage](#onServerMessage) | Server message event |
| [onSessionBegin](#onSessionBegin) | Session begin event |
| [onSessionEnd](#onSessionEnd) | Session end event |
| [onStreamBegin](#onStreamBegin) | Stream begin event |
| [onStreamEnd](#onStreamEnd) | Stream end event |

<a id="onKeywordVerification"></a>
## *onKeywordVerification*

Keyword verification event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.VoiceControl.onKeywordVerification",
    "params": {
        "eventData": ""
    }
}
```

<a id="onServerMessage"></a>
## *onServerMessage*

Server message event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.VoiceControl.onServerMessage",
    "params": {
        "eventData": ""
    }
}
```

<a id="onSessionBegin"></a>
## *onSessionBegin*

Session begin event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.VoiceControl.onSessionBegin",
    "params": {
        "eventData": ""
    }
}
```

<a id="onSessionEnd"></a>
## *onSessionEnd*

Session end event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.VoiceControl.onSessionEnd",
    "params": {
        "eventData": ""
    }
}
```

<a id="onStreamBegin"></a>
## *onStreamBegin*

Stream begin event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.VoiceControl.onStreamBegin",
    "params": {
        "eventData": ""
    }
}
```

<a id="onStreamEnd"></a>
## *onStreamEnd*

Stream end event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventData | ctrlm_voice_iarm_event_json_t |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.VoiceControl.onStreamEnd",
    "params": {
        "eventData": ""
    }
}
```
