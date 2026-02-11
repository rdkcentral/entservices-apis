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
// @json 1.0.0 @text:keep
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
        // @text onAppLifecycleStateChanged
        // @brief Notifies the new state
        // @param appId:App identifier for the application.
        // @param appInstanceId:A numerical identifier for a specific instance of the application.
        // @param oldLifecycleState:The previous state of the application instance before the update.
        // @param newLifecycleState:The new state to transition the application.
        // @param navigationIntent:navigation intent during active state
        virtual void OnAppLifecycleStateChanged(const string& appId /* @text appId */,
                                        const string& appInstanceId /* @text appInstanceId */,
                                        const ILifecycleManager::LifecycleState oldLifecycleState /* @text oldLifecycleState */,
                                        const ILifecycleManager::LifecycleState newLifecycleState /* @text newLifecycleState */,
                                        const string& navigationIntent /* @text navigationIntent */) {}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** Response api call to appInitializing API */
    // @text appReady
    // @brief Response api call to appInitializing API
    // @param appId:App identifier for the application.
    virtual Core::hresult AppReady(const string& appId ) = 0;

    /** Response api call to appLifecycleStateChanged API */
    // @text stateChangeComplete
    // @brief Response api call to appLifecycleStateChanged API
    // @param appId:App identifier for the application.
    // @param stateChangedId: state changed identifier
    virtual Core::hresult StateChangeComplete(const string& appId , const uint32_t stateChangedId , const bool success ) = 0;

    /** close the app */
    // @text closeApp
    // @brief close the app
    // @param appId:App identifier for the application.
    // @param closeReason: closed reason for application
    virtual Core::hresult CloseApp(const string& appId , const AppCloseReason closeReason ) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
