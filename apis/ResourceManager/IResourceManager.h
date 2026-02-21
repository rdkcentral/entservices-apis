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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IResourceManager : virtual public Core::IUnknown
        {
            enum { ID = ID_RESOURCEMANAGER };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            struct EXTERNAL Success {
                bool success;
            };

            /** Sets AV blocking status for an application */
            // @text setAVBlocked
            // @brief Adds/removes the application with the given callsign to/from the AV blacklist
            // @param appId - in - string
            // @param blocked - in - boolean
            // @param result - out - Success
            virtual Core::hresult SetAVBlocked(const string& appId, const bool blocked, Success& result /* @out */) = 0;

            /** Gets a list of blacklisted clients */
            // @text getBlockedAVApplications
            // @brief Gets a list of blacklisted clients
            // @param clients - out - IStringIterator
            // @param success - out - boolean
            virtual Core::hresult GetBlockedAVApplications(IStringIterator*& clients /* @out */, bool& success /* @out */) const = 0;

            /** Reserves the Text To Speech resource for a specified client */
            // @text reserveTTSResource
            // @brief Reserves the Text To Speech resource for a specified client
            // @param appId - in - string
            // @param result - out - Success
            virtual Core::hresult ReserveTTSResource(const string& appId, Success& result /* @out */) = 0;

            /** Reserves the Text To Speech resource for specified clients */
            // @text reserveTTSResourceForApps
            // @brief Reserves the Text To Speech resource for specified clients
            // @param appids - in - IStringIterator
            // @param result - out - Success
            virtual Core::hresult ReserveTTSResourceForApps(IStringIterator* const appids, Success& result /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework