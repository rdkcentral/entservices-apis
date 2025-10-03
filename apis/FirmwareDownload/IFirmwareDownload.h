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
                int downloadPercent;
            };

            struct EXTERNAL FirmwareDownloadState {
                string downloadState;
            };

            struct EXTERNAL DownloadFailureReason {
                string failureReason;
            };
            
            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_FIRMWARE_DOWNLOAD_NOTIFICATION };

                // @brief Triggered when the SearchFirmware asynchronous method is invoked
                // @param searchStatus - in - integer
                // @param serverResponse - in - string
                // @param firmwareAvailable - in - boolean
                // @param firmwareVersion - in - string
                // @param rebootImmediately - in - boolean
                // @text onFirmwareAvailable
                virtual void OnFirmwareAvailable (const int searchStatus, const string& serverResponse, const bool firmwareAvailable, const string& firmwareVersion, const bool rebootImmediately) {};  
            };

            virtual Core::hresult Register(IFirmwareDownload::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFirmwareDownload::INotification* notification) = 0;

            // @text getDownloadedFirmwareInfo
            // @brief Returns information about firmware downloads.
            // @param currentFWVersion - out - string
            // @param downloadedFWVersion - out - string
            // @param downloadedFWLocation - out - string
            // @param isRebootDeferred -out - boolean
            virtual Core::hresult GetDownloadedFirmwareInfo(string& currentFWVersion /* @out */, string& downloadedFWVersion /* @out */, string& downloadedFWLocation /* @out */, bool& isRebootDeferred /* @out */) = 0;

            // @text getFirmwareDownloadPercent
            // @brief Gets the current download percentage.
            // @param firmwareDownloadPercent -out - struct
            virtual Core::hresult GetFirmwareDownloadPercent( FirmwareDownloadPercent& firmwareDownloadPercent /* @out */) = 0;

            // @text searchFirmware
            // @brief Search for any available firmware ( in the remote server - for ex., xconf) that the device can update to.
            virtual Core::hresult SearchFirmware() = 0;
            
            // @text getDownloadState
            // @brief Retrieve the current state of the download process.
            // @param FirmwareDownloadState -out - struct
            virtual Core::hresult GetDownloadState( FirmwareDownloadState& downloadState /* @out */) = 0;
            
            // @text getDownloadFailureReason
            // @brief Gets the last firmware download failure reason.
            // @param DownloadFailureReason -out - struct
            virtual Core::hresult GetDownloadFailureReason( DownloadFailureReason& downloadFailureReason /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
