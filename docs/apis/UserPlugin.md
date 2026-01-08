<!-- Generated automatically, DO NOT EDIT! -->
<a id="UserPlugin_Plugin"></a>
# UserPlugin Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/UserPlugin/IUserPlugin.h)**

A UserPlugin plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `UserPlugin` plugin provides an interface for UserPlugin.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.UserPlugin) |
| classname | string | Class name: *UserPlugin* |
| locator | string | Library name: *libWPEFrameworkUserPlugin.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the UserPlugin plugin:

UserPlugin interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDevicePowerState](#getDevicePowerState) | Get current Power State |
| [getVolumeLevel](#getVolumeLevel) | Get Volume Level |

<a id="getDevicePowerState"></a>
## *getDevicePowerState*

Get current Power State

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerState | string | current power state |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.UserPlugin.getDevicePowerState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.UserPlugin.getDevicePowerState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "powerState": ""
    }
}
```

<a id="getVolumeLevel"></a>
## *getVolumeLevel*

Get Volume Level

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.port | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.volumeLevel | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.UserPlugin.getVolumeLevel",
    "params": {
        "port": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.UserPlugin.getVolumeLevel", "params": {"port": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "volumeLevel": ""
    }
}
```


