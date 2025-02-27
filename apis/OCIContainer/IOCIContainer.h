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
        Invalid = 0,
        Starting = 1,
        Running = 2,
        Stopping = 3,
        Paused = 4,
        Stopped = 5,
        Hibernating = 6,
        Hibernated = 7,
        Awakening = 8
    };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_OCICONTAINER_NOTIFICATION };

        // @brief Notifies container is started
        // @text onContainerStarted
        virtual void OnContainerStarted(const string& containerId, const string& name) {}

        // @brief Notifies container is stopped
        // @text onContainerStopped
        virtual void OnContainerStopped(const string& containerId, const string& name) {}

        // @brief Notifies failure in container execution
        // @text onContainerFailed
        virtual void OnContainerFailed(const string& containerId, const string& name, uint32_t error) {}

        // @brief Notifies state change of container
        // @text onContainerStateChanged
        virtual void OnContainerStateChanged(const string& containerId, ContainerState state) {}
        // Possible state values {Starting, running, suspended, hibernating, hibernated, waking, terminating, terminated}
    };

    /** Register notification interface */
    virtual Core::hresult Register(INotification *notification) = 0;

    /** Unregister notification interface */
    virtual Core::hresult Unregister(INotification *notification) = 0;

    /** Provide list of containers */
    // @text listContainers
    // @param containers - out/json - string
    virtual Core::hresult ListContainers(string& containers /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Get the information about container */
    // @text getContainerInfo
    // @param containerId Identifier of container
    virtual Core::hresult GetContainerInfo(const string& containerId /* @in */, string& info /* @out @opaque */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Get the state of container */
    // @text getContainerState
    // @param containerId Identifier of container
    virtual Core::hresult GetContainerState(const string& containerId /* @in */, ContainerState& state /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Start the container from bundle */
    // @text startContainer
    // @param containerId Identifier of container
    // @param bundlePath path of application bundle
    // @param command(optional) command to run in container
    // @param westerosSocket(optional) Westeros socket container need to connect
    virtual Core::hresult StartContainer(const string& containerId /* @in */, const string& bundlePath /* @in */, const string& command /* @in */, const string& westerosSocket /* @in */, int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Start the container from dobby specification */
    // @text startContainerFromDobbySpec
    // @param containerId Identifier of container
    // @param dobbySpec dobby specification as json string
    // @param command(optional) command to run in container
    // @param westerosSocket(optional) Westeros socket container need to connect
    virtual Core::hresult StartContainerFromDobbySpec(const string& containerId /* @in */, const string& dobbySpec /* @in */, const string& command /* @in */, const string& westerosSocket /* @in */, int32_t& descriptor /* @out */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Stop the container */
    // @text stopContainer
    // @param containerId Identifier of container
    // @param force(optional) Metion forceful or graceful termination of container
    virtual Core::hresult StopContainer(const string& containerId /* @in */, bool force /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Pause the container */
    // @text pauseContainer
    // @param containerId Identifier of container
    virtual Core::hresult PauseContainer(const string& containerId /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Resume the container */
    // @text resumeContainer
    // @param containerId Identifier of container
    virtual Core::hresult ResumeContainer(const string& containerId /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Hibernate the container */
    // @text hibernateContainer
    // @param containerId Identifier of container
    virtual Core::hresult HibernateContainer(const string& containerId /* @in */, const string& options /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Wakeup the container */
    // @text wakeupContainer
    // @param containerId Identifier of container
    virtual Core::hresult WakeupContainer(const string& containerId /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Execute the command in container */
    // @text executeCommand
    // @param containerId Identifier of container
    // @param options(optional) options to be passed to command
    // @param command command to run in container
    virtual Core::hresult ExecuteCommand(const string& containerId /* @in */, const string& options /* @in */, const string& command /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** update container properties */
    // @text annotate
    // @param containerId Identifier of container
    // @param key name of property
    // @param value property data
    virtual Core::hresult Annotate(const string& containerId /* @in */, const string& key /* @in */, const string& value /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Remove container property */
    // @text removeAnnotation
    // @param containerId Identifier of container
    // @param key name of property
    virtual Core::hresult RemoveAnnotation(const string& containerId /* @in */, const string& key /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Mount a path in container */
    // @text mount
    // @param containerId Identifier of container
    // @param source path source to mount
    // @param target mount target inside container
    // @param type type of mounting
    // @param options options for mounting
    virtual Core::hresult Mount(const string& containerId /* @in */, const string& source /* @in */, const string& target /* @in */, const string& type /* @in */, const string& options /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;

    /** Unmount a path in container */
    // @text unmount
    // @param containerId Identifier of container
    // @param target path to unmount from container
    virtual Core::hresult Unmount(const string& containerId /* @in */, const string& target /* @in */, bool& success /* @out */, string& errorReason /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
