<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.Application_Plugin"></a>
# Application Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/Application/CHANGELOG.md)**

A Application plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)
- [Notifications](#head.Notifications)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `Application` plugin provides an interface for Application.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.Application) |
| classname | string | Class name: *Application* |
| locator | string | Library name: *libWPEFrameworkApplication.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the Application plugin:

Application interface methods:

| Method | Description |
| :-------- | :-------- |
| [reset](#method.reset) | Resets application data |

<a id="method.reset"></a>
## *reset [<sup>method</sup>](#head.Methods)*

Resets application data

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.type | resettype | Type of reset to perform |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.Application.reset",
    "params": {
        "type": "FACTORY"
    }
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


<a id="head.Properties"></a>
# Properties
The following properties are provided by the Application plugin:

Application interface properties:

| Method | Description |
| :-------- | :-------- |
| [ContentLink](#property.ContentLink)<sup>WO</sup> | URI of the associated application-specific content |
| [Identifier](#property.Identifier)<sup>RO</sup> | Application-specific identification string |
| [Language](#property.Language) | Current application user interface language |
| [LaunchPoint](#property.LaunchPoint) | Application launching point |
| [Visible](#property.Visible) | Current application visibility |

<a id="property.ContentLink"></a>
## *ContentLink [<sup>property</sup>](#head.Properties)*

URI of the associated application-specific content

> This property is write-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).link | string | Content URI (e.g. https://youtube.com) |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.Application.contentLink",
    "params": {
        "link": ""
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": null
}
```

<a id="property.Identifier"></a>
## *Identifier [<sup>property</sup>](#head.Properties)*

Application-specific identification string

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).id | string | Identifier string |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.Application.identifier"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": ""
}
```

<a id="property.Language"></a>
## *Language [<sup>property</sup>](#head.Properties)*

Current application user interface language

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).language | string | Language string as per RFC5646 (e.g. en) |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Application.language"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": ""
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.Application.language",
    "params": {
        "language": ""
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```

<a id="property.LaunchPoint"></a>
## *LaunchPoint [<sup>property</sup>](#head.Properties)*

Application launching point

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).point | launchpointtype |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Application.launchPoint"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": "UNDEFINED"
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.Application.launchPoint",
    "params": {
        "point": "UNDEFINED"
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="property.Visible"></a>
## *Visible [<sup>property</sup>](#head.Properties)*

Current application visibility

### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).visiblity | bool |  |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Application.visible"
}
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": true
}
```


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.Application.visible",
    "params": {
        "visiblity": true
    }
}
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```


<a id="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the Application plugin:

Application interface events:

| Event | Description |
| :-------- | :-------- |
| [visibilityChange](#event.visibilityChange) | Application visibility changes |

<a id="event.visibilityChange"></a>
## *visibilityChange [<sup>event</sup>](#head.Notifications)*

Application visibility changes

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.hidden | bool | Denotes if application is currently hidden |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.Application.visibilityChange",
    "params": {
        "hidden": true
    }
}
```
