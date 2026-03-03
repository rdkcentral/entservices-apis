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
#include "IVoiceControlStructs.h"

// @stubgen:include <com/IIteratorType.h>

struct ctrlm_voice_iarm_event_json_t;

namespace WPEFramework {

    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            
            enum { ID = ID_VOICECONTROL };
            
            // Begin methods
            // @brief Get the API version number
            // @text getApiVersionNumber
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(VoiceControlData::GetApiVersionNumberResponse& response /* @out */) = 0;

            // @brief Send a notification event
            // @text sendNotify_
            // @param eventName: Name of the event
            // @param parameters: JSON parameters for the event
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult SendNotify_(const string& eventName, string& parameters /* @out @opaque */) = 0;

            // @brief Returns the current status of the RDK voice stack
            // @text voiceStatus
            // @param response: The voice status response
            // @retval ErrorCode::NONE: Voice status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice status.
            virtual Core::hresult VoiceStatus(VoiceControlData::VoiceStatusResponse& response /* @out */) = 0;

            // @brief Configures the RDK's voice stack
            // @text configureVoice
            // @param request: The configure voice request parameters
            // @retval ErrorCode::NONE: Voice settings configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure voice settings.
            virtual Core::hresult ConfigureVoice(const VoiceControlData::ConfigureVoiceRequest& request) = 0;

            // @brief Sets the application metadata in the INIT message that gets sent to the Voice Server
            // @text setVoiceInit
            // @param request: The voice init request parameters
            // @retval ErrorCode::NONE: Voice initialization set successfully.
            // @retval ErrorCode::GENERAL: Failed to set voice initialization.
            virtual Core::hresult SetVoiceInit(const VoiceControlData::SetVoiceInitRequest& request) = 0;

            // @brief Sends a message to the Voice Server
            // @text sendVoiceMessage
            // @param request: The voice message request parameters
            // @retval ErrorCode::NONE: Voice message sent successfully.
            // @retval ErrorCode::GENERAL: Failed to send voice message.
            virtual Core::hresult SendVoiceMessage(const VoiceControlData::SendVoiceMessageRequest& request) = 0;

            // @brief Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)
            // @text voiceSessionByText
            // @param request: The voice session by text request parameters
            // @retval ErrorCode::NONE: Voice session by text executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute voice session by text.
            virtual Core::hresult VoiceSessionByText(const VoiceControlData::VoiceSessionByTextRequest& request) = 0; // DEPRECATED

            // @brief Retrieves the types of voice sessions which are supported by the platform
            // @text voiceSessionTypes
            // @param response: The voice session types response
            // @retval ErrorCode::NONE: Voice session types retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice session types.
            virtual Core::hresult VoiceSessionTypes(VoiceControlData::VoiceSessionTypesResponse& response /* @out */) = 0;

            // @brief Requests a voice session using the specified request type and optional parameters
            // @text voiceSessionRequest
            // @param request: The voice session request parameters
            // @retval ErrorCode::NONE: Voice session requested successfully.
            // @retval ErrorCode::GENERAL: Failed to request voice session.
            virtual Core::hresult VoiceSessionRequest(const VoiceControlData::VoiceSessionRequestParams& request) = 0;

            // @brief Terminates a voice session using the specified session identifier
            // @text voiceSessionTerminate
            // @param request: The voice session terminate request parameters
            // @retval ErrorCode::NONE: Voice session terminated successfully.
            // @retval ErrorCode::GENERAL: Failed to terminate voice session.
            virtual Core::hresult VoiceSessionTerminate(const VoiceControlData::VoiceSessionTerminateRequest& request) = 0;

            // @brief Starts a subsequent audio stream for the voice session indicated by the session identifier
            // @text voiceSessionAudioStreamStart
            // @param request: The voice session audio stream start request parameters
            // @retval ErrorCode::NONE: Voice session audio stream started successfully.
            // @retval ErrorCode::GENERAL: Failed to start voice session audio stream.
            virtual Core::hresult VoiceSessionAudioStreamStart(const VoiceControlData::VoiceSessionAudioStreamStartRequest& request) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {

                enum { ID = ID_VOICECONTROL_NOTIFICATION };

                // @brief Triggered when a voice session begins
                // @text onSessionBegin
                // @param params: Event data containing session begin information.
                virtual void OnSessionBegin(const string& params /* @opaque */) {}

                // @brief Triggered when a device starts streaming voice data to the RDK
                // @text onStreamBegin
                // @param params: Event data containing stream begin information.
                virtual void OnStreamBegin(const string& params /* @opaque */) {}

                // @brief Triggered when a keyword verification result is received
                // @text onKeywordVerification
                // @param params: Event data containing keyword verification information.
                virtual void OnKeywordVerification(const string& params /* @opaque */) {}

                // @brief Triggered when a message is received from the Voice Server
                // @text onServerMessage
                // @param params: Event data containing server message information.
                virtual void OnServerMessage(const string& params /* @opaque */) {}

                // @brief Triggered when the device has stopped streaming audio
                // @text onStreamEnd
                // @param params: Event data containing stream end information.
                virtual void OnStreamEnd(const string& params /* @opaque */) {}

                // @brief Triggered when the interaction with the server has concluded
                // @text onSessionEnd
                // @param params: Event data containing session end information.
                virtual void OnSessionEnd(const string& params /* @opaque */) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
