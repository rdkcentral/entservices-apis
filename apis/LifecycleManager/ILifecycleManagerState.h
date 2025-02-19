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
#include "ILifecycleManager.h"
// @stubgen:include "ILifecycleManager.h"

namespace WPEFramework {
namespace Exchange {
struct EXTERNAL ILifecycleManagerState : virtual public Core::IUnknown {

    enum AppCloseReason : uint8_t {
        USER_EXIT,
        ERROR,
        KILL_AND_RUN,
        KILL_AND_ACTIVATE
    };

    enum { ID = ID_LIFECYCLE_MANAGER_STATE };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_LIFECYCLE_MANAGER_STATE_NOTIFICATION };

        /** Notifies the new state */
        // @json:omit
        // @brief Notifies the new state
        virtual void OnAppLifecycleStateChanged(const string& appId,
                                                const string& appInstanceId,
                                                const ILifecycleManager::LifecycleState oldState,
                                                const ILifecycleManager::LifecycleState newState,
                                                const string& navigationIntent) {}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** Response api call to appInitializing API */
    // @json:omit
    // @brief Response api call to appInitializing API
    virtual Core::hresult AppReady(const string& appId /* @in */) = 0;

    /** Response api call to appLifecycleStateChanged API */
    // @json:omit
    // @brief Response api call to appLifecycleStateChanged API
    virtual Core::hresult StateChangeComplete(const string& appId /* @in */, const uint32_t stateChangedId /* @in */, const bool success /* @in */) = 0;

    /** close the app */
    // @json:omit
    // @brief close the app
    virtual Core::hresult CloseApp(const string& appId /* @in */, const AppCloseReason closeReason /* @in */) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
