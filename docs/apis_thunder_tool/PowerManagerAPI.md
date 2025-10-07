<!-- Generated automatically, DO NOT EDIT! -->
<a id="head_PowerManager_API"></a>
# PowerManager API

**Version: 1.0.0**

**Status: :black_circle::white_circle::white_circle:**

PowerManager interface for Thunder framework.

(Defined with IPowerManager in [IPowerManager.h](https://github.com/rdkcentral/ThunderInterfaces/blob/master/interfaces/IPowerManager.h))

### Table of Contents

- [Introduction](#head_Introduction)
- [Description](#head_Description)
- [Methods](#head_Methods)
- [Properties](#head_Properties)
- [Notifications](#head_Notifications)

<a id="head_Introduction"></a>
# Introduction

<a id="head_Scope"></a>
## Scope

This document describes purpose and functionality of the PowerManager interface (version 1.0.0). It includes detailed specification about its methods and properties as well as sent notifications.

<a id="head_Case_Sensitivity"></a>
## Case Sensitivity

All identifiers of the interfaces described in this document are case-sensitive. Thus, unless stated otherwise, all keywords, entities, properties, relations and actions should be treated as such.

<a id="head_Acronyms,_Abbreviations_and_Terms"></a>
## Acronyms, Abbreviations and Terms

The table below provides and overview of acronyms used in this document and their definitions.

| Acronym | Description |
| :-------- | :-------- |
| <a name="acronym.API">API</a> | Application Programming Interface |
| <a name="acronym.HTTP">HTTP</a> | Hypertext Transfer Protocol |
| <a name="acronym.JSON">JSON</a> | JavaScript Object Notation; a data interchange format |
| <a name="acronym.JSON-RPC">JSON-RPC</a> | A remote procedure call protocol encoded in JSON |

The table below provides and overview of terms and abbreviations used in this document and their definitions.

| Term | Description |
| :-------- | :-------- |
| <a name="term.callsign">callsign</a> | The name given to an instance of a plugin. One plugin can be instantiated multiple times, but each instance the instance name, callsign, must be unique. |

<a id="head_References"></a>
## References

| Ref ID | Description |
| :-------- | :-------- |
| <a name="ref.HTTP">[HTTP](http://www.w3.org/Protocols)</a> | HTTP specification |
| <a name="ref.JSON-RPC">[JSON-RPC](https://www.jsonrpc.org/specification)</a> | JSON-RPC 2.0 specification |
| <a name="ref.JSON">[JSON](http://www.json.org/)</a> | JSON specification |
| <a name="ref.Thunder">[Thunder](https://github.com/WebPlatformForEmbedded/Thunder/blob/master/doc/WPE%20-%20API%20-%20WPEFramework.docx)</a> | Thunder API Reference |

<a id="head_Description"></a>
# Description

PowerManager JSON-RPC interface.

<a id="head_Methods"></a>
# Methods

The following methods are provided by the PowerManager interface:

PowerManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [addPowerModePreChangeClient](#method_addPowerModePreChangeClient) | Register a client to engage in power mode state changes |
| [removePowerModePreChangeClient](#method_removePowerModePreChangeClient) | Removes a registered client from participating in power mode pre-change operations |
| [setPowerState](#method_setPowerState) | Set Power State |
| [getPowerState](#method_getPowerState) | Get Power State |
| [getThermalState](#method_getThermalState) | Get Current Thermal State (temperature) |
| [setTemperatureThresholds](#method_setTemperatureThresholds) | Set Temperature Thresholds |
| [getTemperatureThresholds](#method_getTemperatureThresholds) | Get Temperature Thresholds |
| [reboot](#method_reboot) | Reboot device |
| [getNetworkStandbyMode](#method_getNetworkStandbyMode) | Get the standby mode for Network |
| [setWakeupSourceConfig](#method_setWakeupSourceConfig) | Set the source configuration for device wakeup |
| [getWakeupSourceConfig](#method_getWakeupSourceConfig) | Get the source configuration for device wakeup |
| [setSystemMode](#method_setSystemMode) | System mode change |
| [getPowerStateBeforeReboot](#method_getPowerStateBeforeReboot) | Get Power state before reboot |
| [powerModePreChangeComplete](#method_powerModePreChangeComplete) | Pre power mode handling complete for given client and transation id |
| [delayPowerModeChangeBy](#method_delayPowerModeChangeBy) | Delay Powermode change by given time |

<a id="method_addPowerModePreChangeClient"></a>
## *addPowerModePreChangeClient [<sup>method</sup>](#head_Methods)*

Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.clientName | string | mandatory | Name of the client |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | integer | mandatory | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.addPowerModePreChangeClient",
  "params": {
    "clientName": "..."
  }
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="method_removePowerModePreChangeClient"></a>
## *removePowerModePreChangeClient [<sup>method</sup>](#head_Methods)*

Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.clientId | integer | mandatory | Unique identifier for the client. See `AddPowerModePreChangeClient` |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.removePowerModePreChangeClient",
  "params": {
    "clientId": 0
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

<a id="method_setPowerState"></a>
## *setPowerState [<sup>method</sup>](#head_Methods)*

Set Power State.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.keyCode | integer | mandatory |  |
| params.powerState | string | mandatory | Set power to this state (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |
| params.reason | string | mandatory | Reason for moving to the power state |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setPowerState",
  "params": {
    "keyCode": 0,
    "powerState": "OFF",
    "reason": "..."
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

<a id="method_getPowerState"></a>
## *getPowerState [<sup>method</sup>](#head_Methods)*

Get Power State.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.currentState | string | mandatory |  (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |
| result.previousState | string | mandatory |  (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPowerState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "currentState": "OFF",
    "previousState": "OFF"
  }
}
```

<a id="method_getThermalState"></a>
## *getThermalState [<sup>method</sup>](#head_Methods)*

Get Current Thermal State (temperature).

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | number | mandatory | Current temperature |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getThermalState"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0.0
}
```

<a id="method_setTemperatureThresholds"></a>
## *setTemperatureThresholds [<sup>method</sup>](#head_Methods)*

Set Temperature Thresholds.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.high | number | mandatory | High threshold |
| params.critical | number | mandatory | : critical threshold |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setTemperatureThresholds",
  "params": {
    "high": 0.0,
    "critical": 0.0
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

<a id="method_getTemperatureThresholds"></a>
## *getTemperatureThresholds [<sup>method</sup>](#head_Methods)*

Get Temperature Thresholds.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | object | mandatory |  |
| result.high | number | mandatory | High threshold |
| result.critical | number | mandatory | : critical threshold |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getTemperatureThresholds"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": {
    "high": 0.0,
    "critical": 0.0
  }
}
```

<a id="method_reboot"></a>
## *reboot [<sup>method</sup>](#head_Methods)*

Reboot device.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.rebootRequestor | string | mandatory |  |
| params.rebootReasonCustom | string | mandatory |  |
| params.rebootReasonOther | string | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.reboot",
  "params": {
    "rebootRequestor": "...",
    "rebootReasonCustom": "...",
    "rebootReasonOther": "..."
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

<a id="method_getNetworkStandbyMode"></a>
## *getNetworkStandbyMode [<sup>method</sup>](#head_Methods)*

Get the standby mode for Network.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | boolean | mandatory | Network standby mode |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getNetworkStandbyMode"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": false
}
```

<a id="method_setWakeupSourceConfig"></a>
## *setWakeupSourceConfig [<sup>method</sup>](#head_Methods)*

Set the source configuration for device wakeup.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.wakeupSources | array | mandatory | Wake up sources array |
| params.wakeupSources[#] | object | mandatory |  |
| params.wakeupSources[#].wakeupSource | string | mandatory |  (must be one of the following: *BLUETOOTH, CEC, IR, LAN, POWERKEY, PRESENCEDETECTED, RF4CE, TIMER, UNKNOWN, VOICE, WIFI*) |
| params.wakeupSources[#].enabled | boolean | mandatory |  |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setWakeupSourceConfig",
  "params": {
    "wakeupSources": [
      {
        "wakeupSource": "VOICE",
        "enabled": false
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
  "result": null
}
```

<a id="method_getWakeupSourceConfig"></a>
## *getWakeupSourceConfig [<sup>method</sup>](#head_Methods)*

Get the source configuration for device wakeup.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | array | mandatory | Wake up sources array |
| result[#] | object | mandatory |  |
| result[#].wakeupSource | string | mandatory |  (must be one of the following: *BLUETOOTH, CEC, IR, LAN, POWERKEY, PRESENCEDETECTED, RF4CE, TIMER, UNKNOWN, VOICE, WIFI*) |
| result[#].enabled | boolean | mandatory |  |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getWakeupSourceConfig"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": [
    {
      "wakeupSource": "VOICE",
      "enabled": false
    }
  ]
}
```

<a id="method_setSystemMode"></a>
## *setSystemMode [<sup>method</sup>](#head_Methods)*

System mode change.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.currentMode | string | mandatory |  (must be one of the following: *EAS, NORMAL, UNKNOWN, WAREHOUSE*) |
| params.newMode | string | mandatory | New mode (must be one of the following: *EAS, NORMAL, UNKNOWN, WAREHOUSE*) |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setSystemMode",
  "params": {
    "currentMode": "NORMAL",
    "newMode": "NORMAL"
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

<a id="method_getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot [<sup>method</sup>](#head_Methods)*

Get Power state before reboot.

### Parameters

This method takes no parameters.

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | string | mandatory | Power state (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getPowerStateBeforeReboot"
}
```

#### Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "OFF"
}
```

<a id="method_powerModePreChangeComplete"></a>
## *powerModePreChangeComplete [<sup>method</sup>](#head_Methods)*

Pre power mode handling complete for given client and transation id.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.clientId | integer | mandatory | Unique identifier for the client, as received in AddPowerModePreChangeClient |
| params.transactionId | integer | mandatory | Transaction id as received in OnPowerModePreChange |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.powerModePreChangeComplete",
  "params": {
    "clientId": 0,
    "transactionId": 0
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

<a id="method_delayPowerModeChangeBy"></a>
## *delayPowerModeChangeBy [<sup>method</sup>](#head_Methods)*

Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used.

### Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.clientId | integer | mandatory | Unique identifier for the client, as received in AddPowerModePreChangeClient |
| params.transactionId | integer | mandatory | Transaction id as received in OnPowerModePreChange |
| params.delayPeriod | integer | mandatory | Delay in seconds |

### Result

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| result | null | mandatory | Always null |

### Example

#### Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.delayPowerModeChangeBy",
  "params": {
    "clientId": 0,
    "transactionId": 0,
    "delayPeriod": 0
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

<a id="head_Properties"></a>
# Properties

The following properties are provided by the PowerManager interface:

PowerManager interface properties:

| Property | R/W | Description |
| :-------- | :-------- | :-------- |
| [setOvertempGraceInterval](#property_setOvertempGraceInterval) | write-only | Set Temperature Thresholds |
| [getOvertempGraceInterval](#property_getOvertempGraceInterval) | read-only | Get Temperature Grace interval |
| [setDeepSleepTimer](#property_setDeepSleepTimer) | write-only | Set Deep sleep timer for timeOut period |
| [getLastWakeupReason](#property_getLastWakeupReason) | read-only | Get Last Wake up reason |
| [getLastWakeupKeyCode](#property_getLastWakeupKeyCode) | read-only | Get the key code that can be used for wakeup |
| [setNetworkStandbyMode](#property_setNetworkStandbyMode) | write-only | Set the standby mode for Network |

<a id="property_setOvertempGraceInterval"></a>
## *setOvertempGraceInterval [<sup>property</sup>](#head_Properties)*

Provides access to the set Temperature Thresholds.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Set Temperature Thresholds |
| (property).graceInterval | integer | mandatory | Interval in secs? |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setOvertempGraceInterval",
  "params": {
    "graceInterval": 0
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

<a id="property_getOvertempGraceInterval"></a>
## *getOvertempGraceInterval [<sup>property</sup>](#head_Properties)*

Provides access to the get Temperature Grace interval.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Interval in secs? |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getOvertempGraceInterval"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_setDeepSleepTimer"></a>
## *setDeepSleepTimer [<sup>property</sup>](#head_Properties)*

Provides access to the set Deep sleep timer for timeOut period.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Set Deep sleep timer for timeOut period |
| (property).timeOut | integer | mandatory | Deep sleep timeout |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setDeepSleepTimer",
  "params": {
    "timeOut": 0
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

<a id="property_getLastWakeupReason"></a>
## *getLastWakeupReason [<sup>property</sup>](#head_Properties)*

Provides access to the get Last Wake up reason.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | string | mandatory | Wake up reason (must be one of the following: *BLUETOOTH, CEC, COLDBOOT, FRONTPANEL, GPIO, IR, LAN, PRESENCE, RF4CE, SOFTWARERESET, STR_AUTH_FAIL, THERMALRESET, TIMER, UNKNOWN, VOICE, WARMRESET, WATCHDOG, WIFI*) |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLastWakeupReason"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": "IR"
}
```

<a id="property_getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode [<sup>property</sup>](#head_Properties)*

Provides access to the get the key code that can be used for wakeup.

> This property is **read-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | integer | mandatory | Key code for wakeup |

### Example

#### Get Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.getLastWakeupKeyCode"
}
```

#### Get Response

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "result": 0
}
```

<a id="property_setNetworkStandbyMode"></a>
## *setNetworkStandbyMode [<sup>property</sup>](#head_Properties)*

Provides access to the set the standby mode for Network.

> This property is **write-only**.

### Value

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| (property) | object | mandatory | Set the standby mode for Network |
| (property).standbyMode | boolean | mandatory | Network standby mode |

### Example

#### Set Request

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.setNetworkStandbyMode",
  "params": {
    "standbyMode": false
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

<a id="head_Notifications"></a>
# Notifications

Notifications are autonomous events triggered by the internals of the implementation and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](#ref.Thunder)] for information on how to register for a notification.

The following events are provided by the PowerManager interface:

PowerManager interface events:

| Notification | Description |
| :-------- | :-------- |
| [onThermalModeChanged](#notification_onThermalModeChanged) | Thermal Mode changed event |
| [onPowerModePreChange](#notification_onPowerModePreChange) | Power mode Pre-change event |
| [onPowerModeChanged](#notification_onPowerModeChanged) | Power mode changed |
| [onRebootBegin](#notification_onRebootBegin) | Reboot begin event |
| [onNetworkStandbyModeChanged](#notification_onNetworkStandbyModeChanged) | Network Standby Mode changed event - only on XIone |
| [onDeepSleepTimeout](#notification_onDeepSleepTimeout) | Deep sleep timeout event |

<a id="notification_onThermalModeChanged"></a>
## *onThermalModeChanged [<sup>notification</sup>](#head_Notifications)*

Thermal Mode changed event.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.currentThermalLevel | string | mandatory | Current thermal level (must be one of the following: *Critial, High, Normal, UNKNOWN*) |
| params.newThermalLevel | string | mandatory | New thermal level (must be one of the following: *Critial, High, Normal, UNKNOWN*) |
| params.currentTemperature | number | mandatory | Current temperature |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onThermalModeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onThermalModeChanged",
  "params": {
    "currentThermalLevel": "Normal",
    "newThermalLevel": "Normal",
    "currentTemperature": 0.0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onThermalModeChanged``.

<a id="notification_onPowerModePreChange"></a>
## *onPowerModePreChange [<sup>notification</sup>](#head_Notifications)*

Power mode Pre-change event.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.currentState | string | mandatory | Current Power State (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |
| params.newState | string | mandatory | Changing power state to this New Power State (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |
| params.transactionId | integer | mandatory | TransactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.stateChangeAfter | integer | mandatory | Seconds after which the actual power mode will be applied |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPowerModePreChange",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPowerModePreChange",
  "params": {
    "currentState": "OFF",
    "newState": "OFF",
    "transactionId": 0,
    "stateChangeAfter": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPowerModePreChange``.

<a id="notification_onPowerModeChanged"></a>
## *onPowerModeChanged [<sup>notification</sup>](#head_Notifications)*

Power mode changed.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.currentState | string | mandatory | Current Power State (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |
| params.newState | string | mandatory | New Power State (must be one of the following: *DEEP_SLEEP, LIGHT_SLEEP, OFF, ON, STANDBY, UNKNOWN*) |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onPowerModeChanged",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onPowerModeChanged",
  "params": {
    "currentState": "OFF",
    "newState": "OFF"
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onPowerModeChanged``.

<a id="notification_onRebootBegin"></a>
## *onRebootBegin [<sup>notification</sup>](#head_Notifications)*

Reboot begin event.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.rebootReasonCustom | string | mandatory | Reboot reason custom |
| params.rebootReasonOther | string | mandatory | Reboot reason other |
| params.rebootRequestor | string | mandatory | Reboot requested by |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onRebootBegin",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onRebootBegin",
  "params": {
    "rebootReasonCustom": "...",
    "rebootReasonOther": "...",
    "rebootRequestor": "..."
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onRebootBegin``.

<a id="notification_onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged [<sup>notification</sup>](#head_Notifications)*

Network Standby Mode changed event - only on XIone.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.enabled | boolean | mandatory | Network standby enabled or disabled |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
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
    "enabled": false
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onNetworkStandbyModeChanged``.

<a id="notification_onDeepSleepTimeout"></a>
## *onDeepSleepTimeout [<sup>notification</sup>](#head_Notifications)*

Deep sleep timeout event.

### Notification Parameters

| Name | Type | M/O | Description |
| :-------- | :-------- | :-------- | :-------- |
| params | object | mandatory |  |
| params.wakeupTimeout | integer | mandatory | Deep sleep wakeup timeout in seconds |

### Example

#### Registration

```json
{
  "jsonrpc": "2.0",
  "id": 42,
  "method": "<callsign>.1.register",
  "params": {
    "event": "onDeepSleepTimeout",
    "id": "myid"
  }
}
```

#### Notification

```json
{
  "jsonrpc": "2.0",
  "method": "myid.onDeepSleepTimeout",
  "params": {
    "wakeupTimeout": 0
  }
}
```

> The *client ID* parameter is passed within the notification designator, i.e. ``<client-id>.onDeepSleepTimeout``.

