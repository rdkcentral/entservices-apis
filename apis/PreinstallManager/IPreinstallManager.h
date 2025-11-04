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



  // @event
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_PREINSTALL_MANAGER_NOTIFICATION };


    // @text onAppInstallationStatus
    // @brief Emitted when the installation of a preinstalled app succeeds or fails.
    // @param jsonresponse: Output installation status details as string object
    virtual void OnAppInstallationStatus(const string& jsonresponse /* @opaque */) {};
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