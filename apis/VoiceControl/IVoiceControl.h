/**
 * @file IVoiceControl.h
 * @brief Voice Control JSONRPC interface definition for WPEFramework.
 *  
 * If not stated otherwise in this file or this component's LICENSE
 * file the following copyright and licenses apply:
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
**/

#pragma once

#include "Module.h"
#include "libIBus.h"

#include "ctrlm_ipc.h"
#include "ctrlm_ipc_voice.h"

#define IARM_VOICECONTROL_PLUGIN_NAME       "Voice_Control"

namespace WPEFramework {

    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        class IVoiceControl : virtual public Core::IUnknown  {
        private:
            // We do not allow this plugin to be copied !!
            IVoiceControl(const IVoiceControl&) = delete;
            IVoiceControl& operator=(const IVoiceControl&) = delete;

            // Begin methods
            // @brief Get the API version number
            // @param parameters: Input parameters (unused)
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t getApiVersionNumber(const JsonObject& parameters, JsonObject& response);

            // @brief Send a notification event
            // @param eventName: Name of the event
            // @param parameters: JSON parameters for the event
            void     sendNotify_(const char* eventName, JsonObject& parameters);

            // @brief Get voice status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceStatus(const JsonObject& parameters, JsonObject& response);

            // @brief Configure voice settings
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t configureVoice(const JsonObject& parameters, JsonObject& response);

            // @brief Set voice initialization
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t setVoiceInit(const JsonObject& parameters, JsonObject& response);

            // @brief Send a voice message
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t sendVoiceMessage(const JsonObject& parameters, JsonObject& response);

            // @brief Voice session by text (DEPRECATED)
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceSessionByText(const JsonObject& parameters, JsonObject& response); // DEPRECATED

            // @brief Get voice session types
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceSessionTypes(const JsonObject& parameters, JsonObject& response);

            // @brief Request a voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceSessionRequest(const JsonObject& parameters, JsonObject& response);

            // @brief Terminate a voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceSessionTerminate(const JsonObject& parameters, JsonObject& response);

            // @brief Start audio stream for voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            uint32_t voiceSessionAudioStreamStart(const JsonObject& parameters, JsonObject& response);
            // End methods

            // Begin events
            // @brief Notify session begin event
            // @param eventData: Event data structure
            void onSessionBegin(ctrlm_voice_iarm_event_json_t* eventData);

            // @brief Notify stream begin event
            // @param eventData: Event data structure
            void onStreamBegin(ctrlm_voice_iarm_event_json_t* eventData);

            // @brief Notify keyword verification event
            // @param eventData: Event data structure
            void onKeywordVerification(ctrlm_voice_iarm_event_json_t* eventData);

            // @brief Notify server message event
            // @param eventData: Event data structure
            void onServerMessage(ctrlm_voice_iarm_event_json_t* eventData);

            // @brief Notify stream end event
            // @param eventData: Event data structure
            void onStreamEnd(ctrlm_voice_iarm_event_json_t* eventData);

            // @brief Notify session end event
            // @param eventData: Event data structure
            void onSessionEnd(ctrlm_voice_iarm_event_json_t* eventData);
            // End events

        public:
            IVoiceControl();
            virtual ~IVoiceControl();
            // IPlugin methods
            virtual const string Initialize(PluginHost::IShell* service) override;
            virtual void Deinitialize(PluginHost::IShell* service) override;
            virtual string Information() const override { return {}; }

            BEGIN_INTERFACE_MAP(IVoiceControl)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            END_INTERFACE_MAP

        private:
            void InitializeIARM();
            void DeinitializeIARM();
            // Handlers for ControlMgr BT Remote events
            static void voiceEventHandler(const char *owner, IARM_EventId_t eventId, void *data, size_t len);
            void iarmEventHandler(const char *owner, IARM_EventId_t eventId, void *data, size_t len);

            // Local utility methods
            void setApiVersionNumber(uint32_t apiVersionNumber);
            void getMaskPii_();
        public:
            static IVoiceControl* _instance;
        private:
            uint32_t m_apiVersionNumber;
            bool     m_hasOwnProcess;
            bool     m_maskPii;
        };
    } // namespace Exchange
} // namespace WPEFramework
