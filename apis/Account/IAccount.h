/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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
    // Account Plugin provides various operations that can be made at account level
    // @json 1.0.0 @text:keep
    struct EXTERNAL IAccount : virtual public Core::IUnknown {
        enum { ID = ID_ACCOUNT };

        virtual ~IAccount() = default;

        // @text getLastCheckoutResetTime
        // @brief Gets the last reset time for Hotel Checkout.
        // @param resetTime: Time in UTC. Returns 0, if time is not available.
        virtual Core::hresult GetLastCheckoutResetTime(uint64_t& resetTime /* @out */) = 0;

        // @text setLastCheckoutResetTime
        // @brief Sets the last reset time for Hotel Checkout.
        // @param resetTime: Time in UTC.
        virtual Core::hresult SetLastCheckoutResetTime(const uint64_t resetTime) const = 0;

    };
}
}

