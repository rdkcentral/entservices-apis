#pragma once
#include "Module.h"
#include <utility>

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {
#ifndef RUNTIME_CONFIG
    struct RuntimeConfig {
        bool dial;
        bool wanLanAccess;
        bool thunder;
        int32_t systemMemoryLimit;
        int32_t gpuMemoryLimit;
        std::string envVars;
        uint32_t userId;
        uint32_t groupId;
        uint32_t dataImageSize;

        bool resourceManagerClientEnabled;
        std::string dialId;
        std::string command;
        uint32_t appType;
        std::string appPath;
        std::string runtimePath;

        std::string logFilePath;
        uint32_t logFileMaxSize;
        std::string logLevels;          //json array of strings
        bool mapi;
        std::string fkpsFiles;          //json array of strings

        std::string fireboltVersion;
        bool enableDebugger;
    };
    #define RUNTIME_CONFIG
#endif

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

        // @json:omit
        virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

        // @json:omit
        virtual Core::hresult  Deinitialize(PluginHost::IShell* service) = 0;


        struct Options {
            bool priority;
            uint32_t retries;
            uint64_t rateLimit;
        };

	    // @brief Download
        // @text download
        // @param url: Download url
        // @param options: Download options
        virtual Core::hresult Download(
            const string &url,
            const Options &options,
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

        struct Percent {
            uint8_t percent;
        };
        // {"jsonrpc":"2.0","id":1007,"result":{"percent":77}}

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


    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageInstaller : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_INSTALLER };

        enum PackageLifecycleState : uint8_t {
            INSTALLING,
            INSTALLATION_BLOCKED,
            INSTALLED,
            UNINSTALLING,
            UNINSTALLED
        };

        enum FailReason : uint8_t {
            NONE,
            SIGNATURE_VERIFICATION_FAILURE,
            PACKAGE_MISMATCH_FAILURE,
            INVALID_METADATA_FAILURE,
            PERSISTENCE_FAILURE
    };
        struct Package {
            // @brief PackageId
            string packageId;
            // @brief Version
            string version;
            // @brief PackageState
            PackageLifecycleState packageState;
            // @brief Digest
            string digest;
            // @brief SizeKb
            uint64_t sizeKb;
        };
        using IPackageIterator = RPC::IIteratorType<Package, ID_PACKAGE_ITERATOR>;

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGE_INSTALLER_NOTIFICATION  };
            ~INotification() override = default;

            // @brief Signal changes on the status
            // @text onAppInstallationStatus
            virtual void OnAppInstallationStatus(const string& jsonresponse) {
            }
        };

        ~IPackageInstaller() override = default;

        // Register for any changes
        virtual Core::hresult Register(IPackageInstaller::INotification *sink) = 0;
        virtual Core::hresult Unregister(IPackageInstaller::INotification *sink) = 0;

        struct EXTERNAL KeyValue  {
            // @brief Name
            string name;
            // @brief Value
            string value;
        };
        using IKeyValueIterator = RPC::IIteratorType<KeyValue, ID_PACKAGE_KEY_VALUE_ITERATOR>;

        // @brief Install
        // @text install
        // @param packageId: Package Id
        // @param version: Version
        // @param additionalMetadata: Additional Metadata
        // @param fileLocator: File Locator
        virtual Core::hresult Install(
            const string &packageId,
            const string &version,
            IPackageInstaller::IKeyValueIterator* const& additionalMetadata,
            const string &fileLocator,
            FailReason &reason /* @out */) = 0;

        // @brief Uninstall
        // @text uninstall
        // @param packageId: Package Id
        virtual Core::hresult Uninstall(
            const string &packageId,
            string &errorReason /* @out */
            ) = 0;

        // @brief ListPackages
        // @text listPackages
        virtual Core::hresult ListPackages(IPackageIterator*& packages /* @out */) = 0;

        // @brief Config
        // @text config
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult Config(
            const string &packageId,
            const string &version,
            RuntimeConfig &configMetadata /* @out */
            ) = 0;

        // @brief PackageState
        // @text packageState
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult PackageState(
            const string &packageId,
            const string &version,
            PackageLifecycleState &state /* @out */
            ) = 0;
   };


    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageHandler : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_HANDLER };

        ~IPackageHandler() override = default;

        enum LockReason : uint8_t {
            SYSTEM_APP,
            LAUNCH
        };

        // @brief Lock
        // @text lock
        // @param packageId: Package Id
        // @param version: Version
        // @param lockReason: LockReason
        // @param lockId: Lock Id
        // @param unpackedPath: Unpacked Path
        // @param configMetadata: Config Metadata
        // @param appMetadata: App Metadata
        virtual Core::hresult Lock(
            const string &packageId,
            const string &version,
            const LockReason &lockReason,
            uint32_t &lockId /* @out */,
            string &unpackedPath /* @out */,
            RuntimeConfig &configMetadata /* @out */,
            string &appMetadata /* @out */
            // XXX: appContextPath ?!
            ) = 0;

        // @brief Unlock
        // @text unlock
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult Unlock(
            const string &packageId,
            const string &version) = 0;

        // @brief GetLockedInfo
        // @text getLockedInfo
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult GetLockedInfo(
            const string &packageId,
            const string &version,
            string &unpackedPath /* @out */,
            RuntimeConfig &configMetadata /* @out */,
            string &gatewayMetadataPath /* @out */,
            bool &locked /* @out */
            ) = 0;
    };

} // Exchange
} // WPEFramework
