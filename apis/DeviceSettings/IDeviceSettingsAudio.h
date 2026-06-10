/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management.
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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IDeviceSettingsAudio : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_AUDIO };

        enum AudioPortType : uint8_t {
            AUDIO_PORT_TYPE_LR        = 0,
            AUDIO_PORT_TYPE_HDMI      = 1,
            AUDIO_PORT_TYPE_SPDIF     = 2,
            AUDIO_PORT_TYPE_SPEAKER   = 3,
            AUDIO_PORT_TYPE_HDMIARC   = 4,
            AUDIO_PORT_TYPE_HEADPHONE = 5,
            AUDIO_PORT_TYPE_MAX       = 6
        };

        enum AudioPortState : uint8_t {
            AUDIO_PORT_STATE_UNINITIALIZED = 0,
            AUDIO_PORT_STATE_INITIALIZED   = 1,
            AUDIO_PORT_STATE_MAX           = 2
        };

        enum AudioEncoding : uint8_t {
            AUDIO_ENCODING_NONE            = 0,
            AUDIO_ENCODING_DISPLAY         = 1,
            AUDIO_ENCODING_PCM             = 2,
            AUDIO_ENCODING_AC3             = 3,
            AUDIO_ENCODING_EAC3            = 4,
            AUDIO_ENCODING_MAX             = 5
        };

        using IDeviceSettingsAudioEncodingIterator = RPC::IIteratorType<AudioEncoding, ID_DEVICESETTINGS_AUDIO_ENCODING_ITERATOR>;

        enum AudioCompression : uint8_t {
            AUDIO_COMPRESSION_NONE          = 0,
            AUDIO_COMPRESSION_LIGHT         = 1,
            AUDIO_COMPRESSION_MEDIUM        = 2,
            AUDIO_COMPRESSION_HEAVY         = 3,
            AUDIO_COMPRESSION_MAX           = 4
        };

        using IDeviceSettingsAudioCompressionIterator = RPC::IIteratorType<AudioCompression, ID_DEVICESETTINGS_AUDIO_COMPRESSION_ITERATOR>;

        enum AudioFormat : uint8_t {
            AUDIO_FORMAT_NONE               = 0,
            AUDIO_FORMAT_PCM                = 1,
            AUDIO_FORMAT_DOLBY_AC3          = 2,
            AUDIO_FORMAT_DOLBY_EAC3         = 3,
            AUDIO_FORMAT_DOLBY_AC4          = 4,
            AUDIO_FORMAT_DOLBY_MAT          = 5,
            AUDIO_FORMAT_DOLBY_TRUEHD       = 6,
            AUDIO_FORMAT_DOLBY_EAC3_ATMOS   = 7,
            AUDIO_FORMAT_DOLBY_TRUEHD_ATMOS = 8,
            AUDIO_FORMAT_DOLBY_MAT_ATMOS    = 9,
            AUDIO_FORMAT_DOLBY_AC4_ATMOS    = 10,
            AUDIO_FORMAT_AAC                = 11,
            AUDIO_FORMAT_VORBIS             = 12,
            AUDIO_FORMAT_WMA                = 13,
            AUDIO_FORMAT_UNKNOWN            = 14,
            AUDIO_FORMAT_MAX                = 15
        };

        enum AudioDuckingAction : uint8_t {
            AUDIO_DUCKINGACTION_START         = 0,
            AUDIO_DUCKINGACTION_STOP          = 1,
            AUDIO_DUCKINGACTION_MAX           = 2,
        };

        enum AudioDuckingType : uint8_t {
            AUDIO_DUCKINGTYPE_ABSOLUTE       = 0,
            AUDIO_DUCKINGTYPE_RELATIVE       = 1,
            AUDIO_DUCKINGTYPE_MAX            = 2
        };

        enum AudioCapabilities : uint32_t {
            AUDIO_CAPS_NONE                      = 0,
            AUDIO_CAPS_ATMOS                     = 1,
            AUDIO_CAPS_DOLBY_DIGITAL             = 2,
            AUDIO_CAPS_DOLBY_DIGITAL_PLUS        = 4,
            AUDIO_CAPS_DIGITAL_AUDIO_DELIVERY    = 8,
            AUDIO_CAPS_DIGITAL_AUDIO_PROCESS_V2  = 16,
            AUDIO_CAPS_MS12                      = 32,
            AUDIO_CAPS_MS12_V2                   = 64,
            AUDIO_CAPS_INVALID                   = 128,
        };

        enum AudioARCType : uint8_t {
            AUDIO_ARCTYPE_NONE                    = 0,
            AUDIO_ARCTYPE_ARC                     = 1,
            AUDIO_ARCTYPE_EARC                    = 2
        };

        enum AudioInput : uint8_t {
            AUDIO_INPUT_PRIMARY                   = 0,
            AUDIO_INPUT_SYSTEM                    = 1,
            AUDIO_INPUT_MAX                       = 2
        };

        enum MS12Capabilities : uint32_t {
            AUDIO_MS12_CAPABILITIES_NONE                    = 0,
            AUDIO_MS12_CAPABILITIES_DOLBYVOLUME             = 1,
            AUDIO_MS12_CAPABILITIES_INTELLIGENT_EQUALIZER   = 2,
            AUDIO_MS12_CAPABILITIES_DIALOG_ENHANCER         = 4,
            AUDIO_MS12_CAPABILITIES_VOLUME_LEVELLER         = 8,
            AUDIO_MS12_CAPABILITIES_BASE_ENHANCER           = 16,
            AUDIO_MS12_CAPABILITIES_SURROUND_DECODER        = 32,
            AUDIO_MS12_CAPABILITIES_DRC_MODE                = 64,
            AUDIO_MS12_CAPABILITIES_SURROUND_VIRTUALIZER    = 128,
            AUDIO_MS12_CAPABILITIES_MI_STEERING             = 256,
            AUDIO_MS12_CAPABILITIES_GRAPHIC_EQUALIZER       = 512,
            AUDIO_MS12_CAPABILITIES_LE_CONFIG               = 1024,
            AUDIO_MS12_CAPABILITIES_INVALID                 = (1 << 30)
        };

        struct MS12AudioProfile {
            string audioProfile;
        };

        using IDeviceSettingsAudioMS12AudioProfileIterator = RPC::IIteratorType<MS12AudioProfile, ID_DEVICESETTINGS_AUDIO_PROFILE_ITERATOR>;

        struct VolumeLeveller {
            uint8_t mode;       /* @text 0 = off, 1 = on, 2 = auto  */
            uint8_t level;      /* @text Value of volume leveller. 0 -10 */
        };

        struct SurroundVirtualizer {
            uint8_t mode;       /* @text 0 = off, 1 = on, 2 = auto  */
            uint8_t boost;      /* @text Value of boost level. 0 -96 */
        };

        enum StereoMode : uint8_t {
            AUDIO_STEREO_UNKNOWN     = 0,
            AUDIO_STEREO_MONO        = 1,
            AUDIO_STEREO_STEREO      = 2,
            AUDIO_STEREO_SURROUND    = 3,
            AUDIO_STEREO_PASSTHROUGH = 4,
            AUDIO_STEREO_DD          = 5,
            AUDIO_STEREO_DDPLUS      = 6,
            AUDIO_STEREO_MAX         = 7
        };

        using IDeviceSettingsStereoModeIterator = RPC::IIteratorType<StereoMode, ID_DEVICESETTINGS_AUDIO_STEREOMODE_ITERATOR>;

        enum DolbyAtmosCapability: uint8_t {
            AUDIO_DOLBY_ATMOS_NOT_SUPPORTED     = 0,
            AUDIO_DOLBY_ATMOS_DDPLUS_STREAM     = 1,
            AUDIO_DOLBY_ATMOS_METADATA          = 2,
            AUDIO_DOLBY_ATMOS_MAX               = 3
        };

        enum SurroundMode: uint8_t {
            AUDIO_SURROUND_MODE_NONE              = 0,
            AUDIO_SURROUND_MODE_DD                = 1,
            AUDIO_SURROUND_MODE_DDPLUS            = 2,
            AUDIO_SURROUND_MODE_MAX               = 4
        };

        enum MS12Feature: uint8_t {
            AUDIO_MS12_FEATURE_DAPV2           = 0,
            AUDIO_MS12_FEATURE_DE              = 1,
            AUDIO_MS12_FEATURE_MAX             = 2
        };

        struct AudioConfig {
           int32_t typeId;
           string  name;
           // IDeviceSettingsAudioCompressionIterator *audioCompressions;
           // IDeviceSettingsAudioEncodingIterator *audioEncodings;
           // IDeviceSettingsStereoModeIterator *stereoModes;
        };

        struct AudioARCStatus { 
            AudioARCType  arcType    /* @brief ARC Type */ ;
            bool          status     /* @brief ARC status */;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_AUDIO_NOTIFICATION };

            // @brief Associated Audio mixing changed
            // @text onAssociatedAudioMixingChanged
            // @param mixing: true or false
            virtual void OnAssociatedAudioMixingChanged(bool mixing) { };

            // @brief Audio Fader balance changed
            // @text onAudioFaderControlChanged
            // @param mixerBalance: applied mixer balance value
            virtual void OnAudioFaderControlChanged(int32_t mixerBalance) { };

            // @brief Primary language for Audio changed
            // @text onAudioPrimaryLanguageChanged
            // @param primaryLanguage: current primary language for audio
            virtual void OnAudioPrimaryLanguageChanged(const string& primaryLanguage) { };

            // @brief Secondary language for Audio changed
            // @text onAudioSecondaryLanguageChanged
            // @param secondaryLanguage: current secondary language for audio
            virtual void OnAudioSecondaryLanguageChanged(const string& secondaryLanguage) { };

            // @brief Audio output hot plug event
            // @text onAudioOutHotPlug
            // @param portType: Type of audio port see AudioPortType
            // @param uiPortNumber: The port number assigned by UI
            // @param isPortConnected: true (connected) or false (not connected)
            virtual void OnAudioOutHotPlug(AudioPortType portType, uint32_t uiPortNumber, bool isPortConnected) { };

            // @brief Audio Output format changed
            // @text onAudioFormatUpdate
            // @param audioFormat: Type of audio format see AudioFormat
            virtual void OnAudioFormatUpdate(AudioFormat audioFormat) { };

            // @brief Dolby Atmos capabilities changed
            // @text onDolbyAtmosCapabilitiesChanged
            // @param atmosCapability: the dolby atmos capability
            // @param status: true (available) or false (not available)
            virtual void OnDolbyAtmosCapabilitiesChanged(DolbyAtmosCapability atmosCapability, bool status) { };

            // @brief Audio port state changed
            // @text onAudioPortStateChanged
            // @param audioPortState: audio port state
            virtual void OnAudioPortStateChanged(AudioPortState audioPortState) { };

            // @brief Audio mode for the respective audio port - raised for every type of port
            // @text onAudioModeEvent
            // @param audioPortType: audio port type see AudioPortType
            // @param audioMode: audio mode - see StereoMode
            virtual void OnAudioModeEvent(AudioPortType audioPortType, StereoMode audioMode) { };

            // @brief Audio mode for the respective audio port - raised for every type of port
            // @text onAudioModeEvent
            // @param audioPortType: audio port type see AudioPortType
            // @param audioMode: audio mode - see StereoMode
            virtual void OnAudioLevelChangedEvent(int32_t audioLevel) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsAudio::INotification* notification )   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsAudio::INotification* notification ) = 0;

        /** Get Audio Port . */
        // @text getAudioPort
        // @brief Get Audio Port handle for the port type and index
        // @param type: Type of Audio port - see AudioPortType
        // @param index: index of the audio port within the list of audio port types
        // @param handle: handle to the port
        virtual Core::hresult GetAudioPort(const AudioPortType type , const int32_t index , int32_t &handle /* @out */) = 0;

        /** Audio Port status. */
        // @text isAudioPortEnabled
        // @brief Audio port enabled or not
        // @param handle: handle to the port
        // @param enabled: enabled (true) or not (false)
        virtual Core::hresult IsAudioPortEnabled(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Enable Audio Port. */
        // @text enableAudioPort
        // @brief Audio port status
        // @param handle: handle to the port
        // @param enable : enable (true) or disable (false)
        virtual Core::hresult EnableAudioPort(const int32_t handle , const bool enable ) = 0;

        /** Get Supported ARC types . */
        // @text getSupportedARCTypes
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param types: Supported types
        virtual Core::hresult GetSupportedARCTypes(const int32_t handle , int32_t &types /* @out */) = 0;

        /** Set SAD */
        // @text setSAD
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param sadList: SAD array 
        // @param count: number of items in sadList (max 15)
        virtual Core::hresult SetSAD(const int32_t handle , const uint8_t sadList[] /* @length:count */, const uint8_t count ) = 0;

        /** Enable ARC */
        // @text enableARC
        // @brief Get Supported ARC types
        // @param handle: handle returned in GetAudioPort()
        // @param arcStatus: ARC param
        virtual Core::hresult EnableARC(const int32_t handle , const AudioARCStatus arcStatus ) = 0;

        /** Get Stereo Mode  . */
        // @text getStereoMode
        // @brief Get Stereo Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult GetStereoMode(const int32_t handle , StereoMode &mode /* @out */) = 0;

        /** Set Stereo Mode  . */
        // @text setStereoMode
        // @brief Set Stereo Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        // @param persist: persist the mode
        virtual Core::hresult SetStereoMode(const int32_t handle , const StereoMode mode , const bool persist ) = 0;

        /** Get Stereo Auto  . */
        // @text getStereoAuto
        // @brief Get Stereo Auto
        // @param handle: handle returned in GetAudioPort()
        // @param mode: auto mode
        virtual Core::hresult GetStereoAuto(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Set Stereo Auto  . */
        // @text setStereoAuto
        // @brief Set Stereo Auto
        // @param handle: handle returned in GetAudioPort()
        // @param mode: auto mode
        // @param persist: persist the setting
        virtual Core::hresult SetStereoAuto(const int32_t handle , const int32_t mode , const bool persist ) = 0;

        /** Set Audio Mute . */
        // @text setAudioMute
        // @brief Set Audio mute
        // @param handle: handle returned in GetAudioPort()
        // @param mute: Mute (true) or Unmute (false)
        virtual Core::hresult SetAudioMute(const int32_t handle , const bool mute ) = 0;

        /** Audio Mute Status. */
        // @text isAudioMuted
        // @brief Audio mute status
        // @param handle: handle returned in GetAudioPort()
        // @param muted: Muted (true) or not (false)
        virtual Core::hresult IsAudioMuted(const int32_t handle , bool &muted /* @out */) = 0;

        /** Set Audio ducking */
        // @text setAudioDucking
        // @brief Set Audio ducking
        // @param handle: handle returned in GetAudioPort()
        // @param duckingType: Audio ducking type
        // @param duckingAction: Audio ducking action
        // @param level : Volume level when audio is ducked. 
        virtual Core::hresult SetAudioDucking(const int32_t handle , const AudioDuckingType duckingType , const AudioDuckingAction duckingAction , const uint8_t level ) = 0;

        /** Set Audio Level */
        // @text setAudioLevel
        // @brief Set Audio Level
        // @param handle: handle returned in GetAudioPort()
        // @param audioLevel: Audio level
        virtual Core::hresult SetAudioLevel(const int32_t handle , const float audioLevel ) = 0;

        /** Get Audio Level */
        // @text GetAudioDucking
        // @brief Get Audio Level
        // @param handle: handle returned in GetAudioPort()
        // @param audioLevel: Audio level
        virtual Core::hresult GetAudioLevel(const int32_t handle , float &audioLevel /* @out */) = 0;

        /** Set Audio Gain */
        // @text setAudioGain
        // @brief Set Audio Gain
        // @param handle: handle returned in GetAudioPort()
        // @param gainLevel: Gain level
        virtual Core::hresult SetAudioGain(const int32_t handle , const float gainLevel ) = 0;

        /** Get Audio Gain */
        // @text getAudioGain
        // @brief Get Audio Gain
        // @param handle: handle returned in GetAudioPort()
        // @param gainLevel: Gain level
        virtual Core::hresult GetAudioGain(const int32_t handle , float &gainLevel /* @out */) = 0;

        /** Get Audio Format */
        // @text getAudioFormat
        // @brief Get Audio Format
        // @param handle: handle returned in GetAudioPort()
        // @param audioFormat: Audio format
        virtual Core::hresult GetAudioFormat(const int32_t handle , AudioFormat &audioFormat /* @out */) = 0;

        /** Get Audio encoding */
        // @text getAudioEncoding
        // @brief Get Audio encoding
        // @param handle: handle returned in GetAudioPort()
        // @param encoding: Audio encoding
        virtual Core::hresult GetAudioEncoding(const int32_t handle , AudioEncoding &encoding /* @out */) = 0;

        /** Get Audio Persistence status . */
        // @text getAudioEnablePersist
        // @brief Get Persistence status
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: Is persistence enabled or not
        // @param portName: portName for which persistence is enabled
        virtual Core::hresult GetAudioEnablePersist(const int32_t handle , bool &enabled /* @out */, string &portName /* @out */) = 0;

        /** Set Audio Persistence status . */
        // @text SetAudioEnablePersist
        // @brief Set Persistence status
        // @param handle: handle returned in GetAudioPort()
        // @param enable :  persistence enable (true) or disable (false)
        // @param portName: portName for which persistence is enabled
        virtual Core::hresult SetAudioEnablePersist(const int32_t handle , const bool enable , const string portName ) = 0;

        /** Audio MS decode Status. */
        // @text isAudioMSDecoded
        // @brief Audio MS decode status
        // @param handle: handle returned in GetAudioPort()
        // @param hasms11Decode: true or false
        virtual Core::hresult IsAudioMSDecoded(const int32_t handle , bool &hasms11Decode /* @out */) = 0;

        /** Audio MS12 decode Status. */
        // @text isAudioMS12Decoded
        // @brief Audio MS12 decode status
        // @param handle: handle returned in GetAudioPort()
        // @param hasms12Decode: true or false
        virtual Core::hresult IsAudioMS12Decoded(const int32_t handle , bool &hasms12Decode /* @out */) = 0;

        /** Get Audio LE config */
        // @text getAudioLEConfig
        // @brief Get Audio LE config
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled) or false (disabled)
        virtual Core::hresult GetAudioLEConfig(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Enable Audio LE config */
        // @text enableAudioLEConfig
        // @brief Audio LE config Enable
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled) or false (disabled)
        virtual Core::hresult EnableAudioLEConfig(const int32_t handle , const bool enable ) = 0;

        /** Set Audio Delay  */
        // @text setAudioDelay
        // @brief Set Audio Delay
        // @param handle: handle returned in GetAudioPort()
        // @param audioDelay: Audio delay in millisecs
        virtual Core::hresult SetAudioDelay(const int32_t handle , const uint32_t audioDelay ) = 0;

        /** Get Audio Delay  */
        // @text getAudioDelay
        // @brief Get Audio Delay
        // @param handle: handle returned in GetAudioPort()
        // @param audioDelay: Audio delay in millisecs
        virtual Core::hresult GetAudioDelay(const int32_t handle , uint32_t &audioDelay /* @out */) = 0;

        /** Set Audio Delay Offset */
        // @text setAudioDelayOffset
        // @brief Set Audio Delay offset
        // @param handle: handle returned in GetAudioPort()
        // @param delayOffset: delay offset in millisecs
        virtual Core::hresult SetAudioDelayOffset(const int32_t handle , const uint32_t delayOffset ) = 0;

        /** Get Audio Delay Offset */
        // @text getAudioDelayOffset
        // @brief Get Audio Delay offset
        // @param handle: handle returned in GetAudioPort()
        // @param delayOffset: delay offset in millisecs
        virtual Core::hresult GetAudioDelayOffset(const int32_t handle , uint32_t &delayOffset /* @out */) = 0;

        /** Get Audio Sink device Atmos capability */
        // @text getAudioSinkDeviceAtmosCapability
        // @brief Get Audio Sink device Atmos capability
        // @param handle: handle returned in GetAudioPort()
        // @param atmosCapability: Atmos capability
        virtual Core::hresult GetAudioSinkDeviceAtmosCapability(const int32_t handle , DolbyAtmosCapability &atmosCapability /* @out */) = 0;

        /** Set Audio Atmos output mode */
        // @text setAudioAtmosOutputMode
        // @brief Set Audio Atmos output mode
        // @param handle: handle returned in GetAudioPort()
        // @param enable: Enable audio atmos output mode
        virtual Core::hresult SetAudioAtmosOutputMode(const int32_t handle , const bool enable ) = 0;

        /** Set Audio Compression */
        // @text setAudioCompression
        // @brief Set Audio Compression
        // @param handle: handle returned in GetAudioPort()
        // @param compressionLevel: compression level
        virtual Core::hresult SetAudioCompression(const int32_t handle , const int32_t compressionLevel ) = 0;

        /** Get Audio Compression */
        // @text getAudioCompression
        // @brief Get Audio Compression
        // @param handle: handle returned in GetAudioPort()
        // @param compressionLevel: compression level
        virtual Core::hresult GetAudioCompression(const int32_t handle , int32_t &compressionLevel /* @out */) = 0;

        /** Set Audio Dialog Enhancement */
        // @text setAudioDialogEnhancement
        // @brief Set Audio Dialog Enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param level: Enhancement level
        virtual Core::hresult SetAudioDialogEnhancement(const int32_t handle , const int32_t level ) = 0;

        /** Get Audio Dialog Enhancement */
        // @text getAudioDialogEnhancement
        // @brief Get Audio Dialog Enhancement
        // @param handle: handle returned in GetAudioPort()
        // @param level: Enhancement level
        virtual Core::hresult GetAudioDialogEnhancement(const int32_t handle , int32_t &level /* @out */) = 0;

        /** Set Audio Dolby Volume mode  */
        // @text setAudioDolbyVolumeMode
        // @brief Set Audio Dolby volume mode
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable dolby volume mode) or false (disable dolby volume mode)
        virtual Core::hresult SetAudioDolbyVolumeMode(const int32_t handle , const bool enable ) = 0;

        /** Get Audio Dolby Volume mode  */
        // @text getAudioDolbyVolumeMode
        // @brief Get Audio Dolby volume mode
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (enabled dolby volume mode) or false (disabled dolby volume mode)
        virtual Core::hresult GetAudioDolbyVolumeMode(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Set Audio Intelligent equalizer mode  */
        // @text setAudioIntelligentEqualizerMode
        // @brief Set Audio Intelligent equalizer mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult SetAudioIntelligentEqualizerMode(const int32_t handle , const int32_t mode ) = 0;

        /** Get Audio Intelligent equalizer mode  */
        // @text getAudioIntelligentEqualizerMode
        // @brief Get Audio Intelligent equalizer mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: mode
        virtual Core::hresult GetAudioIntelligentEqualizerMode(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Set Audio Volume leveller  */
        // @text setAudioVolumeLeveller
        // @brief Set Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        // @param volumeLeveller: volume leveller (mode and a level)
        virtual Core::hresult SetAudioVolumeLeveller(const int32_t handle , const VolumeLeveller volumeLeveller ) = 0;

        /** Get Audio Volume leveller  */
        // @text getAudioVolumeLeveller
        // @brief Get Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        // @param volumeLeveller: volume leveller (mode and a level)
        virtual Core::hresult GetAudioVolumeLeveller(const int32_t handle , VolumeLeveller &volumeLeveller /* @out */) = 0;

        /** Set Audio Bass Enhancer  */
        // @text setAudioBassEnhancer
        // @brief Set Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param boost: boost for bass
        virtual Core::hresult SetAudioBassEnhancer(const int32_t handle , const int32_t boost ) = 0;

        /** Get Audio Bass Enhancer  */
        // @text getAudioBassEnhancer
        // @brief Get Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param boost: boost for bass
        virtual Core::hresult GetAudioBassEnhancer(const int32_t handle , int32_t &boost /* @out */) = 0;

        /** Enable Audio Surroud Decoder  */
        // @text enableAudioSurroudDecoder
        // @brief Enable Audio Surroud Decoder
        // @param handle: handle returned in GetAudioPort()
         // @param enable: true (surround decoder enabled) or false (surround decoder disabled)
        virtual Core::hresult EnableAudioSurroudDecoder(const int32_t handle , const bool enable ) = 0;

        /** Is Audio Surroud Decoder enabled? */
        // @text isAudioSurroudDecoderEnabled
        // @brief Audio Surroud Decoder enabled or not
        // @param handle: handle returned in GetAudioPort()
        // @param enabled: true (surround decoder enabled) or false (surround decoder disabled)
        virtual Core::hresult IsAudioSurroudDecoderEnabled(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Set Audio DRC mode  */
        // @text setAudioDRCMode
        // @brief Set Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param drcMode: mode
        virtual Core::hresult SetAudioDRCMode(const int32_t handle , const int32_t drcMode ) = 0;

         /** Get Audio DRC mode  */
        // @text getAudioDRCMode
        // @brief Get Audio Bass Enhancer
        // @param handle: handle returned in GetAudioPort()
        // @param drcMode: mode
        virtual Core::hresult GetAudioDRCMode(const int32_t handle , int32_t &drcMode /* @out */) = 0;

        /** Set Audio Surroud Virtualizer  */
        // @text setAudioSurroudVirtualizer
        // @brief Set Audio Surroud Virtualizer
        // @param handle: handle returned in GetAudioPort()
        // @param surroundVirtualizer: virtualizer
        virtual Core::hresult SetAudioSurroudVirtualizer(const int32_t handle , const SurroundVirtualizer surroundVirtualizer ) = 0;

        /** Get Audio Surroud Virtualizer  */
        // @text getAudioSurroudVirtualizer
        // @brief Get Audio Surroud Virtualizer
        // @param handle: handle returned in GetAudioPort()
        // @param surroundVirtualizer: virtualizer
        virtual Core::hresult GetAudioSurroudVirtualizer(const int32_t handle , SurroundVirtualizer &surroundVirtualizer /* @out */) = 0;

        /** Set Audio MI Steering   */
        // @text setAudioMISteering
        // @brief Set Audio MI Steering
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable steering) or false (disable steering)
        virtual Core::hresult SetAudioMISteering(const int32_t handle , const bool enable ) = 0;

        /** Get Audio MI Steering   */
        // @text getAudioMISteering
        // @brief Get Audio MI Steering
        // @param handle: handle returned in GetAudioPort()
        // @param enable: true (enable steering) or false (disable steering)
        virtual Core::hresult GetAudioMISteering(const int32_t handle , bool &enable /* @out */) = 0;

        /** Set Audio Graphic Equalizer Mode    */
        // @text setAudioGraphicEqualizerMode
        // @brief Set Audio Graphic Equalizer Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: Equalizer mode
        virtual Core::hresult SetAudioGraphicEqualizerMode(const int32_t handle , const int32_t mode ) = 0;

        /** Get Audio Graphic Equalizer Mode    */
        // @text getAudioGraphicEqualizerMode
        // @brief Get Audio Graphic Equalizer Mode
        // @param handle: handle returned in GetAudioPort()
        // @param mode: Equalizer mode
        virtual Core::hresult GetAudioGraphicEqualizerMode(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Get Audio MS12 profile list    */
        // @text getAudioMS12ProfileList
        // @brief Get Audio MS12 profile list
        // @param handle: handle returned in GetAudioPort()
        // @param ms12ProfileList: MS12 profile list iterator
        virtual Core::hresult GetAudioMS12ProfileList(const int32_t handle , IDeviceSettingsAudioMS12AudioProfileIterator*& ms12ProfileList /* @out */) const = 0;

        /** Get Audio MS12 profile    */
        // @text getAudioMS12Profile
        // @brief Get Audio MS12 profile
        // @param handle: handle returned in GetAudioPort()
        // @param profile: Name of the profile
        virtual Core::hresult GetAudioMS12Profile(const int32_t handle , string &profile /* @out */) = 0;

        /** Set Audio MS12 profile    */
        // @text setAudioMS12Profile
        // @brief Set Audio MS12 profile
        // @param handle: handle returned in GetAudioPort()
        // @param profile: Name of the profile
        virtual Core::hresult SetAudioMS12Profile(const int32_t handle , const string profile ) = 0;

        /** Set Audio Mixer Levels     */
        // @text setAudioMixerLevels
        // @brief Set Audio Mixer levels
        // @param handle: handle returned in GetAudioPort()
        // @param audioInput: AudioInput 
        // @param volume: Volume level
        virtual Core::hresult SetAudioMixerLevels(const int32_t handle , const AudioInput audioInput , const int32_t volume ) = 0;


        /** Set Associated Audio Mixing values     */
        // @text setAssociatedAudioMixing
        // @brief Set Associated Audio Mixing values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixing: true or false
        virtual Core::hresult SetAssociatedAudioMixing(const int32_t handle , const bool mixing ) = 0;

        /** Get Associated Audio Mixing values     */
        // @text getAssociatedAudioMixing
        // @brief Get Associated Audio Mixing values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixing: true or false
        virtual Core::hresult GetAssociatedAudioMixing(const int32_t handle , bool &mixing /* @out */) = 0;

        /** Set Audio Fader control values     */
        // @text setAudioFaderControl
        // @brief Set Audio Fader control values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixerBalance: Mixer balance for fader control
        virtual Core::hresult SetAudioFaderControl(const int32_t handle , const int32_t mixerBalance ) = 0;

        /** Get Audio Fader control values     */
        // @text getAudioFaderControl
        // @brief Get Audio Fader control values 
        // @param handle: handle returned in GetAudioPort()
        // @param mixerBalance: Mixer balance for fader control
        virtual Core::hresult GetAudioFaderControl(const int32_t handle , int32_t &mixerBalance /* @out */) = 0;

        /** Set Primary Audio language     */
        // @text setAudioPrimaryLanguage
        // @brief Set Primary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param primaryAudioLanguage: Primary audio language
        virtual Core::hresult SetAudioPrimaryLanguage(const int32_t handle , const string primaryAudioLanguage ) = 0;

        /** Get Primary Audio language     */
        // @text getAudioPrimaryLanguage
        // @brief Get Primary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param primaryAudioLanguage: Primary audio language
        virtual Core::hresult GetAudioPrimaryLanguage(const int32_t handle , string &primaryAudioLanguage /* @out */) = 0;

        /** Set Secondary Audio language     */
        // @text setAudioSecondaryLanguage
        // @brief Set Secondary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param secondaryAudioLanguage: Secondary audio language
        virtual Core::hresult SetAudioSecondaryLanguage(const int32_t handle , const string secondaryAudioLanguage ) = 0;

        /** Get Primary Audio language     */
        // @text getAudioSecondaryLanguage
        // @brief Get Secondary Audio language
        // @param handle: handle returned in GetAudioPort()
        // @param secondaryAudioLanguage: Secondary audio language
        virtual Core::hresult GetAudioSecondaryLanguage(const int32_t handle , string &secondaryAudioLanguage /* @out */) = 0;

        /** Get Audio Capabilities     */
        // @text getAudioCapabilities
        // @brief Get Audio capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param capabilities: Capabilities
        virtual Core::hresult GetAudioCapabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /** Get Audio MS12 Capabilities     */
        // @text getAudioMS12Capabilities
        // @brief Get Audio MS12 capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param capabilities: Capabilities
        virtual Core::hresult GetAudioMS12Capabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /** Set Audio MS12 Settings override     */
        // @text setAudioMS12SettingsOverride
        // @brief Get Audio MS12 capabilites
        // @param handle: handle returned in GetAudioPort()
        // @param profileName: Name of the profile
        // @param profileSettingsName: Name of the profile setting 
        // @param profileSettingValue : value of the profile setting 
        // @param profileState: ADD or REMOVE
        virtual Core::hresult SetAudioMS12SettingsOverride(const int32_t handle , const string profileName , const string profileSettingsName , const string profileSettingValue , const string profileState  ) = 0;

        /** Is Audio output connected?    */
        // @text isAudioOutputConnected
        // @brief Is Audio output connected?
        // @param handle: handle returned in GetAudioPort()
        // @param isConnected: connected (true) or not (false)
        virtual Core::hresult IsAudioOutputConnected(const int32_t handle , bool &isConnected /* @out */) = 0;


        /** Reset Audio Dialog enhancement    */
        // @text resetAudioDialogEnhancement
        // @brief Reset Audio Dialog enhancement
        // @param handle: handle returned in GetAudioPort()
        virtual Core::hresult ResetAudioDialogEnhancement(const int32_t handle ) = 0;

        /** Reset Audio Bass enhancement    */
        // @text resetAudioBassEnhancer
        // @brief Reset Audio Bass enhancement
        // @param handle: handle returned in GetAudioPort()
        virtual Core::hresult ResetAudioBassEnhancer(const int32_t handle ) = 0;

        /** Reset Audio Surround virtualizer   */
        // @text resetAudioSurroundVirtualizer
        // @brief Reset Audio Surround virtualizer
        // @param handle: handle returned in GetAudioPort()
        virtual Core::hresult ResetAudioSurroundVirtualizer(const int32_t handle ) = 0;

        /** Reset Audio Volume leveller    */
        // @text resetAudioVolumeLeveller
        // @brief Reset Audio Volume leveller
        // @param handle: handle returned in GetAudioPort()
        virtual Core::hresult ResetAudioVolumeLeveller(const int32_t handle ) = 0;

        /** Get Audio HDMI ARC Port ID    */
        // @text getAudioHDMIARCPortId
        // @brief Get Audio HDMI ARC Port ID
        // @param handle: handle returned in GetAudioPort()
        // @param portId: Port Id
        virtual Core::hresult GetAudioHDMIARCPortId(const int32_t handle , int32_t &portId /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
