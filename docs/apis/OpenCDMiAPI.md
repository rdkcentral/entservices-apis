<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_OpenCDMi_API"></a>
# OpenCDMi API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

OCDM interface for Thunder framework.

(Defined by [OCDM.json](https://github.com/rdkcentral/entservices-apis/tree/main/apis))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the OCDM interface (version 1.0.0). It includes detailed specification about its properties provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

OpenCDMi JSON-RPC interface.

<a id="head_Properties"></a>
# Properties

The following properties are provided by the OCDM interface:

OCDM interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [drms](#property_drms) | read-only | Supported DRM systems |
| [keysystems](#property_keysystems) | read-only | DRM key systems |
| [sessions](#property_sessions) | read-only | Active sessions enumerator |

<a id="property_drms"></a>
## *drms [<sup>property</sup>](#head_Properties)*

Provides access to the supported DRM systems.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Supported DRM systems |
| (property)[#] | object | mandatory | *...* |
| (property)[#].name | string | mandatory | Name of the DRM |
| (property)[#].keysystems | array | mandatory | *...* |
| (property)[#].keysystems[#] | string | mandatory | Identifier of a key system |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.drms"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "name": "PlayReady",
      "keysystems": [
        "com.microsoft.playready"
      ]
    }
  ]
}
```

<a id="property_keysystems"></a>
## *keysystems [<sup>property</sup>](#head_Properties)*

Provides access to the DRM key systems.

> This property is **read-only**.

> The *drm system* parameter shall be passed as the index to the property, i.e. ``keysystems@<drm-system>``.

### Index

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| drm-system | string | mandatory | *...* |

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | DRM key systems |
| (property)[#] | string | mandatory | Identifier of a key system |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ERROR_BAD_REQUEST``` | Invalid DRM name |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.keysystems@PlayReady"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    "com.microsoft.playready"
  ]
}
```

<a id="property_sessions"></a>
## *sessions [<sup>property</sup>](#head_Properties)*

Provides access to the active sessions enumerator.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | array | mandatory | Active sessions enumerator |
| (property)[#] | object | mandatory | *...* |
| (property)[#].drm | string | mandatory | Name of the DRM system |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.sessions"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "drm": "PlayReady"
    }
  ]
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the OCDM interface:

OCDM interface events:

| Notification | Description |
| :-------- | :-------- |
| [drmalreadyinitialized](#notification_drmalreadyinitialized) | Signals that the specified DRM system could not be initialized because it is already initialized by another process |
| [drminitializationstatus](#notification_drminitializationstatus) | Notifies about DRM initialization status |

<a id="notification_drmalreadyinitialized"></a>
## *drmalreadyinitialized [<sup>notification</sup>](#head_Notifications)*

Signals that the specified DRM system could not be initialized because it is already initialized by another process.

### Description

When this event is received, the application owning given DRM system should release it immediately.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.drm | string | mandatory | Name of the DRM system |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "drmalreadyinitialized",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.drmalreadyinitialized",
  "params": {
    "drm": "PlayReady"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.drmalreadyinitialized``.

<a id="notification_drminitializationstatus"></a>
## *drminitializationstatus [<sup>notification</sup>](#head_Notifications)*

Notifies about DRM initialization status.

### Description

Register to this event to be notified about DRM retrying status busy/failure/success

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | string | mandatory | BUSY - drm is used by another process, SUCCESS - recovered from BUSY state after retry, FAILED - not recovered after re-trying from BUSY (must be one of the following: *BUSY, FAILED, SUCCESS*) |
| params.drm | string | mandatory | Name of the DRM system |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "drminitializationstatus",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.drminitializationstatus",
  "params": {
    "status": "SUCCESS",
    "drm": "PlayReady"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.drminitializationstatus``.

