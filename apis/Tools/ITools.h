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
#include <vector>

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
    namespace Exchange
    {
        // @json 1.0.0 @text:keep
        struct EXTERNAL ITools : virtual public Core::IUnknown {
            enum { ID = ID_TOOLS };

            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @text generateKeys
            // @brief Simulates key events for a list of key entries. Each entry contains parallel arrays of key codes and
            //        their corresponding modifier sets, along with timing controls.
            // @param keys: JSON array of key entry objects. Each object contains:
            //   keyCode (array of Linux key codes),
            //   modifiers (array of arrays of modifier strings, where modifiers[i] applies to keyCode[i]; supported values: "ctrl", "alt", "shift"),
            //   delay (number, seconds to wait before sending the key event),
            //   duration (number, optional, seconds between key press and key release; omit or 0 if not used)
            // @param success: Indicates whether the operation was successful
            // @retval Core::ERROR_NONE: Keys generated successfully
            // @retval Core::ERROR_GENERAL: Failed to generate keys
            // @retval Core::ERROR_INVALID_INPUT_LENGTH: The keys list is empty or invalid
            virtual Core::hresult GenerateKey(const string& keys /* @opaque */, bool& success /* @out */) = 0;

        };
} // namespace Exchange
} // namespace WPEFramework
