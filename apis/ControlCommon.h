/**
 * @file ControlCommon.h
 * @brief Shared data types used by RemoteControl and VoiceControl interfaces.
 *
 * If not stated otherwise in this file or this component's LICENSE
 * file the following copyright and licenses apply:
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
**/

#pragma once

// Shared data types for RemoteControl and VoiceControl. Add here anything that
// would otherwise be duplicated across IRemoteControl.h and IVoiceControl.h.

#include "Module.h"

namespace WPEFramework {

    namespace Exchange {

        // ThunderTools BuildResult() collapses a single out param into a single value ("result":true/false),
        // so we wrap the boolean success in a struct to maintain the response shape ("result":{"success":true/false}).
        // Shared by RemoteControl and VoiceControl.
        struct EXTERNAL SuccessResult {
            bool success /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL GetApiVersionNumberResponse {
            uint32_t version /* @brief The API version number ex: 1 */;
            bool success     /* @brief Whether the request succeeded */;
        };

    } // namespace Exchange

} // namespace WPEFramework
