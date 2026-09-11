/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
    namespace Exchange
    {
        // @json @text:keep
        struct EXTERNAL IPowerManager : virtual public Core::IUnknown {
        enum { ID = ID_POWER_MANAGER };

        enum PowerState : uint8_t {
            POWER_STATE_UNKNOWN   = 0  /* @text UNKNOWN */,
            POWER_STATE_OFF                = 1  /* @text OFF */,
            POWER_STATE_STANDBY            = 2  /* @text STANDBY */,
            POWER_STATE_ON                 = 3  /* @text ON */,
            POWER_STATE_STANDBY_LIGHT_SLEEP  = 4  /* @text LIGHT_SLEEP */,
            POWER_STATE_STANDBY_DEEP_SLEEP   = 5  /* @text DEEP_SLEEP */
        };

        enum ThermalTemperature : uint8_t {
            THERMAL_TEMPERATURE_UNKNOWN     = 0  /* @text UNKNOWN Thermal Temperature */,
            THERMAL_TEMPERATURE_NORMAL     = 1  /* @text Normal Thermal Temperature */,
            THERMAL_TEMPERATURE_HIGH       = 2  /* @text High Thermal Temperature */,
            THERMAL_TEMPERATURE_CRITICAL   = 4  /* @text Critial Thermal Temperature */
        };

        enum WakeupSrcType : uint16_t {
            WAKEUP_SRC_UNKNOWN          = 0    /* @text UNKNOWN */,
            WAKEUP_SRC_VOICE            = 1    /* @text VOICE */,
            WAKEUP_SRC_PRESENCEDETECTED = 2    /* @text PRESENCEDETECTED */,
            WAKEUP_SRC_BLUETOOTH        = 3    /* @text BLUETOOTH */,
            WAKEUP_SRC_WIFI             = 4    /* @text WIFI */,
            WAKEUP_SRC_IR               = 5    /* @text IR */,
            WAKEUP_SRC_POWERKEY         = 6    /* @text POWERKEY */,
            WAKEUP_SRC_TIMER            = 7    /* @text TIMER */,
            WAKEUP_SRC_CEC              = 8    /* @text CEC */,
            WAKEUP_SRC_LAN              = 9    /* @text LAN */,
            WAKEUP_SRC_RF4CE            = 10   /* @text RF4CE (IMPORTANT: Add any new wakeupsrc before this)*/
        };

        enum WakeupReason : uint8_t {
            WAKEUP_REASON_UNKNOWN = 0              /* @text UNKNOWN */,
            WAKEUP_REASON_IR = 1              /* @text IR */,
            WAKEUP_REASON_BLUETOOTH = 2       /* @text BLUETOOTH */,
            WAKEUP_REASON_RF4CE = 3           /* @text RF4CE */,
            WAKEUP_REASON_GPIO = 4            /* @text GPIO */,
            WAKEUP_REASON_LAN = 5             /* @text LAN */,
            WAKEUP_REASON_WIFI = 6            /* @text WIFI */,
            WAKEUP_REASON_TIMER = 7           /* @text TIMER */,
            WAKEUP_REASON_FRONTPANEL = 8      /* @text FRONTPANEL */,
            WAKEUP_REASON_WATCHDOG = 9        /* @text WATCHDOG */,
            WAKEUP_REASON_SOFTWARERESET = 10   /* @text SOFTWARERESET */,
            WAKEUP_REASON_THERMALRESET = 11   /* @text THERMALRESET */,
            WAKEUP_REASON_WARMRESET = 12      /* @text WARMRESET */,
            WAKEUP_REASON_COLDBOOT = 13       /* @text COLDBOOT */,
            WAKEUP_REASON_STRAUTHFAIL = 14    /* @text STR_AUTH_FAIL */,
            WAKEUP_REASON_CEC = 15            /* @text CEC */,
            WAKEUP_REASON_PRESENCE = 16       /* @text PRESENCE */,
            WAKEUP_REASON_VOICE = 17       /* @text VOICE */
        };

        enum SystemMode : uint8_t {
            SYSTEM_MODE_UNKNOWN      = 0  /* @text UNKNOWN */,
            SYSTEM_MODE_NORMAL      = 1  /* @text NORMAL */,
            SYSTEM_MODE_EAS         = 2  /* @text EAS */,
            SYSTEM_MODE_WAREHOUSE   = 3  /* @text WAREHOUSE */
        };

        struct WakeupSourceConfig {
            WakeupSrcType wakeupSource;
            bool          enabled;
        };

        struct EXTERNAL TimeSinceWakeup {
            uint32_t secondsSinceWakeup /* @brief Wakeup time in seconds */;
        };

        using IWakeupSourceConfigIterator = RPC::IIteratorType<WakeupSourceConfig, ID_POWER_MANAGER_WAKEUP_SRC_ITERATOR>;

        // @event
        struct EXTERNAL IRebootNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_REBOOT };
            // @brief Reboot begin event
            // @text onRebootBegin
            // @details Notifies clients that a reboot operation has been initiated. Clients can use this event to perform any necessary pre-reboot tasks or cleanup operations.
            // @param rebootReasonCustom: Reboot reason custom
            // @example rebootReasonCustom: "FirmwareUpdate"
            // @param rebootReasonOther: Reboot reason other
            // @example rebootReasonOther: "UserInitiated"
            // @param rebootRequestor: Reboot requested by
            // @example rebootRequestor: "SystemService"
            virtual void OnRebootBegin(const string &rebootReasonCustom, const string &rebootReasonOther, const string &rebootRequestor) {};
        };
        virtual Core::hresult Register(Exchange::IPowerManager::IRebootNotification* notification ) = 0;
        virtual Core::hresult Unregister(const Exchange::IPowerManager::IRebootNotification* notification ) = 0;

        // @event
        struct EXTERNAL IModePreChangeNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_MODE_PRECHANGE };
            // @brief Power mode Pre-change event
            // @text onPowerModePreChange
            // @details Notifies clients before the power mode changes. Clients can use this event to prepare for the upcoming power mode transition.
            // @param currentState: Current Power State
            // @example currentState: POWER_STATE_ON
            // @param newState: Changing power state to this New Power State
            // @example newState: POWER_STATE_STANDBY
            // @param transactionId: TransactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API
            // @example transactionId: 12345
            // @param stateChangeAfter: Seconds after which the actual power mode will be applied.
            // @example stateChangeAfter: 10
            virtual void OnPowerModePreChange(const PowerState currentState, const PowerState newState, const int transactionId, const int stateChangeAfter) {};
        };
        // @brief Register for Power Mode pre-change event
        virtual Core::hresult Register(IModePreChangeNotification* notification ) = 0;
        // @brief Unregister for Power Mode pre-change event
        //       IMPORTANT: If client is also engaged in power mode pre-change operation (requested via AddPowerModePreChangeClient API),
        //                  make sure to disengage (using RemovePowerModePreChangeClient API) before calling Unregister.
        virtual Core::hresult Unregister(const IModePreChangeNotification* notification ) = 0;

        // @event
        struct EXTERNAL IModeChangedNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_MODE_CHANGED };
            // @brief Power mode changed
            // @text onPowerModeChanged
            // @details Notifies clients after the power mode has changed.
            // @param currentState: Current Power State
            // @example currentState: POWER_STATE_STANDBY
            // @param newState: New Power State
            // @example newState: POWER_STATE_ON
            virtual void OnPowerModeChanged(const PowerState currentState, const PowerState newState) {};
        };
        virtual Core::hresult Register(IModeChangedNotification* notification ) = 0;
        virtual Core::hresult Unregister(const IModeChangedNotification* notification ) = 0;

        // @event
        struct EXTERNAL IDeepSleepTimeoutNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_DEEP_SLEEP_TIMEOUT };
            // @brief Deep sleep timeout event
            // @text onDeepSleepTimeout
            // @details Notifies clients when the deep sleep wakeup timeout is reached. Clients can use this event to perform any necessary actions before the system enters deep sleep mode.
            // @param wakeupTimeout: Deep sleep wakeup timeout in seconds
            // @example wakeupTimeout: 300
            virtual void OnDeepSleepTimeout(const int wakeupTimeout) {};
        };
        virtual Core::hresult Register(IDeepSleepTimeoutNotification* notification ) = 0;
        virtual Core::hresult Unregister(const IDeepSleepTimeoutNotification* notification ) = 0;

         // @event
         struct EXTERNAL INetworkStandbyModeChangedNotification : virtual public Core::IUnknown
         {
             enum { ID = ID_POWER_MANAGER_NOTIFICATION_NETWORK_STANDBY_MODE_CHANGED };
             // @brief Network Standby Mode changed event - only on XIone
             // @details Notifies clients when the network standby mode is changed. Clients can use this event to perform any necessary actions based on the new network standby mode.
             // @text onNetworkStandbyModeChanged
             // @param enabled: network standby enabled or disabled
             // @example enabled: true
             virtual void OnNetworkStandbyModeChanged(const bool enabled) {};
         };
         virtual Core::hresult Register(INetworkStandbyModeChangedNotification* notification ) = 0;
         virtual Core::hresult Unregister(const INetworkStandbyModeChangedNotification* notification ) = 0;

         // @event
         struct EXTERNAL IThermalModeChangedNotification : virtual public Core::IUnknown
         {
             enum { ID = ID_POWER_MANAGER_NOTIFICATION_THERMAL_MODE_CHANGED };
             // @brief Thermal Mode changed event
             // @text onThermalModeChanged
             // @details Notifies clients when the thermal mode is changed. Clients can use this event to perform any necessary actions based on the new thermal mode.
             // @param currentThermalLevel: current thermal level
             // @example currentThermalLevel: THERMAL_TEMPERATURE_NORMAL
             // @param newThermalLevel: new thermal level
             // @example newThermalLevel: THERMAL_TEMPERATURE_HIGH
             // @param currentTemperature: current temperature
             // @example currentTemperature: 75.5
             virtual void OnThermalModeChanged(const ThermalTemperature currentThermalLevel, const ThermalTemperature newThermalLevel, const float currentTemperature) {};
         };
         virtual Core::hresult Register(IThermalModeChangedNotification* notification ) = 0;
         virtual Core::hresult Unregister(const IThermalModeChangedNotification* notification ) = 0;

        /** Engage a client in power mode change operation. */
        // @text addPowerModePreChangeClient
        // @brief Register a client to engage in power mode state changes.
        //        Added client should call either
        //          - `PowerModePreChangeComplete` API to inform power manager that this client has completed its pre-change operation.
        //          - Or `DelayPowerModeChangeBy` API to delay the power mode change.
        //        If the client does not call `PowerModePreChangeComplete` API, the power mode change will complete
        //        after the maximum delay `stateChangeAfter` seconds (as received in `OnPowerModePreChange` event).
        //
        //        IMPORTANT: ** IT'S A BUG IF CLIENT `Unregister` FROM `IModePreChangeNotification` BEFORE DISENGAGING ITSELF **
        //                   always make sure to call `RemovePowerModePreChangeClient` before calling `Unregister` from `IModePreChangeNotification`.
        // @details Registers a client to engage in power mode pre-change operations.
        // @param clientName: Name of the client
        // @example clientName: "MyClient"
        // @param clientId: Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) 
        //                  or to delay the power mode change (`DelayPowerModeChangeBy`)
        // @example clientId: 12345
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult AddPowerModePreChangeClient(const string& clientName , uint32_t& clientId /* @out */) = 0;

        /** Disengage a client from the power mode change operation. */
        // @text removePowerModePreChangeClient
        // @brief Removes a registered client from participating in power mode pre-change operations.
        //        NOTE client will still continue to receive pre-change notifications.
        // @details This API should be called when the client no longer wishes to participate in power mode pre-change operations.
        // @param clientId: Unique identifier for the client. See `AddPowerModePreChangeClient`
        // @example clientId: 12345
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult RemovePowerModePreChangeClient(const uint32_t clientId ) = 0;

        /** Sets Power State . */
        // @text setPowerState
        // @brief Set Power State
        // @details Sets the power state of the device. Clients can use this API to request a specific power state, such as ON, OFF, or STANDBY.
        // @param keyCode: Key code for the power state change request
        // @example keyCode: 12345
        // @param powerState: Set power to this state
        // @example powerState: POWER_STATE_STANDBY
        // @param reason: Reason for moving to the power state
        // @example reason: "UserInitiated"
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetPowerState(const int keyCode , const PowerState powerState ,const string &reason ) = 0;

        /** Gets the Power State.*/
        // @text getPowerState
        // @brief Get Power State
        // @details Retrieves the current and previous power states of the device. Clients can use this API to query the device's power state information.
        // @param currentState: Current Power State
        // @example currentState: POWER_STATE_ON
        // @param previousState: Get previous power state
        // @example previousState: POWER_STATE_OFF
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetPowerState(PowerState& currentState /* @out */, PowerState &previousState /* @out */) const = 0;

        /** Gets the current Thermal state.*/
        // @text getThermalState
        // @brief Get Current Thermal State (temperature)
        // @details Retrieves the current thermal state of the device, including the current temperature. Clients can use this API to monitor the device's thermal conditions.
        // @param currentTemperature: current temperature
        // @example currentTemperature: 75.5
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetThermalState(float& currentTemperature /* @out */) const = 0;

        /** Sets the Temperature Thresholds.*/
        // @text setTemperatureThresholds
        // @brief Set Temperature Thresholds
        // @details Sets the temperature thresholds for the device. Clients can use this API to define high and critical temperature limits, which can trigger specific actions or notifications when exceeded.
        // @param high: high threshold
        // @example high: 80.0
        // @param critical : critical threshold
        // @example critical: 90.0
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetTemperatureThresholds(float high , float critical ) = 0;

        /** Gets the current Temperature Thresholds.*/
        // @text getTemperatureThresholds
        // @brief Get Temperature Thresholds
        // @details Retrieves the current temperature thresholds for the device. Clients can use this API to query the defined high and critical temperature limits.
        // @param high: high threshold
        // @example high: 80.0
        // @param critical : critical threshold
        // @example critical: 90.0
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetTemperatureThresholds(float& high /* @out */, float& critical /* @out */) const = 0;

        /** Sets the current Temperature Grace interval.*/
        // @property
        // @text setOvertempGraceInterval
        // @brief Set Temperature Grace interval
        // @details Sets the grace interval for over-temperature conditions. Clients can use this API to define a time period during which the device can operate above the defined temperature thresholds before taking action.
        // @param graceInterval: interval in secs?
        // @example graceInterval: 60
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetOvertempGraceInterval(const int graceInterval ) = 0;

        /** Gets the current Temperature Grace interval.*/
        // @property
        // @text getOvertempGraceInterval
        // @brief Get Temperature Grace interval
        // @details Retrieves the current grace interval for over-temperature conditions. Clients can use this API to query the defined time period during which the device can operate above the defined temperature thresholds before taking action.
        // @param graceInterval: interval in secs?
        // @example graceInterval: 60
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetOvertempGraceInterval(int& graceInterval /* @out */) const = 0;

        /** Set Deep Sleep Timer for later wakeup */
        // @property
        // @text setDeepSleepTimer
        // @brief Set Deep sleep timer for timeOut period
        // @details Sets the deep sleep timer for the device. Clients can use this API to specify a timeout period after which the device will enter deep sleep mode.
        // @param timeOut: Deep sleep timeout
        // @example timeOut: 300
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetDeepSleepTimer(const int timeOut ) = 0;

        /** Get Last Wakeup reason */
        // @property
        // @text getLastWakeupReason
        // @brief Get Last Wake up reason
        // @details Retrieves the last wakeup reason for the device. Clients can use this API to determine the cause of the most recent wakeup event, such as a specific wakeup source or user action.
        // @param wakeupReason: Wake up reason
        // @example wakeupReason: WAKEUP_REASON_IR
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetLastWakeupReason(WakeupReason &wakeupReason /* @out */) const = 0;

        /** Get Last Wakeup key code */
        // @property
        // @text getLastWakeupKeyCode
        // @brief Get the key code that can be used for wakeup
        // @details Retrieves the last wakeup key code for the device. Clients can use this API to determine the specific key code that triggered the most recent wakeup event.
        // @param keycode: Key code for wakeup
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetLastWakeupKeyCode(int &keycode /* @out */) const = 0;

        /** Perform Reboot */
        // @text reboot
        // @brief Reboot device
        // @details Initiates a reboot operation for the device. Clients can use this API to request a system reboot, providing a reason and requestor information.
        // @param rebootRequestor: Reboot requested by
        // @example rebootRequestor: "SystemService"
        // @param rebootReasonCustom: Reboot reason custom
        // @example rebootReasonCustom: "FirmwareUpdate"
        // @param rebootReasonOther: Reboot reason other
        // @example rebootReasonOther: "UserInitiated"
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult Reboot(const string &rebootRequestor , const string &rebootReasonCustom , const string &rebootReasonOther ) = 0;

        /** Set Network Standby Mode */
        // @property
        // @text setNetworkStandbyMode
        // @brief Set the standby mode for Network
        // @details Sets the network standby mode for the device. Clients can use this API to enable or disable network standby functionality, which may affect the device's behavior when in low-power states.
        // @param standbyMode: Network standby mode
        // @example standbyMode: true
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetNetworkStandbyMode(const bool standbyMode ) = 0;

        /** Get Network Standby Mode */
        // @text getNetworkStandbyMode
        // @brief Get the standby mode for Network
        // @details Retrieves the current network standby mode for the device. Clients can use this API to query whether network standby functionality is enabled or disabled.
        // @param standbyMode: Network standby mode
        // @example standbyMode: true
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetNetworkStandbyMode(bool &standbyMode /* @out */) = 0;

        /** Set Wakeup source configuration */
        // @text setWakeupSourceConfig
        // @brief Set the source configuration for device wakeup
        // @details Configures the wakeup sources for the device. Clients can use this API to specify which sources are enabled or disabled for waking up the device from low-power states.
        // @param wakeupSources: Wake up sources array
        // @example wakeupSources: [{ "wakeupSource": WAKEUP_SRC_IR, "enabled": true }, { "wakeupSource": WAKEUP_SRC_BLUETOOTH, "enabled": false }]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult SetWakeupSourceConfig(IWakeupSourceConfigIterator* const wakeupSources) = 0;

        /** Get Wakeup source configuration */
        // @text getWakeupSourceConfig
        // @brief Get the source configuration for device wakeup
        // @details Retrieves the current wakeup source configuration for the device. Clients can use this API to query which sources are enabled or disabled for waking up the device from low-power states.
        // @param wakeupSources: Wake up sources array
        // @example wakeupSources: [{ "wakeupSource": WAKEUP_SRC_IR, "enabled": true }, { "wakeupSource": WAKEUP_SRC_BLUETOOTH, "enabled": false }]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetWakeupSourceConfig(IWakeupSourceConfigIterator*& wakeupSources /* @out */) const = 0;

        /** Get Power State before reboot */
        // @text getPowerStateBeforeReboot
        // @brief Get Power state before reboot
        // @details Retrieves the power state of the device before the last reboot. Clients can use this API to determine the power state that was active prior to the most recent reboot event.
        // @param powerStateBeforeReboot: power state
        // @example powerStateBeforeReboot: POWER_STATE_STANDBY
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetPowerStateBeforeReboot(PowerState &powerStateBeforeReboot /* @out */) = 0;

        /** Power prechange activity completed */
        // @text powerModePreChangeComplete
        // @brief Pre power mode handling complete for given client and transation id
        // @details Informs the power manager that the pre-change operation for a specific client and transaction ID has been completed. Clients should call this API after completing their pre-change tasks to allow the power mode transition to proceed.
        // @param clientId: Unique identifier for the client, as received in AddPowerModePreChangeClient
        // @example clientId: 12345
        // @param transactionId: Transaction ID as received in OnPowerModePreChange
        // @example transactionId: 67890
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult PowerModePreChangeComplete(const uint32_t clientId , const int transactionId ) = 0;

        /** Delay Powermode change by given time */
        // @text delayPowerModeChangeBy
        // @brief Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used.
        // @details Delays the power mode change by a specified time period for a specific client and transaction ID. Clients can use this API to request additional time before the power mode transition occurs, allowing them to complete any necessary tasks.
        // @param clientId: Unique identifier for the client, as received in AddPowerModePreChangeClient
        // @example clientId: 12345
        // @param transactionId: Transaction ID as received in OnPowerModePreChange
        // @example transactionId: 67890
        // @param delayPeriod: delay in seconds
        // @example delayPeriod: 30
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult DelayPowerModeChangeBy(const uint32_t clientId , const int transactionId , const int delayPeriod ) = 0;

        /** Get the Wakeup Time in seconds */
        // @text getTimeSinceWakeup
        // @brief Get the Wakeup Time in seconds since the device transitioned to the ON state.
        // @details Retrieves the time elapsed since the device transitioned to the ON state. Clients can use this API to determine how long the device has been awake and active.
        // @param timeSinceWakeup: Wakeup time in seconds
        // @example timeSinceWakeup: 120
        // @retval ErrorCode::ERROR_NONE: Indicates success
        virtual Core::hresult GetTimeSinceWakeup(TimeSinceWakeup &timeSinceWakeup /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

