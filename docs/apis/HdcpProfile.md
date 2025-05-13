<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IHdcpProfile_Plugin"></a>
# IHdcpProfile Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IHdcpProfile/CHANGELOG.md)**

A IHdcpProfile plugin for Thunder framework.

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

The `IHdcpProfile` plugin provides an interface for IHdcpProfile.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IHdcpProfile*) |
| classname | string | Class name: *IHdcpProfile* |
| locator | string | Library name: *libWPEFrameworkIHdcpProfile.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IHdcpProfile plugin:

IHdcpProfile interface methods:

| Method | Description |
| :-------- | :-------- |
| [GetHDCPStatus](#method.GetHDCPStatus) | Returns HDCP-related data. |
| [GetSettopHDCPSupport](#method.GetSettopHDCPSupport) | Returns which version of HDCP is supported by the STB. |

<a id="method.GetHDCPStatus"></a>
## *GetHDCPStatus [<sup>method</sup>](#head.Methods)*

Returns HDCP-related data.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.hdcpStatus | HDCPStatus |  |
| result.hdcpStatus.isConnected | bool | isConnected */ /* @brief Indicates whether a display is connected |
| result.hdcpStatus.isHDCPCompliant | bool | isHDCPCompliant */ /* @brief Indicates whether the display is HDCP compliant |
| result.hdcpStatus.isHDCPEnabled | bool | isHDCPEnabled *//* @brief Indicates whether content is protected |
| result.hdcpStatus.hdcpReason | uint32_t | hdcpReason *//* @brief The HDCP status reason |
| result.hdcpStatus.supportedHDCPVersion | string | supportedHDCPVersion */ /* @brief Supported HDCP protocol version by the host device |
| result.hdcpStatus.receiverHDCPVersion | string | receiverHDCPVersion */ /* @brief Supported HDCP protocol version by the receiver device (display) |
| result.hdcpStatus.currentHDCPVersion | string | currentHDCPVersion */ /* @brief Currently used HDCP protocol version |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdcpProfile.GetHDCPStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "hdcpStatus": {
            "isConnected": "true",
            "isHDCPCompliant": "true",
            "isHDCPEnabled": "true",
            "hdcpReason": "0",
            "supportedHDCPVersion": "",
            "receiverHDCPVersion": "",
            "currentHDCPVersion": ""
        },
        "success": "true"
    }
}
```
<a id="method.GetSettopHDCPSupport"></a>
## *GetSettopHDCPSupport [<sup>method</sup>](#head.Methods)*

Returns which version of HDCP is supported by the STB.

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.supportedHDCPVersion | string | supportedHDCPVersion */ /* @brief Supported HDCP protocol version by the host device |
| result.isHDCPSupported | bool | Indicates whether HDCP is supported by the STB |
| result.success | bool | Indicates whether the operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdcpProfile.GetSettopHDCPSupport"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "supportedHDCPVersion": "",
        "isHDCPSupported": "true",
        "success": "true"
    }
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the IHdcpProfile plugin:

IHdcpProfile interface events:

| Method | Description |
| :-------- | :-------- |
| [OnDisplayConnectionChanged](#event.OnDisplayConnectionChanged) | Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug |

<a id="event.OnDisplayConnectionChanged"></a>
## *OnDisplayConnectionChanged [<sup>event</sup>](#head.Notifications)*

Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.hdcpStatus | HDCPStatus |  |
| params.hdcpStatus.isConnected | bool | isConnected */ /* @brief Indicates whether a display is connected |
| params.hdcpStatus.isHDCPCompliant | bool | isHDCPCompliant */ /* @brief Indicates whether the display is HDCP compliant |
| params.hdcpStatus.isHDCPEnabled | bool | isHDCPEnabled *//* @brief Indicates whether content is protected |
| params.hdcpStatus.hdcpReason | uint32_t | hdcpReason *//* @brief The HDCP status reason |
| params.hdcpStatus.supportedHDCPVersion | string | supportedHDCPVersion */ /* @brief Supported HDCP protocol version by the host device |
| params.hdcpStatus.receiverHDCPVersion | string | receiverHDCPVersion */ /* @brief Supported HDCP protocol version by the receiver device (display) |
| params.hdcpStatus.currentHDCPVersion | string | currentHDCPVersion */ /* @brief Currently used HDCP protocol version |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IHdcpProfile.OnDisplayConnectionChanged",
    "params": {
        "hdcpStatus": {
            "isConnected": "true",
            "isHDCPCompliant": "true",
            "isHDCPEnabled": "true",
            "hdcpReason": "0",
            "supportedHDCPVersion": "",
            "receiverHDCPVersion": "",
            "currentHDCPVersion": ""
        }
    }
}
```