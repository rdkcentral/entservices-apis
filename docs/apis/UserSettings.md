<!-- Generated automatically, DO NOT EDIT! -->
<a id="UserSettings_Module"></a>
# UserSettings Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/UserSettings/IUserSettings.h)**

A UserSettings module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IUserSettings](#IUserSettings)
    - [Methods](#IUserSettings-Methods)
    - [Notifications](#IUserSettings-Notifications)
  - [IUserSettingsInspector](#IUserSettingsInspector)
    - [Methods](#IUserSettingsInspector-Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `UserSettings` module provides the following interface(s):

- IUserSettings
- IUserSettingsInspector

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.UserSettings) |
| classname | string | Class name: *UserSettings* |
| locator | string | Library name: *libWPEFrameworkUserSettings.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IUserSettings"></a>
## IUserSettings Interface

<a id="IUserSettings-Methods"></a>
### Methods

The following methods are provided by the IUserSettings Interface:

| Method | Description |
| :-------- | :-------- |
| [getAudioDescription](#getAudioDescription) | Gets the current AudioDescription setting |
| [getBlockNotRatedContent](#getBlockNotRatedContent) | Gets the BlockNotRatedContent setting |
| [getCaptions](#getCaptions) | Gets the Captions setting. |
| [getContentPin](#getContentPin) | Gets the ContentPin. |
| [getHighContrast](#getHighContrast) | Gets the current highContrast setting. |
| [getLiveWatershed](#getLiveWatershed) | Gets the LiveWatershed setting |
| [getPinControl](#getPinControl) | Gets the PinControl setting |
| [getPinOnPurchase](#getPinOnPurchase) | Gets the PinOnPurchase setting |
| [getPlaybackWatershed](#getPlaybackWatershed) | Gets the PlaybackWatershed setting |
| [getPreferredAudioLanguages](#getPreferredAudioLanguages) | Gets the current PreferredAudioLanguages setting |
| [getPreferredCaptionsLanguages](#getPreferredCaptionsLanguages) | Gets the current PreferredCaptionsLanguages setting. |
| [getPreferredClosedCaptionService](#getPreferredClosedCaptionService) | Gets the current PreferredClosedCaptionService setting. |
| [getPresentationLanguage](#getPresentationLanguage) | Gets the presentationLanguage |
| [getPrivacyMode](#getPrivacyMode) | Gets the current PrivacyMode setting. |
| [getViewingRestrictions](#getViewingRestrictions) | Gets the current ViewingRestrictions. |
| [getViewingRestrictionsWindow](#getViewingRestrictionsWindow) | Gets the current ViewingRestrictionsWindow. |
| [getVoiceGuidance](#getVoiceGuidance) | Gets the current voiceGuidance setting. |
| [getVoiceGuidanceHints](#getVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting. |
| [getVoiceGuidanceRate](#getVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting. |
| [setAudioDescription](#setAudioDescription) | Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled |
| [setBlockNotRatedContent](#setBlockNotRatedContent) | Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project. |
| [setCaptions](#setCaptions) | brief Sets Captions ON/OFF. |
| [setContentPin](#setContentPin) | Sets the ContentPin. |
| [setHighContrast](#setHighContrast) | Sets highContrast. Whether the app should display with high contrast or not. |
| [setLiveWatershed](#setLiveWatershed) | Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project. |
| [setPinControl](#setPinControl) | Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled. |
| [setPinOnPurchase](#setPinOnPurchase) | Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted. |
| [setPlaybackWatershed](#setPlaybackWatershed) | Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project. |
| [setPreferredAudioLanguages](#setPreferredAudioLanguages) | A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track. |
| [setPreferredCaptionsLanguages](#setPreferredCaptionsLanguages) | Set preferred languages for captions. |
| [setPreferredClosedCaptionService](#setPreferredClosedCaptionService) | Sets the PreferredClosedCaptionService. |
| [setPresentationLanguage](#setPresentationLanguage) | Sets the presentationLanguage in a full BCP 47 value, including script, region, variant |
| [setPrivacyMode](#setPrivacyMode) | Sets the PrivacyMode. |
| [setViewingRestrictions](#setViewingRestrictions) | Sets the ViewingRestrictions. |
| [setViewingRestrictionsWindow](#setViewingRestrictionsWindow) | Sets the ViewingRestrictionsWindow. |
| [setVoiceGuidance](#setVoiceGuidance) | Sets voiceGuidance. Whether Voice Guidance is enabled or not. |
| [setVoiceGuidanceHints](#setVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not. |
| [setVoiceGuidanceRate](#setVoiceGuidanceRate) | Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive. |

<a id="getAudioDescription"></a>
## *getAudioDescription*

Retrieves the persistent user preference for this setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.UserSettings.getAudioDescription"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.UserSettings.getAudioDescription"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "enabled": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getBlockNotRatedContent"></a>
## *getBlockNotRatedContent*

Gets the BlockNotRatedContent setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.blockNotRatedContent | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.UserSettings.getBlockNotRatedContent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.UserSettings.getBlockNotRatedContent"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "blockNotRatedContent": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getCaptions"></a>
## *getCaptions*

Gets the Captions setting. This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions and timed text types. Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes of this state while a playback is active. When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state. This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media players or apps that decode-display internally.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Receives the state |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.UserSettings.getCaptions"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.UserSettings.getCaptions"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "enabled": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getContentPin"></a>
## *getContentPin*

ContentPin is a string of four decimal digits that represents the PIN code which is used to unlock access to restricted AV content.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.contentPin | string | A string of four decimal digits that represents the content PIN. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.UserSettings.getContentPin"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.UserSettings.getContentPin"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "contentPin": 1234
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getHighContrast"></a>
## *getHighContrast*

Gets the current highContrast setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.UserSettings.getHighContrast"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.UserSettings.getHighContrast"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "enabled": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getLiveWatershed"></a>
## *getLiveWatershed*

Gets the LiveWatershed setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.liveWatershed | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.UserSettings.getLiveWatershed"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.UserSettings.getLiveWatershed"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "liveWatershed": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPinControl"></a>
## *getPinControl*

Gets the PinControl setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.pinControl | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.UserSettings.getPinControl"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.UserSettings.getPinControl"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "pinControl": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPinOnPurchase"></a>
## *getPinOnPurchase*

Gets the PinOnPurchase setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.pinOnPurchase | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.UserSettings.getPinOnPurchase"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.UserSettings.getPinOnPurchase"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "pinOnPurchase": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPlaybackWatershed"></a>
## *getPlaybackWatershed*

Gets the PlaybackWatershed setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.playbackWatershed | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.UserSettings.getPlaybackWatershed"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.UserSettings.getPlaybackWatershed"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "playbackWatershed": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPreferredAudioLanguages"></a>
## *getPreferredAudioLanguages*

Retrieves the persistent user preference for this setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.preferredLanguages | string | PreferredLanguages |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.UserSettings.getPreferredAudioLanguages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.UserSettings.getPreferredAudioLanguages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPreferredCaptionsLanguages"></a>
## *getPreferredCaptionsLanguages*

Gets the current PreferredCaptionsLanguages setting

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.preferredLanguages | string | "eng,fra" |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.UserSettings.getPreferredCaptionsLanguages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.UserSettings.getPreferredCaptionsLanguages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPreferredClosedCaptionService"></a>
## *getPreferredClosedCaptionService*

Gets the current PreferredClosedCaptionService setting Valid output for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.service | string | Identifies the service to display . |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.UserSettings.getPreferredClosedCaptionService"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.UserSettings.getPreferredClosedCaptionService"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "service": "CC3"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPresentationLanguage"></a>
## *getPresentationLanguage*

Gets the presentationLanguage in a full BCP 47 value, including script, region, variant

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.presentationLanguage | string | "en-US", "es-US", "en-CA", "fr-CA" |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.UserSettings.getPresentationLanguage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.UserSettings.getPresentationLanguage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "presentationLanguage": "en-US"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPrivacyMode"></a>
## *getPrivacyMode*

Gets the current PrivacyMode setting Valid output for privacyMode is "SHARE", "DO_NOT_SHARE"

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.privacyMode | string | "SHARE" |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.UserSettings.getPrivacyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.UserSettings.getPrivacyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "privacyMode": "DO_NOT_SHARE"
    }
}
```

<a id="getViewingRestrictions"></a>
## *getViewingRestrictions*

Gets the current ViewingRestrictions.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.viewingRestrictions | string | A JSON document that escribes the rating scheme(s) and ratings that are blocked. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.UserSettings.getViewingRestrictions"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.UserSettings.getViewingRestrictions"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "viewingRestrictions": {
            "ratingScheme": "MPAA",
            "ratings": [
                "PG-13",
                "R"
            ]
        }
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getViewingRestrictionsWindow"></a>
## *getViewingRestrictionsWindow*

Gets the current ViewingRestrictionsWindow.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.viewingRestrictionsWindow | string | A project-specific representation of the time interval.Eg: "ALWAYS" |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.UserSettings.getViewingRestrictionsWindow"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.UserSettings.getViewingRestrictionsWindow"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "viewingRestrictionsWindow": "ALWAYS"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getVoiceGuidance"></a>
## *getVoiceGuidance*

Gets the current voiceGuidance setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | Enabled/Disabled |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.UserSettings.getVoiceGuidance"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.UserSettings.getVoiceGuidance"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "enabled": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getVoiceGuidanceHints"></a>
## *getVoiceGuidanceHints*

Gets the current voiceGuidanceHints setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hints | bool | true/false |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.UserSettings.getVoiceGuidanceHints"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.UserSettings.getVoiceGuidanceHints"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "hints": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getVoiceGuidanceRate"></a>
## *getVoiceGuidanceRate*

Gets the current voiceGuidanceRate setting.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.rate | double | Gets Voice Guidance rate |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.UserSettings.getVoiceGuidanceRate"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.UserSettings.getVoiceGuidanceRate"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "rate": 1.0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setAudioDescription"></a>
## *setAudioDescription*

Updates the persistent user preference for this setting. Changes are stored by the UserSettings service and may trigger the corresponding notification event so that applications can react to runtime configuration changes.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setAudioDescription",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.UserSettings.setAudioDescription", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setBlockNotRatedContent"></a>
## *setBlockNotRatedContent*

Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blockNotRatedContent | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setBlockNotRatedContent",
    "params": {
        "blockNotRatedContent": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.UserSettings.setBlockNotRatedContent", "params": {"blockNotRatedContent": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setCaptions"></a>
## *setCaptions*

A setting of ON indicates that Players should select a subtitle track for presentation The Setting does not influence any running sessions. It is up to the player to enforce the setting. This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions and timed text types. Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes of this state while a playback is active. When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state. This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media players or apps that decode-display internally

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Sets the state |
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
    "method": "org.rdk.UserSettings.setCaptions",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.UserSettings.setCaptions", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setContentPin"></a>
## *setContentPin*

ContentPin is a string of four decimal digits that represents the PIN code which is used to unlock access to restricted AV content.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.contentPin | string | A string of four decimal digits that represents the content PIN. |
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
    "method": "org.rdk.UserSettings.setContentPin",
    "params": {
        "contentPin": 1234
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.UserSettings.setContentPin", "params": {"contentPin": 1234}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setHighContrast"></a>
## *setHighContrast*

Sets highContrast. Whether the app should display with high contrast or not.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setHighContrast",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.UserSettings.setHighContrast", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setLiveWatershed"></a>
## *setLiveWatershed*

Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.liveWatershed | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setLiveWatershed",
    "params": {
        "liveWatershed": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.UserSettings.setLiveWatershed", "params": {"liveWatershed": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPinControl"></a>
## *setPinControl*

A setting of ON indicates that Parental Control is enabled. Players should enforce the parental control settings when enabled.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinControl | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setPinControl",
    "params": {
        "pinControl": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.UserSettings.setPinControl", "params": {"pinControl": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPinOnPurchase"></a>
## *setPinOnPurchase*

Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinOnPurchase | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setPinOnPurchase",
    "params": {
        "pinOnPurchase": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.UserSettings.setPinOnPurchase", "params": {"pinOnPurchase": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPlaybackWatershed"></a>
## *setPlaybackWatershed*

Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playbackWatershed | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setPlaybackWatershed",
    "params": {
        "playbackWatershed": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.UserSettings.setPlaybackWatershed", "params": {"playbackWatershed": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPreferredAudioLanguages"></a>
## *setPreferredAudioLanguages*

The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | PreferredLanguages |
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
    "method": "org.rdk.UserSettings.setPreferredAudioLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.UserSettings.setPreferredAudioLanguages", "params": {"preferredLanguages": "eng,fra"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPreferredCaptionsLanguages"></a>
## *setPreferredCaptionsLanguages*

A prioritized list of ISO 639-2/B codes for the preferred Captions languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the subtitle track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred subtitle track.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | Is the list to set () |
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
    "method": "org.rdk.UserSettings.setPreferredCaptionsLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.UserSettings.setPreferredCaptionsLanguages", "params": {"preferredLanguages": "eng,fra"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPreferredClosedCaptionService"></a>
## *setPreferredClosedCaptionService*

The setting should be honored by the player. The behaviour of AUTO may be player specific. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | string | Identifies the service to display . |
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
    "method": "org.rdk.UserSettings.setPreferredClosedCaptionService",
    "params": {
        "service": "CC3"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.UserSettings.setPreferredClosedCaptionService", "params": {"service": "CC3"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPresentationLanguage"></a>
## *setPresentationLanguage*

Stores the user's preferred presentation language. Media players and applications can use this preference to automatically select the most appropriate language for presentation.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.presentationLanguage | string | "en-US", "es-US", "en-CA", "fr-CA" |
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
    "method": "org.rdk.UserSettings.setPresentationLanguage",
    "params": {
        "presentationLanguage": "en-US"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.UserSettings.setPresentationLanguage", "params": {"presentationLanguage": "en-US"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPrivacyMode"></a>
## *setPrivacyMode*

The setting should be honored by the Telemetry. If privacyMode is "DO_NOT_SHARE", logs and crash report should not be uploaded.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privacyMode | string | "SHARE", "DO_NOT_SHARE" |
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
    "method": "org.rdk.UserSettings.setPrivacyMode",
    "params": {
        "privacyMode": "DO_NOT_SHARE"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.UserSettings.setPrivacyMode", "params": {"privacyMode": "DO_NOT_SHARE"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setViewingRestrictions"></a>
## *setViewingRestrictions*

A JSON document that escribes the rating scheme(s) and ratings that are blocked.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictions | string | A JSON document that describes the rating scheme(s) and ratings that are blocked. |
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
    "method": "org.rdk.UserSettings.setViewingRestrictions",
    "params": {
        "viewingRestrictions": {
            "ratingScheme": "MPAA",
            "ratings": [
                "PG-13",
                "R"
            ]
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.UserSettings.setViewingRestrictions", "params": {"viewingRestrictions": {"ratingScheme": "MPAA", "ratings": ["PG-13", "R"]}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setViewingRestrictionsWindow"></a>
## *setViewingRestrictionsWindow*

A project-specific representation of the time interval when viewing restrictions are to be applied, if applicable for the project

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictionsWindow | string | A project-specific representation of the time interval.Eg: "ALWAYS" |
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
    "method": "org.rdk.UserSettings.setViewingRestrictionsWindow",
    "params": {
        "viewingRestrictionsWindow": "ALWAYS"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.UserSettings.setViewingRestrictionsWindow", "params": {"viewingRestrictionsWindow": "ALWAYS"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setVoiceGuidance"></a>
## *setVoiceGuidance*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setVoiceGuidance",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.UserSettings.setVoiceGuidance", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setVoiceGuidanceHints"></a>
## *setVoiceGuidanceHints*

Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hints | bool | Enabled/Disabled |
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
    "method": "org.rdk.UserSettings.setVoiceGuidanceHints",
    "params": {
        "hints": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.UserSettings.setVoiceGuidanceHints", "params": {"hints": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setVoiceGuidanceRate"></a>
## *setVoiceGuidanceRate*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rate | double | Sets Voice Guidance rate |
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
    "method": "org.rdk.UserSettings.setVoiceGuidanceRate",
    "params": {
        "rate": 1.0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.UserSettings.setVoiceGuidanceRate", "params": {"rate": 1.0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IUserSettings-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IUserSettings Interface:

| Event | Description |
| :-------- | :-------- |
| [onAudioDescriptionChanged](#onAudioDescriptionChanged) | The AudioDescription setting has changed. |
| [onBlockNotRatedContentChanged](#onBlockNotRatedContentChanged) | The BlockNotRatedContent setting has changed. |
| [onCaptionsChanged](#onCaptionsChanged) | The Captions setting has changed. |
| [onContentPinChanged](#onContentPinChanged) | The ContentPin setting has changed. |
| [onHighContrastChanged](#onHighContrastChanged) | Triggered after the high contrast settings changes. |
| [onLiveWatershedChanged](#onLiveWatershedChanged) | The LiveWatershed setting has changed. |
| [onPinControlChanged](#onPinControlChanged) | The PinControl setting has changed. |
| [onPinOnPurchaseChanged](#onPinOnPurchaseChanged) | The PinOnPurchase setting has changed. |
| [onPlaybackWatershedChanged](#onPlaybackWatershedChanged) | The PlaybackWatershed setting has changed. |
| [onPreferredAudioLanguagesChanged](#onPreferredAudioLanguagesChanged) | The preferredLanguages setting has changed. |
| [onPreferredCaptionsLanguagesChanged](#onPreferredCaptionsLanguagesChanged) | The PreferredCaptionsLanguages setting has changed. |
| [onPreferredClosedCaptionServiceChanged](#onPreferredClosedCaptionServiceChanged) | The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]". |
| [onPresentationLanguageChanged](#onPresentationLanguageChanged) | The PresentationLanguages setting has changed. |
| [onPrivacyModeChanged](#onPrivacyModeChanged) | The PrivacyMode setting has changed. |
| [onViewingRestrictionsChanged](#onViewingRestrictionsChanged) | The ViewingRestrictions setting has changed. |
| [onViewingRestrictionsWindowChanged](#onViewingRestrictionsWindowChanged) | The ViewingRestrictionsWindow setting has changed. |
| [onVoiceGuidanceChanged](#onVoiceGuidanceChanged) | Triggered after the voice guidance enabled settings changes. |
| [onVoiceGuidanceHintsChanged](#onVoiceGuidanceHintsChanged) | Triggered after the voice guidance hints changes. |
| [onVoiceGuidanceRateChanged](#onVoiceGuidanceRateChanged) | Triggered after the voice guidance rate changed. |

<a id="onAudioDescriptionChanged"></a>
## *onAudioDescriptionChanged*

Triggered when the AudioDescription setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.UserSettings.onAudioDescriptionChanged",
    "params": {
        "enabled": true
    }
}
```

<a id="onBlockNotRatedContentChanged"></a>
## *onBlockNotRatedContentChanged*

Triggered when the BlockNotRatedContent setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.UserSettings.onBlockNotRatedContentChanged",
    "params": {
        "blockNotRatedContent": true
    }
}
```

<a id="onCaptionsChanged"></a>
## *onCaptionsChanged*

Triggered when the Captions setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | Captions enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.UserSettings.onCaptionsChanged",
    "params": {
        "enabled": true
    }
}
```

<a id="onContentPinChanged"></a>
## *onContentPinChanged*

Triggered when the ContentPin setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.contentPin | string | The changed contentPin. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.UserSettings.onContentPinChanged",
    "params": {
        "contentPin": 1234
    }
}
```

<a id="onHighContrastChanged"></a>
## *onHighContrastChanged*

Triggered after the high contrast settings changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | high contrast enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "method": "org.rdk.UserSettings.onHighContrastChanged",
    "params": {
        "enabled": true
    }
}
```

<a id="onLiveWatershedChanged"></a>
## *onLiveWatershedChanged*

Triggered when the LiveWatershed setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.liveWatershed | bool | liveWatershed enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "method": "org.rdk.UserSettings.onLiveWatershedChanged",
    "params": {
        "liveWatershed": true
    }
}
```

<a id="onPinControlChanged"></a>
## *onPinControlChanged*

Triggered when the PinControl setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinControl | bool | pinControl enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 46,
    "method": "org.rdk.UserSettings.onPinControlChanged",
    "params": {
        "pinControl": true
    }
}
```

<a id="onPinOnPurchaseChanged"></a>
## *onPinOnPurchaseChanged*

Triggered when the PinOnPurchase setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinOnPurchase | bool | pinOnPurchase enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 47,
    "method": "org.rdk.UserSettings.onPinOnPurchaseChanged",
    "params": {
        "pinOnPurchase": true
    }
}
```

<a id="onPlaybackWatershedChanged"></a>
## *onPlaybackWatershedChanged*

Triggered when the PlaybackWatershed setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playbackWatershed | bool | playbackWatershed enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 48,
    "method": "org.rdk.UserSettings.onPlaybackWatershedChanged",
    "params": {
        "playbackWatershed": true
    }
}
```

<a id="onPreferredAudioLanguagesChanged"></a>
## *onPreferredAudioLanguagesChanged*

Triggered when the preferredLanguages setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 49,
    "method": "org.rdk.UserSettings.onPreferredAudioLanguagesChanged",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```

<a id="onPreferredCaptionsLanguagesChanged"></a>
## *onPreferredCaptionsLanguagesChanged*

Triggered when the PreferredCaptionsLanguages setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 50,
    "method": "org.rdk.UserSettings.onPreferredCaptionsLanguagesChanged",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```

<a id="onPreferredClosedCaptionServiceChanged"></a>
## *onPreferredClosedCaptionServiceChanged*

Triggered when the PreferredClosedCaptionService setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | string | the changed preferredClosedCaptionService. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 51,
    "method": "org.rdk.UserSettings.onPreferredClosedCaptionServiceChanged",
    "params": {
        "service": "CC3"
    }
}
```

<a id="onPresentationLanguageChanged"></a>
## *onPresentationLanguageChanged*

Triggered when the PresentationLanguages setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.presentationLanguage | string | the changed presentationLanguage. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 52,
    "method": "org.rdk.UserSettings.onPresentationLanguageChanged",
    "params": {
        "presentationLanguage": "en-US"
    }
}
```

<a id="onPrivacyModeChanged"></a>
## *onPrivacyModeChanged*

Triggered when the PrivacyMode setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privacyMode | string | "SHARE", "DO_NOT_SHARE". |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 53,
    "method": "org.rdk.UserSettings.onPrivacyModeChanged",
    "params": {
        "privacyMode": "DO_NOT_SHARE"
    }
}
```

<a id="onViewingRestrictionsChanged"></a>
## *onViewingRestrictionsChanged*

Triggered when the ViewingRestrictions setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictions | string | the changed viewingRestrictions. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 54,
    "method": "org.rdk.UserSettings.onViewingRestrictionsChanged",
    "params": {
        "viewingRestrictions": {
            "ratingScheme": "MPAA",
            "ratings": [
                "PG-13",
                "R"
            ]
        }
    }
}
```

<a id="onViewingRestrictionsWindowChanged"></a>
## *onViewingRestrictionsWindowChanged*

Triggered when the ViewingRestrictionsWindow setting is changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 55,
    "method": "org.rdk.UserSettings.onViewingRestrictionsWindowChanged",
    "params": {
        "viewingRestrictionsWindow": "ALWAYS"
    }
}
```

<a id="onVoiceGuidanceChanged"></a>
## *onVoiceGuidanceChanged*

This event is triggered when the voice guidance setting is updated.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | voice guidance enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 56,
    "method": "org.rdk.UserSettings.onVoiceGuidanceChanged",
    "params": {
        "enabled": true
    }
}
```

<a id="onVoiceGuidanceHintsChanged"></a>
## *onVoiceGuidanceHintsChanged*

This event is triggered when the voice guidance hints setting is updated.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hints | bool | voice guidance hints enabled or not. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 57,
    "method": "org.rdk.UserSettings.onVoiceGuidanceHintsChanged",
    "params": {
        "hints": true
    }
}
```

<a id="onVoiceGuidanceRateChanged"></a>
## *onVoiceGuidanceRateChanged*

This event is triggered when the voice guidance rate setting is updated.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rate | double | the changed voice guidance rate. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 58,
    "method": "org.rdk.UserSettings.onVoiceGuidanceRateChanged",
    "params": {
        "rate": 1.0
    }
}
```

---

<a id="IUserSettingsInspector"></a>
## IUserSettingsInspector Interface

<a id="IUserSettingsInspector-Methods"></a>
### Methods

The following methods are provided by the IUserSettingsInspector Interface:

| Method | Description |
| :-------- | :-------- |
| [getMigrationState](#getMigrationState) | Get the migration state of the respective key |
| [getMigrationStates](#getMigrationStates) | Get the migration state of all the defined keys |

<a id="getMigrationState"></a>
## *getMigrationState*

Get the migration state of the respective key. If requiresMigration is true, the setting is not valid and should not be used.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.key | string | one of UserSettingsKey. Possible values: PREFERRED_AUDIO_LANGUAGES, AUDIO_DESCRIPTION, CAPTIONS, PREFERRED_CAPTIONS_LANGUAGES, PREFERRED_CLOSED_CAPTION_SERVICE, PRESENTATION_LANGUAGE, HIGH_CONTRAST, PIN_CONTROL, VIEWING_RESTRICTIONS, VIEWING_RESTRICTIONS_WINDOW, LIVE_WATERSHED, PLAYBACK_WATERSHED, BLOCK_NOT_RATED_CONTENT, PIN_ON_PURCHASE, VOICE_GUIDANCE, VOICE_GUIDANCE_RATE, VOICE_GUIDANCE_HINTS, CONTENT_PIN, PRIVACY_MODE |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.requiresMigration | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "method": "org.rdk.UserSettings.getMigrationState",
    "params": {
        "key": 1
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.UserSettings.getMigrationState", "params": {"key": 1}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": {
        "requiresMigration": true
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getMigrationStates"></a>
## *getMigrationStates*

Get the migration state of all the defined keys. If requiresMigration is true, the setting is not valid and should not be used.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.states | array | array of migration status. |
| result.states[#].key | string | Possible values: PREFERRED_AUDIO_LANGUAGES, AUDIO_DESCRIPTION, CAPTIONS, PREFERRED_CAPTIONS_LANGUAGES, PREFERRED_CLOSED_CAPTION_SERVICE, PRESENTATION_LANGUAGE, HIGH_CONTRAST, PIN_CONTROL, VIEWING_RESTRICTIONS, VIEWING_RESTRICTIONS_WINDOW, LIVE_WATERSHED, PLAYBACK_WATERSHED, BLOCK_NOT_RATED_CONTENT, PIN_ON_PURCHASE, VOICE_GUIDANCE, VOICE_GUIDANCE_RATE, VOICE_GUIDANCE_HINTS, CONTENT_PIN, PRIVACY_MODE |
| result.states[#].requiresMigration | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.UserSettings.getMigrationStates"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.UserSettings.getMigrationStates"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": [
        {
            "key": 1,
            "requiresMigration": true
        },
        {
            "key": 2,
            "requiresMigration": false
        }
    ]
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

