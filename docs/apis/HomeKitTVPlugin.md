<!-- Generated automatically, DO NOT EDIT! -->
<a id="HomeKitTV_Plugin"></a>
# HomeKitTV Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HomeKitTV)**

A HomeKitTV plugin for Thunder framework.

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

The `HomeKitTV` plugin provides an interface for HomeKitTV.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HomeKitTV) |
| classname | string | Class name: *HomeKitTV* |
| locator | string | Library name: *libWPEFrameworkHomeKitTV.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the HomeKitTV plugin:

HomeKitTV interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryReset](#factoryReset) |  |
| [getConnectionStatus](#getConnectionStatus) |  |
| [getEnabledStatus](#getEnabledStatus) |  |
| [requestAppLaunch](#requestAppLaunch) |  |
| [setAppContainerIPAddress](#setAppContainerIPAddress) |  |
| [setCurrentInputSource](#setCurrentInputSource) |  |

<a id="factoryReset"></a>
## *factoryReset*



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
    "id": 0,
    "method": "org.rdk.HomeKitTV.factoryReset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.HomeKitTV.factoryReset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="getConnectionStatus"></a>
## *getConnectionStatus*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.HomeKitTV.getConnectionStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.HomeKitTV.getConnectionStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "result": true
    }
}
```

<a id="getEnabledStatus"></a>
## *getEnabledStatus*



### Events
Event details are missing in the header file documentation.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.HomeKitTV.getEnabledStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.HomeKitTV.getEnabledStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "result": true
    }
}
```

<a id="requestAppLaunch"></a>
## *requestAppLaunch*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.origin | string |  |
| params.reason | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.HomeKitTV.requestAppLaunch",
    "params": {
        "origin": "",
        "reason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.HomeKitTV.requestAppLaunch", "params": {"origin": "", "reason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "result": ""
    }
}
```

<a id="setAppContainerIPAddress"></a>
## *setAppContainerIPAddress*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ipaddress | string |  |
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
    "method": "org.rdk.HomeKitTV.setAppContainerIPAddress",
    "params": {
        "ipaddress": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.HomeKitTV.setAppContainerIPAddress", "params": {"ipaddress": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="setCurrentInputSource"></a>
## *setCurrentInputSource*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.inputsource | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.HomeKitTV.setCurrentInputSource",
    "params": {
        "inputsource": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.HomeKitTV.setCurrentInputSource", "params": {"inputsource": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "response": ""
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the HomeKitTV plugin:

HomeKitTV interface events:

| Event | Description |
| :-------- | :-------- |
| [exit](#exit) |  |
| [stateChange](#stateChange) |  |
| [dispatchAirplayErrorEvent](#dispatchAirplayErrorEvent) |  |
| [dispatchOnAppStateChangeRequest](#dispatchOnAppStateChangeRequest) |  |
| [dispatchOnConnectionStatusChanged](#dispatchOnConnectionStatusChanged) |  |
| [dispatchOnEnabledStatusChanged](#dispatchOnEnabledStatusChanged) |  |
| [dispatchOnInputSourceChanged](#dispatchOnInputSourceChanged) |  |

<a id="exit"></a>
## *exit*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.exitCode | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.HomeKitTV.exit",
    "params": {
        "exitCode": 0
    }
}
```

<a id="stateChange"></a>
## *stateChange*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | IHomeKitTV::state |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.HomeKitTV.stateChange",
    "params": {
        "state": ""
    }
}
```

<a id="dispatchAirplayErrorEvent"></a>
## *dispatchAirplayErrorEvent*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.HomeKitTV.dispatchAirplayErrorEvent",
    "params": {
        "params": ""
    }
}
```

<a id="dispatchOnAppStateChangeRequest"></a>
## *dispatchOnAppStateChangeRequest*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.HomeKitTV.dispatchOnAppStateChangeRequest",
    "params": {
        "params": ""
    }
}
```

<a id="dispatchOnConnectionStatusChanged"></a>
## *dispatchOnConnectionStatusChanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.HomeKitTV.dispatchOnConnectionStatusChanged",
    "params": {
        "params": ""
    }
}
```

<a id="dispatchOnEnabledStatusChanged"></a>
## *dispatchOnEnabledStatusChanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.HomeKitTV.dispatchOnEnabledStatusChanged",
    "params": {
        "params": ""
    }
}
```

<a id="dispatchOnInputSourceChanged"></a>
## *dispatchOnInputSourceChanged*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.HomeKitTV.dispatchOnInputSourceChanged",
    "params": {
        "params": ""
    }
}
```
