<!-- Generated automatically, DO NOT EDIT! -->
<a id="AppActions_Module"></a>
# AppActions Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AppActions/IAppActions.h)**

A AppActions module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IAppActions](#IAppActions)
    - [Methods](#IAppActions-Methods)
    - [Notifications](#IAppActions-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `AppActions` module provides the following interface(s):

- IAppActions

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AppActions) |
| classname | string | Class name: *AppActions* |
| locator | string | Library name: *libWPEFrameworkAppActions.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IAppActions"></a>
## IAppActions Interface

### Description

Interface for AppActions plugin

<a id="IAppActions-Methods"></a>
### Methods

The following methods are provided by the IAppActions Interface:

| Method | Description |
| :-------- | :-------- |
| [actionStart](#actionStart) | Starts an action for the given intent and handler app. |

<a id="actionStart"></a>
## *actionStart*

Initiates an action from the initiator to the AppActions with the specified intent.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.initiator | string | The ID of the app/ module initiating the action. |
| params.intent | string | The intent string describing the action. |
| params?.handlerAppId | string | <sup>(optional)</sup>The ID of the app handling the action. |
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
    "method": "org.rdk.AppActions.actionStart",
    "params": {
        "initiator": "",
        "intent": "",
        "handlerAppId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AppActions.actionStart", "params": {"initiator": "", "intent": "", "handlerAppId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Failure"
    }
}
```

<a id="IAppActions-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IAppActions Interface:

| Event | Description |
| :-------- | :-------- |
| [onActionStartRequest](#onActionStartRequest) | Notifies when an action start event occurs. |

<a id="onActionStartRequest"></a>
## *onActionStartRequest*

Notifies when an action start event occurs.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.initiator | string | The ID of the app/ module initiating the action. |
| params.intent | string | The intent string describing the action. |
| params?.handlerAppId | string | <sup>(optional)</sup>The ID of the app handling the action. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.AppActions.onActionStartRequest",
    "params": {
        "initiator": "",
        "intent": "",
        "handlerAppId": ""
    }
}
```

