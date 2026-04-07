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
#include "../ControlCommon.h"

// @stubgen:include <com/IIteratorType.h>
// @stubgen:include "../ControlCommon.h"

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

        enum class AVDevType : uint8_t {
            INVALID = 0 /* @text INVALID */,
            TV          /* @text TV */,
            AMP         /* @text AMP */
        };

        enum class WakeupConfig : uint8_t {
            INVALID = 0 /* @text INVALID */,
            ALL         /* @text all */,
            NONE        /* @text none */,
            CUSTOM      /* @text custom */
        };

        enum class FindMyRemoteLevel : uint8_t {
            INVALID = 0 /* @text INVALID */,
            OFF         /* @text off */,
            MID         /* @text mid */,
            HIGH        /* @text high */
        };

        enum class FirmwareUpdateState : uint8_t {
            DOWNLOADING /* @text DOWNLOADING */,
            COMPLETE    /* @text COMPLETE */,
            FAILED      /* @text FAILED */
        };

        // Data structures for Remote Control

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        struct EXTERNAL GetLastKeypressSourceResponse {
            uint32_t controllerId       /* @brief The controller ID of the target remote on the specified network ex: 1 */;
            uint64_t timestamp          /* @brief The time of the last key press in milliseconds since epoch */;
            string sourceName           /* @brief The source of the last key press e.g. "IR" */;
            string sourceType           /* @brief The source type of the last key press e.g. "REMOTE" */;
            uint32_t sourceKeyCode      /* @brief The source key code ex: 195 */;
            bool bIsScreenBindMode      /* @brief True if in screen bind mode, otherwise false */;
            uint32_t remoteKeypadConfig /* @brief The configuration of the remote keypad ex: 0 */;
            bool success                /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL FirmwareUpdateStatus {
            FirmwareUpdateState state /* @brief The firmware update state */;
            uint32_t percentComplete  /* @brief The estimated percentage of the firmware update that has completed (0-100) ex: 50 */;
        };

        struct EXTERNAL StatusFirmwareUpdateResponse {
            string sessionId          /* @brief The firmware update session identifier ex: 12345-abc-def */;
            string macAddress         /* @brief The MAC address of the remote in hex-colon format e.g. "AA:BB:CC:DD:EE:FF" */;
            FirmwareUpdateState state /* @brief The firmware update state */;
            uint32_t percentComplete  /* @brief The estimated percentage of the firmware update that has completed (0-100) ex: 50 */;
            string error              /* @optional @brief The firmware update error string, only present on failure */;
            bool success              /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL NetStatusData {
            uint32_t netType          /* @brief The type of remote control network ex: 1 */;
            PairingState pairingState /* @brief The pairing state */;
            IRProgState irProgState   /* @brief The IR programming state */;
            string netTypesSupported  /* @opaque @brief JSON array of supported network types e.g. [1] */;
            string remoteData         /* @opaque @brief JSON array of paired remote information */;
        };

        struct EXTERNAL GetNetStatusResult {
            bool success         /* @brief Whether the request succeeded */;
            NetStatusData status /* @brief The network status data */;
        };

        struct EXTERNAL StatusEventData {
            uint32_t netType          /* @brief The type of remote control network ex: 1 */;
            bool netTypeSupported     /* @brief Whether the network type is supported */;
            PairingState pairingState /* @brief The pairing state */;
            IRProgState irProgState   /* @brief The IR programming state */;
        };

        struct EXTERNAL ValidationStatusObject {
            uint32_t netType           /* @brief The type of remote control network ex: 1 */;
            uint32_t validationDigit1  /* @brief The first validation digit ex: 1 */;
            uint32_t validationDigit2  /* @brief The second validation digit ex: 2 */;
            uint32_t validationDigit3  /* @brief The third validation digit ex: 3 */;
        };

        struct EXTERNAL FirmwareUpdateProgressEvent {
            string sessionId            /* @brief The session identifier ex: 12345-abc-def */;
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
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @text getApiVersionNumber
            virtual Core::hresult GetApiVersionNumber(GetApiVersionNumberResponse& response /* @out @extract */) = 0;

            // @brief Initiates pairing a remote with the STB on the specified network.
            // @text startPairing
            // @param netType: The type of network ex: 1
            // @param timeout: The amount of time, in seconds, to attempt pairing before timing out (0 indicates no timeout) ex: 30
            // @param screenBindEnable: Whether to enable screen bind mode (default: true)
            // @param scanEnable: Whether to enable scanning for remotes (default: true)
            // @param success: Whether the request succeeded
            // @param macAddressList(optional): Optional list of MAC addresses to pair with (only used if scanEnable is true)
            // @retval ErrorCode::NONE: Pairing started successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to start pairing.
            virtual Core::hresult StartPairing(const uint32_t netType, const uint32_t timeout, const bool screenBindEnable, const bool scanEnable, SuccessResult& result /* @out @extract */, IStringIterator* const macAddressList) = 0;

            // @brief Cancels pairing a remote with the STB on the specified network.
            // @text stopPairing
            // @param screenBindDisable: Whether to disable screen bind mode (default: true)
            // @param scanDisable: Whether to disable scanning for remotes (default: true)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Pairing stopped successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to stop pairing.
            virtual Core::hresult StopPairing(const bool screenBindDisable, const bool scanDisable, SuccessResult& result /* @out @extract */) = 0;

            // @brief Returns the status information provided by the last `onStatus` event for the specified network.
            // @text getNetStatus
            // @param netType: The type of network ex: 1
            // @param result: The network status result containing success and a nested status object with netType, pairingState, irProgState, netTypesSupported, and remoteData
            // @retval ErrorCode::NONE: Network status retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve network status.
            virtual Core::hresult GetNetStatus(const uint32_t netType, GetNetStatusResult& result /* @out @extract */) = 0;

            // @brief Returns a list of manufacturer names based on the specified input parameters
            // @text getIRDBManufacturers
            // @param avDevType: Whether the device is a video (TV) or audio (AMP) device
            // @param manufacturer: A part of the name of the manufacturer of the AV device e.g. "Sam"
            // @param success: Whether the request succeeded
            // @param manufacturers: A list of manufacturer names e.g. "Samsung"
            // @retval ErrorCode::NONE: IRDB manufacturers retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB manufacturers.
            virtual Core::hresult GetIRDBManufacturers(AVDevType& avDevType /* @inout */, const string& manufacturer, bool& success /* @out */, IStringIterator*& manufacturers /* @out */) = 0;

            // @brief Returns a list of model names based on the specified input parameters
            // @text getIRDBModels
            // @param avDevType: Whether the device is a video (TV) or audio (AMP) device
            // @param manufacturer: The manufacturer name of the AV device e.g. "Samsung"
            // @param model: A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6"
            // @param success: Whether the request succeeded
            // @param models: A list of model names e.g. "AH5901068L"
            // @retval ErrorCode::NONE: IRDB models retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve IRDB models.
            virtual Core::hresult GetIRDBModels(AVDevType& avDevType /* @inout */, string& manufacturer /* @inout */, const string& model, bool& success /* @out */, IStringIterator*& models /* @out @optional */) = 0;

            // @brief Returns a list of available IR codes for the TV and AVRs specified by the input parameters
            // @text getIRCodesByAutoLookup
            // @param netType: The type of network ex: 1
            // @param tvManufacturer: The TV manufacturer for which codes are provided e.g. "Samsung"
            // @param tvModel: The TV model for which codes are provided e.g. "UN65JU750"
            // @param avrManufacturer: The AVR manufacturer for which codes are provided e.g. "Denon"
            // @param avrModel: The AVR model for which codes are provided e.g. "AVR-S750H"
            // @param success: Whether the request succeeded
            // @param tvCodes: A list of TV IR codes e.g. "1156"
            // @param avrCodes: A list of AVR IR codes e.g. "R2467"
            // @retval ErrorCode::NONE: IR codes retrieved successfully by auto lookup.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by auto lookup.
            virtual Core::hresult GetIRCodesByAutoLookup(const uint32_t netType, string& tvManufacturer /* @out */, string& tvModel /* @out */, string& avrManufacturer /* @out */, string& avrModel /* @out */, bool& success /* @out */, IStringIterator*& tvCodes /* @out */, IStringIterator*& avrCodes /* @out */) = 0;

            // @brief Returns a list of IR codes for the AV device specified by the input parameters
            // @text getIRCodesByNames
            // @param avDevType: Whether the device is a video (TV) or audio (AMP) device
            // @param manufacturer: The manufacturer name of the AV device e.g. "Samsung"
            // @param model: A part (minimum of 3 characters) of the model name of the AV device e.g. "UN6"
            // @param success: Whether the request succeeded
            // @param codes: A list of IR codes for the specified device e.g. "R2467"
            // @retval ErrorCode::NONE: IR codes retrieved successfully by names.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve IR codes by names.
            virtual Core::hresult GetIRCodesByNames(AVDevType& avDevType /* @inout */, string& manufacturer /* @inout */, string& model /* @inout */, bool& success /* @out */, IStringIterator*& codes /* @out @optional */) = 0;

            // @brief Programs an IR code into the specified remote control
            // @text setIRCode
            // @param remoteId: The remote ID of the target remote on the specified network ex: 1
            // @param netType: The type of network ex: 1
            // @param avDevType: Whether the device is a video (TV) or audio (AMP) device
            // @param code: The IR code being programmed into the remote e.g. "PANASONIC_3DTV"
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: IR code set successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to set IR code.
            virtual Core::hresult SetIRCode(const uint32_t remoteId, const uint32_t netType, const AVDevType avDevType, const string& code, SuccessResult& result /* @out @extract */) = 0;

            // @brief Clears the IR codes from the specified remote
            // @text clearIRCodes
            // @param remoteId: The remote ID of the target remote on the specified network ex: 1
            // @param netType: The type of network ex: 1
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: IR codes cleared successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to clear IR codes.
            virtual Core::hresult ClearIRCodes(const uint32_t remoteId, const uint32_t netType, SuccessResult& result /* @out @extract */) = 0;

            // @brief Returns last key press source data
            // @text getLastKeypressSource
            // @param response: The last keypress source response
            // @retval ErrorCode::NONE: Last keypress source retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve last keypress source.
            virtual Core::hresult GetLastKeypressSource(GetLastKeypressSourceResponse& response /* @out @extract */) = 0;

            // @brief Configures which keys on the remote will wake the target from deepsleep
            // @text configureWakeupKeys
            // @param wakeupConfig: The deepsleep wakeup key configuration of the remote. Possible values: all (all keys on the remote will wake target from deepsleep), none (no keys will wake target), custom (the custom list of Linux key codes in customKeys will wake target)
            // @param customKeys: List of Linux key codes that can wake the target from deepsleep. Mandatory if wakeupConfig is custom, otherwise should be omitted e.g. "195,199"
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Wakeup keys configured successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to configure wakeup keys.
            virtual Core::hresult ConfigureWakeupKeys(const WakeupConfig wakeupConfig, const string& customKeys /* @optional */, SuccessResult& result /* @out @extract */) = 0;

            // @brief Initializes the IR database
            // @text initializeIRDB
            // @param netType: The type of network ex: 1
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: IRDB initialized successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to initialize IRDB.
            virtual Core::hresult InitializeIRDB(const uint32_t netType, SuccessResult& result /* @out @extract */) = 0;

            // @brief Tells the most recently used remote to beep
            // @text findMyRemote
            // @param level: The level at which the remote will beep
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Find my remote executed successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to execute find my remote.
            virtual Core::hresult FindMyRemote(const FindMyRemoteLevel level, SuccessResult& result /* @out @extract */) = 0;

            // @brief Tells all paired and connected remotes to factory reset
            // @text factoryReset
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Factory reset executed successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to execute factory reset.
            virtual Core::hresult FactoryReset(SuccessResult& result /* @out @extract */) = 0;

            // @brief Unpairs all remotes from the STB
            // @text unpair
            // @param success: Whether the request succeeded
            // @param macAddressList(optional): Optional list of MAC addresses to unpair (if empty, unpairs all remotes)
            // @retval ErrorCode::NONE: Unpair executed successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to execute unpair.
            virtual Core::hresult Unpair(SuccessResult& result /* @out @extract */, IStringIterator* const macAddressList /* @unwrapped */) = 0;

            // @brief Starts a firmware image update session for the specified remote(s)
            // @text startFirmwareUpdate
            // @param macAddress: The MAC address of the target remote in hex-colon format e.g. "AA:BB:CC:DD:EE:FF"
            // @param fileName: The full path and filename for the firmware image e.g. "/tmp/remote_firmware.bin"
            // @param fileType: The type of firmware image file e.g. "mfg"
            // @param percentIncrement: The increment change of a firmware update to notify. Valid range 1-100 percent ex: 10
            // @param success: Whether the request succeeded
            // @param sessionIdList: List of session IDs created for the firmware update(s)
            // @retval ErrorCode::NONE: Firmware update started successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to start firmware update.
            virtual Core::hresult StartFirmwareUpdate(const string& macAddress, const string& fileName, const string& fileType, const uint32_t percentIncrement, bool& success /* @out */, IStringIterator*& sessionIdList /* @out */) = 0;

            // @brief Cancels an active firmware image update session
            // @text cancelFirmwareUpdate
            // @param sessionId: The session identifier e.g. "12345-abc-def"
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Firmware update cancelled successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to cancel firmware update.
            virtual Core::hresult CancelFirmwareUpdate(const string& sessionId, SuccessResult& result /* @out @extract */) = 0;

            // @brief Returns the status of an active firmware image update session
            // @text statusFirmwareUpdate
            // @param sessionId: The session identifier e.g. "12345-abc-def"
            // @param response: The firmware update status fields including sessionId, macAddress, state, percentComplete, optional error, and success
            // @retval ErrorCode::NONE: Firmware update status retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve firmware update status.
            virtual Core::hresult StatusFirmwareUpdate(const string& sessionId, StatusFirmwareUpdateResponse& response /* @out @extract */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_REMOTECONTROL_NOTIFICATION };

                // @brief Triggered at any time when the status of any one of the supported STB remote networks changes
                // @text onStatus
                // @param status: Network status information including network type, pairing state, and IR programming state
                virtual void OnStatus(const StatusEventData& status) {}

                // @brief Generated for manual pairing validation
                // @text onValidation
                // @param status: Validation information including network type and validation digits for manual pairing
                virtual void OnValidation(const ValidationStatusObject& status) {}

                // @brief Generated at 0 and 100 percent and each time a download percent increment is reached
                // @text onFirmwareUpdateProgress
                // @param progress: Firmware update progress information including session ID and current status
                virtual void OnFirmwareUpdateProgress(const FirmwareUpdateProgressEvent& progress) {}
            };

            // @json:omit
            // @text register
            // @brief Register notification interface
            // @param notification: Notification interface pointer
            // @retval Core::ERROR_NONE: Indicates successful registration of notification interface
            // @retval Core::ERROR_BAD_REQUEST: notification is null
            virtual Core::hresult Register(IRemoteControl::INotification* notification) = 0;

            // @json:omit
            // @text unregister
            // @brief Unregister notification interface
            // @param notification: Notification interface pointer
            // @retval Core::ERROR_NONE: Indicates successful unregistration of notification interface
            // @retval Core::ERROR_BAD_REQUEST: notification is null
            virtual Core::hresult Unregister(const IRemoteControl::INotification* notification) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
