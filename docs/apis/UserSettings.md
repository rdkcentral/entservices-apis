<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IUserSettings_Plugin"></a>
# IUserSettings Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IUserSettings/CHANGELOG.md)**

A IUserSettings plugin for Thunder framework.

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

The `IUserSettings` plugin provides an interface for IUserSettings.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IUserSettings*) |
| classname | string | Class name: *IUserSettings* |
| locator | string | Library name: *libWPEFrameworkIUserSettings.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IUserSettings plugin:

IUserSettings interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetAudioDescription](#method.GetAudioDescription) | Gets the current AudioDescription setting |
| [GetBlockNotRatedContent](#method.GetBlockNotRatedContent) | Gets the BlockNotRatedContent setting |
| [GetCaptions](#method.GetCaptions) | Gets the Captions setting. |
| [GetHighContrast](#method.GetHighContrast) | Gets the current highContrast setting. |
| [GetLiveWatershed](#method.GetLiveWatershed) | Gets the LiveWatershed setting |
| [GetMigrationState](#method.GetMigrationState) | Get the migration state of the respective key |
| [GetMigrationStates](#method.GetMigrationStates) | Get the migration state of all the defined keys |
| [GetPinControl](#method.GetPinControl) | Gets the PinControl setting |
| [GetPinOnPurchase](#method.GetPinOnPurchase) | Gets the PinOnPurchase setting |
| [GetPlaybackWatershed](#method.GetPlaybackWatershed) | Gets the PlaybackWatershed setting |
| [GetPreferredAudioLanguages](#method.GetPreferredAudioLanguages) | Gets the current PreferredAudioLanguages setting |
| [GetPreferredCaptionsLanguages](#method.GetPreferredCaptionsLanguages) | Gets the current PreferredCaptionsLanguages setting. |
| [GetPreferredClosedCaptionService](#method.GetPreferredClosedCaptionService) | Gets the current PreferredClosedCaptionService setting. |
| [GetPresentationLanguage](#method.GetPresentationLanguage) | Gets the presentationLanguage |
| [GetViewingRestrictions](#method.GetViewingRestrictions) | Gets the current ViewingRestrictions. |
| [GetViewingRestrictionsWindow](#method.GetViewingRestrictionsWindow) | Gets the current ViewingRestrictionsWindow. |
| [GetVoiceGuidance](#method.GetVoiceGuidance) | Gets the current voiceGuidance setting. |
| [GetVoiceGuidanceHints](#method.GetVoiceGuidanceHints) | Gets the current voiceGuidanceHints setting. |
| [GetVoiceGuidanceRate](#method.GetVoiceGuidanceRate) | Gets the current voiceGuidanceRate setting. |
| [SetAudioDescription](#method.SetAudioDescription) | Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled |
| [SetBlockNotRatedContent](#method.SetBlockNotRatedContent) | Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project. |
| [SetCaptions](#method.SetCaptions) | brief Sets Captions ON/OFF. |
| [SetHighContrast](#method.SetHighContrast) | Sets highContrast. Whether the app should display with high contrast or not. |
| [SetLiveWatershed](#method.SetLiveWatershed) | Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project. |
| [SetPinControl](#method.SetPinControl) | Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled. |
| [SetPinOnPurchase](#method.SetPinOnPurchase) | Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted. |
| [SetPlaybackWatershed](#method.SetPlaybackWatershed) | Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project. |
| [SetPreferredAudioLanguages](#method.SetPreferredAudioLanguages) | A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track. |
| [SetPreferredCaptionsLanguages](#method.SetPreferredCaptionsLanguages) | Set preferred languages for captions. |
| [SetPreferredClosedCaptionService](#method.SetPreferredClosedCaptionService) | Sets the PreferredClosedCaptionService. |
| [SetPresentationLanguage](#method.SetPresentationLanguage) | Sets the presentationLanguage in a full BCP 47 value, including script, region, variant |
| [SetViewingRestrictions](#method.SetViewingRestrictions) | Sets the ViewingRestrictions. |
| [SetViewingRestrictionsWindow](#method.SetViewingRestrictionsWindow) | Sets the ViewingRestrictionsWindow. |
| [SetVoiceGuidance](#method.SetVoiceGuidance) | Sets voiceGuidance. Whether Voice Guidance is enabled or not. |
| [SetVoiceGuidanceHints](#method.SetVoiceGuidanceHints) | Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not. |
| [SetVoiceGuidanceRate](#method.SetVoiceGuidanceRate) | Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive. |

<a id="method.GetAudioDescription"></a>
## *GetAudioDescription [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetAudioDescription"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true"
    }
}
```
<a id="method.GetBlockNotRatedContent"></a>
## *GetBlockNotRatedContent [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetBlockNotRatedContent"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "blockNotRatedContent": "true"
    }
}
```
<a id="method.GetCaptions"></a>
## *GetCaptions [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetCaptions"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true"
    }
}
```
<a id="method.GetHighContrast"></a>
## *GetHighContrast [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetHighContrast"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true"
    }
}
```
<a id="method.GetLiveWatershed"></a>
## *GetLiveWatershed [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetLiveWatershed"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "liveWatershed": "true"
    }
}
```
<a id="method.GetMigrationState"></a>
## *GetMigrationState [<sup>method</sup>](#head.Methods)*

Get the migration state of the respective key

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.key | SettingsKey | one of UserSettingsKey |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.requiresMigration | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetMigrationState",
    "params": {
        "key": "PREFERRED_AUDIO_LANGUAGES"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "requiresMigration": "true"
    }
}
```
<a id="method.GetMigrationStates"></a>
## *GetMigrationStates [<sup>method</sup>](#head.Methods)*

Get the migration state of all the defined keys

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.states | IUserSettingsMigrationStateIterator | array of migration status. |
| result.states[#].key | SettingsKey |  |
| result.states[#].requiresMigration | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetMigrationStates"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "states": [
            {
                "key": "PREFERRED_AUDIO_LANGUAGES",
                "requiresMigration": "true"
            }
        ]
    }
}
```
<a id="method.GetPinControl"></a>
## *GetPinControl [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPinControl"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "pinControl": "true"
    }
}
```
<a id="method.GetPinOnPurchase"></a>
## *GetPinOnPurchase [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPinOnPurchase"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "pinOnPurchase": "true"
    }
}
```
<a id="method.GetPlaybackWatershed"></a>
## *GetPlaybackWatershed [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPlaybackWatershed"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "playbackWatershed": "true"
    }
}
```
<a id="method.GetPreferredAudioLanguages"></a>
## *GetPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPreferredAudioLanguages"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```
<a id="method.GetPreferredCaptionsLanguages"></a>
## *GetPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPreferredCaptionsLanguages"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "preferredLanguages": "eng,fra"
    }
}
```
<a id="method.GetPreferredClosedCaptionService"></a>
## *GetPreferredClosedCaptionService [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPreferredClosedCaptionService"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "service": "CC3"
    }
}
```
<a id="method.GetPresentationLanguage"></a>
## *GetPresentationLanguage [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetPresentationLanguage"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "presentationLanguage": ""
    }
}
```
<a id="method.GetViewingRestrictions"></a>
## *GetViewingRestrictions [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetViewingRestrictions"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "viewingRestrictions": ""
    }
}
```
<a id="method.GetViewingRestrictionsWindow"></a>
## *GetViewingRestrictionsWindow [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetViewingRestrictionsWindow"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "viewingRestrictionsWindow": ""
    }
}
```
<a id="method.GetVoiceGuidance"></a>
## *GetVoiceGuidance [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetVoiceGuidance"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "enabled": "true"
    }
}
```
<a id="method.GetVoiceGuidanceHints"></a>
## *GetVoiceGuidanceHints [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetVoiceGuidanceHints"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "hints": "true"
    }
}
```
<a id="method.GetVoiceGuidanceRate"></a>
## *GetVoiceGuidanceRate [<sup>method</sup>](#head.Methods)*

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
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.GetVoiceGuidanceRate"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "rate": "0.0"
    }
}
```
<a id="method.SetAudioDescription"></a>
## *SetAudioDescription [<sup>method</sup>](#head.Methods)*

Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetAudioDescription",
    "params": {
        "enabled": "true"
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
<a id="method.SetBlockNotRatedContent"></a>
## *SetBlockNotRatedContent [<sup>method</sup>](#head.Methods)*

Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be blocked, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetBlockNotRatedContent",
    "params": {
        "blockNotRatedContent": "true"
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
<a id="method.SetCaptions"></a>
## *SetCaptions [<sup>method</sup>](#head.Methods)*

brief Sets Captions ON/OFF.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetCaptions",
    "params": {
        "enabled": "true"
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
<a id="method.SetHighContrast"></a>
## *SetHighContrast [<sup>method</sup>](#head.Methods)*

Sets highContrast. Whether the app should display with high contrast or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetHighContrast",
    "params": {
        "enabled": "true"
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
<a id="method.SetLiveWatershed"></a>
## *SetLiveWatershed [<sup>method</sup>](#head.Methods)*

Sets LiveWatershed ON/OFF.Whether project-specific watershed rules should be applied for live content, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.liveWatershed | bool | liveWatershed enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetLiveWatershed",
    "params": {
        "liveWatershed": "true"
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
<a id="method.SetPinControl"></a>
## *SetPinControl [<sup>method</sup>](#head.Methods)*

Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.pinControl | bool | pinControl enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPinControl",
    "params": {
        "pinControl": "true"
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
<a id="method.SetPinOnPurchase"></a>
## *SetPinOnPurchase [<sup>method</sup>](#head.Methods)*

Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made when a purchase is attempted.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.pinOnPurchase | bool | pinOnPurchase enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPinOnPurchase",
    "params": {
        "pinOnPurchase": "true"
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
<a id="method.SetPlaybackWatershed"></a>
## *SetPlaybackWatershed [<sup>method</sup>](#head.Methods)*

Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules should be applied for non-live content, if applicable for the project.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.playbackWatershed | bool | playbackWatershed enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPlaybackWatershed",
    "params": {
        "playbackWatershed": "true"
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
<a id="method.SetPreferredAudioLanguages"></a>
## *SetPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*

A prioritized list of ISO 639-2/B codes for the preferred audio languages, expressed as a comma separated lists of languages of zero of more elements. The players will pick the audio track that has the best match compared with this list. In the absence of a matching track, the player should by best effort select the preferred audio track.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.preferredLanguages | string | the changed preferredLanguages. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPreferredAudioLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
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
<a id="method.SetPreferredCaptionsLanguages"></a>
## *SetPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*

Set preferred languages for captions.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.preferredLanguages | string | the changed preferredLanguages. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPreferredCaptionsLanguages",
    "params": {
        "preferredLanguages": "eng,fra"
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
<a id="method.SetPreferredClosedCaptionService"></a>
## *SetPreferredClosedCaptionService [<sup>method</sup>](#head.Methods)*

Sets the PreferredClosedCaptionService.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.service | string | the changed preferredClosedCaptionService. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPreferredClosedCaptionService",
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
<a id="method.SetPresentationLanguage"></a>
## *SetPresentationLanguage [<sup>method</sup>](#head.Methods)*

Sets the presentationLanguage in a full BCP 47 value, including script, region, variant

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.presentationLanguage | string | the changed presentationLanguage. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetPresentationLanguage",
    "params": {
        "presentationLanguage": ""
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
<a id="method.SetViewingRestrictions"></a>
## *SetViewingRestrictions [<sup>method</sup>](#head.Methods)*

Sets the ViewingRestrictions.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.viewingRestrictions | string | the changed viewingRestrictions. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetViewingRestrictions",
    "params": {
        "viewingRestrictions": ""
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
<a id="method.SetViewingRestrictionsWindow"></a>
## *SetViewingRestrictionsWindow [<sup>method</sup>](#head.Methods)*

Sets the ViewingRestrictionsWindow.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetViewingRestrictionsWindow",
    "params": {
        "viewingRestrictionsWindow": ""
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
<a id="method.SetVoiceGuidance"></a>
## *SetVoiceGuidance [<sup>method</sup>](#head.Methods)*

Sets voiceGuidance. Whether Voice Guidance is enabled or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetVoiceGuidance",
    "params": {
        "enabled": "true"
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
<a id="method.SetVoiceGuidanceHints"></a>
## *SetVoiceGuidanceHints [<sup>method</sup>](#head.Methods)*

Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.hints | bool | voice guidance hints enabled or not. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetVoiceGuidanceHints",
    "params": {
        "hints": "true"
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
<a id="method.SetVoiceGuidanceRate"></a>
## *SetVoiceGuidanceRate [<sup>method</sup>](#head.Methods)*

Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.rate | double | the changed voice guidance rate. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.SetVoiceGuidanceRate",
    "params": {
        "rate": "0.0"
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

The following events are provided by the IUserSettings plugin:

IUserSettings interface events:

| Method | Description |
| :-------- | :-------- |
| [OnAudioDescriptionChanged](#event.OnAudioDescriptionChanged) | The AudioDescription setting has changed. |
| [OnBlockNotRatedContentChanged](#event.OnBlockNotRatedContentChanged) | The BlockNotRatedContent setting has changed. |
| [OnCaptionsChanged](#event.OnCaptionsChanged) | The Captions setting has changed. |
| [OnHighContrastChanged](#event.OnHighContrastChanged) | Triggered after the high contrast settings changes. |
| [OnLiveWatershedChanged](#event.OnLiveWatershedChanged) | The LiveWatershed setting has changed. |
| [OnPinControlChanged](#event.OnPinControlChanged) | The PinControl setting has changed. |
| [OnPinOnPurchaseChanged](#event.OnPinOnPurchaseChanged) | The PinOnPurchase setting has changed. |
| [OnPlaybackWatershedChanged](#event.OnPlaybackWatershedChanged) | The PlaybackWatershed setting has changed. |
| [OnPreferredAudioLanguagesChanged](#event.OnPreferredAudioLanguagesChanged) | The preferredLanguages setting has changed. |
| [OnPreferredCaptionsLanguagesChanged](#event.OnPreferredCaptionsLanguagesChanged) | The PreferredCaptionsLanguages setting has changed. |
| [OnPreferredClosedCaptionServiceChanged](#event.OnPreferredClosedCaptionServiceChanged) | The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]". |
| [OnPresentationLanguageChanged](#event.OnPresentationLanguageChanged) | The PresentationLanguages setting has changed. |
| [OnViewingRestrictionsChanged](#event.OnViewingRestrictionsChanged) | The ViewingRestrictions setting has changed. |
| [OnViewingRestrictionsWindowChanged](#event.OnViewingRestrictionsWindowChanged) | The ViewingRestrictionsWindow setting has changed. |
| [OnVoiceGuidanceChanged](#event.OnVoiceGuidanceChanged) | Triggered after the voice guidance enabled settings changes. |
| [OnVoiceGuidanceHintsChanged](#event.OnVoiceGuidanceHintsChanged) | Triggered after the voice guidance hints changes. |
| [OnVoiceGuidanceRateChanged](#event.OnVoiceGuidanceRateChanged) | Triggered after the voice guidance rate changed. |

<a id="event.OnAudioDescriptionChanged"></a>
## *OnAudioDescriptionChanged [<sup>event</sup>](#head.Notifications)*

The AudioDescription setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnAudioDescriptionChanged",
    "params": {
        "enabled": "true"
    }
}
```
<a id="event.OnBlockNotRatedContentChanged"></a>
## *OnBlockNotRatedContentChanged [<sup>event</sup>](#head.Notifications)*

The BlockNotRatedContent setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.blockNotRatedContent | bool | blockNotRatedContent enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnBlockNotRatedContentChanged",
    "params": {
        "blockNotRatedContent": "true"
    }
}
```
<a id="event.OnCaptionsChanged"></a>
## *OnCaptionsChanged [<sup>event</sup>](#head.Notifications)*

The Captions setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnCaptionsChanged",
    "params": {
        "enabled": "true"
    }
}
```
<a id="event.OnHighContrastChanged"></a>
## *OnHighContrastChanged [<sup>event</sup>](#head.Notifications)*

Triggered after the high contrast settings changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnHighContrastChanged",
    "params": {
        "enabled": "true"
    }
}
```
<a id="event.OnLiveWatershedChanged"></a>
## *OnLiveWatershedChanged [<sup>event</sup>](#head.Notifications)*

The LiveWatershed setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.liveWatershed | bool | liveWatershed enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnLiveWatershedChanged",
    "params": {
        "liveWatershed": "true"
    }
}
```
<a id="event.OnPinControlChanged"></a>
## *OnPinControlChanged [<sup>event</sup>](#head.Notifications)*

The PinControl setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.pinControl | bool | pinControl enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPinControlChanged",
    "params": {
        "pinControl": "true"
    }
}
```
<a id="event.OnPinOnPurchaseChanged"></a>
## *OnPinOnPurchaseChanged [<sup>event</sup>](#head.Notifications)*

The PinOnPurchase setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.pinOnPurchase | bool | pinOnPurchase enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPinOnPurchaseChanged",
    "params": {
        "pinOnPurchase": "true"
    }
}
```
<a id="event.OnPlaybackWatershedChanged"></a>
## *OnPlaybackWatershedChanged [<sup>event</sup>](#head.Notifications)*

The PlaybackWatershed setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.playbackWatershed | bool | playbackWatershed enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPlaybackWatershedChanged",
    "params": {
        "playbackWatershed": "true"
    }
}
```
<a id="event.OnPreferredAudioLanguagesChanged"></a>
## *OnPreferredAudioLanguagesChanged [<sup>event</sup>](#head.Notifications)*

The preferredLanguages setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.preferredLanguages | string | the changed preferredLanguages. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPreferredAudioLanguagesChanged",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```
<a id="event.OnPreferredCaptionsLanguagesChanged"></a>
## *OnPreferredCaptionsLanguagesChanged [<sup>event</sup>](#head.Notifications)*

The PreferredCaptionsLanguages setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.preferredLanguages | string | the changed preferredLanguages. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPreferredCaptionsLanguagesChanged",
    "params": {
        "preferredLanguages": "eng,fra"
    }
}
```
<a id="event.OnPreferredClosedCaptionServiceChanged"></a>
## *OnPreferredClosedCaptionServiceChanged [<sup>event</sup>](#head.Notifications)*

The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.service | string | the changed preferredClosedCaptionService. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPreferredClosedCaptionServiceChanged",
    "params": {
        "service": "CC3"
    }
}
```
<a id="event.OnPresentationLanguageChanged"></a>
## *OnPresentationLanguageChanged [<sup>event</sup>](#head.Notifications)*

The PresentationLanguages setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.presentationLanguage | string | the changed presentationLanguage. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnPresentationLanguageChanged",
    "params": {
        "presentationLanguage": ""
    }
}
```
<a id="event.OnViewingRestrictionsChanged"></a>
## *OnViewingRestrictionsChanged [<sup>event</sup>](#head.Notifications)*

The ViewingRestrictions setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.viewingRestrictions | string | the changed viewingRestrictions. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnViewingRestrictionsChanged",
    "params": {
        "viewingRestrictions": ""
    }
}
```
<a id="event.OnViewingRestrictionsWindowChanged"></a>
## *OnViewingRestrictionsWindowChanged [<sup>event</sup>](#head.Notifications)*

The ViewingRestrictionsWindow setting has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.viewingRestrictionsWindow | string | the changed viewingRestrictionsWindow. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnViewingRestrictionsWindowChanged",
    "params": {
        "viewingRestrictionsWindow": ""
    }
}
```
<a id="event.OnVoiceGuidanceChanged"></a>
## *OnVoiceGuidanceChanged [<sup>event</sup>](#head.Notifications)*

Triggered after the voice guidance enabled settings changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | audioDescription enabled or not |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnVoiceGuidanceChanged",
    "params": {
        "enabled": "true"
    }
}
```
<a id="event.OnVoiceGuidanceHintsChanged"></a>
## *OnVoiceGuidanceHintsChanged [<sup>event</sup>](#head.Notifications)*

Triggered after the voice guidance hints changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.hints | bool | voice guidance hints enabled or not. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnVoiceGuidanceHintsChanged",
    "params": {
        "hints": "true"
    }
}
```
<a id="event.OnVoiceGuidanceRateChanged"></a>
## *OnVoiceGuidanceRateChanged [<sup>event</sup>](#head.Notifications)*

Triggered after the voice guidance rate changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.rate | double | the changed voice guidance rate. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IUserSettings.OnVoiceGuidanceRateChanged",
    "params": {
        "rate": "0.0"
    }
}
```