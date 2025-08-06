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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

#ifndef RUNTIME_CONFIG
    struct RuntimeConfig {
        bool dial;
        bool wanLanAccess;
        bool thunder;
        int32_t systemMemoryLimit;
        int32_t gpuMemoryLimit;
        std::string envVariables;
        uint32_t userId;
        uint32_t groupId;
        uint32_t dataImageSize;

        bool resourceManagerClientEnabled;
        std::string dialId;
        std::string command;
        std::string appType;
        std::string appPath;
        std::string runtimePath;

        std::string logFilePath;
        uint32_t logFileMaxSize;
        std::string logLevels;          //json array of strings
        bool mapi;
        std::string fkpsFiles;          //json array of strings

        std::string fireboltVersion;
        bool enableDebugger;
    };
    #define RUNTIME_CONFIG
#endif

// @json 1.0.0 @text:keep
struct EXTERNAL IPreinstallManager : virtual public Core::IUnknown {
  enum { ID = ID_PREINSTALL_MANAGER };

  enum PreinstallState : uint8_t {
          PREINSTALL_STATE_UNKNOWN         = 0   /* @text PREINSTALL_STATE_UNKNOWN */,      //required?
          PREINSTALL_STATE_INSTALLED       = 1   /* @text PREINSTALL_STATE_INSTALLED */,
          PREINSTALL_STATE_INSTALL_FAILURE = 2   /* @text PREINSTALL_STATE_INSTALL_FAILURE */
      };

  enum PreinstallFailReason : uint8_t {
          PREINSTALL_FAIL_REASON_NONE                           = 0   /* @text PREINSTALL_FAIL_REASON_NONE */,
          PREINSTALL_FAIL_REASON_UNKNOWN                        = 1   /* @text PREINSTALL_FAIL_REASON_UNKNOWN */,
          PREINSTALL_FAIL_REASON_SIGNATURE_VERIFICATION_FAILURE = 2   /* @text PREINSTALL_FAIL_REASON_SIGNATURE_VERIFICATION_FAILURE */,
          PREINSTALL_FAIL_REASON_PERSISTENCE_FAILURE            = 3   /* @text PREINSTALL_FAIL_REASON_PERSISTENCE_FAILURE */
        };


    struct AppInstallInfo {
        string packageId;
        string version;
        PreinstallState state;
        PreinstallFailReason failReason;
    };


    // using IAppInstallInfoIterator = RPC::IIteratorType<AppInstallInfo, ID_PREINSTALL_MANAGER_INSTALL_INFO_ITERATOR>;

  // @event
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_PREINSTALL_MANAGER_NOTIFICATION };


    // @text onAppInstallationStatus
    // @brief Emitted when the installation of a preinstalled app succeeds or fails.
    // @param appInstallInfoArray: Output installation status details as string object
    virtual void OnAppInstallationStatus(const string& jsonresponse) {};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  // @text startPreinstall
  // @brief Checks the preinstall directory for packages to be preinstalled and installs them as needed.
  // @param[in] forceInstall: If true always install the app; if false then install only if not installed or existing is older version
  // @return Core::ERROR_NONE on success, Core::ERROR_GENERAL on error.
  virtual Core::hresult StartPreinstall(bool forceInstall) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
