<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Telemetry_Plugin"></a>
# Telemetry Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Telemetry/CHANGELOG.md)**

A Telemetry plugin for Thunder framework.

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

The `Telemetry` plugin provides an interface for Telemetry.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Telemetry) |
| classname | string | Class name: *Telemetry* |
| locator | string | Library name: *libWPEFrameworkTelemetry.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Telemetry plugin:

Telemetry interface methods:

| Method | Description |
| :-------- | :-------- |
| [abortReport](#method.abortReport) | Abort report upload |
| [logApplicationEvent](#method.logApplicationEvent) | Logs an application |
| [setReportProfileStatus](#method.setReportProfileStatus) | Sets the status of telemetry reporting |
| [uploadReport](#method.uploadReport) | Uploading of telemetry report |

<a id="method.abortReport"></a>
## *abortReport [<sup>method</sup>](#head.Methods)*

Abort report upload

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
    "method": "org.rdk.Telemetry.abortReport"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Telemetry.abortReport"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.logApplicationEvent"></a>
## *logApplicationEvent [<sup>method</sup>](#head.Methods)*

Logs an application

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | string |
| params.eventValue | string | string |
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
    "method": "org.rdk.Telemetry.logApplicationEvent",
    "params": {
        "eventName": "",
        "eventValue": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Telemetry.logApplicationEvent", "params": {"eventName": "", "eventValue": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.setReportProfileStatus"></a>
## *setReportProfileStatus [<sup>method</sup>](#head.Methods)*

Sets the status of telemetry reporting

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | string |
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
    "method": "org.rdk.Telemetry.setReportProfileStatus",
    "params": {
        "status": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Telemetry.setReportProfileStatus", "params": {"status": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.uploadReport"></a>
## *uploadReport [<sup>method</sup>](#head.Methods)*

Uploading of telemetry report

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
    "id": 3,
    "method": "org.rdk.Telemetry.uploadReport"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Telemetry.uploadReport"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Telemetry plugin:

Telemetry interface events:

| Event | Description |
| :-------- | :-------- |
| [onReportUpload](#event.onReportUpload) | Triggered by callback from Telemetry after report uploading |

<a id="event.onReportUpload"></a>
## *onReportUpload [<sup>event</sup>](#head.Notifications)*

Triggered by callback from Telemetry after report uploading

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.telemetryUploadStatus | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Telemetry.onReportUpload",
    "params": {
        "telemetryUploadStatus": ""
    }
}
```
