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
  // @details Invoked by the SystemMode service to request a new state for a given system mode. Components implementing this interface should asynchronously adjust their internal behavior, resource usage, or performance characteristics to match the requested optimization state.
  // @param[in] systemMode       The system mode.
  // @example systemMode: DEVICE_OPTIMIZE
  // @param[in] state            The requested state.
  // @example state: VIDEO
  // @returns Core::hresult
  // @param success: Indicates whether the operation was successful
  // @example success: true
  virtual Core::hresult RequestState(const SystemMode systemMode /* @text systemMode */ , const State state /* @text state */ ) = 0;

  // @text getState
  // @brief Gets the current state for a given system property
  // @details Invoked by the SystemMode service to retrieve the current state of a given system mode. Components implementing this interface should return the current state of the requested system mode.
  // @param[in] systemMode       The system mode to get the state of.
  // @example systemMode: DEVICE_OPTIMIZE
  // @param[out] state           Receives the state of the system mode.
  // @example state: VIDEO
  // @returns Core::hresult
  virtual Core::hresult GetState(const SystemMode systemMode /* @text systemMode */ , GetStateResult& getStateResult /* @out */) const = 0;

  // @text clientActivated
  // @brief To put client plugin entry in map.
  // @details Invoked by the SystemMode service to notify that a client plugin has been activated. Components implementing this interface should record the activation of the client plugin for the specified system mode.
  // @param[in] callsign       callsign of client.
  // @example callsign: "com.example.client"
  // @param[in] systemMode       The system mode.
  // @example systemMode: DEVICE_OPTIMIZE
  // @returns Core::hresult
  virtual Core::hresult ClientActivated(const string& callsign /* @text callsign*/ ,const string& systemMode) = 0;

  // @text clientDeactivated
  // @brief To put client plugin entry in map.
  // @details Invoked by the SystemMode service to notify that a client plugin has been deactivated. Components implementing this interface should remove the activation record of the client plugin for the specified system mode.
  // @param[in] callsign       callsign of client.
  // @example callsign: "com.example.client"
  // @param[in] systemMode       The system mode.
  // @example systemMode: DEVICE_OPTIMIZE
  // @returns Core::hresult
  virtual Core::hresult ClientDeactivated(const string& callsign /* @text callsign*/, const string& systemMode) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
