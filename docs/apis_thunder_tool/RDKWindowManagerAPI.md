<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_RDKWindowManager_API"></a>
# RDKWindowManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

RDKWindowManager interface for Thunder framework.

(Defined with IRDKWindowManager in [IRDKWindowManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IRDKWindowManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the RDKWindowManager interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

RDKWindowManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the RDKWindowManager interface:

RDKWindowManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [createDisplay](#method_createDisplay) | Create the display window |
| [getApps](#method_getApps) | Get the list of Apps which are currently active and available |
| [addKeyIntercept](#method_addKeyIntercept) | Registers a key intercept for a specific key code and client |
| [addKeyIntercepts](#method_addKeyIntercepts) | Registers multiple key intercepts in a single operation |
| [removeKeyIntercept](#method_removeKeyIntercept) | Removes a key intercept for a specific key code and client |
| [addKeyListener](#method_addKeyListener) | Registers listeners for specific keys |
| [removeKeyListener](#method_removeKeyListener) | Removes listeners for specific keys |
| [injectKey](#method_injectKey) | Simulates a key press event with optional modifiers |
| [generateKey](#method_generateKey) | Generates a key event for the specified keys and client |
| [enableInactivityReporting](#method_enableInactivityReporting) | Enables the inactivity reporting |
| [setInactivityInterval](#method_setInactivityInterval) | Sets inactivity interval if EnableUserInactivity feature is enabled |
| [resetInactivityTime](#method_resetInactivityTime) | Resets inactivity interval if EnableUserInactivity feature is enabled |
| [enableKeyRepeats](#method_enableKeyRepeats) | Key repeats are enabled/disabled |
| [getKeyRepeatsEnabled](#method_getKeyRepeatsEnabled) | Retrieves the flag determining whether keyRepeat true/false |
| [ignoreKeyInputs](#method_ignoreKeyInputs) | Ignore key inputs |
| [enableInputEvents](#method_enableInputEvents) | Enables KeyInputEvents for list of clients specified |
| [keyRepeatConfig](#method_keyRepeatConfig) | Enables KeyInputEvents for list of clients specified |
| [setFocus](#method_setFocus) | Sets the focus to the app with the app id |
| [setVisible](#method_setVisible) | Sets the visibility of the given client or appInstanceId |
| [renderReady](#method_renderReady) | To get the status of first frame is rendered or not |
| [enableDisplayRender](#method_enableDisplayRender) | Enable or disable the rendering of a Wayland display |

<a id="method_createDisplay"></a>
## *createDisplay [<sup>method</sup>](#head_Methods)*

Create the display window.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.displayParams | string | mandatory | JSON String format with client,displayName,displayWidth,displayHeight,virtualDisplay,virtualWidth,virtualHeight,topmost,focus |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.createDisplay",
  "params": {
    "displayParams": "..."
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

<a id="method_getApps"></a>
## *getApps [<sup>method</sup>](#head_Methods)*

Get the list of Apps which are currently active and available.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Returns the list of app IDs as a JSON string |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getApps"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="method_addKeyIntercept"></a>
## *addKeyIntercept [<sup>method</sup>](#head_Methods)*

Registers a key intercept for a specific key code and client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.intercept | string | mandatory | JSON String format with the client/callSign, keyCode, modifiers |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.addKeyIntercept",
  "params": {
    "intercept": "..."
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

<a id="method_addKeyIntercepts"></a>
## *addKeyIntercepts [<sup>method</sup>](#head_Methods)*

Registers multiple key intercepts in a single operation.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.intercepts | string | mandatory | JSON String format containing the array of key intercept(client/callSign, keyCode, modifiers) configuration |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.addKeyIntercepts",
  "params": {
    "intercepts": "..."
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

<a id="method_removeKeyIntercept"></a>
## *removeKeyIntercept [<sup>method</sup>](#head_Methods)*

Removes a key intercept for a specific key code and client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.intercept | string | mandatory | JSON String format with the client/callSign, keyCode, modifiers |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.removeKeyIntercept",
  "params": {
    "intercept": "..."
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

<a id="method_addKeyListener"></a>
## *addKeyListener [<sup>method</sup>](#head_Methods)*

Registers listeners for specific keys.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.keyListeners | string | mandatory | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.addKeyListener",
  "params": {
    "keyListeners": "..."
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

<a id="method_removeKeyListener"></a>
## *removeKeyListener [<sup>method</sup>](#head_Methods)*

Removes listeners for specific keys.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.keyListeners | string | mandatory | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.removeKeyListener",
  "params": {
    "keyListeners": "..."
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

<a id="method_injectKey"></a>
## *injectKey [<sup>method</sup>](#head_Methods)*

Simulates a key press event with optional modifiers.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.keyCode | integer | mandatory | Key code to be injected, modifiers :  JSON String format with one or more modifiers |
| params.modifiers | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.injectKey",
  "params": {
    "keyCode": 0,
    "modifiers": "..."
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

<a id="method_generateKey"></a>
## *generateKey [<sup>method</sup>](#head_Methods)*

Generates a key event for the specified keys and client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.keys | string | mandatory | JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate |
| params.client | string | mandatory | Name of the client/callSign requesting the key generation |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.generateKey",
  "params": {
    "keys": "...",
    "client": "..."
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

<a id="method_enableInactivityReporting"></a>
## *enableInactivityReporting [<sup>method</sup>](#head_Methods)*

Enables the inactivity reporting.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enable | boolean | mandatory | Flag to true/false the feature |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.enableInactivityReporting",
  "params": {
    "enable": false
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

<a id="method_setInactivityInterval"></a>
## *setInactivityInterval [<sup>method</sup>](#head_Methods)*

Sets inactivity interval if EnableUserInactivity feature is enabled.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.interval | integer | mandatory | Time interval set for inactivity |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setInactivityInterval",
  "params": {
    "interval": 0
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

<a id="method_resetInactivityTime"></a>
## *resetInactivityTime [<sup>method</sup>](#head_Methods)*

Resets inactivity interval if EnableUserInactivity feature is enabled.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.resetInactivityTime"
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

<a id="method_enableKeyRepeats"></a>
## *enableKeyRepeats [<sup>method</sup>](#head_Methods)*

Key repeats are enabled/disabled.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enable | boolean | mandatory | Flag to true/false the key repeats |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.enableKeyRepeats",
  "params": {
    "enable": false
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

<a id="method_getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled [<sup>method</sup>](#head_Methods)*

Retrieves the flag determining whether keyRepeat true/false.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Flag stating whether keyRepeat true/false |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getKeyRepeatsEnabled"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_ignoreKeyInputs"></a>
## *ignoreKeyInputs [<sup>method</sup>](#head_Methods)*

Ignore key inputs.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.ignore | boolean | mandatory | Flag stating whether key inputs ignored |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.ignoreKeyInputs",
  "params": {
    "ignore": false
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

<a id="method_enableInputEvents"></a>
## *enableInputEvents [<sup>method</sup>](#head_Methods)*

Enables KeyInputEvents for list of clients specified.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.clients | string | mandatory | JSON String format with number of clients, enable:Flag to enable input events |
| params.enable | boolean | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.enableInputEvents",
  "params": {
    "clients": "...",
    "enable": false
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

<a id="method_keyRepeatConfig"></a>
## *keyRepeatConfig [<sup>method</sup>](#head_Methods)*

Enables KeyInputEvents for list of clients specified.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.input | string | mandatory | Input type (default/keyboard) |
| params.keyConfig | string | mandatory | JSON String format with enabled, initialDelay and repeatInterval |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.keyRepeatConfig",
  "params": {
    "input": "...",
    "keyConfig": "..."
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

<a id="method_setFocus"></a>
## *setFocus [<sup>method</sup>](#head_Methods)*

Sets the focus to the app with the app id.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setFocus",
  "params": {
    "client": "..."
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

<a id="method_setVisible"></a>
## *setVisible [<sup>method</sup>](#head_Methods)*

Sets the visibility of the given client or appInstanceId.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory | Client name or application instance ID |
| params.visible | boolean | mandatory | Boolean indicating the visibility status: `true` for visible, `false` for hide |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setVisible",
  "params": {
    "client": "...",
    "visible": false
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

<a id="method_renderReady"></a>
## *renderReady [<sup>method</sup>](#head_Methods)*

To get the status of first frame is rendered or not.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory | Client name or application instance ID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Returns true if the application has rendered first frame, false if it has not yet |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.renderReady",
  "params": {
    "client": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_enableDisplayRender"></a>
## *enableDisplayRender [<sup>method</sup>](#head_Methods)*

Enable or disable the rendering of a Wayland display.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory | Client name or application instance ID |
| params.enable | boolean | mandatory | Flag to true/false for controlling the wayland render |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.enableDisplayRender",
  "params": {
    "client": "...",
    "enable": false
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the RDKWindowManager interface:

RDKWindowManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [onUserInactivity](#notification_onUserInactivity) | Posting the client is inactive state |
| [onDisconnected](#notification_onDisconnected) | Notifies when an application is disconnected |
| [onReady](#notification_onReady) | Posting the client for first frame ready |
| [onConnected](#notification_onConnected) | Notifies when an application is connected |
| [onVisible](#notification_onVisible) | Notifies when an application is visible |
| [OnHidden](#notification_OnHidden) | Notifies when an application is hidden |
| [OnFocus](#notification_OnFocus) | Notifies when an application is in focus |
| [OnBlur](#notification_OnBlur) | Notifies when an application is blurred |

<a id="notification_onUserInactivity"></a>
## *onUserInactivity [<sup>notification</sup>](#head_Notifications)*

Posting the client is inactive state.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.minutes | number | mandatory | Notify how long user is inactive state |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onUserInactivity",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onUserInactivity",
  "params": {
    "minutes": 0.0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onUserInactivity``.

<a id="notification_onDisconnected"></a>
## *onDisconnected [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is disconnected.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory | The identifier of the disconnected application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDisconnected",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDisconnected",
  "params": {
    "client": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDisconnected``.

<a id="notification_onReady"></a>
## *onReady [<sup>notification</sup>](#head_Notifications)*

Posting the client for first frame ready.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.client | string | mandatory | Notify first frame event received for client or application instance ID |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onReady",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onReady",
  "params": {
    "client": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onReady``.

<a id="notification_onConnected"></a>
## *onConnected [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is connected.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appInstanceId | string | mandatory | The identifier of the connected application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onConnected",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onConnected",
  "params": {
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onConnected``.

<a id="notification_onVisible"></a>
## *onVisible [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is visible.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appInstanceId | string | mandatory | The identifier of the visible application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onVisible",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onVisible",
  "params": {
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onVisible``.

<a id="notification_OnHidden"></a>
## *OnHidden [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is hidden.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appInstanceId | string | mandatory | The identifier of the hidden application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "OnHidden",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.OnHidden",
  "params": {
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.OnHidden``.

<a id="notification_OnFocus"></a>
## *OnFocus [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is in focus.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appInstanceId | string | mandatory | The identifier of the focussed application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "OnFocus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.OnFocus",
  "params": {
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.OnFocus``.

<a id="notification_OnBlur"></a>
## *OnBlur [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is blurred.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.appInstanceId | string | mandatory | The identifier of the blurred application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "OnBlur",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.OnBlur",
  "params": {
    "appInstanceId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.OnBlur``.

