/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
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
 // @json @text:keep
struct EXTERNAL ISystemMode : virtual public Core::IUnknown {
  enum { ID = ID_SYSTEM_MODE };

  /// Enumeration of system modes.
  enum SystemMode : uint8_t {
	  DEVICE_OPTIMIZE = 1 /* @text: device_optimize */
  };

  /// Enumeration of states for all system modes.
  enum State : uint32_t {
	  // DEVICE_OPTIMIZE states
	  VIDEO = (DEVICE_OPTIMIZE << 24) | 1 /* @text: video */,
	  GAME  = (DEVICE_OPTIMIZE << 24) | 2 /* @text: game */,

	  // next system mode states...
  };

  struct EXTERNAL GetStateResult {
	  State state /* @text state */;
  };
  // @text requestState
  // @brief Requests a new system mode state in the device.  Thunder components asynchronously reconfigure themselves so the caller cannot be guaranteed a full state transition upon return.
  // @param[in] systemMode       The system mode.
  // @param[in] state            The requested state.
  // @returns Core::hresult
  virtual Core::hresult RequestState(const SystemMode systemMode /* @in @text systemMode */ , const State state /* @in @text state */ ) = 0;

  // @text getState
  // @brief Gets the current state for a given system property
  // @param[in] systemMode       The system mode to get the state of.
  // @param[out] state           Receives the state of the system mode.
  // @returns Core::hresult
  virtual Core::hresult GetState(const SystemMode systemMode /* @in @text systemMode */ , GetStateResult& getStateResult /* @out */) const = 0;

  // @text clientActivated
  // @brief To put client plugin entry in map.
  // @param[in] callsign       callsign of client.
  // @param[in] systemMode       The system mode.
  // @returns uint32_t
  virtual uint32_t ClientActivated(const string& callsign /* @in @text callsign*/ ,const string& systemMode) = 0;

  // @text clientDeactivated
  // @brief To put client plugin entry in map.
  // @param[in] callsign       callsign of client.
  // @param[in] systemMode       The system mode.
  // @returns uint32_t
  virtual uint32_t ClientDeactivated(const string& callsign /* @in @text callsign*/, const string& systemMode) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
