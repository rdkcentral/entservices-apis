<!-- Generated automatically, DO NOT EDIT! -->
<a name="HomeKitTV Plugin"></a>
# HomeKitTV Plugin

A org.rdk.HomeKitTV Plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
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
| callsign | string | HomeKitTV |
| classname | string | Class name : HomeKitTV |
| locator | string | Library name: LibWPEFrameworkHomeKitTV.so |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the HomeKitTV plugin:

| Method | Description |
| :-------- | :-------- |
| [requestAppLaunch](#requestAppLaunch) | The distributor application (example, Immersive UI) running in the HomeKit Television accessory devices (such as TVs, Streaming Boxes and Streaming Sticks) SHALL use this API to request HomeKit to prepare for the launch of AirPlay Application |
| [setCurrentInputSource](#setCurrentInputSource) | The distributor application (example, Immersive UI) running in the HomeKit Television accessory devices (such as TVs, Streaming Boxes and Streaming Sticks) SHALL use this API to inform HomeKit about the change in the currently selected Input Source. |
| [getEnabledStatus](#getEnabledStatus) | Returns whether the airplay status is switched ON (true) or switched OFF(false) in the connected AirPlay Device's AirPlay Settings. |
| [getEnabledStatus](#getEnabledStatus) | Returns whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device |

<a name="requestAppLaunch"></a>
## *requestAppLaunch*

Launches the AirPlay Application and displays application UI when Airplay icon selected from Settings and/or Input source.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object | An empty parameter object |
| param.origin | string | The origin of the launch request. One of the following string SHALL be used: "EPG" |
| params.reason | string | Sets the reason to launch AirPlay Application:"HomeScreenButton" or "InputSourceSelected" |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | success: true/false |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.requestapplaunch",
    "params": {"origin": "EPG" ,"reason":"HomeScreenButton"}
}
```
#### Curl command Form

curl -H "Authorization: Bearer `WPEFrameworkSecurityUtility | cut -d '"' -f 4`" --header "Content-Type: application/json" --request POST --data '{"jsonrpc":"2.0","id":"3","method": "HomeKitTV.1.requestapplaunch", "params": {"origin": "EPG" ,"reason":"HomeScreenButton"}}' http://127.0.0.1:9998/jsonrpc

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

<a name="setCurrentInputSource"></a>
## *setCurrentInputSource*

Request Airplay-Daemon to set the current Input-Source

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object | An empty parameter object |
| params.sourceName	 | string | Selected Input-Source using IR Remote "HDMI1" ,"AirPlay" |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | boolean | success: true/false |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.setcurrentInputsource",
    "params": {"sourceName":"AirPlay"}
}
```

#### Curl command Form

curl  --header "Content-Type: application/json" -H "Authorization: Bearer `WPEFrameworkSecurityUtility | cut -d '"' -f 4`"  --request POST --data '{"jsonrpc": "2.0","id": 4,"method":"HomeKitTV.1.setcurrentinputsource","params": {"sourceName": "AirPlay"}}' http://127.0.0.1:9998/jsonrpc

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": 1
}
```

<a name="getConnectionStatus"></a>
## *getConnectionStatus*

Set/Get property to Returns whether the AirPlay capable Apple companion device is paired (true) or unpaired (false) with this HomeKit Television Accessory device.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (Property) | object | An empty parameter object |
| (property).getConnectionStatus | Boolean | AirPlay paired status On(true)/Off(false) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.getconnectionstatus"
}
```

#### Curl command Form

curl -H "Authorization: Bearer `WPEFrameworkSecurityUtility | cut -d '"' -f 4`" --header "Content-Type: application/json" --request POST --data '{"jsonrpc":"2.0","id":"3","method": "HomeKitTV.1.getconnectionstatus"}' http://127.0.0.1:9998/jsonrpc

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="getEnabledStatus"></a>
## *getEnabledStatus*

Get AirPlay Setting On/Off value.
Default value set by Daemon is On.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (Property) | object | An empty parameter object |
| (property).getenabledstatus | Boolean | AirPlay option in AirPlay Settings set as On(true)/Off(false) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "HomeKitTV.getenabledstatus"
}
```

#### Curl command Form

curl -H "Authorization: Bearer `WPEFrameworkSecurityUtility | cut -d '"' -f 4`" --header "Content-Type: application/json" --request POST --data '{"jsonrpc":"2.0","id":"3","method": "HomeKitTV.1.getenabledstatus"}' http://127.0.0.1:9998/jsonrpc

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": 
     {"success": 
        true,
      "enabled":true
     }
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

Notifications are the events generated by AirPlay Daemon to manage AirPlay Application states:

| Event | Description |
| :-------- | :-------- |
| [onAppStateChangeRequest](#onAppStateChangeRequest) | Raised when HomeKit TV wants the distributor application to switch the state of the AirPlay Application running in the device. |
| [onEnabledStatusChanged](#onEnabledStatusChanged) | AirPlay Daemon raises this event when user changes the AirPlay On/Off from AirPlay Settings  |
| [onConnectionStatusChanged](#onConnectionStatusChanged) | AirPlay Daemon raises this event in below cases:Pairing status - When Pairing status changes from pair to unpair or vice-a-versa from Homekit |
| [OninputSourceChanged](#OninputSourceChanged) | AirPlay Daemon raises this event when input source changes via Home Application in Sender's Apple devices (iPhone/iPad/iPod)o |

<a name="onAppStateChangeRequest"></a>
## *onAppStateChangeRequest*

Raised when HomeKit TV wants the distributor application to switch the state of the AirPlay Application running in the device.

### Parameters

| Name | Type | Description | M/O |
| :-------- | :-------- | :-------- | :-------- |
| params | object |  |  |
| params.origin | string | the state of Airplay application requested. "AppStart, AppSuspend, AppResume, AppStop" |  |
| params.intent | object | Input Parameters to be passed to RDKShell APIs. |  |
| params.intent.action | String | One of the following string:For "starting" or "resuming" the app: section For "suspending" the app: close For "stopping" the app: destroy |  |
| params.intent.data | object | App State Change Intent "Data Object" associated with the requested action. Applicable only for the "section" action. | Mandatory for intent action "section" Don't care for other actions. |
| params.intent.data.sectionName | boolean | String representing launch parameters that needs to be passed to the AirPlay Application in case of "section" action. | Mandatory for intent action "section" Don't care for other actions. |
| params.intent.context | Object | App State Change Intent "Context Object" associated with the requested action. Applicable only for the "section" action. | Mandatory for intent action "section" Don't care for other actions. |
| params.intent.context.source | String | String representing the reason for triggering the "section" action from the given origin. Value of the String SHALL be one of the following: HomeScreenButton, InputSourceSelected | Mandatory for intent action "section"Don't care for other actions |

### Example

## Start or Resume AirPlay App:
```json
{
    "jsonrpc":"2.0",
    "id":"3",
    "method": "org.rdk.HomeKitTV.onAppStateChangeRequest",
    "params": {"origin":"AirPlay",
    "intent":{"action":"section",
    "data":{"sectionName":"uejhfeufeuifbuefbiejfief"},
    "context":{"source":"HomeScreenButton"}
    }
  }
}
```

## Suspend AirPlay App
```json
{
    "jsonrpc":"2.0",
    "id":"3",
    "method": "org.rdk.HomeKitTV.onAppStateChangeRequest",
    "params": {"origin":"AirPlay", "intent":{"action":"close"}
    }
}
```

## Stop AirPlay App:
```json
{
    "jsonrpc":"2.0",
    "id":"3",
    "method": "org.rdk.HomeKitTV.onAppStateChangeRequest",
    "params": {"origin":"AirPlay", "intent":{"action":"destroy"}
    }
}
```

<a name="onEnabledStatusChanged"></a>
## *onEnabledStatusChanged*

AirPlay Daemon raises this event when user changes the AirPlay On/Off from AirPlay Settings 

### Parameters

| Name | Type | Description | M/O |
| :-------- | :-------- | :-------- | :-------- |
| params | object | Notification / Event Object | Mandatory |
| params.enabled | Boolean | true if Airplay Status is enabled or false if disabled | Mandatory |

<a name="onConnectionStatusChanged"></a>
## *onConnectionStatusChanged*

AirPlay Daemon raises this event in below cases:
Pairing status - When Pairing status changes from pair to unpair or vice-a-versa from Homekit

### Parameters

| Name | Type | Description | M/O |
| :-------- | :-------- | :-------- | :-------- |
| params | object | Notification / Event Object | Mandatory |
| params.enabled | Boolean | true if Airplay Status is enabled or false if disabled | Mandatory |

<a name="onInputSourceChanged"></a>
## *onInputSourceChanged*

Raised when input source is changed via Home Application running in Apple devices.

### Parameters

| Name | Type | Description | M/O |
| :-------- | :-------- | :-------- | :-------- |
| params | object | Notification / Event Object | Mandatory |
| params.sourceType | string | Name of the Input Source Type. e.g., HDMI, Composite, etc. | Mandatory |
| params.portId | Number | Port ID of the input source e.g., 0, 1 | Mandatory |

## Example
```json
{
  "jsonrpc":"2.0",
  "id":"3",
  "method": "org.rdk.HomeKitTV.onAppStateChangeRequest",
  "params":
}

