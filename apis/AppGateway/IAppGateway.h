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
// @stubgen:include <com/IIteratorType.h>
namespace WPEFramework
{
    namespace Exchange
    {
        struct EXTERNAL GatewayContext
        {
                uint32_t requestId;       /* @text requestId */ /* @brief Unique identifier for the request. */ 
                uint32_t connectionId;    /* @text connectionId */ /* @brief Unique identifier for the execution/session context. */
                string appId;             /* @text appId */ /* @brief Application identifier (Firebolt appId). */
        };
        
        // @json 1.0.0 @text:keep
        struct EXTERNAL IAppGatewayResolver : virtual public Core::IUnknown
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
            virtual Core::hresult Configure(IStringIterator *const& paths ) = 0;


            // @json:omit
            // @text resolve
            // @brief Provides support for other thunder plugins to use the 
            // resolver for processing requests.
            // @param context: Execution context containing requestId, connectionId, appId
            // @param origin: Origin of the request typically the callsign.
            // @param method: the method to resolve
            // @param params (optional): the parameters to resolve
            // @param result: Result of the resolution can be empty
            // @returns Core::hresult
            virtual Core::hresult Resolve(const GatewayContext& context ,
                                          const string& origin ,
                                          const string& method ,
                                          const string& params /*@opaque */,
                                          string& result /*@out @opaque */) = 0;
        };

        // @text:keep
        struct EXTERNAL IAppGatewayAuthenticator : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_AUTHENTICATOR
            };

            // ---- Authenticate ----
            // @json:omit
            // @text Authenticate
            // @param sessionId: Session Id provided by a given application.
            // @brief Authenticate an incoming connection
            virtual Core::hresult Authenticate(const string& sessionId , string& appId /* @out */) = 0;

            // ---- GetSessionId ----
            // @json:omit
            // @text GetSessionId
            // @param appId: AppId of the current application.
            // @brief Get the sessionId for a given application provided to the delegate
            virtual Core::hresult GetSessionId(const string& appId  , string& sessionId /* @out */) = 0;

            // ---- CheckPermissionGroup ----
            // @json:omit
            // @text CheckPermissionGroup
            // @param appId: AppId of the current application.
            // @param permissionGroup: Permission group to check
            // @brief Check if the application belongs to a given permission group
            virtual Core::hresult CheckPermissionGroup(const string& appId ,
                                                       const string& permissionGroup ,
                                                       bool& allowed /* @out */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayResponder : virtual public Core::IUnknown
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
            virtual Core::hresult Respond(const GatewayContext& context ,
                                          const string& payload /*@opaque */) = 0;

            // @json:omit
            // @text Emit
            // @brief Provides support for Emitting Notifications to a given context
            // @param context: Execution context containing requestId, connectionId, appId
            // @param payload: the response payload
            // @returns Core::hresult
            virtual Core::hresult Emit(const GatewayContext& context ,
                const string& method , const string& payload /*@opaque */) = 0;

            // @json:omit
            // @text Request
            // @brief Forwards a Request to the Client. Needed for App Provider Patterns.
            // @param connectionId: Connection Id
            // @param id: Request id
            // @param method: Method
            // @param params: Params string object
            // @returns Core::hresult
            virtual Core::hresult Request(const uint32_t connectionId , 
                const uint32_t id , const string& method , const string& params /*@opaque */) = 0;

            
            // @json:omit
            // @text GetGatewayConnectionContext
            // @brief Gets any connection context parameter like headers, url params
            // @param connectionId: Connection Id
            // @param contextKey: Connection Id
            // @param contextValue: response value
            // @returns Core::hresult
            virtual Core::hresult GetGatewayConnectionContext(const uint32_t connectionId ,
                const string& contextKey ,
                string& contextValue /* @out */) = 0;


            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_APP_GATEWAY_CONNECTION_NOTIFICATION };

                // @brief Notifies App has either started or stopped a connection. App can create multiple connections.
                // @text OnAppConnectionChanged
                // @param appId App identifier for the application
                // @param connectionId Unique identifier for the connection
                // @param connected true if connection started, false if connection stopped
                virtual void OnAppConnectionChanged(const string& appId, const uint32_t connectionId, const bool& connected) {};
            };

            /** Register notification interface */
            virtual Core::hresult Register(INotification* notification) = 0;

            /** Unregister notification interface */
            virtual Core::hresult Unregister(INotification* notification) = 0;

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
            // @param payload: the request payload
            // @param result: Response for the given request. Can be empty.
            // @returns Core::hresult
            virtual Core::hresult HandleAppGatewayRequest(const GatewayContext& context ,
                                          const string& method ,
                                          const string& payload /*@opaque */,
                                          string& result /*@out @opaque */) = 0;

        };
    } // namespace Exchange
} // namespace WPEFramework
