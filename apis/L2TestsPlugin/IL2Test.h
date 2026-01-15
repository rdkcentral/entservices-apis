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

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IL2Test : virtual public Core::IUnknown {
        enum { ID = ID_L2TEST };

        // @text performL2Tests
        // @brief Perform L2 tests
        // @param parameters: Input parameters as a JSON string
        // @param response: Output response as a JSON string
        // @retval ErrorCode::ERROR_NONE: Indicates success
        // @retval ErrorCode::ERROR_GENERAL: Indicates failure
        virtual Core::hresult PerformL2Tests(const string& parameters, string& response /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
 