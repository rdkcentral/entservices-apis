<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.PackageInstaller"></a>
# PackageInstaller

A org.rdk.PackageInstaller plugin for Thunder framework.

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

The `PackageInstaller plugin allows download of packages to the system from a remote repository.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| classname | string | Class name: *org.rdk.PackageInstaller* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.PackageInstaller plugin:

org.rdk.PackageInstaller interface methods:

| Method | Description |
| :-------- | :-------- |
| [install](#method.install) | Install a package |
| [uninstall](#method.uninstall) | Uninstall a package |
| [listPackages](#method.listPackages) | Package List |
| [config](#method.config) | Return an opaque runtime configuration payload |
| [packageState](#method.packageState) | retrutn Package State |
| [getConfigForPackage](#method.getConfigForPackage) | Return package details and an opaque runtime configuration payload |


<a name="method.install"></a>
## *install [<sup>method</sup>](#head.Methods)*

Install a package.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params?.version | string | <sup>*(optional)*</sup> Package Version |
| params?.additionalMetadata | array | <sup>*(optional)*</sup> Array of Key Values |
| params?.additionalMetadata[#] | object | <sup>*(optional)*</sup>  |
| params?.additionalMetadata[#].key | string |  |
| params?.additionalMetadata[#].value | string |  |
| params?.fileLocator | string | <sup>*(optional)*</sup> File Locator |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.install",
    "params": {
        "packageId": "...",
        "version": "...",
        "additionalMetadata": [
            {
                "key": "...",
                "value": "..."
            }
        ],
        "fileLocator": "..."
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="method.uninstall"></a>
## *uninstall [<sup>method</sup>](#head.Methods)*

Uninstall a package.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.uninstall",
    "params": {
        "packageId": "..."
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": null
}
```

<a name="method.listPackages"></a>
## *listPackages [<sup>method</sup>](#head.Methods)*

Package List.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | array | Returns null on success or an error code string on failure |
| result[#] | object |  |
| result[#].packageId | string |  |
| result[#].version | string |  |
| result[#].state | string | Install State (must be one of the following: *INSTALLING*, *INSTALLATION_BLOCKED*, *INSTALL_FAILURE*, *INSTALLED*, *UNINSTALLING*, *UNINSTALL_FAILURE*, *UNINSTALLED*) |
| result[#]?.digest | string | <sup>*(optional)*</sup>  |
| result[#]?.sizeKb | integer | <sup>*(optional)*</sup>  |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.listPackages"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "packageId": "...",
            "version": "...",
            "state": "INSTALLING",
            "digest": "...",
            "sizeKb": 0
        }
    ]
}
```

<a name="method.config"></a>
## *config [<sup>method</sup>](#head.Methods)*

Return the runtime configuration as an opaque serialized JSON object. Array-valued properties such as environment variables, log levels, and FKPS files remain JSON arrays; consumers must preserve unknown properties.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Package Version |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.runtimeConfigPayload | string | Opaque serialized JSON object containing runtime configuration |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.config",
    "params": {
        "packageId": "...",
        "version": "..."
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "runtimeConfigPayload": "{\"command\":\"...\",\"envVariables\":[\"KEY=value\"]}"
    }
}
```

<a name="method.packageState"></a>
## *packageState [<sup>method</sup>](#head.Methods)*

retrutn Package State.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageId | string | Package Id |
| params.version | string | Package Version |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | Returns InstallState on success or an error code string on failure. (must be one of the following: *INSTALLING*, *INSTALLATION_BLOCKED*, *INSTALL_FAILURE*, *INSTALLED*, *UNINSTALLING*, *UNINSTALL_FAILURE*, *UNINSTALLED*) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.packageState",
    "params": {
        "packageId": "...",
        "version": "..."
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "INSTALLING"
}
```

<a name="method.getConfigForPackage"></a>
## *getConfigForPackage [<sup>method</sup>](#head.Methods)*

Return the runtime configuration as an opaque serialized JSON object. Array-valued properties such as environment variables, log levels, and FKPS files remain JSON arrays; consumers must preserve unknown properties.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | File Locator |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.packageId | string | Package Id |
| result.version | string | Package Version |
| result.runtimeConfigPayload | string | Opaque serialized JSON object containing runtime configuration |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageInstaller.getConfigForPackage",
    "params": {
        "fileLocator": "..."
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "packageId": "...",
        "version": "...",
        "runtimeConfigPayload": "{\"command\":\"...\",\"envVariables\":[\"KEY=value\"]}"
    }
}
```

