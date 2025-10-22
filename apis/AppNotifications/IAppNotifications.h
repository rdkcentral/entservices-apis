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

            struct AppNotificationContext
            {
                uint32_t requestId;       // @brief Unique identifier for the request.
                uint32_t connectionId; // @brief Unique identifier for the execution/session context.
                string appId;        // @brief Application identifier (Firebolt appId).
                string origin;      // @brief Origin of the request (e.g., org.rdk.AppGateway).

                bool operator==(const AppNotificationContext& other) const {
                    return this->requestId == other.requestId && this->connectionId == other.connectionId && this->appId == other.appId;
                }
            };

            // @json:omit
            // @text subscribe
            // @brief Thunder register/unregister for Firebolt subsciption requests
            // @param context: Execution context containing requestId, connectionId, appId
            // @param register: boolean
            // @param module: the thunder plugin to subscribe
            // @param event: the event to subscribe
            // @returns Core::hresult
            virtual Core::hresult Subscribe(const AppNotificationContext &context /* @in */,
                                            bool listen /* @in */,
                                            const string &module /* @in */,
                                            const string &event /* @in */) = 0;

            // @json:omit
            // @text emit
            // @brief Dispatch event for a given registration, if appId is provided the dispatch happens for a given App.
            // @param event: the event to emit
            // @param payload: the payload to emit
            // @param appId (optional): the appId to emit the event for, if empty the event is emitted for all Apps
            // @returns Core::hresult
            virtual Core::hresult Emit(const string &event /* @in */,
                                       const string &payload /* @in @opaque */,
                                       const string &appId /* @in */) = 0;

            // @json:omit
            // @text Cleanup
            // @brief Cleanup any context which has a given connectionId for a given origin
            // @param connectionId: connection id for a given context
            // @param origin: origin of the context
            // @returns Core::hresult
            virtual Core::hresult Cleanup(const uint32_t connectionId /* @in */, const string &origin /* @in */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppNotificationHandler : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_NOTIFICATIONS_HANDLER_INTERNAL
            };

            // @json:omit
            // @text handleAppEventNotifier
            // @brief Handle AppEvent Notfier expectations for a given event
            // @param event: the event for registration
            // @param listen: whether to listen
            // @param status: status to be filled in
            // @returns Core::hresult
            virtual Core::hresult HandleAppEventNotifier(const string& event /* @in */, const bool& listen /* @in */, bool& status /* @out */) = 0;

        };
    } // namespace Exchange
} // namespace WPEFramework
