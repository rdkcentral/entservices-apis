<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.NativeJS_Plugin"></a>
# NativeJS Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/NativeJS/CHANGELOG.md)**

A NativeJS plugin for Thunder framework.

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

The `NativeJS` plugin provides an interface for NativeJS.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.NativeJS) |
| classname | string | Class name: *NativeJS* |
| locator | string | Library name: *libWPEFrameworkNativeJS.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the NativeJS plugin:

NativeJS interface methods:

| Method | Description |
| :-------- | :-------- |
| [createApplication](#method.createApplication) | Create a NativeJS application. |
| [getApplications](#method.getApplications) | Get details of existing plugin. |
| [runApplication](#method.runApplication) | run a NativeJS application. |
| [runJavaScript](#method.runJavaScript) | run a NativeJS code. |
| [terminateApplication](#method.terminateApplication) | Destroy a running NativeJS application. |

<a id="method.createApplication"></a>
## *createApplication [<sup>method</sup>](#head.Methods)*

Create a NativeJS application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.options | std::string | Additional options for creating the application. |
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

<a id="method.getApplications"></a>
## *getApplications [<sup>method</sup>](#head.Methods)*

Get details of existing plugin.

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

<a id="method.runApplication"></a>
## *runApplication [<sup>method</sup>](#head.Methods)*

run a NativeJS application.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | This should have the id of the created application |
| params.url | std::string | URL for the application to run. |
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

<a id="method.runJavaScript"></a>
## *runJavaScript [<sup>method</sup>](#head.Methods)*

run a NativeJS code.

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | This should have the id of the created application |
| params.code | std::string |  |
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

<a id="method.terminateApplication"></a>
## *terminateApplication [<sup>method</sup>](#head.Methods)*

Destroy a running NativeJS application.

### Events
Event details are missing in the header file documentation.
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


