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

#pragma once
#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IPackager : virtual public Core::IUnknown {
        enum { ID = ID_PACKAGER };

        enum state : uint8_t {
            IDLE,
            DOWNLOADING,
            DOWNLOADED,
            DECRYPTING,
            DECRYPTED,
            VERIFYING,
            VERIFIED,
            INSTALLING,
            INSTALLED,

            DOWNLOAD_FAILED,
            DECRYPTION_FAILED,
            EXTRACTION_FAILED,
            VERIFICATION_FAILED,
            INSTALL_FAILED,
            REMOVE_FAILED
        };

        struct EXTERNAL IInstallationInfo : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGER_INSTALLATIONINFO };
            // @brief Returns the current state of the package installation.
            // @details The state indicates the active installation phase or the result of the last phase.
            // @example State: DOWNLOADING
            // @retval state: Current installation state.
            virtual state State() const = 0;

            // @brief Returns the installation progress value.
            // @details Reports the progress associated with this installation.
            // @example Progress: 50
            // @retval uint8_t: Current installation progress value.
            virtual uint8_t Progress() const = 0;

	    // @brief Returns the name of the application being installed.
	    // @details Identifies the application associated with this installation information.
	    // @example AppName: "com.example.player"
	    // @retval string: Application name.
	    virtual string AppName() const = 0;

            // @brief Returns the error code for the installation.
            // @details Provides the error code associated with the installation status.
            // @example ErrorCode: 0
            // @retval uint32_t: Installation error code.
            virtual uint32_t ErrorCode() const = 0;

            // @brief Aborts the installation represented by this information.
            // @details Requests cancellation of the associated installation.
            // @example installationInfo->Abort()
            // @retval uint32_t: Framework status code for the abort request.
            virtual uint32_t Abort() = 0;
        };

        struct EXTERNAL IPackageInfo : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGER_PACKAGEINFO };

            // @brief Returns the package name.
            // @details Identifies the package represented by this package information.
            // @example Name: "wpeframework-plugin-netflix"
            // @retval string: Package name.
            virtual string Name() const = 0;

            // @brief Returns the package version.
            // @details Identifies the version of the package represented by this package information.
            // @example Version: "1.0"
            // @retval string: Package version.
            virtual string Version() const = 0;

            // @brief Returns the package architecture.
            // @details Identifies the target architecture of the package.
            // @example Architecture: "arm"
            // @retval string: Package architecture.
            virtual string Architecture() const = 0;
        };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PACKAGER_NOTIFICATION };
            virtual void StateChange(IPackageInfo* package, IInstallationInfo* install) = 0;
            virtual void RepositorySynchronize(uint32_t status) = 0;
        };

        virtual void Register(INotification* observer) = 0;
        virtual void Unregister(const INotification* observer) = 0;

        // @brief Configures the Packager interface with its host service.
        // @details Supplies the Thunder plugin host shell used by the Packager implementation.
        // @param service: Thunder plugin host shell for this service.
        // @example packager->Configure(service)
        // @retval uint32_t: Framework status code.
        virtual uint32_t Configure(PluginHost::IShell* service) = 0;

        // @brief Starts installation of a package.
        // @details Installs the package identified by its name, with an optional version and architecture as supported by the Packager service.
        // @param name: Package name, URL, or file path identifying the package to install.
        // @param version: Version of the package to install.
        // @param arch: Target architecture of the package to install.
        // @example packager->Install("wpeframework-plugin-netflix", "1.0", "arm")
        // @retval uint32_t: Framework status code; the request can report an in-progress error when another installation or synchronization is active.
        virtual uint32_t Install(const string& name, const string& version, const string& arch) = 0;
       
        // @brief Synchronizes the package repository.
        // @details Requests synchronization of the repository manifest; completion status is reported through the RepositorySynchronize notification.
        // @example packager->SynchronizeRepository()
        // @retval uint32_t: Framework status code; the request can report an in-progress error when another installation or synchronization is active.
        virtual uint32_t SynchronizeRepository() = 0;
    };
}
}
