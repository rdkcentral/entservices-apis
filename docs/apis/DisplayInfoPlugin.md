<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.DisplayInfo_Plugin"></a>
# DisplayInfo Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/DisplayInfo/CHANGELOG.md)**

A DisplayInfo plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `DisplayInfo` plugin provides an interface for DisplayInfo.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DisplayInfo) |
| classname | string | Class name: *DisplayInfo* |
| locator | string | Library name: *libWPEFrameworkDisplayInfo.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the DisplayInfo plugin:

DisplayInfo interface methods:

| Method | Description |
| :-------- | :-------- |
| [eDID](#method.eDID) | TV's Extended Display Identification Data |
| [heightInCentimeters](#method.heightInCentimeters) | Vertical size in centimeters |
| [widthInCentimeters](#method.widthInCentimeters) | Horizontal size in centimeters |

<a id="method.eDID"></a>
## *eDID [<sup>method</sup>](#head.Methods)*

TV's Extended Display Identification Data

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | uint16_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.length | uint16_t | - |
| result.data[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DisplayInfo.eDID",
    "params": {
        "length": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": ""
}
```

<a id="method.heightInCentimeters"></a>
## *heightInCentimeters [<sup>method</sup>](#head.Methods)*

Vertical size in centimeters

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.height | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DisplayInfo.heightInCentimeters"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": ""
}
```

<a id="method.widthInCentimeters"></a>
## *widthInCentimeters [<sup>method</sup>](#head.Methods)*

Horizontal size in centimeters

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.width | uint8_t | width in cm |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DisplayInfo.widthInCentimeters"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": ""
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the DisplayInfo plugin:

DisplayInfo interface properties:

| Method | Description |
| :-------- | :-------- |
| [ColorSpace](#property.ColorSpace)<sup>RO</sup> | Provides access to the display's Colour space (chroma subsampling format) |
| [Colorimetry](#property.Colorimetry)<sup>RO</sup> | Provides access to display's colorimetry |
| [ColourDepth](#property.ColourDepth)<sup>RO</sup> | Provides access to display's colour Depth |
| [Connected](#property.Connected)<sup>RO</sup> | Current HDMI connection status |
| [EOTF](#property.EOTF)<sup>RO</sup> | Provides access to display's Electro optical transfer function |
| [FrameRate](#property.FrameRate)<sup>RO</sup> | Provides access to Frame Rate |
| [FreeGpuRam](#property.FreeGpuRam)<sup>RO</sup> | Free GPU DRAM memory (in bytes) |
| [HDCPProtection](#property.HDCPProtection) | HDCP protocol used for transmission |
| [HDRSetting](#property.HDRSetting)<sup>RO</sup> | HDR format in use |
| [Height](#property.Height)<sup>RO</sup> | Vertical resolution of TV |
| [IsAudioPassthrough](#property.IsAudioPassthrough)<sup>RO</sup> | Current audio passthrough status on HDMI |
| [PortName](#property.PortName)<sup>RO</sup> | Video output port on the STB used for connection to TV |
| [QuantizationRange](#property.QuantizationRange)<sup>RO</sup> | Provides access to display's Qauntization Range |
| [STBCapabilities](#property.STBCapabilities)<sup>RO</sup> | HDR formats supported by STB |
| [TVCapabilities](#property.TVCapabilities)<sup>RO</sup> | HDR formats supported by TV |
| [TotalGpuRam](#property.TotalGpuRam)<sup>RO</sup> | Total GPU DRAM memory (in bytes) |
| [VerticalFreq](#property.VerticalFreq)<sup>RO</sup> | Vertical Frequency |
| [Width](#property.Width)<sup>RO</sup> | Horizontal resolution of TV |

<a id="property.ColorSpace"></a>
## *ColorSpace [<sup>property</sup>](#head.Properties)*

Provides access to the display's Colour space (chroma subsampling format)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).cs | ColourSpaceType | colour space |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DisplayInfo.colorSpace"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": "FORMAT_UNKNOWN"
}
```

<a id="property.Colorimetry"></a>
## *Colorimetry [<sup>property</sup>](#head.Properties)*

Provides access to display's colorimetry

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).colorimetry | IColorimetryIterator | display colorimetry |
| (property).colorimetry[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DisplayInfo.colorimetry"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": [
        "COLORIMETRY_UNKNOWN"
    ]
}
```

<a id="property.ColourDepth"></a>
## *ColourDepth [<sup>property</sup>](#head.Properties)*

Provides access to display's colour Depth

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).colour | ColourDepthType | colour depth |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DisplayInfo.colourDepth"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": "COLORDEPTH_UNKNOWN"
}
```

<a id="property.Connected"></a>
## *Connected [<sup>property</sup>](#head.Properties)*

Current HDMI connection status

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).isconnected | bool | connected/disconnected |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DisplayInfo.connected"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": true
}
```

<a id="property.EOTF"></a>
## *EOTF [<sup>property</sup>](#head.Properties)*

Provides access to display's Electro optical transfer function

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).eotf | EotfType | display's EOTF |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DisplayInfo.eOTF"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": "EOTF_UNKNOWN"
}
```

<a id="property.FrameRate"></a>
## *FrameRate [<sup>property</sup>](#head.Properties)*

Provides access to Frame Rate

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).rate | FrameRateType | frame rate |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DisplayInfo.frameRate"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": "FRAMERATE_UNKNOWN"
}
```

<a id="property.FreeGpuRam"></a>
## *FreeGpuRam [<sup>property</sup>](#head.Properties)*

Free GPU DRAM memory (in bytes)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).free | uint64_t |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DisplayInfo.freeGpuRam"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": 0
}
```

<a id="property.HDCPProtection"></a>
## *HDCPProtection [<sup>property</sup>](#head.Properties)*

HDCP protocol used for transmission

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).value | HDCPProtectionType | protocol |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DisplayInfo.hDCPProtection"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": "HDCP_Unencrypted"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DisplayInfo.hDCPProtection",
    "params": {
        "value": "HDCP_Unencrypted"
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="property.HDRSetting"></a>
## *HDRSetting [<sup>property</sup>](#head.Properties)*

HDR format in use

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | HDRType | HDR format |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DisplayInfo.hDRSetting"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": "HDR_OFF"
}
```

<a id="property.Height"></a>
## *Height [<sup>property</sup>](#head.Properties)*

Vertical resolution of TV

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).height | uint32_t | height of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DisplayInfo.height"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": 0
}
```

<a id="property.IsAudioPassthrough"></a>
## *IsAudioPassthrough [<sup>property</sup>](#head.Properties)*

Current audio passthrough status on HDMI

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).passthru | bool | enabled/disabled |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.DisplayInfo.isAudioPassthrough"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": true
}
```

<a id="property.PortName"></a>
## *PortName [<sup>property</sup>](#head.Properties)*

Video output port on the STB used for connection to TV

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).name | string | video output port name |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.DisplayInfo.portName"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": ""
}
```

<a id="property.QuantizationRange"></a>
## *QuantizationRange [<sup>property</sup>](#head.Properties)*

Provides access to display's Qauntization Range

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).qr | QuantizationRangeType | quantization range |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DisplayInfo.quantizationRange"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": "QUANTIZATIONRANGE_UNKNOWN"
}
```

<a id="property.STBCapabilities"></a>
## *STBCapabilities [<sup>property</sup>](#head.Properties)*

HDR formats supported by STB

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | IHDRIterator |  |
| (property).type[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.DisplayInfo.sTBCapabilities"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": [
        "HDR_OFF"
    ]
}
```

<a id="property.TVCapabilities"></a>
## *TVCapabilities [<sup>property</sup>](#head.Properties)*

HDR formats supported by TV

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).type | IHDRIterator |  |
| (property).type[#] | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.DisplayInfo.tVCapabilities"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": [
        "HDR_OFF"
    ]
}
```

<a id="property.TotalGpuRam"></a>
## *TotalGpuRam [<sup>property</sup>](#head.Properties)*

Total GPU DRAM memory (in bytes)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).total | uint64_t |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.DisplayInfo.totalGpuRam"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": 0
}
```

<a id="property.VerticalFreq"></a>
## *VerticalFreq [<sup>property</sup>](#head.Properties)*

Vertical Frequency

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).vf | uint32_t | vertical freq |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.DisplayInfo.verticalFreq"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": 0
}
```

<a id="property.Width"></a>
## *Width [<sup>property</sup>](#head.Properties)*

Horizontal resolution of TV

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).width | uint32_t | width of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DisplayInfo.width"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": 0
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the DisplayInfo plugin:

DisplayInfo interface events:

| Event | Description |
| :-------- | :-------- |
| [updated](#event.updated) |  |

<a id="event.updated"></a>
## *updated [<sup>event</sup>](#head.Notifications)*



### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.event | Source | - |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DisplayInfo.updated",
    "params": {
        "event": "PRE_RESOLUTION_CHANGE"
    }
}
```
