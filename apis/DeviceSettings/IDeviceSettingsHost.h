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

        /** Get EDID Bytes. */
        // @text getEDID
        // @brief Get EDID.
        // @details Retrieves the raw EDID byte sequence reported by the host display device.
        // @param edId: EDID in bytes
        // @example edId: [0, 255, 255, 255, 255, 255, 255, 0]
        // @param edIdLength: number of bytes in edId array
        // @example edIdLength: 128
        // @retval Core::ERROR_NONE: EDID bytes were retrieved successfully
        virtual Core::hresult GetEDID(uint8_t edId[] /* @out @length:edIdLength @maxlength:edIdLength */, const uint16_t edIdLength ) = 0;

        /** Get MS12 Config type. */
        // @text getMS12ConfigType
        // @brief Get MS12 Config
        // @details Retrieves the MS12 configuration type used by the host audio implementation.
        // @param ms12Config: MS12 config type
        // @example ms12Config: "MS12"
        // @retval Core::ERROR_NONE: MS12 configuration type was retrieved successfully
        virtual Core::hresult GetMS12ConfigType(string &ms12Config /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
