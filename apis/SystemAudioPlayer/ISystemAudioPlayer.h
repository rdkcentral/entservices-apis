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
            // @brief Notify SAP events
            // @param data: SAP event data
            virtual void OnSAPEvents(const string &data) {}        
        };

        virtual ~ISystemAudioPlayer() {}

        // @text configure
        // @brief Configure SAP plugin
        // @param service: interface instance
        // @retval Core::NONE: Indicates successful configuration of SAP plugin
        virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

        // @text register
        // @brief Register notification interface
        // @param sink: notification interface pointer
        // @retval Core::NONE: Indicates successful registration of sink
        virtual Core::hresult Register(INotification* sink) = 0;

        // @text unregister
        // @brief Unregister notification interface
        // @param sink: notification interface pointer
        // @retval Core::NONE: Indicates successful unregistration of sink
        virtual Core::hresult Unregister(INotification* sink) = 0;

        // @text open
        // @brief open player instance
        // @param input: parameters needed for player
        // @param output: response params
        // @retval Core::NONE: Indicates successful opening of audio player
        virtual Core::hresult Open(const string &input, string &output /* @out */) = 0;

        // @text play
        // @brief start playback of audio.
        // @param input: parameters needed for audio playback
        // @param output: response params
        // @retval Core::NONE: Indicates successful opening of audio player
        virtual Core::hresult Play(const string &input, string &output /* @out */) = 0;

        // @text playBuffer
        // @brief start playback of audiobuffer.
        // @param input: Base64 encoded audio data
        // @param output: response params
        // @retval Core::NONE: Indicates successful playstate change of audio player
        virtual Core::hresult PlayBuffer(const string &input, string &output /* @out */) = 0;

        // @text pause
        // @brief pausing audio playback
        // @param input: audio player id
        // @param output: response params
        // @retval Core::NONE: Indicates successful pausing of audio player
        virtual Core::hresult Pause(const string &input, string &output /* @out */) = 0;

        // @text resume
        // @brief resuming audio playback
        // @param input: audio player id
        // @param output: response params
        // @retval Core::NONE: Indicates successful resume of audio player
        virtual Core::hresult Resume(const string &input, string &output /* @out */) = 0;

        // @text stop
        // @brief stopping audio playback
        // @param input: audio player id
        // @param output: response params
        // @retval Core::NONE: Indicates successful stop of audio player
        virtual Core::hresult Stop(const string &input, string &output /* @out */) = 0;

        // @text close
        // @brief closing audio playback
        // @param input: audio player id
        // @param output: response params
        // @retval Core::NONE: Indicates successful close of audio player
        virtual Core::hresult Close(const string &input, string &output /* @out */) = 0;

        // @text setMixerLevels
        // @brief setting mixer levels
        // @param input: audio player id
        // @param output: response params
        // @retval Core::NONE: Indicates successful setting of mixer levels
        virtual Core::hresult SetMixerLevels(const string &input, string &output /* @out */) = 0;

        // @text setSmartVolControl
        // @brief setting smart volume level
        // @param input: audio player id and smart volume params
        // @param output: response params
        // @retval Core::NONE: Indicates successful setting of smart volume level
        virtual Core::hresult SetSmartVolControl(const string &input, string &output /* @out */) = 0;

        // @text isPlaying
        // @brief get state of audio player
        // @param input: audio player details
        // @param output: response params
        // @retval Core::NONE: Indicates audio player state retrieved successfuly
        virtual Core::hresult IsPlaying(const string &input, string &output /* @out */) = 0;

        // @text config
        // @brief setting audio player configuration
        // @param input: configuration details
        // @param output: response params
        // @retval Core::NONE: Indicates proper set of audio player configuration
        virtual Core::hresult Config(const string &input, string &output /* @out */) = 0;

        // @text getPlayerSessionId
        // @brief getting audio player session id
        // @param input: player details
        // @param output: response params
        // @retval Core::NONE: Indicates GetPlayerSessionId retrieved successfuly
        virtual Core::hresult GetPlayerSessionId(const string &input, string &output /* @out */) = 0;

    };

} // Exchange
} // WPEFramework
