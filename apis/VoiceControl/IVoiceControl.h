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
#include <vector>

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {

    namespace Exchange {

        // Enums for Voice Control

        enum class DeviceType : uint8_t {
            PTT /* @text ptt */,
            FF  /* @text ff */,
            MIC /* @text mic */
        };

        enum class SessionResult : uint8_t {
            SUCCESS         /* @text success */,
            ERROR           /* @text error */,
            ABORT           /* @text abort */,
            SHORT_UTTERANCE /* @text shortUtterance */
        };

        enum class VoiceSessionRequestType : uint8_t {
            PTT_TRANSCRIPTION     /* @text ptt_transcription */,
            PTT_AUDIO_FILE        /* @text ptt_audio_file */,
            FF_TRANSCRIPTION      /* @text ff_transcription */,
            MIC_TRANSCRIPTION     /* @text mic_transcription */,
            MIC_AUDIO_FILE        /* @text mic_audio_file */,
            MIC_STREAM_DEFAULT    /* @text mic_stream_default */,
            MIC_STREAM_SINGLE     /* @text mic_stream_single */,
            MIC_STREAM_MULTI      /* @text mic_stream_multi */,
            MIC_TAP_STREAM_SINGLE /* @text mic_tap_stream_single */,
            MIC_TAP_STREAM_MULTI  /* @text mic_tap_stream_multi */,
            MIC_FACTORY_TEST      /* @text mic_factory_test */
        };

        // Data structures for Voice Control

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // ThunderTools BuildResult() collapses a single out param into a single value ("result":true/false), so we wrap the boolean success in a struct and extract to main the response shape ("result":{"success":true/false})
        struct EXTERNAL VoiceControlSuccessResult {
            bool success /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL DeviceStatus {
            string status /* @brief The status of the device e.g. "ready" */;
        };

        struct EXTERNAL ServerStats {
            double dnsTime     /* @brief The DNS time of the voice server in milliseconds ex: 0.5 */;
            string serverIp    /* @brief The IP of the voice server e.g. "192.168.1.100" */;
            double connectTime /* @brief The connection time of the voice server in milliseconds ex: 10.2 */;
        };

        struct EXTERNAL VoiceControlGetApiVersionNumberResponse {
            uint32_t version /* @brief The API version number ex: 1 */;
            bool success     /* @brief Whether the request succeeded */;
        };

        struct EXTERNAL VoiceSessionByTextRequest {
            string transcription /* @brief The transcription text to be sent to the voice server e.g. "turn on the lights" */;
            DeviceType type      /* @brief The device type to simulate the voice session from. Possible values: PTT, FF, MIC */;
        };

        struct EXTERNAL DeviceEnableConfig {
            Core::OptionalType<bool> enable /* @brief Whether the device type should be enabled */;
        };

        struct EXTERNAL VoiceInitIdentity {
            Core::OptionalType<string> type    /* @brief The device type identifier e.g. "llama" */;
            Core::OptionalType<string> partner /* @brief The partner identifier e.g. "sky-uk" */;
        };

        struct EXTERNAL VoiceStatusResponse {
            bool maskPii                            /* @brief Indicates if PII should be masked (1 - mask PII, 0 - display PII) */;
            string urlPtt                           /* @brief The PTT URL e.g. "ws://voice.example.com/ptt" */;
            string urlHf                            /* @brief The HF (ff and mic) URL e.g. "ws://voice.example.com/hf" */;
            string urlMicTap                        /* @brief The microphone tap URL e.g. "ws://voice.example.com/mictap" */;
            bool prv                                /* @brief The Press & Release Voice feature (true for enable, false for disable) */;
            bool wwFeedback                         /* @brief The Wake Word Feedback feature (true for enable, false for disable) */;
            DeviceStatus ptt                        /* @brief The status information for the PTT device type */;
            DeviceStatus ff                         /* @brief The status information for the FF device type */;
            DeviceStatus mic                        /* @brief The status information for the MIC device type */;
            Core::OptionalType<DeviceStatus> micTap /* @text mic_tap @brief The status information for the MIC TAP device type, present only when MIC TAP capability is available */;
            string capabilities                     /* @opaque @brief JSON array of capability strings returned by the voice stack. Kept as opaque JSON because of limitations of nesting COM-RPC iterators within struct data e.g. ["PRV"] */;
            bool success                            /* @brief Whether the request succeeded */;
        };

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IVoiceControl : virtual public Core::IUnknown {
            
            enum { ID = ID_VOICECONTROL };
            
            // Begin methods
            // @brief Get the API version number
            // @param response: The API version response
            // @retval ErrorCode::NONE: Operation completed successfully.
            // @text getApiVersionNumber
            virtual Core::hresult GetApiVersionNumber(VoiceControlGetApiVersionNumberResponse& response /* @out */) = 0;

            // @brief Returns the current status of the RDK voice stack
            // @text voiceStatus
            // @param response: The typed voice status fields including urlPtt, urlHf, urlMicTap, maskPii, prv, wwFeedback, ptt, ff, mic, optional mic_tap, capabilities, and success
            // @retval ErrorCode::NONE: Voice status retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice status.
            virtual Core::hresult GetVoiceStatus(VoiceStatusResponse& response /* @out */) = 0;

            // @brief Configures the RDK's voice stack. Only the fields provided are applied; omitted fields are left unchanged.
            // @text configureVoice
            // @param urlAll(optional): Convenience URL applied to urlPtt, urlHf, and urlMicTap at once e.g. "ws://voice.example.com/all"
            // @param urlPtt(optional): The PTT URL e.g. "ws://voice.example.com/ptt"
            // @param urlHf(optional): The HF (ff and mic) URL e.g. "ws://voice.example.com/hf"
            // @param urlMicTap(optional): The microphone tap URL e.g. "ws://voice.example.com/mictap"
            // @param enable(optional): Enables or disables voice globally
            // @param prv(optional): The Press & Release Voice feature (true for enable, false for disable)
            // @param wwFeedback(optional): The Wake Word Feedback feature (true for enable, false for disable)
            // @param ptt(optional): Enable configuration for the PTT device type
            // @param ff(optional): Enable configuration for the FF device type
            // @param mic(optional): Enable configuration for the MIC device type
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice settings configured successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to configure voice settings.
            virtual Core::hresult ConfigureVoice(const Core::OptionalType<string>& urlAll, const Core::OptionalType<string>& urlPtt, const Core::OptionalType<string>& urlHf, const Core::OptionalType<string>& urlMicTap, const Core::OptionalType<bool>& enable, const Core::OptionalType<bool>& prv, const Core::OptionalType<bool>& wwFeedback, const Core::OptionalType<DeviceEnableConfig>& ptt, const Core::OptionalType<DeviceEnableConfig>& ff, const Core::OptionalType<DeviceEnableConfig>& mic, VoiceControlSuccessResult& result /* @out */) = 0;

            // @brief Sets the application metadata in the INIT message that gets sent to the Voice Server. Only the fields provided are forwarded to ctrlm.
            // @text setVoiceInit
            // @param roles(optional): The client roles e.g. ["envoy", "input"]
            // @param transmissionProtocol(optional): The transmission protocol e.g. "webSocket"
            // @param downstreamProtocol(optional): The downstream protocol e.g. "webSocket"
            // @param capabilities(optional): The client capabilities e.g. ["GUI", "WBW"]
            // @param clientProfile(optional): The client profile identifier e.g. "profileName"
            // @param language(optional): The client language e.g. "eng-USA"
            // @param vrexFields(optional): The vrex fields to request e.g. ["executeResponse"]
            // @param id(optional): The device/partner identity e.g. {"type": "deviceType", "partner": "partnerName"}
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice initialization set successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to set voice initialization.
            virtual Core::hresult SetVoiceInit(const Core::OptionalType<std::vector<string>>& roles /* @restrict:8 */, const Core::OptionalType<string>& transmissionProtocol, const Core::OptionalType<string>& downstreamProtocol, const Core::OptionalType<std::vector<string>>& capabilities /* @restrict:16 */, const Core::OptionalType<string>& clientProfile, const Core::OptionalType<string>& language, const Core::OptionalType<std::vector<string>>& vrexFields /* @restrict:16 */, const Core::OptionalType<VoiceInitIdentity>& id, VoiceControlSuccessResult& result /* @out */) = 0;

            // @brief Sends a message to the Voice Server
            // @text sendVoiceMessage
            // @param msgType: Message type from the server e.g. "asr"
            // @param trx(optional): The unique id of the voice session e.g. "12345-abc"
            // @param created(optional): The timestamp for server information in milliseconds since epoch ex: 1700000000000
            // @param msgPayload(optional): Vrex server information e.g. {"appFocuses": [], "environmentalContext": {"entities": []}, "screenContext": {"searchParams": {"catalog": ["Netflix", "DisneyPlus"]}}}
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice message sent successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to send voice message.
            virtual Core::hresult SendVoiceMessage(const string& msgType, const Core::OptionalType<string>& trx, const Core::OptionalType<uint64_t>& created, const Core::OptionalType<string>& msgPayload /* @opaque */, VoiceControlSuccessResult& result /* @out */) = 0;

            // @brief Sends a voice session with a transcription string to simulate a real voice session for QA (DEPRECATED)
            // @text voiceSessionByText
            // @param transcription: The transcription text to be sent to the voice server e.g. "turn on the lights"
            // @param type(optional): The device type to simulate the voice session from. Possible values: PTT, FF, MIC
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice session by text executed successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to execute voice session by text.
            virtual Core::hresult VoiceSessionByText(const string& transcription, const Core::OptionalType<DeviceType>& type, VoiceControlSuccessResult& result /* @out */) = 0; // DEPRECATED

            // @brief Retrieves the types of voice sessions which are supported by the platform
            // @text voiceSessionTypes
            // @param success: Whether the request succeeded
            // @param types: Array of strings indicating the voice session request types which are valid e.g. "ptt_transcription"
            // @retval ErrorCode::NONE: Voice session types retrieved successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to retrieve voice session types.
            virtual Core::hresult GetVoiceSessionTypes(bool& success /* @out */, IStringIterator*& types /* @out */) = 0;

            // @brief Requests a voice session using the specified request type and optional parameters
            // @text voiceSessionRequest
            // @param type: The request type to initiate the voice session. Possible values: ptt_transcription, ptt_audio_file, ff_transcription, mic_transcription, mic_audio_file, mic_stream_default, mic_stream_single, mic_stream_multi, mic_tap_stream_single, mic_tap_stream_multi, mic_factory_test
            // @param transcription(optional): The transcription text to be sent to the voice server (for ptt_transcription and mic_transcription request types) e.g. "comedy movies"
            // @param audioFile(optional): The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file request types) e.g. "/tmp/audio.wav"
            // @param audioFormat(optional): The audio format of audioFile e.g. "pcm"
            // @param name(optional): A friendly name for the simulated session e.g. "Test"
            // @param success: Whether the request succeeded
            // @param sessionId: The identifier of the created voice session, present only when success is true e.g. "83d7747d-e02f-42f8-bdc3-bc8f510605c6"
            // @retval ErrorCode::NONE: Voice session requested successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to request voice session.
            virtual Core::hresult VoiceSessionRequest(const VoiceSessionRequestType type, const Core::OptionalType<string>& transcription, const Core::OptionalType<string>& audioFile /* @text audio_file */, const Core::OptionalType<string>& audioFormat /* @text audio_format */, const Core::OptionalType<string>& name, bool& success /* @out */, Core::OptionalType<string>& sessionId /* @out */) = 0;

            // @brief Terminates a voice session using the specified session identifier
            // @text voiceSessionTerminate
            // @param sessionId: The session identifier of the session from the onSessionBegin event e.g. "session-12345"
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice session terminated successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to terminate voice session.
            virtual Core::hresult VoiceSessionTerminate(const string& sessionId, VoiceControlSuccessResult& result /* @out */) = 0;

            // @brief Starts a subsequent audio stream for the voice session indicated by the session identifier
            // @text voiceSessionAudioStreamStart
            // @param sessionId: The session identifier of the session from the onSessionBegin event e.g. "session-12345"
            // @param result: Whether the request succeeded
            // @retval ErrorCode::NONE: Voice session audio stream started successfully.
            // @retval ErrorCode::RPC_CALL_FAILED: IARM bus call failed.
            // @retval ErrorCode::GENERAL: Failed to start voice session audio stream.
            virtual Core::hresult VoiceSessionAudioStreamStart(const string& sessionId, VoiceControlSuccessResult& result /* @out */) = 0;
            // End methods

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {

                enum { ID = ID_VOICECONTROL_NOTIFICATION };

                // @brief Triggered when a voice session begins
                // @text onSessionBegin
                // @param remoteId: The voice device identifier ex: 1
                // @param sessionId: The unique identifier for the voice session e.g. "session-12345"
                // @param deviceType: The type of voice device starting the session. Possible values: ptt, ff, mic
                // @param keywordVerification: True if the session uses keyword verification, otherwise false
                virtual void OnSessionBegin(const uint32_t remoteId, const string& sessionId, const DeviceType deviceType, const bool keywordVerification) {}

                // @brief Triggered when a device starts streaming voice data to the RDK
                // @text onStreamBegin
                // @param remoteId: The voice device identifier ex: 1
                // @param sessionId: The unique identifier for the voice session e.g. "session-12345"
                virtual void OnStreamBegin(const uint32_t remoteId, const string& sessionId) {}

                // @brief Triggered when a keyword verification result is received
                // @text onKeywordVerification
                // @param remoteId: The voice device identifier ex: 1
                // @param sessionId: The unique identifier for the voice session e.g. "session-12345"
                // @param verified: True if the keyword was verified, otherwise false
                virtual void OnKeywordVerification(const uint32_t remoteId, const string& sessionId, const bool verified) {}

                // @brief Triggered when a message is received from the Voice Server
                // @text onServerMessage
                // @param msgType: Message type from the server e.g. "asr"
                // @param trx: The unique id of the voice session e.g. "12345-abc"
                // @param created: The timestamp for server information in milliseconds since epoch ex: 1700000000000
                // @param msgPayload: Vrex server information e.g. {"appFocuses": [], "environmentalContext": {"entities": []}, "screenContext": {"searchParams": {"catalog": ["Netflix", "DisneyPlus"]}}}
                virtual void OnServerMessage(const string& msgType, const string& trx, const uint64_t created, const string& msgPayload /* @opaque @restrict:256K */) {}

                // @brief Triggered when the device has stopped streaming audio
                // @text onStreamEnd
                // @param remoteId: The voice device identifier ex: 1
                // @param sessionId: The unique identifier for the voice session e.g. "session-12345"
                // @param reason: The reason code for why the device stopped streaming audio. 0: End of Stream (Mic Key Released / EOS detected), 1: First Packet Timeout, 2: Inter-packet Timeout, 3: Max Utterance Length, 4: Adjacent Key Press, 5: Other Key Press, 6: Other / Unknown ex: 0
                virtual void OnStreamEnd(const uint32_t remoteId, const string& sessionId, const uint8_t reason) {}

                // @brief Triggered when the interaction with the server has concluded
                // @text onSessionEnd
                // @param remoteId: The voice device identifier ex: 1
                // @param sessionId: The unique identifier for the voice session e.g. "session-12345"
                // @param result: The result of the voice session. Possible values: success, error, abort, shortUtterance
                // @param serverStats: The voice server stats
                // @param success: Result data for a successful voice session containing transcription
                // @param error: Result data for a failed voice session containing error codes
                // @param abort: Result data for an aborted voice session containing reason
                // @param shortUtterance: Result data for a short utterance voice session containing reason
                // @param stbStats: STB statistics including device type, firmware, and controller info
                virtual void OnSessionEnd(const uint32_t remoteId, const string& sessionId, const SessionResult result, const ServerStats& serverStats, const Core::OptionalType<string>& success /* @opaque */, const Core::OptionalType<string>& error /* @opaque */, const Core::OptionalType<string>& abort /* @opaque */, const Core::OptionalType<string>& shortUtterance /* @opaque */, const Core::OptionalType<string>& stbStats /* @opaque */) {}
            };

            // @json:omit
            // @text register
            // @brief Register notification interface
            // @param notification: Notification interface pointer
            // @retval Core::ERROR_NONE: Indicates successful registration of notification interface
            // @retval Core::ERROR_BAD_REQUEST: notification is null
            virtual Core::hresult Register(IVoiceControl::INotification* notification) = 0;

            // @json:omit
            // @text unregister
            // @brief Unregister notification interface
            // @param notification: Notification interface pointer
            // @retval Core::ERROR_NONE: Indicates successful unregistration of notification interface
            // @retval Core::ERROR_BAD_REQUEST: notification is null
            virtual Core::hresult Unregister(const IVoiceControl::INotification* notification) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
