<!-- Generated automatically, DO NOT EDIT! -->
<a id="Telemetry_Module"></a>
# Telemetry Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Telemetry/ITelemetry.h)**

A Telemetry module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ITelemetry](#ITelemetry)
    - [Methods](#ITelemetry-Methods)
    - [Notifications](#ITelemetry-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Telemetry` module provides the following interface(s):

- ITelemetry

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Telemetry) |
| classname | string | Class name: *Telemetry* |
| locator | string | Library name: *libWPEFrameworkTelemetry.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ITelemetry"></a>
## ITelemetry Interface

<a id="ITelemetry-Methods"></a>
### Methods

The following methods are provided by the ITelemetry Interface:

| Method | Description |
| :-------- | :-------- |
| [abortReport](#abortReport) | Abort report upload |
| [isOptOutTelemetry](#isOptOutTelemetry) | Checks the telemetry opt-out status. |
| [logApplicationEvent](#logApplicationEvent) | Logs an application |
| [setOptOutTelemetry](#setOptOutTelemetry) | Sets the telemetry opt-out status. |
| [setReportProfileStatus](#setReportProfileStatus) | Sets the status of telemetry reporting |
| [uploadReport](#uploadReport) | Uploading of telemetry report |

<a id="abortReport"></a>
## *abortReport*

Invoked by the Telemetry service to abort an ongoing telemetry report upload. Components implementing this interface should terminate the upload process and handle any necessary cleanup.

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "- Failed to abort the report upload."
    }
}
```

<a id="isOptOutTelemetry"></a>
## *isOptOutTelemetry*

Invoked by the Telemetry service to check the current opt-out status for telemetry reporting. Components implementing this interface should return the current configuration indicating whether telemetry data collection is opted out.

### Events Triggered
None
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "- Failed to retrieve the opt-out status."
    }
}
```

<a id="logApplicationEvent"></a>
## *logApplicationEvent*

Invoked by the Telemetry service to log an application  Components implementing this interface should record the event with the provided name and value.

### Events Triggered
None
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
        "eventName": "UserLogin",
        "eventValue": "Success"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.Telemetry.logApplicationEvent", "params": {"eventName": "UserLogin", "eventValue": "Success"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "- Failed to log the "
    }
}
```

<a id="setOptOutTelemetry"></a>
## *setOptOutTelemetry*

Invoked by the Telemetry service to set the opt-out status for telemetry reporting. Components implementing this interface should update their internal configuration to reflect the user's preference regarding telemetry data collection.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.Opt-Out | bool |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | struct |

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "- Failed to set the OptOut status."
    }
}
```

<a id="setReportProfileStatus"></a>
## *setReportProfileStatus*

Invoked by the Telemetry service to set the status of telemetry reporting. Components implementing this interface should update their internal state to reflect the new reporting status.

### Events Triggered
None
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
        "status": "enabled"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.Telemetry.setReportProfileStatus", "params": {"status": "enabled"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "- Failed to set the status."
    }
}
```

<a id="uploadReport"></a>
## *uploadReport*

Invoked by the Telemetry service to upload a telemetry report. Components implementing this interface should initiate the report upload process and handle the result accordingly.

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "- Failed to initiate the report upload."
    }
}
```

<a id="ITelemetry-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the ITelemetry Interface:

| Event | Description |
| :-------- | :-------- |
| [onReportUpload](#onReportUpload) | Triggered by callback from Telemetry after report uploading |

<a id="onReportUpload"></a>
## *onReportUpload*

Invoked by the Telemetry service after a report has been uploaded. Components implementing this interface should handle the upload status accordingly.

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
        "telemetryUploadStatus": "success"
    }
}
```

