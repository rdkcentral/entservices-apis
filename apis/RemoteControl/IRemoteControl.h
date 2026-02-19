/**
 * @file IRemoteControl.h
 * @brief Remote Control JSONRPC interface definition for WPEFramework.
 * 
 * If not stated otherwise in this file or this component's LICENSE
 * file the following copyright and licenses apply:
 *
 * Copyright 2023 RDK Management
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
**/

#pragma once

#include "Module.h"
#include "libIBus.h"
#include "ctrlm_ipc.h"
#include "ctrlm_ipc_rcu.h"
#include "ctrlm_ipc_ble.h"

#define IARM_REMOTECONTROL_PLUGIN_NAME    "Remote_Control"


namespace WPEFramework {

    namespace Exchange {

        /**
         * @brief Server for a JSONRPC communication channel for remote control management.
         *
         * This interface is a JSONRPC server for remote control management in WPEFramework.
         * By inheriting from PluginHost::JSONRPC, it realizes the PluginHost::IDispatcher interface.
         * The default methods implemented include exists, register, and unregister.
         * Additional methods can be handled by registering them with PluginHost::JSONRPC.
         * Registration and unregistration of notifications are managed by PluginHost::JSONRPC.
         * The Notify() method allows all subscribed clients to receive JSONRPC notifications.
         * Most of this functionality is now inherited from the AbstractPlugin class.
         *
         * This interface provides methods and events for managing remote control devices,
         * pairing, IRDB operations, firmware updates, and related notifications.
         */
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IRemoteControl : virtual public Core::IUnknown {
            // Begin methods
            // @brief Get the API version number
            // @param parameters: Input parameters (unused)
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getApiVersionNumber(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start pairing process
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t startPairing(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Stop pairing process
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t stopPairing(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get network status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getNetStatus(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IRDB manufacturers
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getIRDBManufacturers(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IRDB models
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getIRDBModels(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IR codes by auto lookup
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getIRCodesByAutoLookup(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get IR codes by names
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getIRCodesByNames(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Set IR code
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t setIRCode(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Clear IR codes
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t clearIRCodes(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get last keypress source
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t getLastKeypressSource(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Configure wakeup keys
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t configureWakeupKeys(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Initialize IRDB
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t initializeIRDB(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Find my remote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t findMyRemote(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Factory reset
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t factoryReset(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Unpair remote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t unpair(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start firmware update
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t startFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Cancel firmware update
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t cancelFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Get firmware update status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual uint32_t statusFirmwareUpdate(const JsonObject& parameters, JsonObject& response) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                // @brief Status event
                // @text onStatus
                virtual void OnStatus(ctrlm_main_iarm_event_json_t* eventData) {}

                // @brief Validation event
                // @text onValidation
                virtual void OnValidation(ctrlm_main_iarm_event_json_t* eventData) {}

                // @brief Firmware update progress event
                // @text onFirmwareUpdateProgress
                virtual void OnFirmwareUpdateProgress(ctrlm_main_iarm_event_json_t* eventData) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
