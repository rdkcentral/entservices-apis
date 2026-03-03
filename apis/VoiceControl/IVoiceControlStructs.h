/**
 * @file IVoiceControlStructs.h
 * @brief Data structures for Voice Control JSONRPC interface
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

#include <core/JSON.h>

namespace WPEFramework {
namespace Exchange {
namespace VoiceControlData {

    // @json 1.0.0
    struct DeviceSettings : public Core::JSON::Container {
        DeviceSettings(const DeviceSettings&) = delete;
        DeviceSettings& operator=(const DeviceSettings&) = delete;

        DeviceSettings()
            : Core::JSON::Container()
            , Enable(false)
        {
            Add(_T("enable"), &Enable);
        }

        ~DeviceSettings() override = default;

        // @brief Enable (true) or disable (false)
        Core::JSON::Boolean Enable;
    };

    // @json 1.0.0
    struct DeviceStatus : public Core::JSON::Container {
        DeviceStatus(const DeviceStatus&) = delete;
        DeviceStatus& operator=(const DeviceStatus&) = delete;

        DeviceStatus()
            : Core::JSON::Container()
            , Status()
        {
            Add(_T("status"), &Status);
        }

        ~DeviceStatus() override = default;

        // @brief The status of the device
        Core::JSON::String Status;
    };

    // @json 1.0.0
    struct ServerStats : public Core::JSON::Container {
        ServerStats(const ServerStats&) = delete;
        ServerStats& operator=(const ServerStats&) = delete;

        ServerStats()
            : Core::JSON::Container()
            , DnsTime(0.0)
            , ServerIp()
            , ConnectTime(0.0)
        {
            Add(_T("dnsTime"), &DnsTime);
            Add(_T("serverIp"), &ServerIp);
            Add(_T("connectTime"), &ConnectTime);
        }

        ~ServerStats() override = default;

        // @brief The DNS time of the voice server
        Core::JSON::Double DnsTime;
        // @brief The IP of the voice server
        Core::JSON::String ServerIp;
        // @brief The connection time of the voice server
        Core::JSON::Double ConnectTime;
    };

    // ============== Request/Response Structures ==============

    // @json 1.0.0
    struct GetApiVersionNumberResponse : public Core::JSON::Container {
        GetApiVersionNumberResponse(const GetApiVersionNumberResponse&) = delete;
        GetApiVersionNumberResponse& operator=(const GetApiVersionNumberResponse&) = delete;

        GetApiVersionNumberResponse()
            : Core::JSON::Container()
            , Version(0)
        {
            Add(_T("version"), &Version);
        }

        ~GetApiVersionNumberResponse() override = default;

        // @brief The API version number
        Core::JSON::DecUInt32 Version;
    };

    // @json 1.0.0
    struct ConfigureVoiceRequest : public Core::JSON::Container {
        ConfigureVoiceRequest(const ConfigureVoiceRequest&) = delete;
        ConfigureVoiceRequest& operator=(const ConfigureVoiceRequest&) = delete;

        ConfigureVoiceRequest()
            : Core::JSON::Container()
            , UrlAll()
            , UrlPtt()
            , UrlHf()
            , UrlMicTap()
            , Enable()
            , Prv()
            , WwFeedback()
            , Ptt()
            , Ff()
            , Mic()
        {
            Add(_T("urlAll"), &UrlAll);
            Add(_T("urlPtt"), &UrlPtt);
            Add(_T("urlHf"), &UrlHf);
            Add(_T("urlMicTap"), &UrlMicTap);
            Add(_T("enable"), &Enable);
            Add(_T("prv"), &Prv);
            Add(_T("wwFeedback"), &WwFeedback);
            Add(_T("ptt"), &Ptt);
            Add(_T("ff"), &Ff);
            Add(_T("mic"), &Mic);
        }

        ~ConfigureVoiceRequest() override = default;

        // @brief Specifies the URL for all devices instead of individually specifying the URL for each device
        Core::JSON::String UrlAll;
        // @brief The PTT URL
        Core::JSON::String UrlPtt;
        // @brief The HF (ff and mic) URL
        Core::JSON::String UrlHf;
        // @brief The microphone tap URL
        Core::JSON::String UrlMicTap;
        // @brief Enables or disables all of the voice devices instead of individually enabling or disabling each device
        Core::JSON::Boolean Enable;
        // @brief The Press & Release Voice feature (true for enable, false for disable)
        Core::JSON::Boolean Prv;
        // @brief The Wake Word Feedback feature, typically an audible beep (true for enable, false for disable)
        Core::JSON::Boolean WwFeedback;
        // @brief The settings for PTT devices
        DeviceSettings Ptt;
        // @brief The settings for FF devices
        DeviceSettings Ff;
        // @brief The settings for MIC devices
        DeviceSettings Mic;
    };

    // @json 1.0.0
    struct SetVoiceInitRequest : public Core::JSON::Container {
        SetVoiceInitRequest(const SetVoiceInitRequest&) = delete;
        SetVoiceInitRequest& operator=(const SetVoiceInitRequest&) = delete;

        SetVoiceInitRequest()
            : Core::JSON::Container()
            , Capabilities()
            , Language()
        {
            Add(_T("capabilities"), &Capabilities);
            Add(_T("language"), &Language);
        }

        ~SetVoiceInitRequest() override = default;

        // @brief A list of capabilities
        Core::JSON::ArrayType<Core::JSON::String> Capabilities;
        // @brief Preferred user interface language
        Core::JSON::String Language;
    };

    // @json 1.0.0
    struct SendVoiceMessageRequest : public Core::JSON::Container {
        SendVoiceMessageRequest(const SendVoiceMessageRequest&) = delete;
        SendVoiceMessageRequest& operator=(const SendVoiceMessageRequest&) = delete;

        SendVoiceMessageRequest()
            : Core::JSON::Container()
            , MsgType()
            , Trx()
            , Created(0)
            , MsgPayload()
        {
            Add(_T("msgType"), &MsgType);
            Add(_T("trx"), &Trx);
            Add(_T("created"), &Created);
            Add(_T("msgPayload"), &MsgPayload);
        }

        ~SendVoiceMessageRequest() override = default;

        // @brief Message type expected from server
        Core::JSON::String MsgType;
        // @brief The unique id of the voice session
        Core::JSON::String Trx;
        // @brief The timestamp for server information
        Core::JSON::DecUInt64 Created;
        // @brief Message payload (opaque object)
        Core::JSON::String MsgPayload;
    };

    // @json 1.0.0
    struct VoiceSessionByTextRequest : public Core::JSON::Container {
        VoiceSessionByTextRequest(const VoiceSessionByTextRequest&) = delete;
        VoiceSessionByTextRequest& operator=(const VoiceSessionByTextRequest&) = delete;

        VoiceSessionByTextRequest()
            : Core::JSON::Container()
            , Transcription()
            , Type()
        {
            Add(_T("transcription"), &Transcription);
            Add(_T("type"), &Type);
        }

        ~VoiceSessionByTextRequest() override = default;

        // @brief The transcription text to be sent to the voice server
        Core::JSON::String Transcription;
        // @brief The device type to simulate the voice session from (PTT, FF, MIC)
        Core::JSON::String Type;
    };

    // @json 1.0.0
    struct VoiceSessionTypesResponse : public Core::JSON::Container {
        VoiceSessionTypesResponse(const VoiceSessionTypesResponse&) = delete;
        VoiceSessionTypesResponse& operator=(const VoiceSessionTypesResponse&) = delete;

        VoiceSessionTypesResponse()
            : Core::JSON::Container()
            , Types()
        {
            Add(_T("types"), &Types);
        }

        ~VoiceSessionTypesResponse() override = default;

        // @brief Array of strings indicating the voice session request types which are valid
        Core::JSON::ArrayType<Core::JSON::String> Types;
    };

    // @json 1.0.0
    struct VoiceSessionRequestParams : public Core::JSON::Container {
        VoiceSessionRequestParams(const VoiceSessionRequestParams&) = delete;
        VoiceSessionRequestParams& operator=(const VoiceSessionRequestParams&) = delete;

        VoiceSessionRequestParams()
            : Core::JSON::Container()
            , Transcription()
            , AudioFile()
            , Type()
        {
            Add(_T("transcription"), &Transcription);
            Add(_T("audio_file"), &AudioFile);
            Add(_T("type"), &Type);
        }

        ~VoiceSessionRequestParams() override = default;

        // @brief The transcription text to be sent to the voice server (for ptt_transcription and mic_transcription types)
        Core::JSON::String Transcription;
        // @brief The full path to the audio file to be sent to the voice server (for ptt_audio_file and mic_audio_file types)
        Core::JSON::String AudioFile;
        // @brief The request type to initiate the voice session
        Core::JSON::String Type;
    };

    // @json 1.0.0
    struct VoiceSessionTerminateRequest : public Core::JSON::Container {
        VoiceSessionTerminateRequest(const VoiceSessionTerminateRequest&) = delete;
        VoiceSessionTerminateRequest& operator=(const VoiceSessionTerminateRequest&) = delete;

        VoiceSessionTerminateRequest()
            : Core::JSON::Container()
            , SessionId()
        {
            Add(_T("sessionId"), &SessionId);
        }

        ~VoiceSessionTerminateRequest() override = default;

        // @brief The session identifier of the session from the onSessionBegin event
        Core::JSON::String SessionId;
    };

    // @json 1.0.0
    struct VoiceSessionAudioStreamStartRequest : public Core::JSON::Container {
        VoiceSessionAudioStreamStartRequest(const VoiceSessionAudioStreamStartRequest&) = delete;
        VoiceSessionAudioStreamStartRequest& operator=(const VoiceSessionAudioStreamStartRequest&) = delete;

        VoiceSessionAudioStreamStartRequest()
            : Core::JSON::Container()
            , SessionId()
        {
            Add(_T("sessionId"), &SessionId);
        }

        ~VoiceSessionAudioStreamStartRequest() override = default;

        // @brief The session identifier of the session from the onSessionBegin event
        Core::JSON::String SessionId;
    };

    // @json 1.0.0
    struct VoiceStatusResponse : public Core::JSON::Container {
        VoiceStatusResponse(const VoiceStatusResponse&) = delete;
        VoiceStatusResponse& operator=(const VoiceStatusResponse&) = delete;

        VoiceStatusResponse()
            : Core::JSON::Container()
            , MaskPii()
            , Capabilities()
            , UrlPtt()
            , UrlHf()
            , Prv(false)
            , WwFeedback(false)
            , Ptt()
            , Ff()
            , Mic()
        {
            Add(_T("maskPii"), &MaskPii);
            Add(_T("capabilities"), &Capabilities);
            Add(_T("urlPtt"), &UrlPtt);
            Add(_T("urlHf"), &UrlHf);
            Add(_T("prv"), &Prv);
            Add(_T("wwFeedback"), &WwFeedback);
            Add(_T("ptt"), &Ptt);
            Add(_T("ff"), &Ff);
            Add(_T("mic"), &Mic);
        }

        ~VoiceStatusResponse() override = default;

        // @brief Indicates if PII should be masked (1 - mask PII, 0 - display PII)
        Core::JSON::Boolean MaskPii;
        // @brief A list of capabilities
        Core::JSON::ArrayType<Core::JSON::String> Capabilities;
        // @brief The PTT URL
        Core::JSON::String UrlPtt;
        // @brief The HF (ff and mic) URL
        Core::JSON::String UrlHf;
        // @brief The Press & Release Voice feature (true for enable, false for disable)
        Core::JSON::Boolean Prv;
        // @brief The Wake Word Feedback feature (true for enable, false for disable)
        Core::JSON::Boolean WwFeedback;
        // @brief The status information for the PTT device type
        DeviceStatus Ptt;
        // @brief The status information for the FF device type
        DeviceStatus Ff;
        // @brief The status information for the MIC device type
        DeviceStatus Mic;
    };

    // ============== Event Structures ==============

    // @json 1.0.0
    struct SessionBeginEvent : public Core::JSON::Container {
        SessionBeginEvent(const SessionBeginEvent&) = delete;
        SessionBeginEvent& operator=(const SessionBeginEvent&) = delete;

        SessionBeginEvent()
            : Core::JSON::Container()
            , RemoteId(0)
            , SessionId()
            , DeviceType()
            , KeywordVerification(false)
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("sessionId"), &SessionId);
            Add(_T("deviceType"), &DeviceType);
            Add(_T("keywordVerification"), &KeywordVerification);
        }

        ~SessionBeginEvent() override = default;

        // @brief The voice device identifier
        Core::JSON::DecUInt32 RemoteId;
        // @brief The unique identifier for the voice session
        Core::JSON::String SessionId;
        // @brief The type of voice device starting the session (ptt, ff, mic)
        Core::JSON::String DeviceType;
        // @brief True if the session uses keyword verification, otherwise false
        Core::JSON::Boolean KeywordVerification;
    };

    // @json 1.0.0
    struct StreamBeginEvent : public Core::JSON::Container {
        StreamBeginEvent(const StreamBeginEvent&) = delete;
        StreamBeginEvent& operator=(const StreamBeginEvent&) = delete;

        StreamBeginEvent()
            : Core::JSON::Container()
            , RemoteId(0)
            , SessionId()
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("sessionId"), &SessionId);
        }

        ~StreamBeginEvent() override = default;

        // @brief The voice device identifier
        Core::JSON::DecUInt32 RemoteId;
        // @brief The unique identifier for the voice session
        Core::JSON::String SessionId;
    };

    // @json 1.0.0
    struct KeywordVerificationEvent : public Core::JSON::Container {
        KeywordVerificationEvent(const KeywordVerificationEvent&) = delete;
        KeywordVerificationEvent& operator=(const KeywordVerificationEvent&) = delete;

        KeywordVerificationEvent()
            : Core::JSON::Container()
            , RemoteId(0)
            , SessionId()
            , Verified(false)
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("sessionId"), &SessionId);
            Add(_T("verified"), &Verified);
        }

        ~KeywordVerificationEvent() override = default;

        // @brief The voice device identifier
        Core::JSON::DecUInt32 RemoteId;
        // @brief The unique identifier for the voice session
        Core::JSON::String SessionId;
        // @brief True if the keyword was verified, otherwise false
        Core::JSON::Boolean Verified;
    };

    // @json 1.0.0
    struct ServerMessageEvent : public Core::JSON::Container {
        ServerMessageEvent(const ServerMessageEvent&) = delete;
        ServerMessageEvent& operator=(const ServerMessageEvent&) = delete;

        ServerMessageEvent()
            : Core::JSON::Container()
            , MsgType()
            , Trx()
            , Created(0)
            , MsgPayload()
        {
            Add(_T("msgType"), &MsgType);
            Add(_T("trx"), &Trx);
            Add(_T("created"), &Created);
            Add(_T("msgPayload"), &MsgPayload);
        }

        ~ServerMessageEvent() override = default;

        // @brief Message type from the server
        Core::JSON::String MsgType;
        // @brief The unique id of the voice session
        Core::JSON::String Trx;
        // @brief The timestamp for server information
        Core::JSON::DecUInt64 Created;
        // @brief Vrex server information
        Core::JSON::String MsgPayload;
    };

    // @json 1.0.0
    struct StreamEndEvent : public Core::JSON::Container {
        StreamEndEvent(const StreamEndEvent&) = delete;
        StreamEndEvent& operator=(const StreamEndEvent&) = delete;

        StreamEndEvent()
            : Core::JSON::Container()
            , RemoteId(0)
            , SessionId()
            , Reason(0)
        {
            Add(_T("remoteId"), &RemoteId);
            Add(_T("sessionId"), &SessionId);
            Add(_T("reason"), &Reason);
        }

        ~StreamEndEvent() override = default;

        // @brief The voice device identifier
        Core::JSON::DecUInt32 RemoteId;
        // @brief The unique identifier for the voice session
        Core::JSON::String SessionId;
        // @brief The reason code for why the device stopped streaming audio (0-6)
        Core::JSON::DecUInt8 Reason;
    };

    // @json 1.0.0
    struct SessionEndEvent : public Core::JSON::Container {
        SessionEndEvent(const SessionEndEvent&) = delete;
        SessionEndEvent& operator=(const SessionEndEvent&) = delete;

        SessionEndEvent()
            : Core::JSON::Container()
            , ServerStats()
            , RemoteId(0)
            , SessionId()
            , Result()
        {
            Add(_T("serverStats"), &ServerStats);
            Add(_T("remoteId"), &RemoteId);
            Add(_T("sessionId"), &SessionId);
            Add(_T("result"), &Result);
        }

        ~SessionEndEvent() override = default;

        // @brief Returns the voice server stats
        VoiceControlData::ServerStats ServerStats;
        // @brief The voice device identifier
        Core::JSON::DecUInt32 RemoteId;
        // @brief The unique identifier for the voice session
        Core::JSON::String SessionId;
        // @brief The result of the voice session (success, error, abort, shortUtterance)
        Core::JSON::String Result;
    };

} // namespace VoiceControlData
} // namespace Exchange
} // namespace WPEFramework
