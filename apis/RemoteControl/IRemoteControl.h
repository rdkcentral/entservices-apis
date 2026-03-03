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

        // Enums for Remote Control

        enum class PairingState : uint8_t {
            INITIALISING  /* @text INITIALISING */,
            IDLE          /* @text IDLE */,
            SEARCHING     /* @text SEARCHING */,
            PAIRING       /* @text PAIRING */,
            COMPLETE      /* @text COMPLETE */,
            FAILED        /* @text FAILED */
        };

        enum class IRProgState : uint8_t {
            IDLE      /* @text IDLE */,
            WAITING   /* @text WAITING */,
            COMPLETE  /* @text COMPLETE */,
            FAILED    /* @text FAILED */
        };

        // Data structures for Remote Control

        struct EXTERNAL RemoteData {
            string macAddress       /* @brief The MAC address of the remote in hex-colon format e.g. "AA:BB:CC:DD:EE:FF" */;
            bool connected          /* @brief True if the remote is connected, otherwise false */;
            string name             /* @brief The remote name e.g. "XR15-700" */;
            uint32_t remoteId       /* @brief This integer is the remote ID number, assigned by the network */;
            uint32_t deviceId       /* @brief The device ID number that is assigned by the network */;
            string make             /* @brief The manufacturer name of the remote e.g. "Technicolor" */;
            string model            /* @brief The remote model name e.g. "XR15" */;
            string hwVersion        /* @brief The remote hardware revision */;
            string swVersion        /* @brief The remote software revision */;
            string btlVersion       /* @brief The remote bootloader revision */;
            string serialNumber     /* @brief The remote serial number */;
            uint8_t batteryPercent  /* @brief The current remote battery level as a percentage (0 to 100) */;
            string tvIRCode         /* @brief The current TV IR code that the remote is programmed with */;
            string ampIRCode        /* @brief The current AVR/AMP IR code that the remote is programmed with */;
            uint32_t wakeupKeyCode  /* @brief The Linux key code of the last button to be pressed on the remote before wakeup from deepsleep */;
            string wakeupConfig     /* @brief The current deepsleep wakeup key configuration of the remote e.g. "all", "none", "custom" */;
            string wakeupCustomList /* @brief List of linux keycodes that can wake the target from deepsleep (only present if wakeupConfig is custom) */;
            string upgradeSessionId /* @brief The unique identifier for the firmware update session */;
        };

        using IRemoteDataIterator = RPC::IIteratorType<RemoteData, RPC::ID_STRINGITERATOR>;
        using IUint32Iterator = RPC::IIteratorType<uint32_t, RPC::ID_STRINGITERATOR>;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        struct EXTERNAL GetApiVersionNumberResponse {
            uint32_t version /* @brief The API version number e.g. 1 */;
        };

        struct EXTERNAL StartPairingRequest {
            uint32_t netType        /* @brief The type of network e.g. 1 */;
            uint32_t timeout        /* @brief The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout) e.g. 30 */;
        };

        struct EXTERNAL StopPairingRequest {
            bool screenBindDisable /* @brief Whether to disable screen bind mode (default: true) */;
            bool scanDisable       /* @brief Whether to disable scanning for remotes (default: true) */;
        };

        struct EXTERNAL NetworkStatus {
            uint32_t netType       /* @brief The type of network e.g. 1 */;
            PairingState pairingState /* @brief The current overall pairing state of the specified network */;
            IRProgState irProgState   /* @brief The current state of the IR code programming request to the remote */;
        };

        struct EXTERNAL GetNetStatusRequest {
            uint32_t netType /* @brief The type of network e.g. 1 */;
        };

        struct EXTERNAL GetNetStatusResponse {
            NetworkStatus status /* @brief The network status information */;
        };

        struct EXTERNAL InitializeIRDBRequest {
            uint32_t netType /* @brief The type of network e.g. 1 */;
        };

        struct EXTERNAL ClearIRCodesRequest {
            uint32_t remoteId /* @brief The remote ID of the target remote on the specified network e.g. 1 */;
            uint32_t netType  /* @brief The type of network e.g. 1 */;
        };

        struct EXTERNAL SetIRCodeRequest {
            uint32_t remoteId /* @brief The remote ID of the target remote on the specified network e.g. 1 */;
            uint32_t netType  /* @brief The type of network e.g. 1 */;
            string avDevType  /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string code       /* @brief The IR code being programmed into the remote e.g. "PANASONIC_3DTV" */;
        };

        struct EXTERNAL GetIRCodesByAutoLookupRequest {
            uint32_t netType /* @brief The type of network e.g. 1 */;
        };

        struct EXTERNAL GetIRCodesByAutoLookupResponse {
            string tvManufacturer  /* @brief The TV manufacturer for which codes are provided e.g. "Samsung" */;
            string tvModel         /* @brief The TV model for which codes are provided e.g. "UN65JU750" */;
            string avrManufacturer /* @brief The AVR manufacturer for which codes are provided e.g. "Denon" */;
            string avrModel        /* @brief The AVR model for which codes are provided e.g. "AVR-S750H" */;
        };

        struct EXTERNAL IRCodeList {
            string code /* @brief IR code e.g. "PANASONIC_3DTV" */;
        };

        using IIRCodeIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        struct EXTERNAL GetIRCodesByNamesRequest {
            string avDevType    /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string manufacturer /* @brief The manufacturer name of the AV device e.g. "Samsung" */;
            string model        /* @brief The model name of the AV device e.g. "UN65JU750" */;
        };

        struct EXTERNAL GetIRCodesByNamesResponse {
            string avDevType    /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string manufacturer /* @brief The manufacturer name of the AV device e.g. "Samsung" */;
            string model        /* @brief The model name of the AV device e.g. "UN65JU750" */;
        };

        using IManufacturerIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        using IModelIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        struct EXTERNAL GetIRDBManufacturersRequest {
            string avDevType    /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string manufacturer /* @brief A part of the name of the manufacturer of the AV device e.g. "Sam" */;
        };

        struct EXTERNAL GetIRDBManufacturersResponse {
            string avDevType /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
        };

        struct EXTERNAL GetIRDBModelsRequest {
            string avDevType    /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string manufacturer /* @brief The manufacturer name of the AV device e.g. "Samsung" */;
            string model        /* @brief A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6" */;
        };

        struct EXTERNAL GetIRDBModelsResponse {
            string avDevType    /* @brief Whether the device is a video (TV) or audio (AMP) device e.g. "TV" */;
            string manufacturer /* @brief The manufacturer name of the AV device e.g. "Samsung" */;
        };

        struct EXTERNAL GetLastKeypressSourceResponse {
            uint32_t controllerId    /* @brief The controller ID of the target remote on the specified network e.g. 1 */;
            uint64_t timestamp       /* @brief The time of the last key press in milliseconds since epoch */;
            string sourceName        /* @brief The source of the last key press e.g. "IR" */;
            string sourceType        /* @brief The source type of the last key press e.g. "REMOTE" */;
            uint32_t sourceKeyCode   /* @brief The source key code e.g. 195 */;
            bool isScreenBindMode    /* @brief true if in screen bind mode, otherwise false */;
            uint32_t remoteKeypadConfig /* @brief The configuration of the remote keypad e.g. 0 */;
        };

        struct EXTERNAL ConfigureWakeupKeysRequest {
            string wakeupConfig  /* @brief The deepsleep wakeup key configuration of the remote e.g. "all", "none", "custom" */;
            string customKeys    /* @brief List of Linux key codes that can wake the target from deepsleep (mandatory if wakeupConfig is custom) e.g. "195,199" */;
        };

        struct EXTERNAL FindMyRemoteRequest {
            string level /* @brief The level at which the remote will beep e.g. "off", "mid", "high" */;
        };

        struct EXTERNAL StartFirmwareUpdateRequest {
            string macAddress       /* @brief The MAC address of the target remote e.g. "AA:BB:CC:DD:EE:FF" */;
            string fileName         /* @brief The full path and filename for the firmware image e.g. "/tmp/remote_firmware.bin" */;
            string fileType         /* @brief The type of firmware image file e.g. "mfg" */;
            uint32_t percentIncrement /* @brief The increment change of a firmware update to notify (1-100 percent) e.g. 10 */;
        };

        struct EXTERNAL StartFirmwareUpdateResponse {
            uint32_t sessionId /* @brief The session identifier for the firmware update e.g. 12345 */;
        };

        struct EXTERNAL CancelFirmwareUpdateRequest {
            uint32_t sessionId /* @brief The session identifier e.g. 12345 */;
        };

        struct EXTERNAL StatusFirmwareUpdateRequest {
            uint32_t sessionId /* @brief The session identifier e.g. 12345 */;
        };

        struct EXTERNAL FirmwareUpdateStatus {
            string state           /* @brief The firmware update state e.g. "DOWNLOADING", "COMPLETE", "FAILED" */;
            uint32_t percentComplete /* @brief The percentage complete (0-100) e.g. 50 */;
        };

        struct EXTERNAL StatusFirmwareUpdateResponse {
            FirmwareUpdateStatus result /* @brief The firmware update status */;
        };

        struct EXTERNAL StatusEventData {
            uint32_t netType        /* @brief The type of remote control network e.g. 1 */;
            bool netTypeSupported   /* @brief Whether the network type is supported */;
            PairingState pairingState  /* @brief The pairing state */;
            IRProgState irProgState    /* @brief The IR programming state */;
        };

        struct EXTERNAL ValidationStatusObject {
            uint32_t netType           /* @brief The type of remote control network e.g. 1 */;
            uint32_t validationDigit1  /* @brief The first validation digit e.g. 1 */;
            uint32_t validationDigit2  /* @brief The second validation digit e.g. 2 */;
            uint32_t validationDigit3  /* @brief The third validation digit e.g. 3 */;
        };

        struct EXTERNAL FirmwareUpdateProgressEvent {
            uint32_t sessionId         /* @brief The session identifier e.g. 12345 */;
            FirmwareUpdateStatus status /* @brief The firmware update status */;
        };

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
            virtual Core::hresult GetApiVersionNumber(GetApiVersionNumberResponse& response /* @out */) = 0;

            // @brief Initiates pairing a remote with the STB on the specified network.
            // @text startPairing
            // @param request: The pairing request parameters
            // @retval ErrorCode::NONE: Pairing started successfully.
            // @retval ErrorCode::GENERAL: Failed to start pairing.
            virtual Core::hresult StartPairing(const StartPairingRequest& request) = 0;

            // @brief Cancels pairing a remote with the STB on the specified network.
            // @text stopPairing
            // @param request: The stop pairing request parameters
            // @retval ErrorCode::NONE: Pairing stopped successfully.
            // @retval ErrorCode::GENERAL: Failed to stop pairing.
            virtual Core::hresult StopPairing(const StopPairingRequest& request) = 0;

            // @brief Returns the status information provided by the last `onStatus` event for the specified network.
            // @text getNetStatus
            // @param request: The network status request parameters
            // @param netType: The type of network
            // @param netTypeSupported: A list of the network types that the STB supports
            // @param pairingState: The current overall pairing state of the specified network
            // @param irProgState: The current state of the IR code programming request to the remote
            // @param remoteData: Remote information for each paired remote control
            // @retval ErrorCode::NONE: Network status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve network status.
            virtual Core::hresult GetNetStatus(const GetNetStatusRequest& request, uint32_t& netType /* @out */, IUint32Iterator*& netTypeSupported /* @out */, PairingState& pairingState /* @out */, IRProgState& irProgState /* @out */, IRemoteDataIterator*& remoteData /* @out */) = 0;

            // @brief Returns a list of manufacturer names based on the specified input parameters
            // @text getIRDBManufacturers
            // @param request: The get IRDB manufacturers request parameters
            // @param manufacturers: A list of manufacturer names
            // @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers.
            virtual Core::hresult GetIRDBManufacturers(const GetIRDBManufacturersRequest& request, IStringIterator*& manufacturers /* @out */) = 0;

            // @brief Returns a list of model names based on the specified input parameters
            // @text getIRDBModels
            // @param request: The get IRDB models request parameters
            // @param models: A list of model names
            // @retval ErrorCode::NONE: IRDB models retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB models.
            virtual Core::hresult GetIRDBModels(const GetIRDBModelsRequest& request, IStringIterator*& models /* @out */) = 0;

            // @brief Returns a list of available IR codes for the TV and AVRs specified by the input parameters
            // @text getIRCodesByAutoLookup
            // @param request: The get IR codes by auto lookup request parameters
            // @param tvCodes: A list of TV IR codes
            // @param avrCodes: A list of AVR IR codes
            // @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup.
            virtual Core::hresult GetIRCodesByAutoLookup(const GetIRCodesByAutoLookupRequest& request, IStringIterator*& tvCodes /* @out */, IStringIterator*& avrCodes /* @out */) = 0;

            // @brief Returns a list of IR codes for the AV device specified by the input parameters
            // @text getIRCodesByNames
            // @param request: The get IR codes by names request parameters
            // @param codes: A list of IR codes for the specified device
            // @retval ErrorCode::NONE: IR codes retrieved successfully by names.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names.
            virtual Core::hresult GetIRCodesByNames(const GetIRCodesByNamesRequest& request, IStringIterator*& codes /* @out */) = 0;

            // @brief Programs an IR code into the specified remote control
            // @text setIRCode
            // @param request: The set IR code request parameters
            // @retval ErrorCode::NONE: IR code set successfully.
            // @retval ErrorCode::GENERAL: Failed to set IR code.
            virtual Core::hresult SetIRCode(const SetIRCodeRequest& request) = 0;

            // @brief Clears the IR codes from the specified remote
            // @text clearIRCodes
            // @param request: The clear IR codes request parameters
            // @retval ErrorCode::NONE: IR codes cleared successfully.
            // @retval ErrorCode::GENERAL: Failed to clear IR codes.
            virtual Core::hresult ClearIRCodes(const ClearIRCodesRequest& request) = 0;

            // @brief Returns last key press source data
            // @text getLastKeypressSource
            // @param response: The last keypress source response
            // @retval ErrorCode::NONE: Last keypress source retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve last keypress source.
            virtual Core::hresult GetLastKeypressSource(GetLastKeypressSourceResponse& response /* @out */) = 0;

            // @brief Configures which keys on the remote will wake the target from deepsleep
            // @text configureWakeupKeys
            // @param request: The configure wakeup keys request parameters
            // @retval ErrorCode::NONE: Wakeup keys configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure wakeup keys.
            virtual Core::hresult ConfigureWakeupKeys(const ConfigureWakeupKeysRequest& request) = 0;

            // @brief Initializes the IR database
            // @text initializeIRDB
            // @param request: The initialize IRDB request parameters
            // @retval ErrorCode::NONE: IRDB initialized successfully.
            // @retval ErrorCode::GENERAL: Failed to initialize IRDB.
            virtual Core::hresult InitializeIRDB(const InitializeIRDBRequest& request) = 0;

            // @brief Tells the most recently used remote to beep
            // @text findMyRemote
            // @param request: The find my remote request parameters
            // @retval ErrorCode::NONE: Find my remote executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute find my remote.
            virtual Core::hresult FindMyRemote(const FindMyRemoteRequest& request) = 0;

            // @brief Tells all paired and connected remotes to factory reset
            // @text factoryReset
            virtual Core::hresult FactoryReset() = 0;

            // @brief Unpairs all remotes from the STB
            // @text unpair
            virtual Core::hresult Unpair() = 0;

            // @brief Starts a firmware image update session for the specified remote(s)
            // @text startFirmwareUpdate
            // @param request: The start firmware update request parameters
            // @param response: The start firmware update response
            // @retval ErrorCode::NONE: Firmware update started successfully.
            // @retval ErrorCode::GENERAL: Failed to start firmware update.
            virtual Core::hresult StartFirmwareUpdate(const StartFirmwareUpdateRequest& request, StartFirmwareUpdateResponse& response /* @out */) = 0;

            // @brief Cancels an active firmware image update session
            // @text cancelFirmwareUpdate
            // @param request: The cancel firmware update request parameters
            // @retval ErrorCode::NONE: Firmware update cancelled successfully.
            // @retval ErrorCode::GENERAL: Failed to cancel firmware update.
            virtual Core::hresult CancelFirmwareUpdate(const CancelFirmwareUpdateRequest& request) = 0;

            // @brief Returns the status of an active firmware image update session
            // @text statusFirmwareUpdate
            // @param request: The status firmware update request parameters
            // @param response: The status firmware update response
            // @retval ErrorCode::NONE: Firmware update status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve firmware update status.
            virtual Core::hresult StatusFirmwareUpdate(const StatusFirmwareUpdateRequest& request, StatusFirmwareUpdateResponse& response /* @out */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_REMOTECONTROL_NOTIFICATION };

                // @brief Triggered at any time when the status of any one of the supported STB remote networks changes
                // @text onStatus
                // @param status: Event data containing remote control status information.
                virtual void OnStatus(const StatusEventData& status) {}

                // @brief Generated for manual pairing validation
                // @text onValidation
                // @param status: Event data containing remote control validation information.
                virtual void OnValidation(const ValidationStatusObject& status) {}

                // @brief Generated at 0 and 100 percent and each time a download percent increment is reached
                // @text onFirmwareUpdateProgress
                // @param progress: Event data containing firmware update progress information.
                virtual void OnFirmwareUpdateProgress(const FirmwareUpdateProgressEvent& progress) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
