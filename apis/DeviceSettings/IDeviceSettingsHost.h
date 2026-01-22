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

    struct EXTERNAL IDeviceSettingsHost : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_HOST };

        enum SleepMode : uint8_t {
            DS_HOST_SLEEPMODE_LIGHT      = 0,
            DS_HOST_SLEEPMODE_DEEP       = 1,
            DS_HOST_SLEEPMODE_MAX        = 2
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_HOST_NOTIFICATION };

            // @brief Sleep mode changed
            // @text onSleepModeChanged
            // @param sleepMode: see SleepMode
            virtual void OnSleepModeChanged(const SleepMode sleepMode) {};
            
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsHost::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsHost::INotification* notification ) = 0;

        /** Get Preferred Sleep mode. */
        // @text getPreferredSleepMode
        // @brief Get Preferred Sleep mode.
        // @param mode: Sleep mode
        virtual Core::hresult GetPreferredSleepMode(SleepMode &mode /* @out */) = 0;

        /** Get Preferred Sleep mode. */
        // @text setPreferredSleepMode
        // @brief Set Preferred Sleep mode.
        // @param mode: Sleep mode
        virtual Core::hresult SetPreferredSleepMode(const SleepMode mode ) = 0;

        /** Get CPU temperature. */
        // @text getCPUTemperature
        // @brief Get CPU temperature.
        // @param temperature: temperature in degree centigrade?
        virtual Core::hresult GetCPUTemperature(float &temperature /* @out */) = 0;

        /** Get HAL Version . */
        // @text getHALVersion
        // @brief Get HAL Version.
        // @param versionNo: 16 bits MSB is major version and 16 bits LSB is minor version
        virtual Core::hresult GetHALVersion(uint32_t &versionNo /* @out */) = 0;

        /** Get SOCID. */
        // @text getSoCID
        // @brief Get SOCID.
        // @param socID: SOCID in string format
        virtual Core::hresult GetSoCID(string &socID /* @out */) = 0;

        /** Get EDID Bytes. */
        // @text getEDID
        // @brief Get EDID.
        // @param edId: EDID in bytes
        // @param edIdLength: number of bytes in edId array
        virtual Core::hresult GetEDID(uint8_t edId[] /* @out @length:edIdLength @maxlength:edIdLength */, const uint16_t edIdLength ) = 0;

        /** Get MS12 Config type. */
        // @text getMS12ConfigType
        // @brief Get MS12 Config
        // @param ms12Config: MS12 config type
        virtual Core::hresult GetMS12ConfigType(string &ms12Config /* @out */) = 0;

    };

} // namespace Exchange
} // namespace WPEFramework
