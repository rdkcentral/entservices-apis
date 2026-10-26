<!-- Generated automatically, DO NOT EDIT! -->
<a id="ResourceMonitor_Module"></a>
# ResourceMonitor Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/ResourceMonitor/IResourceMonitor.h)**

A ResourceMonitor module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IResourceMonitor](#IResourceMonitor)
    - [Methods](#IResourceMonitor-Methods)
    - [Notifications](#IResourceMonitor-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `ResourceMonitor` module provides the following interface(s):

- IResourceMonitor

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.ResourceMonitor) |
| classname | string | Class name: *ResourceMonitor* |
| locator | string | Library name: *libWPEFrameworkResourceMonitor.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IResourceMonitor"></a>
## IResourceMonitor Interface

### Description

Structure for the Resource monitor stats

<a id="IResourceMonitor-Methods"></a>
### Methods

The following methods are provided by the IResourceMonitor Interface:

| Method | Description |
| :-------- | :-------- |
| [GetFlashSpace](#GetFlashSpace) | Returns flash usage. |
| [GetMemInfo](#GetMemInfo) | Returns memory information. |
| [GetPsiMetrics](#GetPsiMetrics) | Returns PSI metrics. |
| [GetStats](#GetStats) | Returns resource statistics. |
| [GetSwapUsed](#GetSwapUsed) | Returns swap usage. |
| [reconcile](#reconcile) | Requests a resource reconciliation pass, evicting inactive applications if required and permitted. |
| [SetConfig](#SetConfig) | Loads Resource Monitor Configuration |

<a id="GetFlashSpace"></a>
## *GetFlashSpace*

Returns flash usage.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.total | integer | Total flash storage quota for hibernated apps. |
| result.used | integer | Flash storage currently consumed by hibernated apps. |
| result.available | integer | Remaining flash storage available to hibernated apps. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "method": "org.rdk.ResourceMonitor.GetFlashSpace"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 0, "method": "org.rdk.ResourceMonitor.GetFlashSpace"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "result": {
        "total": 0,
        "used": 0,
        "available": 0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 0,
    "error": {
        "code": 1,
        "message": "Failed to access flash storage information."
    }
}
```

<a id="GetMemInfo"></a>
## *GetMemInfo*

Returns memory information.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.memAvailable | integer | Amount of available RAM in KiB. |
| result.swapFree | integer | Amount of free swap space in KiB. |
| result.swapTotal | integer | Total configured swap space in KiB. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "method": "org.rdk.ResourceMonitor.GetMemInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 1, "method": "org.rdk.ResourceMonitor.GetMemInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "result": {
        "memAvailable": 0,
        "swapFree": 0,
        "swapTotal": 0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 1,
    "error": {
        "code": 1,
        "message": "Failed to read memory information from the system."
    }
}
```

<a id="GetPsiMetrics"></a>
## *GetPsiMetrics*

Returns PSI metrics.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.metric | string | PSI metric selector |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.value | double | PSI percentage value |
| result.total | integer | PSI total value |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "method": "org.rdk.ResourceMonitor.GetPsiMetrics",
    "params": {
        "metric": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 2, "method": "org.rdk.ResourceMonitor.GetPsiMetrics", "params": {"metric": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "result": {
        "value": 0.0,
        "total": 0
    }
}
```


#### Error Response (Core::ERROR_BAD_REQUEST)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 240,
        "message": "Invalid metric selector."
    }
}
```


#### Error Response (Core::ERROR_UNAVAILABLE)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 2,
        "message": "PSI monitoring is disabled."
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 2,
    "error": {
        "code": 1,
        "message": "Failed to access PSI statistics."
    }
}
```

<a id="GetStats"></a>
## *GetStats*

Returns resource statistics.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.stats | object | Structure containing memory, swap, flash, GPU and peak usage statistics. |
| result.stats.systemMemTotal | integer |  |
| result.stats.systemMemUsed | integer |  |
| result.stats.systemMemAvailable | integer |  |
| result.stats.peakSystemMemUsed | integer |  |
| result.stats.gpuMemTotal | integer |  |
| result.stats.gpuMemUsed | integer |  |
| result.stats.gpuMemAvailable | integer |  |
| result.stats.peakGpuMemUsed | integer |  |
| result.stats.swapTotal | integer |  |
| result.stats.swapFree | integer |  |
| result.stats.swapUsed | integer |  |
| result.stats.peakSwapUsed | integer |  |
| result.stats.flashSpaceTotal | integer |  |
| result.stats.flashSpaceUsed | integer |  |
| result.stats.flashSpaceAvailable | integer |  |
| result.stats.peakFlashSpaceUsed | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "method": "org.rdk.ResourceMonitor.GetStats"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.ResourceMonitor.GetStats"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "result": {
        "systemMemTotal": 0,
        "systemMemUsed": 0,
        "systemMemAvailable": 0,
        "peakSystemMemUsed": 0,
        "gpuMemTotal": 0,
        "gpuMemUsed": 0,
        "gpuMemAvailable": 0,
        "peakGpuMemUsed": 0,
        "swapTotal": 0,
        "swapFree": 0,
        "swapUsed": 0,
        "peakSwapUsed": 0,
        "flashSpaceTotal": 0,
        "flashSpaceUsed": 0,
        "flashSpaceAvailable": 0,
        "peakFlashSpaceUsed": 0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 3,
    "error": {
        "code": 1,
        "message": "Failed to gather one or more resource statistics."
    }
}
```

<a id="GetSwapUsed"></a>
## *GetSwapUsed*

Returns swap usage.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.swapUsed | integer | Uncompressed swap data currently stored in zram. |
| result.memUsedTotal | integer | Actual memory consumed by zram. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "method": "org.rdk.ResourceMonitor.GetSwapUsed"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 4, "method": "org.rdk.ResourceMonitor.GetSwapUsed"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "result": {
        "swapUsed": 0,
        "memUsedTotal": 0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": "2.0",
    "id": 4,
    "error": {
        "code": 1,
        "message": "Failed to access zram statistics."
    }
}
```

<a id="reconcile"></a>
## *reconcile*

Requests a resource reconciliation pass, evicting inactive applications if required and permitted.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Application identifier associated with the resource request. |
| params.ramTargetMB | integer | Maximum RAM requested by the application, in megabytes. |
| params.allowTerminate | bool | When true, inactive applications may be terminated to free resources. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "method": "org.rdk.ResourceMonitor.reconcile",
    "params": {
        "appId": "",
        "ramTargetMB": 0,
        "allowTerminate": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 5, "method": "org.rdk.ResourceMonitor.reconcile", "params": {"appId": "", "ramTargetMB": 0, "allowTerminate": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 5,
    "result": null
}
```

<a id="SetConfig"></a>
## *SetConfig*

Loads Resource Monitor Configuration

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.config | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "method": "org.rdk.ResourceMonitor.SetConfig",
    "params": {
        "config": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": "2.0", "id": 6, "method": "org.rdk.ResourceMonitor.SetConfig", "params": {"config": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "result": null
}
```


#### Error Response (Core::ERROR_BAD_REQUEST)

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "error": {
        "code": 240,
        "message": "Invalid JSON configuration."
    }
}
```


#### Error Response (Core::ERROR_ILLEGAL_STATE)

```json
{
    "jsonrpc": "2.0",
    "id": 6,
    "error": {
        "code": 5,
        "message": "Configuration change attempted after initialization."
    }
}
```

<a id="IResourceMonitor-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IResourceMonitor Interface:

| Event | Description |
| :-------- | :-------- |
| [onReconciliationComplete](#onReconciliationComplete) | Triggered when a resource reconciliation pass completes. |

<a id="onReconciliationComplete"></a>
## *onReconciliationComplete*

Triggered when a resource reconciliation pass completes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | Application identifier associated with the reconciliation request. |
| params.targetRamAchieved | bool | True when enough RAM headroom is available to proceed with loading another application. |

### Examples

```json
{
    "jsonrpc": "2.0",
    "id": 7,
    "method": "org.rdk.ResourceMonitor.onReconciliationComplete",
    "params": {
        "appId": "",
        "targetRamAchieved": true
    }
}
```

