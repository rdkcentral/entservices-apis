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
            // @brief Notify TTS enabled/disabled
            // @param state enabled/disabled
            virtual void onSpeechEnabled(const bool /*state*/) {}

            // @brief Notify change in voice used for speaking
            // @param voice voice changed 
            virtual void onToneChanged(const string /*voice*/) {}

            // @brief Notify speechid based on the speech state(eg: start,pause,..etc)
            // @param speechid id of the text
            virtual void onSpeechPossible(const uint32_t /*speechid*/) {}
            virtual void onSpeechBegin(const uint32_t /*speechid*/) {}
            virtual void onSpeechBreak(const uint32_t /*speechid*/) {}
            virtual void onSpeechContinue(const uint32_t /*speechid*/) {}
            virtual void onSpeechDisrupt(const uint32_t /*speechid*/) {}
            virtual void onConnectionLost(const uint32_t /*speechid*/) {}
            virtual void onAudioIssue(const uint32_t /*speechid*/) {}
            virtual void onSpeechDone(const uint32_t /*speechid*/) {}
        };

        ~ITextToSpeech() override = default;

        // @text Register
        // @brief Register notification interface
        // @param sink: notification interface pointer
        // @retval ErrorCode::NONE: Indicates successful registration of sink
        virtual Core::hresult Register(ITextToSpeech::INotification* sink) = 0;

        // @text Unregister
        // @brief Unregister notification interface
        // @param sink: notification interface pointer
        // @retval ErrorCode::NONE: Indicates successful unregistration of sink
        virtual Core::hresult Unregister(ITextToSpeech::INotification* sink) = 0;

        // @text RegisterWithCallsign
        // @brief Register notification interface with callsign
        // @param sink: notification interface pointer
        // @retval ErrorCode::NONE: Indicates successful registration of sink with callsign
        virtual Core::hresult RegisterWithCallsign(const string callsign,ITextToSpeech::INotification* sink) = 0;
        
        // @property
        // @text Enable
        // @brief enable/disable tts
        // @param enable: flag to enable/disable tts
        // @retval ErrorCode::NONE: Indicates successful state change
        // @retval ErrorCode::ERROR_GENERAL: Indicates state change got failed
        virtual Core::hresult Enable(const bool enable) = 0;

        // @text IsTTSActive
        // @brief Query whether TTS enabled or disabled
        // @param enable: tts status
        // @retval ErrorCode::NONE: Indicates TTS state retrieved successfully
        virtual Core::hresult IsTTSActive(bool &enable /* @out */) const = 0;
        
        // @text SetConfiguration
        // @brief Set the tts configuration attributes
        // @param config: tts configuration
        // @param status: return status
        // @retval ErrorCode::NONE: Indicates successful configuration set
        // @retval ErrorCode::ERROR_GENERAL: Indicates configuration set got failed
        virtual Core::hresult SetConfiguration(const Configuration &config,TTSErrorDetail &status/* @out */) = 0;

        // @text SetFallbackText
        // @brief Set the tts fallback text
        // @param scenario: scenario for fallback text
        // @param value: fallback text
        // @retval ErrorCode::NONE: Indicates successful set of fallback text
        virtual Core::hresult SetFallbackText(const string scenario,const string value) = 0;

        // @text SetAPIKey
        // @brief Set the api key for TTS endpoint
        // @param apikey: api key for TTS
        // @retval ErrorCode::NONE: Indicates successful set of api key
        virtual Core::hresult SetAPIKey(const string apikey) = 0;

        // @text SetPrimaryVolDuck
        // @brief Set the primary volume ducking level
        // @param prim: primary volume ducking level
        // @retval ErrorCode::NONE: Indicates successful configuration set of primary vol duck
        // @retval ErrorCode::ERROR_GENERAL: Indicates configuration set of primary vol duck got failed
        virtual Core::hresult SetPrimaryVolDuck(const uint8_t prim) = 0;

        // @text SetACL
        // @brief Set the access control list for TTS
        // @param method: method name
        // @param apps: applications allowed
        // @retval ErrorCode::NONE: Indicates successful update of access control list
        // @retval ErrorCode::ERROR_GENERAL: Indicates update of access control list got failed
        virtual Core::hresult SetACL(const string method,const string apps) = 0;

        // @text GetConfiguration
        // @brief Retrieve tts configuration attributes 
        // @param config: tts configuration
        // @retval ErrorCode::NONE: Indicates successful retrieval of configuration
        // @retval ErrorCode::ERROR_GENERAL: Indicates retrieval of configuration got failed
        virtual Core::hresult GetConfiguration(Configuration &config/* @out */) const = 0;
        
        // @text ListVoices
        // @brief List voices available 
        // @param language: input
        // @param voices: list of voices
        // @retval ErrorCode::NONE: Indicates successful retrieval of voices list
        // @retval ErrorCode::ERROR_GENERAL: Indicates retrieval of voices list got failed
        virtual Core::hresult ListVoices(const string language,RPC::IStringIterator*& voices/* @out */) const = 0;
        
        // @text Speak
        // @brief Speaks text provided
        // @param text: for conversion
        // @param speechid: returns id for the text 
        // @param status: return status
        // @retval ErrorCode::NONE: Indicates successful conversion of text to speech
        // @retval ErrorCode::ERROR_GENERAL: Indicates conversion of text to speech got failed
        virtual Core::hresult Speak(const string callsign,const string text,uint32_t &speechid/* @out */,TTSErrorDetail &status/* @out */) = 0;
        
        // @text Cancel
        // @brief Cancel the speech
        // @param speechid: id of text to be cancelled
        // @retval ErrorCode::NONE: Indicates successful cancellation of speech in progress
        // @retval ErrorCode::ERROR_GENERAL: Indicates cancellation of speech got failed
        virtual Core::hresult Cancel(const uint32_t speechid) = 0;
        
        // @text Pause
        // @brief Pause the speech
        // @param speechid: id of text to be paused
        // @param status: return status
        // @retval ErrorCode::NONE: Indicates successful pause of speech in progress
        // @retval ErrorCode::ERROR_GENERAL: Indicates pause of speech got failed
        virtual Core::hresult Pause(const uint32_t speechid,TTSErrorDetail &status /* @out */) = 0;
        
        // @text Resume
        // @brief Resume the speech
        // @param speechid: id of text to be resumed
        // @param status: return status
        // @retval ErrorCode::NONE: Indicates successful resume of speech in progress
        // @retval ErrorCode::ERROR_GENERAL: Indicates resume of speech got failed
        virtual Core::hresult Resume(const uint32_t speechid,TTSErrorDetail &status /* @out */) = 0;
        
        // @text GetSpeechState
        // @brief Get speech status
        // @param speechid: id of text to get status
        // @param state: speech state
        // @retval ErrorCode::NONE: Indicates successful retrieval of speech state
        // @retval ErrorCode::ERROR_GENERAL: Indicates retrieval of speech state got failed
        virtual Core::hresult GetSpeechState(const uint32_t speechid,SpeechState &state/* @out */) = 0;
    };

} // Exchange
} // WPEFramework

#endif //__ITEXTTOSPEECH_H
