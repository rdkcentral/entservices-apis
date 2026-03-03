<!-- Generated automatically, DO NOT EDIT! -->
<a name="head.System_API"></a>
# System API

A org.rdk.System plugin for Thunder framework.

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

The `System` plugin is used to manage various system-level features such as power settings and firmware updates.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a name="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| classname | string | Class name: *org.rdk.System* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="head.Methods"></a>
# Methods

The following methods are provided by the org.rdk.System plugin:

org.rdk.System interface methods:

| Method | Description |
| :-------- | :-------- |
| [getDeviceInfo](#method.getDeviceInfo) | Collects device details |
| [getDownloadedFirmwareInfo](#method.getDownloadedFirmwareInfo) | Returns information about firmware downloads |
| [getFirmwareDownloadPercent](#method.getFirmwareDownloadPercent) | Gets the current download percentage |
| [getFirmwareUpdateInfo](#method.getFirmwareUpdateInfo) | Checks the firmware update information |
| [getFirmwareUpdateState](#method.getFirmwareUpdateState) | Checks the state of the firmware update |
| [getLastFirmwareFailureReason](#method.getLastFirmwareFailureReason) | Retrieves the last firmware failure reason |
| [getLastWakeupKeyCode](#method.getLastWakeupKeyCode) | Returns the last wakeup keycode |
| [getMacAddresses](#method.getMacAddresses) | Gets the MAC address of the device |
| [getMfgSerialNumber](#method.getMfgSerialNumber) | Gets the Manufacturing Serial Number |
| [getNetworkStandbyMode](#method.getNetworkStandbyMode) | Returns the network standby mode of the device |
| [getPlatformConfiguration](#method.getPlatformConfiguration) | Returns the supported features and device/account info |
| [getPowerState](#method.getPowerState) | Returns the power state of the device |
| [getPowerStateBeforeReboot](#method.getPowerStateBeforeReboot) | Returns the power state before reboot |
| [getRFCConfig](#method.getRFCConfig) | Returns information that is related to RDK Feature Control (RFC) configurations |
| [getSerialNumber](#method.getSerialNumber) | Returns the device serial number |
| [getSystemVersions](#method.getSystemVersions) | Returns system version details |
| [getFriendlyName](#method.getFriendlyName) | Returns the friendly name set by setFriendlyName API or default value |
| [getTerritory](#method.getTerritory) | Gets the configured system territory and region |
| [getTimeZones](#method.getTimeZones) | (Version2) Gets the available timezones from the system's time zone database |
| [getTimeZoneDST](#method.getTimeZoneDST) | Get the configured time zone from the file referenced by `TZ_FILE` |
| [getWakeupReason](#method.getWakeupReason) | Returns the reason for the device coming out of deep sleep |
| [getPreviousRebootInfo](#method.getPreviousRebootInfo) | Returns basic information about a reboot |
| [isOptOutTelemetry](#method.isOptOutTelemetry) | Checks the telemetry opt-out status |
| [reboot](#method.reboot) | Requests that the system performs a reboot of the set-top box |
| [requestSystemUptime](#method.requestSystemUptime) | Returns the device uptime |
| [setDeepSleepTimer](#method.setDeepSleepTimer) | Sets the deep sleep timeout period |
| [setFirmwareAutoReboot](#method.setFirmwareAutoReboot) | Enables or disables the AutoReboot Feature |
| [setMode](#method.setMode) | Sets the mode of the set-top box for a specific duration before returning to normal mode |
| [setNetworkStandbyMode](#method.setNetworkStandbyMode) | This API will be deprecated in the future |
| [setOptOutTelemetry](#method.setOptOutTelemetry) | Sets the telemetry opt-out status |
| [setPowerState](#method.setPowerState) | Sets the power state of the device |
| [setFriendlyName](#method.setFriendlyName) | Sets the friendly name of device |
| [setBootLoaderSplashScreen](#method.setBootLoaderSplashScreen) | Install or update the BootLoader Splash Screens |
| [getBuildType](#method.getBuildType) | Returns build type of the image flashed on the device |
| [setTerritory](#method.setTerritory) | Sets the system territory and region |
| [setTimeZoneDST](#method.setTimeZoneDST) | Sets the system time zone |
| [setWakeupSrcConfiguration](#method.setWakeupSrcConfiguration) | Sets the wakeup source configuration for the input powerState |
| [updateFirmware](#method.updateFirmware) | Initiates a firmware update |
| [uploadLogsAsync](#method.uploadLogsAsync) | Starts background process to upload logs |
| [abortLogUpload](#method.abortLogUpload) | Stops background process to upload logs |
| [setFSRFlag](#method.setFSRFlag) | Set the FSR flag into the emmc raw area |
| [getFSRFlag](#method.getFSRFlag) | Get the FSR flag from the emmc raw area |
| [getBootTypeInfo](#method.getBootTypeInfo) | Getting Boot Type |
| [setMigrationStatus](#method.setMigrationStatus) | sets the tr181 MigrationStatus parameter |
| [getMigrationStatus](#method.getMigrationStatus) | get the Migration Status of the device |
| [setBlocklistFlag](#method.setBlocklistFlag) | To update Blocklist flag |
| [getBlocklistFlag](#method.getBlocklistFlag) | Get the FSR flag from the emmc raw area |
| [getTimeStatus](#method.getTimeStatus) | Get the time status on the device |


<a name="method.getDeviceInfo"></a>
## *getDeviceInfo [<sup>method</sup>](#head.Methods)*

Collects device details. Sample keys include:  
* bluetooth_mac  
* boxIP  
* build_type  
* estb_mac  
* imageVersion  
* rf4ce_mac  
* wifi_mac. 
 
 System.getDeviceInfo is DEPRECATED use the following APIS 
* make = [DeviceInfo.make](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=make)  
* bluetooth_mac = DEPRECATED  
* boxIP = [Network.GetIPSettings](https://github.com/rdkcentral/networkmanager/blob/main/docs/NetworkManagerPlugin.md#method.GetIPSettings)  
* build_type = org.rdk.System.getBuildType  
* device_type = DEPRECATED  
* estb_mac = [DeviceInfo.addresses](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=addresses)  
* eth_mac = [DeviceInfo.addresses](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=addresses) 
* friendly_id = [DeviceInfo.modelname](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=modelname)  
* imageVersion = [DeviceInfo.firmwareversion](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=firmwareversion)  
* version = [DeviceInfo.firmwareversion](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=firmwareversion)  
* wifi_mac = [DeviceInfo.addresses](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=addresses) .

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations. [Refer this link for the new api](https://rdkcentral.github.io/entservices-apis/#/apis/DeviceInfoPlugin?id=properties)

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.params | array | A list of supported device keys |
| params.params[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.estb_mac | string | Value for the specified key name |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getDeviceInfo",
    "params": {
        "params": [
            "estb_mac"
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
        "estb_mac": "20:F1:9E:EE:62:08",
        "success": true
    }
}
```

<a name="method.getDownloadedFirmwareInfo"></a>
## *getDownloadedFirmwareInfo [<sup>method</sup>](#head.Methods)*

Returns information about firmware downloads.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentFWVersion | string | The current firmware version |
| result.downloadedFWVersion | string | The downloaded firmware version |
| result.downloadedFWLocation | string | The location of the downloaded firmware |
| result.isRebootDeferred | boolean | Whether the device should be rebooted |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getDownloadedFirmwareInfo"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "currentFWVersion": "AB121AEI_VBN_1911_sprint_20200109040424sdy",
        "downloadedFWVersion": "AB121AEI_VBN_1911_sprint_20200510040450sdy",
        "downloadedFWLocation": "/tmp",
        "isRebootDeferred": false,
        "success": true
    }
}
```

<a name="method.getFirmwareDownloadPercent"></a>
## *getFirmwareDownloadPercent [<sup>method</sup>](#head.Methods)*

Gets the current download percentage.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.downloadPercent | integer | The percentage completed |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getFirmwareDownloadPercent"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "downloadPercent": 25,
        "success": true
    }
}
```

<a name="method.getFirmwareUpdateInfo"></a>
## *getFirmwareUpdateInfo [<sup>method</sup>](#head.Methods)*

Checks the firmware update information.

### Events

| Event | Description |
| :-------- | :-------- |
| [onFirmwareUpdateInfoReceived](#event.onFirmwareUpdateInfoReceived) | Triggers when the firmware update information is requested |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.GUID | string | <sup>*(optional)*</sup> A unique identifier |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | boolean | Whether the event notification succeeded |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getFirmwareUpdateInfo",
    "params": {
        "GUID": "1234abcd"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "asyncResponse": true,
        "success": true
    }
}
```

<a name="method.getFirmwareUpdateState"></a>
## *getFirmwareUpdateState [<sup>method</sup>](#head.Methods)*

Checks the state of the firmware update.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.firmwareUpdateState | integer | The state (must be one of the following: *Uninitialized*, *Requesting*, *Downloading*, *Failed*, *DownLoad Complete*, *Validation Complete*, *Preparing to Reboot*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getFirmwareUpdateState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "firmwareUpdateState": 5,
        "success": true
    }
}
```

<a name="method.getLastFirmwareFailureReason"></a>
## *getLastFirmwareFailureReason [<sup>method</sup>](#head.Methods)*

Retrieves the last firmware failure reason.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.failReason | string | The reason the failure occurred |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getLastFirmwareFailureReason"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "failReason": "Image Download Failed - Unable to connect",
        "success": true
    }
}
```

<a name="method.getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode [<sup>method</sup>](#head.Methods)*

Returns the last wakeup keycode.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupKeyCode | string | The last wakeup keycode |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getLastWakeupKeyCode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "wakeupKeyCode": "59",
        "success": true
    }
}
```

<a name="method.getMacAddresses"></a>
## *getMacAddresses [<sup>method</sup>](#head.Methods)*

Gets the MAC address of the device.

### Events

| Event | Description |
| :-------- | :-------- |
| [onMacAddressesRetreived](#event.onMacAddressesRetreived) | Triggers when the MAC addresses are requested |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.GUID | string | <sup>*(optional)*</sup> A unique identifier |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.asyncResponse | boolean | Whether the event notification succeeded |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getMacAddresses",
    "params": {
        "GUID": "1234abcd"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "asyncResponse": true,
        "success": true
    }
}
```

<a name="method.getMfgSerialNumber"></a>
## *getMfgSerialNumber [<sup>method</sup>](#head.Methods)*

Gets the Manufacturing Serial Number.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.mfgSerialNumber | string | Manufacturing Serial Number |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getMfgSerialNumber"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "mfgSerialNumber": "F00020CE000003",
        "success": true
    }
}
```

<a name="method.getNetworkStandbyMode"></a>
## *getNetworkStandbyMode [<sup>method</sup>](#head.Methods)*

Returns the network standby mode of the device. If network standby is `true`, the device supports `WakeOnLAN` and `WakeOnWLAN` actions in STR (S3) mode.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.nwStandby | boolean | Whether `WakeOnLAN` and `WakeOnWLAN` is supported (`true`); otherwise, `false` |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getNetworkStandbyMode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "nwStandby": false,
        "success": true
    }
}
```

<a name="method.getPlatformConfiguration"></a>
## *getPlatformConfiguration [<sup>method</sup>](#head.Methods)*

Returns the supported features and device/account info.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.query | string | Query for support of a particular feature, e.g. AccountInfo.accountId |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result?.AccountInfo | object | <sup>*(optional)*</sup>  |
| result?.AccountInfo?.accountId | string | <sup>*(optional)*</sup> Account Id |
| result?.AccountInfo?.x1DeviceId | string | <sup>*(optional)*</sup> X1 Device Id |
| result?.AccountInfo?.XCALSessionTokenAvailable | boolean | <sup>*(optional)*</sup>  |
| result?.AccountInfo?.experience | string | <sup>*(optional)*</sup> Experience |
| result?.AccountInfo?.deviceMACAddress | string | <sup>*(optional)*</sup> Device MAC Address |
| result?.AccountInfo?.firmwareUpdateDisabled | boolean | <sup>*(optional)*</sup>  |
| result?.DeviceInfo | object | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.quirks | array | <sup>*(optional)*</sup> The list of installed "quirks" |
| result?.DeviceInfo?.quirks[#] | string | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.mimeTypeExclusions | object | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.features | object | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.mimeTypes | array | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.mimeTypes[#] | string | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.model | string | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.deviceType | string | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.supportsTrueSD | boolean | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.webBrowser | object | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.webBrowser.browserType | string |  |
| result?.DeviceInfo?.webBrowser.version | string |  |
| result?.DeviceInfo?.webBrowser.userAgent | string |  |
| result?.DeviceInfo?.HdrCapability | string | <sup>*(optional)*</sup> e.g. HDR10,Dolby Vision,Technicolor Prime |
| result?.DeviceInfo?.canMixPCMWithSurround | boolean | <sup>*(optional)*</sup>  |
| result?.DeviceInfo?.publicIP | string | <sup>*(optional)*</sup> Public IP |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getPlatformConfiguration",
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
            "accountId": "1000000000000000000",
            "x1DeviceId": "1000000000000000000",
            "XCALSessionTokenAvailable": false,
            "experience": "X1",
            "deviceMACAddress": "44:AA:F5:39:D3:42",
            "firmwareUpdateDisabled": false
        },
        "DeviceInfo": {
            "quirks": [
                "XRE-4621"
            ],
            "mimeTypeExclusions": {},
            "features": {},
            "mimeTypes": [
                "audio/mpeg"
            ],
            "model": "AB121AEI",
            "deviceType": "IpStb",
            "supportsTrueSD": true,
            "webBrowser": {
                "browserType": "WPE",
                "version": "1.0.0.0",
                "userAgent": "Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WPE"
            },
            "HdrCapability": "none",
            "canMixPCMWithSurround": true,
            "publicIP": "12.34.56.78"
        },
        "success": true
    }
}
```

<a name="method.getPowerState"></a>
## *getPowerState [<sup>method</sup>](#head.Methods)*

Returns the power state of the device.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerState | string | The power state (must be one of the following: *STANDBY*, *DEEP_SLEEP*, *LIGHT_SLEEP*, *ON*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getPowerState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "powerState": "ON",
        "success": true
    }
}
```

<a name="method.getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot [<sup>method</sup>](#head.Methods)*

Returns the power state before reboot.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.state | string | The power state |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getPowerStateBeforeReboot"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "state": "ON",
        "success": true
    }
}
```

<a name="method.getRFCConfig"></a>
## *getRFCConfig [<sup>method</sup>](#head.Methods)*

Returns information that is related to RDK Feature Control (RFC) configurations.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rfcList | array | A list of RFC properties to query |
| params.rfcList[#] | string |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.RFCConfig | object | A list of specified RFC properties |
| result.RFCConfig?.Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AccountInfo.AccountID | string | <sup>*(optional)*</sup>  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getRFCConfig",
    "params": {
        "rfcList": [
            "Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AccountInfo.AccountID"
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
        "RFCConfig": {
            "Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.Feature.AccountInfo.AccountID": "1181405614235499371"
        },
        "success": true
    }
}
```

<a name="method.getSerialNumber"></a>
## *getSerialNumber [<sup>method</sup>](#head.Methods)*

Returns the device serial number.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.serialNumber | string | The serial number |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getSerialNumber"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "serialNumber": "M11806TK0024",
        "success": true
    }
}
```

<a name="method.getSystemVersions"></a>
## *getSystemVersions [<sup>method</sup>](#head.Methods)*

Returns system version details.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.stbVersion | string | The STB version |
| result.receiverVersion | string | The receiver version |
| result.stbTimestamp | string | The STB timestamp |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getSystemVersions"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "stbVersion": "AB121AEI_VBN_1911_sprint_20200109040424sdy",
        "receiverVersion": "3.14.0.0",
        "stbTimestamp": "Thu 09 Jan 2020 04:04:24 AP UTC",
        "success": true
    }
}
```

<a name="method.getFriendlyName"></a>
## *getFriendlyName [<sup>method</sup>](#head.Methods)*

Returns the friendly name set by setFriendlyName API or default value.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.friendlyName | string | The friendly name of the device which used to display on the client device list |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getFriendlyName"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "friendlyName": "My Device",
        "success": true
    }
}
```

<a name="method.getTerritory"></a>
## *getTerritory [<sup>method</sup>](#head.Methods)*

Gets the configured system territory and region. Territory is a ISO-3166-1 alpha-3 standard (see https://en.wikipedia.org/wiki/ISO_3166-1). Region is a ISO-3166-2 alpha-2 standard (see https://en.wikipedia.org/wiki/ISO_3166-2).

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.territory | string | territory name |
| result.region | string | region name |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getTerritory"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "territory": "USA",
        "region": "US-NY",
        "success": true
    }
}
```

<a name="method.getTimeZones"></a>
## *getTimeZones [<sup>method</sup>](#head.Methods)*

(Version2) Gets the available timezones from the system's time zone database. This method is useful for determining time offsets per zone.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.zoneinfo | object | A timezone area |
| result.zoneinfo?.America | object | <sup>*(optional)*</sup>  |
| result.zoneinfo?.America?.New_York | string | <sup>*(optional)*</sup>  |
| result.zoneinfo?.America?.Los_Angeles | string | <sup>*(optional)*</sup>  |
| result.zoneinfo?.Europe | object | <sup>*(optional)*</sup>  |
| result.zoneinfo?.Europe?.London | string | <sup>*(optional)*</sup>  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getTimeZones"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "zoneinfo": {
            "America": {
                "New_York": "Thu Nov 5 15:21:17 2020 EST",
                "Los_Angeles": "Thu Nov 5 12:21:17 2020 PST"
            },
            "Europe": {
                "London": "Thu Nov 5 14:21:18 2020 CST"
            }
        },
        "success": true
    }
}
```

<a name="method.getTimeZoneDST"></a>
## *getTimeZoneDST [<sup>method</sup>](#head.Methods)*

Get the configured time zone from the file referenced by `TZ_FILE`. If the time zone is not set, then `null` is returned.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.timeZone | string | The timezone |
| result.accuracy | string | The timezone accuracy (must be one of the following: *INITIAL*, *INTERIM*, *FINAL*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getTimeZoneDST"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "timeZone": "America/New_York",
        "accuracy": "INITIAL",
        "success": true
    }
}
```

<a name="method.getWakeupReason"></a>
## *getWakeupReason [<sup>method</sup>](#head.Methods)*

Returns the reason for the device coming out of deep sleep.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupReason | string | The reason (must be one of the following: *WAKEUP_REASON_IR*, *WAKEUP_REASON_RCU_BT*, *WAKEUP_REASON_RCU_RF4CE*, *WAKEUP_REASON_GPIO*, *WAKEUP_REASON_LAN*, *WAKEUP_REASON_WLAN*, *WAKEUP_REASON_TIMER*, *WAKEUP_REASON_FRONT_PANEL*, *WAKEUP_REASON_WATCHDOG*, *WAKEUP_REASON_SOFTWARE_RESET*, *WAKEUP_REASON_THERMAL_RESET*, *WAKEUP_REASON_WARM_RESET*, *WAKEUP_REASON_COLDBOOT*, *WAKEUP_REASON_STR_AUTH_FAILURE*, *WAKEUP_REASON_CEC*, *WAKEUP_REASON_PRESENCE*, *WAKEUP_REASON_VOICE*, *WAKEUP_REASON_UNKNOWN*) |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getWakeupReason"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "wakeupReason": "WAKEUP_REASON_VOICE",
        "success": true
    }
}
```

<a name="method.getPreviousRebootInfo"></a>
## *getPreviousRebootInfo [<sup>method</sup>](#head.Methods)*

Returns basic information about a reboot.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.timestamp | string | The last reboot time |
| result.reason | string | The reboot reason |
| result.source | string | Source that trigerred reboot |
| result.customReason | string | A custom reason |
| result.otherReason | string | Other reasons for reboot |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getPreviousRebootInfo"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "timestamp": "20200128083540",
        "reason": "FIRMWARE_FAILURE",
        "source": "-sh",
        "customReason": "API Validation",
        "otherReason": "API Validation",
        "success": true
    }
}
```

<a name="method.isOptOutTelemetry"></a>
## *isOptOutTelemetry [<sup>method</sup>](#head.Methods)*

Checks the telemetry opt-out status.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.Opt-Out | boolean | `true` for opt-out, otherwise `false` |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.isOptOutTelemetry"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "Opt-Out": false,
        "success": true
    }
}
```

<a name="method.reboot"></a>
## *reboot [<sup>method</sup>](#head.Methods)*

Requests that the system performs a reboot of the set-top box.

### Events

| Event | Description |
| :-------- | :-------- |
| [onRebootRequest](#event.onRebootRequest) | Triggers when a device reboot request is made |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rebootReason | string | The reboot reason |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.IARM_Bus_Call_STATUS | integer | IARM BUS status |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.reboot",
    "params": {
        "rebootReason": "FIRMWARE_FAILURE"
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
        "success": true
    }
}
```

<a name="method.requestSystemUptime"></a>
## *requestSystemUptime [<sup>method</sup>](#head.Methods)*

Returns the device uptime.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.systemUptime | string | The uptime, in seconds, of the device |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.requestSystemUptime"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "systemUptime": "1655.92",
        "success": true
    }
}
```

<a name="method.setDeepSleepTimer"></a>
## *setDeepSleepTimer [<sup>method</sup>](#head.Methods)*

Sets the deep sleep timeout period.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.seconds | integer | The deep sleep timeout in seconds |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setDeepSleepTimer",
    "params": {
        "seconds": 3
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setFirmwareAutoReboot"></a>
## *setFirmwareAutoReboot [<sup>method</sup>](#head.Methods)*

Enables or disables the AutoReboot Feature. This method internally sets the tr181 `AutoReboot.Enable` parameter to `true` or `false`.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enable | boolean | `true` to enable Autoreboot or `false` to disable |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setFirmwareAutoReboot",
    "params": {
        "enable": true
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setMode"></a>
## *setMode [<sup>method</sup>](#head.Methods)*

Sets the mode of the set-top box for a specific duration before returning to normal mode. Valid modes are:  
* `NORMAL` - The set-top box is operating in normal mode.  
* `EAS` - The set-top box is operating in Emergency Alert System (EAS) mode. This mode is set when the device needs to perform certain tasks when entering EAS mode, such as setting the clock display or preventing the user from using the diagnostics menu.  
* `WAREHOUSE` - The set-top box is operating in warehouse mode.

### Events

| Event | Description |
| :-------- | :-------- |
| [onSystemModeChanged](#event.onSystemModeChanged) | Triggers when the system mode is changed successfully |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.modeInfo | object | The mode information |
| params.modeInfo.mode | string | The mode (must be one of the following: *NORMAL*, *EAS*, *WAREHOUSE*) |
| params.modeInfo.duration | integer | The duration |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setMode",
    "params": {
        "modeInfo": {
            "mode": "NORMAL",
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
        "success": true
    }
}
```

<a name="method.setNetworkStandbyMode"></a>
## *setNetworkStandbyMode [<sup>method</sup>](#head.Methods)*

This API will be deprecated in the future. Please refer setWakeupSrcConfiguration to Migrate. This API Enables or disables the network standby mode of the device. If network standby is enabled, the device supports `WakeOnLAN` and `WakeOnWLAN` actions in STR (S3) mode.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nwStandby | boolean | Whether `WakeOnLAN` and `WakeOnWLAN` is supported (`true`); otherwise, `false` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setNetworkStandbyMode",
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
        "success": true
    }
}
```

<a name="method.setOptOutTelemetry"></a>
## *setOptOutTelemetry [<sup>method</sup>](#head.Methods)*

Sets the telemetry opt-out status.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.Opt-Out | boolean | `true` for opt-out, otherwise `false` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setOptOutTelemetry",
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
        "success": true
    }
}
```

<a name="method.setPowerState"></a>
## *setPowerState [<sup>method</sup>](#head.Methods)*

Sets the power state of the device.

### Events

| Event | Description |
| :-------- | :-------- |
| [onSystemPowerStateChanged](#event.onSystemPowerStateChanged) | Triggers when the system power state changes |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | The power state (must be one of the following: *STANDBY*, *DEEP_SLEEP*, *LIGHT_SLEEP*, *ON*) |
| params.standbyReason | string | The reason for a standby state |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setPowerState",
    "params": {
        "powerState": "ON",
        "standbyReason": "APIUnitTest"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setFriendlyName"></a>
## *setFriendlyName [<sup>method</sup>](#head.Methods)*

Sets the friendly name of device. It allows an applications to set friendly name value which could be used by different applications to list this device on client mobile application. The provided name should not be empty. Friendly name is persisted on device and reuse after each reboot until updated by the user.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyName | string | The friendly name of the device which used to display on the client device list |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setFriendlyName",
    "params": {
        "friendlyName": "My Device"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setBootLoaderSplashScreen"></a>
## *setBootLoaderSplashScreen [<sup>method</sup>](#head.Methods)*

Install or update the BootLoader Splash Screens. This is typically called by Resident Apps to configure the Splash Screen shown during device boot up.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.path | string | Path to the pre-downloaded splash screen file location. Full path with file name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setBootLoaderSplashScreen",
    "params": {
        "path": "/tmp/osd1"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.getBuildType"></a>
## *getBuildType [<sup>method</sup>](#head.Methods)*

Returns build type of the image flashed on the device.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.build_type | string | Image build type |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getBuildType"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "build_type": "VBN",
        "success": true
    }
}
```

<a name="method.setTerritory"></a>
## *setTerritory [<sup>method</sup>](#head.Methods)*

Sets the system territory and region.Territory is a ISO-3166-1 alpha-3 standard (see https://en.wikipedia.org/wiki/ISO_3166-1). Region is a ISO-3166-2 alpha-2 standard (see https://en.wikipedia.org/wiki/ISO_3166-2).

### Events

| Event | Description |
| :-------- | :-------- |
| [onTerritoryChanged](#event.onTerritoryChanged) | Triggered when territory is set |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.territory | string | territory name |
| params?.region | string | <sup>*(optional)*</sup> region name |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setTerritory",
    "params": {
        "territory": "USA",
        "region": "US-NY"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setTimeZoneDST"></a>
## *setTimeZoneDST [<sup>method</sup>](#head.Methods)*

Sets the system time zone. See `getTimeZones` to get a list of available timezones on the system.

### Events

| Event | Description |
| :-------- | :-------- |
| [onTimeZoneDSTChanged](#event.onTimeZoneDSTChanged) | Triggered when device time zone changed |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.timeZone | string | The timezone |
| params?.accuracy | string | <sup>*(optional)*</sup> The timezone accuracy (must be one of the following: *INITIAL*, *INTERIM*, *FINAL*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setTimeZoneDST",
    "params": {
        "timeZone": "America/New_York",
        "accuracy": "INITIAL"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setWakeupSrcConfiguration"></a>
## *setWakeupSrcConfiguration [<sup>method</sup>](#head.Methods)*

Sets the wakeup source configuration for the input powerState. if you are using setNetworkStandbyMode API, Please do not use this API to set LAN and WIFI wakeup. Please migrate to setWakeupSrcConfiguration API to control all wakeup source settings. This API does not persist. Please call this API on Every bootup to set the values.

> This API is **deprecated** and may be removed in the future. It is no longer recommended for use in new implementations. [Refer this link for the new api](https://rdkcentral.github.io/entservices-apis/#/apis/PowerManagerPlugin?id=setwakeupsrcconfig)

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.powerState | string | <sup>*(optional)*</sup> The power state (must be one of the following: *STANDBY*, *DEEP_SLEEP*, *LIGHT_SLEEP*, *ON*) |
| params.wakeupSources | array | Array of Key value pair with wake up sources and its configurations |
| params.wakeupSources[#] | object |  |
| params.wakeupSources[#]?.WAKEUPSRC_VOICE | boolean | <sup>*(optional)*</sup> Voice Wake up |
| params.wakeupSources[#]?.WAKEUPSRC_PRESENCE_DETECTION | boolean | <sup>*(optional)*</sup> Presense detection wake up |
| params.wakeupSources[#]?.WAKEUPSRC_BLUETOOTH | boolean | <sup>*(optional)*</sup> Bluetooth Wakeup |
| params.wakeupSources[#]?.WAKEUPSRC_WIFI | boolean | <sup>*(optional)*</sup> WiFi Wake up |
| params.wakeupSources[#]?.WAKEUPSRC_IR | boolean | <sup>*(optional)*</sup> IR Remote Wake up |
| params.wakeupSources[#]?.WAKEUPSRC_POWER_KEY | boolean | <sup>*(optional)*</sup> Power Button Wake up - GPIO |
| params.wakeupSources[#]?.WAKEUPSRC_CEC | boolean | <sup>*(optional)*</sup> HDMI CEC commadn Wake up |
| params.wakeupSources[#]?.WAKEUPSRC_LAN | boolean | <sup>*(optional)*</sup> LAN wake up |
| params.wakeupSources[#]?.WAKEUPSRC_TIMER | boolean | <sup>*(optional)*</sup> TImer Wake up |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setWakeupSrcConfiguration",
    "params": {
        "powerState": "ON",
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

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.updateFirmware"></a>
## *updateFirmware [<sup>method</sup>](#head.Methods)*

Initiates a firmware update. This method has no affect if an update is not available.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.updateFirmware"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.uploadLogsAsync"></a>
## *uploadLogsAsync [<sup>method</sup>](#head.Methods)*

Starts background process to upload logs.

### Events

| Event | Description |
| :-------- | :-------- |
| [onLogUpload](#event.onLogUpload) | Triggered when logs upload process is done |
### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.uploadLogsAsync"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.abortLogUpload"></a>
## *abortLogUpload [<sup>method</sup>](#head.Methods)*

Stops background process to upload logs.

### Events

| Event | Description |
| :-------- | :-------- |
| [onLogUpload](#event.onLogUpload) | Triggered when logs upload process is stopped |
### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.abortLogUpload"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.setFSRFlag"></a>
## *setFSRFlag [<sup>method</sup>](#head.Methods)*

Set the FSR flag into the emmc raw area. This API will fail if you attempt to set the same value.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.fsrFlag | boolean | FSR flag |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setFSRFlag"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "fsrFlag": true,
        "success": true
    }
}
```

<a name="method.getFSRFlag"></a>
## *getFSRFlag [<sup>method</sup>](#head.Methods)*

Get the FSR flag from the emmc raw area.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.fsrFlag | boolean | FSR flag |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getFSRFlag"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "fsrFlag": true,
        "success": true
    }
}
```

<a name="method.getBootTypeInfo"></a>
## *getBootTypeInfo [<sup>method</sup>](#head.Methods)*

Getting Boot Type.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.bootType | string | BOOT Type Info |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getBootTypeInfo"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "bootType": "BOOT_NORMAL"
    }
}
```

<a name="method.setMigrationStatus"></a>
## *setMigrationStatus [<sup>method</sup>](#head.Methods)*

sets the tr181 MigrationStatus parameter.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | string | Migration status |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setMigrationStatus",
    "params": {
        "status": "NOT_STARTED"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.getMigrationStatus"></a>
## *getMigrationStatus [<sup>method</sup>](#head.Methods)*

get the Migration Status of the device.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.migrationStatus | string | Migration status |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getMigrationStatus"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "migrationStatus": "NOT_STARTED"
    }
}
```

<a name="method.setBlocklistFlag"></a>
## *setBlocklistFlag [<sup>method</sup>](#head.Methods)*

To update Blocklist flag.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.blocklist | boolean | Blocklist flag |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.setBlocklistFlag",
    "params": {
        "blocklist": true
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "success": true
    }
}
```

<a name="method.getBlocklistFlag"></a>
## *getBlocklistFlag [<sup>method</sup>](#head.Methods)*

Get the FSR flag from the emmc raw area.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.blocklist | string | block list string |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getBlocklistFlag"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "blocklist": "...",
        "success": true
    }
}
```

<a name="method.getTimeStatus"></a>
## *getTimeStatus [<sup>method</sup>](#head.Methods)*

Get the time status on the device.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.TimeQuality | string | Time Quality |
| result.TimeSrc | string | Time Source |
| result.Time | string | Current Time |
| result.success | boolean | Whether the request succeeded |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.System.getTimeStatus"
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
        "success": true
    }
}
```

<a name="head.Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.System plugin:

org.rdk.System interface events:

| Event | Description |
| :-------- | :-------- |
| [onFirmwareUpdateInfoReceived](#event.onFirmwareUpdateInfoReceived) | Triggered when the `getFirmwareUpdateInfo` asynchronous method is invoked |
| [onFirmwareUpdateStateChange](#event.onFirmwareUpdateStateChange) | Triggered when the state of a firmware update changes |
| [onMacAddressesRetreived](#event.onMacAddressesRetreived) | Triggered when the `getMacAddresses` asynchronous method is invoked |
| [onNetworkStandbyModeChanged](#event.onNetworkStandbyModeChanged) | Triggered when the network standby mode setting changes |
| [onRebootRequest](#event.onRebootRequest) | Triggered when an application invokes the reboot method |
| [onSystemClockSet](#event.onSystemClockSet) | Triggered when the clock on the set-top device is updated |
| [onSystemModeChanged](#event.onSystemModeChanged) | Triggered when the device operating mode changes |
| [onSystemPowerStateChanged](#event.onSystemPowerStateChanged) | Triggered when the power manager detects a device power state change |
| [onFriendlyNameChanged](#event.onFriendlyNameChanged) | Triggered when the device friendly name change |
| [onTemperatureThresholdChanged](#event.onTemperatureThresholdChanged) | Triggered when the device temperature changes beyond the `WARN` or `MAX` limits (see `setTemperatureThresholds`) |
| [onTerritoryChanged](#event.onTerritoryChanged) | Triggered when the device territory changed |
| [onDeviceMgtUpdateReceived](#event.onDeviceMgtUpdateReceived) | Triggered when the device management update completes |
| [onTimeZoneDSTChanged](#event.onTimeZoneDSTChanged) | Triggered when device time zone changed |
| [onLogUpload](#event.onLogUpload) | Triggered when logs upload process is done or stopped |


<a name="event.onFirmwareUpdateInfoReceived"></a>
## *onFirmwareUpdateInfoReceived [<sup>event</sup>](#head.Notifications)*

Triggered when the `getFirmwareUpdateInfo` asynchronous method is invoked.  
Update details are:  
* `0` - A new firmware version is available.  
* `1` - The firmware version is at the current version.  
* `2` - XCONF did not return a firmware version (timeout or other XCONF error).  
* `3` - The device is configured not to update the firmware (`swupdate.conf` exists on the device).

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.status | integer | The firmware update status |
| params.responseString | string | A custom response |
| params?.firmwareUpdateVersion | string | <sup>*(optional)*</sup> The next firmware update version |
| params.rebootImmediately | boolean | The value `true` indicates that the device has to be rebooted immediately or `false` otherwise |
| params.updateAvailable | boolean | The value `false` indicates that there is no update available, either because there was no firmware update version returned from XCONF, or because the version returned from XCONF matches the version already on the device. The value of `true` indicates there is a firmware version available for update |
| params.updateAvailableEnum | integer | The update available details (must be one of the following: *0*, *1*, *2*, *3*) |
| params.success | boolean | Whether the request succeeded |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFirmwareUpdateInfoReceived",
    "params": {
        "status": 0,
        "responseString": "...",
        "firmwareUpdateVersion": "AB121AEI_VBN_1911_sprint_20200109040424sdy",
        "rebootImmediately": true,
        "updateAvailable": true,
        "updateAvailableEnum": 0,
        "success": true
    }
}
```

<a name="event.onFirmwareUpdateStateChange"></a>
## *onFirmwareUpdateStateChange [<sup>event</sup>](#head.Notifications)*

Triggered when the state of a firmware update changes.  
State details are:  
* `0`: Uninitialized - there is no firmware update in progress  
* `1`: Requesting - requesting firmware update information  
* `2`: Downloading  
* `3`: Failed  
* `4`: Download Complete  
* `5`: Validation Complete  
* `6`: Preparing to Reboot.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.firmwareUpdateStateChange | integer | The state (must be one of the following: *Uninitialized*, *Requesting*, *Downloading*, *Failed*, *DownLoad Complete*, *Validation Complete*, *Preparing to Reboot*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFirmwareUpdateStateChange",
    "params": {
        "firmwareUpdateStateChange": 5
    }
}
```

<a name="event.onMacAddressesRetreived"></a>
## *onMacAddressesRetreived [<sup>event</sup>](#head.Notifications)*

Triggered when the `getMacAddresses` asynchronous method is invoked.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.ecm_mac | string | The embedded cable modem MAC address |
| params.estb_mac | string | The embedded set-top box MAC address |
| params.moca_mac | string | The MOCA MAC address |
| params.eth_mac | string | The Ethernet MAC address |
| params.wifi_mac | string | The Wifi MAC address |
| params.bluetooth_mac | string | The Bluetooth MAC address |
| params.rf4ce_mac | string | The Rf4ce MAC address |
| params?.info | string | <sup>*(optional)*</sup> Additional information (only if any of the above data is missing) |
| params.success | boolean | Whether the request succeeded |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onMacAddressesRetreived",
    "params": {
        "ecm_mac": "A8:11:XX:FD:0C:XX",
        "estb_mac": "A8:11:XX:FD:0C:XX",
        "moca_mac": "00:15:5F:XX:20:5E:57:XX",
        "eth_mac": "A8:11:XX:FD:0C:XX",
        "wifi_mac": "A8:11:XX:FD:0C:XX",
        "bluetooth_mac": "AA:AA:AA:AA:AA:AA",
        "rf4ce_mac": "00:00:00:00:00:00",
        "info": "Details fetch: all are not success",
        "success": true
    }
}
```

<a name="event.onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the network standby mode setting changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.nwStandby | boolean | Network standby mode |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onNetworkStandbyModeChanged",
    "params": {
        "nwStandby": true
    }
}
```

<a name="event.onRebootRequest"></a>
## *onRebootRequest [<sup>event</sup>](#head.Notifications)*

Triggered when an application invokes the reboot method.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.requestedApp | string | The source of the reboot |
| params.rebootReason | string | The reboot reason |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onRebootRequest",
    "params": {
        "requestedApp": "SystemPlugin",
        "rebootReason": "FIRMWARE_FAILURE"
    }
}
```

<a name="event.onSystemClockSet"></a>
## *onSystemClockSet [<sup>event</sup>](#head.Notifications)*

Triggered when the clock on the set-top device is updated.

### Parameters

This event carries no parameters.

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSystemClockSet"
}
```

<a name="event.onSystemModeChanged"></a>
## *onSystemModeChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the device operating mode changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.mode | string | The mode (must be one of the following: *NORMAL*, *EAS*, *WAREHOUSE*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSystemModeChanged",
    "params": {
        "mode": "NORMAL"
    }
}
```

<a name="event.onSystemPowerStateChanged"></a>
## *onSystemPowerStateChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the power manager detects a device power state change.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.powerState | string | The power state (must be one of the following: *STANDBY*, *DEEP_SLEEP*, *LIGHT_SLEEP*, *ON*) |
| params.currentPowerState | string | The current power state |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onSystemPowerStateChanged",
    "params": {
        "powerState": "ON",
        "currentPowerState": "ON"
    }
}
```

<a name="event.onFriendlyNameChanged"></a>
## *onFriendlyNameChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the device friendly name change.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.friendlyName | string | The friendly name of the device which used to display on the client device list |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onFriendlyNameChanged",
    "params": {
        "friendlyName": "My Device"
    }
}
```

<a name="event.onTemperatureThresholdChanged"></a>
## *onTemperatureThresholdChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the device temperature changes beyond the `WARN` or `MAX` limits (see `setTemperatureThresholds`). Not supported on all devices.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.thresholdType | string | The exceeded threshold (must be one of the following: *MAX*, *MIN*) |
| params.exceeded | boolean | Whether the threshold exceeded the configured value |
| params.temperature | string | The temperature |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onTemperatureThresholdChanged",
    "params": {
        "thresholdType": "MAX",
        "exceeded": true,
        "temperature": "48.000000"
    }
}
```

<a name="event.onTerritoryChanged"></a>
## *onTerritoryChanged [<sup>event</sup>](#head.Notifications)*

Triggered when the device territory changed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.oldTerritory | string |  old territory |
| params.newTerritory | string |  new territory |
| params.oldRegion | string | old region |
| params.newRegion | string | new region |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onTerritoryChanged",
    "params": {
        "oldTerritory": "GBR",
        "newTerritory": "USA",
        "oldRegion": "GB-ENG",
        "newRegion": "US-NY"
    }
}
```

<a name="event.onDeviceMgtUpdateReceived"></a>
## *onDeviceMgtUpdateReceived [<sup>event</sup>](#head.Notifications)*

Triggered when the device management update completes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.source | string | Source information from where the event on update is posted |
| params.type | string |  Type of Update received currently it will be used as initial |
| params.success | boolean | Status information of update whether success or failure |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeviceMgtUpdateReceived",
    "params": {
        "source": "rfc",
        "type": "initial",
        "success": true
    }
}
```

<a name="event.onTimeZoneDSTChanged"></a>
## *onTimeZoneDSTChanged [<sup>event</sup>](#head.Notifications)*

Triggered when device time zone changed.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.oldTimeZone | string | old time zone |
| params.newTimeZone | string | new time zone |
| params.oldAccuracy | string | old time zone accuracy |
| params.newAccuracy | string | new time zone accuracy |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onTimeZoneDSTChanged",
    "params": {
        "oldTimeZone": "America/New_York",
        "newTimeZone": "Europe/London",
        "oldAccuracy": "INITIAL",
        "newAccuracy": "FINAL"
    }
}
```

<a name="event.onLogUpload"></a>
## *onLogUpload [<sup>event</sup>](#head.Notifications)*

Triggered when logs upload process is done or stopped.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.logUploadStatus | string | Upload status (must be one of the following: *UPLOAD_SUCCESS*, *UPLOAD_FAILURE*, *UPLOAD_ABORTED*) |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onLogUpload",
    "params": {
        "logUploadStatus": "UPLOAD_SUCCESS"
    }
}
```
