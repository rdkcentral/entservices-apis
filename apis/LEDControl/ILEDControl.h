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

            virtual ~ILEDControl() = default;

            enum LEDControlState : uint8_t {
                LEDSTATE_NONE = 0,       /* @text NONE @brief TRISTATE or not in a defined state */
                LEDSTATE_ACTIVE,         /* @text ACTIVE @brief Indicates Active power state */
                LEDSTATE_STANDBY,        /* @text STANDBY @brief Indicates Standby power state */
                LEDSTATE_WPS_CONNECTING, /* @text WPS_CONNECTING @brief Indicates WPS Connecting */
                LEDSTATE_WPS_CONNECTED,  /* @text WPS_CONNECTED @brief Indicates WPS Connected */
                LEDSTATE_WPS_ERROR,      /* @text WPS_ERROR @brief Indicates WPS Error */
                LEDSTATE_FACTORY_RESET,  /* @text FACTORY_RESET @brief Indicates Factory Reset */
                LEDSTATE_USB_UPGRADE,    /* @text USB_UPGRADE @brief Indicates USB Upgrade */
                LEDSTATE_DOWNLOAD_ERROR, /* @text DOWNLOAD_ERROR @brief Indicates Software Download Error */
                LEDSTATE_MAX             /* @text MAX @brief Indicates Maximum State */
            };

            // @text getSupportedLEDStates
            // @details Returns the list of LED states that are actually supported by the platform at runtime. Possible values include `NONE`, `ACTIVE`, `STANDBY`, `WPS_CONNECTING`, `WPS_CONNECTED`, `WPS_ERROR`, `FACTORY_RESET`, `USB_UPGRADE` and `DOWNLOAD_ERROR`.
            // @param supportedLEDStates: string [] of supported LED states. e.g. "['ACTIVE', 'STANDBY', 'WPS_CONNECTING', 'WPS_CONNECTED', 'WPS_ERROR', 'FACTORY_RESET', 'USB_UPGRADE', 'DOWNLOAD_ERROR']"
            // @param success: boolean
            virtual Core::hresult GetSupportedLEDStates(IStringIterator*& supportedLEDStates /* @out */, bool& success /* @out */) = 0;

            // @text getLEDState
            // @brief Retrieves current state of the LED. e.g. "WPS_CONNECTING"
            // @param state: LEDControlState
            virtual Core::hresult GetLEDState(LEDControlState& state /* @out */) = 0;

            // @text setLEDState
            // @brief Changes the device LED state to mentioned input state.
            // @param state: LEDControlState. e.g. "FACTORY_RESET"
            // @param success: boolean
            virtual Core::hresult SetLEDState(const LEDControlState& state, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
