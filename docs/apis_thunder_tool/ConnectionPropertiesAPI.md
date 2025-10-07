<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_ConnectionProperties_API"></a>
# ConnectionProperties API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

ConnectionProperties interface for Thunder framework.

(Defined with IConnectionProperties in [IDisplayInfo.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IDisplayInfo.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the ConnectionProperties interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

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

ConnectionProperties JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the ConnectionProperties interface:

ConnectionProperties interface methods:

| Method | Description |
| :-------- | :-------- |
| [edid](#method_edid) | TV's Extended Display Identification Data |
| [widthincentimeters](#method_widthincentimeters) | Horizontal size in centimeters |
| [heightincentimeters](#method_heightincentimeters) | Vertical size in centimeters |

<a id="method_edid"></a>
## *edid [<sup>method</sup>](#head_Methods)*

TV's Extended Display Identification Data.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.length | integer | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.length | integer | mandatory |  |
| result.data | string | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.edid",
  "params": {
    "length": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "length": 0,
    "data": "..."
  }
}
```

<a id="method_widthincentimeters"></a>
## *widthincentimeters [<sup>method</sup>](#head_Methods)*

Horizontal size in centimeters.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Width in cm |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.widthincentimeters"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_heightincentimeters"></a>
## *heightincentimeters [<sup>method</sup>](#head_Methods)*

Vertical size in centimeters.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.heightincentimeters"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="head_Properties"></a>
# Properties

The following properties are provided by the ConnectionProperties interface:

ConnectionProperties interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [isaudiopassthrough](#property_isaudiopassthrough) | read-only | Current audio passthrough status on HDMI |
| [connected](#property_connected) | read-only | Current HDMI connection status |
| [width](#property_width) | read-only | Horizontal resolution of TV |
| [height](#property_height) | read-only | Vertical resolution of TV |
| [verticalfreq](#property_verticalfreq) | read-only | Vertical Frequency |
| [hdcpprotection](#property_hdcpprotection) | read/write | HDCP protocol used for transmission |
| [portname](#property_portname) | read-only | Video output port on the STB used for connection to TV |

<a id="property_isaudiopassthrough"></a>
## *isaudiopassthrough [<sup>property</sup>](#head_Properties)*

Provides access to the current audio passthrough status on HDMI.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Enabled/disabled |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.isaudiopassthrough"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="property_connected"></a>
## *connected [<sup>property</sup>](#head_Properties)*

Provides access to the current HDMI connection status.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | boolean | mandatory | Connected/disconnected |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.connected"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="property_width"></a>
## *width [<sup>property</sup>](#head_Properties)*

Provides access to the horizontal resolution of TV.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Width of TV in pixels |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.width"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_height"></a>
## *height [<sup>property</sup>](#head_Properties)*

Provides access to the vertical resolution of TV.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Height of TV in pixels |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.height"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_verticalfreq"></a>
## *verticalfreq [<sup>property</sup>](#head_Properties)*

Provides access to the vertical Frequency.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Vertical freq |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.verticalfreq"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_hdcpprotection"></a>
## *hdcpprotection [<sup>property</sup>](#head_Properties)*

Provides access to the HDCP protocol used for transmission.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | HDCP protocol used for transmission (must be one of the following: *Hdcp1X, Hdcp2X, HdcpAuto, HdcpUnencrypted*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.hdcpprotection"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "Hdcp1X"
}
```

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.hdcpprotection",
  "params": "Hdcp1X"
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a id="property_portname"></a>
## *portname [<sup>property</sup>](#head_Properties)*

Provides access to the video output port on the STB used for connection to TV.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Video output port name |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.portname"
}
```

#### Get Response

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

The following events are provided by the ConnectionProperties interface:

ConnectionProperties interface events:

| Notification | Description |
| :-------- | :-------- |
| [updated](#notification_updated) |  |

<a id="notification_updated"></a>
## *updated [<sup>notification</sup>](#head_Notifications)*

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.event | string | mandatory |  (must be one of the following: *HdcpChange, HdmiChange, PostResolutionChange, PreResolutionChange*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "updated",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.updated",
  "params": {
    "event": "PostResolutionChange"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.updated``.

