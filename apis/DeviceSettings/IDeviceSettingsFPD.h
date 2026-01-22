/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management.
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

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IDeviceSettingsFPD : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_FPD };

        enum FPDTimeFormat : uint8_t {
            DS_FPD_TIMEFORMAT_12_HOUR    = 0,
            DS_FPD_TIMEFORMAT_24_HOUR    = 1,
            DS_FPD_TIMEFORMAT_MAX        = 2
        };

        enum FPDIndicator : uint8_t {
            DS_FPD_INDICATOR_MESSAGE    = 0,
            DS_FPD_INDICATOR_POWER      = 1,
            DS_FPD_INDICATOR_RECORD     = 2,
            DS_FPD_INDICATOR_REMOTE     = 3,
            DS_FPD_INDICATOR_RFBYPASS   = 4,
            DS_FPD_INDICATOR_MAX        = 5
        };

        enum FPDState : uint8_t {
            DS_FPD_STATE_OFF        = 0,
            DS_FPD_STATE_ON         = 1,
            DS_FPD_STATE_MAX        = 2
        };

        enum FPDTextDisplay : uint8_t {
            DS_FPD_TEXTDISPLAY_TEXT        = 0,
            DS_FPD_TEXTDISPLAY_MAX         = 1
        };

        enum FPDMode : uint8_t {
            DS_FPD_MODE_ANY        = 0,
            DS_FPD_MODE_TEXT       = 1,
            DS_FPD_MODE_CLOCK      = 2,
            DS_FPD_MODE_MAX        = 3,
        };

        enum FDPLEDState: uint8_t {
            DS_FPD_LED_DEVICE_NONE              = 0,
            DS_FPD_LED_DEVICE_ACTIVE            = 1,
            DS_FPD_LED_DEVICE_STANDBY           = 2,
            DS_FPD_LED_DEVICE_WPS_CONNECTING    = 3,
            DS_FPD_LED_DEVICE_WPS_CONNECTED     = 4,
            DS_FPD_LED_DEVICE_WPS_ERROR         = 5,
            DS_FPD_LED_DEVICE_FACTORY_RESET     = 6,
            DS_FPD_LED_DEVICE_USB_UPGRADE       = 7,
            DS_FPD_LED_DEVICE_SW_UPGRADE_ERROR  = 8,
            DS_FPD_LED_DEVICE_MAX               = 9
        };
        

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_FPD_NOTIFICATION };

            // @brief On Front Panel display time format changed
            // @text OnFPDTimeFormatChanged
            // @param timeFormat: current time format 12 or 24 hour
            virtual void OnFPDTimeFormatChanged(const FPDTimeFormat timeFormat) {};
            
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsFPD::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsFPD::INotification* notification ) = 0;

        /** Set Front Panel Display Time. */
        // @text setFPDTime
        // @brief Set Front Panel Display Time.
        // @param timeFormat: Time format in 12 hour or 24 hour format
        // @param minutes: Minutes value to display
        // @param seconds: Seconds value to display
        virtual Core::hresult SetFPDTime(const FPDTimeFormat timeFormat , const uint32_t minutes , const uint32_t seconds ) = 0;

        /** Set Front Panel Display Scroll. */
        // @text setFPDScroll
        // @brief Set Front Panel Display Scroll.
        // @param scrollHoldDuration: Scroll hold duration
        // @param nHorizontalScrollIterations: number of horizontal scroll iterations
        // @param nVerticalScrollIterations: number of vertical scroll iterations
        virtual Core::hresult SetFPDScroll(const uint32_t scrollHoldDuration , const uint32_t nHorizontalScrollIterations , const uint32_t nVerticalScrollIterations ) = 0;

        /** Set Front Panel Display Blink. */
        // @text setFPDBlink
        // @brief Set Front Panel Display Blink.
        // @param indicator: Type of indicator
        // @param blinkDuration: Time in seconds for which the indictor has to be blinked
        // @param blinkIterations: number of times the blink has to be done for the blink duration
        virtual Core::hresult SetFPDBlink(const FPDIndicator indicator , const uint32_t blinkDuration , const uint32_t blinkIterations ) = 0;

        /** Set Front Panel Display Blink. */
        // @text setFPDBrightness
        // @brief Set Front Panel Display Blink.
        // @param indicator: Type of indicator
        // @param brightNess: brightness between 1 and 100 
        // @param persist: persist( true ) the brightness or not (false)
        virtual Core::hresult SetFPDBrightness(const FPDIndicator indicator , const uint32_t brightNess , const bool persist )  = 0;

        /** Get Front Panel Display Brightness. */
        // @text GetFPDBrightness
        // @brief Get Front Panel Display Brightness.
        // @param indicator: Type of indicator
        // @param brightNess: brightness between 1 and 100 
        virtual Core::hresult GetFPDBrightness(const FPDIndicator indicator , uint32_t &brightNess /* @out */)  = 0;

        /** Set Front Panel Display State. */
        // @text setFPDState
        // @brief Set Front Panel Display State.
        // @param indicator: Type of indicator
        // @param state: FPD State
        virtual Core::hresult SetFPDState(const FPDIndicator indicator , const FPDState state )  = 0;

        /** Get Front Panel Display State. */
        // @text getFPDState
        // @brief Get Front Panel Display State.
        // @param indicator: Type of indicator
        // @param state: FPD State
        virtual Core::hresult GetFPDState(const FPDIndicator indicator , FPDState &state /* @out */)  = 0;

        /** Get Front Panel Display Color. */
        // @text getFPDColor
        // @brief Get Front Panel Display Color.
        // @param indicator: Type of indicator
        // @param color: color
        virtual Core::hresult GetFPDColor(const FPDIndicator indicator , uint32_t &color /* @out */)  = 0;

        /** Set Front Panel Display Color. */
        // @text setFPDColor
        // @brief Set Front Panel Display State.
        // @param indicator: Type of indicator
        // @param color: color
        virtual Core::hresult SetFPDColor(const FPDIndicator indicator , const uint32_t color )  = 0;

        /** Set Front Panel Text Display (LED). */
        // @text setFPDTextBrightness
        // @brief Set Front Panel Text Display (LED).
        // @param textDisplay: Text display
        // @param brightNess: Brightness of the text display
        virtual Core::hresult SetFPDTextBrightness(const FPDTextDisplay textDisplay , const uint32_t brightNess )  = 0;
       
        /** Get Front Panel Text Display (LED). */
        // @text getFPDTextBrightness
        // @brief Get Front Panel Text Display (LED).
        // @param textDisplay: Text display
        // @param brightNess: Brightness of the text display
        virtual Core::hresult GetFPDTextBrightness(const FPDTextDisplay textDisplay , uint32_t &brightNess /* @out */)  = 0;

        /** Enable Front Panel Clock display. */
        // @text enableFPDClockDisplay
        // @brief Enable Front Panel Clock display.
        // @param enable: enable (true) or disable (false) clock display
        virtual Core::hresult EnableFPDClockDisplay(const bool enable )  = 0;

        /** Get Front Panel Display Time format. */
        // @text getFPDTimeFormat
        // @brief Get Front Panel Display Time format.
        // @param fpdTimeFormat: 12 or 24 hour format
        virtual Core::hresult GetFPDTimeFormat(FPDTimeFormat &fpdTimeFormat /* @out */)  = 0;

        /** Set Front Panel Display Time format. */
        // @text setFPDTimeFormat
        // @brief Set Front Panel Display Time format.
        // @param fpdTimeFormat: 12 or 24 hour format
        virtual Core::hresult SetFPDTimeFormat(const FPDTimeFormat fpdTimeFormat )  = 0;

        /** Set Front Panel Display Mode. */
        // @text setFPDMode
        // @brief Set Front Panel Display Mode.
        // @param fpdMode: FPD Mode
        virtual Core::hresult SetFPDMode(const FPDMode fpdMode )  = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
