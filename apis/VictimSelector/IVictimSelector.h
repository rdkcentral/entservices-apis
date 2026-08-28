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

// @jsonrpc VictimSelector
// @json 1.0.0 @text:keep
struct EXTERNAL IVictimSelector : virtual public Core::IUnknown {
    enum { ID = ID_VICTIM_SELECTOR };

    enum EvictionReason : uint8_t {
        EVICTION_REASON_RAM   = 0 /* @text RAM */,
        EVICTION_REASON_GPU   = 1 /* @text GPU */,
        EVICTION_REASON_FLASH = 2 /* @text FLASH */
    };

    enum EvictionType : uint8_t {
        EVICTION_TYPE_HARD = 0 /* @text HARD */,
        EVICTION_TYPE_SOFT = 1 /* @text SOFT */
    };

    enum EvictErrorReason : uint8_t {
        EVICT_ERROR_NONE             = 0 /* @text NONE */,
        EVICT_ERROR_NO_CANDIDATE_FOUND = 1 /* @text NO_CANDIDATE_FOUND */,
        EVICT_ERROR_TERMINATION_FAILED = 2 /* @text TERMINATION_FAILED */,
        EVICT_ERROR_TIMEOUT            = 3 /* @text TIMEOUT */
    };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_VICTIM_SELECTOR_NOTIFICATION };

        // @text onEvictComplete
        // @brief Triggered when eviction is complete.
        // @param evicted True when an application was evicted.
        // @param errorCode Error code when an application could not be evicted.
        virtual void OnEvictComplete(const bool evicted, const EvictErrorReason errorCode) {}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification* notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification* notification) = 0;

    // @text evict
    // @brief Determines the best application to terminate using the app priority algorithm.
    // @param reason Resource requiring eviction: RAM, GPU, or FLASH.
    // @param type Eviction type: HARD or SOFT.
    virtual Core::hresult Evict(const EvictionReason reason, const EvictionType type) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
