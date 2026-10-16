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

// @stubgen:include <com/IIteratorType.h>

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
                             /* @brief Comma-separated lowercase runtime capability tokens supported by the runtime configuration */;
    std::string ralfPkgPath /* @text ralfPkgPath */
                            /* @brief Filesystem path holding metadata information for RALF packages */;

    std::string fireboltVersion;
    bool enableDebugger;
    string unpackedPath;
};
#define RUNTIME_CONFIG
#endif

// @text:keep
struct EXTERNAL IRuntimeManager : virtual public Core::IUnknown {
    enum { ID = ID_RUNTIME_MANAGER };

    using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
    using IValueIterator = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

    enum RuntimeState : uint8_t {
        RUNTIME_STATE_UNKNOWN     = 0   /* @text RUNTIME_STATE_UNKNOWN */,
        RUNTIME_STATE_STARTING    = 1   /* @text RUNTIME_STATE_STARTING */,
        RUNTIME_STATE_RUNNING     = 2   /* @text RUNTIME_STATE_RUNNING */,
        RUNTIME_STATE_SUSPENDED   = 3   /* @text RUNTIME_STATE_SUSPENDED */,
        RUNTIME_STATE_HIBERNATING = 4   /* @text RUNTIME_STATE_HIBERNATING */,
        RUNTIME_STATE_HIBERNATED  = 5   /* @text RUNTIME_STATE_HIBERNATED */,
        RUNTIME_STATE_WAKING      = 6   /* @text RUNTIME_STATE_WAKING */,
        RUNTIME_STATE_TERMINATING = 7   /* @text RUNTIME_STATE_TERMINATING */,
        RUNTIME_STATE_TERMINATED  = 8   /* @text RUNTIME_STATE_TERMINATED */
    };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_RUNTIME_MANAGER_NOTIFICATION };

        // @brief Notifies container is started
        // @details Sent after the application container has started successfully.
        // @text onStarted
        // @param appInstanceId: Identifier of the application/container instance.
        // @example appInstanceId: "org.example.app"
        virtual void OnStarted(const string& appInstanceId) {};

        // @brief Notifies container is shutdown
        // @details Sent after the application container has shut down, with its process exit code.
        // @text onTerminated
        // @param appInstanceId: Identifier of the application/container instance.
        // @example appInstanceId: "org.example.app"
        // @param exitCode: Exit code returned by the container process.
        // @example exitCode: 0
        virtual void OnTerminated(const string& appInstanceId, int32_t exitCode) {};

        // @brief Notifies failure in container execution
        // @details Sent when the application container encounters an execution failure.
        // @text onFailure
        // @param appInstanceId: Identifier of the application/container instance.
        // @example appInstanceId: "org.example.app"
        // @param error: Description of the container execution failure.
        // @example error: "Container failed to start"
        virtual void OnFailure(const string& appInstanceId, const string& error) {};

        // @brief Notifies state of container
        // @details Sent when the application container changes its runtime state.
        // @text onStateChanged
        // @param appInstanceId: Identifier of the application/container instance.
        // @example appInstanceId: "org.example.app"
        // @param state: New runtime state of the application/container.
        // @example state: RuntimeState::RUNTIME_STATE_RUNNING
        virtual void OnStateChanged(const string& appInstanceId, const RuntimeState state) {};
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** @brief Run the application */
    // @details Creates and starts an application container using the supplied identity, permissions, resource configuration, and optional access settings.
    // @text run
    // @param appId: Identifier of the application to run.
    // @example appId: "org.example.app"
    // @param appInstanceId: Unique identifier for this application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @param userId: User ID under which the container runs.
    // @example userId: 1000
    // @param groupId: Group ID under which the container runs.
    // @example groupId: 1000
    // @param ports: Optional iterator of socket ports to allow for the container.
    // @example ports: [8080, 8443]
    // @param paths: Optional iterator of host files and directories to map into the container.
    // @example paths: ["/data/app"]
    // @param debugSettings: Optional iterator of debugging settings, including ports to open for GDB.
    // @example debugSettings: ["gdbPort=5555"]
    // @param runtimeConfigObject: Runtime configuration, including capabilities, paths, and resource limits.
    // @example runtimeConfigObject: {"systemMemoryLimit": 512, "gpuMemoryLimit": 128}
    // @retval Core::ERROR_NONE: The application container was started successfully.
    // @retval Core::ERROR_GENERAL: The application container could not be started.
    virtual Core::hresult Run(const string& appId, const string& appInstanceId, const uint32_t userId, const uint32_t groupId, IValueIterator* const& ports, IStringIterator* const& paths, IStringIterator* const& debugSettings, const RuntimeConfig& runtimeConfigObject) = 0;

    /** @brief Hibernate the application */
    // @details Transitions the application container into the hibernated state.
    // @text hibernate
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @retval Core::ERROR_NONE: The application was hibernated successfully.
    // @retval Core::ERROR_GENERAL: The application could not be hibernated.
    virtual Core::hresult Hibernate(const string& appInstanceId) = 0;

    /** @brief Wake the application to given state */
    // @details Wakes the application container and transitions it to the requested runtime state.
    // @text wake
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @param runtimeState: Runtime state to enter when the application is woken.
    // @example runtimeState: RuntimeState::RUNTIME_STATE_RUNNING
    // @retval Core::ERROR_NONE: The application was woken successfully.
    // @retval Core::ERROR_GENERAL: The application could not be woken to the requested state.
    virtual Core::hresult Wake(const string& appInstanceId, const RuntimeState runtimeState) = 0;

    /** @brief Suspend the application */
    // @details Transitions the application container into the suspended state.
    // @text suspend
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @retval Core::ERROR_NONE: The application was suspended successfully.
    // @retval Core::ERROR_GENERAL: The application could not be suspended.
    virtual Core::hresult Suspend(const string& appInstanceId) = 0;

    /** @brief Resume the application */
    // @details Resumes the application container from its suspended state.
    // @text resume
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @retval Core::ERROR_NONE: The application was resumed successfully.
    // @retval Core::ERROR_GENERAL: The application could not be resumed.
    virtual Core::hresult Resume(const string& appInstanceId) = 0;

    /** @brief Terminate the application */
    // @details Stops the application container and terminates its process.
    // @text terminate
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @retval Core::ERROR_NONE: The application was terminated successfully.
    // @retval Core::ERROR_GENERAL: The application could not be terminated.
    virtual Core::hresult Terminate(const string& appInstanceId) = 0;

    /**@brief  Kill the application */
    // @details Immediately stops the application container process.
    // @text kill
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @retval Core::ERROR_NONE: The application process was killed successfully.
    // @retval Core::ERROR_GENERAL: The application process could not be killed.
    virtual Core::hresult Kill(const string& appInstanceId) = 0;

    /** @brief get info of the application */
    // @details Retrieves runtime resource usage and other application/container statistics as a JSON string.
    // @text getInfo
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @param info: On success, receives a JSON string containing statistics such as RAM, CPU, and GPU memory usage.
    // @example info: "{\"cpuUsage\":12,\"memoryUsage\":256}"
    // @retval Core::ERROR_NONE: Application information was retrieved successfully.
    // @retval Core::ERROR_GENERAL: Application information could not be retrieved.
    virtual Core::hresult GetInfo(const string& appInstanceId, string& info /* @out */) = 0;

    /** @brief annotates are sent to Dobby for recording */
    // @details Records a key/value annotation for the specified running container.
    // @text annotate
    // @param appInstanceId: Identifier of the application/container instance.
    // @example appInstanceId: "org.example.app.instance1"
    // @param key: Annotation name to record for the running container.
    // @example key: "sessionId"
    // @param value: Value associated with the annotation name.
    // @example value: "session-123"
    // @retval Core::ERROR_NONE: The annotation was recorded successfully.
    // @retval Core::ERROR_GENERAL: The annotation could not be recorded.
    virtual Core::hresult Annotate(const string& appInstanceId, const string& key, const string& value) = 0;

    /** @brief mounts a new host directory/device inside container */
    // @details Mounts a host directory or device into a container.
    // @text mount
    // @retval Core::ERROR_NONE: The host directory or device was mounted successfully.
    // @retval Core::ERROR_GENERAL: The host directory or device could not be mounted.
    virtual Core::hresult Mount() = 0;

    /** @brief unmounts a new host directory/device inside container */
    // @details Unmounts a host directory or device from a container.
    // @text unmount
    // @retval Core::ERROR_NONE: The host directory or device was unmounted successfully.
    // @retval Core::ERROR_GENERAL: The host directory or device could not be unmounted.
    virtual Core::hresult Unmount() = 0;
};
} // namespace Exchange
} // namespace WPEFramework
