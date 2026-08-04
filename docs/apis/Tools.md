<!-- Generated automatically, DO NOT EDIT! -->
<a id="Tools_Module"></a>
# Tools Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Tools/ITools.h)**

A Tools module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ITools](#ITools)
    - [Methods](#ITools-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Tools` module provides the following interface(s):

- ITools

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Tools) |
| classname | string | Class name: *Tools* |
| locator | string | Library name: *libWPEFrameworkTools.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ITools"></a>
## ITools Interface

<a id="ITools-Methods"></a>
### Methods

The following methods are provided by the ITools Interface:

| Method | Description |
| :-------- | :-------- |
| [generateKeys](#generateKeys) | Generates local key events for each key entry. |
| [generateRemoteKeys](#generateRemoteKeys) | Generates remote key events for each key entry. |

<a id="generateKeys"></a>
## *generateKeys*

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Tools.generateKeys"
}
```


#### CURL Command

```curl
curl  -v -H "Content-Type: application/json" -d '{  "jsonrpc": "2.0",  "id": 42,  "method": "org.rdk.Tools.generateKeys",  "params": {"keys" : [{"code": 1,"modifier": "CTRL","delay": 0,"duration": 0}] } }' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
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
        "message": "Failed to generate one or more key events"
    }
}
```


#### Error Response (Core::ERROR_INVALID_INPUT_LENGTH)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 14,
        "message": "Input key list is empty"
    }
}
```
<a id="generateRemoteKeys"></a>
## *generateRemoteKeys*

Implementations should generate key press and key release events via /dev/uinput and honor delay/duration values.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Tools.generateRemoteKeys"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Tools.generateRemoteKeys"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Failed to generate one or more remote key events"
    }
}
```


#### Error Response (Core::ERROR_INVALID_INPUT_LENGTH)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 14,
        "message": "Input key list is empty"
    }
}
```

