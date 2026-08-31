<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PreinstallManager_API"></a>
# PreinstallManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PreinstallManager interface for Thunder framework.

(Defined with IPreinstallManager in [IPreinstallManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IPreinstallManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PreinstallManager interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

PreinstallManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PreinstallManager interface:

PreinstallManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [startPreinstall](#method_startPreinstall) | Checks the preinstall directory for packages to be preinstalled and installs them as needed |
| [getPreinstallState](#method_getPreinstallState) | Provides the state of the preinstallation process |

<a id="method_startPreinstall"></a>
## *startPreinstall [<sup>method</sup>](#head_Methods)*

Checks the preinstall directory for packages to be preinstalled and installs them as needed.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.forceInstall | boolean | mandatory | If true always install the app; if false then install only if not installed or existing is older version |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | Preinstallation completed or started successfully. |
| ```Core::ERROR_GENERAL``` | An error occurred while starting or running preinstallation. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.startPreinstall",
  "params": {
    "forceInstall": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": null
}
```

<a id="method_getPreinstallState"></a>
## *getPreinstallState [<sup>method</sup>](#head_Methods)*

Provides the state of the preinstallation process.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | *...* (must be one of the following: *COMPLETED, IN_PROGRESS, NOT_STARTED*) |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```Core::ERROR_NONE``` | State retrieved successfully. |
| ```Core::ERROR_GENERAL``` | Failed to retrieve the preinstallation state. |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getPreinstallState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "IN_PROGRESS"
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the PreinstallManager interface:

PreinstallManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [onAppInstallationStatus](#notification_onAppInstallationStatus) <sup>deprecated</sup> | Emitted when the installation of a preinstalled app succeeds or fails |
| [onPreinstallationComplete](#notification_onPreinstallationComplete) | Emitted when the preinstallation process completes |

<a id="notification_onAppInstallationStatus"></a>
## *onAppInstallationStatus [<sup>notification</sup>](#head_Notifications)*

Emitted when the installation of a preinstalled app succeeds or fails.

> ``onAppInstallationStatus`` is an alternative name for this notification. This name is **deprecated** and may be removed in the future. It is not recommended for use in new implementations.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.jsonresponse | opaque object | mandatory | Output installation status details as string object |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onAppInstallationStatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onAppInstallationStatus",
  "params": {
    "jsonresponse": {}
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onAppInstallationStatus``.

<a id="notification_onPreinstallationComplete"></a>
## *onPreinstallationComplete [<sup>notification</sup>](#head_Notifications)*

Emitted when the preinstallation process completes.

### Notification Parameters

This notification carries no parameters.

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onPreinstallationComplete",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPreinstallationComplete"
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPreinstallationComplete``.

