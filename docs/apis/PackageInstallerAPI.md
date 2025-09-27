<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.PackageInstaller_API"></a>
# PackageInstaller API

A PackageInstaller plugin for Thunder framework.

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
| classname | string | Class name: *PackageInstaller* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the PackageInstaller plugin:

PackageInstaller interface methods:

| Method | Description |
| :-------- | :-------- |
| [install](#method.install) | Install a package |
| [uninstall](#method.uninstall) | Uninstall a package |
| [listPackages](#method.listPackages) | Package List |


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
    "method": "PackageInstaller.install",
    "params": {
        "packageId": "...",
        "version": "...",
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
    "method": "PackageInstaller.uninstall",
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
    "method": "PackageInstaller.listPackages"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": [
        {
            "packageId": "APPLICATION_TYPE_INTERACTIVE",
            "version": "...",
            "state": "INSTALLING",
            "digest": "...",
            "sizeKb": 0
        }
    ]
}
```

