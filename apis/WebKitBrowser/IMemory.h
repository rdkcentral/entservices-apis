/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

//already added the below so it is not forgotten when to start generating proxy/stubs for this
// @stubgen:include <com/IIteratorType.h>
 
namespace WPEFramework {
namespace Exchange {

    // This interface allows for retrieval of memory usage specific to the implementor
    // of the interface
    // @stubgen:omit
    struct EXTERNAL IMemory : virtual public Core::IUnknown {
        enum { ID = ID_MEMORY };

        // @brief Retrieves the resident memory usage.
        // @details Reports memory currently resident in physical memory, in bytes.
        // @return Resident memory usage in bytes.
        virtual uint64_t Resident() const = 0;

        // @brief Retrieves the allocated memory usage.
        // @details Reports memory allocated by the interface implementor, in bytes.
        // @retval uint64_t: Allocated memory usage in bytes
        virtual uint64_t Allocated() const = 0;

        // @brief Retrieves the shared memory usage.
        // @details Reports memory shared with other processes, in bytes.
        // @retval uint64_t: Shared memory usage in bytes
        virtual uint64_t Shared() const = 0;

        // @brief Retrieves the number of processes.
        // @details Reports the number of processes associated with the memory interface.
        // @retval uint8_t: Number of processes
        virtual uint8_t Processes() const = 0;

        // @brief Checks whether the memory interface is operational.
        // @details Returns whether the implementing component is operational.
        // @retval bool: True when operational; otherwise false
        virtual bool IsOperational() const = 0;
    };

    // @stubgen:omit
    struct EXTERNAL IProcessMemory : public IMemory {
        enum { ID = ID_PROCESSMEMORY };

        // @brief Retrieves the process identifier.
        // @details Returns the identifier of the process represented by this interface.
        // @retval uint32_t: Identifier of the process
        virtual uint32_t Identifier() const = 0;

        // @brief Retrieves the process name.
        // @details Returns the name of the process represented by this interface.
        // @retval string: Name of the process
        virtual string Name() const = 0;
    };

    // @stubgen:omit
    struct EXTERNAL IMemoryExtended : virtual public Core::IUnknown {
        enum { ID = ID_MEMORYEXTENDED };

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // @brief Lists process names.
        // @details Provides an iterator over the process names available to this memory interface.
        // @param processnames: Receives an iterator over the process names
        // @example processnames: ["WebKitBrowser", "WebKitBrowser-GPU"]
        // @retval Core::ERROR_NONE: Process list retrieved successfully
        virtual uint32_t Processes(IStringIterator*& processnames /* @out */) const = 0;

        // @brief Retrieves memory information for a named process.
        // @details Returns a process memory interface for the requested process.
        // @param processname: Name of the process to retrieve
        // @example processname: "WebKitBrowser"
        // @param process: Receives the process memory interface
        // @example process: IProcessMemory instance
        // @retval Core::ERROR_NONE: Process memory interface retrieved successfully
        virtual uint32_t Process(const string& processname, IProcessMemory*& process /* @out */ ) const = 0;
    };
}
}

