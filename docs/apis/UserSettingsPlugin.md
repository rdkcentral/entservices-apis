<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.UserSettings_Plugin"></a>
# UserSettings Plugin

**Version: [2.1.0](https://github.com/rdkcentral/rdkservices/blob/main/UserSettings/CHANGELOG.md)**

A org.rdk.UserSettings plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a name="head.Description"></a>
# Description

The `UserSettings` that is responsible for persisting and notifying listeners of any change of these settings.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.UserSettings*) |
| classname | string | Class name: *org.rdk.UserSettings* |
| locator | string | Library name: *libWPEFrameworkUserSettings.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.UserSettings plugin:

org.rdk.UserSettings interface methods:

| Method | Description |
| :-------- | :-------- |
| [setAudioDescription](#method.setAudioDescription) | Setting Audio Description |
| [setPreferredAudioLanguages](#method.setPreferredAudioLanguages) | Setting Preferred Audio Languages |
| [setPresentationLanguage](#method.setPresentationLanguage) | Setting Presentation Languages |
| [setCaptions](#method.setCaptions) | Setting Captions |
| [setPreferredCaptionsLanguages](#method.setPreferredCaptionsLanguages) | Setting PreferredCaption Languages |
| [setPreferredClosedCaptionService](#method.setPreferredClosedCaptionService) | Setting Preferred Closed Caption Service |
| [setPinControl](#method.setPinControl) | Setting PinControl |
| [setViewingRestrictions](#method.setViewingRestrictions) | Setting ViewingRestrictions |
| [setViewingRestrictionsWindow](#method.setViewingRestrictionsWindow) | Setting viewingRestrictionsWindow |
| [setLiveWatershed](#method.setLiveWatershed) | Setting LiveWatershed |
| [setPlaybackWatershed](#method.setPlaybackWatershed) | Setting PlaybackWatershed |
| [setBlockNotRatedContent](#method.setBlockNotRatedContent) | Setting BlockNotRatedContent |
| [setPinOnPurchase](#method.setPinOnPurchase) | Setting setPinOnPurchase |
| [setHighContrast](#method.setHighContrast) | Sets highContrast |
| [setVoiceGuidance](#method.setVoiceGuidance) | Sets voiceGuidance |
| [setVoiceGuidanceRate](#method.setVoiceGuidanceRate) | Sets voiceGuidanceRate |
| [setVoiceGuidanceHints](#method.setVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF |
| [getAudioDescription](#method.getAudioDescription) | Returns Audio Description |
| [getPreferredAudioLanguages](#method.getPreferredAudioLanguages) | Returns Preferred Audio Languages |
| [getPresentationLanguage](#method.getPresentationLanguage) | Getting Presentation Languages |
| [getCaptions](#method.getCaptions) | Getting Captions Enabled |
| [getPreferredCaptionsLanguages](#method.getPreferredCaptionsLanguages) | Getting Preferred Caption Languages |
| [getPreferredClosedCaptionService](#method.getPreferredClosedCaptionService) | Getting Preferred ClosedCaption Service |
| [getPinControl](#method.getPinControl) | Returns Pin Control |
| [getViewingRestrictions](#method.getViewingRestrictions) | Returns Get Viewing Restrictions |
| [getViewingRestrictionsWindow](#method.getViewingRestrictionsWindow) | Returns Get Viewing Restrictions Window |
| [getLiveWatershed](#method.getLiveWatershed) | Returns Live Watershed |
| [getPlaybackWatershed](#method.getPlaybackWatershed) | Returns Playback Watershed |
| [getBlockNotRatedContent](#method.getBlockNotRatedContent) | Returns BlockNotRatedContent |
| [getPinOnPurchase](#method.getPinOnPurchase) | Returns PinOnPurchase |
| [getHighContrast](#method.getHighContrast) | Gets the current highContrast setting |
| [getVoiceGuidance](#method.getVoiceGuidance) | Gets the current voiceGuidance setting |
| [getVoiceGuidanceRate](#method.getVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting |
| [getVoiceGuidanceHints](#method.getVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting |


<a name="method.setAudioDescription"></a>
## *setAudioDescription [<sup>method</sup>](#head.Methods)*

Setting Audio Description.

### Events

| Event | Description |
| :-------- | :-------- |
| [onAudioDescriptionChanged](#event.onAudioDescriptionChanged) | Triggered when the audio description changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | Audio Description Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setAudioDescription",
    "params": {
        "enabled": true
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

<a name="method.setPreferredAudioLanguages"></a>
## *setPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*

Setting Preferred Audio Languages.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPreferredAudioLanguagesChanged](#event.onPreferredAudioLanguagesChanged) | Triggered when the audio preferred Audio languages changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | A prioritized list of ISO 639-2/B codes for the preferred audio languages |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPreferredAudioLanguages",
    "params": {
        "preferredLanguages": "eng"
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

<a name="method.setPresentationLanguage"></a>
## *setPresentationLanguage [<sup>method</sup>](#head.Methods)*

Setting Presentation Languages.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPresentationLanguageChanged](#event.onPresentationLanguageChanged) | Triggered when the presentation Language changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.presentationLanguage | string | The preferred presentationLanguage in a full BCP 47 value, including script, * region, variant The language set and used by Immerse UI |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPresentationLanguage",
    "params": {
        "presentationLanguage": "en-US"
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

<a name="method.setCaptions"></a>
## *setCaptions [<sup>method</sup>](#head.Methods)*

Setting Captions.

### Events

| Event | Description |
| :-------- | :-------- |
| [onCaptionsChanged](#event.onCaptionsChanged) | Triggered when the captions changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | Captions Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setCaptions",
    "params": {
        "enabled": true
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

<a name="method.setPreferredCaptionsLanguages"></a>
## *setPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*

Setting PreferredCaption Languages.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPreferredCaptionsLanguagesChanged](#event.onPreferredCaptionsLanguagesChanged) | Triggered when the PreferredCaption Languages changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | A prioritized list of ISO 639-2/B codes for the preferred captions languages |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPreferredCaptionsLanguages",
    "params": {
        "preferredLanguages": "eng"
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

<a name="method.setPreferredClosedCaptionService"></a>
## *setPreferredClosedCaptionService [<sup>method</sup>](#head.Methods)*

Setting Preferred Closed Caption Service.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPreferredClosedCaptionServiceChanged](#event.onPreferredClosedCaptionServiceChanged) | Triggered when the Preferred Closed Caption changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | string | A string for the preferred closed captions service.  Valid values are AUTO, CC[1-4], TEXT[1-4], SERVICE[1-64] where CC and TEXT is CTA-608 and SERVICE is CTA-708.  AUTO indicates that the choice is left to the player |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPreferredClosedCaptionService",
    "params": {
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

<a name="method.setPinControl"></a>
## *setPinControl [<sup>method</sup>](#head.Methods)*

Setting PinControl.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPinControlChanged](#event.onPinControlChanged) | Triggered when the pincontrol changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinControl | boolean | PinControl Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPinControl",
    "params": {
        "pinControl": true
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

<a name="method.setViewingRestrictions"></a>
## *setViewingRestrictions [<sup>method</sup>](#head.Methods)*

Setting ViewingRestrictions.

### Events

| Event | Description |
| :-------- | :-------- |
| [onViewingRestrictionsChanged](#event.onViewingRestrictionsChanged) | Triggered when the viewingRestrictions changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictions | string | A JSON document that describes the rating scheme(s) and ratings that are blocked |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setViewingRestrictions",
    "params": {
        "viewingRestrictions": "ALWAYS"
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

<a name="method.setViewingRestrictionsWindow"></a>
## *setViewingRestrictionsWindow [<sup>method</sup>](#head.Methods)*

Setting viewingRestrictionsWindow.

### Events

| Event | Description |
| :-------- | :-------- |
| [onViewingRestrictionsWindowChanged](#event.onViewingRestrictionsWindowChanged) | Triggered when the viewingRestrictionsWindow changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictionsWindow | string | A project-specific representation of the time interval |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setViewingRestrictionsWindow",
    "params": {
        "viewingRestrictionsWindow": "ALWAYS"
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

<a name="method.setLiveWatershed"></a>
## *setLiveWatershed [<sup>method</sup>](#head.Methods)*

Setting LiveWatershed.

### Events

| Event | Description |
| :-------- | :-------- |
| [onLiveWatershedChanged](#event.onLiveWatershedChanged) | Triggered when the liveWatershed changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.liveWatershed | boolean | LiveWatershed Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setLiveWatershed",
    "params": {
        "liveWatershed": true
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

<a name="method.setPlaybackWatershed"></a>
## *setPlaybackWatershed [<sup>method</sup>](#head.Methods)*

Setting PlaybackWatershed.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPlaybackWatershedChanged](#event.onPlaybackWatershedChanged) | Triggered when the playbackWatershed changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playbackWatershed | boolean | PlaybackWatershed Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPlaybackWatershed",
    "params": {
        "playbackWatershed": true
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

<a name="method.setBlockNotRatedContent"></a>
## *setBlockNotRatedContent [<sup>method</sup>](#head.Methods)*

Setting BlockNotRatedContent.

### Events

| Event | Description |
| :-------- | :-------- |
| [onBlockNotRatedContentChanged](#event.onBlockNotRatedContentChanged) | Triggered when the blockNotRatedContent changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blockNotRatedContent | boolean | BlockNotRatedContent Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setBlockNotRatedContent",
    "params": {
        "blockNotRatedContent": true
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

<a name="method.setPinOnPurchase"></a>
## *setPinOnPurchase [<sup>method</sup>](#head.Methods)*

Setting setPinOnPurchase.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPinOnPurchaseChanged](#event.onPinOnPurchaseChanged) | Triggered when the pin on the purchase changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinOnPurchase | boolean | setPinOnPurchase Enabled: true/false |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setPinOnPurchase",
    "params": {
        "pinOnPurchase": true
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

<a name="method.setHighContrast"></a>
## *setHighContrast [<sup>method</sup>](#head.Methods)*

Sets highContrast. Whether the app should display with high contrast or not.

### Events

| Event | Description |
| :-------- | :-------- |
| [onHighContrastChanged](#event.onHighContrastChanged) | Triggers when the highContrast changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | high contrast enabled(true) or disabled(false) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setHighContrast",
    "params": {
        "enabled": true
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

<a name="method.setVoiceGuidance"></a>
## *setVoiceGuidance [<sup>method</sup>](#head.Methods)*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Events

| Event | Description |
| :-------- | :-------- |
| [onVoiceGuidanceChanged](#event.onVoiceGuidanceChanged) | Triggers after the voice guidance enabled settings changes. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | voice guidance enabled(true) or disabled(false) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.UserSettings.setVoiceGuidance",
    "params": {
        "enabled": true
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

<a name="method.setVoiceGuidanceRate"></a>
## *setVoiceGuidanceRate [<sup>method</sup>](#head.Methods)*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Events

| Event | Description |
| :-------- | :-------- |
| [onVoiceGuidanceRateChanged](#event.onVoiceGuidanceRateChanged) | Triggered after the voice guidance rate changed. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rate | double | voice guidance rate value |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Example

#### Request

