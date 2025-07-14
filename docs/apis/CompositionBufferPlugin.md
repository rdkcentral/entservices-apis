<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.CompositionBuffer_Plugin"></a>
# CompositionBuffer Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/CompositionBuffer/CHANGELOG.md)**

A CompositionBuffer plugin for Thunder framework.

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

The `CompositionBuffer` plugin provides an interface for CompositionBuffer.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.CompositionBuffer) |
| classname | string | Class name: *CompositionBuffer* |
| locator | string | Library name: *libWPEFrameworkCompositionBuffer.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the CompositionBuffer plugin:

CompositionBuffer interface methods:

| Method | Description |
| :-------- | :-------- |
| [accessor](#method.accessor) | frame buffer interface with hardware optimisation in mind |
| [addRef](#method.addRef) |  |
| [completed](#method.completed) |  |
| [format](#method.format) |  |
| [height](#method.height) |  |
| [identifier](#method.identifier) |  |
| [isValid](#method.isValid) |  |
| [modifier](#method.modifier) |  |
| [next](#method.next) |  |
| [offset](#method.offset) |  |
| [release](#method.release) |  |
| [render](#method.render) |  |
| [reset](#method.reset) |  |
| [stride](#method.stride) |  |
| [type](#method.type) |  |
| [width](#method.width) |  |

<a id="method.accessor"></a>
## *accessor [<sup>method</sup>](#head.Methods)*

frame buffer interface with hardware optimisation in mind

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
    "id": 0,
    "method": "org.rdk.CompositionBuffer.accessor"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="method.addRef"></a>
## *addRef [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.CompositionBuffer.addRef"
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

<a id="method.completed"></a>
## *completed [<sup>method</sup>](#head.Methods)*



### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.dirty | bool | - |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.CompositionBuffer.completed",
    "params": {
        "dirty": true
    }
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

<a id="method.format"></a>
## *format [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.CompositionBuffer.format"
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

<a id="method.height"></a>
## *height [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.CompositionBuffer.height"
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

<a id="method.identifier"></a>
## *identifier [<sup>method</sup>](#head.Methods)*



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
    "id": 5,
    "method": "org.rdk.CompositionBuffer.identifier"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="method.isValid"></a>
## *isValid [<sup>method</sup>](#head.Methods)*



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
    "id": 6,
    "method": "org.rdk.CompositionBuffer.isValid"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="method.modifier"></a>
## *modifier [<sup>method</sup>](#head.Methods)*



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
    "id": 7,
    "method": "org.rdk.CompositionBuffer.modifier"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": null
}
```

<a id="method.next"></a>
## *next [<sup>method</sup>](#head.Methods)*



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
    "method": "org.rdk.CompositionBuffer.next"
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

<a id="method.offset"></a>
## *offset [<sup>method</sup>](#head.Methods)*



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
    "id": 9,
    "method": "org.rdk.CompositionBuffer.offset"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="method.release"></a>
## *release [<sup>method</sup>](#head.Methods)*



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
    "id": 10,
    "method": "org.rdk.CompositionBuffer.release"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="method.render"></a>
## *render [<sup>method</sup>](#head.Methods)*



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
    "id": 11,
    "method": "org.rdk.CompositionBuffer.render"
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

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*



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
    "id": 12,
    "method": "org.rdk.CompositionBuffer.reset"
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

<a id="method.stride"></a>
## *stride [<sup>method</sup>](#head.Methods)*



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
    "id": 13,
    "method": "org.rdk.CompositionBuffer.stride"
}
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="method.type"></a>
## *type [<sup>method</sup>](#head.Methods)*



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
    "id": 14,
    "method": "org.rdk.CompositionBuffer.type"
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

<a id="method.width"></a>
## *width [<sup>method</sup>](#head.Methods)*



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
    "id": 15,
    "method": "org.rdk.CompositionBuffer.width"
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


