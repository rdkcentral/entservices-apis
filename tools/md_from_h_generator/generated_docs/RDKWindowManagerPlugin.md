<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.RDKWindowManager_Plugin"></a>
# RDKWindowManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/RDKWindowManager/CHANGELOG.md)**

A RDKWindowManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `RDKWindowManager` plugin provides an interface for RDKWindowManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.RDKWindowManager) |
| classname | string | Class name: *RDKWindowManager* |
| locator | string | Library name: *libWPEFrameworkRDKWindowManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the RDKWindowManager plugin:

RDKWindowManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [addKeyIntercept](#method.addKeyIntercept) | Registers a key intercept for a specific key code and client |
| [addKeyIntercepts](#method.addKeyIntercepts) | Registers multiple key intercepts in a single operation. |
| [addKeyListener](#method.addKeyListener) | Registers listeners for specific keys. |
| [createDisplay](#method.createDisplay) | Create the display window |
| [enableDisplayRender](#method.enableDisplayRender) | Enable or disable the rendering of a Wayland display |
| [enableInactivityReporting](#method.enableInactivityReporting) | Enables the inactivity reporting |
| [enableInputEvents](#method.enableInputEvents) | Enables KeyInputEvents for list of clients specified |
| [enableKeyRepeats](#method.enableKeyRepeats) | Key repeats are enabled/disabled |
| [generateKey](#method.generateKey) | Generates a key event for the specified keys and client. |
| [getApps](#method.getApps) | Get the list of Apps which are currently active and available |
| [getKeyRepeatsEnabled](#method.getKeyRepeatsEnabled) | Retrieves the flag determining whether keyRepeat true/false |
| [ignoreKeyInputs](#method.ignoreKeyInputs) | Ignore key inputs |
| [injectKey](#method.injectKey) | Simulates a key press event with optional modifiers. |
| [keyRepeatConfig](#method.keyRepeatConfig) | Enables KeyInputEvents for list of clients specified |
| [removeKeyIntercept](#method.removeKeyIntercept) | Removes a key intercept for a specific key code and client. |
| [removeKeyListener](#method.removeKeyListener) | Removes listeners for specific keys. |
| [renderReady](#method.renderReady) | To get the status of first frame is rendered or not |
| [resetInactivityTime](#method.resetInactivityTime) | Resets inactivity interval if EnableUserInactivity feature is enabled |
| [setFocus](#method.setFocus) | Sets the focus to the app with the app id |
| [setInactivityInterval](#method.setInactivityInterval) | Sets inactivity interval if EnableUserInactivity feature is enabled |
| [setVisible](#method.setVisible) | Sets the visibility of the given client or appInstanceId |

<a id="method.addKeyIntercept"></a>
## *addKeyIntercept [<sup>method</sup>](#head.Methods)*

Registers a key intercept for a specific key code and client

### Events
Event details are missing in the header file documentation.
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

<a id="method.addKeyIntercepts"></a>
## *addKeyIntercepts [<sup>method</sup>](#head.Methods)*

Registers multiple key intercepts in a single operation.

### Events
Event details are missing in the header file documentation.
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

<a id="method.addKeyListener"></a>
## *addKeyListener [<sup>method</sup>](#head.Methods)*

Registers listeners for specific keys.

### Events
Event details are missing in the header file documentation.
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

<a id="method.createDisplay"></a>
## *createDisplay [<sup>method</sup>](#head.Methods)*

Create the display window

### Events
Event details are missing in the header file documentation.
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

<a id="method.enableDisplayRender"></a>
## *enableDisplayRender [<sup>method</sup>](#head.Methods)*

Enable or disable the rendering of a Wayland display

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | notify first frame event received for client or application instance ID |
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

<a id="method.enableInactivityReporting"></a>
## *enableInactivityReporting [<sup>method</sup>](#head.Methods)*

Enables the inactivity reporting

### Events
Event details are missing in the header file documentation.
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

<a id="method.enableInputEvents"></a>
## *enableInputEvents [<sup>method</sup>](#head.Methods)*

Enables KeyInputEvents for list of clients specified

### Events
Event details are missing in the header file documentation.
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

<a id="method.enableKeyRepeats"></a>
## *enableKeyRepeats [<sup>method</sup>](#head.Methods)*

Key repeats are enabled/disabled

### Events
Event details are missing in the header file documentation.
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

<a id="method.generateKey"></a>
## *generateKey [<sup>method</sup>](#head.Methods)*

Generates a key event for the specified keys and client.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keys | string | JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate |
| params.client | string | notify first frame event received for client or application instance ID |
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

<a id="method.getApps"></a>
## *getApps [<sup>method</sup>](#head.Methods)*

Get the list of Apps which are currently active and available

### Events
Event details are missing in the header file documentation.
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

<a id="method.getKeyRepeatsEnabled"></a>
## *getKeyRepeatsEnabled [<sup>method</sup>](#head.Methods)*

Retrieves the flag determining whether keyRepeat true/false

### Events
Event details are missing in the header file documentation.
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

<a id="method.ignoreKeyInputs"></a>
## *ignoreKeyInputs [<sup>method</sup>](#head.Methods)*

Ignore key inputs

### Events
Event details are missing in the header file documentation.
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

<a id="method.injectKey"></a>
## *injectKey [<sup>method</sup>](#head.Methods)*

Simulates a key press event with optional modifiers.

### Events
Event details are missing in the header file documentation.
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

<a id="method.keyRepeatConfig"></a>
## *keyRepeatConfig [<sup>method</sup>](#head.Methods)*

Enables KeyInputEvents for list of clients specified

### Events
Event details are missing in the header file documentation.
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

<a id="method.removeKeyIntercept"></a>
## *removeKeyIntercept [<sup>method</sup>](#head.Methods)*

Removes a key intercept for a specific key code and client.

### Events
Event details are missing in the header file documentation.
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

<a id="method.removeKeyListener"></a>
## *removeKeyListener [<sup>method</sup>](#head.Methods)*

Removes listeners for specific keys.

### Events
Event details are missing in the header file documentation.
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

<a id="method.renderReady"></a>
## *renderReady [<sup>method</sup>](#head.Methods)*

To get the status of first frame is rendered or not

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | notify first frame event received for client or application instance ID |
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

<a id="method.resetInactivityTime"></a>
## *resetInactivityTime [<sup>method</sup>](#head.Methods)*

Resets inactivity interval if EnableUserInactivity feature is enabled

### Events
Event details are missing in the header file documentation.
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

<a id="method.setFocus"></a>
## *setFocus [<sup>method</sup>](#head.Methods)*

Sets the focus to the app with the app id

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | notify first frame event received for client or application instance ID |
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

<a id="method.setInactivityInterval"></a>
## *setInactivityInterval [<sup>method</sup>](#head.Methods)*

Sets inactivity interval if EnableUserInactivity feature is enabled

### Events
Event details are missing in the header file documentation.
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

<a id="method.setVisible"></a>
## *setVisible [<sup>method</sup>](#head.Methods)*

Sets the visibility of the given client or appInstanceId

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | std::string | the identifier of the disconnected application |
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the RDKWindowManager plugin:

RDKWindowManager interface events:

| Event | Description |
| :-------- | :-------- |
| [OnBlur](#event.OnBlur) | Notifies when an application is blurred |
| [onConnected](#event.onConnected) | Notifies when an application is connected |
| [onDisconnected](#event.onDisconnected) | Notifies when an application is disconnected |
| [OnFocus](#event.OnFocus) | Notifies when an application is in focus |
| [OnHidden](#event.OnHidden) | Notifies when an application is hidden |
| [onReady](#event.onReady) | Posting the client for first frame ready. |
| [onUserInactivity](#event.onUserInactivity) | Posting the client is inactive state |
| [onVisible](#event.onVisible) | Notifies when an application is visible |

<a id="event.onBlur"></a>
## *onBlur [<sup>event</sup>](#head.Notifications)*

Notifies when an application is blurred

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | std::string | the identifier of the connected application |

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

<a id="event.onConnected"></a>
## *onConnected [<sup>event</sup>](#head.Notifications)*

Notifies when an application is connected

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | std::string | the identifier of the connected application |

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

<a id="event.onDisconnected"></a>
## *onDisconnected [<sup>event</sup>](#head.Notifications)*

Notifies when an application is disconnected

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | std::string | the identifier of the disconnected application |

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

<a id="event.onFocus"></a>
## *onFocus [<sup>event</sup>](#head.Notifications)*

Notifies when an application is in focus

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | std::string | the identifier of the connected application |

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

<a id="event.onHidden"></a>
## *onHidden [<sup>event</sup>](#head.Notifications)*

Notifies when an application is hidden

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | std::string | the identifier of the connected application |

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

<a id="event.onReady"></a>
## *onReady [<sup>event</sup>](#head.Notifications)*

Posting the client for first frame ready.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.client | string | notify first frame event received for client or application instance ID |

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

<a id="event.onUserInactivity"></a>
## *onUserInactivity [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onVisible"></a>
## *onVisible [<sup>event</sup>](#head.Notifications)*

Notifies when an application is visible

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appInstanceId | std::string | the identifier of the connected application |

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
