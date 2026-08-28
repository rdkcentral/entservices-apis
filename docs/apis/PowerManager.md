<!-- Generated automatically, DO NOT EDIT! -->
<a id="PowerManager_Module"></a>
# PowerManager Module

**Version: [1.0.0](https://github.com/rdkcentral/entservices-apis/tree/main/apis/PowerManager/IPowerManager.h)**

A PowerManager module for Thunder framework.

### Table of Contents

- [Abbreviation, Acronyms and Terms](#abbreviation-acronyms-and-terms)
- [Description](#Description)
- [Configuration](#Configuration)
- [Interfaces](#Interfaces)
  - [IPowerManager](#IPowerManager)
    - [Methods](#IPowerManager-Methods)
    - [Notifications](#IPowerManager-Notifications)
    - [Properties](#IPowerManager-Properties)

<a id="abbreviation-acronyms-and-terms"></a>
# Abbreviation, Acronyms and Terms

[[Refer to this link](overview/aat.md)]

<a id="Description"></a>
# Description

The `PowerManager` module provides the following interface(s):

- IPowerManager

The module is designed to be loaded and executed within the Thunder framework. For more information about the framework refer to [[Thunder](https://rdkcentral.github.io/Thunder/)].

<a id="Configuration"></a>
# Configuration

The table below lists configuration options of the plugin.

| Name | Type | Description |
| :-------- | :-------- | :-------- |
| callsign | string | Plugin instance name (default: org.rdk.PowerManager) |
| classname | string | Class name: *PowerManager* |
| locator | string | Library name: *libWPEFrameworkPowerManager.so* |
| autostart | boolean | Determines if the plugin shall be started automatically along with the framework |

<a id="Interfaces"></a>
# Interfaces

<a id="IPowerManager"></a>
## IPowerManager Interface

<a id="IPowerManager-Methods"></a>
### Methods

The following methods are provided by the IPowerManager Interface:

| Method | Description |
| :-------- | :-------- |
| [addPowerModePreChangeClient](#addPowerModePreChangeClient) | Register a client to engage in power mode state changes. Added client should call either - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation. - Or `DelayPowerModeChangeBy` API to delay the power mode change. If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).  IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF ** always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`.  |
| [delayPowerModeChangeBy](#delayPowerModeChangeBy) | Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used. |
| [getNetworkStandbyMode](#getNetworkStandbyMode) | Get the standby mode for Network |
| [getPowerState](#getPowerState) | Get Power State |
| [getPowerStateBeforeReboot](#getPowerStateBeforeReboot) | Get Power state before reboot |
| [getTemperatureThresholds](#getTemperatureThresholds) | Get Temperature Thresholds |
| [getThermalState](#getThermalState) | Get Current Thermal State (temperature) |
| [getTimeSinceWakeup](#getTimeSinceWakeup) | Get the Wakeup Time in seconds since the device transitioned to the ON state. |
| [getWakeupSourceConfig](#getWakeupSourceConfig) | Get the source configuration for device wakeup |
| [powerModePreChangeComplete](#powerModePreChangeComplete) | Pre power mode handling complete for given client and transation id |
| [reboot](#reboot) | Reboot device |
| [removePowerModePreChangeClient](#removePowerModePreChangeClient) | Removes a registered client from participating in power mode pre-change operations. NOTE client will still continue to receive pre-change notifications. |
| [setPowerState](#setPowerState) | Set Power State |
| [setTemperatureThresholds](#setTemperatureThresholds) | Set Temperature Thresholds |
| [setWakeupSourceConfig](#setWakeupSourceConfig) | Set the source configuration for device wakeup |

<a id="addPowerModePreChangeClient"></a>
## *addPowerModePreChangeClient*

Registers a client to engage in power mode pre-change operations.

### Events Triggered
None
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
        "clientName": "MyClient"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 0, "method": "org.rdk.PowerManager.addPowerModePreChangeClient", "params": {"clientName": "MyClient"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "result": {
        "clientId": 12345
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 0,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="delayPowerModeChangeBy"></a>
## *delayPowerModeChangeBy*

Delays the power mode change by a specified time period for a specific client and transaction ID. Clients can use this API to request additional time before the power mode transition occurs, allowing them to complete any necessary tasks.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client, as received in AddPowerModePreChangeClient |
| params.transactionId | int | transaction id as received in OnPowerModePreChange |
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
        "clientId": 12345,
        "transactionId": 67890,
        "delayPeriod": 30
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 1, "method": "org.rdk.PowerManager.delayPowerModeChangeBy", "params": {"clientId": 12345, "transactionId": 67890, "delayPeriod": 30}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 1,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getNetworkStandbyMode"></a>
## *getNetworkStandbyMode*

Retrieves the current network standby mode for the device. Clients can use this API to query whether network standby functionality is enabled or disabled.

### Events Triggered
None
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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 2,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPowerState"></a>
## *getPowerState*

Retrieves the current and previous power states of the device. Clients can use this API to query the device's power state information.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.currentState | string | Current Power State. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |
| result.previousState | string | Get previous power state. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |

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
        "currentState": "POWER_STATE_ON",
        "previousState": "POWER_STATE_OFF"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 3,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getPowerStateBeforeReboot"></a>
## *getPowerStateBeforeReboot*

Retrieves the power state of the device before the last reboot. Clients can use this API to determine the power state that was active prior to the most recent reboot 

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.powerStateBeforeReboot | string | power state. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |

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
        "powerStateBeforeReboot": "POWER_STATE_STANDBY"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 4,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getTemperatureThresholds"></a>
## *getTemperatureThresholds*

Retrieves the current temperature thresholds for the device. Clients can use this API to query the defined high and critical temperature limits.

### Events Triggered
None
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
        "high": 80.0,
        "critical": 90.0
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 5,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getThermalState"></a>
## *getThermalState*

Retrieves the current thermal state of the device, including the current temperature. Clients can use this API to monitor the device's thermal conditions.

### Events Triggered
None
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
        "currentTemperature": 75.5
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 6,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getTimeSinceWakeup"></a>
## *getTimeSinceWakeup*

Retrieves the time elapsed since the device transitioned to the ON state. Clients can use this API to determine how long the device has been awake and active.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.secondsSinceWakeup | integer | Wakeup time in seconds |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "method": "org.rdk.PowerManager.getTimeSinceWakeup"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 7, "method": "org.rdk.PowerManager.getTimeSinceWakeup"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "result": 120
}
```


#### Error Response (ErrorCode::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 7,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getWakeupSourceConfig"></a>
## *getWakeupSourceConfig*

Retrieves the current wakeup source configuration for the device. Clients can use this API to query which sources are enabled or disabled for waking up the device from low-power states.

### Events Triggered
None
### Parameters
This method takes no parameters.
### Results
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| result | object |  |
| result.wakeupSources | array | Wake up sources array |
| result.wakeupSources[#].wakeupSource | string | Possible values: UNKNOWN, VOICE, PRESENCEDETECTED, BLUETOOTH, WIFI, IR, POWERKEY, TIMER, CEC, LAN, RF4CE (IMPORTANT: Add any new wakeupsrc before this) |
| result.wakeupSources[#].enabled | bool |  |

### Examples


#### Request

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "method": "org.rdk.PowerManager.getWakeupSourceConfig"
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 8, "method": "org.rdk.PowerManager.getWakeupSourceConfig"}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "result": [
        "[{ \"wakeupSource\": WAKEUP_SRC_IR, \"enabled\": true }, { \"wakeupSource\": WAKEUP_SRC_BLUETOOTH, \"enabled\": false }]"
    ]
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 8,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="powerModePreChangeComplete"></a>
## *powerModePreChangeComplete*

Informs the power manager that the pre-change operation for a specific client and transaction ID has been completed. Clients should call this API after completing their pre-change tasks to allow the power mode transition to proceed.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client, as received in AddPowerModePreChangeClient example clientId: 12345 |
| params.transactionId | int | transaction id as received in OnPowerModePreChange |
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
    "method": "org.rdk.PowerManager.powerModePreChangeComplete",
    "params": {
        "clientId": 12345,
        "transactionId": 67890
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 9, "method": "org.rdk.PowerManager.powerModePreChangeComplete", "params": {"clientId": 12345, "transactionId": 67890}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 9,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="reboot"></a>
## *reboot*

Initiates a reboot operation for the device. Clients can use this API to request a system reboot, providing a reason and requestor information.

### Events Triggered
None
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
    "id": 10,
    "method": "org.rdk.PowerManager.reboot",
    "params": {
        "rebootRequestor": "SystemService",
        "rebootReasonCustom": "FirmwareUpdate",
        "rebootReasonOther": "UserInitiated"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 10, "method": "org.rdk.PowerManager.reboot", "params": {"rebootRequestor": "SystemService", "rebootReasonCustom": "FirmwareUpdate", "rebootReasonOther": "UserInitiated"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 10,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="removePowerModePreChangeClient"></a>
## *removePowerModePreChangeClient*

Removes a registered client from participating in power mode pre-change operations.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.clientId | integer | Unique identifier for the client. See `AddPowerModePreChangeClient` |
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
    "method": "org.rdk.PowerManager.removePowerModePreChangeClient",
    "params": {
        "clientId": 12345
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 11, "method": "org.rdk.PowerManager.removePowerModePreChangeClient", "params": {"clientId": 12345}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 11,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setPowerState"></a>
## *setPowerState*

Sets the power state of the device. Clients can use this API to request a specific power state, such as ON, OFF, or STANDBY.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.keyCode | int | Key code for the power state change request |
| params.powerState | string | Set power to this state. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |
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
    "id": 12,
    "method": "org.rdk.PowerManager.setPowerState",
    "params": {
        "keyCode": 12345,
        "powerState": "POWER_STATE_STANDBY",
        "reason": "UserInitiated"
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 12, "method": "org.rdk.PowerManager.setPowerState", "params": {"keyCode": 12345, "powerState": "POWER_STATE_STANDBY", "reason": "UserInitiated"}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 12,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setTemperatureThresholds"></a>
## *setTemperatureThresholds*

Sets the temperature thresholds for the device. Clients can use this API to define high and critical temperature limits, which can trigger specific actions or notifications when exceeded.

### Events Triggered
None
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
        "high": 80.0,
        "critical": 90.0
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 13, "method": "org.rdk.PowerManager.setTemperatureThresholds", "params": {"high": 80.0, "critical": 90.0}}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 13,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setWakeupSourceConfig"></a>
## *setWakeupSourceConfig*

Configures the wakeup sources for the device. Clients can use this API to specify which sources are enabled or disabled for waking up the device from low-power states.

### Events Triggered
None
### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.wakeupSources | array | Wake up sources array |
| params.wakeupSources[#].wakeupSource | string | Possible values: UNKNOWN, VOICE, PRESENCEDETECTED, BLUETOOTH, WIFI, IR, POWERKEY, TIMER, CEC, LAN, RF4CE (IMPORTANT: Add any new wakeupsrc before this) |
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
        "[{ \"wakeupSource\": WAKEUP_SRC_IR, \"enabled\": true }, { \"wakeupSource\": WAKEUP_SRC_BLUETOOTH, \"enabled\": false }]"
    ]
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 14, "method": "org.rdk.PowerManager.setWakeupSourceConfig", "params": ["[{ \"wakeupSource\": WAKEUP_SRC_IR, \"enabled\": true }, { \"wakeupSource\": WAKEUP_SRC_BLUETOOTH, \"enabled\": false }]"]}' http://127.0.0.1:9998/jsonrpc
```


#### Response

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 14,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="IPowerManager-Notifications"></a>
### Notifications

Notifications are autonomous events, triggered by the internals of the implementation, and broadcasted via JSON-RPC to all registered observers. Refer to [[Thunder](https://rdkcentral.github.io/Thunder/)] for information on how to register for a notification.

The following events are provided by the IPowerManager Interface:

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

Notifies clients when the deep sleep wakeup timeout is reached. Clients can use this event to perform any necessary actions before the system enters deep sleep mode.

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
        "wakeupTimeout": 300
    }
}
```

<a id="onNetworkStandbyModeChanged"></a>
## *onNetworkStandbyModeChanged*

Notifies clients when the network standby mode is changed. Clients can use this event to perform any necessary actions based on the new network standby mode.

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

Notifies clients after the power mode has changed.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | Current Power State. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |
| params.newState | string | New Power State. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 17,
    "method": "org.rdk.PowerManager.onPowerModeChanged",
    "params": {
        "currentState": "POWER_STATE_ON",
        "newState": "POWER_STATE_ON"
    }
}
```

<a id="onPowerModePreChange"></a>
## *onPowerModePreChange*

Notifies clients before the power mode changes. Clients can use this event to prepare for the upcoming power mode transition.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentState | string | Current Power State. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |
| params.newState | string | Changing power state to this New Power State. Possible values: UNKNOWN, OFF, STANDBY, ON, LIGHT_SLEEP, DEEP_SLEEP |
| params.transactionId | int | transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API |
| params.stateChangeAfter | int | seconds after which the actual power mode will be applied. |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 18,
    "method": "org.rdk.PowerManager.onPowerModePreChange",
    "params": {
        "currentState": "POWER_STATE_ON",
        "newState": "POWER_STATE_ON",
        "transactionId": 67890,
        "stateChangeAfter": 10
    }
}
```

<a id="onRebootBegin"></a>
## *onRebootBegin*

Notifies clients that a reboot operation has been initiated. Clients can use this event to perform any necessary pre-reboot tasks or cleanup operations.

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
        "rebootReasonCustom": "FirmwareUpdate",
        "rebootReasonOther": "UserInitiated",
        "rebootRequestor": "SystemService"
    }
}
```

<a id="onThermalModeChanged"></a>
## *onThermalModeChanged*

Notifies clients when the thermal mode is changed. Clients can use this event to perform any necessary actions based on the new thermal mode.

### Parameters
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| params | object |  |
| params.currentThermalLevel | string | current thermal level. Possible values: UNKNOWN Thermal Temperature, Normal Thermal Temperature, High Thermal Temperature, Critial Thermal Temperature |
| params.newThermalLevel | string | new thermal level. Possible values: UNKNOWN Thermal Temperature, Normal Thermal Temperature, High Thermal Temperature, Critial Thermal Temperature |
| params.currentTemperature | float | current temperature |

### Examples

```json
{
    "jsonrpc": 2.0,
    "id": 20,
    "method": "org.rdk.PowerManager.onThermalModeChanged",
    "params": {
        "currentThermalLevel": "THERMAL_TEMPERATURE_NORMAL",
        "newThermalLevel": "THERMAL_TEMPERATURE_HIGH",
        "currentTemperature": 75.5
    }
}
```

<a id="IPowerManager-Properties"></a>
### Properties

The following properties are provided by the IPowerManager Interface:

| Property | Description |
| :-------- | :-------- |
| [getLastWakeupKeyCode](#getLastWakeupKeyCode)<sup>RO</sup> | Get the key code that can be used for wakeup |
| [getLastWakeupReason](#getLastWakeupReason)<sup>RO</sup> | Get Last Wake up reason |
| [getOvertempGraceInterval](#getOvertempGraceInterval)<sup>RO</sup> | Get Temperature Grace interval |
| [setDeepSleepTimer](#setDeepSleepTimer)<sup>WO</sup> | Set Deep sleep timer for timeOut period |
| [setNetworkStandbyMode](#setNetworkStandbyMode)<sup>WO</sup> | Set the standby mode for Network |
| [setOvertempGraceInterval](#setOvertempGraceInterval)<sup>WO</sup> | Set Temperature Thresholds |

<a id="getLastWakeupKeyCode"></a>
## *getLastWakeupKeyCode*

Retrieves the last wakeup key code for the device. Clients can use this API to determine the specific key code that triggered the most recent wakeup 

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 21,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getLastWakeupReason"></a>
## *getLastWakeupReason*

Retrieves the last wakeup reason for the device. Clients can use this API to determine the cause of the most recent wakeup event, such as a specific wakeup source or user action.

> This property is read-only.
### Events
Event details will be updated soon.
### Values
| Name | Type | Description |
| :-------- | :-------- | :-------- |
| (property).wakeupReason | string | wake up reason. Possible values: UNKNOWN, IR, BLUETOOTH, RF4CE, GPIO, LAN, WIFI, TIMER, FRONTPANEL, WATCHDOG, SOFTWARERESET, THERMALRESET, WARMRESET, COLDBOOT, STR_AUTH_FAIL, CEC, PRESENCE, VOICE |

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
        "wakeupReason": "WAKEUP_REASON_IR"
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 22,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="getOvertempGraceInterval"></a>
## *getOvertempGraceInterval*

Retrieves the current grace interval for over-temperature conditions. Clients can use this API to query the defined time period during which the device can operate above the defined temperature thresholds before taking action.

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
        "graceInterval": 60
    }
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 23,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setDeepSleepTimer"></a>
## *setDeepSleepTimer*

Sets the deep sleep timer for the device. Clients can use this API to specify a timeout period after which the device will enter deep sleep mode.

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
        "timeOut": 300
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 24, "method": "org.rdk.PowerManager.setDeepSleepTimer", "params": {"timeOut": 300}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 24,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setNetworkStandbyMode"></a>
## *setNetworkStandbyMode*

Sets the network standby mode for the device. Clients can use this API to enable or disable network standby functionality, which may affect the device's behavior when in low-power states.

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


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 25,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

<a id="setOvertempGraceInterval"></a>
## *setOvertempGraceInterval*

Sets the grace interval for over-temperature conditions. Clients can use this API to define a time period during which the device can operate above the defined temperature thresholds before taking action.

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
        "graceInterval": 60
    }
}
```


#### CURL Command

```curl
curl -H 'content-type:text/plain;' --data-binary '{"jsonrpc": 2.0, "id": 26, "method": "org.rdk.PowerManager.setOvertempGraceInterval", "params": {"graceInterval": 60}}' http://127.0.0.1:9998/jsonrpc
```


#### Set Response

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "result": null
}
```


#### Error Response (Core::ERROR_GENERAL)

```json
{
    "jsonrpc": 2.0,
    "id": 26,
    "error": {
        "code": 1,
        "message": "Indicates failure"
    }
}
```

