<!-- Generated automatically, DO NOT EDIT! -->
<a id="ResourceManager_Plugin"></a>
# ResourceManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/ResourceManager/IResourceManager.h)**

A ResourceManager plugin for Thunder framework.

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

The `ResourceManager` plugin provides an interface for ResourceManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.ResourceManager) |
| classname | string | Class name: *ResourceManager* |
| locator | string | Library name: *libWPEFrameworkResourceManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the ResourceManager plugin:

ResourceManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [getBlockedAVApplications](#getBlockedAVApplications) | Gets list of applications with blocked AV access |
| [reserveTTSResource](#reserveTTSResource) | Reserves TTS resource for a single application |
| [reserveTTSResourceForApps](#reserveTTSResourceForApps) | Reserves TTS resource for multiple applications |
| [setAVBlocked](#setAVBlocked) | Sets AV blocking status for an application |

<a id="getBlockedAVApplications"></a>
## *getBlockedAVApplications*

Gets list of applications with blocked AV access

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clients | IClientIterator | Iterator containing the list of application identifiers that have blocked AV access |
| result.clients[#] | string |  |
| result.success | bool | Indicates whether the TTS operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.ResourceManager.getBlockedAVApplications"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.ResourceManager.getBlockedAVApplications"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "clients": [
            ""
        ],
        "success": true
    }
}
```

<a id="reserveTTSResource"></a>
## *reserveTTSResource*

Reserves TTS resource for a single application

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the TTS operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.ResourceManager.reserveTTSResource",
    "params": {
        "appId": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.ResourceManager.reserveTTSResource", "params": {"appId": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "success": true
    }
}
```

<a id="reserveTTSResourceForApps"></a>
## *reserveTTSResourceForApps*

Reserves TTS resource for multiple applications

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appIds | IAppIdIterator | Iterator containing the list of application identifiers requesting TTS resource reservation |
| params.appIds[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Indicates whether the TTS operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.ResourceManager.reserveTTSResourceForApps",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.ResourceManager.reserveTTSResourceForApps", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "success": true
    }
}
```

<a id="setAVBlocked"></a>
## *setAVBlocked*

Sets AV blocking status for an application

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.appId | string | The unique identifier of the application |
| params.blocked | bool | Boolean flag indicating whether to block (true) or unblock (false) AV access |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.message | string | Status or error message describing the result of the operation |
| result.success | bool | Indicates whether the TTS operation was successful |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.ResourceManager.setAVBlocked",
    "params": {
        "appId": "",
        "blocked": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.ResourceManager.setAVBlocked", "params": {"appId": "", "blocked": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "message": "",
        "success": true
    }
}
```


