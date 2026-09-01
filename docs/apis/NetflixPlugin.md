<!-- Generated automatically, DO NOT EDIT! -->
<a name="Netflix_Plugin"></a>
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
| [factoryreset](#factoryreset) | Performs a reset to factory defaults |
| [systemcommand](#systemcommand) | Does Netflix system command |


<a name="factoryreset"></a>
## *factoryreset*

Performs a reset to factory defaults.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations.

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
| 2 | ```ERROR_UNAVAILABLE``` | Netflix is unavailable |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.factoryreset"
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

Does Netflix system command.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | Command to send to Netflix |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Always null |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ```ERROR_UNAVAILABLE``` | Netflix is unavailable |
| 22 | ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.systemcommand",
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

<a name="Properties"></a>
# Properties

The following properties are provided by the Netflix plugin:

Netflix interface properties:

| Property | Description |
| :-------- | :-------- |
| [esn](#esn) <sup>RO</sup> | ESN value |
| [visibility](#visibility) <sup>WO</sup> | Current Netflix visibility |
| [nfrstatus](#nfrstatus) | native frame rate status |

StateControl interface properties:

| Property | Description |
| :-------- | :-------- |
| [state](#state) | Running state of the service |


<a name="esn"></a>
## *esn*

Provides access to the ESN value.

> This property is **read-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | ESN value |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ```ERROR_UNAVAILABLE``` | Netflix is unavailable |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.esn"
}
```

#### Get Response

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

> This property is **write-only**.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | Current Netflix visibility (must be one of the following: *visible*, *hidden*) |

### Example

#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.visibility",
    "params": "visible"
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

<a name="nfrstatus"></a>
## *nfrstatus*

Provides access to the native frame rate status.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | native frame rate status (must be one of the following: *enable*, *disable*) |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.nfrstatus"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "enable"
}
```

#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.nfrstatus",
    "params": "enable"
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

<a name="state"></a>
## *state*

Provides access to the running state of the service.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | string | Running state of the service (must be one of the following: *resumed*, *suspended*) |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "Netflix.state"
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
    "method": "Netflix.state",
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
| [visibilitychange](#visibilitychange) | Signals a visibility change of the Netflix |
| [playbackchange](#playbackchange) | Signals a playback change of the Netflix |

StateControl interface events:

| Event | Description |
| :-------- | :-------- |
| [statechange](#statechange) | Signals a state change of the service |


<a name="visibilitychange"></a>
## *visibilitychange*

Signals a visibility change of the Netflix.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | boolean | Determines if the Netflix has been hidden (true) or made visible (false) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.visibilitychange",
    "params": {
        "hidden": false
    }
}
```

<a name="playbackchange"></a>
## *playbackchange*

Signals a playback change of the Netflix.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playing | boolean | Determines if the Netflix is in playing mode (true) or not playing (false) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.playbackchange",
    "params": {
        "playing": true
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
    "method": "client.events.statechange",
    "params": {
        "suspended": false
    }
}
```

