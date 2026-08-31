<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_DeviceVideoCapabilities_API"></a>
# DeviceVideoCapabilities API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DeviceVideoCapabilities interface for Thunder framework.

(Defined with IDeviceVideoCapabilities in [IDeviceInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDeviceInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DeviceVideoCapabilities interface (version 1.0.0). It includes detailed specification about its methods and properties provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

DeviceVideoCapabilities JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the DeviceVideoCapabilities interface:

DeviceVideoCapabilities interface methods:

| Method | Description |
| :-------- | :-------- |
| [supportedvideodisplays](#method_supportedvideodisplays) <sup>deprecated</sup> | Provides access to the video ports supported on the device |
| [defaultresolution](#method_defaultresolution) <sup>deprecated</sup> | Default resolution on the selected video display port |
| [supportedresolutions](#method_supportedresolutions) <sup>deprecated</sup> | Supported resolutions on the selected video display port |
| [supportedhdcp](#method_supportedhdcp) <sup>deprecated</sup> | Supported hdcp version on the selected video display port |

<a id="method_supportedvideodisplays"></a>
## *supportedvideodisplays [<sup>method</sup>](#head_Methods)*

Provides access to the video ports supported on the device.

> ``supportedvideodisplays`` is an alternative name for this method. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.supportedVideoDisplays | array | mandatory | Video ports supported on the device |
| result.supportedVideoDisplays[#] | string | mandatory | *...* |
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
  "method": "<callsign>.supportedvideodisplays"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedVideoDisplays": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_defaultresolution"></a>
## *defaultresolution [<sup>method</sup>](#head_Methods)*

Default resolution on the selected video display port.

> ``defaultresolution`` is an alternative name for this method. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.videoDisplay | string | mandatory | Video display port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.defaultResolution | string | mandatory | Resolution supported by the device |

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
  "method": "<callsign>.defaultresolution",
  "params": {
    "videoDisplay": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "defaultResolution": "..."
  }
}
```

<a id="method_supportedresolutions"></a>
## *supportedresolutions [<sup>method</sup>](#head_Methods)*

Supported resolutions on the selected video display port.

> ``supportedresolutions`` is an alternative name for this method. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.videoDisplay | string | mandatory | Video display port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.supportedResolutions | array | mandatory | Supported Resolutions |
| result.supportedResolutions[#] | string | mandatory | *...* |
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
  "method": "<callsign>.supportedresolutions",
  "params": {
    "videoDisplay": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedResolutions": [
      "..."
    ],
    "success": false
  }
}
```

<a id="method_supportedhdcp"></a>
## *supportedhdcp [<sup>method</sup>](#head_Methods)*

Supported hdcp version on the selected video display port.

> ``supportedhdcp`` is an alternative name for this method. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.videoDisplay | string | mandatory | Video display port name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.supportedHDCPVersion | string | mandatory | HDCP support (must be one of the following: unavailable, 1.4, 2.0, 2.1, 2.2) (must be one of the following: *1.4, 2.0, 2.1, 2.2, unavailable*) |

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
  "method": "<callsign>.supportedhdcp",
  "params": {
    "videoDisplay": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedHDCPVersion": "1.4"
  }
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the DeviceVideoCapabilities interface:

DeviceVideoCapabilities interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [hostedid](#property_hostedid) <sup>deprecated</sup> | read-only | Provides access to the EDID of the host |

<a id="property_hostedid"></a>
## *hostedid [<sup>property</sup>](#head_Properties)*

Provides access to the provides access to the EDID of the host.

> This property is **read-only**.

> ``hostedid`` is an alternative name for this property. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Provides access to the EDID of the host |
| (property).EDID | string | mandatory | A base64 encoded byte array string representing the EDID |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.hostedid"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "EDID": "..."
  }
}
```

