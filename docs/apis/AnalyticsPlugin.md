<!-- Generated automatically, DO NOT EDIT! -->
<a name="Analytics_Plugin"></a>
# Analytics Plugin

**Version: [1.0.0]()**

A org.rdk.Analytics plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `Analytics` plugin allows to send analytics events to dedicated backends. Currently the SIFT backend is supported.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.Analytics*) |
| classname | string | Class name: *org.rdk.Analytics* |
| locator | string | Library name: *libWPEFrameworkAnalytics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |
| configuration | object |  |
| configuration.deviceosname | string | Device OS name |
| configuration?.eventsmap | string | <sup>*(optional)*</sup> Optional path to json file with array of mapped events name |
| configuration.sift | object |  |
| configuration.sift.schema2 | boolean | If true, enables Sift 2.0 schema, otherwise uses Sift 1.0 schema |
| configuration.sift.commonschema | string | Sift schema common schema |
| configuration.sift?.env | string | <sup>*(optional)*</sup> Sift schema environment |
| configuration.sift.productname | string | Sift schema product name |
| configuration.sift.loggername | string | Sift schema logger name |
| configuration.sift.loggerversion | string | Sift schema logger version |
| configuration.sift.platformdefault | string | Sift schema platform default value |
| configuration.sift.maxrandomisationwindowtime | number | Sift uploader max randomisation window time of posting queued events in seconds |
| configuration.sift.maxeventsinpost | number | Sift uploader max events in single post |
| configuration.sift.maxretries | number | Sift uploader max retries posting events |
| configuration.sift.minretryperiod | number | Sift uploader min retry period seconds |
| configuration.sift.maxretryperiod | number | Sift uploader max retry period seconds |
| configuration.sift.exponentialperiodicfactor | number | Sift uploader exponential periodic factor for retry delay |
| configuration.sift.storepath | number | Sift store path to persistent queue with events |
| configuration.sift.eventslimit | number | Sift store events limit |
| configuration.sift.url | string | URL to Sift server endpoint |
| configuration.sift?.cetmap | object | <sup>*(optional)*</sup> Privacy settings to CET mapping |
| configuration.sift?.cetmap.privacy-setting-x | string | Example privacy setting |
| configuration.sift?.cetdroponalltags | boolean | <sup>*(optional)*</sup> If true, drop event if all CET appended to the event |
| configuration.sift?.ceteventtype | string | <sup>*(optional)*</sup> Privacy specific event type string to parse Exclusion Policy |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.Analytics plugin:

Analytics interface methods:

| Method | Description |
| :-------- | :-------- |
| [sendEvent](#sendEvent) | Enqueue an event to be sent to the SIFT analytics backend |


<a name="sendEvent"></a>
## *sendEvent*

Enqueue an event to be sent to the SIFT analytics backend.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.eventName | string | Name of the event |
| params?.eventVersion | string | <sup>*(optional)*</sup> Version number of event schema |
| params.eventSource | string | Name of the component that originates the event (Durable App ID if an App) |
| params.eventSourceVersion | string | Version number for the component that originates the event |
| params.cetList | array | An array of Capability Exclusion Tags to be included on the report. Each CET will exclude the event from being processed for the specified process, any may result in the event being dropped. May be an array of length zero |
| params.cetList[#] | string |  |
| params?.epochTimestamp | integer | <sup>*(optional)*</sup> Timestamp for the START of this event, epoch time, in ms UTC |
| params?.uptimeTimestamp | integer | <sup>*(optional)*</sup> Timestamp for the START of this event, uptime of the device, in ms. ONLY to be used when Time quality is not good |
| params?.appId | string | <sup>*(optional)*</sup> Durable App ID string |
| params.eventPayload | object | Custom payload of the event in JSON format. User defined colection of objects and keys. May be an empty object |
| params.eventPayload.keyOrObject | string | User defined custom key or object |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.Analytics.sendEvent",
    "params": {
        "eventName": "app_summary",
        "eventVersion": "1.0.0",
        "eventSource": "epg",
        "eventSourceVersion": "1.0.0",
        "cetList": [
            "cet1"
        ],
        "epochTimestamp": 1721906631000,
        "uptimeTimestamp": 35000,
        "appId": "app-id-app1",
        "eventPayload": {
            "keyOrObject": "value1"
        }
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

