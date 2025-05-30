<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.ITextTrack_Plugin"></a>
# ITextTrack Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/ITextTrack/CHANGELOG.md)**

A ITextTrack plugin for Thunder framework.

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

The `ITextTrack` plugin provides an interface for ITextTrack.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *ITextTrack*) |
| classname | string | Class name: *ITextTrack* |
| locator | string | Library name: *libWPEFrameworkITextTrack.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the ITextTrack plugin:

ITextTrack interface methods:

| Method | Description |
| :-------- | :-------- |
| [CloseSession](#method.CloseSession) | Closes a previously opened render session. |
| [GetBackgroundColor](#method.GetBackgroundColor) | Getter for BackgroundColor |
| [GetBackgroundOpacity](#method.GetBackgroundOpacity) | Getter for BackgroundOpacity |
| [GetClosedCaptionsStyle](#method.GetClosedCaptionsStyle) | Gets the current ClosedCaptionsStyle settings. |
| [GetFontColor](#method.GetFontColor) | Getter for FontColor |
| [GetFontEdge](#method.GetFontEdge) | Getter for FontEdge |
| [GetFontEdgeColor](#method.GetFontEdgeColor) | Getter for FontEdgeColor |
| [GetFontFamily](#method.GetFontFamily) | Getter for FontFamily |
| [GetFontOpacity](#method.GetFontOpacity) | Getter for FontOpacity |
| [GetFontSize](#method.GetFontSize) | Getter for FontSize |
| [GetTtmlStyleOverrides](#method.GetTtmlStyleOverrides) |  |
| [GetWindowColor](#method.GetWindowColor) | Getter for WindowColor |
| [GetWindowOpacity](#method.GetWindowOpacity) | Getter for WindowOpacity |
| [MuteSession](#method.MuteSession) | Mute will hide rendering of Captions |
| [OpenSession](#method.OpenSession) | Opens a new renderSession. |
| [PauseSession](#method.PauseSession) | Pauses a render session. |
| [ResetSession](#method.ResetSession) | Resets a previously opened render session back to its opened state. |
| [ResumeSession](#method.ResumeSession) | Resumed a paused session |
| [SendSessionData](#method.SendSessionData) | Sends data of Closed Captions, Captions or Timed Text data to a render session. |
| [SendSessionTimestamp](#method.SendSessionTimestamp) | Sends the current timestamp from a media player to a render session. |
| [SetBackgroundColor](#method.SetBackgroundColor) | Setter for BackgroundColor |
| [SetBackgroundOpacity](#method.SetBackgroundOpacity) | Setter for BackgroundOpacity |
| [SetClosedCaptionsStyle](#method.SetClosedCaptionsStyle) | Sets the ClosedCaptionsStyle. |
| [SetFontColor](#method.SetFontColor) | Setter for FontColor |
| [SetFontEdge](#method.SetFontEdge) | Setter for FontEdge |
| [SetFontEdgeColor](#method.SetFontEdgeColor) | Setter for FontEdgeColor |
| [SetFontFamily](#method.SetFontFamily) | Setter for FontFamily |
| [SetFontOpacity](#method.SetFontOpacity) | Setter for FontOpacity |
| [SetFontSize](#method.SetFontSize) | Setter for FontSize |
| [SetPreviewText](#method.SetPreviewText) | Sets a static text in the display for preview purposes. |
| [SetSessionClosedCaptionsService](#method.SetSessionClosedCaptionsService) | Sets the render session into CC mode. |
| [SetSessionDvbSubtitleSelection](#method.SetSessionDvbSubtitleSelection) | Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743) |
| [SetSessionSCTESelection](#method.SetSessionSCTESelection) | Set the render session into SCTE mode |
| [SetSessionTTMLSelection](#method.SetSessionTTMLSelection) | Set the render session into TTML mode |
| [SetSessionTeletextSelection](#method.SetSessionTeletextSelection) | Set the render session into Teletext mode, providing the teletext caption page for presentation |
| [SetSessionWebVTTSelection](#method.SetSessionWebVTTSelection) | Set the render session into WebVTT mode |
| [SetTtmlStyleOverrides](#method.SetTtmlStyleOverrides) | Sets global TTML override style. |
| [SetWindowColor](#method.SetWindowColor) | Setter for WindowColor |
| [SetWindowOpacity](#method.SetWindowOpacity) | Setter for WindowOpacity |
| [UnMuteSession](#method.UnMuteSession) | UnMute will unhide the rendering of Captions. |

<a id="method.CloseSession"></a>
## *CloseSession [<sup>method</sup>](#head.Methods)*

Closes a previously opened render session.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.CloseSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.GetBackgroundColor"></a>
## *GetBackgroundColor [<sup>method</sup>](#head.Methods)*

Getter for BackgroundColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetBackgroundColor"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "color": ""
    }
}
```
<a id="method.GetBackgroundOpacity"></a>
## *GetBackgroundOpacity [<sup>method</sup>](#head.Methods)*

Getter for BackgroundOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetBackgroundOpacity"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "opacity": ""
    }
}
```
<a id="method.GetClosedCaptionsStyle"></a>
## *GetClosedCaptionsStyle [<sup>method</sup>](#head.Methods)*

Gets the current ClosedCaptionsStyle settings.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.style | ClosedCaptionsStyle | Contains the chosen styles |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetClosedCaptionsStyle"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "style": {}
    }
}
```
<a id="method.GetFontColor"></a>
## *GetFontColor [<sup>method</sup>](#head.Methods)*

Getter for FontColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontColor"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "color": ""
    }
}
```
<a id="method.GetFontEdge"></a>
## *GetFontEdge [<sup>method</sup>](#head.Methods)*

Getter for FontEdge

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.edge | FontEdge |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontEdge"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "edge": ""
    }
}
```
<a id="method.GetFontEdgeColor"></a>
## *GetFontEdgeColor [<sup>method</sup>](#head.Methods)*

Getter for FontEdgeColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontEdgeColor"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "color": ""
    }
}
```
<a id="method.GetFontFamily"></a>
## *GetFontFamily [<sup>method</sup>](#head.Methods)*

Getter for FontFamily

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.font | FontFamily |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontFamily"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "font": ""
    }
}
```
<a id="method.GetFontOpacity"></a>
## *GetFontOpacity [<sup>method</sup>](#head.Methods)*

Getter for FontOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontOpacity"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "opacity": ""
    }
}
```
<a id="method.GetFontSize"></a>
## *GetFontSize [<sup>method</sup>](#head.Methods)*

Getter for FontSize

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.size | FontSize |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetFontSize"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "size": ""
    }
}
```
<a id="method.GetTtmlStyleOverrides"></a>
## *GetTtmlStyleOverrides [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.style | string | Contains the chosen override for styles |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetTtmlStyleOverrides"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "style": ""
    }
}
```
<a id="method.GetWindowColor"></a>
## *GetWindowColor [<sup>method</sup>](#head.Methods)*

Getter for WindowColor

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetWindowColor"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "color": ""
    }
}
```
<a id="method.GetWindowOpacity"></a>
## *GetWindowOpacity [<sup>method</sup>](#head.Methods)*

Getter for WindowOpacity

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.GetWindowOpacity"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "opacity": ""
    }
}
```
<a id="method.MuteSession"></a>
## *MuteSession [<sup>method</sup>](#head.Methods)*

Mute will hide rendering of Captions

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.MuteSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.OpenSession"></a>
## *OpenSession [<sup>method</sup>](#head.Methods)*

Opens a new renderSession.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.displayHandle | string | The displayHandle is an encoding of the wayland display name  optionally including the and window ID |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.sessionId | uint32_t | On success the returned session id |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OpenSession",
    "params": {
        "displayHandle": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "sessionId": "0"
    }
}
```
<a id="method.PauseSession"></a>
## *PauseSession [<sup>method</sup>](#head.Methods)*

Pauses a render session.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.PauseSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.ResetSession"></a>
## *ResetSession [<sup>method</sup>](#head.Methods)*

Resets a previously opened render session back to its opened state.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.ResetSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.ResumeSession"></a>
## *ResumeSession [<sup>method</sup>](#head.Methods)*

Resumed a paused session

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.ResumeSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SendSessionData"></a>
## *SendSessionData [<sup>method</sup>](#head.Methods)*

Sends data of Closed Captions, Captions or Timed Text data to a render session.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.type | DataType | Is the type of data |
| params.displayOffsetMs | int32_t | Is currently unused |
| params.data | string | Is the data to display, properly formatted as per the expectations of the type used |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SendSessionData",
    "params": {
        "sessionId": "0",
        "type": "",
        "displayOffsetMs": "0",
        "data": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SendSessionTimestamp"></a>
## *SendSessionTimestamp [<sup>method</sup>](#head.Methods)*

Sends the current timestamp from a media player to a render session.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.mediaTimestampMs | uint64_t | Is a timestamp |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SendSessionTimestamp",
    "params": {
        "sessionId": "0",
        "mediaTimestampMs": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetBackgroundColor"></a>
## *SetBackgroundColor [<sup>method</sup>](#head.Methods)*

Setter for BackgroundColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetBackgroundColor",
    "params": {
        "color": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetBackgroundOpacity"></a>
## *SetBackgroundOpacity [<sup>method</sup>](#head.Methods)*

Setter for BackgroundOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetBackgroundOpacity",
    "params": {
        "opacity": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetClosedCaptionsStyle"></a>
## *SetClosedCaptionsStyle [<sup>method</sup>](#head.Methods)*

Sets the ClosedCaptionsStyle.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.style | ClosedCaptionsStyle | Contains the chosen styles |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetClosedCaptionsStyle",
    "params": {
        "style": {}
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontColor"></a>
## *SetFontColor [<sup>method</sup>](#head.Methods)*

Setter for FontColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontColor",
    "params": {
        "color": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontEdge"></a>
## *SetFontEdge [<sup>method</sup>](#head.Methods)*

Setter for FontEdge

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.edge | FontEdge |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontEdge",
    "params": {
        "edge": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontEdgeColor"></a>
## *SetFontEdgeColor [<sup>method</sup>](#head.Methods)*

Setter for FontEdgeColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontEdgeColor",
    "params": {
        "color": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontFamily"></a>
## *SetFontFamily [<sup>method</sup>](#head.Methods)*

Setter for FontFamily

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.font | FontFamily |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontFamily",
    "params": {
        "font": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontOpacity"></a>
## *SetFontOpacity [<sup>method</sup>](#head.Methods)*

Setter for FontOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontOpacity",
    "params": {
        "opacity": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetFontSize"></a>
## *SetFontSize [<sup>method</sup>](#head.Methods)*

Setter for FontSize

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.size | FontSize |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetFontSize",
    "params": {
        "size": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetPreviewText"></a>
## *SetPreviewText [<sup>method</sup>](#head.Methods)*

Sets a static text in the display for preview purposes.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.text | string | Is the text to display |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetPreviewText",
    "params": {
        "sessionId": "0",
        "text": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionClosedCaptionsService"></a>
## *SetSessionClosedCaptionsService [<sup>method</sup>](#head.Methods)*

Sets the render session into CC mode.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.service | string | Identifies the service to display  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionClosedCaptionsService",
    "params": {
        "sessionId": "0",
        "service": "CC3"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionDvbSubtitleSelection"></a>
## *SetSessionDvbSubtitleSelection [<sup>method</sup>](#head.Methods)*

Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.compositionPageId | uint16_t | Is the one Id |
| params.ancillaryPageId | uint16_t | Is the other Id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionDvbSubtitleSelection",
    "params": {
        "sessionId": "0",
        "compositionPageId": "",
        "ancillaryPageId": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionSCTESelection"></a>
## *SetSessionSCTESelection [<sup>method</sup>](#head.Methods)*

Set the render session into SCTE mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionSCTESelection",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionTTMLSelection"></a>
## *SetSessionTTMLSelection [<sup>method</sup>](#head.Methods)*

Set the render session into TTML mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionTTMLSelection",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionTeletextSelection"></a>
## *SetSessionTeletextSelection [<sup>method</sup>](#head.Methods)*

Set the render session into Teletext mode, providing the teletext caption page for presentation

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
| params.page | uint16_t | The user selected teletext caption page 100-899 |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionTeletextSelection",
    "params": {
        "sessionId": "0",
        "page": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetSessionWebVTTSelection"></a>
## *SetSessionWebVTTSelection [<sup>method</sup>](#head.Methods)*

Set the render session into WebVTT mode

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetSessionWebVTTSelection",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetTtmlStyleOverrides"></a>
## *SetTtmlStyleOverrides [<sup>method</sup>](#head.Methods)*

Sets global TTML override style.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.style | string | Contains the chosen override for styles |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetTtmlStyleOverrides",
    "params": {
        "style": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetWindowColor"></a>
## *SetWindowColor [<sup>method</sup>](#head.Methods)*

Setter for WindowColor

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetWindowColor",
    "params": {
        "color": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.SetWindowOpacity"></a>
## *SetWindowOpacity [<sup>method</sup>](#head.Methods)*

Setter for WindowOpacity

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.SetWindowOpacity",
    "params": {
        "opacity": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="method.UnMuteSession"></a>
## *UnMuteSession [<sup>method</sup>](#head.Methods)*

UnMute will unhide the rendering of Captions.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.sessionId | uint32_t | On success the returned session id |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.UnMuteSession",
    "params": {
        "sessionId": "0"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the ITextTrack plugin:

ITextTrack interface events:

| Method | Description |
| :-------- | :-------- |
| [OnBackgroundColorChanged](#event.OnBackgroundColorChanged) | Notify backgroundColor Changed |
| [OnBackgroundOpacityChanged](#event.OnBackgroundOpacityChanged) | Notify backgroundOpacity Changed |
| [OnClosedCaptionsStyleChanged](#event.OnClosedCaptionsStyleChanged) | The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings. |
| [OnFontColorChanged](#event.OnFontColorChanged) | Notify fontColor Changed |
| [OnFontEdgeChanged](#event.OnFontEdgeChanged) | Notify fontEdge Changed |
| [OnFontEdgeColorChanged](#event.OnFontEdgeColorChanged) | Notify fontEdgeColor Changed |
| [OnFontFamilyChanged](#event.OnFontFamilyChanged) | Notify fontFamily Changed |
| [OnFontOpacityChanged](#event.OnFontOpacityChanged) | Notify fontOpacity Changed |
| [OnFontSizeChanged](#event.OnFontSizeChanged) | Notify fontSize Changed |
| [OnTtmlStyleOverridesChanged](#event.OnTtmlStyleOverridesChanged) | The TTML Style override settings has changed. |
| [OnWindowColorChanged](#event.OnWindowColorChanged) | Notify windowColor Changed |
| [OnWindowOpacityChanged](#event.OnWindowOpacityChanged) | Notify windowOpacity Changed |

<a id="event.OnBackgroundColorChanged"></a>
## *OnBackgroundColorChanged [<sup>event</sup>](#head.Notifications)*

Notify backgroundColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnBackgroundColorChanged",
    "params": {
        "color": ""
    }
}
```
<a id="event.OnBackgroundOpacityChanged"></a>
## *OnBackgroundOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify backgroundOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnBackgroundOpacityChanged",
    "params": {
        "opacity": ""
    }
}
```
<a id="event.OnClosedCaptionsStyleChanged"></a>
## *OnClosedCaptionsStyleChanged [<sup>event</sup>](#head.Notifications)*

The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.style | ClosedCaptionsStyle | Contains the chosen styles |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnClosedCaptionsStyleChanged",
    "params": {
        "style": {}
    }
}
```
<a id="event.OnFontColorChanged"></a>
## *OnFontColorChanged [<sup>event</sup>](#head.Notifications)*

Notify fontColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontColorChanged",
    "params": {
        "color": ""
    }
}
```
<a id="event.OnFontEdgeChanged"></a>
## *OnFontEdgeChanged [<sup>event</sup>](#head.Notifications)*

Notify fontEdge Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.edge | FontEdge |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontEdgeChanged",
    "params": {
        "edge": ""
    }
}
```
<a id="event.OnFontEdgeColorChanged"></a>
## *OnFontEdgeColorChanged [<sup>event</sup>](#head.Notifications)*

Notify fontEdgeColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontEdgeColorChanged",
    "params": {
        "color": ""
    }
}
```
<a id="event.OnFontFamilyChanged"></a>
## *OnFontFamilyChanged [<sup>event</sup>](#head.Notifications)*

Notify fontFamily Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.font | FontFamily |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontFamilyChanged",
    "params": {
        "font": ""
    }
}
```
<a id="event.OnFontOpacityChanged"></a>
## *OnFontOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify fontOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontOpacityChanged",
    "params": {
        "opacity": ""
    }
}
```
<a id="event.OnFontSizeChanged"></a>
## *OnFontSizeChanged [<sup>event</sup>](#head.Notifications)*

Notify fontSize Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.size | FontSize |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnFontSizeChanged",
    "params": {
        "size": ""
    }
}
```
<a id="event.OnTtmlStyleOverridesChanged"></a>
## *OnTtmlStyleOverridesChanged [<sup>event</sup>](#head.Notifications)*

The TTML Style override settings has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.style | string | Contains the chosen override for styles |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnTtmlStyleOverridesChanged",
    "params": {
        "style": ""
    }
}
```
<a id="event.OnWindowColorChanged"></a>
## *OnWindowColorChanged [<sup>event</sup>](#head.Notifications)*

Notify windowColor Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.color | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnWindowColorChanged",
    "params": {
        "color": ""
    }
}
```
<a id="event.OnWindowOpacityChanged"></a>
## *OnWindowOpacityChanged [<sup>event</sup>](#head.Notifications)*

Notify windowOpacity Changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.opacity | int8_t |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ITextTrack.OnWindowOpacityChanged",
    "params": {
        "opacity": ""
    }
}
```