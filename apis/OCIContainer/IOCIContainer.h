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

        // @brief Notifies that a container has started.
        // @details This event is sent when a container process reaches its running state after startup has completed successfully.
        // @text onContainerStarted
        // @param containerId: Unique identifier of the started container.
        // @example containerId: "container-1"
        // @param name: User-visible name assigned to the container.
        // @example name: "my-app"
        virtual void OnContainerStarted(const string& containerId, const string& name) {}

        // @brief Notifies that a container has stopped.
        // @details This event is emitted when a container exits, including the associated process exit code.
        // @text onContainerStopped
        // @param containerId: Unique identifier of the stopped container.
        // @example containerId: "container-1"
        // @param name: User-visible name assigned to the container.
        // @example name: "my-app"
        // @param exitCode: Exit code returned by the container process.
        // @example exitCode: 0
        virtual void OnContainerStopped(const string& containerId, const string& name, int32_t exitCode) {}

        // @brief Notifies of a failure during container execution.
        // @details This event is raised for failures encountered during startup, shutdown, hibernation, or wakeup transitions.
        // @text onContainerFailed
        // @param containerId: Unique identifier of the container that failed.
        // @example containerId: "container-1"
        // @param name: User-visible name assigned to the container.
        // @example name: "my-app"
        // @param error: Platform-specific error code describing the failure.
        // @example error: 5001
        virtual void OnContainerFailed(const string& containerId, const string& name, uint32_t error) {}

        // @brief Notifies that the state of a container changed.
        // @details This event reports a lifecycle transition for the container and includes the new state value.
        // @text onContainerStateChanged
        // @param containerId: Unique identifier of the container whose state changed.
        // @example containerId: "container-1"
        // @param state: New state reported for the container.
        // @example state: RUNNING;
        virtual void OnContainerStateChanged(const string& containerId, ContainerState state) {}
        // Possible state values {Starting, running, suspended, hibernating, hibernated, waking, terminating, terminated}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    // @brief Provides a list of containers.
    // @details Returns the current container inventory in a serialized JSON payload and the success status of the operation.
    // @text listContainers
    // @param containers: Serialized list of containers returned by the call.
    // @example containers: "[{\"id\":\"container-1\",\"name\":\"my-app\"}]"
    // @param success: Indicates whether the request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the request failed.
    // @example errorReason: "Failed to retrieve container list"
    // @retval Core::ERROR_NONE: The container list was retrieved successfully.
    virtual Core::hresult ListContainers(string& containers /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Gets the information for a container.
    // @details Returns the serialized metadata for the specified container and includes the request status and any error reason.
    // @text getContainerInfo
    // @param containerId: Identifier of the container to inspect.
    // @example containerId: "container-1"
    // @param info: Serialized metadata for the target container.
    // @example info: "{\"id\":\"container-1\",\"name\":\"my-app\"}"
    // @param success: Indicates whether the lookup completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the lookup failed.
    // @example errorReason: "Failed to retrieve container list"
    // @retval Core::ERROR_NONE: The container information was retrieved successfully.
    virtual Core::hresult GetContainerInfo(const string& containerId , string& info /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Gets the current state of a container.
    // @details Returns the lifecycle state of the specified container, along with the request result and any error description.
    // @text getContainerState
    // @param containerId: Identifier of the container whose state is requested.
    // @example containerId: "container-1"
    // @param state: Current container state returned by the call.
    // @example state: RUNNING
    // @param success: Indicates whether the state lookup completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the lookup failed.
    // @example errorReason: "Failed to retrieve container state"
    // @retval Core::ERROR_NONE: The container state was retrieved successfully.
    virtual Core::hresult GetContainerState(const string& containerId , ContainerState& state /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Starts a container from a bundle.
    // @details Creates and launches a container from the supplied application bundle, optionally injecting a command and a Westeros socket path.
    // @text startContainer
    // @param containerId: Identifier for the new container instance.
    // @example containerId: "container-1"
    // @param bundlePath: Filesystem path to the application bundle used to start the container.
    // @example bundlePath: "/bundle/path"
    // @param command: Optional command to run inside the container.
    // @example command: ""
    // @param westerosSocket: Optional Westeros socket path to connect the container to.
    // @example westerosSocket: ""
    // @param descriptor:File descriptor associated with the started container.
    // @example descriptor: -1
    // @param success: Indicates whether the start request succeeded.
    // @example success: true
    // @param errorReason: Human-readable error description if the start request failed.
    // @example errorReason: "Failed to start container"
    // @retval Core::ERROR_NONE: The container started successfully.
    virtual Core::hresult StartContainer(const string& containerId , const string& bundlePath , const string& command , const string& westerosSocket , int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Starts a container from a Dobby specification.
    // @details Creates and launches a container from a serialized Dobby spec, optionally injecting a command and a Westeros socket path.
    // @text startContainerFromDobbySpec
    // @param containerId: Identifier for the new container instance.
    // @example containerId: "container-1"
    // @param dobbySpec: Serialized Dobby specification used to start the container.
    // @example dobbySpec: "{\"spec\":true}"
    // @param command: Optional command to run inside the container.
    // @example command: ""
    // @param westerosSocket: Optional Westeros socket path to connect the container to.
    // @example westerosSocket: ""
    // @param descriptor: File descriptor associated with the started container.
    // @example descriptor: -1
    // @param success: Indicates whether the start request succeeded.
    // @example success: true
    // @param errorReason: Human-readable error description if the start request failed.
    // @example errorReason: "Failed to start container"
    // @retval Core::ERROR_NONE: The container started successfully.
    virtual Core::hresult StartContainerFromDobbySpec(const string& containerId , const string& dobbySpec , const string& command , const string& westerosSocket , int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Stops a container.
    // @details Terminates the specified container, either gracefully or forcefully based on the supplied flag.
    // @text stopContainer
    // @param containerId: Identifier of the container to stop.
    // @example containerId: "container-1"
    // @param force: When true, forces an immediate termination; otherwise a graceful shutdown is requested.
    // @example force: true
    // @param success: Indicates whether the stop request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the stop request failed.
    // @example errorReason: "Failed to stop container"
    // @retval Core::ERROR_NONE: The container was stopped successfully.
    virtual Core::hresult StopContainer(const string& containerId , bool force , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Pauses a container.
    // @details Suspends the target container while preserving its state for later resume.
    // @text pauseContainer
    // @param containerId: Identifier of the container to pause.
    // @example containerId: "container-1"
    // @param success: Indicates whether the pause request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the pause request failed.
    // @example errorReason: "Failed to pause container"
    // @retval Core::ERROR_NONE: The container was paused successfully.
    // @retval Core::ERROR_GENERAL: The container could not be paused.
    // @example Example usage: bool success = false; std::string errorReason; container.PauseContainer("container-1", success, errorReason);
    virtual Core::hresult PauseContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Resumes a paused container.
    // @details Restores a paused container to its active state when the runtime is ready to resume operations.
    // @text resumeContainer
    // @param containerId: Identifier of the container to resume.
    // @example containerId: "container-1"
    // @param success: Indicates whether the resume request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the resume request failed.
    // @example errorReason: "Failed to resume container"
    // @retval Core::ERROR_NONE: The container was resumed successfully.
    // @retval Core::ERROR_GENERAL: The container could not be resumed.
    // @example Example usage: bool success = false; std::string errorReason; container.ResumeContainer("container-1", success, errorReason);
    virtual Core::hresult ResumeContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Hibernates a container.
    // @details Saves the state of the target container and places it into a hibernated state using the supplied runtime options.
    // @text hibernateContainer
    // @param containerId: Identifier of the container to hibernate.
    // @example containerId: "container-1"
    // @param options: Additional hibernation options passed to the runtime.
    // @example options: "save-state"
    // @param success: Indicates whether the hibernation request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the hibernation request failed.
    // @example errorReason: "Failed to hibernate container"
    // @retval Core::ERROR_NONE: The container was hibernated successfully.
    // @retval Core::ERROR_GENERAL: The container could not be hibernated.
    // @example Example usage: bool success = false; std::string errorReason; container.HibernateContainer("container-1", "save-state", success, errorReason);
    virtual Core::hresult HibernateContainer(const string& containerId , const string& options , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Wakes a hibernated container.
    // @details Restores the specified container from a hibernated state to an active runtime state.
    // @text wakeupContainer
    // @param containerId: Identifier of the container to wake.
    // @example containerId: "container-1"
    // @param success: Indicates whether the wakeup request completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the wakeup request failed.
    // @example errorReason: "Failed to wake container"
    // @retval Core::ERROR_NONE: The container was woken successfully.
    // @retval Core::ERROR_GENERAL: The container could not be woken.
    // @example Example usage: bool success = false; std::string errorReason; container.WakeupContainer("container-1", success, errorReason);
    virtual Core::hresult WakeupContainer(const string& containerId , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Executes a command in a container.
    // @details Runs the provided command inside the target container with any optional runtime arguments.
    // @text executeCommand
    // @param containerId: Identifier of the container to execute the command in.
    // @example containerId: "container-1"
    // @param options: Optional command-line options passed to the running process.
    // @example options: "--verbose"
    // @param command: Command to run inside the container.
    // @example command: "ls /"
    // @param success: Indicates whether the command completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the command failed.
    // @example errorReason: "Failed to execute command"
    // @retval Core::ERROR_NONE: The command executed successfully.
    // @retval Core::ERROR_GENERAL: The command could not be executed.
    // @example Example usage: bool success = false; std::string errorReason; container.ExecuteCommand("container-1", "--verbose", "ls /", success, errorReason);
    virtual Core::hresult ExecuteCommand(const string& containerId , const string& options , const string& command , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Updates a container property.
    // @details Adds or updates the named key-value property associated with the container.
    // @text annotate
    // @param containerId: Identifier of the container to annotate.
    // @example containerId: "container-1"
    // @param key: Name of the property to set.
    // @example key: "label"
    // @param value: Value assigned to the property.
    // @example value: "production"
    // @param success: Indicates whether the property update completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the update failed.
    // @example errorReason: "Failed to update property"
    // @retval Core::ERROR_NONE: The container property was updated successfully.
    virtual Core::hresult Annotate(const string& containerId , const string& key , const string& value , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Removes a container property.
    // @details Deletes the named property from the specified container metadata.
    // @text removeAnnotation
    // @param containerId: Identifier of the container to modify.
    // @example containerId: "container-1"
    // @param key: Name of the property to remove.
    // @example key: "label"
    // @param success: Indicates whether the removal completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the removal failed.
    // @example errorReason: "Failed to remove property"
    // @retval Core::ERROR_NONE: The container property was removed successfully.
    virtual Core::hresult RemoveAnnotation(const string& containerId , const string& key , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Mounts a path into a container.
    // @details Binds the source path into the container target location using the requested mount type and options.
    // @text mount
    // @param containerId: Identifier of the container to mount into.
    // @example containerId: "container-1"
    // @param source: Source path to mount.
    // @example source: "/host/path"
    // @param target: Target path inside the container.
    // @example target: "/container/path"
    // @param type: Type of mount operation to perform.
    // @example type: "bind"
    // @param options: Mount options to apply.
    // @example options: "ro"
    // @param success: Indicates whether the mount operation completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the mount failed.
    // @example errorReason: "Failed to mount path"
    // @retval Core::ERROR_NONE: The path was mounted successfully.
    virtual Core::hresult Mount(const string& containerId , const string& source , const string& target , const string& type , const string& options , bool& success /* @out */, string& errorReason /* @out */) = 0;

    // @brief Unmounts a path from a container.
    // @details Removes the mount for the specified path inside the target container.
    // @text unmount
    // @param containerId: Identifier of the container to unmount from.
    // @example containerId: "container-1"
    // @param target: Path inside the container to unmount.
    // @example target: "/container/path"
    // @param success: Indicates whether the unmount operation completed successfully.
    // @example success: true
    // @param errorReason: Human-readable error description if the unmount failed.
    // @example errorReason: "Failed to unmount path"
    // @retval Core::ERROR_NONE: The path was unmounted successfully.
    virtual Core::hresult Unmount(const string& containerId , const string& target , bool& success /* @out */, string& errorReason /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
