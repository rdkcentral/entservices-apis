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
            // @param names - in - String array of property names
            // @param paramList - out - specified properties and their values
            // @param success - out - boolean
            virtual Core::hresult GetConfiguration(IStringIterator* const& names , IDeviceDiagnosticsParamListIterator*& paramList /* @out */, bool& success /* @out */) = 0;

            // @text getMilestones
            // @brief Returns the list of milestones
            // @param milestones - out - A string [] of milestones
            // @param success - out - boolean
            virtual Core::hresult GetMilestones(IStringIterator*& milestones /* @out */, bool& success /* @out */) = 0;

            // @text logMilestone
            // @brief Log marker string to rdk milestones log
            // @param marker - in - string
            // @param success - out - boolean
            virtual Core::hresult LogMilestone(const string& marker , bool& success /* @out */) = 0;

            // @text getAVDecoderStatus
            // @brief Gets the most active status of audio/video decoder/pipeline
            // @param AVDecoderStatus - out
            virtual Core::hresult GetAVDecoderStatus(AvDecoderStatusResult& AVDecoderStatus /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
