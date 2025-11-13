<!-- Generated automatically, DO NOT EDIT! -->
<a id="DeviceDiagnostics_Plugin"></a>
# DeviceDiagnostics Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DeviceDiagnostics/IDeviceDiagnostics.h)**

A DeviceDiagnostics plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DeviceDiagnostics` plugin provides an interface for DeviceDiagnostics.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DeviceDiagnostics) |
| classname | string | Class name: *DeviceDiagnostics* |
| locator | string | Library name: *libWPEFrameworkDeviceDiagnostics.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the DeviceDiagnostics plugin:

DeviceDiagnostics interface methods:

| Method | Description |
| :-------- | :-------- |
| [getAVDecoderStatus](#getAVDecoderStatus) | Gets the most active status of audio/video decoder/pipeline |
| [getConfiguration](#getConfiguration) | Gets the values associated with the corresponding property names |
| [getMilestones](#getMilestones) | Returns the list of milestones |
| [logMilestone](#logMilestone) | Log marker string to rdk milestones log |

<a id="getAVDecoderStatus"></a>
## *getAVDecoderStatus*

Gets the most active status of audio/video decoder/pipeline

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.avDecoderStatus | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DeviceDiagnostics.getAVDecoderStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DeviceDiagnostics.getAVDecoderStatus"}' http://127.0.0.1:9998/jsonrpc
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

<a id="getConfiguration"></a>
## *getConfiguration*

Gets the values associated with the corresponding property names

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.names | IStringIterator | String array of property names |
| params.names[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.paramList | IDeviceDiagnosticsParamListIterator | specified properties and their values |
| result.paramList[#].name | string | name |
| result.paramList[#].value | string | value |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.DeviceDiagnostics.getConfiguration",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DeviceDiagnostics.getConfiguration", "params": [""]}' http://127.0.0.1:9998/jsonrpc
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

<a id="getMilestones"></a>
## *getMilestones*

Returns the list of milestones

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.milestones | IStringIterator | A string [] of milestones |
| result.milestones[#] | string |  |
| result.success | bool | boolean |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DeviceDiagnostics.getMilestones"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DeviceDiagnostics.getMilestones"}' http://127.0.0.1:9998/jsonrpc
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

<a id="logMilestone"></a>
## *logMilestone*

Log marker string to rdk milestones log

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.marker | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | boolean |

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


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DeviceDiagnostics.logMilestone", "params": {"marker": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the DeviceDiagnostics plugin:

DeviceDiagnostics interface events:

| Event | Description |
| :-------- | :-------- |
| [onAVDecoderStatusChanged](#onAVDecoderStatusChanged) | Triggered when the most active status of audio/video decoder/pipeline changes |

<a id="onAVDecoderStatusChanged"></a>
## *onAVDecoderStatusChanged*

Triggered when the most active status of audio/video decoder/pipeline changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.avDecoderStatusChange | string | string |

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
