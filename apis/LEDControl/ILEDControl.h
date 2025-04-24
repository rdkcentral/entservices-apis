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
        struct EXTERNAL ILEDControl : virtual public Core::IUnknown
        {
            enum { ID = ID_LEDCONTROL };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            struct EXTERNAL LEDControlSuccess {
                bool success;
            };

            // @text getSupportedLEDStates
            // @brief Returns all the LED states supported by the platform
            // @param supportedLEDStates - out - string [] of supported LED states
            // @param success - out - boolean
            virtual Core::hresult GetSupportedLEDStates(IStringIterator*& supportedLEDStates /* @out */, bool& success /* @out */) = 0;

            // @text getLEDState
            // @brief Returns current LED state.
            // @param state - out - string
            // @param success - out - boolean
            virtual Core::hresult GetLEDState(string& state /* @out */, bool& success /* @out */) = 0;

            // @text setLEDState
            // @brief Change the device LED state to one mentioned in the input argument.
            // @param state - in - string
            // @param LEDControlSuccess - out
            virtual Core::hresult SetLEDState(const string& state, LEDControlSuccess& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
