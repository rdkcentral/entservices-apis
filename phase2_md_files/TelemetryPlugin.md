<!-- Generated automatically, DO NOT EDIT! -->
<a id="Telemetry_Plugin"></a>
# Telemetry Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Telemetry/ITelemetry.h)**

A Telemetry plugin for Thunder framework.

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

The `Telemetry` plugin provides an interface for Telemetry.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Telemetry) |
| classname | string | Class name: *Telemetry* |
| locator | string | Library name: *libWPEFrameworkTelemetry.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the Telemetry plugin:

Telemetry interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [abortReport](#abortReport) | Abort report upload | NA |
| [isOptOutTelemetry](#isOptOutTelemetry) | Checks the telemetry opt-out status. | NA |
| [logApplicationEvent](#logApplicationEvent) | Logs an application | NA |
| [setOptOutTelemetry](#setOptOutTelemetry) | Sets the telemetry opt-out status. | NA |
| [setReportProfileStatus](#setReportProfileStatus) | Sets the status of telemetry reporting | NA |
| [uploadReport](#uploadReport) | Uploading of telemetry report | onReportUpload |

<a id="abortReport"></a>
## *abortReport [<sup>method</sup>](#Methods)*

Abort report upload

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

<a id="isOptOutTelemetry"></a>
## *isOptOutTelemetry [<sup>method</sup>](#Methods)*

Checks the telemetry opt-out status.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.Opt-Out | bool |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Telemetry.isOptOutTelemetry"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.Telemetry.isOptOutTelemetry"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "Opt-Out": true,
        "success": true
    }
}
```

<a id="logApplicationEvent"></a>
## *logApplicationEvent [<sup>method</sup>](#Methods)*

Logs an application

### Events
Event details will be updated soon.
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
    "id": 2,
    "method": "org.rdk.Telemetry.logApplicationEvent",
    "params": {
        "eventName": "",
        "eventValue": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Telemetry.logApplicationEvent", "params": {"eventName": "", "eventValue": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="setOptOutTelemetry"></a>
## *setOptOutTelemetry [<sup>method</sup>](#Methods)*

Sets the telemetry opt-out status.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.Opt-Out | bool |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Telemetry.setOptOutTelemetry",
    "params": {
        "Opt-Out": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.Telemetry.setOptOutTelemetry", "params": {"Opt-Out": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="setReportProfileStatus"></a>
## *setReportProfileStatus [<sup>method</sup>](#Methods)*

Sets the status of telemetry reporting

### Events
Event details will be updated soon.
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
    "id": 4,
    "method": "org.rdk.Telemetry.setReportProfileStatus",
    "params": {
        "status": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.Telemetry.setReportProfileStatus", "params": {"status": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="uploadReport"></a>
## *uploadReport [<sup>method</sup>](#Methods)*

Uploading of telemetry report

### Events
| Event | Description |
| :-------- | :-------- |
| [onReportUpload ](#event.onReportUpload ) |  Triggered by callback from Telemetry after report uploading |
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
    "id": 5,
    "method": "org.rdk.Telemetry.uploadReport"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.Telemetry.uploadReport"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the Telemetry plugin:

Telemetry interface events:

| Event | Description |
| :-------- | :-------- |
| [onReportUpload](#onReportUpload) | Triggered by callback from Telemetry after report uploading |

<a id="onReportUpload"></a>
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
    "id": 6,
    "method": "org.rdk.Telemetry.onReportUpload",
    "params": {
        "telemetryUploadStatus": ""
    }
}
```
