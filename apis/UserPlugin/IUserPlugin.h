/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
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

namespace WPEFramework {
namespace Exchange {
    // @json @text:keep
    struct EXTERNAL IUserPlugin : virtual public Core::IUnknown {
        enum { ID = ID_USER_PLUGIN };

        virtual ~IUserPlugin() override = default;

        /** Gets the Power State.*/
        // @json getDevicePowerState
        // @brief Get current Power State
        // @param[out] powerState current power state
        virtual Core::hresult GetDevicePowerState(std::string& powerState /* @out */) const = 0;

        /** Gets the Audio Volume Level.*/
        // @text getVolumeLevel
        // @brief Get Volume Level
	// @param[in] port, from which port they need an audio level
        // @param[volumeLevel] response, audio level
        virtual Core::hresult GetVolumeLevel (const std::string& port /* @in */, std::string& volumeLevel /* @out */) const = 0;
    };
}
}
