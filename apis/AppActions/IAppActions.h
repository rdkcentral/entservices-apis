/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management.
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

namespace WPEFramework {
namespace Exchange {

    /*
     * @jsonrpc AppActions
     * @brief Interface for AppActions plugin
     */

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IAppActions : virtual public Core::IUnknown {
        enum { ID = ID_APP_ACTIONS };

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_APP_ACTIONS_NOTIFICATION };

            /**
             * @brief Notifies when an action start event occurs.
             * @param initiator The ID of the app/ module initiating the action.
             * @param intent The intent string describing the action.
             * @param handlerAppId(optional) The ID of the app handling the action.
             */
            // @text onActionStartRequest
            virtual void OnActionStartRequest(const string& initiator, const string& intent, const string& handlerAppId) {}
        };

        /**
         * @brief Starts an action for the given intent and handler app.
         * @param initiator The ID of the app/ module initiating the action.
         * @param intent The intent string describing the action.
         * @param handlerAppId(optional) The ID of the app handling the action.
         * @retval Core::ERROR_NONE: Success
         * @retval Core::ERROR_GENERAL: Failure
         * @details Initiates an action from the initiator to the AppActions with the specified intent.
         */
        // @text actionStart
        virtual Core::hresult ActionStart(const string& initiator, const string& intent, const string& handlerAppId) = 0;

        /**
         * @brief Registers a notification interface to receive AppActions events.
         * @param notification The notification interface implementation to register.
         * @retval Core::ERROR_NONE: Notification interface registered successfully.
         * @retval Core::ERROR_GENERAL: Notification interface registration failed.
         */
        virtual Core::hresult Register(INotification *notification) = 0;

        /**
         * @brief Unregisters a previously registered notification interface.
         * @param notification The notification interface implementation to unregister.
         * @retval Core::ERROR_NONE: Notification interface unregistered successfully.
         * @retval Core::ERROR_GENERAL: Notification interface unregistration failed.
         */
        virtual Core::hresult Unregister(INotification *notification) = 0;
    };
} // namespace Exchange
} // namespace WPEFramework
