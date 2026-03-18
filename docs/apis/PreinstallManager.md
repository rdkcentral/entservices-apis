<!-- Generated automatically, DO NOT EDIT! -->
<a id="PreinstallManager_Plugin"></a>
# PreinstallManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PreinstallManager/IPreinstallManager.h)**

A PreinstallManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PreinstallManager` plugin provides an interface for PreinstallManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PreinstallManager) |
| classname | string | Class name: *PreinstallManager* |
| locator | string | Library name: *libWPEFrameworkPreinstallManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the PreinstallManager plugin:

PreinstallManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [getPreinstallState](#getPreinstallState) | Provides the state of the preinstallation process. |
| [startPreinstall](#startPreinstall) | Checks the preinstall directory for packages to be preinstalled and installs them as needed. |

<a id="getPreinstallState"></a>
## *getPreinstallState*

Provides the state of the preinstallation process.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | Value can be NOT_STARTED/IN_PROGRESS/COMPLETED @retval Core::ERROR_NONE: State retrieved successfully. @retval Core::ERROR_GENERAL: Failed to retrieve the preinstallation state. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PreinstallManager.getPreinstallState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PreinstallManager.getPreinstallState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "state": "NOT_STARTED"
    }
}
```

<a id="startPreinstall"></a>
## *startPreinstall*

Checks the preinstall directory for packages to be preinstalled and installs them as needed.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.forceInstall | bool | If true always install the app; if false then install only if not installed or existing is older version @retval Core::ERROR_NONE: Preinstallation completed or started successfully. @retval Core::ERROR_GENERAL: An error occurred while starting or running preinstallation. |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.PreinstallManager.startPreinstall",
    "params": {
        "forceInstall": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PreinstallManager.startPreinstall", "params": {"forceInstall": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PreinstallManager plugin:

PreinstallManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onAppInstallationStatus](#onAppInstallationStatus) | Emitted when the installation of a preinstalled app succeeds or fails. |
| [OnPreinstallationComplete](#OnPreinstallationComplete) | Emitted when the preinstallation process completes |

<a id="onAppInstallationStatus"></a>
## *onAppInstallationStatus*

Emitted when the installation of a preinstalled app succeeds or fails.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.jsonresponse | string | Output installation status details as string object @deprecated |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PreinstallManager.onAppInstallationStatus",
    "params": {
        "jsonresponse": ""
    }
}
```

<a id="onPreinstallationComplete"></a>
## *onPreinstallationComplete*

Emitted when the preinstallation process completes

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PreinstallManager.onPreinstallationComplete"
}
```
