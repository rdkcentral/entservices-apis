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
| [configure](#method.configure) |  |
| [eDID](#method.eDID) | TV's Extended Display Identification Data |
| [heightInCentimeters](#method.heightInCentimeters) | Vertical size in centimeters |
| [widthInCentimeters](#method.widthInCentimeters) | Horizontal size in centimeters |

<a id="method.configure"></a>
## *configure [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.framework | PluginHost::IShell |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DisplayInfo.configure",
    "params": {
        "framework": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DisplayInfo.configure", "params": {"framework": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.eDID"></a>
## *eDID [<sup>method</sup>](#head.Methods)*

TV's Extended Display Identification Data

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.length | integer |  |
| result.data | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DisplayInfo.eDID",
    "params": {
        "length": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DisplayInfo.eDID", "params": {"length": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "length": 0,
        "data": ""
    }
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
| result | object |  |
| result.height | integer | height of TV in pixels |

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
        "height": 0
    }
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
| result | object |  |
| result.width | integer | width of TV in pixels |

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
        "width": 0
    }
}
```


<a id="head.Properties"></a>
# Properties
The following properties are provided by the DisplayInfo plugin:

DisplayInfo interface properties:

| Method | Description |
| :-------- | :-------- |
| [colorSpace](#property.colorSpace)<sup>RO</sup> | Provides access to the display's Colour space (chroma subsampling format) |
| [colorimetry](#property.colorimetry)<sup>RO</sup> | Provides access to display's colorimetry |
| [colourDepth](#property.colourDepth)<sup>RO</sup> | Provides access to display's colour Depth |
| [connected](#property.connected)<sup>RO</sup> | Current HDMI connection status |
| [eOTF](#property.eOTF)<sup>RO</sup> | Provides access to display's Electro optical transfer function |
| [frameRate](#property.frameRate)<sup>RO</sup> | Provides access to Frame Rate |
| [freeGpuRam](#property.freeGpuRam)<sup>RO</sup> | Free GPU DRAM memory (in bytes) |
| [hDCPProtection](#property.hDCPProtection) | HDCP protocol used for transmission |
| [hDRSetting](#property.hDRSetting)<sup>RO</sup> | HDR format in use |
| [height](#property.height)<sup>RO</sup> | Vertical resolution of TV |
| [isAudioPassthrough](#property.isAudioPassthrough)<sup>RO</sup> | Current audio passthrough status on HDMI |
| [portName](#property.portName)<sup>RO</sup> | Video output port on the STB used for connection to TV |
| [quantizationRange](#property.quantizationRange)<sup>RO</sup> | Provides access to display's Qauntization Range |
| [sTBCapabilities](#property.sTBCapabilities)<sup>RO</sup> | HDR formats supported by STB |
| [tVCapabilities](#property.tVCapabilities)<sup>RO</sup> | HDR formats supported by TV |
| [totalGpuRam](#property.totalGpuRam)<sup>RO</sup> | Total GPU DRAM memory (in bytes) |
| [verticalFreq](#property.verticalFreq)<sup>RO</sup> | Vertical Frequency |
| [width](#property.width)<sup>RO</sup> | Horizontal resolution of TV |

<a id="property.ColorSpace"></a>
## *ColorSpace [<sup>property</sup>](#head.Properties)*

Provides access to the display's Colour space (chroma subsampling format)

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).cs | string | colour space |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DisplayInfo.colorSpace"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.DisplayInfo.colorSpace"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "cs": "FORMAT_UNKNOWN"
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DisplayInfo.colorimetry"}' http://127.0.0.1:9998/jsonrpc
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
| (property).colour | string | colour depth |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DisplayInfo.colourDepth"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DisplayInfo.colourDepth"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "colour": "COLORDEPTH_UNKNOWN"
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.DisplayInfo.connected"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "isconnected": true
    }
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
| (property).eotf | string | display's EOTF |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.DisplayInfo.eOTF"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.DisplayInfo.eOTF"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "eotf": "EOTF_UNKNOWN"
    }
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
| (property).rate | string | frame rate |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.DisplayInfo.frameRate"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.DisplayInfo.frameRate"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "rate": "FRAMERATE_UNKNOWN"
    }
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
| (property).free | integer |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.DisplayInfo.freeGpuRam"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.DisplayInfo.freeGpuRam"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "free": 0
    }
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
| (property).value | string | protocol |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.DisplayInfo.hDCPProtection"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DisplayInfo.hDCPProtection"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "value": "HDCP_Unencrypted"
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.DisplayInfo.hDCPProtection", "params": {"value": "HDCP_Unencrypted"}}' http://127.0.0.1:9998/jsonrpc
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
| (property).type | string | HDR format |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.DisplayInfo.hDRSetting"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.DisplayInfo.hDRSetting"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "type": "HDR_OFF"
    }
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
| (property).height | integer | height of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.DisplayInfo.height"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.DisplayInfo.height"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "height": 0
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.DisplayInfo.isAudioPassthrough"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "passthru": true
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.DisplayInfo.portName"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "name": ""
    }
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
| (property).qr | string | quantization range |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.DisplayInfo.quantizationRange"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.DisplayInfo.quantizationRange"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "qr": "QUANTIZATIONRANGE_UNKNOWN"
    }
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.DisplayInfo.sTBCapabilities"}' http://127.0.0.1:9998/jsonrpc
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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.DisplayInfo.tVCapabilities"}' http://127.0.0.1:9998/jsonrpc
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
| (property).total | integer |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.DisplayInfo.totalGpuRam"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.DisplayInfo.totalGpuRam"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "total": 0
    }
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
| (property).vf | integer | vertical freq |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.DisplayInfo.verticalFreq"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.DisplayInfo.verticalFreq"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "vf": 0
    }
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
| (property).width | integer | width of TV in pixels |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.DisplayInfo.width"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.DisplayInfo.width"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "width": 0
    }
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
| params.event | string |  |

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
