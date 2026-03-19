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

#ifndef __IHelloPlugin_H
#define __IHelloPlugin_H

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IHelloPlugin : virtual public Core::IUnknown {
            enum { ID = ID_HELLO_PLUGIN };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_HELLO_PLUGIN_NOTIFICATION };

                // @text onGreetingChanged
                // @brief Triggered when the greeting message changes
                // @param message: The new greeting message
                virtual void OnGreetingChanged(const string& message /* @text message */) {}
            };

            virtual Core::hresult Register(IHelloPlugin::INotification* sink) = 0;
            virtual Core::hresult Unregister(IHelloPlugin::INotification* sink) = 0;

            // @text getGreeting
            // @brief Returns the plugin greeting message
            // @param message: The greeting string produced by the plugin
            // @retval Core::ERROR_NONE: Greeting retrieved successfully
            // @retval Core::ERROR_GENERAL: Failed to retrieve greeting
            virtual Core::hresult GetGreeting(string& message /* @out @text message */) = 0;
        };

    } // namespace Exchange
} // namespace WPEFramework

#endif // __IHelloPlugin_H
