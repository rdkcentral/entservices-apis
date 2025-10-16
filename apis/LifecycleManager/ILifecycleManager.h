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

        // @brief Notifies the change of state of application
        // @text onnAppStateChanged
        // @json:omit
        virtual void OnAppStateChanged(const string& appId, LifecycleState state, const string& errorReason) {};
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** Get the list of loaded applications */
    // @json:omit
    // @text getLoadedApps
    // @brief Get the list of loaded applications, state and additional information
    virtual Core::hresult GetLoadedApps(const bool verbose , string& apps /* @out */) = 0;

    /** Tell whether application is loaded or not */
    // @json:omit
    // @text isAppLoaded
    // @brief Check whether the given application is loaded or not
    virtual Core::hresult IsAppLoaded(const string& appId , bool& loaded /* @out */) const = 0;

    /** Perform launching of application with window and runtime manager */
    // @json:omit
    // @text spawnApp
    // @brief Perform launching of application with window and runtime manager
    virtual Core::hresult SpawnApp(const string& appId , const string& launchIntent , const LifecycleState targetLifecycleState , const RuntimeConfig& runtimeConfigObject , const string& launchArgs , string& appInstanceId /* @out */, string& errorReason /* @out */, bool& success /* @out */) = 0;

    /** Get the list of loaded applications */
    // @json:omit
    // @text setTargetAppState
    // @brief Set the state for the application instance
    virtual Core::hresult SetTargetAppState(const string& appInstanceId , const LifecycleState targetLifecycleState , const string& launchIntent ) = 0;

    /** unload the application */
    // @json:omit
    // @text unloadApp
    // @brief Perform graceful termination and unload the application
    virtual Core::hresult UnloadApp(const string& appInstanceId , string& errorReason /* @out */, bool& success /* @out */) = 0;

    /** kill the application */
    // @json:omit
    // @text killApp
    // @brief Perform forceful termination of the application
    virtual Core::hresult KillApp(const string& appInstanceId , string& errorReason /* @out */, bool& success /* @out */) = 0;

    /** send intent to target application */
    // @json:omit
    // @text sendIntentToActiveApp
    // @brief Send firebolt intent to target application
    virtual Core::hresult SendIntentToActiveApp(const string& appInstanceId , const string& intent , string& errorReason /* @out */, bool& success /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
