<!-- Generated automatically, DO NOT EDIT! -->
<a id="head.IPowerManager_Plugin"></a>
# IPowerManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/rdkservices/blob/main/IPowerManager/CHANGELOG.md)**

A IPowerManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#head.Abbreviation,_Acronyms_and_Terms)
- [Description](#head.Description)
- [Configuration](#head.Configuration)
- [Methods](#head.Methods)
- [Properties](#head.Properties)

<a id="head.Abbreviation,_Acronyms_and_Terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](userguide/aat.md)]

<a id="head.Description"></a>
# Description

The `IPowerManager` plugin provides an interface for IPowerManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](#ref.Thunder)].

<a id="head.Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: *IPowerManager*) |
| classname | string | Class name: *IPowerManager* |
| locator | string | Library name: *libWPEFrameworkIPowerManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="head.Methods"></a>
# Methods

The following methods are provided by the IPowerManager plugin:

IPowerManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [AddPowerModePreChangeClient](#method.AddPowerModePreChangeClient) | Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`.  |
| [DelayPowerModeChangeBy](#method.DelayPowerModeChangeBy) | Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used. |
| [GetNetworkStandbyMode](#method.GetNetworkStandbyMode) | Get the standby mode for Network |
| [GetPowerState](#method.GetPowerState) | Get Power State |
| [GetPowerStateBeforeReboot](#method.GetPowerStateBeforeReboot) | Get Power state before reboot |
| [GetTemperatureThresholds](#method.GetTemperatureThresholds) | Get Temperature Thresholds |
| [GetThermalState](#method.GetThermalState) | Get Current Thermal State (temperature) |
| [GetWakeupSrcConfig](#method.GetWakeupSrcConfig) | Get the source configuration for device wakeup |
| [OnDeepSleepTimeout](#method.OnDeepSleepTimeout) | Deep sleep timeout event |
| [OnNetworkStandbyModeChanged](#method.OnNetworkStandbyModeChanged) | Network Standby Mode changed event - only on XIone |
| [OnPowerModeChanged](#method.OnPowerModeChanged) | Power mode changed |
| [OnPowerModePreChange](#method.OnPowerModePreChange) | Power mode Pre-change event |
| [OnRebootBegin](#method.OnRebootBegin) | Reboot begin event |
| [OnThermalModeChanged](#method.OnThermalModeChanged) | Thermal Mode changed event |
| [PowerModePreChangeComplete](#method.PowerModePreChangeComplete) | Pre power mode handling complete for given client and transation id |
| [Reboot](#method.Reboot) | Reboot device |
| [RemovePowerModePreChangeClient](#method.RemovePowerModePreChangeClient) | Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications. |
| [SetPowerState](#method.SetPowerState) | Set Power State |
| [SetSystemMode](#method.SetSystemMode) | System mode change |
| [SetTemperatureThresholds](#method.SetTemperatureThresholds) | Set Temperature Thresholds |
| [SetWakeupSrcConfig](#method.SetWakeupSrcConfig) | Set the source configuration for device wakeup |

<a id="method.AddPowerModePreChangeClient"></a>
## *AddPowerModePreChangeClient [<sup>method</sup>](#head.Methods)*

Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`. 

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.clientName | string | Name of the client |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.clientId | uint32_t | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.AddPowerModePreChangeClient",
    "params": {
        "clientName": ""
    }
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "clientId": "0"
    }
}
```
<a id="method.DelayPowerModeChangeBy"></a>
## *DelayPowerModeChangeBy [<sup>method</sup>](#head.Methods)*

Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.clientId | uint32_t | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.delayPeriod | int | delay in seconds |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.DelayPowerModeChangeBy",
    "params": {
        "clientId": "0",
        "transactionId": "0",
        "delayPeriod": "0"
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
<a id="method.GetNetworkStandbyMode"></a>
## *GetNetworkStandbyMode [<sup>method</sup>](#head.Methods)*

Get the standby mode for Network

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.standbyMode | bool | Network standby mode |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetNetworkStandbyMode"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "standbyMode": "true"
    }
}
```
<a id="method.GetPowerState"></a>
## *GetPowerState [<sup>method</sup>](#head.Methods)*

Get Power State

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.currentState | PowerState | Current Power State |
| result.previousState | PowerState |  |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetPowerState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "currentState": "POWER_STATE_UNKNOWN",
        "previousState": "POWER_STATE_UNKNOWN"
    }
}
```
<a id="method.GetPowerStateBeforeReboot"></a>
## *GetPowerStateBeforeReboot [<sup>method</sup>](#head.Methods)*

Get Power state before reboot

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.powerStateBeforeReboot | PowerState | power state |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetPowerStateBeforeReboot"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "powerStateBeforeReboot": "POWER_STATE_UNKNOWN"
    }
}
```
<a id="method.GetTemperatureThresholds"></a>
## *GetTemperatureThresholds [<sup>method</sup>](#head.Methods)*

Get Temperature Thresholds

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.high | float | high threshold |
| result.critical | float | critical threshold |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetTemperatureThresholds"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "high": "0.0",
        "critical": "0.0"
    }
}
```
<a id="method.GetThermalState"></a>
## *GetThermalState [<sup>method</sup>](#head.Methods)*

Get Current Thermal State (temperature)

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.currentTemperature | float | current temperature |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetThermalState"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "currentTemperature": "0.0"
    }
}
```
<a id="method.GetWakeupSrcConfig"></a>
## *GetWakeupSrcConfig [<sup>method</sup>](#head.Methods)*

Get the source configuration for device wakeup

### Events
No events are associated with this method.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result.powerMode | int | power mode |
| result.srcType | int | source type |
| result.config | int | config |

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetWakeupSrcConfig"
}
```

#### Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "powerMode": "0",
        "srcType": "0",
        "config": "0"
    }
}
```
<a id="method.OnDeepSleepTimeout"></a>
## *OnDeepSleepTimeout [<sup>method</sup>](#head.Methods)*

Deep sleep timeout event

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.wakeupTimeout | int | Deep sleep wakeup timeout in seconds |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnDeepSleepTimeout",
    "params": {
        "wakeupTimeout": "0"
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
<a id="method.OnNetworkStandbyModeChanged"></a>
## *OnNetworkStandbyModeChanged [<sup>method</sup>](#head.Methods)*

Network Standby Mode changed event - only on XIone

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.enabled | bool | network standby enabled or disabled |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnNetworkStandbyModeChanged",
    "params": {
        "enabled": "true"
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
<a id="method.OnPowerModeChanged"></a>
## *OnPowerModeChanged [<sup>method</sup>](#head.Methods)*

Power mode changed

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.currentState | PowerState | Current Power State |
| params.newState | PowerState | Changing power state to this New Power State |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnPowerModeChanged",
    "params": {
        "currentState": "POWER_STATE_UNKNOWN",
        "newState": "POWER_STATE_UNKNOWN"
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
<a id="method.OnPowerModePreChange"></a>
## *OnPowerModePreChange [<sup>method</sup>](#head.Methods)*

Power mode Pre-change event

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.currentState | PowerState | Current Power State |
| params.newState | PowerState | Changing power state to this New Power State |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.stateChangeAfter | int | seconds after which the actual power mode will be applied. |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnPowerModePreChange",
    "params": {
        "currentState": "POWER_STATE_UNKNOWN",
        "newState": "POWER_STATE_UNKNOWN",
        "transactionId": "0",
        "stateChangeAfter": "0"
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
<a id="method.OnRebootBegin"></a>
## *OnRebootBegin [<sup>method</sup>](#head.Methods)*

Reboot begin event

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.rebootReasonCustom | string | Reboot reason custom |
| params.rebootReasonOther | string | Reboot reason other |
| params.rebootRequestor | string | Reboot requested by |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnRebootBegin",
    "params": {
        "rebootReasonCustom": "",
        "rebootReasonOther": "",
        "rebootRequestor": ""
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
<a id="method.OnThermalModeChanged"></a>
## *OnThermalModeChanged [<sup>method</sup>](#head.Methods)*

Thermal Mode changed event

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.currentThermalLevel | ThermalTemperature | current thermal level |
| params.newThermalLevel | ThermalTemperature | new thermal level |
| params.currentTemperature | float | current temperature |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.OnThermalModeChanged",
    "params": {
        "currentThermalLevel": "THERMAL_TEMPERATURE_UNKNOWN",
        "newThermalLevel": "THERMAL_TEMPERATURE_UNKNOWN",
        "currentTemperature": "0.0"
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
<a id="method.PowerModePreChangeComplete"></a>
## *PowerModePreChangeComplete [<sup>method</sup>](#head.Methods)*

Pre power mode handling complete for given client and transation id

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.clientId | uint32_t | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.PowerModePreChangeComplete",
    "params": {
        "clientId": "0",
        "transactionId": "0"
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
<a id="method.Reboot"></a>
## *Reboot [<sup>method</sup>](#head.Methods)*

Reboot device

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.rebootRequestor | string | Reboot requested by |
| params.rebootReasonCustom | string | Reboot reason custom |
| params.rebootReasonOther | string | Reboot reason other |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.Reboot",
    "params": {
        "rebootRequestor": "",
        "rebootReasonCustom": "",
        "rebootReasonOther": ""
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
<a id="method.RemovePowerModePreChangeClient"></a>
## *RemovePowerModePreChangeClient [<sup>method</sup>](#head.Methods)*

Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications.

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.clientId | uint32_t | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.RemovePowerModePreChangeClient",
    "params": {
        "clientId": "0"
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
<a id="method.SetPowerState"></a>
## *SetPowerState [<sup>method</sup>](#head.Methods)*

Set Power State

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.keyCode | int |  |
| params.powerState | PowerState | Set power to this state |
| params.reason | string | Reason for moving to the power state |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetPowerState",
    "params": {
        "keyCode": "0",
        "powerState": "POWER_STATE_UNKNOWN",
        "reason": ""
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
<a id="method.SetSystemMode"></a>
## *SetSystemMode [<sup>method</sup>](#head.Methods)*

System mode change

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.currentMode | SystemMode |  |
| params.newMode | SystemMode | new mode |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetSystemMode",
    "params": {
        "currentMode": "SYSTEM_MODE_UNKNOWN",
        "newMode": "SYSTEM_MODE_UNKNOWN"
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
<a id="method.SetTemperatureThresholds"></a>
## *SetTemperatureThresholds [<sup>method</sup>](#head.Methods)*

Set Temperature Thresholds

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.high | float | high threshold |
| params.critical | float | critical threshold |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetTemperatureThresholds",
    "params": {
        "high": "0.0",
        "critical": "0.0"
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
<a id="method.SetWakeupSrcConfig"></a>
## *SetWakeupSrcConfig [<sup>method</sup>](#head.Methods)*

Set the source configuration for device wakeup

### Events
No events are associated with this method.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params.powerMode | int | power mode |
| params.wakeSrcType | int | source type |
| params.config | int | config |
### Results
This method returns no results.

### Examples


#### Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetWakeupSrcConfig",
    "params": {
        "powerMode": "0",
        "wakeSrcType": "0",
        "config": "0"
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

<a id="head.Properties"></a>
# Properties
The following properties are provided by the IPowerManager plugin:

IPowerManager interface properties:

| Method | Description |
| :-------- | :-------- |
| [GetLastWakeupKeyCode](#property.GetLastWakeupKeyCode)<sup>RO</sup> | Get the key code that can be used for wakeup |
| [GetLastWakeupReason](#property.GetLastWakeupReason)<sup>RO</sup> | Get Last Wake up reason |
| [GetOvertempGraceInterval](#property.GetOvertempGraceInterval)<sup>RO</sup> | Get Temperature Grace interval |
| [SetDeepSleepTimer](#property.SetDeepSleepTimer)<sup>WO</sup> | Set Deep sleep timer for timeOut period |
| [SetNetworkStandbyMode](#property.SetNetworkStandbyMode)<sup>WO</sup> | Set the standby mode for Network |
| [SetOvertempGraceInterval](#property.SetOvertempGraceInterval)<sup>WO</sup> | Set Temperature Thresholds |

<a id="property.GetLastWakeupKeyCode"></a>
## *GetLastWakeupKeyCode [<sup>property</sup>](#head.Properties)*

Get the key code that can be used for wakeup

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).keycode | int | Key code for wakeup |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetLastWakeupKeyCode"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "keycode": "0"
    }
}
```
<a id="property.GetLastWakeupReason"></a>
## *GetLastWakeupReason [<sup>property</sup>](#head.Properties)*

Get Last Wake up reason

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).wakeupReason | WakeupReason | wake up reason |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetLastWakeupReason"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "wakeupReason": "WAKEUP_REASON_UNKNOWN"
    }
}
```
<a id="property.GetOvertempGraceInterval"></a>
## *GetOvertempGraceInterval [<sup>property</sup>](#head.Properties)*

Get Temperature Grace interval

> This property is read-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).graceInterval | int | interval in secs? |

### Examples


#### Get Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.GetOvertempGraceInterval"
}
```

#### Get Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": {
        "graceInterval": "0"
    }
}
```
<a id="property.SetDeepSleepTimer"></a>
## *SetDeepSleepTimer [<sup>property</sup>](#head.Properties)*

Set Deep sleep timer for timeOut period

> This property is write-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).timeOut | int | deep sleep timeout |

### Examples


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetDeepSleepTimer",
    "params": {
        "timeOut": "0"
    }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="property.SetNetworkStandbyMode"></a>
## *SetNetworkStandbyMode [<sup>property</sup>](#head.Properties)*

Set the standby mode for Network

> This property is write-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).standbyMode | bool | Network standby mode |

### Examples


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetNetworkStandbyMode",
    "params": {
        "standbyMode": "true"
    }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
<a id="property.SetOvertempGraceInterval"></a>
## *SetOvertempGraceInterval [<sup>property</sup>](#head.Properties)*

Set Temperature Thresholds

> This property is write-only.
### Events
No events are associated with this method.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).graceInterval | int | interval in secs? |

### Examples


#### Set Request

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "method": "org.rdk.IPowerManager.SetOvertempGraceInterval",
    "params": {
        "graceInterval": "0"
    }
}
```

#### Set Response

```json
{
    "jsonrpc": "2.0",
    "id": 42,
    "result": "null"
}
```
