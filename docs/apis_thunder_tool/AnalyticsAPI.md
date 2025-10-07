<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Analytics_API"></a>
# Analytics API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Analytics interface for Thunder framework.

(Defined with IAnalytics in [IAnalytics.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IAnalytics.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Analytics interface (version 1.0.0). It includes detailed specification about its methods provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

Analytics JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Analytics interface:

Analytics interface methods:

| Method | Description |
| :-------- | :-------- |
| [SendEvent](#method_SendEvent) / [sendEvent](#method_SendEvent) | Send an event to the analytics server |

<a id="method_SendEvent"></a>
## *SendEvent [<sup>method</sup>](#head_Methods)*

Send an event to the analytics server.

> ``sendEvent`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.eventName | string | mandatory | Name of the event |
| params.eventVersion | string | mandatory | Version of the event |
| params.eventSource | string | mandatory | Source of the event |
| params.eventSourceVersion | string | mandatory | Version of the event source |
| params.cetList | array | mandatory | List of CETs |
| params.cetList[#] | string | mandatory |  |
| params.epochTimestamp | integer | mandatory | Epoch timestamp of the event |
| params.uptimeTimestamp | integer | mandatory | Uptime timestamp of the event |
| params.appId | string | mandatory | Durable App Id string |
| params.eventPayload | string | mandatory | Payload of the event |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.SendEvent",
  "params": {
    "eventName": "...",
    "eventVersion": "...",
    "eventSource": "...",
    "eventSourceVersion": "...",
    "cetList": [
      "..."
    ],
    "epochTimestamp": 0,
    "uptimeTimestamp": 0,
    "appId": "...",
    "eventPayload": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

