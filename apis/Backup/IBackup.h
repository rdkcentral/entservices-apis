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


namespace WPEFramework {
namespace Exchange {
    /*
     * Manages the "backup and restore" operations for various settings in the system
     * by working with other plugins in the system
     */
    // @json 1.0.0 @text:keep
    struct EXTERNAL IBackupManager : virtual public Core::IUnknown {
        enum { ID = ID_BACKUP_MANAGER };

        virtual ~IBackupManager() = default;

        enum Scenario : uint8_t {
            SCENARIO_HOSPITALITY_RESET /* @text HOSPITALITY_RESET */
        };

        // @text backupSettings
        // @brief Backup settings across the system
        // @param scenario: Scenario for which the backup to happen
        virtual Core::hresult BackupSettings(const Scenario scenario) const = 0;

        // @text restoreSettings
        // @brief Restore settings across the system
        // @param scenario: Scenario for which the restore to happen
        virtual Core::hresult RestoreSettings(const Scenario scenario) const = 0;

    };

    /*
     * Provides APIs to "backup" and "restore" the settings the plugin owns.
     * Exact list of settings that gets backed up and restored are internal to the implementation.
     */
    // @json 1.0.0 @text:keep
    struct EXTERNAL IBackupProvider : virtual public Core::IUnknown {
        enum { ID = ID_BACKUP_PROVIDER };

        virtual ~IBackupProvider() = default;

        enum Scenario : uint8_t {
            SCENARIO_HOSPITALITY_RESET /* @text HOSPITALITY_RESET */
        };

        // @text backup
        // @brief Backup settings that belong to this component.
        // @param scenario: Scenario for which the backup to happen
        virtual Core::hresult Backup(const Scenario scenario) const = 0;

        // @text restore
        // @brief Restore settings that belong to this component.
        // @param scenario: Scenario for which the restore to happen
        virtual Core::hresult Restore(const Scenario scenario) const = 0;

    };
}
}

