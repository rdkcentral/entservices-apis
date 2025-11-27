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
                int downloadPercent;
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

                // @brief Triggered when the SearchFirmware asynchronous method is invoked
                // @param searchStatus: Status of the firmware search operation
                // @param serverResponse: Response message from the server
                // @param firmwareAvailable: Indicates whether new firmware is available
                // @param firmwareVersion: Version string of the available firmware
                // @param rebootImmediately: Indicates whether immediate reboot is required
                // @text onFirmwareAvailable
                virtual void OnFirmwareAvailable (const int searchStatus, const string& serverResponse, const bool firmwareAvailable, const string& firmwareVersion, const bool rebootImmediately) {};  
            };

            virtual Core::hresult Register(IFirmwareDownload::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFirmwareDownload::INotification* notification) = 0;

            // @text getDownloadedFirmwareInfo
            // @brief Returns information about firmware downloads.
            // @param currentFWVersion: The current firmware version
            // @param downloadedFWVersion: The downloaded firmware version
            // @param downloadedFWLocation: The location of the downloaded firmware
            // @param isRebootDeferred: Whether the device should be rebooted
            virtual Core::hresult GetDownloadedFirmwareInfo(string& currentFWVersion /* @out */, string& downloadedFWVersion /* @out */, string& downloadedFWLocation /* @out */, bool& isRebootDeferred /* @out */) = 0;

            // @text getFirmwareDownloadPercent
            // @brief Gets the current download percentage.
            // @param firmwareDownloadPercent: Current download percentage
            virtual Core::hresult GetFirmwareDownloadPercent( FirmwareDownloadPercent& firmwareDownloadPercent /* @out */) = 0;

            // @text searchFirmware
            // @brief Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to.
            virtual Core::hresult SearchFirmware() = 0;
            
            // @text getDownloadState
            // @brief Retrieve the current state of the download process.
            // @param FirmwareDownloadState: current firmware download state
            virtual Core::hresult GetDownloadState( FirmwareDownloadState& downloadState /* @out */) = 0;
            
            // @text getDownloadFailureReason
            // @brief Gets the last firmware download failure reason.
            // @param DownloadFailureReason: firmware download failure reason
            virtual Core::hresult GetDownloadFailureReason( DownloadFailureReason& downloadFailureReason /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
