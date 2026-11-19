<!-- Generated automatically, DO NOT EDIT! -->
<a id="DABAdapter_Module"></a>
# DABAdapter Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DABAdapter/IDABAdapter.h)**

A DABAdapter module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IDABAdapter](#IDABAdapter)
    - [Methods](#IDABAdapter-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DABAdapter` module provides the following interface(s):

- IDABAdapter

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DABAdapter) |
| classname | string | Class name: *DABAdapter* |
| locator | string | Library name: *libWPEFrameworkDABAdapter.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IDABAdapter"></a>
## IDABAdapter Interface

<a id="IDABAdapter-Methods"></a>
### Methods

The following methods are provided by the IDABAdapter Interface:

| Method | Description |
| :-------- | :-------- |
| [publishDABResponse](#publishDABResponse) | Publish response to the DAB request received via AppActions. |

<a id="publishDABResponse"></a>
## *publishDABResponse*

Publish response to the DAB request received via AppActions.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.correlationData | string | The correlation data received in `org.rdk.dab.request` app action. |
| params.payload | string | DAB compliant response payload, opaque json string. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.DABAdapter.publishDABResponse",
    "params": {
        "correlationData": "",
        "payload": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.DABAdapter.publishDABResponse", "params": {"correlationData": "", "payload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "Failure"
    }
}
```

