/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 Synamedia Ltd.
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

namespace WPEFramework
{
    namespace Exchange
    {
        // @json @text:keep
        struct EXTERNAL IDeviceSettingsAudio : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_AUDIO };

        enum AudioPortType : uint8_t {
            AUDIO_PORT_TYPE_UNKNOWN         = 0,
            AUDIO_PORT_TYPE_LR              = 1,
            AUDIO_PORT_TYPE_HDMI            = 2,
            AUDIO_PORT_TYPE_SPDIF           = 3,
            AUDIO_PORT_TYPE_SPEAKER         = 4,
            AUDIO_PORT_TYPE_HDMIARC         = 5,
            AUDIO_PORT_TYPE_HEADPHONE       = 6
        };

        enum AudioPortState : uint8_t {
            AUDIO_PORT_STATE_UNKNOWN         = 0,
            AUDIO_PORT_STATE_UNINITIALIZED   = 1,
            AUDIO_PORT_STATE_INITIALIZED     = 2
        };

        enum AudioEncoding : uint8_t {
            AUDIO_ENCODING_UNKNOWN         = 0,
            AUDIO_ENCODING_NONE            = 1,
            AUDIO_ENCODING_DISPLAY         = 2,
            AUDIO_ENCODING_PCM             = 3,
            AUDIO_ENCODING_AC3             = 4,
            AUDIO_ENCODING_EAC3            = 5
        };

        enum AudioCompression : uint8_t {
            AUDIO_COMPRESSION_UNKNOWN       = 0,
            AUDIO_COMPRESSION_NONE          = 1,
            AUDIO_COMPRESSION_LIGHT         = 2,
            AUDIO_COMPRESSION_MEDIUM        = 3,
            AUDIO_COMPRESSION_HEAVY         = 4
        };

        enum AudioFormat : uint8_t {
            AUDIO_FORMAT_UNKNOWN            = 0,
            AUDIO_FORMAT_NONE               = 1,
            AUDIO_FORMAT_PCM                = 2,
            AUDIO_FORMAT_DOLBY_AC3          = 3,
            AUDIO_FORMAT_DOLBY_EAC3         = 4,
            AUDIO_FORMAT_DOLBY_AC4          = 5,
            AUDIO_FORMAT_DOLBY_MAT          = 6,
            AUDIO_FORMAT_DOLBY_TRUEHD       = 7,
            AUDIO_FORMAT_DOLBY_EAC3_ATMOS   = 8,
            AUDIO_FORMAT_DOLBY_TRUEHD_ATMOS = 9,
            AUDIO_FORMAT_DOLBY_MAT_ATMOS    = 10,
            AUDIO_FORMAT_DOLBY_AC4_ATMOS    = 11,
            AUDIO_FORMAT_AAC                = 12,
            AUDIO_FORMAT_VORBIS             = 13,
            AUDIO_FORMAT_WMA                = 14
        };

        enum AudioDuckingAction : uint8_t {
            AUDIO_DUCKINGACTION_UNKNOWN       = 0,
            AUDIO_DUCKINGACTION_START         = 1,
            AUDIO_DUCKINGACTION_STOP          = 2
        };

        enum AudioDuckingType : uint8_t {
            AUDIO_DUCKINGTYPE_UNKNOWN        = 0,
            AUDIO_DUCKINGTYPE_ABSOLUTE       = 1,
            AUDIO_DUCKINGTYPE_RELATIVE       = 2
        };

        enum AudioCapabilities : uint32_t {
            AUDIO_CAPS_UNKNOWN                   = 0,
            AUDIO_CAPS_ATMOS                     = 1,
            AUDIO_CAPS_DOLBY_DIGITAL             = 2,
            AUDIO_CAPS_DOLBY_DIGITAL_PLUS        = 4,
            AUDIO_CAPS_DIGITAL_AUDIO_DELIVERY    = 8,
            AUDIO_CAPS_DIGITAL_AUDIO_PROCESS_V2  = 16,
            AUDIO_CAPS_MS12                      = 32,
            AUDIO_CAPS_MS12_V2                   = 64
        };

        enum AudioARCType : uint8_t {
            AUDIO_ARCTYPE_UNKNOWN                 = 0,
            AUDIO_ARCTYPE_ARC                     = 1,
            AUDIO_ARCTYPE_EARC                    = 2
        };

        enum AudioInput : uint8_t {
            AUDIO_INPUT_UNKNOWN                   = 0,
            AUDIO_INPUT_PRIMARY                   = 1,
            AUDIO_INPUT_SYSTEM                    = 2
        };

        struct AudioARCStatus {
            AudioARCType    type;               
            bool status;                        
        };
        // TODO AudioSADList 

        enum MS12Capabilities : uint8_t {
            AUDIO_MS12_CAPABILITIES_UNKNOWN                 = 0,
            AUDIO_MS12_CAPABILITIES_NONE                    = 1,
            AUDIO_MS12_CAPABILITIES_DOLBYVOLUME             = 2,
            AUDIO_MS12_CAPABILITIES_INTELLIGENT_EQUALIZER   = 4,
            AUDIO_MS12_CAPABILITIES_DIALOG_ENHANCER         = 8
        };

        // TODO MS12 Audio Profile list
        struct MS12AudioProfile {
            string audioProfile;                 
        };

        using IDeviceSettingsAudioMS12AudioProfileIterator = RPC::IIteratorType<MS12AudioProfile, ID_DEVICE_SETTINGS_AUDIO_PROFILE_ITERATOR>;

        struct VolumeLeveller {
            uint8_t mode;       /* @text 0 = off, 1 = on, 2 = auto  */
            uint8_t level;      /* @text Value of volume leveller. 0 -10 */
        };

        struct SurroundVirtualizer {
            uint8_t mode;       /* @text 0 = off, 1 = on, 2 = auto  */
            uint8_t boost;      /* @text Value of boost level. 0 -96 */
        };

        enum StereoMode : uint8_t {
            AUDIO_STEREO_UNKNOWN                 = 0,
            AUDIO_STEREO_MONO                    = 1,
            AUDIO_STEREO_STEREO                  = 2,
            AUDIO_STEREO_SURROUND                = 3,
            AUDIO_STEREO_PASSTHROUGH             = 4,
            AUDIO_STEREO_DD                      = 5,
            AUDIO_STEREO_DDPLUS                  = 6
        };

        enum DolbyAtmosCapability: uint8_t {
            AUDIO_DOLBYATMOS_UNKNOWN           = 0,
            AUDIO_DOLBYATMOS_DDPLUS_STREAM     = 1,
            AUDIO_DOLBYATMOS_ATMOS_METADATA    = 2
        };

        enum SurroundMode: uint8_t {
            AUDIO_SURROUND_MODE_UNKNOWN           = 0,
            AUDIO_SURROUND_MODE_NONE              = 1,
            AUDIO_SURROUND_MODE_DD                = 2,
            AUDIO_SURROUND_MODE_DDPLUS            = 3
        };

        enum MS12Feature: uint8_t {
            AUDIO_MS12_FEATURE_UNKNOWN         = 0,
            AUDIO_MS12_FEATURE_DAPV2           = 1,
            AUDIO_MS12_FEATURE_DE              = 2
        };

        // TODO AudioConfig type from dsAVDTypes.h - vdixit
        struct AudioSADItem { 
            int  sad    /* @brief SAD value */ ;
        };
        using IDSAudioSADIterator = RPC::IIteratorType<AudioSADItem, ID_DSAUDIO_SAD_ITERATOR>;

        struct AudioARCStatus { 
            AudioARCType  arcType    /* @brief ARC Type */ ;
            bool          status     /* @brief ARC status */;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_AUDIO_NOTIFICATION };

            // @brief Associated Audio mixing changed
            // @text onAssociatedAudioMixingChanged
            // @param mixing: true or false
            virtual void OnAssociatedAudioMixingChanged(const bool mixing) = 0;

            // @brief Audio Fader balance changed
            // @text onAudioFaderControlChanged
            // @param mixerBalance: applied mixer balance value
            virtual void OnAudioFaderControlChanged(const int mixerBalance) = 0;

            // @brief Primary language for Audio changed
            // @text onAudioPrimaryLanguageChanged
            // @param primaryLanguage: current primary language for audio
            virtual void OnAudioPrimaryLanguageChanged(const string primaryLanguage) = 0;

            // @brief Secondary language for Audio changed
            // @text onAudioSecondaryLanguageChanged
            // @param secondaryLanguage: current secondary language for audio
            virtual void OnAudioSecondaryLanguageChanged(const string secondaryLanguage) = 0;

            // @brief Audio output hot plug event
            // @text onAudioOutHotPlug
            // @param portType: Type of audio port see AudioPortType
            // @param uiPortNumber: The port number assigned by UI
            // @param isPortConnected: true (connected) or false (not connected)
            virtual void OnAudioOutHotPlug(const AudioPortType portType, const int uiPortNumber, const bool isPortConnected) = 0;

            // @brief Audio Output format changed
            // @text onAudioFormatUpdate
            // @param audioFormat: Type of audio format see AudioFormat
            virtual void OnAudioFormatUpdate(const AudioFormat audioFormat) = 0;

            // @brief Dolby Atmos capabilities changed
            // @text onDolbyAtmosCapabilitiesChanged
            // @param atmosCapability: the dolby atmos capability 
            // @param status: true (available) or false (not available)
            virtual void OnDolbyAtmosCapabilitiesChanged(const DolbyAtmosCapability atmosCapability, const bool status) = 0;

            // @brief Audio port state changed
            // @text onAudioPortStateChanged
            // @param audioPortState: audio port state
            virtual void OnAudioPortStateChanged(const AudioPortState audioPortState) = 0;

            // @brief Audio mode for the respective audio port - raised for every type of port
            // @text onAudioModeEvent
            // @param audioPortType: audio port type see AudioPortType
            // @param audioMode: audio mode - see StereoMode
            virtual void OnAudioModeEvent(const AudioPortType audioPortType, const StereoMode audioMode) = 0;
             
            // @brief Audio mode for the respective audio port - raised for every type of port
            // @text onAudioModeEvent
            // @param audioPortType: audio port type see AudioPortType
            // @param audioMode: audio mode - see StereoMode
            virtual void OnAudioLevelChangedEvent(const int audioLevel) = 0;
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsAudio::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsAudio::INotification* notification /* @in */) = 0;

        /** Get Audio Port . */
        // @text getAudioPort
        // @brief Get Audio Port handle for the port type and index
        // @param type: Type of Audio port - see AudioPortType
        // @param index: index of the audio port within the list of audio port types
        // @param handle: handle to the port
        virtual Core::hresult GetAudioPort(const AudioPortType type /* @in */, const int index /* @in */,int &handle /* @out */) = 0;

        /** Terminate Audio Port . */
        // @text audioPortTerm
        // @brief Terminate the Audio Port for the port type and index
        // @param type: Type of Audio port - see AudioPortType
        // @param index: index of the audio port within the list of audio port types
        // @param handle: handle to the port
        virtual Core::hresult AudioPortTerm(const AudioPortType type /* @in */, const int index /* @in */,int handle /* @in */) = 0;

        /** Audio Port status. */
        // @text isAudioPortEnabled
        // @brief Audio port status
        // @param type: Type of Audio port - see AudioPortType
        // @param index: index of the audio port within the list of audio port types
        // @param handle: handle to the port
        virtual Core::hresult IsAudioPortEnabled(const AudioPortType type /* @in */, const int index /* @in */,int &handle /* @out */) = 0;

        /** Enable Audio Port. */
        // @text enableAudioPort
        // @brief Audio port status
        // @param type: Type of Audio port - see AudioPortType
        // @param index: index of the audio port within the list of audio port types
        // @param handle: handle to the port
        virtual Core::hresult EnableAudioPort(const AudioPortType type /* @in */, const int index /* @in */,int &handle /* @out */) = 0;

        /** Get Supported ARC types . */
        // @text getSupportedARCTypes
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult GetSupportedARCTypes(const int handle /* @in */, int &types /* @out */) = 0;

        /** Set SAD */
        // @text setSAD
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param count: number of items in sadList (max 15)
        // @param sadList: SAD array 
        virtual Core::hresult SetSAD(const int handle /* @in */, int count /* @in */, int sadList[] /* @in */) = 0;

        /** Enable ARC */
        // @text enableARC
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param arcStatus: ARC param
        virtual Core::hresult EnableARC(const int handle /* @in */, AudioARCStatus arcStatus /* @in */) = 0;

        /** Get Stereo Mode  . */
        // @text getStereoMode
        // @brief Get Stereo Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult GetStereoMode(const int handle /* @in */, StereoMode &mode /* @out */) = 0;

        /** Set Stereo Mode  . */
        // @text setStereoMode
        // @brief Set Stereo Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        // @param persist: persist the mode
        virtual Core::hresult SetStereoMode(const int handle /* @in */, StereoMode mode /* @in */ ,bool persist /* @in */) = 0;

        /** Get Stereo Auto  . */
        // @text getStereoAuto
        // @brief Get Stereo Auto
        // @param handle: handle returned in GetAudioPort()
        // @param mode: auto mode
        virtual Core::hresult GetStereoAuto(const int handle /* @in */, int &mode /* @out */) = 0;

        /** Set Stereo Auto  . */
        // @text setStereoAuto
        // @brief Set Stereo Auto
        // @param handle: handle returned in GetAudioPort()
        // @param mode: auto mode
        // @param persist: persist the setting
        virtual Core::hresult SetStereoAuto(const int handle /* @in */, int mode /* @in */, bool persist /* @in */) = 0;

        /** Set Audio Mute . */
        // @text setAudioMute
        // @brief Set Audio mute
        // @param handle: handle returned in GetAudioPort()
        // @param mute: Mute (true) or Unmute (false)
        virtual Core::hresult SetAudioMute(const int handle /* @in */, bool mute /* @in */) = 0;

        /** Audio Mute Status. */
        // @text isAudioMuted
        // @brief Audio mute status
        // @param handle: handle returned in GetAudioPort()
        // @param muted: Muted (true) or not (false)
        virtual Core::hresult IsAudioMuted(const int handle /* @in */, bool &muted /* @out */) = 0;

        /** Set Audio ducking */
        // @text setAudioDucking
        // @brief Set Audio ducking
        // @param handle: handle returned in GetAudioPort()
        // @param duckingType: Audio ducking type
        // @param duckingAction: Audio ducking action
        // @param level : Volume level when audio is ducked. 
        virtual Core::hresult SetAudioDucking(const int handle /* @in */, AudioDuckingType duckingType /* @in */, AudioDuckingAction duckingAction /* @in */, uint8_t level /* @in */) = 0;

        /** Set Audio Level */
        // @text setAudioLevel
        // @brief Set Audio Level
        // @param handle: handle returned in GetAudioPort()
        // @param audioLevel: Audio level
        virtual Core::hresult SetAudioLevel(const int handle /* @in */, float audioLevel /* @in */) = 0;

        /** Get Audio Level */
        // @text GetAudioDucking
        // @brief Get Audio Level
        // @param handle: handle returned in GetAudioPort()
        // @param audioLevel: Audio level
        virtual Core::hresult GetAudioLevel(const int handle /* @in */, float &audioLevel /* @out */) = 0;

        /** Set Audio Gain */
        // @text setAudioGain
        // @brief Set Audio Gain
        // @param handle: handle returned in GetAudioPort()
        // @param gainLevel: Gain level
        virtual Core::hresult SetAudioGain(const int handle /* @in */, float gainLevel /* @in */) = 0;

        /** Get Audio Gain */
        // @text setAudioGain
        // @brief Get Audio Gain
        // @param handle: handle returned in GetAudioPort()
        // @param gainLevel: Gain level
        virtual Core::hresult GetAudioGain(const int handle /* @in */, float &gainLevel /* @out */) = 0;

        /** Get Audio Format */
        // @text getAudioFormat
        // @brief Get Audio Format
        // @param handle: handle returned in GetAudioPort()
        // @param audioFormat: Audio format
        virtual Core::hresult GetAudioFormat(const int handle /* @in */, AudioFormat &audioFormat /* @out */) = 0;

        /** Get Audio encoding */
        // @text getAudioEncoding
        // @brief Get Audio encoding
        // @param handle: handle returned in GetAudioPort()
        // @param encoding: Audio encoding
        virtual Core::hresult GetAudioEncoding(const int handle /* @in */, AudioEncoding &encoding /* @out */) = 0;

        /** Get Audio Persistence status . */
        // @text getAudioEnablePersist
        // @brief Get Persistence status
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: Is persistence enabled or not
        // @param portName: portName for which persistence is enabled
        virtual Core::hresult GetAudioEnablePersist(const int handle /* @in */, bool &enabled /* @out */, string &portName /* @out */) = 0;

        /** Set Audio Persistence status . */
        // @text SetAudioEnablePersist
        // @brief Set Persistence status
        // @param handle: handle returned in GetAudioPort()
        // @param enable :  persistence enable (true) or disable (false)
        // @param portName: portName for which persistence is enabled
        virtual Core::hresult SetAudioEnablePersist(const int handle /* @in */, bool enable /* @in */, string &portName /* @in */) = 0;

        /** Audio MS decode Status. */
        // @text isAudioMSDecoded
        // @brief Audio MS decode status
        // @param handle: handle returned in GetAudioPort()
        // @param hasms11Decode: true or false
        virtual Core::hresult IsAudioMSDecoded(const int handle /* @in */, bool &hasms11Decode /* @out */) = 0;

        /** Audio MS12 decode Status. */
        // @text isAudioMS12Decoded
        // @brief Audio MS12 decode status
        // @param handle: handle returned in GetAudioPort()
        // @param hasms12Decode: true or false
        virtual Core::hresult IsAudioMS12Decoded(const int handle /* @in */, int &hasms12Decode /* @out */) = 0;

        /** Get Audio LE config */
        // @text getAudioLEConfig
        // @brief Get Audio LE config
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled) or false (disabled)
        virtual Core::hresult GetAudioLEConfig(const int handle /* @in */, bool &enabled /* @out */) = 0;

        /** Enable Audio LE config */
        // @text enableAudioLEConfig
        // @brief Audio LE config Enable
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled) or false (disabled)
        virtual Core::hresult EnableAudioLEConfig(const int handle /* @in */, bool enable /* @in */) = 0;

        /** Set Audio Delay  */
        // @text setAudioDelay
        // @brief Set Audio Delay
        // @param handle: handle returned in GetAudioPort()
        // @param audioDelay: Audio delay in millisecs
        virtual Core::hresult SetAudioDelay(const int handle /* @in */, uint32_t audioDelay /* @in */) = 0;

        /** Get Audio Delay  */
        // @text getAudioDelay
        // @brief Get Audio Delay
        // @param handle: handle returned in GetAudioPort()
        // @param audioDelay: Audio delay in millisecs
        virtual Core::hresult GetAudioDelay(const int handle /* @in */, uint32_t &audioDelay /* @out */) = 0;

        /** Set Audio Delay Offset */
        // @text setAudioDelayOffset
        // @brief Set Audio Delay offset
        // @param handle: handle returned in GetAudioPort()
        // @param delayOffset: delay offset in millisecs
        virtual Core::hresult SetAudioDelayOffset(const int handle /* @in */, int delayOffset /* @in */) = 0;

        /** Get Audio Delay Offset */
        // @text getAudioDelayOffset
        // @brief Get Audio Delay offset
        // @param handle: handle returned in GetAudioPort()
        // @param delayOffset: delay offset in millisecs
        virtual Core::hresult GetAudioDelayOffset(const int handle /* @in */, uint32_t &delayOffset /* @out */) = 0;

        /** Get Audio Sink device Atmos capability */
        // @text getAudioSinkDeviceAtmosCapability
        // @brief Get Audio Sink device Atmos capability
        // @param handle: handle returned in GetAudioPort()
        // @param atmosCapability: Atmos capability
        virtual Core::hresult GetAudioSinkDeviceAtmosCapability(const int handle /* @in */, DolbyAtmosCapability &atmosCapability /* @out */) = 0;

        /** Set Audio Atmos output mode */
        // @text setAudioAtmosOutputMode
        // @brief Set Audio Atmos output mode
        // @param handle: handle returned in GetAudioPort()
        // @param enable: Enable audio atmos output mode
        virtual Core::hresult SetAudioAtmosOutputMode(const int handle /* @in */, bool enable /* @in */) = 0;

        /** Set Audio Compression */
        // @text setAudioCompression
        // @brief Set Audio Compression
        // @param handle: handle returned in GetAudioPort()
        // @param compressionLevel: compression level
        virtual Core::hresult SetAudioCompression(const int handle /* @in */, int compressionLevel /* @in */) = 0;

        /** Get Audio Compression */
        // @text getAudioCompression
        // @brief Get Audio Compression
        // @param handle: handle returned in GetAudioPort()
        // @param compressionLevel: compression level
        virtual Core::hresult GetAudioCompression(const int handle /* @in */, int &compressionLevel /* @out */) = 0;

        /** Set Audio Dialog Enhancement */
        // @text setAudioDialogEnhancement
        // @brief Set Audio Dialog Enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param level: Enhancement level
        virtual Core::hresult SetAudioDialogEnhancement(const int handle /* @in */, int level /* @in */) = 0;

        /** Get Audio Dialog Enhancement */
        // @text getAudioDialogEnhancement
        // @brief Get Audio Dialog Enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param level: Enhancement level
        virtual Core::hresult GetAudioDialogEnhancement(const int handle /* @in */, int &level /* @out */) = 0;

        /** Set Audio Dolby Volume mode  */
        // @text setAudioDolbyVolumeMode
        // @brief Set Audio Dolby volume mode
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable dolby volume mode) or false (disable dolby volume mode)
        virtual Core::hresult SetAudioDolbyVolumeMode(const int handle /* @in */, bool enable /* @in */) = 0;

        /** Get Audio Dolby Volume mode  */
        // @text getAudioDolbyVolumeMode
        // @brief Get Audio Dolby volume mode
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled dolby volume mode) or false (disabled dolby volume mode)
        virtual Core::hresult GetAudioDolbyVolumeMode(const int handle /* @in */, bool &enabled /* @out */) = 0;


        /** Set Audio Intelligent equalizer mode  */
        // @text setAudioIntelligentEqualizerMode
        // @brief Set Audio Intelligent equalizer mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult SetAudioIntelligentEqualizerMode(const int handle /* @in */, int mode /* @in */) = 0;

        /** Get Audio Intelligent equalizer mode  */
        // @text getAudioIntelligentEqualizerMode
        // @brief Get Audio Intelligent equalizer mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult GetAudioIntelligentEqualizerMode(const int handle /* @in */, int &mode /* @out */) = 0;

        /** Set Audio Volume leveller  */
        // @text setAudioVolumeLeveller
        // @brief Set Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        // @param volumeLeveller: volume leveller (mode and a level)
        virtual Core::hresult SetAudioVolumeLeveller(const int handle /* @in */, VolumeLeveller volumeLeveller /* @in */) = 0;

        /** Get Audio Volume leveller  */
        // @text getAudioVolumeLeveller
        // @brief Get Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        // @param volumeLeveller: volume leveller (mode and a level)
        virtual Core::hresult GetAudioVolumeLeveller(const int handle /* @in */, VolumeLeveller &volumeLeveller /* @out */) = 0;

        /** Set Audio Bass Enhancer  */
        // @text setAudioBassEnhancer
        // @brief Set Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param boost: boost for bass
        virtual Core::hresult SetAudioBassEnhancer(const int handle /* @in */, int boost /* @in */) = 0;

        /** Get Audio Bass Enhancer  */
        // @text getAudioBassEnhancer
        // @brief Get Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param boost: boost for bass
        virtual Core::hresult GetAudioBassEnhancer(const int handle /* @in */, int &boost /* @out */) = 0;

        /** Enable Audio Surroud Decoder  */
        // @text enableAudioSurroudDecoder
        // @brief Enable Audio Surroud Decoder
        // @param handle: handle returned in GetAudioPort()
         // @param enable: true (surround decoder enabled) or false (surround decoder disabled)
        virtual Core::hresult EnableAudioSurroudDecoder(const int handle /* @in */, bool enable /* @in */) = 0;

        /** Is Audio Surroud Decoder enabled? */
        // @text isAudioSurroudDecoderEnabled
        // @brief Audio Surroud Decoder enabled or not
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (surround decoder enabled) or false (surround decoder disabled)
        virtual Core::hresult IsAudioSurroudDecoderEnabled(const int handle /* @in */, bool &enabled /* @out */) = 0;

        /** Set Audio DRC mode  */
        // @text setAudioDRCMode
        // @brief Set Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param drcMode: mode
        virtual Core::hresult SetAudioDRCMode(const int handle /* @in */, int drcMode /* @in */) = 0;

         /** Get Audio DRC mode  */
        // @text getAudioDRCMode
        // @brief Get Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param drcMode: mode
        virtual Core::hresult GetAudioDRCMode(const int handle /* @in */, int &drcMode /* @out */) = 0;

        /** Set Audio Surroud Virtualizer  */
        // @text setAudioSurroudVirtualizer
        // @brief Set Audio Surroud Virtualizer
        // @param handle: handle returned in GetAudioPort()
        // @param surroundVirtualizer: virtualizer
        virtual Core::hresult SetAudioSurroudVirtualizer(const int handle /* @in */, SurroundVirtualizer surroundVirtualizer /* @in */) = 0;

        /** Get Audio Surroud Virtualizer  */
        // @text getAudioSurroudVirtualizer
        // @brief Get Audio Surroud Virtualizer
        // @param handle: handle returned in GetAudioPort()
        // @param surroundVirtualizer: virtualizer
        virtual Core::hresult GetAudioSurroudVirtualizer(const int handle /* @in */, SurroundVirtualizer &surroundVirtualizer /* @out */) = 0;

        /** Set Audio MI Steering   */
        // @text setAudioMISteering
        // @brief Set Audio MI Steering
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable steering) or false (disable steering)
        virtual Core::hresult SetAudioMISteering(const int handle /* @in */, bool enable /* @out */) = 0;

        /** Get Audio MI Steering   */
        // @text getAudioMISteering
        // @brief Get Audio MI Steering
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable steering) or false (disable steering)
        virtual Core::hresult GetAudioMISteering(const int handle /* @in */, bool &enable /* @out */) = 0;

        /** Set Audio Graphic Equalizer Mode    */
        // @text setAudioGraphicEqualizerMode
        // @brief Set Audio Graphic Equalizer Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: Equalizer mode
        virtual Core::hresult SetAudioGraphicEqualizerMode(const int handle /* @in */, int mode /* @in */) = 0;

        /** Get Audio Graphic Equalizer Mode    */
        // @text getAudioGraphicEqualizerMode
        // @brief Get Audio Graphic Equalizer Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: Equalizer mode
        virtual Core::hresult GetAudioGraphicEqualizerMode(const int handle /* @in */, int &mode /* @out */) = 0;

        /** Get Audio MS12 profile list    */
        // @text getAudioMS12ProfileList
        // @brief Get Audio MS12 profile list
        // @param handle: handle returned in GetAudioPort()
        // @param ms12ProfileList: MS12 profile list iterator
        virtual Core::hresult GetAudioMS12ProfileList(const int handle /* @in */, IDeviceSettingsAudioMS12AudioProfileIterator *&ms12ProfileList /* @out */) = 0;

        /** Get Audio MS12 profile    */
        // @text getAudioMS12Profile
        // @brief Get Audio MS12 profile
        // @param handle: handle returned in GetAudioPort()
        // @param profile: Name of the profile
        virtual Core::hresult GetAudioMS12Profile(const int handle /* @in */, string &profile /* @out */) = 0;

        /** Set Audio MS12 profile    */
        // @text setAudioMS12Profile
        // @brief Set Audio MS12 profile
        // @param handle: handle returned in GetAudioPort()
        // @param profile: Name of the profile
        virtual Core::hresult SetAudioMS12Profile(const int handle /* @in */, string &profile /* @out */) = 0;

        /** Set Audio Mixer Levels     */
        // @text setAudioMixerLevels
        // @brief Set Audio Mixer levels
        // @param handle: handle returned in GetAudioPort()
        // @param audioInput: AudioInput 
        // @param volume: Volume level
        virtual Core::hresult SetAudioMixerLevels(const int handle /* @in */, const AudioInput audioInput /* @in */, int &volume /* @in */) = 0;

        /** Set Associated Audio Mixing values     */
        // @text setAssociatedAudioMixing
        // @brief Set Associated Audio Mixing values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixing: true or false
        virtual Core::hresult SetAssociatedAudioMixing(const int handle /* @in */, bool mixing /* @out */) = 0;

        /** Get Associated Audio Mixing values     */
        // @text getAssociatedAudioMixing
        // @brief Get Associated Audio Mixing values 
        // @param handle: handle returned in GetAudioPort()
        // @param types: true or false
        virtual Core::hresult GetAssociatedAudioMixing(const int handle /* @in */, bool &mixing /* @out */) = 0;

        /** Set Audio Fader control values     */
        // @text setAudioFaderControl
        // @brief Set Audio Fader control values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixerBalance: Mixer balance for fader control
        virtual Core::hresult SetAudioFaderControl(const int handle /* @in */, int &mixerBalance /* @out */) = 0;

        /** Get Audio Fader control values     */
        // @text getAudioFaderControl
        // @brief Get Audio Fader control values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixerBalance: Mixer balance for fader control
        virtual Core::hresult GetAudioFaderControl(const int handle /* @in */, int &mixerBalance /* @out */) = 0;

        /** Set Primary Audio language     */
        // @text setAudioPrimaryLanguage
        // @brief Set Primary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param primaryAudioLanguage: Primary audio language
        virtual Core::hresult SetAudioPrimaryLanguage(const int handle /* @in */, string &primaryAudioLanguage /* @in */) = 0;

        /** Get Primary Audio language     */
        // @text getAudioPrimaryLanguage
        // @brief Get Primary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param primaryAudioLanguage: Primary audio language
        virtual Core::hresult GetAudioPrimaryLanguage(const int handle /* @in */, string &primaryAudioLanguage /* @out */) = 0;

        /** Set Secondary Audio language     */
        // @text setAudioSecondaryLanguage
        // @brief Set Secondary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param secondaryAudioLanguage: Secondary audio language
        virtual Core::hresult SetAudioSecondaryLanguage(const int handle /* @in */, string &secondaryAudioLanguage /* @in */) = 0;

        /** Get Primary Audio language     */
        // @text getAudioSecondaryLanguage
        // @brief Get Secondary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param secondaryAudioLanguage: Secondary audio language
        virtual Core::hresult GetAudioSecondaryLanguage(const int handle /* @in */, string &secondaryAudioLanguage /* @out */) = 0;

        /** Get Audio Capabilities     */
        // @text getAudioCapabilities
        // @brief Get Audio capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param capabilities: Capabilities
        virtual Core::hresult GetAudioCapabilities(const int handle /* @in */, int &capabilities /* @out */) = 0;

        /** Get Audio MS12 Capabilities     */
        // @text getAudioMS12Capabilities
        // @brief Get Audio MS12 capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param capabilities: Capabilities
        virtual Core::hresult GetAudioMS12Capabilities(const int handle /* @in */, int &capabilities /* @out */) = 0;

        /** Set Audio MS12 Settings override     */
        // @text setAudioMS12SettingsOverride
        // @brief Get Audio MS12 capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param profileName: Name of the profile
        // @param profileSettingsName: Name of the profile setting 
        // @param profileState: ADD or REMOVE
        virtual Core::hresult SetAudioMS12SettingsOverride(const int handle /* @in */, string &profileName /* @in */, string &profileSettingsName /* @in */, string &profileSettingValue /* @in */, string &profileState /* @in */ ) = 0;

        /** Is Audio output connected?    */
        // @text isAudioOutputConnected
        // @brief Is Audio output connected?
        // @param handle: handle returned in GetAudioPort()
        // @param isConnected: connected (true) or not (false)
        virtual Core::hresult IsAudioOutputConnected(const int handle /* @in */, bool &isConnected /* @out */) = 0;

        /** Reset Audio Dialog enhancement    */
        // @text resetAudioDialogEnhancement
        // @brief Reset Audio Dialog enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult ResetAudioDialogEnhancement(const int handle /* @in */) = 0;

        /** Reset Audio Bass enhancement    */
        // @text resetAudioBassEnhancer
        // @brief Reset Audio Bass enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult ResetAudioBassEnhancer(const int handle /* @in */) = 0;

        /** Reset Audio Surround virtualizer   */
        // @text resetAudioSurroundVirtualizer
        // @brief Reset Audio Surround virtualizer
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult ResetAudioSurroundVirtualizer(const int handle /* @in */) = 0;

        /** Reset Audio Volume leveller    */
        // @text resetAudioVolumeLeveller
        // @brief Reset Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult ResetAudioVolumeLeveller(const int handle /* @in */) = 0;

        /** Get Audio HDMI ARC Port ID    */
        // @text getAudioHDMIARCPortId
        // @brief Get Audio HDMI ARC Port ID
        // @param handle: handle returned in GetAudioPort()
        // @param portId: Port Id
        virtual Core::hresult GetAudioHDMIARCPortId(const int handle /* @in */, int &portId /* @out */) = 0;
            };
    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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



        // @json @text:keep
        struct EXTERNAL IDeviceSettingsVideoPort : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_VIDEOPORT };

        enum VideoPort : uint8_t {
            DS_VIDEO_PORT_TYPE_UNKNOWN     = 0,
            DS_VIDEO_PORT_TYPE_RF          = 1,
            DS_VIDEO_PORT_TYPE_BB          = 2,
            DS_VIDEO_PORT_TYPE_SVIDEO      = 3,
            DS_VIDEO_PORT_TYPE_1394        = 4,
            DS_VIDEO_PORT_TYPE_DVI         = 5,
            DS_VIDEO_PORT_TYPE_COMPONENT   = 6,
            DS_VIDEO_PORT_TYPE_HDMI        = 7,
            DS_VIDEO_PORT_TYPE_HDMI_INPUT  = 8,
            DS_VIDEO_PORT_TYPE_INTERNAL    = 9 
        }

        enum VideoPortSurroundMode: uint8_t {
            DS_VIDEO_PORT_SURROUNDMODE_UNKNOWN = 0,
            DS_VIDEO_PORT_SURROUNDMODE_NONE    = 1,
            DS_VIDEO_PORT_SURROUNDMODE_DD      = 2,
            DS_VIDEO_PORT_SURROUNDMODE_DDPLUS  = 3
        }

        enum TVResolution: uint32_t {
            DS_TV_RESOLUTION_480I     = 0x000001,     
            DS_TV_RESOLUTION_480P     = 0x000002,     
            DS_TV_RESOLUTION_576I     = 0x000004,     
            DS_TV_RESOLUTION_576P     = 0x000008,     
            DS_TV_RESOLUTION_576P50   = 0x000010,   
            DS_TV_RESOLUTION_720P     = 0x000020,     
            DS_TV_RESOLUTION_720P50   = 0x000040,   
            DS_TV_RESOLUTION_1080I    = 0x000080,    
            DS_TV_RESOLUTION_1080P    = 0x000100,    
            DS_TV_RESOLUTION_1080P24  = 0x000200,  
            DS_TV_RESOLUTION_1080I25  = 0x000400,  
            DS_TV_RESOLUTION_1080I25  = 0x000800,  
            DS_TV_RESOLUTION_1080P30  = 0x001000,  
            DS_TV_RESOLUTION_1080I50  = 0x002000,  
            DS_TV_RESOLUTION_1080P50  = 0x004000,  
            DS_TV_RESOLUTION_1080P60  = 0x008000,  
            DS_TV_RESOLUTION_2160P24  = 0x010000,  
            DS_TV_RESOLUTION_2160P25  = 0x020000,  
            DS_TV_RESOLUTION_2160P30  = 0x040000,  
            DS_TV_RESOLUTION_2160P50  = 0x080000,  
            DS_TV_RESOLUTION_2160P60  = 0x100000  
        }

        enum VideoResolution: uint8_t {
            DS_VIDEO_PIXELRES_720x480,     
            DS_VIDEO_PIXELRES_720x576,     
            DS_VIDEO_PIXELRES_1280x720,    
            DS_VIDEO_PIXELRES_1366x768,    
            DS_VIDEO_PIXELRES_1920x1080,   
            DS_VIDEO_PIXELRES_3840x2160,   
            DS_VIDEO_PIXELRES_4096x2160 
        }

        enum VideoAspectRatio: uint8_t {
            DS_VIDEO_ASPECT_RATIO_4x3,    
            DS_VIDEO_ASPECT_RATIO_16x9 
        }
         
        enum VideoStereoScopicMode : uint8_t {
            DS_VIDEO_SSMODE_UNKNOWN           = 0,         
            DS_VIDEO_SSMODE_2D                = 1,                  
            DS_VIDEO_SSMODE_3D_SIDE_BY_SIDE   = 2,     
            DS_VIDEO_SSMODE_3D_TOP_AND_BOTTOM = 3                  
        }

        enum VideoFrameRate: uint8_t {
            DS_VIDEO_FRAMERATE_UNKNOWN   = 0, 
            DS_VIDEO_FRAMERATE_24        = 1,
            DS_VIDEO_FRAMERATE_25        = 2,       
            DS_VIDEO_FRAMERATE_30        = 3,       
            DS_VIDEO_FRAMERATE_60        = 4,       
            DS_VIDEO_FRAMERATE_23_98     = 5,  
            DS_VIDEO_FRAMERATE_29_97     = 6,  
            DS_VIDEO_FRAMERATE_50        = 7,       
            DS_VIDEO_FRAMERATE_59_94     = 8  
             
        }

        struct VideoPortResolution {
            string name;
            VideoResolution pixelResolution;
            VideoAspectRatio aspectRatio;
            VideoStereoScopicMode stereoScopicMode;
            VideoFrameRate frameRate;
            bool interlaced;
        };

        enum HDCPStatus : uint8_t {
            DS_HDCP_STATUS_UNPOWERED              = 0,            
            DS_HDCP_STATUS_UNAUTHENTICATED        = 1,          
            DS_HDCP_STATUS_AUTHENTICATED          = 2,            
            DS_HDCP_STATUS_AUTHENTICATIONFAILURE  = 3,    
            DS_HDCP_STATUS_INPROGRESS             = 4,               
            DS_HDCP_STATUS_PORTDISABLED           = 5             
        }

        enum HDCPProtocolVersion: uint8_t {
            DS_HDCP_VERSION_1X = 0,  
            DS_HDCP_VERSION_2X = 1
        }

        enum HDRStandard: uint16_t {
            DS_HDRSTANDARD_NONE             = 0x0,               
            DS_HDRSTANDARD_HDR10            = 0x01,             
            DS_HDRSTANDARD_HLG              = 0x02,              
            DS_HDRSTANDARD_DOLBYVISION      = 0x04,       
            DS_HDRSTANDARD_TECHNICOLORPRIME = 0x08,  
            DS_HDRSTANDARD_HDR10PLUS        = 0x10,          
            DS_HDRSTANDARD_SDR              = 0x20        
        }

        enum DisplayMatrixCoefficients: uint8_t {
            DS_DISPLAY_MATRIXCOEFFICIENT_UNKNOWN        = 0,   
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_709         = 1,        
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_470_2_BG    = 2,   
            DS_DISPLAY_MATRIXCOEFFICIENT_SMPTE_170M     = 3,   
            DS_DISPLAY_MATRIXCOEFFICIENT_XvYCC_709      = 4,     
            DS_DISPLAY_MATRIXCOEFFICIENT_eXvYCC_601     = 5,    
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_2020_NCL    = 6,   
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_2020_CL     = 7,    
            DS_DISPLAY_MATRIXCOEFFICIENT_eDVI_FR_RGB    = 8,   
            DS_DISPLAY_MATRIXCOEFFICIENT_eHDMI_RGB      = 9,     
            DS_DISPLAY_MATRIXCOEFFICIENT_eFCC           = 10,          
            DS_DISPLAY_MATRIXCOEFFICIENT_eSMPTE_240M    = 11,   
            DS_DISPLAY_MATRIXCOEFFICIENT_eHDMI_FR_YCbCr = 12           
        }

        enum DisplayColorSpace: uint8_t {
            DS_DISPLAY_COLORSPACE_UNKNOWN  = 0,   
            DS_DISPLAY_COLORSPACE_RGB      = 1,       
            DS_DISPLAY_COLORSPACE_YCbCr422 = 2,  
            DS_DISPLAY_COLORSPACE_YCbCr444 = 3,  
            DS_DISPLAY_COLORSPACE_YCbCr420 = 4,  
            DS_DISPLAY_COLORSPACE_AUTO     = 5              
        }

        enum DisplayQuantizationRange: uint8_t {
            DS_DISPLAY_QUANTIZATIONRANGE_UNKNOWN = 0,
            DS_DISPLAY_QUANTIZATIONRANGE_LIMITED = 1,    
            DS_DISPLAY_QUANTIZATIONRANGE_FULL    = 2
        }

        enum DisplayColorDepth : uint8_t {
            DS_DISPLAY_COLORDEPTH_UNKNOWN = 0x0, 
            DS_DISPLAY_COLORDEPTH_8BIT    = 0x01,   
            DS_DISPLAY_COLORDEPTH_10BIT   = 0x02,  
            DS_DISPLAY_COLORDEPTH_12BIT   = 0x04,  
            DS_DISPLAY_COLORDEPTH_AUTO    = 0x08
        }

        struct DSOutputSettings {
            HDRStandard videoEotf;
            DisplayMatrixCoefficients matrixCoefficients;
            uint32_t color_depth;
            DisplayColorSpace colorSpace;
            DisplayQuantizationRange quantizationRange;
        };

         enum VideoBackgroundColor : uint8_t {
            DS_VIDEO_BGCOLOR_BLUE   = 0,   
            DS_VIDEO_BGCOLOR_BLACK  = 1,  
            DS_VIDEO_BGCOLOR_NONE   = 2
        };

        struct ResolutioChange {
            uint32_t width;
            uint32_t height;
        };

         
        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_VIDEOPORT_NOTIFICATION };

            // @brief On Resolution Post change
            // @text onResolutionPostChange
            // @param resolution: resolution
            virtual void OnResolutionPostChange(const ResolutioChange resolution) = 0;

            // @brief On Resolution Pre changed
            // @text OnResolutionPreChange
            // @param resolution: resolution
            virtual void OnResolutionPreChange(const ResolutioChange resolution) = 0;

            // @brief On HDCP Status change 
            // @text OnHDCPStatusChange
            // @param hdcpStatus: HDCP Status
            virtual void OnHDCPStatusChange(const HDCPStatus hdcpStatus) = 0;

            // @brief On Video Format update 
            // @text OnVideoFormatUpdate
            // @param videoFormatHDR: Video format HDR standard
            virtual void OnVideoFormatUpdate(const HDRStandard videoFormatHDR) = 0;
             
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsVideoPort::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsVideoPort::INotification* notification /* @in */) = 0;

        /** Get Video Port handle. */
        // @text getVideoPort
        // @brief Get Video Port handle
        // @param videoPort: Type of port
        // @param index: index of the port (there can be multiple number of ports)
        // @param handle: handle to the port
        virtual Core::hresult GetVideoPort(const VideoPort videoPort /* @in */, const int index /* @in */, int &handle /* @out */) = 0;

        /** Video Port Enabled or not. */
        // @text isVideoPortEnabled
        // @brief Is Video Port enabled
        // @param handle: handle to the port
        // @param enabled: enabled (true) or disabled (false)
        virtual Core::hresult IsVideoPortEnabled(const int handle /* @in */, bool &enabled /* @out */) = 0;

        /** Video Port connected to display or not. */
        // @text isVideoPortDisplayConnected
        // @brief Is Video Port connected to display or not
        // @param handle: handle to the port
        // @param connected: connected (true) or not connected (false)
        virtual Core::hresult IsVideoPortDisplayConnected(const int handle /* @in */, bool &connected /* @out */) = 0;

        /** Video Port connected to display or not. */
        // @text isVideoPortDisplayConnected
        // @brief Is Video Port connected to display or not
        // @param handle: handle to the port
        // @param connected: connected (true) or not connected (false)
        virtual Core::hresult IsVideoPortDisplayConnected(const int handle /* @in */, bool &connected /* @out */) = 0;

        /** Video port display supports surround or not. */
        // @text isVideoPortDisplaySurround
        // @brief Does Video Port display support surround or not
        // @param handle: handle to the port
        // @param surround: supports surround (true) or not (false)
        virtual Core::hresult IsVideoPortDisplaySurround(const int handle /* @in */, bool &surround /* @out */) = 0;

        /** Video port display supports surround or not. */
        // @text isVideoPortDisplaySurround
        // @brief Does Video Port display support surround or not
        // @param handle: handle to the port
        // @param surroundMode: surround mode
        virtual Core::hresult GetVideoPortDisplaySurroundMode(const int handle /* @in */, VideoPortSurroundMode &surroundMode /* @out */) = 0;

        /** Video port display supports surround or not. */
        // @text isVideoPortDisplaySurround
        // @brief Does Video Port display support surround or not
        // @param handle: handle to the port
        // @param surroundMode: surround mode
        virtual Core::hresult GetVideoPortDisplaySurroundMode(const int handle /* @in */, VideoPortSurroundMode &surroundMode /* @out */) = 0;

        /** Enable Video port. */
        // @text enableVideoPort
        // @brief Enable video port
        // @param handle: handle to the port
        // @param enable: enable (true) or disable (false) 
        virtual Core::hresult EnableVideoPort(const int handle /* @in */, bool enable /* @in */) = 0;

        /** Get Video port resolution. */
        // @text getVideoPortResolution
        // @brief Get Video port resolution
        // @param handle: handle to the port
        // @param enable: enable (true) or disable (false) 
        virtual Core::hresult GetVideoPortResolution(const int handle /* @in */, VideoPortResolution &videoPortResolution /* @out */) = 0;

        /** Set Video port resolution. */
        // @text setVideoPortResolution
        // @brief Set Video port resolution
        // @param handle: handle to the port
        // @param videoPortResolution: video port resolution 
        // @param persist: persist this setting
        // @param forCompatibilty: force compatibility
        virtual Core::hresult SetVideoPortResolution(const int handle /* @in */, VideoPortResolution videoPortResolution /* @in */, bool persist /* @in */, bool forceCompatibility /* @in */) = 0;

        /** Enable HDCP Video port. */
        // @text enableHDCPOnVideoPort
        // @brief Enable HDCP on video port
        // @param handle: handle to the port
        // @param enable: enable (true) or disable (false) 
        // @param hdcpKey: hdcp key 
        // @param hdcpKeySize: number of bytes in hdcpKey array
        virtual Core::hresult EnableHDCPOnVideoPort(const int handle /* @in */, bool hdcpEnable /* @in */, char hdcpKey[] /* @in */, int hdcpKeySize /* @in */) = 0;

        /** Is HDCP enabled on Video port. */
        // @text isHDCPEnabledOnVideoPort
        // @brief Is HDCP enabled on Video port
        // @param handle: handle to the port
        // @param hdcpEnabled: enabled (true) or disabled (false) 
        virtual Core::hresult IsHDCPEnabledOnVideoPort(const int handle /* @in */, bool &hdcpEnabled /* @out */) = 0;

        /**  Get HDCP Status on Video port. */
        // @text getHDCPStatusOnVideoPort
        // @brief Get HDCP Status on Video port
        // @param handle: handle to the port
        // @param hdcpStatus: HDCP status
        virtual Core::hresult GetHDCPStatusOnVideoPort(const int handle /* @in */, HDCPStatus &hdcpStatus /* @out */) = 0;

        /**  Get HDCP Protocol version on Video port. */
        // @text getHDCPProtocolVersionOnVideoPort
        // @brief Get HDCP Protocol version on Video port
        // @param handle: handle to the port
        // @param hdcpVersion: HDCP version
        virtual Core::hresult GetHDCPProtocolVersionOnVideoPort(const int handle /* @in */, HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Get HDCP Receiver Protocol version on Video port. */
        // @text getHDCPReceiverProtocolVersionOnVideoPort
        // @brief Get HDCP Receiver Protocol version on Video port
        // @param handle: handle to the port
        // @param hdcpVersion: HDCP version
        virtual Core::hresult GetHDCPReceiverProtocolVersionOnVideoPort(const int handle /* @in */, HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Get HDCP Current Protocol version on Video port. */
        // @text getHDCPCurrentProtocolVersionOnVideoPort
        // @brief Get HDCP Current Protocol version on Video port
        // @param handle: handle to the port
        // @param hdcpVersion: HDCP version
        virtual Core::hresult GetHDCPCurrentProtocolVersionOnVideoPort(const int handle /* @in */, HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /** Is Video port active. */
        // @text isVideoPortActive
        // @brief Is Video port active
        // @param handle: handle to the port
        // @param active: active (true) or inactive (false) 
        virtual Core::hresult IsVideoPortActive(const int handle /* @in */, bool &active /* @out */) = 0;

        /**  Get TVs HDR capabilities. */
        // @text getTVHDRCapabilities
        // @brief Get TVs HDR capabilities
        // @param handle: handle to the port
        // @param capabilities: capabilities (masked value) - see HDRStandard
        virtual Core::hresult GetTVHDRCapabilities(const int handle /* @in */, int &capabilities /* @out */) = 0;

        /**  Get TVs supported resolutions. */
        // @text getTVHDRCapabilities
        // @brief  Get TVs supported resolutions
        // @param handle: handle to the port
        // @param resolutions: resolutions (masked value) - see TVResolution
        virtual Core::hresult GetTVSupportedResolutions(const int handle /* @in */, int &resolutions /* @out */) = 0;

        /** Set Disable 4K. */
        // @text setForceDisable4K
        // @brief Force disable 4K
        // @param handle: handle to the port
        // @param disable: disable (true) or enable (false) 
        virtual Core::hresult SetForceDisable4K(const int handle /* @in */, bool disable /* @in */) = 0;

        /** Get Disable 4K status. */
        // @text setForceDisable4K
        // @brief Get Force disable 4K value
        // @param handle: handle to the port
        // @param disabled: disabled (true) or enabled (false) 
        virtual Core::hresult GetForceDisable4K(const int handle /* @in */, bool &disabled /* @out */) = 0;

        /** Is Video port output HDR?. */
        // @text issVideoPortOutputHDR
        // @brief Is Video port output HDR?
        // @param handle: handle to the port
        // @param isHDR: yes (true) or no (false) 
        virtual Core::hresult IsVideoPortOutputHDR(const int handle /* @in */, bool &isHDR /* @out */) = 0;

        /** Reset Video port output to SDR. */
        // @text resetVideoPortOutputToSDR
        // @brief Reset Video port output to SDR
        virtual Core::hresult ResetVideoPortOutputToSDR() = 0;

        /**  Get HDMI preferred HDCP protocol version. */
        // @text getHDMIPreference
        // @brief Get HDMI preferred HDCP protocol version
        // @param handle: handle to the port
        // @param hdcpVersion: HDCP version
        virtual Core::hresult GetHDMIPreference(const int handle /* @in */, HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Set HDMI preferred HDCP protocol version. */
        // @text setHDMIPreference
        // @brief Set HDMI preferred HDCP protocol version
        // @param handle: handle to the port
        // @param hdcpVersion: HDCP version
        virtual Core::hresult SetHDMIPreference(const int handle /* @in */, HDCPProtocolVersion hdcpVersion /* @in */) = 0;


        /**  Get TVs HDR capabilities. */
        // @text getVideoEOTF
        // @brief Get TVs HDR capabilities
        // @param handle: handle to the port
        // @param hdrStandard: see HDRStandard
        virtual Core::hresult GetVideoEOTF(const int handle /* @in */, HDRStandard &hdrStandard /* @out */) = 0;

        /**  Get Matrix coefficients. */
        // @text getMatrixCoefficients
        // @brief Get Matrix coefficients
        // @param handle: handle to the port
        // @param matrixCoefficients: see DisplayMatrixCoefficients
        virtual Core::hresult GetMatrixCoefficients(const int handle /* @in */, DisplayMatrixCoefficients &matrixCoefficients /* @out */) = 0;
                 
        /**  Get Color Depth. */
        // @text getColorDepth
        // @brief Get Color Depth
        // @param handle: handle to the port
        // @param colorDepth: color depth See DisplayColorDepth (masked)
        virtual Core::hresult GetColorDepth(const int handle /* @in */, uint32_t &colorDepth /* @out */) = 0;

        /**  Get Color Space. */
        // @text getColorSpace
        // @brief Get Color Space
        // @param handle: handle to the port
        // @param colorSpace: color space
        virtual Core::hresult GetColorSpace(const int handle /* @in */, DisplayColorSpace &colorSpace /* @out */) = 0;

        /**  Get Quantization Range. */
        // @text getQuantizationRange
        // @brief Get Quantization range
        // @param handle: handle to the port
        // @param quantizationRange: quantization range
        virtual Core::hresult GetQuantizationRange(const int handle /* @in */, DisplayQuantizationRange &quantizationRange /* @out */) = 0;

        /**  Get Current output settings. */
        // @text getCurrentOutputSettings
        // @brief Get Current output settings
        // @param handle: handle to the port
        // @param outputSettings: Output settings 
        virtual Core::hresult GetCurrentOutputSettings(const int handle /* @in */, DSOutputSettings &outputSettings /* @out */) = 0;

        /**  Set Video background color. */
        // @text setBackgroundColor
        // @brief Set Video background color.
        // @param handle: handle to the port
        // @param backgroundColor: video background color
        virtual Core::hresult SetBackgroundColor(const int handle /* @in */, VideoBackgroundColor backgroundColor /* @in */) = 0;

        /**  Set HDR mode. */
        // @text setForceHDRMode
        // @brief Set HDR mode 
        // @param handle: handle to the port
        // @param hdrMode: see HDRStandard
        virtual Core::hresult SetForceHDRMode(const int handle /* @in */, HDRStandard hdrMode /* @in */) = 0;

        /**  Get Color Depth capabilities. */
        // @text getColorDepthCapabilities
        // @brief Get Color Depth capabilities
        // @param handle: handle to the port
        // @param colorDepthCapabilities: color depth capabilities See DisplayColorDepth (masked)
        virtual Core::hresult GetColorDepthCapabilities(const int handle /* @in */, uint32_t &colorDepthCapabilities /* @out */) = 0;

        /**  Get Preferred Color Depth. */
        // @text getPreferredColorDepth
        // @brief Get Preferred Color Depth
        // @param handle: handle to the port
        // @param colorDepth: color depth See DisplayColorDepth 
        // @param persist: return persisted value (true) or not (false)
        virtual Core::hresult GetPreferredColorDepth(const int handle /* @in */, DisplayColorDepth &colorDepth /* @out */, bool persist /* @in */) = 0;
         
        /**  Set Preferred Color Depth. */
        // @text getPreferredColorDepth
        // @brief Set Preferred Color Depth
        // @param handle: handle to the port
        // @param colorDepth: color depth See DisplayColorDepth 
        // @param persist:  persist value (true) or not (false)
        virtual Core::hresult SetPreferredColorDepth(const int handle /* @in */, DisplayColorDepth colorDepth /* @in */, bool persist /* @in */) = 0;
     

    };

    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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


        // @json @text:keep
        struct EXTERNAL IDeviceSettingsVideoDevice : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_VIDEODEVICE };

        enum VideoZoom : uint8_t {
            DS_VIDEO_DEVICE_ZOOM_UNKNOWN           = 0,
            DS_VIDEO_DEVICE_ZOOM_NONE              = 1,
            DS_VIDEO_DEVICE_ZOOM_FULL              = 2,
            DS_VIDEO_DEVICE_ZOOM_LB_16_9           = 3,
            DS_VIDEO_DEVICE_ZOOM_LB_14_9           = 4,
            DS_VIDEO_DEVICE_ZOOM_CCO               = 5,
            DS_VIDEO_DEVICE_ZOOM_PAN_SCAN          = 6,
            DS_VIDEO_DEVICE_ZOOM_LB_2_21_1_ON_4_3  = 7,
            DS_VIDEO_DEVICE_ZOOM_LB_2_21_1_ON_16_9 = 8,
            DS_VIDEO_DEVICE_ZOOM_PLATFORM          = 9,
            DS_VIDEO_DEVICE_ZOOM_16_9_ZOOM         = 10,
            DS_VIDEO_DEVICE_ZOOM_PILLARBOX_4_3     = 11,
            DS_VIDEO_DEVICE_ZOOM_WIDE_4_3          = 12
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_VIDEODEVICE_NOTIFICATION };

            // @brief Zoom settings changed
            // @text OnZoomSettingsChanged
            // @param zoomSetting: Currently applied zoom setting
            virtual void OnZoomSettingsChanged(const VideoZoom zoomSetting) = 0;

            // @brief Display Framerate Pre-change
            // @text OnDisplayFrameratePreChange
            // @param frameRate: PreChange framerate
            virtual void OnDisplayFrameratePreChange(const string frameRate) = 0;

            // @brief Display Framerate Post-change
            // @text OnDisplayFrameratePostChange
            // @param frameRate:  framerate post change
            virtual void OnDisplayFrameratePostChange(const string frameRate) = 0;
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsVidoeDevice::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingVideoDevice::INotification* notification /* @in */) = 0;
     

        /** Get Video Device handle. */
        // @text getVideoDeviceHandle
        // @brief Get Video device handle
        // @param index: index (can be multiple instances)
        // @param handle: video device handle (to be used for other APIs)
        virtual Core::hresult GetVideoDeviceHandle(const int index /* @in */, int &handle /* @out */) = 0;

        /** Set Video Device DFC. */
        // @text setVideoDeviceDFC
        // @brief Set Video Device DFC
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param zoomSetting: Zoom setting to apply
        virtual Core::hresult SetVideoDeviceDFC(const int handle /* @in */, const VideoZoom zoomSetting /* @in */) = 0;

        /** Get Video Device DFC. */
        // @text getVideoDeviceDFC
        // @brief Get Video Device DFC
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param zoomSetting: current Zoom setting
        virtual Core::hresult GetVideoDeviceDFC(const int handle /* @in */, VideoZoom &zoomSetting /* @out */) = 0;

        /** Get Video Device HDR capabilities. */
        // @text getHDRCapabilities
        // @brief Get Video Device HDR capabilities
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param capabilities: Capabilities
        virtual Core::hresult GetHDRCapabilities(const int handle /* @in */, int &capabilities /* @out */) = 0;

        /** Get Video Device Supported . */
        // @text getSupportedVideoCodingFormats
        // @brief Get Video Zoom setting
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param supportedFormats: Supported Formats
        virtual Core::hresult GetSupportedVideoCodingFormats(const int handle /* @in */, int &supportedFormats /* @out */) = 0;

        /** Get Video Device Codec Information TBD - vdixit. */
        // @text getCodecInfo
        // @brief Get Video Device Codec Information
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param supportedFormats: Supported Formats
        virtual Core::hresult GetCodecInfo(const int handle /* @in */, int &supportedFormats /* @out */) = 0;

        /** Video Device Disable HDR */
        // @text disableHDR
        // @brief Video Device Disable HDR
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param disable: disable (true) or enable (false)
        virtual Core::hresult DisableHDR(const int handle /* @in */, const bool disable /* @in */) = 0;

        /** Set Video Device FRF mode. */
        // @text setFRFMode
        // @brief Set FRF mode
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult SetFRFMode(const int handle /* @in */, const int frfmode /* @in */) = 0;

        /** Get Video Device FRF mode. */
        // @text getFRFMode
        // @brief Get FRF mode
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult GetFRFMode(const int handle /* @in */, int &frfmode /* @in */) = 0;

        /** Get Video Device display frame rate */
        // @text getCurrentDisplayFrameRate
        // @brief Get current display frame rate
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult GetCurrentDisplayFrameRate(const int handle /* @in */, string &framerate /* @out */) = 0;

        /** Set Video Device display frame rate */
        // @text setDisplayFrameRate
        // @brief Set current display frame rate
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult SetDisplayFrameRate(const int handle /* @in */, string &framerate /* @in */) = 0;


    };

    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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


        // @json @text:keep
        struct EXTERNAL IDeviceSettingsCompositeIn : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_COMPOSITEIN };


        enum CompositeInPort: uint8_t {
            DS_COMPOSITE_IN_PORT_UNKNOWN = 0  /* @text UNKNOWN */,
            DS_COMPOSITE_IN_PORT_0       = 1  /* @text CompositeIn Port 0 */,
            DS_COMPOSITE_IN_PORT_1       = 2  /* @text CompositeIn Port 1 */
        }

        enum CompositeInSignalStatus: uint8_t {
            DS_COMPOSITE_IN_SIGNAL_STATUS_UNKNOWN       = 0 /* @text UNKNOWN */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NONE          = 1 /* @text Signal Status None */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOSIGNAL      = 2 /* @text Signal Status No Signal */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_UNSTABLE      = 3 /* @text Signal Status Unstable */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOTSUPPORTED  = 4 /* @text Signal Status Not supported */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_STABLE        = 5 /* @text Signal Status Stable */
        }

        struct CompositeInStatus {
            bool isPresented;
            CompositeInPort activePort;
            bool isPort0Connected;
            bool isPort1Connected; /* Can't have array in structures..so separating the booleans */
        }

        struct VideoRectangle {
            int x;
            int y;
            int width;
            int height;
        }

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_COMPOSITEIN_NOTIFICATION };

            // @brief Composite In Hotplug event
            // @text onCompositeInHotPlug
            // @param port: Port of the hotplug 
            // @param isConnected: Is it connected (true) or not(false)
            virtual void OnCompositeInHotPlug(const CompositeInPort port, const bool isConnected) = 0;

            // @brief Composite In Signal status
            // @text onCompositeInSignalStatus
            // @param port: Port of the hotplug 
            // @param signalStatus: Signal status
            virtual void OnCompositeInSignalStatus(const CompositeInPort port, const CompositeInSignalStatus signalStatus) = 0;

            // @brief Composite In status
            // @text onCompositeInStatus
            // @param activePort: Active port
            // @param isPresented: is it presented to user
            virtual void OnCompositeInStatus(const CompositeInPort activePort, const bool isPresented) = 0;
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsCompositeIn::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsCompositeIn::INotification* notification /* @in */) = 0;
     
        /** Get number of composite inputs. */
        // @text getNrOfCompositeInputs
        // @brief Get Preferred Sleep mode.
        // @param nrCompositeInputs: number of composite inputs
        virtual Core::hresult GetNrOfCompositeInputs(int &nrCompositeInputs /* @out */) = 0;

        /** Get Composite In port status. */
        // @text getCompositeInStatus
        // @brief Get Composite In port status
        // @param status: Composite In status
        virtual Core::hresult GetCompositeInStatus(CompositeInStatus &status /* @in */) = 0;

        /** Select Composite In port */
        // @text selectCompositeInPort
        // @brief Select Composite In port.
        // @param port: port to be selected
        virtual Core::hresult SelectCompositeInPort(const CompositeInPort port /* @in */) = 0;

        /** Scale composite video . */
        // @text scaleCompositeInVideo
        // @brief Scale composite video.
        // @param videoRect: co-ordinates and width/height to scale to
        virtual Core::hresult ScaleCompositeInVideo(const VideoRectangle videoRect /* @in */) = 0;

    };

    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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

        // @json @text:keep
        struct EXTERNAL IDeviceSettingsHost : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_HOST };

        enum SleepMode : uint8_t {
            DS_HOST_SLEEPMODE_UNKNOWN    = 0,
            DS_HOST_SLEEPMODE_LIGHT      = 1,
            DS_HOST_SLEEPMODE_DEEP       = 2,
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_HOST_NOTIFICATION };

            // @brief Associated Audio mixing changed
            // @text onAssociatedAudioMixingChanged
            // @param mixing: true or false
            virtual void OnSleepModeChanged(const SleepMode sleepMode) = 0;
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsHost::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsHost::INotification* notification /* @in */) = 0;
     
        /** Get Preferred Sleep mode. */
        // @text getPreferredSleepMode
        // @brief Get Preferred Sleep mode.
        // @param mode: Sleep mode
        virtual Core::hresult GetPreferredSleepMode(SleepMode &mode /* @out */) = 0;

        /** Get Preferred Sleep mode. */
        // @text setPreferredSleepMode
        // @brief Set Preferred Sleep mode.
        // @param mode: Sleep mode
        virtual Core::hresult SetPreferredSleepMode(const SleepMode mode /* @in */) = 0;

        /** Get CPU temperature. */
        // @text getCPUTemperature
        // @brief Get CPU temperature.
        // @param temperature: temperature in degree centigrade?
        virtual Core::hresult GetCPUTemperature(float &temperature /* @out */) = 0;

        /** Get HAL Version . */
        // @text getHALVersion
        // @brief Get HAL Version.
        // @param versionNo: 16 bits MSB is major version and 16 bits LSB is minor version
        virtual Core::hresult GetHALVersion(uint32 &versionNo /* @out */) = 0;

        /** Get SOCID. */
        // @text getHALVersion
        // @brief Get SOCID.
        // @param socID: SOCID in string format
        virtual Core::hresult GetSoCID(string &socID /* @out */) = 0;

        /** Get EDID Bytes. */
        // @text getHALVersion
        // @brief Get EDID.
        // @param socID: EDID in string format - TBD is string ok? - vdixit
        virtual Core::hresult GetEDID(string &edId /* @out */) = 0;

        /** Get MS12 Config type. */
        // @text getHALVersion
        // @brief Get MS12 Config
        // @param ms12Config: MS12 config type
        virtual Core::hresult GetMS12ConfigType(string &ms12Config /* @out */) = 0;

    };


    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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

        // @json @text:keep
        struct EXTERNAL IDeviceSettingsFPD : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_FPD };

        enum FPDTimeFormat : uint8_t {
            DS_FPD_TIMEFORMAT_UNKNOWN    = 0,
            DS_FPD_TIMEFORMAT_12_HOUR    = 1,
            DS_FPD_TIMEFORMAT_24_HOUR    = 2
        };

        enum FPDIndicator : uint8_t {
            DS_FPD_INDICATOR_UNKNOWN    = 0,
            DS_FPD_INDICATOR_MESSAGE    = 1,
            DS_FPD_INDICATOR_POWER      = 2,
            DS_FPD_INDICATOR_RECORD     = 3,
            DS_FPD_INDICATOR_REMOTE     = 4,
            DS_FPD_INDICATOR_RFBYPASS   = 5
        };

        enum FPDState : uint8_t {
            DS_FPD_STATE_UNKNOWN    = 0,
            DS_FPD_STATE_OFF        = 1,
            DS_FPD_STATE_ON         = 2
        };

        enum FPDTextDisplay : uint8_t {
            DS_FPD_TEXTDISPLAY_UNKNOWN     = 0,
            DS_FPD_TEXTDISPLAY_TEXT        = 1
        };

        enum FPDMode : uint8_t {
            DS_FPD_MODE_UNKNOWN    = 0,
            DS_FPD_MODE_ANY        = 1,
            DS_FPD_MODE_TEXT       = 2,
            DS_FPD_MODE_CLOCK      = 3
        };
         

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_FPD_NOTIFICATION };

            // @brief On Front Panel display time format changed
            // @text OnFPDTimeFormatChanged
            // @param timeFormat: current time format 12 or 24 hour
            virtual void OnFPDTimeFormatChanged(const FPDTimeFormat timeFormat) = 0;
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsFPD::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingFPD::INotification* notification /* @in */) = 0;

        /** Set Front Panel Display Time. */
        // @text setFPDTime
        // @brief Set Front Panel Display Time.
        // @param timeFormat: Time format in 12 hour or 24 hour format
        // @param minutes: Minutes value to display
        // @param seconds: Seconds value to display
        virtual Core::hresult SetFPDTime(const FPDTimeFormat timeFormat /* @in */, const uint32_t minutes /* @in */, const uint32_t seconds /* @in */) = 0;

        /** Set Front Panel Display Scroll. */
        // @text setFPDScroll
        // @brief Set Front Panel Display Scroll.
        // @param scrollHoldDuration: Scroll hold duration
        // @param nHorizontalScrollIterations: number of horizontal scroll iterations
        // @param nVerticalScrollIterations: number of vertical scroll iterations
        virtual Core::hresult SetFPDScroll(const uint32_t scrollHoldDuration /* @in */, const uint32_t nHorizontalScrollIterations /* @in */, const uint32_t nVerticalScrollIterations /* @in */) = 0;

        /** Set Front Panel Display Blink. */
        // @text setFPDBlink
        // @brief Set Front Panel Display Blink.
        // @param indicator: Type of indicator
        // @param blinkDuration: Time in seconds for which the indictor has to be blinked
        // @param blinkIterations: number of times the blink has to be done for the blink duration
        virtual Core::hresult SetFPDBlink(const FPDIndicator indicator /* @in */, const uint32_t blinkDuration /* @in */, const uint32_t blinkIterations /* @in */) = 0;

        /** Set Front Panel Display Blink. */
        // @text setFPDBrightness
        // @brief Set Front Panel Display Blink.
        // @param indicator: Type of indicator
        // @param brightNess: brightness between 1 and 100 
        // @param persist: persist( true ) the brightness or not (false)
        virtual Core::hresult SetFPDBrightness(const FPDIndicator indicator /* @in */, const uint32_t brightNess /* @in */, const bool persist /* @in */)  = 0;

        /** Get Front Panel Display Brightness. */
        // @text getFPDScroll
        // @brief Get Front Panel Display Brightness.
        // @param indicator: Type of indicator
        // @param brightNess: brightness between 1 and 100 
        virtual Core::hresult GetFPDBrightness(const FPDIndicator indicator /* @in */, uint32_t &brightNess /* @out */)  = 0;

        /** Set Front Panel Display State. */
        // @text setFPDState
        // @brief Set Front Panel Display State.
        // @param indicator: Type of indicator
        // @param state: FPD State
        virtual Core::hresult SetFPDState(const FPDIndicator indicator /* @in */, const FPDState state /* @in */)  = 0;

        /** Get Front Panel Display State. */
        // @text getFPDState
        // @brief Get Front Panel Display State.
        // @param indicator: Type of indicator
        // @param state: FPD State
        virtual Core::hresult GetFPDState(const FPDIndicator indicator /* @in */, FPDState &state /* @out */)  = 0;

        /** Get Front Panel Display Color. */
        // @text getFPDColor
        // @brief Get Front Panel Display Color.
        // @param indicator: Type of indicator
        // @param color: color
        virtual Core::hresult GetFPDColor(const FPDIndicator indicator /* @in */, uint32_t &color /* @out */)  = 0;

        /** Set Front Panel Display Color. */
        // @text setFPDColor
        // @brief Set Front Panel Display State.
        // @param indicator: Type of indicator
        // @param color: color
        virtual Core::hresult SetFPDColor(const FPDIndicator indicator /* @in */, const uint32_t color /* @in */)  = 0;

        /** Set Front Panel Text Display (LED). */
        // @text setFPDColor
        // @brief Set Front Panel Text Display (LED).
        // @param textDisplay: Text display
        // @param brightNess: Brightness of the text display
        virtual Core::hresult SetFPDTextBrightness(const FPDTextDisplay textDisplay /* @in */, const uint32_t brightNess /* @in */)  = 0;
        
        /** Get Front Panel Text Display (LED). */
        // @text setFPDColor
        // @brief Get Front Panel Text Display (LED).
        // @param textDisplay: Text display
        // @param brightNess: Brightness of the text display
        virtual Core::hresult GetFPDTextBrightness(const FPDTextDisplay textDisplay /* @in */, uint32_t &brightNess /* @out */)  = 0;

        /** Enable Front Panel Clock display. */
        // @text enableFPDClockDisplay
        // @brief Enable Front Panel Clock display.
        // @param enable: enable (true) or disable (false) clock display
        virtual Core::hresult EnableFPDClockDisplay(const bool enable /* @in */)  = 0;

        /** Get Front Panel Display Time format. */
        // @text getFPDTimeFormat
        // @brief Get Front Panel Display Time format.
        // @param fpdTimeFormat: 12 or 24 hour format
        virtual Core::hresult GetFPDTimeFormat(FPDTimeFormat &fpdTimeFormat /* @out */)  = 0;

        /** Set Front Panel Display Time format. */
        // @text setFPDTimeFormat
        // @brief Set Front Panel Display Time format.
        // @param fpdTimeFormat: 12 or 24 hour format
        virtual Core::hresult SetFPDTimeFormat(const FPDTimeFormat fpdTimeFormat /* @in */)  = 0;

        /** Set Front Panel Display Mode. */
        // @text setFPDMode
        // @brief Set Front Panel Display Mode.
        // @param fpdMode: FPD Mode
        virtual Core::hresult SetFPDMode(const FPDMode fpdMode /* @in */)  = 0;
    };

    /*
    * If not stated otherwise in this file or this component's LICENSE file the
    * following copyright and licenses apply:
    *
    * Copyright 2025 Synamedia Ltd.
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

        // @json @text:keep
        struct EXTERNAL IDeviceSettingsDisplay : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_DISPLAY };

        enum VideoPort : uint8_t {
            DS_VIDEO_PORT_TYPE_UNKNOWN     = 0  /* @text Video Port UNKNOWN */,
            DS_VIDEO_PORT_TYPE_RF          = 1  /* @text Video Port Type RF */,
            DS_VIDEO_PORT_TYPE_BB          = 2  /* @text Video Port Type Baseband composite */,
            DS_VIDEO_PORT_TYPE_SVIDEO      = 3  /* @text Video Port Type SVideo */,
            DS_VIDEO_PORT_TYPE_1394        = 4  /* @text Video Port Type 1394 firewire */,
            DS_VIDEO_PORT_TYPE_DVI         = 5  /* @text Video Port Type DVI  */,
            DS_VIDEO_PORT_TYPE_COMPONENT   = 6  /* @text Video Port Type Component video output */,
            DS_VIDEO_PORT_TYPE_HDMI        = 7  /* @text Video Port Type HDMI output*/,
            DS_VIDEO_PORT_TYPE_HDMI_INPUT  = 8  /* @text Video Port Type HDMI Input */,
            DS_VIDEO_PORT_TYPE_INTERNAL    = 9  /* @text Video Port Type Internal/integrated display */
        }

        enum VideoAspectRatio : uint8_t {
            DS_VIDEO_ASPECT_RATIO_UNKNOWN     = 0  /* @text Video Aspect Ratio UNKNOWN */,
            DS_VIDEO_ASPECT_RATIO_4X3         = 1  /* @text Video Aspect Ratio 4X3 */,
            DS_VIDEO_ASPECT_RATIO_16x9        = 2  /* @text Video Aspect Ratio 16x9 */
        }


        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_DISPLAY_NOTIFICATION };

            // @brief Composite In Hotplug event
            // @text onCompositeInHotPlug
            // @param port: Port of the hotplug 
            // @param isConnected: Is it connected (true) or not(false)
            virtual void OnCompositeInHotPlug(const CompositeInPort port, const bool isConnected) = 0;

            // @brief Composite In Signal status
            // @text onCompositeInSignalStatus
            // @param port: Port of the hotplug 
            // @param signalStatus: Signal status
            virtual void OnCompositeInSignalStatus(const CompositeInPort port, const CompositeInSignalStatus signalStatus) = 0;

            // @brief Composite In status
            // @text onCompositeInStatus
            // @param activePort: Active port
            // @param isPresented: is it presented to user
            virtual void OnCompositeInStatus(const CompositeInPort activePort, const bool isPresented) = 0;
             
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsDisplay::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsDisplay::INotification* notification /* @in */) = 0;

        /** Get Handle of Video port. */
        // @text getDisplay
        // @brief Get Handle of Video port
        // @param port: port for which the handle is required
        // @param index: index of the port (there can be multiple number of ports)
        // @param handle: handle to the port
        virtual Core::hresult GetDisplay(VideoPort port /* @in */, int index /* @in */, int &handle /* @out */) = 0;

        /** Get Display Aspect ratio. */
        // @text getDisplayAspectRatio
        // @brief Get Display Aspect ratio
        // @param handle: handle returned in GetDisplay
        // @param aspectRatio: Aspect ratio of port
        virtual Core::hresult GetDisplayAspectRatio(const int handle /* @in */, VideoAspectRatio &aspectRatio /* @out */) = 0;

        /** Select Composite In port */
        // @text selectCompositeInPort
        // @brief Select Composite In port.
        // @param port: port to be selected
        virtual Core::hresult SelectCompositeInPort(const CompositeInPort port /* @in */) = 0;

        /** Scale composite video . */
        // @text scaleCompositeInVideo
        // @brief Scale composite video.
        // @param videoRect: co-ordinates and width/height to scale to
        virtual Core::hresult ScaleCompositeInVideo(const VideoRectangle videoRect /* @in */) = 0;

    };
    } // namespace Exchange
    } // namespace WPEFramework

