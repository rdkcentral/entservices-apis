/**
 * @file IRemoteControl.h
 * @brief Remote Control JSONRPC interface definition for WPEFramework.
 * 
 * If not stated otherwise in this file or this component's LICENSE
 * file the following copyright and licenses apply:
 *
 * Copyright 2023 RDK Management
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
**/

#pragma once

#include "Module.h"
#include "libIBus.h"
#include "ctrlm_ipc.h"
#include "ctrlm_ipc_rcu.h"
#include "ctrlm_ipc_ble.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {

    namespace Exchange {

        /**
         * @brief Interface for the Remote Control JSONRPC API in WPEFramework.
         *
         * This interface defines the JSONRPC methods and events for remote control management,
         * including pairing, IRDB operations, firmware updates, and related notifications.
         * Implementations of this interface are expected to be registered with the Thunder framework.
         */
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IRemoteControl : virtual public Core::IUnknown {

            enum { ID = ID_REMOTECONTROL };

            // Begin methods
            // @brief Get the API version number
            // @text getApiVersionNumber
            // @param parameters: Input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start pairing process
            // @text startPairing
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Pairing started successfully.
            // @retval ErrorCode::GENERAL: Failed to start pairing.
            virtual Core::hresult StartPairing(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Stop pairing process
            // @text stopPairing
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Pairing stopped successfully.
            // @retval ErrorCode::GENERAL: Failed to stop pairing.
            virtual Core::hresult StopPairing(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get network status
            // @text getNetStatus
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Network status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve network status.
            virtual Core::hresult GetNetStatus(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IRDB manufacturers
            // @text getIRDBManufacturers
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers.
            virtual Core::hresult GetIRDBManufacturers(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IRDB models
            // @text getIRDBModels
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB models retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB models.
            virtual Core::hresult GetIRDBModels(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IR codes by auto lookup
            // @text getIRCodesByAutoLookup
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup.
            virtual Core::hresult GetIRCodesByAutoLookup(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IR codes by names
            // @text getIRCodesByNames
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes retrieved successfully by names.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names.
            virtual Core::hresult GetIRCodesByNames(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Set IR code
            // @text setIRCode
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR code set successfully.
            // @retval ErrorCode::GENERAL: Failed to set IR code.
            virtual Core::hresult SetIRCode(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Clear IR codes
            // @text clearIRCodes
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes cleared successfully.
            // @retval ErrorCode::GENERAL: Failed to clear IR codes.
            virtual Core::hresult ClearIRCodes(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get last keypress source
            // @text getLastKeypressSource
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Last keypress source retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve last keypress source.
            virtual Core::hresult GetLastKeypressSource(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Configure wakeup keys
            // @text configureWakeupKeys
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Wakeup keys configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure wakeup keys.
            virtual Core::hresult ConfigureWakeupKeys(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Initialize IRDB
            // @text initializeIRDB
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB initialized successfully.
            // @retval ErrorCode::GENERAL: Failed to initialize IRDB.
            virtual Core::hresult InitializeIRDB(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Find my remote
            // @text findMyRemote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Find my remote executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute find my remote.
            virtual Core::hresult FindMyRemote(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Factory reset
            // @text factoryReset
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Factory reset executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute factory reset.
            virtual Core::hresult FactoryReset(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Unpair remote
            // @text unpair
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Remote unpaired successfully.
            // @retval ErrorCode::GENERAL: Failed to unpair remote.
            virtual Core::hresult Unpair(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start firmware update
            // @text startFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update started successfully.
            // @retval ErrorCode::GENERAL: Failed to start firmware update.
            virtual Core::hresult StartFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Cancel firmware update
            // @text cancelFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update cancelled successfully.
            // @retval ErrorCode::GENERAL: Failed to cancel firmware update.
            virtual Core::hresult CancelFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get firmware update status
            // @text statusFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve firmware update status.
            virtual Core::hresult StatusFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_REMOTECONTROL_NOTIFICATION };

                // @brief Status event
                // @text onStatus
                // @param eventData: Pointer to event data containing remote control status information.
                virtual void OnStatus(ctrlm_main_iarm_event_json_t* eventData) {}

                // @brief Validation event
                // @text onValidation
                // @param eventData: Pointer to event data containing remote control validation information.
                virtual void OnValidation(ctrlm_main_iarm_event_json_t* eventData) {}

                // @brief Firmware update progress event
                // @text onFirmwareUpdateProgress
                // @param eventData: Pointer to event data containing firmware update progress information.
                virtual void OnFirmwareUpdateProgress(ctrlm_main_iarm_event_json_t* eventData) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
