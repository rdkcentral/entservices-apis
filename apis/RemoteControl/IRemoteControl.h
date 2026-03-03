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
#include "IRemoteControlStructs.h"

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
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(RemoteControlData::GetApiVersionNumberResponse& response /* @out */) = 0;

            // @brief Initiates pairing a remote with the STB on the specified network.
            // @text startPairing
            // @param request: The pairing request parameters
            // @retval ErrorCode::NONE: Pairing started successfully.
            // @retval ErrorCode::GENERAL: Failed to start pairing.
            virtual Core::hresult StartPairing(const RemoteControlData::StartPairingRequest& request) = 0;

            // @brief Cancels pairing a remote with the STB on the specified network.
            // @text stopPairing
            // @param request: The stop pairing request parameters
            // @retval ErrorCode::NONE: Pairing stopped successfully.
            // @retval ErrorCode::GENERAL: Failed to stop pairing.
            virtual Core::hresult StopPairing(const RemoteControlData::StopPairingRequest& request) = 0;

            // @brief Returns the status information provided by the last `onStatus` event for the specified network.
            // @text getNetStatus
            // @param request: The network status request parameters
            // @param response: The network status response
            // @retval ErrorCode::NONE: Network status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve network status.
            virtual Core::hresult GetNetStatus(const RemoteControlData::GetNetStatusRequest& request, RemoteControlData::GetNetStatusResponse& response /* @out */) = 0;

            // @brief Returns a list of manufacturer names based on the specified input parameters
            // @text getIRDBManufacturers
            // @param request: The get IRDB manufacturers request parameters
            // @param response: The get IRDB manufacturers response
            // @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers.
            virtual Core::hresult GetIRDBManufacturers(const RemoteControlData::GetIRDBManufacturersRequest& request, RemoteControlData::GetIRDBManufacturersResponse& response /* @out */) = 0;

            // @brief Returns a list of model names based on the specified input parameters
            // @text getIRDBModels
            // @param request: The get IRDB models request parameters
            // @param response: The get IRDB models response
            // @retval ErrorCode::NONE: IRDB models retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB models.
            virtual Core::hresult GetIRDBModels(const RemoteControlData::GetIRDBModelsRequest& request, RemoteControlData::GetIRDBModelsResponse& response /* @out */) = 0;

            // @brief Returns a list of available IR codes for the TV and AVRs specified by the input parameters
            // @text getIRCodesByAutoLookup
            // @param request: The get IR codes by auto lookup request parameters
            // @param response: The IR codes by auto lookup response
            // @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup.
            virtual Core::hresult GetIRCodesByAutoLookup(const RemoteControlData::GetIRCodesByAutoLookupRequest& request, RemoteControlData::GetIRCodesByAutoLookupResponse& response /* @out */) = 0;

            // @brief Returns a list of IR codes for the AV device specified by the input parameters
            // @text getIRCodesByNames
            // @param request: The get IR codes by names request parameters
            // @param response: The get IR codes by names response
            // @retval ErrorCode::NONE: IR codes retrieved successfully by names.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names.
            virtual Core::hresult GetIRCodesByNames(const RemoteControlData::GetIRCodesByNamesRequest& request, RemoteControlData::GetIRCodesByNamesResponse& response /* @out */) = 0;

            // @brief Programs an IR code into the specified remote control
            // @text setIRCode
            // @param request: The set IR code request parameters
            // @retval ErrorCode::NONE: IR code set successfully.
            // @retval ErrorCode::GENERAL: Failed to set IR code.
            virtual Core::hresult SetIRCode(const RemoteControlData::SetIRCodeRequest& request) = 0;

            // @brief Clears the IR codes from the specified remote
            // @text clearIRCodes
            // @param request: The clear IR codes request parameters
            // @retval ErrorCode::NONE: IR codes cleared successfully.
            // @retval ErrorCode::GENERAL: Failed to clear IR codes.
            virtual Core::hresult ClearIRCodes(const RemoteControlData::ClearIRCodesRequest& request) = 0;

            // @brief Returns last key press source data
            // @text getLastKeypressSource
            // @param response: The last keypress source response
            // @retval ErrorCode::NONE: Last keypress source retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve last keypress source.
            virtual Core::hresult GetLastKeypressSource(RemoteControlData::GetLastKeypressSourceResponse& response /* @out */) = 0;

            // @brief Configures which keys on the remote will wake the target from deepsleep
            // @text configureWakeupKeys
            // @param request: The configure wakeup keys request parameters
            // @retval ErrorCode::NONE: Wakeup keys configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure wakeup keys.
            virtual Core::hresult ConfigureWakeupKeys(const RemoteControlData::ConfigureWakeupKeysRequest& request) = 0;

            // @brief Initializes the IR database
            // @text initializeIRDB
            // @param request: The initialize IRDB request parameters
            // @retval ErrorCode::NONE: IRDB initialized successfully.
            // @retval ErrorCode::GENERAL: Failed to initialize IRDB.
            virtual Core::hresult InitializeIRDB(const RemoteControlData::InitializeIRDBRequest& request) = 0;

            // @brief Tells the most recently used remote to beep
            // @text findMyRemote
            // @param request: The find my remote request parameters
            // @retval ErrorCode::NONE: Find my remote executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute find my remote.
            virtual Core::hresult FindMyRemote(const RemoteControlData::FindMyRemoteRequest& request) = 0;

            // @brief Tells all paired and connected remotes to factory reset
            // @text factoryReset
            // @retval ErrorCode::NONE: Factory reset executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute factory reset.
            virtual Core::hresult FactoryReset() = 0;

            // @brief Unpairs a given or all remote(s) from the STB
            // @text unpair
            // @param request: The unpair request parameters
            // @retval ErrorCode::NONE: Remote unpaired successfully.
            // @retval ErrorCode::GENERAL: Failed to unpair remote.
            virtual Core::hresult Unpair(const RemoteControlData::UnpairRequest& request) = 0;

            // @brief Starts a firmware image update session for the specified remote(s)
            // @text startFirmwareUpdate
            // @param request: The start firmware update request parameters
            // @param response: The start firmware update response
            // @retval ErrorCode::NONE: Firmware update started successfully.
            // @retval ErrorCode::GENERAL: Failed to start firmware update.
            virtual Core::hresult StartFirmwareUpdate(const RemoteControlData::StartFirmwareUpdateRequest& request, RemoteControlData::StartFirmwareUpdateResponse& response /* @out */) = 0;

            // @brief Cancels an active firmware image update session
            // @text cancelFirmwareUpdate
            // @param request: The cancel firmware update request parameters
            // @retval ErrorCode::NONE: Firmware update cancelled successfully.
            // @retval ErrorCode::GENERAL: Failed to cancel firmware update.
            virtual Core::hresult CancelFirmwareUpdate(const RemoteControlData::CancelFirmwareUpdateRequest& request) = 0;

            // @brief Returns the status of an active firmware image update session
            // @text statusFirmwareUpdate
            // @param request: The status firmware update request parameters
            // @param response: The status firmware update response
            // @retval ErrorCode::NONE: Firmware update status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve firmware update status.
            virtual Core::hresult StatusFirmwareUpdate(const RemoteControlData::StatusFirmwareUpdateRequest& request, RemoteControlData::StatusFirmwareUpdateResponse& response /* @out */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_REMOTECONTROL_NOTIFICATION };

                // @brief Triggered at any time when the status of any one of the supported STB remote networks changes
                // @text onStatus
                // @param status: Event data containing remote control status information.
                virtual void OnStatus(const RemoteControlData::StatusEventData& status) {}

                // @brief Generated for manual pairing validation
                // @text onValidation
                // @param status: Event data containing remote control validation information.
                virtual void OnValidation(const RemoteControlData::ValidationStatusObject& status) {}

                // @brief Generated at 0 and 100 percent and each time a download percent increment is reached
                // @text onFirmwareUpdateProgress
                // @param progress: Event data containing firmware update progress information.
                virtual void OnFirmwareUpdateProgress(const RemoteControlData::FirmwareUpdateProgressEvent& progress) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
