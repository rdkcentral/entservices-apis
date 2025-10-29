<!-- Generated automatically, DO NOT EDIT! -->
<a id="SystemAudioPlayer_Plugin"></a>
# SystemAudioPlayer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SystemAudioPlayer/ISystemAudioPlayer.h)**

A SystemAudioPlayer plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `SystemAudioPlayer` plugin provides an interface for SystemAudioPlayer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemAudioPlayer) |
| classname | string | Class name: *SystemAudioPlayer* |
| locator | string | Library name: *libWPEFrameworkSystemAudioPlayer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the SystemAudioPlayer plugin:

SystemAudioPlayer interface events:

| Event | Description |
| :-------- | :-------- |
| [onSAPEvents](#onSAPEvents) |  |

<a id="onSAPEvents"></a>
## *onSAPEvents*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.data | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.SystemAudioPlayer.onSAPEvents",
    "params": {
        "data": ""
    }
}
```
