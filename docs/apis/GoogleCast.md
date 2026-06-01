<!-- Generated automatically, DO NOT EDIT! -->
<a id="GoogleCast_Plugin"></a>
# GoogleCast Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/GoogleCast/IGoogleCast.h)**

A GoogleCast plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Properties](#Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `GoogleCast` plugin provides an interface for GoogleCast.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.GoogleCast) |
| classname | string | Class name: *GoogleCast* |
| locator | string | Library name: *libWPEFrameworkGoogleCast.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |


<a id="Properties"></a>
# Properties
The following properties are provided by the GoogleCast plugin:

GoogleCast interface properties:

| Property | Description |
| :-------- | :-------- |
| [getCastStatus](#getCastStatus)<sup>RO</sup> | Status of cast shell interfacing via Cast control API. @retval Core::ERROR_NONE: Indicates successful retrieval of cast status. |

<a id="GetCastStatus"></a>
## *GetCastStatus*

Status of cast shell interfacing via Cast control API. @retval Core::ERROR_NONE: Indicates successful retrieval of cast status.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).status | CastStatus |  |
| (property).status.castBuildNumber | string |  |
| (property).status.castState | string |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.GoogleCast.getCastStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.GoogleCast.getCastStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "castBuildNumber": "",
        "castState": "UNKNOWN"
    }
}
```

