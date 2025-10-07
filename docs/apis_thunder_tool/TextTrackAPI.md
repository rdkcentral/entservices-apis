<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_TextTrack_API"></a>
# TextTrack API

**Version: 1.3.0**

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

This document describes purpose and functionality of the TextTrack interface (version 1.3.0). It includes detailed specification about its methods provided.

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
| params | object | mandatory |  |
| params.displayHandle | string | mandatory | Is an encoding of the wayland display name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | On success the returned s |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.openSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.closeSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.resetSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.pauseSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.resumeSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.muteSession",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.unMuteSession",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.type | string | mandatory | Is the type of data
* @param displayOffsetMs Is currently unused
* @param data Is t (must be one of the following: *CC, PES, TTML, WEBVTT*) |
| params.displayOffsetMs | integer | mandatory |  |
| params.data | string | mandatory |  |

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
  "method": "<callsign>.1.sendSessionData",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.mediaTimestampMs | integer | mandatory | Is a timestamp
* @text sendSessionTimestamp
*/ |

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
  "method": "<callsign>.1.sendSessionTimestamp",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory |  |
| params.text | string | mandatory | Is the text to display |

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
  "method": "<callsign>.1.setPreviewText",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.service | string | mandatory | Identifies the service to display e.g |

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
  "method": "<callsign>.1.setSessionClosedCaptionsService",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.page | integer | mandatory | The user selected teletext caption page 100-899
* @text setSessionTeletextSelection
*/ |

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
  "method": "<callsign>.1.setSessionTeletextSelection",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.compositionPageId | integer | mandatory | Is the one Id
* @param ancillaryPageId Is the other Id
* @text setSessionDvbSubtitleSelection
*/ |
| params.ancillaryPageId | integer | mandatory |  |

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
  "method": "<callsign>.1.setSessionDvbSubtitleSelection",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.setSessionWebVTTSelection",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.setSessionTTMLSelection",
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
| params | object | mandatory |  |
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
  "method": "<callsign>.1.setSessionSCTESelection",
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
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session as returned in the ITextTrack interface |
| params.style | string | mandatory | Contains the list of styles to be overridden
* @text applyCustomTtmlStyleOverri |

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
  "method": "<callsign>.1.applyCustomTtmlStyleOverridesToSession",
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
* The assocation is active until CloseSession() or ResetSession() is called, and can also be
* cancelled by calling AssociateVideoDecoder() with an empty string for handle.
* After associating the video decoder, further calls to SendSessionData will be ignored.
* Added in version 3

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.sessionId | integer | mandatory | Is the session |
| params.handle | string | mandatory | Is a textual representation of the video decoder h |

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
  "method": "<callsign>.1.associateVideoDecoder",
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

