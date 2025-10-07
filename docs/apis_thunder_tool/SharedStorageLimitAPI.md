<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_SharedStorageLimit_API"></a>
# SharedStorageLimit API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

SharedStorageLimit interface for Thunder framework.

(Defined with ISharedStorageLimit in [ISharedStorage.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ISharedStorage.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the SharedStorageLimit interface (version 1.0.0). It includes detailed specification about its methods provided.

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
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

SharedStorageLimit JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the SharedStorageLimit interface:

SharedStorageLimit interface methods:

| Method | Description |
| :-------- | :-------- |
| [setNamespaceStorageLimit](#method_setNamespaceStorageLimit) | Sets the storage limit for a given namespace |
| [getNamespaceStorageLimit](#method_getNamespaceStorageLimit) | Returns the storage limit for a given namespace |

<a id="method_setNamespaceStorageLimit"></a>
## *setNamespaceStorageLimit [<sup>method</sup>](#head_Methods)*

Sets the storage limit for a given namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |
| params.storageLimit | integer | mandatory | Size |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Success |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setNamespaceStorageLimit",
  "params": {
    "scope": "account",
    "namespace": "...",
    "storageLimit": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_getNamespaceStorageLimit"></a>
## *getNamespaceStorageLimit [<sup>method</sup>](#head_Methods)*

Returns the storage limit for a given namespace.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.scope | string | mandatory | Must be device or account (must be one of the following: *account, device*) |
| params.namespace | string | mandatory | Name space |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Size in bytes |
| result.storageLimit | integer | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getNamespaceStorageLimit",
  "params": {
    "scope": "account",
    "namespace": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "storageLimit": 0
  }
}
```

