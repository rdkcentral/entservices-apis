/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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
struct EXTERNAL IResourceMonitor : virtual public Core::IUnknown {
    enum { ID = ID_RESOURCE_MONITOR };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_RESOURCE_MONITOR_NOTIFICATION };

        // @text onReconciliationComplete
        // @brief Triggered when a resource reconciliation pass completes.
        // @param appId Application identifier associated with the reconciliation request.
        // @param targetRamAchieved True when enough RAM headroom is available to proceed with loading another application.
        virtual void OnReconciliationComplete(const string& appId, const bool targetRamAchieved) {}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification* notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification* notification) = 0;

    // @text reconcile
    // @brief Requests a resource reconciliation pass, evicting inactive applications if required and permitted.
    // @param appId Application identifier associated with the resource request.
    // @param ramTargetMB Maximum RAM requested by the application, in megabytes.
    // @param allowTerminate When true, inactive applications may be terminated to free resources.
        virtual Core::hresult Reconcile(const string& appId, const uint32_t ramTargetMB, const bool allowTerminate) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
