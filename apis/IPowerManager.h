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
            // @text onRebootBegin
            // @brief Reboot begin event
            // @details Triggered when the reboot process is initiated by the Power Manager. This notification is sent before the actual reboot operation begins, allowing registered clients to perform cleanup activities, persist state information, release resources, or log reboot-related diagnostics. The event provides information about the reboot requestor and the associated reboot reason.
            // @param rebootReasonCustom: Reboot reason custom
            // @example rebootReasonCustom: "FirmwareUpgrade"
            // @param rebootReasonOther: Reboot reason other
            // @example rebootReasonOther: "User requested reboot after update"
            // @param rebootRequestor: Reboot requested by
            // @example rebootRequestor: "SystemManager"
            virtual void OnRebootBegin(const string &rebootReasonCustom, const string &rebootReasonOther, const string &rebootRequestor) {};
        };
        virtual Core::hresult Register(Exchange::IPowerManager::IRebootNotification* notification ) = 0;
        virtual Core::hresult Unregister(const Exchange::IPowerManager::IRebootNotification* notification ) = 0;

        // @event
        struct EXTERNAL IModePreChangeNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_MODE_PRECHANGE };
            // @text onPowerModePreChange
            // @brief Power mode Pre-change event
            // @details Triggered before the Power Manager applies a power state transition. Registered pre-change clients can use this notification to prepare for the upcoming state change by releasing resources, saving state, or performing cleanup operations. Clients should either call PowerModePreChangeComplete() when their pre-change processing is finished or DelayPowerModeChangeBy() if additional time is required. The power state transition proceeds automatically after the maximum allowed delay period expires.
            // @param currentState: Current Power State
            // @example currentState: POWER_STATE_ON
            // @param newState: Changing power state to this New Power State
            // @example newState: POWER_STATE_STANDBY
            // @param transactionId: transactionId to be used when invoking prePowerChangeComplete() / delayPowerModeChangeBy API
            // @example transactionId: 1234
            // @param stateChangeAfter: seconds after which the actual power mode will be applied.
            // @example stateChangeAfter: 30
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
            // @text onPowerModeChanged
            // @brief Power mode changed
            // @details Triggered after the Power Manager successfully completes a power state transition. This notification informs clients of both the previous and the new power states, allowing applications to release resources, suspend activities, or reinitialize services as required by the new operating state.
            // @param currentState: Current Power State
            // @example currentState - POWER_STATE_STANDBY
            // @param newState: New Power State
            // @example newState - POWER_STATE_ACTIVE
            virtual void OnPowerModeChanged(const PowerState currentState, const PowerState newState) {};
        };
        virtual Core::hresult Register(IModeChangedNotification* notification ) = 0;
        virtual Core::hresult Unregister(const IModeChangedNotification* notification ) = 0;

        // @event
        struct EXTERNAL IDeepSleepTimeoutNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_POWER_MANAGER_NOTIFICATION_DEEP_SLEEP_TIMEOUT };
            // @text onDeepSleepTimeout
            // @brief Deep sleep timeout event
            // @details Triggered when the configured deep sleep timeout period expires. This notification indicates that the device has reached the wakeup timeout associated with a previously configured deep sleep timer. Applications can use this event to perform wakeup-related processing or update power state dependent functionality.
            // @param wakeupTimeout: Deep sleep wakeup timeout in seconds
            // @example wakeupTimeout - 3600
            virtual void OnDeepSleepTimeout(const int wakeupTimeout) {};
        };
        virtual Core::hresult Register(IDeepSleepTimeoutNotification* notification ) = 0;
        virtual Core::hresult Unregister(const IDeepSleepTimeoutNotification* notification ) = 0;

         // @event
         struct EXTERNAL INetworkStandbyModeChangedNotification : virtual public Core::IUnknown
         {
             enum { ID = ID_POWER_MANAGER_NOTIFICATION_NETWORK_STANDBY_MODE_CHANGED };
             // @text onNetworkStandbyModeChanged
             // @brief Network Standby Mode changed event - only on XIone
             // @details Triggered when the network standby mode configuration changes. This notification is generated when network standby support is enabled or disabled by the Power Manager. Applications can use this event to update network-related behavior based on the current standby mode state.
             // @param enabled: network standby enabled or disabled
             // @example enabled - true
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
             // @details Triggered whenever the Power Manager detects a transition between thermal levels based on the current device temperature. Applications can use this notification to reduce workload, adjust performance settings, or take other thermal mitigation actions when the device temperature reaches higher thermal states.
             // @param currentThermalLevel: current thermal level
             // @example currentThermalLevel - THERMAL_TEMPERATURE_NORMAL
             // @param newThermalLevel: new thermal level
             // @example newThermalLevel - THERMAL_TEMPERATURE_HIGH
             // @param currentTemperature: current temperature
             // @example currentTemperature - 72.5
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
        // @details Adds a client to the power mode pre-change coordination process. Registered clients receive OnPowerModePreChange 
        // notifications and are expected to either acknowledge completion of their pre-change handling through PowerModePreChangeComplete() or request 
        // additional delay using DelayPowerModeChangeBy(). The Power Manager waits for participating clients before completing a power state transition.
        // @param clientName: Name of the client
        // @example clientName - "NetworkManager"
        // @param clientId: Unique identifier for the client to be used while acknowledging the pre-change operation (`PowerModePreChangeComplete`) 
        //                  or to delay the power mode change (`DelayPowerModeChangeBy`)
        // @example clientId - 1001
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Client registered successfully.
        // @retval Core::ERROR_GENERAL - Failed to register the client.
        virtual Core::hresult AddPowerModePreChangeClient(const string& clientName , uint32_t& clientId /* @out */) = 0;

        /** Disengage a client from the power mode change operation. */
        // @text removePowerModePreChangeClient
        // @brief Removes a registered client from participating in power mode pre-change operations.
        //        NOTE client will still continue to receive pre-change notifications.
        // @details Disengages a previously registered client from active participation in power mode transition handling. After removal, the client is no longer required to acknowledge or delay power mode changes. The client will continue to receive power mode pre-change notifications until it explicitly unregisters from the IModePreChangeNotification interface.
        // @param clientId: Unique identifier for the client. See `AddPowerModePreChangeClient`
        // @example clientId - 1001
		// @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Client was successfully removed from power mode Pre-change participation.
        // @retval Core::ERROR_GENERAL - Failed to remove the client.
        virtual Core::hresult RemovePowerModePreChangeClient(const uint32_t clientId ) = 0;

        /** Sets Power State . */
        // @text setPowerState
        // @brief Set Power State
        // @details Requests a transition of the device to the specified power state. The Power Manager coordinates the transition and notifies registered clients of any pending or completed power mode changes.
        // @param keyCode - in - Key code associated with the power state change request.
        // @example keyCode - 116
        // @param powerState: Set power to this state
        // @example powerState - POWER_STATE_STANDBY
        // @param reason: Reason for moving to the power state
        // @example reason - "User initiated standby"
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Power state change request accepted successfully.
        // @retval Core::ERROR_GENERAL - Failed to process the power state change request.
        virtual Core::hresult SetPowerState(const int keyCode , const PowerState powerState ,const string &reason ) = 0;

        /** Gets the Power State.*/
        // @text getPowerState
        // @brief Get Power State
        // @details Returns the device's current power state and the state that was active before the most recent transition
        // @param powerState: Get current power state
        // @param currentState - out - Current power state.
        // @example currentState - POWER_STATE_ON
        // @param previousState - out - Previous power state.
        // @example previousState - POWER_STATE_STANDBY
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Power state retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve power state.
        virtual Core::hresult GetPowerState(PowerState& currentState /* @out */, PowerState &previousState /* @out */) const = 0;

        /** Gets the current Thermal state.*/
        // @text getThermalState
        // @brief Get Current Thermal State (temperature)
        // @details Returns the current thermal state of the device based on the current temperature. 
        // The thermal state indicates whether the device is operating within normal temperature 
        // ranges or if it has reached high or critical thermal levels that may require mitigation actions.
        // @param currentTemperature: current temperature
        // @example currentTemperature - 72.5
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Thermal state retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve thermal state.
        virtual Core::hresult GetThermalState(float& currentTemperature /* @out */) const = 0;

        /** Sets the Temperature Thresholds.*/
        // @text setTemperatureThresholds
        // @brief Set Temperature Thresholds
        // @details Sets the high and critical temperature thresholds for the device.
        // @param high: high threshold
        // @example high - 85.0
        // @param critical : critical threshold
        // @example critical - 95.0
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Temperature thresholds set successfully.
        // @retval Core::ERROR_GENERAL - Failed to set temperature thresholds.
        virtual Core::hresult SetTemperatureThresholds(float high , float critical ) = 0;

        /** Gets the current Temperature Thresholds.*/
        // @text getTemperatureThresholds
        // @brief Get Temperature Thresholds
        // @details Retrieves the current high and critical temperature thresholds configured for the device.
        // @param high: high threshold
        // @example high - 85.0
        // @param critical : critical threshold
        // @example critical - 95.0
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Temperature thresholds retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve temperature thresholds.
        virtual Core::hresult GetTemperatureThresholds(float& high /* @out */, float& critical /* @out */) const = 0;

        /** Sets the current Temperature Grace interval.*/
        // @property
        // @text setOvertempGraceInterval
        // @brief Set Temperature Grace interval
        // @details Sets the grace interval for over-temperature conditions. The grace interval defines the duration (in seconds) that the device can remain in
        // an over-temperature state before triggering any mitigation actions or notifications. This allows for temporary temperature spikes without immediate intervention.
        // @param graceInterval: interval in seconds
        // @example graceInterval - 30
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Temperature grace interval set successfully.
        // @retval Core::ERROR_GENERAL - Failed to set temperature grace interval.
        virtual Core::hresult SetOvertempGraceInterval(const int graceInterval ) = 0;

        /** Gets the current Temperature Thresholds.*/
        // @property
        // @text getOvertempGraceInterval
        // @brief Get Temperature Grace interval
        // @param graceInterval: interval in seconds
        // @example graceInterval: 30
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Temperature grace interval retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve temperature grace interval.
        virtual Core::hresult GetOvertempGraceInterval(int& graceInterval /* @out */) const = 0;

        /** Set Deep Sleep Timer for later wakeup */
        // @property
        // @text setDeepSleepTimer
        // @brief Set Deep sleep timer for timeOut period
        // @details Configures a deep sleep timer that determines how long the device will remain in deep sleep mode before automatically waking up. 
        // The timer is set in seconds, and when the specified timeout period elapses, the device will transition from deep sleep to an active state.
        // This feature is useful for scheduling wakeup events or ensuring that the device does not remain in deep sleep indefinitely.
        // @param timeOut: deep sleep timeout in seconds
        // @example timeOut: 60
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Deep sleep timer set successfully.
        // @retval Core::ERROR_GENERAL - Failed to set deep sleep timer.
        virtual Core::hresult SetDeepSleepTimer(const int timeOut ) = 0;

        /** Get Last Wakeup reason */
        // @property
        // @text getLastWakeupReason
        // @brief Get Last Wake up reason
        // @details Retrieves the last wakeup reason.
        // @param wakeupReason: wake up reason
        // @example wakeupReason: WakeupReason::TIMER
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Last wakeup reason retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve last wakeup reason.
        virtual Core::hresult GetLastWakeupReason(WakeupReason &wakeupReason /* @out */) const = 0;

        /** Get Last Wakeup key code */
        // @property
        // @text getLastWakeupKeyCode
        // @brief Get the key code that can be used for wakeup
        // @details Retrieves the key code that was used to wake up the device.
        // @param keycode: Key code for wakeup
        // @example keycode: 42
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Last wakeup key code retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve last wakeup key code.
        virtual Core::hresult GetLastWakeupKeyCode(int &keycode /* @out */) const = 0;

        /** Perform Reboot */
        // @text reboot
        // @brief Reboot device
        // @details Initiates a reboot of the device. The reboot process is coordinated by the Power Manager, which notifies registered clients of the impending reboot through the OnRebootBegin event. Clients can perform any necessary cleanup or state persistence before the actual reboot occurs.
        // @param rebootRequestor: Identifier for the entity requesting the reboot (e.g., "SystemManager", "UserRequest").
        // @example rebootRequestor - "SystemManager"
        // @param rebootReasonCustom: Custom reason for the reboot, providing additional context (e.g., "FirmwareUpgrade", "UserInitiated").
        // @example rebootReasonCustom - "FirmwareUpgrade"
        // @param rebootReasonOther: Additional details or context for the reboot reason (e.g., "User requested reboot after update").
        // @example rebootReasonOther - "User requested reboot after update"
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Reboot request accepted successfully.
        // @retval Core::ERROR_GENERAL - Failed to initiate reboot.
        virtual Core::hresult Reboot(const string &rebootRequestor , const string &rebootReasonCustom , const string &rebootReasonOther ) = 0;

        /** Set Network Standby Mode */
        // @property
        // @text setNetworkStandbyMode
        // @brief Set the standby mode for Network
        // @details Sets the standby mode for the network interface.
        // @param standbyMode: Network standby mode
        // @example standbyMode - true
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Network standby mode set successfully.
        // @retval Core::ERROR_GENERAL Failed to set network standby mode.
        virtual Core::hresult SetNetworkStandbyMode(const bool standbyMode ) = 0;

        /** Get Network Standby Mode */
        // @text getNetworkStandbyMode
        // @brief Get the standby mode for Network
        // @details Gets the standby mode for the network interface.
        // @param standbyMode: Network standby mode
        // @example standbyMode: true
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Network standby mode retrieved successfully.
        // @retval Core::ERROR_GENERAL Failed to retrieve network standby mode.
        virtual Core::hresult GetNetworkStandbyMode(bool &standbyMode /* @out */) = 0;

        /** Set Wakeup source configuration */
        // @text setWakeupSourceConfig
        // @brief Set the source configuration for device wakeup
        // @details Configures the wakeup sources that can trigger the device to transition from a low-power state to an active state.
        // The configuration is provided as an array of WakeupSourceConfig structures, each specifying a wakeup source and whether it is
        // enabled or disabled. This allows for fine-grained control over which events can wake the device.
        // @param wakeupSources: Wake up sources array
        // @example wakeupSources: [{wakeupSource: WAKEUP_SRC_IR, enabled: true}, {wakeupSource: WAKEUP_SRC_TIMER, enabled: false}]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Wakeup source configuration set successfully.
        // @retval Core::ERROR_GENERAL Failed to set wakeup source configuration.
        virtual Core::hresult SetWakeupSourceConfig(IWakeupSourceConfigIterator* const wakeupSources) = 0;

        /** Get Wakeup source configuration */
        // @text getWakeupSourceConfig
        // @brief Get the source configuration for device wakeup
        // @details Retrieves the current configuration of wakeup sources that can trigger the device to transition from a low-power state to an active state.
        // @param wakeupSources: Wake up sources array
        // @example wakeupSources: [{wakeupSource: WAKEUP_SRC_IR, enabled: true}, {wakeupSource: WAKEUP_SRC_TIMER, enabled: false}]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Wakeup source configuration retrieved successfully.
        // @retval Core::ERROR_GENERAL Failed to retrieve wakeup source configuration.
        virtual Core::hresult GetWakeupSourceConfig(IWakeupSourceConfigIterator*& wakeupSources /* @out */) const = 0;

        /** Get Power State before reboot */
        // @text getPowerStateBeforeReboot
        // @brief Get Power state before reboot
        // @details Retrieves the power state of the device before the last reboot.
        // @param powerStateBeforeReboot: Power state before the last reboot
        // @example powerStateBeforeReboot: POWER_STATE_ON
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Power state retrieved successfully.
        // @retval Core::ERROR_GENERAL Failed to retrieve power state.
        virtual Core::hresult GetPowerStateBeforeReboot(PowerState &powerStateBeforeReboot /* @out */) = 0;

        /** Power prechange activity completed */
        // @text powerModePreChangeComplete
        // @brief Pre power mode handling complete for given client and transation id
        // @details Notifies that the pre power mode handling is complete for the given client and transaction id.
        // @param clientId: Unique identifier for the client, as received in AddPowerModePreChangeClient
        // @example clientId: 1001
        // @param transactionId: transaction id as received in OnPowerModePreChange
        // @example transactionId: 1234
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Pre power mode handling completed successfully.
        // @retval Core::ERROR_GENERAL - Failed to complete pre power mode handling.
        virtual Core::hresult PowerModePreChangeComplete(const uint32_t clientId , const int transactionId ) = 0;

        /** Delay Powermode change by given time */
        // @text delayPowerModeChangeBy
        // @brief Delay Powermode change by given time. If different clients provide different values of delay, then the maximum of these values is used.
        // @details Requests a delay in the power mode change operation for the specified client and transaction ID. The delay period is specified in seconds. 
        // If multiple clients request delays, the Power Manager will use the maximum delay value provided by any client. This allows clients to perform necessary pre-change operations before the power state transition occurs.
        // @param clientId: Unique identifier for the client, as received in AddPowerModePreChangeClient
        // @example clientId: 1001
        // @param transactionId: transaction id as received in OnPowerModePreChange
        // @example transactionId: 1234
        // @param delayPeriod: delay in seconds
        // @example delayPeriod: 5
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Power mode change delay accepted successfully.
        // @retval Core::ERROR_GENERAL - Failed to process the power mode change delay request.
        virtual Core::hresult DelayPowerModeChangeBy(const uint32_t clientId , const int transactionId , const int delayPeriod ) = 0;

        /** Get the Wakeup Time in seconds */
        // @text getTimeSinceWakeup
        // @brief Get the Wakeup Time in seconds since the device transitioned to the ON state.
        // @details Retrieves the time elapsed in seconds since the device last transitioned to the ON power state.
        // This information can be useful for applications that need to track uptime or perform actions based on the duration since the last wakeup event.
        // @param timeSinceWakeup: Wakeup time in seconds
        // @example timeSinceWakeup: 3600
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult GetTimeSinceWakeup(TimeSinceWakeup &timeSinceWakeup /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

