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

/*
 * @brief Structure for the Resource monitor stats
 */
struct EXTERNAL ResourceMonitorStats {
	// @brief Total physical system memory in KiB.
        uint64_t systemMemTotal;
	// @brief Physical system memory currently in use in KiB.
        uint64_t systemMemUsed;
	// @brief Physical system memory currently available in KiB.
        uint64_t systemMemAvailable;
	// @brief Highest observed system memory usage in KiB since ResourceMonitor startup.
        uint64_t peakSystemMemUsed;

	// @brief Total GPU memory in bytes. Zero if GPU monitoring is not supported.
        uint64_t gpuMemTotal;
	// @brief GPU memory currently in use in bytes. Zero if GPU monitoring is not supported.
        uint64_t gpuMemUsed;
	// @brief GPU memory currently available in bytes. Zero if GPU monitoring is not supported.
        uint64_t gpuMemAvailable;
	// @brief Highest observed GPU memory usage in bytes since ResourceMonitor startup.
        uint64_t peakGpuMemUsed;

	// @brief Total configured swap space in bytes.
        uint64_t swapTotal;
	// @brief Free swap space in bytes.
        uint64_t swapFree;
	// @brief Swap usage in bytes based on zram uncompressed data size.
        uint64_t swapUsed;
	// @brief Highest observed swap usage in bytes since ResourceMonitor startup.
        uint64_t peakSwapUsed;

	// @brief Total flash storage quota allocated for hibernated apps in bytes.
        uint64_t flashSpaceTotal;
	// @brief Flash storage currently consumed by hibernated apps in bytes.
        uint64_t flashSpaceUsed;
	// @brief Flash storage available for additional hibernated app data in bytes.
        uint64_t flashSpaceAvailable;
	// @brief Highest observed flash storage usage in bytes since ResourceMonitor startup.
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

    // @text setConfig
    // @brief Loads Resource Monitor Configuration
    // @param JSON formatted configuration string
    // @retval Core::ERROR_NONE Configuration successfully loaded.
    // @retval Core::ERROR_BAD_REQUEST Invalid JSON configuration.
    // @retval Core::ERROR_ILLEGAL_STATE Configuration change attempted after initialization.
    virtual Core::hresult SetConfig(const string& config) = 0;

    // @brief Registers a notification interface.
    // @param notification ResourceMonitor notification interface.
    // @retval Core::ERROR_NONE Notification registered.
    // @retval Core::ERROR_BAD_REQUEST notification is nullptr.
    virtual Core::hresult Register(INotification* notification) = 0;

    // @brief Unregisters a notification interface.
    // @param notification ResourceMonitor notification interface.
    // @retval Core::ERROR_NONE Notification unregistered.
    // @retval Core::ERROR_BAD_REQUEST notification is nullptr.
    // @retval Core::ERROR_NOT_EXIST Notification was not registered.
    virtual Core::hresult Unregister(INotification* notification) = 0;

    // @text getMemInfo
    // @brief Returns memory information.
    // @param memAvailable Amount of available RAM in KiB.
    // @param swapFree Amount of free swap space in KiB.
    // @param swapTotal Total configured swap space in KiB.
    // @retval Core::ERROR_NONE Successfully retrieved memory information.
    // @retval Core::ERROR_GENERAL Failed to read memory information from the system.
    virtual Core::hresult GetMemInfo(uint64_t& memAvailable /* @out */,
                           uint64_t& swapFree /* @out */,
                           uint64_t& swapTotal /* @out */) = 0;

    // @text getPsiMetrics
    // @brief Returns PSI metrics.
    // @param metric PSI metric selector
    // @param value PSI percentage value
    // @param total PSI total value
    // @retval Core::ERROR_NONE PSI metric successfully retrieved.
    // @retval Core::ERROR_BAD_REQUEST Invalid metric selector.
    // @retval Core::ERROR_UNAVAILABLE PSI monitoring is disabled.
    // @retval Core::ERROR_GENERAL Failed to access PSI statistics.
    virtual Core::hresult GetPsiMetrics(const string& metric,
                           double& value /* @out */,
			   uint64_t& total /* @out */) = 0;

    // @text getFlashSpace
    // @brief Returns flash usage.
    // @param total Total flash storage quota for hibernated apps.
    // @param used Flash storage currently consumed by hibernated apps.
    // @param available Remaining flash storage available to hibernated apps.
    // @retval Core::ERROR_NONE Flash usage successfully retrieved.
    // @retval Core::ERROR_GENERAL Failed to access flash storage information.
    virtual Core::hresult GetFlashSpace(uint64_t& total /* @out */,
		           uint64_t& used /* @out */,
                           uint64_t& available /* @out */) = 0;

    // @text getSwapUsed
    // @brief Returns swap usage.
    // @param swapUsed Uncompressed swap data currently stored in zram.
    // @param memUsedTotal Actual memory consumed by zram.
    // @retval Core::ERROR_NONE Swap usage successfully retrieved.
    // @retval Core::ERROR_GENERAL Failed to access zram statistics.
    virtual Core::hresult GetSwapUsed(uint64_t& swapUsed /* @out */,
                            uint64_t& memUsedTotal /* @out */) = 0;

    // @text getStats
    // @brief Returns resource statistics.
    // @param stats Structure containing memory, swap, flash, GPU and peak usage statistics.
    // @retval Core::ERROR_NONE Statistics successfully collected.
    // @retval Core::ERROR_GENERAL Failed to gather one or more resource statistics.
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
