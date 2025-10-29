<!-- Generated automatically, DO NOT EDIT! -->
<a id="AmazonPrime_Plugin"></a>
# AmazonPrime Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/AmazonPrime/IAmazonPrime.h)**

A AmazonPrime plugin for Thunder framework.

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

The `AmazonPrime` plugin provides an interface for AmazonPrime.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AmazonPrime) |
| classname | string | Class name: *AmazonPrime* |
| locator | string | Library name: *libWPEFrameworkAmazonPrime.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the AmazonPrime plugin:

AmazonPrime interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryResetRequest](#factoryResetRequest) | Factory reset amazon prime app data |
| [personalInfoRequest](#personalInfoRequest) | Request for personal access token to amazon prime app |
| [setDeepLink](#setDeepLink) | Set the deeplink command for amazon prime |
| [setLaunchReason](#setLaunchReason) | Set launch reason for amazon prime app |

<a id="factoryResetRequest"></a>
## *factoryResetRequest*

Factory reset amazon prime app data

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
    "id": 0,
    "method": "org.rdk.AmazonPrime.factoryResetRequest"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.AmazonPrime.factoryResetRequest"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="personalInfoRequest"></a>
## *personalInfoRequest*

Request for personal access token to amazon prime app

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
    "id": 1,
    "method": "org.rdk.AmazonPrime.personalInfoRequest"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.AmazonPrime.personalInfoRequest"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="setDeepLink"></a>
## *setDeepLink*

Set the deeplink command for amazon prime

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | app Deeplink command |
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
    "method": "org.rdk.AmazonPrime.setDeepLink",
    "params": {
        "command": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.AmazonPrime.setDeepLink", "params": {"command": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="setLaunchReason"></a>
## *setLaunchReason*

Set launch reason for amazon prime app

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.command | string | app Deeplink command |
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
    "method": "org.rdk.AmazonPrime.setLaunchReason",
    "params": {
        "command": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.AmazonPrime.setLaunchReason", "params": {"command": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the AmazonPrime plugin:

AmazonPrime interface events:

| Event | Description |
| :-------- | :-------- |
| [StateChange](#StateChange) | Triggered whenever the App state changes |

<a id="stateChange"></a>
## *stateChange*

Triggered whenever the App state changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | IAmazon::State | current state of amazon prime |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.AmazonPrime.stateChange",
    "params": {
        "state": ""
    }
}
```
