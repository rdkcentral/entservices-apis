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

namespace WPEFramework {
namespace Exchange {
    // @json 1.0.0 @text:keep
    struct EXTERNAL IAnalytics : virtual public Core::IUnknown {
        enum { ID = ID_ANALYTICS };

        virtual ~IAnalytics() = default;

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;


        // @alt sendEvent
        // @brief Send an event to the analytics server
        // @details Sends an analytics event along with its metadata, timestamps, application identifier, payload, CET information, and optional contextual data. The event is forwarded to the Analytics service for processing and delivery to the configured analytics backend.
        // @param eventName: Name of the event
        // @param eventVersion: Version of the event
        // @param eventSource: Source of the event
        // @param eventSourceVersion: Version of the event source
        // @param cetList: List of CETs
        // @param epochTimestamp: Epoch timestamp of the event
        // @param uptimeTimestamp: Uptime timestamp of the event
        // @param appId: Durable App Id string
        // @param eventPayload: Payload of the event
        // @param additionalContext: Additional context for the event
        // @example eventName: "playback_started"
        // @example eventVersion: "1.0.0"
        // @example eventSource: "player_component"
        // @example eventSourceVersion: "2.1.0"
        // @example cetList: ["CET_01", "CET_02"]
        // @example epochTimestamp: 1719824400
        // @example uptimeTimestamp: 3600
        // @example appId: "com.comcast.xr11"
        // @example eventPayload: "{\"bitrate\":5000,\"codec\":\"h264\"}"
        // @example additionalContext: "{\"networkType\":\"ethernet\"}"
        // @retval Core::ERROR_NONE: Event was accepted and successfully queued for processing by the Analytics service.
        // @retval Core::ERROR_GENERAL: Event submission failed due to an internal service error.
        virtual Core::hresult SendEvent(const string& eventName,
                                   const string& eventVersion,
                                   const string& eventSource,
                                   const string& eventSourceVersion,
                                   IStringIterator* const& cetList,
                                   const uint64_t epochTimestamp,
                                   const uint64_t uptimeTimestamp,
                                   const string& appId,
                                   const string& eventPayload,
                                   const string& additionalContext /* @opaque */) = 0;
    };
}
}
