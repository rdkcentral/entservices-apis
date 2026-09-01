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
#include <string>

// @stubgen:include <com/IIteratorType.h>
namespace WPEFramework {
namespace Exchange {

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IAudioOutput : virtual public Core::IUnknown {

        enum { ID = ID_AUDIO_OUTPUT };

        enum AudioModes : uint8_t {
                UNKNOWN,
                MONO,
                STEREO,
                SURROUND,
                PASSTHRU,
                DOLBYDIGITAL,
                DOLBYDIGITALPLUS,
                SOUNDMODE_AUTO
         };

        using IAudioConfigListIterator = RPC::IIteratorType<string, ID_AUDIO_CONFIG_LIST_ITERATOR>;

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {

            enum { ID = ID_AUDIO_OUTPUT_NOTIFICATION };

            // @text onDolbyAtmosExperienceChanged
            // @brief Notifies subscribers when the Dolby Atmos Experience state changes
            // @param dolbyAtmosExperience: true if Dolby Atmos Experience is now enabled
            virtual void OnDolbyAtmosExperienceChanged(const bool dolbyAtmosExperience) {}
        };

        
        virtual Core::hresult Register(IAudioOutput::INotification* notification) = 0;
        virtual Core::hresult Unregister(const IAudioOutput::INotification* notification) = 0;

        // @text dolbyAtmosExperience
        // @brief Returns whether Dolby Atmos Experience is currently enabled
        // @details Combines AtmosMetadata capability (must be ATMOS_METADATA) and
        //          current sound mode (must be PASSTHRU, DOLBYDIGITALPLUS, or SOUNDMODE_AUTO)
        //          to determine the Dolby Atmos Experience state.
        // @param enabled: true if Dolby Atmos Experience is enabled, false otherwise
        // @retval Core::ERROR_NONE on success
        virtual Core::hresult DolbyAtmosExperience(bool& enabled /* @out */) const = 0;

        // @text setAudioConfig
        // @brief Sets an audio configuration state.
        // @details Enables or disables the specified audio configuration based on the `enabled` parameter.
        // @param audioConfig: Audio configuration. e.g. `CONTINUOUS_AUDIO_OUTPUT`
        // @example audioConfig: CONTINUOUS_AUDIO_OUTPUT
        // @param enabled: true to enable the configuration, false to disable it
        // @example enabled: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_BAD_REQUEST: Provided audioConfig is unsupported
        virtual Core::hresult SetAudioConfig(const string& audioConfig /* @text audioConfig */, const bool enabled) = 0;

        // @text getAudioConfig
        // @brief Gets an audio configuration state.
        // @details Returns whether the specified AudioConfig is currently enabled.
        // @param audioConfig: Audio configuration. e.g. `CONTINUOUS_AUDIO_OUTPUT`
        // @example audioConfig: CONTINUOUS_AUDIO_OUTPUT
        // @param enabled: true if the configuration is currently enabled, false otherwise
        // @example enabled: true
        // @retval Core::ERROR_NONE on success
        // @retval Core::ERROR_BAD_REQUEST for unsupported configuration
        virtual Core::hresult GetAudioConfig(const string& audioConfig /* @text audioConfig */, bool& enabled /* @out */) const = 0;

        // @text getSupportedAudioConfigs
        // @brief Returns list of supported audio configurations.
        // @details Returns the list of audio configuration available for this device that the clients can enable or disable.
        // @param audioConfigs: List of supported audio configurations
        // @example audioConfigs: ["CONTINUOUS_AUDIO_OUTPUT"]
        // @retval Core::ERROR_NONE on success
        virtual Core::hresult GetSupportedAudioConfigs(IAudioConfigListIterator*& audioConfigs /* @out */) const = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

