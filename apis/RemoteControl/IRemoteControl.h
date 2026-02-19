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
        struct EXTERNAL RemoteControl : virtual public Core::IUnknown {
        private:
            typedef Core::JSON::String JString;
            typedef Core::JSON::ArrayType<JString> JStringArray;
            typedef Core::JSON::ArrayType<JsonObject> JObjectArray;
            typedef Core::JSON::Boolean JBool;

            // We do not allow this plugin to be copied !!
            RemoteControl(const RemoteControl&) = delete;
            RemoteControl& operator=(const RemoteControl&) = delete;

            // Begin methods
            // @brief Get the API version number
            // @param parameters: Input parameters (unused)
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getApiVersionNumber(const JsonObject& parameters, JsonObject& response);

            // @brief Start pairing process
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t startPairing(const JsonObject& parameters, JsonObject& response);

            // @brief Stop pairing process
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t stopPairing(const JsonObject& parameters, JsonObject& response);

            // @brief Get network status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getNetStatus(const JsonObject& parameters, JsonObject& response);

            // @brief Get IRDB manufacturers
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getIRDBManufacturers(const JsonObject& parameters, JsonObject& response);

            // @brief Get IRDB models
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getIRDBModels(const JsonObject& parameters, JsonObject& response);

            // @brief Get IR codes by auto lookup
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getIRCodesByAutoLookup(const JsonObject& parameters, JsonObject& response);

            // @brief Get IR codes by names
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getIRCodesByNames(const JsonObject& parameters, JsonObject& response);

            // @brief Set IR code
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t setIRCode(const JsonObject& parameters, JsonObject& response);

            // @brief Clear IR codes
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t clearIRCodes(const JsonObject& parameters, JsonObject& response);

            // @brief Get last keypress source
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getLastKeypressSource(const JsonObject& parameters, JsonObject& response);

            // @brief Configure wakeup keys
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t configureWakeupKeys(const JsonObject& parameters, JsonObject& response);

            // @brief Initialize IRDB
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t initializeIRDB(const JsonObject& parameters, JsonObject& response);

            // @brief Find my remote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t findMyRemote(const JsonObject& parameters, JsonObject& response);

            // @brief Factory reset
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t factoryReset(const JsonObject& parameters, JsonObject& response);

            // @brief Unpair remote
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t unpair(const JsonObject& parameters, JsonObject& response);

            // @brief Start firmware update
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t startFirmwareUpdate(const JsonObject& parameters, JsonObject& response);

            // @brief Cancel firmware update
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t cancelFirmwareUpdate(const JsonObject& parameters, JsonObject& response);

            // @brief Get firmware update status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t statusFirmwareUpdate(const JsonObject& parameters, JsonObject& response);
            // End methods

            // Begin events
            // @brief Notify status event
            // @param eventData: Event data structure
            void onStatus(ctrlm_main_iarm_event_json_t* eventData);

            // @brief Notify validation event
            // @param eventData: Event data structure
            void onValidation(ctrlm_main_iarm_event_json_t* eventData);

            // @brief Notify firmware update progress event
            // @param eventData: Event data structure
            void onFirmwareUpdateProgress(ctrlm_main_iarm_event_json_t* eventData);
            // End events

        public:
            RemoteControl();
            virtual ~RemoteControl();
            // IPlugin methods
            virtual const string Initialize(PluginHost::IShell* service) override;
            virtual void Deinitialize(PluginHost::IShell* service) override;
            virtual string Information() const override { return {}; }

            BEGIN_INTERFACE_MAP(RemoteControl)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            END_INTERFACE_MAP

        private:
            void InitializeIARM();
            void DeinitializeIARM();
            // Handlers for ControlMgr BT Remote events
            static void remoteEventHandler(const char *owner, IARM_EventId_t eventId, void *data, size_t len);
            void iarmEventHandler(const char *owner, IARM_EventId_t eventId, void *data, size_t len);

            // Local utility methods
            void setApiVersionNumber(uint32_t apiVersionNumber);

        public:
            static RemoteControl* _instance;
        private:
            // Generic members
            uint32_t   m_apiVersionNumber;
            bool       m_hasOwnProcess;
        };
    } // namespace Exchange
} // namespace WPEFramework
