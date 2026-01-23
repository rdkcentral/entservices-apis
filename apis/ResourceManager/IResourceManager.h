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

            // @brief Define custom iterators for ResourceManager
            using IClientIterator = RPC::IIteratorType<string, ID_RESOURCEMANAGER_CLIENT_ITERATOR>;
            using IAppIdIterator = RPC::IIteratorType<string, ID_RESOURCEMANAGER_APPID_ITERATOR>;

            // @brief Result struct for TTS operations
            struct EXTERNAL TTSResult {
                bool success /* @text success */ /* @brief Indicates whether the TTS operation was successful */;
            };

            /**********************setAVBlocked() - start****************************/
            // @text setAVBlocked
            // @brief Sets AV blocking status for an application
            // @param appId: The unique identifier of the application
            // @param blocked: Boolean flag indicating whether to block (true) or unblock (false) AV access
            // @param message: Status or error message describing the result of the operation
            // @param success: Boolean flag indicating whether the operation was successful
            // @retval ERROR_NONE: Operation completed successfully
            // @retval ERROR_GENERAL: Operation failed
            virtual Core::hresult SetAVBlocked(const string& appId /* @text appId */, const bool blocked /* @text blocked */, string& message /* @out */, bool& success /* @out */) = 0;
            /**********************setAVBlocked() - end******************************/

            /**********************getBlockedAVApplications() - start***************/
            // @text getBlockedAVApplications  
            // @brief Gets list of applications with blocked AV access
            // @param clients: Iterator containing the list of application identifiers that have blocked AV access
            // @param success: Boolean flag indicating whether the operation was successful
            // @retval ERROR_NONE: Operation completed successfully
            // @retval ERROR_GENERAL: Operation failed
            virtual Core::hresult GetBlockedAVApplications(IClientIterator*& clients /* @out */, bool& success /* @out */) const = 0;
            /**********************getBlockedAVApplications() - end*****************/

            /**********************reserveTTSResource() - start*********************/
            // @text reserveTTSResource
            // @brief Reserves TTS resource for a single application
            // @param appId: The unique identifier of the application requesting TTS resource reservation
            // @param ttsResult: Structure containing the result of the TTS resource reservation operation
            // @retval ERROR_NONE: Operation completed successfully
            // @retval ERROR_GENERAL: Operation failed
            virtual Core::hresult ReserveTTSResource(const string& appId /* @text appId */, TTSResult& ttsResult /* @out */) = 0;
            /**********************reserveTTSResource() - end***********************/

            /**********************reserveTTSResourceForApps() - start***************/
            // @text reserveTTSResourceForApps
            // @brief Reserves TTS resource for multiple applications
            // @param appIds: Iterator containing the list of application identifiers requesting TTS resource reservation
            // @param ttsResult: Structure containing the result of the TTS resource reservation operation
            // @retval ERROR_NONE: Operation completed successfully
            // @retval ERROR_GENERAL: Operation failed
            virtual Core::hresult ReserveTTSResourceForApps(IAppIdIterator* const appIds /* @text appIds */, TTSResult& ttsResult /* @out */) = 0;
            /**********************reserveTTSResourceForApps() - end*****************/
        };
    } // namespace Exchange
} // namespace WPEFramework