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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

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
| [addKeyIntercepts](#method_addKeyIntercepts) | Registers multiple key intercepts in a single operation for a specific client |
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
| [getVisibility](#method_getVisibility) | Gets the visibility of the given client or appInstanceId |
| [getLastKeyInfo](#method_getLastKeyInfo) | Retrieves information about the most recent key press event, including the key code, modifier flags, and the timestamp in seconds when the key was pressed |
| [setZOrder](#method_setZOrder) | Sets the zOrder of the given client or appInstanceId |
| [getZOrder](#method_getZOrder) | Gets the zOrder of the given client or appInstanceId |
| [startVncServer](#method_startVncServer) | Starts the VNC server |
| [stopVncServer](#method_stopVncServer) | Stops the VNC server |
| [getFocused](#method_getFocused) | Gets the identifier of the currently focused application |
| [getScreenshot](#method_getScreenshot) | Captures the entire screen buffer as Base64 encoded image data (PNG format) |
| [setAlias](#method_setAlias) | Sets the alias name for the given client identifier |
| [showSplashScreen](#method_showSplashScreen) | Shows or hides the splash screen in the window manager |
| [setBounds](#method_setBounds) | Sets the x, y position and width, height dimensions of the given client |
| [getBounds](#method_getBounds) | Gets the x, y position and width, height dimensions of the given client |
| [setScale](#method_setScale) | Sets the horizontal and vertical scale factors of the given client |
| [getScale](#method_getScale) | Gets the horizontal and vertical scale factors of the given client |

<a id="method_createDisplay"></a>
## *createDisplay [<sup>method</sup>](#head_Methods)*

Create the display window.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client identifier |
| params.displayName | string | mandatory | Name of Wayland display |
| params?.displayWidth | integer | optional | Optional width of client window |
| params?.displayHeight | integer | optional | Optional height of client window |
| params?.virtualDisplay | boolean | optional | Optional flag indicating whether virtual display is enabled |
| params?.virtualWidth | integer | optional | Optional width of display in framebuffer mode |
| params?.virtualHeight | integer | optional | Optional height of display in framebuffer mode |
| params?.ownerId | integer | optional | Optional UID of owner of Wayland socket |
| params?.groupId | integer | optional | Optional group identifier of Wayland socket |
| params?.topmost | boolean | optional | Optional flag indicating whether client window needs to be topmost |
| params?.focus | boolean | optional | Optional flag indicating whether the client needs focus |
| params?.capabilities | string | optional | Optional JSON string containing the runtime capability tokens for the client |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Display window created successfully |
| ```Core::ERROR_GENERAL``` | Failed to create the display window |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.createDisplay",
  "params": {
    "clientId": "...",
    "displayName": "...",
    "displayWidth": 0,
    "displayHeight": 0,
    "virtualDisplay": false,
    "virtualWidth": 0,
    "virtualHeight": 0,
    "ownerId": 0,
    "groupId": 0,
    "topmost": false,
    "focus": false,
    "capabilities": "..."
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
| result | array | mandatory | Returns the list of active app IDs as a JSON array |
| result[#] | string | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Active app IDs retrieved successfully |
| ```Core::ERROR_GENERAL``` | Failed to retrieve active app IDs |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getApps"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "..."
  ]
}
```

<a id="method_addKeyIntercept"></a>
## *addKeyIntercept [<sup>method</sup>](#head_Methods)*

Registers a key intercept for a specific key code and client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
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
  "method": "<callsign>.addKeyIntercept",
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

Registers multiple key intercepts in a single operation for a specific client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The client identifier |
| params.intercepts | string | mandatory | JSON String format containing the array of key intercepts (keyCode, modifiers, focusOnly, propagate) configuration |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | All provided key intercepts were registered successfully |
| ```Core::ERROR_GENERAL``` | A general error occurred while registering one or more key intercepts |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.addKeyIntercepts",
  "params": {
    "clientId": "...",
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
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The client identifier |
| params.keyCode | integer | mandatory | The key code to remove |
| params.modifiers | string | mandatory | JSON String format with one or more modifiers |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | The key intercept was removed successfully. |
| ```Core::ERROR_GENERAL``` | The intercept could not be removed due to an internal error. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.removeKeyIntercept",
  "params": {
    "clientId": "...",
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

<a id="method_addKeyListener"></a>
## *addKeyListener [<sup>method</sup>](#head_Methods)*

Registers listeners for specific keys.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
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
  "method": "<callsign>.addKeyListener",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.removeKeyListener",
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
| params | object | mandatory | *...* |
| params.keyCode | integer | mandatory | Key code to be injected, modifiers :  JSON String format with one or more modifiers |
| params.modifiers | string | mandatory | *...* |

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
  "method": "<callsign>.injectKey",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.generateKey",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.enableInactivityReporting",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.setInactivityInterval",
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
  "method": "<callsign>.resetInactivityTime"
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.enableKeyRepeats",
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
  "method": "<callsign>.getKeyRepeatsEnabled"
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.ignoreKeyInputs",
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
| params | object | mandatory | *...* |
| params.clients | string | mandatory | JSON String format with number of clients, enable:Flag to enable input events |
| params.enable | boolean | mandatory | *...* |

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
  "method": "<callsign>.enableInputEvents",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.keyRepeatConfig",
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
| params | object | mandatory | *...* |
| params.client | string | mandatory | *...* |

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
  "method": "<callsign>.setFocus",
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
| params | object | mandatory | *...* |
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
  "method": "<callsign>.setVisible",
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

<a id="method_getVisibility"></a>
## *getVisibility [<sup>method</sup>](#head_Methods)*

Gets the visibility of the given client or appInstanceId.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.client | string | mandatory | Client name or application instance ID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Boolean indicating the visibility status: `true` for visible, `false` for hide |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getVisibility",
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

<a id="method_getLastKeyInfo"></a>
## *getLastKeyInfo [<sup>method</sup>](#head_Methods)*

Retrieves information about the most recent key press event, including the key code, modifier flags, and the timestamp in seconds when the key was pressed.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.keyCode | integer | mandatory | Output parameter. The key code of the last pressed key |
| result.modifiers | integer | mandatory | Output parameter. The modifier flags |
| result.timestampInSeconds | integer | mandatory | Output parameter. The timestamp (in seconds) when the last key press occurred |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Successfully retrieved the last key press information. |
| ```Core::ERROR_UNAVAILABLE``` | No key press information is available. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getLastKeyInfo"
}
```

#### Response

```json
Failed to generate JSON example for getLastKeyInfo
```

<a id="method_setZOrder"></a>
## *setZOrder [<sup>method</sup>](#head_Methods)*

Sets the zOrder of the given client or appInstanceId.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |
| params.zOrder | integer | mandatory | Integer value indicating the zOrder |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setZOrder",
  "params": {
    "clientId": "...",
    "zOrder": 0
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

<a id="method_getZOrder"></a>
## *getZOrder [<sup>method</sup>](#head_Methods)*

Gets the zOrder of the given client or appInstanceId.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Integer value indicating the zOrder of the client |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getZOrder",
  "params": {
    "clientId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_startVncServer"></a>
## *startVncServer [<sup>method</sup>](#head_Methods)*

Starts the VNC server.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.startVncServer"
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

<a id="method_stopVncServer"></a>
## *stopVncServer [<sup>method</sup>](#head_Methods)*

Stops the VNC server.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.stopVncServer"
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

<a id="method_getFocused"></a>
## *getFocused [<sup>method</sup>](#head_Methods)*

Gets the identifier of the currently focused application.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Output parameter. The identifier of the currently focused application |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Successfully retrieved the focused application identifier |
| ```Core::ERROR_GENERAL``` | Failed to retrieve the focused application identifier |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFocused"
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

<a id="method_getScreenshot"></a>
## *getScreenshot [<sup>method</sup>](#head_Methods)*

Captures the entire screen buffer as Base64 encoded image data (PNG format). The screenshot is returned asynchronously via the onScreenshotComplete event.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | on success |
| ```Core::ERROR_GENERAL``` | on failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getScreenshot"
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

<a id="method_setAlias"></a>
## *setAlias [<sup>method</sup>](#head_Methods)*

Sets the alias name for the given client identifier.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client identifier |
| params.alias | string | mandatory | Alias name for the given client identifier |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Operation completed successfully |
| ```Core::ERROR_GENERAL``` | Operation failed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setAlias",
  "params": {
    "clientId": "...",
    "alias": "..."
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

<a id="method_showSplashScreen"></a>
## *showSplashScreen [<sup>method</sup>](#head_Methods)*

Shows or hides the splash screen in the window manager.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.show | boolean | mandatory | Boolean indicating whether to show (true) or hide (false) the splash screen |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Operation completed successfully |
| ```Core::ERROR_GENERAL``` | Operation failed |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.showSplashScreen",
  "params": {
    "show": false
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

<a id="method_setBounds"></a>
## *setBounds [<sup>method</sup>](#head_Methods)*

Sets the x, y position and width, height dimensions of the given client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |
| params.x | integer | mandatory | X coordinate of the client window |
| params.y | integer | mandatory | Y coordinate of the client window |
| params.width | integer | mandatory | Width of the client window in pixels |
| params.height | integer | mandatory | Height of the client window in pixels |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Bounds set successfully |
| ```Core::ERROR_GENERAL``` | Failed to set bounds |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setBounds",
  "params": {
    "clientId": "...",
    "x": 0,
    "y": 0,
    "width": 0,
    "height": 0
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

<a id="method_getBounds"></a>
## *getBounds [<sup>method</sup>](#head_Methods)*

Gets the x, y position and width, height dimensions of the given client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.x | integer | mandatory | X coordinate of the client window |
| result.y | integer | mandatory | Y coordinate of the client window |
| result.width | integer | mandatory | Width of the client window in pixels |
| result.height | integer | mandatory | Height of the client window in pixels |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Bounds retrieved successfully |
| ```Core::ERROR_GENERAL``` | Failed to get bounds |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBounds",
  "params": {
    "clientId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "x": 0,
    "y": 0,
    "width": 0,
    "height": 0
  }
}
```

<a id="method_setScale"></a>
## *setScale [<sup>method</sup>](#head_Methods)*

Sets the horizontal and vertical scale factors of the given client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |
| params.scaleX | number | mandatory | Horizontal scale factor |
| params.scaleY | number | mandatory | Vertical scale factor |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Scale set successfully |
| ```Core::ERROR_GENERAL``` | Failed to set scale |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setScale",
  "params": {
    "clientId": "...",
    "scaleX": 0.0,
    "scaleY": 0.0
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

<a id="method_getScale"></a>
## *getScale [<sup>method</sup>](#head_Methods)*

Gets the horizontal and vertical scale factors of the given client.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Client name or application instance ID |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.scaleX | number | mandatory | Horizontal scale factor |
| result.scaleY | number | mandatory | Vertical scale factor |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Scale retrieved successfully |
| ```Core::ERROR_GENERAL``` | Failed to get scale |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getScale",
  "params": {
    "clientId": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "scaleX": 0.0,
    "scaleY": 0.0
  }
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
| [onHidden](#notification_onHidden) | Notifies when an application is hidden |
| [onFocus](#notification_onFocus) | Notifies when an application is in focus |
| [onBlur](#notification_onBlur) | Notifies when an application is blurred |
| [onScreenshotComplete](#notification_onScreenshotComplete) | Notifies when a screenshot capture is complete |

<a id="notification_onUserInactivity"></a>
## *onUserInactivity [<sup>notification</sup>](#head_Notifications)*

Posting the client is inactive state.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.minutes | number | mandatory | Notify how long user is inactive state |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the disconnected application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "clientId": "..."
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
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | Notify first frame event received for client or application instance ID |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "clientId": "..."
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
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the connected application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "clientId": "..."
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
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the visible application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
    "clientId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onVisible``.

<a id="notification_onHidden"></a>
## *onHidden [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is hidden.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the hidden application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onHidden",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onHidden",
  "params": {
    "clientId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onHidden``.

<a id="notification_onFocus"></a>
## *onFocus [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is in focus.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the focussed application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFocus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFocus",
  "params": {
    "clientId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFocus``.

<a id="notification_onBlur"></a>
## *onBlur [<sup>notification</sup>](#head_Notifications)*

Notifies when an application is blurred.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.clientId | string | mandatory | The identifier of the blurred application |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onBlur",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onBlur",
  "params": {
    "clientId": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onBlur``.

<a id="notification_onScreenshotComplete"></a>
## *onScreenshotComplete [<sup>notification</sup>](#head_Notifications)*

Notifies when a screenshot capture is complete.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.success | boolean | mandatory | Indicates whether the screenshot was captured successfully |
| params.imageData | string | mandatory | Base64 encoded image data (PNG format) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onScreenshotComplete",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onScreenshotComplete",
  "params": {
    "success": false,
    "imageData": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onScreenshotComplete``.

