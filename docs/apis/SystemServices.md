<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_SystemServices_API"></a>
# SystemServices API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

SystemServices interface for Thunder framework.

(Defined with ISystemServices in [ISystemServices.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/ISystemServices.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the SystemServices interface (version 1.0.0). It includes detailed specification about its methods provided and notifications sent.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="API">API</a> | Application Programming Interface |
| <a name="HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20Thunder.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

SystemServices JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the SystemServices interface:

SystemServices interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceInfo](#method_getDeviceInfo) | Collects device details |
| [getDownloadedFirmwareInfo](#method_getDownloadedFirmwareInfo) | Returns information about firmware downloads |
| [getFirmwareDownloadPercent](#method_getFirmwareDownloadPercent) | Gets the current download percentage |
| [getFirmwareUpdateInfo](#method_getFirmwareUpdateInfo) | Checks the firmware update information |
| [getFirmwareUpdateState](#method_getFirmwareUpdateState) | Checks the state of the firmware update |
| [getLastFirmwareFailureReason](#method_getLastFirmwareFailureReason) | Retrieves the last firmware failure reason |
| [getLastWakeupKeyCode](#method_getLastWakeupKeyCode) | Returns the last wakeup keycode |
| [getMfgSerialNumber](#method_getMfgSerialNumber) | Gets the Manufacturing Serial Number |
| [getNetworkStandbyMode](#method_getNetworkStandbyMode) | Returns the network standby mode of the device |
| [getPowerState](#method_getPowerState) | Returns the power state of the device |
| [getPowerStateBeforeReboot](#method_getPowerStateBeforeReboot) | Returns the power state before reboot |
| [getRFCConfig](#method_getRFCConfig) | Returns information that is related to RDK Feature Control (RFC) configurations |
| [getSerialNumber](#method_getSerialNumber) | Returns the device serial number |
| [getFriendlyName](#method_getFriendlyName) | Returns the friendly name set by setFriendlyName API or default value |
| [getTerritory](#method_getTerritory) | Gets the configured system territory and region |
| [getTimeZones](#method_getTimeZones) | Returns the friendly name set by setFriendlyName API or default value |
| [getTimeZoneDST](#method_getTimeZoneDST) | Gets the available timezones from the system’s time zone database |
| [getWakeupReason](#method_getWakeupReason) | Returns the reason for the device coming out of deep sleep |
| [isOptOutTelemetry](#method_isOptOutTelemetry) | Checks the telemetry opt-out status |
| [reboot](#method_reboot) | Requests that the system performs a reboot of the set-top box |
| [setDeepSleepTimer](#method_setDeepSleepTimer) | Sets the deep sleep timeout period |
| [setFirmwareAutoReboot](#method_setFirmwareAutoReboot) | Enables or disables the AutoReboot Feature |
| [setNetworkStandbyMode](#method_setNetworkStandbyMode) | Enables or disables the AutoReboot Feature |
| [setOptOutTelemetry](#method_setOptOutTelemetry) | Sets the telemetry opt-out status |
| [setPowerState](#method_setPowerState) | Sets the power state of the device |
| [setFriendlyName](#method_setFriendlyName) | Sets the friendly name of device |
| [setBootLoaderSplashScreen](#method_setBootLoaderSplashScreen) | Install or update the BootLoader Splash Screens |
| [setTerritory](#method_setTerritory) | Sets the system territory and region |
| [setTimeZoneDST](#method_setTimeZoneDST) | Sets the system time zone |
| [updateFirmware](#method_updateFirmware) | Initiates a firmware update |
| [getBootTypeInfo](#method_getBootTypeInfo) | Get the FSR flag from the emmc raw area |
| [setMigrationStatus](#method_setMigrationStatus) | set the Migration Status of the device |
| [getMigrationStatus](#method_getMigrationStatus) | get the Migration Status of the device |
| [getMacAddresses](#method_getMacAddresses) | Gets the MAC address of the device |
| [getPlatformConfiguration](#method_getPlatformConfiguration) | Returns the Supported features and device/account info |
| [setWakeupSrcConfiguration](#method_setWakeupSrcConfiguration) | Sets the wakeup source configuration for the input powerState |
| [getSystemVersions](#method_getSystemVersions) | Returns system version details |
| [requestSystemUptime](#method_requestSystemUptime) | Returns the device uptime |
| [setMode](#method_setMode) | Sets the mode of the set-top box for a specific duration before returning to normal mode |
| [uploadLogsAsync](#method_uploadLogsAsync) | Starts background process to upload logs |
| [abortLogUpload](#method_abortLogUpload) | Stops background process to upload logs |
| [setFSRFlag](#method_setFSRFlag) | Set the FSR flag into the emmc raw area |
| [getFSRFlag](#method_getFSRFlag) | Get the FSR flag from the emmc raw area |
| [setBlocklistFlag](#method_setBlocklistFlag) | To update Blocklist flag |
| [getBlocklistFlag](#method_getBlocklistFlag) | Get block list flag |
| [getBuildType](#method_getBuildType) | Returns build type of the image flashed on the device |
| [getTimeStatus](#method_getTimeStatus) | Get the time status on the device |

<a id="method_getDeviceInfo"></a>
## *getDeviceInfo [<sup>method</sup>](#head_Methods)*

Collects device details.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.params | array | mandatory | A list of Supported device keys |
| params.params[#] | string | mandatory | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Device Information |
| result.make | string | mandatory | Device manufacturer |
| result.bluetooth_mac | string | mandatory | <sup>*(deprecated)*</sup> Bluetooth MAC Address |
| result.boxIP | string | mandatory | STB IP Address |
| result.build_type | string | mandatory | Image build type |
| result.device_type | string | mandatory | <sup>*(deprecated)*</sup> Device type |
| result.estb_mac | string | mandatory | STB MAC Address |
| result.eth_mac | string | mandatory | Ethernet MAC Address |
| result.friendly_id | string | mandatory | Friendly device model name |
| result.imageVersion | string | mandatory | Image version |
| result.version | string | mandatory | Version Info |
| result.software_version | string | mandatory | Software version |
| result.model_number | string | mandatory | Device model number |
| result.wifi_mac | string | mandatory | WIFI Mac Address |
| result.modelName | string | mandatory | Device model name |
| result.hardwareID | string | mandatory | Hardware ID |
| result.message | string | mandatory | Error message if input failure |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getDeviceInfo",
  "params": {
    "params": [
      "..."
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "make": "...",
    "boxIP": "...",
    "build_type": "...",
    "estb_mac": "...",
    "eth_mac": "...",
    "friendly_id": "...",
    "imageVersion": "...",
    "version": "...",
    "software_version": "...",
    "model_number": "...",
    "wifi_mac": "...",
    "modelName": "...",
    "hardwareID": "...",
    "message": "...",
    "success": false
  }
}
```

<a id="method_getDownloadedFirmwareInfo"></a>
## *getDownloadedFirmwareInfo [<sup>method</sup>](#head_Methods)*

Returns information about firmware downloads.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.currentFWVersion | string | mandatory | The current firmware version |
| result.downloadedFWVersion | string | mandatory | The downloaded firmware version |
| result.downloadedFWLocation | string | mandatory | The location of the downloaded firmware |
| result.isRebootDeferred | boolean | mandatory | Whether the device should be rebooted |
| result.success | boolean | mandatory | Whether the request succeeded |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getDownloadedFirmwareInfo"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "currentFWVersion": "...",
    "downloadedFWVersion": "...",
    "downloadedFWLocation": "...",
    "isRebootDeferred": false,
    "success": false,
    "SysSrv_Status": 0,
    "errorMessage": "..."
  }
}
```

<a id="method_getFirmwareDownloadPercent"></a>
## *getFirmwareDownloadPercent [<sup>method</sup>](#head_Methods)*

Gets the current download percentage.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.downloadPercent | integer | mandatory | Current download percentage (0-100) |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFirmwareDownloadPercent"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "downloadPercent": 0,
    "success": false
  }
}
```

<a id="method_getFirmwareUpdateInfo"></a>
## *getFirmwareUpdateInfo [<sup>method</sup>](#head_Methods)*

Checks the firmware update information.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.GUID | string | mandatory | A unique identifier |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.asyncResponse | boolean | mandatory | Whether the event notification succeeded |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFirmwareUpdateInfo",
  "params": {
    "GUID": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "asyncResponse": false,
    "success": false
  }
}
```

<a id="method_getFirmwareUpdateState"></a>
## *getFirmwareUpdateState [<sup>method</sup>](#head_Methods)*

Checks the state of the firmware update.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.firmwareUpdateState | integer | mandatory | The state (must be one of the following: Uninitialized, Requesting, Downloading, Failed, DownLoad Complete, Validation Complete, Preparing to Reboot) |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFirmwareUpdateState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "firmwareUpdateState": 0,
    "success": false
  }
}
```

<a id="method_getLastFirmwareFailureReason"></a>
## *getLastFirmwareFailureReason [<sup>method</sup>](#head_Methods)*

Retrieves the last firmware failure reason.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.failReason | string | mandatory | The reason the failure occurred |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getLastFirmwareFailureReason"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "failReason": "...",
    "success": false
  }
}
```

<a id="method_getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode [<sup>method</sup>](#head_Methods)*

Returns the last wakeup keycode.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.wakeupKeyCode | integer | mandatory | The last wakeup keycode |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getLastWakeupKeyCode"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "wakeupKeyCode": 0,
    "success": false
  }
}
```

<a id="method_getMfgSerialNumber"></a>
## *getMfgSerialNumber [<sup>method</sup>](#head_Methods)*

Gets the Manufacturing Serial Number.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.mfgSerialNumber | string | mandatory | Manufacturing Serial Number |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getMfgSerialNumber"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "mfgSerialNumber": "...",
    "success": false
  }
}
```

<a id="method_getNetworkStandbyMode"></a>
## *getNetworkStandbyMode [<sup>method</sup>](#head_Methods)*

Returns the network standby mode of the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.nwStandby | boolean | mandatory | Whether WakeOnLAN and WakeOnWLAN is Supported (true); otherwise, false |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getNetworkStandbyMode"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "nwStandby": false,
    "success": false
  }
}
```

<a id="method_getPowerState"></a>
## *getPowerState [<sup>method</sup>](#head_Methods)*

Returns the power state of the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.powerState | string | mandatory | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getPowerState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "powerState": "...",
    "success": false
  }
}
```

<a id="method_getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot [<sup>method</sup>](#head_Methods)*

Returns the power state before reboot.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.state | string | mandatory | The power state |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getPowerStateBeforeReboot"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "state": "...",
    "success": false
  }
}
```

<a id="method_getRFCConfig"></a>
## *getRFCConfig [<sup>method</sup>](#head_Methods)*

Returns information that is related to RDK Feature Control (RFC) configurations.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.rfcList | array | mandatory | A list of RFC properties to query |
| params.rfcList[#] | string | mandatory | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.RFCConfig | opaque object | mandatory | A list of specified RFC properties |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getRFCConfig",
  "params": {
    "rfcList": [
      "..."
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "RFCConfig": {},
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_getSerialNumber"></a>
## *getSerialNumber [<sup>method</sup>](#head_Methods)*

Returns the device serial number.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.serialNumber | string | mandatory | The serial number |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getSerialNumber"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "serialNumber": "...",
    "success": false
  }
}
```

<a id="method_getFriendlyName"></a>
## *getFriendlyName [<sup>method</sup>](#head_Methods)*

Returns the friendly name set by setFriendlyName API or default value.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.friendlyName | string | mandatory | The friendly name of the device which used to display on the client device list |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFriendlyName"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "friendlyName": "...",
    "success": false
  }
}
```

<a id="method_getTerritory"></a>
## *getTerritory [<sup>method</sup>](#head_Methods)*

Gets the configured system territory and region.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.territory | string | mandatory | Territory name |
| result.region | string | mandatory | Region name |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getTerritory"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "territory": "...",
    "region": "...",
    "success": false
  }
}
```

<a id="method_getTimeZones"></a>
## *getTimeZones [<sup>method</sup>](#head_Methods)*

Returns the friendly name set by setFriendlyName API or default value.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.timeZones | array | mandatory | A list of available timezones from the system |
| params.timeZones[#] | string | mandatory | *...* |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.zoneinfo | opaque object | mandatory | A timezone area |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getTimeZones",
  "params": {
    "timeZones": [
      "..."
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "zoneinfo": {},
    "success": false
  }
}
```

<a id="method_getTimeZoneDST"></a>
## *getTimeZoneDST [<sup>method</sup>](#head_Methods)*

Gets the available timezones from the system’s time zone database.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.timeZone | string | mandatory | The timezone |
| result.accuracy | string | mandatory | The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL) |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getTimeZoneDST"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "timeZone": "...",
    "accuracy": "...",
    "success": false
  }
}
```

<a id="method_getWakeupReason"></a>
## *getWakeupReason [<sup>method</sup>](#head_Methods)*

Returns the reason for the device coming out of deep sleep.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.wakeupReason | string | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getWakeupReason"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "wakeupReason": "...",
    "success": false
  }
}
```

<a id="method_isOptOutTelemetry"></a>
## *isOptOutTelemetry [<sup>method</sup>](#head_Methods)*

Checks the telemetry opt-out status.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.Opt-Out | boolean | mandatory | True for opt-out, otherwise false |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.isOptOutTelemetry"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "Opt-Out": false,
    "success": false
  }
}
```

<a id="method_reboot"></a>
## *reboot [<sup>method</sup>](#head_Methods)*

Requests that the system performs a reboot of the set-top box.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.rebootReason | string | mandatory | The reboot reason |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.IARM_Bus_Call_STATUS | integer | mandatory | IARM BUS status |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.reboot",
  "params": {
    "rebootReason": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "IARM_Bus_Call_STATUS": 0,
    "success": false
  }
}
```

<a id="method_setDeepSleepTimer"></a>
## *setDeepSleepTimer [<sup>method</sup>](#head_Methods)*

Sets the deep sleep timeout period.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.seconds | integer | mandatory | The deep sleep timeout in seconds |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setDeepSleepTimer",
  "params": {
    "seconds": 0
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_setFirmwareAutoReboot"></a>
## *setFirmwareAutoReboot [<sup>method</sup>](#head_Methods)*

Enables or disables the AutoReboot Feature.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.enable | boolean | mandatory | True to enable Autoreboot or false to disable |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setFirmwareAutoReboot",
  "params": {
    "enable": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setNetworkStandbyMode"></a>
## *setNetworkStandbyMode [<sup>method</sup>](#head_Methods)*

Enables or disables the AutoReboot Feature.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.nwStandby | boolean | mandatory | Whether WakeOnLAN and WakeOnWLAN is Supported (true); otherwise, false |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setNetworkStandbyMode",
  "params": {
    "nwStandby": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setOptOutTelemetry"></a>
## *setOptOutTelemetry [<sup>method</sup>](#head_Methods)*

Sets the telemetry opt-out status.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.Opt-Out | boolean | mandatory | True for opt-out, otherwise false |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setOptOutTelemetry",
  "params": {
    "Opt-Out": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setPowerState"></a>
## *setPowerState [<sup>method</sup>](#head_Methods)*

Sets the power state of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.powerState | string | mandatory | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.standbyReason | string | mandatory | The reason for a standby state |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setPowerState",
  "params": {
    "powerState": "...",
    "standbyReason": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_setFriendlyName"></a>
## *setFriendlyName [<sup>method</sup>](#head_Methods)*

Sets the friendly name of device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.friendlyName | string | mandatory | The friendly name of the device which used to display on the client device list |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setFriendlyName",
  "params": {
    "friendlyName": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setBootLoaderSplashScreen"></a>
## *setBootLoaderSplashScreen [<sup>method</sup>](#head_Methods)*

Install or update the BootLoader Splash Screens.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.path | string | mandatory | Path to the pre-downloaded splash screen file location. Full path with file name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.error | object | mandatory | *...* |
| result.error.message | string | mandatory | Error Message |
| result.error.code | string | mandatory | Error Code |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setBootLoaderSplashScreen",
  "params": {
    "path": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "error": {
      "message": "...",
      "code": "..."
    },
    "success": false
  }
}
```

<a id="method_setTerritory"></a>
## *setTerritory [<sup>method</sup>](#head_Methods)*

Sets the system territory and region.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.territory | string | mandatory | Territory name |
| params.region | string | mandatory | Region name |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.error | object | mandatory | *...* |
| result.error.message | string | mandatory | Error Message |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setTerritory",
  "params": {
    "territory": "...",
    "region": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "error": {
      "message": "..."
    },
    "success": false
  }
}
```

<a id="method_setTimeZoneDST"></a>
## *setTimeZoneDST [<sup>method</sup>](#head_Methods)*

Sets the system time zone.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.timeZone | string | mandatory | The timezone |
| params.accuracy | string | mandatory | The timezone accuracy (must be one of the following: INITIAL, INTERIM, FINAL) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setTimeZoneDST",
  "params": {
    "timeZone": "...",
    "accuracy": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_updateFirmware"></a>
## *updateFirmware [<sup>method</sup>](#head_Methods)*

Initiates a firmware update.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.updateFirmware"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getBootTypeInfo"></a>
## *getBootTypeInfo [<sup>method</sup>](#head_Methods)*

Get the FSR flag from the emmc raw area.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.bootType | string | mandatory | BOOT Type Info |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBootTypeInfo"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "bootType": "..."
  }
}
```

<a id="method_setMigrationStatus"></a>
## *setMigrationStatus [<sup>method</sup>](#head_Methods)*

set the Migration Status of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | string | mandatory | Migration Status |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setMigrationStatus",
  "params": {
    "status": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getMigrationStatus"></a>
## *getMigrationStatus [<sup>method</sup>](#head_Methods)*

get the Migration Status of the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.migrationStatus | string | mandatory | Migration Status |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getMigrationStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "migrationStatus": "..."
  }
}
```

<a id="method_getMacAddresses"></a>
## *getMacAddresses [<sup>method</sup>](#head_Methods)*

Gets the MAC address of the device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.GUID | string | mandatory | A unique identifier |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.asyncResponse | boolean | mandatory | Whether the event notification succeeded |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getMacAddresses",
  "params": {
    "GUID": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "asyncResponse": false,
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_getPlatformConfiguration"></a>
## *getPlatformConfiguration [<sup>method</sup>](#head_Methods)*

Returns the Supported features and device/account info.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.query | string | mandatory | Query for support of a particular feature, e.g. AccountInfo.accountId |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | Platform Configuration Details |
| result.AccountInfo | object | mandatory | AccountInfo Details |
| result.AccountInfo.accountId | string | mandatory | Account Id |
| result.AccountInfo.x1DeviceId | string | mandatory | X1 Device Id |
| result.AccountInfo.XCALSessionTokenAvailable | boolean | mandatory | XCAL Session Token Available |
| result.AccountInfo.experience | string | mandatory | Experience |
| result.AccountInfo.deviceMACAddress | string | mandatory | Device MAC Address |
| result.AccountInfo.firmwareUpdateDisabled | boolean | mandatory | Whether the firmwareUpdate Disabled |
| result.DeviceInfo | object | mandatory | DeviceInfo Details |
| result.DeviceInfo.quirks | string | mandatory | The list of installed “quirks” |
| result.DeviceInfo.mimeTypeExclusions | object | mandatory | Mime Type Exclusions |
| result.DeviceInfo.mimeTypeExclusions.CDVR | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.DVR | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.EAS | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.IPDVR | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.IVOD | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.LINEAR_TV | string | mandatory | *...* |
| result.DeviceInfo.mimeTypeExclusions.VOD | string | mandatory | *...* |
| result.DeviceInfo.features | object | mandatory | Features |
| result.DeviceInfo.features.allowSelfSignedWithIPAddress | integer | mandatory | *...* |
| result.DeviceInfo.features.connection.supportsSecure | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.callJavaScriptWithResult | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.cookies | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.disableCSSAnimations | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.evaluateJavaScript | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.headers | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.httpCookies | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.postMessage | integer | mandatory | *...* |
| result.DeviceInfo.features.htmlview.urlpatterns | integer | mandatory | *...* |
| result.DeviceInfo.features.keySource | integer | mandatory | *...* |
| result.DeviceInfo.features.uhd_4k_decode | integer | mandatory | *...* |
| result.DeviceInfo.mimeTypes | string | mandatory | Mime Types |
| result.DeviceInfo.model | string | mandatory | Model |
| result.DeviceInfo.deviceType | string | mandatory | Device Type |
| result.DeviceInfo.supportsTrueSD | boolean | mandatory | SD Support |
| result.DeviceInfo.webBrowser | object | mandatory | WebBrowser Info |
| result.DeviceInfo.webBrowser.browserType | string | mandatory | Browser Type |
| result.DeviceInfo.webBrowser.version | string | mandatory | Version |
| result.DeviceInfo.webBrowser.userAgent | string | mandatory | User Agent |
| result.DeviceInfo.HdrCapability | string | mandatory | E.g. HDR10,Dolby Vision,Technicolor Prime |
| result.DeviceInfo.canMixPCMWithSurround | boolean | mandatory | PCM with Surround |
| result.DeviceInfo.publicIP | string | mandatory | Public IP |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getPlatformConfiguration",
  "params": {
    "query": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "AccountInfo": {
      "accountId": "...",
      "x1DeviceId": "...",
      "XCALSessionTokenAvailable": false,
      "experience": "...",
      "deviceMACAddress": "...",
      "firmwareUpdateDisabled": false
    },
    "DeviceInfo": {
      "quirks": "...",
      "mimeTypeExclusions": {
        "CDVR": "...",
        "DVR": "...",
        "EAS": "...",
        "IPDVR": "...",
        "IVOD": "...",
        "LINEAR_TV": "...",
        "VOD": "..."
      },
      "features": {
        "allowSelfSignedWithIPAddress": 0,
        "connection.supportsSecure": 0,
        "htmlview.callJavaScriptWithResult": 0,
        "htmlview.cookies": 0,
        "htmlview.disableCSSAnimations": 0,
        "htmlview.evaluateJavaScript": 0,
        "htmlview.headers": 0,
        "htmlview.httpCookies": 0,
        "htmlview.postMessage": 0,
        "htmlview.urlpatterns": 0,
        "keySource": 0,
        "uhd_4k_decode": 0
      },
      "mimeTypes": "...",
      "model": "...",
      "deviceType": "...",
      "supportsTrueSD": false,
      "webBrowser": {
        "browserType": "...",
        "version": "...",
        "userAgent": "..."
      },
      "HdrCapability": "...",
      "canMixPCMWithSurround": false,
      "publicIP": "..."
    },
    "success": false
  }
}
```

<a id="method_setWakeupSrcConfiguration"></a>
## *setWakeupSrcConfiguration [<sup>method</sup>](#head_Methods)*

Sets the wakeup source configuration for the input powerState.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.powerState | string | mandatory | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.wakeupSources | array | mandatory | Array of Key value pair with wake up sources and its configurations |
| params.wakeupSources[#] | object | mandatory | *...* |
| params.wakeupSources[#].WAKEUPSRC_VOICE | boolean | mandatory | Voice Wake up |
| params.wakeupSources[#].WAKEUPSRC_PRESENCE_DETECTION | boolean | mandatory | Presence detection wake up |
| params.wakeupSources[#].WAKEUPSRC_BLUETOOTH | boolean | mandatory | Bluetooth Wakeup |
| params.wakeupSources[#].WAKEUPSRC_WIFI | boolean | mandatory | WiFi Wake up |
| params.wakeupSources[#].WAKEUPSRC_IR | boolean | mandatory | IR Remote Wake up |
| params.wakeupSources[#].WAKEUPSRC_POWER_KEY | boolean | mandatory | Power Button Wake up - GPIO |
| params.wakeupSources[#].WAKEUPSRC_CEC | boolean | mandatory | HDMI CEC command Wake up |
| params.wakeupSources[#].WAKEUPSRC_LAN | boolean | mandatory | LAN wake up |
| params.wakeupSources[#].WAKEUPSRC_TIMER | boolean | mandatory | Timer Wake up |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setWakeupSrcConfiguration",
  "params": {
    "powerState": "...",
    "wakeupSources": [
      {
        "WAKEUPSRC_VOICE": false,
        "WAKEUPSRC_PRESENCE_DETECTION": false,
        "WAKEUPSRC_BLUETOOTH": false,
        "WAKEUPSRC_WIFI": false,
        "WAKEUPSRC_IR": false,
        "WAKEUPSRC_POWER_KEY": false,
        "WAKEUPSRC_CEC": false,
        "WAKEUPSRC_LAN": false,
        "WAKEUPSRC_TIMER": false
      }
    ]
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getSystemVersions"></a>
## *getSystemVersions [<sup>method</sup>](#head_Methods)*

Returns system version details.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.stbVersion | string | mandatory | The STB version |
| result.receiverVersion | string | mandatory | The receiver version |
| result.stbTimestamp | string | mandatory | The STB timestamp |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getSystemVersions"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "stbVersion": "...",
    "receiverVersion": "...",
    "stbTimestamp": "...",
    "success": false
  }
}
```

<a id="method_requestSystemUptime"></a>
## *requestSystemUptime [<sup>method</sup>](#head_Methods)*

Returns the device uptime.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.systemUptime | string | mandatory | The uptime, in seconds, of the device |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.requestSystemUptime"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "systemUptime": "...",
    "success": false
  }
}
```

<a id="method_setMode"></a>
## *setMode [<sup>method</sup>](#head_Methods)*

Sets the mode of the set-top box for a specific duration before returning to normal mode.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.modeInfo | object | mandatory | *...* |
| params.modeInfo.mode | string | mandatory | The mode (must be one of the following: NORMAL, EAS, WAREHOUSE) |
| params.modeInfo.duration | integer | mandatory | The duration |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.SysSrv_Status | integer | mandatory | System service status error code if failure occurs |
| result.errorMessage | string | mandatory | Error message if failure occurs |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setMode",
  "params": {
    "modeInfo": {
      "mode": "...",
      "duration": 0
    }
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "SysSrv_Status": 0,
    "errorMessage": "...",
    "success": false
  }
}
```

<a id="method_uploadLogsAsync"></a>
## *uploadLogsAsync [<sup>method</sup>](#head_Methods)*

Starts background process to upload logs.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.uploadLogsAsync"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_abortLogUpload"></a>
## *abortLogUpload [<sup>method</sup>](#head_Methods)*

Stops background process to upload logs.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.abortLogUpload"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_setFSRFlag"></a>
## *setFSRFlag [<sup>method</sup>](#head_Methods)*

Set the FSR flag into the emmc raw area.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.fsrFlag | boolean | mandatory | FSR flag |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setFSRFlag",
  "params": {
    "fsrFlag": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "success": false
  }
}
```

<a id="method_getFSRFlag"></a>
## *getFSRFlag [<sup>method</sup>](#head_Methods)*

Get the FSR flag from the emmc raw area.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.fsrFlag | boolean | mandatory | FSR flag |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getFSRFlag"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "fsrFlag": false,
    "success": false
  }
}
```

<a id="method_setBlocklistFlag"></a>
## *setBlocklistFlag [<sup>method</sup>](#head_Methods)*

To update Blocklist flag.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.blocklist | boolean | mandatory | Blocklist flag |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.error | object | mandatory | Error Information |
| result.error.message | string | mandatory | Error Message |
| result.error.code | string | mandatory | Error Code |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.setBlocklistFlag",
  "params": {
    "blocklist": false
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "error": {
      "message": "...",
      "code": "..."
    },
    "success": false
  }
}
```

<a id="method_getBlocklistFlag"></a>
## *getBlocklistFlag [<sup>method</sup>](#head_Methods)*

Get block list flag.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.blocklist | boolean | mandatory | Whether the device is blocklisted |
| result.error | object | mandatory | Error Information |
| result.error.message | string | mandatory | Error Message |
| result.error.code | string | mandatory | Error Code |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBlocklistFlag"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "blocklist": false,
    "error": {
      "message": "...",
      "code": "..."
    },
    "success": false
  }
}
```

<a id="method_getBuildType"></a>
## *getBuildType [<sup>method</sup>](#head_Methods)*

Returns build type of the image flashed on the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.build_type | string | mandatory | *...* |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getBuildType"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "build_type": "...",
    "success": false
  }
}
```

<a id="method_getTimeStatus"></a>
## *getTimeStatus [<sup>method</sup>](#head_Methods)*

Get the time status on the device.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory | *...* |
| result.TimeQuality | string | mandatory | Time Quality |
| result.TimeSrc | string | mandatory | Time Source |
| result.Time | string | mandatory | Current Time |
| result.success | boolean | mandatory | Whether the request succeeded |

### Errors

| Message | Description |
| :-------- | :-------- |
| ```ErrorCode::ERROR_NONE``` | Indicates success |
| ```ErrorCode::ERROR_GENERAL``` | Indicates failure |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.getTimeStatus"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "TimeQuality": "...",
    "TimeSrc": "...",
    "Time": "...",
    "success": false
  }
}
```

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the SystemServices interface:

SystemServices interface events:

| Notification | Description |
| :-------- | :-------- |
| [onFirmwareUpdateInfoReceived](#notification_onFirmwareUpdateInfoReceived) | Triggered when the getFirmwareUpdateInfo asynchronous method is invoked |
| [onRebootRequest](#notification_onRebootRequest) | Triggers when a device reboot request is made |
| [onSystemPowerStateChanged](#notification_onSystemPowerStateChanged) | Triggered when the power manager detects a device power state change |
| [onTerritoryChanged](#notification_onTerritoryChanged) | Triggered when the device territory changed |
| [onTimeZoneDSTChanged](#notification_onTimeZoneDSTChanged) | Triggered when device time zone changed |
| [onMacAddressesRetreived](#notification_onMacAddressesRetreived) | Triggered when the getMacAddresses asynchronous method is invoked |
| [onSystemModeChanged](#notification_onSystemModeChanged) | Triggers when the system mode is changed successfully |
| [onLogUpload](#notification_onLogUpload) | Triggered when logs upload process is done or stopped |
| [onNetworkStandbyModeChanged](#notification_onNetworkStandbyModeChanged) | Triggered when the network standby mode is changed |
| [onFirmwareUpdateStateChange](#notification_onFirmwareUpdateStateChange) | Triggered when the firmware update state is changed |
| [onTemperatureThresholdChanged](#notification_onTemperatureThresholdChanged) | Triggered when the temperature threshold is changed |
| [onSystemClockSet](#notification_onSystemClockSet) | Triggered when time source state has changed |
| [onFirmwarePendingReboot](#notification_onFirmwarePendingReboot) | Triggered when system is in maintenance window |
| [onFriendlyNameChanged](#notification_onFriendlyNameChanged) | Triggered when the friendly name is changed |
| [onDeviceMgtUpdateReceived](#notification_onDeviceMgtUpdateReceived) | Triggered when Device Mgt settings update is received |
| [onBlocklistChanged](#notification_onBlocklistChanged) | Triggered when blocklist flag has changed |
| [onTimeStatusChanged](#notification_onTimeStatusChanged) | Triggered when time status has changed |

<a id="notification_onFirmwareUpdateInfoReceived"></a>
## *onFirmwareUpdateInfoReceived [<sup>notification</sup>](#head_Notifications)*

Triggered when the getFirmwareUpdateInfo asynchronous method is invoked.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.status | integer | mandatory | The firmware update status |
| params.responseString | string | mandatory | A custom response |
| params.firmwareUpdateVersion | string | mandatory | The next firmware update version |
| params.rebootImmediately | boolean | mandatory | The value true indicates that the device has to be rebooted immediately or false otherwise |
| params.updateAvailable | boolean | mandatory | The value false indicates that there is no update available |
| params.updateAvailableEnum | integer | mandatory | The update available details (must be one of the following: 0, 1, 2, 3) |
| params.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFirmwareUpdateInfoReceived",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFirmwareUpdateInfoReceived",
  "params": {
    "status": 0,
    "responseString": "...",
    "firmwareUpdateVersion": "...",
    "rebootImmediately": false,
    "updateAvailable": false,
    "updateAvailableEnum": 0,
    "success": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFirmwareUpdateInfoReceived``.

<a id="notification_onRebootRequest"></a>
## *onRebootRequest [<sup>notification</sup>](#head_Notifications)*

Triggers when a device reboot request is made.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.requestedApp | string | mandatory | The source of the reboot |
| params.rebootReason | string | mandatory | The reboot reason |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onRebootRequest",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onRebootRequest",
  "params": {
    "requestedApp": "...",
    "rebootReason": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onRebootRequest``.

<a id="notification_onSystemPowerStateChanged"></a>
## *onSystemPowerStateChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the power manager detects a device power state change.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.powerState | string | mandatory | The power state (must be one of the following: STANDBY, DEEP_SLEEP, LIGHT_SLEEP, ON) |
| params.currentPowerState | string | mandatory | The current power state |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onSystemPowerStateChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSystemPowerStateChanged",
  "params": {
    "powerState": "...",
    "currentPowerState": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSystemPowerStateChanged``.

<a id="notification_onTerritoryChanged"></a>
## *onTerritoryChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the device territory changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.oldTerritory | string | mandatory | Old territory |
| params.newTerritory | string | mandatory | New territory |
| params.oldRegion | string | mandatory | Old region |
| params.newRegion | string | mandatory | New region |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onTerritoryChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTerritoryChanged",
  "params": {
    "oldTerritory": "...",
    "newTerritory": "...",
    "oldRegion": "...",
    "newRegion": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTerritoryChanged``.

<a id="notification_onTimeZoneDSTChanged"></a>
## *onTimeZoneDSTChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when device time zone changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.oldTimeZone | string | mandatory | Old time zone |
| params.newTimeZone | string | mandatory | New time zone |
| params.oldAccuracy | string | mandatory | Old time zone accuracy |
| params.newAccuracy | string | mandatory | New time zone accuracy |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onTimeZoneDSTChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTimeZoneDSTChanged",
  "params": {
    "oldTimeZone": "...",
    "newTimeZone": "...",
    "oldAccuracy": "...",
    "newAccuracy": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTimeZoneDSTChanged``.

<a id="notification_onMacAddressesRetreived"></a>
## *onMacAddressesRetreived [<sup>notification</sup>](#head_Notifications)*

Triggered when the getMacAddresses asynchronous method is invoked.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.ecm_mac | string | mandatory | The embedded cable modem MAC address |
| params.estb_mac | string | mandatory | The embedded set-top box MAC address |
| params.moca_mac | string | mandatory | The MOCA MAC address |
| params.eth_mac | string | mandatory | The Ethernet MAC address |
| params.wifi_mac | string | mandatory | The Wifi MAC address |
| params.bluetooth_mac | string | mandatory | The Bluetooth MAC address |
| params.rf4ce_mac | string | mandatory | The Rf4ce MAC address |
| params.info | string | mandatory | Additional information (only if any of the above data is missing) |
| params.success | boolean | mandatory | Whether the request succeeded |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onMacAddressesRetreived",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onMacAddressesRetreived",
  "params": {
    "ecm_mac": "...",
    "estb_mac": "...",
    "moca_mac": "...",
    "eth_mac": "...",
    "wifi_mac": "...",
    "bluetooth_mac": "...",
    "rf4ce_mac": "...",
    "info": "...",
    "success": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onMacAddressesRetreived``.

<a id="notification_onSystemModeChanged"></a>
## *onSystemModeChanged [<sup>notification</sup>](#head_Notifications)*

Triggers when the system mode is changed successfully.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.mode | string | mandatory | The mode (must be one of the following: NORMAL, EAS, WAREHOUSE) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onSystemModeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSystemModeChanged",
  "params": {
    "mode": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSystemModeChanged``.

<a id="notification_onLogUpload"></a>
## *onLogUpload [<sup>notification</sup>](#head_Notifications)*

Triggered when logs upload process is done or stopped.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.logUploadStatus | string | mandatory | Upload status (must be one of the following: UPLOAD_SUCCESS, UPLOAD_FAILURE, UPLOAD_ABORTED) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onLogUpload",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onLogUpload",
  "params": {
    "logUploadStatus": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onLogUpload``.

<a id="notification_onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the network standby mode is changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.nwStandby | boolean | mandatory | The network standby mode |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onNetworkStandbyModeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onNetworkStandbyModeChanged",
  "params": {
    "nwStandby": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onNetworkStandbyModeChanged``.

<a id="notification_onFirmwareUpdateStateChange"></a>
## *onFirmwareUpdateStateChange [<sup>notification</sup>](#head_Notifications)*

Triggered when the firmware update state is changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.firmwareUpdateStateChange | integer | mandatory | The firmware update state change |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFirmwareUpdateStateChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFirmwareUpdateStateChange",
  "params": {
    "firmwareUpdateStateChange": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFirmwareUpdateStateChange``.

<a id="notification_onTemperatureThresholdChanged"></a>
## *onTemperatureThresholdChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the temperature threshold is changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.thresholdType | string | mandatory | The type of temperature threshold |
| params.exceeded | boolean | mandatory | Whether the threshold is exceeded |
| params.temperature | string | mandatory | The current temperature |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onTemperatureThresholdChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTemperatureThresholdChanged",
  "params": {
    "thresholdType": "...",
    "exceeded": false,
    "temperature": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTemperatureThresholdChanged``.

<a id="notification_onSystemClockSet"></a>
## *onSystemClockSet [<sup>notification</sup>](#head_Notifications)*

Triggered when time source state has changed.

### Notification Parameters

This notification carries no parameters.

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onSystemClockSet",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onSystemClockSet"
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onSystemClockSet``.

<a id="notification_onFirmwarePendingReboot"></a>
## *onFirmwarePendingReboot [<sup>notification</sup>](#head_Notifications)*

Triggered when system is in maintenance window.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.fireFirmwarePendingReboot | integer | mandatory | Time in seconds for pending reboot |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFirmwarePendingReboot",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFirmwarePendingReboot",
  "params": {
    "fireFirmwarePendingReboot": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFirmwarePendingReboot``.

<a id="notification_onFriendlyNameChanged"></a>
## *onFriendlyNameChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when the friendly name is changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.friendlyName | string | mandatory | The new friendly name |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onFriendlyNameChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onFriendlyNameChanged",
  "params": {
    "friendlyName": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onFriendlyNameChanged``.

<a id="notification_onDeviceMgtUpdateReceived"></a>
## *onDeviceMgtUpdateReceived [<sup>notification</sup>](#head_Notifications)*

Triggered when Device Mgt settings update is received.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.source | string | mandatory | The source of the update |
| params.type | string | mandatory | The type of update |
| params.success | boolean | mandatory | Whether the update was successful |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onDeviceMgtUpdateReceived",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDeviceMgtUpdateReceived",
  "params": {
    "source": "...",
    "type": "...",
    "success": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDeviceMgtUpdateReceived``.

<a id="notification_onBlocklistChanged"></a>
## *onBlocklistChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when blocklist flag has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.oldBlocklistFlag | string | mandatory | The previous blocklist flag |
| params.newBlocklistFlag | string | mandatory | The new blocklist flag |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onBlocklistChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onBlocklistChanged",
  "params": {
    "oldBlocklistFlag": "...",
    "newBlocklistFlag": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onBlocklistChanged``.

<a id="notification_onTimeStatusChanged"></a>
## *onTimeStatusChanged [<sup>notification</sup>](#head_Notifications)*

Triggered when time status has changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory | *...* |
| params.TimeQuality | string | mandatory | The quality of the time |
| params.TimeSrc | string | mandatory | The source of the time |
| params.Time | string | mandatory | The current time |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.register",
  "params": {
    "event": "onTimeStatusChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onTimeStatusChanged",
  "params": {
    "TimeQuality": "...",
    "TimeSrc": "...",
    "Time": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onTimeStatusChanged``.

