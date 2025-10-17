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

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IFbSettings : virtual public Core::IUnknown {
        enum { ID = ID_FBSETTINGS };

        virtual ~IFbSettings() override = default;

        // @text SetName
        // @brief Set the name
        // @param value: the name value to set
        // @returns Core::hresult
        virtual Core::hresult SetName(const string& value  /* @in */, string& result /* @out @opaque*/) = 0;


        // @text AddAdditionalInfo
        // @brief Add additional info in opaque format
        // @param value: the additional info in opaque format
        // @returns Core::hresult
        virtual Core::hresult AddAdditionalInfo(const string& value  /* @in @opaque */, string& result /* @out @opaque*/) = 0;

        
        // @text getDeviceMake
        // @brief Retrieve the device manufacturer or make.
        // @param make: Output string receiving the device make.
        // @returns Core::hresult
        virtual Core::hresult GetDeviceMake(string& make /* @out */) = 0;

        // @text getDeviceName
        // @brief Retrieve the device friendly name.
        // @param name: Output string receiving the device friendly name.
        // @returns Core::hresult
        virtual Core::hresult GetDeviceName(string& name /* @out */) = 0;

        // @text setDeviceName
        // @brief Set the device friendly name.
        // @param name: New device friendly name.
        // @returns Core::hresult
        virtual Core::hresult SetDeviceName(const string name) = 0;

        // @text getDeviceSku
        // @brief Retrieve the device SKU.
        // @param sku: Output string receiving the device SKU.
        // @returns Core::hresult
        virtual Core::hresult GetDeviceSku(string& sku /* @out */) = 0;

        // @text getCountryCode
        // @brief Retrieve the device country code.
        // @param countryCode: Output string receiving the country code.
        // @returns Core::hresult
        virtual Core::hresult GetCountryCode(string& countryCode /* @out */) = 0;

        // @text setCountryCode
        // @brief Set the device country code.
        // @param countryCode: New device country code.
        // @returns Core::hresult
        virtual Core::hresult SetCountryCode(const string countryCode) = 0;

        // @text getTimeZone
        // @brief Retrieve the device time zone identifier.
        // @param timeZone: Output string receiving the time zone.
        // @returns Core::hresult
        virtual Core::hresult GetTimeZone(string& timeZone /* @out */) = 0;

        // @text setTimeZone
        // @brief Set the device time zone identifier.
        // @param timeZone: New device time zone.
        // @returns Core::hresult
        virtual Core::hresult SetTimeZone(const string timeZone) = 0;

        // @text getSecondScreenFriendlyName
        // @brief Retrieve the second screen friendly name.
        // @param name: Output string receiving the second screen friendly name.
        // @returns Core::hresult
        virtual Core::hresult GetSecondScreenFriendlyName(string& name /* @out */) = 0;

    };

} // namespace Exchange
} // namespace WPEFramework
