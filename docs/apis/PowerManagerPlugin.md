<!-- Generated automatically, DO NOT EDIT! -->
<a name="PowerManager_Plugin"></a>
# PowerManager Plugin

**Version: [1.0.0]()**

A org.rdk.PowerManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#Abbreviation,_Acronyms_and_Terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Notifications](#Notifications)

<a name="Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a name="Description"></a>
# Description

The `PowerManager` that is responsible for persisting and notifying listeners of any change of these settings.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#Thunder)].

<a name="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *org.rdk.PowerManager*) |
| classname | string | Class name: *org.rdk.PowerManager* |
| locator | string | Library name: *libWPEFrameworkPowerManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a name="Methods"></a>
# Methods

The following methods are provided by the org.rdk.PowerManager plugin:

org.rdk.PowerManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [getOvertempGraceInterval](#getOvertempGraceInterval) | Returns the over-temperature grace interval value |
| [getPowerState](#getPowerState) | Returns the current power state of the device |
| [getThermalState](#getThermalState) | Returns temperature threshold values |
| [getTemperatureThresholds](#getTemperatureThresholds) | Returns temperature threshold values |
| [setOvertempGraceInterval](#setOvertempGraceInterval) | Sets the over-temperature grace interval value |
| [setPowerState](#setPowerState) | Sets the power state of the device |
| [setDeepSleepTimer](#setDeepSleepTimer) | Sets the deep sleep timeout period |
| [getLastWakeupReason](#getLastWakeupReason) | Returns the reason for the device coming out of deep sleep |
| [getLastWakeupKeyCode](#getLastWakeupKeyCode) | Returns the last wakeup keycode |
| [reboot](#reboot) | Requests that the system performs a reboot of the set-top box |
| [getNetworkStandbyMode](#getNetworkStandbyMode) | Returns the network standby mode of the device |
| [setNetworkStandbyMode](#setNetworkStandbyMode) | This API will be deprecated in the future |
| [setWakeupSrcConfig](#setWakeupSrcConfig) | Sets the wakeup source configuration for the input powerState |
| [getWakeupSrcConfig](#getWakeupSrcConfig) | Returns all the supported wakeup configurations and powerState |
| [setSystemMode](#setSystemMode) | Sets the mode of the set-top box for a specific duration before returning to normal mode |
| [getPowerStateBeforeReboot](#getPowerStateBeforeReboot) | Returns the power state before reboot |
| [setTemperatureThresholds](#setTemperatureThresholds) | Sets the temperature threshold values |


<a name="getOvertempGraceInterval"></a>
## *getOvertempGraceInterval*

Returns the over-temperature grace interval value. Not supported on all devices.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.graceInterval | integer |  |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getOvertempGraceInterval"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "graceInterval": 60
    }
}
```

<a name="getPowerState"></a>
## *getPowerState*

Returns the current power state of the device. The power state (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*).

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentState | string | The current power state |
| result.newState | string | The new power state |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getPowerState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "currentState": "STANDBY",
        "newState": "ON"
    }
}
```

<a name="getThermalState"></a>
## *getThermalState*

Returns temperature threshold values. Not supported on all devices.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result?.currentTemperature | float | <sup>*(optional)*</sup> The temperature |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getThermalState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "currentTemperature": 48.0
    }
}
```

<a name="getTemperatureThresholds"></a>
## *getTemperatureThresholds*

Returns temperature threshold values. Not supported on all devices.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.high | float | The warning threshold |
| result.critical | float | The max temperature threshold |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getTemperatureThresholds"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "high": 100.0,
        "critical": 110.0
    }
}
```

<a name="setOvertempGraceInterval"></a>
## *setOvertempGraceInterval*

Sets the over-temperature grace interval value. Not supported on all devices.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.graceInterval | integer |  |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setOvertempGraceInterval",
    "params": {
        "graceInterval": 60
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="setPowerState"></a>
## *setPowerState*

Sets the power state of the device.

### Events

| Event | Description |
| :-------- | :-------- |
| [onPowerModeChanged](#onPowerModeChanged) | Triggers when the system power state changes. The power state (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*) |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.keyCode | integer | <sup>*(optional)*</sup> power state changed keycode |
| params.powerState | string | Set the new power state |
| params.standbyReason | string | The reason for a standby state |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setPowerState",
    "params": {
        "keyCode": 30,
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
    "result": "null"
}
```

<a name="setDeepSleepTimer"></a>
## *setDeepSleepTimer*

Sets the deep sleep timeout period.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.timeOut | integer | <sup>*(optional)*</sup> The deep sleep timeout in seconds |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setDeepSleepTimer",
    "params": {
        "timeOut": 3
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="getLastWakeupReason"></a>
## *getLastWakeupReason*

Returns the reason for the device coming out of deep sleep.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupReason | integer | The reason (must be one of the following: *WAKEUP_REASON_IR*, *WAKEUP_REASON_RCU_BT*, *WAKEUP_REASON_RCU_RF4CE*, *WAKEUP_REASON_GPIO*, *WAKEUP_REASON_LAN*, *WAKEUP_REASON_WLAN*, *WAKEUP_REASON_TIMER*, *WAKEUP_REASON_FRONT_PANEL*, *WAKEUP_REASON_WATCHDOG*, *WAKEUP_REASON_SOFTWARE_RESET*, *WAKEUP_REASON_THERMAL_RESET*, *WAKEUP_REASON_WARM_RESET*, *WAKEUP_REASON_COLDBOOT*, *WAKEUP_REASON_STR_AUTH_FAILURE*, *WAKEUP_REASON_CEC*, *WAKEUP_REASON_PRESENCE*, *WAKEUP_REASON_VOICE*, *WAKEUP_REASON_UNKNOWN*) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getLastWakeupReason"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "wakeupReason": 7
    }
}
```

<a name="getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode*

Returns the last wakeup keycode.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupKeyCode | integer | The last wakeup keycode |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getLastWakeupKeyCode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "wakeupKeyCode": 59
    }
}
```

<a name="reboot"></a>
## *reboot*

Requests that the system performs a reboot of the set-top box.

### Events

| Event | Description |
| :-------- | :-------- |
| [onRebootBegin](#onRebootBegin) | Triggers when a device reboot request is made |
### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.rebootRequestor | string | <sup>*(optional)*</sup> Reboot requiested module |
| params?.rebootReasonCustom | string | <sup>*(optional)*</sup> The reboot reason |
| params?.rebootReasonOther | string | <sup>*(optional)*</sup> The reboot reason |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.IARM_Bus_Call_STATUS | integer | IARM BUS status |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.reboot",
    "params": {
        "rebootRequestor": "SystemServicesPlugin",
        "rebootReasonCustom": "FIRMWARE_FAILURE",
        "rebootReasonOther": "FIRMWARE_FAILURE"
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "IARM_Bus_Call_STATUS": 0
    }
}
```

<a name="getNetworkStandbyMode"></a>
## *getNetworkStandbyMode*

Returns the network standby mode of the device. If network standby is `true`, the device supports `WakeOnLAN` and `WakeOnWLAN` actions in STR mode.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.standbyMode | boolean | Whether `WakeOnLAN` and `WakeOnWLAN` is enabled (`true`); otherwise, `false` |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getNetworkStandbyMode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "standbyMode": false
    }
}
```

<a name="setNetworkStandbyMode"></a>
## *setNetworkStandbyMode*

This API will be deprecated in the future. Please refer setWakeupSrcConfiguration to Migrate. This API Enables or disables the network standby mode of the device. If network standby is enabled, the device supports `WakeOnLAN` and `WakeOnWLAN` actions in STR mode.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.standbyMode | boolean | Whether `WakeOnLAN` and `WakeOnWLAN` is enabled (`true`); otherwise, `false` |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setNetworkStandbyMode",
    "params": {
        "standbyMode": false
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="setWakeupSrcConfig"></a>
## *setWakeupSrcConfig*

Sets the wakeup source configuration for the input powerState. if you are using setNetworkStandbyMode API, Please do not use this API to set LAN and WIFI wakeup. Please migrate to setWakeupSrcConfiguration API to control all wakeup source settings. This API does not persist. Please call this API on Every bootup to set the values.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.powerState | integer | <sup>*(optional)*</sup> Enum indicating bit position, If the reason is STANDBY, the value is 4(bit counting starts at 1) (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*) |
| params.wakeupSources | integer | Enum indicating bit position, If the reason is LAN, the value is 32(bit counting starts at 1) (must be one of the following: *WAKEUP_REASON_IR*, *WAKEUP_REASON_RCU_BT*, *WAKEUP_REASON_RCU_RF4CE*, *WAKEUP_REASON_GPIO*, *WAKEUP_REASON_LAN*, *WAKEUP_REASON_WLAN*, *WAKEUP_REASON_TIMER*, *WAKEUP_REASON_FRONT_PANEL*, *WAKEUP_REASON_WATCHDOG*, *WAKEUP_REASON_SOFTWARE_RESET*, *WAKEUP_REASON_THERMAL_RESET*, *WAKEUP_REASON_WARM_RESET*, *WAKEUP_REASON_COLDBOOT*, *WAKEUP_REASON_STR_AUTH_FAILURE*, *WAKEUP_REASON_CEC*, *WAKEUP_REASON_PRESENCE*, *WAKEUP_REASON_VOICE*, *WAKEUP_REASON_UNKNOWN*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setWakeupSrcConfig",
    "params": {
        "powerState": 4,
        "wakeupSources": 6
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="getWakeupSrcConfig"></a>
## *getWakeupSrcConfig*

Returns all the supported wakeup configurations and powerState.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerState | integer | Enum indicating bit position, If the reason is STANDBY, the value is 4(bit counting starts at 1) (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*) |
| result.wakeupSources | integer | Enum indicating bit position, If the reason is LAN, the value is 32(bit counting starts at 1) (must be one of the following: *WAKEUP_REASON_IR*, *WAKEUP_REASON_RCU_BT*, *WAKEUP_REASON_RCU_RF4CE*, *WAKEUP_REASON_GPIO*, *WAKEUP_REASON_LAN*, *WAKEUP_REASON_WLAN*, *WAKEUP_REASON_TIMER*, *WAKEUP_REASON_FRONT_PANEL*, *WAKEUP_REASON_WATCHDOG*, *WAKEUP_REASON_SOFTWARE_RESET*, *WAKEUP_REASON_THERMAL_RESET*, *WAKEUP_REASON_WARM_RESET*, *WAKEUP_REASON_COLDBOOT*, *WAKEUP_REASON_STR_AUTH_FAILURE*, *WAKEUP_REASON_CEC*, *WAKEUP_REASON_PRESENCE*, *WAKEUP_REASON_VOICE*, *WAKEUP_REASON_UNKNOWN*) |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getWakeupSrcConfig"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "powerState": 4,
        "wakeupSources": 6
    }
}
```

<a name="setSystemMode"></a>
## *setSystemMode*

Sets the mode of the set-top box for a specific duration before returning to normal mode. Valid modes are:  
* `NORMAL` - The set-top box is operating in normal mode.  
* `EAS` - The set-top box is operating in Emergency Alert System (EAS) mode. This mode is set when the device needs to perform certain tasks when entering EAS mode, such as setting the clock display or preventing the user from using the diagnostics menu.  
* `WAREHOUSE` - The set-top box is operating in warehouse mode.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentMode | integer | Indicates the current operating mode of the STB (must be one of the following: *UNKNOWN*, *NORMAL*, *EAS*, *WAREHOUSE*) |
| params.newMode | integer | Sets the desired operating mode for the STB (must be one of the following: *UNKNOWN*, *NORMAL*, *EAS*, *WAREHOUSE*) |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setSystemMode",
    "params": {
        "currentMode": 2,
        "newMode": 1
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot*

Returns the power state before reboot.

### Events

No Events

### Parameters

This method takes no parameters.

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result?.powerStateBeforeReboot | string | <sup>*(optional)*</sup> The power state |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.getPowerStateBeforeReboot"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "powerStateBeforeReboot": "ON"
    }
}
```

<a name="setTemperatureThresholds"></a>
## *setTemperatureThresholds*

Sets the temperature threshold values. Not supported on all devices.

### Events

No Events

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.high | float | The warning threshold |
| params.critical | float | The max temperature threshold |

### Result

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | string | On success null will be returned |

### Errors

| Code | Message | Description |
| :-------- | :-------- | :-------- |
| 1 | ```ERROR_GENERAL``` | General error |

### Example

#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.PowerManager.setTemperatureThresholds",
    "params": {
        "high": 100.0,
        "critical": 110.0
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```

<a name="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#Thunder)] for information on how to register for a notification.

The following events are provided by the org.rdk.PowerManager plugin:

org.rdk.PowerManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onRebootBegin](#onRebootBegin) | Triggered when an application invokes the reboot method |
| [onPowerModeChanged](#onPowerModeChanged) | Triggered when the power manager detects a device power state change |
| [onPowerModePreChange](#onPowerModePreChange) | Triggered before change then device power state |
| [onDeepSleepTimeout](#onDeepSleepTimeout) | Triggered when the power manager detects a device power state change to light sleep from deep sleep |
| [onNetworkStandbyModeChanged](#onNetworkStandbyModeChanged) | Triggered when the network standby mode setting changes |
| [onThermalModeChanged](#onThermalModeChanged) | Triggered when the device temperature changes beyond the `WARN` or `MAX` limits (see `setTemperatureThresholds`) |


<a name="onRebootBegin"></a>
## *onRebootBegin*

Triggered when an application invokes the reboot 

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
    "method": "client.events.onRebootBegin",
    "params": {
        "requestedApp": "SystemPlugin",
        "rebootReason": "FIRMWARE_FAILURE"
    }
}
```

<a name="onPowerModeChanged"></a>
## *onPowerModeChanged*

Triggered when the power manager detects a device power state change. The power state (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*).

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | The current power state |
| params.newState | string | The new power state |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onPowerModeChanged",
    "params": {
        "currentState": "STANDBY",
        "newState": "ON"
    }
}
```

<a name="onPowerModePreChange"></a>
## *onPowerModePreChange*

Triggered before change then device power state. The power state (must be one of the following: *OFF*, *STANDBY*, *ON*, *LIGHT_SLEEP*, *DEEP_SLEEP*).

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | The current power state |
| params?.newState | string | <sup>*(optional)*</sup> The new power state |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onPowerModePreChange",
    "params": {
        "currentState": "STANDBY",
        "newState": "ON"
    }
}
```

<a name="onDeepSleepTimeout"></a>
## *onDeepSleepTimeout*

Triggered when the power manager detects a device power state change to light sleep from deep sleep.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.wakeupTimeout | integer | <sup>*(optional)*</sup> Timeout in seconds, to wakeup from deep sleep |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onDeepSleepTimeout",
    "params": {
        "wakeupTimeout": 30
    }
}
```

<a name="onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged*

Triggered when the network standby mode setting changes.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | boolean | Network standby mode |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onNetworkStandbyModeChanged",
    "params": {
        "enabled": true
    }
}
```

<a name="onThermalModeChanged"></a>
## *onThermalModeChanged*

Triggered when the device temperature changes beyond the `WARN` or `MAX` limits (see `setTemperatureThresholds`). Not supported on all devices.

### Parameters

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params?.currentThermalLevel | string | <sup>*(optional)*</sup> The exceeded threshold |
| params?.newThermalLevel | string | <sup>*(optional)*</sup> The exceeded threshold |
| params?.currentTemperature | float | <sup>*(optional)*</sup> The temperature |

### Example

```json
{
    "jsonrpc": "2.0",
    "method": "client.events.onThermalModeChanged",
    "params": {
        "currentThermalLevel": "HIGH",
        "newThermalLevel": "NORMAL",
        "currentTemperature": 48.0
    }
}
```

