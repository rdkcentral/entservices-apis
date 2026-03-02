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

// @stubgen:include <com/IIteratorType.h>

struct ctrlm_main_iarm_event_json_t;

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
            // @brief Gets the current API version number.
            // @text getApiVersionNumber
            // @param parameters: Input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Initiates pairing a remote with the STB on the specified network.
            // @text startPairing
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Pairing started successfully.
            // @retval ErrorCode::GENERAL: Failed to start pairing.
            virtual Core::hresult StartPairing(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Cancels pairing a remote with the STB on the specified network.
            // @text stopPairing
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Pairing stopped successfully.
            // @retval ErrorCode::GENERAL: Failed to stop pairing.
            virtual Core::hresult StopPairing(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns the status information provided by the last `onStatus` event for the specified network.
            // @text getNetStatus
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Network status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve network status.
            virtual Core::hresult GetNetStatus(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns a list of manufacturer names based on the specified input parameters
            // @text getIRDBManufacturers
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers.
            virtual Core::hresult GetIRDBManufacturers(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns a list of model names based on the specified input parameters
            // @text getIRDBModels
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB models retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB models.
            virtual Core::hresult GetIRDBModels(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns a list of available IR codes for the TV and AVRs specified by the input parameters
            // @text getIRCodesByAutoLookup
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup.
            virtual Core::hresult GetIRCodesByAutoLookup(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns a list of IR codes for the AV device specified by the input parameters
            // @text getIRCodesByNames
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes retrieved successfully by names.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names.
            virtual Core::hresult GetIRCodesByNames(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Programs an IR code into the specified remote control
            // @text setIRCode
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR code set successfully.
            // @retval ErrorCode::GENERAL: Failed to set IR code.
            virtual Core::hresult SetIRCode(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Clears the IR codes from the specified remote
            // @text clearIRCodes
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IR codes cleared successfully.
            // @retval ErrorCode::GENERAL: Failed to clear IR codes.
            virtual Core::hresult ClearIRCodes(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns last key press source data
            // @text getLastKeypressSource
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Last keypress source retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve last keypress source.
            virtual Core::hresult GetLastKeypressSource(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Configures which keys on the remote will wake the target from deepsleep
            // @text configureWakeupKeys
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Wakeup keys configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure wakeup keys.
            virtual Core::hresult ConfigureWakeupKeys(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Initializes the IR database
            // @text initializeIRDB
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: IRDB initialized successfully.
            // @retval ErrorCode::GENERAL: Failed to initialize IRDB.
            virtual Core::hresult InitializeIRDB(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Tells the most recently used remote to beep
            // @text findMyRemote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Find my remote executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute find my remote.
            virtual Core::hresult FindMyRemote(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Tells all paired and connected remotes to factory reset
            // @text factoryReset
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Factory reset executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute factory reset.
            virtual Core::hresult FactoryReset(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Unpairs a given or all remote(s) from the STB
            // @text unpair
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Remote unpaired successfully.
            // @retval ErrorCode::GENERAL: Failed to unpair remote.
            virtual Core::hresult Unpair(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Starts a firmware image update session for the specified remote(s)
            // @text startFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update started successfully.
            // @retval ErrorCode::GENERAL: Failed to start firmware update.
            virtual Core::hresult StartFirmwareUpdate(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Cancels an active firmware image update session
            // @text cancelFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update cancelled successfully.
            // @retval ErrorCode::GENERAL: Failed to cancel firmware update.
            virtual Core::hresult CancelFirmwareUpdate(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;

            // @brief Returns the status of an active firmware image update session
            // @text statusFirmwareUpdate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Firmware update status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve firmware update status.
            virtual Core::hresult StatusFirmwareUpdate(const string& parameters /* @opaque */, string& response /* @out @opaque */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_REMOTECONTROL_NOTIFICATION };

                // @brief Triggered at any time when the status of any one of the supported STB remote networks changes
                // @text onStatus
                // @param params: Event data containing remote control status information.
                virtual void OnStatus(const string& params /* @opaque */) {}

                // @brief Generated for manual pairing validation
                // @text onValidation
                // @param params: Event data containing remote control validation information.
                virtual void OnValidation(const string& params /* @opaque */) {}

                // @brief Generated at 0 and 100 percent and each time a download percent increment is reached
                // @text onFirmwareUpdateProgress
                // @param params: Event data containing firmware update progress information.
                virtual void OnFirmwareUpdateProgress(const string& params /* @opaque */) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
