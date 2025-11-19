<!-- Generated automatically, DO NOT EDIT! -->
<a id="Analytics_Plugin"></a>
# Analytics Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/Analytics/IAnalytics.h)**

A Analytics plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `Analytics` plugin provides an interface for Analytics.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Analytics) |
| classname | string | Class name: *Analytics* |
| locator | string | Library name: *libWPEFrameworkAnalytics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |
| configuration | object |  |
| configuration.loggername | string | Logger name used by backend |
| configuration.loggerversion | string | Logger version used by backend |
| configuration?.eventsmap | string | <sup>*(optional)*</sup> Optional path to json file with array of mapped events name |
| configuration.backendlib | string | Name of backend library |

<a id="Methods"></a>
# Methods

The following methods are provided by the Analytics plugin:

Analytics interface methods:

| Method | Description |
| :-------- | :-------- |
| [sendEvent](#sendEvent) | Send an event to the analytics server |

<a id="sendEvent"></a>
## *sendEvent*

Send an event to the analytics server

### Events
Event details will be updated soon.
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
| params?.epochTimestamp | integer | <sup>*(optional)*</sup> Timestamp for the START of this event, epoch time, in ms UTC |
| params?.uptimeTimestamp | integer | <sup>*(optional)*</sup> Timestamp for the START of this event, uptime of the device, in ms. ONLY to be used when Time quality is not good |
| params?.appId | string | <sup>*(optional)*</sup> Durable App ID string |
| params.eventPayload | object | Custom payload of the event in JSON format. User defined colection of objects and keys. May be an empty object |
| params.eventPayload.keyOrObject | string | User defined custom key or object |
| params?.additionalContext | string | <sup>*(optional)*</sup> Additional context for the event in JSON format. Opaque string passed through without schema validation |

### Result

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
        "epochTimestamp": 1721906631000,
        "uptimeTimestamp": 35000,
        "appId": "app-id-app1",
        "eventPayload": {
            "keyOrObject": "value1"
        },
        "additionalContext": "{}"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.Analytics.sendEvent", "params": {"eventName": "", "eventVersion": "", "eventSource": "", "eventSourceVersion": "", "cetList": [""], "epochTimestamp": 0, "uptimeTimestamp": 0, "appId": "", "eventPayload": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```


