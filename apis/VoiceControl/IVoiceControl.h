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
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            // Begin methods
            // @brief Get the API version number
            // @param parameters: Input parameters (unused)
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult getApiVersionNumber(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Send a notification event
            // @param eventName: Name of the event
            // @param parameters: JSON parameters for the event
            virtual void sendNotify_(const char* eventName, JsonObject& parameters) = 0;

            // @brief Get voice status
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceStatus(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Configure voice settings
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult configureVoice(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Set voice initialization
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult setVoiceInit(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Send a voice message
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult sendVoiceMessage(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Voice session by text (DEPRECATED)
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceSessionByText(const JsonObject& parameters, JsonObject& response) = 0; // DEPRECATED

            // @brief Get voice session types
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceSessionTypes(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Request a voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceSessionRequest(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Terminate a voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceSessionTerminate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start audio stream for voice session
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval 0: Success
            virtual Core::hresult voiceSessionAudioStreamStart(const JsonObject& parameters, JsonObject& response) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                // @brief Session begin event
                // @text onSessionBegin
                virtual void OnSessionBegin(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Stream begin event
                // @text onStreamBegin
                virtual void OnStreamBegin(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Keyword verification event
                // @text onKeywordVerification
                virtual void OnKeywordVerification(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Server message event
                // @text onServerMessage
                virtual void OnServerMessage(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Stream end event
                // @text onStreamEnd
                virtual void OnStreamEnd(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Session end event
                // @text onSessionEnd
                virtual void OnSessionEnd(ctrlm_voice_iarm_event_json_t* eventData) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
