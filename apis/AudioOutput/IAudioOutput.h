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

namespace WPEFramework {
namespace Exchange {

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IAudioOutput : virtual public Core::IUnknown {

        enum { ID = ID_AUDIO_OUTPUT };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {

            enum { ID = ID_AUDIO_OUTPUT_NOTIFICATION };

            // @text onDolbyAtmosExperienceChanged
            // @brief Notifies subscribers when the Dolby Atmos Experience state changes
            // @param dolbyAtmosExperience: true if Dolby Atmos Experience is now enabled
            virtual void OnDolbyAtmosExperienceChanged(const bool dolbyAtmosExperience) {};
        };

        // @brief Registers a notification observer
        // @param notification: Notification observer to be registered
        // @retval Core::ERROR_NONE: Observer registered successfully
        // @retval Core::ERROR_GENERAL: Failed to register observer
        virtual Core::hresult Register(IAudioOutput::INotification* notification) = 0;

        // @brief Unregisters a notification observer
        // @param notification: Notification observer to be unregistered
        // @retval Core::ERROR_NONE: Observer unregistered successfully
        // @retval Core::ERROR_GENERAL: Failed to unregister observer
        virtual Core::hresult Unregister(const IAudioOutput::INotification* notification) = 0;

        // @text dolbyAtmosExperience
        // @brief Returns whether Dolby Atmos Experience is currently enabled
        // @details Combines AtmosMetadata capability (must be ATMOS_METADATA) and
        //          current sound mode (must be PASSTHRU, DOLBYDIGITALPLUS, or SOUNDMODE_AUTO)
        //          to determine the Dolby Atmos Experience state.
        // @param enabled: true if Dolby Atmos Experience is enabled, false otherwise
        // @retval Core::ERROR_NONE on success
        // @retval Core::ERROR_GENERAL on failure
        virtual Core::hresult DolbyAtmosExperience(bool& enabled /* @out */) const = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

