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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {

    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            // Begin methods
            // @brief Get the API version number
            // @text getApiVersionNumber
            // @param parameters: Input parameters (unused)
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Send a notification event
            // @text sendNotify_
            // @param eventName: Name of the event
            // @param parameters: JSON parameters for the event
            virtual void SendNotify_(const char* eventName, JsonObject& parameters) = 0;

            // @brief Get voice status
            // @text voiceStatus
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice status.
            virtual Core::hresult VoiceStatus(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Configure voice settings
            // @text configureVoice
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice settings configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure voice settings.
            virtual Core::hresult ConfigureVoice(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Set voice initialization
            // @text setVoiceInit
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice initialization set successfully.
            // @retval ErrorCode::GENERAL: Failed to set voice initialization.
            virtual Core::hresult SetVoiceInit(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Send a voice message
            // @text sendVoiceMessage
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice message sent successfully.
            // @retval ErrorCode::GENERAL: Failed to send voice message.
            virtual Core::hresult SendVoiceMessage(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Voice session by text (DEPRECATED)
            // @text voiceSessionByText
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice session by text executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute voice session by text.
            virtual Core::hresult VoiceSessionByText(const JsonObject& parameters, JsonObject& response) = 0; // DEPRECATED

            // @brief Get voice session types
            // @text voiceSessionTypes
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice session types retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice session types.
            virtual Core::hresult VoiceSessionTypes(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Request a voice session
            // @text voiceSessionRequest
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice session requested successfully.
            // @retval ErrorCode::GENERAL: Failed to request voice session.
            virtual Core::hresult VoiceSessionRequest(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Terminate a voice session
            // @text voiceSessionTerminate
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice session terminated successfully.
            // @retval ErrorCode::GENERAL: Failed to terminate voice session.
            virtual Core::hresult VoiceSessionTerminate(const JsonObject& parameters, JsonObject& response) = 0;

            // @brief Start audio stream for voice session
            // @text voiceSessionAudioStreamStart
            // @param parameters: JSON input parameters
            // @param response: JSON response object
            // @retval ErrorCode::NONE: Voice session audio stream started successfully.
            // @retval ErrorCode::GENERAL: Failed to start voice session audio stream.
            virtual Core::hresult VoiceSessionAudioStreamStart(const JsonObject& parameters, JsonObject& response) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                // @brief Session begin event
                // @text onSessionBegin
                // @param eventData: Pointer to event data containing session begin information.
                virtual void OnSessionBegin(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Stream begin event
                // @text onStreamBegin
                // @param eventData: Pointer to event data containing stream begin information.
                virtual void OnStreamBegin(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Keyword verification event
                // @text onKeywordVerification
                // @param eventData: Pointer to event data containing keyword verification information.
                virtual void OnKeywordVerification(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Server message event
                // @text onServerMessage
                // @param eventData: Pointer to event data containing server message information.
                virtual void OnServerMessage(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Stream end event
                // @text onStreamEnd
                // @param eventData: Pointer to event data containing stream end information.
                virtual void OnStreamEnd(ctrlm_voice_iarm_event_json_t* eventData) {}

                // @brief Session end event
                // @text onSessionEnd
                // @param eventData: Pointer to event data containing session end information.
                virtual void OnSessionEnd(ctrlm_voice_iarm_event_json_t* eventData) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
