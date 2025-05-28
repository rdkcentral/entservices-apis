<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IRDKWindowManager_Plugin"></a>
# IRDKWindowManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IRDKWindowManager/CHANGELOG.md)**

A IRDKWindowManager plugin for Thunder framework.

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

The `IRDKWindowManager` plugin provides an interface for IRDKWindowManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IRDKWindowManager*) |
| classname | string | Class name: *IRDKWindowManager* |
| locator | string | Library name: *libWPEFrameworkIRDKWindowManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IRDKWindowManager plugin:

IRDKWindowManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [AddKeyIntercept](#method.AddKeyIntercept) | Registers a key intercept for a specific key code and client |
| [AddKeyIntercepts](#method.AddKeyIntercepts) | Registers multiple key intercepts in a single operation. |
| [AddKeyListener](#method.AddKeyListener) | Registers listeners for specific keys. |
| [CreateDisplay](#method.CreateDisplay) | Create the display window |
| [EnableInactivityReporting](#method.EnableInactivityReporting) | Enables the inactivity reporting |
| [EnableInputEvents](#method.EnableInputEvents) | Enables KeyInputEvents for list of clients specified |
| [EnableKeyRepeats](#method.EnableKeyRepeats) | Key repeats are enabled/disabled |
| [GenerateKey](#method.GenerateKey) | Generates a key event for the specified keys and client. |
| [GetClients](#method.GetClients) | get the list of Clients which are available |
| [GetKeyRepeatsEnabled](#method.GetKeyRepeatsEnabled) | Retrieves the flag determining whether keyRepeat true/false |
| [IgnoreKeyInputs](#method.IgnoreKeyInputs) | Ignore key inputs |
| [InjectKey](#method.InjectKey) | Simulates a key press event with optional modifiers. |
| [KeyRepeatConfig](#method.KeyRepeatConfig) | Enables KeyInputEvents for list of clients specified |
| [RemoveKeyIntercept](#method.RemoveKeyIntercept) | Removes a key intercept for a specific key code and client. |
| [RemoveKeyListener](#method.RemoveKeyListener) | Removes listeners for specific keys. |
| [ResetInactivityTime](#method.ResetInactivityTime) | Resets inactivity interval if EnableUserInactivity feature is enabled |
| [SetFocus](#method.SetFocus) | Sets the focus to the app with the app id |
| [SetInactivityInterval](#method.SetInactivityInterval) | Sets inactivity interval if EnableUserInactivity feature is enabled |
| [SetVisible](#method.SetVisible) | Sets the visibility of the given client or appInstanceId |

<a id="method.AddKeyIntercept"></a>
## *AddKeyIntercept [<sup>method</sup>](#head.Methods)*

Registers a key intercept for a specific key code and client

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.intercept | string | JSON String format with the client/callSign, keyCode, modifiers |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.AddKeyIntercept",
    "params": {
        "intercept": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.AddKeyIntercepts"></a>
## *AddKeyIntercepts [<sup>method</sup>](#head.Methods)*

Registers multiple key intercepts in a single operation.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.intercepts | string | JSON String format containing the array of key intercept(client/callSign, keyCode, modifiers) configuration |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.AddKeyIntercepts",
    "params": {
        "intercepts": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.AddKeyListener"></a>
## *AddKeyListener [<sup>method</sup>](#head.Methods)*

Registers listeners for specific keys.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.keyListeners | string | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.AddKeyListener",
    "params": {
        "keyListeners": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.CreateDisplay"></a>
## *CreateDisplay [<sup>method</sup>](#head.Methods)*

Create the display window

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.displayParams | string | JSON String format with client,displayName,displayWidth,displayHeight,virtualDisplay,virtualWidth,virtualHeight,topmost,focus |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.CreateDisplay",
    "params": {
        "displayParams": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.EnableInactivityReporting"></a>
## *EnableInactivityReporting [<sup>method</sup>](#head.Methods)*

Enables the inactivity reporting

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enable | bool | flag to true/false the feature |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.EnableInactivityReporting",
    "params": {
        "enable": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.EnableInputEvents"></a>
## *EnableInputEvents [<sup>method</sup>](#head.Methods)*

Enables KeyInputEvents for list of clients specified

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.clients | string | get the number of clients as a JSON string format |
| params.enable | bool | flag to true/false the feature |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.EnableInputEvents",
    "params": {
        "clients": "",
        "enable": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.EnableKeyRepeats"></a>
## *EnableKeyRepeats [<sup>method</sup>](#head.Methods)*

Key repeats are enabled/disabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enable | bool | flag to true/false the feature |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.EnableKeyRepeats",
    "params": {
        "enable": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GenerateKey"></a>
## *GenerateKey [<sup>method</sup>](#head.Methods)*

Generates a key event for the specified keys and client.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.keys | string | JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate |
| params.client | string | Name of the client/callSign requesting the key generation. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.GenerateKey",
    "params": {
        "keys": "",
        "client": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetClients"></a>
## *GetClients [<sup>method</sup>](#head.Methods)*

get the list of Clients which are available

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.clients | string | get the number of clients as a JSON string format |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.GetClients"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clients": ""
    }
}
```
<a id="method.GetKeyRepeatsEnabled"></a>
## *GetKeyRepeatsEnabled [<sup>method</sup>](#head.Methods)*

Retrieves the flag determining whether keyRepeat true/false

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.keyRepeat | bool | flag stating whether keyRepeat true/false |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.GetKeyRepeatsEnabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "keyRepeat": "true"
    }
}
```
<a id="method.IgnoreKeyInputs"></a>
## *IgnoreKeyInputs [<sup>method</sup>](#head.Methods)*

Ignore key inputs

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.ignore | bool | flag stating whether key inputs ignored |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.IgnoreKeyInputs",
    "params": {
        "ignore": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.InjectKey"></a>
## *InjectKey [<sup>method</sup>](#head.Methods)*

Simulates a key press event with optional modifiers.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.keyCode | uint32_t | Key code to be injected, modifiers :  JSON String format with one or more modifiers |
| params.modifiers | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.InjectKey",
    "params": {
        "keyCode": "0",
        "modifiers": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.KeyRepeatConfig"></a>
## *KeyRepeatConfig [<sup>method</sup>](#head.Methods)*

Enables KeyInputEvents for list of clients specified

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.input | string | input type (default/keyboard) |
| params.keyConfig | string | JSON String format with enabled, initialDelay and repeatInterval |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.KeyRepeatConfig",
    "params": {
        "input": "",
        "keyConfig": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.RemoveKeyIntercept"></a>
## *RemoveKeyIntercept [<sup>method</sup>](#head.Methods)*

Removes a key intercept for a specific key code and client.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.intercept | string | JSON String format with the client/callSign, keyCode, modifiers |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.RemoveKeyIntercept",
    "params": {
        "intercept": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.RemoveKeyListener"></a>
## *RemoveKeyListener [<sup>method</sup>](#head.Methods)*

Removes listeners for specific keys.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.keyListeners | string | JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.RemoveKeyListener",
    "params": {
        "keyListeners": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.ResetInactivityTime"></a>
## *ResetInactivityTime [<sup>method</sup>](#head.Methods)*

Resets inactivity interval if EnableUserInactivity feature is enabled

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.ResetInactivityTime"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFocus"></a>
## *SetFocus [<sup>method</sup>](#head.Methods)*

Sets the focus to the app with the app id

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.client | string | Name of the client/callSign requesting the key generation. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.SetFocus",
    "params": {
        "client": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetInactivityInterval"></a>
## *SetInactivityInterval [<sup>method</sup>](#head.Methods)*

Sets inactivity interval if EnableUserInactivity feature is enabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.interval | uint32_t | time interval set for inactivity |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.SetInactivityInterval",
    "params": {
        "interval": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetVisible"></a>
## *SetVisible [<sup>method</sup>](#head.Methods)*

Sets the visibility of the given client or appInstanceId

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.client | std::string | the identifier of the disconnected application |
| params.visible | bool | boolean indicating the visibility status: `true` for visible, `false` for hide. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.SetVisible",
    "params": {
        "client": "",
        "visible": "true"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IRDKWindowManager plugin:

IRDKWindowManager interface events:

| Method | Description |
| :-------- | :-------- |
| [OnDisconnected](#event.OnDisconnected) | Notifies when an application is disconnected |
| [OnUserInactivity](#event.OnUserInactivity) | Posting the client is inactive state |

<a id="event.OnDisconnected"></a>
## *OnDisconnected [<sup>event</sup>](#head.Notifications)*

Notifies when an application is disconnected

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.client | std::string | the identifier of the disconnected application |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.OnDisconnected",
    "params": {
        "client": ""
    }
}
```
<a id="event.OnUserInactivity"></a>
## *OnUserInactivity [<sup>event</sup>](#head.Notifications)*

Posting the client is inactive state

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.minutes | double | notify how long user is inactive state |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IRDKWindowManager.OnUserInactivity",
    "params": {
        "minutes": "0.0"
    }
}
```