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
        // @json @text:keep
        struct EXTERNAL IFrontPanel : virtual public Core::IUnknown {
            enum { ID = ID_HDMI_CEC_SOURCE };


            struct EXTERNAL FrontPanelSuccess {
                bool success;
            };

            struct FrontPanelPattern{
                uint32_t brightness;
                uint32_t duration;
                string color;
                uint32_t red;
                uint32_t green;
                uint32_t blue;
            };


            struct FrontPanelBlinkInfo{
                string ledIndiciator;
                uint32_t iterations;
                std::vector<FrontPanelPattern> pattern;
            };

            using IFrontPanelLightsListIterator = RPC::IIteratorType<string, ID_FRONT_PANEL_LIGHTS_LIST_ITERATOR>;
            using IFrontPanelBlinkInfoListIterator = RPC::IIteratorType<FrontPanelBlinkInfo, ID_FRONT_PANEL_BLINK_INFO_LIST_ITERATOR>;



            // @json:omit
            virtual Core::hresult Register() = 0;
            // @json:omit
            virtual Core::hresult Unregister() = 0;
            // @json:omit
            virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

            // @brief Gets the status of the Front Panel
            // @text getBrightness
            // @param index: Index of the brightness level
            // @param brightness: Brightness level
            // @param success: Is the operation successful or not
            virtual Core::hresult GetBrightness(const string &index /* @in */, int32_t &brightness /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the clock brightness of the Front Panel
            // @text getClockBrightness
            // @param brightness: Brightness level of the clock
            // @param success: Is the operation successful or not
            virtual Core::hresult GetClockBrightness(uint32_t &brightness /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the front panel lights
            // @text getFrontPanelLights
            // @param supportedLights: List of supported front panel lights
            // @param supportedLightsInfo: Information about the supported front panel lights
            // @param success: Is the operation successful or not
            virtual Core::hresult GetFrontPanelLights(IFrontPanelLightsListIterator &supportedLights /* @out */, string &supportedLightsInfo /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the front panel light preferences
            // @text getPreferences
            // @param preferences: Preferences of the front panel lights
            // @param success: Is the operation successful or not
            virtual Core::hresult GetPreferences(string &preferences /* @out */, bool &success /* @out */) = 0;

            // @brief Gets whether clock is 24 hour format or not
            // @text is24HourClock
            // @param is24Hour: Is the clock in 24 hour format or not
            // @param success: Is the operation successful or not
            virtual Core::hresult Is24HourClock(bool &is24Hour /* @out */, bool &success /* @out */) = 0;

            // @brief Switches the specified LED off
            // @text powerLedOff
            // @param index: Index of the LED to switch off
            // @param success: Is the operation successful or not
            virtual Core::hresult PowerLedOff(const string &index /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Switches the specified LED on
            // @text powerLedOn
            // @param index: Index of the LED to switch on
            // @param success: Is the operation successful or not
            virtual Core::hresult PowerLedOn(const string &index /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets whether the clock is in 24 hour format or not
            // @text set24HourClock
            // @param is24Hour: Is the clock in 24 hour format or not
            // @param success: Is the operation successful or not
            virtual Core::hresult Set24HourClock(const bool &is24Hour /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the blink pattern for the specified LED
            // @text setBlink
            // @param blinkInfo: Information about the blink pattern @see FrontPanelBlinkInfo
            // @param success: Is the operation successful or not
            virtual Core::hresult SetBlink(const FrontPanelBlinkInfo &blinkInfo /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the brightness of the specified LED
            // @text setBrightness
            // @param index: Index of the brightness level
            // @param brightness: Brightness level to set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetBrightness(const string &index /* @in */, const int32_t &brightness /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the clock brightness of the Front Panel
            // @text setClockBrightness
            // @param brightness: Brightness level of the clock to set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetClockBrightness(const uint32_t &brightness /* @in */, FrontPanelSuccess &success /* @out */) = 0;


            // @brief Allows you to set a test pattern on the STB clock (88 88).
            // @text setClockTestPattern
            // @param show: Whether to show the test pattern or not
            // @param timeInterval: Time interval in milliseconds for which the test pattern should be shown
            // @param success: Is the operation successful or not
            virtual Core::hresult SetClockTestPattern(const bool &show /* @in */, const uint32_t &timeInterval /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the LED with the specified color and brightness
            // @text setLED
            // @param ledIndiciator: LED indicator to set
            // @param brightness: Brightness level of the LED
            // @param red: Red component of the LED color
            // @param green: Green component of the LED color
            // @param blue: Blue component of the LED color
            // @param success: Is the operation successful or not
            virtual Core::hresult SetLED(const string &ledIndiciator /* @in */, const uint32_t &brightness /* @in */, const uint32_t &red /* @in */, const uint32_t &green /* @in */, const uint32_t &blue /* @in */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the preferences for the front panel lights
            // @text setPreferences
            // @param preferences: Preferences of the front panel lights
            // @param success: Is the operation successful or not
            virtual Core::hresult SetPreferences(const string &preferences /* @in */, FrontPanelSuccess &success /* @out */) = 0;


        };
} // namespace Exchange
} // namespace WPEFramework
