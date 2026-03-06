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

namespace WPEFramework {

    namespace Exchange {

        // Enums for Voice Control

        enum class DeviceType : uint8_t {
            PTT /* @text PTT */,
            FF  /* @text FF */,
            MIC /* @text MIC */
        };

        enum class SessionResult : uint8_t {
            SUCCESS         /* @text success */,
            ERROR           /* @text error */,
            ABORT           /* @text abort */,
            SHORT_UTTERANCE /* @text shortUtterance */
        };

        // Data structures for Voice Control

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        struct EXTERNAL DeviceSettings {
            bool enable /* @brief Enable (true) or disable (false) the device */;
        };

        struct EXTERNAL DeviceStatus {
            string status /* @brief The status of the device e.g. "ready" */;
        };

        struct EXTERNAL ServerStats {
            double dnsTime     /* @brief The DNS time of the voice server in milliseconds ex: 0.5 */;
            string serverIp    /* @brief The IP of the voice server e.g. "192.168.1.100" */;
            double connectTime /* @brief The connection time of the voice server in milliseconds ex: 10.2 */;
        };

        struct EXTERNAL SuccessResponse {
            bool success /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL GetApiVersionNumberResponse {
            uint32_t version /* @brief The API version number ex: 1 */;
            bool success /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL ConfigureVoiceRequest {
            string urlAll      /* @brief Specifies the URL for all devices instead of individually specifying the URL for each device. URL Scheme determines which API protocol is used (http/https: VREX Legacy HTTP API, ws/wss: VREX XR18  WS API, vrng/vrngs: VREX NextGen WS API, aows/aowss: Audio only over websockets, sdt: Simple data transfer) e.g. "ws://voice.example.com" */;
            string urlPtt      /* @brief The PTT URL e.g. "ws://voice.example.com/ptt" */;
            string urlHf       /* @brief The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" */;
            string urlMicTap   /* @brief The microphone tap URL e.g. "ws://voice.example.com/mictap" */;
            bool enable        /* @brief Enables or disables all of the voice devices instead of individually enabling or disabling each device */;
            bool prv           /* @brief The Press & Release Voice feature (true for enable, false for disable) */;
            bool wwFeedback    /* @brief The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable) */;
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
            DeviceType type      /* @brief The device type to simulate the voice session from. Possible values: PTT, FF, MIC */;
        };

        struct EXTERNAL VoiceSessionTypesResponse {
            bool success /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL VoiceSessionRequestData {
            string transcription /* @brief The transcription text to be sent to the voice server (for ptt_transcription and mic_transcription request types) e.g. "what's the weather" */;
            string audioFile     /* @brief The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file request types) e.g. "/tmp/audio.wav" */;
            string type          /* @brief The request type to initiate the voice session. Use voiceSessionTypes method to get supported types (e.g. ptt_transcription, ptt_audio_file, mic_transcription, mic_audio_file, mic_stream_default, mic_stream_single, mic_stream_multi, mic_tap_stream_single, mic_tap_stream_multi, mic_factory_test) e.g. "ptt_transcription" */;
        };

        struct EXTERNAL VoiceSessionTerminateRequest {
            string sessionId /* @brief The session identifier of the session from the onSessionBegin event e.g. "session-12345" */;
        };

        struct EXTERNAL VoiceSessionAudioStreamStartRequest {
            string sessionId /* @brief The session identifier of the session from the onSessionBegin event e.g. "session-12345" */;
        };

        struct EXTERNAL VoiceStatusResponse {
            bool maskPii     /* @brief Indicates if PII should be masked (1 - mask PII, 0 - display PII) */;
            string urlPtt    /* @brief The PTT URL e.g. "ws://voice.example.com/ptt" */;
            string urlHf     /* @brief The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" */;
            bool prv         /* @brief The Press & Release Voice feature (true for enable, false for disable) */;
            bool wwFeedback  /* @brief The Wake Word Feedback feature (true for enable, false for disable) */;
            DeviceStatus ptt /* @brief The status information for the PTT device type */;
            DeviceStatus ff  /* @brief The status information for the FF device type */;
            DeviceStatus mic /* @brief The status information for the MIC device type */;
            bool success     /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL SessionBeginEvent {
            uint32_t remoteId        /* @brief The voice device identifier ex: 1 */;
            string sessionId         /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            DeviceType deviceType    /* @brief The type of voice device starting the session. Possible values: PTT, FF, MIC */;
            bool keywordVerification /* @brief True if the session uses keyword verification, otherwise false */;
        };

        struct EXTERNAL StreamBeginEvent {
            uint32_t remoteId /* @brief The voice device identifier ex: 1 */;
            string sessionId  /* @brief The unique identifier for the voice session e.g. "session-12345" */;
        };

        struct EXTERNAL KeywordVerificationEvent {
            uint32_t remoteId /* @brief The voice device identifier ex: 1 */;
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
            uint32_t remoteId /* @brief The voice device identifier ex: 1 */;
            string sessionId  /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            uint8_t reason    /* @brief The reason code for why the device stopped streaming audio. 0: End of Stream (Mic Key Released / EOS detected), 1: First Packet Timeout, 2: Inter-packet Timeout, 3: Max Utterance Length, 4: Adjacent Key Press, 5: Other Key Press, 6: Other / Unknown ex: 0 */;
        };

        struct EXTERNAL SessionEndEvent {
            ServerStats serverStats /* @brief Returns the voice server stats */;
            uint32_t remoteId       /* @brief The voice device identifier ex: 1 */;
            string sessionId        /* @brief The unique identifier for the voice session e.g. "session-12345" */;
            SessionResult result    /* @brief The result of the voice session. Possible values: success, error, abort, shortUtterance */;
        };

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            
            enum { ID = ID_VOICECONTROL };
            
            // Begin methods
            // @brief Get the API version number
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @retval ErrorCode::GENERAL: General failure.
            // @text getApiVersionNumber
            virtual Core::hresult GetApiVersionNumber(GetApiVersionNumberResponse& response /* @out @unwrapped */) = 0;

            // @json:omit
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
            // @param capabilities: A list of capabilities
            // @retval ErrorCode::NONE: Voice status retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice status.
            virtual Core::hresult GetVoiceStatus(VoiceStatusResponse& response /* @out */, IStringIterator*& capabilities /* @out */) = 0;

            // @brief Configures the RDK's voice stack
            // @text configureVoice
            // @param request: The configure voice request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice settings configured successfully.
            // @retval ErrorCode::GENERAL: Failed to configure voice settings.
            virtual Core::hresult ConfigureVoice(const ConfigureVoiceRequest& request, SuccessResponse& response /* @out */) = 0;

            // @brief Sets the application metadata in the INIT message that gets sent to the Voice Server
            // @text setVoiceInit
            // @param language: Preferred user interface language
            // @param capabilities: A list of capabilities
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice initialization set successfully.
            // @retval ErrorCode::GENERAL: Failed to set voice initialization.
            virtual Core::hresult SetVoiceInit(const string& language, IStringIterator* const capabilities, SuccessResponse& response /* @out */) = 0;

            // @brief Sends a message to the Voice Server
            // @text sendVoiceMessage
            // @param request: The voice message request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice message sent successfully.
            // @retval ErrorCode::GENERAL: Failed to send voice message.
            virtual Core::hresult SendVoiceMessage(const SendVoiceMessageRequest& request, SuccessResponse& response /* @out */) = 0;

            // @brief Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)
            // @text voiceSessionByText
            // @param request: The voice session by text request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice session by text executed successfully.
            // @retval ErrorCode::GENERAL: Failed to execute voice session by text.
            virtual Core::hresult VoiceSessionByText(const VoiceSessionByTextRequest& request, SuccessResponse& response /* @out */) = 0; // DEPRECATED

            // @brief Retrieves the types of voice sessions which are supported by the platform
            // @text voiceSessionTypes
            // @param response: The voice session types response
            // @param types: Array of strings indicating the voice session request types which are valid
            // @retval ErrorCode::NONE: Voice session types retrieved successfully.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice session types.
            virtual Core::hresult GetVoiceSessionTypes(VoiceSessionTypesResponse& response /* @out */, IStringIterator*& types /* @out */) = 0;

            // @brief Requests a voice session using the specified request type and optional parameters
            // @text voiceSessionRequest
            // @param request: The voice session request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice session requested successfully.
            // @retval ErrorCode::GENERAL: Failed to request voice session.
            virtual Core::hresult VoiceSessionRequest(const VoiceSessionRequestData& request, SuccessResponse& response /* @out */) = 0;

            // @brief Terminates a voice session using the specified session identifier
            // @text voiceSessionTerminate
            // @param request: The voice session terminate request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice session terminated successfully.
            // @retval ErrorCode::GENERAL: Failed to terminate voice session.
            virtual Core::hresult VoiceSessionTerminate(const VoiceSessionTerminateRequest& request, SuccessResponse& response /* @out */) = 0;

            // @brief Starts a subsequent audio stream for the voice session indicated by the session identifier
            // @text voiceSessionAudioStreamStart
            // @param request: The voice session audio stream start request parameters
            // @param response: The response containing success status
            // @retval ErrorCode::NONE: Voice session audio stream started successfully.
            // @retval ErrorCode::GENERAL: Failed to start voice session audio stream.
            virtual Core::hresult VoiceSessionAudioStreamStart(const VoiceSessionAudioStreamStartRequest& request, SuccessResponse& response /* @out */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {

                enum { ID = ID_VOICECONTROL_NOTIFICATION };

                // @brief Triggered when a voice session begins
                // @text onSessionBegin
                // @param event: Session begin event data including remote ID, session ID, device type, and keyword verification status
                virtual void OnSessionBegin(const SessionBeginEvent& event) {}

                // @brief Triggered when a device starts streaming voice data to the RDK
                // @text onStreamBegin
                // @param event: Stream begin event data including remote ID and session ID
                virtual void OnStreamBegin(const StreamBeginEvent& event) {}

                // @brief Triggered when a keyword verification result is received
                // @text onKeywordVerification
                // @param event: Keyword verification event data including remote ID, session ID, and verification result
                virtual void OnKeywordVerification(const KeywordVerificationEvent& event) {}

                // @brief Triggered when a message is received from the Voice Server
                // @text onServerMessage
                // @param event: Server message event data including message type, transaction ID, timestamp, and message payload
                virtual void OnServerMessage(const ServerMessageEvent& event) {}

                // @brief Triggered when the device has stopped streaming audio
                // @text onStreamEnd
                // @param event: Stream end event data including remote ID, session ID, and reason code for stopping
                virtual void OnStreamEnd(const StreamEndEvent& event) {}

                // @brief Triggered when the interaction with the server has concluded
                // @text onSessionEnd
                // @param event: Session end event data including server stats, remote ID, session ID, and session result
                virtual void OnSessionEnd(const SessionEndEvent& event) {}
            };
        };
    } // namespace Exchange
} // namespace WPEFramework
