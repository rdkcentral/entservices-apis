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
        // @brief Notifies when an application lifecycle state changes.
        // @details This notification is sent whenever an application transitions between lifecycle states and includes the previous state, the new state, and any active navigation context.
        // @param appId: App identifier for the application.
        // @example appId: "com.example.app"
        // @param appInstanceId: A numerical identifier for a specific instance of the application.
        // @example appInstanceId: "1"
        // @param oldLifecycleState: The previous state of the application instance before the update.
        // @example oldLifecycleState: ACTIVE
        // @param newLifecycleState: The new state to transition the application.
        // @example newLifecycleState: INACTIVE
        // @param navigationIntent: Navigation intent associated with the application while it is active.
        // @example navigationIntent: "home"
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
    // @brief Confirms that the application is ready to complete its initialization.
    // @details This method is called by the application after initialization to acknowledge that the app is ready for the lifecycle transition to proceed.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.app"
    // @retval Core::ERROR_NONE: The readiness acknowledgement was accepted successfully.
    virtual Core::hresult AppReady(const string& appId ) = 0;

    /** Response api call to appLifecycleStateChanged API */
    // @text stateChangeComplete
    // @brief Confirms completion of a requested lifecycle state change.
    // @details This method allows the application to report the outcome of a previously requested lifecycle transition and indicates whether the operation succeeded.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.app"
    // @param stateChangedId: Unique identifier of the requested state transition.
    // @example stateChangedId: 42
    // @param success: Indicates whether the lifecycle state change completed successfully.
    // @example success: true
    // @retval Core::ERROR_NONE: The completion response was accepted successfully.
    virtual Core::hresult StateChangeComplete(const string& appId , const uint32_t stateChangedId , const bool success ) = 0;

    /** close the app */
    // @text closeApp
    // @brief Requests that the application be closed.
    // @details This method instructs the lifecycle manager to terminate the specified application using the supplied close reason.
    // @param appId: App identifier for the application.
    // @example appId: "com.example.app"
    // @param closeReason: Reason the application is being closed.
    // @example closeReason: USER_EXIT
    // @retval Core::ERROR_NONE: The close request was accepted successfully.
    virtual Core::hresult CloseApp(const string& appId , const AppCloseReason closeReason ) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
