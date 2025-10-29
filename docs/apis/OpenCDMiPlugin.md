<!-- Generated automatically, DO NOT EDIT! -->
<a id="OpenCDMi_Plugin"></a>
# OpenCDMi Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/OpenCDMi/IDRM.h)**

A OpenCDMi plugin for Thunder framework.

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

The `OpenCDMi` plugin provides an interface for OpenCDMi.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.OpenCDMi) |
| classname | string | Class name: *OpenCDMi* |
| locator | string | Library name: *libWPEFrameworkOpenCDMi.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the OpenCDMi plugin:

OpenCDMi interface events:

| Event | Description |
| :-------- | :-------- |
| [initializationStatus](#initializationStatus) | initialization status. |

<a id="initializationStatus"></a>
## *initializationStatus*

initialization status.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.drm | std::string |  |
| params.status | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.OpenCDMi.initializationStatus",
    "params": {
        "drm": "",
        "status": "BUSY"
    }
}
```
