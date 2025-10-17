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
        #ifndef GATEWAY_CONTEXT
        struct Context
        {
                int requestId;       // @brief Unique identifier for the request.
                uint32_t connectionId; // @brief guid for the execution/session context.
                string appId;        // @brief Application identifier (Firebolt appId).
        };
        #define GATEWAY_CONTEXT
        #endif

        // @json 1.0.0 @text:keep
        struct EXTERNAL IAppGateway : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY
            };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            // @text configure
            // @brief Adds additional Resolution paths to the gateway
            // @param paths: Adds set of paths in the order of override to be used by gateway to update the resolutions
            // @returns Core::hresult
            virtual Core::hresult Configure(IStringIterator *const &paths /* @in */) = 0;


            // @text resolve
            // @brief Provides support for other thunder plugins which implement IAppGatewayResponderInternal to use the 
            // resolver for processing async requests.
            // @param context: Execution context containing requestId, connectionId, appId
            // @param method: the method to resolve
            // @param params (optional): the parameters to resolve
            // @returns Core::hresult
            virtual Core::hresult Resolve(const Context &context /* @in */,
                                          const string &method /* @in */,
                                          const string &params /* @in @opaque */) = 0;
        };

        // @text:keep
        struct EXTERNAL IAppGatewayAuthenticatorInternal : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_AUTHENTICATOR
            };

            // @json:omit
            // @text Authenticate
            // @param sessionId: Session Id provided by a given application.
            // @brief Authenticate an incoming connection
            virtual Core::hresult Authenticate(const string& sessionId /* @in */, string& appId /* @out */) = 0;

            // ---- GetSessionId ----
            // @text getSessionId
            // @param appId: AppId of the current application.
            // @brief Get the sessionId for a given application provided to the delegate
            virtual Core::hresult GetSessionId(const string& appId /* @in */ , string& sessionId /* @out */) = 0;


            // ---- GetContentPartnerId ----
            // @text getContentPartnerId
            // @param appId: AppId of the current application.
            // @brief Get the contentPartnerId for a given application provided to the delegate
            virtual Core::hresult GetContentPartnerId(const string& appId /* @in */ , string& contentPartnerId /* @out */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayResponderInternal : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_RESPONDER
            };

            // @json:omit
            // @text respond
            // @brief Provides support for responding to a given context
            // @param context: Execution context containing requestId, connectionId, appId
            // @param payload: the response payload
            // @returns Core::hresult
            virtual Core::hresult Respond(const Context &context /* @in */,
                                          const string &payload /* @in @opaque */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayRequestHandler : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_REQUEST_HANDLER
            };

            // @json:omit
            // @text respond
            // @brief Provides support for responding to a given context
            // @param context: Execution context containing requestId, connectionId, appId
            // @param payload: the response payload
            // @returns Core::hresult
            virtual Core::hresult HandleAppGatewayRequest(const Context &context /* @in */,
                                          const string& method /* @in */,
                                          const string &payload /* @in @opaque */,
                                          string& result /*@out @opaque */) = 0;

        };
    } // namespace Exchange
} // namespace WPEFramework
