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
        struct EXTERNAL IResourceMonitor : virtual public Core::IUnknown {
            enum { ID = ID_RESOURCEMONITOR };

            typedef string EventData;

            enum class CaptureMode : uint8_t {
                NONE = 0 /* @text: NONE */,
                LIVE = 1 /* @text: LIVE */,
                SUMMARY = 2 /* @text: SUMMARY */,
                MIXED = 3 /* @text: MIXED */,
            };

            enum class MeasurementType : uint8_t {
                NONE /* @text: NONE */,
                ALL /* @text: ALL */,
                ALLMEMORY /* @text: ALLMEMORY */,
                ALLCPU /* @text: ALLCPU */,
                MEMORYUSS /* @text: MEMORYUSS */,
                MEMORYPSS /* @text: MEMORYPSS */,
                MEMORYRSS /* @text: MEMORYRSS */,
                MEMORYRAMFREE /* @text: MEMORYRAMFREE */,
                MEMORYRAMTOTAL /* @text: MEMORYRAMTOTAL */,
                MEMORYRAMAVAILABLE /* @text: MEMORYRAMAVAILABLE */,
                CPULOADTOTAL /* @text: CPULOADTOTAL */,
                CPULOADTOTALUSER /* @text: CPULOADTOTALUSER */,
                CPULOADTOTALSYSTEM /* @text: CPULOADTOTALSYSTEM */,
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_RESOURCEMONITOR_NOTIFICATION };
                ~INotification() override = default;

                // @brief Notification with resource monitor data
                // @param data EventData, which contains serialized JSON Lines with data
                // samples
                virtual void OnResourceMonitorData(const EventData &events) = 0;
            };

            ~IResourceMonitor() override = default;

            // @brief Manage notifications lifecycle
            virtual void Register(IResourceMonitor::INotification *sink) = 0;
            virtual void Unregister(IResourceMonitor::INotification *sink) = 0;

            // @brief Configure plugin
            /* @json:omit */
            virtual uint32_t Configure(PluginHost::IShell *framework) = 0;

            // @brief Begin capture session
            virtual uint32_t StartCapture(const uint32_t interval,
                                        const CaptureMode captureMode) = 0;

            // @brief End capture session
            virtual uint32_t StopCapture() = 0;

            // @brief Get current resource usage
            virtual uint32_t GetCurrentUsage(const string &processPrefix,
                                            const MeasurementType measurementType) = 0;

            // @brief Add custom label to dataset
            virtual uint32_t AddLabel(const string &annotation) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
