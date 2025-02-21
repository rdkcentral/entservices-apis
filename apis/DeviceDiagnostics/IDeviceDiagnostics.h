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
        /* @json @text:keep */
        struct EXTERNAL IDeviceDiagnostics : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICE_DIAGNOSTICS };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_DEVICE_DIAGNOSTICS_NOTIFICATION };

                // @text onAVDecoderStatusChanged
                // @brief Triggered when the most active status of audio/video decoder/pipeline changes
                // @param AVDecoderStatus - in - string
                virtual void OnAVDecoderStatusChanged(const string& AVDecoderStatus /* @in */) = 0;
            };

            virtual uint32_t Register(IDeviceDiagnostics::INotification* notification /* @in */) = 0;
            virtual uint32_t Unregister(IDeviceDiagnostics::INotification* notification /* @in */) = 0;

            // @text getConfiguration
            // @brief Gets the values associated with the corresponding property names
            // @param names - in - String array of property names
            // @param name - out - String property name
            // @param value - out - String property value
            virtual uint32_t GetConfiguration(IStringIterator* const& names /* @in */, string& name /* @out */, string& value /* @out */) = 0;

            // @text getMilestones
            // @brief Returns the list of milestones
            // @param milestones - out - A string [] of milestones
            virtual uint32_t GetMilestones(IStringIterator*& milestones /* @out */) = 0;

            // @text logMilestone
            // @brief Log marker string to rdk milestones log
            // @param marker - in - string
            virtual uint32_t LogMilestone(const string& marker /* @in */) = 0;

            // @text getAVDecoderStatus
            // @brief Gets the most active status of audio/video decoder/pipeline
            // @param AVDecoderStatus - out - string
            virtual uint32_t GetAVDecoderStatus(string& AVDecoderStatus /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
