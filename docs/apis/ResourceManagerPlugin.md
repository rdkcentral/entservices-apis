<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.ResourceManager_Plugin"></a>
# ResourceManager Plugin

A org.rdk.ResourceManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `ResourceManager`plugin controls the management of platform resource reservations.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.ResourceManager*) |
| classname | string | Class name: *org.rdk.ResourceManager* |
| locator | string | Library name: *libWPEFrameworkResourceManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.ResourceManager plugin:

ResourceManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [setAVBlocked](#method.setAVBlocked) | adds/removes the list of applications with the given callsigns to/from the blacklist |
| [getBlockedAVApplications](#method.getBlockedAVApplications) | Gets a list of blacklisted clients |
| [reserveTTSResourceForApps](#method.reserveTTSResourceForApps) | Reserves the Text To speech Resource for specified clients |
| [reserveTTSResource](#method.reserveTTSResource) | Reserves the Text To speech Resource for specified client |


<a name="method.setAVBlocked"></a>
## *setAVBlocked [<sup>method</sup>](#head.Methods)*

adds/removes the list of applications with the given callsigns to/from the blacklist.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The application callsign |
| params.blocked | boolean | Whether to block (`true`) or unblock (`false`) AV for the callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ResourceManager.setAVBlocked",
    "params": {
        "appId": "searchanddiscovery",
        "blocked": true
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.getBlockedAVApplications"></a>
## *getBlockedAVApplications [<sup>method</sup>](#head.Methods)*

Gets a list of blacklisted clients.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clients | array | A list of clients |
| result.clients[#] | string |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ResourceManager.getBlockedAVApplications"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clients": [
            "org.rdk.Netflix"
        ],
        "success": true
    }
}
```

<a name="method.reserveTTSResourceForApps"></a>
## *reserveTTSResourceForApps [<sup>method</sup>](#head.Methods)*

Reserves the Text To speech Resource for specified clients.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appids | array | A list of application callsigns |
| params.appids[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ResourceManager.reserveTTSResourceForApps",
    "params": {
        "appids": [
            "xumo"
        ]
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.reserveTTSResource"></a>
## *reserveTTSResource [<sup>method</sup>](#head.Methods)*

Reserves the Text To speech Resource for specified client.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The application callsign |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.ResourceManager.reserveTTSResource",
    "params": {
        "appId": "xumo"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

