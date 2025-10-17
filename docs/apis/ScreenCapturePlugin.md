<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ScreenCapture_Plugin"></a>
# ScreenCapture Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/ScreenCapture/CHANGELOG.md)**

A ScreenCapture plugin for Thunder framework.

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

The `ScreenCapture` plugin provides an interface for ScreenCapture.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.ScreenCapture) |
| classname | string | Class name: *ScreenCapture* |
| locator | string | Library name: *libWPEFrameworkScreenCapture.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the ScreenCapture plugin:

ScreenCapture interface methods:

| Method | Description |
| :-------- | :-------- |
| [uploadScreenCapture](#method.uploadScreenCapture) | Takes a screenshot and uploads it to the specified URL |

<a id="method.uploadScreenCapture"></a>
## *uploadScreenCapture [<sup>method</sup>](#head.Methods)*

Takes a screenshot and uploads it to the specified URL

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.url | string | string |
| params.callGUID | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | success |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.ScreenCapture.uploadScreenCapture",
    "params": {
        "url": "",
        "callGUID": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.ScreenCapture.uploadScreenCapture", "params": {"url": "", "callGUID": ""}}' http://127.0.0.1:9998/jsonrpc
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



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the ScreenCapture plugin:

ScreenCapture interface events:

| Event | Description |
| :-------- | :-------- |
| [uploadComplete](#event.uploadComplete) | Triggered after uploading a screen capture |

<a id="event.uploadComplete"></a>
## *uploadComplete [<sup>event</sup>](#head.Notifications)*

Triggered after uploading a screen capture

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | bool | boolean |
| params.message | string | string |
| params.call_guid | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.ScreenCapture.uploadComplete",
    "params": {
        "status": true,
        "message": "",
        "call_guid": ""
    }
}
```
