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
            // Utility functions for enum-string conversion
            enum class LEDControlState : uint8_t {
                LEDSTATE_NONE = 0,                /* @text NONE */ /* @brief Indicates Uninitialized state */
                LEDSTATE_ACTIVE,                  /* @text ACTIVE */ /* @brief Indicates Active power state */
                LEDSTATE_STANDBY,                 /* @text STANDBY */ /* @brief Indicates Standby power state */
                LEDSTATE_WPS_CONNECTING,          /* @text WPS_CONNECTING */ /* @brief Indicates WPS Connecting */
                LEDSTATE_WPS_CONNECTED,           /* @text WPS_CONNECTED */ /* @brief Indicates WPS Connected */
                LEDSTATE_WPS_ERROR,               /* @text WPS_ERROR */ /* @brief Indicates WPS Error */
                LEDSTATE_FACTORY_RESET,           /* @text FACTORY_RESET */ /* @brief Indicates Factory Reset */
                LEDSTATE_USB_UPGRADE,             /* @text USB_UPGRADE */ /* @brief Indicates USB Upgrade */
                LEDSTATE_SOFTWARE_DOWNLOAD_ERROR, /* @text SOFTWARE_DOWNLOAD_ERROR */ /* @brief Indicates Software Download Error */
                LEDSTATE_UNKNOWN
            };

            static const char* LEDControlStateToString(LEDControlState state)
            {
                switch (state) {
                    case LEDControlState::LEDSTATE_NONE: return "NONE";
                    case LEDControlState::LEDSTATE_ACTIVE: return "ACTIVE";
                    case LEDControlState::LEDSTATE_STANDBY: return "STANDBY";
                    case LEDControlState::LEDSTATE_WPS_CONNECTING: return "WPS_CONNECTING";
                    case LEDControlState::LEDSTATE_WPS_CONNECTED: return "WPS_CONNECTED";
                    case LEDControlState::LEDSTATE_WPS_ERROR: return "WPS_ERROR";
                    case LEDControlState::LEDSTATE_FACTORY_RESET: return "FACTORY_RESET";
                    case LEDControlState::LEDSTATE_USB_UPGRADE: return "USB_UPGRADE";
                    case LEDControlState::LEDSTATE_SOFTWARE_DOWNLOAD_ERROR: return "DOWNLOAD_ERROR";
                    default: return "UNKNOWN";
                }
            }

            static LEDControlState StringToLEDControlState(const std::string& str)
            {
                if (str == "NONE") return LEDControlState::LEDSTATE_NONE;
                if (str == "ACTIVE") return LEDControlState::LEDSTATE_ACTIVE;
                if (str == "STANDBY") return LEDControlState::LEDSTATE_STANDBY;
                if (str == "WPS_CONNECTING") return LEDControlState::LEDSTATE_WPS_CONNECTING;
                if (str == "WPS_CONNECTED") return LEDControlState::LEDSTATE_WPS_CONNECTED;
                if (str == "WPS_ERROR") return LEDControlState::LEDSTATE_WPS_ERROR;
                if (str == "FACTORY_RESET") return LEDControlState::LEDSTATE_FACTORY_RESET;
                if (str == "USB_UPGRADE") return LEDControlState::LEDSTATE_USB_UPGRADE;
                if (str == "DOWNLOAD_ERROR") return LEDControlState::LEDSTATE_SOFTWARE_DOWNLOAD_ERROR;
                return LEDControlState::LEDSTATE_UNKNOWN;
            }

            enum { ID = ID_LEDCONTROL };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            // @text getSupportedLEDStates
            // @brief Returns all the LED states supported by the platform
            // @param supportedLEDStates - out - string [] of supported LED states. e.g. "['NONE', 'ACTIVE', 'STANDBY']"
            // @param success - out - boolean
            virtual Core::hresult GetSupportedLEDStates(IStringIterator*& supportedLEDStates /* @out */, bool& success /* @out */) = 0;

            // @text getLEDState
            // @brief Returns current LED state. e.g. "ACTIVE"
            // @param state - out - LEDControlState
            virtual Core::hresult GetLEDState(LEDControlState& state /* @out */) = 0;

            // @text setLEDState
            // @brief Change the device LED state to one mentioned in the input argument.
            // @param state - in - LEDControlState. e.g. "FACTORY_RESET"
            // @param success - out - boolean
            virtual Core::hresult SetLEDState(const LEDControlState& state, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
