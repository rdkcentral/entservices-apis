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

#include <com/com.h>
#include <core/core.h>
#include "Ids.h"

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0
    struct EXTERNAL IProcessWatcher : virtual public Core::IUnknown {

        enum { ID = ID_PROCESS_WATCHER };

        ~IProcessWatcher() override = default;

        // @brief Return the API version number
        virtual Core::hresult GetApiVersionNumber(int& version /* @out */) = 0;

        // @brief Return current resource state
        virtual Core::hresult GetState() = 0;

        // @brief Return system resource information (output of `top -b -n1`)
        virtual Core::hresult GetSystemResourceInfo(string& info /* @out */) = 0;

        // @brief Kill a process by PID (sends SIGKILL via ResourceMonitor)
        virtual Core::hresult KillProcess(const int pid /* @in */, bool& result /* @out */) = 0;

    }; // struct IProcessWatcher

} // namespace Exchange
} // namespace WPEFramework
