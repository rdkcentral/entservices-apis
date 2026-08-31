<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_Display_Info_API"></a>
# Display Info API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

DisplayInfo interface for Thunder framework.

(Defined by [DisplayInfo.json](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/DisplayInfo.json))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the DisplayInfo interface (version 1.0.0). It includes detailed specification about its properties provided and notifications sent.

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

DisplayInfo JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the DisplayInfo interface:

DisplayInfo interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [displayinfo](#property_displayinfo) | read-only | Display general information |

<a id="property_displayinfo"></a>
## *displayinfo [<sup>property</sup>](#head_Properties)*

Provides access to the display general information.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Display general information |
| (property).totalgpuram | integer | mandatory | Total GPU DRAM memory (in bytes) |
| (property).freegpuram | integer | mandatory | Free GPU DRAM memory (in bytes) |
| (property).audiopassthrough | boolean | mandatory | Audio Pass through is support for this device |
| (property).connected | boolean | mandatory | HDMI display connection status |
| (property).width | integer | mandatory | Width of the connected HDMI display |
| (property).height | integer | mandatory | Height of the connected HDMI display |
| (property).hdcpprotection | string | mandatory | HDCP Protection (must be one of the following: *HDCP1x, HDCP2x, Unencrypted*) |
| (property).hdrtype | string | mandatory | HDR Type used (must be one of the following: *HDR10, HDR10Plus, HDRDolbyVision, HDROff, HDRTechnicolor*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.displayinfo"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "totalgpuram": 381681664,
    "freegpuram": 358612992,
    "audiopassthrough": false,
    "connected": true,
    "width": 1280,
    "height": 720,
    "hdcpprotection": "HDCP1x",
    "hdrtype": "HDROff"
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the DisplayInfo interface:

DisplayInfo interface events:

| Notification | Description |
| :-------- | :-------- |
| [updated](#notification_updated) | Notifies about a change/update in the connection |

<a id="notification_updated"></a>
## *updated [<sup>notification</sup>](#head_Notifications)*

Notifies about a change/update in the connection.

### Description

Register to this event to be notified about any change in the connection

### Notification Parameters

This notification carries no parameters.

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
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
  "method": "myid.updated"
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.updated``.

