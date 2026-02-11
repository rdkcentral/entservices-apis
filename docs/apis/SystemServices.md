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
| [clearLastDeepSleepReason](#clearLastDeepSleepReason) | Clears the last deep sleep reason |
| [deletePersistentPath](#deletePersistentPath) | Deletes persistent path associated with a callsign. |
| [enableMoca](#enableMoca) | Enables (or disables) Moca support for the platform. |
| [enableXREConnectionRetention](#enableXREConnectionRetention) | Enables (or disables) XRE Connection Retention option. |
| [fireFirmwarePendingReboot](#fireFirmwarePendingReboot) | Notifies the device about a pending reboot. |
| [getAvailableStandbyModes](#getAvailableStandbyModes) | Queries the available standby modes. |
| [getBlocklistFlag](#getBlocklistFlag) | Get block list falg. |
| [getBootTypeInfo](#getBootTypeInfo) | Get the FSR flag from the emmc raw area. |
| [getBuildType](#getBuildType) | Returns build type of the image flashed on the device. |
| [getCoreTemperature](#getCoreTemperature) | Returns the core temperature of the device. |
| [getDeviceInfo](#getDeviceInfo) | Collects device details |
| [getDownloadedFirmwareInfo](#getDownloadedFirmwareInfo) | Returns information about firmware downloads. |
| [getFSRFlag](#getFSRFlag) | Get the FSR flag from the emmc raw area. |
| [getFirmwareDownloadPercent](#getFirmwareDownloadPercent) | Gets the current download percentage. |
| [getFirmwareUpdateInfo](#getFirmwareUpdateInfo) | Checks the firmware update information. |
| [getFirmwareUpdateState](#getFirmwareUpdateState) | Checks the state of the firmware update. |
| [getFriendlyName](#getFriendlyName) | Returns the friendly name set by setFriendlyName API or default value. |
| [getLastDeepSleepReason](#getLastDeepSleepReason) | Retrieves the last deep sleep reason. |
| [getLastFirmwareFailureReason](#getLastFirmwareFailureReason) | Retrieves the last firmware failure reason. |
| [getLastWakeupKeyCode](#getLastWakeupKeyCode) | Returns the last wakeup keycode. |
| [getMacAddresses](#getMacAddresses) | Gets the MAC address of the device. |
| [getMfgSerialNumber](#getMfgSerialNumber) | Gets the Manufacturing Serial Number. |
| [getMigrationStatus](#getMigrationStatus) | set the Migration Status of the device |
| [getMode](#getMode) | Returns the currently set mode information. |
| [getNetworkStandbyMode](#getNetworkStandbyMode) | Returns the network standby mode of the device. |
| [getOvertempGraceInterval](#getOvertempGraceInterval) | Returns the over-temperature grace interval value. |
| [getPowerState](#getPowerState) | Returns the power state of the device. |
| [getPowerStateBeforeReboot](#getPowerStateBeforeReboot) | Returns the power state before reboot. |
| [getPowerStateIsManagedByDevice](#getPowerStateIsManagedByDevice) | Checks whether the power state is managed by the device. |
| [getPreferredStandbyMode](#getPreferredStandbyMode) | Returns the preferred standby mode. |
| [getPreviousRebootInfo](#getPreviousRebootInfo) | Returns the preferred standby mode. |
| [getPreviousRebootInfo2](#getPreviousRebootInfo2) | Returns detailed information about a reboot. |
| [getPreviousRebootReason](#getPreviousRebootReason) | Returns the last reboot reason. |
| [getPrivacyMode](#getPrivacyMode) | Getting Privacy Mode. |
| [getRFCConfig](#getRFCConfig) | Returns information that is related to RDK Feature Control (RFC) configurations. |
| [getSerialNumber](#getSerialNumber) | Returns the device serial number. |
| [getStateInfo](#getStateInfo) | Queries device state information of various properties. |
| [getStoreDemoLink](#getStoreDemoLink) | Returns the store demo video link. |
| [getSystemVersions](#getSystemVersions) | Returns system version details. |
| [getTemperatureThresholds](#getTemperatureThresholds) | Returns temperature threshold values. |
| [getTerritory](#getTerritory) | Gets the configured system territory and region. |
| [getThunderStartReason](#getThunderStartReason) | Returns the Thunder start reason. |
| [getTimeZoneDST](#getTimeZoneDST) | Gets the available timezones from the system’s time zone database. |
| [getTimeZones](#getTimeZones) | Returns the friendly name set by setFriendlyName API or default value. |
| [getWakeupReason](#getWakeupReason) | Returns the reason for the device coming out of deep sleep. |
| [getWakeupSrcConfiguration](#getWakeupSrcConfiguration) | Returns all the supported wakeup configurations and powerState. |
| [getXconfParams](#getXconfParams) | Returns XCONF configuration parameters for the device. |
| [isOptOutTelemetry](#isOptOutTelemetry) | Checks the telemetry opt-out status. |
| [queryMocaStatus](#queryMocaStatus) | Checks whether MOCA is enabled. |
| [reboot](#reboot) | Requests that the system performs a reboot of the set-top box. |
| [requestSystemUptime](#requestSystemUptime) | Returns the device uptime. |
| [setBlocklistFlag](#setBlocklistFlag) | To update Blocklist flag. |
| [setBootLoaderPattern](#setBootLoaderPattern) | Sets the boot loader pattern mode in MFR. |
| [setBootLoaderSplashScreen](#setBootLoaderSplashScreen) | Install or update the BootLoader Splash Screens. |
| [setDeepSleepTimer](#setDeepSleepTimer) | Sets the deep sleep timeout period. |
| [setFSRFlag](#setFSRFlag) | Set the FSR flag into the emmc raw area. |
| [setFirmwareAutoReboot](#setFirmwareAutoReboot) | Enables or disables the AutoReboot Feature. |
| [setFirmwareRebootDelay](#setFirmwareRebootDelay) | Delays the firmware reboot. |
| [setFriendlyName](#setFriendlyName) | Sets the friendly name of device. |
| [setMigrationStatus](#setMigrationStatus) | set the Migration Status of the device. |
| [setMode](#setMode) | Sets the mode of the set-top box for a specific duration before returning to normal mode. |
| [setOptOutTelemetry](#setOptOutTelemetry) | Sets the telemetry opt-out status. |
| [setOvertempGraceInterval](#setOvertempGraceInterval) | Sets the over-temperature grace interval value. Not supported on all devices. |
| [setPowerState](#setPowerState) | Sets the power state of the device. |
| [setPreferredStandbyMode](#setPreferredStandbyMode) | Sets and persists the preferred standby mode. |
| [setPrivacyMode](#setPrivacyMode) | Setting Privacy Mode. |
| [setTemperatureThresholds](#setTemperatureThresholds) | Sets the temperature threshold values. |
| [setTerritory](#setTerritory) | Sets the system territory and region. |
| [setTimeZoneDST](#setTimeZoneDST) | Sets the system time zone. |
| [setWakeupSrcConfiguration](#setWakeupSrcConfiguration) | Sets the wakeup source configuration for the input powerState. |
| [updateFirmware](#updateFirmware) | Initiates a firmware update. |
| [uploadLogsAsync](#uploadLogsAsync) | Starts background process to upload logs. |

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
| result.success | bool | bool |

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

<a id="clearLastDeepSleepReason"></a>
## *clearLastDeepSleepReason*

Clears the last deep sleep reason

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "method": "org.rdk.SystemServices.clearLastDeepSleepReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.SystemServices.clearLastDeepSleepReason"}' http://127.0.0.1:9998/jsonrpc
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

<a id="deletePersistentPath"></a>
## *deletePersistentPath*

Deletes persistent path associated with a callsign.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.callsign | string | string |
| params.type | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.SystemServices.deletePersistentPath",
    "params": {
        "callsign": "",
        "type": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.SystemServices.deletePersistentPath", "params": {"callsign": "", "type": ""}}' http://127.0.0.1:9998/jsonrpc
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

<a id="enableMoca"></a>
## *enableMoca*

Enables (or disables) Moca support for the platform.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.value | bool | bool |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.SystemServices.enableMoca",
    "params": {
        "value": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.SystemServices.enableMoca", "params": {"value": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "success": true
    }
}
```

<a id="enableXREConnectionRetention"></a>
## *enableXREConnectionRetention*

Enables (or disables) XRE Connection Retention option.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | bool | bool |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.SystemServices.enableXREConnectionRetention",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.SystemServices.enableXREConnectionRetention", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "success": true
    }
}
```

<a id="fireFirmwarePendingReboot"></a>
## *fireFirmwarePendingReboot*

Notifies the device about a pending reboot.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.SystemServices.fireFirmwarePendingReboot"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.SystemServices.fireFirmwarePendingReboot"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "success": true
    }
}
```

<a id="getAvailableStandbyModes"></a>
## *getAvailableStandbyModes*

Queries the available standby modes.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.supportedStandbyModes | IStringIterator | array of supported standby modes |
| result.supportedStandbyModes[#] | string |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.SystemServices.getAvailableStandbyModes"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.SystemServices.getAvailableStandbyModes"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "supportedStandbyModes": [
            ""
        ],
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
| result.result.error | ErrorInfo |  |
| result.result.error.message | string |  |
| result.result.error.code | string |  |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.SystemServices.getBlocklistFlag"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.SystemServices.getBlocklistFlag"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
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
| result.bootType | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.SystemServices.getBootTypeInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.SystemServices.getBootTypeInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
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
| result.build_type | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.SystemServices.getBuildType"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.SystemServices.getBuildType"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": {
        "build_type": "",
        "success": true
    }
}
```

<a id="getCoreTemperature"></a>
## *getCoreTemperature*

Returns the core temperature of the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.temperature | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.SystemServices.getCoreTemperature"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.SystemServices.getCoreTemperature"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": {
        "temperature": "",
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
| result.estb_mac | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.SystemServices.getDeviceInfo",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.SystemServices.getDeviceInfo", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": {
        "estb_mac": "",
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
| result.downloadedFirmwareInfo.currentFWVersion | string |  |
| result.downloadedFirmwareInfo.downloadedFWVersion | string |  |
| result.downloadedFirmwareInfo.downloadedFWLocation | string |  |
| result.downloadedFirmwareInfo.isRebootDeferred | bool |  |
| result.downloadedFirmwareInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.SystemServices.getDownloadedFirmwareInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.SystemServices.getDownloadedFirmwareInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
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
| result.fsrFlag | bool | bool |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.SystemServices.getFSRFlag"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.SystemServices.getFSRFlag"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
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
| result.downloadPercent | int | int |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.SystemServices.getFirmwareDownloadPercent"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.SystemServices.getFirmwareDownloadPercent"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
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
| params.GUID | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | bool | bool |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.SystemServices.getFirmwareUpdateInfo",
    "params": {
        "GUID": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 15, "method": "org.rdk.SystemServices.getFirmwareUpdateInfo", "params": {"GUID": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 15,
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
| result.firmwareUpdateState | int | int |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.SystemServices.getFirmwareUpdateState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 16, "method": "org.rdk.SystemServices.getFirmwareUpdateState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 16,
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
| result.friendlyName | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.SystemServices.getFriendlyName"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 17, "method": "org.rdk.SystemServices.getFriendlyName"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "result": {
        "friendlyName": "",
        "success": true
    }
}
```

<a id="getLastDeepSleepReason"></a>
## *getLastDeepSleepReason*

Retrieves the last deep sleep reason.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.reason | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.SystemServices.getLastDeepSleepReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 18, "method": "org.rdk.SystemServices.getLastDeepSleepReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "result": {
        "reason": "",
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
| result.failReason | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.SystemServices.getLastFirmwareFailureReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 19, "method": "org.rdk.SystemServices.getLastFirmwareFailureReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 19,
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
| result.wakeupKeyCode | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.SystemServices.getLastWakeupKeyCode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 20, "method": "org.rdk.SystemServices.getLastWakeupKeyCode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 20,
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
| params.GUID | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | bool | bool |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.SystemServices.getMacAddresses",
    "params": {
        "GUID": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.SystemServices.getMacAddresses", "params": {"GUID": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
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
| result.mfgSerialNumber | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.SystemServices.getMfgSerialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.SystemServices.getMfgSerialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
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
| result.MigrationStatus | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.SystemServices.getMigrationStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.SystemServices.getMigrationStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "MigrationStatus": "",
        "success": true
    }
}
```

<a id="getMode"></a>
## *getMode*

Returns the currently set mode information.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.systemMode | SystemModeInfo |  |
| result.systemMode.modeinfo | ModeInfo |  |
| result.systemMode.modeinfo.mode | string |  |
| result.systemMode.modeinfo.duration | int |  |
| result.systemMode.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.SystemServices.getMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.SystemServices.getMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": {
        "modeinfo": {
            "mode": "",
            "duration": 0
        },
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
| result.nwStandby | bool | bool |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.SystemServices.getNetworkStandbyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.SystemServices.getNetworkStandbyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": {
        "nwStandby": true,
        "success": true
    }
}
```

<a id="getOvertempGraceInterval"></a>
## *getOvertempGraceInterval*

Returns the over-temperature grace interval value.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.graceInterval | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.SystemServices.getOvertempGraceInterval"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.SystemServices.getOvertempGraceInterval"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": {
        "graceInterval": "",
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
| result.powerState | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 27,
    "method": "org.rdk.SystemServices.getPowerState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 27, "method": "org.rdk.SystemServices.getPowerState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 27,
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
| result.state | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "method": "org.rdk.SystemServices.getPowerStateBeforeReboot"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 28, "method": "org.rdk.SystemServices.getPowerStateBeforeReboot"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 28,
    "result": {
        "state": "",
        "success": true
    }
}
```

<a id="getPowerStateIsManagedByDevice"></a>
## *getPowerStateIsManagedByDevice*

Checks whether the power state is managed by the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerStateManagedByDevice | bool | bool |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "method": "org.rdk.SystemServices.getPowerStateIsManagedByDevice"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 29, "method": "org.rdk.SystemServices.getPowerStateIsManagedByDevice"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 29,
    "result": {
        "powerStateManagedByDevice": true,
        "success": true
    }
}
```

<a id="getPreferredStandbyMode"></a>
## *getPreferredStandbyMode*

Returns the preferred standby mode.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.preferredStandbyMode | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "method": "org.rdk.SystemServices.getPreferredStandbyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 30, "method": "org.rdk.SystemServices.getPreferredStandbyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 30,
    "result": {
        "preferredStandbyMode": "",
        "success": true
    }
}
```

<a id="getPreviousRebootInfo"></a>
## *getPreviousRebootInfo*

Returns the preferred standby mode.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.previousRebootInfo | PreviousRebootInfo |  |
| result.previousRebootInfo.timestamp | string |  |
| result.previousRebootInfo.reason | string |  |
| result.previousRebootInfo.source | string |  |
| result.previousRebootInfo.customReason | string |  |
| result.previousRebootInfo.otherReason | string |  |
| result.previousRebootInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "method": "org.rdk.SystemServices.getPreviousRebootInfo"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 31, "method": "org.rdk.SystemServices.getPreviousRebootInfo"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 31,
    "result": {
        "timestamp": "",
        "reason": "",
        "source": "",
        "customReason": "",
        "otherReason": "",
        "success": true
    }
}
```

<a id="getPreviousRebootInfo2"></a>
## *getPreviousRebootInfo2*

Returns detailed information about a reboot.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.rebootInfo | RebootInfo |  |
| result.rebootInfo.timestamp | string |  |
| result.rebootInfo.reason | string |  |
| result.rebootInfo.source | string |  |
| result.rebootInfo.customReason | string |  |
| result.rebootInfo.otherReason | string |  |
| result.rebootInfo.lastHardPowerReset | string |  |
| result.rebootInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "method": "org.rdk.SystemServices.getPreviousRebootInfo2"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 32, "method": "org.rdk.SystemServices.getPreviousRebootInfo2"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 32,
    "result": {
        "timestamp": "",
        "reason": "",
        "source": "",
        "customReason": "",
        "otherReason": "",
        "lastHardPowerReset": "",
        "success": true
    }
}
```

<a id="getPreviousRebootReason"></a>
## *getPreviousRebootReason*

Returns the last reboot reason.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.reason | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "method": "org.rdk.SystemServices.getPreviousRebootReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 33, "method": "org.rdk.SystemServices.getPreviousRebootReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 33,
    "result": {
        "reason": "",
        "success": true
    }
}
```

<a id="getPrivacyMode"></a>
## *getPrivacyMode*

Getting Privacy Mode.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.privacyMode | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "method": "org.rdk.SystemServices.getPrivacyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 34, "method": "org.rdk.SystemServices.getPrivacyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 34,
    "result": {
        "privacyMode": "",
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
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 35,
    "method": "org.rdk.SystemServices.getRFCConfig",
    "params": [
        ""
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 35, "method": "org.rdk.SystemServices.getRFCConfig", "params": [""]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 35,
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
| result.serialNumber | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "method": "org.rdk.SystemServices.getSerialNumber"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 36, "method": "org.rdk.SystemServices.getSerialNumber"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 36,
    "result": {
        "serialNumber": "",
        "success": true
    }
}
```

<a id="getStateInfo"></a>
## *getStateInfo*

Queries device state information of various properties.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.param | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.paramValue | int | int |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "method": "org.rdk.SystemServices.getStateInfo",
    "params": {
        "param": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 37, "method": "org.rdk.SystemServices.getStateInfo", "params": {"param": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 37,
    "result": {
        "paramValue": 0,
        "success": true
    }
}
```

<a id="getStoreDemoLink"></a>
## *getStoreDemoLink*

Returns the store demo video link.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.fileURL | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "method": "org.rdk.SystemServices.getStoreDemoLink"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 38, "method": "org.rdk.SystemServices.getStoreDemoLink"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 38,
    "result": {
        "fileURL": "",
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
| result.systemVersionsInfo.stbVersion | string |  |
| result.systemVersionsInfo.receiverVersion | string |  |
| result.systemVersionsInfo.stbTimestamp | string |  |
| result.systemVersionsInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "method": "org.rdk.SystemServices.getSystemVersions"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 39, "method": "org.rdk.SystemServices.getSystemVersions"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 39,
    "result": {
        "stbVersion": "",
        "receiverVersion": "",
        "stbTimestamp": "",
        "success": true
    }
}
```

<a id="getTemperatureThresholds"></a>
## *getTemperatureThresholds*

Returns temperature threshold values.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.temperatureThresholdsInfo | TemperatureThresholdsInfo |  |
| result.temperatureThresholdsInfo.temperatureThresholds | TemperatureThresholds |  |
| result.temperatureThresholdsInfo.temperatureThresholds.WARN | string |  |
| result.temperatureThresholdsInfo.temperatureThresholds.MAX | string |  |
| result.temperatureThresholdsInfo.temperatureThresholds.temperature | string |  |
| result.temperatureThresholdsInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "method": "org.rdk.SystemServices.getTemperatureThresholds"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 40, "method": "org.rdk.SystemServices.getTemperatureThresholds"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 40,
    "result": {
        "temperatureThresholds": {
            "WARN": "",
            "MAX": "",
            "temperature": ""
        },
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
| result.territory | string | string |
| result.region | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "method": "org.rdk.SystemServices.getTerritory"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 41, "method": "org.rdk.SystemServices.getTerritory"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 41,
    "result": {
        "territory": "",
        "region": "",
        "success": true
    }
}
```

<a id="getThunderStartReason"></a>
## *getThunderStartReason*

Returns the Thunder start reason.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.startReason | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "method": "org.rdk.SystemServices.getThunderStartReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 42, "method": "org.rdk.SystemServices.getThunderStartReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 42,
    "result": {
        "startReason": "",
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
| result.timeZone | string | string |
| result.accuracy | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 43,
    "method": "org.rdk.SystemServices.getTimeZoneDST"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 43, "method": "org.rdk.SystemServices.getTimeZoneDST"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 43,
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
| result.timeZoneInfo.zoneinfo | Zoneinfo |  |
| result.timeZoneInfo.zoneinfo.America | AmericaInfo |  |
| result.timeZoneInfo.zoneinfo.America.New_York | string |  |
| result.timeZoneInfo.zoneinfo.America.Los_Angeles | string |  |
| result.timeZoneInfo.zoneinfo.Europe | EuropeInfo |  |
| result.timeZoneInfo.zoneinfo.Europe.London | string |  |
| result.timeZoneInfo.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 44,
    "method": "org.rdk.SystemServices.getTimeZones"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 44, "method": "org.rdk.SystemServices.getTimeZones"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 44,
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
| result.WakeupReason | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "method": "org.rdk.SystemServices.getWakeupReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 45, "method": "org.rdk.SystemServices.getWakeupReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 45,
    "result": {
        "WakeupReason": "",
        "success": true
    }
}
```

<a id="getWakeupSrcConfiguration"></a>
## *getWakeupSrcConfiguration*

Returns all the supported wakeup configurations and powerState.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerState | string | string |
| result.wakeupSources | ISystemServicesWakeupSourcesIterator | Boolean Array of Key value pair with wake up sources and its configurations |
| result.wakeupSources[#].WAKEUPSRC_VOICE | bool |  |
| result.wakeupSources[#].WAKEUPSRC_PRESENCE_DETECTION | bool |  |
| result.wakeupSources[#].WAKEUPSRC_BLUETOOTH | bool |  |
| result.wakeupSources[#].WAKEUPSRC_WIFI | bool |  |
| result.wakeupSources[#].WAKEUPSRC_IR | bool |  |
| result.wakeupSources[#].WAKEUPSRC_POWER_KEY | bool |  |
| result.wakeupSources[#].WAKEUPSRC_CEC | bool |  |
| result.wakeupSources[#].WAKEUPSRC_LAN | bool |  |
| result.wakeupSources[#].WAKEUPSRC_TIMER | bool |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 46,
    "method": "org.rdk.SystemServices.getWakeupSrcConfiguration"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 46, "method": "org.rdk.SystemServices.getWakeupSrcConfiguration"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 46,
    "result": {
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
        ],
        "success": true
    }
}
```

<a id="getXconfParams"></a>
## *getXconfParams*

Returns XCONF configuration parameters for the device.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.xconfParamsResult | XconfParamsResult |  |
| result.xconfParamsResult.xconfParams | XconfParams |  |
| result.xconfParamsResult.xconfParams.env | string |  |
| result.xconfParamsResult.xconfParams.eStbMac | string |  |
| result.xconfParamsResult.xconfParams.model | string |  |
| result.xconfParamsResult.xconfParams.firmwareVersion | string |  |
| result.xconfParamsResult.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 47,
    "method": "org.rdk.SystemServices.getXconfParams"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 47, "method": "org.rdk.SystemServices.getXconfParams"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 47,
    "result": {
        "xconfParams": {
            "env": "",
            "eStbMac": "",
            "model": "",
            "firmwareVersion": ""
        },
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
| result.Opt-Out | bool | boolean |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 48,
    "method": "org.rdk.SystemServices.isOptOutTelemetry"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 48, "method": "org.rdk.SystemServices.isOptOutTelemetry"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 48,
    "result": {
        "Opt-Out": true,
        "success": true
    }
}
```

<a id="queryMocaStatus"></a>
## *queryMocaStatus*

Checks whether MOCA is enabled.

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mocaEnabled | bool | boolean |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 49,
    "method": "org.rdk.SystemServices.queryMocaStatus"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 49, "method": "org.rdk.SystemServices.queryMocaStatus"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 49,
    "result": {
        "mocaEnabled": true,
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
| params.rebootReason | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.IARM_Bus_Call_STATUS | int | int |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 50,
    "method": "org.rdk.SystemServices.reboot",
    "params": {
        "rebootReason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 50, "method": "org.rdk.SystemServices.reboot", "params": {"rebootReason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 50,
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
| result.systemUptime | string | string |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 51,
    "method": "org.rdk.SystemServices.requestSystemUptime"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 51, "method": "org.rdk.SystemServices.requestSystemUptime"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 51,
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
| params.blocklist | bool | bool |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.result | BlocklistResult |  |
| result.result.error | ErrorInfo |  |
| result.result.error.message | string |  |
| result.result.error.code | string |  |
| result.result.success | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 52,
    "method": "org.rdk.SystemServices.setBlocklistFlag",
    "params": {
        "blocklist": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 52, "method": "org.rdk.SystemServices.setBlocklistFlag", "params": {"blocklist": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 52,
    "result": {
        "error": {
            "message": "",
            "code": ""
        },
        "success": true
    }
}
```

<a id="setBootLoaderPattern"></a>
## *setBootLoaderPattern*

Sets the boot loader pattern mode in MFR.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.pattern | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 53,
    "method": "org.rdk.SystemServices.setBootLoaderPattern",
    "params": {
        "pattern": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 53, "method": "org.rdk.SystemServices.setBootLoaderPattern", "params": {"pattern": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 53,
    "result": {
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
| params.path | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 54,
    "method": "org.rdk.SystemServices.setBootLoaderSplashScreen",
    "params": {
        "path": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 54, "method": "org.rdk.SystemServices.setBootLoaderSplashScreen", "params": {"path": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 54,
    "result": {
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
| params.seconds | int | int |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 55,
    "method": "org.rdk.SystemServices.setDeepSleepTimer",
    "params": {
        "seconds": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 55, "method": "org.rdk.SystemServices.setDeepSleepTimer", "params": {"seconds": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 55,
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
| params.fsrFlag | bool | bool |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 56,
    "method": "org.rdk.SystemServices.setFSRFlag",
    "params": {
        "fsrFlag": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 56, "method": "org.rdk.SystemServices.setFSRFlag", "params": {"fsrFlag": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 56,
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
| params.enable | bool | bool |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 57,
    "method": "org.rdk.SystemServices.setFirmwareAutoReboot",
    "params": {
        "enable": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 57, "method": "org.rdk.SystemServices.setFirmwareAutoReboot", "params": {"enable": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 57,
    "result": {
        "success": true
    }
}
```

<a id="setFirmwareRebootDelay"></a>
## *setFirmwareRebootDelay*

Delays the firmware reboot.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.delaySeconds | int | int |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 58,
    "method": "org.rdk.SystemServices.setFirmwareRebootDelay",
    "params": {
        "delaySeconds": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 58, "method": "org.rdk.SystemServices.setFirmwareRebootDelay", "params": {"delaySeconds": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 58,
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
| params.friendlyName | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 59,
    "method": "org.rdk.SystemServices.setFriendlyName",
    "params": {
        "friendlyName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 59, "method": "org.rdk.SystemServices.setFriendlyName", "params": {"friendlyName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 59,
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
| params.status | bool | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 60,
    "method": "org.rdk.SystemServices.setMigrationStatus",
    "params": {
        "status": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 60, "method": "org.rdk.SystemServices.setMigrationStatus", "params": {"status": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 60,
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
| params.modeinfo | ModeInfo |  |
| params.modeinfo.mode | string |  |
| params.modeinfo.duration | int |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 61,
    "method": "org.rdk.SystemServices.setMode",
    "params": {
        "mode": "",
        "duration": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 61, "method": "org.rdk.SystemServices.setMode", "params": {"mode": "", "duration": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 61,
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
| params.Opt-Out | bool | boolean |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 62,
    "method": "org.rdk.SystemServices.setOptOutTelemetry",
    "params": {
        "Opt-Out": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 62, "method": "org.rdk.SystemServices.setOptOutTelemetry", "params": {"Opt-Out": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 62,
    "result": {
        "success": true
    }
}
```

<a id="setOvertempGraceInterval"></a>
## *setOvertempGraceInterval*

Sets the over-temperature grace interval value. Not supported on all devices.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.graceInterval | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 63,
    "method": "org.rdk.SystemServices.setOvertempGraceInterval",
    "params": {
        "graceInterval": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 63, "method": "org.rdk.SystemServices.setOvertempGraceInterval", "params": {"graceInterval": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 63,
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
| params.powerState | string | string |
| params.standbyReason | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 64,
    "method": "org.rdk.SystemServices.setPowerState",
    "params": {
        "powerState": "",
        "standbyReason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 64, "method": "org.rdk.SystemServices.setPowerState", "params": {"powerState": "", "standbyReason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 64,
    "result": {
        "success": true
    }
}
```

<a id="setPreferredStandbyMode"></a>
## *setPreferredStandbyMode*

Sets and persists the preferred standby mode.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.standbyMode | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 65,
    "method": "org.rdk.SystemServices.setPreferredStandbyMode",
    "params": {
        "standbyMode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 65, "method": "org.rdk.SystemServices.setPreferredStandbyMode", "params": {"standbyMode": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 65,
    "result": {
        "success": true
    }
}
```

<a id="setPrivacyMode"></a>
## *setPrivacyMode*

Setting Privacy Mode.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.privacyMode | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 66,
    "method": "org.rdk.SystemServices.setPrivacyMode",
    "params": {
        "privacyMode": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 66, "method": "org.rdk.SystemServices.setPrivacyMode", "params": {"privacyMode": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 66,
    "result": {
        "success": true
    }
}
```

<a id="setTemperatureThresholds"></a>
## *setTemperatureThresholds*

Sets the temperature threshold values.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.thresholds | TemperatureThresholdsSet |  |
| params.thresholds.WARN | string |  |
| params.thresholds.MAX | string |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 67,
    "method": "org.rdk.SystemServices.setTemperatureThresholds",
    "params": {
        "WARN": "",
        "MAX": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 67, "method": "org.rdk.SystemServices.setTemperatureThresholds", "params": {"WARN": "", "MAX": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 67,
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
| params.territory | string | string |
| params.region | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 68,
    "method": "org.rdk.SystemServices.setTerritory",
    "params": {
        "territory": "",
        "region": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 68, "method": "org.rdk.SystemServices.setTerritory", "params": {"territory": "", "region": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 68,
    "result": {
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
| params.timeZone | string | string |
| params.accuracy | string | string |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 69,
    "method": "org.rdk.SystemServices.setTimeZoneDST",
    "params": {
        "timeZone": "",
        "accuracy": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 69, "method": "org.rdk.SystemServices.setTimeZoneDST", "params": {"timeZone": "", "accuracy": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 69,
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
| params.powerState | string | string |
| params.wakeupSources | ISystemServicesWakeupSourcesIterator | Boolean Array of Key value pair with wake up sources and its configurations |
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
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 70,
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
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 70, "method": "org.rdk.SystemServices.setWakeupSrcConfiguration", "params": {"powerState": "", "wakeupSources": [{"WAKEUPSRC_VOICE": true, "WAKEUPSRC_PRESENCE_DETECTION": true, "WAKEUPSRC_BLUETOOTH": true, "WAKEUPSRC_WIFI": true, "WAKEUPSRC_IR": true, "WAKEUPSRC_POWER_KEY": true, "WAKEUPSRC_CEC": true, "WAKEUPSRC_LAN": true, "WAKEUPSRC_TIMER": true}]}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 70,
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
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 71,
    "method": "org.rdk.SystemServices.updateFirmware"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 71, "method": "org.rdk.SystemServices.updateFirmware"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 71,
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
| result.success | bool | bool |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 72,
    "method": "org.rdk.SystemServices.uploadLogsAsync"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 72, "method": "org.rdk.SystemServices.uploadLogsAsync"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 72,
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
| [onBlocklistChanged](#onBlocklistChanged) | Triggers when the blocklist flag is modified. |
| [onDeviceMgtUpdateReceived](#onDeviceMgtUpdateReceived) | Triggered when the device management update completes. |
| [OnFirmwarePendingReboot](#OnFirmwarePendingReboot) | Triggered when the fireFirmwarePendingReboot method is invoked. |
| [onFirmwareUpdateInfoReceived](#onFirmwareUpdateInfoReceived) | Triggered when the getFirmwareUpdateInfo asynchronous method is invoked. |
| [onFirmwareUpdateStateChange](#onFirmwareUpdateStateChange) | Triggered when the state of a firmware update changes. |
| [onFriendlyNameChanged](#onFriendlyNameChanged) | Triggered when the device friendly name change. |
| [onLogUpload](#onLogUpload) | Triggered when logs upload process is done or stopped. |
| [onMacAddressesRetreived](#onMacAddressesRetreived) | Triggered when the getMacAddresses asynchronous method is invoked. |
| [onNetworkStandbyModeChanged](#onNetworkStandbyModeChanged) | Triggered when the network standby mode setting changes. |
| [onRebootRequest](#onRebootRequest) | Triggered when an application invokes the reboot |
| [onSystemClockSet](#onSystemClockSet) | Triggered when the clock on the set-top device is updated. |
| [onSystemModeChanged](#onSystemModeChanged) | Triggered when the device operating mode changes. |
| [onSystemPowerStateChanged](#onSystemPowerStateChanged) | Triggered when the power manager detects a device power state change. |
| [onTemperatureThresholdChanged](#onTemperatureThresholdChanged) | Triggered when the device temperature changes beyond the WARN or MAX limits. |
| [onTerritoryChanged](#onTerritoryChanged) | Triggered when the device territory changed. |
| [onTimeZoneDSTChanged](#onTimeZoneDSTChanged) | Triggered when device time zone changed. |

<a id="onBlocklistChanged"></a>
## *onBlocklistChanged*

Triggers when the blocklist flag is modified.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.oldBlocklistFlag | bool | bool |
| params.newBlocklistFlag | bool | bool |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 73,
    "method": "org.rdk.SystemServices.onBlocklistChanged",
    "params": {
        "oldBlocklistFlag": true,
        "newBlocklistFlag": true
    }
}
```

<a id="onDeviceMgtUpdateReceived"></a>
## *onDeviceMgtUpdateReceived*

Triggered when the device management update completes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.source | string | string |
| params.type | string | string |
| params.success | bool | bool |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 74,
    "method": "org.rdk.SystemServices.onDeviceMgtUpdateReceived",
    "params": {
        "source": "",
        "type": "",
        "success": true
    }
}
```

<a id="onFirmwarePendingReboot"></a>
## *onFirmwarePendingReboot*

Triggered when the fireFirmwarePendingReboot method is invoked.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.fireFirmwarePendingReboot | int | int |
| params.success | bool | bool |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 75,
    "method": "org.rdk.SystemServices.onFirmwarePendingReboot",
    "params": {
        "fireFirmwarePendingReboot": 0,
        "success": true
    }
}
```

<a id="onFirmwareUpdateInfoReceived"></a>
## *onFirmwareUpdateInfoReceived*

Triggered when the getFirmwareUpdateInfo asynchronous method is invoked.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareUpdateInfo | FirmwareUpdateInfo |  |
| params.firmwareUpdateInfo.status | int |  |
| params.firmwareUpdateInfo.responseString | string |  |
| params.firmwareUpdateInfo.firmwareUpdateVersion | string |  |
| params.firmwareUpdateInfo.rebootImmediately | bool |  |
| params.firmwareUpdateInfo.updateAvailable | bool |  |
| params.firmwareUpdateInfo.updateAvailableEnum | int |  |
| params.firmwareUpdateInfo.success | bool |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 76,
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

<a id="onFirmwareUpdateStateChange"></a>
## *onFirmwareUpdateStateChange*

Triggered when the state of a firmware update changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareUpdateStateChange | int | int |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 77,
    "method": "org.rdk.SystemServices.onFirmwareUpdateStateChange",
    "params": {
        "firmwareUpdateStateChange": 0
    }
}
```

<a id="onFriendlyNameChanged"></a>
## *onFriendlyNameChanged*

Triggered when the device friendly name change.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyName | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 78,
    "method": "org.rdk.SystemServices.onFriendlyNameChanged",
    "params": {
        "friendlyName": ""
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
| params.logUploadStatus | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 79,
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
| params.macAddressesInfo.ecm_mac | string |  |
| params.macAddressesInfo.estb_mac | string |  |
| params.macAddressesInfo.moca_mac | string |  |
| params.macAddressesInfo.eth_mac | string |  |
| params.macAddressesInfo.wifi_mac | string |  |
| params.macAddressesInfo.rf4ce_mac | string |  |
| params.macAddressesInfo.info | string |  |
| params.macAddressesInfo.success | bool |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 80,
    "method": "org.rdk.SystemServices.onMacAddressesRetreived",
    "params": {
        "ecm_mac": "",
        "estb_mac": "",
        "moca_mac": "",
        "eth_mac": "",
        "wifi_mac": "",
        "rf4ce_mac": "",
        "info": "",
        "success": true
    }
}
```

<a id="onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged*

Triggered when the network standby mode setting changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nwStandby | bool | bool |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 81,
    "method": "org.rdk.SystemServices.onNetworkStandbyModeChanged",
    "params": {
        "nwStandby": true
    }
}
```

<a id="onRebootRequest"></a>
## *onRebootRequest*

Triggered when an application invokes the reboot

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestedApp | string | string |
| params.rebootReason | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 82,
    "method": "org.rdk.SystemServices.onRebootRequest",
    "params": {
        "requestedApp": "",
        "rebootReason": ""
    }
}
```

<a id="onSystemClockSet"></a>
## *onSystemClockSet*

Triggered when the clock on the set-top device is updated.

### Parameters
This method takes no parameters.

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 83,
    "method": "org.rdk.SystemServices.onSystemClockSet"
}
```

<a id="onSystemModeChanged"></a>
## *onSystemModeChanged*

Triggered when the device operating mode changes.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 84,
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
| params.powerState | string | string |
| params.currentPowerState | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 85,
    "method": "org.rdk.SystemServices.onSystemPowerStateChanged",
    "params": {
        "powerState": "",
        "currentPowerState": ""
    }
}
```

<a id="onTemperatureThresholdChanged"></a>
## *onTemperatureThresholdChanged*

Triggered when the device temperature changes beyond the WARN or MAX limits.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.thresholdType | string | string |
| params.exceeded | bool | bool |
| params.temperature | string | string |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 86,
    "method": "org.rdk.SystemServices.onTemperatureThresholdChanged",
    "params": {
        "thresholdType": "",
        "exceeded": true,
        "temperature": ""
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
| params.territoryChangedInfo.oldTerritory | string |  |
| params.territoryChangedInfo.newTerritory | string |  |
| params.territoryChangedInfo.oldRegion | string |  |
| params.territoryChangedInfo.newRegion | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 87,
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
| params.timeZoneDSTChangedInfo.oldTimeZone | string |  |
| params.timeZoneDSTChangedInfo.newTimeZone | string |  |
| params.timeZoneDSTChangedInfo.oldAccuracy | string |  |
| params.timeZoneDSTChangedInfo.newAccuracy | string |  |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 88,
    "method": "org.rdk.SystemServices.onTimeZoneDSTChanged",
    "params": {
        "oldTimeZone": "",
        "newTimeZone": "",
        "oldAccuracy": "",
        "newAccuracy": ""
    }
}
```
