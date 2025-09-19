<!-- Generated automatically, DO NOT EDIT! -->
<a name="Netflix Plugin"></a>
# Netflix Plugin

A Netflix plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The Netflix plugin allows applications to interact with the Netflix application that is running on a set-top device.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *Netflix*) |
| classname | string | Class name: *Netflix* |
| locator | string | Library name: *libWPEFrameworkNetflix.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the Netflix plugin:

Netflix interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryreset](#factoryreset) | Performs a Netflix factory reset |
| [systemcommand](#systemcommand) | Executes the specified Netflix system command |
| [voicecommand](#voicecommand) | Executes the specified Netflix voice command |

<a name="factoryreset"></a>
## *factoryreset*

Performs a Netflix factory reset.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ERROR_UNAVAILABLE | Netflix is unavailable |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.factoryreset"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="systemcommand"></a>
## *systemcommand*

Executes the specified Netflix system command.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | The system command to send to the Netflix application |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ERROR_UNAVAILABLE | Netflix is unavailable |
| 22 | ERROR_UNKNOWN_KEY | Command is not set |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.systemcommand",
    "params": {
        "command": "config"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="voicecommand"></a>
## *voicecommand*

Executes the specified Netflix voice command.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.assistant | string | The voice assistant |
| params.lang | string | The uttered language |
| params.micType | string | The microphone type |
| params.timeout | Integer | The duration, in milliseconds, to wait for execution |
| params.utteranceStructured | object | The structure of the utterance |
| params.utteranceStructured.command | string | The command to send to the Netflix application |
| params.utteranceStructured.intents | array | A string array of intents |
| params.utteranceStructured.intents[#] | string |  |
| params.utteranceStructured.resources | array | The structured utterances to be executed |
| params.utteranceStructured.resources[#] | object |  |
| params.utteranceStructured.resources[#].type | string | The resources type |
| params.utteranceStructured.resources[#].value | string | The resources value |
| params.utterancetext | string | The uttered text |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ERROR_UNAVAILABLE | Netflix is unavailable |
| 22 | ERROR_UNKNOWN_KEY | Command is not set |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.voicecommand",
    "params": {
        "assistant": "XFINITY",
        "lang": "en-US",
        "micType": "NEAR_FIELD",
        "timeout": 15000,
        "utteranceStructured": {
            "command": "search",
            "intents": [
                "..."
            ],
            "resources": [
                {
                    "type": "Query",
                    "value": "Comedy Movies"
                }
            ]
        },
        "utterancetext": "Find Comedy Movies"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="Properties"></a>
# Properties

The following properties are provided by the Netflix plugin:

Netflix interface properties:
| Property | Description |
| :-------- | :-------- |
| [esn](#esn)  | ESN value|
| [visibility](#visibility)  | Current Netflix visibility |

StateControl interface properties:
| Property | Description |
| :-------- | :-------- |
| [state](#state) | Running state of the service |

<a name="esn"></a>
## *esn*

Provides access to the ESN value.
This property is read-only.

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | ESN value |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ERROR_UNAVAILABLE | Netflix is unavailable |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.esn"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "DADDAUFV2=00000000000000000000000000000001"
}
```

<a name="visibility"></a>
## *visibility*

Provides access to the current Netflix visibility.

This property is write-only.

### Description

Use this property to return current visibilty status of Netflix.

### Events

| Event | Description |
| :-------- | :-------- |
| visibilitychange | Triggered if the Netflix visibility changed. |

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | Current Netflix visibility. (must be one of the following: visible, hidden) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.visibility",
    "params": "visible"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="state"></a>
## *state*

Provides access to the running state of the service.

### Description

Use this property to return the running state of the service.

### Events

| Event | Description |
| :-------- | :-------- |
| statechange | Triggered if the state of the service changed. |

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | Running state of the service. (must be one of the following: resumed, suspended) |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.state"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "resumed"
}
```

#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.1.state",
    "params": "resumed"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the Netflix plugin:

Netflix interface events:
| Event | Description |
| :-------- | :-------- |
| [visibilitychange](#visibilitychange) | Triggered when the Netflix service visibility changes |
| [playbackchange](#playbackchange) | Triggered when Netflix playback changes |
| [notifyeventchange](#notifyeventchange) | Triggered when an event change is sent with custom event names |

StateControl interface events:
| Event | Description |
| :-------- | :-------- |
| [statechange](#statechange) | Signals a state change of the service |

<a name="visibilitychange"></a>
## *visibilitychange*

Triggered when the Netflix service visibility changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | boolean | Whether Netflix has been hidden (true) or made visible (false) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.1.visibilitychange",
    "params": {
        "hidden": false
    }
}
```

<a name="playbackchange "></a>
## *playbackchange *

Triggered when Netflix playback changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playing | boolean | Whether Netflix is playing (true) or not playing (false) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.1.playbackchange",
    "params": {
        "playing": true
    }
}
```

<a name="notifyeventchange "></a>
## *notifyeventchange *

Triggered when an event change is sent with custom event names.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.EventName | string | The event name corresponding to the Netflix action |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.1.notifyeventchange",
    "params": {
        "EventName": "signoff"
    }
}
```

<a name="statechange"></a>
## *statechange*

Signals a state change of the service.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.suspended | boolean | Determines if the service has entered suspended state (true) or resumed state (false) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.1.statechange",
    "params": {
        "suspended": false
    }
}
```
