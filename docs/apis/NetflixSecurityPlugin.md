<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.NetflixSecurity_Plugin"></a>
# NetflixSecurity Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/NetflixSecurity/CHANGELOG.md)**

A NetflixSecurity plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `NetflixSecurity` plugin provides an interface for NetflixSecurity.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.NetflixSecurity) |
| classname | string | Class name: *NetflixSecurity* |
| locator | string | Library name: *libWPEFrameworkNetflixSecurity.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the NetflixSecurity plugin:

NetflixSecurity interface methods:

| Method | Description |
| :-------- | :-------- |
| [deriveKeys](#method.deriveKeys) |  |
| [eSN](#method.eSN) |  |
| [encryptionKey](#method.encryptionKey) |  |
| [hMACKey](#method.hMACKey) |  |
| [wrappingKey](#method.wrappingKey) |  |

<a id="method.deriveKeys"></a>
## *deriveKeys [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privateDhKeyId | uint32_t | - |
| params.peerPublicDhKeyId | uint32_t | - |
| params.derivationKeyId | uint32_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.encryptionKeyId | uint32_t | - |
| result.hmacKeyId | uint32_t | - |
| result.wrappingKeyId | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.NetflixSecurity.deriveKeys",
    "params": {
        "privateDhKeyId": 0,
        "peerPublicDhKeyId": 0,
        "derivationKeyId": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "encryptionKeyId": 0,
        "hmacKeyId": 0,
        "wrappingKeyId": 0
    }
}
```

<a id="method.eSN"></a>
## *eSN [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.NetflixSecurity.eSN"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="method.encryptionKey"></a>
## *encryptionKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.NetflixSecurity.encryptionKey"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="method.hMACKey"></a>
## *hMACKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.NetflixSecurity.hMACKey"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="method.wrappingKey"></a>
## *wrappingKey [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.NetflixSecurity.wrappingKey"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```


