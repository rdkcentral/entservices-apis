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
/* @json 1.0.0 @text:keep */    
struct EXTERNAL IFirmwareUpdate : virtual public Core::IUnknown {
  enum { ID = ID_FIRMWARE_UPDATE };

  enum State : uint8_t {
      VALIDATION_FAILED  = 1 /* @text VALIDATION_FAILED */,
      FLASHING_STARTED   = 2 /* @text FLASHING_STARTED */,
      FLASHING_FAILED    = 3 /* @text FLASHING_FAILED */,
      FLASHING_SUCCEEDED = 4 /* @text FLASHING_SUCCEEDED */,
      WAITING_FOR_REBOOT = 5 /* @text WAITING_FOR_REBOOT */ 
  };

  enum SubState : uint8_t {
      NOT_APPLICABLE = 0 /* @text NOT_APPLICABLE */,
      FIRMWARE_NOT_FOUND = 1 /* @text FIRMWARE_NOT_FOUND */,
      FIRMWARE_INVALID = 2 /* @text FIRMWARE_INVALID */,
      FIRMWARE_OUTDATED = 3 /* @text FIRMWARE_OUTDATED */,
      FIRMWARE_UPTODATE = 4 /* @text FIRMWARE_UPTODATE */,
      FIRMWARE_INCOMPATIBLE = 5 /* @text FIRMWARE_INCOMPATIBLE */,
      PREWRITE_SIGNATURE_CHECK_FAILED = 6 /* @text PREWRITE_SIGNATURE_CHECK_FAILED */,
      FLASH_WRITE_FAILED = 7 /* @text FLASH_WRITE_FAILED */,
      POSTWRITE_FIRMWARE_CHECK_FAILED = 8 /* @text POSTWRITE_FIRMWARE_CHECK_FAILED */,
      POSTWRITE_SIGNATURE_CHECK_FAILED = 9 /* @text POSTWRITE_SIGNATURE_CHECK_FAILED */
  };

  struct EXTERNAL Result {
         bool success /* @text success */;
  };

  struct EXTERNAL GetUpdateStateResult {
         State state /* @text state */;
         SubState substate /* @text substate */;
  };

   // @event
   struct EXTERNAL INotification : virtual public Core::IUnknown {
          enum { ID = ID_FIRMWARE_UPDATE_NOTIFICATION };

          // @brief notify Firmware update state change.
          // @param State   : State
          // @param SubState: SubState
          // @text onUpdateStateChange
          virtual void OnUpdateStateChange (const State state  , const SubState substate ) {};

          // @brief This notification is raised between flashing started state and flashing succeeded/failed.
          // @param percentageComplete   : Number between 0 and 100 indicating the "percentage complete" of the flashing process. 
          // @text onFlashingStateChange
          virtual void OnFlashingStateChange (const uint32_t percentageComplete ) {};
  
   };

   virtual Core::hresult Register(Exchange::IFirmwareUpdate::INotification* notification ) = 0;
   virtual Core::hresult Unregister(Exchange::IFirmwareUpdate::INotification* notification ) = 0;

  // @brief Initiates a firmware update.
  // @param[in] firmwareFilepath The complete path of the firmware file to which the device needs to be updated to.
  // @param[in] firmwareType     Type of firmware. One of the following (PCI,DRI)
  // @returns Core::hresult
  // @text updateFirmware
  virtual Core::hresult UpdateFirmware(const string& firmwareFilepath /* @text firmwareFilepath */ , const string& firmwareType /* @text firmwareType */, Result &result /* @out  */ ) = 0;

  // @brief Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method.
  // @param[out] GetUpdateStateResult  
  // @returns Core::hresult
  // @text getUpdateState
  virtual Core::hresult GetUpdateState(GetUpdateStateResult& getUpdateStateResult /* @out */) = 0;

  // @brief Enable or disable the AutoReboot feature.
  // @param[in] enable Boolean to enable or disable AutoReboot
  // @returns Core::hresult
  // @text setFirmwareAutoReboot
  virtual Core::hresult SetFirmwareAutoReboot(const bool enable, Result& result /* @out */) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
