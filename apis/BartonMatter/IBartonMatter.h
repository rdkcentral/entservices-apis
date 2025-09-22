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

struct EXTERNAL IBartonMatter : virtual public Core::IUnknown {
    enum { ID = ID_BARTONMATTER };

    /** Allow the plugin to initialize to use service object */
    // @json:omit
    virtual Core::hresult Initialize(string waylandDisplay) = 0;

    /** Allow the plugin to deinitialize to use service object */
    // @json:omit
    virtual Core::hresult Deinitialize() = 0;

    /** Creates the BartonMatter plugin */
    // @text createApplication
    // @brief Create a BartonMatter application.
    // @param options Additional options for creating the application.
    // @param id This should have the id of the created application
    virtual Core::hresult CreateApplication(const std::string options /* @in */, uint32_t& id /* @out */) = 0;
    
    /** Run the created BartonMatter plugin */
    // @text runApplication
    // @brief run a BartonMatter application.
    // @param id The ID for the application to run.
    // @param url URL for the application to run.
    virtual Core::hresult RunApplication(uint32_t id /* @in */, const std::string url /* @in */) = 0;
    
    /** Run the created BartonMatter plugin */
    // @text runJavaScript 
    // @brief run a BartonMatter code.
    // @param id The ID for the code to run.
    // @param options Additional options for creating the application.
    virtual Core::hresult RunJavaScript(uint32_t id /* @in */, const std::string code /* @in */) = 0;
    
    /** Get all the existing BartonMatter plugin */
    // @text getApplications
    // @brief Get details of existing plugin.
    virtual Core::hresult GetApplications() = 0;

    /** Stops the BartonMatter plugin */
    // @text terminateApplication
    // @brief Destroy a running BartonMatter application.
    // @param id The ID of the application to destroy.
    virtual Core::hresult TerminateApplication(uint32_t id /* @in */) = 0;
};

} // Exchange
} // WPEFramework
