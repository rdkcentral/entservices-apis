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

// @json 1.0.0 @text:keep
struct EXTERNAL IPreinstallManager : virtual public Core::IUnknown {
  enum { ID = ID_PREINSTALL_MANAGER };


  enum State : uint8_t {
    NOT_STARTED   = 0 /* @text NOT_STARTED */,
    IN_PROGRESS   = 1 /* @text IN_PROGRESS */,
    COMPLETED     = 2 /* @text COMPLETED   */
  };

  // @event
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_PREINSTALL_MANAGER_NOTIFICATION };

    // @text onAppInstallationStatus
    // @brief Triggered when a per-application installation status update is available
    // @param jsonResponse: JSON string containing per-application installation status and failure details
    // @param jsonresponse: JSON string containing per-application installation status and failure details
    virtual void OnAppInstallationStatus(const string& jsonResponse /* @text jsonresponse */) {};
    // @text OnPreInstallationComplete
    // @brief Emitted when the preinstallation process completes
    virtual void OnPreInstallationComplete() {};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  // @text startPreinstall
  // @brief Checks the preinstall directory for packages to be preinstalled and installs them as needed.
  // @param[in] forceInstall: If true always install the app; if false then install only if not installed or existing is older version
  // @retval Core::ERROR_NONE: Preinstallation completed or started successfully.
  // @retval Core::ERROR_GENERAL: An error occurred while starting or running preinstallation.
  virtual Core::hresult StartPreinstall(bool forceInstall) = 0;

  // @text getPreinstallState
  // @brief Provides the state of preinstallation process
  // @param[out] state: Value can be NOT_STARTED/IN_PROGRESS/COMPLETED
  // @retval Core::ERROR_NONE: State retrieved successfully.
  // @retval Core::ERROR_GENERAL: Failed to retrieve the preinstallation state.
  virtual Core::hresult getPreinstallState(State& state /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
