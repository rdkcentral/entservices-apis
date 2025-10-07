<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_HdcpProfile_API"></a>
# HdcpProfile API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

HdcpProfile interface for Thunder framework.

(Defined with IHdcpProfile in [IHdcpProfile.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IHdcpProfile.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the HdcpProfile interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

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

HdcpProfile JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the HdcpProfile interface:

HdcpProfile interface methods:

| Method | Description |
| :-------- | :-------- |
| [getHDCPStatus](#method_getHDCPStatus) | Returns HDCP-related data |
| [getSettopHDCPSupport](#method_getSettopHDCPSupport) | Returns which version of HDCP is supported by the STB |

<a id="method_getHDCPStatus"></a>
## *getHDCPStatus [<sup>method</sup>](#head_Methods)*

Returns HDCP-related data.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.HDCPStatus | object | mandatory |  |
| result.HDCPStatus.isConnected | boolean | mandatory | Indicates whether a display is connected |
| result.HDCPStatus.isHDCPCompliant | boolean | mandatory | Indicates whether the display is HDCP compliant |
| result.HDCPStatus.isHDCPEnabled | boolean | mandatory | Indicates whether content is protected |
| result.HDCPStatus.hdcpReason | integer | mandatory | The HDCP status reason |
| result.HDCPStatus.supportedHDCPVersion | string | mandatory | Supported HDCP protocol version by the host device |
| result.HDCPStatus.receiverHDCPVersion | string | mandatory | Supported HDCP protocol version by the receiver device (display) |
| result.HDCPStatus.currentHDCPVersion | string | mandatory | Currently used HDCP protocol version |
| result.success | boolean | mandatory | Indicates whether the operation was successful |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getHDCPStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "HDCPStatus": {
      "isConnected": false,
      "isHDCPCompliant": false,
      "isHDCPEnabled": false,
      "hdcpReason": 0,
      "supportedHDCPVersion": "...",
      "receiverHDCPVersion": "...",
      "currentHDCPVersion": "..."
    },
    "success": false
  }
}
```

<a id="method_getSettopHDCPSupport"></a>
## *getSettopHDCPSupport [<sup>method</sup>](#head_Methods)*

Returns which version of HDCP is supported by the STB.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.supportedHDCPVersion | string | mandatory | Supported HDCP protocol version by the host device |
| result.isHDCPSupported | boolean | mandatory | Indicates whether HDCP is supported by the STB |
| result.success | boolean | mandatory | Indicates whether the operation was successful |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getSettopHDCPSupport"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "supportedHDCPVersion": "...",
    "isHDCPSupported": false,
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HdcpProfile interface:

HdcpProfile interface events:

| Notification | Description |
| :-------- | :-------- |
| [onDisplayConnectionChanged](#notification_onDisplayConnectionChanged) | Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug |

<a id="notification_onDisplayConnectionChanged"></a>
## *onDisplayConnectionChanged [<sup>notification</sup>](#head_Notifications)*

Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.HDCPStatus | object | mandatory |  |
| params.HDCPStatus.isConnected | boolean | mandatory | Indicates whether a display is connected |
| params.HDCPStatus.isHDCPCompliant | boolean | mandatory | Indicates whether the display is HDCP compliant |
| params.HDCPStatus.isHDCPEnabled | boolean | mandatory | Indicates whether content is protected |
| params.HDCPStatus.hdcpReason | integer | mandatory | The HDCP status reason |
| params.HDCPStatus.supportedHDCPVersion | string | mandatory | Supported HDCP protocol version by the host device |
| params.HDCPStatus.receiverHDCPVersion | string | mandatory | Supported HDCP protocol version by the receiver device (display) |
| params.HDCPStatus.currentHDCPVersion | string | mandatory | Currently used HDCP protocol version |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDisplayConnectionChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDisplayConnectionChanged",
  "params": {
    "HDCPStatus": {
      "isConnected": false,
      "isHDCPCompliant": false,
      "isHDCPEnabled": false,
      "hdcpReason": 0,
      "supportedHDCPVersion": "...",
      "receiverHDCPVersion": "...",
      "currentHDCPVersion": "..."
    }
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDisplayConnectionChanged``.

