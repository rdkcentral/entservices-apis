<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Analytics_Plugin"></a>
# Analytics Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Analytics/CHANGELOG.md)**

A Analytics plugin for Thunder framework.

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

The `Analytics` plugin provides an interface for Analytics.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Analytics) |
| classname | string | Class name: *Analytics* |
| locator | string | Library name: *libWPEFrameworkAnalytics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Analytics plugin:

Analytics interface methods:

| Method | Description |
| :-------- | :-------- |
| [sendEvent](#method.sendEvent) | Send an event to the analytics server |

<a id="method.sendEvent"></a>
## *sendEvent [<sup>method</sup>](#head.Methods)*

Send an event to the analytics server

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | Name of the event |
| params.eventVersion | string | Version of the event |
| params.eventSource | string | Source of the event |
| params.eventSourceVersion | string | Version of the event source |
| params.cetList | IStringIterator | List of CETs |
| params.cetList[#] | string | - |
| params.epochTimestamp | uint64_t | Epoch timestamp of the event |
| params.uptimeTimestamp | uint64_t | Uptime timestamp of the event |
| params.appId | string | Durable App Id string |
| params.eventPayload | string | Payload of the event |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Analytics.sendEvent",
    "params": {
        "eventName": "",
        "eventVersion": "",
        "eventSource": "",
        "eventSourceVersion": "",
        "cetList": [
            ""
        ],
        "epochTimestamp": 0,
        "uptimeTimestamp": 0,
        "appId": "",
        "eventPayload": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


