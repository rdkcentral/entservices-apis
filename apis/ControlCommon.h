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
//
// Note: Module.h is intentionally NOT included here. Interface headers that use
// this file (IRemoteControl.h, IVoiceControl.h) include Module.h first, so
// EXTERNAL is already defined by the time these structs are compiled. Keeping
// Module.h out of this file also prevents the ProxyStubGenerator from crashing
// on the complex templates it contains when following @stubgen:include chains.

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
