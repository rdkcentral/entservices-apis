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
namespace WPEFramework
{
    namespace Exchange
    {
        // @text:keep
        struct EXTERNAL IAppNotifications : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_NOTIFICATIONS
            };

            struct EXTERNAL AppNotificationContext
            {
                uint32_t requestId;       /* @text requestId */ /* @brief Unique identifier for the request. */
                uint32_t connectionId;    /* @text connectionId */ /* @brief Unique identifier for the execution/session context. */
                string appId;             /* @text appId */ /* @brief Application identifier (Firebolt appId). */
                string origin;           /* @text origin */ /* @brief Origin of the request (e.g., org.rdk.AppGateway). */
            };

            // @json:omit
            // @text subscribe
            // @brief Thunder register/unregister for Firebolt subscription requests
            // @param context: Execution context containing requestId, connectionId, appId
            // @param listen: boolean
            // @param module: the thunder plugin to subscribe
            // @param event: the event to subscribe
            // @returns Core::hresult 
            virtual Core::hresult Subscribe(const AppNotificationContext& context ,
                                            bool listen ,
                                            const string& module ,
                                            const string& event ) = 0;

            // @json:omit
            // @text emit
            // @brief Dispatch event for a given registration, if appId is provided the dispatch happens for a given App.
            // @param event: the event to emit
            // @param payload: the payload to emit
            // @param appId (optional): the appId to emit the event for, if empty the event is emitted for all Apps
            // @returns Core::hresult
            virtual Core::hresult Emit(const string& event ,
                                       const string& payload /* @opaque */,
                                       const string& appId ) = 0;

            // @json:omit
            // @text cleanup
            // @brief Cleanup any context which has a given connectionId for a given origin
            // @param connectionId: connection id for a given context
            // @param origin: origin of the context
            // @returns Core::hresult
            virtual Core::hresult Cleanup(const uint32_t connectionId , const string& origin ) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppNotificationHandler : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_NOTIFICATIONS_HANDLER_INTERNAL
            };


            struct EXTERNAL IEmitter : virtual public Core::IUnknown
            {
                enum { ID = ID_APP_NOTIFICATIONS_HANDLER_INTERNAL_EMITTER };
                virtual ~IEmitter() override = default;

                // @json:omit
                // @text emit
                // @brief Dispatch event for a given registration, if appId is provided the dispatch happens for a given App.
                // @param event: the event to emit
                // @param payload: the payload to emit
                // @param appId (optional): the appId to emit the event for, if empty the event is emitted for all Apps
                virtual void Emit(const string &event,
                                  const string &payload /*@opaque */,
                                  const string &appId) {};

            };

            // @json:omit
            // @text handleAppEventNotifier
            // @brief Handle AppEvent Notifier expectations for a given event
            // @param emitCb: the emit callback interface
            // @param event: the event for registration
            // @param listen: whether to listen
            // @param status: status to be filled in
            // @returns Core::hresult
            virtual Core::hresult HandleAppEventNotifier(IEmitter *emitCb, const string& event, bool listen, bool& status /* @out */) = 0;

        };
    } // namespace Exchange
} // namespace WPEFramework
