/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
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
 */

#ifndef __ITEXTTOSPEECH_H
#define __ITEXTTOSPEECH_H

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL ITextToSpeech : virtual public Core::IUnknown {
        enum { ID = ID_TEXT_TO_SPEECH };

        struct Configuration {
            std::string ttsEndPoint;
            std::string ttsEndPointSecured;
            std::string language;
            std::string voice;
            std::string speechRate;
            uint8_t volume;
            uint8_t rate;
        };

        enum SpeechState: uint8_t {
            SPEECH_PENDING = 0,
            SPEECH_IN_PROGRESS,
            SPEECH_PAUSED,
            SPEECH_NOT_FOUND
        };

        enum TTSErrorDetail: uint8_t {
            TTS_OK = 0,
            TTS_FAIL,
            TTS_NOT_ENABLED,
            TTS_INVALID_CONFIGURATION,
            TTS_NO_ACCESS
        };


        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_TEXT_TO_SPEECH_NOTIFICATION };

            ~INotification() override = default;

            // Signal changes on the subscribed namespace
            // @text onTTSEnabled
            // @brief Notify TTS enabled/disabled
            // @param state: enabled/disabled
            virtual void onTTSEnabled(const bool /*state*/) {}

            // @text onVoiceUpdated
            // @brief Notify change in voice used for speaking
            // @param voice: voice changed
            virtual void onVoiceUpdated(const string /*voice*/) {}

            // @text onSpeechReady
            // @brief Notify that speech is possible
            // @param speechid: id of the text
            virtual void onSpeechReady(const uint32_t /*speechid*/) {}

            // @text onSpeechStarted
            // @brief Notify that speech is started
            // @param speechid: id of the text
            virtual void onSpeechStarted(const uint32_t /*speechid*/) {}
            
            // @text onSpeechPaused
            // @brief Notify that speech is paused
            // @param speechid: id of the text
            virtual void onSpeechPaused(const uint32_t /*speechid*/) {}
            
            // @text onSpeechResumed
            // @brief Notify that speech is continued
            // @param speechid: id of the text
            virtual void onSpeechResumed(const uint32_t /*speechid*/) {}
            
            // @text onSpeechDisrupted
            // @brief Notify that speech is interrupted
            // @param speechid: id of the text
            virtual void onSpeechDisrupted(const uint32_t /*speechid*/) {}
            
            // @text onConnectionLost
            // @brief Notify that network connection is lost
            // @param speechid: id of the text
            virtual void onConnectionLost(const uint32_t /*speechid*/) {}
            
            // @text onPlaybackFailed
            // @brief Notify that there is a playback failure
            // @param speechid: id of the text
            virtual void onPlaybackFailed(const uint32_t /*speechid*/) {}

            // @text onSpeechCompleted
            // @brief Notify that speech is completed
            // @param speechid: id of the text
            virtual void onSpeechCompleted(const uint32_t /*speechid*/) {}
        };

        ~ITextToSpeech() override = default;

        // @text register
        // @brief Register notification interface
        // @param sink: notification interface pointer
        // @retval Core::NONE: Indicates successful registration of sink
        virtual Core::hresult Register(ITextToSpeech::INotification* sink) = 0;

        // @text unregister
        // @brief Unregister notification interface
        // @param sink: notification interface pointer
        // @retval Core::NONE: Indicates successful unregistration of sink
        virtual Core::hresult Unregister(ITextToSpeech::INotification* sink) = 0;

        // @text registerWithCallsign
        // @brief Register notification interface with callsign
        // @param sink: notification interface pointer
        // @retval Core::NONE: Indicates successful registration of sink with callsign
        virtual Core::hresult RegisterWithCallsign(const string callsign, ITextToSpeech::INotification* sink) = 0;
        
        // @property
        // @text enable
        // @brief enable/disable tts
        // @param enable: flag to enable/disable tts
        // @retval Core::NONE: Indicates successful state change
        // @retval Core::ERROR_GENERAL: Indicates state change got failed
        virtual Core::hresult Enable(const bool enable) = 0;

        // @text getTTSStatus
        // @brief Query whether TTS enabled or disabled
        // @param enable: tts status
        // @retval Core::NONE: Indicates TTS state retrieved successfully
        virtual Core::hresult GetTTSStatus(bool &enable /* @out */) const = 0;
        
        // @text setConfiguration
        // @brief Set the tts configuration attributes
        // @param config: tts configuration
        // @param status: return status
        // @retval Core::NONE: Indicates successful configuration set
        // @retval Core::ERROR_GENERAL: Indicates configuration set got failed
        virtual Core::hresult SetConfiguration(const Configuration &config, TTSErrorDetail &status/* @out */) = 0;

        // @text setFallbackText
        // @brief Set the tts fallback text
        // @param scenario: scenario for fallback text
        // @param value: fallback text
        // @retval Core::NONE: Indicates successful set of fallback text
        virtual Core::hresult SetFallbackText(const string scenario, const string value) = 0;

        // @text setAPIKey
        // @brief Set the api key for TTS endpoint
        // @param apikey: api key for TTS
        // @retval Core::NONE: Indicates successful set of api key
        virtual Core::hresult SetAPIKey(const string apikey) = 0;

        // @text setPrimaryVolDuck
        // @brief Set the primary volume ducking level
        // @param prim: primary volume ducking level
        // @retval Core::NONE: Indicates successful configuration set of primary vol duck
        // @retval Core::ERROR_GENERAL: Indicates configuration set of primary vol duck got failed
        virtual Core::hresult SetPrimaryVolDuck(const uint8_t prim) = 0;

        // @text setACL
        // @brief Set the access control list for TTS
        // @param method: method name
        // @param apps: applications allowed
        // @retval Core::NONE: Indicates successful update of access control list
        // @retval Core::ERROR_GENERAL: Indicates update of access control list got failed
        virtual Core::hresult SetACL(const string method, const string apps) = 0;

        // @text getConfiguration
        // @brief Retrieve tts configuration attributes 
        // @param config: tts configuration
        // @retval Core::NONE: Indicates successful retrieval of configuration
        // @retval Core::ERROR_GENERAL: Indicates retrieval of configuration got failed
        virtual Core::hresult GetConfiguration(Configuration &config/* @out */) const = 0;
        
        // @text listVoices
        // @brief List voices available 
        // @param language: input
        // @param voices: list of voices
        // @retval Core::NONE: Indicates successful retrieval of voices list
        // @retval Core::ERROR_GENERAL: Indicates retrieval of voices list got failed
        virtual Core::hresult ListVoices(const string language, RPC::IStringIterator*& voices/* @out */) const = 0;
        
        // @text speak
        // @brief Speaks text provided
        // @param text: for conversion
        // @param speechid: returns id for the text 
        // @param status: return status
        // @retval Core::NONE: Indicates successful conversion of text to speech
        // @retval Core::ERROR_GENERAL: Indicates conversion of text to speech got failed
        virtual Core::hresult Speak(const string callsign, const string text, uint32_t &speechid/* @out */,TTSErrorDetail &status/* @out */) = 0;
        
        // @text cancel
        // @brief Cancel the speech
        // @param speechid: id of text to be cancelled
        // @retval Core::NONE: Indicates successful cancellation of speech in progress
        // @retval Core::ERROR_GENERAL: Indicates cancellation of speech got failed
        virtual Core::hresult Cancel(const uint32_t speechid) = 0;
        
        // @text pause
        // @brief Pause the speech
        // @param speechid: id of text to be paused
        // @param status: return status
        // @retval Core::NONE: Indicates successful pause of speech in progress
        // @retval Core::ERROR_GENERAL: Indicates pause of speech got failed
        virtual Core::hresult Pause(const uint32_t speechid, TTSErrorDetail &status /* @out */) = 0;
        
        // @text resume
        // @brief Resume the speech
        // @param speechid: id of text to be resumed
        // @param status: return status
        // @retval Core::NONE: Indicates successful resume of speech in progress
        // @retval Core::ERROR_GENERAL: Indicates resume of speech got failed
        virtual Core::hresult Resume(const uint32_t speechid, TTSErrorDetail &status /* @out */) = 0;
        
        // @text getSpeechState
        // @brief Get speech status
        // @param speechid: id of text to get status
        // @param state: speech state
        // @retval Core::NONE: Indicates successful retrieval of speech state
        // @retval Core::ERROR_GENERAL: Indicates retrieval of speech state got failed
        virtual Core::hresult GetSpeechState(const uint32_t speechid, SpeechState &state/* @out */) = 0;
    };

} // Exchange
} // WPEFramework

#endif //__ITEXTTOSPEECH_H
