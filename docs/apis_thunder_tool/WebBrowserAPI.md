<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_WebBrowser_API"></a>
# WebBrowser API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

WebBrowser interface for Thunder framework.

(Defined with IWebBrowser in [IBrowser.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IBrowser.h))

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

This document describes purpose and functionality of the WebBrowser interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

WebBrowser JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the WebBrowser interface:

WebBrowser interface methods:

| Method | Description |
| :-------- | :-------- |
| [collectgarbage](#method_collectgarbage) | Initiate garbage collection |

<a id="method_collectgarbage"></a>
## *collectgarbage [<sup>method</sup>](#head_Methods)*

Initiate garbage collection.

### Parameters

This method takes no parameters.

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
  "method": "<callsign>.1.collectgarbage"
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

The following properties are provided by the WebBrowser interface:

WebBrowser interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [url](#property_url) | read/write | Page loaded in the browser |
| [visibility](#property_visibility) | read/write | Browser window visibility state |
| [fps](#property_fps) | read-only | Current framerate the browser is rendering at |
| [useragent](#property_useragent) | read/write | UserAgent string used by the browser |
| [localstorageenabled](#property_localstorageenabled) | read/write | Controls the local storage availability |
| [httpcookieacceptpolicy](#property_httpcookieacceptpolicy) | read/write | HTTP cookies accept policy |
| [bridgereply](#property_bridgereply) | write-only | Response for legacy $badger |
| [bridgeevent](#property_bridgeevent) | write-only | Send legacy $badger event |

<a id="property_url"></a>
## *url [<sup>property</sup>](#head_Properties)*

Provides access to the page loaded in the browser.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Page loaded in the browser |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.url"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "https://example.com"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.url",
  "params": "..."
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

<a id="property_visibility"></a>
## *visibility [<sup>property</sup>](#head_Properties)*

Provides access to the browser window visibility state.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Browser window visibility state (must be one of the following: *hidden, visible*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.visibility"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "visible"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.visibility",
  "params": "visible"
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

<a id="property_fps"></a>
## *fps [<sup>property</sup>](#head_Properties)*

Provides access to the current framerate the browser is rendering at.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Current FPS |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.fps"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_useragent"></a>
## *useragent [<sup>property</sup>](#head_Properties)*

Provides access to the userAgent string used by the browser.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | UserAgent string used by the browser |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.useragent"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WP"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.useragent",
  "params": "..."
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

<a id="property_localstorageenabled"></a>
## *localstorageenabled [<sup>property</sup>](#head_Properties)*

Provides access to the controls the local storage availability.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Controls the local storage availability |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.localstorageenabled"
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
  "method": "<callsign>.1.localstorageenabled",
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

<a id="property_httpcookieacceptpolicy"></a>
## *httpcookieacceptpolicy [<sup>property</sup>](#head_Properties)*

Provides access to the HTTP cookies accept policy.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | HTTP cookies accept policy (must be one of the following: *always, exclusivelyfrommaindocumentdomain, never, onlyfrommaindocumentdomain*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.httpcookieacceptpolicy"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "always"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.httpcookieacceptpolicy",
  "params": "never"
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

<a id="property_bridgereply"></a>
## *bridgereply [<sup>property</sup>](#head_Properties)*

Provides access to the response for legacy $badger.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Base64 encoded JSON string response to be delivered to $badger.callback |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.bridgereply",
  "params": "..."
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

<a id="property_bridgeevent"></a>
## *bridgeevent [<sup>property</sup>](#head_Properties)*

Provides access to the send legacy $badger event.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Base64 encoded JSON string response to be delivered to window.$badger.event |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.bridgeevent",
  "params": "..."
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

The following events are provided by the WebBrowser interface:

WebBrowser interface events:

| Notification | Description |
| :-------- | :-------- |
| [loadfinished](#notification_loadfinished) | Initial HTML document has been completely loaded and parsed |
| [loadfailed](#notification_loadfailed) | Browser failed to load page |
| [urlchange](#notification_urlchange) | Signals a URL change in the browser |
| [visibilitychange](#notification_visibilitychange) | Signals a visibility change of the browser |
| [pageclosure](#notification_pageclosure) | Notifies that the web page requests to close its window |

<a id="notification_loadfinished"></a>
## *loadfinished [<sup>notification</sup>](#head_Notifications)*

Initial HTML document has been completely loaded and parsed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.url | string | mandatory | The URL that has been loaded |
| params.httpstatus | integer | mandatory | The response code of main resource request |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "loadfinished",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.loadfinished",
  "params": {
    "url": "https://example.com",
    "httpstatus": 200
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.loadfinished``.

<a id="notification_loadfailed"></a>
## *loadfailed [<sup>notification</sup>](#head_Notifications)*

Browser failed to load page.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.url | string | mandatory | The URL that has been failed to load |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "loadfailed",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.loadfailed",
  "params": {
    "url": "https://example.com"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.loadfailed``.

<a id="notification_urlchange"></a>
## *urlchange [<sup>notification</sup>](#head_Notifications)*

Signals a URL change in the browser.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.url | string | mandatory | The URL that has been loaded or requested |
| params.loaded | boolean | mandatory | Loaded (true) or not (false) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "urlchange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.urlchange",
  "params": {
    "url": "https://example.com",
    "loaded": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.urlchange``.

<a id="notification_visibilitychange"></a>
## *visibilitychange [<sup>notification</sup>](#head_Notifications)*

Signals a visibility change of the browser.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.hidden | boolean | mandatory | Hidden (true) or visible (false) |

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
  "params": {
    "hidden": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.visibilitychange``.

<a id="notification_pageclosure"></a>
## *pageclosure [<sup>notification</sup>](#head_Notifications)*

Notifies that the web page requests to close its window.

### Notification Parameters

This notification carries no parameters.

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "pageclosure",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.pageclosure"
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.pageclosure``.

