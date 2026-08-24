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
        struct EXTERNAL IDeviceDiagnostics : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICE_DIAGNOSTICS };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            struct EXTERNAL ParamList {
                string name /* @text name */;
                string value /* @text value */;
            };

            struct EXTERNAL AvDecoderStatusResult {
                string avDecoderStatus;
            };

            struct EXTERNAL RebootInfo {
                string timestamp /* @text timestamp */; 
                string source /* @text source */;
                string reason /* @text reason */;
                string customReason /* @text customReason */; 
                string otherReason /* @text otherReason */;
                string lastHardPowerReset /* @text lastHardPowerReset */;
            };

            using IDeviceDiagnosticsParamListIterator = RPC::IIteratorType<ParamList, ID_DEVICE_DIAGNOSTICS_PARAM_LIST_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_DEVICE_DIAGNOSTICS_NOTIFICATION };

                // @text onAVDecoderStatusChanged
                // @brief Triggered when the most active status of audio/video decoder/pipeline changes
                // @param avDecoderStatusChange - in - string
                virtual void OnAVDecoderStatusChanged(const string& avDecoderStatusChange) {};
            };

            virtual Core::hresult Register(IDeviceDiagnostics::INotification* notification ) = 0;
            virtual Core::hresult Unregister(IDeviceDiagnostics::INotification* notification ) = 0;

            // @text getConfiguration
            // @brief Gets the values associated with the corresponding property names
            // @details Retrieves the configuration values corresponding to the supplied property names from the device.
            // @param names: String array of property names
            // @example names: ["DeviceInfo", "FirmwareVersion", "SerialNumber"]
            // @param paramList: Specified properties and their values
            // @example paramList: [{"name":"DeviceInfo","value":"X1"}]
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE: Configuration retrieved successfully.
            // @retval Core::ERROR_GENERAL: Failed to retrieve configuration.
            virtual Core::hresult GetConfiguration(IStringIterator* const& names , IDeviceDiagnosticsParamListIterator*& paramList /* @out */, bool& success /* @out */) = 0;

            // @text getMilestones
            // @brief Returns the list of milestones
            // @details Retrieves the list of milestone strings recorded by the device.
            // @param milestones: A string array of milestones
            // @example milestones: ["BootStart", "NetworkReady", "BootComplete"]
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE: Milestones retrieved successfully.
            // @retval Core::ERROR_GENERAL: Failed to retrieve milestones.
            virtual Core::hresult GetMilestones(IStringIterator*& milestones /* @out */, bool& success /* @out */) = 0;

            // @text logMilestone
            // @brief Log marker string to rdk milestones log
            // @details Appends the specified marker string to the RDK milestones log file.
            // @param marker: Marker string to log
            // @example marker: BootComplete
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE: Milestone logged successfully.
            // @retval Core::ERROR_GENERAL: Failed to log milestone.
            virtual Core::hresult LogMilestone(const string& marker , bool& success /* @out */) = 0;

            // @text getAVDecoderStatus
            // @brief Gets the most active status of audio/video decoder/pipeline
            // @details Retrieves the current most active status of the audio/video decoder or pipeline on the device.
            // @param AVDecoderStatus: [Type: Object] Element containing the string status value
            // @retval Core::ERROR_NONE: AV decoder status retrieved successfully.
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_GENERAL: Failed to retrieve AV decoder status.
            // @example AVDecoderStatus: {"avDecoderStatus": "PLAYING"}
            virtual Core::hresult GetAVDecoderStatus(AvDecoderStatusResult& AVDecoderStatus /* @out */) = 0;

            // @text getPreviousRebootInfo
            // @brief Returns information about the previous reboot including timestamp, source, and reason
            // @details Retrieves detailed information about the device's most recent reboot event.
            // @param rebootInfo: Contains previous reboot information
            // @example rebootInfo: PreviousRebootInfo
            // @example rebootInfo: {"timestamp":"2025-01-15T10:30:00Z","source":"PowerManager","reason":"FirmwareUpdate","customReason":"UserInitiated","otherReason":"None","lastHardPowerReset":"2025-01-01T00:00:00Z"}           
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE: Previous reboot information retrieved successfully.
            // @retval Core::ERROR_GENERAL: Failed to retrieve previous reboot information.
            virtual Core::hresult GetPreviousRebootInfo(RebootInfo& rebootInfo /* @out */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
