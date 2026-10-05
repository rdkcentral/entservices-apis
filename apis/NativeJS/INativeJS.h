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
    // @brief Initialize the NativeJS plugin with the specified Wayland display.
    // @details This API initializes the NativeJS plugin with the specified Wayland display.
    // @param waylandDisplay The Wayland display to use for initialization.
    // @example waylandDisplay: "wayland-0"
    // @retval Core::ERROR_NONE: The initialization was successful.
    virtual Core::hresult Initialize(string waylandDisplay) = 0;

    /** Allow the plugin to deinitialize to use service object */
    // @json:omit
    // @brief Deinitialize the NativeJS plugin.
    // @details This API deinitializes the NativeJS plugin.
    // @retval Core::ERROR_NONE: The deinitialization was successful.
    virtual Core::hresult Deinitialize() = 0;

    /** Creates the NativeJS plugin */
    // @text createApplication
    // @brief Create a NativeJS application.
    // @details This API creates a new NativeJS application with the specified options.
    // @param options Additional options for creating the application.
    // @example options: "{ \"name\": \"MyApp\", \"version\": \"1.0.0\" }"
    // @param id This should have the id of the created application
    // @example id: 1
    // @retval Core::ERROR_NONE: The application was created successfully.
    virtual Core::hresult CreateApplication(const std::string options , uint32_t& id /* @out */) = 0;
    
    /** Run the created NativeJS plugin */
    // @text runApplication
    // @brief run a NativeJS application.
    // @details This API runs the specified NativeJS application with the given URL.
    // @param id The ID for the application to run.
    // @example id: 1
    // @param url URL for the application to run.
    // @example url: "http://example.com/myapp"
    // @retval Core::ERROR_NONE: The application was started successfully.
    virtual Core::hresult RunApplication(uint32_t id , const std::string url ) = 0;
    
    /** Run the created NativeJS plugin */
    // @text runJavaScript 
    // @brief Run a NativeJS code.
    // @details This API runs the specified JavaScript code within the NativeJS plugin.
    // @param id The ID for the code to run.
    // @example id: 1
    // @param code The JavaScript code to execute.
    // @example code: "console.log('Hello, World!');"
    // @retval Core::ERROR_NONE: The code was executed successfully.
    virtual Core::hresult RunJavaScript(uint32_t id , const std::string code ) = 0;
    
    /** Get all the existing NativeJS plugin */
    // @text getApplications
    // @brief Get details of existing plugin.
    // @details This API retrieves details of all existing NativeJS applications.
    // @retval Core::ERROR_NONE: The details were retrieved successfully.
    virtual Core::hresult GetApplications() = 0;

    /** Stops the NativeJS plugin */
    // @text terminateApplication
    // @brief Destroy a running NativeJS application.
    // @details This API terminates the specified NativeJS application.
    // @param id The ID of the application to destroy.
    // @example id: 1
    // @retval Core::ERROR_NONE: The application was terminated successfully.
    virtual Core::hresult TerminateApplication(uint32_t id ) = 0;
};

} // Exchange
} // WPEFramework
