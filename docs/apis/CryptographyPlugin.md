<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Cryptography_Plugin"></a>
# Cryptography Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Cryptography/CHANGELOG.md)**

A Cryptography plugin for Thunder framework.

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

The `Cryptography` plugin provides an interface for Cryptography.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Cryptography) |
| classname | string | Class name: *Cryptography* |
| locator | string | Library name: *libWPEFrameworkCryptography.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Cryptography plugin:

Cryptography interface methods:

| Method | Description |
| :-------- | :-------- |
| [calculate](#method.calculate) |  |
| [create](#method.create) |  |
| [decrypt](#method.decrypt) |  |
| [delete](#method.delete) |  |
| [derive](#method.derive) |  |
| [encrypt](#method.encrypt) |  |
| [exists](#method.exists) |  |
| [export](#method.export) |  |
| [flush](#method.flush) |  |
| [generate](#method.generate) |  |
| [get](#method.get) |  |
| [import](#method.import) |  |
| [ingest](#method.ingest) |  |
| [load](#method.load) |  |
| [set](#method.set) |  |
| [size](#method.size) |  |

<a id="method.calculate"></a>
## *calculate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.maxLength | uint8_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.data[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Cryptography.calculate",
    "params": {
        "maxLength": ""
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

<a id="method.create"></a>
## *create [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.locator | string | - |
| params.keyType | keytype | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.id | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Cryptography.create",
    "params": {
        "locator": "",
        "keyType": "AES128"
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": 0
}
```

<a id="method.decrypt"></a>
## *decrypt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ivLength | uint8_t | - |
| params.iv[] | uint8_t | - |
| params.inputLength | uint32_t | - |
| params.input[] | uint8_t | - |
| params.maxOutputLength | uint32_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Cryptography.decrypt",
    "params": {
        "ivLength": "",
        "iv[]": "",
        "inputLength": 0,
        "input[]": "",
        "maxOutputLength": 0
    }
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

<a id="method.delete"></a>
## *delete [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Cryptography.delete",
    "params": {
        "id": 0
    }
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

<a id="method.derive"></a>
## *derive [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privateKey | uint32_t | - |
| params.peerPublicKeyId | uint32_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.secretId | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Cryptography.derive",
    "params": {
        "privateKey": 0,
        "peerPublicKeyId": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": 0
}
```

<a id="method.encrypt"></a>
## *encrypt [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ivLength | uint8_t | - |
| params.iv[] | uint8_t | - |
| params.inputLength | uint32_t | - |
| params.input[] | uint8_t | - |
| params.maxOutputLength | uint32_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.output[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Cryptography.encrypt",
    "params": {
        "ivLength": "",
        "iv[]": "",
        "inputLength": 0,
        "input[]": "",
        "maxOutputLength": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": ""
}
```

<a id="method.exists"></a>
## *exists [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.locator | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.result | bool | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Cryptography.exists",
    "params": {
        "locator": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```

<a id="method.export"></a>
## *export [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | uint32_t | - |
| params.maxLength | uint16_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.blob[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.Cryptography.export",
    "params": {
        "id": 0,
        "maxLength": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": ""
}
```

<a id="method.flush"></a>
## *flush [<sup>method</sup>](#head.Methods)*



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
    "id": 8,
    "method": "org.rdk.Cryptography.flush"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="method.generate"></a>
## *generate [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.generator | uint8_t | - |
| params.modulusSize | uint16_t | - |
| params.modulus[] | uint8_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.privKeyId | uint32_t | - |
| result.pubKeyId | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.Cryptography.generate",
    "params": {
        "generator": "",
        "modulusSize": "",
        "modulus[]": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "privKeyId": 0,
        "pubKeyId": 0
    }
}
```

<a id="method.get"></a>
## *get [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | uint32_t | - |
| params.maxLength | uint16_t | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.blob[] | uint8_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.Cryptography.get",
    "params": {
        "id": 0,
        "maxLength": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": ""
}
```

<a id="method.import"></a>
## *import [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | uint16_t | - |
| params.blob[] | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.Cryptography.import",
    "params": {
        "length": "",
        "blob[]": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="method.ingest"></a>
## *ingest [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | uint32_t | - |
| params.data[] | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.Cryptography.ingest",
    "params": {
        "length": 0,
        "data[]": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="method.load"></a>
## *load [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.locator | string | - |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.id | uint32_t | - |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.Cryptography.load",
    "params": {
        "locator": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": 0
}
```

<a id="method.set"></a>
## *set [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.length | uint16_t | - |
| params.blob[] | uint8_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.Cryptography.set",
    "params": {
        "length": "",
        "blob[]": ""
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```

<a id="method.size"></a>
## *size [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.id | uint32_t | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.Cryptography.size",
    "params": {
        "id": 0
    }
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": null
}
```


