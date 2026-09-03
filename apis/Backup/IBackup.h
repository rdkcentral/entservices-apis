/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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
        enum Scenario : uint8_t
        {
            HOSPITALITY_RESET /* @text HOSPITALITY_RESET */
        };

        struct EXTERNAL BackupContext
        {
            Scenario scenario /* @text scenario */ 
                             /* @brief The scenario for which the backup operations are done */;
            string variant /* @text variant */ 
                           /* @brief Variant label for the backup context (for example, user profile for which the backup operations are done) */ 
                           /* @default:"generic" */;
            string persistentPath /* @text persistentPath */ 
                                  /* @brief Filesystem path where backup data is stored persistently */ 
                                  /* @default:"/opt/secure/persistent/settings_backup/" */;
        };

        /*
         * Manages "backup and restore" operations for various settings in the system
         * by working with other plugins in the system
         */
        // @json 1.0.0 @text:keep
        struct EXTERNAL IBackupManager : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_BACKUP_MANAGER
            };

            virtual ~IBackupManager() = default;

            // @text backupSettings
            // @brief Backup settings across the system
            // @details Invokes all registered backup providers and requests them to persist their settings into the location 
            // specified by the supplied BackupContext. The backup operation is performed for the given scenario and variant.
            // @param context: Context for which the backup to happen
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully backed up the settings
            virtual Core::hresult BackupSettings(const BackupContext& context) = 0;

            // @text restoreSettings
            // @brief Restore settings across the system
            // @details Invokes all registered backup providers and requests them to restore their settings from the location specified by the supplied BackupContext.
            // The restore operation is performed for the given scenario and variant.
            // @param context: Context for which the restore to happen
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully restored the settings
            virtual Core::hresult RestoreSettings(const BackupContext& context) = 0;

            // @text deleteBackup
            // @brief Deletes the previously backed up settings across the system
            // @details Locates the backup directory specified by the BackupContext and removes all archived settings
            // data associated with the given scenario and variant.
            // @param context: Context for which the backup to be deleted
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully deleted the backup
            virtual Core::hresult DeleteBackup(const BackupContext& context) = 0;
        };

        /*
         * Provides APIs to "backup" and "restore" the settings the plugin owns.
         * Exact list of settings that gets backed up and restored are internal to the implementation.
         */
        struct EXTERNAL IBackupProvider : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_BACKUP_PROVIDER
            };

            virtual ~IBackupProvider() = default;

            // @text backup
            // @brief Backup settings that belong to this component.
            // @details Instructs this specific plugin or component provider to compile its
            // internal state and persist it into the provided BackupContext directory path.
            // @param context: Context for which the backup to happen
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully backed up
            virtual Core::hresult Backup(const BackupContext& context) = 0;

            // @text restore
            // @brief Restore settings that belong to this component.
            // @details Instructs this specific plugin or component provider to ingest saved settings
            // data from the BackupContext location and re-apply them to its runtime configuration.
            // @param context: Context for which the restore to happen
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully restored
            virtual Core::hresult Restore(const BackupContext& context) = 0;

            // @text delete
            // @brief Deletes the previously backed up settings that belong to this component.
            // @details Commands this specific plugin provider to purge any specialized local archives, references, or storage files 
            // created for this particular context scenario and variant.
            // @param context: Context for which the backup to be deleted
            // @example context: {"scenario": "HOSPITALITY_RESET", "variant": "generic", "persistentPath": "/opt/secure/persistent/settings_backup/"}
            // @retval Core::ERROR_NONE: Successfully deleted the backup
            virtual Core::hresult Delete(const BackupContext& context) = 0;
        };
    }
}
