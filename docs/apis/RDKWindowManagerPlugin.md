<!-- Generated automatically, DO NOT EDIT! -->
<a name="RDKWindowManager_Plugin"></a>
# RDKWindowManager Plugin

**Version: [1.0.0]()**

A org.rdk.RDKWindowManager plugin for Thunder framework.

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

The `RDKWindowManager`plugin controls the management of composition, layout, Z order, and key handling.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.RDKWindowManager*) |
| classname | string | Class name: *org.rdk.RDKWindowManager* |
| locator | string | Library name: *libWPEFrameworkRDKWindowManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.RDKWindowManager plugin:

RDKWindowManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [addKeyIntercept](#addKeyIntercept) | Adds a key intercept to the client application specified |
| [addKeyIntercepts](#addKeyIntercepts) | Adds the list of key intercepts |
| [addKeyListener](#addKeyListener) | Adds a key listener to an application |
| [createDisplay](#createDisplay) |  Creates a display for the specified client using the configuration parameters |
| [enableInactivityReporting](#enableInactivityReporting) | Enables or disables inactivity reporting and events |
| [enableInputEvents](#enableInputEvents) | Enables KeyInputEvents for list of clients specified |
| [enableKeyRepeats](#enableKeyRepeats) | Enables or disables key repeats |
| [generateKey](#generateKey) | Triggers the key events (key press and release) |
| [getApps](#getApps) | Gets a list of active application IDs |
| [getKeyRepeatsEnabled](#getKeyRepeatsEnabled) | Returns whether key repeating is enabled or disabled |
| [ignoreKeyInputs](#ignoreKeyInputs) | Blocks user key inputs |
| [injectKey](#injectKey) | Injects the keys |
| [keyRepeatConfig](#keyRepeatConfig) | Configuration for keyrepeat |
| [removeKeyIntercept](#removeKeyIntercept) | Removes a key intercept |
| [removeKeyListener](#removeKeyListener) | Removes a key listener for an application |
| [resetInactivityTime](#resetInactivityTime) | Resets the inactivity notification interval |
| [setInactivityInterval](#setInactivityInterval) | Sets the inactivity notification interval |
| [setFocus](#setFocus) | Sets the focus to the specified app by app ID |
| [setVisible](#setVisible) | Sets the visibility of the specified client or application instance ID |
| [renderReady](#renderReady) | Returns whether the specified application has rendered its first frame |
| [enableDisplayRender](#enableDisplayRender) | Enables or disables the rendering of a Wayland display for the specified client or application instance |
| [setZOrder](#setZOrder) | Sets the z-order of the specified app |
| [getZOrder](#getZOrder) | Returns the z-order of the specified app |


<a name="addKeyIntercept"></a>
## *addKeyIntercept*

Adds a key intercept to the client application specified. The keys are specified by a key code and a set of modifiers. Regardless of the application that has focus, key presses that match the key code and modifiers will be sent to the client application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercept | string | A JSON String containing client, callSign (optional), keyCode and modifiers (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.addKeyIntercept",
    "params": {
        "intercept": "{\"client\":\"org.rdk.Netflix\",\"keyCode\":37,\"modifiers\":[\"shift\"]}"
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

<a name="addKeyIntercepts"></a>
## *addKeyIntercepts*

Adds the list of key intercepts.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercepts | string | A JSON String containing client, callSign (optional), keyCode and modifiers (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
    "params": {
        "intercepts": "{\"intercepts\":[{\"keys\":[{\"keyCode\": 37,\"modifiers\":[\"ctrl\",\"alt\"]},{\"keyCode\": 38,\"modifiers\":[\"shift\"]}],\"client\":\"org.rdk.Netflix\"}]}"
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

<a name="addKeyListener"></a>
## *addKeyListener*

Adds a key listener to an application. The keys are bubbled up based on their z-order.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyListeners | string | A JSON String containing keys(keyCode, nativekeyCode (optional), modifiers (optional), activate, propagate), client, callSign (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.addKeyListener",
    "params": {
        "keyListeners": "{\"keys\":[{\"keyCode\":37,\"modifiers\":[\"shift\"],\"activate\":false,\"propagate\":true}],\"client\":\"org.rdk.Netflix\"}"
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

<a name="createDisplay"></a>
## *createDisplay*

 Creates a display for the specified client using the configuration parameters.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayParams | string | A JSON String containing client, callSign (optional), displayName, displayWidth, displayHeight, virtualDisplay, virtualWidth, virtualHeight, topmost (optional), focus (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.createDisplay",
    "params": {
        "displayParams": "{\"client\":\"org.rdk.Netflix\",\"callsign\":\"org.rdk.Netflix\",\"displayName\":\"test\",\"displayWidth\":1920,\"displayHeight\":1080,\"virtualDisplay\":true,\"virtualWidth\":1920,\"virtualHeight\":1080,\"topmost\":false,\"focus\":false}"
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

<a name="enableInactivityReporting"></a>
## *enableInactivityReporting*

Enables or disables inactivity reporting and events.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | boolean | Whether to enable (`true`) or disable (`false`) inactivity reporting |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.enableInactivityReporting",
    "params": {
        "enable": true
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

<a name="enableInputEvents"></a>
## *enableInputEvents*

Enables KeyInputEvents for list of clients specified.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clients | string | A JSON String containing one or more clients |
| params.enable | boolean | enable:Flag to enable input events |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.enableInputEvents",
    "params": {
        "clients": "{\"clients\":[\"org.rdk.Netflix\"]}",
        "enable": true
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

<a name="enableKeyRepeats"></a>
## *enableKeyRepeats*

Enables or disables key repeats.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | boolean | Whether to enable (`true`) or disable (`false`) key repeats |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.enableKeyRepeats",
    "params": {
        "enable": true
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

<a name="generateKey"></a>
## *generateKey*

Triggers the key events (key press and release).

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | string | A JSON String containing keyCode, modifiers (optional), delay |
| params?.client | string | <sup>*(optional)*</sup> The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.generateKey",
    "params": {
        "keys": "{\"keys\": [{\"keyCode\":37,\"modifiers\":[\"shift\"],\"delay\":1}]}",
        "client": "org.rdk.Netflix"
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

<a name="getApps"></a>
## *getApps*

Gets a list of active application IDs.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | A JSON String containing one or more application IDs |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.getApps"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "{\"appIds\":[\"org.rdk.Netflix\"]}"
}
```

<a name="getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled*

Returns whether key repeating is enabled or disabled.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keyRepeat | boolean | `true` if enabled, otherwise `false` |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.getKeyRepeatsEnabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "keyRepeat": true
    }
}
```

<a name="ignoreKeyInputs"></a>
## *ignoreKeyInputs*

Blocks user key inputs.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ignore | boolean | Whether key inputs are ignored |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.ignoreKeyInputs",
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

<a name="injectKey"></a>
## *injectKey*

Injects the keys.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keycode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params?.modifiers | string | <sup>*(optional)*</sup> A JSON String containing one or more modifiers (`ctrl`, `alt`, and `shift` are supported) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.injectKey",
    "params": {
        "keycode": 37,
        "modifiers": "{\"modifiers\":[\"ctrl\",\"alt\"]}"
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

<a name="keyRepeatConfig"></a>
## *keyRepeatConfig*

Configuration for keyrepeat.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | Input type (default/keyboard) |
| params.keyConfig | string | A JSON String containing enabled, initialDelay (in milli seconds) and repeatInterval (in milli seconds) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.keyRepeatConfig",
    "params": {
        "input": "default",
        "keyConfig": "{\"enabled\":true,\"initialDelay\":500,\"repeatInterval\":100}"
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

<a name="removeKeyIntercept"></a>
## *removeKeyIntercept*

Removes a key intercept.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercept | string | A JSON String containing client, callSign (optional), keyCode and modifiers (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.removeKeyIntercept",
    "params": {
        "intercept": "{\"client\":\"org.rdk.Netflix\",\"keyCode\":37,\"modifiers\":[\"shift\"]}"
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

<a name="removeKeyListener"></a>
## *removeKeyListener*

Removes a key listener for an application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyListeners | string | A JSON String containing keys(keyCode, nativekeyCode (optional), modifiers (optional), activate, propagate), client, callSign (optional) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.removeKeyListener",
    "params": {
        "keyListeners": "{\"keys\":[{\"keyCode\":37,\"modifiers\":[\"ctrl\",\"alt\"]},{\"keyCode\":38,\"modifiers\":[\"ctrl\",\"alt\"]}],\"client\":\"org.rdk.Netflix\"}"
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

<a name="resetInactivityTime"></a>
## *resetInactivityTime*

Resets the inactivity notification interval.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.resetInactivityTime"
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

<a name="setInactivityInterval"></a>
## *setInactivityInterval*

Sets the inactivity notification interval.

### Events

| Event | Description |
| :-------- | :-------- |
| [onUserInactivity](#onUserInactivity) | Triggers only if the device is inactive for the specified time interval |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.interval | integer | The inactivity event interval in minutes |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.setInactivityInterval",
    "params": {
        "interval": 15
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

<a name="setFocus"></a>
## *setFocus*

Sets the focus to the specified app by app ID.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.setFocus",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
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

<a name="setVisible"></a>
## *setVisible*

Sets the visibility of the specified client or application instance ID.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |
| params.visible | boolean | Whether the client is visible (`true`) or not (`false`) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.setVisible",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193",
        "visible": true
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

<a name="renderReady"></a>
## *renderReady*

Returns whether the specified application has rendered its first frame.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | boolean | Returns true if the application has rendered its first frame, false if it has not |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.renderReady",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "status": true
    }
}
```

<a name="enableDisplayRender"></a>
## *enableDisplayRender*

Enables or disables the rendering of a Wayland display for the specified client or application instance.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |
| params.enable | boolean | Boolean flag to enable (`true`) or disable (`false`) the Wayland display render |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.enableDisplayRender",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193",
        "enable": true
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

<a name="setZOrder"></a>
## *setZOrder*

Sets the z-order of the specified app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |
| params.zOrder | integer | The desired z-order value (integer) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | null on success |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.setZOrder",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193",
        "zOrder": 5
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

<a name="getZOrder"></a>
## *getZOrder*

Returns the z-order of the specified app.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.zOrder | integer | The desired z-order value (integer) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKWindowManager.getZOrder",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "zOrder": 5
    }
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.RDKWindowManager plugin:

RDKWindowManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onUserInactivity](#onUserInactivity) | Triggered when a device has been inactive for a period of time |
| [onDisconnected](#onDisconnected) | Triggered when an app is disconnected from a Wayland display |
| [onReady](#onReady) | Triggered when an app has made its first graphics visible on a Wayland display |
| [onConnected](#onConnected) | Triggered when an app is connected to a Wayland display |
| [onVisible](#onVisible) | Sent when the app becomes visible |
| [onHidden](#onHidden) | Sent when the app becomes visible |
| [onFocus](#onFocus) | Sent when the app receives focus |
| [onBlur](#onBlur) | Sent when the app removes focus |


<a name="onUserInactivity"></a>
## *onUserInactivity*

Triggered when a device has been inactive for a period of time. This event is broadcasted at the frequency specified by `setInactivityInterval` if the device is not active. The default frequency is 15 minutes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.minutes | number | The number of minutes that the device has been inactive |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onUserInactivity",
    "params": {
        "minutes": 5
    }
}
```

<a name="onDisconnected"></a>
## *onDisconnected*

Triggered when an app is disconnected from a Wayland display.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDisconnected",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onReady"></a>
## *onReady*

Triggered when an app has made its first graphics visible on a Wayland display.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onReady",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onConnected"></a>
## *onConnected*

Triggered when an app is connected to a Wayland display.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onConnected",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onVisible"></a>
## *onVisible*

Sent when the app becomes visible.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onVisible",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onHidden"></a>
## *onHidden*

Sent when the app becomes visible.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onHidden",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onFocus"></a>
## *onFocus*

Sent when the app receives focus.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFocus",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```

<a name="onBlur"></a>
## *onBlur*

Sent when the app removes focus.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | The application instance ID for an app |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onBlur",
    "params": {
        "appInstanceId": "rdkwmtestapp_13193"
    }
}
```
    
