<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_TextTrackClosedCaptionsStyle_API"></a>
# TextTrackClosedCaptionsStyle API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

TextTrackClosedCaptionsStyle interface for Thunder framework.

(Defined with ITextTrackClosedCaptionsStyle in [ITextTrack.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITextTrack.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the TextTrackClosedCaptionsStyle interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

TextTrackClosedCaptionsStyle JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the TextTrackClosedCaptionsStyle interface:

TextTrackClosedCaptionsStyle interface methods:

| Method | Description |
| :-------- | :-------- |
| [setClosedCaptionsStyle](#method_setClosedCaptionsStyle) | Sets the ClosedCaptionsStyle |
| [getClosedCaptionsStyle](#method_getClosedCaptionsStyle) | Gets the current ClosedCaptionsStyle settings |
| [setFontFamily](#method_setFontFamily) | Setter for FontFamily |
| [getFontFamily](#method_getFontFamily) | Getter for FontFamily |
| [setFontSize](#method_setFontSize) | Setter for FontSize |
| [getFontSize](#method_getFontSize) | Getter for FontSize |
| [setFontColor](#method_setFontColor) | Setter for FontColor |
| [getFontColor](#method_getFontColor) | Getter for FontColor |
| [setFontOpacity](#method_setFontOpacity) | Setter for FontOpacity |
| [getFontOpacity](#method_getFontOpacity) | Getter for FontOpacity |
| [setFontEdge](#method_setFontEdge) | Setter for FontEdge |
| [getFontEdge](#method_getFontEdge) | Getter for FontEdge |
| [setFontEdgeColor](#method_setFontEdgeColor) | Setter for FontEdgeColor |
| [getFontEdgeColor](#method_getFontEdgeColor) | Getter for FontEdgeColor |
| [setBackgroundColor](#method_setBackgroundColor) | Setter for BackgroundColor |
| [getBackgroundColor](#method_getBackgroundColor) | Getter for BackgroundColor |
| [setBackgroundOpacity](#method_setBackgroundOpacity) | Setter for BackgroundOpacity |
| [getBackgroundOpacity](#method_getBackgroundOpacity) | Getter for BackgroundOpacity |
| [setWindowColor](#method_setWindowColor) | Setter for WindowColor |
| [getWindowColor](#method_getWindowColor) | Getter for WindowColor |
| [setWindowOpacity](#method_setWindowOpacity) | Setter for WindowOpacity |
| [getWindowOpacity](#method_getWindowOpacity) | Getter for WindowOpacity |

<a id="method_setClosedCaptionsStyle"></a>
## *setClosedCaptionsStyle [<sup>method</sup>](#head_Methods)*

Sets the ClosedCaptionsStyle.

### Description

For all values it is possible to keep or override the stream default.
* The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.style | object | mandatory | Contains the chosen styles |
| params.style.fontFamily | string | mandatory | Selected fontFamily (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |
| params.style.fontSize | string | mandatory | Selected fontSize (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |
| params.style.fontColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.fontOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| params.style.fontEdge | string | mandatory | Selected fontEdge (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |
| params.style.fontEdgeColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.backgroundColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.backgroundOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| params.style.windowColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.windowOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |

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
  "method": "<callsign>.1.setClosedCaptionsStyle",
  "params": {
    "style": {
      "fontFamily": "MONOSPACED_SERIF",
      "fontSize": "SMALL",
      "fontColor": "...",
      "fontOpacity": 0,
      "fontEdge": "NONE",
      "fontEdgeColor": "...",
      "backgroundColor": "...",
      "backgroundOpacity": 0,
      "windowColor": "...",
      "windowOpacity": 0
    }
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

<a id="method_getClosedCaptionsStyle"></a>
## *getClosedCaptionsStyle [<sup>method</sup>](#head_Methods)*

Gets the current ClosedCaptionsStyle settings.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.fontFamily | string | mandatory | Selected fontFamily (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |
| result.fontSize | string | mandatory | Selected fontSize (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |
| result.fontColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| result.fontOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| result.fontEdge | string | mandatory | Selected fontEdge (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |
| result.fontEdgeColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| result.backgroundColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| result.backgroundOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| result.windowColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| result.windowOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getClosedCaptionsStyle"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "fontFamily": "MONOSPACED_SERIF",
    "fontSize": "SMALL",
    "fontColor": "...",
    "fontOpacity": 0,
    "fontEdge": "NONE",
    "fontEdgeColor": "...",
    "backgroundColor": "...",
    "backgroundOpacity": 0,
    "windowColor": "...",
    "windowOpacity": 0
  }
}
```

<a id="method_setFontFamily"></a>
## *setFontFamily [<sup>method</sup>](#head_Methods)*

Setter for FontFamily.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.font | string | mandatory |  (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |

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
  "method": "<callsign>.1.setFontFamily",
  "params": {
    "font": "MONOSPACED_SERIF"
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

<a id="method_getFontFamily"></a>
## *getFontFamily [<sup>method</sup>](#head_Methods)*

Getter for FontFamily.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontFamily"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "MONOSPACED_SERIF"
}
```

<a id="method_setFontSize"></a>
## *setFontSize [<sup>method</sup>](#head_Methods)*

Setter for FontSize.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.size | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |

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
  "method": "<callsign>.1.setFontSize",
  "params": {
    "size": "SMALL"
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

<a id="method_getFontSize"></a>
## *getFontSize [<sup>method</sup>](#head_Methods)*

Getter for FontSize.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontSize"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "SMALL"
}
```

<a id="method_setFontColor"></a>
## *setFontColor [<sup>method</sup>](#head_Methods)*

Setter for FontColor.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

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
  "method": "<callsign>.1.setFontColor",
  "params": {
    "color": "..."
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

<a id="method_getFontColor"></a>
## *getFontColor [<sup>method</sup>](#head_Methods)*

Getter for FontColor.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontColor"
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

<a id="method_setFontOpacity"></a>
## *setFontOpacity [<sup>method</sup>](#head_Methods)*

Setter for FontOpacity.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

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
  "method": "<callsign>.1.setFontOpacity",
  "params": {
    "opacity": 0
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

<a id="method_getFontOpacity"></a>
## *getFontOpacity [<sup>method</sup>](#head_Methods)*

Getter for FontOpacity.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontOpacity"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_setFontEdge"></a>
## *setFontEdge [<sup>method</sup>](#head_Methods)*

Setter for FontEdge.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.edge | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |

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
  "method": "<callsign>.1.setFontEdge",
  "params": {
    "edge": "NONE"
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

<a id="method_getFontEdge"></a>
## *getFontEdge [<sup>method</sup>](#head_Methods)*

Getter for FontEdge.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontEdge"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "NONE"
}
```

<a id="method_setFontEdgeColor"></a>
## *setFontEdgeColor [<sup>method</sup>](#head_Methods)*

Setter for FontEdgeColor.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

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
  "method": "<callsign>.1.setFontEdgeColor",
  "params": {
    "color": "..."
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

<a id="method_getFontEdgeColor"></a>
## *getFontEdgeColor [<sup>method</sup>](#head_Methods)*

Getter for FontEdgeColor.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getFontEdgeColor"
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

<a id="method_setBackgroundColor"></a>
## *setBackgroundColor [<sup>method</sup>](#head_Methods)*

Setter for BackgroundColor.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

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
  "method": "<callsign>.1.setBackgroundColor",
  "params": {
    "color": "..."
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

<a id="method_getBackgroundColor"></a>
## *getBackgroundColor [<sup>method</sup>](#head_Methods)*

Getter for BackgroundColor.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getBackgroundColor"
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

<a id="method_setBackgroundOpacity"></a>
## *setBackgroundOpacity [<sup>method</sup>](#head_Methods)*

Setter for BackgroundOpacity.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

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
  "method": "<callsign>.1.setBackgroundOpacity",
  "params": {
    "opacity": 0
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

<a id="method_getBackgroundOpacity"></a>
## *getBackgroundOpacity [<sup>method</sup>](#head_Methods)*

Getter for BackgroundOpacity.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getBackgroundOpacity"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_setWindowColor"></a>
## *setWindowColor [<sup>method</sup>](#head_Methods)*

Setter for WindowColor.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

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
  "method": "<callsign>.1.setWindowColor",
  "params": {
    "color": "..."
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

<a id="method_getWindowColor"></a>
## *getWindowColor [<sup>method</sup>](#head_Methods)*

Getter for WindowColor.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getWindowColor"
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

<a id="method_setWindowOpacity"></a>
## *setWindowOpacity [<sup>method</sup>](#head_Methods)*

Setter for WindowOpacity.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

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
  "method": "<callsign>.1.setWindowOpacity",
  "params": {
    "opacity": 0
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

<a id="method_getWindowOpacity"></a>
## *getWindowOpacity [<sup>method</sup>](#head_Methods)*

Getter for WindowOpacity.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getWindowOpacity"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the TextTrackClosedCaptionsStyle interface:

TextTrackClosedCaptionsStyle interface events:

| Notification | Description |
| :-------- | :-------- |
| [onClosedCaptionsStyleChanged](#notification_onClosedCaptionsStyleChanged) | The ClosedCaptionsStyle settings has changed |
| [onFontFamilyChanged](#notification_onFontFamilyChanged) | Notify fontFamily Changed |
| [onFontSizeChanged](#notification_onFontSizeChanged) | Notify fontSize Changed |
| [onFontColorChanged](#notification_onFontColorChanged) | Notify fontColor Changed |
| [onFontOpacityChanged](#notification_onFontOpacityChanged) | Notify fontOpacity Changed |
| [onFontEdgeChanged](#notification_onFontEdgeChanged) | Notify fontEdge Changed |
| [onFontEdgeColorChanged](#notification_onFontEdgeColorChanged) | Notify fontEdgeColor Changed |
| [onBackgroundColorChanged](#notification_onBackgroundColorChanged) | Notify backgroundColor Changed |
| [onBackgroundOpacityChanged](#notification_onBackgroundOpacityChanged) | Notify backgroundOpacity Changed |
| [onWindowColorChanged](#notification_onWindowColorChanged) | Notify windowColor Changed |
| [onWindowOpacityChanged](#notification_onWindowOpacityChanged) | Notify windowOpacity Changed |

<a id="notification_onClosedCaptionsStyleChanged"></a>
## *onClosedCaptionsStyleChanged [<sup>notification</sup>](#head_Notifications)*

The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.style | object | mandatory |  |
| params.style.fontFamily | string | mandatory | Selected fontFamily (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |
| params.style.fontSize | string | mandatory | Selected fontSize (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |
| params.style.fontColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.fontOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| params.style.fontEdge | string | mandatory | Selected fontEdge (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |
| params.style.fontEdgeColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.backgroundColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.backgroundOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |
| params.style.windowColor | string | mandatory | #rrggbb Empty string implies - use stream default<br>*String length must be at most 7 chars.* |
| params.style.windowOpacity | integer | mandatory | 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default<br>*Value must be in range [-1..100].* |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onClosedCaptionsStyleChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onClosedCaptionsStyleChanged",
  "params": {
    "style": {
      "fontFamily": "MONOSPACED_SERIF",
      "fontSize": "SMALL",
      "fontColor": "...",
      "fontOpacity": 0,
      "fontEdge": "NONE",
      "fontEdgeColor": "...",
      "backgroundColor": "...",
      "backgroundOpacity": 0,
      "windowColor": "...",
      "windowOpacity": 0
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onClosedCaptionsStyleChanged``.

<a id="notification_onFontFamilyChanged"></a>
## *onFontFamilyChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontFamily Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.font | string | mandatory |  (must be one of the following: *CASUAL, CONTENT_DEFAULT, CURSIVE, MONOSPACED_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, PROPORTIONAL_SERIF, SMALL_CAPITAL*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontFamilyChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontFamilyChanged",
  "params": {
    "font": "MONOSPACED_SERIF"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontFamilyChanged``.

<a id="notification_onFontSizeChanged"></a>
## *onFontSizeChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontSize Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.size | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, EXTRA_LARGE, LARGE, REGULAR, SMALL*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontSizeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontSizeChanged",
  "params": {
    "size": "SMALL"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontSizeChanged``.

<a id="notification_onFontColorChanged"></a>
## *onFontColorChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontColor Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontColorChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontColorChanged",
  "params": {
    "color": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontColorChanged``.

<a id="notification_onFontOpacityChanged"></a>
## *onFontOpacityChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontOpacity Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontOpacityChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontOpacityChanged",
  "params": {
    "opacity": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontOpacityChanged``.

<a id="notification_onFontEdgeChanged"></a>
## *onFontEdgeChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontEdge Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.edge | string | mandatory |  (must be one of the following: *CONTENT_DEFAULT, DEPRESSED, LEFT_DROP_SHADOW, NONE, RAISED, RIGHT_DROP_SHADOW, UNIFORM*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontEdgeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontEdgeChanged",
  "params": {
    "edge": "NONE"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontEdgeChanged``.

<a id="notification_onFontEdgeColorChanged"></a>
## *onFontEdgeColorChanged [<sup>notification</sup>](#head_Notifications)*

Notify fontEdgeColor Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onFontEdgeColorChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFontEdgeColorChanged",
  "params": {
    "color": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFontEdgeColorChanged``.

<a id="notification_onBackgroundColorChanged"></a>
## *onBackgroundColorChanged [<sup>notification</sup>](#head_Notifications)*

Notify backgroundColor Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onBackgroundColorChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onBackgroundColorChanged",
  "params": {
    "color": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onBackgroundColorChanged``.

<a id="notification_onBackgroundOpacityChanged"></a>
## *onBackgroundOpacityChanged [<sup>notification</sup>](#head_Notifications)*

Notify backgroundOpacity Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onBackgroundOpacityChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onBackgroundOpacityChanged",
  "params": {
    "opacity": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onBackgroundOpacityChanged``.

<a id="notification_onWindowColorChanged"></a>
## *onWindowColorChanged [<sup>notification</sup>](#head_Notifications)*

Notify windowColor Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.color | string | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onWindowColorChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onWindowColorChanged",
  "params": {
    "color": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onWindowColorChanged``.

<a id="notification_onWindowOpacityChanged"></a>
## *onWindowOpacityChanged [<sup>notification</sup>](#head_Notifications)*

Notify windowOpacity Changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.opacity | integer | mandatory |  |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onWindowOpacityChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onWindowOpacityChanged",
  "params": {
    "opacity": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onWindowOpacityChanged``.

