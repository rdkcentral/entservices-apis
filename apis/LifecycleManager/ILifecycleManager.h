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

namespace WPEFramework {
namespace Exchange {

#ifndef RUNTIME_CONFIG
struct RuntimeConfig {
    bool dial;
    bool wanLanAccess;
    bool thunder;
    int32_t systemMemoryLimit;
    int32_t gpuMemoryLimit;
    std::string envVariables;
    uint32_t userId;
    uint32_t groupId;
    uint32_t dataImageSize;

    bool resourceManagerClientEnabled;
    std::string dialId;
    std::string command;
    std::string appType;
    std::string appPath;
    std::string runtimePath;

    std::string logFilePath;
    uint32_t logFileMaxSize;
    std::string logLevels;          //json array of strings
    bool mapi;
    std::string fkpsFiles;          //json array of strings
    std::string capabilities /* @text capabilities */
                             /* @brief Comma-separated lowercase runtime capability tokens */;
    std::string ralfPkgPath /* @text ralfPkgPath */
                            /* @brief Filesystem path holding metadata information for RALF packages */;

    std::string fireboltVersion;
    bool enableDebugger;
    string unpackedPath;
};
#define RUNTIME_CONFIG
#endif

// @text:keep
struct EXTERNAL ILifecycleManager : virtual public Core::IUnknown {

    enum LifecycleState : uint8_t {
        UNLOADED,
        LOADING,
        INITIALIZING,
        PAUSED,
        ACTIVE,
        SUSPENDED,
        HIBERNATED,
        TERMINATING
    };

    enum { ID = ID_LIFECYCLE_MANAGER };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_LIFECYCLE_MANAGER_NOTIFICATION };
       
        // @text onnAppStateChanged
        // @json:omit
        // @brief Notifies the change of state of application
        // @details Indicates that an application instance has transitioned to a new lifecycle state.
        // @param appId: Identifier of the application whose state changed.
        // @example appId: "com.example.app"
        // @param state: New lifecycle state of the application.
        // @example state: ACTIVE
        // @param errorReason: Error details when the state transition failed; otherwise empty.
        // @example errorReason: "Failed to initialize"
        virtual void OnAppStateChanged(const string& appId, LifecycleState state, const string& errorReason) {};
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    // @json:omit
    // @text getLoadedApps
    // @brief Gets the list of loaded applications, their state, and additional information.
    // @details The verbose flag controls whether additional application details are included.
    // @param verbose: Whether to include additional application information.
    // @example verbose: true
    // @param apps: Output string containing the loaded application information.
    // @example apps: "[{\"appId\": \"com.example.app\", \"state\": \"ACTIVE\"}]"
    // @retval Core::ERROR_NONE: The loaded application information was retrieved successfully.
    virtual Core::hresult GetLoadedApps(const bool verbose , string& apps /* @out */) = 0;

    // @json:omit
    // @text isAppLoaded
    // @brief Checks whether the specified application is loaded.
    // @details The result reflects the current loading state of the application.
    // @param appId: Identifier of the application to check.
    // @example appId: "com.example.app"
    // @param loaded: Output flag set to true when the application is loaded.
    // @example loaded: true
    // @retval Core::ERROR_NONE: The application loading state was retrieved successfully.
    virtual Core::hresult IsAppLoaded(const string& appId , bool& loaded /* @out */) const = 0;

    // @json:omit
    // @text spawnApp
    // @brief Launches an application with the requested lifecycle state and runtime configuration.
    // @details The lifecycle manager creates an application instance using the supplied intent, arguments, and runtime configuration.
    // @param appId: Identifier of the application to launch.
    // @example appId: "com.example.app"
    // @param launchIntent: Intent used to launch the application.
    // @example launchIntent: "launch"
    // @param targetLifecycleState: Lifecycle state requested after launch.
    // @example targetLifecycleState: ACTIVE
    // @param runtimeConfigObject: Runtime configuration for the application.
    // @example runtimeConfigObject: { "configKey": "configValue" }
    // @param launchArgs: Arguments passed to the application at launch.
    // @example launchArgs: "--verbose"
    // @param appInstanceId: Output identifier assigned to the launched application instance.
    // @example appInstanceId: "instance-123"
    // @param errorReason: Output error details when launching fails.
    // @example errorReason: "Failed to start application"
    // @param success: Output flag indicating whether launch completed successfully.
    // @example success: true
    // @retval Core::ERROR_NONE: The application launch request was processed successfully.
    virtual Core::hresult SpawnApp(const string& appId , const string& launchIntent , const LifecycleState targetLifecycleState , const RuntimeConfig& runtimeConfigObject , const string& launchArgs , string& appInstanceId /* @out */, string& errorReason /* @out */, bool& success /* @out */) = 0;

    // @json:omit
    // @text setTargetAppState
    // @brief Sets the target lifecycle state for an application instance.
    // @details The lifecycle manager transitions the application instance toward the requested state using the supplied intent.
    // @param appInstanceId: Identifier of the application instance to update.
    // @example appInstanceId: "instance-123"
    // @param targetLifecycleState: Lifecycle state requested for the application instance.
    // @example targetLifecycleState: ACTIVE
    // @param launchIntent: Intent associated with the state change.
    // @example launchIntent: "resume"
    // @retval Core::ERROR_NONE: The target lifecycle state was set successfully.
    virtual Core::hresult SetTargetAppState(const string& appInstanceId , const LifecycleState targetLifecycleState , const string& launchIntent ) = 0;

    // @json:omit
    // @text unloadApp
    // @brief Gracefully terminates and unloads an application instance.
    // @details The application is given an opportunity to terminate cleanly before it is removed.
    // @param appInstanceId: Identifier of the application instance to unload.
    // @example appInstanceId: "instance-123"
    // @param errorReason: Output error details when unloading fails.
    // @example errorReason: "Failed to unload application"
    // @param success: Output flag indicating whether unloading completed successfully.
    // @example success: true
    // @retval Core::ERROR_NONE: The application unload request was processed successfully.
    virtual Core::hresult UnloadApp(const string& appInstanceId , string& errorReason /* @out */, bool& success /* @out */) = 0;

    // @json:omit
    // @text killApp
    // @brief Forcefully terminates an application instance.
    // @details The application is stopped without waiting for graceful termination.
    // @param appInstanceId: Identifier of the application instance to terminate.
    // @example appInstanceId: "instance-123"
    // @param errorReason: Output error details when termination fails.
    // @example errorReason: "Failed to terminate application"
    // @param success: Output flag indicating whether termination completed successfully.
    // @example success: true
    // @retval Core::ERROR_NONE: The application termination request was processed successfully.
    virtual Core::hresult KillApp(const string& appInstanceId , string& errorReason /* @out */, bool& success /* @out */) = 0;

    // @json:omit
    // @text sendIntentToActiveApp
    // @brief Sends a Firebolt intent to an active application instance.
    // @details The intent is delivered to the specified active application.
    // @param appInstanceId: Identifier of the active application instance.
    // @example appInstanceId: "instance-123"
    // @param intent: Firebolt intent to send to the application.
    // @example intent: "navigate"
    // @param errorReason: Output error details when sending the intent fails.
    // @example errorReason: "Failed to send intent"
    // @param success: Output flag indicating whether the intent was sent successfully.
    // @example success: true
    // @retval Core::ERROR_NONE: The intent was sent successfully.
    virtual Core::hresult SendIntentToActiveApp(const string& appInstanceId , const string& intent , string& errorReason /* @out */, bool& success /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
