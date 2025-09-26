<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.HomeKitTV_Plugin"></a>
# HomeKitTV Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/HomeKitTV/CHANGELOG.md)**

A HomeKitTV plugin for Thunder framework.

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

The `HomeKitTV` plugin provides an interface for HomeKitTV.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HomeKitTV) |
| classname | string | Class name: *HomeKitTV* |
| locator | string | Library name: *libWPEFrameworkHomeKitTV.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the HomeKitTV plugin:

HomeKitTV interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryReset](#method.factoryReset) |  |
| [getConnectionStatus](#method.getConnectionStatus) |  |
| [getEnabledStatus](#method.getEnabledStatus) |  |
| [requestAppLaunch](#method.requestAppLaunch) |  |
| [setAppContainerIPAddress](#method.setAppContainerIPAddress) |  |
| [setCurrentInputSource](#method.setCurrentInputSource) |  |

<a id="method.factoryReset"></a>
## *factoryReset [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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

<a id="method.getConnectionStatus"></a>
## *getConnectionStatus [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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

<a id="method.getEnabledStatus"></a>
## *getEnabledStatus [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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

<a id="method.requestAppLaunch"></a>
## *requestAppLaunch [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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

<a id="method.setAppContainerIPAddress"></a>
## *setAppContainerIPAddress [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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

<a id="method.setCurrentInputSource"></a>
## *setCurrentInputSource [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HomeKitTV plugin:

HomeKitTV interface events:

| Event | Description |
| :-------- | :-------- |
| [exit](#event.exit) |  |
| [stateChange](#event.stateChange) |  |
| [dispatchAirplayErrorEvent](#event.dispatchAirplayErrorEvent) |  |
| [dispatchOnAppStateChangeRequest](#event.dispatchOnAppStateChangeRequest) |  |
| [dispatchOnConnectionStatusChanged](#event.dispatchOnConnectionStatusChanged) |  |
| [dispatchOnEnabledStatusChanged](#event.dispatchOnEnabledStatusChanged) |  |
| [dispatchOnInputSourceChanged](#event.dispatchOnInputSourceChanged) |  |

<a id="event.exit"></a>
## *exit [<sup>event</sup>](#head.Notifications)*



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

<a id="event.stateChange"></a>
## *stateChange [<sup>event</sup>](#head.Notifications)*



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

<a id="event.dispatchAirplayErrorEvent"></a>
## *dispatchAirplayErrorEvent [<sup>event</sup>](#head.Notifications)*



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

<a id="event.dispatchOnAppStateChangeRequest"></a>
## *dispatchOnAppStateChangeRequest [<sup>event</sup>](#head.Notifications)*



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

<a id="event.dispatchOnConnectionStatusChanged"></a>
## *dispatchOnConnectionStatusChanged [<sup>event</sup>](#head.Notifications)*



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

<a id="event.dispatchOnEnabledStatusChanged"></a>
## *dispatchOnEnabledStatusChanged [<sup>event</sup>](#head.Notifications)*



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

<a id="event.dispatchOnInputSourceChanged"></a>
## *dispatchOnInputSourceChanged [<sup>event</sup>](#head.Notifications)*



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
