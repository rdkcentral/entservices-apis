<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.Analytics_Plugin"></a>
# Analytics Plugin

**Version: [1.0.0]()**

A org.rdk.Analytics plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `Analytics` plugin allows to send analytics events to dedicated backends.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.Analytics*) |
| classname | string | Class name: *org.rdk.Analytics* |
| locator | string | Library name: *libWPEFrameworkAnalytics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.Analytics plugin:

Analytics interface methods:

| Method | Description |
| :-------- | :-------- |
| [sendEvent](#method.sendEvent) | Send event |


<a name="method.sendEvent"></a>
## *sendEvent [<sup>method</sup>](#head.Methods)*

Send event.

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
| params.eventPayload | object | The payload of the event |
