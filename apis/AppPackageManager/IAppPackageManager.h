#pragma once
#include "Module.h"
#include <utility>

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageDownloader : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_DOWNLOADER };

        enum class Reason : uint8_t {
            NONE,                    // XXX: Not in HLA
            DOWNLOAD_FAILURE,
            DISK_PERSISTENCE_FAILURE
        };

        struct PackageInfo {
           string downloadId;   /*@brief Download ID*/
           string fileLocator;  /*@brief File Locator*/
           Reason reason;       /*@brief Reason for the download status*/
        };

        //typedef std::vector<PackageInfo> PackageInfoList;
        using IPackageInfoIterator = RPC::IIteratorType<PackageInfo, ID_PACKAGE_INFO_ITERATOR>;

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGE_DOWNLOADER_NOTIFICATION  };
            ~INotification() override = default;

            // @brief Signal changes on the status
            // @text onAppDownloadStatus
            virtual void OnAppDownloadStatus(IPackageInfoIterator* const packageInfo) {
            }
        };

        ~IPackageDownloader() override = default;

        // Register for any changes
        // @json:omit
        virtual Core::hresult Register(IPackageDownloader::INotification *sink) = 0;
        // @json:omit
        virtual Core::hresult Unregister(IPackageDownloader::INotification *sink) = 0;

        // @json:omit
        virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

        // @json:omit
        virtual Core::hresult  Deinitialize(PluginHost::IShell* service) = 0;


        struct Options {
            // @brief Priority
            bool priority;
            // @brief Retries
            uint32_t retries;
            // @brief RateLimit
            uint64_t rateLimit;
        };

        struct DownloadId {
            string downloadId;
        };

	    // @brief Download
        // @text download
        // @param url: Download url
        // @param options: Download options
        virtual Core::hresult Download(
            const string &url,
            const Options &options,
            DownloadId &downloadId /* @out */) = 0;

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

        struct ProgressInfo {
            uint8_t progress;
        };

        // @brief Progress
        // @text progress
        // @param downloadId: Download id
        virtual Core::hresult Progress(
            const string &downloadId,
            ProgressInfo &progress /* @out */) = 0;

        // @brief GetStorageInformation
        // @text getStorageInformation
        // @param quotaKb: Storage quota in kilobytes
        // @param usedKb: Used storage in kilobytes
        virtual Core::hresult GetStorageInformation(
            uint32_t &quotaKb /* @out */,
            uint32_t &usedKb  /* @out */) = 0;

        // @brief RateLimit
        // @text rateLimit
        // @param downloadId: Download id
        // @param limit: Limit
        virtual Core::hresult RateLimit(const string &downloadId, const uint64_t &limit) = 0;
    };


    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageInstaller : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_INSTALLER };

        enum class InstallState : uint8_t{
            INSTALLING,                 // XXX: necessary ?!
            INSTALLATION_BLOCKED,
            INSTALL_FAILURE,
            INSTALLED,
            UNINSTALLING,               // XXX: necessary ?!
            UNINSTALL_BLOCKED,
            UNINSTALL_FAILURE,
            UNINSTALLED
        };

        enum class FailReason : uint8_t {
            NONE,                       // XXX: Not in HLA
            GENERAL_FAILURE,
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
            // @brief state
            InstallState state;
            // @brief Digest
            string digest;
            // @brief SizeKb
            uint64_t sizeKb;
            // @brief PackageType
            string packageType /* @brief Type of the package as defined by the OCI package spec (e.g. base, runtime, application, service, resource) */;
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
            FailReason &failReason /* @out */) = 0;

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

        // @brief Return the package runtime configuration as an opaque serialized JSON string
        // @text config
        // @param packageId: Package Id
        // @param version: Version
        // @param configMetadata: Opaque runtime configuration transported as a serialized string over COM-RPC and emitted as a JSON object over JSON-RPC; array-valued properties are represented as JSON arrays
        // @retval Core::ERROR_NONE: Runtime configuration returned successfully
        // @retval Core::ERROR_UNAVAILABLE: Package cache is not initialized
        // @retval Core::ERROR_INVALID_PARAMETER: Package or version was not found
        // @retval Core::ERROR_GENERAL: Package is not installed or its runtime configuration is unavailable
        virtual Core::hresult Config(
            const string &packageId,
            const string &version,
            string &configMetadata /* @out @opaque */
            ) = 0;

        struct PackageStateResponse {
            InstallState state;
        };
        // XXX: update vvv

        // @brief PackageState
        // @text packageState
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult PackageState(
            const string &packageId,
            const string &version,
            InstallState &state /* @out */
            ) = 0;

        // @brief Return package metadata and its opaque serialized JSON runtime configuration
        // @text getConfigForPackage
        // @param fileLocator: Locator of the package file
        // @param id: Package Id
        // @param version: Version
        // @param config: Opaque runtime configuration transported as a serialized string over COM-RPC and emitted as a JSON object over JSON-RPC; array-valued properties are represented as JSON arrays
        // @retval Core::ERROR_NONE: Package metadata and runtime configuration returned successfully
        // @retval Core::ERROR_UNAVAILABLE: Package cache is not initialized
        // @retval Core::ERROR_INVALID_SIGNATURE: File locator is empty
        // @retval Core::ERROR_GENERAL: Package metadata or runtime configuration could not be retrieved
        virtual Core::hresult GetConfigForPackage(const string &fileLocator, string& id /* @out */, string &version /* @out */, string& config /* @out @opaque */) = 0;
   };


    struct EXTERNAL IPackageHandler : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_HANDLER };

        ~IPackageHandler() override = default;

        enum class LockReason : uint8_t {
            SYSTEM_APP,
            LAUNCH
        };

        struct EXTERNAL AdditionalLock  {
            // @brief PackageId
            string packageId;
            // @brief Version
            string version;
        };
        using ILockIterator = RPC::IIteratorType<AdditionalLock, ID_PACKAGE_LOCK_ITERATOR>;

        // @brief Lock
        // @text lock
        // @param packageId: Package Id
        // @param version: Version
        // @param lockReason: Reason for locking the package
        // @param lockId: Identifier assigned to the package lock
        // @param unpackedPath: Path to the unpacked package
        // @param runtimeConfigPayload: Opaque string containing a serialized JSON runtime configuration object
        // @param appMetadata: Additional packages locked for the application
        // @retval Core::ERROR_NONE: Package locked successfully
        // @retval Core::ERROR_UNAVAILABLE: Package cache is not initialized
        // @retval Core::ERROR_INVALID_PARAMETER: Package or version was not found
        // @retval Core::ERROR_GENERAL: Package locking or runtime configuration processing failed
        virtual Core::hresult Lock(
            const string &packageId,
            const string &version,
            const LockReason &lockReason,
            uint32_t &lockId /* @out */,
            string &unpackedPath /* @out */,
            string &runtimeConfigPayload /* @out @opaque */,
            IPackageHandler::ILockIterator*& appMetadata /* @out */
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
        // @param unpackedPath: Path to the unpacked package
        // @param runtimeConfigPayload: Opaque string containing a serialized JSON runtime configuration object
        // @param gatewayMetadataPath: Path to the application gateway metadata
        // @param locked: Indicates whether the package is locked
        // @retval Core::ERROR_NONE: Package lock information returned successfully
        // @retval Core::ERROR_UNAVAILABLE: Package cache is not initialized
        // @retval Core::ERROR_INVALID_PARAMETER: Package or version was not found
        // @retval Core::ERROR_GENERAL: Runtime configuration could not be processed
        virtual Core::hresult GetLockedInfo(
            const string &packageId,
            const string &version,
            string &unpackedPath /* @out */,
            string &runtimeConfigPayload /* @out @opaque */,
            string &gatewayMetadataPath /* @out */,
            bool &locked /* @out */
            ) = 0;
    };
    // @json 1.0.0 @text:keep
    struct EXTERNAL IAppPackageManagerConfig : virtual public Core::IUnknown {
        enum { ID = ID_APP_PACKAGE_MANAGER_CONFIG };


        // @brief Returns the metadata of installed package in JSON string format
        // @text getConfigForInstalledPackage
        // @param packageId: Package Id
        // @param version: Version
        // @param config: Config of the installed package in JSON string format
        virtual Core::hresult GetConfigForInstalledPackage(const string &packageId, const string &version, string &config /* @out @opaque */) = 0;

        // @brief Returns the metadata of all installed packages in JSON string format.
        // @text getConfigListForInstalledPackages
        // @param filter: capability filter for installed packages
        // @param config: Returns the metadata of all installed packages in JSON string format
        virtual Core::hresult GetConfigListForInstalledPackages(const string &filter, string &config /* @out @opaque */) = 0;
    };

    struct EXTERNAL IPackageCacheInitializer : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_CACHE_INITIALIZER };

        ~IPackageCacheInitializer() override = default;

        // @brief Start cache initialization
        // @text startCacheInitialization
        // @retval Core::ERROR_NONE: Cache initialization start requested successfully
        // @retval Core::ERROR_GENERAL: Failed to start cache initialization
        virtual Core::hresult StartCacheInitialization() = 0;
    };
} // Exchange
} // WPEFramework
