/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IFirmwareDownload : virtual public Core::IUnknown
        {
            enum { ID = ID_FIRMWARE_DOWNLOAD };

            struct EXTERNAL FirmwareDownloadPercent {
                /* @brief Current download percentage (0-100) */
                uint32_t downloadPercent;
            };

            struct EXTERNAL FirmwareDownloadState {
                /* @brief current state of the download process */
                string downloadState;
            };

            struct EXTERNAL DownloadFailureReason {
                /* @brief firmware download failure reason */
                string failureReason;
            };
            
            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_FIRMWARE_DOWNLOAD_NOTIFICATION };

                // @text onFirmwareAvailable
                // @brief Triggered when the SearchFirmware asynchronous method is invoked
                // @details This event is triggered when the SearchFirmware asynchronous method is invoked. It provides information about the firmware search operation, including the status, server response, availability of new firmware, version string of the available firmware, and whether an immediate reboot is required.
                // @param searchStatus: Status of the firmware search operation
                // @example searchStatus: 0
                // @param serverResponse: Response message from the server
                // @example serverResponse: "Firmware search completed successfully."
                // @param firmwareAvailable: Indicates whether new firmware is available
                // @example firmwareAvailable: true
                // @param firmwareVersion: Version string of the available firmware
                // @example firmwareVersion: "1.0.0"
                // @param rebootImmediately: Indicates whether immediate reboot is required
                // @example rebootImmediately: false
                virtual void OnFirmwareAvailable (const int searchStatus, const string& serverResponse, const bool firmwareAvailable, const string& firmwareVersion, const bool rebootImmediately) {};  
            };

            virtual Core::hresult Register(IFirmwareDownload::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFirmwareDownload::INotification* notification) = 0;

            // @text getDownloadedFirmwareInfo
            // @brief Returns information about firmware downloads.
            // @details Retrieves information about firmware downloads, including the current firmware version, downloaded firmware version, location of the downloaded firmware, and whether a reboot is deferred.
            // @param currentFWVersion: The current firmware version
            // @example currentFWVersion: "1.0.0"
            // @param downloadedFWVersion: The downloaded firmware version
            // @example downloadedFWVersion: "1.1.0"
            // @param downloadedFWLocation: The location of the downloaded firmware
            // @example downloadedFWLocation: "/path/to/downloaded/firmware"
            // @param isRebootDeferred: Whether the device should be rebooted
            // @example isRebootDeferred: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetDownloadedFirmwareInfo(string& currentFWVersion /* @out */, string& downloadedFWVersion /* @out */, string& downloadedFWLocation /* @out */, bool& isRebootDeferred /* @out */) = 0;

            // @text getFirmwareDownloadPercent
            // @brief Gets the current download percentage.
            // @details Retrieves the current download percentage of the firmware download process.
            // @param firmwareDownloadPercent: Current download percentage
            // @example firmwareDownloadPercent: { downloadPercent: 75 }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetFirmwareDownloadPercent( FirmwareDownloadPercent& firmwareDownloadPercent /* @out */) = 0;

            // @text searchFirmware
            // @brief Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to.
            // @details Initiates a search for any available firmware in the remote server (e.g., xconf) that the device can update to. This method triggers an asynchronous operation, and the result will be provided through the OnFirmwareAvailable event.
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SearchFirmware() = 0;
            
            // @text getDownloadState
            // @brief Retrieve the current state of the download process.
            // @details Retrieves the current state of the firmware download process, providing information about whether the download is in progress, completed, or encountered an error.
            // @param downloadState: Current firmware download state
            // @example downloadState: { downloadState: "InProgress" }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetDownloadState( FirmwareDownloadState& downloadState /* @out */) = 0;
            
            // @text getDownloadFailureReason
            // @brief Gets the last firmware download failure reason.
            // @details Retrieves the last firmware download failure reason, providing information about the cause of the failure during the firmware download process.
            // @param downloadFailureReason: Firmware download failure reason
            // @example downloadFailureReason: { failureReason: "NetworkError" }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetDownloadFailureReason( DownloadFailureReason& downloadFailureReason /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
