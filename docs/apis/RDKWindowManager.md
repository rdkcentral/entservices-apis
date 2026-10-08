<!-- Generated automatically, DO NOT EDIT! -->
<a id="RDKWindowManager_Module"></a>
# RDKWindowManager Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RDKWindowManager/IRDKWindowManager.h)**

A RDKWindowManager module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IRDKWindowManager](#IRDKWindowManager)
    - [Methods](#IRDKWindowManager-Methods)
    - [Notifications](#IRDKWindowManager-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `RDKWindowManager` module provides the following interface(s):

- IRDKWindowManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RDKWindowManager) |
| classname | string | Class name: *RDKWindowManager* |
| locator | string | Library name: *libWPEFrameworkRDKWindowManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IRDKWindowManager"></a>
## IRDKWindowManager Interface

<a id="IRDKWindowManager-Methods"></a>
### Methods

The following methods are provided by the IRDKWindowManager Interface:

| Method | Description |
| :-------- | :-------- |
| [addKeyIntercept](#addKeyIntercept) | Registers a key intercept for a specific key code and client |
| [addKeyIntercepts](#addKeyIntercepts) | Registers multiple key intercepts in a single operation for a specific client. |
| [addKeyListener](#addKeyListener) | Registers listeners for specific keys. |
| [createDisplay](#createDisplay) | Create the display window |
| [enableInactivityReporting](#enableInactivityReporting) | Enables the inactivity reporting |
| [enableInputEvents](#enableInputEvents) | Enables KeyInputEvents for list of clients specified |
| [enableKeyRepeats](#enableKeyRepeats) | Key repeats are enabled/disabled |
| [generateKey](#generateKey) | Generates a key event for the specified keys and client. |
| [getApps](#getApps) | Get the list of Apps which are currently active and available |
| [getBounds](#getBounds) | Gets the x, y position and width, height dimensions of the given client |
| [getFocused](#getFocused) | Gets the identifier of the currently focused application |
| [getKeyRepeatsEnabled](#getKeyRepeatsEnabled) | Retrieves the flag determining whether keyRepeat true/false |
| [getLastKeyInfo](#getLastKeyInfo) | Retrieves information about the most recent key press event, including the key code, modifier flags, and the timestamp in seconds when the key was pressed. |
| [getScale](#getScale) | Gets the horizontal and vertical scale factors of the given client |
| [getScreenshot](#getScreenshot) | Captures the entire screen buffer as Base64 encoded image data (PNG format). The screenshot is returned asynchronously via the onScreenshotComplete  |
| [getVisibility](#getVisibility) | Gets the visibility of the given client or appInstanceId |
| [getZOrder](#getZOrder) | Gets the zOrder of the given client or appInstanceId |
| [ignoreKeyInputs](#ignoreKeyInputs) | Ignore key inputs |
| [injectKey](#injectKey) | Simulates a key press event with optional modifiers. |
| [keyRepeatConfig](#keyRepeatConfig) | Enables KeyInputEvents for list of clients specified |
| [removeKeyIntercept](#removeKeyIntercept) | Removes a key intercept for a specific key code and client. |
| [removeKeyListener](#removeKeyListener) | Removes listeners for specific keys. |
| [resetInactivityTime](#resetInactivityTime) | Resets inactivity interval if EnableUserInactivity feature is enabled |
| [setAlias](#setAlias) | Sets the alias name for the given client identifier |
| [setBounds](#setBounds) | Sets the x, y position and width, height dimensions of the given client |
| [setFocus](#setFocus) | Sets the focus to the app with the app id |
| [setInactivityInterval](#setInactivityInterval) | Sets inactivity interval if EnableUserInactivity feature is enabled |
| [setScale](#setScale) | Sets the horizontal and vertical scale factors of the given client |
| [setVisible](#setVisible) | Sets the visibility of the given client or appInstanceId |
| [setZOrder](#setZOrder) | Sets the zOrder of the given client or appInstanceId |
| [showSplashScreen](#showSplashScreen) | Shows or hides the splash screen in the window manager |
| [startVncServer](#startVncServer) | Starts the VNC server |
| [stopVncServer](#stopVncServer) | Stops the VNC server |

<a id="addKeyIntercept"></a>
## *addKeyIntercept*

Configures a key intercept using the client and key information encoded in the JSON string.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercept | string | JSON String format with the client/callSign, keyCode, modifiers |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.RDKWindowManager.addKeyIntercept",
    "params": {
        "intercept": {
            "client": "org.example.app",
            "keyCode": 13,
            "modifiers": []
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.RDKWindowManager.addKeyIntercept", "params": {"intercept": {"client": "org.example.app", "keyCode": 13, "modifiers": []}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```

<a id="addKeyIntercepts"></a>
## *addKeyIntercepts*

Registers the supplied set of key intercepts for the specified client in one operation.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | The client identifier |
| params.intercepts | string | JSON String format containing the array of key intercepts (keyCode, modifiers, focusOnly, propagate) configuration |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
    "params": {
        "clientId": "org.example.app",
        "intercepts": [
            {
                "keyCode": 13,
                "modifiers": [],
                "focusOnly": true,
                "propagate": false
            }
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.RDKWindowManager.addKeyIntercepts", "params": {"clientId": "org.example.app", "intercepts": [{"keyCode": 13, "modifiers": [], "focusOnly": true, "propagate": false}]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "A general error occurred while registering one or more key intercepts"
    }
}
```

<a id="addKeyListener"></a>
## *addKeyListener*

Registers the key listener definitions encoded in the supplied JSON string.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyListeners | string | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.RDKWindowManager.addKeyListener",
    "params": {
        "keyListeners": {
            "client": "org.example.app",
            "keys": [
                {
                    "keyCode": 13
                }
            ]
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.RDKWindowManager.addKeyListener", "params": {"keyListeners": {"client": "org.example.app", "keys": [{"keyCode": 13}]}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": null
}
```

<a id="createDisplay"></a>
## *createDisplay*

Creates a display window for the client with the specified parameters.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | Client identifier |
| params.displayName | string | Name of Wayland display |
| params.displayWidth | integer | Optional width of client window |
| params.displayHeight | integer | Optional height of client window |
| params.virtualDisplay | bool | Optional flag indicating whether virtual display is enabled |
| params.virtualWidth | integer | Optional width of display in framebuffer mode |
| params.virtualHeight | integer | Optional height of display in framebuffer mode |
| params.ownerId | integer | Optional UID of owner of Wayland socket |
| params.groupId | integer | Optional group identifier of Wayland socket |
| params.topmost | bool | Optional flag indicating whether client window needs to be topmost |
| params.focus | bool | Optional flag indicating whether the client needs focus |
| params.capabilities | string | Optional JSON string containing the runtime capability tokens for the client |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.RDKWindowManager.createDisplay",
    "params": {
        "clientId": "org.example.app",
        "displayName": "wayland-0",
        "displayWidth": 1280,
        "displayHeight": 720,
        "virtualDisplay": true,
        "virtualWidth": 0,
        "virtualHeight": 0,
        "ownerId": 0,
        "groupId": 0,
        "topmost": true,
        "focus": true,
        "capabilities": "{}"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.RDKWindowManager.createDisplay", "params": {"clientId": "org.example.app", "displayName": "wayland-0", "displayWidth": 1280, "displayHeight": 720, "virtualDisplay": true, "virtualWidth": 0, "virtualHeight": 0, "ownerId": 0, "groupId": 0, "topmost": true, "focus": true, "capabilities": "{}"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "error": {
        "code": 1,
        "message": "Failed to create the display window"
    }
}
```

<a id="enableInactivityReporting"></a>
## *enableInactivityReporting*

Controls whether the window manager reports periods of user inactivity.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | flag to true/false the feature |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.RDKWindowManager.enableInactivityReporting",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.RDKWindowManager.enableInactivityReporting", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```

<a id="enableInputEvents"></a>
## *enableInputEvents*

Enables or disables key input events for the specified clients.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clients | string | JSON string identifying the clients whose input events are controlled. |
| params.enable | bool | Whether to enable or disable input events for those clients. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.RDKWindowManager.enableInputEvents",
    "params": {
        "clients": "[\\\"org.example.app\\\"]",
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.RDKWindowManager.enableInputEvents", "params": {"clients": "[\\\"org.example.app\\\"]", "enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": null
}
```

<a id="enableKeyRepeats"></a>
## *enableKeyRepeats*

Enables or disables repeated key events while a key remains pressed.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | flag to true/false the key repeats |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.RDKWindowManager.enableKeyRepeats",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.RDKWindowManager.enableKeyRepeats", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": null
}
```

<a id="generateKey"></a>
## *generateKey*

Generates the key events described by the JSON string on behalf of the specified client.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | string | JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate |
| params.client | string | Name of the client/callSign requesting the key generation. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.RDKWindowManager.generateKey",
    "params": {
        "keys": {
            "keys": [
                {
                    "keyCode": 13
                }
            ]
        },
        "client": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.RDKWindowManager.generateKey", "params": {"keys": {"keys": [{"keyCode": 13}]}, "client": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": null
}
```

<a id="getApps"></a>
## *getApps*

Returns identifiers for applications that are currently active and available to the window manager.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.appsIds | array | Returns the list of active app IDs as a JSON array. |
| result.appsIds[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.RDKWindowManager.getApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.RDKWindowManager.getApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": [
        "org.example.app"
    ]
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "error": {
        "code": 1,
        "message": "Failed to retrieve active app IDs"
    }
}
```

<a id="getBounds"></a>
## *getBounds*

Retrieves the position and dimensions of the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.x | integer | x coordinate of the client window |
| result.y | integer | y coordinate of the client window |
| result.width | integer | width of the client window in pixels |
| result.height | integer | height of the client window in pixels |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.RDKWindowManager.getBounds",
    "params": {
        "clientId": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.RDKWindowManager.getBounds", "params": {"clientId": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": {
        "x": 0,
        "y": 0,
        "width": 1280,
        "height": 720
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "error": {
        "code": 1,
        "message": "Failed to get bounds"
    }
}
```

<a id="getFocused"></a>
## *getFocused*

Retrieves the identifier of the application that currently has input focus.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.client | string | Output parameter. The identifier of the currently focused application |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.RDKWindowManager.getFocused"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.RDKWindowManager.getFocused"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "result": {
        "client": "org.example.app"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "error": {
        "code": 1,
        "message": "Failed to retrieve the focused application identifier"
    }
}
```

<a id="getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled*

Retrieves whether repeated key events are currently enabled.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keyRepeat | bool | flag stating whether keyRepeat true/false |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.RDKWindowManager.getKeyRepeatsEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.RDKWindowManager.getKeyRepeatsEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": {
        "keyRepeat": true
    }
}
```

<a id="getLastKeyInfo"></a>
## *getLastKeyInfo*

Returns the key information recorded for the most recent key press.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.keyCode | integer | Output parameter. The key code of the last pressed key. |
| result.modifiers | integer | Output parameter. The modifier flags (e.g., Shift, Ctrl) active during the last key press. |
| result.timestampInSeconds | integer | Output parameter. The timestamp (in seconds) when the last key press occurred. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.RDKWindowManager.getLastKeyInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.RDKWindowManager.getLastKeyInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "result": {
        "keyCode": 13,
        "modifiers": 1,
        "timestampInSeconds": 1710000000
    }
}
```


#### Error Response (Core::ERROR_UNAVAILABLE)

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "error": {
        "code": 2,
        "message": "No key press information is available."
    }
}
```

<a id="getScale"></a>
## *getScale*

Retrieves the horizontal and vertical scale factors of the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.scaleX | double | horizontal scale factor |
| result.scaleY | double | vertical scale factor |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "method": "org.rdk.RDKWindowManager.getScale",
    "params": {
        "clientId": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.RDKWindowManager.getScale", "params": {"clientId": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "result": {
        "scaleX": 1.0,
        "scaleY": 1.0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "error": {
        "code": 1,
        "message": "Failed to get scale"
    }
}
```

<a id="getScreenshot"></a>
## *getScreenshot*

Starts an asynchronous screenshot capture; the result is delivered through the onScreenshotComplete notification.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.RDKWindowManager.getScreenshot"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.RDKWindowManager.getScreenshot"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "error": {
        "code": 1,
        "message": "on failure"
    }
}
```

<a id="getVisibility"></a>
## *getVisibility*

Retrieves whether the specified client window is visible.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | client name or application instance ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.visible | bool | boolean indicating the visibility status: `true` for visible, `false` for hide. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.RDKWindowManager.getVisibility",
    "params": {
        "client": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 15, "method": "org.rdk.RDKWindowManager.getVisibility", "params": {"client": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "result": {
        "visible": true
    }
}
```

<a id="getZOrder"></a>
## *getZOrder*

Retrieves the stacking order of the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.zOrder | integer | integer value indicating the zOrder of the client |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.RDKWindowManager.getZOrder",
    "params": {
        "clientId": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 16, "method": "org.rdk.RDKWindowManager.getZOrder", "params": {"clientId": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "result": {
        "zOrder": 2
    }
}
```

<a id="ignoreKeyInputs"></a>
## *ignoreKeyInputs*

Sets whether key input events are ignored by the window manager.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ignore | bool | flag stating whether key inputs ignored |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "method": "org.rdk.RDKWindowManager.ignoreKeyInputs",
    "params": {
        "ignore": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 17, "method": "org.rdk.RDKWindowManager.ignoreKeyInputs", "params": {"ignore": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "result": null
}
```

<a id="injectKey"></a>
## *injectKey*

Injects the specified key code with the provided modifier configuration.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | integer | Key code to inject. |
| params.modifiers | string | JSON string containing zero or more key modifiers. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.RDKWindowManager.injectKey",
    "params": {
        "keyCode": 13,
        "modifiers": "CTRL"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 18, "method": "org.rdk.RDKWindowManager.injectKey", "params": {"keyCode": 13, "modifiers": "CTRL"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "result": null
}
```

<a id="keyRepeatConfig"></a>
## *keyRepeatConfig*

Applies key repeat configuration for the specified input type.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.input | string | input type (default/keyboard) |
| params.keyConfig | string | JSON String format with enabled, initialDelay and repeatInterval |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "method": "org.rdk.RDKWindowManager.keyRepeatConfig",
    "params": {
        "input": "keyboard",
        "keyConfig": "{\\\"enabled\\\":true,\\\"initialDelay\\\":500,\\\"repeatInterval\\\":50}"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 19, "method": "org.rdk.RDKWindowManager.keyRepeatConfig", "params": {"input": "keyboard", "keyConfig": "{\\\"enabled\\\":true,\\\"initialDelay\\\":500,\\\"repeatInterval\\\":50}"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "result": null
}
```

<a id="removeKeyIntercept"></a>
## *removeKeyIntercept*

Removes the key intercept matching the client, key code, and modifier configuration.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | The client identifier |
| params.keyCode | integer | The key code to remove |
| params.modifiers | string | JSON String format with one or more modifiers |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "method": "org.rdk.RDKWindowManager.removeKeyIntercept",
    "params": {
        "clientId": "org.example.app",
        "keyCode": 13,
        "modifiers": "CTRL"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 20, "method": "org.rdk.RDKWindowManager.removeKeyIntercept", "params": {"clientId": "org.example.app", "keyCode": 13, "modifiers": "CTRL"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "error": {
        "code": 1,
        "message": "The intercept could not be removed due to an internal error."
    }
}
```

<a id="removeKeyListener"></a>
## *removeKeyListener*

Removes the key listener definitions identified by the supplied JSON string.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyListeners | string | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "method": "org.rdk.RDKWindowManager.removeKeyListener",
    "params": {
        "keyListeners": {
            "client": "org.example.app",
            "keys": [
                {
                    "keyCode": 13
                }
            ]
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 21, "method": "org.rdk.RDKWindowManager.removeKeyListener", "params": {"keyListeners": {"client": "org.example.app", "keys": [{"keyCode": 13}]}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "result": null
}
```

<a id="resetInactivityTime"></a>
## *resetInactivityTime*

Resets the inactivity timer so the current period starts over.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "method": "org.rdk.RDKWindowManager.resetInactivityTime"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 22, "method": "org.rdk.RDKWindowManager.resetInactivityTime"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "result": null
}
```

<a id="setAlias"></a>
## *setAlias*

Associates the specified alias with a client identifier.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client identifier |
| params.alias | string | alias name for the given client identifier |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "method": "org.rdk.RDKWindowManager.setAlias",
    "params": {
        "clientId": "org.example.app",
        "alias": "home-screen"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 23, "method": "org.rdk.RDKWindowManager.setAlias", "params": {"clientId": "org.example.app", "alias": "home-screen"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "error": {
        "code": 1,
        "message": "Operation failed"
    }
}
```

<a id="setBounds"></a>
## *setBounds*

Sets the position and dimensions of the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
| params.x | integer | x coordinate of the client window |
| params.y | integer | y coordinate of the client window |
| params.width | integer | width of the client window in pixels |
| params.height | integer | height of the client window in pixels |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "method": "org.rdk.RDKWindowManager.setBounds",
    "params": {
        "clientId": "org.example.app",
        "x": 0,
        "y": 0,
        "width": 1280,
        "height": 720
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 24, "method": "org.rdk.RDKWindowManager.setBounds", "params": {"clientId": "org.example.app", "x": 0, "y": 0, "width": 1280, "height": 720}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "error": {
        "code": 1,
        "message": "Failed to set bounds"
    }
}
```

<a id="setFocus"></a>
## *setFocus*

Requests that the specified application receive input focus.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | Client name or application instance ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 25,
    "method": "org.rdk.RDKWindowManager.setFocus",
    "params": {
        "client": "org.example.app"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 25, "method": "org.rdk.RDKWindowManager.setFocus", "params": {"client": "org.example.app"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 25,
    "result": null
}
```

<a id="setInactivityInterval"></a>
## *setInactivityInterval*

Sets the interval used to determine when the user is considered inactive.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.interval | integer | time interval set for inactivity |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 26,
    "method": "org.rdk.RDKWindowManager.setInactivityInterval",
    "params": {
        "interval": 300
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 26, "method": "org.rdk.RDKWindowManager.setInactivityInterval", "params": {"interval": 300}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 26,
    "result": null
}
```

<a id="setScale"></a>
## *setScale*

Applies horizontal and vertical scale factors to the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
| params.scaleX | double | horizontal scale factor |
| params.scaleY | double | vertical scale factor |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "method": "org.rdk.RDKWindowManager.setScale",
    "params": {
        "clientId": "org.example.app",
        "scaleX": 1.0,
        "scaleY": 1.0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 27, "method": "org.rdk.RDKWindowManager.setScale", "params": {"clientId": "org.example.app", "scaleX": 1.0, "scaleY": 1.0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "error": {
        "code": 1,
        "message": "Failed to set scale"
    }
}
```

<a id="setVisible"></a>
## *setVisible*

Shows or hides the specified client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | client name or application instance ID |
| params.visible | bool | boolean indicating the visibility status: `true` for visible, `false` for hide. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 28,
    "method": "org.rdk.RDKWindowManager.setVisible",
    "params": {
        "client": "org.example.app",
        "visible": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 28, "method": "org.rdk.RDKWindowManager.setVisible", "params": {"client": "org.example.app", "visible": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 28,
    "result": null
}
```

<a id="setZOrder"></a>
## *setZOrder*

Assigns the specified stacking order to the client window.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | client name or application instance ID |
| params.zOrder | integer | integer value indicating the zOrder |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 29,
    "method": "org.rdk.RDKWindowManager.setZOrder",
    "params": {
        "clientId": "org.example.app",
        "zOrder": 2
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 29, "method": "org.rdk.RDKWindowManager.setZOrder", "params": {"clientId": "org.example.app", "zOrder": 2}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 29,
    "result": null
}
```

<a id="showSplashScreen"></a>
## *showSplashScreen*

Sets the splash screen visibility according to the supplied flag.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.show | bool | boolean indicating whether to show (true) or hide (false) the splash screen |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "method": "org.rdk.RDKWindowManager.showSplashScreen",
    "params": {
        "show": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 30, "method": "org.rdk.RDKWindowManager.showSplashScreen", "params": {"show": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "error": {
        "code": 1,
        "message": "Operation failed"
    }
}
```

<a id="startVncServer"></a>
## *startVncServer*

Starts remote screen access through the VNC server.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 31,
    "method": "org.rdk.RDKWindowManager.startVncServer"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 31, "method": "org.rdk.RDKWindowManager.startVncServer"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 31,
    "result": null
}
```

<a id="stopVncServer"></a>
## *stopVncServer*

Stops remote screen access through the VNC server.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 32,
    "method": "org.rdk.RDKWindowManager.stopVncServer"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 32, "method": "org.rdk.RDKWindowManager.stopVncServer"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 32,
    "result": null
}
```

<a id="IRDKWindowManager-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IRDKWindowManager Interface:

| Event | Description |
| :-------- | :-------- |
| [onBlur](#onBlur) | Notifies when an application is blurred |
| [onConnected](#onConnected) | Notifies when an application is connected |
| [onDisconnected](#onDisconnected) | Notifies when an application is disconnected |
| [onFocus](#onFocus) | Notifies when an application is in focus |
| [onHidden](#onHidden) | Notifies when an application is hidden |
| [onReady](#onReady) | Notifies when an application is ready for its first frame. |
| [onScreenshotComplete](#onScreenshotComplete) | Notifies when a screenshot capture is complete |
| [onUserInactivity](#onUserInactivity) | Posting the client is inactive state |
| [onVisible](#onVisible) | Notifies when an application is visible |

<a id="onBlur"></a>
## *onBlur*

Indicates that the application has lost focus in the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the blurred application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 33,
    "method": "org.rdk.RDKWindowManager.onBlur",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onConnected"></a>
## *onConnected*

Indicates that the application has successfully connected to the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 34,
    "method": "org.rdk.RDKWindowManager.onConnected",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onDisconnected"></a>
## *onDisconnected*

Notifies when an application is disconnected from the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the disconnected application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 35,
    "method": "org.rdk.RDKWindowManager.onDisconnected",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onFocus"></a>
## *onFocus*

Indicates that the application has gained focus in the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the focussed application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 36,
    "method": "org.rdk.RDKWindowManager.onFocus",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onHidden"></a>
## *onHidden*

Indicates that the application is currently hidden in the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the hidden application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 37,
    "method": "org.rdk.RDKWindowManager.onHidden",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onReady"></a>
## *onReady*

Indicates that the application has completed its initial setup and is ready to display its first frame.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | notify first frame event received for client or application instance ID |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 38,
    "method": "org.rdk.RDKWindowManager.onReady",
    "params": {
        "clientId": "org.example.app"
    }
}
```

<a id="onScreenshotComplete"></a>
## *onScreenshotComplete*

Indicates that the screenshot capture process has completed, providing the success status and the captured image data.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.success | bool | Indicates whether the screenshot was captured successfully |
| params.imageData | string | Base64 encoded image data (PNG format) |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 39,
    "method": "org.rdk.RDKWindowManager.onScreenshotComplete",
    "params": {
        "success": true,
        "imageData": "iVBORw0KGgoAAAANSUhEUgAA..."
    }
}
```

<a id="onUserInactivity"></a>
## *onUserInactivity*

Notifies when the user has been inactive for a specified duration.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.minutes | double | notify how long user is inactive state |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 40,
    "method": "org.rdk.RDKWindowManager.onUserInactivity",
    "params": {
        "minutes": 5
    }
}
```

<a id="onVisible"></a>
## *onVisible*

Indicates that the application is currently visible in the window manager.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | string | the identifier of the visible application |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 41,
    "method": "org.rdk.RDKWindowManager.onVisible",
    "params": {
        "clientId": "org.example.app"
    }
}
```

