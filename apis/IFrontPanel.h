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

            // @text getBrightness
            // @brief Gets the status of the Front Panel
            // @details Retrieves the current brightness level associated with the specified brightness index.
            // @param[in] index Index of the brightness level to retrieve.
            // @param[out] brightness Current brightness level.
            // @param[out] success Indicates whether the brightness was retrieved successfully.
            // @example index: "power"
            // @example brightness: 100
            // @example success: true
            // @retval Core::ERROR_NONE The brightness level was retrieved successfully.
            // @retval Core::ERROR_GENERAL The brightness level could not be retrieved.
            virtual Core::hresult GetBrightness(const string& index, uint32_t &brightness /* @out */, bool &success /* @out */) = 0;

            // @text getFrontPanelLights
            // @brief Gets the front panel lights
            // @details Retrieves the list of supported Front Panel lights and additional information describing those lights.
            // @param[out] supportedLights Iterator containing the supported Front Panel lights.
            // @param[out] supportedLightsInfo Additional information about the supported lights.
            // @param[out] success Indicates whether the list was retrieved successfully.
            // @example supportedLights: ["power", "recording"]
            // @example supportedLightsInfo: ["power", "Power LED"]
            // @example success: true
            // @retval Core::ERROR_NONE The supported Front Panel lights were retrieved successfully.
            // @retval Core::ERROR_GENERAL The supported Front Panel lights could not be retrieved.
            virtual Core::hresult GetFrontPanelLights(IFrontPanelLightsListIterator*& supportedLights /* @out */, string &supportedLightsInfo /* @out @opaque */, bool &success /* @out */) = 0;

            // @text powerLedOff
            // @brief Switches the specified LED off
            // @details Turns off the LED identified by the supplied indicator index.
            // @param[in] index Index of the LED to switch off.
            // @param[out] success Result indicating whether the LED was switched off.
            // @example index: "power"
            // @example success: true
            // @retval Core::ERROR_NONE The LED was switched off successfully.
            // @retval Core::ERROR_GENERAL The LED could not be switched off.
            virtual Core::hresult PowerLedOff(const string& index, FrontPanelSuccess &success /* @out */) = 0;

            // @text powerLedOn
            // @brief Switches the specified LED on
            // @details Turns on the LED identified by the supplied indicator index.
            // @param[in] index Index of the LED to switch on.
            // @param[out] success Result indicating whether the LED was switched on.
            // @example index: "power"
            // @example success: true
            // @retval Core::ERROR_NONE The LED was switched on successfully.
            // @retval Core::ERROR_GENERAL The LED could not be switched on.
            virtual Core::hresult PowerLedOn(const string& index, FrontPanelSuccess &success /* @out */) = 0;

            // @text setBlink
            // @brief Sets a blink pattern for the specified LED. The blinkInfo parameter is a JSON string containing: ledIndicator (string) 
            // @details Applies the blinking pattern described by the JSON input. The pattern includes the LED indicator, iteration count, and brightness and duration values. Optional color components may also be specified.
            // @param[in] blinkInfo: JSON string with blink pattern information containing ledIndicator, iterations, and pattern array with brightness, duration(milliseconds), and optional color and red/green/blue values.
            // @param[out] success: Is the operation successful or not
            // @example blinkInfo: "{\"ledIndicator\":\"power\",\"iterations\":3,\"pattern\":[{\"brightness\":100,\"duration\":500}]}"
            // @example blinkInfo: "{\"ledIndicator\":\"status\",\"iterations\":5,\"pattern\":[{\"brightness\":100,\"duration\":1000,\"color\":\"green\"}]}"
            // @example blinkInfo: "{\"ledIndicator\":\"power\",\"iterations\":2,\"pattern\":[{\"brightness\":100,\"duration\":1000,\"red\":255,\"green\":0,\"blue\":0}]}"
            // @example success.success: true
            // @retval Core::ERROR_NONE The blinking pattern was set successfully.
            // @retval Core::ERROR_GENERAL The blinking pattern could not be set.
            virtual Core::hresult SetBlink(const string& blinkInfo /* @opaque */, FrontPanelSuccess &success /* @out */) = 0;

            // @text setBrightness
            // @brief Sets the brightness of the specified LED
            // @details Sets the requested brightness value for the LED identified by the supplied index.
            // @param[in] index Index of the brightness level or LED.
            // @param[in] brightness Brightness level to set.
            // @param[out] success Result indicating whether the brightness was set.
            // @example index: "power"
            // @example brightness: 75
            // @example success.success: true
            // @retval Core::ERROR_NONE The LED brightness was set successfully.
            // @retval Core::ERROR_GENERAL The LED brightness could not be set.
            virtual Core::hresult SetBrightness(const string& index, const uint32_t brightness, FrontPanelSuccess &success /* @out */) = 0;

            // @text setLED
            // @brief Sets the LED with the specified color and brightness
            // @details Configures the selected LED using the supplied brightness, color name, and red, green, and blue color component values.
            // @param[in] ledIndicator LED indicator to configure.
            // @param[in] brightness Brightness level of the LED.
            // @param[in] color Color name to apply to the LED.
            // @param[in] red Red color component value.
            // @param[in] green Green color component value.
            // @param[in] blue Blue color component value.
            // @param[out] success Result indicating whether the LED configuration was applied.
            // @example ledIndicator: "power"
            // @example brightness: 100
            // @example color: "white"
            // @example red: 255
            // @example green: 255
            // @example blue: 255
            // @example success.success: true
            // @retval Core::ERROR_NONE The LED color and brightness were set successfully.
            // @retval Core::ERROR_GENERAL The LED color and brightness could not be set.
            virtual Core::hresult SetLED(const string& ledIndicator, const uint32_t brightness, const string& color, const uint32_t red, const uint32_t green, const uint32_t blue, FrontPanelSuccess &success /* @out */) = 0;

        };
} // namespace Exchange
} // namespace WPEFramework
