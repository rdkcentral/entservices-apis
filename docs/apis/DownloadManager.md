<!-- Generated automatically, DO NOT EDIT! -->
<a id="DownloadManager_Module"></a>
# DownloadManager Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/DownloadManager/IDownloadManager.h)**

A DownloadManager module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IDownloadManager](#IDownloadManager)
    - [Methods](#IDownloadManager-Methods)
    - [Notifications](#IDownloadManager-Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `DownloadManager` module provides the following interface(s):

- IDownloadManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.DownloadManager) |
| classname | string | Class name: *DownloadManager* |
| locator | string | Library name: *libWPEFrameworkDownloadManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IDownloadManager"></a>
## IDownloadManager Interface

<a id="IDownloadManager-Methods"></a>
### Methods

The following methods are provided by the IDownloadManager Interface:

| Method | Description |
| :-------- | :-------- |
| [cancel](#cancel) | Cancel an ongoing download session |
| [delete](#delete) | Delete a downloaded file from the system using its locator path |
| [download](#download) | Download Start downloading a file from a specified URL with custom options |
| [pause](#pause) | Pause an active download session |
| [progress](#progress) | Progress Query current download progress |
| [rateLimit](#rateLimit) | RateLimit Set rate limiting for a specific download session |
| [resume](#resume) | Resume a paused download session |

<a id="cancel"></a>
## *cancel*

Cancels the specified download session, stopping any ongoing download and cleaning up associated resources.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Unique identifier of the download to cancel |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.DownloadManager.cancel",
    "params": {
        "downloadId": 1234
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.DownloadManager.cancel", "params": {"downloadId": 1234}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": null
}
```

<a id="delete"></a>
## *delete*

Deletes the specified downloaded file from the system, freeing up storage space.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fileLocator | string | File path or locator of the file to be deleted |
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
    "method": "org.rdk.DownloadManager.delete",
    "params": {
        "fileLocator": "/path/to/file"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.DownloadManager.delete", "params": {"fileLocator": "/path/to/file"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="download"></a>
## *download*

Initiates the download of a file from the specified URL using the provided options. The download ID is returned through the output parameter.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.url | string | URL from which the file is to be downloaded |
| params.options | object | Options controlling download behavior |
| params.options.priority | bool |  |
| params.options.retries | integer |  |
| params.options.rateLimit | integer |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.downloadId | string | Output parameter that returns the assigned download ID |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.DownloadManager.download",
    "params": {
        "url": "http://example.com/file",
        "options": {
            "priority": true,
            "retries": 3,
            "rateLimit": 1024
        }
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.DownloadManager.download", "params": {"url": "http://example.com/file", "options": {"priority": true, "retries": 3, "rateLimit": 1024}}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "downloadId": 1234
    }
}
```

<a id="pause"></a>
## *pause*

Pauses the specified download session, temporarily halting the download process.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Unique identifier of the download to pause |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.DownloadManager.pause",
    "params": {
        "downloadId": 1234
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.DownloadManager.pause", "params": {"downloadId": 1234}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": null
}
```

<a id="progress"></a>
## *progress*

Retrieves the current progress of the specified download session, providing the completion percentage.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Unique identifier of the download |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.percent | integer | Output parameter returning percentage completed |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.DownloadManager.progress",
    "params": {
        "downloadId": 1234
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.DownloadManager.progress", "params": {"downloadId": 1234}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "percent": 50
    }
}
```

<a id="rateLimit"></a>
## *rateLimit*

Sets a maximum bandwidth limit for the specified download session, controlling the rate at which data is downloaded.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Unique identifier of the download |
| params.limit | integer | Maximum bandwidth in bytes per second (0 = unlimited) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.DownloadManager.rateLimit",
    "params": {
        "downloadId": 1234,
        "limit": 1024
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.DownloadManager.rateLimit", "params": {"downloadId": 1234, "limit": 1024}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": null
}
```

<a id="resume"></a>
## *resume*

Resumes a previously paused download session, allowing the download to continue from where it left off.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadId | string | Unique identifier of the download to resume |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.DownloadManager.resume",
    "params": {
        "downloadId": 1234
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.DownloadManager.resume", "params": {"downloadId": 1234}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": null
}
```

<a id="IDownloadManager-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IDownloadManager Interface:

| Event | Description |
| :-------- | :-------- |
| [onAppDownloadStatus](#onAppDownloadStatus) | OnAppDownloadStatus Callback for status changes of app downloads |

<a id="onAppDownloadStatus"></a>
## *onAppDownloadStatus*

Provides detailed information about the current status of the download, including progress and any errors encountered.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.downloadStatus | string | [JSON string] Download status of a queued download request, includes downloadId, fileLocator, failReason (enum) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.DownloadManager.onAppDownloadStatus",
    "params": {
        "downloadStatus": "{\\\"downloadId\\\":\\\"1234\\\",\\\"fileLocator\\\":\\\"http://example.com/file\\\",\\\"failReason\\\":\\\"DOWNLOAD_FAILURE\\\"}"
    }
}
```

