<!-- Generated automatically, DO NOT EDIT! -->
<a id="DisplayInfo_Module"></a>
# DisplayInfo Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DisplayInfo/IDisplayInfo.h)**

A DisplayInfo module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IGraphicsProperties](#IGraphicsProperties)
    - [Properties](#IGraphicsProperties-Properties)
  - [IConnectionProperties](#IConnectionProperties)
    - [Methods](#IConnectionProperties-Methods)
    - [Notifications](#IConnectionProperties-Notifications)
    - [Properties](#IConnectionProperties-Properties)
  - [IHDRProperties](#IHDRProperties)
    - [Properties](#IHDRProperties-Properties)
  - [IDisplayProperties](#IDisplayProperties)
    - [Methods](#IDisplayProperties-Methods)
    - [Properties](#IDisplayProperties-Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DisplayInfo` module provides the following interface(s):

- IGraphicsProperties
- IConnectionProperties
- IHDRProperties
- IDisplayProperties

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DisplayInfo) |
| classname | string | Class name: *DisplayInfo* |
| locator | string | Library name: *libWPEFrameworkDisplayInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IGraphicsProperties"></a>
## IGraphicsProperties Interface

<a id="IGraphicsProperties-Properties"></a>
### Properties

The following properties are provided by the IGraphicsProperties Interface:

| Property | Description |
| :-------- | :-------- |
| [freeGpuRam](#freeGpuRam)<sup>RO</sup> | Free GPU DRAM memory (in bytes) |
| [totalGpuRam](#totalGpuRam)<sup>RO</sup> | Total GPU DRAM memory (in bytes) |

<a id="freeGpuRam"></a>
## *freeGpuRam*

Retrieves the free GPU DRAM memory (in bytes).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).free | integer | Free GPU RAM |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DisplayInfo.freeGpuRam"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DisplayInfo.freeGpuRam"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "free": 1073741824
    }
}
```

<a id="totalGpuRam"></a>
## *totalGpuRam*

Retrieves the total GPU DRAM memory (in bytes).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).total | integer | Total GPU RAM |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.DisplayInfo.totalGpuRam"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.DisplayInfo.totalGpuRam"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "total": 2147483648
    }
}
```

---

<a id="IConnectionProperties"></a>
## IConnectionProperties Interface

<a id="IConnectionProperties-Methods"></a>
### Methods

The following methods are provided by the IConnectionProperties Interface:

| Method | Description |
| :-------- | :-------- |
| [eDID](#eDID) | TV's Extended Display Identification Data |
| [heightInCentimeters](#heightInCentimeters) | Vertical size in centimeters |
| [widthInCentimeters](#widthInCentimeters) | Horizontal size in centimeters |

<a id="eDID"></a>
## *eDID*

Retrieves the TV's Extended Display Identification Data (EDID) as a byte string.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | integer | length of edid byte string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.length | integer | length of edid byte string |
| result.data | string | EDID byte string |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DisplayInfo.eDID",
    "params": {
        "length": 2
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DisplayInfo.eDID", "params": {"length": 2}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "length": 2,
        "data": "[0x00,0xFF,0xFF,0xFF]"
    }
}
```

<a id="heightInCentimeters"></a>
## *heightInCentimeters*

Retrieves the vertical size of the TV in centimeters.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.height | integer | Height in cm |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DisplayInfo.heightInCentimeters"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DisplayInfo.heightInCentimeters"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "height": 50
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="widthInCentimeters"></a>
## *widthInCentimeters*

Retrieves the horizontal size of the TV in centimeters.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.width | integer | Width in cm |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DisplayInfo.widthInCentimeters"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DisplayInfo.widthInCentimeters"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "width": 100
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IConnectionProperties-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IConnectionProperties Interface:

| Event | Description |
| :-------- | :-------- |
| [updated](#updated) |  |

<a id="updated"></a>
## *updated*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.event | string | Possible values: PRE_RESOLUTION_CHANGE, POST_RESOLUTION_CHANGE, HDMI_CHANGE, HDCP_CHANGE |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DisplayInfo.updated",
    "params": {
        "event": "PRE_RESOLUTION_CHANGE"
    }
}
```

<a id="IConnectionProperties-Properties"></a>
### Properties

The following properties are provided by the IConnectionProperties Interface:

| Property | Description |
| :-------- | :-------- |
| [connected](#connected)<sup>RO</sup> | Current HDMI connection status |
| [hDCPProtection](#hDCPProtection) | HDCP protocol used for transmission |
| [height](#height)<sup>RO</sup> | Vertical resolution of TV |
| [isAudioPassthrough](#isAudioPassthrough)<sup>RO</sup> | Current audio passthrough status on HDMI |
| [portName](#portName)<sup>RO</sup> | Video output port on the STB used for connection to TV |
| [verticalFreq](#verticalFreq)<sup>RO</sup> | Vertical Frequency |
| [width](#width)<sup>RO</sup> | Horizontal resolution of TV |

<a id="connected"></a>
## *connected*

Retrieves the current HDMI connection status.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).isconnected | bool | connected/disconnected |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DisplayInfo.connected"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.DisplayInfo.connected"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "isconnected": true
    }
}
```

<a id="hDCPProtection"></a>
## *hDCPProtection*

Retrieves the HDCP protocol used for transmission.

### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).value | string | Protocol. Possible values: HDCP_UNENCRYPTED, HDCP_1X, HDCP_2X, HDCP_AUTO |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DisplayInfo.hDCPProtection"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DisplayInfo.hDCPProtection"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "value": "HDCP_2X"
    }
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DisplayInfo.hDCPProtection",
    "params": {
        "value": "HDCP_2X"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DisplayInfo.hDCPProtection", "params": {"value": "HDCP_2X"}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="height"></a>
## *height*

Retrieves the vertical resolution of the TV.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).height | integer | Height of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DisplayInfo.height"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.DisplayInfo.height"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "height": 50
    }
}
```

<a id="isAudioPassthrough"></a>
## *isAudioPassthrough*

Retrieves the current audio passthrough status on HDMI.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).passthru | bool | enabled/disabled |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.DisplayInfo.isAudioPassthrough"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.DisplayInfo.isAudioPassthrough"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "passthru": true
    }
}
```

<a id="portName"></a>
## *portName*

Retrieves the video output port on the STB used for connection to TV.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).name | string | Video output port name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DisplayInfo.portName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.DisplayInfo.portName"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "name": "HDMI0"
    }
}
```

<a id="verticalFreq"></a>
## *verticalFreq*

Retrieves the vertical frequency of the TV.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).vf | integer | Vertical frequency |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DisplayInfo.verticalFreq"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.DisplayInfo.verticalFreq"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "vf": 60
    }
}
```

<a id="width"></a>
## *width*

Retrieves the horizontal resolution of the TV.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).width | integer | Width of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.DisplayInfo.width"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.DisplayInfo.width"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "width": 100
    }
}
```

---

<a id="IHDRProperties"></a>
## IHDRProperties Interface

<a id="IHDRProperties-Properties"></a>
### Properties

The following properties are provided by the IHDRProperties Interface:

| Property | Description |
| :-------- | :-------- |
| [hDRSetting](#hDRSetting)<sup>RO</sup> | HDR format in use |
| [sTBCapabilities](#sTBCapabilities)<sup>RO</sup> | HDR formats supported by STB |
| [tVCapabilities](#tVCapabilities)<sup>RO</sup> | HDR formats supported by TV |

<a id="hDRSetting"></a>
## *hDRSetting*

Retrieves the HDR format in use.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | string | HDR format. Possible values: HDR_OFF, HDR_10, HDR_10PLUS, HDR_HLG, HDR_DOLBYVISION, HDR_TECHNICOLOR, HDR_SDR |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DisplayInfo.hDRSetting"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.DisplayInfo.hDRSetting"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "type": "HDR_10"
    }
}
```

<a id="sTBCapabilities"></a>
## *sTBCapabilities*

Retrieves the HDR formats supported by STB.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | array | array of HDR formats |
| (property).type[#] | string | Possible values: HDR_OFF, HDR_10, HDR_10PLUS, HDR_HLG, HDR_DOLBYVISION, HDR_TECHNICOLOR, HDR_SDR |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DisplayInfo.sTBCapabilities"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.DisplayInfo.sTBCapabilities"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": [
        "[HDR_10, HDR_10PLUS]"
    ]
}
```

<a id="tVCapabilities"></a>
## *tVCapabilities*

Retrieves the HDR formats supported by TV.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | array | array of HDR formats |
| (property).type[#] | string | Possible values: HDR_OFF, HDR_10, HDR_10PLUS, HDR_HLG, HDR_DOLBYVISION, HDR_TECHNICOLOR, HDR_SDR |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.DisplayInfo.tVCapabilities"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.DisplayInfo.tVCapabilities"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": [
        "[HDR_10, HDR_10PLUS]"
    ]
}
```

---

<a id="IDisplayProperties"></a>
## IDisplayProperties Interface

<a id="IDisplayProperties-Methods"></a>
### Methods

The following methods are provided by the IDisplayProperties Interface:

| Method | Description |
| :-------- | :-------- |
| [getCurrentColorimetry](#getCurrentColorimetry) | Returns the active colorimetry standard of the current connected video port |

<a id="getCurrentColorimetry"></a>
## *getCurrentColorimetry*

Retrieves the active colorimetry standard of the current connected video port. If no display is connected, COLORIMETRY_UNKNOWN is returned. If the colorimetry coefficient is not mapped to a known standard, COLORIMETRY_OTHER is returned.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.colorimetry | string | current colorimetry info (colorimetryType is COLORIMETRY_UNKNOWN if no display connected, COLORIMETRY_OTHER if coefficient unmapped). Possible values: COLORIMETRY_UNKNOWN, COLORIMETRY_OTHER, COLORIMETRY_SMPTE170M, COLORIMETRY_BT709, COLORIMETRY_XVYCC601, COLORIMETRY_XVYCC709, COLORIMETRY_SYCC601, COLORIMETRY_OPYCC601, COLORIMETRY_OPRGB, COLORIMETRY_BT2020YCCBCBRC, COLORIMETRY_BT2020RGB_YCBCR |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DisplayInfo.getCurrentColorimetry"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DisplayInfo.getCurrentColorimetry"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": "{ colorimetry: COLORIMETRY_BT709 }"
}
```

<a id="IDisplayProperties-Properties"></a>
### Properties

The following properties are provided by the IDisplayProperties Interface:

| Property | Description |
| :-------- | :-------- |
| [colorSpace](#colorSpace)<sup>RO</sup> | Provides access to the display's Colour space (chroma subsampling format) |
| [colorimetry](#colorimetry)<sup>RO</sup> | Provides access to display's colorimetry |
| [colourDepth](#colourDepth)<sup>RO</sup> | Provides access to display's Colour Depth |
| [eOTF](#eOTF)<sup>RO</sup> | Provides access to display's Electro optical transfer function |
| [frameRate](#frameRate)<sup>RO</sup> | Provides access to Frame Rate |
| [quantizationRange](#quantizationRange)<sup>RO</sup> | Provides access to display's Quantization Range |

<a id="colorSpace"></a>
## *colorSpace*

Retrieves the display's Colour space (chroma subsampling format).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).cs | string | Colour space. Possible values: FORMAT_UNKNOWN, FORMAT_OTHER, FORMAT_RGB_444, FORMAT_YCBCR_444, FORMAT_YCBCR_422, FORMAT_YCBCR_420 |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DisplayInfo.colorSpace"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DisplayInfo.colorSpace"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "cs": "FORMAT_YCBCR_422"
    }
}
```

<a id="colorimetry"></a>
## *colorimetry*

Retrieves the display's colorimetry.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).colorimetry | array | display colorimetry |
| (property).colorimetry[#] | string | Possible values: COLORIMETRY_UNKNOWN, COLORIMETRY_OTHER, COLORIMETRY_SMPTE170M, COLORIMETRY_BT709, COLORIMETRY_XVYCC601, COLORIMETRY_XVYCC709, COLORIMETRY_SYCC601, COLORIMETRY_OPYCC601, COLORIMETRY_OPRGB, COLORIMETRY_BT2020YCCBCBRC, COLORIMETRY_BT2020RGB_YCBCR |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DisplayInfo.colorimetry"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DisplayInfo.colorimetry"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": [
        "[COLORIMETRY_BT709, COLORIMETRY_BT2020YCCBCBRC]"
    ]
}
```

<a id="colourDepth"></a>
## *colourDepth*

Retrieves the display's Colour depth.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).colour | string | Colour depth. Possible values: COLORDEPTH_UNKNOWN, COLORDEPTH_8_BIT, COLORDEPTH_10_BIT, COLORDEPTH_12_BIT |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DisplayInfo.colourDepth"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.DisplayInfo.colourDepth"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "colour": "COLOURDEPTH_10_BIT"
    }
}
```

<a id="eOTF"></a>
## *eOTF*

Retrieves the display's Electro optical transfer function (EOTF).

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).eotf | string | display's EOTF. Possible values: EOTF_UNKNOWN, EOTF_OTHER, EOTF_BT1886, EOTF_BT2100, EOTF_SMPTE_ST_2084 |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DisplayInfo.eOTF"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.DisplayInfo.eOTF"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "eotf": "EOTF_BT2100"
    }
}
```

<a id="frameRate"></a>
## *frameRate*

Retrieves the display's frame rate.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).rate | string | Frame rate. Possible values: FRAMERATE_UNKNOWN, FRAMERATE_23_976, FRAMERATE_24, FRAMERATE_25, FRAMERATE_29_97, FRAMERATE_30, FRAMERATE_47_952, FRAMERATE_48, FRAMERATE_50, FRAMERATE_59_94, FRAMERATE_60, FRAMERATE_119_88, FRAMERATE_120, FRAMERATE_144 |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DisplayInfo.frameRate"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.DisplayInfo.frameRate"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "rate": "FRAMERATE_60"
    }
}
```

<a id="quantizationRange"></a>
## *quantizationRange*

Retrieves the display's quantization range.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).qr | string | quantization range. Possible values: QUANTIZATIONRANGE_UNKNOWN, QUANTIZATIONRANGE_LIMITED, QUANTIZATIONRANGE_FULL |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.DisplayInfo.quantizationRange"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.DisplayInfo.quantizationRange"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "qr": "QUANTIZATIONRANGE_LIMITED"
    }
}
```

