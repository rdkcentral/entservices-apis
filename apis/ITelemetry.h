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
                // @details This event is generated when a telemetry report upload operation completes. The notification contains the final upload status returned by the telemetry subsystem.
                // @param telemetryUploadStatus - in - string
                // @example telemetryUploadStatus : "COMPLETE"
                virtual void OnReportUpload(const string& telemetryUploadStatus) {};
            };

            virtual Core::hresult Register(ITelemetry::INotification* notification) = 0;
            virtual Core::hresult Unregister(ITelemetry::INotification* notification) = 0;

            /**********************setReportProfileStatus() - start****************************/
            // @text setReportProfileStatus
            // @brief Sets the status of telemetry reporting
            // @details Enables or disables telemetry report profile processing based on the supplied status value. The configured state determines whether telemetry reports are collected and uploaded.
            // @param status - in - Telemetry reporting status.
            // @example status : "STARTED"
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Report profile status updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update report profile status.
            virtual Core::hresult SetReportProfileStatus(const string& status) = 0;
            /**********************setReportProfileStatus() - end******************************/

            /**********************logApplicationEvent() - start*******************************/
            // @text logApplicationEvent
            // @brief Logs an application
            // @details Records an application-specific telemetry event and its associated value. Logged events may be included in telemetry reports for analytics and diagnostic purposes.
            // @param eventName - in - string
            // @example eventName : "ApplicationLaunch"
            // @param eventValue - in - string
            // @example eventValue : "Success"
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Event logged successfully.
            // @retval Core::ERROR_GENERAL - Failed to log the event.
            virtual Core::hresult LogApplicationEvent(const string& eventName , const string& eventValue) = 0;
            /**********************logApplicationEvent() - end*********************************/

            /**********************uploadReport() - start**************************************/
            // @text uploadReport
            // @brief Uploading of telemetry report
            // @details Initiates upload of the currently generated telemetry report to the configured telemetry backend. Completion status is reported through the onReportUpload notification.
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Report upload initiated successfully.
            // @retval Core::ERROR_GENERAL - Failed to initiate the report upload.
            virtual Core::hresult UploadReport() = 0;
            /**********************uploadReport() - end****************************************/

            /**********************abortReport() - start***************************************/
            // @text abortReport
            // @brief Abort report upload
            // @details Cancels an ongoing telemetry report upload operation.
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE - Report upload aborted successfully.
            // @retval Core::ERROR_GENERAL - Failed to abort the report upload.
            virtual Core::hresult AbortReport() = 0;
            /**********************abortReport() - end*****************************************/

            /**********************setOptOutTelemetry() - start***************************************/
            // @text setOptOutTelemetry
            // @brief Sets the telemetry opt-out status.
            // @details Configures the telemetry privacy preference for the device. When opt-out is enabled, telemetry collection and reporting are disabled according to platform policy.
            // @param OptOut  - in - boolean
            // @example optOut: true
            // @param  - out - struct
            // @example successResult: {"success": true}
            //  @param success: Indicates whether the operation was successful
            // @example success: true
            // @example telemetry:SetOptOutTelemetry(true, successResult);
            // @retval Core::ERROR_NONE - Opt-out status updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the opt-out status.
            virtual Core::hresult SetOptOutTelemetry(const bool optOut /* @text Opt-Out */, TelemetrySuccess& successResult /* @out */) = 0;
            /**********************setOptOutTelemetry() - end*****************************************/

            /**********************isOptOutTelemetry() - start***************************************/
	        // @text isOptOutTelemetry
            // @brief Checks the telemetry opt-out status.
            // @details Retrieves the current telemetry privacy preference for the device.
            // @param OptOut  - out - boolean
            // @example optOut: true
            // @param success - out - boolean
            // @example success - true
            // @example telemetry:IsOptOutTelemetry(optOut,success);
            // @retval Core::ERROR_NONE - Telemetry opt-out status retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to retrieve the telemetry opt-out status.
            virtual Core::hresult IsOptOutTelemetry(bool& optOut /* @out @text Opt-Out*/, bool& success /* @out */) = 0;
            /**********************isOptOutTelemetry() - end*****************************************/
        };
    } // namespace Exchange
} // namespace WPEFramework
