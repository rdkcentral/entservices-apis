/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2026 RDK Management
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

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IGoogleCast : virtual public Core::IUnknown {
        enum { ID = ID_GOOGLE_CAST };

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // @json 1.0.0 @text:keep
        struct EXTERNAL IRuntimeManagerDelegate : virtual public Core::IUnknown {
            enum { ID = ID_GOOGLE_CAST_RM_DELEGATE };

            enum IntentAction : uint8_t {
                // @text launch
                LAUNCH,  // Launch the runtime and bring it to the foreground on the screen.
                // @text close
                CLOSE,   // Send the runtime to the background off the screen.
                // @text destroy
                DESTROY  // Destroy the runtime instance.
            };

            struct IntentContext {
                // @brief Source of the intent.
                string source;
            };

            struct Intent {
                // @brief Specifies the intent action to launch, close or destroy the app runtime instance.
                IntentAction action;
                // @brief Intent context.
                IntentContext context;
                // @opaque
                // @brief An array of launch arguments to forward to app runtime instance as is.
                string data;
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_GOOGLE_CAST_RM_DELEGATE_NOTIFICATION };

                // @text onIntentChanged
                // @brief Notifies about GoogleCast intent to launch/close/destroy cast application runtime.
                // @param appId: Durable application id.
                // @param inactive: Indicates pre-launch(off screen) request.
                // @param intent: A Firebolt compliant navigation intent.
                virtual void OnIntentChanged(
                    const string& appId,
                    const bool    inactive,
                    const Intent& intent) {
                }
            };
            virtual Core::hresult Register(IRuntimeManagerDelegate::INotification* sink) = 0;
            virtual Core::hresult Unregister(IRuntimeManagerDelegate::INotification* sink) = 0;

            // @json:omit
            // @brief Starts the runtime and brings it to the foreground on the screen.
            // @brief Emits onIntentChanged with launch action and args passed in intent data field.
            // @param appId: Durable application id of cast web runtime or cast settings.
            // @param args: A list of arguments to forward to app runtime.
            // @param prelaunch: Indicates if runtimes should be started in background.
            // @retval Core::ERROR_NOT_SUPPORTED: Pre-launch is not supported.
            // @retval Core::ERROR_NONE: Successfully delegated launch request.
            virtual Core::hresult StartRuntime(const string& appId, IStringIterator *const args, bool prelaunch) = 0;

            // @json:omit
            // @brief Stops the runtime.
            // @brief Emits onIntentChanged with destroy action.
            // @param appId: Durable application id of cast web runtime or cast settings.
            // @retval Core::ERROR_NONE: Successfully delegated destroy request.
            virtual Core::hresult StopRuntime(const string& appId) = 0;

            // @json:omit
            // @brief Sends the runtime to the background off-screen.
            // @brief Emits onIntentChanged with close action.
            // @param appId: Durable application id of cast web runtime or cast settings.
            // @retval Core::ERROR_NONE: Successfully delegated the request.
            virtual Core::hresult SendToBackground(const string& appId) = 0;
        };

        enum CastState : uint8_t {
            UNKNOWN,       // Cast shell is unconnected and current state is unknown. Cast is NOT functional.
            STARTING,      // Cast shell is starting and the connection to cast control is being established. Cast is NOT functional.
            NOT_SETUP,     // Started. But not setup yet - tos not accepted. Cast is NOT functional.
            OFFLINE,       // Started and setup. But network is not connected.  Cast is NOT functional.
            FORCED_UPDATE, // Started and setup and network connected. But forced update is in progress. Cast is NOT functional.
            SUSPENDED,     // Started and setup. But suspended by caller.  Cast is NOT functional.
            READY_TO_CAST  // Ready to cast. Cast is functional.
        };

        // @json
        // @brief Status of Cast shell.
        struct EXTERNAL CastStatus {
            // @brief Build number of the currently running Cast shell.
            // @text cast_build_number
            string castBuildNumber;

            // @brief Current cast shell state.
            // @text cast_state
            CastState castState;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_GOOGLE_CAST_NOTIFICATION };

            // @brief Notifies that the GoogleCast status changed.
            // @text onStatusChanged
            // @alt onStatusChange
            virtual void OnStatusChanged() {
            }
        };
        virtual Core::hresult Register(IGoogleCast::INotification* sink) = 0;
        virtual Core::hresult Unregister(IGoogleCast::INotification* sink) = 0;

        // @property @text getCastStatus @alt cast_status
        // @brief Status of cast shell interfacing via Cast control API.
        // @retval Core::ERROR_NONE: Indicates successful retrieval of cast status.
        virtual Core::hresult GetCastStatus(CastStatus& status /* @out */) const = 0;
    };

}
}
