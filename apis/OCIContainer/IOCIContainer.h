/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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
struct EXTERNAL IOCIContainer : virtual public Core::IUnknown {

    enum { ID = ID_OCICONTAINER };

    enum ContainerState : uint8_t {
        INVALID = 0,
        STARTING = 1,
        RUNNING = 2,
        STOPPING = 3,
        PAUSED = 4,
        STOPPED = 5,
        HIBERNATING = 6,
        HIBERNATED = 7,
        AWAKENING = 8
    };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_OCICONTAINER_NOTIFICATION };

        // @brief Notifies container is started
        // @text onContainerStarted
        // @details This event is triggered when the container has successfully started.
        // @param containerId: Identifier of the container that started
        // @example containerId: "container123"
        // @param name: Name of the container
        // @example name: "myContainer"
        virtual void OnContainerStarted(const string& containerId, const string& name) {}

        // @brief Notifies container is stopped
        // @text onContainerStopped
        // @details This event is triggered when the container has successfully stopped.
        // @param containerId: Identifier of the container that stopped
        // @example containerId: "container123"
        // @param name: Name of the container
        // @example name: "myContainer"
        // @param exitCode: Exit code of the container process
        // @example exitCode: 0
        virtual void OnContainerStopped(const string& containerId, const string& name, int32_t exitCode) {}

        // @brief Notifies failure in container execution, only triggered for states start, stop, hibernate, wakeup.
        // @text onContainerFailed
        // @details This event is triggered when the container has failed during execution.
        // @param containerId: Identifier of the container that failed
        // @example containerId: "container123"
        // @param name: Name of the container
        // @example name: "myContainer"
        // @param error: Error code indicating the failure reason
        // @example error: 1
        virtual void OnContainerFailed(const string& containerId, const string& name, uint32_t error) {}

        // @brief Notifies state change of container
        // @text onContainerStateChanged
    // @details This event is triggered when the state of the container changes.
    // @param containerId: Identifier of the container whose state changed
    // @example containerId: "container123"
    // @param state: New state of the container
    // @example state: RUNNING
        virtual void OnContainerStateChanged(const string& containerId, ContainerState state) {}
        // Possible state values {Starting, running, suspended, hibernating, hibernated, waking, terminating, terminated}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    // @brief Provide list of containers
    // @text listContainers
    // @details This API provides the list of all containers managed by the system.
    // @param containers: Output list of containers in JSON format
    // @example containers: "[{\"containerId\": \"container123\", \"name\": \"myContainer\", \"state\": \"running\"}]"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: ""
    // @retval Core::ERROR_NONE: Indicates successful retrieval of the container list
    virtual Core::hresult ListContainers(string& containers /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Get the information about a specific container
    // @text getContainerInfo
    // @details This API retrieves detailed information about a specific container identified by its container ID.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param info: Detailed information about the container in JSON format
    // @example info: "{\"containerId\": \"container123\", \"name\": \"myContainer\", \"state\": \"running\"}"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to retrieve container information"
    // @retval Core::ERROR_NONE: Indicates successful retrieval of the container information
    virtual Core::hresult GetContainerInfo(const string& containerId , string& info /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Get the state of container
    // @text getContainerState
    // @details This API retrieves the current state of a specific container identified by its container ID.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param state: Current state of the container
    // @example state: "running"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to retrieve container state"
    // @retval Core::ERROR_NONE: Indicates successful retrieval of the container state
    virtual Core::hresult GetContainerState(const string& containerId , ContainerState& state /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Start the container from bundle
    // @text startContainer
    // @details This API starts a container using the specified application bundle.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param bundlePath: Path of the application bundle
    // @example bundlePath: "/path/to/bundle"
    // @param command: Command to run in the container
    // @example command: "/bin/bash"
    // @param westerosSocket: Westeros socket the container needs to connect to
    // @example westerosSocket: "/tmp/westeros.sock"
    // @param descriptor: File descriptor associated with the container
    // @example descriptor: 5
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to start container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult StartContainer(const string& containerId , const string& bundlePath , const string& command , const string& westerosSocket , int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Start the container from dobby specification
    // @text startContainerFromDobbySpec
    // @details This API starts a container using the specified dobby specification.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param dobbySpec: Dobby specification as a JSON string
    // @example dobbySpec: "{\"containerId\": \"container123\", \"name\": \"myContainer\"}"
    // @param command: Command to run in the container
    // @example command: "/bin/bash"
    // @param westerosSocket: Westeros socket the container needs to connect to
    // @example westerosSocket: "/tmp/westeros.sock"
    // @param descriptor: File descriptor associated with the container
    // @example descriptor: 5
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to start container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult StartContainerFromDobbySpec(const string& containerId , const string& dobbySpec , const string& command , const string& westerosSocket , int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Stop the container
    // @text stopContainer
    // @details This API stops the specified container, either forcefully or gracefully based on the 'force' parameter.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param force: Mention forceful or graceful termination of the container
    // @example force: true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to stop container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult StopContainer(const string& containerId , bool force , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Pause the container
    // @text pauseContainer
    // @details This API pauses the specified container, temporarily halting its execution.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to pause container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult PauseContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Resume the container
    // @text resumeContainer
    // @details This API resumes the specified container, allowing it to continue execution.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to resume container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult ResumeContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Hibernate the container
    // @text hibernateContainer
    // @details This API hibernates the specified container, saving its state and freeing up system resources.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param options: Options to be passed to the hibernate command
    // @example options: "--force"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to hibernate container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult HibernateContainer(const string& containerId , const string& options , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Wakeup the container
    // @text wakeupContainer
    // @details This API wakes up the specified container, restoring it from a hibernated state.
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to wakeup container"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult WakeupContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Execute the command in container
    // @text executeCommand
    // @details Executes the specified command within the container
    // @param containerId: Identifier of the container
    // @example containerId: "container123"
    // @param options: Options to be passed to the command
    // @example options: "-l"
    // @param command: Command to run in the container
    // @example command: "/bin/bash"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @param errorReason: Provides the reason for failure if the operation was not successful
    // @example errorReason: "Failed to execute command"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult ExecuteCommand(const string& containerId , const string& options , const string& command , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Update container properties
    // @text annotate
    // @details Updates the specified property of the container
    // @param containerId: Identifier of container
    // @example containerId: "container123"
    // @param key: name of property
    // @example key: "propertyName"
    // @param value: property data
    // @example value: "propertyValue"
    // @param success: indicates whether the annotate operation was successful
    // @example success: true
    // @param errorReason: provides the reason for failure if any
    // @example errorReason: "Failed to update container property"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult Annotate(const string& containerId , const string& key , const string& value , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Remove container property
    // @text removeAnnotation
    // @details Removes the specified property from the container
    // @param containerId: Identifier of container
    // @example containerId: "container123"
    // @param key: name of property
    // @example key: "propertyName"
    // @param success: indicates whether the remove annotation operation was successful
    // @example success: true
    // @param errorReason: provides the reason for failure if any
    // @example errorReason: "Failed to remove annotation"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult RemoveAnnotation(const string& containerId , const string& key , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Mount a path in container
    // @text mount
    // @details Mounts the specified source path to the target path inside the container
    // @param containerId: Identifier of container
    // @param source: path source to mount
    // @example source: "/host/path"
    // @param target: mount target inside container
    // @example target: "/container/path"
    // @param type: type of mounting
    // @example type: "bind"
    // @param options: options for mounting
    // @example options: "rw"
    // @param success: indicates whether the mount operation was successful
    // @example success: true
    // @param errorReason: provides the reason for failure if any
    // @example errorReason: "Failed to mount path"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult Mount(const string& containerId , const string& source , const string& target , const string& type , const string& options , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Unmount a path in container
    // @text unmount
    // @details Unmounts the specified target path from the container
    // @param containerId: Identifier of container
    // @example containerId: "container123"
    // @param target: path to unmount from container
    // @example target: "/container/path"
    // @param success: indicates whether the unmount operation was successful
    // @example success: true
    // @param errorReason: provides the reason for failure if any
    // @example errorReason: "Failed to unmount path"
    // @retval Core::ERROR_NONE: Indicates successful state change
    virtual Core::hresult Unmount(const string& containerId , const string& target , bool& success /* @out */, string& errorReason /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
