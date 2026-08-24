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
                BOOT_TYPE_INIT         = 0  /* @text BOOT_INIT */,
                BOOT_TYPE_NORMAL       = 1  /* @text BOOT_NORMAL */,
                BOOT_TYPE_MIGRATION    = 2  /* @text BOOT_MIGRATION */,
                BOOT_TYPE_UPDATE       = 3  /* @text BOOT_UPDATE */
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
            // @details Retrieves information about how the device was booted, which indicates whether the device is in normal operation mode, migration mode for transferring data from a previous device, or update/upgrade mode
            // @param bootType - out - struct
            // @example bootType: {"bootType": "BOOT_TYPE_NORMAL"}
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::hresult S_OK on success, E_FAIL if boot type information is unavailable, or error code otherwise
            virtual Core::hresult GetBootTypeInfo(BootTypeInfo& bootTypeInfo /* @out */) = 0;

            // @text setMigrationStatus
            // @brief sets the tr181 MigrationStatus parameter
            // @details Updates the tr181 MigrationStatus parameter to track the progress of data migration from a previous device. This method allows clients to advance the migration state through its various stages from NOT_STARTED to MIGRATION_COMPLETED
            // @param status - in - MigrationStatus - The MigrationStatus to set (NOT_STARTED, NOT_NEEDED, STARTED, PRIORITY_SETTINGS_MIGRATED, DEVICE_SETTINGS_MIGRATED, CLOUD_SETTINGS_MIGRATED, APP_DATA_MIGRATED, or MIGRATION_COMPLETED)
            // @param migrationResult - out - MigrationResult - The result of the migration status update
            // @example status: MIGRATION_STATUS_PRIORITY_SETTINGS_MIGRATED
            // @example migrationResult: {"success": true}
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::hresult S_OK on success, E_FAIL if migration status could not be updated, or error code otherwise
            virtual Core::hresult SetMigrationStatus(const MigrationStatus status, MigrationResult& migrationResult /* @out */, bool &success /* @out */) = 0;

            // @text getMigrationStatus
            // @brief get the MigrationStatus details
            // @details Queries the current state of the device migration process. This method returns the tr181 MigrationStatus parameter value which tracks which components have been successfully migrated from a previous device
            // @param migrationStatus - out - struct
            // @example migrationStatus: {"migrationStatus": "MIGRATION_STATUS_DEVICE_SETTINGS_MIGRATED"}
            // @param success: Indicates whether the operation was successful
            // @example success: true
            // @retval Core::hresult S_OK on success, E_FAIL if migration status is unavailable, or error code otherwise
            virtual Core::hresult GetMigrationStatus(MigrationStatusInfo& migrationStatusInfo /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
