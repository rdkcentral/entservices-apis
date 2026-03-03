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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.VoiceControl.configureVoice", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
| result.response | GetApiVersionNumberResponse | The API version response @retval ErrorCode::NONE: Operation completed successfully. @retval ErrorCode::GENERAL: General failure. |

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
        "response": ""
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.VoiceControl.sendVoiceMessage", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
| params.request | SetVoiceInitRequest | The voice init request parameters @retval ErrorCode::NONE: Voice initialization set successfully. @retval ErrorCode::GENERAL: Failed to set voice initialization. |
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.VoiceControl.setVoiceInit", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
| params.request | VoiceSessionAudioStreamStartRequest | The voice session audio stream start request parameters @retval ErrorCode::NONE: Voice session audio stream started successfully. @retval ErrorCode::GENERAL: Failed to start voice session audio stream. |
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.VoiceControl.voiceSessionAudioStreamStart", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.VoiceControl.voiceSessionByText", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.VoiceControl.voiceSessionRequest", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
| params.request | VoiceSessionTerminateRequest | The voice session terminate request parameters @retval ErrorCode::NONE: Voice session terminated successfully. @retval ErrorCode::GENERAL: Failed to terminate voice session. |
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
        "request": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.VoiceControl.voiceSessionTerminate", "params": {"request": ""}}' http://127.0.0.1:9998/jsonrpc
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
| result.response | VoiceSessionTypesResponse | The voice session types response @retval ErrorCode::NONE: Voice session types retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve voice session types. |

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
    "result": {
        "response": ""
    }
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
| result.response | VoiceStatusResponse | The voice status response @retval ErrorCode::NONE: Voice status retrieved successfully. @retval ErrorCode::GENERAL: Failed to retrieve voice status. |

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
        "response": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.VoiceControl.onKeywordVerification",
    "params": {
        "params": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.VoiceControl.onServerMessage",
    "params": {
        "params": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.VoiceControl.onSessionBegin",
    "params": {
        "params": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.VoiceControl.onSessionEnd",
    "params": {
        "params": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.VoiceControl.onStreamBegin",
    "params": {
        "params": ""
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
| params.params | string | Event data containing session begin information. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.VoiceControl.onStreamEnd",
    "params": {
        "params": ""
    }
}
```
