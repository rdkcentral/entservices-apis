<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_UserSettings_API"></a>
# UserSettings API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

UserSettings interface for Thunder framework.

(Defined with IUserSettings in [IUserSettings.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IUserSettings.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the UserSettings interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

UserSettings JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the UserSettings interface:

UserSettings interface methods:

| Method | Description |
| :-------- | :-------- |
| [setAudioDescription](#method_setAudioDescription) | Sets AudioDescription ON/OFF |
| [getAudioDescription](#method_getAudioDescription) | Gets the current AudioDescription setting |
| [setPreferredAudioLanguages](#method_setPreferredAudioLanguages) | A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements |
| [getPreferredAudioLanguages](#method_getPreferredAudioLanguages) | Gets the current PreferredAudioLanguages setting |
| [setPresentationLanguage](#method_setPresentationLanguage) | Sets the presentationLanguage in a full BCP 47 value, including script, region, variant |
| [getPresentationLanguage](#method_getPresentationLanguage) | Gets the presentationLanguage |
| [setCaptions](#method_setCaptions) | brief Sets Captions ON/OFF |
| [getCaptions](#method_getCaptions) | Gets the Captions setting |
| [setPreferredCaptionsLanguages](#method_setPreferredCaptionsLanguages) | Set preferred languages for captions |
| [getPreferredCaptionsLanguages](#method_getPreferredCaptionsLanguages) | Gets the current PreferredCaptionsLanguages setting |
| [setPreferredClosedCaptionService](#method_setPreferredClosedCaptionService) | Sets the PreferredClosedCaptionService |
| [getPreferredClosedCaptionService](#method_getPreferredClosedCaptionService) | Gets the current PreferredClosedCaptionService setting |
| [setPrivacyMode](#method_setPrivacyMode) | Sets the PrivacyMode |
| [getPrivacyMode](#method_getPrivacyMode) | Gets the current PrivacyMode setting |
| [SetPinControl](#method_SetPinControl) / [setPinControl](#method_SetPinControl) | Sets PinControl ON/OFF |
| [getPinControl](#method_getPinControl) | Gets the PinControl setting |
| [setViewingRestrictions](#method_setViewingRestrictions) | Sets the ViewingRestrictions |
| [getViewingRestrictions](#method_getViewingRestrictions) | Gets the current ViewingRestrictions |
| [setViewingRestrictionsWindow](#method_setViewingRestrictionsWindow) | Sets the ViewingRestrictionsWindow |
| [getViewingRestrictionsWindow](#method_getViewingRestrictionsWindow) | Gets the current ViewingRestrictionsWindow |
| [setLiveWatershed](#method_setLiveWatershed) | Sets LiveWatershed ON/OFF |
| [getLiveWatershed](#method_getLiveWatershed) | Gets the LiveWatershed setting |
| [setPlaybackWatershed](#method_setPlaybackWatershed) | Sets PlaybackWatershed ON/OFF |
| [getPlaybackWatershed](#method_getPlaybackWatershed) | Gets the PlaybackWatershed setting |
| [setBlockNotRatedContent](#method_setBlockNotRatedContent) | Sets BlockNotRatedContent ON/OFF |
| [getBlockNotRatedContent](#method_getBlockNotRatedContent) | Gets the BlockNotRatedContent setting |
| [setPinOnPurchase](#method_setPinOnPurchase) | Sets PinOnPurchase ON/OFF |
| [getPinOnPurchase](#method_getPinOnPurchase) | Gets the PinOnPurchase setting |
| [setHighContrast](#method_setHighContrast) | Sets highContrast |
| [getHighContrast](#method_getHighContrast) | Gets the current highContrast setting |
| [setVoiceGuidance](#method_setVoiceGuidance) | Sets voiceGuidance |
| [getVoiceGuidance](#method_getVoiceGuidance) | Gets the current voiceGuidance setting |
| [setVoiceGuidanceRate](#method_setVoiceGuidanceRate) | Sets voiceGuidanceRate |
| [getVoiceGuidanceRate](#method_getVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting |
| [setVoiceGuidanceHints](#method_setVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF |
| [getVoiceGuidanceHints](#method_getVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting |
| [setContentPin](#method_setContentPin) | Sets the ContentPin |
| [getContentPin](#method_getContentPin) | Gets the ContentPin |

<a id="method_setAudioDescription"></a>
## *setAudioDescription [<sup>method</sup>](#head_Methods)*

Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setAudioDescription",
  "params": {
    "enabled": false
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

<a id="method_getAudioDescription"></a>
## *getAudioDescription [<sup>method</sup>](#head_Methods)*

Gets the current AudioDescription setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getAudioDescription"
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

<a id="method_setPreferredAudioLanguages"></a>
## *setPreferredAudioLanguages [<sup>method</sup>](#head_Methods)*

A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.preferredLanguages | string | mandatory | PreferredLanguages |

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
  "method": "<callsign>.1.setPreferredAudioLanguages",
  "params": {
    "preferredLanguages": "..."
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

<a id="method_getPreferredAudioLanguages"></a>
## *getPreferredAudioLanguages [<sup>method</sup>](#head_Methods)*

Gets the current PreferredAudioLanguages setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | PreferredLanguages |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPreferredAudioLanguages"
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

<a id="method_setPresentationLanguage"></a>
## *setPresentationLanguage [<sup>method</sup>](#head_Methods)*

Sets the presentationLanguage in a full BCP 47 value, including script, region, variant.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.presentationLanguage | string | mandatory | "en-US", "es-US", "en-CA", "fr-CA" |

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
  "method": "<callsign>.1.setPresentationLanguage",
  "params": {
    "presentationLanguage": "..."
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

<a id="method_getPresentationLanguage"></a>
## *getPresentationLanguage [<sup>method</sup>](#head_Methods)*

Gets the presentationLanguage.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | "en-US", "es-US", "en-CA", "fr-CA" |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPresentationLanguage"
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

<a id="method_setCaptions"></a>
## *setCaptions [<sup>method</sup>](#head_Methods)*

brief Sets Captions ON/OFF.

### Description

A setting of ON indicates that Players should select a subtitle track for presentation The Setting does not influence any running sessions. It is up to the player to enforce the setting. This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions and timed text types. Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes of this state while a playback is active. When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state. This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media players or apps that decode-display internally

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Sets the state |

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
  "method": "<callsign>.1.setCaptions",
  "params": {
    "enabled": false
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

<a id="method_getCaptions"></a>
## *getCaptions [<sup>method</sup>](#head_Methods)*

Gets the Captions setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Receives the state |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getCaptions"
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

<a id="method_setPreferredCaptionsLanguages"></a>
## *setPreferredCaptionsLanguages [<sup>method</sup>](#head_Methods)*

Set preferred languages for captions.

### Description

A prioritized list of ISO 639-2/B codes for the preferred Captions languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the subtitle track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred subtitle track.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.preferredLanguages | string | mandatory | Is the list to set |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
Failed to generate JSON example for setPreferredCaptionsLanguages
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_getPreferredCaptionsLanguages"></a>
## *getPreferredCaptionsLanguages [<sup>method</sup>](#head_Methods)*

Gets the current PreferredCaptionsLanguages setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | "eng,fra" |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPreferredCaptionsLanguages"
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

<a id="method_setPreferredClosedCaptionService"></a>
## *setPreferredClosedCaptionService [<sup>method</sup>](#head_Methods)*

Sets the PreferredClosedCaptionService.

### Description

The setting should be honored by the player. The behaviour of AUTO may be player specific. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
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
  "method": "<callsign>.1.setPreferredClosedCaptionService",
  "params": {
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

<a id="method_getPreferredClosedCaptionService"></a>
## *getPreferredClosedCaptionService [<sup>method</sup>](#head_Methods)*

Gets the current PreferredClosedCaptionService setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Identifies the service to display e.g. "CC3" |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPreferredClosedCaptionService"
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

<a id="method_setPrivacyMode"></a>
## *setPrivacyMode [<sup>method</sup>](#head_Methods)*

Sets the PrivacyMode.

### Description

The setting should be honored by the Telemetry. If privacyMode is "DO_NOT_SHARE", logs and crash report should not be uploaded.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.privacyMode | string | mandatory | "SHARE", "DO_NOT_SHARE" |

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
  "method": "<callsign>.1.setPrivacyMode",
  "params": {
    "privacyMode": "..."
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

<a id="method_getPrivacyMode"></a>
## *getPrivacyMode [<sup>method</sup>](#head_Methods)*

Gets the current PrivacyMode setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | "SHARE" |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPrivacyMode"
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

<a id="method_SetPinControl"></a>
## *SetPinControl [<sup>method</sup>](#head_Methods)*

Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.

> ``setPinControl`` is an alternative name for this method.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.pinControl | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.SetPinControl",
  "params": {
    "pinControl": false
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

<a id="method_getPinControl"></a>
## *getPinControl [<sup>method</sup>](#head_Methods)*

Gets the PinControl setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPinControl"
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

<a id="method_setViewingRestrictions"></a>
## *setViewingRestrictions [<sup>method</sup>](#head_Methods)*

Sets the ViewingRestrictions.

### Description

A JSON document that escribes the rating scheme(s) and ratings that are blocked.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.viewingRestrictions | string | mandatory | A JSON document that describes the rating scheme(s) and ratings that are blocked |

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
  "method": "<callsign>.1.setViewingRestrictions",
  "params": {
    "viewingRestrictions": "..."
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

<a id="method_getViewingRestrictions"></a>
## *getViewingRestrictions [<sup>method</sup>](#head_Methods)*

Gets the current ViewingRestrictions.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | A JSON document that escribes the rating scheme(s) and ratings that are blocked |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getViewingRestrictions"
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

<a id="method_setViewingRestrictionsWindow"></a>
## *setViewingRestrictionsWindow [<sup>method</sup>](#head_Methods)*

Sets the ViewingRestrictionsWindow.

### Description

A project-specific representation of the time interval when viewing restrictions are to be applied, if applicable for the project

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.viewingRestrictionsWindow | string | mandatory | A project-specific representation of the time interval.Eg: "ALWAYS" |

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
  "method": "<callsign>.1.setViewingRestrictionsWindow",
  "params": {
    "viewingRestrictionsWindow": "..."
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

<a id="method_getViewingRestrictionsWindow"></a>
## *getViewingRestrictionsWindow [<sup>method</sup>](#head_Methods)*

Gets the current ViewingRestrictionsWindow.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | A project-specific representation of the time interval.Eg: "ALWAYS" |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getViewingRestrictionsWindow"
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

<a id="method_setLiveWatershed"></a>
## *setLiveWatershed [<sup>method</sup>](#head_Methods)*

Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.liveWatershed | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setLiveWatershed",
  "params": {
    "liveWatershed": false
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

<a id="method_getLiveWatershed"></a>
## *getLiveWatershed [<sup>method</sup>](#head_Methods)*

Gets the LiveWatershed setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLiveWatershed"
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

<a id="method_setPlaybackWatershed"></a>
## *setPlaybackWatershed [<sup>method</sup>](#head_Methods)*

Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.playbackWatershed | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setPlaybackWatershed",
  "params": {
    "playbackWatershed": false
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

<a id="method_getPlaybackWatershed"></a>
## *getPlaybackWatershed [<sup>method</sup>](#head_Methods)*

Gets the PlaybackWatershed setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPlaybackWatershed"
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

<a id="method_setBlockNotRatedContent"></a>
## *setBlockNotRatedContent [<sup>method</sup>](#head_Methods)*

Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.blockNotRatedContent | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setBlockNotRatedContent",
  "params": {
    "blockNotRatedContent": false
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

<a id="method_getBlockNotRatedContent"></a>
## *getBlockNotRatedContent [<sup>method</sup>](#head_Methods)*

Gets the BlockNotRatedContent setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getBlockNotRatedContent"
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

<a id="method_setPinOnPurchase"></a>
## *setPinOnPurchase [<sup>method</sup>](#head_Methods)*

Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.pinOnPurchase | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setPinOnPurchase",
  "params": {
    "pinOnPurchase": false
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

<a id="method_getPinOnPurchase"></a>
## *getPinOnPurchase [<sup>method</sup>](#head_Methods)*

Gets the PinOnPurchase setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPinOnPurchase"
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

<a id="method_setHighContrast"></a>
## *setHighContrast [<sup>method</sup>](#head_Methods)*

Sets highContrast. Whether the app should display with high contrast or not.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setHighContrast",
  "params": {
    "enabled": false
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

<a id="method_getHighContrast"></a>
## *getHighContrast [<sup>method</sup>](#head_Methods)*

Gets the current highContrast setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getHighContrast"
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

<a id="method_setVoiceGuidance"></a>
## *setVoiceGuidance [<sup>method</sup>](#head_Methods)*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setVoiceGuidance",
  "params": {
    "enabled": false
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

<a id="method_getVoiceGuidance"></a>
## *getVoiceGuidance [<sup>method</sup>](#head_Methods)*

Gets the current voiceGuidance setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Enabled/Disabled |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVoiceGuidance"
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

<a id="method_setVoiceGuidanceRate"></a>
## *setVoiceGuidanceRate [<sup>method</sup>](#head_Methods)*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.rate | number | mandatory | Sets Voice Guidance rate |

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
  "method": "<callsign>.1.setVoiceGuidanceRate",
  "params": {
    "rate": 0.0
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

<a id="method_getVoiceGuidanceRate"></a>
## *getVoiceGuidanceRate [<sup>method</sup>](#head_Methods)*

Gets the current voiceGuidanceRate setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | number | mandatory | Gets Voice Guidance rate |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVoiceGuidanceRate"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0.0
}
```

<a id="method_setVoiceGuidanceHints"></a>
## *setVoiceGuidanceHints [<sup>method</sup>](#head_Methods)*

Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.hints | boolean | mandatory | Enabled/Disabled |

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
  "method": "<callsign>.1.setVoiceGuidanceHints",
  "params": {
    "hints": false
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

<a id="method_getVoiceGuidanceHints"></a>
## *getVoiceGuidanceHints [<sup>method</sup>](#head_Methods)*

Gets the current voiceGuidanceHints setting.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | True/false |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getVoiceGuidanceHints"
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

<a id="method_setContentPin"></a>
## *setContentPin [<sup>method</sup>](#head_Methods)*

Sets the ContentPin.

### Description

ContentPin is a string of four decimal digits that represents the PIN code which is used to unlock access to restricted AV content.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.contentPin | string | mandatory | A string of four decimal digits that represents the content PIN |

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
  "method": "<callsign>.1.setContentPin",
  "params": {
    "contentPin": "..."
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

<a id="method_getContentPin"></a>
## *getContentPin [<sup>method</sup>](#head_Methods)*

Gets the ContentPin.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | A string of four decimal digits that represents the content PIN |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getContentPin"
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

The following events are provided by the UserSettings interface:

UserSettings interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAudioDescriptionChanged](#notification_onAudioDescriptionChanged) | The AudioDescription setting has changed |
| [onPreferredAudioLanguagesChanged](#notification_onPreferredAudioLanguagesChanged) | The preferredLanguages setting has changed |
| [onPresentationLanguageChanged](#notification_onPresentationLanguageChanged) | The PresentationLanguages setting has changed |
| [onCaptionsChanged](#notification_onCaptionsChanged) | The Captions setting has changed |
| [onPreferredCaptionsLanguagesChanged](#notification_onPreferredCaptionsLanguagesChanged) | The PreferredCaptionsLanguages setting has changed |
| [onPreferredClosedCaptionServiceChanged](#notification_onPreferredClosedCaptionServiceChanged) | The PreferredClosedCaptionService setting has changed |
| [onPrivacyModeChanged](#notification_onPrivacyModeChanged) | The PrivacyMode setting has changed |
| [OnPinControlChanged](#notification_OnPinControlChanged) / [onPinControlChanged](#notification_OnPinControlChanged) | The PinControl setting has changed |
| [onViewingRestrictionsChanged](#notification_onViewingRestrictionsChanged) | The ViewingRestrictions setting has changed |
| [onViewingRestrictionsWindowChanged](#notification_onViewingRestrictionsWindowChanged) | The ViewingRestrictionsWindow setting has changed |
| [onLiveWatershedChanged](#notification_onLiveWatershedChanged) | The LiveWatershed setting has changed |
| [onPlaybackWatershedChanged](#notification_onPlaybackWatershedChanged) | The PlaybackWatershed setting has changed |
| [onBlockNotRatedContentChanged](#notification_onBlockNotRatedContentChanged) | The BlockNotRatedContent setting has changed |
| [onPinOnPurchaseChanged](#notification_onPinOnPurchaseChanged) | The PinOnPurchase setting has changed |
| [onHighContrastChanged](#notification_onHighContrastChanged) | Triggered after the high contrast settings changes |
| [onVoiceGuidanceChanged](#notification_onVoiceGuidanceChanged) | Triggered after the voice guidance enabled settings changes |
| [onVoiceGuidanceRateChanged](#notification_onVoiceGuidanceRateChanged) | Triggered after the voice guidance rate changed |
| [onVoiceGuidanceHintsChanged](#notification_onVoiceGuidanceHintsChanged) | Triggered after the voice guidance hints changes |
| [onContentPinChanged](#notification_onContentPinChanged) | The ContentPin setting has changed |

<a id="notification_onAudioDescriptionChanged"></a>
## *onAudioDescriptionChanged [<sup>notification</sup>](#head_Notifications)*

The AudioDescription setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | AudioDescription enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onAudioDescriptionChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAudioDescriptionChanged",
  "params": {
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAudioDescriptionChanged``.

<a id="notification_onPreferredAudioLanguagesChanged"></a>
## *onPreferredAudioLanguagesChanged [<sup>notification</sup>](#head_Notifications)*

The preferredLanguages setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.preferredLanguages | string | mandatory | The changed preferredLanguages |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPreferredAudioLanguagesChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPreferredAudioLanguagesChanged",
  "params": {
    "preferredLanguages": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPreferredAudioLanguagesChanged``.

<a id="notification_onPresentationLanguageChanged"></a>
## *onPresentationLanguageChanged [<sup>notification</sup>](#head_Notifications)*

The PresentationLanguages setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.presentationLanguage | string | mandatory | The changed presentationLanguage |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPresentationLanguageChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPresentationLanguageChanged",
  "params": {
    "presentationLanguage": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPresentationLanguageChanged``.

<a id="notification_onCaptionsChanged"></a>
## *onCaptionsChanged [<sup>notification</sup>](#head_Notifications)*

The Captions setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Captions enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onCaptionsChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onCaptionsChanged",
  "params": {
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onCaptionsChanged``.

<a id="notification_onPreferredCaptionsLanguagesChanged"></a>
## *onPreferredCaptionsLanguagesChanged [<sup>notification</sup>](#head_Notifications)*

The PreferredCaptionsLanguages setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.preferredLanguages | string | mandatory | The changed preferredLanguages |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPreferredCaptionsLanguagesChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPreferredCaptionsLanguagesChanged",
  "params": {
    "preferredLanguages": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPreferredCaptionsLanguagesChanged``.

<a id="notification_onPreferredClosedCaptionServiceChanged"></a>
## *onPreferredClosedCaptionServiceChanged [<sup>notification</sup>](#head_Notifications)*

The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.service | string | mandatory | The changed preferredClosedCaptionService |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPreferredClosedCaptionServiceChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPreferredClosedCaptionServiceChanged",
  "params": {
    "service": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPreferredClosedCaptionServiceChanged``.

<a id="notification_onPrivacyModeChanged"></a>
## *onPrivacyModeChanged [<sup>notification</sup>](#head_Notifications)*

The PrivacyMode setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.privacyMode | string | mandatory | "SHARE", "DO_NOT_SHARE" |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPrivacyModeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPrivacyModeChanged",
  "params": {
    "privacyMode": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPrivacyModeChanged``.

<a id="notification_OnPinControlChanged"></a>
## *OnPinControlChanged [<sup>notification</sup>](#head_Notifications)*

The PinControl setting has changed.

> ``onPinControlChanged`` is an alternative name for this notification.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.pinControl | boolean | mandatory | PinControl enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "OnPinControlChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.OnPinControlChanged",
  "params": {
    "pinControl": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.OnPinControlChanged``.

<a id="notification_onViewingRestrictionsChanged"></a>
## *onViewingRestrictionsChanged [<sup>notification</sup>](#head_Notifications)*

The ViewingRestrictions setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.viewingRestrictions | string | mandatory | The changed viewingRestrictions |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onViewingRestrictionsChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onViewingRestrictionsChanged",
  "params": {
    "viewingRestrictions": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onViewingRestrictionsChanged``.

<a id="notification_onViewingRestrictionsWindowChanged"></a>
## *onViewingRestrictionsWindowChanged [<sup>notification</sup>](#head_Notifications)*

The ViewingRestrictionsWindow setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.viewingRestrictionsWindow | string | mandatory | The changed viewingRestrictionsWindow |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onViewingRestrictionsWindowChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onViewingRestrictionsWindowChanged",
  "params": {
    "viewingRestrictionsWindow": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onViewingRestrictionsWindowChanged``.

<a id="notification_onLiveWatershedChanged"></a>
## *onLiveWatershedChanged [<sup>notification</sup>](#head_Notifications)*

The LiveWatershed setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.liveWatershed | boolean | mandatory | LiveWatershed enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onLiveWatershedChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onLiveWatershedChanged",
  "params": {
    "liveWatershed": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onLiveWatershedChanged``.

<a id="notification_onPlaybackWatershedChanged"></a>
## *onPlaybackWatershedChanged [<sup>notification</sup>](#head_Notifications)*

The PlaybackWatershed setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.playbackWatershed | boolean | mandatory | PlaybackWatershed enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPlaybackWatershedChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPlaybackWatershedChanged",
  "params": {
    "playbackWatershed": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPlaybackWatershedChanged``.

<a id="notification_onBlockNotRatedContentChanged"></a>
## *onBlockNotRatedContentChanged [<sup>notification</sup>](#head_Notifications)*

The BlockNotRatedContent setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.blockNotRatedContent | boolean | mandatory | BlockNotRatedContent enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onBlockNotRatedContentChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onBlockNotRatedContentChanged",
  "params": {
    "blockNotRatedContent": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onBlockNotRatedContentChanged``.

<a id="notification_onPinOnPurchaseChanged"></a>
## *onPinOnPurchaseChanged [<sup>notification</sup>](#head_Notifications)*

The PinOnPurchase setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.pinOnPurchase | boolean | mandatory | PinOnPurchase enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPinOnPurchaseChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPinOnPurchaseChanged",
  "params": {
    "pinOnPurchase": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPinOnPurchaseChanged``.

<a id="notification_onHighContrastChanged"></a>
## *onHighContrastChanged [<sup>notification</sup>](#head_Notifications)*

Triggered after the high contrast settings changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | High contrast enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onHighContrastChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onHighContrastChanged",
  "params": {
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onHighContrastChanged``.

<a id="notification_onVoiceGuidanceChanged"></a>
## *onVoiceGuidanceChanged [<sup>notification</sup>](#head_Notifications)*

Triggered after the voice guidance enabled settings changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Voice guidance enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onVoiceGuidanceChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onVoiceGuidanceChanged",
  "params": {
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onVoiceGuidanceChanged``.

<a id="notification_onVoiceGuidanceRateChanged"></a>
## *onVoiceGuidanceRateChanged [<sup>notification</sup>](#head_Notifications)*

Triggered after the voice guidance rate changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.rate | number | mandatory | The changed voice guidance rate |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onVoiceGuidanceRateChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onVoiceGuidanceRateChanged",
  "params": {
    "rate": 0.0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onVoiceGuidanceRateChanged``.

<a id="notification_onVoiceGuidanceHintsChanged"></a>
## *onVoiceGuidanceHintsChanged [<sup>notification</sup>](#head_Notifications)*

Triggered after the voice guidance hints changes.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.hints | boolean | mandatory | Voice guidance hints enabled or not |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onVoiceGuidanceHintsChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onVoiceGuidanceHintsChanged",
  "params": {
    "hints": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onVoiceGuidanceHintsChanged``.

<a id="notification_onContentPinChanged"></a>
## *onContentPinChanged [<sup>notification</sup>](#head_Notifications)*

The ContentPin setting has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.contentPin | string | mandatory | The changed contentPin |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onContentPinChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onContentPinChanged",
  "params": {
    "contentPin": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onContentPinChanged``.

