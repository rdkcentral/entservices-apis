/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
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
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL ISystemAudioPlayer : virtual public Core::IUnknown {
        enum { ID = ID_SYSTEMAUDIOPLAYER };

        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_SYSTEMAUDIOPLAYER_NOTIFICATION };

            virtual ~INotification() {}

            // @text onSAPEvents
            // @alt onsapevents
            // @brief Notify SAP events
            // @details Delivers an event payload emitted by the System Audio Player plugin.
            // @param data: SAP event data
            // @example data: "{\"event\":\"playbackStarted\",\"sessionId\":\"session-123\"}"
            virtual void OnSAPEvents(const string &data) {}        
        };

        virtual ~ISystemAudioPlayer() {}
        
        // @json:omit
        // @text configure
        // @brief Configure SAP plugin
        // @details Supplies the Thunder plugin host service used to configure the System Audio Player plugin.
        // @param service: interface instance
        // @example service: PluginHost::IShell instance
        // @retval Core::NONE: Indicates successful configuration of SAP plugin
        virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

        // @json:omit
        // @text register
        // @brief Register notification interface
        // @details Registers a notification sink to receive System Audio Player events.
        // @param sink: notification interface pointer
        // @example sink: ISystemAudioPlayer::INotification instance
        // @retval Core::NONE: Indicates successful registration of sink
        virtual Core::hresult Register(INotification* sink) = 0;

        // @json:omit
        // @text unregister
        // @brief Unregister notification interface
        // @details Removes a previously registered notification sink.
        // @param sink: notification interface pointer
        // @example sink: ISystemAudioPlayer::INotification instance
        // @retval Core::NONE: Indicates successful unregistration of sink
        virtual Core::hresult Unregister(INotification* sink) = 0;

        // @text open
        // @brief Open player instance
        // @details Opens an audio player instance using the supplied request and returns the operation response.
        // @param input: parameters needed for player
        // @example input: "{\"audioType\":\"music\",\"url\":\"https://example.com/audio.mp3\"}"
        // @param output: response params
        // @example output: "{\"success\":true,\"playerId\":\"player-1\"}"
        // @retval Core::NONE: Indicates successful opening of audio player
        virtual Core::hresult Open(const string &input, string &output /* @out */) = 0;

        // @text play
        // @brief Start playback of audio.
        // @details Starts playback for the player described by the request and returns the operation response.
        // @param input: parameters needed for audio playback
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful playstate change of audio player
        virtual Core::hresult Play(const string &input, string &output /* @out */) = 0;

        // @text playBuffer
        // @brief Start playback of audiobuffer.
        // @details Starts playback of the supplied Base64-encoded audio buffer and returns the operation response.
        // @param input: Base64 encoded audio data
        // @example input: "{\"audioBuffer\":\"AQIDBA==\",\"sampleRate\":48000}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful playstate change of audio player
        virtual Core::hresult PlayBuffer(const string &input, string &output /* @out */) = 0;

        // @text pause
        // @brief Pausing audio playback
        // @details Pauses playback for the audio player identified in the request.
        // @param input: audio player id
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful pausing of audio player
        virtual Core::hresult Pause(const string &input, string &output /* @out */) = 0;

        // @text resume
        // @brief Resuming audio playback
        // @details Resumes playback for the audio player identified in the request.
        // @param input: audio player id
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful resume of audio player
        virtual Core::hresult Resume(const string &input, string &output /* @out */) = 0;

        // @text stop
        // @brief Stopping audio playback
        // @details Stops playback for the audio player identified in the request.
        // @param input: audio player id
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful stop of audio player
        virtual Core::hresult Stop(const string &input, string &output /* @out */) = 0;

        // @text close
        // @brief Closing audio playback
        // @details Closes the audio player instance identified in the request.
        // @param input: audio player id
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful close of audio player
        virtual Core::hresult Close(const string &input, string &output /* @out */) = 0;

        // @text setMixerLevels
        // @brief Setting mixer levels
        // @details Sets mixer levels using the player and level values provided in the request.
        // @param input: audio player id
        // @example input: "{\"playerId\":\"player-1\",\"levels\":[0.5,0.5]}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful setting of mixer levels
        virtual Core::hresult SetMixerLevels(const string &input, string &output /* @out */) = 0;

        // @text setSmartVolControl
        // @brief Setting smart volume level
        // @details Configures smart volume control using the settings in the request.
        // @param input: audio player id and smart volume params
        // @example input: "{\"playerId\":\"player-1\",\"enabled\":true,\"level\":0.5}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates successful setting of smart volume level
        virtual Core::hresult SetSmartVolControl(const string &input, string &output /* @out */) = 0;

        // @text isPlaying
        // @brief playing state of audio player
        // @details Retrieves the playback state for the audio player described in the request.
        // @param input: audio player details
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"isPlaying\":true}"
        // @retval Core::NONE: Indicates audio player state retrieved successfully
        virtual Core::hresult IsPlaying(const string &input, string &output /* @out */) = 0;

        // @text config
        // @brief Setting audio player configuration
        // @details Applies the configuration values supplied for the audio player.
        // @param input: configuration details
        // @example input: "{\"volume\":0.8,\"rate\":1.0}"
        // @param output: response params
        // @example output: "{\"success\":true}"
        // @retval Core::NONE: Indicates proper set of audio player configuration
        virtual Core::hresult Config(const string &input, string &output /* @out */) = 0;

        // @text getPlayerSessionId
        // @brief Getting audio player session id
        // @details Retrieves the session identifier for the audio player described in the request.
        // @param input: player details
        // @example input: "{\"playerId\":\"player-1\"}"
        // @param output: response params
        // @example output: "{\"sessionId\":\"session-123\"}"
        // @retval Core::NONE: Indicates GetPlayerSessionId retrieved successfuly
        virtual Core::hresult GetPlayerSessionId(const string &input, string &output /* @out */) = 0;

    };

} // Exchange
} // WPEFramework
