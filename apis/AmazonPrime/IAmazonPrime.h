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

#ifndef __IAMAZON_PRIME_H
#define __IAMAZON_PRIME_H

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct IAmazon : virtual public Core::IUnknown {

        enum { ID = ID_AMAZONPRIME };

        enum State {
            PLAYING = 0x0001     /* @text PLAYING */,
            STOPPED = 0x0002     /* @text STOPPED */,
            SUSPENDING = 0x0004  /* @text SUSPENDING */
        };

        // @event 
        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_AMAZONPRIME_NOTIFICATION };

            virtual ~INotification() {}

            // @text StateChange
            // @brief Triggered whenever the App state changes
            // @param state: current state of amazon prime
            virtual void StateChange(const IAmazon::State state) {};
        };

        virtual ~IAmazon() {}

        /** Register notification interface */
        virtual Core::hresult Register(IAmazon::INotification* amazon /* @in */) = 0;
        /** Unregister notification interface */
        virtual Core::hresult Unregister(IAmazon::INotification* amazon /* @in */) = 0;

        /** To send deeplink command to amazon prime application **/
        // @text setDeepLink
        // @brief Set the deeplink command for amazon prime
        // @param command : app Deeplink command
        virtual Core::hresult SetDeepLink(const string& command) = 0;

        /** To request for personal access token to amazon prime application **/
        // @text personalInfoRequest
        // @brief Request for personal access token to amazon prime app
        virtual Core::hresult PersonalInfoRequest() = 0;

        /** To factory reset amazon prime application **/
        // @text factoryResetRequest
        // @brief Factory reset amazon prime app data
        virtual Core::hresult FactoryResetRequest() = 0;

        /** To set launch reason for amazon prime application **/
        // @texts setLaunchReason
        // @brief Set launch reason for amazon prime app
        // @param command : app launch reason
        virtual Core::hresult SetLaunchReason(const string& command) = 0;
    };
}
}

#endif // __IAMAZON_PRIME_H
