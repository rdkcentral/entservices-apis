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

// @stubgen:include <com/IIteratorType.h>

struct ctrlm_voice_iarm_event_json_t;

namespace WPEFramework {

    namespace Exchange {

        // Data structures for Voice Control

        struct EXTERNAL DeviceSettings {
            bool enable /* @brief Enable (true) or disable (false) the device */;
        };

        struct EXTERNAL DeviceStatus {
            string status /* @brief The status of the device e.g. "ready" */;
        };

        struct EXTERNAL ServerStats {
            double dnsTime     /* @brief The DNS time of the voice server in milliseconds e.g. 0.5 */;
            string serverIp    /* @brief The IP of the voice server e.g. "192.168.1.100" */;
            double connectTime /* @brief The connection time of the voice server in milliseconds e.g. 10.2 */;
        };

        struct EXTERNAL GetApiVersionNumberResponse {
            uint32_t version /* @brief The API version number e.g. 1 */;
        };

        struct EXTERNAL ConfigureVoiceRequest {
            string urlAll    /* @brief Specifies the URL for all devices instead of individually specifying the URL for each device e.g. "ws://voice.example.com" */;
            string urlPtt    /* @brief The PTT URL e.g. "ws://voice.example.com/ptt" */;
            string urlHf     /* @brief The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" */;
            string urlMicTap /* @brief The microphone tap URL e.g. "ws://voice.example.com/mictap" */;
            bool enable      /* @brief Enables or disables all of the voice devices instead of individually enabling or disabling each device */;
            bool prv         /* @brief The Press & Release Voice feature (true for enable, false for disable) */;
            bool wwFeedback  /* @brief The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable) */;
            DeviceSettings ptt /* @brief The settings for PTT devices */;
            DeviceSettings ff  /* @brief The settings for FF devices */;
            DeviceSettings mic /* @brief The settings for MIC devices */;
        };

        struct EXTERNAL SetVoiceInitRequest {
            string language /* @brief Preferred user interface language e.g. "en-US" */;
        };

        struct EXTERNAL SendVoiceMessageRequest {
            string msgType    /* @brief Message type expected from server e.g. "query" */;
            string trx        /* @brief The unique id of the voice session e.g. "12345-abc" */;
            uint64_t created  /* @brief The timestamp for server information in milliseconds since epoch */;
            string msgPayload /* @brief Message payload (opaque object) */;
        };

        struct EXTERNAL VoiceSessionByTextRequest {
            string transcription /* @brief The transcription text to be sent to the voice server e.g. "turn on the lights" */;
            string type          /* @brief The device type to simulate the voice session from e.g. "PTT", "FF", "MIC" */;
        };

        struct EXTERNAL VoiceSessionTypesResponse {
            // types array would go here, but for POD struct we return success/failure only
        };

        struct EXTERNAL VoiceSessionRequestParams {
            string transcription /* @brief The transcription text to be sent to the voice server (for ptt_transcription and mic_transcription types) e.g. "what's the weather" */;
            string audioFile     /* @brief The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file types) e.g. "/tmp/audio.wav" */;
            string type          /* @brief The request type to initiate the voice session e.g. "ptt_transcription" */;
        };

        struct EXTERNAL VoiceSessionTerminateRequest {
            string sessionId /* @brief The session identifier of the session from the onSessionBegin event e.g. "session-12345" */;
        };

        struct EXTERNAL VoiceSessionAudioStreamStartRequest {
            string sessionId /* @brief The session identifier of the session from the onSessionBegin event e.g. "session-12345" */;
        };

        struct EXTERNAL VoiceStatusResponse {
            bool maskPii   /* @brief Indicates if PII should be masked (1 - mask PII, 0 - display PII) */;
            string urlPtt  /* @brief The PTT URL e.g. "ws://voice.example.com/ptt" */;
            string urlHf   /* @brief The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" */;
            bool prv       /* @brief The Press & Release Voice feature (true for enable, false for disable) */;
            bool wwFeedback /* @brief The Wake Word Feedback feature (true for enable, false for disable) */;
            DeviceStatus ptt /* @brief The status information for the PTT device type */;
            DeviceStatus ff  /* @brief The status information for the FF device type */;
            DeviceStatus mic /* @brief The status information for the MIC device type */;
        };

        struct EXTERNAL SessionBeginEvent {
            uint32_t remoteId        /* @brief The voice device identifier e.g. 1 */;
            string sessionId         /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            string deviceType        /* @brief The type of voice device starting the session e.g. "ptt", "ff", "mic" */;
            bool keywordVerification /* @brief True if the session uses keyword verification, otherwise false */;
        };

        struct EXTERNAL StreamBeginEvent {
            uint32_t remoteId /* @brief The voice device identifier e.g. 1 */;
            string sessionId  /* @brief The unique identifier for the voice session e.g. "session-12345" */;
        };

        struct EXTERNAL KeywordVerificationEvent {
            uint32_t remoteId /* @brief The voice device identifier e.g. 1 */;
            string sessionId  /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            bool verified     /* @brief True if the keyword was verified, otherwise false */;
        };

        struct EXTERNAL ServerMessageEvent {
            string msgType    /* @brief Message type from the server e.g. "asr" */;
            string trx        /* @brief The unique id of the voice session e.g. "12345-abc" */;
            uint64_t created  /* @brief The timestamp for server information in milliseconds since epoch */;
            string msgPayload /* @brief Vrex server information */;
        };

        struct EXTERNAL StreamEndEvent {
            uint32_t remoteId /* @brief The voice device identifier e.g. 1 */;
            string sessionId  /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            uint8_t reason    /* @brief The reason code for why the device stopped streaming audio (0-6) e.g. 0 */;
        };

        struct EXTERNAL SessionEndEvent {
            ServerStats serverStats /* @brief Returns the voice server stats */;
            uint32_t remoteId       /* @brief The voice device identifier e.g. 1 */;
            string sessionId        /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            string result           /* @brief The result of the voice session e.g. "success", "error", "abort", "shortUtterance" */;
        };

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            
            enum { ID = ID_VOICECONTROL };
            
            // Begin methods
            // @brief Get the API version number
            // @text getApiVersionNumber
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            virtual Core::hresult GetApiVersionNumber(GetApiVersionNumberResponse& response /* @out */) = 0;

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
            virtual Core::hresult VoiceStatus(VoiceStatusResponse& response /* @out */) = 0;

            // @brief Configures the RDK's voice stack
            // @text configureVoice
            // @param request: The configure voice request parameters
            // @retval ErrorCode::NONE: Voice settings configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure voice settings.
            virtual Core::hresult ConfigureVoice(const ConfigureVoiceRequest& request) = 0;

            // @brief Sets the application metadata in the INIT message that gets sent to the Voice Server
            // @text setVoiceInit
            // @param request: The voice init request parameters
            // @retval ErrorCode::NONE: Voice initialization set successfully.
            // @retval ErrorCode::GENERAL: Failed to set voice initialization.
            virtual Core::hresult SetVoiceInit(const SetVoiceInitRequest& request) = 0;

            // @brief Sends a message to the Voice Server
            // @text sendVoiceMessage
            // @param request: The voice message request parameters
            // @retval ErrorCode::NONE: Voice message sent successfully.
            // @retval ErrorCode::GENERAL: Failed to send voice message.
            virtual Core::hresult SendVoiceMessage(const SendVoiceMessageRequest& request) = 0;

            // @brief Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)
            // @text voiceSessionByText
            // @param request: The voice session by text request parameters
            // @retval ErrorCode::NONE: Voice session by text executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute voice session by text.
            virtual Core::hresult VoiceSessionByText(const VoiceSessionByTextRequest& request) = 0; // DEPRECATED

            // @brief Retrieves the types of voice sessions which are supported by the platform
            // @text voiceSessionTypes
            // @param response: The voice session types response
            // @retval ErrorCode::NONE: Voice session types retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice session types.
            virtual Core::hresult VoiceSessionTypes(VoiceSessionTypesResponse& response /* @out */) = 0;

            // @brief Requests a voice session using the specified request type and optional parameters
            // @text voiceSessionRequest
            // @param request: The voice session request parameters
            // @retval ErrorCode::NONE: Voice session requested successfully.
            // @retval ErrorCode::GENERAL: Failed to request voice session.
            virtual Core::hresult VoiceSessionRequest(const VoiceSessionRequestParams& request) = 0;

            // @brief Terminates a voice session using the specified session identifier
            // @text voiceSessionTerminate
            // @param request: The voice session terminate request parameters
            // @retval ErrorCode::NONE: Voice session terminated successfully.
            // @retval ErrorCode::GENERAL: Failed to terminate voice session.
            virtual Core::hresult VoiceSessionTerminate(const VoiceSessionTerminateRequest& request) = 0;

            // @brief Starts a subsequent audio stream for the voice session indicated by the session identifier
            // @text voiceSessionAudioStreamStart
            // @param request: The voice session audio stream start request parameters
            // @retval ErrorCode::NONE: Voice session audio stream started successfully.
            // @retval ErrorCode::GENERAL: Failed to start voice session audio stream.
            virtual Core::hresult VoiceSessionAudioStreamStart(const VoiceSessionAudioStreamStartRequest& request) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {

                enum { ID = ID_VOICECONTROL_NOTIFICATION };

                // @brief Triggered when a voice session begins
                // @text onSessionBegin
                // @param params: Event data containing session begin information.
                virtual void OnSessionBegin(const SessionBeginEvent& params) {}

                // @brief Triggered when a device starts streaming voice data to the RDK
                // @text onStreamBegin
                // @param params: Event data containing stream begin information.
                virtual void OnStreamBegin(const StreamBeginEvent& params) {}

                // @brief Triggered when a keyword verification result is received
                // @text onKeywordVerification
                // @param params: Event data containing keyword verification information.
                virtual void OnKeywordVerification(const KeywordVerificationEvent& params) {}

                // @brief Triggered when a message is received from the Voice Server
                // @text onServerMessage
                // @param params: Event data containing server message information.
                virtual void OnServerMessage(const ServerMessageEvent& params) {}

                // @brief Triggered when the device has stopped streaming audio
                // @text onStreamEnd
                // @param params: Event data containing stream end information.
                virtual void OnStreamEnd(const StreamEndEvent& params) {}

                // @brief Triggered when the interaction with the server has concluded
                // @text onSessionEnd
                // @param params: Event data containing session end information.
                virtual void OnSessionEnd(const SessionEndEvent& params) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
