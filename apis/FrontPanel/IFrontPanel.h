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
        // @json @text:keep
        struct EXTERNAL IFrontPanel : virtual public Core::IUnknown {
            enum { ID = ID_FRONT_PANEL };


            struct EXTERNAL FrontPanelSuccess {
                bool success;
            };

            using IFrontPanelLightsListIterator = RPC::IIteratorType<string, ID_FRONT_PANEL_LIGHTS_LIST_ITERATOR>;

            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the status of the Front Panel
            // @text getBrightness
            // @param index: Index of the brightness level
            // @param brightness: Brightness level
            // @param success: Is the operation successful or not
            virtual Core::hresult GetBrightness(const string &index, int32_t &brightness /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the front panel lights
            // @text getFrontPanelLights
            // @param supportedLights: List of supported front panel lights
            // @param supportedLightsInfo: Information about the supported front panel lights
            // @param success: Is the operation successful or not
            virtual Core::hresult GetFrontPanelLights(IFrontPanelLightsListIterator*& supportedLights /* @out */, string &supportedLightsInfo /* @out @opaque */, bool &success /* @out */) = 0;

            // @brief Switches the specified LED off
            // @text powerLedOff
            // @param index: Index of the LED to switch off
            // @param success: Is the operation successful or not
            virtual Core::hresult PowerLedOff(const string &index, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Switches the specified LED on
            // @text powerLedOn
            // @param index: Index of the LED to switch on
            // @param success: Is the operation successful or not
            virtual Core::hresult PowerLedOn(const string &index, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the blink pattern for the specified LED
            // @text setBlink
            // @param blinkInfo: Information about the blink pattern @see FrontPanelBlinkInfo
            // @param success: Is the operation successful or not
            virtual Core::hresult SetBlink(const string &blinkInfo /* @opaque */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the brightness of the specified LED
            // @text setBrightness
            // @param index: Index of the brightness level
            // @param brightness: Brightness level to set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetBrightness(const string &index, const int32_t &brightness, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the LED with the specified color and brightness
            // @text setLED
            // @param ledIndiciator: LED indicator to set
            // @param brightness: Brightness level of the LED
            // @param color: Color of the LED
            // @param red: Red component of the LED color
            // @param green: Green component of the LED color
            // @param blue: Blue component of the LED color
            // @param success: Is the operation successful or not
            virtual Core::hresult SetLED(const string &ledIndiciator, const uint32_t &brightness, const string& color, const uint32_t &red, const uint32_t &green, const uint32_t &blue, FrontPanelSuccess &success /* @out */) = 0;

        };
} // namespace Exchange
} // namespace WPEFramework
