<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.TextTrack_Plugin"></a>
# TextTrack Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/TextTrack/CHANGELOG.md)**

A TextTrack plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `TextTrack` plugin provides an interface for TextTrack.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TextTrack) |
| classname | string | Class name: *TextTrack* |
| locator | string | Library name: *libWPEFrameworkTextTrack.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the TextTrack plugin:

TextTrack interface methods:

| Method | Description |
| :-------- | :-------- |
| [closeSession](#method.closeSession) | Closes a previously opened render session. |
| [getBackgroundColor](#method.getBackgroundColor) | Getter for BackgroundColor |
| [getBackgroundOpacity](#method.getBackgroundOpacity) | Getter for BackgroundOpacity |
| [getClosedCaptionsStyle](#method.getClosedCaptionsStyle) | Gets the current ClosedCaptionsStyle settings. |
| [getFontColor](#method.getFontColor) | Getter for FontColor |
| [getFontEdge](#method.getFontEdge) | Getter for FontEdge |
| [getFontEdgeColor](#method.getFontEdgeColor) | Getter for FontEdgeColor |
| [getFontFamily](#method.getFontFamily) | Getter for FontFamily |
| [getFontOpacity](#method.getFontOpacity) | Getter for FontOpacity |
| [getFontSize](#method.getFontSize) | Getter for FontSize |
| [getTtmlStyleOverrides](#method.getTtmlStyleOverrides) |  |
| [getWindowColor](#method.getWindowColor) | Getter for WindowColor |
| [getWindowOpacity](#method.getWindowOpacity) | Getter for WindowOpacity |
| [muteSession](#method.muteSession) | Mute will hide rendering of Captions |
| [openSession](#method.openSession) | Opens a new renderSession. |
| [pauseSession](#method.pauseSession) | Pauses a render session. |
| [resetSession](#method.resetSession) | Resets a previously opened render session back to its opened state. |
| [resumeSession](#method.resumeSession) | Resumed a paused session |
| [sendSessionData](#method.sendSessionData) | Sends data of Closed Captions, Captions or Timed Text data to a render session. |
| [sendSessionTimestamp](#method.sendSessionTimestamp) | Sends the current timestamp from a media player to a render session. |
| [setBackgroundColor](#method.setBackgroundColor) | Setter for BackgroundColor |
| [setBackgroundOpacity](#method.setBackgroundOpacity) | Setter for BackgroundOpacity |
| [setClosedCaptionsStyle](#method.setClosedCaptionsStyle) | Sets the ClosedCaptionsStyle. |
| [setFontColor](#method.setFontColor) | Setter for FontColor |
| [setFontEdge](#method.setFontEdge) | Setter for FontEdge |
| [setFontEdgeColor](#method.setFontEdgeColor) | Setter for FontEdgeColor |
| [setFontFamily](#method.setFontFamily) | Setter for FontFamily |
| [setFontOpacity](#method.setFontOpacity) | Setter for FontOpacity |
| [setFontSize](#method.setFontSize) | Setter for FontSize |
| [setPreviewText](#method.setPreviewText) | Sets a static text in the display for preview purposes. |
| [setSessionClosedCaptionsService](#method.setSessionClosedCaptionsService) | Sets the render session into CC mode. |
| [setSessionDvbSubtitleSelection](#method.setSessionDvbSubtitleSelection) | Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743) |
| [setSessionSCTESelection](#method.setSessionSCTESelection) | Set the render session into SCTE mode |
| [setSessionTTMLSelection](#method.setSessionTTMLSelection) | Set the render session into TTML mode |
| [setSessionTeletextSelection](#method.setSessionTeletextSelection) | Set the render session into Teletext mode, providing the teletext caption page for presentation |
| [setSessionWebVTTSelection](#method.setSessionWebVTTSelection) | Set the render session into WebVTT mode |
| [setTtmlStyleOverrides](#method.setTtmlStyleOverrides) | Sets global TTML override style. |
| [setWindowColor](#method.setWindowColor) | Setter for WindowColor |
| [setWindowOpacity](#method.setWindowOpacity) | Setter for WindowOpacity |
| [unMuteSession](#method.unMuteSession) | UnMute will unhide the rendering of Captions. |

<a id="method.closeSession"></a>
## *closeSession [<sup>method</sup>](#head.Methods)*

Any created windows and surfaces is destroyed

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
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
    "method": "org.rdk.TextTrack.closeSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.TextTrack.closeSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.getBackgroundColor"></a>
## *getBackgroundColor [<sup>method</sup>](#head.Methods)*

Getter for BackgroundColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.TextTrack.getBackgroundColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.TextTrack.getBackgroundColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "color": ""
    }
}
```

<a id="method.getBackgroundOpacity"></a>
## *getBackgroundOpacity [<sup>method</sup>](#head.Methods)*

Getter for BackgroundOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.TextTrack.getBackgroundOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.TextTrack.getBackgroundOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "opacity": 0
    }
}
```

<a id="method.getClosedCaptionsStyle"></a>
## *getClosedCaptionsStyle [<sup>method</sup>](#head.Methods)*

Gets the current ClosedCaptionsStyle settings.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.style | ClosedCaptionsStyle | Contains the chosen styles |
| result.style.fontFamily | string |  |
| result.style.fontSize | string |  |
| result.style.fontColor | string |  |
| result.style.fontOpacity | integer |  |
| result.style.fontEdge | string |  |
| result.style.fontEdgeColor | string |  |
| result.style.backgroundColor | string |  |
| result.style.backgroundOpacity | integer |  |
| result.style.windowColor | string |  |
| result.style.windowOpacity | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.TextTrack.getClosedCaptionsStyle"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.TextTrack.getClosedCaptionsStyle"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "fontFamily": "CONTENT_DEFAULT",
        "fontSize": "CONTENT_DEFAULT",
        "fontColor": "",
        "fontOpacity": 0,
        "fontEdge": "CONTENT_DEFAULT",
        "fontEdgeColor": "",
        "backgroundColor": "",
        "backgroundOpacity": 0,
        "windowColor": "",
        "windowOpacity": 0
    }
}
```

<a id="method.getFontColor"></a>
## *getFontColor [<sup>method</sup>](#head.Methods)*

Getter for FontColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.TextTrack.getFontColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.TextTrack.getFontColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "color": ""
    }
}
```

<a id="method.getFontEdge"></a>
## *getFontEdge [<sup>method</sup>](#head.Methods)*

Getter for FontEdge

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.edge | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.TextTrack.getFontEdge"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.TextTrack.getFontEdge"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "edge": "CONTENT_DEFAULT"
    }
}
```

<a id="method.getFontEdgeColor"></a>
## *getFontEdgeColor [<sup>method</sup>](#head.Methods)*

Getter for FontEdgeColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.TextTrack.getFontEdgeColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.TextTrack.getFontEdgeColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "color": ""
    }
}
```

<a id="method.getFontFamily"></a>
## *getFontFamily [<sup>method</sup>](#head.Methods)*

Getter for FontFamily

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.font | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.TextTrack.getFontFamily"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.TextTrack.getFontFamily"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "font": "CONTENT_DEFAULT"
    }
}
```

<a id="method.getFontOpacity"></a>
## *getFontOpacity [<sup>method</sup>](#head.Methods)*

Getter for FontOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.TextTrack.getFontOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.TextTrack.getFontOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "opacity": 0
    }
}
```

<a id="method.getFontSize"></a>
## *getFontSize [<sup>method</sup>](#head.Methods)*

Getter for FontSize

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.size | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.TextTrack.getFontSize"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.TextTrack.getFontSize"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "size": "CONTENT_DEFAULT"
    }
}
```

<a id="method.getTtmlStyleOverrides"></a>
## *getTtmlStyleOverrides [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.style | string | Contains the chosen override for styles |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.TextTrack.getTtmlStyleOverrides"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.TextTrack.getTtmlStyleOverrides"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "style": ""
    }
}
```

<a id="method.getWindowColor"></a>
## *getWindowColor [<sup>method</sup>](#head.Methods)*

Getter for WindowColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.TextTrack.getWindowColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.TextTrack.getWindowColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "color": ""
    }
}
```

<a id="method.getWindowOpacity"></a>
## *getWindowOpacity [<sup>method</sup>](#head.Methods)*

Getter for WindowOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.opacity | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.TextTrack.getWindowOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.TextTrack.getWindowOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "opacity": 0
    }
}
```

<a id="method.muteSession"></a>
## *muteSession [<sup>method</sup>](#head.Methods)*

Mute will hide rendering of Captions

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.TextTrack.muteSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.TextTrack.muteSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.openSession"></a>
## *openSession [<sup>method</sup>](#head.Methods)*

If a session is already running on the supplied displayHandle, the sessionId for this session is returned. If the session is instead newly opened, the session type is not set and display is muted. Use one of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayHandle | string | is an encoding of the wayland display name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sessionId | integer | On success the returned session id |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.TextTrack.openSession",
    "params": {
        "displayHandle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.TextTrack.openSession", "params": {"displayHandle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "sessionId": 0
    }
}
```

<a id="method.pauseSession"></a>
## *pauseSession [<sup>method</sup>](#head.Methods)*

Any text rendered remains on screen and any text due to be rendered soon is held until the render session is resumed.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.TextTrack.pauseSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.TextTrack.pauseSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="method.resetSession"></a>
## *resetSession [<sup>method</sup>](#head.Methods)*

The state will be like after calling OpenSession()

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.TextTrack.resetSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.TextTrack.resetSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": null
}
```

<a id="method.resumeSession"></a>
## *resumeSession [<sup>method</sup>](#head.Methods)*

Resumed a paused session

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.TextTrack.resumeSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.TextTrack.resumeSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="method.sendSessionData"></a>
## *sendSessionData [<sup>method</sup>](#head.Methods)*

Sends data of Closed Captions, Captions or Timed Text data to a render session.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
| params.type | string | Is the type of data |
| params.displayOffsetMs | integer | Is currently unused |
| params.data | string | Is the data to display, properly formatted as per the expectations of the type used |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.TextTrack.sendSessionData",
    "params": {
        "sessionId": 0,
        "type": "PES",
        "displayOffsetMs": 0,
        "data": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.TextTrack.sendSessionData", "params": {"sessionId": 0, "type": "PES", "displayOffsetMs": 0, "data": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="method.sendSessionTimestamp"></a>
## *sendSessionTimestamp [<sup>method</sup>](#head.Methods)*

The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
| params.mediaTimestampMs | integer | Is a timestamp |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.TextTrack.sendSessionTimestamp",
    "params": {
        "sessionId": 0,
        "mediaTimestampMs": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.TextTrack.sendSessionTimestamp", "params": {"sessionId": 0, "mediaTimestampMs": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="method.setBackgroundColor"></a>
## *setBackgroundColor [<sup>method</sup>](#head.Methods)*

Setter for BackgroundColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.TextTrack.setBackgroundColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.TextTrack.setBackgroundColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="method.setBackgroundOpacity"></a>
## *setBackgroundOpacity [<sup>method</sup>](#head.Methods)*

Setter for BackgroundOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.TextTrack.setBackgroundOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.TextTrack.setBackgroundOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="method.setClosedCaptionsStyle"></a>
## *setClosedCaptionsStyle [<sup>method</sup>](#head.Methods)*

For all values it is possible to keep or override the stream default. The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | ClosedCaptionsStyle | Contains the chosen styles |
| params.style.fontFamily | string |  |
| params.style.fontSize | string |  |
| params.style.fontColor | string |  |
| params.style.fontOpacity | integer |  |
| params.style.fontEdge | string |  |
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
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.TextTrack.setClosedCaptionsStyle",
    "params": {
        "fontFamily": "CONTENT_DEFAULT",
        "fontSize": "CONTENT_DEFAULT",
        "fontColor": "",
        "fontOpacity": 0,
        "fontEdge": "CONTENT_DEFAULT",
        "fontEdgeColor": "",
        "backgroundColor": "",
        "backgroundOpacity": 0,
        "windowColor": "",
        "windowOpacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.TextTrack.setClosedCaptionsStyle", "params": {"fontFamily": "CONTENT_DEFAULT", "fontSize": "CONTENT_DEFAULT", "fontColor": "", "fontOpacity": 0, "fontEdge": "CONTENT_DEFAULT", "fontEdgeColor": "", "backgroundColor": "", "backgroundOpacity": 0, "windowColor": "", "windowOpacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="method.setFontColor"></a>
## *setFontColor [<sup>method</sup>](#head.Methods)*

Setter for FontColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.TextTrack.setFontColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.TextTrack.setFontColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="method.setFontEdge"></a>
## *setFontEdge [<sup>method</sup>](#head.Methods)*

Setter for FontEdge

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.edge | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.TextTrack.setFontEdge",
    "params": {
        "edge": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.TextTrack.setFontEdge", "params": {"edge": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="method.setFontEdgeColor"></a>
## *setFontEdgeColor [<sup>method</sup>](#head.Methods)*

Setter for FontEdgeColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.TextTrack.setFontEdgeColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.TextTrack.setFontEdgeColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="method.setFontFamily"></a>
## *setFontFamily [<sup>method</sup>](#head.Methods)*

Setter for FontFamily

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.font | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.TextTrack.setFontFamily",
    "params": {
        "font": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.TextTrack.setFontFamily", "params": {"font": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="method.setFontOpacity"></a>
## *setFontOpacity [<sup>method</sup>](#head.Methods)*

Setter for FontOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.TextTrack.setFontOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.TextTrack.setFontOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="method.setFontSize"></a>
## *setFontSize [<sup>method</sup>](#head.Methods)*

Setter for FontSize

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.size | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.TextTrack.setFontSize",
    "params": {
        "size": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.TextTrack.setFontSize", "params": {"size": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="method.setPreviewText"></a>
## *setPreviewText [<sup>method</sup>](#head.Methods)*

The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
| params.text | string | Is the text to display |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.TextTrack.setPreviewText",
    "params": {
        "sessionId": 0,
        "text": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.TextTrack.setPreviewText", "params": {"sessionId": 0, "text": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="method.setSessionClosedCaptionsService"></a>
## *setSessionClosedCaptionsService [<sup>method</sup>](#head.Methods)*

Selecting the specified CC service to decode and display in the specified render session. This should be done before starting the injection of data. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
| params.service | string | Identifies the service to display  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.TextTrack.setSessionClosedCaptionsService",
    "params": {
        "sessionId": 0,
        "service": "CC3"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.TextTrack.setSessionClosedCaptionsService", "params": {"sessionId": 0, "service": "CC3"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="method.setSessionDvbSubtitleSelection"></a>
## *setSessionDvbSubtitleSelection [<sup>method</sup>](#head.Methods)*

Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
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
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection",
    "params": {
        "sessionId": 0,
        "compositionPageId": 0,
        "ancillaryPageId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection", "params": {"sessionId": 0, "compositionPageId": 0, "ancillaryPageId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```

<a id="method.setSessionSCTESelection"></a>
## *setSessionSCTESelection [<sup>method</sup>](#head.Methods)*

Set the render session into SCTE mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.TextTrack.setSessionSCTESelection",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.TextTrack.setSessionSCTESelection", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="method.setSessionTTMLSelection"></a>
## *setSessionTTMLSelection [<sup>method</sup>](#head.Methods)*

Set the render session into TTML mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.TextTrack.setSessionTTMLSelection",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.TextTrack.setSessionTTMLSelection", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```

<a id="method.setSessionTeletextSelection"></a>
## *setSessionTeletextSelection [<sup>method</sup>](#head.Methods)*

Set the render session into Teletext mode, providing the teletext caption page for presentation

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
| params.page | integer | The user selected teletext caption page 100-899 |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.TextTrack.setSessionTeletextSelection",
    "params": {
        "sessionId": 0,
        "page": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.TextTrack.setSessionTeletextSelection", "params": {"sessionId": 0, "page": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```

<a id="method.setSessionWebVTTSelection"></a>
## *setSessionWebVTTSelection [<sup>method</sup>](#head.Methods)*

Set the render session into WebVTT mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.TextTrack.setSessionWebVTTSelection",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.TextTrack.setSessionWebVTTSelection", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```

<a id="method.setTtmlStyleOverrides"></a>
## *setTtmlStyleOverrides [<sup>method</sup>](#head.Methods)*

The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning that they will override styles given in the content. The value will be persisted in the system. The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.

### Events
No events are associated with this method.
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
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.TextTrack.setTtmlStyleOverrides",
    "params": {
        "style": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.TextTrack.setTtmlStyleOverrides", "params": {"style": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": null
}
```

<a id="method.setWindowColor"></a>
## *setWindowColor [<sup>method</sup>](#head.Methods)*

Setter for WindowColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "method": "org.rdk.TextTrack.setWindowColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.TextTrack.setWindowColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": null
}
```

<a id="method.setWindowOpacity"></a>
## *setWindowOpacity [<sup>method</sup>](#head.Methods)*

Setter for WindowOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "method": "org.rdk.TextTrack.setWindowOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.TextTrack.setWindowOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": null
}
```

<a id="method.unMuteSession"></a>
## *unMuteSession [<sup>method</sup>](#head.Methods)*

A newly created session is muted and should be unmuted to me visible

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.TextTrack.unMuteSession",
    "params": {
        "sessionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.TextTrack.unMuteSession", "params": {"sessionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": null
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the TextTrack plugin:

TextTrack interface events:

| Event | Description |
| :-------- | :-------- |
| [onBackgroundColorChanged](#event.onBackgroundColorChanged) | Notify backgroundColor Changed |
| [onBackgroundOpacityChanged](#event.onBackgroundOpacityChanged) | Notify backgroundOpacity Changed |
| [onClosedCaptionsStyleChanged](#event.onClosedCaptionsStyleChanged) | The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings. |
| [onFontColorChanged](#event.onFontColorChanged) | Notify fontColor Changed |
| [onFontEdgeChanged](#event.onFontEdgeChanged) | Notify fontEdge Changed |
| [onFontEdgeColorChanged](#event.onFontEdgeColorChanged) | Notify fontEdgeColor Changed |
| [onFontFamilyChanged](#event.onFontFamilyChanged) | Notify fontFamily Changed |
| [onFontOpacityChanged](#event.onFontOpacityChanged) | Notify fontOpacity Changed |
| [onFontSizeChanged](#event.onFontSizeChanged) | Notify fontSize Changed |
| [onTtmlStyleOverridesChanged](#event.onTtmlStyleOverridesChanged) | The TTML Style override settings has changed. |
| [onWindowColorChanged](#event.onWindowColorChanged) | Notify windowColor Changed |
| [onWindowOpacityChanged](#event.onWindowOpacityChanged) | Notify windowOpacity Changed |

<a id="event.onBackgroundColorChanged"></a>
## *onBackgroundColorChanged [<sup>event</sup>](#head.Notifications)*

Notify backgroundColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.TextTrack.onBackgroundColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="event.onBackgroundOpacityChanged"></a>
## *onBackgroundOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify backgroundOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.TextTrack.onBackgroundOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```

<a id="event.onClosedCaptionsStyleChanged"></a>
## *onClosedCaptionsStyleChanged [<sup>event</sup>](#head.Notifications)*

The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | ClosedCaptionsStyle | Contains the chosen styles |
| params.style.fontFamily | string |  |
| params.style.fontSize | string |  |
| params.style.fontColor | string |  |
| params.style.fontOpacity | integer |  |
| params.style.fontEdge | string |  |
| params.style.fontEdgeColor | string |  |
| params.style.backgroundColor | string |  |
| params.style.backgroundOpacity | integer |  |
| params.style.windowColor | string |  |
| params.style.windowOpacity | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.TextTrack.onClosedCaptionsStyleChanged",
    "params": {
        "fontFamily": "CONTENT_DEFAULT",
        "fontSize": "CONTENT_DEFAULT",
        "fontColor": "",
        "fontOpacity": 0,
        "fontEdge": "CONTENT_DEFAULT",
        "fontEdgeColor": "",
        "backgroundColor": "",
        "backgroundOpacity": 0,
        "windowColor": "",
        "windowOpacity": 0
    }
}
```

<a id="event.onFontColorChanged"></a>
## *onFontColorChanged [<sup>event</sup>](#head.Notifications)*

Notify fontColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.TextTrack.onFontColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="event.onFontEdgeChanged"></a>
## *onFontEdgeChanged [<sup>event</sup>](#head.Notifications)*

Notify fontEdge Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.edge | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "method": "org.rdk.TextTrack.onFontEdgeChanged",
    "params": {
        "edge": "CONTENT_DEFAULT"
    }
}
```

<a id="event.onFontEdgeColorChanged"></a>
## *onFontEdgeColorChanged [<sup>event</sup>](#head.Notifications)*

Notify fontEdgeColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "method": "org.rdk.TextTrack.onFontEdgeColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="event.onFontFamilyChanged"></a>
## *onFontFamilyChanged [<sup>event</sup>](#head.Notifications)*

Notify fontFamily Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.font | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 46,
    "method": "org.rdk.TextTrack.onFontFamilyChanged",
    "params": {
        "font": "CONTENT_DEFAULT"
    }
}
```

<a id="event.onFontOpacityChanged"></a>
## *onFontOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify fontOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 47,
    "method": "org.rdk.TextTrack.onFontOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```

<a id="event.onFontSizeChanged"></a>
## *onFontSizeChanged [<sup>event</sup>](#head.Notifications)*

Notify fontSize Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.size | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 48,
    "method": "org.rdk.TextTrack.onFontSizeChanged",
    "params": {
        "size": "CONTENT_DEFAULT"
    }
}
```

<a id="event.onTtmlStyleOverridesChanged"></a>
## *onTtmlStyleOverridesChanged [<sup>event</sup>](#head.Notifications)*

The TTML Style override settings has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.style | string | Contains the chosen override for styles |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 49,
    "method": "org.rdk.TextTrack.onTtmlStyleOverridesChanged",
    "params": {
        "style": ""
    }
}
```

<a id="event.onWindowColorChanged"></a>
## *onWindowColorChanged [<sup>event</sup>](#head.Notifications)*

Notify windowColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.color | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 50,
    "method": "org.rdk.TextTrack.onWindowColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="event.onWindowOpacityChanged"></a>
## *onWindowOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify windowOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.opacity | integer |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 51,
    "method": "org.rdk.TextTrack.onWindowOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```
