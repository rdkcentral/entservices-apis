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
            // @details The notification is sent when the Amazon Prime application changes playback state.
            // @param state: Current state of amazon prime
            // @example state: PLAYING
            // @retval Core::ERROR_NONE: State change notification was delivered successfully
            virtual void StateChange(const IAmazon::State state) {};
        };

        virtual ~IAmazon() {}

        /** Register notification interface */
        virtual Core::hresult Register(IAmazon::INotification* amazon) = 0;
        /** Unregister notification interface */
        virtual Core::hresult Unregister(IAmazon::INotification* amazon) = 0;

        // @text setDeepLink
        // @brief Set the deeplink command for amazon prime
        // @details The command is forwarded to the Amazon Prime application when it is launched or active.
        // @param command: App Deeplink command
        // @example command: "https://www.amazon.com/gp/video/detail/B012345678"
        // @retval Core::ERROR_NONE: Deeplink command set successfully
        virtual Core::hresult SetDeepLink(const string& command) = 0;

        // @text personalInfoRequest
        // @brief Request for personal access token to amazon prime app
        // @details Requests the Amazon Prime application to provide the user's personal access token.
        // @retval Core::ERROR_NONE: Personal access token request accepted successfully
        virtual Core::hresult PersonalInfoRequest() = 0;

        // @text factoryResetRequest
        // @brief Factory reset amazon prime app data
        // @details Removes the stored application data and restores Amazon Prime to its factory state.
        // @retval Core::ERROR_NONE: Factory reset request accepted successfully
        virtual Core::hresult FactoryResetRequest() = 0;

        // @texts setLaunchReason
        // @brief Set launch reason for amazon prime app
        // @details Stores the reason that should be provided when launching the Amazon Prime application.
        // @param command: App launch reason
        // @example command: "USER_REQUEST"
        // @retval Core::ERROR_NONE: Launch reason set successfully
        virtual Core::hresult SetLaunchReason(const string& command) = 0;
    };
}
}

#endif // __IAMAZON_PRIME_H
