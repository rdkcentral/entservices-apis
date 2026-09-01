<!-- Generated automatically, DO NOT EDIT! -->
<a id="VictimSelector_Module"></a>
# VictimSelector Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/VictimSelector/IVictimSelector.h)**

A VictimSelector module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IVictimSelector](#IVictimSelector)
    - [Methods](#IVictimSelector-Methods)
    - [Notifications](#IVictimSelector-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `VictimSelector` module provides the following interface(s):

- IVictimSelector

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.VictimSelector) |
| classname | string | Class name: *VictimSelector* |
| locator | string | Library name: *libWPEFrameworkVictimSelector.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IVictimSelector"></a>
## IVictimSelector Interface

### Description

Interface for the VictimSelector plugin.

<a id="IVictimSelector-Methods"></a>
### Methods

The following methods are provided by the IVictimSelector Interface:

| Method | Description |
| :-------- | :-------- |
| [evict](#evict) | Determines the best application to terminate using the app priority algorithm. |

<a id="evict"></a>
## *evict*

Determines the best application to terminate using the app priority algorithm.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.reason | string | Resource requiring eviction: RAM, GPU, or FLASH. Possible values: RAM, GPU, FLASH |
| params.type | string | Eviction type: HARD or SOFT. Possible values: HARD, SOFT |
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
    "method": "org.rdk.VictimSelector.evict",
    "params": {
        "reason": "RAM",
        "type": "HARD"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.VictimSelector.evict", "params": {"reason": "RAM", "type": "HARD"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_UNAVAILABLE)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 2,
        "message": "The requested resource is unsupported or AppManager is unavailable."
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "A victim could not be selected or terminated."
    }
}
```

<a id="IVictimSelector-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IVictimSelector Interface:

| Event | Description |
| :-------- | :-------- |
| [onEvictComplete](#onEvictComplete) | Triggered when eviction is complete. |

<a id="onEvictComplete"></a>
## *onEvictComplete*

Triggered when eviction is complete.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.evicted | bool | True when an application was evicted. |
| params.errorCode | string | Error code when an application could not be evicted. Possible values: NONE, NO_CANDIDATE_FOUND, TERMINATION_FAILED, TIMEOUT |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.VictimSelector.onEvictComplete",
    "params": {
        "evicted": true,
        "errorCode": "NONE"
    }
}
```

