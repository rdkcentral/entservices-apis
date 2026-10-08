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
        // applications using the package (e.g. ["app1","app2"]). The string carries a
        // JSON document (@opaque): over COM the caller receives the plain payload;
        // over JSON-RPC it is transported as a string result containing that JSON
        // (e.g. "[\"app1\",\"app2\"]") - clients parse the envelope first, then
        // parse the string as JSON.
        // @retval Core::ERROR_NONE: Success; applicationIds carries the JSON array
        //        ("[]" when no running application uses the package)
        // @retval Core::ERROR_UNAVAILABLE: Package cache not initialized yet (plugin
        //        still starting up); retry later
        // @retval Core::ERROR_GENERAL: Backend failure (libpackage not initialized or
        //        the mount-graph query failed) or payload serialization failure
        virtual Core::hresult GetRunningApplicationsUsingPackage(const string &packageId,
                                                                 string& applicationIds /* @out @opaque */) = 0;
    };
} // Exchange
} // WPEFramework
