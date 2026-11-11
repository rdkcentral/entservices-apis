/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

    namespace Dolby {

        // @json @uncompliant:extended
        struct EXTERNAL IOutput : virtual public Core::IUnknown {

            enum { ID = ID_DOLBY_OUTPUT };

            ~IOutput() override = default;

            enum Type : uint8_t {
                DIGITAL_PCM = 0,
                DIGITAL_PLUS = 3,
                DIGITAL_AC3 = 4,
                AUTO = 5,
                DIGITAL_PASSTHROUGH = 6,
                MS12 = 7
            };

            enum SoundModes : uint8_t {
                UNKNOWN,
                MONO,
                STEREO,
                SURROUND,
                PASSTHRU,
                DOLBYDIGITAL,
                DOLBYDIGITALPLUS,
                SOUNDMODE_AUTO
            };

            // @event @uncompliant:extended
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_DOLBY_OUTPUT_NOTIFICATION };

                ~INotification() override = default;
                // @text dolby_audiomodechanged
                virtual void AudioModeChanged(const Dolby::IOutput::SoundModes mode, const bool enabled) = 0;
            };

            virtual uint32_t Register(INotification*) = 0;
            virtual uint32_t Unregister(INotification*) = 0;

            // @property
            // @brief Atmos capabilities of Sink
            // @details Retrieves whether the connected sink supports Dolby Atmos.
            // @param supported: Receives true when Atmos is supported by the sink; otherwise false.
            // @example supported: true
            // @retval Core::ERROR_NONE: The Atmos capability was retrieved successfully.
            // @text dolby_atmosmetadata
            // @return supported: atmos supported or unsupported
            virtual uint32_t AtmosMetadata(bool& supported /* @out */) const = 0;

            // @property
            // @brief Sound Mode - Mono/Stereo/Surround
            // @details Retrieves the current sound mode of the Dolby output.
            // @param mode: Receives the current sound mode.
            // @example mode: "STEREO"
            // @retval Core::ERROR_NONE: The current sound mode was retrieved successfully.
            // @text dolby_soundmode
            // @return mode: sound mode
            virtual uint32_t SoundMode(Dolby::IOutput::SoundModes& mode /* @out */) const = 0;

            // @property
            // @brief Enable Atmos Audio Output
            // @details Enables or disables Dolby Atmos audio output.
            // @param enable: enable/disable
            // @example enable: true
            // @retval Core::ERROR_NONE: The Atmos output setting was applied successfully.
            // @text dolby_enableatmosoutput
            virtual uint32_t EnableAtmosOutput(const bool& enable) = 0;

            // @property
            // @brief Dolby Mode
            // @details Sets the Dolby output mode. Supported values are DIGITAL_PCM, DIGITAL_PLUS, DIGITAL_AC3, AUTO, DIGITAL_PASSTHROUGH, and MS12.
            // @param mode: dolby mode type
            // @example mode: "DIGITAL_PCM"
            // @retval Core::ERROR_NONE: The Dolby output mode was set successfully.
            // @text dolby_mode
            virtual uint32_t Mode(const Dolby::IOutput::Type& mode) = 0;

            // @property
            // @brief Returns the current Dolby output mode.
            // @details Retrieves the configured Dolby output mode.
            // @param mode: Receives the current Dolby output mode.
            // @example mode: "DIGITAL_PCM"
            // @retval Core::ERROR_NONE: The Dolby output mode was retrieved successfully.
            virtual uint32_t Mode(Dolby::IOutput::Type& mode /* @out */) const = 0;

        };
    }
}
}
