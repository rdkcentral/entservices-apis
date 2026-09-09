<!-- Generated automatically, DO NOT EDIT! -->
<a name="TextToSpeech_Plugin"></a>
# TextToSpeech Plugin

A org.rdk.TextToSpeech plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `TextToSpeech` plugin provides TTS functionality (Voice Guidance & Speech Synthesis) for the client application.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

**Note:** The ITextToSpeech interface has been updated to version 2 (`ITEXTTOSPEECH_VERSION 2`). This version introduces new data structures, methods, and notification events for enhanced TTS functionality.

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.TextToSpeech*) |
| classname | string | Class name: *org.rdk.TextToSpeech* |
| locator | string | Library name: *libWPEFrameworkTextToSpeech.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.TextToSpeech plugin:

TextToSpeech interface methods:

| Method | Description |
| :-------- | :-------- |
| [cancel](#cancel) | Cancels the speech |
| [enabletts](#enabletts) | (For Resident App) Enables or disables the TTS conversion processing |
| [getapiversion](#getapiversion) | Gets the API Version |
| [getcapability](#getcapability) | Queries whether a specific capability (SSML, RAW_TEXT) is supported (Added in version 2) |
| [getcapabilities](#getcapabilities) | Returns an iterator over all supported capabilities (Added in version 2) |
| [getdeviceconfiguration](#getdeviceconfiguration) | Retrieves current TTS device configuration (Added in version 2) |
| [getinterfaceversion](#getinterfaceversion) | Returns the interface version number (Added in version 2) |
| [getspeechstate](#getspeechstate) | Returns the current state of the speech request |
| [getttsconfiguration](#getttsconfiguration) | Gets the current TTS configuration (Deprecated - use getdeviceconfiguration instead) |
| [getvoices](#getvoices) | Lists available voices with detailed information (Added in version 2) |
| [isspeaking](#isspeaking) | Checks if speech is in progress |
| [isttsenabled](#isttsenabled) | Returns whether the TTS engine is enabled or disabled |
| [listvoices](#listvoices) | Lists the available voices for the specified language (Deprecated - use getvoices instead) |
| [pause](#pause) | Pauses the speech |
| [resume](#resume) | Resumes the speech |
| [setdeviceconfiguration](#setdeviceconfiguration) | Sets TTS device configuration (Added in version 2) |
| [setttsconfiguration](#setttsconfiguration) | Sets the TTS configuration (Deprecated - use setdeviceconfiguration instead) |
| [speak](#speak) | Converts the input text to speech when TTS is enabled |
| [speakwithutterance](#speakwithutterance) | Speaks text with per-utterance configuration overrides (Added in version 2) |
| [setACL](#setACL) | Configures app to speak |


<a name="cancel"></a>
## *cancel*

Cancels the speech. Triggers the `onspeechinterrupted` 

### Events

| Event | Description |
| :-------- | :-------- |
| [onspeechinterrupted](#onspeechinterrupted) | Triggered when ongoing speech is cancelled. Event is not triggered: if TTS is not enabled; if ongoing Speech is completed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.cancel",
    "params": {
        "speechid": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="enabletts"></a>
## *enabletts*

(For Resident App) Enables or disables the TTS conversion processing. Triggered `onttsstatechanged` event when state changes and `onspeechinterrupted` event when disabling TTS while speech is in-progress.

### Events

| Event | Description |
| :-------- | :-------- |
| [onttsstatechanged](#onttsstatechanged) | state : true Triggered when TTS is enabled; state : false Triggered when TTS is disabled; otherwise No event When TTS enable or disable is in-progress |
| [onspeechinterrupted](#onspeechinterrupted) | Triggered when disabling TTS while speech is in-progress. |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabletts | boolean | Enable or Disable TTS |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.enabletts",
    "params": {
        "enabletts": true
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="getapiversion"></a>
## *getapiversion*

Gets the API Version.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | number | Indicates the  API Version |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getapiversion"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "version": 1,
        "success": true
    }
}
```

<a name="getspeechstate"></a>
## *getspeechstate*

Returns the current state of the speech request.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speechstate | string | The speech state (must be one of the following: *SPEECH_PENDING(0)*, *SPEECH_IN_PROGRESS(1)*, *SPEECH_PAUSED(2)*, *SPEECH_NOT_FOUND(3)*) |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getspeechstate",
    "params": {
        "speechid": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "speechstate": "SPEECH_IN_PROGRESS",
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="getttsconfiguration"></a>
## *getttsconfiguration*

Gets the current TTS configuration.

**Deprecated:** This method is deprecated. Use [getdeviceconfiguration](#getdeviceconfiguration) instead. The Configuration struct is also deprecated in favor of DeviceConfiguration.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.ttsendpoint | string | The TTS engine URL |
| result.ttsendpointsecured | string | The TTS engine secured URL |
| result.language | string | The TTS language |
| result.voice | string | The TTS Voice |
| result.volume | string | The TTS Volume |
| result.rate | number | The TTS Rate |
| result?.speechrate | string | <sup>*(optional)*</sup> TTS Rate for TTS2 endpoint |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getttsconfiguration"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "ttsendpoint": "http://url_for_the_text_to_speech_processing_unit",
        "ttsendpointsecured": "https://url_for_the_text_to_speech_processing_unit",
        "language": "en-US",
        "voice": "carol",
        "volume": "100.000000",
        "rate": 50,
        "speechrate": "medium",
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="isspeaking"></a>
## *isspeaking*

Checks if speech is in progress.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speaking | boolean | `true` if the passed speech is in progress (that is, audio was playing), `false` if speech is completed or speech ID not found |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.isspeaking",
    "params": {
        "speechid": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "speaking": true,
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="isttsenabled"></a>
## *isttsenabled*

Returns whether the TTS engine is enabled or disabled. By default the TTS engine is disabled.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.isenabled | boolean | `true` if the TTS engine is enabled, otherwise `false` |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.isttsenabled"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "isenabled": true,
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="listvoices"></a>
## *listvoices*

Lists the available voices for the specified language. For every language there is a set of pre-defined voices.

**Deprecated:** This method is deprecated. Use [getvoices](#getvoices) instead, which provides more information about voices such as language and default status.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.language | string | The TTS language |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.voices | string | Array of available voice |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.listvoices",
    "params": {
        "language": "en-US"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "voices": "carol",
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="pause"></a>
## *pause*

Pauses the speech. Triggers the `onspeechpause` 

### Events

| Event | Description |
| :-------- | :-------- |
| [onspeechpause](#onspeechpause) | Triggered when ongoing speech is paused. Event not triggered on following conditions: TTS is not enabled; Speech is already in pause; or Speech is completed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.pause",
    "params": {
        "speechid": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="resume"></a>
## *resume*

Resumes the speech. Triggers the `onspeechresume` 

### Events

| Event | Description |
| :-------- | :-------- |
| [onspeechresume](#onspeechresume) | Triggered when speech is resumed and speech output is available. Event not triggered under following conditions: TTS is not enabled; Speech is resumed already; or Speech is completed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.resume",
    "params": {
        "speechid": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="setttsconfiguration"></a>
## *setttsconfiguration*

Sets the TTS configuration. Triggers the `onvoicechanged`

**Deprecated:** This method is deprecated. Use [setdeviceconfiguration](#setdeviceconfiguration) instead. 

### Events

| Event | Description |
| :-------- | :-------- |
| [onvoicechanged](#onvoicechanged) | Triggered only when the voice configuration is changed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.ttsendpoint | string | <sup>*(optional)*</sup> The TTS engine URL |
| params?.ttsendpointsecured | string | <sup>*(optional)*</sup> The TTS engine secured URL |
| params?.language | string | <sup>*(optional)*</sup> The TTS language |
| params?.voice | string | <sup>*(optional)*</sup> The TTS Voice |
| params?.volume | string | <sup>*(optional)*</sup> The TTS Volume |
| params?.primvolduckpercent | number | <sup>*(optional)*</sup> The TTS Primary Volumeduckpercentage |
| params?.rate | number | <sup>*(optional)*</sup> The TTS Rate |
| params?.speechrate | string | <sup>*(optional)*</sup> TTS Rate for TTS2 endpoint |
| params?.fallbacktext | object | <sup>*(optional)*</sup>  |
| params?.fallbacktext?.scenario | string | <sup>*(optional)*</sup> Describes the scenario where fallback text is to be used . At present, only `offline` is supported |
| params?.fallbacktext?.value | string | <sup>*(optional)*</sup> The Text which is to be spoken when the scenario is met |
| params?.authinfo | object | <sup>*(optional)*</sup>  |
| params?.authinfo?.type | string | <sup>*(optional)*</sup> The type of authentication. At present, only `apikey` is supported |
| params?.authinfo?.value | string | <sup>*(optional)*</sup> x api key(secret key) required for GCD Endpoints |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.setttsconfiguration",
    "params": {
        "ttsendpoint": "http://url_for_the_text_to_speech_processing_unit",
        "ttsendpointsecured": "https://url_for_the_text_to_speech_processing_unit",
        "language": "en-US",
        "voice": "carol",
        "volume": "100.000000",
        "primvolduckpercent": 25,
        "rate": 50,
        "speechrate": "medium",
        "fallbacktext": {
            "scenario": "offline",
            "value": "No Internet connection"
        },
        "authinfo": {
            "type": "apikey",
            "value": "XXXXXXXXXXXX"
        }
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="speak"></a>
## *speak*

Converts the input text to speech when TTS is enabled. Any ongoing speech is interrupted and the newly requested speech is processed. The clients of the previous speech is sent an `onspeechinterrupted`  Upon success, this API returns an ID, which is used as input to other API methods for controlling the speech (for example, `pause`, `resume`, and `cancel`).

### Events

| Event | Description |
| :-------- | :-------- |
| [onwillspeak](#onwillspeak) | Triggered when speech conversion is about to start |
| [onspeechstart](#onspeechstart) | Triggered when conversion of text to speech is started |
| [onspeechinterrupted](#onspeechinterrupted) | Current speech is interrupted either by a next speech request; by calling the cancel method; or by disabling TTS, when speech is in-progress |
| [onspeechcomplete](#onspeechcomplete) | Triggered when conversion from text to speech is completed |
| [onnetworkerror](#onnetworkerror) | Triggered when failed to fetch audio from the endpoint |
| [onplaybackerror](#onplaybackerror) | Triggered when an error occurs during playback including pipeline failures; Triggered when speak is called during TTS disabled |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.text | string | The text input |
| params?.callsign | string | <sup>*(optional)*</sup>  Callsign of the application. This is mandatory when setACL is called prior to speak  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speechid | number | The speech ID |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.speak",
    "params": {
        "text": "speech_1",
        "callsign": "WebApp"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "speechid": 1,
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="setACL"></a>
## *setACL*

Configures app to speak. Allows the ResidentAPP to configure the particular app and provides access to `speak`  If not configured any then gives access to all apps to speak. Configuration does not retained after reboot.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.accesslist | array |  |
| params.accesslist[#] | object |  |
| params.accesslist[#].method | string | Method of TTS function to be performed |
| params.accesslist[#].apps | array | List of client application |
| params.accesslist[#].apps[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.setACL",
    "params": {
        "accesslist": [
            {
                "method": "speak",
                "apps": [
                    "App1"
                ]
            }
        ]
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="getvoices"></a>
## *getvoices*

Lists available voices with detailed information (language, name, isDefault status). Takes optional language parameter (BCP 47 tag) to filter results. Returns voice information iterator. Added in version 2.

This method replaces the deprecated [listvoices](#listvoices) method and provides more detailed information about the voices.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.language | string | <sup>*(optional)*</sup> Optional language filter using BCP 47 language tag (e.g., "en-US"). If empty string or omitted, returns all available voices |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.voices | array | Array of voice information objects |
| result.voices[#] | object |  |
| result.voices[#].name | string | Unique voice identifier |
| result.voices[#].language | string | BCP 47 language tag of the voice |
| result.voices[#].isDefault | boolean | `true` if this is the default voice for its language |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getvoices",
    "params": {
        "language": "en-US"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "voices": [
            {
                "name": "carol",
                "language": "en-US",
                "isDefault": true
            },
            {
                "name": "kevin",
                "language": "en-US",
                "isDefault": false
            }
        ],
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="speakwithutterance"></a>
## *speakwithutterance*

Speaks text with per-utterance configuration overrides via SpeechUtterance struct. Supports plain text or SSML markup (SSML detected by starting with "<speak>" or "<?xml"). Added in version 2.

This method allows overriding the global TTS configuration for specific speech requests, including language, voice, volume, rate, and pitch settings.

### Events

| Event | Description |
| :-------- | :-------- |
| [onwillspeak](#onwillspeak) | Triggered when speech conversion is about to start |
| [onspeechstart](#onspeechstart) | Triggered when conversion of text to speech is started |
| [onspeechinterrupted](#onspeechinterrupted) | Current speech is interrupted either by a next speech request; by calling the cancel method; or by disabling TTS, when speech is in-progress |
| [onspeechcomplete](#onspeechcomplete) | Triggered when conversion from text to speech is completed |
| [onnetworkerror](#onnetworkerror) | Triggered when failed to fetch audio from the endpoint |
| [onplaybackerror](#onplaybackerror) | Triggered when an error occurs during playback including pipeline failures; Triggered when speak is called during TTS disabled |

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | Identifier for the source of the request |
| params.text | string | Plain text or SSML markup for conversion. If the string starts with "<speak>" or "<?xml" it is treated as SSML, otherwise as plain text. If SSML capability is not supported, SSML tags will be ignored |
| params.utterance | object | Per-utterance configuration overrides |
| params.utterance?.language | string | <sup>*(optional)*</sup> Language of the utterance (BCP 47 language tag). Empty string means use TTS configuration value |
| params.utterance?.voice | string | <sup>*(optional)*</sup> Voice to use for synthesis. Empty string means use TTS configuration value |
| params.utterance?.volume | number | <sup>*(optional)*</sup> Volume of the utterance (range 0.0 to 1.0). -1.0 means use TTS configuration value |
| params.utterance?.rate | number | <sup>*(optional)*</sup> Speed of the utterance (range 0.1 to 10.0). -1.0 means use TTS configuration value |
| params.utterance?.pitch | number | <sup>*(optional)*</sup> Pitch of the utterance (range 0.0 to 2.0). -1.0 means use TTS configuration value |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.speechid | number | The speech ID |
| result.TTS_Status | number |  (must be one of the following: *TTS_OK(0)*, *TTS_FAIL(1)*, *TTS_NOT_ENABLED(2)*, *TTS_INVALID_CONFIGURATION(3)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.speakwithutterance",
    "params": {
        "callsign": "WebApp",
        "text": "Hello, this is a test.",
        "utterance": {
            "language": "en-US",
            "voice": "carol",
            "volume": 0.8,
            "rate": 1.2,
            "pitch": 1.0
        }
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "speechid": 1,
        "TTS_Status": 0,
        "success": true
    }
}
```

<a name="getinterfaceversion"></a>
## *getinterfaceversion*

Returns the interface version number (e.g., 2). Used to determine available functionality. Added in version 2.

If this method is not implemented, it returns Core::ERROR_NOT_SUPPORTED and you should assume version 1.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.version | number | The interface version number (e.g., 2) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getinterfaceversion"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "version": 2,
        "success": true
    }
}
```

<a name="getcapability"></a>
## *getcapability*

Queries whether a specific capability (SSML, RAW_TEXT) is supported. Added in version 2.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.capability | string | The capability to query (must be one of the following: *UNSET(0)*, *RAW_TEXT(1)*, *SSML(2)*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.hasCapability | boolean | `true` if the queried capability is supported |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getcapability",
    "params": {
        "capability": "SSML"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "hasCapability": true,
        "success": true
    }
}
```

<a name="getcapabilities"></a>
## *getcapabilities*

Returns an iterator over all supported capabilities. Added in version 2.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.capabilities | array | Array of supported capabilities |
| result.capabilities[#] | string | Capability name (must be one of the following: *RAW_TEXT(1)*, *SSML(2)*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getcapabilities"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "capabilities": [
            "RAW_TEXT",
            "SSML"
        ],
        "success": true
    }
}
```

<a name="getdeviceconfiguration"></a>
## *getdeviceconfiguration*

Retrieves current TTS device configuration (DeviceConfiguration struct). Replaces deprecated [getttsconfiguration](#getttsconfiguration). Added in version 2.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.ttsendpoint | string | The TTS engine URL |
| result.ttsendpointsecured | string | The TTS engine secured URL |
| result.language | string | Device default language (BCP 47 language tag) |
| result.voice | string | Device default voice. Empty string means use TTS Engine default for the configured language |
| result.volume | number | Device default volume (range 0.0 to 1.0, default 1.0) |
| result.rate | number | Device default speed (range 0.1 to 10.0, default 1.0) |
| result.pitch | number | Device default pitch (range 0.0 to 2.0, default 1.0) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.getdeviceconfiguration"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "ttsendpoint": "http://url_for_the_text_to_speech_processing_unit",
        "ttsendpointsecured": "https://url_for_the_text_to_speech_processing_unit",
        "language": "en-US",
        "voice": "carol",
        "volume": 1.0,
        "rate": 1.0,
        "pitch": 1.0,
        "success": true
    }
}
```

<a name="setdeviceconfiguration"></a>
## *setdeviceconfiguration*

Sets TTS device configuration (DeviceConfiguration struct). Replaces deprecated [setttsconfiguration](#setttsconfiguration). Added in version 2.

### Events

| Event | Description |
| :-------- | :-------- |
| [onvoicechanged](#onvoicechanged) | Triggered only when the voice configuration is changed |
| [ondeviceconfigurationchanged](#ondeviceconfigurationchanged) | Triggered when device configuration changes |

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.ttsendpoint | string | <sup>*(optional)*</sup> The TTS engine URL |
| params?.ttsendpointsecured | string | <sup>*(optional)*</sup> The TTS engine secured URL |
| params?.language | string | <sup>*(optional)*</sup> Device default language (BCP 47 language tag) |
| params?.voice | string | <sup>*(optional)*</sup> Device default voice. Empty string means use TTS Engine default |
| params?.volume | number | <sup>*(optional)*</sup> Device default volume (range 0.0 to 1.0, default 1.0) |
| params?.rate | number | <sup>*(optional)*</sup> Device default speed (range 0.1 to 10.0, default 1.0) |
| params?.pitch | number | <sup>*(optional)*</sup> Device default pitch (range 0.0 to 2.0, default 1.0) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.TextToSpeech.setdeviceconfiguration",
    "params": {
        "ttsendpoint": "http://url_for_the_text_to_speech_processing_unit",
        "ttsendpointsecured": "https://url_for_the_text_to_speech_processing_unit",
        "language": "en-US",
        "voice": "carol",
        "volume": 1.0,
        "rate": 1.0,
        "pitch": 1.0
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.TextToSpeech plugin:

TextToSpeech interface events:

| Event | Description |
| :-------- | :-------- |
| [oncapabilitieschanged](#oncapabilitieschanged) | Triggered when available capabilities change (Added in version 2) |
| [ondeviceconfigurationchanged](#ondeviceconfigurationchanged) | Triggered when device configuration changes (Added in version 2) |
| [onnetworkerror](#onnetworkerror) | Triggered when a network error occurs while fetching the audio from the endpoint |
| [onplaybackerror](#onplaybackerror) | Triggered when an error occurs during playback including pipeline failures |
| [onspeechcomplete](#onspeechcomplete) | Triggered when the speech completes |
| [onspeechinterrupted](#onspeechinterrupted) | Triggered when the current speech is interrupted either by a next speech request, by calling `cancel` or by disabling TTS, when speech is in progress |
| [onspeechpause](#onspeechpause) | Triggered when the ongoing speech pauses |
| [onspeechresume](#onspeechresume) | Triggered when any paused speech resumes |
| [onspeechstart](#onspeechstart) | Triggered when the speech start |
| [onttsstatechanged](#onttsstatechanged) | Triggered when TTS is enabled or disabled |
| [onvoicechanged](#onvoicechanged) | Triggered when the configured voice changes |
| [onvoiceschanged](#onvoiceschanged) | Triggered when available voices change (Added in version 2) |
| [onwillspeak](#onwillspeak) | Triggered when the text to speech conversion is about to start |


<a name="onvoiceschanged"></a>
## *onvoiceschanged*

Triggered when available voices change (e.g., due to TTS configuration change, language pack installation, or TTS engine update). Added in version 2.

### Parameters

This event has no parameters.

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onvoiceschanged",
    "params": {}
}
```

<a name="oncapabilitieschanged"></a>
## *oncapabilitieschanged*

Triggered when available capabilities change (e.g., due to TTS configuration change). Added in version 2.

### Parameters

This event has no parameters.

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.oncapabilitieschanged",
    "params": {}
}
```

<a name="ondeviceconfigurationchanged"></a>
## *ondeviceconfigurationchanged*

Triggered when device configuration changes. Added in version 2.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ttsendpoint | string | The TTS engine URL |
| params.ttsendpointsecured | string | The TTS engine secured URL |
| params.language | string | Device default language (BCP 47 language tag) |
| params.voice | string | Device default voice |
| params.volume | number | Device default volume (range 0.0 to 1.0) |
| params.rate | number | Device default speed (range 0.1 to 10.0) |
| params.pitch | number | Device default pitch (range 0.0 to 2.0) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.ondeviceconfigurationchanged",
    "params": {
        "ttsendpoint": "http://url_for_the_text_to_speech_processing_unit",
        "ttsendpointsecured": "https://url_for_the_text_to_speech_processing_unit",
        "language": "en-US",
        "voice": "carol",
        "volume": 1.0,
        "rate": 1.0,
        "pitch": 1.0
    }
}
```

<a name="onnetworkerror"></a>
## *onnetworkerror*

Triggered when a network error occurs while fetching the audio from the endpoint.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onnetworkerror",
    "params": {
        "speechid": 1
    }
}
```

<a name="onplaybackerror"></a>
## *onplaybackerror*

Triggered when an error occurs during playback including pipeline failures.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onplaybackerror",
    "params": {
        "speechid": 1
    }
}
```

<a name="onspeechcomplete"></a>
## *onspeechcomplete*

Triggered when the speech completes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onspeechcomplete",
    "params": {
        "speechid": 1
    }
}
```

<a name="onspeechinterrupted"></a>
## *onspeechinterrupted*

Triggered when the current speech is interrupted either by a next speech request, by calling `cancel` or by disabling TTS, when speech is in progress.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onspeechinterrupted",
    "params": {
        "speechid": 1
    }
}
```

<a name="onspeechpause"></a>
## *onspeechpause*

Triggered when the ongoing speech pauses.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onspeechpause",
    "params": {
        "speechid": 1
    }
}
```

<a name="onspeechresume"></a>
## *onspeechresume*

Triggered when any paused speech resumes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onspeechresume",
    "params": {
        "speechid": 1
    }
}
```

<a name="onspeechstart"></a>
## *onspeechstart*

Triggered when the speech start.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onspeechstart",
    "params": {
        "speechid": 1
    }
}
```

<a name="onttsstatechanged"></a>
## *onttsstatechanged*

Triggered when TTS is enabled or disabled.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.state | boolean | `True` if TTS is enabled, otherwise `False` |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onttsstatechanged",
    "params": {
        "state": true
    }
}
```

<a name="onvoicechanged"></a>
## *onvoicechanged*

Triggered when the configured voice changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.voice | string | The TTS Voice |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onvoicechanged",
    "params": {
        "voice": "carol"
    }
}
```

<a name="onwillspeak"></a>
## *onwillspeak*

Triggered when the text to speech conversion is about to start. It provides the speech ID, generated for the text input given in the speak 

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.speechid | number | The speech ID |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onwillspeak",
    "params": {
        "speechid": 1
    }
}
```

