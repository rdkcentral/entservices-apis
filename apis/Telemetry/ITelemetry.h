/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL ITelemetry : virtual public Core::IUnknown 
        {
            enum { ID = ID_TELEMETRY };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_TELEMETRY_NOTIFICATION };

                // @text onReportUpload
                // @brief Triggered by callback from Telemetry after report uploading
                // @param telemetryUploadStatus - in - string
                virtual void OnReportUpload(const string& telemetryUploadStatus) {};
            };

            virtual Core::hresult Register(ITelemetry::INotification* notification /* @in */) = 0;
            virtual Core::hresult Unregister(ITelemetry::INotification* notification /* @in */) = 0;

            /**********************setReportProfileStatus() - start****************************/
            // @text setReportProfileStatus
            // @brief Sets the status of telemetry reporting
            // @param status - in - string
            virtual Core::hresult SetReportProfileStatus(const string& status /* @in */) = 0;
            /**********************setReportProfileStatus() - end******************************/

            /**********************logApplicationEvent() - start*******************************/
            // @text logApplicationEvent
            // @brief Logs an application
            // @param eventName - in - string
            // @param eventValue - in - string
            virtual Core::hresult LogApplicationEvent(const string& eventName /* @in */, const string& eventValue /* @in */) = 0;
            /**********************logApplicationEvent() - end*********************************/

            /**********************uploadReport() - start**************************************/
            // @text uploadReport
            // @brief Uploading of telemetry report
            // @see onReportUpload : Triggered by callback from Telemetry after report uploading
            virtual Core::hresult UploadReport() = 0;
            /**********************uploadReport() - end****************************************/

            /**********************abortReport() - start***************************************/
            // @text abortReport
            // @brief Abort report upload
            virtual Core::hresult AbortReport() = 0;
            /**********************abortReport() - end*****************************************/
        };
    } // namespace Exchange
} // namespace WPEFramework