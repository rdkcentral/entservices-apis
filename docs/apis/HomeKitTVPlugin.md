<!-- Generated automatically, DO NOT EDIT! -->
<a name="HomeKitTV_Plugin"></a>
# HomeKitTV Plugin

A HomeKitTV plugin for Thunder framework.

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

The HomeKitTV plugin starts the Daemon backend service and provides Thunder Interface APIs/Properties/Events to manage the AirPlay Application life cycle.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *HomeKitTV*) |
| classname | string | Class name: *HomeKitTV* |
| locator | string | Library name: *libWPEFrameworkHomeKitTV.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the HomeKitTV plugin:

HomeKitTVJSONRPC interface methods:

| Method | Description |
| :-------- | :-------- |
| [setCurrentInputSource](#setCurrentInputSource) | Request Airplay to set the current Input-Source |
| [getEnabledStatus](#getEnabledStatus) | Return the status of Airplay On/Off |
| [getConnectionStatus](#getConnectionStatus) | Request whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device |
| [requestAppLaunch](#requestAppLaunch) | Requests Airplay Daemon to launch specific page of Airplay App |


<a name="setCurrentInputSource"></a>
## *setCurrentInputSource*

Request Airplay to set the current Input-Source.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sourceName | string | Selected Input-Source using IR Remote |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ```ERROR_UNAVAILABLE``` | Airplay is unavailable |
| 22 | ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.setCurrentInputSource",
    "params": {
        "sourceName": "HDMI1,AirPlay,ImmersiveUI"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="getEnabledStatus"></a>
## *getEnabledStatus*

Return the status of Airplay On/Off.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | boolean |  |
| result.success | boolean | Legacy parameter (always true) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.getEnabledStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": true,
        "success": true
    }
}
```

<a name="getConnectionStatus"></a>
## *getConnectionStatus*

Request whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.paired | boolean |  |
| result.success | boolean | Legacy parameter (always true) |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.getConnectionStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "paired": true,
        "success": true
    }
}
```

<a name="requestAppLaunch"></a>
## *requestAppLaunch*

Requests Airplay Daemon to launch specific page of Airplay App.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.origin | string | Origin of the launch Request |
| params.reason | string | Reason to request Airplay app UI, e.g., to display Airplay curtain page or Airlay & HomeKit settings |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean |  |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 2 | ```ERROR_UNAVAILABLE``` | Airplay is unavailable |
| 22 | ```ERROR_UNKNOWN_KEY``` | Command is not set |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.requestAppLaunch",
    "params": {
        "origin": "EPG",
        "reason": "HomeScreenButton"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="Properties"></a>
# Properties

The following properties are provided by the HomeKitTV plugin:

HomeKitTVJSONRPC interface properties:

| Property | Description |
| :-------- | :-------- |
| [setAppContainerIPAddress](#setAppContainerIPAddress) | Set the Airplay Application containers IP address to Daemon side |

StateControl interface properties:

| Property | Description |
| :-------- | :-------- |
| [state](#state) | Running state of the service |


<a name="setAppContainerIPAddress"></a>
## *setAppContainerIPAddress*

Provides access to the set the Airplay Application containers IP address to Daemon side.

### Events

No Events

### Value

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property) | object | Set the Airplay Application containers IP address to Daemon side |
| (property).ipaddress | string | IP Address of Application container |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.setAppContainerIPAddress"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "ipaddress": "127.0.0.1"
    }
}
```

#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.setAppContainerIPAddress",
    "params": {
        "ipaddress": "127.0.0.1"
    }
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
    "method": "HomeKitTV.state"
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
    "method": "HomeKitTV.state",
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

The following events are provided by the HomeKitTV plugin:

HomeKitTVJSONRPC interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppStateChangeRequest](#onAppStateChangeRequest) | Event raised to request state change of the Airplay Application to starting-section, resuming-section, suspending-close, and stopping-destroy |
| [onEnabledStatusChanged](#onEnabledStatusChanged) | Event raised to send Airplay status changed to On or Off |
| [onInputSourceChanged](#onInputSourceChanged) | Event raised to send selected Inputsource details |
| [onairplayerror](#onairplayerror) | Event raised to send failure events |
| [onConnectionStatusChanged](#onConnectionStatusChanged) | Event raised to notify pairing status changed |

StateControl interface events:

| Event | Description |
| :-------- | :-------- |
| [statechange](#statechange) | Signals a state change of the service |


<a name="onAppStateChangeRequest"></a>
## *onAppStateChangeRequest*

Event raised to request state change of the Airplay Application to starting-section, resuming-section, suspending-close, and stopping-destroy.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.origin | string | Origin of app state change request |
| params.intent | object | App State change intent object |
| params.intent?.action | string | <sup>*(optional)*</sup> Intent action |
| params.intent?.data | object | <sup>*(optional)*</sup> Intent's data |
| params.intent?.data.sectionName | string | String representing launch parameters |
| params.intent?.context | object | <sup>*(optional)*</sup> App State Change Intent Context Object |
| params.intent?.context.source | string | String representing the reason for triggering the section |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onAppStateChangeRequest",
    "params": {
        "origin": "EPG, Airplay",
        "intent": {
            "action": "section",
            "data": {
                "sectionName": "argv0:--cwd=/tmp"
            },
            "context": {
                "source": "HomeScreenButton, InputSourceSelected"
            }
        }
    }
}
```

<a name="onEnabledStatusChanged"></a>
## *onEnabledStatusChanged*

Event raised to send Airplay status changed to On or Off.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | Airplay setting status changed between On or Off |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onEnabledStatusChanged",
    "params": {
        "enabled": true
    }
}
```

<a name="onInputSourceChanged"></a>
## *onInputSourceChanged*

Event raised to send selected Inputsource details.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sourceType | string | Type of inputsource hdmi, composite, Airplay |
| params.portId | number | Port ID of Input source |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onInputSourceChanged",
    "params": {
        "sourceType": "HDMI, COMPOSITE, AIRPLAY",
        "portId": 1
    }
}
```

<a name="onairplayerror"></a>
## *onairplayerror*

Event raised to send failure events.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.errordata | string | Details of the failure |
| params.errorid | number | Failure code |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onairplayerror",
    "params": {
        "errordata": "Network lost",
        "errorid": 10
    }
}
```

<a name="onConnectionStatusChanged"></a>
## *onConnectionStatusChanged*

Event raised to notify pairing status changed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.paired | boolean | HomeKit Pairing status |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onConnectionStatusChanged",
    "params": {
        "paired": true
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

