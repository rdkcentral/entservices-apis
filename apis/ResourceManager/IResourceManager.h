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

            // Define string iterator for ResourceManager
            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            // Result struct for SetAVBlocked operation
            struct EXTERNAL SetAVBlockedResult {
                bool success;
            };

            // Result struct for TTS operations
            struct EXTERNAL TTSResult {
                bool success;
            };

            /**********************setAVBlocked() - start****************************/
            // @text setAVBlocked
            // @brief Sets AV blocking status for an application
            // @param appId - in - string
            // @param blocked - in - bool
            // @param result - out - SetAVBlockedResult
            virtual Core::hresult SetAVBlocked(const string& appId, const bool blocked, SetAVBlockedResult& result /* @out */) = 0;
            /**********************setAVBlocked() - end******************************/

            /**********************getBlockedAVApplications() - start***************/
            // @text getBlockedAVApplications  
            // @brief Gets list of applications with blocked AV access
            // @param clients: list of blocked applications
            // @param success: success status
            virtual Core::hresult GetBlockedAVApplications(IStringIterator*& clients /* @out */, bool& success /* @out */) const = 0;
            /**********************getBlockedAVApplications() - end*****************/

            /**********************reserveTTSResource() - start*********************/
            // @text reserveTTSResource
            // @brief Reserves TTS resource for a single application
            // @param appId - in - string
            // @param ttsResult - out - TTSResult
            virtual Core::hresult ReserveTTSResource(const string& appId, TTSResult& ttsResult /* @out */) = 0;
            /**********************reserveTTSResource() - end***********************/

            /**********************reserveTTSResourceForApps() - start***************/
            // @text reserveTTSResourceForApps
            // @brief Reserves TTS resource for multiple applications
            // @param appids: list of application IDs
            // @param ttsResult: result of the TTS reservation
            virtual Core::hresult ReserveTTSResourceForApps(IStringIterator* const appids, TTSResult& ttsResult /* @out */) = 0;
            /**********************reserveTTSResourceForApps() - end*****************/
        };
    } // namespace Exchange
} // namespace WPEFramework