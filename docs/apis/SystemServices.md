<!-- Generated automatically, DO NOT EDIT! -->
<a id="SystemServices_Plugin"></a>
# SystemServices Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/SystemServices/ISystemServices.h)**

A SystemServices plugin for Thunder framework.

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

The `SystemServices` plugin provides an interface for SystemServices.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.SystemServices) |
| classname | string | Class name: *SystemServices* |
| locator | string | Library name: *libWPEFrameworkSystemServices.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the SystemServices plugin:

SystemServices interface methods:

| Method | Description |
| :-------- | :-------- |
| [abortLogUpload](#abortLogUpload) | Stops background process to upload logs. |
| [getBlocklistFlag](#getBlocklistFlag) | Get block list falg. |
| [getBootTypeInfo](#getBootTypeInfo) | Get the FSR flag from the emmc raw area. |
| [getBuildType](#getBuildType) | Returns build type of the image flashed on the device. |
| [getDeviceInfo](#getDeviceInfo) | Collects device details |
| [getDownloadedFirmwareInfo](#getDownloadedFirmwareInfo) | Returns information about firmware downloads. |
| [getFSRFlag](#getFSRFlag) | Get the FSR flag from the emmc raw area. |
| [getFirmwareDownloadPercent](#getFirmwareDownloadPercent) | Gets the current download percentage. |
| [getFirmwareUpdateInfo](#getFirmwareUpdateInfo) | Checks the firmware update information. |
| [getFirmwareUpdateState](#getFirmwareUpdateState) | Checks the state of the firmware update. |
| [getFriendlyName](#getFriendlyName) | Returns the friendly name set by setFriendlyName API or default value. |
| [getLastFirmwareFailureReason](#getLastFirmwareFailureReason) | Retrieves the last firmware failure reason. |
| [getLastWakeupKeyCode](#getLastWakeupKeyCode) | Returns the last wakeup keycode. |
| [getMacAddresses](#getMacAddresses) | Gets the MAC address of the device. |
| [getMfgSerialNumber](#getMfgSerialNumber) | Gets the Manufacturing Serial Number. |
| [getMigrationStatus](#getMigrationStatus) | set the Migration Status of the device |
| [getNetworkStandbyMode](#getNetworkStandbyMode) | Returns the network standby mode of the device. |
| [getPlatformConfiguration](#getPlatformConfiguration) | Returns the supported features and device/account info |
| [getPowerState](#getPowerState) | Returns the power state of the device. |
| [getPowerStateBeforeReboot](#getPowerStateBeforeReboot) | Returns the power state before reboot. |
| [getRFCConfig](#getRFCConfig) | Returns information that is related to RDK Feature Control (RFC) configurations. |
| [getSerialNumber](#getSerialNumber) | Returns the device serial number. |
| [getSystemVersions](#getSystemVersions) | Returns system version details. |
| [getTerritory](#getTerritory) | Gets the configured system territory and region. |
| [getTimeZoneDST](#getTimeZoneDST) | Gets the available timezones from the system’s time zone database. |
| [getTimeZones](#getTimeZones) | Returns the friendly name set by setFriendlyName API or default value. |
| [getWakeupReason](#getWakeupReason) | Returns the reason for the device coming out of deep sleep. |
| [isOptOutTelemetry](#isOptOutTelemetry) | Checks the telemetry opt-out status. |
| [reboot](#reboot) | Requests that the system performs a reboot of the set-top box. |
| [requestSystemUptime](#requestSystemUptime) | Returns the device uptime. |
| [setBlocklistFlag](#setBlocklistFlag) | To update Blocklist flag. |
| [setBootLoaderSplashScreen](#setBootLoaderSplashScreen) | Install or update the BootLoader Splash Screens. |
| [setDeepSleepTimer](#setDeepSleepTimer) | Sets the deep sleep timeout period. |
| [setFSRFlag](#setFSRFlag) | Set the FSR flag into the emmc raw area. |
| [setFirmwareAutoReboot](#setFirmwareAutoReboot) | Enables or disables the AutoReboot Feature. |
| [setFriendlyName](#setFriendlyName) | Sets the friendly name of device. |
| [setMigrationStatus](#setMigrationStatus) | set the Migration Status of the device. |
| [setMode](#setMode) | Sets the mode of the set-top box for a specific duration before returning to normal mode. |
| [setOptOutTelemetry](#setOptOutTelemetry) | Sets the telemetry opt-out status. |
| [setPowerState](#setPowerState) | Sets the power state of the device. |
| [setTerritory](#setTerritory) | Sets the system territory and region. |
| [setTimeZoneDST](#setTimeZoneDST) | Sets the system time zone. |
| [setWakeupSrcConfiguration](#setWakeupSrcConfiguration) | Sets the wakeup source configuration for the input powerState. |
| [updateFirmware](#updateFirmware) | Initiates a firmware update. |
| [uploadLogsAsync](#uploadLogsAsync) | Starts background process to upload logs. |
| [setNetworkStandbyMode](#setNetworkStandbyMode) | Enables or disables the AutoReboot Feature. |

<a id="abortLogUpload"></a>
## *abortLogUpload*

Stops background process to upload logs.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.SystemServices.abortLogUpload"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.SystemServices.abortLogUpload"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "success": true
    }
}
```

<a id="getBlocklistFlag"></a>
## *getBlocklistFlag*

Get block list falg.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | BlocklistResult |  |
| result.result.error | ErrorInfo | Error Information |
| result.result.error.message | string | Error Message |
| result.result.error.code | string | Error Code |
| result.result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SystemServices.getBlocklistFlag"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SystemServices.getBlocklistFlag"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": {
        "error": {
            "message": "",
            "code": ""
        },
        "success": true
    }
}
```

<a id="getBootTypeInfo"></a>
## *getBootTypeInfo*

Get the FSR flag from the emmc raw area.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.bootType | string | BOOT Type Info |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SystemServices.getBootTypeInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SystemServices.getBootTypeInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "bootType": "",
        "success": true
    }
}
```

<a id="getBuildType"></a>
## *getBuildType*

Returns build type of the image flashed on the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.build_type | string | Image build type |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.SystemServices.getBuildType"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SystemServices.getBuildType"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "build_type": "",
        "success": true
    }
}
```

<a id="getDeviceInfo"></a>
## *getDeviceInfo*

Collects device details

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | IStringIterator | A list of supported device keys |
| params.params[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.deviceInfo | DeviceInfo | Device Information @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |
| result.deviceInfo.make | string | Device manufacturer |
| result.deviceInfo.bluetooth_mac | string | Bluetooth MAC Address |
| result.deviceInfo.boxIP | string | STB IP Address |
| result.deviceInfo.build_type | string | Image build type |
| result.deviceInfo.device_type | string | Device type |
| result.deviceInfo.estb_mac | string | STB MAC Address |
| result.deviceInfo.eth_mac | string | Ethernet MAC Address |
| result.deviceInfo.friendly_id | string | friendly device model name |
| result.deviceInfo.imageVersion | string | Image version |
| result.deviceInfo.version | string | Version Info |
| result.deviceInfo.software_version | string | Software version |
| result.deviceInfo.model_number | string | Device model number |
| result.deviceInfo.wifi_mac | string | WIFI Mac Address |
| result.deviceInfo.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.SystemServices.getDeviceInfo",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.SystemServices.getDeviceInfo", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "make": "",
        "bluetooth_mac": "",
        "boxIP": "",
        "build_type": "",
        "device_type": "",
        "estb_mac": "",
        "eth_mac": "",
        "friendly_id": "",
        "imageVersion": "",
        "version": "",
        "software_version": "",
        "model_number": "",
        "wifi_mac": "",
        "success": true
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
| result.downloadedFirmwareInfo | DownloadedFirmwareInfo |  |
| result.downloadedFirmwareInfo.currentFWVersion | string | The current firmware version |
| result.downloadedFirmwareInfo.downloadedFWVersion | string | The downloaded firmware version |
| result.downloadedFirmwareInfo.downloadedFWLocation | string | The location of the downloaded firmware |
| result.downloadedFirmwareInfo.isRebootDeferred | bool | Whether the device should be rebooted |
| result.downloadedFirmwareInfo.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SystemServices.getDownloadedFirmwareInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.SystemServices.getDownloadedFirmwareInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "currentFWVersion": "",
        "downloadedFWVersion": "",
        "downloadedFWLocation": "",
        "isRebootDeferred": true,
        "success": true
    }
}
```

<a id="getFSRFlag"></a>
## *getFSRFlag*

Get the FSR flag from the emmc raw area.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.fsrFlag | bool | FSR flag |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SystemServices.getFSRFlag"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.SystemServices.getFSRFlag"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "fsrFlag": true,
        "success": true
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
| result.downloadPercent | integer | Current download percentage (0-100) |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SystemServices.getFirmwareDownloadPercent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.SystemServices.getFirmwareDownloadPercent"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": {
        "downloadPercent": 0,
        "success": true
    }
}
```

<a id="getFirmwareUpdateInfo"></a>
## *getFirmwareUpdateInfo*

Checks the firmware update information.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.GUID | string | A unique identifier |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | bool | Whether the event notification succeeded |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SystemServices.getFirmwareUpdateInfo",
    "params": {
        "GUID": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.SystemServices.getFirmwareUpdateInfo", "params": {"GUID": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": {
        "asyncResponse": true,
        "success": true
    }
}
```

<a id="getFirmwareUpdateState"></a>
## *getFirmwareUpdateState*

Checks the state of the firmware update.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.firmwareUpdateState | int | The state (must be one of the following: Uninitialized, Requesting, Downloading, Failed, DownLoad Complete, Validation Complete, Preparing to Reboot) |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SystemServices.getFirmwareUpdateState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.SystemServices.getFirmwareUpdateState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "firmwareUpdateState": 0,
        "success": true
    }
}
```

<a id="getFriendlyName"></a>
## *getFriendlyName*

Returns the friendly name set by setFriendlyName API or default value.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.friendlyName | string | The friendly name of the device which used to display on the client device list |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.SystemServices.getFriendlyName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.SystemServices.getFriendlyName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "friendlyName": "",
        "success": true
    }
}
```

<a id="getLastFirmwareFailureReason"></a>
## *getLastFirmwareFailureReason*

Retrieves the last firmware failure reason.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.failReason | string | The reason the failure occurred |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.SystemServices.getLastFirmwareFailureReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.SystemServices.getLastFirmwareFailureReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "failReason": "",
        "success": true
    }
}
```

<a id="getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode*

Returns the last wakeup keycode.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupKeyCode | string | The last wakeup keycode |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.SystemServices.getLastWakeupKeyCode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.SystemServices.getLastWakeupKeyCode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": {
        "wakeupKeyCode": "",
        "success": true
    }
}
```

<a id="getMacAddresses"></a>
## *getMacAddresses*

Gets the MAC address of the device.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.GUID | string | A unique identifier |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | bool | Whether the event notification succeeded |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.SystemServices.getMacAddresses",
    "params": {
        "GUID": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.SystemServices.getMacAddresses", "params": {"GUID": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": {
        "asyncResponse": true,
        "success": true
    }
}
```

<a id="getMfgSerialNumber"></a>
## *getMfgSerialNumber*

Gets the Manufacturing Serial Number.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mfgSerialNumber | string | Manufacturing Serial Number |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.SystemServices.getMfgSerialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.SystemServices.getMfgSerialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": {
        "mfgSerialNumber": "",
        "success": true
    }
}
```

<a id="getMigrationStatus"></a>
## *getMigrationStatus*

set the Migration Status of the device

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.MigrationStatus | string | Migration Status |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.SystemServices.getMigrationStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.SystemServices.getMigrationStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "result": {
        "MigrationStatus": "",
        "success": true
    }
}
```

<a id="getNetworkStandbyMode"></a>
## *getNetworkStandbyMode*

Returns the network standby mode of the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.nwStandby | bool | Whether WakeOnLAN and WakeOnWLAN is supported (true); otherwise, false |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.SystemServices.getNetworkStandbyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.SystemServices.getNetworkStandbyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "result": {
        "nwStandby": true,
        "success": true
    }
}
```

<a id="getPlatformConfiguration"></a>
## *getPlatformConfiguration*

Returns the supported features and device/account info

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.platformConfig | PlatformConfig | Platform Configuration Details @retval ErrorCode::ERROR_NONE: Indicates success @retval ErrorCode::ERROR_GENERAL: Indicates failure |
| result.platformConfig.AccountInfo | AccountInfoDetails | AccountInfo Details |
| result.platformConfig.AccountInfo.accountId | string | Account Id |
| result.platformConfig.AccountInfo.x1DeviceId | string | X1 Device Id |
| result.platformConfig.AccountInfo.XCALSessionTokenAvailable | bool | XCAL Session Token Available |
| result.platformConfig.AccountInfo.experience | string | Experience |
| result.platformConfig.AccountInfo.deviceMACAddress | string | Device MAC Address |
| result.platformConfig.AccountInfo.firmwareUpdateDisabled | bool | Whether the firmwareUpdate Disabled |
| result.platformConfig.DeviceInfo | DeviceInfoDetails | DeviceInfo Details |
| result.platformConfig.DeviceInfo.quirks | string | The list of installed “quirks” |
| result.platformConfig.DeviceInfo.mimeTypeExclusions | MIMETypeExclusions | mime Type Exclusions |
| result.platformConfig.DeviceInfo.features | Features | features |
| result.platformConfig.DeviceInfo.mimeTypes | string | mime Types |
| result.platformConfig.DeviceInfo.model | string |  |
| result.platformConfig.DeviceInfo.deviceType | string |  |
| result.platformConfig.DeviceInfo.supportsTrueSD | bool |  |
| result.platformConfig.DeviceInfo.webBrowser | WebBrowserInfo |  |
| result.platformConfig.DeviceInfo.webBrowser.browserType | string | Browser Type |
| result.platformConfig.DeviceInfo.webBrowser.version | string | Version |
| result.platformConfig.DeviceInfo.webBrowser.userAgent | string | User Agent |
| result.platformConfig.DeviceInfo.HdrCapability | string | e.g. HDR10,Dolby Vision,Technicolor Prime |
| result.platformConfig.DeviceInfo.canMixPCMWithSurround | bool |  |
| result.platformConfig.DeviceInfo.publicIP | string | Public IP |
| result.platformConfig.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.SystemServices.getPlatformConfiguration"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.SystemServices.getPlatformConfiguration"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "AccountInfo": {
            "accountId": "",
            "x1DeviceId": "",
            "XCALSessionTokenAvailable": true,
            "experience": "",
            "deviceMACAddress": "",
            "firmwareUpdateDisabled": true
        },
        "DeviceInfo": {
            "quirks": "",
            "mimeTypeExclusions": {},
            "features": {},
            "mimeTypes": "",
            "model": "",
            "deviceType": "",
            "supportsTrueSD": true,
            "webBrowser": {
                "browserType": "",
                "version": "",
                "userAgent": ""
            },
            "HdrCapability": "",
            "canMixPCMWithSurround": true,
            "publicIP": ""
        },
        "success": true
    }
}
```

<a id="getPowerState"></a>
## *getPowerState*

Returns the power state of the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerState | string | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.SystemServices.getPowerState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.SystemServices.getPowerState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "powerState": "",
        "success": true
    }
}
```

<a id="getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot*

Returns the power state before reboot.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | The power state |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.SystemServices.getPowerStateBeforeReboot"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.SystemServices.getPowerStateBeforeReboot"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "result": {
        "state": "",
        "success": true
    }
}
```

<a id="getRFCConfig"></a>
## *getRFCConfig*

Returns information that is related to RDK Feature Control (RFC) configurations.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rfcList | IStringIterator | A list of RFC properties to query |
| params.rfcList[#] | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.RFCConfig | IStringIterator | A list of specified RFC properties |
| result.RFCConfig[#] | string |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.SystemServices.getRFCConfig",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.SystemServices.getRFCConfig", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "result": {
        "RFCConfig": [
            ""
        ],
        "success": true
    }
}
```

<a id="getSerialNumber"></a>
## *getSerialNumber*

Returns the device serial number.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.serialNumber | string | The serial number |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.SystemServices.getSerialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.SystemServices.getSerialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "serialNumber": "",
        "success": true
    }
}
```

<a id="getSystemVersions"></a>
## *getSystemVersions*

Returns system version details.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.systemVersionsInfo | SystemVersionsInfo |  |
| result.systemVersionsInfo.stbVersion | string | The STB version |
| result.systemVersionsInfo.receiverVersion | string | The receiver version |
| result.systemVersionsInfo.stbTimestamp | string | The STB timestamp |
| result.systemVersionsInfo.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.SystemServices.getSystemVersions"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.SystemServices.getSystemVersions"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "stbVersion": "",
        "receiverVersion": "",
        "stbTimestamp": "",
        "success": true
    }
}
```

<a id="getTerritory"></a>
## *getTerritory*

Gets the configured system territory and region.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.territory | string | territory name |
| result.region | string | region name |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.SystemServices.getTerritory"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.SystemServices.getTerritory"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "territory": "",
        "region": "",
        "success": true
    }
}
```

<a id="getTimeZoneDST"></a>
## *getTimeZoneDST*

Gets the available timezones from the system’s time zone database.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.timeZone | string | The timezone |
| result.accuracy | string | The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL) |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.SystemServices.getTimeZoneDST"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.SystemServices.getTimeZoneDST"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "timeZone": "",
        "accuracy": "",
        "success": true
    }
}
```

<a id="getTimeZones"></a>
## *getTimeZones*

Returns the friendly name set by setFriendlyName API or default value.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.timeZoneInfo | TimeZoneInfo |  |
| result.timeZoneInfo.zoneinfo | Zoneinfo | Error Information |
| result.timeZoneInfo.zoneinfo.America | AmericaInfo | Error Information |
| result.timeZoneInfo.zoneinfo.America.New_York | string | Error Information |
| result.timeZoneInfo.zoneinfo.America.Los_Angeles | string | Error Information |
| result.timeZoneInfo.zoneinfo.Europe | EuropeInfo | Error Information |
| result.timeZoneInfo.zoneinfo.Europe.London | string | Error Information |
| result.timeZoneInfo.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.SystemServices.getTimeZones"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.SystemServices.getTimeZones"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "zoneinfo": {
            "America": {
                "New_York": "",
                "Los_Angeles": ""
            },
            "Europe": {
                "London": ""
            }
        },
        "success": true
    }
}
```

<a id="getWakeupReason"></a>
## *getWakeupReason*

Returns the reason for the device coming out of deep sleep.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.WakeupReason | string | The reason |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.SystemServices.getWakeupReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.SystemServices.getWakeupReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "WakeupReason": "",
        "success": true
    }
}
```

<a id="isOptOutTelemetry"></a>
## *isOptOutTelemetry*

Checks the telemetry opt-out status.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.Opt-Out | bool | true for opt-out, otherwise false |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.SystemServices.isOptOutTelemetry"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.SystemServices.isOptOutTelemetry"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "result": {
        "Opt-Out": true,
        "success": true
    }
}
```

<a id="reboot"></a>
## *reboot*

Requests that the system performs a reboot of the set-top box.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rebootReason | string | The reboot reason |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.IARM_Bus_Call_STATUS | int | IARM BUS status |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.SystemServices.reboot",
    "params": {
        "rebootReason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.SystemServices.reboot", "params": {"rebootReason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": {
        "IARM_Bus_Call_STATUS": 0,
        "success": true
    }
}
```

<a id="requestSystemUptime"></a>
## *requestSystemUptime*

Returns the device uptime.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.systemUptime | string | The uptime, in seconds, of the device |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.SystemServices.requestSystemUptime"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.SystemServices.requestSystemUptime"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": {
        "systemUptime": "",
        "success": true
    }
}
```

<a id="setBlocklistFlag"></a>
## *setBlocklistFlag*

To update Blocklist flag.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blocklist | bool | Blocklist flag |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | BlocklistResult |  |
| result.result.error | ErrorInfo | Error Information |
| result.result.error.message | string | Error Message |
| result.result.error.code | string | Error Code |
| result.result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.SystemServices.setBlocklistFlag",
    "params": {
        "blocklist": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.SystemServices.setBlocklistFlag", "params": {"blocklist": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": {
        "error": {
            "message": "",
            "code": ""
        },
        "success": true
    }
}
```

<a id="setBootLoaderSplashScreen"></a>
## *setBootLoaderSplashScreen*

Install or update the BootLoader Splash Screens.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.path | string | Path to the pre-downloaded splash screen file location. Full path with file name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.error | ErrorInfo | Error Information |
| result.error.message | string | Error Message |
| result.error.code | string | Error Code |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.SystemServices.setBootLoaderSplashScreen",
    "params": {
        "path": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.SystemServices.setBootLoaderSplashScreen", "params": {"path": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": {
        "error": {
            "message": "",
            "code": ""
        },
        "success": true
    }
}
```

<a id="setDeepSleepTimer"></a>
## *setDeepSleepTimer*

Sets the deep sleep timeout period.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.seconds | int | The deep sleep timeout in seconds |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.SystemServices.setDeepSleepTimer",
    "params": {
        "seconds": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.SystemServices.setDeepSleepTimer", "params": {"seconds": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": {
        "success": true
    }
}
```

<a id="setFSRFlag"></a>
## *setFSRFlag*

Set the FSR flag into the emmc raw area.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fsrFlag | bool | FSR flag |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.SystemServices.setFSRFlag",
    "params": {
        "fsrFlag": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.SystemServices.setFSRFlag", "params": {"fsrFlag": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": {
        "success": true
    }
}
```

<a id="setFirmwareAutoReboot"></a>
## *setFirmwareAutoReboot*

Enables or disables the AutoReboot Feature.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | true to enable Autoreboot or false to disable |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.SystemServices.setFirmwareAutoReboot",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.SystemServices.setFirmwareAutoReboot", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": {
        "success": true
    }
}
```

<a id="setFriendlyName"></a>
## *setFriendlyName*

Sets the friendly name of device.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyName | string | The friendly name of the device which used to display on the client device list |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.SystemServices.setFriendlyName",
    "params": {
        "friendlyName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.SystemServices.setFriendlyName", "params": {"friendlyName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "result": {
        "success": true
    }
}
```

<a id="setMigrationStatus"></a>
## *setMigrationStatus*

set the Migration Status of the device.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | bool | Migration Status |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.SystemServices.setMigrationStatus",
    "params": {
        "status": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.SystemServices.setMigrationStatus", "params": {"status": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": {
        "success": true
    }
}
```

<a id="setMode"></a>
## *setMode*

Sets the mode of the set-top box for a specific duration before returning to normal mode.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.modeinfo | ModeInfo | The mode information |
| params.modeinfo.mode | string | The mode (must be one of the following: NORMAL, EAS, WAREHOUSE) |
| params.modeinfo.duration | int | The duration |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "method": "org.rdk.SystemServices.setMode",
    "params": {
        "mode": "",
        "duration": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.SystemServices.setMode", "params": {"mode": "", "duration": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": {
        "success": true
    }
}
```

<a id="setOptOutTelemetry"></a>
## *setOptOutTelemetry*

Sets the telemetry opt-out status.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.Opt-Out | bool | true for opt-out, otherwise false |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "method": "org.rdk.SystemServices.setOptOutTelemetry",
    "params": {
        "Opt-Out": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.SystemServices.setOptOutTelemetry", "params": {"Opt-Out": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": {
        "success": true
    }
}
```

<a id="setPowerState"></a>
## *setPowerState*

Sets the power state of the device.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.standbyReason | string | The reason for a standby state |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.SystemServices.setPowerState",
    "params": {
        "powerState": "",
        "standbyReason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.SystemServices.setPowerState", "params": {"powerState": "", "standbyReason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": {
        "success": true
    }
}
```

<a id="setTerritory"></a>
## *setTerritory*

Sets the system territory and region.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.territory | string | territory name |
| params.region | string | region name |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.message | string | Error Message |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.SystemServices.setTerritory",
    "params": {
        "territory": "",
        "region": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 40, "method": "org.rdk.SystemServices.setTerritory", "params": {"territory": "", "region": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "result": {
        "error": {
            "message": ""
        },
        "success": true
    }
}
```

<a id="setTimeZoneDST"></a>
## *setTimeZoneDST*

Sets the system time zone.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.timeZone | string | The timezone |
| params.accuracy | string | The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.SystemServices.setTimeZoneDST",
    "params": {
        "timeZone": "",
        "accuracy": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 41, "method": "org.rdk.SystemServices.setTimeZoneDST", "params": {"timeZone": "", "accuracy": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "result": {
        "success": true
    }
}
```

<a id="setWakeupSrcConfiguration"></a>
## *setWakeupSrcConfiguration*

Sets the wakeup source configuration for the input powerState.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.wakeupSources | ISystemServicesWakeupSourcesIterator | Array of Key value pair with wake up sources and its configurations |
| params.wakeupSources[#].WAKEUPSRC_VOICE | bool |  |
| params.wakeupSources[#].WAKEUPSRC_PRESENCE_DETECTION | bool |  |
| params.wakeupSources[#].WAKEUPSRC_BLUETOOTH | bool |  |
| params.wakeupSources[#].WAKEUPSRC_WIFI | bool |  |
| params.wakeupSources[#].WAKEUPSRC_IR | bool |  |
| params.wakeupSources[#].WAKEUPSRC_POWER_KEY | bool |  |
| params.wakeupSources[#].WAKEUPSRC_CEC | bool |  |
| params.wakeupSources[#].WAKEUPSRC_LAN | bool |  |
| params.wakeupSources[#].WAKEUPSRC_TIMER | bool |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.SystemServices.setWakeupSrcConfiguration",
    "params": {
        "powerState": "",
        "wakeupSources": [
            {
                "WAKEUPSRC_VOICE": true,
                "WAKEUPSRC_PRESENCE_DETECTION": true,
                "WAKEUPSRC_BLUETOOTH": true,
                "WAKEUPSRC_WIFI": true,
                "WAKEUPSRC_IR": true,
                "WAKEUPSRC_POWER_KEY": true,
                "WAKEUPSRC_CEC": true,
                "WAKEUPSRC_LAN": true,
                "WAKEUPSRC_TIMER": true
            }
        ]
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 42, "method": "org.rdk.SystemServices.setWakeupSrcConfiguration", "params": {"powerState": "", "wakeupSources": [{"WAKEUPSRC_VOICE": true, "WAKEUPSRC_PRESENCE_DETECTION": true, "WAKEUPSRC_BLUETOOTH": true, "WAKEUPSRC_WIFI": true, "WAKEUPSRC_IR": true, "WAKEUPSRC_POWER_KEY": true, "WAKEUPSRC_CEC": true, "WAKEUPSRC_LAN": true, "WAKEUPSRC_TIMER": true}]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a id="updateFirmware"></a>
## *updateFirmware*

Initiates a firmware update.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.SystemServices.updateFirmware"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 43, "method": "org.rdk.SystemServices.updateFirmware"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "result": {
        "success": true
    }
}
```

<a id="uploadLogsAsync"></a>
## *uploadLogsAsync*

Starts background process to upload logs.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "method": "org.rdk.SystemServices.uploadLogsAsync"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 44, "method": "org.rdk.SystemServices.uploadLogsAsync"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "result": {
        "success": true
    }
}
```

<a id="setNetworkStandbyMode"></a>
## *setNetworkStandbyMode*

Enables or disables the AutoReboot Feature.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nwStandby | bool | Whether WakeOnLAN and WakeOnWLAN is supported (true); otherwise, false |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | Whether the request succeeded |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "method": "org.rdk.SystemServices.setNetworkStandbyMode",
    "params": {
        "nwStandby": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 45, "method": "org.rdk.SystemServices.setNetworkStandbyMode", "params": {"nwStandby": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "result": {
        "success": true
    }
}
```



<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the SystemServices plugin:

SystemServices interface events:

| Event | Description |
| :-------- | :-------- |
| [onFirmwareUpdateInfoReceived](#onFirmwareUpdateInfoReceived) | Triggered when the getFirmwareUpdateInfo asynchronous method is invoked. |
| [onLogUpload](#onLogUpload) | Triggered when logs upload process is done or stopped. |
| [OnMacAddressesRetreived](#OnMacAddressesRetreived) | Triggered when the getMacAddresses asynchronous method is invoked. |
| [onRebootRequest](#onRebootRequest) | Triggers when a device reboot request is made |
| [onSystemModeChanged](#onSystemModeChanged) | Triggers when the system mode is changed successfully. |
| [onSystemPowerStateChanged](#onSystemPowerStateChanged) | Triggered when the power manager detects a device power state change. |
| [onTerritoryChanged](#onTerritoryChanged) | Triggered when the device territory changed. |
| [onTimeZoneDSTChanged](#onTimeZoneDSTChanged) | Triggered when device time zone changed. |

<a id="onFirmwareUpdateInfoReceived"></a>
## *onFirmwareUpdateInfoReceived*

Triggered when the getFirmwareUpdateInfo asynchronous method is invoked.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareUpdateInfo | FirmwareUpdateInfo |  |
| params.firmwareUpdateInfo.status | int | The firmware update status |
| params.firmwareUpdateInfo.responseString | string | A custom response |
| params.firmwareUpdateInfo.firmwareUpdateVersion | string | The next firmware update version |
| params.firmwareUpdateInfo.rebootImmediately | bool | The value true indicates that the device has to be rebooted immediately or false otherwise |
| params.firmwareUpdateInfo.updateAvailable | bool | The value false indicates that there is no update available |
| params.firmwareUpdateInfo.updateAvailableEnum | int | The update available details (must be one of the following: 0, 1, 2, 3) |
| params.firmwareUpdateInfo.success | bool | Whether the request succeeded |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 46,
    "method": "org.rdk.SystemServices.onFirmwareUpdateInfoReceived",
    "params": {
        "status": 0,
        "responseString": "",
        "firmwareUpdateVersion": "",
        "rebootImmediately": true,
        "updateAvailable": true,
        "updateAvailableEnum": 0,
        "success": true
    }
}
```

<a id="onLogUpload"></a>
## *onLogUpload*

Triggered when logs upload process is done or stopped.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logUploadStatus | string | Upload status (must be one of the following: UPLOAD_SUCCESS, UPLOAD_FAILURE, UPLOAD_ABORTED) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 47,
    "method": "org.rdk.SystemServices.onLogUpload",
    "params": {
        "logUploadStatus": ""
    }
}
```

<a id="onMacAddressesRetreived"></a>
## *onMacAddressesRetreived*

Triggered when the getMacAddresses asynchronous method is invoked.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.macAddressesInfo | MacAddressesInfo |  |
| params.macAddressesInfo.ecm_mac | string | The embedded cable modem MAC address |
| params.macAddressesInfo.estb_mac | string | The embedded set-top box MAC address |
| params.macAddressesInfo.moca_mac | string | The MOCA MAC address |
| params.macAddressesInfo.eth_mac | string | The Ethernet MAC address |
| params.macAddressesInfo.wifi_mac | string | The Wifi MAC address |
| params.macAddressesInfo.bluetooth_mac | string | The Bluetooth MAC address |
| params.macAddressesInfo.rf4ce_mac | string | The Rf4ce MAC address |
| params.macAddressesInfo.info | string | Additional information (only if any of the above data is missing) |
| params.macAddressesInfo.success | bool | Whether the request succeeded |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 48,
    "method": "org.rdk.SystemServices.onMacAddressesRetreived",
    "params": {
        "ecm_mac": "",
        "estb_mac": "",
        "moca_mac": "",
        "eth_mac": "",
        "wifi_mac": "",
        "bluetooth_mac": "",
        "rf4ce_mac": "",
        "info": "",
        "success": true
    }
}
```

<a id="onRebootRequest"></a>
## *onRebootRequest*

Triggers when a device reboot request is made

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestedApp | string | The source of the reboot |
| params.rebootReason | string | The reboot reason |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 49,
    "method": "org.rdk.SystemServices.onRebootRequest",
    "params": {
        "requestedApp": "",
        "rebootReason": ""
    }
}
```

<a id="onSystemModeChanged"></a>
## *onSystemModeChanged*

Triggers when the system mode is changed successfully.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | string | The mode (must be one of the following: NORMAL, EAS, WAREHOUSE) |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 50,
    "method": "org.rdk.SystemServices.onSystemModeChanged",
    "params": {
        "mode": ""
    }
}
```

<a id="onSystemPowerStateChanged"></a>
## *onSystemPowerStateChanged*

Triggered when the power manager detects a device power state change.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.currentPowerState | string | The current power state |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 51,
    "method": "org.rdk.SystemServices.onSystemPowerStateChanged",
    "params": {
        "powerState": "",
        "currentPowerState": ""
    }
}
```

<a id="onTerritoryChanged"></a>
## *onTerritoryChanged*

Triggered when the device territory changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.territoryChangedInfo | TerritoryChangedInfo |  |
| params.territoryChangedInfo.oldTerritory | string | old territory |
| params.territoryChangedInfo.newTerritory | string | new territory |
| params.territoryChangedInfo.oldRegion | string | old region |
| params.territoryChangedInfo.newRegion | string | new region |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 52,
    "method": "org.rdk.SystemServices.onTerritoryChanged",
    "params": {
        "oldTerritory": "",
        "newTerritory": "",
        "oldRegion": "",
        "newRegion": ""
    }
}
```

<a id="onTimeZoneDSTChanged"></a>
## *onTimeZoneDSTChanged*

Triggered when device time zone changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.timeZoneDSTChangedInfo | TimeZoneDSTChangedInfo |  |
| params.timeZoneDSTChangedInfo.oldTimeZone | string | old time zone |
| params.timeZoneDSTChangedInfo.newTimeZone | string | new time zone |
| params.timeZoneDSTChangedInfo.oldAccuracy | string | old time zone accuracy |
| params.timeZoneDSTChangedInfo.newAccuracy | string | new time zone accuracy |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 53,
    "method": "org.rdk.SystemServices.onTimeZoneDSTChanged",
    "params": {
        "oldTimeZone": "",
        "newTimeZone": "",
        "oldAccuracy": "",
        "newAccuracy": ""
    }
}
```
