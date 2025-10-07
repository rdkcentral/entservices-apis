<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_TextTrackTtmlStyle_API"></a>
# TextTrackTtmlStyle API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

TextTrackTtmlStyle interface for Thunder framework.

(Defined with ITextTrackTtmlStyle in [ITextTrack.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITextTrack.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the TextTrackTtmlStyle interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

TextTrackTtmlStyle JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the TextTrackTtmlStyle interface:

TextTrackTtmlStyle interface methods:

| Method | Description |
| :-------- | :-------- |
| [setTtmlStyleOverrides](#method_setTtmlStyleOverrides) | Sets global TTML override style |
| [getTtmlStyleOverrides](#method_getTtmlStyleOverrides) |  |

<a id="method_setTtmlStyleOverrides"></a>
## *setTtmlStyleOverrides [<sup>method</sup>](#head_Methods)*

Sets global TTML override style.

### Description

The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning
* that they will override styles given in the content.
* The value will be persisted in the system.
* The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.style | string | mandatory | Contains the chosen override for styles |

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
  "method": "<callsign>.1.setTtmlStyleOverrides",
  "params": {
    "style": "..."
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

<a id="method_getTtmlStyleOverrides"></a>
## *getTtmlStyleOverrides [<sup>method</sup>](#head_Methods)*

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Will receive the style overrides |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getTtmlStyleOverrides"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the TextTrackTtmlStyle interface:

TextTrackTtmlStyle interface events:

| Notification | Description |
| :-------- | :-------- |
| [onTtmlStyleOverridesChanged](#notification_onTtmlStyleOverridesChanged) | The TTML Style override settings has changed |

<a id="notification_onTtmlStyleOverridesChanged"></a>
## *onTtmlStyleOverridesChanged [<sup>notification</sup>](#head_Notifications)*

The TTML Style override settings has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.style | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onTtmlStyleOverridesChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTtmlStyleOverridesChanged",
  "params": {
    "style": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTtmlStyleOverridesChanged``.

