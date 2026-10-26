<!-- Generated automatically, DO NOT EDIT! -->
<a id="TextTrack_Module"></a>
# TextTrack Module

**Version: [1.5.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/TextTrack/ITextTrack.h)**

A TextTrack module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [ITextTrackClosedCaptionsStyle](#ITextTrackClosedCaptionsStyle)
    - [Methods](#ITextTrackClosedCaptionsStyle-Methods)
    - [Notifications](#ITextTrackClosedCaptionsStyle-Notifications)
  - [ITextTrackTtmlStyle](#ITextTrackTtmlStyle)
    - [Methods](#ITextTrackTtmlStyle-Methods)
    - [Notifications](#ITextTrackTtmlStyle-Notifications)
  - [ITextTrackCapabilities](#ITextTrackCapabilities)
    - [Methods](#ITextTrackCapabilities-Methods)
  - [ITextTrack](#ITextTrack)
    - [Methods](#ITextTrack-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `TextTrack` module provides the following interface(s):

- ITextTrackClosedCaptionsStyle
- ITextTrackTtmlStyle
- ITextTrackCapabilities
- ITextTrack

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TextTrack) |
| classname | string | Class name: *TextTrack* |
| locator | string | Library name: *libWPEFrameworkTextTrack.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="ITextTrackClosedCaptionsStyle"></a>
## ITextTrackClosedCaptionsStyle Interface

<a id="ITextTrackClosedCaptionsStyle-Methods"></a>
### Methods

The following methods are provided by the ITextTrackClosedCaptionsStyle Interface:

| Method | Description |
| :-------- | :-------- |
| [getBackgroundColor](#getBackgroundColor) | Gets the closed-caption background color. |
| [getBackgroundOpacity](#getBackgroundOpacity) | Gets the closed-caption background opacity. |
| [getClosedCaptionsStyle](#getClosedCaptionsStyle) | Gets the current ClosedCaptionsStyle settings. |
| [getFontColor](#getFontColor) | Gets the closed-caption font color. |
| [getFontEdge](#getFontEdge) | Gets the closed-caption font edge effect. |
| [getFontEdgeColor](#getFontEdgeColor) | Gets the closed-caption font edge color. |
| [getFontFamily](#getFontFamily) | Gets the closed-caption font family. |
| [getFontOpacity](#getFontOpacity) | Gets the closed-caption font opacity. |
| [getFontSize](#getFontSize) | Gets the closed-caption font size. |
| [getWindowColor](#getWindowColor) | Gets the closed-caption window color. |
| [getWindowOpacity](#getWindowOpacity) | Gets the closed-caption window opacity. |
| [setBackgroundColor](#setBackgroundColor) | Sets the closed-caption background color. |
| [setBackgroundOpacity](#setBackgroundOpacity) | Sets the closed-caption background opacity. |
| [setClosedCaptionsStyle](#setClosedCaptionsStyle) | Sets the ClosedCaptionsStyle. |
| [setFontColor](#setFontColor) | Sets the closed-caption font color. |
| [setFontEdge](#setFontEdge) | Sets the closed-caption font edge effect. |
| [setFontEdgeColor](#setFontEdgeColor) | Sets the closed-caption font edge color. |
| [setFontFamily](#setFontFamily) | Sets the closed-caption font family. |
| [setFontOpacity](#setFontOpacity) | Sets the closed-caption font opacity. |
| [setFontSize](#setFontSize) | Sets the closed-caption font size. |
| [setWindowColor](#setWindowColor) | Sets the closed-caption window color. |
| [setWindowOpacity](#setWindowOpacity) | Sets the closed-caption window opacity. |

<a id="getBackgroundColor"></a>
## *getBackgroundColor*

Returns the configured #rrggbb color or an empty string when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string | Receives the configured background color. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "method": "org.rdk.TextTrack.getBackgroundColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 18, "method": "org.rdk.TextTrack.getBackgroundColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "result": {
        "color": "#000000"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 18,
    "error": {
        "code": 1,
        "message": "Background color could not be retrieved."
    }
}
```

<a id="getBackgroundOpacity"></a>
## *getBackgroundOpacity*

Returns the configured opacity percentage, or -1 when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer | Receives the configured background opacity. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "method": "org.rdk.TextTrack.getBackgroundOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 19, "method": "org.rdk.TextTrack.getBackgroundOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "result": {
        "opacity": 50
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 19,
    "error": {
        "code": 1,
        "message": "Background opacity could not be retrieved."
    }
}
```

<a id="getClosedCaptionsStyle"></a>
## *getClosedCaptionsStyle*

Returns the global closed-caption style configuration.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.style | object | Receives the current style settings. |
| result.style.fontFamily | string | Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |
| result.style.fontSize | string | Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |
| result.style.fontColor | string |  |
| result.style.fontOpacity | integer |  |
| result.style.fontEdge | string | Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |
| result.style.fontEdgeColor | string |  |
| result.style.backgroundColor | string |  |
| result.style.backgroundOpacity | integer |  |
| result.style.windowColor | string |  |
| result.style.windowOpacity | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "method": "org.rdk.TextTrack.getClosedCaptionsStyle"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 20, "method": "org.rdk.TextTrack.getClosedCaptionsStyle"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "result": "{fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}"
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 20,
    "error": {
        "code": 1,
        "message": "Style could not be retrieved."
    }
}
```

<a id="getFontColor"></a>
## *getFontColor*

Returns the configured #rrggbb color or an empty string when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string | Receives the configured font color. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "method": "org.rdk.TextTrack.getFontColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 21, "method": "org.rdk.TextTrack.getFontColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "result": {
        "color": "#000000"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 21,
    "error": {
        "code": 1,
        "message": "Font color could not be retrieved."
    }
}
```

<a id="getFontEdge"></a>
## *getFontEdge*

Returns the currently configured global font edge effect.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.edge | string | Receives the configured font edge effect. Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "method": "org.rdk.TextTrack.getFontEdge"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 22, "method": "org.rdk.TextTrack.getFontEdge"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "result": {
        "edge": "RAISED"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 22,
    "error": {
        "code": 1,
        "message": "Font edge could not be retrieved."
    }
}
```

<a id="getFontEdgeColor"></a>
## *getFontEdgeColor*

Returns the configured #rrggbb color or an empty string when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string | Receives the configured font edge color. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "method": "org.rdk.TextTrack.getFontEdgeColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 23, "method": "org.rdk.TextTrack.getFontEdgeColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "result": {
        "color": "#000000"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 23,
    "error": {
        "code": 1,
        "message": "Font edge color could not be retrieved."
    }
}
```

<a id="getFontFamily"></a>
## *getFontFamily*

Returns the currently configured global font family.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.font | string | Receives the configured font family. Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "method": "org.rdk.TextTrack.getFontFamily"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 24, "method": "org.rdk.TextTrack.getFontFamily"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "result": {
        "font": "PROPORTIONAL_SANS_SERIF"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 24,
    "error": {
        "code": 1,
        "message": "Font family could not be retrieved."
    }
}
```

<a id="getFontOpacity"></a>
## *getFontOpacity*

Returns the configured opacity percentage, or -1 when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer | Receives the configured font opacity. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 25,
    "method": "org.rdk.TextTrack.getFontOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 25, "method": "org.rdk.TextTrack.getFontOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 25,
    "result": {
        "opacity": 50
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 25,
    "error": {
        "code": 1,
        "message": "Font opacity could not be retrieved."
    }
}
```

<a id="getFontSize"></a>
## *getFontSize*

Returns the currently configured global font size.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.size | string | Receives the configured font size. Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 26,
    "method": "org.rdk.TextTrack.getFontSize"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 26, "method": "org.rdk.TextTrack.getFontSize"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 26,
    "result": {
        "size": "REGULAR"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 26,
    "error": {
        "code": 1,
        "message": "Font size could not be retrieved."
    }
}
```

<a id="getWindowColor"></a>
## *getWindowColor*

Returns the configured #rrggbb color or an empty string when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string | Receives the configured window color. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "method": "org.rdk.TextTrack.getWindowColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 27, "method": "org.rdk.TextTrack.getWindowColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "result": {
        "color": "#000000"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 27,
    "error": {
        "code": 1,
        "message": "Window color could not be retrieved."
    }
}
```

<a id="getWindowOpacity"></a>
## *getWindowOpacity*

Returns the configured opacity percentage, or -1 when using the stream default.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer | Receives the configured window opacity. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 28,
    "method": "org.rdk.TextTrack.getWindowOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 28, "method": "org.rdk.TextTrack.getWindowOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 28,
    "result": {
        "opacity": 50
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 28,
    "error": {
        "code": 1,
        "message": "Window opacity could not be retrieved."
    }
}
```

<a id="setBackgroundColor"></a>
## *setBackgroundColor*

Provide a #rrggbb color or an empty string to use the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Background color to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 29,
    "method": "org.rdk.TextTrack.setBackgroundColor",
    "params": {
        "color": "#000000"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 29, "method": "org.rdk.TextTrack.setBackgroundColor", "params": {"color": "#000000"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 29,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 29,
    "error": {
        "code": 1,
        "message": "Background color could not be updated."
    }
}
```

<a id="setBackgroundOpacity"></a>
## *setBackgroundOpacity*

Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Background opacity to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "method": "org.rdk.TextTrack.setBackgroundOpacity",
    "params": {
        "opacity": 50
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 30, "method": "org.rdk.TextTrack.setBackgroundOpacity", "params": {"opacity": 50}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 30,
    "error": {
        "code": 1,
        "message": "Background opacity could not be updated."
    }
}
```

<a id="setClosedCaptionsStyle"></a>
## *setClosedCaptionsStyle*

For all values it is possible to keep or override the stream default. The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | object | Contains the chosen styles |
| params.style.fontFamily | string | Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |
| params.style.fontSize | string | Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |
| params.style.fontColor | string |  |
| params.style.fontOpacity | integer |  |
| params.style.fontEdge | string | Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |
| params.style.fontEdgeColor | string |  |
| params.style.backgroundColor | string |  |
| params.style.backgroundOpacity | integer |  |
| params.style.windowColor | string |  |
| params.style.windowOpacity | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 31,
    "method": "org.rdk.TextTrack.setClosedCaptionsStyle",
    "params": "{fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 31, "method": "org.rdk.TextTrack.setClosedCaptionsStyle", "params": "{fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 31,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 31,
    "error": {
        "code": 1,
        "message": "Style could not be updated."
    }
}
```

<a id="setFontColor"></a>
## *setFontColor*

Provide a #rrggbb color or an empty string to use the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Font color to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 32,
    "method": "org.rdk.TextTrack.setFontColor",
    "params": {
        "color": "#000000"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 32, "method": "org.rdk.TextTrack.setFontColor", "params": {"color": "#000000"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 32,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 32,
    "error": {
        "code": 1,
        "message": "Font color could not be updated."
    }
}
```

<a id="setFontEdge"></a>
## *setFontEdge*

The edge effect improves the visual separation of caption text from its background.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.edge | string | Font edge effect to apply. Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 33,
    "method": "org.rdk.TextTrack.setFontEdge",
    "params": {
        "edge": "RAISED"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 33, "method": "org.rdk.TextTrack.setFontEdge", "params": {"edge": "RAISED"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 33,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 33,
    "error": {
        "code": 1,
        "message": "Font edge could not be updated."
    }
}
```

<a id="setFontEdgeColor"></a>
## *setFontEdgeColor*

Provide a #rrggbb color or an empty string to use the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Font edge color to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 34,
    "method": "org.rdk.TextTrack.setFontEdgeColor",
    "params": {
        "color": "#000000"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 34, "method": "org.rdk.TextTrack.setFontEdgeColor", "params": {"color": "#000000"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 34,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 34,
    "error": {
        "code": 1,
        "message": "Font edge color could not be updated."
    }
}
```

<a id="setFontFamily"></a>
## *setFontFamily*

The selected family is applied unless the stream or a session-specific style overrides it.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.font | string | Font family to apply. Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 35,
    "method": "org.rdk.TextTrack.setFontFamily",
    "params": {
        "font": "PROPORTIONAL_SANS_SERIF"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 35, "method": "org.rdk.TextTrack.setFontFamily", "params": {"font": "PROPORTIONAL_SANS_SERIF"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 35,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 35,
    "error": {
        "code": 1,
        "message": "Font family could not be updated."
    }
}
```

<a id="setFontOpacity"></a>
## *setFontOpacity*

Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Font opacity to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 36,
    "method": "org.rdk.TextTrack.setFontOpacity",
    "params": {
        "opacity": 50
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 36, "method": "org.rdk.TextTrack.setFontOpacity", "params": {"opacity": 50}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 36,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 36,
    "error": {
        "code": 1,
        "message": "Font opacity could not be updated."
    }
}
```

<a id="setFontSize"></a>
## *setFontSize*

The size can use the content default or a configured caption size.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.size | string | Font size to apply. Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 37,
    "method": "org.rdk.TextTrack.setFontSize",
    "params": {
        "size": "REGULAR"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 37, "method": "org.rdk.TextTrack.setFontSize", "params": {"size": "REGULAR"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 37,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 37,
    "error": {
        "code": 1,
        "message": "Font size could not be updated."
    }
}
```

<a id="setWindowColor"></a>
## *setWindowColor*

Provide a #rrggbb color or an empty string to use the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Window color to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 38,
    "method": "org.rdk.TextTrack.setWindowColor",
    "params": {
        "color": "#000000"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 38, "method": "org.rdk.TextTrack.setWindowColor", "params": {"color": "#000000"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 38,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 38,
    "error": {
        "code": 1,
        "message": "Window color could not be updated."
    }
}
```

<a id="setWindowOpacity"></a>
## *setWindowOpacity*

Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Window opacity to apply. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 39,
    "method": "org.rdk.TextTrack.setWindowOpacity",
    "params": {
        "opacity": 50
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 39, "method": "org.rdk.TextTrack.setWindowOpacity", "params": {"opacity": 50}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 39,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 39,
    "error": {
        "code": 1,
        "message": "Window opacity could not be updated."
    }
}
```

<a id="ITextTrackClosedCaptionsStyle-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the ITextTrackClosedCaptionsStyle Interface:

| Event | Description |
| :-------- | :-------- |
| [onBackgroundColorChanged](#onBackgroundColorChanged) | Notifies that the configured background color changed. |
| [onBackgroundOpacityChanged](#onBackgroundOpacityChanged) | Notifies that the configured background opacity changed. |
| [onClosedCaptionsStyleChanged](#onClosedCaptionsStyleChanged) | The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings. |
| [onFontColorChanged](#onFontColorChanged) | Notifies that the configured font color changed. |
| [onFontEdgeChanged](#onFontEdgeChanged) | Notifies that the configured font edge changed. |
| [onFontEdgeColorChanged](#onFontEdgeColorChanged) | Notifies that the configured font edge color changed. |
| [onFontFamilyChanged](#onFontFamilyChanged) | Notifies that the configured font family changed. |
| [onFontOpacityChanged](#onFontOpacityChanged) | Notifies that the configured font opacity changed. |
| [onFontSizeChanged](#onFontSizeChanged) | Notifies that the configured font size changed. |
| [onWindowColorChanged](#onWindowColorChanged) | Notifies that the configured window color changed. |
| [onWindowOpacityChanged](#onWindowOpacityChanged) | Notifies that the configured window opacity changed. |

<a id="onBackgroundColorChanged"></a>
## *onBackgroundColorChanged*

The new value can be retrieved with GetBackgroundColor().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Updated background color. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextTrack.onBackgroundColorChanged",
    "params": {
        "color": "#000000"
    }
}
```

<a id="onBackgroundOpacityChanged"></a>
## *onBackgroundOpacityChanged*

The new value can be retrieved with GetBackgroundOpacity().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Updated background opacity percentage, or -1 for the stream default. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 43,
    "method": "org.rdk.TextTrack.onBackgroundOpacityChanged",
    "params": {
        "opacity": 50
    }
}
```

<a id="onClosedCaptionsStyleChanged"></a>
## *onClosedCaptionsStyleChanged*

The notification carries the updated global style values.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | object | Updated closed-caption style. |
| params.style.fontFamily | string | Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |
| params.style.fontSize | string | Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |
| params.style.fontColor | string |  |
| params.style.fontOpacity | integer |  |
| params.style.fontEdge | string | Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |
| params.style.fontEdgeColor | string |  |
| params.style.backgroundColor | string |  |
| params.style.backgroundOpacity | integer |  |
| params.style.windowColor | string |  |
| params.style.windowOpacity | integer |  |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 44,
    "method": "org.rdk.TextTrack.onClosedCaptionsStyleChanged",
    "params": "{fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}"
}
```

<a id="onFontColorChanged"></a>
## *onFontColorChanged*

The new value can be retrieved with GetFontColor().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Updated font color. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 45,
    "method": "org.rdk.TextTrack.onFontColorChanged",
    "params": {
        "color": "#000000"
    }
}
```

<a id="onFontEdgeChanged"></a>
## *onFontEdgeChanged*

The new value can be retrieved with GetFontEdge().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.edge | string | Updated font edge effect. Possible values: CONTENT_DEFAULT, NONE, RAISED, DEPRESSED, UNIFORM, LEFT_DROP_SHADOW, RIGHT_DROP_SHADOW |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 46,
    "method": "org.rdk.TextTrack.onFontEdgeChanged",
    "params": {
        "edge": "RAISED"
    }
}
```

<a id="onFontEdgeColorChanged"></a>
## *onFontEdgeColorChanged*

The new value can be retrieved with GetFontEdgeColor().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Updated font edge color. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 47,
    "method": "org.rdk.TextTrack.onFontEdgeColorChanged",
    "params": {
        "color": "#000000"
    }
}
```

<a id="onFontFamilyChanged"></a>
## *onFontFamilyChanged*

The new value can be retrieved with GetFontFamily().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.font | string | Updated font family. Possible values: CONTENT_DEFAULT, MONOSPACED_SERIF, PROPORTIONAL_SERIF, MONOSPACE_SANS_SERIF, PROPORTIONAL_SANS_SERIF, CASUAL, CURSIVE, SMALL_CAPITAL |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 48,
    "method": "org.rdk.TextTrack.onFontFamilyChanged",
    "params": {
        "font": "PROPORTIONAL_SANS_SERIF"
    }
}
```

<a id="onFontOpacityChanged"></a>
## *onFontOpacityChanged*

The new value can be retrieved with GetFontOpacity().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Updated font opacity percentage, or -1 for the stream default. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 49,
    "method": "org.rdk.TextTrack.onFontOpacityChanged",
    "params": {
        "opacity": 50
    }
}
```

<a id="onFontSizeChanged"></a>
## *onFontSizeChanged*

The new value can be retrieved with GetFontSize().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.size | string | Updated font size. Possible values: CONTENT_DEFAULT, SMALL, REGULAR, LARGE, EXTRA_LARGE |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 50,
    "method": "org.rdk.TextTrack.onFontSizeChanged",
    "params": {
        "size": "REGULAR"
    }
}
```

<a id="onWindowColorChanged"></a>
## *onWindowColorChanged*

The new value can be retrieved with GetWindowColor().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string | Updated window color. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 52,
    "method": "org.rdk.TextTrack.onWindowColorChanged",
    "params": {
        "color": "#000000"
    }
}
```

<a id="onWindowOpacityChanged"></a>
## *onWindowOpacityChanged*

The new value can be retrieved with GetWindowOpacity().

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer | Updated window opacity percentage, or -1 for the stream default. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 53,
    "method": "org.rdk.TextTrack.onWindowOpacityChanged",
    "params": {
        "opacity": 50
    }
}
```

---

<a id="ITextTrackTtmlStyle"></a>
## ITextTrackTtmlStyle Interface

<a id="ITextTrackTtmlStyle-Methods"></a>
### Methods

The following methods are provided by the ITextTrackTtmlStyle Interface:

| Method | Description |
| :-------- | :-------- |
| [getTtmlStyleOverrides](#getTtmlStyleOverrides) | Gets the global TTML style overrides |
| [setTtmlStyleOverrides](#setTtmlStyleOverrides) | Sets global TTML override style. |

<a id="getTtmlStyleOverrides"></a>
## *getTtmlStyleOverrides*

Returns the persisted global override string applied to TTML sessions.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.style | string | Will receive the style overrides |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 40,
    "method": "org.rdk.TextTrack.getTtmlStyleOverrides"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 40, "method": "org.rdk.TextTrack.getTtmlStyleOverrides"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 40,
    "result": {
        "style": "color: white;fontSize: 1.2em"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 40,
    "error": {
        "code": 1,
        "message": "TTML style overrides could not be retrieved."
    }
}
```

<a id="setTtmlStyleOverrides"></a>
## *setTtmlStyleOverrides*

The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning that they will override styles given in the content. The value will be persisted in the system. The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | string | Contains the chosen override for styles |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 41,
    "method": "org.rdk.TextTrack.setTtmlStyleOverrides",
    "params": {
        "style": "color: white;fontSize: 1.2em"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 41, "method": "org.rdk.TextTrack.setTtmlStyleOverrides", "params": {"style": "color: white;fontSize: 1.2em"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 41,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 41,
    "error": {
        "code": 1,
        "message": "TTML style overrides could not be updated."
    }
}
```

<a id="ITextTrackTtmlStyle-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the ITextTrackTtmlStyle Interface:

| Event | Description |
| :-------- | :-------- |
| [onTtmlStyleOverridesChanged](#onTtmlStyleOverridesChanged) | The TTML Style override settings has changed. |

<a id="onTtmlStyleOverridesChanged"></a>
## *onTtmlStyleOverridesChanged*

The notification contains the updated global TTML style override string.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | string | Updated TTML style overrides. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 51,
    "method": "org.rdk.TextTrack.onTtmlStyleOverridesChanged",
    "params": {
        "style": "color: white;fontSize: 1.2em"
    }
}
```

---

<a id="ITextTrackCapabilities"></a>
## ITextTrackCapabilities Interface

<a id="ITextTrackCapabilities-Methods"></a>
### Methods

The following methods are provided by the ITextTrackCapabilities Interface:

| Method | Description |
| :-------- | :-------- |
| [getCapabilities](#getCapabilities) | Retrieves an iterator over all supported TextTrack capabilities. |
| [getCapability](#getCapability) | Queries whether a specific TextTrack capability is supported by the implementation. |

<a id="getCapabilities"></a>
## *getCapabilities*

Enumerates the capabilities supported by this implementation.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.capabilities | array | Iterator providing the list of supported capabilities. |
| result.capabilities[#] | string | Possible values: UNSET, FIREBOLT_MIGRATION |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "method": "org.rdk.TextTrack.getCapabilities"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 16, "method": "org.rdk.TextTrack.getCapabilities"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "result": [
        "[FIREBOLT_MIGRATION]"
    ]
}
```


#### Error Response (Core::ERROR_NOT_SUPPORTED)

```json
{
    "jsonrpc": "2.0",
    "id": 16,
    "error": {
        "code": 22,
        "message": "Retrieving capabilities is not supported."
    }
}
```

<a id="getCapability"></a>
## *getCapability*

Query support before relying on optional TextTrack functionality.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.capability | string | The capability to query . Possible values: UNSET, FIREBOLT_MIGRATION |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hasCapability | bool | Indicates whether the queried capability is supported. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "method": "org.rdk.TextTrack.getCapability",
    "params": {
        "capability": "FIREBOLT_MIGRATION"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 17, "method": "org.rdk.TextTrack.getCapability", "params": {"capability": "FIREBOLT_MIGRATION"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "result": {
        "hasCapability": true
    }
}
```


#### Error Response (Core::ERROR_NOT_SUPPORTED)

```json
{
    "jsonrpc": "2.0",
    "id": 17,
    "error": {
        "code": 22,
        "message": "Capability querying is not supported."
    }
}
```

---

<a id="ITextTrack"></a>
## ITextTrack Interface

<a id="ITextTrack-Methods"></a>
### Methods

The following methods are provided by the ITextTrack Interface:

| Method | Description |
| :-------- | :-------- |
| [closeSession](#closeSession) | Closes a previously opened render session. |
| [muteSession](#muteSession) | Mutes a render session. |
| [openSession](#openSession) | Opens a new renderSession. |
| [pauseSession](#pauseSession) | Pauses a render session. |
| [resetSession](#resetSession) | Resets a previously opened render session back to its opened state. |
| [resumeSession](#resumeSession) | Resumes a paused render session. |
| [sendSessionData](#sendSessionData) | Sends data of Closed Captions, Captions or Timed Text data to a render session. |
| [sendSessionTimestamp](#sendSessionTimestamp) | Sends the current timestamp from a media player to a render session. |
| [setPreviewText](#setPreviewText) | Sets a static text in the display for preview purposes. |
| [setSessionClosedCaptionsService](#setSessionClosedCaptionsService) | Sets the render session into CC mode. |
| [setSessionDvbSubtitleSelection](#setSessionDvbSubtitleSelection) | Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743) |
| [setSessionSCTESelection](#setSessionSCTESelection) | Set the render session into SCTE mode |
| [setSessionTTMLSelection](#setSessionTTMLSelection) | Set the render session into TTML mode |
| [setSessionTeletextSelection](#setSessionTeletextSelection) | Set the render session into Teletext mode, providing the teletext caption page for presentation |
| [setSessionWebVTTSelection](#setSessionWebVTTSelection) | Set the render session into WebVTT mode |
| [unMuteSession](#unMuteSession) | UnMute will unhide the rendering of Captions. |

<a id="closeSession"></a>
## *closeSession*

Any created windows and surfaces is destroyed

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session to close |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.TextTrack.closeSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.TextTrack.closeSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "Session could not be closed."
    }
}
```

<a id="muteSession"></a>
## *muteSession*

Caption rendering is hidden until the session is unmuted.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.TextTrack.muteSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.TextTrack.muteSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "Session could not be muted."
    }
}
```

<a id="openSession"></a>
## *openSession*

If a session is already running on the supplied displayHandle, the sessionId for this session is returned. If the session is instead newly opened, the session type is not set and display is muted. Use one of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayHandle | string | Is an encoding of the wayland display name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sessionId | integer | On success the returned session id  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.TextTrack.openSession",
    "params": {
        "displayHandle": "wayland-0"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.TextTrack.openSession", "params": {"displayHandle": "wayland-0"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": {
        "sessionId": 1
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 1,
        "message": "Session could not be opened."
    }
}
```

<a id="pauseSession"></a>
## *pauseSession*

Any text rendered remains on screen and any text due to be rendered soon is held until the render session is resumed.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.TextTrack.pauseSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.TextTrack.pauseSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "error": {
        "code": 1,
        "message": "Session could not be paused."
    }
}
```

<a id="resetSession"></a>
## *resetSession*

The state will be like after calling OpenSession()

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session to reset |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.TextTrack.resetSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.TextTrack.resetSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "error": {
        "code": 1,
        "message": "Session could not be reset."
    }
}
```

<a id="resumeSession"></a>
## *resumeSession*

Rendering continues for the session after it has been resumed.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.TextTrack.resumeSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.TextTrack.resumeSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "error": {
        "code": 1,
        "message": "Session could not be resumed."
    }
}
```

<a id="sendSessionData"></a>
## *sendSessionData*

Data is decoded according to the selected session type and rendered according to its presentation timestamps.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.type | string | Is the type of data. Possible values: PES, TTML, CC, WEBVTT |
| params.displayOffsetMs | integer | Is added to a timestamp in the data to determine when to display it. The offset is in milliseconds and can be negative. Not all types support this. |
| params.data | string | Is the data to display, properly formatted as per the expectations of the type used |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.TextTrack.sendSessionData",
    "params": {
        "sessionId": 1,
        "type": "TTML",
        "displayOffsetMs": 0,
        "data": "<tt>Caption</tt>"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.TextTrack.sendSessionData", "params": {"sessionId": 1, "type": "TTML", "displayOffsetMs": 0, "data": "<tt>Caption</tt>"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "error": {
        "code": 1,
        "message": "Session data could not be sent."
    }
}
```

<a id="sendSessionTimestamp"></a>
## *sendSessionTimestamp*

The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.mediaTimestampMs | integer | Is a timestamp |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.TextTrack.sendSessionTimestamp",
    "params": {
        "sessionId": 1,
        "mediaTimestampMs": 123456
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 7, "method": "org.rdk.TextTrack.sendSessionTimestamp", "params": {"sessionId": 1, "mediaTimestampMs": 123456}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "error": {
        "code": 1,
        "message": "Session timestamp could not be sent."
    }
}
```

<a id="setPreviewText"></a>
## *setPreviewText*

The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.text | string | Is the text to display |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "method": "org.rdk.TextTrack.setPreviewText",
    "params": {
        "sessionId": 1,
        "text": "Sample captions"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 8, "method": "org.rdk.TextTrack.setPreviewText", "params": {"sessionId": 1, "text": "Sample captions"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "result": null
}
```


#### Error Response (Core::ERROR_NOT_SUPPORTED)

```json
{
    "jsonrpc": "2.0",
    "id": 8,
    "error": {
        "code": 22,
        "message": "if preview is not supported"
    }
}
```

<a id="setSessionClosedCaptionsService"></a>
## *setSessionClosedCaptionsService*

Selecting the specified CC service to decode and display in the specified render session. This should be done before starting the injection of data. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.service | string | Identifies the service to display  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "method": "org.rdk.TextTrack.setSessionClosedCaptionsService",
    "params": {
        "sessionId": 1,
        "service": "CC3"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 9, "method": "org.rdk.TextTrack.setSessionClosedCaptionsService", "params": {"sessionId": 1, "service": "CC3"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 9,
    "error": {
        "code": 1,
        "message": "Closed-caption service could not be selected."
    }
}
```

<a id="setSessionDvbSubtitleSelection"></a>
## *setSessionDvbSubtitleSelection*

Selects the composition and ancillary pages used to decode and present DVB subtitles in the render session.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.compositionPageId | integer | Is the one Id |
| params.ancillaryPageId | integer | Is the other Id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection",
    "params": {
        "sessionId": 1,
        "compositionPageId": 1,
        "ancillaryPageId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 10, "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection", "params": {"sessionId": 1, "compositionPageId": 1, "ancillaryPageId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 10,
    "error": {
        "code": 1,
        "message": "DVB subtitle pages could not be selected."
    }
}
```

<a id="setSessionSCTESelection"></a>
## *setSessionSCTESelection*

Selects SCTE data for decoding and presentation in the render session.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "method": "org.rdk.TextTrack.setSessionSCTESelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 11, "method": "org.rdk.TextTrack.setSessionSCTESelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 11,
    "error": {
        "code": 1,
        "message": "SCTE mode could not be selected."
    }
}
```

<a id="setSessionTTMLSelection"></a>
## *setSessionTTMLSelection*

Selects TTML data for decoding and presentation in the render session.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "method": "org.rdk.TextTrack.setSessionTTMLSelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 12, "method": "org.rdk.TextTrack.setSessionTTMLSelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 12,
    "error": {
        "code": 1,
        "message": "TTML mode could not be selected."
    }
}
```

<a id="setSessionTeletextSelection"></a>
## *setSessionTeletextSelection*

Selects the requested Teletext page for decoding and presentation in the render session.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
| params.page | integer | The user selected teletext caption page 100-899 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "method": "org.rdk.TextTrack.setSessionTeletextSelection",
    "params": {
        "sessionId": 1,
        "page": 100
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 13, "method": "org.rdk.TextTrack.setSessionTeletextSelection", "params": {"sessionId": 1, "page": 100}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 13,
    "error": {
        "code": 1,
        "message": "Teletext page could not be selected."
    }
}
```

<a id="setSessionWebVTTSelection"></a>
## *setSessionWebVTTSelection*

Selects WebVTT data for decoding and presentation in the render session.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "method": "org.rdk.TextTrack.setSessionWebVTTSelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 14, "method": "org.rdk.TextTrack.setSessionWebVTTSelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 14,
    "error": {
        "code": 1,
        "message": "WebVTT mode could not be selected."
    }
}
```

<a id="unMuteSession"></a>
## *unMuteSession*

A newly created session is muted and should be unmuted to me visible

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | Is the session |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "method": "org.rdk.TextTrack.unMuteSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 15, "method": "org.rdk.TextTrack.unMuteSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 15,
    "error": {
        "code": 1,
        "message": "Session could not be unmuted."
    }
}
```

