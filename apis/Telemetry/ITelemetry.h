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

            struct EXTERNAL TelemetrySuccess {
                bool success;
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_TELEMETRY_NOTIFICATION };

                // @text onReportUpload
                // @brief Triggered by callback from Telemetry after report uploading
                // @details Invoked by the Telemetry service after a report has been uploaded. Components implementing this interface should handle the upload status accordingly.
                // @param telemetryUploadStatus - in - string
                // @example telemetryUploadStatus: "success"
                virtual void OnReportUpload(const string& telemetryUploadStatus) {};
            };

            virtual Core::hresult Register(ITelemetry::INotification* notification) = 0;
            virtual Core::hresult Unregister(ITelemetry::INotification* notification) = 0;

            /**********************setReportProfileStatus() - start****************************/
            // @text setReportProfileStatus
            // @brief Sets the status of telemetry reporting
            // @details Invoked by the Telemetry service to set the status of telemetry reporting. Components implementing this interface should update their internal state to reflect the new reporting status.
            // @param status - in - string
            // @example status: "enabled"
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - The status was set successfully.
            // @retval Core::ERROR_GENERAL - Failed to set the status.
            virtual Core::hresult SetReportProfileStatus(const string& status) = 0;
            /**********************setReportProfileStatus() - end******************************/

            /**********************logApplicationEvent() - start*******************************/
            // @text logApplicationEvent
            // @brief Logs an application
            // @details Invoked by the Telemetry service to log an application event. Components implementing this interface should record the event with the provided name and value.
            // @param eventName - in - string
            // @example eventName: "UserLogin"
            // @param eventValue - in - string
            // @example eventValue: "Success"
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - The event was logged successfully.
            // @retval Core::ERROR_GENERAL - Failed to log the event.
            virtual Core::hresult LogApplicationEvent(const string& eventName , const string& eventValue) = 0;
            /**********************logApplicationEvent() - end*********************************/

            /**********************uploadReport() - start**************************************/
            // @text uploadReport
            // @brief Uploading of telemetry report
            // @details Invoked by the Telemetry service to upload a telemetry report. Components implementing this interface should initiate the report upload process and handle the result accordingly.
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - The report upload was initiated successfully.
            // @retval Core::ERROR_GENERAL - Failed to initiate the report upload.
            virtual Core::hresult UploadReport() = 0;
            /**********************uploadReport() - end****************************************/

            /**********************abortReport() - start***************************************/
            // @text abortReport
            // @brief Abort report upload
            // @details Invoked by the Telemetry service to abort an ongoing telemetry report upload. Components implementing this interface should terminate the upload process and handle any necessary cleanup.
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - The report upload was aborted successfully.
            // @retval Core::ERROR_GENERAL - Failed to abort the report upload.
            virtual Core::hresult AbortReport() = 0;
            /**********************abortReport() - end*****************************************/

            /**********************setOptOutTelemetry() - start***************************************/
            // @text setOptOutTelemetry
            // @brief Sets the telemetry opt-out status.
            // @details Invoked by the Telemetry service to set the opt-out status for telemetry reporting. Components implementing this interface should update their internal configuration to reflect the user's preference regarding telemetry data collection.
            // @param OptOut  - in - boolean
            // @example OptOut: true
            // @param  - out - struct
            // @example success: true
            // @retval Core::ERROR_NONE - The opt-out status was set successfully.
            // @retval Core::ERROR_GENERAL - Failed to set the opt-out status.
            virtual Core::hresult SetOptOutTelemetry(const bool optOut /* @text Opt-Out */, TelemetrySuccess& successResult /* @out */) = 0;
            /**********************setOptOutTelemetry() - end*****************************************/

            /**********************isOptOutTelemetry() - start***************************************/
	        // @text isOptOutTelemetry
            // @brief Checks the telemetry opt-out status.
            // @details Invoked by the Telemetry service to check the current opt-out status for telemetry reporting. Components implementing this interface should return the current configuration indicating whether telemetry data collection is opted out.
            // @param OptOut  - out - boolean
            // @example OptOut: true
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE - The opt-out status was retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the opt-out status.
            virtual Core::hresult IsOptOutTelemetry(bool& optOut /* @out @text Opt-Out*/, bool& success /* @out */) = 0;
            /**********************isOptOutTelemetry() - end*****************************************/
        };
    } // namespace Exchange
} // namespace WPEFramework
