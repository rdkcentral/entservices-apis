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
                string version;           /* @text version */ /* @brief Version of the notification context can be semantic version */
            };

            // @json:omit
            // @text subscribe
            // @brief Thunder register/unregister for Firebolt subscription requests
            // @details Registers or unregisters for Firebolt subscription requests based on the listen parameter.
            // @param context: Execution context containing requestId, connectionId, appId and version
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "origin": "org.rdk.AppGateway", "version": "1.0.0"}
            // @param listen: Boolean
            // @example listen: true
            // @param module: The thunder plugin to subscribe
            // @example module: "org.rdk.AppNotifications"
            // @param event: The event to subscribe
            // @example event: "AppLaunched"
            // @retval Core::ERROR_NONE: Successfully subscribed or unsubscribed for the event
            virtual Core::hresult Subscribe(const AppNotificationContext& context ,
                                            bool listen ,
                                            const string& module ,
                                            const string& event ) = 0;

            // @json:omit
            // @text emit
            // @brief Dispatch event for a given registration, if appId is provided the dispatch happens for a given App.
            // @details Emits an event to the specified app or to all apps if no appId is provided.
            // @param event: The event to emit
            // @example event: "AppLaunched"
            // @param payload: The payload to emit
            // @example payload: "{\"key\": \"value\"}"
            // @param appId (optional): The appId to emit the event for, if empty the event is emitted for all Apps
            // @example appId: "com.example.app"
            // @retval Core::ERROR_NONE: Successfully emitted the event
            virtual Core::hresult Emit(const string& event ,
                                       const string& payload /* @opaque */,
                                       const string& appId ) = 0;

            // @json:omit
            // @text cleanup
            // @brief Cleanup any context which has a given connectionId for a given origin
            // @details Cleans up the context associated with the specified connectionId and origin.
            // @param connectionId: Connection id for a given context
            // @example connectionId: 2
            // @param origin: Origin of the context
            // @example origin: "org.rdk.AppGateway"
            // @retval Core::ERROR_NONE: Successfully cleaned up the context
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
                // @details Emits the specified event with the given payload to the specified app or to all apps if no appId is provided.
                // @param event: The event to emit
                // @example event: "AppLaunched"
                // @param payload: The payload to emit
                // @example payload: "{\"key\": \"value\"}"
                // @param appId (optional): The appId to emit the event for, if empty the event is emitted for all Apps
                // @example appId: "com.example.app"
                // @retval Core::ERROR_NONE: Successfully emitted the event
                virtual void Emit(const string &event,
                                  const string &payload /*@opaque */,
                                  const string &appId) {};

            };

            // @json:omit
            // @text handleAppEventNotifier
            // @brief Handle AppEvent Notifier expectations for a given event
            // @details Registers or unregisters the emit callback for the specified event and reports whether the operation succeeded.
            // @param emitCb: The emit callback interface
            // @example emitCb: "Emitter instance"
            // @param event: The event for registration
            // @example event: "AppLaunched"
            // @param listen: Whether to listen
            // @example listen: true
            // @param status: Status to be filled in
            // @example status: true
            // @retval Core::ERROR_NONE: Successfully handled the AppEvent Notifier expectations for the given event
            virtual Core::hresult HandleAppEventNotifier(IEmitter *emitCb, const string& event, bool listen, bool& status /* @out */) = 0;

        };
    } // namespace Exchange
} // namespace WPEFramework
