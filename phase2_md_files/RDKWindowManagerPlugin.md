<!-- Generated automatically, DO NOT EDIT! -->
<a id="RDKWindowManager_Plugin"></a>
# RDKWindowManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/RDKWindowManager/IRDKWindowManager.h)**

A RDKWindowManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `RDKWindowManager` plugin provides an interface for RDKWindowManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RDKWindowManager) |
| classname | string | Class name: *RDKWindowManager* |
| locator | string | Library name: *libWPEFrameworkRDKWindowManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the RDKWindowManager plugin:

RDKWindowManager interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [addKeyIntercept](#addKeyIntercept) | Registers a key intercept for a specific key code and client | NA |
| [addKeyIntercepts](#addKeyIntercepts) | Registers multiple key intercepts in a single operation. | NA |
| [addKeyListener](#addKeyListener) | Registers listeners for specific keys. | NA |
| [createDisplay](#createDisplay) | Create the display window | NA |
| [enableDisplayRender](#enableDisplayRender) | Enable or disable the rendering of a Wayland display | NA |
| [enableInactivityReporting](#enableInactivityReporting) | Enables the inactivity reporting | NA |
| [enableInputEvents](#enableInputEvents) | Enables KeyInputEvents for list of clients specified | NA |
| [enableKeyRepeats](#enableKeyRepeats) | Key repeats are enabled/disabled | NA |
| [generateKey](#generateKey) | Generates a key event for the specified keys and client. | NA |
| [getApps](#getApps) | Get the list of Apps which are currently active and available | NA |
| [getKeyRepeatsEnabled](#getKeyRepeatsEnabled) | Retrieves the flag determining whether keyRepeat true/false | NA |
| [ignoreKeyInputs](#ignoreKeyInputs) | Ignore key inputs | NA |
| [injectKey](#injectKey) | Simulates a key press event with optional modifiers. | NA |
| [keyRepeatConfig](#keyRepeatConfig) | Enables KeyInputEvents for list of clients specified | NA |
| [removeKeyIntercept](#removeKeyIntercept) | Removes a key intercept for a specific key code and client. | NA |
| [removeKeyListener](#removeKeyListener) | Removes listeners for specific keys. | NA |
| [renderReady](#renderReady) | To get the status of first frame is rendered or not | NA |
| [resetInactivityTime](#resetInactivityTime) | Resets inactivity interval if EnableUserInactivity feature is enabled | NA |
| [setFocus](#setFocus) | Sets the focus to the app with the app id | NA |
| [setInactivityInterval](#setInactivityInterval) | Sets inactivity interval if EnableUserInactivity feature is enabled | onUserInactivity |
| [setVisible](#setVisible) | Sets the visibility of the given client or appInstanceId | NA |

<a id="addKeyIntercept"></a>
## *addKeyIntercept*

Registers a key intercept for a specific key code and client

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.RDKWindowManager.addKeyIntercept",
    "params": {
        "intercept": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.RDKWindowManager.addKeyIntercept", "params": {"intercept": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="addKeyIntercepts"></a>
## *addKeyIntercepts*

Registers multiple key intercepts in a single operation.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.intercepts | string | JSON String format containing the array of key intercept(client/callSign, keyCode, modifiers) configuration |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.RDKWindowManager.addKeyIntercepts",
    "params": {
        "intercepts": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.RDKWindowManager.addKeyIntercepts", "params": {"intercepts": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="addKeyListener"></a>
## *addKeyListener*

Registers listeners for specific keys.

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.RDKWindowManager.addKeyListener",
    "params": {
        "keyListeners": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.RDKWindowManager.addKeyListener", "params": {"keyListeners": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="createDisplay"></a>
## *createDisplay*

Create the display window

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayParams | string | JSON String format with client,displayName,displayWidth,displayHeight,virtualDisplay,virtualWidth,virtualHeight,topmost,focus |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.RDKWindowManager.createDisplay",
    "params": {
        "displayParams": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.RDKWindowManager.createDisplay", "params": {"displayParams": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="enableDisplayRender"></a>
## *enableDisplayRender*

Enable or disable the rendering of a Wayland display

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |
| params.enable | bool | flag to true/false the feature |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.RDKWindowManager.enableDisplayRender",
    "params": {
        "client": "",
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.RDKWindowManager.enableDisplayRender", "params": {"client": "", "enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="enableInactivityReporting"></a>
## *enableInactivityReporting*

Enables the inactivity reporting

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.RDKWindowManager.enableInactivityReporting",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.RDKWindowManager.enableInactivityReporting", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="enableInputEvents"></a>
## *enableInputEvents*

Enables KeyInputEvents for list of clients specified

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clients | string | JSON String format with number of clients, enable:Flag to enable input events |
| params.enable | bool | flag to true/false the feature |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.RDKWindowManager.enableInputEvents",
    "params": {
        "clients": "",
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.RDKWindowManager.enableInputEvents", "params": {"clients": "", "enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="enableKeyRepeats"></a>
## *enableKeyRepeats*

Key repeats are enabled/disabled

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.RDKWindowManager.enableKeyRepeats",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.RDKWindowManager.enableKeyRepeats", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="generateKey"></a>
## *generateKey*

Generates a key event for the specified keys and client.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | string | JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate |
| params.client | string | the identifier of the disconnected application |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.RDKWindowManager.generateKey",
    "params": {
        "keys": "",
        "client": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.RDKWindowManager.generateKey", "params": {"keys": "", "client": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="getApps"></a>
## *getApps*

Get the list of Apps which are currently active and available

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.appsIds | string | Returns the list of app IDs as a JSON string. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.RDKWindowManager.getApps"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.RDKWindowManager.getApps"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "appsIds": ""
    }
}
```

<a id="getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled*

Retrieves the flag determining whether keyRepeat true/false

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.RDKWindowManager.getKeyRepeatsEnabled"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.RDKWindowManager.getKeyRepeatsEnabled"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "keyRepeat": true
    }
}
```

<a id="ignoreKeyInputs"></a>
## *ignoreKeyInputs*

Ignore key inputs

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.RDKWindowManager.ignoreKeyInputs",
    "params": {
        "ignore": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.RDKWindowManager.ignoreKeyInputs", "params": {"ignore": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="injectKey"></a>
## *injectKey*

Simulates a key press event with optional modifiers.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | integer | Key code to be injected, modifiers :  JSON String format with one or more modifiers |
| params.modifiers | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.RDKWindowManager.injectKey",
    "params": {
        "keyCode": 0,
        "modifiers": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.RDKWindowManager.injectKey", "params": {"keyCode": 0, "modifiers": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="keyRepeatConfig"></a>
## *keyRepeatConfig*

Enables KeyInputEvents for list of clients specified

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.RDKWindowManager.keyRepeatConfig",
    "params": {
        "input": "",
        "keyConfig": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.RDKWindowManager.keyRepeatConfig", "params": {"input": "", "keyConfig": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="removeKeyIntercept"></a>
## *removeKeyIntercept*

Removes a key intercept for a specific key code and client.

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.RDKWindowManager.removeKeyIntercept",
    "params": {
        "intercept": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.RDKWindowManager.removeKeyIntercept", "params": {"intercept": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="removeKeyListener"></a>
## *removeKeyListener*

Removes listeners for specific keys.

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.RDKWindowManager.removeKeyListener",
    "params": {
        "keyListeners": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.RDKWindowManager.removeKeyListener", "params": {"keyListeners": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="renderReady"></a>
## *renderReady*

To get the status of first frame is rendered or not

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.status | bool | Returns true if the application has rendered first frame, false if it has not yet. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.RDKWindowManager.renderReady",
    "params": {
        "client": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.RDKWindowManager.renderReady", "params": {"client": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "status": true
    }
}
```

<a id="resetInactivityTime"></a>
## *resetInactivityTime*

Resets inactivity interval if EnableUserInactivity feature is enabled

### Events
Event details will be updated soon.
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
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.RDKWindowManager.resetInactivityTime"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.RDKWindowManager.resetInactivityTime"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="setFocus"></a>
## *setFocus*

Sets the focus to the app with the app id

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.RDKWindowManager.setFocus",
    "params": {
        "client": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.RDKWindowManager.setFocus", "params": {"client": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="setInactivityInterval"></a>
## *setInactivityInterval*

Sets inactivity interval if EnableUserInactivity feature is enabled

### Events
| Event | Description |
| :-------- | :-------- |
| [onUserInactivity ](#event.onUserInactivity ) |  Triggers only if the device is inactive for the specified time interval |
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
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.RDKWindowManager.setInactivityInterval",
    "params": {
        "interval": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.RDKWindowManager.setInactivityInterval", "params": {"interval": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="setVisible"></a>
## *setVisible*

Sets the visibility of the given client or appInstanceId

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |
| params.visible | bool | boolean indicating the visibility status: `true` for visible, `false` for hide. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.RDKWindowManager.setVisible",
    "params": {
        "client": "",
        "visible": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.RDKWindowManager.setVisible", "params": {"client": "", "visible": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the RDKWindowManager plugin:

RDKWindowManager interface events:

| Event | Description |
| :-------- | :-------- |
| [OnBlur](#OnBlur) | Notifies when an application is blurred |
| [onConnected](#onConnected) | Notifies when an application is connected |
| [onDisconnected](#onDisconnected) | Notifies when an application is disconnected |
| [OnFocus](#OnFocus) | Notifies when an application is in focus |
| [OnHidden](#OnHidden) | Notifies when an application is hidden |
| [onReady](#onReady) | Posting the client for first frame ready. |
| [onUserInactivity](#onUserInactivity) | Posting the client is inactive state |
| [onVisible](#onVisible) | Notifies when an application is visible |

<a id="onBlur"></a>
## *onBlur*

Notifies when an application is blurred

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.RDKWindowManager.onBlur",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onConnected"></a>
## *onConnected*

Notifies when an application is connected

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.RDKWindowManager.onConnected",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onDisconnected"></a>
## *onDisconnected*

Notifies when an application is disconnected

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.RDKWindowManager.onDisconnected",
    "params": {
        "client": ""
    }
}
```

<a id="onFocus"></a>
## *onFocus*

Notifies when an application is in focus

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.RDKWindowManager.onFocus",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onHidden"></a>
## *onHidden*

Notifies when an application is hidden

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.RDKWindowManager.onHidden",
    "params": {
        "appInstanceId": ""
    }
}
```

<a id="onReady"></a>
## *onReady*

Posting the client for first frame ready.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | the identifier of the disconnected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.RDKWindowManager.onReady",
    "params": {
        "client": ""
    }
}
```

<a id="onUserInactivity"></a>
## *onUserInactivity*

Posting the client is inactive state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.minutes | double | notify how long user is inactive state |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.RDKWindowManager.onUserInactivity",
    "params": {
        "minutes": 0.0
    }
}
```

<a id="onVisible"></a>
## *onVisible*

Notifies when an application is visible

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | string | the identifier of the connected application |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.RDKWindowManager.onVisible",
    "params": {
        "appInstanceId": ""
    }
}
```
