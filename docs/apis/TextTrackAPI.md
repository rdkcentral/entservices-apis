<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_TextTrack_API"></a>
# TextTrack API

**Version: 1.5.0**

**Status: :black_circle::white_circle::white_circle:**

TextTrack interface for Thunder framework.

(Defined with ITextTrack in [ITextTrack.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ITextTrack.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the TextTrack interface (version 1.5.0). It includes detailed specification about its methods provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

TextTrack JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the TextTrack interface:

TextTrack interface methods:

| Method | Description |
| :-------- | :-------- |
| [openSession](#method_openSession) | Opens a new renderSession |
| [closeSession](#method_closeSession) | Closes a previously opened render session |
| [resetSession](#method_resetSession) | Resets a previously opened render session back to its opened state |
| [pauseSession](#method_pauseSession) | Pauses a render session |
| [resumeSession](#method_resumeSession) | Resumed a paused session |
| [muteSession](#method_muteSession) | Mute will hide rendering of Captions |
| [unMuteSession](#method_unMuteSession) | UnMute will unhide the rendering of Captions |
| [sendSessionData](#method_sendSessionData) | Sends data of Closed Captions, Captions or Timed Text data to a render session |
| [sendSessionTimestamp](#method_sendSessionTimestamp) | Sends the current timestamp from a media player to a render session |
| [setPreviewText](#method_setPreviewText) | Sets a static text in the display for preview purposes |
| [setSessionClosedCaptionsService](#method_setSessionClosedCaptionsService) | Sets the render session into CC mode |
| [setSessionTeletextSelection](#method_setSessionTeletextSelection) | Set the render session into Teletext mode, providing the teletext caption page for presentation |
| [setSessionDvbSubtitleSelection](#method_setSessionDvbSubtitleSelection) | Set the render session into Dvb Subtitle mode, specifying the the page for presentation |
| [setSessionWebVTTSelection](#method_setSessionWebVTTSelection) | Set the render session into WebVTT mode |
| [setSessionTTMLSelection](#method_setSessionTTMLSelection) | Set the render session into TTML mode |
| [setSessionSCTESelection](#method_setSessionSCTESelection) | Set the render session into SCTE mode |
| [applyCustomTtmlStyleOverridesToSession](#method_applyCustomTtmlStyleOverridesToSession) | Applies a custom TTML styling with overrides that is applied on all elements |
| [associateVideoDecoder](#method_associateVideoDecoder) | Associate a video decoder with the given session |
| [getInterfaceVersion](#method_getInterfaceVersion) | Return the interface version implemented |
| [createSession](#method_createSession) | Creates a new rendering session |
| [getSessions](#method_getSessions) | Get a list of active sessions |
| [createPreviewSession](#method_createPreviewSession) | Create a preview session for purposes of previewing style settings |
| [setPreviewGeometry](#method_setPreviewGeometry) | Set the position of the preview session |
| [setClosedCaptionsStyleAppliesTo](#method_setClosedCaptionsStyleAppliesTo) | Sets whether the global ClosedCaptionsStyle applies to a given session type |
| [getClosedCaptionsStyleAppliesTo](#method_getClosedCaptionsStyleAppliesTo) | Gets whether the global ClosedCaptionsStyle applies to a given session type |
| [getClosedCaptionsStyleAppliesToList](#method_getClosedCaptionsStyleAppliesToList) | Gets the list of session types for which the global ClosedCaptionsStyle applies |

<a id="method_openSession"></a>
## *openSession [<sup>method</sup>](#head_Methods)*

Opens a new renderSession.

### Description

If a session is already running on the supplied displayHandle, the sessionId for this session is
     * returned. If the session is instead newly opened, the session type is not set and display is muted. Use one
     * of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.displayHandle | string | mandatory | Is an encoding of the wayland display name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | On success the returned session id ex: 1 |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.openSession",
  "params": {
    "displayHandle": "..."
  }
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

<a id="method_closeSession"></a>
## *closeSession [<sup>method</sup>](#head_Methods)*

Closes a previously opened render session.

### Description

Any created windows and surfaces is destroyed

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session to close |

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
  "method": "<callsign>.closeSession",
  "params": {
    "sessionId": 0
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

<a id="method_resetSession"></a>
## *resetSession [<sup>method</sup>](#head_Methods)*

Resets a previously opened render session back to its opened state.

### Description

The state will be like after calling OpenSession()

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session to reset |

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
  "method": "<callsign>.resetSession",
  "params": {
    "sessionId": 0
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

<a id="method_pauseSession"></a>
## *pauseSession [<sup>method</sup>](#head_Methods)*

Pauses a render session.

### Description

Any text rendered remains on screen and any text due to be rendered soon
     * is held until the render session is resumed.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.pauseSession",
  "params": {
    "sessionId": 0
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

<a id="method_resumeSession"></a>
## *resumeSession [<sup>method</sup>](#head_Methods)*

Resumed a paused session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.resumeSession",
  "params": {
    "sessionId": 0
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

<a id="method_muteSession"></a>
## *muteSession [<sup>method</sup>](#head_Methods)*

Mute will hide rendering of Captions.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.muteSession",
  "params": {
    "sessionId": 0
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

<a id="method_unMuteSession"></a>
## *unMuteSession [<sup>method</sup>](#head_Methods)*

UnMute will unhide the rendering of Captions.

### Description

A newly created session is muted and should be unmuted to me visible

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.unMuteSession",
  "params": {
    "sessionId": 0
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

<a id="method_sendSessionData"></a>
## *sendSessionData [<sup>method</sup>](#head_Methods)*

Sends data of Closed Captions, Captions or Timed Text data to a render session.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.type | string | mandatory | Is the type of data (must be one of the following: *CC, PES, TTML, WEBVTT*) |
| params.displayOffsetMs | integer | mandatory | Is added to a timestamp in the data to determine when to display it. The offset is in milliseconds and can be negative. Not all types support this |
| params.data | string | mandatory | Is the data to display, properly formatted as per the expectations of the type used |

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
  "method": "<callsign>.sendSessionData",
  "params": {
    "sessionId": 0,
    "type": "TTML",
    "displayOffsetMs": 0,
    "data": "..."
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

<a id="method_sendSessionTimestamp"></a>
## *sendSessionTimestamp [<sup>method</sup>](#head_Methods)*

Sends the current timestamp from a media player to a render session.

### Description

The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.mediaTimestampMs | integer | mandatory | Is a timestamp |

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
  "method": "<callsign>.sendSessionTimestamp",
  "params": {
    "sessionId": 0,
    "mediaTimestampMs": 0
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

<a id="method_setPreviewText"></a>
## *setPreviewText [<sup>method</sup>](#head_Methods)*

Sets a static text in the display for preview purposes.

### Description

The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.text | string | mandatory | Is the text to display |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | if preview is shown |
| ```Core::ERROR_NOT_SUPPORTED``` | if preview is not supported |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setPreviewText",
  "params": {
    "sessionId": 0,
    "text": "..."
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

<a id="method_setSessionClosedCaptionsService"></a>
## *setSessionClosedCaptionsService [<sup>method</sup>](#head_Methods)*

Sets the render session into CC mode.

### Description

Selecting the specified CC service to decode and display in the specified render session.
     * This should be done before starting the injection of data.
     * Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.service | string | mandatory | Identifies the service to display e.g. "CC3" |

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
  "method": "<callsign>.setSessionClosedCaptionsService",
  "params": {
    "sessionId": 0,
    "service": "..."
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

<a id="method_setSessionTeletextSelection"></a>
## *setSessionTeletextSelection [<sup>method</sup>](#head_Methods)*

Set the render session into Teletext mode, providing the teletext caption page for presentation.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.page | integer | mandatory | The user selected teletext caption page 100-899 |

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
  "method": "<callsign>.setSessionTeletextSelection",
  "params": {
    "sessionId": 0,
    "page": 0
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

<a id="method_setSessionDvbSubtitleSelection"></a>
## *setSessionDvbSubtitleSelection [<sup>method</sup>](#head_Methods)*

Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743).

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.compositionPageId | integer | mandatory | Is the one Id |
| params.ancillaryPageId | integer | mandatory | Is the other Id |

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
  "method": "<callsign>.setSessionDvbSubtitleSelection",
  "params": {
    "sessionId": 0,
    "compositionPageId": 0,
    "ancillaryPageId": 0
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

<a id="method_setSessionWebVTTSelection"></a>
## *setSessionWebVTTSelection [<sup>method</sup>](#head_Methods)*

Set the render session into WebVTT mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.setSessionWebVTTSelection",
  "params": {
    "sessionId": 0
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

<a id="method_setSessionTTMLSelection"></a>
## *setSessionTTMLSelection [<sup>method</sup>](#head_Methods)*

Set the render session into TTML mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.setSessionTTMLSelection",
  "params": {
    "sessionId": 0
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

<a id="method_setSessionSCTESelection"></a>
## *setSessionSCTESelection [<sup>method</sup>](#head_Methods)*

Set the render session into SCTE mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |

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
  "method": "<callsign>.setSessionSCTESelection",
  "params": {
    "sessionId": 0
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

<a id="method_applyCustomTtmlStyleOverridesToSession"></a>
## *applyCustomTtmlStyleOverridesToSession [<sup>method</sup>](#head_Methods)*

Applies a custom TTML styling with overrides that is applied on all elements.

### Description

When a custom styling override is applied on a specific TTML session, the styling carried on the data for the specified element is
     * overridden. For styling options, see https://www.w3.org/TR/2018/REC-ttml1-20181108/#styling-vocabulary-style
     * The format of the styling string is "attr:value;attr:value;attr:value" (see vocabulary; NB: not all styling is supported)
     * Styles not mentioned in the list will not be affected.
     * Added in version 2

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session as returned in the ITextTrack interface |
| params.style | string | mandatory | Contains the list of styles to be overridden |

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
  "method": "<callsign>.applyCustomTtmlStyleOverridesToSession",
  "params": {
    "sessionId": 0,
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

<a id="method_associateVideoDecoder"></a>
## *associateVideoDecoder [<sup>method</sup>](#head_Methods)*

Associate a video decoder with the given session.

### Description

This will ask TextTrack to subscribe to Closed Captions data from the decoder and display
     * these in the given session. Depending on the support on the platform, this may not be possible to do.
     * The association is active until CloseSession() or ResetSession() is called, and can also be
     * cancelled by calling AssociateVideoDecoder() with an empty string for handle.
     * After associating the video decoder, further calls to SendSessionData will be ignored.
     * Added in version 3

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.handle | string | mandatory | Is a textual representation of the video decoder handle |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_GENERAL``` | if the association failed (whether bad handle is used or lack of support on the platform). |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.associateVideoDecoder",
  "params": {
    "sessionId": 0,
    "handle": "..."
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

<a id="method_getInterfaceVersion"></a>
## *getInterfaceVersion [<sup>method</sup>](#head_Methods)*

Return the interface version implemented.

### Description

This allows to query the running plugin for the version of the interface it was compiled to support. This information can be helpful in determining whether a certain functionality can be expected to be present. There is no guarantee that the plugin has implemented all functions of that version. Added in version 4

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Will receive the version number ex: 4 |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getInterfaceVersion"
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

<a id="method_createSession"></a>
## *createSession [<sup>method</sup>](#head_Methods)*

Creates a new rendering session.

### Description

The session is newly opened, the session type is not set and display is muted. Use one
     * of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.
     * In contrast to OpenSession(), this function will not return an existing session if the displayHandle is
     * already in use, but will always create a new session. This allows multiple sessions to be created for
     * the same displayHandle, which can be useful for example for preview purposes.
     * Added in version 5

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.displayHandle | string | mandatory | Is an encoding of the wayland display name |
| params.whoAmI | string | mandatory | Identifier for the caller; must not be empty |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | On success the returned session id ex: 1 |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_GENERAL``` | if we were unable to create the session |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.createSession",
  "params": {
    "displayHandle": "...",
    "whoAmI": "..."
  }
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

<a id="method_getSessions"></a>
## *getSessions [<sup>method</sup>](#head_Methods)*

Get a list of active sessions.
     * Added in version 5.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | On success, will contain an iterator to the list of active sessions (see SessionInfo struct) |
| result[#] | object | mandatory | *...* |
| result[#].sessionId | integer | mandatory | The session ID |
| result[#].whoAmI | string | mandatory | An identifier for the caller that created the session. May be empty if created via OpenSession |
| result[#].displayHandle | string | mandatory | The display handle of the session |
| result[#].format | string | mandatory | The type of the session (CC, TTML, etc). Can be NONE if not yet set. (must be one of the following: *CC, DVBSUB, NONE, SCTE, TELETEXT, TTML, WEBVTT*) |
| result[#].isPreview | boolean | mandatory | Whether the session is a preview session or not |
| result[#].isMuted | boolean | mandatory | Whether the session is currently muted or not |
| result[#].isPaused | boolean | mandatory | Whether the session is currently paused or not |
| result[#].dataCount | integer | mandatory | The number of data packets sent to this session, for debugging purposes. The count is the number of times SendSessionData() has been called |
| result[#].info | string | mandatory | Opaque debug information about the session |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getSessions"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "sessionId": 0,
      "whoAmI": "...",
      "displayHandle": "...",
      "format": "TTML",
      "isPreview": false,
      "isMuted": false,
      "isPaused": false,
      "dataCount": 0,
      "info": "..."
    }
  ]
}
```

<a id="method_createPreviewSession"></a>
## *createPreviewSession [<sup>method</sup>](#head_Methods)*

Create a preview session for purposes of previewing style settings.

### Description

Like CreateSession(), except: the preview session will be created as a CC type session and unmuted.
     * There can only be one active preview session.
     * Creating a preview session will cause all other sessions to be muted automatically until the preview session is closed.
     * Use ApplyCustomClosedCaptionsStyleToSession() to preview style changes.
     * Given a blank displayHandle, we will create a preview session on the standard display (from the configuration file).
     * Use SetPreviewText() to set the text to display in the preview session.
     * Use SetPreviewGeometry() to set the position of the preview session.
     * Added in version 5

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.displayHandle | string | mandatory | Is an encoding of the wayland display name; may be empty |
| params.whoAmI | string | mandatory | Identifier for the caller; must not be empty |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | On success the returned session id ex: 1 |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_GENERAL``` | if a preview session is already running on the display |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.createPreviewSession",
  "params": {
    "displayHandle": "...",
    "whoAmI": "..."
  }
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

<a id="method_setPreviewGeometry"></a>
## *setPreviewGeometry [<sup>method</sup>](#head_Methods)*

Set the position of the preview session.

### Description

The positions are given as percentage of the subtitle drawing area, so 0.5 means centre and 0.0 means top or left, 1.0 is bottom or right.
     * The anchor value indicates which point of the text the positions refer to, so for example if the anchor is TOP_LEFT, the text will be positioned
     * in such a way that the top left of the text is at the given position. If the anchor is CENTER, the text will be centered on
     * the given position. This allows for more flexible positioning of the preview text.
     * The default geometry is centred on the display/drawing area (0.5, 0.5, Anchor::CENTER).
     * Added in version 5

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.sessionId | integer | mandatory | Is the session |
| params.xPos | number | mandatory | Is the horizontal position (0..1) for the preview text<br>*Value must be <= 1.0* |
| params.yPos | number | mandatory | Is the vertical position (0..1) for the preview text<br>*Value must be <= 1.0* |
| params.anchor | string | mandatory | Indicates the anchor point of the preview text, i.e. which point of the text the positions refer to. (must be one of the following: *BOTTOM, BOTTOM_LEFT, BOTTOM_RIGHT, CENTER, LEFT, RIGHT, TOP, TOP_LEFT, TOP_RIGHT*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_GENERAL``` | if the geometry could not be set |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setPreviewGeometry",
  "params": {
    "sessionId": 0,
    "xPos": 0.0,
    "yPos": 0.0,
    "anchor": "TOP"
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

<a id="method_setClosedCaptionsStyleAppliesTo"></a>
## *setClosedCaptionsStyleAppliesTo [<sup>method</sup>](#head_Methods)*

Sets whether the global ClosedCaptionsStyle applies to a given session type.

### Description

When set to true, the global ClosedCaptionsStyle will be converted and applied to all sessions of the given type. The conversion
     * will be done according to the best effort conversion rules for the given type. When set to false, the global ClosedCaptionsStyle will not be applied.
     * Added in version 5

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.format | string | mandatory | The session type to configure (must be one of the following: *CC, DVBSUB, NONE, SCTE, TELETEXT, TTML, WEBVTT*) |
| params.applies | boolean | mandatory | If true, the global ClosedCaptionsStyle applies to sessions of this type |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_GENERAL``` | if the session type is not supported |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setClosedCaptionsStyleAppliesTo",
  "params": {
    "format": "TTML",
    "applies": false
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

<a id="method_getClosedCaptionsStyleAppliesTo"></a>
## *getClosedCaptionsStyleAppliesTo [<sup>method</sup>](#head_Methods)*

Gets whether the global ClosedCaptionsStyle applies to a given session type.

### Description

Added in version 5

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.format | string | mandatory | The session type to query (must be one of the following: *CC, DVBSUB, NONE, SCTE, TELETEXT, TTML, WEBVTT*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | On success, true if the global ClosedCaptionsStyle applies to sessions of this type |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getClosedCaptionsStyleAppliesTo",
  "params": {
    "format": "TTML"
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_getClosedCaptionsStyleAppliesToList"></a>
## *getClosedCaptionsStyleAppliesToList [<sup>method</sup>](#head_Methods)*

Gets the list of session types for which the global ClosedCaptionsStyle applies.

### Description

Added in version 5

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | On success, an iterator over the session types for which the global ClosedCaptionsStyle applies |
| result[#] | string | mandatory | *...* (must be one of the following: *CC, DVBSUB, NONE, SCTE, TELETEXT, TTML, WEBVTT*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NOT_SUPPORTED``` | if the function is not implemented |
| ```Core::ERROR_NONE``` | on success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getClosedCaptionsStyleAppliesToList"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "TTML"
  ]
}
```

