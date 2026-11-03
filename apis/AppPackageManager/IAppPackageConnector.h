#pragma once
#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IAppPackageConnector : virtual public Core::IUnknown {
        enum { ID = ID_APP_PACKAGES_CONNECTOR };

        ~IAppPackageConnector() override = default;

        struct EXTERNAL PackageSpecifierRuntime {
            string packageSpecifier /* @brief Package specifier associated with the runtime package */;
            string packageId /* @brief ID of the installed package associated with the package specifier */;
        };

        using IPackageSpecifierRuntimeIterator =
            RPC::IIteratorType<PackageSpecifierRuntime, ID_PACKAGE_SPECIFIER_RUNTIME_ITERATOR>;

        // @brief Returns package specifiers and their package IDs.
        // @text getPackageSpecifierRuntimes
        // @param runtimes Iterator containing {PackageSpecifier, packageId} string pairs
        // @retval ERROR_DISABLED when feature is disabled (in thunder plugin config)
        // @retval ERROR_NONE when the operation is successful.
        virtual Core::hresult GetPackageSpecifierRuntimes(
            IPackageSpecifierRuntimeIterator*& runtimes /* @out */) = 0;

        // @brief Associates a package specifier with an installed package ID.
        // @text setPackageSpecifier
        // @param packageSpecifier Package specifier to associate
        // @param packageId ID of the installed package
        // @retval ERROR_NONE: Association updated successfully
        // @retval ERROR_DISABLED: Feature is disabled in the Thunder plugin configuration
        // @retval ERROR_PACKAGEID_NOT_INSTALLED: The requested package ID is not installed
        virtual Core::hresult SetPackageSpecifier(
            const string& packageSpecifier, const string& packageId) = 0;
    };
} // Exchange
} // WPEFramework