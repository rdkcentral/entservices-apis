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

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IMigration : virtual public Core::IUnknown
        {
            enum { ID = ID_MIGRATION };

            // @text getBootTypeInfo
            // @brief query the BootType details
            // @param bootType - out - string
            virtual Core::hresult GetBootTypeInfo(string& bootType /* @text bootType @out */) = 0;

            // @text setMigrationStatus
            // @brief sets the tr181 MigrationStatus parameter
            // @param status - in - string
            // @param success - out - boolean
            virtual Core::hresult SetMigrationStatus(const string& status, bool& success /* @out */) = 0;

            // @text getMigrationStatus
            // @brief get the MigrationStatus details
            // @param state - in - string
            // @param success - out - boolean
            virtual Core::hresult GetMigrationStatus(string& migrationStatus /* @out */ , bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
