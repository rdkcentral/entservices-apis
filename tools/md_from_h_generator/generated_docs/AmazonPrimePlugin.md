<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.AmazonPrime_Plugin"></a>
# AmazonPrime Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/AmazonPrime/CHANGELOG.md)**

A AmazonPrime plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `AmazonPrime` plugin provides an interface for AmazonPrime.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.AmazonPrime) |
| classname | string | Class name: *AmazonPrime* |
| locator | string | Library name: *libWPEFrameworkAmazonPrime.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the AmazonPrime plugin:

AmazonPrime interface methods:

| Method | Description |
| :-------- | :-------- |
| [factoryResetRequest](#method.factoryResetRequest) | Factory reset amazon prime app data |
| [personalInfoRequest](#method.personalInfoRequest) | Request for personal access token to amazon prime app |
| [setDeepLink](#method.setDeepLink) | Set the deeplink command for amazon prime |
| [setLaunchReason](#method.setLaunchReason) | Set launch reason for amazon prime app |
| [StateChange](#method.StateChange) | Triggered whenever the App state changes |

<a id="method.factoryResetRequest"></a>
## *factoryResetRequest [<sup>method</sup>](#head.Methods)*

Factory reset amazon prime app data

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

<a id="method.personalInfoRequest"></a>
## *personalInfoRequest [<sup>method</sup>](#head.Methods)*

Request for personal access token to amazon prime app

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

<a id="method.setDeepLink"></a>
## *setDeepLink [<sup>method</sup>](#head.Methods)*

Set the deeplink command for amazon prime

### Events
No events are associated with this method.
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

<a id="method.setLaunchReason"></a>
## *setLaunchReason [<sup>method</sup>](#head.Methods)*

Set launch reason for amazon prime app

### Events
No events are associated with this method.
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

<a id="method.stateChange"></a>
## *stateChange [<sup>method</sup>](#head.Methods)*

Triggered whenever the App state changes

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | IAmazon::State | current state of amazon prime |
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
    "method": "org.rdk.AmazonPrime.stateChange",
    "params": {
        "state": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.AmazonPrime.stateChange", "params": {"state": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```


