<!-- Generated automatically, DO NOT EDIT! -->
<a id="Cobalt_Plugin"></a>
# Cobalt Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Cobalt)**

A Cobalt plugin for Thunder framework.

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

The `Cobalt` plugin provides an interface for Cobalt.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Cobalt) |
| classname | string | Class name: *Cobalt* |
| locator | string | Library name: *libWPEFrameworkCobalt.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the Cobalt plugin:

Cobalt interface methods:

| Method | Description |
| :-------- | :-------- |
| [get](#get) |  |
| [isValid](#isValid) |  |
| [next](#next) |  |
| [reset](#reset) |  |
| [set](#set) |  |

<a id="get"></a>
## *get*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string |  |
| params.key | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Cobalt.get",
    "params": {
        "nameSpace": "",
        "key": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Cobalt.get", "params": {"nameSpace": "", "key": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "value": ""
    }
}
```

<a id="isValid"></a>
## *isValid*



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
    "id": 1,
    "method": "org.rdk.Cobalt.isValid"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Cobalt.isValid"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="next"></a>
## *next*



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
    "id": 2,
    "method": "org.rdk.Cobalt.next"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Cobalt.next"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="reset"></a>
## *reset*



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
    "id": 3,
    "method": "org.rdk.Cobalt.reset"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Cobalt.reset"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="set"></a>
## *set*



### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string |  |
| params.key | string |  |
| params.value | string |  |
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
    "method": "org.rdk.Cobalt.set",
    "params": {
        "nameSpace": "",
        "key": "",
        "value": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.Cobalt.set", "params": {"nameSpace": "", "key": "", "value": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the Cobalt plugin:

Cobalt interface events:

| Event | Description |
| :-------- | :-------- |
| [modified](#modified) |  |

<a id="modified"></a>
## *modified*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nameSpace | string |  |
| params.key | string |  |
| params.value | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Cobalt.modified",
    "params": {
        "nameSpace": "",
        "key": "",
        "value": ""
    }
}
```
