<!-- Generated automatically, DO NOT EDIT! -->
<a id="HdcpProfile_Plugin"></a>
# HdcpProfile Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/HdcpProfile)**

A HdcpProfile plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `HdcpProfile` plugin provides an interface for HdcpProfile.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.HdcpProfile) |
| classname | string | Class name: *HdcpProfile* |
| locator | string | Library name: *libWPEFrameworkHdcpProfile.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the HdcpProfile plugin:

HdcpProfile interface methods:

| Method | Description | Event |
| :-------- | :-------- |:-------- |
| [getHDCPStatus](#getHDCPStatus) | Returns HDCP-related data. | NA |
| [getSettopHDCPSupport](#getSettopHDCPSupport) | Returns which version of HDCP is supported by the STB. | NA |

<a id="getHDCPStatus"></a>
## *getHDCPStatus [<sup>method</sup>](#Methods)*

Returns HDCP-related data.

### Events
No Events are associated with this method.
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

<a id="getSettopHDCPSupport"></a>
## *getSettopHDCPSupport [<sup>method</sup>](#Methods)*

Returns which version of HDCP is supported by the STB.

### Events
No Events are associated with this method.
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



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the HdcpProfile plugin:

HdcpProfile interface events:

| Event | Description |
| :-------- | :-------- |
| [onDisplayConnectionChanged](#onDisplayConnectionChanged) | Triggered if HDMI was connected or disconnected upon receiving onHdmiOutputHotPlug |

<a id="onDisplayConnectionChanged"></a>
## *onDisplayConnectionChanged [<sup>event</sup>](#Notifications)*

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
