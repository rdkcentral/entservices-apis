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
// @text:keep
struct EXTERNAL IRuntimeManager : virtual public Core::IUnknown {
    enum { ID = ID_RUNTIME_MANAGER };

    using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
    using IValueIterator = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

    enum ContainerState : uint8_t {
        CONTAINER_STATE_UNKNOWN     = 0   /* @text CONTAINER_STATE_UNKNOWN */,
        CONTAINER_STATE_STARTING    = 1   /* @text CONTAINER_STATE_STARTING */,
        CONTAINER_STATE_RUNNING     = 2   /* @text CONTAINER_STATE_RUNNING */,
        CONTAINER_STATE_SUSPENDED   = 3   /* @text CONTAINER_STATE_SUSPENDED */,
        CONTAINER_STATE_HIBERNATING = 4   /* @text CONTAINER_STATE_HIBERNATING */,
        CONTAINER_STATE_HIBERNATED  = 5   /* @text CONTAINER_STATE_HIBERNATED */,
        CONTAINER_STATE_WAKING      = 6   /* @text CONTAINER_STATE_WAKING */,
        CONTAINER_STATE_TERMINATING = 7   /* @text CONTAINER_STATE_TERMINATING */,
        CONTAINER_STATE_TERMINATED  = 8   /* @text CONTAINER_STATE_TERMINATED */
    };

    // @event 
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_RUNTIME_MANAGER_NOTIFICATION };
 
        // @brief Notifies container is started
        // @text onStarted
        // @param appInstanceId App identifier for the application/container
        virtual void OnStarted(const string& appInstanceId) {};
 
        // @brief Notifies container is shutdown
        // @text onTerminated
        // @param appInstanceId App identifier for the application/container
        virtual void OnTerminated(const string& appInstanceId) {};
 
        // @brief Notifies failure in container execution
        // @text onFailure
        // @param appInstanceId App identifier for the application/container
        // @param error error string will send if there is failure
        virtual void OnFailure(const string& appInstanceId, const string& error) {};
 
        // @brief Notifies state of container
        // @text onStateChanged
        // @param appInstanceId App identifier for the application/container
        // @param state state of the container
        virtual void OnStateChanged(const string& appInstanceId, const ContainerState state) {};
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** @brief Run the application */
    // @text run
    // @param appInstanceId App identifier for the application/container
    // @param appPath path of the container/application
    // @param runtimePath(optional) run time path of the container/application
    // @param envVars The tokens from the Firebolt Gateway will be passed as part of the environmentVars
    // @param userId userId used to identify the user
    // @param userId groupid used to represent a group
    // @param ports(optional) array of socket ports to allow
    // @param paths(optional) paths contains an additional set of files and directories to map into the container
    // @param debugSettings(optional) can include additional ports to open for gdb and other settings for debugging
    virtual Core::hresult Run(const string& appInstanceId, const string& appPath, const string& runtimePath, IStringIterator* const& envVars, const uint32_t userId, const uint32_t groupId, IValueIterator* const& ports, IStringIterator* const& paths, IStringIterator* const& debugSettings) = 0;

    /** @brief Hibernate the application */
    // @text hibernate
    // @param appInstanceId App identifier for the application/container
    virtual Core::hresult Hibernate(const string& appInstanceId) = 0;

    /** @brief Wake the application to given state */
    // @text wake
    // @param appInstanceId App identifier for the application/container
    // @param state state of the container
    virtual Core::hresult Wake(const string& appInstanceId, const ContainerState state) = 0;

    /** @brief Suspend the application */
    // @text suspend
    // @param appInstanceId App identifier for the application/container
    virtual Core::hresult Suspend(const string& appInstanceId) = 0;

    /** @brief Resume the application */
    // @text resume
    // @param appInstanceId App identifier for the application/container
    virtual Core::hresult Resume(const string& appInstanceId) = 0;

    /** @brief Terminate the application */
    // @text terminate
    // @param appInstanceId App identifier for the application/container
    virtual Core::hresult Terminate(const string& appInstanceId) = 0;

    /**@brief  Kill the application */
    // @text kill
    // @param appInstanceId App identifier for the application/container
    virtual Core::hresult Kill(const string& appInstanceId) = 0;

    /** @brief get info of the application */
    // @text getInfo
    // @param appInstanceId App identifier for the application/container
    // @param info This should contain information like RAM, CPU usage, GPU memory, and other stats, come as json string format
    virtual Core::hresult GetInfo(const string& appInstanceId, string& info /* @out */) const = 0;

    /** @brief annotates are sent to Dobby for recording */
    // @text annotate
    // @param appInstanceId App identifier for the application/container
    // @param key set a dictionary of key for running containers
    // @param key set a dictionary of value of key for running containers
    virtual Core::hresult Annotate(const string& appInstanceId, const string& key, const string& value) = 0;

    /** @brief mounts a new host directory/device inside container */
    // @text mount
    virtual Core::hresult Mount() = 0;

    /** @brief unmounts a new host directory/device inside container */
    // @text unmount
    virtual Core::hresult Unmount() = 0;
};
} // namespace Exchange
} // namespace WPEFramework
