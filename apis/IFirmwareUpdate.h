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

          // @text onUpdateStateChange
          // @brief Notifies firmware update state changes.
          // @details This notification is raised when the firmware update transitions between validation, flashing, and reboot states.
          // @param[in] state: Firmware update state.
          // @param[in] substate: Firmware update substate.
          // @example state: FLASHING_STARTED
          // @example substate: NOT_APPLICABLE
          // @param[in] success: Indicates whether the operation was successful
          // @example success: true
          // @retval Core::ERROR_NONE Last Checkout reset time is successfully retrieved
          // @retval Core::ERROR_GENERAL Failed to complete the system backup process
          virtual void OnUpdateStateChange (const State state  , const SubState substate ) {};

          // @text onFlashingStateChange
          // @brief This notification is raised between flashing started state and flashing succeeded/failed.
          // @details This notification is raised while the firmware is being flashed, between FLASHING_STARTED and FLASHING_SUCCEEDED or FLASHING_FAILED.
          // @param percentageComplete   : Number between 0 and 100 indicating the "percentage complete" of the flashing process. 
          // @example percentageComplete: 50
          // @param success: Indicates whether the operation was successful
          // @example success: true
          // @retval Core::ERROR_NONE Last Checkout reset time is successfully retrieved
          // @retval Core::ERROR_GENERAL Failed to complete the system backup process
          virtual void OnFlashingStateChange (const uint32_t percentageComplete ) {};
  
   };

   virtual Core::hresult Register(Exchange::IFirmwareUpdate::INotification* notification ) = 0;
   virtual Core::hresult Unregister(Exchange::IFirmwareUpdate::INotification* notification ) = 0;

       // @text updateFirmware
       // @brief Initiates a firmware update.
       // @details The firmware update process consists of firmware validation followed by firmware flashing. The update result indicates whether the request was accepted. Progress and state changes are reported through the registered notification interface.
       // @param[in] firmwareFilepath The complete path of the firmware file to which the device needs to be updated to.
       // @param[in] firmwareType     Type of firmware. One of the following (PCI,DRI)
       // @param[out] result Result of the firmware update request.
       // @example firmwareFilepath: "/tmp/firmware.bin"
       // @example firmwareType: "PCI"
       // @example result.success: true
       // @param success: Indicates whether the operation was successful
       // @example success: true
       // @retval Core::ERROR_NONE Firmware update request was accepted successfully.
       // @retval Core::ERROR_GENERAL Failed to initiate the firmware update.
       virtual Core::hresult UpdateFirmware(const string& firmwareFilepath /* @text firmwareFilepath */ , const string& firmwareType /* @text firmwareType */, Result &result /* @out  */ ) = 0;

       // @text getUpdateState
       // @brief Firmware update consists of 2 major steps: 1. Firmware Validation, and 2. Firmware Flashing. This method returns the "status" of these steps in the firmware update process that was triggered by updateFirmware method.
       // @details This method returns the current state and substate of the firmware update process initiated by UpdateFirmware. The substate provides additional information when validation or flashing fails.
       // @param[out] GetUpdateStateResult Current firmware update state and substate.
       // @example getUpdateStateResult.state: FLASHING_SUCCEEDED
       // @example getUpdateStateResult.substate: NOT_APPLICABLE
       // @param success: Indicates whether the operation was successful
       // @example success: true
       // @retval Core::ERROR_NONE Current firmware update state was retrieved successfully.
       // @retval Core::ERROR_GENERAL Failed to retrieve the firmware update state.
       virtual Core::hresult GetUpdateState(GetUpdateStateResult& getUpdateStateResult /* @out */) = 0;

       // @text setAutoReboot
       // @brief Enable or disable the AutoReboot feature.
       // @details When enabled, the device automatically reboots after the firmware update completes successfully and enters the WAITING_FOR_REBOOT state. When disabled, the device remains operational without automatically rebooting.
       // @param[in] enable Boolean to enable or disable AutoReboot
       // @param[out] result Result of the AutoReboot configuration request.
       // @example enable: true
       // @example result.success: true
       // @param success: Indicates whether the operation was successful
       // @example success: true
       // @retval Core::ERROR_NONE AutoReboot configuration was updated successfully.
       // @retval Core::ERROR_GENERAL Failed to update the AutoReboot configuration.
       virtual Core::hresult SetAutoReboot(const bool enable, Result& result /* @out */) = 0;

};
} // namespace Exchange
} // namespace WPEFramework
