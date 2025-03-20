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

    // This interface gives direct access to a Amazon instance
    struct IAmazon : virtual public Core::IUnknown {

        enum { ID = ID_AMAZONPRIME };

        enum state {
            PLAYING = 0x0001,
            STOPPED = 0x0002,
            SUSPENDING = 0x0004
        };

        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_AMAZONPRIME_NOTIFICATION };

            virtual ~INotification() {}

            // Signal changes on the subscribed namespace..
            virtual void StateChange(const IAmazon::state state) = 0;
        };

        virtual ~IAmazon() {}

        virtual void Register(IAmazon::INotification* amazon) = 0;
        virtual void Unregister(IAmazon::INotification* amazon) = 0;

        virtual void setDeepLink(const string& command) = 0;
        virtual void personalInfoRequest() = 0;
        virtual void factoryResetRequest() = 0;
        virtual void setLaunchReason(const string& command) = 0;
    };
}
}

#endif // __IAMAZON_PRIME_H
