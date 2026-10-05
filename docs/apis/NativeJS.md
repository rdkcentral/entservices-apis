<!-- Generated automatically, DO NOT EDIT! -->
<a id="NativeJS_Module"></a>
# NativeJS Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/NativeJS/INativeJS.h)**

A NativeJS module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [INativeJS](#INativeJS)
    - [Methods](#INativeJS-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `NativeJS` module provides the following interface(s):

- INativeJS

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.NativeJS) |
| classname | string | Class name: *NativeJS* |
| locator | string | Library name: *libWPEFrameworkNativeJS.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="INativeJS"></a>
## INativeJS Interface

<a id="INativeJS-Methods"></a>
### Methods

The following methods are provided by the INativeJS Interface:

| Method | Description |
| :-------- | :-------- |
| [createApplication](#createApplication) | Create a NativeJS application. |
| [getApplications](#getApplications) | Get details of existing plugin. |
| [runApplication](#runApplication) | run a NativeJS application. |
| [runJavaScript](#runJavaScript) | Run a NativeJS code. |
| [terminateApplication](#terminateApplication) | Destroy a running NativeJS application. |

<a id="createApplication"></a>
## *createApplication*

This API creates a new NativeJS application with the specified options.

### Events Triggered
None
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
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.NativeJS.createApplication",
    "params": {
        "options": "{ \\\"name\\\": \\\"MyApp\\\", \\\"version\\\": \\\"1.0.0\\\" }"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.NativeJS.createApplication", "params": {"options": "{ \\\"name\\\": \\\"MyApp\\\", \\\"version\\\": \\\"1.0.0\\\" }"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "id": 1
    }
}
```

<a id="getApplications"></a>
## *getApplications*

This API retrieves details of all existing NativeJS applications.

### Events Triggered
None
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
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.NativeJS.getApplications"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.NativeJS.getApplications"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```

<a id="runApplication"></a>
## *runApplication*

This API runs the specified NativeJS application with the given URL.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | The ID for the application to run. |
| params.url | string | URL for the application to run. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.NativeJS.runApplication",
    "params": {
        "id": 1,
        "url": "http://example.com/myapp"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.NativeJS.runApplication", "params": {"id": 1, "url": "http://example.com/myapp"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": null
}
```

<a id="runJavaScript"></a>
## *runJavaScript*

This API runs the specified JavaScript code within the NativeJS plugin.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | The ID for the code to run. |
| params.code | string | The JavaScript code to execute. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.NativeJS.runJavaScript",
    "params": {
        "id": 1,
        "code": "console.log('Hello, World!');"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.NativeJS.runJavaScript", "params": {"id": 1, "code": "console.log('Hello, World!');"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": null
}
```

<a id="terminateApplication"></a>
## *terminateApplication*

This API terminates the specified NativeJS application.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | integer | The ID of the application to destroy. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.NativeJS.terminateApplication",
    "params": {
        "id": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.NativeJS.terminateApplication", "params": {"id": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```

