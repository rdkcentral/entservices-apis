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
            // @details Provides the current active brightness state or percentage value configured for the device display panel.
            // @param index: Index of the brightness level
            // @example index: "0"
            // @param brightness: Brightness level
            // @example brightness: 100
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetBrightness(const string& index, uint32_t &brightness /* @out */, bool &success /* @out */) = 0;

            // @brief Gets the front panel lights
            // @text getFrontPanelLights
            // @details Provides a list or status bitmask of the active illumination nodes present on the physical display facade of the device.
            // @param supportedLights: List of supported front panel lights
            // @example supportedLights: ["POWER_LED", "STATUS_LED"]
            // @param supportedLightsInfo: Information about the supported front panel lights
            // @example supportedLightsInfo: "The front panel supports POWER_LED and STATUS_LED."
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetFrontPanelLights(IFrontPanelLightsListIterator*& supportedLights /* @out */, string &supportedLightsInfo /* @out @opaque */, bool &success /* @out */) = 0;

            // @brief Switches the specified LED off
            // @text powerLedOff
            // @details Cuts power or disables illumination for the specified light source on the device facade using its identifier.
            // @param index: Index of the LED to switch off
            // @example index: "0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult PowerLedOff(const string& index, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Switches the specified LED on
            // @text powerLedOn
            // @details Applies power or enables illumination for the specified light source on the device facade using its identifier.
            // @param index: Index of the LED to switch on
            // @example index: "0"
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult PowerLedOn(const string& index, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) 
            // @text setBlink
            // @details Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) - the LED indicator to set, iterations (integer) - the number of times to repeat the pattern, and pattern (array of objects) - each object contains brightness (integer), duration (integer in milliseconds), and optional color (string) and red/green/blue (integers) values.
            // @param blinkInfo: JSON string with blink pattern information containing ledIndicator, iterations, and pattern array with brightness, duration(milliseconds), and optional color and red/green/blue values.
            // @example blinkInfo: {"ledIndicator": "POWER_LED", "iterations": 3, "pattern": [{"brightness": 100, "duration": 500}, {"brightness": 0, "duration": 500}]}
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetBlink(const string& blinkInfo /* @opaque */, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the brightness of the specified LED
            // @text setBrightness
            // @details Adjusts the intensity of the light source corresponding to the provided index using a percentage or discrete scale value.
            // @param index: Index of the brightness level
            // @example index: "0"
            // @param brightness: Brightness level to set
            // @example brightness: 100
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetBrightness(const string& index, const uint32_t brightness, FrontPanelSuccess &success /* @out */) = 0;

            // @brief Sets the LED with the specified color and brightness
            // @text setLED
            // @details Configures the specified LED on the device facade with the provided color and brightness settings.
            // @param ledIndicator: LED indicator to set
            // @example ledIndicator: "POWER_LED"
            // @param brightness: Brightness level of the LED
            // @example brightness: 100
            // @param color: Color of the LED
            // @example color: "red"
            // @param red: Red component of the LED color
            // @example red: 255
            // @param green: Green component of the LED color
            // @example green: 0
            // @param blue: Blue component of the LED color
            // @example blue: 0
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetLED(const string& ledIndicator, const uint32_t brightness, const string& color, const uint32_t red, const uint32_t green, const uint32_t blue, FrontPanelSuccess &success /* @out */) = 0;

        };
} // namespace Exchange
} // namespace WPEFramework
