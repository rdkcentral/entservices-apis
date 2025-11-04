<!-- Generated automatically, DO NOT EDIT! -->
<a id="UserSettings_Plugin"></a>
# UserSettings Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/UserSettings/IUserSettings.h)**

A UserSettings plugin for Thunder framework.

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

The `UserSettings` plugin provides an interface for UserSettings.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.UserSettings) |
| classname | string | Class name: *UserSettings* |
| locator | string | Library name: *libWPEFrameworkUserSettings.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the UserSettings plugin:

UserSettings interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getAudioDescription](#getAudioDescription) | Gets the current AudioDescription setting | NA |
| [getBlockNotRatedContent](#getBlockNotRatedContent) | Gets the BlockNotRatedContent setting | NA |
| [getCaptions](#getCaptions) | Gets the Captions setting. | NA |
| [getContentPin](#getContentPin) | Gets the ContentPin. | NA |
| [getHighContrast](#getHighContrast) | Gets the current highContrast setting. | NA |
| [getLiveWatershed](#getLiveWatershed) | Gets the LiveWatershed setting | NA |
| [getMigrationState](#getMigrationState) | Get the migration state of the respective key | NA |
| [getMigrationStates](#getMigrationStates) | Get the migration state of all the defined keys | NA |
| [getPinControl](#getPinControl) | Gets the PinControl setting | NA |
| [getPinOnPurchase](#getPinOnPurchase) | Gets the PinOnPurchase setting | NA |
| [getPlaybackWatershed](#getPlaybackWatershed) | Gets the PlaybackWatershed setting | NA |
| [getPreferredAudioLanguages](#getPreferredAudioLanguages) | Gets the current PreferredAudioLanguages setting | NA |
| [getPreferredCaptionsLanguages](#getPreferredCaptionsLanguages) | Gets the current PreferredCaptionsLanguages setting. | NA |
| [getPreferredClosedCaptionService](#getPreferredClosedCaptionService) | Gets the current PreferredClosedCaptionService setting. | NA |
| [getPresentationLanguage](#getPresentationLanguage) | Gets the presentationLanguage | NA |
| [getPrivacyMode](#getPrivacyMode) | Gets the current PrivacyMode setting. | NA |
| [getViewingRestrictions](#getViewingRestrictions) | Gets the current ViewingRestrictions. | NA |
| [getViewingRestrictionsWindow](#getViewingRestrictionsWindow) | Gets the current ViewingRestrictionsWindow. | NA |
| [getVoiceGuidance](#getVoiceGuidance) | Gets the current voiceGuidance setting. | NA |
| [getVoiceGuidanceHints](#getVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting. | NA |
| [getVoiceGuidanceRate](#getVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting. | NA |
| [setAudioDescription](#setAudioDescription) | Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled | onAudioDescriptionChanged |
| [setBlockNotRatedContent](#setBlockNotRatedContent) | Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project. | onBlockNotRatedContentChanged |
| [setCaptions](#setCaptions) | brief Sets Captions ON/OFF. | onCaptionsChanged |
| [setContentPin](#setContentPin) | Sets the ContentPin. | onContentPinChanged |
| [setHighContrast](#setHighContrast) | Sets highContrast. Whether the app should display with high contrast or not. | onHighContrastChanged |
| [setLiveWatershed](#setLiveWatershed) | Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project. | onLiveWatershedChanged |
| [setPinControl](#setPinControl) | Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled. | onPinControlChanged |
| [setPinOnPurchase](#setPinOnPurchase) | Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted. | onPinOnPurchaseChanged |
| [setPlaybackWatershed](#setPlaybackWatershed) | Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project. | onPlaybackWatershedChanged |
| [setPreferredAudioLanguages](#setPreferredAudioLanguages) | A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track. | onPreferredAudioLanguagesChanged |
| [setPreferredCaptionsLanguages](#setPreferredCaptionsLanguages) | Set preferred languages for captions. | onPreferredCaptionsLanguagesChanged |
| [setPreferredClosedCaptionService](#setPreferredClosedCaptionService) | Sets the PreferredClosedCaptionService. | onPreferredClosedCaptionServiceChanged |
| [setPresentationLanguage](#setPresentationLanguage) | Sets the presentationLanguage in a full BCP 47 value, including script, region, variant | onPresentationLanguageChanged |
| [setPrivacyMode](#setPrivacyMode) | Sets the PrivacyMode. | onPrivacyModeChanged |
| [setViewingRestrictions](#setViewingRestrictions) | Sets the ViewingRestrictions. | onViewingRestrictionsChanged |
| [setViewingRestrictionsWindow](#setViewingRestrictionsWindow) | Sets the ViewingRestrictionsWindow. | onViewingRestrictionsWindowChanged |
| [setVoiceGuidance](#setVoiceGuidance) | Sets voiceGuidance. Whether Voice Guidance is enabled or not. | onVoiceGuidanceChanged |
| [setVoiceGuidanceHints](#setVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not. | onVoiceGuidanceHintsChanged |
| [setVoiceGuidanceRate](#setVoiceGuidanceRate) | Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive. | onVoiceGuidanceRateChanged |

<a id="getAudioDescription"></a>
## *getAudioDescription*

Gets the current AudioDescription setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | audioDescription enabled or not |

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

<a id="getBlockNotRatedContent"></a>
## *getBlockNotRatedContent*

Gets the BlockNotRatedContent setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |

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

<a id="getCaptions"></a>
## *getCaptions*

Gets the Captions setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | audioDescription enabled or not |

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

<a id="getContentPin"></a>
## *getContentPin*

Gets the ContentPin.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.contentPin | string | The changed contentPin. |

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
        "contentPin": ""
    }
}
```

<a id="getHighContrast"></a>
## *getHighContrast*

Gets the current highContrast setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | audioDescription enabled or not |

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

<a id="getLiveWatershed"></a>
## *getLiveWatershed*

Gets the LiveWatershed setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.liveWatershed | bool | liveWatershed enabled or not. |

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

<a id="getMigrationState"></a>
## *getMigrationState*

Get the migration state of the respective key

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.key | string | one of UserSettingsKey |
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
    "id": 6,
    "method": "org.rdk.UserSettings.getMigrationState",
    "params": {
        "key": "PREFERRED_AUDIO_LANGUAGES"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.UserSettings.getMigrationState", "params": {"key": "PREFERRED_AUDIO_LANGUAGES"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "requiresMigration": true
    }
}
```

<a id="getMigrationStates"></a>
## *getMigrationStates*

Get the migration state of all the defined keys

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.states | IUserSettingsMigrationStateIterator | array of migration status. |
| result.states[#].key | string |  |
| result.states[#].requiresMigration | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.UserSettings.getMigrationStates"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.UserSettings.getMigrationStates"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": [
        {
            "key": "PREFERRED_AUDIO_LANGUAGES",
            "requiresMigration": true
        }
    ]
}
```

<a id="getPinControl"></a>
## *getPinControl*

Gets the PinControl setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.pinControl | bool | pinControl enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.UserSettings.getPinControl"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.UserSettings.getPinControl"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "pinControl": true
    }
}
```

<a id="getPinOnPurchase"></a>
## *getPinOnPurchase*

Gets the PinOnPurchase setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.pinOnPurchase | bool | pinOnPurchase enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.UserSettings.getPinOnPurchase"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.UserSettings.getPinOnPurchase"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "pinOnPurchase": true
    }
}
```

<a id="getPlaybackWatershed"></a>
## *getPlaybackWatershed*

Gets the PlaybackWatershed setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.playbackWatershed | bool | playbackWatershed enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.UserSettings.getPlaybackWatershed"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.UserSettings.getPlaybackWatershed"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "playbackWatershed": true
    }
}
```

<a id="getPreferredAudioLanguages"></a>
## *getPreferredAudioLanguages*

Gets the current PreferredAudioLanguages setting

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.preferredLanguages | string | the changed preferredLanguages. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.UserSettings.getPreferredAudioLanguages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.UserSettings.getPreferredAudioLanguages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```

<a id="getPreferredCaptionsLanguages"></a>
## *getPreferredCaptionsLanguages*

Gets the current PreferredCaptionsLanguages setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.preferredLanguages | string | the changed preferredLanguages. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.UserSettings.getPreferredCaptionsLanguages"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.UserSettings.getPreferredCaptionsLanguages"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```

<a id="getPreferredClosedCaptionService"></a>
## *getPreferredClosedCaptionService*

Gets the current PreferredClosedCaptionService setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.service | string | the changed preferredClosedCaptionService. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.UserSettings.getPreferredClosedCaptionService"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.UserSettings.getPreferredClosedCaptionService"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "service": "CC3"
    }
}
```

<a id="getPresentationLanguage"></a>
## *getPresentationLanguage*

Gets the presentationLanguage

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.presentationLanguage | string | the changed presentationLanguage. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.UserSettings.getPresentationLanguage"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.UserSettings.getPresentationLanguage"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "presentationLanguage": ""
    }
}
```

<a id="getPrivacyMode"></a>
## *getPrivacyMode*

Gets the current PrivacyMode setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.privacyMode | string | "SHARE", "DO_NOT_SHARE". |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.UserSettings.getPrivacyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.UserSettings.getPrivacyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "privacyMode": ""
    }
}
```

<a id="getViewingRestrictions"></a>
## *getViewingRestrictions*

Gets the current ViewingRestrictions.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.viewingRestrictions | string | the changed viewingRestrictions. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.UserSettings.getViewingRestrictions"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.UserSettings.getViewingRestrictions"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "viewingRestrictions": ""
    }
}
```

<a id="getViewingRestrictionsWindow"></a>
## *getViewingRestrictionsWindow*

Gets the current ViewingRestrictionsWindow.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.UserSettings.getViewingRestrictionsWindow"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.UserSettings.getViewingRestrictionsWindow"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "viewingRestrictionsWindow": ""
    }
}
```

<a id="getVoiceGuidance"></a>
## *getVoiceGuidance*

Gets the current voiceGuidance setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.enabled | bool | audioDescription enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.UserSettings.getVoiceGuidance"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.UserSettings.getVoiceGuidance"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "enabled": true
    }
}
```

<a id="getVoiceGuidanceHints"></a>
## *getVoiceGuidanceHints*

Gets the current voiceGuidanceHints setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hints | bool | voice guidance hints enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.UserSettings.getVoiceGuidanceHints"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.UserSettings.getVoiceGuidanceHints"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "hints": true
    }
}
```

<a id="getVoiceGuidanceRate"></a>
## *getVoiceGuidanceRate*

Gets the current voiceGuidanceRate setting.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.rate | double | the changed voice guidance rate. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.UserSettings.getVoiceGuidanceRate"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.UserSettings.getVoiceGuidanceRate"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "rate": 0.0
    }
}
```

<a id="setAudioDescription"></a>
## *setAudioDescription*

Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled

### Events
| Event | Description |
| :-------- | :-------- |
| [onAudioDescriptionChanged ](#event.onAudioDescriptionChanged ) |  Triggered when the audio description changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
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
    "method": "org.rdk.UserSettings.setAudioDescription",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.UserSettings.setAudioDescription", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="setBlockNotRatedContent"></a>
## *setBlockNotRatedContent*

Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project.

### Events
| Event | Description |
| :-------- | :-------- |
| [onBlockNotRatedContentChanged ](#event.onBlockNotRatedContentChanged ) |  Triggered when the blockNotRatedContent changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |
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
    "method": "org.rdk.UserSettings.setBlockNotRatedContent",
    "params": {
        "blockNotRatedContent": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.UserSettings.setBlockNotRatedContent", "params": {"blockNotRatedContent": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="setCaptions"></a>
## *setCaptions*

A setting of ON indicates that Players should select a subtitle track for presentation The Setting does not influence any running sessions. It is up to the player to enforce the setting. This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions and timed text types. Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes of this state while a playback is active. When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state. This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media players or apps that decode-display internally

### Events
| Event | Description |
| :-------- | :-------- |
| [onCaptionsChanged ](#event.onCaptionsChanged ) |  Triggered when the captions changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
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
    "method": "org.rdk.UserSettings.setCaptions",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.UserSettings.setCaptions", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="setContentPin"></a>
## *setContentPin*

ContentPin is a string of four decimal digits that represents the PIN code which is used to unlock access to restricted AV content.

### Events
| Event | Description |
| :-------- | :-------- |
| [onContentPinChanged ](#event.onContentPinChanged ) |  Triggered when the ContentPin changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.contentPin | string | The changed contentPin. |
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
    "method": "org.rdk.UserSettings.setContentPin",
    "params": {
        "contentPin": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.UserSettings.setContentPin", "params": {"contentPin": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="setHighContrast"></a>
## *setHighContrast*

Sets highContrast. Whether the app should display with high contrast or not.

### Events
| Event | Description |
| :-------- | :-------- |
| [onHighContrastChanged ](#event.onHighContrastChanged ) |  Triggers when the highContrast changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
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
    "method": "org.rdk.UserSettings.setHighContrast",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.UserSettings.setHighContrast", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="setLiveWatershed"></a>
## *setLiveWatershed*

Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project.

### Events
| Event | Description |
| :-------- | :-------- |
| [onLiveWatershedChanged ](#event.onLiveWatershedChanged ) |  Triggered when the liveWatershed changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.liveWatershed | bool | liveWatershed enabled or not. |
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
    "method": "org.rdk.UserSettings.setLiveWatershed",
    "params": {
        "liveWatershed": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.UserSettings.setLiveWatershed", "params": {"liveWatershed": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="setPinControl"></a>
## *setPinControl*

Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPinControlChanged ](#event.onPinControlChanged ) |  Triggered when the pincontrol changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinControl | bool | pinControl enabled or not. |
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
    "method": "org.rdk.UserSettings.setPinControl",
    "params": {
        "pinControl": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.UserSettings.setPinControl", "params": {"pinControl": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="setPinOnPurchase"></a>
## *setPinOnPurchase*

Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPinOnPurchaseChanged ](#event.onPinOnPurchaseChanged ) |  Triggered when the pin on the purchase changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinOnPurchase | bool | pinOnPurchase enabled or not. |
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
    "method": "org.rdk.UserSettings.setPinOnPurchase",
    "params": {
        "pinOnPurchase": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.UserSettings.setPinOnPurchase", "params": {"pinOnPurchase": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="setPlaybackWatershed"></a>
## *setPlaybackWatershed*

Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPlaybackWatershedChanged ](#event.onPlaybackWatershedChanged ) |  Triggered when the playbackWatershed changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playbackWatershed | bool | playbackWatershed enabled or not. |
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
    "method": "org.rdk.UserSettings.setPlaybackWatershed",
    "params": {
        "playbackWatershed": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.UserSettings.setPlaybackWatershed", "params": {"playbackWatershed": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="setPreferredAudioLanguages"></a>
## *setPreferredAudioLanguages*

A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPreferredAudioLanguagesChanged ](#event.onPreferredAudioLanguagesChanged ) |  Triggered when the audio preferred Audio languages changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |
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
    "method": "org.rdk.UserSettings.setPreferredAudioLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.UserSettings.setPreferredAudioLanguages", "params": {"preferredLanguages": "eng,fra"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="setPreferredCaptionsLanguages"></a>
## *setPreferredCaptionsLanguages*

A prioritized list of ISO 639-2/B codes for the preferred Captions languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the subtitle track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred subtitle track.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPreferredCaptionsLanguagesChanged ](#event.onPreferredCaptionsLanguagesChanged ) |  Triggered when the PreferredCaption Languages changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |
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
    "method": "org.rdk.UserSettings.setPreferredCaptionsLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.UserSettings.setPreferredCaptionsLanguages", "params": {"preferredLanguages": "eng,fra"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```

<a id="setPreferredClosedCaptionService"></a>
## *setPreferredClosedCaptionService*

The setting should be honored by the player. The behaviour of AUTO may be player specific. Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"

### Events
| Event | Description |
| :-------- | :-------- |
| [onPreferredClosedCaptionServiceChanged ](#event.onPreferredClosedCaptionServiceChanged ) |  Triggered when the Preferred Closed Caption changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | string | the changed preferredClosedCaptionService. |
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
    "method": "org.rdk.UserSettings.setPreferredClosedCaptionService",
    "params": {
        "service": "CC3"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.UserSettings.setPreferredClosedCaptionService", "params": {"service": "CC3"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="setPresentationLanguage"></a>
## *setPresentationLanguage*

Sets the presentationLanguage in a full BCP 47 value, including script, region, variant

### Events
| Event | Description |
| :-------- | :-------- |
| [onPresentationLanguageChanged ](#event.onPresentationLanguageChanged ) |  Triggered when the presentation Language changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.presentationLanguage | string | the changed presentationLanguage. |
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
    "method": "org.rdk.UserSettings.setPresentationLanguage",
    "params": {
        "presentationLanguage": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.UserSettings.setPresentationLanguage", "params": {"presentationLanguage": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```

<a id="setPrivacyMode"></a>
## *setPrivacyMode*

The setting should be honored by the Telemetry. If privacyMode is "DO_NOT_SHARE", logs and crash report should not be uploaded.

### Events
| Event | Description |
| :-------- | :-------- |
| [onPrivacyModeChanged ](#event.onPrivacyModeChanged ) |  Triggered when the Privacy Mode changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privacyMode | string | "SHARE", "DO_NOT_SHARE". |
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
    "method": "org.rdk.UserSettings.setPrivacyMode",
    "params": {
        "privacyMode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.UserSettings.setPrivacyMode", "params": {"privacyMode": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```

<a id="setViewingRestrictions"></a>
## *setViewingRestrictions*

A JSON document that escribes the rating scheme(s) and ratings that are blocked.

### Events
| Event | Description |
| :-------- | :-------- |
| [onViewingRestrictionsChanged ](#event.onViewingRestrictionsChanged ) |  Triggered when the viewingRestrictions changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictions | string | the changed viewingRestrictions. |
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
    "method": "org.rdk.UserSettings.setViewingRestrictions",
    "params": {
        "viewingRestrictions": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.UserSettings.setViewingRestrictions", "params": {"viewingRestrictions": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```

<a id="setViewingRestrictionsWindow"></a>
## *setViewingRestrictionsWindow*

A project-specific representation of the time interval when viewing restrictions are to be applied, if applicable for the project

### Events
| Event | Description |
| :-------- | :-------- |
| [onViewingRestrictionsWindowChanged ](#event.onViewingRestrictionsWindowChanged ) |  Triggered when the viewingRestrictionsWindow changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |
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
    "method": "org.rdk.UserSettings.setViewingRestrictionsWindow",
    "params": {
        "viewingRestrictionsWindow": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.UserSettings.setViewingRestrictionsWindow", "params": {"viewingRestrictionsWindow": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": null
}
```

<a id="setVoiceGuidance"></a>
## *setVoiceGuidance*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Events
| Event | Description |
| :-------- | :-------- |
| [onVoiceGuidanceChanged ](#event.onVoiceGuidanceChanged ) |  Triggers after the voice guidance enabled settings changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
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
    "method": "org.rdk.UserSettings.setVoiceGuidance",
    "params": {
        "enabled": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.UserSettings.setVoiceGuidance", "params": {"enabled": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": null
}
```

<a id="setVoiceGuidanceHints"></a>
## *setVoiceGuidanceHints*

Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.

### Events
| Event | Description |
| :-------- | :-------- |
| [onVoiceGuidanceHintsChanged ](#event.onVoiceGuidanceHintsChanged ) |  Triggered after the voice guidance hints changes. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hints | bool | voice guidance hints enabled or not. |
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
    "method": "org.rdk.UserSettings.setVoiceGuidanceHints",
    "params": {
        "hints": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.UserSettings.setVoiceGuidanceHints", "params": {"hints": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": null
}
```

<a id="setVoiceGuidanceRate"></a>
## *setVoiceGuidanceRate*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Events
| Event | Description |
| :-------- | :-------- |
| [onVoiceGuidanceRateChanged ](#event.onVoiceGuidanceRateChanged ) |  Triggered after the voice guidance rate changed. |
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rate | double | the changed voice guidance rate. |
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
    "method": "org.rdk.UserSettings.setVoiceGuidanceRate",
    "params": {
        "rate": 0.0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.UserSettings.setVoiceGuidanceRate", "params": {"rate": 0.0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the UserSettings plugin:

UserSettings interface events:

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

The AudioDescription setting has changed.

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

The BlockNotRatedContent setting has changed.

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

The Captions setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |

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

The ContentPin setting has changed.

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
        "contentPin": ""
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
| params.enabled | bool | audioDescription enabled or not |

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

The LiveWatershed setting has changed.

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

The PinControl setting has changed.

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

The PinOnPurchase setting has changed.

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

The PlaybackWatershed setting has changed.

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

The preferredLanguages setting has changed.

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

The PreferredCaptionsLanguages setting has changed.

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

The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".

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

The PresentationLanguages setting has changed.

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
        "presentationLanguage": ""
    }
}
```

<a id="onPrivacyModeChanged"></a>
## *onPrivacyModeChanged*

The PrivacyMode setting has changed.

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
        "privacyMode": ""
    }
}
```

<a id="onViewingRestrictionsChanged"></a>
## *onViewingRestrictionsChanged*

The ViewingRestrictions setting has changed.

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
        "viewingRestrictions": ""
    }
}
```

<a id="onViewingRestrictionsWindowChanged"></a>
## *onViewingRestrictionsWindowChanged*

The ViewingRestrictionsWindow setting has changed.

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
        "viewingRestrictionsWindow": ""
    }
}
```

<a id="onVoiceGuidanceChanged"></a>
## *onVoiceGuidanceChanged*

Triggered after the voice guidance enabled settings changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |

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

Triggered after the voice guidance hints changes.

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

Triggered after the voice guidance rate changed.

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
        "rate": 0.0
    }
}
```
