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
Event details are missing in the header file documentation.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | Name of the event |
| params.eventVersion | string | Version of the event |
| params.eventSource | string | Source of the event |
| params.eventSourceVersion | string | Version of the event source |
| params.cetList | IStringIterator | List of CETs |
| params.cetList[#] | string |  |
| params.epochTimestamp | integer | Epoch timestamp of the event |
| params.uptimeTimestamp | integer | Uptime timestamp of the event |
| params.appId | string | Durable App Id string |
| params.eventPayload | string | Payload of the event |
| params.additionalContext | string | Additional context for the event |
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
        "eventPayload": "",
        "additionalContext": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Analytics.sendEvent", "params": {"eventName": "", "eventVersion": "", "eventSource": "", "eventSourceVersion": "", "cetList": [""], "epochTimestamp": 0, "uptimeTimestamp": 0, "appId": "", "eventPayload": "", "additionalContext": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


