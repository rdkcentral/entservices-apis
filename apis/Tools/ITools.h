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

namespace WPEFramework
{
    namespace Exchange
    {
        // @json 1.0.0 @text:keep
        struct EXTERNAL ITools : virtual public Core::IUnknown {
            enum { ID = ID_TOOLS };

            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @text generateKey
            // @brief Simulates key events for a list of key entries. Each entry contains parallel arrays of key codes and
            //        their corresponding modifier sets, along with timing controls.
            // @details Supported action to key mapping:
            // | Action | Linux Key Symbol | Linux Key Code | Modifiers |
            // | --- | --- | ---: | --- |
            // | Menu | KEY_HOME | 102 | - |
            // | Guide | KEY_HOME | 102 | - |
            // | Info | KEY_F9 | 67 | - |
            // | Star | KEY_F6 | 64 | - |
            // | TV Power | KEY_F1 | 59 | - |
            // | Input | KEY_F15 | 185 | - |
            // | OK | KEY_OK | 352 | - |
            // | Select | KEY_ENTER | 28 | - |
            // | Enter | KEY_ENTER | 28 | - |
            // | Exit | KEY_ESC | 1 | - |
            // | Back | KEY_ESC | 1 | - |
            // | Period | KEY_F5 | 63 | - |
            // | Push To Talk | KEY_F8 | 66 | - |
            // | Power | KEY_POWER | 116 | - |
            // | Channel Up | KEY_UP | 103 | ctrl |
            // | Channel Down | KEY_DOWN | 108 | ctrl |
            // | Volume Up | KEY_KPPLUS | 78 | - |
            // | Volume Down | KEY_KPMINUS | 74 | - |
            // | Mute | KEY_KPASTERISK | 55 | - |
            // | Digit 1 | KEY_1 | 2 | - |
            // | Digit 2 | KEY_2 | 3 | - |
            // | Digit 3 | KEY_3 | 4 | - |
            // | Digit 4 | KEY_4 | 5 | - |
            // | Digit 5 | KEY_5 | 6 | - |
            // | Digit 6 | KEY_6 | 7 | - |
            // | Digit 7 | KEY_7 | 8 | - |
            // | Digit 8 | KEY_8 | 9 | - |
            // | Digit 9 | KEY_9 | 10 | - |
            // | Digit 0 | KEY_0 | 11 | - |
            // | Fast Forward | KEY_F12 | 88 | - |
            // | Rewind | KEY_F10 | 68 | - |
            // | Pause | KEY_F11 | 87 | - |
            // | Play | KEY_F11 | 87 | - |
            // | Stop | KEY_S | 31 | ctrl |
            // | Record | KEY_F7 | 65 | - |
            // | Arrow Up | KEY_UP | 103 | - |
            // | Arrow Down | KEY_DOWN | 108 | - |
            // | Arrow Left | KEY_LEFT | 105 | - |
            // | Arrow Right | KEY_RIGHT | 106 | - |
            // | Page Up | KEY_PAGEUP | 104 | - |
            // | Page Down | KEY_PAGEDOWN | 109 | - |
            // | Last | KEY_L | 38 | ctrl |
            // | Favorite | KEY_N | 49 | ctrl |
            // | Key A | KEY_INSERT | 110 | - |
            // | Key B | KEY_END | 107 | - |
            // | Key C | KEY_F4 | 62 | - |
            // | Key D | KEY_DELETE | 111 | - |
            // | Help | KEY_F2 | 60 | - |
            // | Setup | KEY_SETUP | 141 | - |
            // | Next | KEY_NEXT | 407 | - |
            // | Previous | KEY_PREVIOUS | 412 | - |
            // | On Demand | KEY_F5 | 63 | - |
            // | Pound | KEY_BATTERY | 236 | - |
            // | Audio | KEY_F23 | 193 | - |
            // | Closed Captioning | KEY_F24 | 194 | - |
            // | Replay | KEY_B | 48 | ctrl |
            // | Search | KEY_F3 | 61 | - |
            // | RF Pair Ghost | KEY_BLUETOOTH | 237 | - |
            // | Undefined | KEY_UNKNOWN | 240 | - |
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
