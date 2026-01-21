<!-- Generated automatically, DO NOT EDIT! -->
<a id="TextTrack_Plugin"></a>
# TextTrack Plugin

**Version: [1.4.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/TextTrack/ITextTrack.h)**

A TextTrack plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `TextTrack` plugin provides an interface for TextTrack.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.TextTrack) |
| classname | string | Class name: *TextTrack* |
| locator | string | Library name: *libWPEFrameworkTextTrack.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the TextTrack plugin:

TextTrack interface methods:

| Method | Description |
| :-------- | :-------- |
| [closeSession](#closeSession) | Closes a previously opened render session. |
| [getBackgroundColor](#getBackgroundColor) | Getter for BackgroundColor |
| [getBackgroundOpacity](#getBackgroundOpacity) | Getter for BackgroundOpacity |
| [getCapabilities](#getCapabilities) | Retrieves an iterator over all supported TextTrack capabilities. |
| [getCapability](#getCapability) | Queries whether a specific TextTrack capability is supported by the implementation. |
| [getClosedCaptionsStyle](#getClosedCaptionsStyle) | Gets the current ClosedCaptionsStyle settings. |
| [getFontColor](#getFontColor) | Getter for FontColor |
| [getFontEdge](#getFontEdge) | Getter for FontEdge |
| [getFontEdgeColor](#getFontEdgeColor) | Getter for FontEdgeColor |
| [getFontFamily](#getFontFamily) | Getter for FontFamily |
| [getFontOpacity](#getFontOpacity) | Getter for FontOpacity |
| [getFontSize](#getFontSize) | Getter for FontSize |
| [getTtmlStyleOverrides](#getTtmlStyleOverrides) | Gets the global TTML style overrides |
| [getWindowColor](#getWindowColor) | Getter for WindowColor |
| [getWindowOpacity](#getWindowOpacity) | Getter for WindowOpacity |
| [muteSession](#muteSession) | Mute will hide rendering of Captions |
| [openSession](#openSession) | Opens a new renderSession. |
| [pauseSession](#pauseSession) | Pauses a render session. |
| [resetSession](#resetSession) | Resets a previously opened render session back to its opened state. |
| [resumeSession](#resumeSession) | Resumed a paused session |
| [sendSessionData](#sendSessionData) | Sends data of Closed Captions, Captions or Timed Text data to a render session. |
| [sendSessionTimestamp](#sendSessionTimestamp) | Sends the current timestamp from a media player to a render session. |
| [setBackgroundColor](#setBackgroundColor) | Setter for BackgroundColor |
| [setBackgroundOpacity](#setBackgroundOpacity) | Setter for BackgroundOpacity |
| [setClosedCaptionsStyle](#setClosedCaptionsStyle) | Sets the ClosedCaptionsStyle. |
| [setFontColor](#setFontColor) | Setter for FontColor |
| [setFontEdge](#setFontEdge) | Setter for FontEdge |
| [setFontEdgeColor](#setFontEdgeColor) | Setter for FontEdgeColor |
| [setFontFamily](#setFontFamily) | Setter for FontFamily |
| [setFontOpacity](#setFontOpacity) | Setter for FontOpacity |
| [setFontSize](#setFontSize) | Setter for FontSize |
| [setPreviewText](#setPreviewText) | Sets a static text in the display for preview purposes. |
| [setSessionClosedCaptionsService](#setSessionClosedCaptionsService) | Sets the render session into CC mode. |
| [setSessionDvbSubtitleSelection](#setSessionDvbSubtitleSelection) | Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743) |
| [setSessionSCTESelection](#setSessionSCTESelection) | Set the render session into SCTE mode |
| [setSessionTTMLSelection](#setSessionTTMLSelection) | Set the render session into TTML mode |
| [setSessionTeletextSelection](#setSessionTeletextSelection) | Set the render session into Teletext mode, providing the teletext caption page for presentation |
| [setSessionWebVTTSelection](#setSessionWebVTTSelection) | Set the render session into WebVTT mode |
| [setTtmlStyleOverrides](#setTtmlStyleOverrides) | Sets global TTML override style. |
| [setWindowColor](#setWindowColor) | Setter for WindowColor |
| [setWindowOpacity](#setWindowOpacity) | Setter for WindowOpacity |
| [unMuteSession](#unMuteSession) | UnMute will unhide the rendering of Captions. |

<a id="closeSession"></a>
## *closeSession*

Any created windows and surfaces is destroyed

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.TextTrack.closeSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="getBackgroundColor"></a>
## *getBackgroundColor*

Getter for BackgroundColor

### Events
Event details will be updated soon.
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

<a id="getBackgroundOpacity"></a>
## *getBackgroundOpacity*

Getter for BackgroundOpacity

### Events
Event details will be updated soon.
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

<a id="getCapabilities"></a>
## *getCapabilities*

Retrieves an iterator over all supported TextTrack capabilities.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.capabilities | IIterator | Iterator providing the list of supported capabilities. @retval Core::ERROR_NONE The list of capabilities was retrieved successfully. @retval Core::ERROR_NOT_SUPPORTED Retrieving capabilities is not supported. |
| result.capabilities[#] | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.TextTrack.getCapabilities"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.TextTrack.getCapabilities"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": [
        "UNSET"
    ]
}
```

<a id="getCapability"></a>
## *getCapability*

Queries whether a specific TextTrack capability is supported by the implementation.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.capability | string | The capability to query  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hasCapability | bool | Indicates whether the queried capability is supported. @retval Core::ERROR_NONE The capability query completed successfully. @retval Core::ERROR_NOT_SUPPORTED Capability querying is not supported. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.TextTrack.getCapability",
    "params": {
        "capability": "FIREBOLT_MIGRATION"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.TextTrack.getCapability", "params": {"capability": "FIREBOLT_MIGRATION"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "hasCapability": true
    }
}
```

<a id="getClosedCaptionsStyle"></a>
## *getClosedCaptionsStyle*

Gets the current ClosedCaptionsStyle settings.

### Events
Event details will be updated soon.
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
    "id": 5,
    "method": "org.rdk.TextTrack.getClosedCaptionsStyle"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.TextTrack.getClosedCaptionsStyle"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
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

<a id="getFontColor"></a>
## *getFontColor*

Getter for FontColor

### Events
Event details will be updated soon.
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
    "method": "org.rdk.TextTrack.getFontColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.TextTrack.getFontColor"}' http://127.0.0.1:9998/jsonrpc
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

<a id="getFontEdge"></a>
## *getFontEdge*

Getter for FontEdge

### Events
Event details will be updated soon.
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
    "id": 7,
    "method": "org.rdk.TextTrack.getFontEdge"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.TextTrack.getFontEdge"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "edge": "CONTENT_DEFAULT"
    }
}
```

<a id="getFontEdgeColor"></a>
## *getFontEdgeColor*

Getter for FontEdgeColor

### Events
Event details will be updated soon.
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
    "id": 8,
    "method": "org.rdk.TextTrack.getFontEdgeColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.TextTrack.getFontEdgeColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "color": ""
    }
}
```

<a id="getFontFamily"></a>
## *getFontFamily*

Getter for FontFamily

### Events
Event details will be updated soon.
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
    "id": 9,
    "method": "org.rdk.TextTrack.getFontFamily"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.TextTrack.getFontFamily"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "font": "CONTENT_DEFAULT"
    }
}
```

<a id="getFontOpacity"></a>
## *getFontOpacity*

Getter for FontOpacity

### Events
Event details will be updated soon.
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
    "id": 10,
    "method": "org.rdk.TextTrack.getFontOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.TextTrack.getFontOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "opacity": 0
    }
}
```

<a id="getFontSize"></a>
## *getFontSize*

Getter for FontSize

### Events
Event details will be updated soon.
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
    "id": 11,
    "method": "org.rdk.TextTrack.getFontSize"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.TextTrack.getFontSize"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "size": "CONTENT_DEFAULT"
    }
}
```

<a id="getTtmlStyleOverrides"></a>
## *getTtmlStyleOverrides*

Gets the global TTML style overrides

### Events
Event details will be updated soon.
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
    "id": 12,
    "method": "org.rdk.TextTrack.getTtmlStyleOverrides"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.TextTrack.getTtmlStyleOverrides"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "style": ""
    }
}
```

<a id="getWindowColor"></a>
## *getWindowColor*

Getter for WindowColor

### Events
Event details will be updated soon.
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
    "id": 13,
    "method": "org.rdk.TextTrack.getWindowColor"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.TextTrack.getWindowColor"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "color": ""
    }
}
```

<a id="getWindowOpacity"></a>
## *getWindowOpacity*

Getter for WindowOpacity

### Events
Event details will be updated soon.
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
    "id": 14,
    "method": "org.rdk.TextTrack.getWindowOpacity"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.TextTrack.getWindowOpacity"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "opacity": 0
    }
}
```

<a id="muteSession"></a>
## *muteSession*

Mute will hide rendering of Captions

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.muteSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.TextTrack.muteSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```

<a id="openSession"></a>
## *openSession*

If a session is already running on the supplied displayHandle, the sessionId for this session is returned. If the session is instead newly opened, the session type is not set and display is muted. Use one of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.displayHandle | string | is an encoding of the wayland display name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.sessionId | integer | On success the returned session id  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.TextTrack.openSession",
    "params": {
        "displayHandle": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.TextTrack.openSession", "params": {"displayHandle": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "sessionId": 1
    }
}
```

<a id="pauseSession"></a>
## *pauseSession*

Any text rendered remains on screen and any text due to be rendered soon is held until the render session is resumed.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.pauseSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.TextTrack.pauseSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": null
}
```

<a id="resetSession"></a>
## *resetSession*

The state will be like after calling OpenSession()

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.resetSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.TextTrack.resetSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": null
}
```

<a id="resumeSession"></a>
## *resumeSession*

Resumed a paused session

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.resumeSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.TextTrack.resumeSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```

<a id="sendSessionData"></a>
## *sendSessionData*

Sends data of Closed Captions, Captions or Timed Text data to a render session.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 20,
    "method": "org.rdk.TextTrack.sendSessionData",
    "params": {
        "sessionId": 1,
        "type": "PES",
        "displayOffsetMs": 0,
        "data": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.TextTrack.sendSessionData", "params": {"sessionId": 1, "type": "PES", "displayOffsetMs": 0, "data": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```

<a id="sendSessionTimestamp"></a>
## *sendSessionTimestamp*

The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 21,
    "method": "org.rdk.TextTrack.sendSessionTimestamp",
    "params": {
        "sessionId": 1,
        "mediaTimestampMs": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.TextTrack.sendSessionTimestamp", "params": {"sessionId": 1, "mediaTimestampMs": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="setBackgroundColor"></a>
## *setBackgroundColor*

Setter for BackgroundColor

### Events
Event details will be updated soon.
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
    "id": 22,
    "method": "org.rdk.TextTrack.setBackgroundColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.TextTrack.setBackgroundColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="setBackgroundOpacity"></a>
## *setBackgroundOpacity*

Setter for BackgroundOpacity

### Events
Event details will be updated soon.
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
    "id": 23,
    "method": "org.rdk.TextTrack.setBackgroundOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.TextTrack.setBackgroundOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="setClosedCaptionsStyle"></a>
## *setClosedCaptionsStyle*

For all values it is possible to keep or override the stream default. The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.

### Events
Event details will be updated soon.
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
    "id": 24,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.TextTrack.setClosedCaptionsStyle", "params": {"fontFamily": "CONTENT_DEFAULT", "fontSize": "CONTENT_DEFAULT", "fontColor": "", "fontOpacity": 0, "fontEdge": "CONTENT_DEFAULT", "fontEdgeColor": "", "backgroundColor": "", "backgroundOpacity": 0, "windowColor": "", "windowOpacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="setFontColor"></a>
## *setFontColor*

Setter for FontColor

### Events
Event details will be updated soon.
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
    "method": "org.rdk.TextTrack.setFontColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.TextTrack.setFontColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="setFontEdge"></a>
## *setFontEdge*

Setter for FontEdge

### Events
Event details will be updated soon.
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
    "id": 26,
    "method": "org.rdk.TextTrack.setFontEdge",
    "params": {
        "edge": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.TextTrack.setFontEdge", "params": {"edge": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="setFontEdgeColor"></a>
## *setFontEdgeColor*

Setter for FontEdgeColor

### Events
Event details will be updated soon.
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
    "id": 27,
    "method": "org.rdk.TextTrack.setFontEdgeColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.TextTrack.setFontEdgeColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="setFontFamily"></a>
## *setFontFamily*

Setter for FontFamily

### Events
Event details will be updated soon.
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
    "id": 28,
    "method": "org.rdk.TextTrack.setFontFamily",
    "params": {
        "font": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.TextTrack.setFontFamily", "params": {"font": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="setFontOpacity"></a>
## *setFontOpacity*

Setter for FontOpacity

### Events
Event details will be updated soon.
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
    "id": 29,
    "method": "org.rdk.TextTrack.setFontOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.TextTrack.setFontOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="setFontSize"></a>
## *setFontSize*

Setter for FontSize

### Events
Event details will be updated soon.
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
    "id": 30,
    "method": "org.rdk.TextTrack.setFontSize",
    "params": {
        "size": "CONTENT_DEFAULT"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.TextTrack.setFontSize", "params": {"size": "CONTENT_DEFAULT"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="setPreviewText"></a>
## *setPreviewText*

The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 31,
    "method": "org.rdk.TextTrack.setPreviewText",
    "params": {
        "sessionId": 1,
        "text": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.TextTrack.setPreviewText", "params": {"sessionId": 1, "text": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```

<a id="setSessionClosedCaptionsService"></a>
## *setSessionClosedCaptionsService*

Selecting the specified CC service to decode and display in the specified render session. This should be done before starting the injection of data. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 32,
    "method": "org.rdk.TextTrack.setSessionClosedCaptionsService",
    "params": {
        "sessionId": 1,
        "service": "CC3"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.TextTrack.setSessionClosedCaptionsService", "params": {"sessionId": 1, "service": "CC3"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="setSessionDvbSubtitleSelection"></a>
## *setSessionDvbSubtitleSelection*

Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 33,
    "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection",
    "params": {
        "sessionId": 1,
        "compositionPageId": 0,
        "ancillaryPageId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.TextTrack.setSessionDvbSubtitleSelection", "params": {"sessionId": 1, "compositionPageId": 0, "ancillaryPageId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```

<a id="setSessionSCTESelection"></a>
## *setSessionSCTESelection*

Set the render session into SCTE mode

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.setSessionSCTESelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.TextTrack.setSessionSCTESelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```

<a id="setSessionTTMLSelection"></a>
## *setSessionTTMLSelection*

Set the render session into TTML mode

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.setSessionTTMLSelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.TextTrack.setSessionTTMLSelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```

<a id="setSessionTeletextSelection"></a>
## *setSessionTeletextSelection*

Set the render session into Teletext mode, providing the teletext caption page for presentation

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "id": 36,
    "method": "org.rdk.TextTrack.setSessionTeletextSelection",
    "params": {
        "sessionId": 1,
        "page": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.TextTrack.setSessionTeletextSelection", "params": {"sessionId": 1, "page": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": null
}
```

<a id="setSessionWebVTTSelection"></a>
## *setSessionWebVTTSelection*

Set the render session into WebVTT mode

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
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
    "method": "org.rdk.TextTrack.setSessionWebVTTSelection",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.TextTrack.setSessionWebVTTSelection", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": null
}
```

<a id="setTtmlStyleOverrides"></a>
## *setTtmlStyleOverrides*

The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning that they will override styles given in the content. The value will be persisted in the system. The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.

### Events
Event details will be updated soon.
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
    "id": 38,
    "method": "org.rdk.TextTrack.setTtmlStyleOverrides",
    "params": {
        "style": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.TextTrack.setTtmlStyleOverrides", "params": {"style": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": null
}
```

<a id="setWindowColor"></a>
## *setWindowColor*

Setter for WindowColor

### Events
Event details will be updated soon.
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
    "id": 39,
    "method": "org.rdk.TextTrack.setWindowColor",
    "params": {
        "color": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.TextTrack.setWindowColor", "params": {"color": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": null
}
```

<a id="setWindowOpacity"></a>
## *setWindowOpacity*

Setter for WindowOpacity

### Events
Event details will be updated soon.
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
    "id": 40,
    "method": "org.rdk.TextTrack.setWindowOpacity",
    "params": {
        "opacity": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 40, "method": "org.rdk.TextTrack.setWindowOpacity", "params": {"opacity": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "result": null
}
```

<a id="unMuteSession"></a>
## *unMuteSession*

A newly created session is muted and should be unmuted to me visible

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.sessionId | integer | On success the returned session id  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.TextTrack.unMuteSession",
    "params": {
        "sessionId": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 41, "method": "org.rdk.TextTrack.unMuteSession", "params": {"sessionId": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the TextTrack plugin:

TextTrack interface events:

| Event | Description |
| :-------- | :-------- |
| [onBackgroundColorChanged](#onBackgroundColorChanged) | Notify backgroundColor Changed |
| [onBackgroundOpacityChanged](#onBackgroundOpacityChanged) | Notify backgroundOpacity Changed |
| [onClosedCaptionsStyleChanged](#onClosedCaptionsStyleChanged) | The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings. |
| [onFontColorChanged](#onFontColorChanged) | Notify fontColor Changed |
| [onFontEdgeChanged](#onFontEdgeChanged) | Notify fontEdge Changed |
| [onFontEdgeColorChanged](#onFontEdgeColorChanged) | Notify fontEdgeColor Changed |
| [onFontFamilyChanged](#onFontFamilyChanged) | Notify fontFamily Changed |
| [onFontOpacityChanged](#onFontOpacityChanged) | Notify fontOpacity Changed |
| [onFontSizeChanged](#onFontSizeChanged) | Notify fontSize Changed |
| [onTtmlStyleOverridesChanged](#onTtmlStyleOverridesChanged) | The TTML Style override settings has changed. |
| [onWindowColorChanged](#onWindowColorChanged) | Notify windowColor Changed |
| [onWindowOpacityChanged](#onWindowOpacityChanged) | Notify windowOpacity Changed |

<a id="onBackgroundColorChanged"></a>
## *onBackgroundColorChanged*

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
    "id": 42,
    "method": "org.rdk.TextTrack.onBackgroundColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="onBackgroundOpacityChanged"></a>
## *onBackgroundOpacityChanged*

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
    "id": 43,
    "method": "org.rdk.TextTrack.onBackgroundOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```

<a id="onClosedCaptionsStyleChanged"></a>
## *onClosedCaptionsStyleChanged*

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
    "id": 44,
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

<a id="onFontColorChanged"></a>
## *onFontColorChanged*

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
    "id": 45,
    "method": "org.rdk.TextTrack.onFontColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="onFontEdgeChanged"></a>
## *onFontEdgeChanged*

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
    "id": 46,
    "method": "org.rdk.TextTrack.onFontEdgeChanged",
    "params": {
        "edge": "CONTENT_DEFAULT"
    }
}
```

<a id="onFontEdgeColorChanged"></a>
## *onFontEdgeColorChanged*

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
    "id": 47,
    "method": "org.rdk.TextTrack.onFontEdgeColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="onFontFamilyChanged"></a>
## *onFontFamilyChanged*

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
    "id": 48,
    "method": "org.rdk.TextTrack.onFontFamilyChanged",
    "params": {
        "font": "CONTENT_DEFAULT"
    }
}
```

<a id="onFontOpacityChanged"></a>
## *onFontOpacityChanged*

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
    "id": 49,
    "method": "org.rdk.TextTrack.onFontOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```

<a id="onFontSizeChanged"></a>
## *onFontSizeChanged*

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
    "id": 50,
    "method": "org.rdk.TextTrack.onFontSizeChanged",
    "params": {
        "size": "CONTENT_DEFAULT"
    }
}
```

<a id="onTtmlStyleOverridesChanged"></a>
## *onTtmlStyleOverridesChanged*

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
    "id": 51,
    "method": "org.rdk.TextTrack.onTtmlStyleOverridesChanged",
    "params": {
        "style": ""
    }
}
```

<a id="onWindowColorChanged"></a>
## *onWindowColorChanged*

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
    "id": 52,
    "method": "org.rdk.TextTrack.onWindowColorChanged",
    "params": {
        "color": ""
    }
}
```

<a id="onWindowOpacityChanged"></a>
## *onWindowOpacityChanged*

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
    "id": 53,
    "method": "org.rdk.TextTrack.onWindowOpacityChanged",
    "params": {
        "opacity": 0
    }
}
```
