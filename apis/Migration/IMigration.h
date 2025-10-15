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

            enum BootType : uint8_t {
                BOOT_TYPE_NORMAL       = 0  /* @text BOOT_NORMAL */,
                BOOT_TYPE_MIGRATION    = 1  /* @text BOOT_MIGRATION */,
                BOOT_TYPE_UPDATE       = 2  /* @text BOOT_UPDATE */,
                BOOT_TYPE_INCONCLUSIVE = 3  /* @text BOOT_INCONCLUSIVE */
            };

            enum MigrationStatus : uint8_t {
                MIGRATION_STATUS_NOT_STARTED                = 0 /* @text NOT_STARTED */,
                MIGRATION_STATUS_NOT_NEEDED                 = 1 /* @text NOT_NEEDED */,
                MIGRATION_STATUS_STARTED                    = 2 /* @text STARTED */,
                MIGRATION_STATUS_PRIORITY_SETTINGS_MIGRATED = 3 /* @text PRIORITY_SETTINGS_MIGRATED */,
                MIGRATION_STATUS_DEVICE_SETTINGS_MIGRATED   = 4 /* @text DEVICE_SETTINGS_MIGRATED */,
                MIGRATION_STATUS_CLOUD_SETTINGS_MIGRATED    = 5 /* @text CLOUD_SETTINGS_MIGRATED */,
                MIGRATION_STATUS_APP_DATA_MIGRATED          = 6 /* @text APP_DATA_MIGRATED */,
                MIGRATION_STATUS_MIGRATION_COMPLETED        = 7 /* @text MIGRATION_COMPLETED */,
            };

            struct EXTERNAL BootTypeInfo {
                BootType bootType;
            };

            struct EXTERNAL MigrationStatusInfo {
                MigrationStatus migrationStatus;
            };

            struct EXTERNAL MigrationResult {
                bool success;
            };

            // @text getBootTypeInfo
            // @brief query the BootType details
            // @param bootType - out - struct
            virtual Core::hresult GetBootTypeInfo(BootTypeInfo& bootTypeInfo /* @out */) = 0;

            // @text setMigrationStatus
            // @brief sets the tr181 MigrationStatus parameter
            // @param status - in - enum
            // @param migrationResult - out - struct
            virtual Core::hresult SetMigrationStatus(const MigrationStatus status, MigrationResult& migrationResult /* @out */) = 0;

            // @text getMigrationStatus
            // @brief get the MigrationStatus details
            // @param migrationStatus - out - struct
            virtual Core::hresult GetMigrationStatus(MigrationStatusInfo& migrationStatusInfo /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
