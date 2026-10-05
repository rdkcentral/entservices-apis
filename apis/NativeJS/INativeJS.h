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
    // @brief Initializes the NativeJS plugin with a specific Wayland display.
    // @details This method prepares the NativeJS runtime to bind to the supplied Wayland display so application instances can be created and executed in the target environment.
    // @param waylandDisplay: Name of the Wayland display used by the NativeJS service.
    // @example waylandDisplay: "wayland-0"
    // @retval Core::ERROR_NONE: The NativeJS plugin was initialized successfully.
    virtual Core::hresult Initialize(string waylandDisplay) = 0;

    /** Allow the plugin to deinitialize to use service object */
    // @json:omit
    // @brief Deinitializes the NativeJS plugin and releases runtime resources.
    // @details This method tears down the NativeJS runtime and cleans up platform resources acquired during initialization.
    // @retval Core::ERROR_NONE: The NativeJS plugin was deinitialized successfully.
    virtual Core::hresult Deinitialize() = 0;

    /** Creates the NativeJS plugin */
    // @text createApplication
    // @brief Creates a NativeJS application instance.
    // @details This method creates a new NativeJS application using the supplied creation options and returns the identifier assigned to the application.
    // @param options:Additional creation options used to configure the application.
    // @example options: "{\"name\":\"demo\"}"
    // @param id:Identifier assigned to the newly created application.
    // @example id: 1
    // @retval Core::ERROR_NONE: The application was created successfully.
    virtual Core::hresult CreateApplication(const std::string options , uint32_t& id /* @out */) = 0;
    
    /** Run the created NativeJS plugin */
    // @text runApplication
    // @brief Runs an existing NativeJS application.
    // @details This method starts the NativeJS application referenced by the supplied identifier and loads the provided URL in that application context.
    // @param id: The ID of the application to run.
    // @example id: 1
    // @param url: The URL to load in the application.
    // @example url: "https://example.com"
    // @retval Core::ERROR_NONE: The application started successfully.
    virtual Core::hresult RunApplication(uint32_t id , const std::string url ) = 0;
    
    /** Run the created NativeJS plugin */
    // @text runJavaScript 
    // @brief Executes JavaScript in a NativeJS application instance.
    // @details This method evaluates the supplied script in the context of the target application instance to allow runtime behavior changes or setup logic.
    // @param id: The ID of the application instance executing the script.
    // @example id: 1
    // @param code: The JavaScript source code to execute.
    // @example code: "console.log('hello');"
    // @retval Core::ERROR_NONE: The script executed successfully.
    virtual Core::hresult RunJavaScript(uint32_t id , const std::string code ) = 0;
    
    /** Get all the existing NativeJS plugin */
    // @text getApplications
    // @brief Retrieves the list of existing NativeJS applications.
    // @details This method returns the current set of managed NativeJS applications so the caller can inspect or display active instances.
    // @retval Core::ERROR_NONE: The application list was retrieved successfully.
    virtual Core::hresult GetApplications() = 0;

    /** Stops the NativeJS plugin */
    // @text terminateApplication
    // @brief Terminates a running NativeJS application.
    // @details This method stops the application identified by the supplied ID and releases the resources associated with it.
    // @param id: The ID of the application to terminate.
    // @example id: 1
    // @retval Core::ERROR_NONE: The application was terminated successfully.
    virtual Core::hresult TerminateApplication(uint32_t id ) = 0;
};

} // Exchange
} // WPEFramework
