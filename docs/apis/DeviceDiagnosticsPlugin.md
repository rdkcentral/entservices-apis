<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.DeviceDiagnostics_Plugin"></a>
# DeviceDiagnostics Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/DeviceDiagnostics/CHANGELOG.md)**

A DeviceDiagnostics plugin for Thunder framework.

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

The `DeviceDiagnostics` plugin provides an interface for DeviceDiagnostics.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceDiagnostics) |
| classname | string | Class name: *DeviceDiagnostics* |
| locator | string | Library name: *libWPEFrameworkDeviceDiagnostics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the DeviceDiagnostics plugin:

DeviceDiagnostics interface methods:

| Method | Description |
| :-------- | :-------- |
| [getAVDecoderStatus](#method.getAVDecoderStatus) | Gets the most active status of audio/video decoder/pipeline |
| [getConfiguration](#method.getConfiguration) | Gets the values associated with the corresponding property names |
| [getMilestones](#method.getMilestones) | Returns the list of milestones |
| [logMilestone](#method.logMilestone) | Log marker string to rdk milestones log |

<a id="method.getAVDecoderStatus"></a>
## *getAVDecoderStatus [<sup>method</sup>](#head.Methods)*

Gets the most active status of audio/video decoder/pipeline

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.AVDecoderStatus | AvDecoderStatusResult | - out |
| result.AVDecoderStatus.avDecoderStatus | string | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceDiagnostics.getAVDecoderStatus"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "avDecoderStatus": ""
    }
}
```

<a id="method.getConfiguration"></a>
## *getConfiguration [<sup>method</sup>](#head.Methods)*

Gets the values associated with the corresponding property names

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.names | IStringIterator | - in - String array of property names |
| params.names[#] | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.paramList | IDeviceDiagnosticsParamListIterator | - out - specified properties and their values |
| result.paramList[#].name | string | name |
| result.paramList[#].value | string | value |
| result.success | bool | - out - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceDiagnostics.getConfiguration",
    "params": {
        "names": [
            ""
        ]
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "paramList": [
            {
                "name": "",
                "value": ""
            }
        ],
        "success": true
    }
}
```

<a id="method.getMilestones"></a>
## *getMilestones [<sup>method</sup>](#head.Methods)*

Returns the list of milestones

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.milestones | IStringIterator | - out - A string [] of milestones |
| result.milestones[#] | string | - |
| result.success | bool | - out - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceDiagnostics.getMilestones"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "milestones": [
            ""
        ],
        "success": true
    }
}
```

<a id="method.logMilestone"></a>
## *logMilestone [<sup>method</sup>](#head.Methods)*

Log marker string to rdk milestones log

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.marker | string | - in - string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.success | bool | - out - boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DeviceDiagnostics.logMilestone",
    "params": {
        "marker": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": true
}
```



<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the DeviceDiagnostics plugin:

DeviceDiagnostics interface events:

| Event | Description |
| :-------- | :-------- |
| [onAVDecoderStatusChanged](#event.onAVDecoderStatusChanged) | Triggered when the most active status of audio/video decoder/pipeline changes |

<a id="event.onAVDecoderStatusChanged"></a>
## *onAVDecoderStatusChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the most active status of audio/video decoder/pipeline changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDecoderStatusChange | string | - in - string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DeviceDiagnostics.onAVDecoderStatusChanged",
    "params": {
        "avDecoderStatusChange": ""
    }
}
```
