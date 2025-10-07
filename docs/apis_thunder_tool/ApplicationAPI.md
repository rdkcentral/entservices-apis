<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Application_API"></a>
# Application API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

Application interface for Thunder framework.

(Defined with IApplication in [IApplication.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IApplication.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the Application interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

Application JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the Application interface:

Application interface methods:

| Method | Description |
| :-------- | :-------- |
| [reset](#method_reset) | Resets application data |

<a id="method_reset"></a>
## *reset [<sup>method</sup>](#head_Methods)*

Resets application data.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | string | mandatory | Type of reset to perform (must be one of the following: *Cache, Credentials, Factory, Recordings*) |

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
  "method": "<callsign>.1.reset",
  "params": "Cache"
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

<a id="head_Properties"></a>
# Properties

The following properties are provided by the Application interface:

Application interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [identifier](#property_identifier) | read-only | Application-specific identification string |
| [contentlink](#property_contentlink) | write-only | URI of the associated application-specific content |
| [launchpoint](#property_launchpoint) | read/write | Application launching point |
| [visible](#property_visible) | read/write | Current application visibility |
| [language](#property_language) | read/write | Current application user interface language |

<a id="property_identifier"></a>
## *identifier [<sup>property</sup>](#head_Properties)*

Provides access to the application-specific identification string.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Identifier string |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.identifier"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "..."
}
```

<a id="property_contentlink"></a>
## *contentlink [<sup>property</sup>](#head_Properties)*

Provides access to the URI of the associated application-specific content.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Content URI |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.contentlink",
  "params": "https://youtube.com"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_launchpoint"></a>
## *launchpoint [<sup>property</sup>](#head_Properties)*

Provides access to the application launching point.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Application launching point (must be one of the following: *ApplicationList, ApplicationPromotion, BannerAd, ChannelBar, ChannelNumber, ChannelZap, DedicatedButton, DedicatedIcon, Dial, EpgGrid, IntegratedTile, PowerOn, PowerOnFromDedicatedButton, Restart, ResumedFromScreenSaver, ResumedFromStandby, SearchContinuation, SearchResult, SuspendedPowerOn, SuspendedRestart, TitleRecommendation, TouchGesture, Undefined, VisualGesture, VoiceControl, VoiceSearchResult, WebBrowser*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.launchpoint"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Dial"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.launchpoint",
  "params": "Dial"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_visible"></a>
## *visible [<sup>property</sup>](#head_Properties)*

Provides access to the current application visibility.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Current application visibility |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.visible"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.visible",
  "params": false
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_language"></a>
## *language [<sup>property</sup>](#head_Properties)*

Provides access to the current application user interface language.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Language string as per RFC5646 |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.language"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "en"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.language",
  "params": "en"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Application interface:

Application interface events:

| Notification | Description |
| :-------- | :-------- |
| [visibilitychange](#notification_visibilitychange) | Application visibility changes |

<a id="notification_visibilitychange"></a>
## *visibilitychange [<sup>notification</sup>](#head_Notifications)*

Application visibility changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | boolean | mandatory | Denotes if application is currently hidden |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "visibilitychange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.visibilitychange",
  "params": false
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.visibilitychange``.

