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
| [config](#method.config) | return RuntimeConfig object |
| [packageState](#method.packageState) | retrutn Package State |
| [getConfigForPackage](#method.getConfigForPackage) | return RuntimeConfig object |


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

return RuntimeConfig object.

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
| result | object | Returns RuntimeConfig on success or an error code string on failure |
| result.dial | boolean |  |
| result.wanLanAccess | boolean |  |
| result?.thunder | boolean | <sup>*(optional)*</sup>  |
| result?.systemMemoryLimit | integer | <sup>*(optional)*</sup>  |
| result?.gpuMemoryLimit | integer | <sup>*(optional)*</sup>  |
| result?.envVariables | string | <sup>*(optional)*</sup>  |
| result?.userId | integer | <sup>*(optional)*</sup>  |
| result?.groupId | integer | <sup>*(optional)*</sup>  |
| result?.grodataImageSizeupId | integer | <sup>*(optional)*</sup>  |
| result?.resourceManagerClientEnabled | boolean | <sup>*(optional)*</sup>  |
| result?.dialId | string | <sup>*(optional)*</sup>  |
| result?.command | string | <sup>*(optional)*</sup>  |
| result?.appType | string | <sup>*(optional)*</sup>  |
| result?.appPath | string | <sup>*(optional)*</sup>  |
| result?.runtimePath | string | <sup>*(optional)*</sup>  |

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
        "dial": false,
        "wanLanAccess": false,
        "thunder": false,
        "systemMemoryLimit": 0,
        "gpuMemoryLimit": 0,
        "envVariables": "...",
        "userId": 0,
        "groupId": 0,
        "grodataImageSizeupId": 0,
        "resourceManagerClientEnabled": false,
        "dialId": "...",
        "command": "...",
        "appType": "...",
        "appPath": "...",
        "runtimePath": "..."
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

return RuntimeConfig object.

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
| result.config | object | Runtime Config values |
| result.config.dial | boolean |  |
| result.config.wanLanAccess | boolean |  |
| result.config?.thunder | boolean | <sup>*(optional)*</sup>  |
| result.config?.systemMemoryLimit | integer | <sup>*(optional)*</sup>  |
| result.config?.gpuMemoryLimit | integer | <sup>*(optional)*</sup>  |
| result.config?.envVariables | string | <sup>*(optional)*</sup>  |
| result.config?.userId | integer | <sup>*(optional)*</sup>  |
| result.config?.groupId | integer | <sup>*(optional)*</sup>  |
| result.config?.grodataImageSizeupId | integer | <sup>*(optional)*</sup>  |
| result.config?.resourceManagerClientEnabled | boolean | <sup>*(optional)*</sup>  |
| result.config?.dialId | string | <sup>*(optional)*</sup>  |
| result.config?.command | string | <sup>*(optional)*</sup>  |
| result.config?.appType | string | <sup>*(optional)*</sup>  |
| result.config?.appPath | string | <sup>*(optional)*</sup>  |
| result.config?.runtimePath | string | <sup>*(optional)*</sup>  |

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
        "config": {
            "dial": false,
            "wanLanAccess": false,
            "thunder": false,
            "systemMemoryLimit": 0,
            "gpuMemoryLimit": 0,
            "envVariables": "...",
            "userId": 0,
            "groupId": 0,
            "grodataImageSizeupId": 0,
            "resourceManagerClientEnabled": false,
            "dialId": "...",
            "command": "...",
            "appType": "...",
            "appPath": "...",
            "runtimePath": "..."
        }
    }
}
```

