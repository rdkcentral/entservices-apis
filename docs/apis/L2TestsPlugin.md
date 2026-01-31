<!-- Generated automatically, DO NOT EDIT! -->
<a id="L2TestsPlugin_Plugin"></a>
# L2TestsPlugin Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/L2TestsPlugin/IL2Test.h)**

A L2TestsPlugin plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `L2TestsPlugin` plugin provides an interface for L2TestsPlugin.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.L2TestsPlugin) |
| classname | string | Class name: *L2TestsPlugin* |
| locator | string | Library name: *libWPEFrameworkL2TestsPlugin.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the L2TestsPlugin plugin:

L2TestsPlugin interface methods:

| Method | Description |
| :-------- | :-------- |
| [performL2Tests](#performL2Tests) | Perform L2 tests |

<a id="performL2Tests"></a>
## *performL2Tests*

Perform L2 tests

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.parameters | string | Input parameters as a JSON string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.response | string | Output response as a JSON string @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.L2TestsPlugin.performL2Tests",
    "params": {
        "parameters": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.L2TestsPlugin.performL2Tests", "params": {"parameters": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "response": ""
    }
}
```


