#pragma once
#include "Module.h"
#include <vector>

namespace WPEFramework {
namespace Exchange {
    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageDownloader : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_DOWNLOADER };

        enum Reason : uint8_t {
            NONE,                    // XXX: Not in HLA
            DOWNLOAD_FAILURE,
            DISK_PERSISTENCE_FAILURE
        };

        //struct PackageInfo {
        //    string downloadId;
        //    string fileLocator;
        //    Reason reason;
        //};

        //typedef std::vector<PackageInfo> PackageInfoList;
        //using IPackageIterator = RPC::IIteratorType<PackageInfo, ID_PACKAGE_INFO_ITERATOR>;

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGE_DOWNLOADER_NOTIFICATION  };
            ~INotification() override = default;

            // @brief Signal changes on the status
            // @text onAppDownloadStatus
            virtual void OnAppDownloadStatus(const string& jsonresponse) {
                // Thunder does not support neither standard collection nor RPC::IIteratorType in notification
            }

        };

        ~IPackageDownloader() override = default;

        // Register for any changes
        virtual Core::hresult Register(IPackageDownloader::INotification *sink) = 0;
        virtual Core::hresult Unregister(IPackageDownloader::INotification *sink) = 0;

	    // @brief Download
        // @text download
        // @param url: Download url
        virtual Core::hresult Download(
            const string &url,
            const bool priority /* @optional */,
            const uint32_t retries /* @optional */,
            const uint64_t rateLimit /* @optional */,
            string &downloadId /* @out */) = 0;

        // @brief Pause
        // @text pause
        // @param downloadId: Download id
        virtual Core::hresult Pause(const string &downloadId) = 0;

        // @brief Resume
        // @text resume
        // @param downloadId: Download id
        virtual Core::hresult Resume(const string &downloadId) = 0;

        // @brief Cancel
        // @text cancel
        // @param downloadId: Download id
        virtual Core::hresult Cancel(const string &downloadId) = 0;

        // @brief Delete
        // @text delete
        // @param fileLocator: FileLocator
        virtual Core::hresult Delete(const string &fileLocator) = 0;

        // @brief Delete
        // @text progress
        // @param downloadId: Download id
        virtual Core::hresult Progress(
            const string &downloadId,
            uint8_t &percent /* @out */) = 0;

        // @brief GetStorageDetails
        // @text getStorageDetails
        virtual Core::hresult GetStorageDetails(
            uint32_t &quotaKB /* @out */,
            uint32_t &usedKB  /* @out */) = 0;

        // @brief RateLimit
        // @text rateLimit
        // @param downloadId: Download id
        virtual Core::hresult RateLimit(const string &downloadId, uint64_t &limit /* @out */) = 0;
    };

} // Exchange
} // WPEFramework
