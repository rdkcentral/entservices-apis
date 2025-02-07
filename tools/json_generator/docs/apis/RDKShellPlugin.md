<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.RDKShell_Plugin"></a>
# RDKShell Plugin

**Version: [1.0.0]()**

A org.rdk.RDKShell plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `RDKShell` plugin controls the management of composition, layout, Z order, and key handling.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.RDKShell*) |
| classname | string | Class name: *org.rdk.RDKShell* |
| locator | string | Library name: *libWPEFrameworkRDKShell.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.RDKShell plugin:

RDKShell interface methods:

| Method | Description |
| :-------- | :-------- |
| [addAnimation](#method.addAnimation) | Performs the set of animations |
| [addKeyIntercept](#method.addKeyIntercept) | Adds a key intercept to the client application specified |
| [addKeyIntercepts](#method.addKeyIntercepts) | Adds the list of key intercepts |
| [addKeyListener](#method.addKeyListener) | Adds a key listener to an application |
| [addKeyMetadataListener](#method.addKeyMetadataListener) | Adds the key metadata listeners |
| [createDisplay](#method.createDisplay) |  Creates a display for the specified client using the configuration parameters |
| [destroy](#method.destroy) | Destroys an application |
| [enableInactivityReporting](#method.enableInactivityReporting) | Enables or disables inactivity reporting and events |
| [enableKeyRepeats](#method.enableKeyRepeats) | Enables or disables key repeats |
| [enableLogsFlushing](#method.enableLogsFlushing) | Enables or disables flushing all logs |
| [enableVirtualDisplay](#method.enableVirtualDisplay) | Enables or disables a virtual display for the specified client |
| [generateKey](#method.generateKey) | Triggers the key events (key press and release) |
| [getAvailableTypes](#method.getAvailableTypes) | Returns the list of application types available on the firmware |
| [getBounds](#method.getBounds) | Gets the bounds of the specified client |
| [getClients](#method.getClients) | Gets a list of clients |
| [getCursorSize](#method.getCursorSize) | Returns the currently set cursor size |
| [getHolePunch](#method.getHolePunch) | Returns whether video hole punching is enabled or disabled for the specified client |
| [getKeyRepeatsEnabled](#method.getKeyRepeatsEnabled) | Returns whether key repeating is enabled or disabled |
| [getLastWakeupKey](#method.getLastWakeupKey) | Returns the last key press prior to a device wakeup |
| [getLogLevel](#method.getLogLevel) | Returns the currently set logging level |
| [getLogsFlushingEnabled](#method.getLogsFlushingEnabled) | Returns whether log flushing is enabled or disabled |
| [getOpacity](#method.getOpacity) | Gets the opacity of the specified client |
| [getScale](#method.getScale) | Returns the scale of an application |
| [getScreenResolution](#method.getScreenResolution) | Gets the screen resolution |
| [getScreenshot](#method.getScreenshot) | Captures a screenshot |
| [getState](#method.getState) | Returns the state of all applications |
| [getSystemMemory](#method.getSystemMemory) | Gets the information of System Memory |
| [getSystemResourceInfo](#method.getSystemResourceInfo) | Returns system resource information about each application |
| [getVirtualDisplayEnabled](#method.getVirtualDisplayEnabled) | Returns whether virtual display is enabled or disabled for the specified client |
| [getVirtualResolution](#method.getVirtualResolution) | Returns the virtual display resolution for the specified client |
| [getVisibility](#method.getVisibility) | Gets the visibility of the specified client |
| [getZOrder](#method.getZOrder) | Returns an array of clients in Z order, starting with the top most application client first |
| [getGraphicsFrameRate](#method.getGraphicsFrameRate) | Returns the current Graphics Frame Rate |
| [hideAllClients](#method.hideAllClients) | Hides/Unhides all the clients |
| [hideCursor](#method.hideCursor) | Hides the cursor from showing on the display |
| [hideFullScreenImage](#method.hideFullScreenImage) | Hides the Full Screen Image |
| [hideSplashLogo](#method.hideSplashLogo) | Removes the splash screen |
| [ignoreKeyInputs](#method.ignoreKeyInputs) | Blocks user key inputs |
| [injectKey](#method.injectKey) | Injects the keys |
| [kill](#method.kill) | Kills the specified client |
| [launch](#method.launch) | Launches an application |
| [launchApplication](#method.launchApplication) | Launches an application |
| [launchResidentApp](#method.launchResidentApp) | Launches the Resident application |
| [moveBehind](#method.moveBehind) | Moves the specified client behind the specified target client |
| [moveToBack](#method.moveToBack) | Moves the specified client to the back or bottom of the Z order |
| [moveToFront](#method.moveToFront) | Moves the specified client to the front or top of the Z order |
| [removeAllKeyIntercepts](#method.removeAllKeyIntercepts) | Removes all key intercepts |
| [removeAllKeyListeners](#method.removeAllKeyListeners) | Removes all key listeners |
| [removeAnimation](#method.removeAnimation) | Removes the current animation for the specified client |
| [removeKeyIntercept](#method.removeKeyIntercept) | Removes a key intercept |
| [removeKeyListener](#method.removeKeyListener) | Removes a key listener for an application |
| [removeKeyMetadataListener](#method.removeKeyMetadataListener) | Removes the key metadata listeners |
| [resetInactivityTime](#method.resetInactivityTime) | Resets the inactivity notification interval |
| [resumeApplication](#method.resumeApplication) | Resumes an application |
| [scaleToFit](#method.scaleToFit) | Scales the specified client to fit the current bounds |
| [setBounds](#method.setBounds) | Sets the bounds of the specified client |
| [setCursorSize](#method.setCursorSize) | Sets the cursor size |
| [setFocus](#method.setFocus) | Sets focus to the specified client |
| [setHolePunch](#method.setHolePunch) | Enables or disables video hole punching for the specified client |
| [setInactivityInterval](#method.setInactivityInterval) | Sets the inactivity notification interval |
| [setLogLevel](#method.setLogLevel) | Sets the logging level |
| [setMemoryMonitor](#method.setMemoryMonitor) | Enables or disables RAM memory monitoring on the device |
| [setOpacity](#method.setOpacity) | Sets the opacity of the specified client |
| [setScale](#method.setScale) | Scales an application |
| [setScreenResolution](#method.setScreenResolution) | Sets the screen resolution |
| [setTopmost](#method.setTopmost) | Sets whether the specified client appears above all other clients on the display |
| [setVirtualResolution](#method.setVirtualResolution) | Sets the virtual resolution for the specified client |
| [setVisibility](#method.setVisibility) | Sets whether the specified client should be visible |
| [setGraphicsFrameRate](#method.setGraphicsFrameRate) | Set Graphics Frame Rate |
| [showCursor](#method.showCursor) | Shows the cursor on the display using the current cursor size |
| [showFullScreenImage](#method.showFullScreenImage) | Shows the Full Screen Image |
| [showSplashLogo](#method.showSplashLogo) | Displays the splash screen |
| [showWatermark](#method.showWatermark) | Sets whether a watermark shows on the display |
| [suspend](#method.suspend) | Suspends an application |
| [suspendApplication](#method.suspendApplication) | Suspends an application |
| [keyRepeatConfig](#method.keyRepeatConfig) | Customizes key repeats |
| [setAVBlocked](#method.setAVBlocked) | adds/removes the list of applications with the given callsigns to/from the blacklist |
| [getBlockedAVApplications](#method.getBlockedAVApplications) | Gets a list of blacklisted clients |


<a name="method.addAnimation"></a>
## *addAnimation [<sup>method</sup>](#head.Methods)*

Performs the set of animations.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.animations | array | A list of animations to perform |
| params.animations[#] | object |  |
| params.animations[#].client | string | The client name |
| params.animations[#]?.x | number | <sup>*(optional)*</sup> The x location |
| params.animations[#]?.y | number | <sup>*(optional)*</sup> The y location |
| params.animations[#]?.w | number | <sup>*(optional)*</sup> The width |
| params.animations[#]?.h | number | <sup>*(optional)*</sup> The height |
| params.animations[#]?.sx | number | <sup>*(optional)*</sup> The x scale factor |
| params.animations[#]?.sy | number | <sup>*(optional)*</sup> The y scale factor |
| params.animations[#]?.a | number | <sup>*(optional)*</sup> The alpha/opacity level to animate to (between 0 and 100) |
| params.animations[#]?.duration | number | <sup>*(optional)*</sup> The duration of the animation in seconds |
| params.animations[#]?.tween | string | <sup>*(optional)*</sup> The animation tween type. The default is `linear` (must be one of the following: *linear*, *exp1*, *exp2*, *exp3*, *inquad*, *incubic*, *nback*, *inelastic*, *outelastic*, *outbounce*) |
| params.animations[#]?.delay | number | <sup>*(optional)*</sup> Set delay for an animation |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.addAnimation",
    "params": {
        "animations": [
            {
                "client": "org.rdk.Netflix",
                "x": 0,
                "y": 0,
                "w": 1920,
                "h": 1080,
                "sx": 0.5,
                "sy": 0.5,
                "a": 0,
                "duration": 2,
                "tween": "exp1",
                "delay": 0
            }
        ]
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

<a name="method.addKeyIntercept"></a>
## *addKeyIntercept [<sup>method</sup>](#head.Methods)*

Adds a key intercept to the client application specified. The keys are specified by a key code and a set of modifiers. Regardless of the application that has focus, key presses that match the key code and modifiers will be sent to the client application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.modifiers[#] | string |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.addKeyIntercept",
    "params": {
        "keyCode": 10,
        "modifiers": [
            "shift"
        ],
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.addKeyIntercepts"></a>
## *addKeyIntercepts [<sup>method</sup>](#head.Methods)*

Adds the list of key intercepts.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercepts | array | A list of intercepts |
| params.intercepts[#] | object |  |
| params.intercepts[#].client | string | The client name |
| params.intercepts[#].keys | array | A list of keys to simulate |
| params.intercepts[#].keys[#] | object |  |
| params.intercepts[#].keys[#].keycode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.intercepts[#].keys[#].modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.intercepts[#].keys[#].modifiers[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.addKeyIntercepts",
    "params": {
        "intercepts": [
            {
                "client": "searchanddiscovery",
                "keys": [
                    {
                        "keycode": 10,
                        "modifiers": [
                            "shift"
                        ]
                    }
                ]
            }
        ]
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

<a name="method.addKeyListener"></a>
## *addKeyListener [<sup>method</sup>](#head.Methods)*

Adds a key listener to an application. The keys are bubbled up based on their z-order.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.keys | array | A list of keys on which to add a listener for the specified application |
| params.keys[#] | object |  |
| params.keys[#].keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.keys[#]?.nativekeyCode | number | <sup>*(optional)*</sup> The native key code |
| params.keys[#].modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.keys[#].modifiers[#] | string |  |
| params.keys[#].activate | boolean | Activate an application on key event. The default is `false` |
| params.keys[#].propagate | boolean | Propagate to the next application in the z-order. The default is `true` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.addKeyListener",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "keys": [
            {
                "keyCode": 10,
                "nativekeyCode": 10,
                "modifiers": [
                    "shift"
                ],
                "activate": false,
                "propagate": true
            }
        ]
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

<a name="method.addKeyMetadataListener"></a>
## *addKeyMetadataListener [<sup>method</sup>](#head.Methods)*

Adds the key metadata listeners.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.addKeyMetadataListener",
    "params": {
        "client": "searchanddiscovery",
        "callsign": "searchanddiscovery"
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

<a name="method.createDisplay"></a>
## *createDisplay [<sup>method</sup>](#head.Methods)*

 Creates a display for the specified client using the configuration parameters.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.displayName | string | A name for the display |
| params.displayWidth | number | The width of the display |
| params.displayHeight | number | The height of the display |
| params.virtualDisplay | boolean | Whether to create a virtual display (`true`) or not (`false`) |
| params.virtualWidth | number | The width of the virtual display |
| params.virtualHeight | number | The height of the virtual display |
| params?.topmost | boolean | <sup>*(optional)*</sup> Whether to set topmost (true) or not (false) |
| params?.focus | boolean | <sup>*(optional)*</sup> Whether to setfocus (true) or not (false) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.createDisplay",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "displayName": "test",
        "displayWidth": 1920,
        "displayHeight": 1080,
        "virtualDisplay": true,
        "virtualWidth": 1920,
        "virtualHeight": 1080,
        "topmost": false,
        "focus": false
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

<a name="method.destroy"></a>
## *destroy [<sup>method</sup>](#head.Methods)*

Destroys an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onDestroyed](#event.onDestroyed) | Triggers when a runtime is successfully destroyed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.destroy",
    "params": {
        "callsign": "Cobalt"
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

<a name="method.enableInactivityReporting"></a>
## *enableInactivityReporting [<sup>method</sup>](#head.Methods)*

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
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.enableInactivityReporting",
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
    "result": {
        "success": true
    }
}
```

<a name="method.enableKeyRepeats"></a>
## *enableKeyRepeats [<sup>method</sup>](#head.Methods)*

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
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.enableKeyRepeats",
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
    "result": {
        "success": true
    }
}
```

<a name="method.enableLogsFlushing"></a>
## *enableLogsFlushing [<sup>method</sup>](#head.Methods)*

Enables or disables flushing all logs.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | boolean | Whether to enable (`true`) or disable (`false`) log flushing |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.enableLogsFlushing",
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
    "result": {
        "success": true
    }
}
```

<a name="method.enableVirtualDisplay"></a>
## *enableVirtualDisplay [<sup>method</sup>](#head.Methods)*

Enables or disables a virtual display for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.enable | boolean | Whether to enable (`true`) or disable (`false`) a virtual display |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.enableVirtualDisplay",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "enable": true
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

<a name="method.generateKey"></a>
## *generateKey [<sup>method</sup>](#head.Methods)*

Triggers the key events (key press and release).

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | array | A list of keys to simulate |
| params.keys[#] | object |  |
| params.keys[#].keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.keys[#].modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.keys[#].modifiers[#] | string |  |
| params.keys[#].delay | number | The amount of time to wait (in seconds) before sending the key event |
| params.keys[#]?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.keys[#]?.client | string | <sup>*(optional)*</sup> The client name can be used instead of callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.generateKey",
    "params": {
        "keys": [
            {
                "keyCode": 10,
                "modifiers": [
                    "shift"
                ],
                "delay": 1.0,
                "callsign": "Cobalt",
                "client": "Cobalt"
            }
        ]
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

<a name="method.getAvailableTypes"></a>
## *getAvailableTypes [<sup>method</sup>](#head.Methods)*

Returns the list of application types available on the firmware.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.types | array | application types |
| result.types[#] | string |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getAvailableTypes"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "types": [
            "HtmlBrowser"
        ],
        "success": true
    }
}
```

<a name="method.getBounds"></a>
## *getBounds [<sup>method</sup>](#head.Methods)*

Gets the bounds of the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.bounds | object |  |
| result.bounds.x | number | The x location |
| result.bounds.y | number | The y location |
| result.bounds.w | number | The width |
| result.bounds.h | number | The height |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getBounds",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "bounds": {
            "x": 0,
            "y": 0,
            "w": 1920,
            "h": 1080
        },
        "success": true
    }
}
```

<a name="method.getClients"></a>
## *getClients [<sup>method</sup>](#head.Methods)*

Gets a list of clients.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clients | array | A list of clients |
| result.clients[#] | string |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getClients"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clients": [
            "org.rdk.Netflix"
        ],
        "success": true
    }
}
```

<a name="method.getCursorSize"></a>
## *getCursorSize [<sup>method</sup>](#head.Methods)*

Returns the currently set cursor size.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.width | number | The cursor width |
| result.height | number | The cursor height |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getCursorSize"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "width": 255,
        "height": 255,
        "success": true
    }
}
```

<a name="method.getHolePunch"></a>
## *getHolePunch [<sup>method</sup>](#head.Methods)*

Returns whether video hole punching is enabled or disabled for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.holePunch | boolean | Whether hole punching is enabled (`true`) or disabled (`false`) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getHolePunch",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "holePunch": true,
        "success": true
    }
}
```

<a name="method.getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled [<sup>method</sup>](#head.Methods)*

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
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getKeyRepeatsEnabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "keyRepeat": true,
        "success": true
    }
}
```

<a name="method.getLastWakeupKey"></a>
## *getLastWakeupKey [<sup>method</sup>](#head.Methods)*

Returns the last key press prior to a device wakeup.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| result.modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| result.modifiers[#] | string |  |
| result.timestampInSeconds | boolean | The time, in seconds, of the last wakeup |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getLastWakeupKey"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "keyCode": 10,
        "modifiers": [
            "shift"
        ],
        "timestampInSeconds": true,
        "success": true
    }
}
```

<a name="method.getLogLevel"></a>
## *getLogLevel [<sup>method</sup>](#head.Methods)*

Returns the currently set logging level.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.logLevel | string | The log level (must be one of the following: *DEBUG*, *INFO*, *WARN*, *ERROR*, *FATAL*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getLogLevel"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "logLevel": "INFO",
        "success": true
    }
}
```

<a name="method.getLogsFlushingEnabled"></a>
## *getLogsFlushingEnabled [<sup>method</sup>](#head.Methods)*

Returns whether log flushing is enabled or disabled.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | boolean | `true` if enabled, otherwise `false` |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getLogsFlushingEnabled"
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

<a name="method.getOpacity"></a>
## *getOpacity [<sup>method</sup>](#head.Methods)*

Gets the opacity of the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer | The opacity level (between 0 and 100) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getOpacity",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "opacity": 100,
        "success": true
    }
}
```

<a name="method.getScale"></a>
## *getScale [<sup>method</sup>](#head.Methods)*

Returns the scale of an application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sx | string | The x scale factor |
| result.sy | string | The y scale factor |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getScale",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "sx": "0.5",
        "sy": "0.5",
        "success": true
    }
}
```

<a name="method.getScreenResolution"></a>
## *getScreenResolution [<sup>method</sup>](#head.Methods)*

Gets the screen resolution.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.w | number | The width |
| result.h | number | The height |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getScreenResolution"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "w": 1920,
        "h": 1080,
        "success": true
    }
}
```

<a name="method.getScreenshot"></a>
## *getScreenshot [<sup>method</sup>](#head.Methods)*

Captures a screenshot.

### Events

| Event | Description |
| :-------- | :-------- |
| [onScreenshotComplete](#event.onScreenshotComplete) | Triggers when a screenshot is captured successfully |
### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getScreenshot"
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

<a name="method.getState"></a>
## *getState [<sup>method</sup>](#head.Methods)*

Returns the state of all applications.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.runtimes | array | A list of apps and their current state |
| result.runtimes[#] | object |  |
| result.runtimes[#].callsign | string | The application callsign |
| result.runtimes[#].state | string | The runtime state of the app |
| result.runtimes[#].uri | string | The URI of the app (empty, if unable to get URI status) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "runtimes": [
            {
                "callsign": "Cobalt",
                "state": "suspended",
                "uri": "https://..."
            }
        ],
        "success": true
    }
}
```

<a name="method.getSystemMemory"></a>
## *getSystemMemory [<sup>method</sup>](#head.Methods)*

Gets the information of System Memory.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.freeRam | number | Free RAM memory (kB) |
| result.swapRam | number | Swap memory (kB) |
| result.totalRam | number | Total RAM memory (kB) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getSystemMemory"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "freeRam": 321944,
        "swapRam": 0,
        "totalRam": 624644,
        "success": true
    }
}
```

<a name="method.getSystemResourceInfo"></a>
## *getSystemResourceInfo [<sup>method</sup>](#head.Methods)*

Returns system resource information about each application.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.types | array | A list of apps and their system resource information |
| result.types[#] | object |  |
| result.types[#].callsign | string | The application callsign |
| result.types[#].ram | integer | The amount of memory the runtime is consuming in kb |
| result.types[#].vram | integer | The amount of graphics memory the runtime is consuming in kb (if supported) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getSystemResourceInfo"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "types": [
            {
                "callsign": "Cobalt",
                "ram": 123,
                "vram": 50
            }
        ],
        "success": true
    }
}
```

<a name="method.getVirtualDisplayEnabled"></a>
## *getVirtualDisplayEnabled [<sup>method</sup>](#head.Methods)*

Returns whether virtual display is enabled or disabled for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | boolean | `true` if a virtual display is enabled, otherwise `false` |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getVirtualDisplayEnabled",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
    }
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

<a name="method.getVirtualResolution"></a>
## *getVirtualResolution [<sup>method</sup>](#head.Methods)*

Returns the virtual display resolution for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.w | number | The width |
| result.h | number | The height |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getVirtualResolution",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "w": 1920,
        "h": 1080,
        "success": true
    }
}
```

<a name="method.getVisibility"></a>
## *getVisibility [<sup>method</sup>](#head.Methods)*

Gets the visibility of the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.visible | boolean | Whether the client is visible (`true`) or not (`false`) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getVisibility",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "visible": true,
        "success": true
    }
}
```

<a name="method.getZOrder"></a>
## *getZOrder [<sup>method</sup>](#head.Methods)*

Returns an array of clients in Z order, starting with the top most application client first.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clients | array | A list of clients |
| result.clients[#] | string |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getZOrder"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clients": [
            "org.rdk.Netflix"
        ],
        "success": true
    }
}
```

<a name="method.getGraphicsFrameRate"></a>
## *getGraphicsFrameRate [<sup>method</sup>](#head.Methods)*

Returns the current Graphics Frame Rate.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.frameRate | number | display the current Graphics framerate |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getGraphicsFrameRate"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "frameRate": 40,
        "success": true
    }
}
```

<a name="method.hideAllClients"></a>
## *hideAllClients [<sup>method</sup>](#head.Methods)*

Hides/Unhides all the clients.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hide | boolean | true to hide all the clients, and false to unhide all the clients |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.hideAllClients",
    "params": {
        "hide": true
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

<a name="method.hideCursor"></a>
## *hideCursor [<sup>method</sup>](#head.Methods)*

Hides the cursor from showing on the display. The cursor is hidden by default.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.hideCursor"
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

<a name="method.hideFullScreenImage"></a>
## *hideFullScreenImage [<sup>method</sup>](#head.Methods)*

Hides the Full Screen Image.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.hideFullScreenImage"
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

<a name="method.hideSplashLogo"></a>
## *hideSplashLogo [<sup>method</sup>](#head.Methods)*

Removes the splash screen.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.hideSplashLogo"
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

<a name="method.ignoreKeyInputs"></a>
## *ignoreKeyInputs [<sup>method</sup>](#head.Methods)*

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
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.ignoreKeyInputs",
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
    "result": {
        "success": true
    }
}
```

<a name="method.injectKey"></a>
## *injectKey [<sup>method</sup>](#head.Methods)*

Injects the keys.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keycode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.modifiers[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.injectKey",
    "params": {
        "keycode": 10,
        "modifiers": [
            "shift"
        ]
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

<a name="method.kill"></a>
## *kill [<sup>method</sup>](#head.Methods)*

Kills the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.kill",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.launch"></a>
## *launch [<sup>method</sup>](#head.Methods)*

Launches an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onLaunched](#event.onLaunched) | Triggers when the runtime of an application is launched successfull |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The application callsign |
| params.type | string | The ID of the runtime package or the callsign of the plugin desired to be cloned |
| params?.version | string | <sup>*(optional)*</sup> The version of the package. Defaults to the latest version |
| params.uri | string | The URI of the app (empty, if unable to get URI status) |
| params?.x | number | <sup>*(optional)*</sup> The x location |
| params?.y | number | <sup>*(optional)*</sup> The y location |
| params?.w | number | <sup>*(optional)*</sup> The width |
| params?.h | number | <sup>*(optional)*</sup> The height |
| params?.suspend | boolean | <sup>*(optional)*</sup> Whether to suspend the app on launch (`true`) or not (`false`). Default is `false` |
| params?.visible | boolean | <sup>*(optional)*</sup> Whether the app is visible on launch (`true`) or not (`false`). Default is `true`. The value will be `false` if the `suspend` argument is `true` |
| params?.focused | boolean | <sup>*(optional)*</sup> Whether the app is focused on launch (`true`) or not (`false`). Default is `true`. The app cannot be focused if the `visible` argument is set to `false` |
| params?.configuration | string | <sup>*(optional)*</sup> The plugin configuration overrides. Empty by default |
| params?.behind | string | <sup>*(optional)*</sup> The client to put behind. Defaults to top of z-order |
| params?.displayName | string | <sup>*(optional)*</sup> A name for the display |
| params?.scaleToFit | boolean | <sup>*(optional)*</sup> Whether the app can be scaled to fit the current bounds. Default is `false` |
| params?.holePunch | boolean | <sup>*(optional)*</sup> Whether the video hole punching can be enabled for the client. Default is `true` |
| params?.topmost | boolean | <sup>*(optional)*</sup> Whether the app appears above all other apps on the display. Default is `false` |
| params?.focus | boolean | <sup>*(optional)*</sup> Whether the app should be under focus. Default is `false` |
| params?.autodestroy | boolean | <sup>*(optional)*</sup> Whether the application can be automatically destroyed. Default is `true` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.launchType | string | The launch type of client |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.launch",
    "params": {
        "callsign": "Cobalt",
        "type": "HtmlApp",
        "version": "1.0",
        "uri": "https://...",
        "x": 0,
        "y": 0,
        "w": 1920,
        "h": 1080,
        "suspend": false,
        "visible": true,
        "focused": true,
        "configuration": "...",
        "behind": "...",
        "displayName": "test",
        "scaleToFit": false,
        "holePunch": false,
        "topmost": false,
        "focus": false,
        "autodestroy": false
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "launchType": "activate",
        "success": true
    }
}
```

<a name="method.launchApplication"></a>
## *launchApplication [<sup>method</sup>](#head.Methods)*

Launches an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onApplicationLaunched](#event.onApplicationLaunched) | Triggers when an application is launched successfully |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params.uri | string | The client uri |
| params.mimeType | string | The mime type |
| params?.topmost | boolean | <sup>*(optional)*</sup> true to put the application at the top, otherwise false |
| params?.focus | boolean | <sup>*(optional)*</sup> true to put the application above all other applications, otherwise false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.launchApplication",
    "params": {
        "client": "HtmlApp",
        "uri": "https://x1box-app.xumo.com/3.0.70/index.html%22",
        "mimeType": "application/native",
        "topmost": true,
        "focus": true
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

<a name="method.launchResidentApp"></a>
## *launchResidentApp [<sup>method</sup>](#head.Methods)*

Launches the Resident application.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.launchResidentApp"
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

<a name="method.moveBehind"></a>
## *moveBehind [<sup>method</sup>](#head.Methods)*

Moves the specified client behind the specified target client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params.target | string | The target in which the client moves behind |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.moveBehind",
    "params": {
        "client": "org.rdk.Netflix",
        "target": "org.rdk.RDKBrowser2"
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

<a name="method.moveToBack"></a>
## *moveToBack [<sup>method</sup>](#head.Methods)*

Moves the specified client to the back or bottom of the Z order.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.moveToBack",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.moveToFront"></a>
## *moveToFront [<sup>method</sup>](#head.Methods)*

Moves the specified client to the front or top of the Z order.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.moveToFront",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.removeAllKeyIntercepts"></a>
## *removeAllKeyIntercepts [<sup>method</sup>](#head.Methods)*

Removes all key intercepts.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeAllKeyIntercepts"
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

<a name="method.removeAllKeyListeners"></a>
## *removeAllKeyListeners [<sup>method</sup>](#head.Methods)*

Removes all key listeners.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeAllKeyListeners"
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

<a name="method.removeAnimation"></a>
## *removeAnimation [<sup>method</sup>](#head.Methods)*

Removes the current animation for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeAnimation",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.removeKeyIntercept"></a>
## *removeKeyIntercept [<sup>method</sup>](#head.Methods)*

Removes a key intercept.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.modifiers[#] | string |  |
| params.client | string | The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeKeyIntercept",
    "params": {
        "keyCode": 10,
        "modifiers": [
            "shift"
        ],
        "client": "org.rdk.Netflix"
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

<a name="method.removeKeyListener"></a>
## *removeKeyListener [<sup>method</sup>](#head.Methods)*

Removes a key listener for an application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.keys | array | A list of keys for which to remove a listener for the specified application (only symbol * (string data type) is acceptable) |
| params.keys[#] | object |  |
| params.keys[#].keyCode | number | The key code of the key to intercept (only symbol * (string data type) is acceptable) |
| params.keys[#].modifiers | array | A list of modifiers that need to be present to intercept (`ctrl`, `alt`, and `shift` are supported) |
| params.keys[#].modifiers[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeKeyListener",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "keys": [
            {
                "keyCode": 10,
                "modifiers": [
                    "shift"
                ]
            }
        ]
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

<a name="method.removeKeyMetadataListener"></a>
## *removeKeyMetadataListener [<sup>method</sup>](#head.Methods)*

Removes the key metadata listeners.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.removeKeyMetadataListener",
    "params": {
        "client": "searchanddiscovery",
        "callsign": "searchanddiscovery"
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

<a name="method.resetInactivityTime"></a>
## *resetInactivityTime [<sup>method</sup>](#head.Methods)*

Resets the inactivity notification interval.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.resetInactivityTime"
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

<a name="method.resumeApplication"></a>
## *resumeApplication [<sup>method</sup>](#head.Methods)*

Resumes an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onApplicationResumed](#event.onApplicationResumed) | Triggers when an application resumes from a suspended state |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.resumeApplication",
    "params": {
        "client": "HtmlApp"
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

<a name="method.scaleToFit"></a>
## *scaleToFit [<sup>method</sup>](#head.Methods)*

Scales the specified client to fit the current bounds.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.x | number | The x location |
| params.y | number | The y location |
| params.w | number | The width |
| params.h | number | The height |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.scaleToFit",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "x": 0,
        "y": 0,
        "w": 1920,
        "h": 1080
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

<a name="method.setBounds"></a>
## *setBounds [<sup>method</sup>](#head.Methods)*

Sets the bounds of the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.x | number | The x location |
| params.y | number | The y location |
| params.w | number | The width |
| params.h | number | The height |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setBounds",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "x": 0,
        "y": 0,
        "w": 1920,
        "h": 1080
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

<a name="method.setCursorSize"></a>
## *setCursorSize [<sup>method</sup>](#head.Methods)*

Sets the cursor size.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.width | number | The cursor width |
| params.height | number | The cursor height |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setCursorSize",
    "params": {
        "width": 255,
        "height": 255
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

<a name="method.setFocus"></a>
## *setFocus [<sup>method</sup>](#head.Methods)*

Sets focus to the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setFocus",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix"
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

<a name="method.setHolePunch"></a>
## *setHolePunch [<sup>method</sup>](#head.Methods)*

Enables or disables video hole punching for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.holePunch | boolean | Whether hole punching is enabled (`true`) or disabled (`false`) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setHolePunch",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "holePunch": true
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

<a name="method.setInactivityInterval"></a>
## *setInactivityInterval [<sup>method</sup>](#head.Methods)*

Sets the inactivity notification interval.

### Events

| Event | Description |
| :-------- | :-------- |
| [onUserInactivity](#event.onUserInactivity) | Triggers only if the device is inactive for the specified time interval |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.interval | integer | The inactivity event interval in minutes |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setInactivityInterval",
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
    "result": {
        "success": true
    }
}
```

<a name="method.setLogLevel"></a>
## *setLogLevel [<sup>method</sup>](#head.Methods)*

Sets the logging level.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logLevel | string | The log level (must be one of the following: *DEBUG*, *INFO*, *WARN*, *ERROR*, *FATAL*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setLogLevel",
    "params": {
        "logLevel": "INFO"
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

<a name="method.setMemoryMonitor"></a>
## *setMemoryMonitor [<sup>method</sup>](#head.Methods)*

Enables or disables RAM memory monitoring on the device. Upon enabling, triggers possible events are onDeviceLowRamWarning, onDeviceCriticallyLowRamWarning, onDeviceLowRamWarningCleared, and onDeviceCriticallyLowRamWarningCleared.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | boolean | `true` to enable memory monitoring or `false` to disable memory monitoring |
| params.interval | number | The duration, in seconds, between memory checks |
| params.lowRam | number | The threshold, in Megabytes, after which a `onDeviceLowRamWarning` event is generated |
| params.criticallyLowRam | number | The threshold, in Megabytes, after which a critically `onDeviceCriticallyLowRamWarning` event is generated |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setMemoryMonitor",
    "params": {
        "enable": true,
        "interval": 300,
        "lowRam": 128,
        "criticallyLowRam": 64
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

<a name="method.setOpacity"></a>
## *setOpacity [<sup>method</sup>](#head.Methods)*

Sets the opacity of the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params.opacity | integer | The opacity level (between 0 and 100) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setOpacity",
    "params": {
        "client": "org.rdk.Netflix",
        "opacity": 100
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

<a name="method.setScale"></a>
## *setScale [<sup>method</sup>](#head.Methods)*

Scales an application.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.sx | number | The x scale factor |
| params.sy | number | The y scale factor |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setScale",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "sx": 0.5,
        "sy": 0.5
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

<a name="method.setScreenResolution"></a>
## *setScreenResolution [<sup>method</sup>](#head.Methods)*

Sets the screen resolution.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.w | number | The width |
| params.h | number | The height |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setScreenResolution",
    "params": {
        "w": 1920,
        "h": 1080
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

<a name="method.setTopmost"></a>
## *setTopmost [<sup>method</sup>](#head.Methods)*

Sets whether the specified client appears above all other clients on the display.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params.topmost | boolean | `true` to set the client as the top most client |
| params?.focus | boolean | <sup>*(optional)*</sup> `true' to set focus for the client |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setTopmost",
    "params": {
        "client": "org.rdk.Netflix",
        "topmost": true,
        "focus": true
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

<a name="method.setVirtualResolution"></a>
## *setVirtualResolution [<sup>method</sup>](#head.Methods)*

Sets the virtual resolution for the specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.width | number | <sup>*(optional)*</sup> The width of the virtual resolution |
| params?.height | number | <sup>*(optional)*</sup> The height of the virtual resolution |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setVirtualResolution",
    "params": {
        "client": "org.rdk.Netflix",
        "width": 1920,
        "height": 1080
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

<a name="method.setVisibility"></a>
## *setVisibility [<sup>method</sup>](#head.Methods)*

Sets whether the specified client should be visible.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params?.callsign | string | <sup>*(optional)*</sup> The application callsign |
| params.visible | boolean | Whether the client is visible (`true`) or not (`false`) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setVisibility",
    "params": {
        "client": "org.rdk.Netflix",
        "callsign": "org.rdk.Netflix",
        "visible": true
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

<a name="method.setGraphicsFrameRate"></a>
## *setGraphicsFrameRate [<sup>method</sup>](#head.Methods)*

Set Graphics Frame Rate.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framerate | number | Graphics Framerate to be set |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setGraphicsFrameRate",
    "params": {
        "framerate": 60
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

<a name="method.showCursor"></a>
## *showCursor [<sup>method</sup>](#head.Methods)*

Shows the cursor on the display using the current cursor size. See `setCursorSize`. The cursor automatically disappears after 5 seconds of inactivity.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.showCursor"
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

<a name="method.showFullScreenImage"></a>
## *showFullScreenImage [<sup>method</sup>](#head.Methods)*

Shows the Full Screen Image.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.path | string | The image path |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.showFullScreenImage",
    "params": {
        "path": "/tmp/netflix.png"
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

<a name="method.showSplashLogo"></a>
## *showSplashLogo [<sup>method</sup>](#head.Methods)*

Displays the splash screen.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayTime | number | The amount of the time to show the splash screen |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.showSplashLogo",
    "params": {
        "displayTime": 5
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

<a name="method.showWatermark"></a>
## *showWatermark [<sup>method</sup>](#head.Methods)*

Sets whether a watermark shows on the display.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.show | boolean | `true` to show the watermark or `false` to hide the watermark |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.showWatermark",
    "params": {
        "show": true
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

<a name="method.suspend"></a>
## *suspend [<sup>method</sup>](#head.Methods)*

Suspends an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onSuspended](#event.onSuspended) | Triggers when the runtime of an application is suspended |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.suspend",
    "params": {
        "callsign": "Cobalt"
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

<a name="method.suspendApplication"></a>
## *suspendApplication [<sup>method</sup>](#head.Methods)*

Suspends an application.

### Events

| Event | Description |
| :-------- | :-------- |
| [onApplicationSuspended](#event.onApplicationSuspended) | Triggers when an application is suspended |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.suspendApplication",
    "params": {
        "client": "HtmlApp"
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

<a name="method.keyRepeatConfig"></a>
## *keyRepeatConfig [<sup>method</sup>](#head.Methods)*

Customizes key repeats.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.input | string | <sup>*(optional)*</sup> input type, can be 'default' or 'keyboard'. If 'input' prop not specified 'default'('keyboard') is assumed |
| params.enabled | boolean | `true` to enable key repeats, false to disable key repeats |
| params.initialDelay | number | number of miliseconds until first key repeat event will be sent |
| params.repeatInterval | number | number of miliseconds until following key repeat events will be sent |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.keyRepeatConfig",
    "params": {
        "input": "default",
        "enabled": true,
        "initialDelay": 500,
        "repeatInterval": 250
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

<a name="method.setAVBlocked"></a>
## *setAVBlocked [<sup>method</sup>](#head.Methods)*

adds/removes the list of applications with the given callsigns to/from the blacklist.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The application callsign |
| params.blocked | boolean | Whether to block (`true`) or unblock (`false`) AV for the callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.setAVBlocked",
    "params": {
        "callsign": "searchanddiscovery",
        "blocked": true
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

<a name="method.getBlockedAVApplications"></a>
## *getBlockedAVApplications [<sup>method</sup>](#head.Methods)*

Gets a list of blacklisted clients.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clients | array | A list of clients |
| result.clients[#] | string |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.RDKShell.getBlockedAVApplications"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clients": [
            "org.rdk.Netflix"
        ],
        "success": true
    }
}
```

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.RDKShell plugin:

RDKShell interface events:

| Event | Description |
| :-------- | :-------- |
| [onApplicationActivated](#event.onApplicationActivated) | Triggered when an application is activated |
| [onApplicationConnected](#event.onApplicationConnected) | Triggered when a connection to an application succeeds |
| [onApplicationDisconnected](#event.onApplicationDisconnected) | Triggered when an attempt to disconnect from an application succeeds |
| [onApplicationFirstFrame](#event.onApplicationFirstFrame) | Triggered when the first frame of an application is loaded |
| [onApplicationLaunched](#event.onApplicationLaunched) | Triggered when an application launches successfully |
| [onApplicationResumed](#event.onApplicationResumed) | Triggered when an application resumes from a suspended state |
| [onApplicationSuspended](#event.onApplicationSuspended) | Triggered when an application is suspended |
| [onApplicationTerminated](#event.onApplicationTerminated) | Triggered when an application terminates |
| [onDestroyed](#event.onDestroyed) | Triggered when a runtime is destroyed |
| [onDeviceCriticallyLowRamWarning](#event.onDeviceCriticallyLowRamWarning) | Triggered when the RAM memory on the device exceeds the configured `criticallyLowRam` threshold value |
| [onDeviceCriticallyLowRamWarningCleared](#event.onDeviceCriticallyLowRamWarningCleared) | Triggered when the RAM memory on the device no longer exceeds the configured `criticallyLowRam` threshold value |
| [onDeviceLowRamWarning](#event.onDeviceLowRamWarning) | Triggered when the RAM memory on the device exceeds the configured `lowRam` threshold value |
| [onDeviceLowRamWarningCleared](#event.onDeviceLowRamWarningCleared) | Triggered when the RAM memory on the device no longer exceeds the configured `lowRam` threshold value |
| [onLaunched](#event.onLaunched) | Triggered when a runtime is launched |
| [onSuspended](#event.onSuspended) | Triggered when a runtime is suspended |
| [onUserInactivity](#event.onUserInactivity) | Triggered when a device has been inactive for a period of time |
| [onWillDestroy](#event.onWillDestroy) | Triggered when an application is set to be destroyed |
| [onPluginSuspended](#event.onPluginSuspended) | Triggered when a plugin is suspended |
| [onScreenshotComplete](#event.onScreenshotComplete) | Triggered when a screenshot is captured successfully using `getScreenshot` method |
| [onBlur](#event.onBlur) | Triggered when the focused client is blurred |
| [onFocus](#event.onFocus) | Triggered when a client is set to focus |


<a name="event.onApplicationActivated"></a>
## *onApplicationActivated [<sup>event</sup>](#head.Notifications)*

Triggered when an application is activated.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationActivated",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationConnected"></a>
## *onApplicationConnected [<sup>event</sup>](#head.Notifications)*

Triggered when a connection to an application succeeds.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationConnected",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationDisconnected"></a>
## *onApplicationDisconnected [<sup>event</sup>](#head.Notifications)*

Triggered when an attempt to disconnect from an application succeeds.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationDisconnected",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationFirstFrame"></a>
## *onApplicationFirstFrame [<sup>event</sup>](#head.Notifications)*

Triggered when the first frame of an application is loaded.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationFirstFrame",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationLaunched"></a>
## *onApplicationLaunched [<sup>event</sup>](#head.Notifications)*

Triggered when an application launches successfully.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationLaunched",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationResumed"></a>
## *onApplicationResumed [<sup>event</sup>](#head.Notifications)*

Triggered when an application resumes from a suspended state.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationResumed",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationSuspended"></a>
## *onApplicationSuspended [<sup>event</sup>](#head.Notifications)*

Triggered when an application is suspended.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationSuspended",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onApplicationTerminated"></a>
## *onApplicationTerminated [<sup>event</sup>](#head.Notifications)*

Triggered when an application terminates.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onApplicationTerminated",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onDestroyed"></a>
## *onDestroyed [<sup>event</sup>](#head.Notifications)*

Triggered when a runtime is destroyed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDestroyed",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onDeviceCriticallyLowRamWarning"></a>
## *onDeviceCriticallyLowRamWarning [<sup>event</sup>](#head.Notifications)*

Triggered when the RAM memory on the device exceeds the configured `criticallyLowRam` threshold value. See `setMemoryMonitor`.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ram | integer | The amount of free memory remaining in Kilobytes |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceCriticallyLowRamWarning",
    "params": {
        "ram": 65536
    }
}
```

<a name="event.onDeviceCriticallyLowRamWarningCleared"></a>
## *onDeviceCriticallyLowRamWarningCleared [<sup>event</sup>](#head.Notifications)*

Triggered when the RAM memory on the device no longer exceeds the configured `criticallyLowRam` threshold value. See `setMemoryMonitor`.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ram | integer | The amount of free memory remaining in Kilobytes |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceCriticallyLowRamWarningCleared",
    "params": {
        "ram": 65536
    }
}
```

<a name="event.onDeviceLowRamWarning"></a>
## *onDeviceLowRamWarning [<sup>event</sup>](#head.Notifications)*

Triggered when the RAM memory on the device exceeds the configured `lowRam` threshold value. See `setMemoryMonitor`.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ram | integer | The amount of free memory remaining in Kilobytes |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceLowRamWarning",
    "params": {
        "ram": 65536
    }
}
```

<a name="event.onDeviceLowRamWarningCleared"></a>
## *onDeviceLowRamWarningCleared [<sup>event</sup>](#head.Notifications)*

Triggered when the RAM memory on the device no longer exceeds the configured `lowRam` threshold value. See `setMemoryMonitor`.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ram | integer | The amount of free memory remaining in Kilobytes |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceLowRamWarningCleared",
    "params": {
        "ram": 65536
    }
}
```

<a name="event.onLaunched"></a>
## *onLaunched [<sup>event</sup>](#head.Notifications)*

Triggered when a runtime is launched.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |
| params.launchType | string | The launch type of an application (must be one of the following: *create*, *active*, *suspend*, *resume*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onLaunched",
    "params": {
        "client": "org.rdk.Netflix",
        "launchType": "create"
    }
}
```

<a name="event.onSuspended"></a>
## *onSuspended [<sup>event</sup>](#head.Notifications)*

Triggered when a runtime is suspended.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSuspended",
    "params": {
        "client": "org.rdk.Netflix"
    }
}
```

<a name="event.onUserInactivity"></a>
## *onUserInactivity [<sup>event</sup>](#head.Notifications)*

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

<a name="event.onWillDestroy"></a>
## *onWillDestroy [<sup>event</sup>](#head.Notifications)*

Triggered when an application is set to be destroyed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | The application callsign |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onWillDestroy",
    "params": {
        "callsign": "Cobalt"
    }
}
```

<a name="event.onPluginSuspended"></a>
## *onPluginSuspended [<sup>event</sup>](#head.Notifications)*

Triggered when a plugin is suspended.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onPluginSuspended",
    "params": {
        "client": "searchanddiscovery"
    }
}
```

<a name="event.onScreenshotComplete"></a>
## *onScreenshotComplete [<sup>event</sup>](#head.Notifications)*

Triggered when a screenshot is captured successfully using `getScreenshot` method.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.imageData | string | Base64 encoded image data |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onScreenshotComplete",
    "params": {
        "imageData": "AAAAAAAAAA"
    }
}
```

<a name="event.onBlur"></a>
## *onBlur [<sup>event</sup>](#head.Notifications)*

Triggered when the focused client is blurred.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onBlur",
    "params": {
        "client": "searchanddiscovery"
    }
}
```

<a name="event.onFocus"></a>
## *onFocus [<sup>event</sup>](#head.Notifications)*

Triggered when a client is set to focus.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | The client name |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFocus",
    "params": {
        "client": "HtmlApp"
    }
}
```

