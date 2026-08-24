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
  // @details Requests the SystemMode service to transition the specified system mode to the supplied target state. Components associated with the system mode asynchronously reconfigure themselves to match the requested state. A successful return value indicates that the request was accepted, but does not guarantee that all components have completed the transition.
  // @param[in] systemMode       The system mode.
  // @example systemMode: DEVICE_OPTIMIZE
  // @param[in] state            The requested state.
  // @example state: GAME
  // @param success: Indicates whether the operation was successful
  // @example success: true
  // @retval Core::ERROR_NONE - State transition request accepted successfully.
  // @retval Core::ERROR_GENERAL - Failed to process the state transition request.
  virtual Core::hresult RequestState(const SystemMode systemMode /* @text systemMode */ , const State state /* @text state */ ) = 0;

  // @text getState
  // @brief Gets the current state for a given system property
  // @details Retrieves the currently active state associated with the specified system mode. The returned value reflects the state that is presently applied on the device.
  // @param[in] systemMode       The system mode to get the state of.
  // @example systemMode: DEVICE_OPTIMIZE
  // @param getStateResult - out - Structure containing the current state.
  // @example getStateResult.state - VIDEO
  // @example GetStateResult result;
  // @example SystemMode->GetState(DEVICE_OPTIMIZE, result);
  // @param success: Indicates whether the operation was successful
  // @example success: true
  // @retval Core::ERROR_NONE - Current state retrieved successfully.
  // @retval Core::ERROR_GENERAL - Failed to retrieve the current state.
  virtual Core::hresult GetState(const SystemMode systemMode /* @text systemMode */ , GetStateResult& getStateResult /* @out */) const = 0;

  // @text clientActivated
  // @brief To put client plugin entry in map.
  // @details Informs the SystemMode service that a client plugin is active and participating in the specified system mode. The service tracks the client as part of the mode activation lifecycle.
  // @param[in] callsign       callsign of client.
  // @example callsign: "org.rdk.VideoPlayer"
  // @param[in] systemMode       The system mode.
  // @example systemMode: "DEVICE_OPTIMIZE"
  // @param success: Indicates whether the operation was successful
  // @example success: true
  // @returns Core::hresult
  virtual Core::hresult ClientActivated(const string& callsign /* @text callsign*/ ,const string& systemMode) = 0;

  // @text clientDeactivated
  // @brief To put client plugin entry in map.
  // @details Informs the SystemMode service that a client plugin is no longer participating in the specified system mode. The service updates its internal tracking information accordingly.
  // @param[in] callsign       callsign of client.
  // @example callsign: "org.rdk.VideoPlayer"
  // @param[in] systemMode       The system mode.
  // @example systemMode: "DEVICE_OPTIMIZE"
  // @example ClientDeactivated( "org.rdk.VideoPlayer", "DEVICE_OPTIMIZE");
  // @param success: Indicates whether the operation was successful
  // @example success: true
  // @retval Core::ERROR_NONE - Client deactivation recorded successfully.
  // @retval Core::ERROR_GENERAL - Failed to record client deactivation.
  virtual Core::hresult ClientDeactivated(const string& callsign /* @text callsign*/, const string& systemMode) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
