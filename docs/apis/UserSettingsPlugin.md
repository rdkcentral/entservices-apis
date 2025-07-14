<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.UserSettings_Plugin"></a>
# UserSettings Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/UserSettings/CHANGELOG.md)**

A UserSettings plugin for Thunder framework.

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

The `UserSettings` plugin provides an interface for UserSettings.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.UserSettings) |
| classname | string | Class name: *UserSettings* |
| locator | string | Library name: *libWPEFrameworkUserSettings.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the UserSettings plugin:

UserSettings interface methods:

| Method | Description |
| :-------- | :-------- |
| [getAudioDescription](#method.getAudioDescription) | Gets the current AudioDescription setting |
| [getBlockNotRatedContent](#method.getBlockNotRatedContent) | Gets the BlockNotRatedContent setting |
| [getCaptions](#method.getCaptions) | Gets the Captions setting. |
| [getContentPin](#method.getContentPin) | Gets the ContentPin. |
| [getHighContrast](#method.getHighContrast) | Gets the current highContrast setting. |
| [getLiveWatershed](#method.getLiveWatershed) | Gets the LiveWatershed setting |
| [getMigrationState](#method.getMigrationState) | Get the migration state of the respective key |
| [getMigrationStates](#method.getMigrationStates) | Get the migration state of all the defined keys |
| [getPinControl](#method.getPinControl) | Gets the PinControl setting |
| [getPinOnPurchase](#method.getPinOnPurchase) | Gets the PinOnPurchase setting |
| [getPlaybackWatershed](#method.getPlaybackWatershed) | Gets the PlaybackWatershed setting |
| [getPreferredAudioLanguages](#method.getPreferredAudioLanguages) | Gets the current PreferredAudioLanguages setting |
| [getPreferredCaptionsLanguages](#method.getPreferredCaptionsLanguages) | Gets the current PreferredCaptionsLanguages setting. |
| [getPreferredClosedCaptionService](#method.getPreferredClosedCaptionService) | Gets the current PreferredClosedCaptionService setting. |
| [getPresentationLanguage](#method.getPresentationLanguage) | Gets the presentationLanguage |
| [getPrivacyMode](#method.getPrivacyMode) | Gets the current PrivacyMode setting. |
| [getViewingRestrictions](#method.getViewingRestrictions) | Gets the current ViewingRestrictions. |
| [getViewingRestrictionsWindow](#method.getViewingRestrictionsWindow) | Gets the current ViewingRestrictionsWindow. |
| [getVoiceGuidance](#method.getVoiceGuidance) | Gets the current voiceGuidance setting. |
| [getVoiceGuidanceHints](#method.getVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting. |
| [getVoiceGuidanceRate](#method.getVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting. |
| [setAudioDescription](#method.setAudioDescription) | Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled |
| [setBlockNotRatedContent](#method.setBlockNotRatedContent) | Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project. |
| [setCaptions](#method.setCaptions) | brief Sets Captions ON/OFF. |
| [setContentPin](#method.setContentPin) | Sets the ContentPin. |
| [setHighContrast](#method.setHighContrast) | Sets highContrast. Whether the app should display with high contrast or not. |
| [setLiveWatershed](#method.setLiveWatershed) | Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project. |
| [setPinControl](#method.setPinControl) | Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled. |
| [setPinOnPurchase](#method.setPinOnPurchase) | Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted. |
| [setPlaybackWatershed](#method.setPlaybackWatershed) | Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project. |
| [setPreferredAudioLanguages](#method.setPreferredAudioLanguages) | A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track. |
| [setPreferredCaptionsLanguages](#method.setPreferredCaptionsLanguages) | Set preferred languages for captions. |
| [setPreferredClosedCaptionService](#method.setPreferredClosedCaptionService) | Sets the PreferredClosedCaptionService. |
| [setPresentationLanguage](#method.setPresentationLanguage) | Sets the presentationLanguage in a full BCP 47 value, including script, region, variant |
| [setPrivacyMode](#method.setPrivacyMode) | Sets the PrivacyMode. |
| [setViewingRestrictions](#method.setViewingRestrictions) | Sets the ViewingRestrictions. |
| [setViewingRestrictionsWindow](#method.setViewingRestrictionsWindow) | Sets the ViewingRestrictionsWindow. |
| [setVoiceGuidance](#method.setVoiceGuidance) | Sets voiceGuidance. Whether Voice Guidance is enabled or not. |
| [setVoiceGuidanceHints](#method.setVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not. |
| [setVoiceGuidanceRate](#method.setVoiceGuidanceRate) | Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive. |

<a id="method.getAudioDescription"></a>
## *getAudioDescription [<sup>method</sup>](#head.Methods)*

Gets the current AudioDescription setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": true
}
```

<a id="method.getBlockNotRatedContent"></a>
## *getBlockNotRatedContent [<sup>method</sup>](#head.Methods)*

Gets the BlockNotRatedContent setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": true
}
```

<a id="method.getCaptions"></a>
## *getCaptions [<sup>method</sup>](#head.Methods)*

Gets the Captions setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": true
}
```

<a id="method.getContentPin"></a>
## *getContentPin [<sup>method</sup>](#head.Methods)*

Gets the ContentPin.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```

<a id="method.getHighContrast"></a>
## *getHighContrast [<sup>method</sup>](#head.Methods)*

Gets the current highContrast setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": true
}
```

<a id="method.getLiveWatershed"></a>
## *getLiveWatershed [<sup>method</sup>](#head.Methods)*

Gets the LiveWatershed setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": true
}
```

<a id="method.getMigrationState"></a>
## *getMigrationState [<sup>method</sup>](#head.Methods)*

Get the migration state of the respective key

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.key | SettingsKey | one of UserSettingsKey |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.requiresMigration | bool | - |

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```

<a id="method.getMigrationStates"></a>
## *getMigrationStates [<sup>method</sup>](#head.Methods)*

Get the migration state of all the defined keys

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.states | IUserSettingsMigrationStateIterator | array of migration status. |
| result.states[#].key | SettingsKey | - |
| result.states[#].requiresMigration | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.UserSettings.getMigrationStates"
}
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

<a id="method.getPinControl"></a>
## *getPinControl [<sup>method</sup>](#head.Methods)*

Gets the PinControl setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": true
}
```

<a id="method.getPinOnPurchase"></a>
## *getPinOnPurchase [<sup>method</sup>](#head.Methods)*

Gets the PinOnPurchase setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": true
}
```

<a id="method.getPlaybackWatershed"></a>
## *getPlaybackWatershed [<sup>method</sup>](#head.Methods)*

Gets the PlaybackWatershed setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": true
}
```

<a id="method.getPreferredAudioLanguages"></a>
## *getPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*

Gets the current PreferredAudioLanguages setting

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": "eng,fra"
}
```

<a id="method.getPreferredCaptionsLanguages"></a>
## *getPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*

Gets the current PreferredCaptionsLanguages setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": "eng,fra"
}
```

<a id="method.getPreferredClosedCaptionService"></a>
## *getPreferredClosedCaptionService [<sup>method</sup>](#head.Methods)*

Gets the current PreferredClosedCaptionService setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": "CC3"
}
```

<a id="method.getPresentationLanguage"></a>
## *getPresentationLanguage [<sup>method</sup>](#head.Methods)*

Gets the presentationLanguage

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": ""
}
```

<a id="method.getPrivacyMode"></a>
## *getPrivacyMode [<sup>method</sup>](#head.Methods)*

Gets the current PrivacyMode setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": ""
}
```

<a id="method.getViewingRestrictions"></a>
## *getViewingRestrictions [<sup>method</sup>](#head.Methods)*

Gets the current ViewingRestrictions.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": ""
}
```

<a id="method.getViewingRestrictionsWindow"></a>
## *getViewingRestrictionsWindow [<sup>method</sup>](#head.Methods)*

Gets the current ViewingRestrictionsWindow.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": ""
}
```

<a id="method.getVoiceGuidance"></a>
## *getVoiceGuidance [<sup>method</sup>](#head.Methods)*

Gets the current voiceGuidance setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": true
}
```

<a id="method.getVoiceGuidanceHints"></a>
## *getVoiceGuidanceHints [<sup>method</sup>](#head.Methods)*

Gets the current voiceGuidanceHints setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": true
}
```

<a id="method.getVoiceGuidanceRate"></a>
## *getVoiceGuidanceRate [<sup>method</sup>](#head.Methods)*

Gets the current voiceGuidanceRate setting.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": 0.0
}
```

<a id="method.setAudioDescription"></a>
## *setAudioDescription [<sup>method</sup>](#head.Methods)*

Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": null
}
```

<a id="method.setBlockNotRatedContent"></a>
## *setBlockNotRatedContent [<sup>method</sup>](#head.Methods)*

Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": null
}
```

<a id="method.setCaptions"></a>
## *setCaptions [<sup>method</sup>](#head.Methods)*

brief Sets Captions ON/OFF.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": null
}
```

<a id="method.setContentPin"></a>
## *setContentPin [<sup>method</sup>](#head.Methods)*

Sets the ContentPin.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.contentPin | string | The changed contentPin. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="method.setHighContrast"></a>
## *setHighContrast [<sup>method</sup>](#head.Methods)*

Sets highContrast. Whether the app should display with high contrast or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="method.setLiveWatershed"></a>
## *setLiveWatershed [<sup>method</sup>](#head.Methods)*

Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.liveWatershed | bool | liveWatershed enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```

<a id="method.setPinControl"></a>
## *setPinControl [<sup>method</sup>](#head.Methods)*

Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinControl | bool | pinControl enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": null
}
```

<a id="method.setPinOnPurchase"></a>
## *setPinOnPurchase [<sup>method</sup>](#head.Methods)*

Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pinOnPurchase | bool | pinOnPurchase enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": null
}
```

<a id="method.setPlaybackWatershed"></a>
## *setPlaybackWatershed [<sup>method</sup>](#head.Methods)*

Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.playbackWatershed | bool | playbackWatershed enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": null
}
```

<a id="method.setPreferredAudioLanguages"></a>
## *setPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*

A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": null
}
```

<a id="method.setPreferredCaptionsLanguages"></a>
## *setPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*

Set preferred languages for captions.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.preferredLanguages | string | the changed preferredLanguages. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": null
}
```

<a id="method.setPreferredClosedCaptionService"></a>
## *setPreferredClosedCaptionService [<sup>method</sup>](#head.Methods)*

Sets the PreferredClosedCaptionService.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.service | string | the changed preferredClosedCaptionService. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": null
}
```

<a id="method.setPresentationLanguage"></a>
## *setPresentationLanguage [<sup>method</sup>](#head.Methods)*

Sets the presentationLanguage in a full BCP 47 value, including script, region, variant

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.presentationLanguage | string | the changed presentationLanguage. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": null
}
```

<a id="method.setPrivacyMode"></a>
## *setPrivacyMode [<sup>method</sup>](#head.Methods)*

Sets the PrivacyMode.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privacyMode | string | "SHARE", "DO_NOT_SHARE". |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": null
}
```

<a id="method.setViewingRestrictions"></a>
## *setViewingRestrictions [<sup>method</sup>](#head.Methods)*

Sets the ViewingRestrictions.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictions | string | the changed viewingRestrictions. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": null
}
```

<a id="method.setViewingRestrictionsWindow"></a>
## *setViewingRestrictionsWindow [<sup>method</sup>](#head.Methods)*

Sets the ViewingRestrictionsWindow.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": null
}
```

<a id="method.setVoiceGuidance"></a>
## *setVoiceGuidance [<sup>method</sup>](#head.Methods)*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": null
}
```

<a id="method.setVoiceGuidanceHints"></a>
## *setVoiceGuidanceHints [<sup>method</sup>](#head.Methods)*

Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hints | bool | voice guidance hints enabled or not. |
### Results
This method returns no results.

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


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": null
}
```

<a id="method.setVoiceGuidanceRate"></a>
## *setVoiceGuidanceRate [<sup>method</sup>](#head.Methods)*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rate | double | the changed voice guidance rate. |
### Results
This method returns no results.

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

The following events are provided by the UserSettings plugin:

UserSettings interface events:

| Event | Description |
| :-------- | :-------- |
| [onAudioDescriptionChanged](#event.onAudioDescriptionChanged) | The AudioDescription setting has changed. |
| [onBlockNotRatedContentChanged](#event.onBlockNotRatedContentChanged) | The BlockNotRatedContent setting has changed. |
| [onCaptionsChanged](#event.onCaptionsChanged) | The Captions setting has changed. |
| [onContentPinChanged](#event.onContentPinChanged) | The ContentPin setting has changed. |
| [onHighContrastChanged](#event.onHighContrastChanged) | Triggered after the high contrast settings changes. |
| [onLiveWatershedChanged](#event.onLiveWatershedChanged) | The LiveWatershed setting has changed. |
| [onPinControlChanged](#event.onPinControlChanged) | The PinControl setting has changed. |
| [onPinOnPurchaseChanged](#event.onPinOnPurchaseChanged) | The PinOnPurchase setting has changed. |
| [onPlaybackWatershedChanged](#event.onPlaybackWatershedChanged) | The PlaybackWatershed setting has changed. |
| [onPreferredAudioLanguagesChanged](#event.onPreferredAudioLanguagesChanged) | The preferredLanguages setting has changed. |
| [onPreferredCaptionsLanguagesChanged](#event.onPreferredCaptionsLanguagesChanged) | The PreferredCaptionsLanguages setting has changed. |
| [onPreferredClosedCaptionServiceChanged](#event.onPreferredClosedCaptionServiceChanged) | The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]". |
| [onPresentationLanguageChanged](#event.onPresentationLanguageChanged) | The PresentationLanguages setting has changed. |
| [onPrivacyModeChanged](#event.onPrivacyModeChanged) | The PrivacyMode setting has changed. |
| [onViewingRestrictionsChanged](#event.onViewingRestrictionsChanged) | The ViewingRestrictions setting has changed. |
| [onViewingRestrictionsWindowChanged](#event.onViewingRestrictionsWindowChanged) | The ViewingRestrictionsWindow setting has changed. |
| [onVoiceGuidanceChanged](#event.onVoiceGuidanceChanged) | Triggered after the voice guidance enabled settings changes. |
| [onVoiceGuidanceHintsChanged](#event.onVoiceGuidanceHintsChanged) | Triggered after the voice guidance hints changes. |
| [onVoiceGuidanceRateChanged](#event.onVoiceGuidanceRateChanged) | Triggered after the voice guidance rate changed. |

<a id="event.onAudioDescriptionChanged"></a>
## *onAudioDescriptionChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onBlockNotRatedContentChanged"></a>
## *onBlockNotRatedContentChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onCaptionsChanged"></a>
## *onCaptionsChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onContentPinChanged"></a>
## *onContentPinChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onHighContrastChanged"></a>
## *onHighContrastChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onLiveWatershedChanged"></a>
## *onLiveWatershedChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPinControlChanged"></a>
## *onPinControlChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPinOnPurchaseChanged"></a>
## *onPinOnPurchaseChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPlaybackWatershedChanged"></a>
## *onPlaybackWatershedChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPreferredAudioLanguagesChanged"></a>
## *onPreferredAudioLanguagesChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPreferredCaptionsLanguagesChanged"></a>
## *onPreferredCaptionsLanguagesChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPreferredClosedCaptionServiceChanged"></a>
## *onPreferredClosedCaptionServiceChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPresentationLanguageChanged"></a>
## *onPresentationLanguageChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onPrivacyModeChanged"></a>
## *onPrivacyModeChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onViewingRestrictionsChanged"></a>
## *onViewingRestrictionsChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onViewingRestrictionsWindowChanged"></a>
## *onViewingRestrictionsWindowChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onVoiceGuidanceChanged"></a>
## *onVoiceGuidanceChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onVoiceGuidanceHintsChanged"></a>
## *onVoiceGuidanceHintsChanged [<sup>event</sup>](#head.Notifications)*

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

<a id="event.onVoiceGuidanceRateChanged"></a>
## *onVoiceGuidanceRateChanged [<sup>event</sup>](#head.Notifications)*

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
