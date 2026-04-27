<!-- Generated automatically, DO NOT EDIT! -->
<a id="UnifiedCASManagement_Plugin"></a>
# UnifiedCASManagement Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/UnifiedCASManagement/IUnifiedCASManagement.h)**

A UnifiedCASManagement plugin for Thunder framework.

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

The `UnifiedCASManagement` plugin provides an interface for UnifiedCASManagement.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.UnifiedCASManagement) |
| classname | string | Class name: *UnifiedCASManagement* |
| locator | string | Library name: *libWPEFrameworkUnifiedCASManagement.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the UnifiedCASManagement plugin:

UnifiedCASManagement interface methods:

| Method | Description |
| :-------- | :-------- |
| [manage](#manage) | Manage a well-known CAS (setup CAS management session) |
| [send](#send) | Sends data to the remote CAS |
| [unmanage](#unmanage) | Destroy a management session |

<a id="manage"></a>
## *manage*

Manage a well-known CAS (setup CAS management session)

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mediaurl | string | The URL to tune to (tune://, ocap://, http://, https://) |
| params.mode | string | The use of the tune request |
| params.managementType | string | Type of CAS management |
| params.casinitdata | string | CAS specific initdata for the selected media |
| params.casocdmid | string | The well-known OCDM ID of the CAS to use |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Returns true if the operation succeeded, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.UnifiedCASManagement.manage",
    "params": {
        "mediaurl": "",
        "mode": "MODE_NONE",
        "managementType": "MANAGE_FULL",
        "casinitdata": "",
        "casocdmid": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.UnifiedCASManagement.manage", "params": {"mediaurl": "", "mode": "MODE_NONE", "managementType": "MANAGE_FULL", "casinitdata": "", "casocdmid": ""}}' http://127.0.0.1:9998/jsonrpc
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
        "message": "Operation failed"
    }
}
```

<a id="send"></a>
## *send*

Sends data to the remote CAS

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.payload | string | Data to transfer. Can be base64 coded if required |
| params.source | string | Origin of the data |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Returns true if the operation succeeded, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.UnifiedCASManagement.send",
    "params": {
        "payload": "",
        "source": "PUBLIC"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.UnifiedCASManagement.send", "params": {"payload": "", "source": "PUBLIC"}}' http://127.0.0.1:9998/jsonrpc
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
        "message": "Operation failed"
    }
}
```

<a id="unmanage"></a>
## *unmanage*

Destroy a management session

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Returns true if the operation succeeded, false otherwise |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.UnifiedCASManagement.unmanage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.UnifiedCASManagement.unmanage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Operation failed"
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the UnifiedCASManagement plugin:

UnifiedCASManagement interface events:

| Event | Description |
| :-------- | :-------- |
| [data](#data) | Sent when the CAS needs to send data to the caller |

<a id="onDataReceived"></a>
## *onDataReceived*

Sent when the CAS needs to send data to the caller

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.payload | string | Data to transfer. Can be base64 coded if required |
| params.source | string | Origin of the data |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.UnifiedCASManagement.onDataReceived",
    "params": {
        "payload": "",
        "source": "PUBLIC"
    }
}
```
