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

namespace WPEFramework {
namespace Exchange {
    // @json 1.0.0 @text:keep
    struct EXTERNAL IDownloadManager : virtual public Core::IUnknown {
        enum { ID = ID_DOWNLOAD_MANAGER };

        enum FailReason : uint8_t {
            NONE,                    // XXX: Not in HLA
            DOWNLOAD_FAILURE,
            DISK_PERSISTENCE_FAILURE
        };

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_DOWNLOAD_MANAGER_NOTIFICATION };
            ~INotification() override = default;

            // @brief OnAppDownloadStatus Callback for status changes of app downloads
            // @text onAppDownloadStatus
            // @param downloadStatus : [JSON string] Download status of a queued download request, includes downloadId, fileLocator, failReason (enum)
            virtual void OnAppDownloadStatus(const string& downloadStatus) {}
        };

        ~IDownloadManager() override = default;

        // Register for any changes
        virtual Core::hresult Register(IDownloadManager::INotification* sink) = 0;
        virtual Core::hresult Unregister(IDownloadManager::INotification* sink) = 0;

        // @json:omit
        virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

        // @json:omit
        virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

        struct Options {
            // @brief Adds the download request to either a priority queue (true) or regular queue (false)
            bool priority;

            // @brief Retries Number of retry attempts allowed for failed downloads (the default retries is 2)
            uint32_t retries;

            // @brief RateLimit Maximum bandwidth allowed for the download (bytes per second)
            uint64_t rateLimit;
        };

        struct DownloadId {
            // @brief DownloadId Unique identifier for a download session
            string downloadId;
        };

        // @brief Download Start downloading a file from a specified URL with custom options
        // @text download
        // @param url: URL from which the file is to be downloaded
        // @param options: Options controlling download behavior
        // @param downloadId: Output parameter that returns the assigned download ID
        virtual Core::hresult Download(
            const string& url,
            const Options& options,
            DownloadId& downloadId /* @out */) = 0;

        // @brief Pause an active download session
        // @text pause
        // @param downloadId: Unique identifier of the download to pause
        virtual Core::hresult Pause(const string& downloadId) = 0;

        // @brief Resume a paused download session
        // @text resume
        // @param downloadId: Unique identifier of the download to resume
        virtual Core::hresult Resume(const string& downloadId) = 0;

        // @brief Cancel an ongoing download session
        // @text cancel
        // @param downloadId: Unique identifier of the download to cancel
        virtual Core::hresult Cancel(const string& downloadId) = 0;

        // @brief Delete a downloaded file from the system using its locator path
        // @text delete
        // @param fileLocator: File path or locator of the file to be deleted
        virtual Core::hresult Delete(const string& fileLocator) = 0;

        struct Percent {
            uint8_t percent;
        };

        // @brief Progress Query current download progress
        // @text progress
        // @param downloadId: Unique identifier of the download
        // @param percent: Output parameter returning percentage completed
        virtual Core::hresult Progress(
            const string& downloadId,
            Percent& percent /* @out */) = 0;

        // @brief GetStorageDetails Get information about storage space availability
        // @text getStorageDetails
        // @param quotaKb: Output parameter for total available quota in KB
        // @param usedKb: Output parameter for currently used storage in KB
        virtual Core::hresult GetStorageDetails(
            uint32_t& quotaKb /* @out */,
            uint32_t& usedKb /* @out */) = 0;

        // @brief RateLimit Set rate limiting for a specific download session
        // @text rateLimit
        // @param downloadId: Unique identifier of the download
        // @param limit: Maximum bandwidth in bytes per second (0 = unlimited)
        virtual Core::hresult RateLimit(const string& downloadId, const uint64_t& limit) = 0;
    };
} // Exchange
} // WPEFramework
