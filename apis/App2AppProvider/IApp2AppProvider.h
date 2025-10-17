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

namespace WPEFramework
{
    namespace Exchange
    {
        // @json 1.0.0 @text:keep
        struct EXTERNAL IApp2AppProvider : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP2APP_PROVIDER
            };

            struct Context
            {
                int requestId;       // @brief Unique identifier for the request.
                uint32_t connectionId; // @brief connectionId for the execution/session context.
                string appId;        // @brief Application identifier (Firebolt appId).
                string origin;      // @brief Origin of the request (e.g., org.rdk.AppGateway or org.rdk.LaunchDelegate).
            };

            // @text registerProvider
            // @brief Registers a provider for a given capability
            // @param context: Execution context containing requestId, connectionId, appId
            // @param register: true to register, false to unregister
            // @param capability: Firebolt Provider Method name
            // @returns Core::hresult
            virtual Core::hresult RegisterProvider(const Context &context /* @in */,
                                                   const bool &provide /* @in */,
                                                   const string &capability /* @in */
                                                   ) = 0;

            // @text invokeProvider
            // @brief Provides support for invoking a provider for a given capability
            // @param context: Execution context containing requestId, connectionId, appId
            // @param capability: the capability to invoke
            // @returns Core::hresult
            virtual Core::hresult InvokeProvider(const Context &context /* @in */,
                                                 const string &capability /* @in */,
                                                 const string &params /* @in @opaque */
                                                 ) = 0;

            // @text handleProviderResponse
            // @brief Handle Response from Provider
            // @param payload: the response payload
            // @param capability: the capability that responded
            // @returns Core::hresult
            virtual Core::hresult HandleProviderResponse(const string &payload /* @in @opaque */,
                                                         const string &capability /* @in */
                                                         ) = 0;

            // @text handleProviderError
            // @brief Handle Response from Provider
            // @param payload: the response payload
            // @param capability: the capability that responded
            // @returns Core::hresult
            virtual Core::hresult HandleProviderError(const string &payload /* @in @opaque */,
                                                      const string &capability /* @in */
                                                      ) = 0;

            // @text Cleanup
            // @brief Cleanup any context which has a given connectionId for a given origin
            // @param connectionId: connection id for a given context
            // @param origin: origin of the context
            // @returns Core::hresult
            virtual Core::hresult Cleanup(const uint32_t connectionId /* @in */, const string &origin /* @in */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
