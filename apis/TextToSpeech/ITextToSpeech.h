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

#define ITEXTTOSPEECH_VERSION 2

namespace WPEFramework {
namespace Exchange {

struct EXTERNAL ITextToSpeech : virtual public Core::IUnknown {
    enum { ID = ID_TEXT_TO_SPEECH };

    // @deprecated: Use DeviceConfiguration struct instead
    struct Configuration {
        std::string ttsEndPoint;
        std::string ttsEndPointSecured;
        std::string language;
        std::string voice;
        std::string speechRate;
        uint8_t volume;
        uint8_t rate;
    };

    struct DeviceConfiguration {
        std::string ttsEndPoint;
        std::string ttsEndPointSecured;
        // @brief Device default language of the utterance, BCP 47 language tag
        std::string language;
        // @brief Device default voice to use for synthesis; empty string means, use TTS Engine default for the configured language
        // @default ""
        std::string voice;
        // @brief Device default volume of the utterance, range 0.0 to 1.0
        // @default 1.0
        double volume;
        // @brief Device default speed of the utterance, range 0.1 to 10.0
        // @default 1.0
        double rate;
        // @brief Device default pitch of the utterance, range 0.0 to 2.0
        // @default 1.0
        double pitch;
    };

    // Struct enabling to override global TTS configuration for a specific text to be spoken
    // Added in version 2
    struct SpeechContext {
        // @brief Language of the utterance, BCP 47 language tag; empty string means, use TTS configuration value
        // @default ""
        std::string language;
        // @brief Voice to use for synthesis; empty string means, use TTS configuration value
        // @default ""
        std::string voice;
        // @brief Volume of the utterance, range 0.0 to 1.0; -1.0 means, use TTS configuration value
        // @default -1.0
        double volume;
        // @brief Speed of the utterance, range 0.1 to 10.0; -1.0 means, use TTS configuration value
        // @default -1.0
        double rate;
        // @brief Pitch of the utterance, range 0.0 to 2.0; -1.0 means, use TTS configuration value
        // @default -1.0
        double pitch;
    };

    // Struct containing voice information, used in the getVoices
    // Added in version 2
    struct VoiceInfo {
        // @brief Unique voice identifier, used as the voice field in SpeechContext or DeviceConfiguration to select this voice
        std::string name;
        // @brief BCP 47 language tag of the voice
        std::string language;
        // @brief True if this is the default voice for its language
        bool isDefault;
    };
    using IVoiceInfoIterator = RPC::IIteratorType<VoiceInfo, ID_VOICE_INFO_ITERATOR>;

    // Capability enum allowing clients to query the TTS capability of the implementation
    // Added in version 2
    enum Capability : uint32_t {
        UNSET = 0,  //< Filler value; will never be used as a capability
        RAW_TEXT = 1,   // The currently configured TTS Engine supports raw text input
        SSML = 2,   // The currently configured TTS Engine supports SSML input
    };

    using ICapabilityIterator = RPC::IIteratorType<Capability, RPC::ID_VALUEITERATOR>;

    enum SpeechState : uint8_t {
        SPEECH_PENDING = 0,
        SPEECH_IN_PROGRESS,
        SPEECH_PAUSED,
        SPEECH_NOT_FOUND
    };

    enum TTSErrorDetail : uint8_t {
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
        // @text onTTSStateChanged
        // @alt onttsstatechanged
        // @brief Notify TTS enabled/disabled
        // @param state: enabled/disabled
        virtual void OnTTSStateChanged(const bool /*state*/) {}

        // @text onVoiceChanged
        // @alt onvoicechanged
        // @brief Notify change in voice used for speaking
        // @param voice: voice changed
        virtual void OnVoiceChanged(const string /*voice*/) {}

        // @text onSpeechReady
        // @alt onWillSpeak
        // @brief Notify that speech is possible
        // @param speechid: id of the text
        virtual void OnSpeechReady(const uint32_t /*speechid*/) {}

        // @text onSpeechStarted
        // @alt onspeechstart
        // @brief Notify that speech is started
        // @param speechid: id of the text
        virtual void OnSpeechStarted(const uint32_t /*speechid*/) {}

        // @text onSpeechPaused
        // @alt onspeechpause
        // @brief Notify that speech is paused
        // @param speechid: id of the text
        virtual void OnSpeechPaused(const uint32_t /*speechid*/) {}

        // @text onSpeechResumed
        // @alt onspeechresume
        // @brief Notify that speech is continued
        // @param speechid: id of the text
        virtual void OnSpeechResumed(const uint32_t /*speechid*/) {}

        // @text onSpeechInterrupted
        // @alt onspeechinterrupted
        // @brief Notify that speech is interrupted
        // @param speechid: id of the text
        virtual void OnSpeechInterrupted(const uint32_t /*speechid*/) {}

        // @text onNetworkError
        // @alt onnetworkerror
        // @brief Notify that network connection is lost
        // @param speechid: id of the text
        virtual void OnNetworkError(const uint32_t /*speechid*/) {}

        // @text onPlaybackError
        // @alt onplaybackerror
        // @brief Notify that there is a playback failure
        // @param speechid: id of the text
        virtual void OnPlaybackError(const uint32_t /*speechid*/) {}

        // @text onSpeechComplete
        // @alt onspeechcomplete
        // @brief Notify that speech is completed
        // @param speechid: id of the text
        virtual void OnSpeechComplete(const uint32_t /*speechid*/) {}

        /**
         * @brief Notify change in if the available voices changes. (Added in version 2)
         * @details E.g due to a change in TTS configuration or a change in the system such as a language pack installation or TTS engine update.
         * @text onVoicesChanged
         */
        virtual void OnVoicesChanged() {}

        /**
         * @brief Notify change in if the available capabilities changes. (Added in version 2)
         * @details E.g due to a change in TTS configuration.
         * @text onCapabilitiesChanged
         */
        virtual void OnCapabilitiesChanged() {}

        /**
         * @brief Notify change in device configuration. (Added in version 2)
         * @details E.g due to a change in TTS configuration.
         * @param config updated device configuration
         * @text onDeviceConfigurationChanged
         */
        virtual void OnDeviceConfigurationChanged(const DeviceConfiguration& config) {}
    };

    ~ITextToSpeech() override = default;

    /* @json:omit */
    // @text register
    // @brief Register notification interface
    // @param sink: notification interface pointer
    // @retval Core::NONE: Indicates successful registration of sink
    virtual Core::hresult Register(ITextToSpeech::INotification* sink) = 0;

    /* @json:omit */
    // @text unregister
    // @brief Unregister notification interface
    // @param sink: notification interface pointer
    // @retval Core::NONE: Indicates successful unregistration of sink
    virtual Core::hresult Unregister(ITextToSpeech::INotification* sink) = 0;

    /* @json:omit */
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

    // @text Enable
    // @brief Query whether TTS enabled or disabled
    // @param enable: tts status
    // @retval Core::NONE: Indicates TTS state retrieved successfully
    virtual Core::hresult Enable(bool& enable /* @out */) const = 0;

    // @text setConfiguration
    // @brief Set the tts configuration attributes
    // @param config: tts configuration
    // @param status: return status
    // @retval Core::NONE: Indicates successful configuration set
    // @retval Core::ERROR_GENERAL: Indicates configuration set got failed
    // @deprecated
    virtual Core::hresult SetConfiguration(const Configuration& config, TTSErrorDetail& status /* @out */) = 0;

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
    // @deprecated
    virtual Core::hresult GetConfiguration(Configuration& config /* @out */) const = 0;

    // @text listVoices
    // @brief List voices available
    // @param language: input
    // @param voices: list of voices
    // @retval Core::NONE: Indicates successful retrieval of voices list
    // @retval Core::ERROR_GENERAL: Indicates retrieval of voices list got failed
    // @deprecated
    virtual Core::hresult ListVoices(const string language, RPC::IStringIterator*& voices /* @out */) const = 0;

    // @text speak
    // @brief Speaks text provided
    // @param callsign: identifier for the source of the request
    // @param text: for conversion
    // @param speechid: returns id for the text
    // @param status: return status
    // @retval Core::NONE: Indicates successful conversion of text to speech
    // @retval Core::ERROR_GENERAL: Indicates conversion of text to speech got failed
    virtual Core::hresult Speak(const string callsign, const string text, uint32_t& speechid /* @out */, TTSErrorDetail& status /* @out */) = 0;

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
    virtual Core::hresult Pause(const uint32_t speechid, TTSErrorDetail& status /* @out */) = 0;

    // @text resume
    // @brief Resume the speech
    // @param speechid: id of text to be resumed
    // @param status: return status
    // @retval Core::NONE: Indicates successful resume of speech in progress
    // @retval Core::ERROR_GENERAL: Indicates resume of speech got failed
    virtual Core::hresult Resume(const uint32_t speechid, TTSErrorDetail& status /* @out */) = 0;

    // @text getSpeechState
    // @brief Get speech status
    // @param speechid: id of text to get status
    // @param state: speech state
    // @retval Core::NONE: Indicates successful retrieval of speech state
    // @retval Core::ERROR_GENERAL: Indicates retrieval of speech state got failed
    virtual Core::hresult GetSpeechState(const uint32_t speechid, SpeechState& state /* @out */) = 0;

    /**
     * @brief List voices available - replacing the listVoices method (Added in version 2)
     * @details It provides more information about the voices such as language and default status, which is necessary for clients to make informed decisions about voice selection
     * @param language optional is empty string, if provided filters the voices by the language specified using BCP 47 language tag
     * @param voices list of voices
     * @retval Core::NONE Indicates successful retrieval of voices list
     * @retval Core::ERROR_GENERAL Indicates retrieval of voices list got failed
     * @retval Core::ERROR_NOT_SUPPORTED Indicates conversion of text to speech is not supported in this implementation
     * @text getVoices
     */
    virtual Core::hresult GetVoices(const string language, IVoiceInfoIterator*& voices /* @out */) const {
        return Core::ERROR_NOT_SUPPORTED;
    };

    /**
     * @brief Speaks text provided with overridecontext (Added in version 2)
     * @details Allows to override the global configuration for settings such as language, voice, volume, rate, pitch.
     * @param callsign identifier for the source of the request
     * @param context override context for the speech such as language, voice, volume, rate, pitch
     * @param text plain text or SSML markup for conversion; if the string starts with "<speak>" or "<?xml" it is treated as SSML, otherwise as plain text
     * If the SSML capability is not supported, the SSML tags will be ignored and the text will be treated as plain text.
     * @param speechid returns id for the text
     * @param status return status
     * @retval Core::NONE Indicates successful conversion of text to speech
     * @retval Core::ERROR_GENERAL Indicates conversion of text to speech got failed
     * @retval Core::ERROR_NOT_SUPPORTED Indicates conversion of text to speech is not supported in this implementation
     * @text speakWithContext
     */
    virtual Core::hresult SpeakWithContext(const string callsign, const SpeechContext& context, const string text, uint32_t& speechid /* @out */, TTSErrorDetail& status /* @out */) {
        return Core::ERROR_NOT_SUPPORTED;
    };

    /**
     * @brief Return the interface version implemented (Added in version 2)
     * @details This allows to query the running plugin for the version of the interface
     * it was compiled to support. This information can be helpful in determining whether
     * a certain functionality can be expected to be present.
     * @param version will receive the version number ex: 2
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented - If not implemented assume version 1
     * @retval Core::ERROR_OK on success
     * @text getInterfaceVersion
     */
    virtual Core::hresult GetInterfaceVersion(uint32_t& version /* @out */) const {
        return Core::ERROR_NOT_SUPPORTED;
    }

    /**
     * @brief Queries whether a specific TextToSpeech capability is supported by the implementation. (Added in version 2)
     * @param capability The capability to query ex: SSML, RAW_TEXT
     * @param hasCapability Indicates whether the queried capability is supported.
     * @retval Core::ERROR_NONE The capability query completed successfully.
     * @retval Core::ERROR_NOT_SUPPORTED Capability querying is not supported.
     * @text getCapability
     */
    virtual Core::hresult GetCapability(Capability capability, bool& hasCapability /* @out */) const {
        return Core::ERROR_NOT_SUPPORTED;
    }

    /**
     * @brief Retrieves an iterator over all supported TextToSpeech capabilities. (Added in version 2)
     * @param capabilities Iterator providing the list of supported capabilities.
     * @retval Core::ERROR_NONE The list of capabilities was retrieved successfully.
     * @retval Core::ERROR_NOT_SUPPORTED Retrieving capabilities is not supported.
     * @text getCapabilities
     */
    virtual Core::hresult GetCapabilities(ICapabilityIterator*& capabilities /* @out */) const {
        return Core::ERROR_NOT_SUPPORTED;
    }

    /**
     * @brief Retrieve tts configuration attributes
     * @param config tts device configuration
     * @retval Core::NONE Indicates successful retrieval of configuration
     * @retval Core::ERROR_GENERAL Indicates retrieval of configuration got failed
     * @retval Core::ERROR_NOT_SUPPORTED Indicates retrieval of configuration is not supported in this implementation
     * @text getDeviceConfiguration
     */
    virtual Core::hresult GetDeviceConfiguration(DeviceConfiguration& config /* @out */) const {
        return Core::ERROR_NOT_SUPPORTED;
    }

    /**
     * @brief Set tts configuration attributes
     * @param config tts deviceconfiguration
     * @retval Core::NONE Indicates successful setting of configuration
     * @retval Core::ERROR_GENERAL Indicates setting of configuration got failed
     * @retval Core::ERROR_NOT_SUPPORTED Indicates setting of configuration is not supported in this implementation
     * @text setDeviceConfiguration
     */
    virtual Core::hresult SetDeviceConfiguration(const DeviceConfiguration& config) {
        return Core::ERROR_NOT_SUPPORTED;
    }
};

}  // namespace Exchange
}  // namespace WPEFramework

#endif  //__ITEXTTOSPEECH_H
