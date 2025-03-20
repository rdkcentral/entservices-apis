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

// @json 1.0.0 @text:keep

struct EXTERNAL INativeJS : virtual public Core::IUnknown {
    enum { ID = ID_NATIVEJS };

    /** Allow the plugin to initialize to use service object */
    // @json:omit
    virtual uint32_t Initialize(string waylandDisplay) = 0;

    /** Allow the plugin to deinitialize to use service object */
    // @json:omit
    virtual uint32_t Deinitialize() = 0;

    /** Launches the NativeJS plugin */
    // @text launchApplication
    // @brief Launch a NativeJS application.
    // @param url The URL of the application to launch.
    // @param options Additional options for launching the application.
    virtual uint32_t LaunchApplication(const std::string url, const std::string options) = 0;

    /** Stops the NativeJS plugin */
    // @text destroyApplication
    // @brief Destroy a running NativeJS application.
    // @param url The URL of the application to destroy.
    virtual uint32_t DestroyApplication(const std::string url) = 0;
};

} // Exchange
} // WPEFramework
