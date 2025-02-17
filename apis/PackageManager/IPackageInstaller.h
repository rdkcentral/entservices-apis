#pragma once

#include <vector>
#include <utility>
#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {
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
            string packageId;
            string version;
            PackageLifecycleState packageState;
            string digest;
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
            string key;
            string value;
        };
        using IKeyValueIterator = RPC::IIteratorType<KeyValue, ID_PACKAGE_KEY_VALUE_ITERATOR>;

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

        // @text uninstall
        // @param packageId: Package Id
        virtual Core::hresult Uninstall(
            const string &packageId,
            string &errorReason /* @out */
            ) = 0;

        // @text listPackages
        virtual Core::hresult ListPackages(IPackageIterator*& packages /* @out */) = 0;

        // @text config
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult Config(
            const string &packageId,
            const string &version,
            string &config /* @out */   // XXX: JsonObject ?!
            ) = 0;

        // @text packageState
        // @param packageId: Package Id
        // @param version: Version
        virtual Core::hresult PackageState(
            const string &packageId,
            const string &version,
            PackageLifecycleState &state /* @out */
            ) = 0;

   };

} // Exchange
} // WPEFramework
