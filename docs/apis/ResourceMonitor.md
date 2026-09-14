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

<a id="IResourceMonitor-Methods"></a>
### Methods

The following methods are provided by the IResourceMonitor Interface:

| Method | Description |
| :-------- | :-------- |
| [reconcile](#reconcile) | Requests a resource reconciliation pass, evicting inactive applications if required and permitted. |

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
    "jsonrpc": 2.0,
    "id": 0,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.ResourceMonitor.reconcile", "params": {"appId": "", "ramTargetMB": 0, "allowTerminate": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
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
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.ResourceMonitor.onReconciliationComplete",
    "params": {
        "appId": "",
        "targetRamAchieved": true
    }
}
```

