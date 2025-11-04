<!-- Generated automatically, DO NOT EDIT! -->
<a id="NativeJS_Plugin"></a>
# NativeJS Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/NativeJS/INativeJS.h)**

A NativeJS plugin for Thunder framework.

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

The `NativeJS` plugin provides an interface for NativeJS.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.NativeJS) |
| classname | string | Class name: *NativeJS* |
| locator | string | Library name: *libWPEFrameworkNativeJS.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the NativeJS plugin:

NativeJS interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [createApplication](#createApplication) | Create a NativeJS application. | NA |
| [getApplications](#getApplications) | Get details of existing plugin. | NA |
| [runApplication](#runApplication) | run a NativeJS application. | NA |
| [runJavaScript](#runJavaScript) | run a NativeJS code. | NA |
| [terminateApplication](#terminateApplication) | Destroy a running NativeJS application. | NA |

<a id="createApplication"></a>
## *createApplication [<sup>method</sup>](#Methods)*

Create a NativeJS application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.options | string | Additional options for creating the application. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.id | integer | This should have the id of the created application |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.NativeJS.createApplication",
    "params": {
        "options": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.NativeJS.createApplication", "params": {"options": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "id": 0
    }
}
```

<a id="getApplications"></a>
## *getApplications [<sup>method</sup>](#Methods)*

Get details of existing plugin.

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
    "method": "org.rdk.NativeJS.getApplications"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.NativeJS.getApplications"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="runApplication"></a>
## *runApplication [<sup>method</sup>](#Methods)*

run a NativeJS application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | This should have the id of the created application |
| params.url | string | URL for the application to run. |
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
    "method": "org.rdk.NativeJS.runApplication",
    "params": {
        "id": 0,
        "url": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.NativeJS.runApplication", "params": {"id": 0, "url": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="runJavaScript"></a>
## *runJavaScript [<sup>method</sup>](#Methods)*

run a NativeJS code.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | This should have the id of the created application |
| params.code | string |  |
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
    "method": "org.rdk.NativeJS.runJavaScript",
    "params": {
        "id": 0,
        "code": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.NativeJS.runJavaScript", "params": {"id": 0, "code": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="terminateApplication"></a>
## *terminateApplication [<sup>method</sup>](#Methods)*

Destroy a running NativeJS application.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | This should have the id of the created application |
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
    "method": "org.rdk.NativeJS.terminateApplication",
    "params": {
        "id": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.NativeJS.terminateApplication", "params": {"id": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```


