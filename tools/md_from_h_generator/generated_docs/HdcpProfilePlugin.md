<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.HdcpProfile_Plugin"></a>
# HdcpProfile Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/HdcpProfile/CHANGELOG.md)**

A HdcpProfile plugin for Thunder framework.

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

The `HdcpProfile` plugin provides an interface for HdcpProfile.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdcpProfile) |
| classname | string | Class name: *HdcpProfile* |
| locator | string | Library name: *libWPEFrameworkHdcpProfile.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the HdcpProfile plugin:

HdcpProfile interface methods:

| Method | Description |
| :-------- | :-------- |
| [getHDCPStatus](#method.getHDCPStatus) | Returns HDCP-related data. |
| [getSettopHDCPSupport](#method.getSettopHDCPSupport) | Returns which version of HDCP is supported by the STB. |

<a id="method.getHDCPStatus"></a>
## *getHDCPStatus [<sup>method</sup>](#head.Methods)*

Returns HDCP-related data.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.HDCPStatus | HDCPStatus | Contains HDCP-related data as separate properties |
| result.HDCPStatus.isConnected | bool | Indicates whether a display is connected |
| result.HDCPStatus.isHDCPCompliant | bool | Indicates whether the display is HDCP compliant |
| result.HDCPStatus.isHDCPEnabled | bool | Indicates whether content is protected |
| result.HDCPStatus.hdcpReason | integer | The HDCP status reason |
| result.HDCPStatus.supportedHDCPVersion | string | Supported HDCP protocol version by the host device |
| result.HDCPStatus.receiverHDCPVersion | string | Supported HDCP protocol version by the receiver device (display) |
| result.HDCPStatus.currentHDCPVersion | string | Currently used HDCP protocol version |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.HdcpProfile.getHDCPStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.HdcpProfile.getHDCPStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "HDCPStatus": {
            "isConnected": true,
            "isHDCPCompliant": true,
            "isHDCPEnabled": true,
            "hdcpReason": 0,
            "supportedHDCPVersion": "",
            "receiverHDCPVersion": "",
            "currentHDCPVersion": ""
        },
        "success": true
    }
}
```

<a id="method.getSettopHDCPSupport"></a>
## *getSettopHDCPSupport [<sup>method</sup>](#head.Methods)*

Returns which version of HDCP is supported by the STB.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedHDCPVersion | string | Supported HDCP protocol version by the host device |
| result.isHDCPSupported | bool | Indicates whether HDCP is supported by the STB |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.HdcpProfile.getSettopHDCPSupport"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.HdcpProfile.getSettopHDCPSupport"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "supportedHDCPVersion": "",
        "isHDCPSupported": true,
        "success": true
    }
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the HdcpProfile plugin:

HdcpProfile interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayConnectionChanged](#event.onDisplayConnectionChanged) | Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug |

<a id="event.onDisplayConnectionChanged"></a>
## *onDisplayConnectionChanged [<sup>event</sup>](#head.Notifications)*

Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.HDCPStatus | HDCPStatus | Contains HDCP-related data as separate properties |
| params.HDCPStatus.isConnected | bool | Indicates whether a display is connected |
| params.HDCPStatus.isHDCPCompliant | bool | Indicates whether the display is HDCP compliant |
| params.HDCPStatus.isHDCPEnabled | bool | Indicates whether content is protected |
| params.HDCPStatus.hdcpReason | integer | The HDCP status reason |
| params.HDCPStatus.supportedHDCPVersion | string | Supported HDCP protocol version by the host device |
| params.HDCPStatus.receiverHDCPVersion | string | Supported HDCP protocol version by the receiver device (display) |
| params.HDCPStatus.currentHDCPVersion | string | Currently used HDCP protocol version |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.HdcpProfile.onDisplayConnectionChanged",
    "params": {
        "isConnected": true,
        "isHDCPCompliant": true,
        "isHDCPEnabled": true,
        "hdcpReason": 0,
        "supportedHDCPVersion": "",
        "receiverHDCPVersion": "",
        "currentHDCPVersion": ""
    }
}
```
