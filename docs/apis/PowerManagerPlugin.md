<!-- Generated automatically, DO NOT EDIT! -->
<a id="PowerManager_Plugin"></a>
# PowerManager Plugin

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PowerManager/IPowerManager.h)**

A PowerManager plugin for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Methods](#Methods)
- [Properties](#Properties)
- [Notifications](#Notifications)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PowerManager` plugin provides an interface for PowerManager.

The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PowerManager) |
| classname | string | Class name: *PowerManager* |
| locator | string | Library name: *libWPEFrameworkPowerManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Methods"></a>
# Methods

The following methods are provided by the PowerManager plugin:

PowerManager interface methods:

| Method | Description |
| :-------- | :-------- |
| [addPowerModePreChangeClient](#addPowerModePreChangeClient) | Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`.  |
| [delayPowerModeChangeBy](#delayPowerModeChangeBy) | Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used. |
| [getNetworkStandbyMode](#getNetworkStandbyMode) | Get the standby mode for Network |
| [getPowerState](#getPowerState) | Get Power State |
| [getPowerStateBeforeReboot](#getPowerStateBeforeReboot) | Get Power state before reboot |
| [getTemperatureThresholds](#getTemperatureThresholds) | Get Temperature Thresholds |
| [getThermalState](#getThermalState) | Get Current Thermal State (temperature) |
| [getWakeupSourceConfig](#getWakeupSourceConfig) | Get the source configuration for device wakeup |
| [powerModePreChangeComplete](#powerModePreChangeComplete) | Pre power mode handling complete for given client and transation id |
| [reboot](#reboot) | Reboot device |
| [removePowerModePreChangeClient](#removePowerModePreChangeClient) | Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications. |
| [setPowerState](#setPowerState) | Set Power State |
| [setSystemMode](#setSystemMode) | System mode change |
| [setTemperatureThresholds](#setTemperatureThresholds) | Set Temperature Thresholds |
| [setWakeupSourceConfig](#setWakeupSourceConfig) | Set the source configuration for device wakeup |

<a id="addPowerModePreChangeClient"></a>
## *addPowerModePreChangeClient*

Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`. 

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientName | string | Name of the client |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.clientId | integer | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "method": "org.rdk.PowerManager.addPowerModePreChangeClient",
    "params": {
        "clientName": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PowerManager.addPowerModePreChangeClient", "params": {"clientName": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "clientId": 0
    }
}
```

<a id="delayPowerModeChangeBy"></a>
## *delayPowerModeChangeBy*

Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.delayPeriod | int | delay in seconds |
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
    "method": "org.rdk.PowerManager.delayPowerModeChangeBy",
    "params": {
        "clientId": 0,
        "transactionId": 0,
        "delayPeriod": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PowerManager.delayPowerModeChangeBy", "params": {"clientId": 0, "transactionId": 0, "delayPeriod": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```

<a id="getNetworkStandbyMode"></a>
## *getNetworkStandbyMode*

Get the standby mode for Network

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.standbyMode | bool | Network standby mode |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "method": "org.rdk.PowerManager.getNetworkStandbyMode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 2, "method": "org.rdk.PowerManager.getNetworkStandbyMode"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "result": {
        "standbyMode": true
    }
}
```

<a id="getPowerState"></a>
## *getPowerState*

Get Power State

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentState | string | Current Power State |
| result.previousState | string |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "method": "org.rdk.PowerManager.getPowerState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 3, "method": "org.rdk.PowerManager.getPowerState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "result": {
        "currentState": "POWER_STATE_UNKNOWN",
        "previousState": "POWER_STATE_UNKNOWN"
    }
}
```

<a id="getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot*

Get Power state before reboot

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerStateBeforeReboot | string | power state |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "method": "org.rdk.PowerManager.getPowerStateBeforeReboot"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 4, "method": "org.rdk.PowerManager.getPowerStateBeforeReboot"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "result": {
        "powerStateBeforeReboot": "POWER_STATE_UNKNOWN"
    }
}
```

<a id="getTemperatureThresholds"></a>
## *getTemperatureThresholds*

Get Temperature Thresholds

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.high | float | high threshold |
| result.critical | float | critical threshold |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "method": "org.rdk.PowerManager.getTemperatureThresholds"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 5, "method": "org.rdk.PowerManager.getTemperatureThresholds"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "result": {
        "high": 0.0,
        "critical": 0.0
    }
}
```

<a id="getThermalState"></a>
## *getThermalState*

Get Current Thermal State (temperature)

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentTemperature | float | current temperature |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "method": "org.rdk.PowerManager.getThermalState"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 6, "method": "org.rdk.PowerManager.getThermalState"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "result": {
        "currentTemperature": 0.0
    }
}
```

<a id="getWakeupSourceConfig"></a>
## *getWakeupSourceConfig*

Get the source configuration for device wakeup

### Events
Event details will be updated soon.
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupSources | IWakeupSourceConfigIterator | Wake up sources array |
| result.wakeupSources[#].wakeupSource | string |  |
| result.wakeupSources[#].enabled | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PowerManager.getWakeupSourceConfig"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PowerManager.getWakeupSourceConfig"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": [
        {
            "wakeupSource": "WAKEUP_SRC_UNKNOWN",
            "enabled": true
        }
    ]
}
```

<a id="powerModePreChangeComplete"></a>
## *powerModePreChangeComplete*

Pre power mode handling complete for given client and transation id

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.PowerManager.powerModePreChangeComplete",
    "params": {
        "clientId": 0,
        "transactionId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PowerManager.powerModePreChangeComplete", "params": {"clientId": 0, "transactionId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": null
}
```

<a id="reboot"></a>
## *reboot*

Reboot device

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rebootRequestor | string | Reboot requested by |
| params.rebootReasonCustom | string | Reboot reason custom |
| params.rebootReasonOther | string | Reboot reason other |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "method": "org.rdk.PowerManager.reboot",
    "params": {
        "rebootRequestor": "",
        "rebootReasonCustom": "",
        "rebootReasonOther": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PowerManager.reboot", "params": {"rebootRequestor": "", "rebootReasonCustom": "", "rebootReasonOther": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```

<a id="removePowerModePreChangeClient"></a>
## *removePowerModePreChangeClient*

Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications.

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) or to delay the power mode change (`DelayPowerModeChangeBy`) |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "method": "org.rdk.PowerManager.removePowerModePreChangeClient",
    "params": {
        "clientId": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PowerManager.removePowerModePreChangeClient", "params": {"clientId": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```

<a id="setPowerState"></a>
## *setPowerState*

Set Power State

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | int |  |
| params.powerState | string | Set power to this state |
| params.reason | string | Reason for moving to the power state |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "method": "org.rdk.PowerManager.setPowerState",
    "params": {
        "keyCode": 0,
        "powerState": "POWER_STATE_UNKNOWN",
        "reason": ""
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PowerManager.setPowerState", "params": {"keyCode": 0, "powerState": "POWER_STATE_UNKNOWN", "reason": ""}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```

<a id="setSystemMode"></a>
## *setSystemMode*

System mode change

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentMode | string |  |
| params.newMode | string | new mode |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "method": "org.rdk.PowerManager.setSystemMode",
    "params": {
        "currentMode": "SYSTEM_MODE_UNKNOWN",
        "newMode": "SYSTEM_MODE_UNKNOWN"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PowerManager.setSystemMode", "params": {"currentMode": "SYSTEM_MODE_UNKNOWN", "newMode": "SYSTEM_MODE_UNKNOWN"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```

<a id="setTemperatureThresholds"></a>
## *setTemperatureThresholds*

Set Temperature Thresholds

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.high | float | high threshold |
| params.critical | float | critical threshold |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "method": "org.rdk.PowerManager.setTemperatureThresholds",
    "params": {
        "high": 0.0,
        "critical": 0.0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PowerManager.setTemperatureThresholds", "params": {"high": 0.0, "critical": 0.0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```

<a id="setWakeupSourceConfig"></a>
## *setWakeupSourceConfig*

Set the source configuration for device wakeup

### Events
Event details will be updated soon.
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.wakeupSources | IWakeupSourceConfigIterator | Wake up sources array |
| params.wakeupSources[#].wakeupSource | string |  |
| params.wakeupSources[#].enabled | bool |  |
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | null | On success null will be returned. |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "method": "org.rdk.PowerManager.setWakeupSourceConfig",
    "params": [
        {
            "wakeupSource": "WAKEUP_SRC_UNKNOWN",
            "enabled": true
        }
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PowerManager.setWakeupSourceConfig", "params": [{"wakeupSource": "WAKEUP_SRC_UNKNOWN", "enabled": true}]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```


<a id="Properties"></a>
# Properties
The following properties are provided by the PowerManager plugin:

PowerManager interface properties:

| Method | Description |
| :-------- | :-------- |
| [getLastWakeupKeyCode](#getLastWakeupKeyCode)<sup>RO</sup> | Get the key code that can be used for wakeup |
| [getLastWakeupReason](#getLastWakeupReason)<sup>RO</sup> | Get Last Wake up reason |
| [getOvertempGraceInterval](#getOvertempGraceInterval)<sup>RO</sup> | Get Temperature Grace interval |
| [setDeepSleepTimer](#setDeepSleepTimer)<sup>WO</sup> | Set Deep sleep timer for timeOut period |
| [setNetworkStandbyMode](#setNetworkStandbyMode)<sup>WO</sup> | Set the standby mode for Network |
| [setOvertempGraceInterval](#setOvertempGraceInterval)<sup>WO</sup> | Set Temperature Thresholds |

<a id="GetLastWakeupKeyCode"></a>
## *GetLastWakeupKeyCode*

Get the key code that can be used for wakeup

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).keycode | int | Key code for wakeup |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "method": "org.rdk.PowerManager.getLastWakeupKeyCode"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 21, "method": "org.rdk.PowerManager.getLastWakeupKeyCode"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "result": {
        "keycode": 0
    }
}
```

<a id="GetLastWakeupReason"></a>
## *GetLastWakeupReason*

Get Last Wake up reason

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).wakeupReason | string | wake up reason |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "method": "org.rdk.PowerManager.getLastWakeupReason"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 22, "method": "org.rdk.PowerManager.getLastWakeupReason"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "result": {
        "wakeupReason": "WAKEUP_REASON_UNKNOWN"
    }
}
```

<a id="GetOvertempGraceInterval"></a>
## *GetOvertempGraceInterval*

Get Temperature Grace interval

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).graceInterval | int | interval in secs? |

### Examples


#### Get Request

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "method": "org.rdk.PowerManager.getOvertempGraceInterval"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 23, "method": "org.rdk.PowerManager.getOvertempGraceInterval"}' http://127.0.0.1:9998/jsonrpc
```


#### Get Response

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "result": {
        "graceInterval": 0
    }
}
```

<a id="SetDeepSleepTimer"></a>
## *SetDeepSleepTimer*

Set Deep sleep timer for timeOut period

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).timeOut | int | deep sleep timeout |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "method": "org.rdk.PowerManager.setDeepSleepTimer",
    "params": {
        "timeOut": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.PowerManager.setDeepSleepTimer", "params": {"timeOut": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```

<a id="SetNetworkStandbyMode"></a>
## *SetNetworkStandbyMode*

Set the standby mode for Network

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).standbyMode | bool | Network standby mode |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "method": "org.rdk.PowerManager.setNetworkStandbyMode",
    "params": {
        "standbyMode": true
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 25, "method": "org.rdk.PowerManager.setNetworkStandbyMode", "params": {"standbyMode": true}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "result": null
}
```

<a id="SetOvertempGraceInterval"></a>
## *SetOvertempGraceInterval*

Set Temperature Thresholds

> This property is write-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).graceInterval | int | interval in secs? |

### Examples


#### Set Request

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "method": "org.rdk.PowerManager.setOvertempGraceInterval",
    "params": {
        "graceInterval": 0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.PowerManager.setOvertempGraceInterval", "params": {"graceInterval": 0}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```


<a id="Notifications"></a>
# Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the PowerManager plugin:

PowerManager interface events:

| Event | Description |
| :-------- | :-------- |
| [onDeepSleepTimeout](#onDeepSleepTimeout) | Deep sleep timeout event |
| [onNetworkStandbyModeChanged](#onNetworkStandbyModeChanged) | Network Standby Mode changed event - only on XIone |
| [onPowerModeChanged](#onPowerModeChanged) | Power mode changed |
| [onPowerModePreChange](#onPowerModePreChange) | Power mode Pre-change event |
| [onRebootBegin](#onRebootBegin) | Reboot begin event |
| [onThermalModeChanged](#onThermalModeChanged) | Thermal Mode changed event |

<a id="onDeepSleepTimeout"></a>
## *onDeepSleepTimeout*

Deep sleep timeout event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.wakeupTimeout | int | Deep sleep wakeup timeout in seconds |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 15,
    "method": "org.rdk.PowerManager.onDeepSleepTimeout",
    "params": {
        "wakeupTimeout": 0
    }
}
```

<a id="onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged*

Network Standby Mode changed event - only on XIone

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.enabled | bool | network standby enabled or disabled |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 16,
    "method": "org.rdk.PowerManager.onNetworkStandbyModeChanged",
    "params": {
        "enabled": true
    }
}
```

<a id="onPowerModeChanged"></a>
## *onPowerModeChanged*

Power mode changed

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | Current Power State |
| params.newState | string | Changing power state to this New Power State |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.PowerManager.onPowerModeChanged",
    "params": {
        "currentState": "POWER_STATE_UNKNOWN",
        "newState": "POWER_STATE_UNKNOWN"
    }
}
```

<a id="onPowerModePreChange"></a>
## *onPowerModePreChange*

Power mode Pre-change event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | Current Power State |
| params.newState | string | Changing power state to this New Power State |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.stateChangeAfter | int | seconds after which the actual power mode will be applied. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.PowerManager.onPowerModePreChange",
    "params": {
        "currentState": "POWER_STATE_UNKNOWN",
        "newState": "POWER_STATE_UNKNOWN",
        "transactionId": 0,
        "stateChangeAfter": 0
    }
}
```

<a id="onRebootBegin"></a>
## *onRebootBegin*

Reboot begin event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.rebootReasonCustom | string | Reboot reason custom |
| params.rebootReasonOther | string | Reboot reason other |
| params.rebootRequestor | string | Reboot requested by |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 19,
    "method": "org.rdk.PowerManager.onRebootBegin",
    "params": {
        "rebootReasonCustom": "",
        "rebootReasonOther": "",
        "rebootRequestor": ""
    }
}
```

<a id="onThermalModeChanged"></a>
## *onThermalModeChanged*

Thermal Mode changed event

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentThermalLevel | string | current thermal level |
| params.newThermalLevel | string | new thermal level |
| params.currentTemperature | float | current temperature |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.PowerManager.onThermalModeChanged",
    "params": {
        "currentThermalLevel": "THERMAL_TEMPERATURE_UNKNOWN",
        "newThermalLevel": "THERMAL_TEMPERATURE_UNKNOWN",
        "currentTemperature": 0.0
    }
}
```
