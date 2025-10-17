<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.TelemetryMetrics_Plugin"></a>
# TelemetryMetrics Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/TelemetryMetrics/CHANGELOG.md)**

A TelemetryMetrics plugin for Thunder framework.

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

The `TelemetryMetrics` plugin provides an interface for TelemetryMetrics.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TelemetryMetrics) |
| classname | string | Class name: *TelemetryMetrics* |
| locator | string | Library name: *libWPEFrameworkTelemetryMetrics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the TelemetryMetrics plugin:

TelemetryMetrics interface methods:

| Method | Description |
| :-------- | :-------- |
| [publish](#method.publish) | Publish the Telemetry Data |
| [record](#method.record) | Record the telementryMetrics add new hash values to existing hash |

<a id="method.publish"></a>
## *publish [<sup>method</sup>](#head.Methods)*

Publish the Telemetry Data

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | string | string identifier for the telemetry record. |
| params.markerName | string | Groups related metrics |
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
    "method": "org.rdk.TelemetryMetrics.publish",
    "params": {
        "id": "",
        "markerName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.TelemetryMetrics.publish", "params": {"id": "", "markerName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.record"></a>
## *record [<sup>method</sup>](#head.Methods)*

Record the telementryMetrics add new hash values to existing hash

### Events
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | string | string identifier for the telemetry record. |
| params.telemetryMetrics | string | jsonString hash  contains key value pair of telemetryData |
| params.markerName | string | Groups related metrics |
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
    "method": "org.rdk.TelemetryMetrics.record",
    "params": {
        "id": "",
        "telemetryMetrics": "",
        "markerName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.TelemetryMetrics.record", "params": {"id": "", "telemetryMetrics": "", "markerName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```


