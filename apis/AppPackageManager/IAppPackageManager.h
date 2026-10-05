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
        std::string envVariables;
        uint32_t userId;
        uint32_t groupId;
        uint32_t dataImageSize;

        bool resourceManagerClientEnabled;
        std::string dialId;
        std::string command;
        std::string appType;
        std::string appPath;
        std::string runtimePath;

        std::string logFilePath;
        uint32_t logFileMaxSize;
        std::string logLevels;          //json array of strings
        bool mapi;
        std::string fkpsFiles;          //json array of strings
        std::string capabilities /* @text capabilities */ /* @brief Comma-separated lowercase runtime capability tokens supported by the application runtime */;
        std::string ralfPkgPath /* @text ralfPkgPath */ /* @brief Filesystem path containing metadata information for RALF packages */;

        std::string fireboltVersion;
        bool enableDebugger;
        std::string unpackedPath;
    };
    #define RUNTIME_CONFIG
#endif

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

            // @brief Reports status changes for application package downloads.
            // @details Emitted when the status of one or more downloads changes.
            // @param packageInfo: Iterator containing download identifiers, file locators, and status reasons.
            // @example packageInfo: [{"downloadId":"download-123","fileLocator":"/tmp/app.pkg","reason":"NONE"}]
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
            bool priority;
            uint32_t retries;
            uint64_t rateLimit;
        };

        struct DownloadId {
            string downloadId;
        };

        // @brief Starts downloading a resource file.
        // @details The returned download identifier can be used to monitor or control the asynchronous download.
        // @param url: URL of the resource to download.
        // @param options: Download priority, retry count, and rate limit settings.
        // @param downloadId: Receives the identifier assigned to the download.
        // @example url: "https://example.com/resources/app-data.tar"
        // @example options: {"priority":true,"retries":3,"rateLimit":1048576}
        // @example downloadId: "download-123"
        // @retval Core::ERROR_NONE: The download request was accepted.
        // @retval Core::ERROR_GENERAL: The download request could not be started.
        // @text download
        virtual Core::hresult Download(
            const string &url,
            const Options &options,
            DownloadId &downloadId /* @out */) = 0;

        // @brief Pauses an active download.
        // @details The download can be continued later with Resume using the same identifier.
        // @param downloadId: Identifier of the download to pause.
        // @example downloadId: "download-123"
        // @retval Core::ERROR_NONE: The download was paused.
        // @retval Core::ERROR_GENERAL: The download could not be paused.
        // @text pause
        virtual Core::hresult Pause(const string &downloadId) = 0;

        // @brief Resumes a paused download.
        // @details The download continues using the state associated with its identifier.
        // @param downloadId: Identifier of the download to resume.
        // @example downloadId: "download-123"
        // @retval Core::ERROR_NONE: The download was resumed.
        // @retval Core::ERROR_GENERAL: The download could not be resumed.
        // @text resume
        virtual Core::hresult Resume(const string &downloadId) = 0;

        // @brief Cancels an active or paused download.
        // @details Cancellation stops the operation associated with the supplied download identifier.
        // @param downloadId: Identifier of the download to cancel.
        // @example downloadId: "download-123"
        // @retval Core::ERROR_NONE: The download was cancelled.
        // @retval Core::ERROR_GENERAL: The download could not be cancelled.
        // @text cancel
        virtual Core::hresult Cancel(const string &downloadId) = 0;

        // @brief Deletes a downloaded package or resource file.
        // @details The file is selected by its file locator.
        // @param fileLocator: Locator of the file to delete.
        // @example fileLocator: "/tmp/downloads/app.pkg"
        // @retval Core::ERROR_NONE: The file was deleted.
        // @retval Core::ERROR_GENERAL: The file could not be deleted.
        // @text delete
        virtual Core::hresult Delete(const string &fileLocator) = 0;

        struct ProgressInfo {
            uint8_t progress;
        };

        // @brief Retrieves the progress of a download.
        // @details Progress is reported as an integer percentage for the identified download.
        // @param downloadId: Identifier of the download to query.
        // @param progress: Receives the current download progress percentage.
        // @example downloadId: "download-123"
        // @example progress: 42
        // @retval Core::ERROR_NONE: Download progress was returned.
        // @retval Core::ERROR_GENERAL: Progress could not be retrieved.
        // @text progress
        virtual Core::hresult Progress(
            const string &downloadId,
            ProgressInfo &progress /* @out */) = 0;

        // @brief Retrieves application package storage usage and quota.
        // @details Values are reported in kilobytes.
        // @param quotaKb: Receives the available storage quota in kilobytes.
        // @param usedKb: Receives the amount of storage currently used in kilobytes.
        // @example quotaKb: 1048576
        // @example usedKb: 262144
        // @retval Core::ERROR_NONE: Storage information was returned.
        // @retval Core::ERROR_GENERAL: Storage information could not be retrieved.
        // @text getStorageInformation
        virtual Core::hresult GetStorageInformation(
            uint32_t &quotaKb /* @out */,
            uint32_t &usedKb  /* @out */) = 0;

        // @brief Sets the maximum rate for a download.
        // @details The limit applies to the download identified by downloadId.
        // @param downloadId: Identifier of the download to configure.
        // @param limit: Maximum download rate.
        // @example downloadId: "download-123"
        // @example limit: 1048576
        // @retval Core::ERROR_NONE: The download rate limit was updated.
        // @retval Core::ERROR_GENERAL: The rate limit could not be updated.
        // @text rateLimit
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

            // @brief Reports status changes for package installation operations.
            // @details The notification carries the serialized installation status response.
            // @param jsonresponse: JSON string describing the installation status change.
            // @example jsonresponse: "{\"packageId\":\"org.example.app\",\"state\":\"INSTALLED\"}"
            // @text onAppInstallationStatus
            virtual void OnAppInstallationStatus(const string& jsonresponse) {
            }
        };

        ~IPackageInstaller() override = default;

        // Register for any changes
        virtual Core::hresult Register(IPackageInstaller::INotification *sink) = 0;
        virtual Core::hresult Unregister(IPackageInstaller::INotification *sink) = 0;

        struct EXTERNAL KeyValue  {
            // @brief Name of a metadata entry.
            string name;
            // @brief Value associated with the metadata entry name.
            string value;
        };
        using IKeyValueIterator = RPC::IIteratorType<KeyValue, ID_PACKAGE_KEY_VALUE_ITERATOR>;

        // @brief Installs a package.
        // @details Installs the specified package version using the supplied file locator and optional metadata.
        // @param packageId: Identifier of the package to install.
        // @param version: Version of the package to install.
        // @param additionalMetadata: Optional key-value metadata to apply during installation.
        // @param fileLocator: Locator of the package bundle to install.
        // @param failReason: Receives the reason if installation fails.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example additionalMetadata: [{"name":"channel","value":"stable"}]
        // @example fileLocator: "/tmp/packages/app-1.2.3.pkg"
        // @example failReason: "NONE"
        // @retval Core::ERROR_NONE: The installation request was processed; inspect failReason for the installation outcome.
        // @retval Core::ERROR_GENERAL: The installation request could not be processed.
        // @text install
        virtual Core::hresult Install(
            const string &packageId,
            const string &version,
            IPackageInstaller::IKeyValueIterator* const& additionalMetadata,
            const string &fileLocator,
            FailReason &failReason /* @out */) = 0;

        // @brief Uninstalls a package.
        // @details Removes the package identified by packageId and reports an implementation-specific error reason when applicable.
        // @param packageId: Identifier of the package to uninstall.
        // @param errorReason: Receives the reason for an unsuccessful uninstall, if any.
        // @example packageId: "org.example.app"
        // @example errorReason: ""
        // @retval Core::ERROR_NONE: The uninstall operation completed.
        // @retval Core::ERROR_GENERAL: The package could not be uninstalled.
        // @text uninstall
        virtual Core::hresult Uninstall(
            const string &packageId,
            string &errorReason /* @out */
            ) = 0;

        // @brief Lists packages known to the package installer.
        // @details Returns package identifiers, versions, states, digests, sizes, and package types.
        // @param packages: Receives an iterator over the package records.
        // @example packages: [{"packageId":"org.example.app","version":"1.2.3","state":"INSTALLED","digest":"sha256:abc123","sizeKb":2048,"packageType":"application"}]
        // @retval Core::ERROR_NONE: The package list was returned.
        // @retval Core::ERROR_GENERAL: The package list could not be retrieved.
        // @text listPackages
        virtual Core::hresult ListPackages(IPackageIterator*& packages /* @out */) = 0;

        // @brief Retrieves runtime configuration for an installed package version.
        // @details The returned configuration contains runtime and resource settings for the package.
        // @param packageId: Identifier of the package.
        // @param version: Version of the package.
        // @param configMetadata: Receives the package runtime configuration.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example configMetadata: {"dial":true,"appPath":"/opt/apps/example"}
        // @retval Core::ERROR_NONE: Package configuration was returned.
        // @retval Core::ERROR_GENERAL: Package configuration could not be retrieved.
        // @text config
        virtual Core::hresult Config(
            const string &packageId,
            const string &version,
            RuntimeConfig &configMetadata /* @out */
            ) = 0;

        struct PackageStateResponse {
            InstallState state;
        };
        // XXX: update vvv

        // @brief Retrieves the installation state of a package version.
        // @details The returned state is one of the InstallState values.
        // @param packageId: Identifier of the package.
        // @param version: Version of the package.
        // @param state: Receives the current installation state.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example state: "INSTALLED"
        // @retval Core::ERROR_NONE: The package state was returned.
        // @retval Core::ERROR_GENERAL: The package state could not be retrieved.
        // @text packageState
        virtual Core::hresult PackageState(
            const string &packageId,
            const string &version,
            InstallState &state /* @out */
            ) = 0;

        // @brief Retrieves package metadata using its file locator.
        // @details Returns the package identifier, version, and runtime configuration associated with the located package.
        // @param fileLocator: Locator of the package whose configuration is requested.
        // @param id: Receives the package identifier.
        // @param version: Receives the package version.
        // @param config: Receives the package runtime configuration.
        // @example fileLocator: "/tmp/packages/app-1.2.3.pkg"
        // @example id: "org.example.app"
        // @example version: "1.2.3"
        // @example config: {"dial":true,"appPath":"/opt/apps/example"}
        // @retval Core::ERROR_NONE: Package metadata was returned.
        // @retval Core::ERROR_GENERAL: Package metadata could not be retrieved.
        // @text getConfigForPackage
        virtual Core::hresult GetConfigForPackage(const string &fileLocator, string& id /* @out */, string &version /* @out */, RuntimeConfig& config /* @out */) = 0;
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

        // @brief Locks a package while an application is using it.
        // @details The lock reason and package identity are associated with the returned lock identifier and metadata.
        // @param packageId: Identifier of the package to lock.
        // @param version: Version of the package to lock.
        // @param lockReason: Reason the package must remain locked.
        // @param lockId: Receives the identifier for the lock.
        // @param unpackedPath: Receives the package's unpacked filesystem path.
        // @param configMetadata: Receives the runtime configuration for the package.
        // @param appMetadata: Receives additional package metadata entries.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example lockReason: "LAUNCH"
        // @example lockId: 17
        // @example unpackedPath: "/opt/apps/org.example.app"
        // @example configMetadata: {"appPath":"/opt/apps/org.example.app"}
        // @example appMetadata: [{"packageId":"org.example.runtime","version":"2.0.0"}]
        // @retval Core::ERROR_NONE: The package was locked.
        // @retval Core::ERROR_GENERAL: The package could not be locked.
        // @text lock
        virtual Core::hresult Lock(
            const string &packageId,
            const string &version,
            const LockReason &lockReason,
            uint32_t &lockId /* @out */,
            string &unpackedPath /* @out */,
            RuntimeConfig &configMetadata /* @out */,
            IPackageHandler::ILockIterator*& appMetadata /* @out */
            // XXX: appContextPath ?!
            ) = 0;

        // @brief Releases a package lock.
        // @details Unlocks the specified package version so it is no longer protected by this lock.
        // @param packageId: Identifier of the package to unlock.
        // @param version: Version of the package to unlock.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @retval Core::ERROR_NONE: The package was unlocked.
        // @retval Core::ERROR_GENERAL: The package could not be unlocked.
        // @text unlock
        virtual Core::hresult Unlock(
            const string &packageId,
            const string &version) = 0;

        // @brief Retrieves lock and package information.
        // @details Returns the unpacked path, runtime configuration, gateway metadata path, and whether the package is locked.
        // @param packageId: Identifier of the package to query.
        // @param version: Version of the package to query.
        // @param unpackedPath: Receives the package's unpacked filesystem path.
        // @param configMetadata: Receives the package runtime configuration.
        // @param gatewayMetadataPath: Receives the gateway metadata file path.
        // @param locked: Receives whether the package is currently locked.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example unpackedPath: "/opt/apps/org.example.app"
        // @example configMetadata: {"appPath":"/opt/apps/org.example.app"}
        // @example gatewayMetadataPath: "/opt/apps/org.example.app/gateway.json"
        // @example locked: true
        // @retval Core::ERROR_NONE: Package lock information was returned.
        // @retval Core::ERROR_GENERAL: Package lock information could not be retrieved.
        // @text getLockedInfo
        virtual Core::hresult GetLockedInfo(
            const string &packageId,
            const string &version,
            string &unpackedPath /* @out */,
            RuntimeConfig &configMetadata /* @out */,
            string &gatewayMetadataPath /* @out */,
            bool &locked /* @out */
            ) = 0;
    };
    // @json 1.0.0 @text:keep
    struct EXTERNAL IAppPackageManagerConfig : virtual public Core::IUnknown {
        enum { ID = ID_APP_PACKAGE_MANAGER_CONFIG };


        // @brief Returns the metadata of an installed package as a JSON string.
        // @details The package is selected by its identifier and version.
        // @param packageId: Identifier of the installed package.
        // @param version: Version of the installed package.
        // @param config: Receives the package metadata serialized as JSON.
        // @example packageId: "org.example.app"
        // @example version: "1.2.3"
        // @example config: "{\"appPath\":\"/opt/apps/example\"}"
        // @retval Core::ERROR_NONE: Package metadata was returned.
        // @retval Core::ERROR_GENERAL: Package metadata could not be retrieved.
        // @text getConfigForInstalledPackage
        virtual Core::hresult GetConfigForInstalledPackage(const string &packageId, const string &version, string &config /* @out @opaque */) = 0;

        // @brief Returns metadata for installed packages as a JSON string.
        // @details An optional filter limits the returned packages to those matching the requested capability.
        // @param filter: Capability filter applied to installed packages.
        // @param config: Receives the matching package metadata serialized as JSON.
        // @example filter: "video"
        // @example config: "[{\"packageId\":\"org.example.app\",\"version\":\"1.2.3\"}]"
        // @retval Core::ERROR_NONE: Package metadata was returned.
        // @retval Core::ERROR_GENERAL: Package metadata could not be retrieved.
        // @text getConfigListForInstalledPackages
        virtual Core::hresult GetConfigListForInstalledPackages(const string &filter, string &config /* @out @opaque */) = 0;
    };

    struct EXTERNAL IPackageCacheInitializer : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGE_CACHE_INITIALIZER };

        ~IPackageCacheInitializer() override = default;

        // @brief Starts package cache initialization.
        // @details Requests initialization of the package cache; completion may occur asynchronously.
        // @example result: "Cache initialization started"
        // @text startCacheInitialization
        // @retval Core::ERROR_NONE: Cache initialization start requested successfully
        // @retval Core::ERROR_GENERAL: Failed to start cache initialization
        virtual Core::hresult StartCacheInitialization() = 0;
    };
} // Exchange
} // WPEFramework
