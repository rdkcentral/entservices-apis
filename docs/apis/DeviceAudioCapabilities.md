<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DeviceAudioCapabilities_API"></a>
# DeviceAudioCapabilities API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DeviceAudioCapabilities interface for Thunder framework.

(Defined with IDeviceAudioCapabilities in [IDeviceInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDeviceInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DeviceAudioCapabilities interface (version 1.0.0). It includes detailed specification about its methods provided.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

DeviceAudioCapabilities JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DeviceAudioCapabilities interface:

DeviceAudioCapabilities interface methods:

| Method | Description |
| :-------- | :-------- |
| [audiocapabilities](#method_audiocapabilities) <sup>deprecated</sup> | Audio capabilities for the specified audio port |
| [ms12capabilities](#method_ms12capabilities) <sup>deprecated</sup> | MS12 audio capabilities for the specified audio port |
| [supportedms12audioprofiles](#method_supportedms12audioprofiles) <sup>deprecated</sup> | Supported MS12 audio profiles for the specified audio port |

<a id="method_audiocapabilities"></a>
## *audiocapabilities [<sup>method</sup>](#head_Methods)*

Audio capabilities for the specified audio port.

> ``audiocapabilities`` is an alternative name for this  This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.audioPort | string | mandatory | Audio port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.AudioCapabilities | array | mandatory | Audio capability |
| result.AudioCapabilities[#] | string | mandatory | *...* (must be one of the following: *ATMOS, DAPv2, DOLBY_DIGITAL, DOLBY_DIGITAL_PLUS, Dual_Audio_Decode, MS12, none*) |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.audiocapabilities",
  "params": {
    "audioPort": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "AudioCapabilities": [
      "ATMOS"
    ],
    "success": false
  }
}
```

<a id="method_ms12capabilities"></a>
## *ms12capabilities [<sup>method</sup>](#head_Methods)*

MS12 audio capabilities for the specified audio port.

> ``ms12capabilities`` is an alternative name for this  This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.audioPort | string | mandatory | Audio port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.MS12Capabilities | array | mandatory | MS12 audio capability |
| result.MS12Capabilities[#] | string | mandatory | *...* (must be one of the following: *Dialogue_Enhancer, Dolby_Volume, Inteligent_Equalizer, none*) |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.ms12capabilities",
  "params": {
    "audioPort": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "MS12Capabilities": [
      "Dolby_Volume"
    ],
    "success": false
  }
}
```

<a id="method_supportedms12audioprofiles"></a>
## *supportedms12audioprofiles [<sup>method</sup>](#head_Methods)*

Supported MS12 audio profiles for the specified audio port.

> ``supportedms12audioprofiles`` is an alternative name for this  This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.audioPort | string | mandatory | Audio port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.supportedMS12AudioProfiles | array | mandatory | MS12 audio profiles |
| result.supportedMS12AudioProfiles[#] | string | mandatory | *...* |
| result.success | boolean | mandatory | *...* |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.supportedms12audioprofiles",
  "params": {
    "audioPort": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedMS12AudioProfiles": [
      "..."
    ],
    "success": false
  }
}
```

