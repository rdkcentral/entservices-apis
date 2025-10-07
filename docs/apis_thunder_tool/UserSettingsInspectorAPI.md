<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_UserSettingsInspector_API"></a>
# UserSettingsInspector API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

UserSettingsInspector interface for Thunder framework.

(Defined with IUserSettingsInspector in [IUserSettings.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IUserSettings.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the UserSettingsInspector interface (version 1.0.0). It includes detailed specification about its methods provided.

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

UserSettingsInspector JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the UserSettingsInspector interface:

UserSettingsInspector interface methods:

| Method | Description |
| :-------- | :-------- |
| [getMigrationState](#method_getMigrationState) | Get the migration state of the respective key |
| [getMigrationStates](#method_getMigrationStates) | Get the migration state of all the defined keys |

<a id="method_getMigrationState"></a>
## *getMigrationState [<sup>method</sup>](#head_Methods)*

Get the migration state of the respective key.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.key | string | mandatory | One of UserSettingsKey (must be one of the following: *AUDIO_DESCRIPTION, BLOCK_NOT_RATED_CONTENT, CAPTIONS, CONTENT_PIN, HIGH_CONTRAST, LIVE_WATERSHED, PIN_CONTROL, PIN_ON_PURCHASE, PLAYBACK_WATERSHED, PREFERRED_AUDIO_LANGUAGES, PREFERRED_CAPTIONS_LANGUAGES, PREFERRED_CLOSED_CAPTION_SERVICE, PRESENTATION_LANGUAGE, VIEWING_RESTRICTIONS, VIEWING_RESTRICTIONS_WINDOW, VOICE_GUIDANCE, VOICE_GUIDANCE_HINTS, VOICE_GUIDANCE_RATE*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMigrationState",
  "params": {
    "key": "AUDIO_DESCRIPTION"
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

<a id="method_getMigrationStates"></a>
## *getMigrationStates [<sup>method</sup>](#head_Methods)*

Get the migration state of all the defined keys.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | Array of migration status |
| result[#] | object | mandatory |  |
| result[#].key | string | mandatory |  (must be one of the following: *AUDIO_DESCRIPTION, BLOCK_NOT_RATED_CONTENT, CAPTIONS, CONTENT_PIN, HIGH_CONTRAST, LIVE_WATERSHED, PIN_CONTROL, PIN_ON_PURCHASE, PLAYBACK_WATERSHED, PREFERRED_AUDIO_LANGUAGES, PREFERRED_CAPTIONS_LANGUAGES, PREFERRED_CLOSED_CAPTION_SERVICE, PRESENTATION_LANGUAGE, VIEWING_RESTRICTIONS, VIEWING_RESTRICTIONS_WINDOW, VOICE_GUIDANCE, VOICE_GUIDANCE_HINTS, VOICE_GUIDANCE_RATE*) |
| result[#].requiresMigration | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getMigrationStates"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "key": "AUDIO_DESCRIPTION",
      "requiresMigration": false
    }
  ]
}
```

