<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.PackageDownloader_API"></a>
# PackageDownloader API

A org.rdk.PackageDownloader plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Notifications](#head.Notifications)

<a name="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="head.Description"></a>
# Description

The `PackageDownloader plugin allows download of packages to the system from a remote repository.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| classname | string | Class name: *org.rdk.PackageDownloader* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.PackageDownloader plugin:

org.rdk.PackageDownloader interface methods:

| Method | Description |
| :-------- | :-------- |
| [download](#method.download) | Download API |
| [pause](#method.pause) | Pause API |
| [resume](#method.resume) | Resume API |
| [cancel](#method.cancel) | Calcel API |
| [delete](#method.delete) | Delete API |
| [progress](#method.progress) | Progress API |
| [getStorageDetails](#method.getStorageDetails) | GetStorageDetails API |
| [rateLimit](#method.rateLimit) | RateLimit API |


<a name="method.download"></a>
## *download [<sup>method</sup>](#head.Methods)*

Download API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.url | string | url |
| params?.option | object | <sup>*(optional)*</sup> download options |
| params?.option?.priority | boolean | <sup>*(optional)*</sup> Priority |
| params?.option?.retries | integer | <sup>*(optional)*</sup> Retries |
| params?.option?.ratelimit | integer | <sup>*(optional)*</sup> Rate limit |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | Returns null on success or an error code string on failure |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PackageDownloader.download",
    "params": {
        "url": "http://<SERVER>/<PATH>",
        "option": {
            "priority": false,
            "retries": 0,
            "ratelimit": 0
        }
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "..."
}
```

<a name="method.pause"></a>
## *pause [<sup>method</sup>](#head.Methods)*

Pause API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.pause",
    "params": {
        "downloadId": "..."
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

<a name="method.resume"></a>
## *resume [<sup>method</sup>](#head.Methods)*

Resume API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.resume",
    "params": {
        "downloadId": "..."
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

<a name="method.cancel"></a>
## *cancel [<sup>method</sup>](#head.Methods)*

Calcel API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.cancel",
    "params": {
        "downloadId": "..."
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

<a name="method.delete"></a>
## *delete [<sup>method</sup>](#head.Methods)*

Delete API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.delete",
    "params": {
        "downloadId": "..."
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

<a name="method.progress"></a>
## *progress [<sup>method</sup>](#head.Methods)*

Progress API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.progress",
    "params": {
        "downloadId": "..."
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

<a name="method.getStorageDetails"></a>
## *getStorageDetails [<sup>method</sup>](#head.Methods)*

GetStorageDetails API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.getStorageDetails",
    "params": {
        "downloadId": "..."
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

<a name="method.rateLimit"></a>
## *rateLimit [<sup>method</sup>](#head.Methods)*

RateLimit API.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Download Id |

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
    "method": "org.rdk.PackageDownloader.rateLimit",
    "params": {
        "downloadId": "..."
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

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.PackageDownloader plugin:

org.rdk.PackageDownloader interface events:

| Event | Description |
| :-------- | :-------- |
| [OnAppDownloadStatus](#event.OnAppDownloadStatus) | Triggered whenever the App is installed |


<a name="event.OnAppDownloadStatus"></a>
## *OnAppDownloadStatus [<sup>event</sup>](#head.Notifications)*

Triggered whenever the App is installed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.packageInfo | array | array of packageInfo |
| params.packageInfo[#] | object |  |
| params.packageInfo[#].downloadId | string |  |
| params.packageInfo[#].fileLocator | string |  |
| params.packageInfo[#].reason | string |  |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.OnAppDownloadStatus",
    "params": {
        "packageInfo": [
            {
                "downloadId": "...",
                "fileLocator": "...",
                "reason": "..."
            }
        ]
    }
}
```

