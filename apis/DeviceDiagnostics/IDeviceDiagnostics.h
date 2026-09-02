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
                // @details The OnAVDecoderStatusChanged event is triggered when the most active status of audio/video decoder/pipeline changes. The event provides a string parameter that describes the new status of the audio/video decoder/pipeline.
                // @param avDecoderStatusChange: Status change of the audio/video decoder/pipeline
                // @example avDecoderStatusChange: "Active"
                virtual void OnAVDecoderStatusChanged(const string& avDecoderStatusChange) {};
            };

            virtual Core::hresult Register(IDeviceDiagnostics::INotification* notification ) = 0;
            virtual Core::hresult Unregister(IDeviceDiagnostics::INotification* notification ) = 0;

            // @text getConfiguration
            // @brief Gets the values associated with the corresponding property names
            // @details Retrieves the configuration values corresponding to the supplied property names from the device.
            // @param names: String array of property names
            // @example names: ["DeviceInfo", "FirmwareVersion", "SerialNumber"]
            // @param paramList: specified properties and their values
            // @example paramList: [{"name":"DeviceInfo","value":"X1"}]
            // @param success: boolean
            // @example success: true
            // @retval Core::ERROR_NONE:Successfully retrieved configuration
            virtual Core::hresult GetConfiguration(IStringIterator* const& names , IDeviceDiagnosticsParamListIterator*& paramList /* @out */, bool& success /* @out */) = 0;

            // @text getMilestones
            // @brief Returns the list of milestones
            // @details Retrieves the list of milestones from the device.
            // @param milestones: A string [] of milestones
            // @example milestones: ["BootStart", "NetworkReady", "BootComplete"]
            // @param success: boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Successfully retrieved milestones
            virtual Core::hresult GetMilestones(IStringIterator*& milestones /* @out */, bool& success /* @out */) = 0;

            // @text logMilestone
            // @brief Log marker string to rdk milestones log
            // @details Logs the provided marker string to the RDK milestones log for tracking and analysis purposes.
            // @param marker: Milestone marker string
            // @example marker: "NetworkReady"
            // @param success: boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Successfully logged the milestone
            virtual Core::hresult LogMilestone(const string& marker , bool& success /* @out */) = 0;

            // @text getAVDecoderStatus
            // @brief Gets the most active status of audio/video decoder/pipeline
            // @details Retrieves the most active status of audio/video decoder/pipeline from the device.
            // @param AVDecoderStatus: The audio/video decoder status
            // @example AVDecoderStatus: {"avDecoderStatus":"Active"}
            // @retval Core::ERROR_NONE: Successfully retrieved the AV decoder status    
            virtual Core::hresult GetAVDecoderStatus(AvDecoderStatusResult& AVDecoderStatus /* @out */) = 0;

            // @text getPreviousRebootInfo
            // @brief Returns information about the previous reboot including timestamp, source, and reason
            // @details Retrieves information about the previous reboot from the device, including the timestamp, source, and reason for the reboot.
            // @param rebootInfo: Contains previous reboot information
            // @example rebootInfo: {"timestamp":"2023-05-15T10:30:00Z","source":"PowerButton","reason":"UserInitiated","customReason":"N/A","otherReason":"N/A","lastHardPowerReset":"2023-05-14T08:15:00Z"}
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::ERROR_NONE: Successfully retrieved the previous reboot information
            virtual Core::hresult GetPreviousRebootInfo(RebootInfo& rebootInfo /* @out */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
