#pragma once
#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IAppPackagesStatus : virtual public Core::IUnknown {
        enum { ID = ID_APP_PACKAGES_STATUS };

        ~IAppPackagesStatus() override = default;

        // @brief Returns the ids of the currently running (locked) applications that use
        // the given package - they are the package or depend on it, directly or
        // transitively. Only top-level applications are returned; restarting an
        // application refreshes its whole dependency chain.
        // @text getRunningApplicationsUsingPackage
        // @param packageId: Package Id that was installed or removed
        // @param applicationIds: JSON array of strings with the ids of the running
        // applications using the package (e.g. "[\"app1\",\"app2\"]")
        virtual Core::hresult GetRunningApplicationsUsingPackage(const string &packageId,
                                                                 string& applicationIds /* @out */) = 0;
    };
} // Exchange
} // WPEFramework
