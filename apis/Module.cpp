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

#include "Module.h"

MODULE_NAME_DECLARATION(BUILD_REFERENCE)

#include "UnifiedCASManagement/IUnifiedCASManagement.h"

// Enum conversion tables for COM-RPC serialization
ENUM_CONVERSION_BEGIN(WPEFramework::Exchange::IUnifiedCASManagement::TuneMode)
    { WPEFramework::Exchange::IUnifiedCASManagement::TuneMode::MODE_NONE, _TXT("MODE_NONE") },
    { WPEFramework::Exchange::IUnifiedCASManagement::TuneMode::MODE_LIVE, _TXT("MODE_LIVE") },
    { WPEFramework::Exchange::IUnifiedCASManagement::TuneMode::MODE_RECORD, _TXT("MODE_RECORD") },
    { WPEFramework::Exchange::IUnifiedCASManagement::TuneMode::MODE_PLAYBACK, _TXT("MODE_PLAYBACK") }
ENUM_CONVERSION_END(WPEFramework::Exchange::IUnifiedCASManagement::TuneMode)

ENUM_CONVERSION_BEGIN(WPEFramework::Exchange::IUnifiedCASManagement::ManagementType)
    { WPEFramework::Exchange::IUnifiedCASManagement::ManagementType::MANAGE_FULL, _TXT("MANAGE_FULL") },
    { WPEFramework::Exchange::IUnifiedCASManagement::ManagementType::MANAGE_NO_PSI, _TXT("MANAGE_NO_PSI") },
    { WPEFramework::Exchange::IUnifiedCASManagement::ManagementType::MANAGE_NO_TUNER, _TXT("MANAGE_NO_TUNER") }
ENUM_CONVERSION_END(WPEFramework::Exchange::IUnifiedCASManagement::ManagementType)

ENUM_CONVERSION_BEGIN(WPEFramework::Exchange::IUnifiedCASManagement::DataSource)
    { WPEFramework::Exchange::IUnifiedCASManagement::DataSource::PUBLIC, _TXT("PUBLIC") },
    { WPEFramework::Exchange::IUnifiedCASManagement::DataSource::PRIVATE, _TXT("PRIVATE") }
ENUM_CONVERSION_END(WPEFramework::Exchange::IUnifiedCASManagement::DataSource)
