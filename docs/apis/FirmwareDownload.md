<!-- Generated automatically, DO NOT EDIT! -->
<a id="FirmwareDownload_Plugin"></a>
# FirmwareDownload Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/FirmwareDownload/IFirmwareDownload.h)**

A FirmwareDownload plugin for Thunder framework.

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

The `FirmwareDownload` plugin provides an interface for FirmwareDownload.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.FirmwareDownload) |
| classname | string | Class name: *FirmwareDownload* |
| locator | string | Library name: *libWPEFrameworkFirmwareDownload.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the FirmwareDownload plugin:

FirmwareDownload interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDownloadFailureReason](#getDownloadFailureReason) | Gets the last firmware download failure reason. |
| [getDownloadState](#getDownloadState) | Retrieve the current state of the download process. |
| [getDownloadedFirmwareInfo](#getDownloadedFirmwareInfo) | Returns information about firmware downloads. |
| [getFirmwareDownloadPercent](#getFirmwareDownloadPercent) | Gets the current download percentage. |
| [searchFirmware](#searchFirmware) | Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to. |

<a id="getDownloadFailureReason"></a>
## *getDownloadFailureReason*

Gets the last firmware download failure reason.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.failureReason | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.FirmwareDownload.getDownloadFailureReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.FirmwareDownload.getDownloadFailureReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "failureReason": ""
    }
}
```

<a id="getDownloadState"></a>
## *getDownloadState*

Retrieve the current state of the download process.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.downloadState | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.FirmwareDownload.getDownloadState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.FirmwareDownload.getDownloadState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "downloadState": ""
    }
}
```

<a id="getDownloadedFirmwareInfo"></a>
## *getDownloadedFirmwareInfo*

Returns information about firmware downloads.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentFWVersion | string | The current firmware version |
| result.downloadedFWVersion | string | The downloaded firmware version |
| result.downloadedFWLocation | string | The location of the downloaded firmware |
| result.isRebootDeferred | bool | Whether the device should be rebooted |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.FirmwareDownload.getDownloadedFirmwareInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.FirmwareDownload.getDownloadedFirmwareInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "currentFWVersion": "",
        "downloadedFWVersion": "",
        "downloadedFWLocation": "",
        "isRebootDeferred": true
    }
}
```

<a id="getFirmwareDownloadPercent"></a>
## *getFirmwareDownloadPercent*

Gets the current download percentage.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.downloadPercent | integer |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.FirmwareDownload.getFirmwareDownloadPercent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.FirmwareDownload.getFirmwareDownloadPercent"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "downloadPercent": 0
    }
}
```

<a id="searchFirmware"></a>
## *searchFirmware*

Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.FirmwareDownload.searchFirmware"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.FirmwareDownload.searchFirmware"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": null
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the FirmwareDownload plugin:

FirmwareDownload interface events:

| Event | Description |
| :-------- | :-------- |
| [onFirmwareAvailable](#onFirmwareAvailable) | Triggered when the SearchFirmware asynchronous method is invoked |

<a id="onFirmwareAvailable"></a>
## *onFirmwareAvailable*

Triggered when the SearchFirmware asynchronous method is invoked

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.searchStatus | int | Status of the firmware search operation |
| params.serverResponse | string | Response message from the server |
| params.firmwareAvailable | bool | Indicates whether new firmware is available |
| params.firmwareVersion | string | Version string of the available firmware |
| params.rebootImmediately | bool | Indicates whether immediate reboot is required |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.FirmwareDownload.onFirmwareAvailable",
    "params": {
        "searchStatus": 0,
        "serverResponse": "",
        "firmwareAvailable": true,
        "firmwareVersion": "",
        "rebootImmediately": true
    }
}
```
