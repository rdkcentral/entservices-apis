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

	struct EXTERNAL ResourceMonitorStats {
            uint64_t systemMemTotal;
            uint64_t systemMemUsed;
            uint64_t systemMemAvailable;
            uint64_t peakSystemMemUsed;

            uint64_t gpuMemTotal;
            uint64_t gpuMemUsed;
            uint64_t gpuMemAvailable;
            uint64_t peakGpuMemUsed;

            uint64_t swapTotal;
            uint64_t swapFree;
            uint64_t swapUsed;
            uint64_t peakSwapUsed;

            uint64_t flashSpaceTotal;
            uint64_t flashSpaceUsed;
            uint64_t flashSpaceAvailable;
            uint64_t peakFlashSpaceUsed;
        };


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

    virtual uint32_t SetConfig(const string& config) = 0;

    /** Register notification interface */
    virtual Core::hresult Register(INotification* notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification* notification) = 0;

    // @text GetMemInfo
    // @brief Returns memory information.
    virtual Core::hresult GetMemInfo(uint64_t& memAvailable /* @out */,
                           uint64_t& swapFree /* @out */,
                           uint64_t& swapTotal /* @out */) = 0;

    // @text GetPsiMetrics
    // @brief Returns PSI metrics.
    virtual Core::hresult GetPsiMetrics(const string& metric,
                           double& value /* @out */,
			   uint64_t& total /* @out */) = 0;

    // @text GetFlashSpace
    // @brief Returns flash usage.
    virtual Core::hresult GetFlashSpace(uint64_t& total /* @out */, uint64_t& used /* @out */,
                           uint64_t& available /* @out */) = 0;

    // @text GetSwapUsed
    // @brief Returns swap usage.
    virtual Core::hresult GetSwapUsed(uint64_t& swapUsed /* @out */,
                            uint64_t& memUsedTotal /* @out */) = 0;

    // @text GetStats
    // @brief Returns resource statistics.
    virtual Core::hresult GetStats(ResourceMonitorStats& stats /* @out */) = 0;

    // @text reconcile
    // @brief Requests a resource reconciliation pass, evicting inactive applications if required and permitted.
    // @param appId Application identifier associated with the resource request.
    // @param ramTargetMB Maximum RAM requested by the application, in megabytes.
    // @param allowTerminate When true, inactive applications may be terminated to free resources.
        virtual Core::hresult Reconcile(const string& appId, const uint32_t ramTargetMB, const bool allowTerminate) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
