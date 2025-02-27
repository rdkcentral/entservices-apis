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

    /// Interface implemented by each Thunder component that needs to react to DEVICE_OPTIMIZE system mode state activation requests.
    struct EXTERNAL IDeviceOptimizeStateActivator : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_OPTIMIZE_STATE_ACTIVATOR };

        /// Requests the component to asynchronously transition to the new state.
        /// @param[in] newState     The new target state to transition to.
        virtual void Request(const string&  newState  /* @in @text newState*/) = 0;
    };
}
}
