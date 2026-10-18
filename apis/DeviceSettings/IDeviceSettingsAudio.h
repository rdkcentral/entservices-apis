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
#include "IDeviceSettings.h"

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
            AUDIO_CAPS_NONE                      = 0x00,
            AUDIO_CAPS_ATMOS                     = 0x01,
            AUDIO_CAPS_DOLBY_DIGITAL             = 0x02,
            AUDIO_CAPS_DOLBY_DIGITAL_PLUS        = 0x04,
            AUDIO_CAPS_DIGITAL_AUDIO_DELIVERY    = 0x08,
            AUDIO_CAPS_DIGITAL_AUDIO_PROCESS_V2  = 0x10,
            AUDIO_CAPS_MS12                      = 0x20,
            AUDIO_CAPS_MS12_V2                   = 0x40,
            AUDIO_CAPS_INVALID                   = 0x80,
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
            AUDIO_MS12_CAPABILITIES_NONE                    = 0x000,
            AUDIO_MS12_CAPABILITIES_DOLBYVOLUME             = 0x001,
            AUDIO_MS12_CAPABILITIES_INTELLIGENT_EQUALIZER   = 0x002,
            AUDIO_MS12_CAPABILITIES_DIALOG_ENHANCER         = 0x004,
            AUDIO_MS12_CAPABILITIES_VOLUME_LEVELLER         = 0x008,
            AUDIO_MS12_CAPABILITIES_BASE_ENHANCER           = 0x010,
            AUDIO_MS12_CAPABILITIES_SURROUND_DECODER        = 0x020,
            AUDIO_MS12_CAPABILITIES_DRC_MODE                = 0x040,
            AUDIO_MS12_CAPABILITIES_SURROUND_VIRTUALIZER    = 0x080,
            AUDIO_MS12_CAPABILITIES_MI_STEERING             = 0x100,
            AUDIO_MS12_CAPABILITIES_GRAPHIC_EQUALIZER       = 0x200,
            AUDIO_MS12_CAPABILITIES_LE_CONFIG               = 0x400,
            AUDIO_MS12_CAPABILITIES_INVALID                 = 0x40000000
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
            AUDIO_SURROUND_MODE_MAX               = 3
        };

        enum MS12Feature: uint8_t {
            AUDIO_MS12_FEATURE_DAPV2           = 0,
            AUDIO_MS12_FEATURE_DE              = 1,
            AUDIO_MS12_FEATURE_MAX             = 2
        };

        enum MS12ProfileState : uint8_t {
            AUDIO_MS12_PROFILE_STATE_ADD       = 0, /* @text ADD */
            AUDIO_MS12_PROFILE_STATE_REMOVE    = 1, /* @text REMOVE */
            AUDIO_MS12_PROFILE_STATE_MAX       = 2
        };

        struct AudioPortConfigInfo {
            AudioPortType audioPortType;
            int32_t audioPortIndex;
            int32_t connectedVideoPortType;
            int32_t connectedVideoPortIndex;
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
            // @details This event is triggered when the associated audio mixing state changes.
            // @param mixing: true or false
            // @example mixing: true
            virtual void OnAssociatedAudioMixingChanged(bool mixing) { };

            // @brief Audio Fader balance changed
            // @text onAudioFaderControlChanged
            // @details This event is triggered when the audio fader balance changes.
            // @param mixerBalance: applied mixer balance value
            // @example mixerBalance: 50
            virtual void OnAudioFaderControlChanged(int32_t mixerBalance) { };

            // @brief Primary language for Audio changed
            // @text onAudioPrimaryLanguageChanged
            // @details This event is triggered when the primary language for audio changes.
            // @param primaryLanguage: current primary language for audio
            // @example primaryLanguage: "en"
            virtual void OnAudioPrimaryLanguageChanged(const string& primaryLanguage) { };

            // @brief Secondary language for Audio changed
            // @text onAudioSecondaryLanguageChanged
            // @details This event is triggered when the secondary language for audio changes.
            // @param secondaryLanguage: current secondary language for audio
            // @example secondaryLanguage: "fr"
            virtual void OnAudioSecondaryLanguageChanged(const string& secondaryLanguage) { };

            // @brief Audio output hot plug event
            // @text onAudioOutHotPlug
            // @details This event is triggered when an audio output port is hot plugged.
            // @param portType: Type of audio port see AudioPortType
            // @example portType: AudioPortType::HDMI
            // @param uiPortNumber: The port number assigned by UI
            // @example uiPortNumber: 1
            // @param isPortConnected: true (connected) or false (not connected)
            // @example isPortConnected: true
            virtual void OnAudioOutHotPlug(AudioPortType portType, uint32_t uiPortNumber, bool isPortConnected) { };

            // @brief Audio Output format changed
            // @text onAudioFormatUpdate
            // @details This event is triggered when the audio output format changes.
            // @param audioFormat: Type of audio format see AudioFormat
            // @example audioFormat: PCM
            virtual void OnAudioFormatUpdate(AudioFormat audioFormat) { };

            // @brief Dolby Atmos capabilities changed
            // @text onDolbyAtmosCapabilitiesChanged
            // @details This event is triggered when the Dolby Atmos capabilities change.
            // @param atmosCapability: the dolby atmos capability
            // @example atmosCapability: ENABLED
            // @param status: true (available) or false (not available)
            // @example status: true
            virtual void OnDolbyAtmosCapabilitiesChanged(DolbyAtmosCapability atmosCapability, bool status) { };

            // @brief Audio port state changed
            // @text onAudioPortStateChanged
            // @details This event is triggered when the audio port state changes.
            // @param audioPortState: audio port state
            // @example audioPortState: CONNECTED
            virtual void OnAudioPortStateChanged(AudioPortState audioPortState) { };

            // @brief Audio mode for the respective audio port - raised for every type of port
            // @text onAudioModeEvent
            // @details This event is triggered when the audio mode for a specific audio port changes.
            // @param audioPortType: audio port type see AudioPortType
            // @example audioPortType: AUDIO_PORT_TYPE_HDMI
            // @param audioMode: audio mode - see StereoMode
            // @example audioMode: AUDIO_STEREO_STEREO
            virtual void OnAudioModeEvent(AudioPortType audioPortType, StereoMode audioMode) { };

            // @brief Audio level changed
            // @text onAudioLevelChanged
            // @details This event is triggered when the audio level changes.
            // @param audioLevel: Current audio level
            // @example audioLevel: 75
            virtual void OnAudioLevelChanged(int32_t audioLevel) { };
        };

        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsAudio::INotification* notification )   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsAudio::INotification* notification ) = 0;

        /** Get Audio Port . */
        // @text getAudioPort
        // @brief Get Audio Port handle for the port type and index
        // @details This method retrieves the handle for a specific audio port based on its type and index.
        // @param type: Type of Audio port - see AudioPortType
        // @example type: HDMI
        // @param index: index of the audio port within the list of audio port types
        // @example index: 0
        // @param handle: handle to the port
        // @example handle: 1
        // @retval Core::ERROR_NONE: Audio port handle was retrieved successfully
        virtual Core::hresult GetAudioPort(const AudioPortType type , const int32_t index , int32_t &handle /* @out */) = 0;

        /** Audio Port status. */
        // @text isAudioPortEnabled
        // @brief Audio port enabled or not
        // @details This method checks whether the specified audio port is enabled.
        // @param handle: handle to the port
        // @example handle: 1
        // @param enabled: enabled (true) or not (false)
        // @example enabled: true
        // @retval Core::ERROR_NONE: Audio port enabled state was retrieved successfully
        virtual Core::hresult IsAudioPortEnabled(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Enable Audio Port. */
        // @text enableAudioPort
        // @brief Audio port status
        // @details This method enables or disables the specified audio port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param enable : enable (true) or disable (false)
        // @example enable: true
        // @retval Core::ERROR_NONE: Audio port state was updated successfully
        virtual Core::hresult EnableAudioPort(const int32_t handle , const bool enable ) = 0;

        /** Get Supported ARC types . */
        // @text getSupportedARCTypes
        // @brief Get Supported ARC types
        // @details This method retrieves the supported ARC types for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param types: Supported types
        // @example types: 3
        // @retval Core::ERROR_NONE: Supported ARC types were retrieved successfully
        virtual Core::hresult GetSupportedARCTypes(const int32_t handle , int32_t &types /* @out */) = 0;

        /** Set SAD */
        // @text setSAD
        // @brief Get Supported ARC types
        // @details This method sets the SAD (Short Audio Descriptor) list for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param sadList: SAD array 
        // @example sadList: [1, 2, 3]
        // @param count: number of items in sadList (max 15)
        // @example count: 3
        // @retval Core::ERROR_NONE: Short Audio Descriptor list was set successfully
        virtual Core::hresult SetSAD(const int32_t handle , const uint8_t sadList[] /* @length:count */, const uint8_t count ) = 0;

        /** Enable ARC */
        // @text enableARC
        // @brief Get Supported ARC types
        // @details This method enables or disables the ARC (Audio Return Channel) for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param arcStatus: ARC param
        // @example arcStatus: {"arcType": AUDIO_ARCTYPE_ARC, "status": true}
        // @retval Core::ERROR_NONE: ARC state was updated successfully
        virtual Core::hresult EnableARC(const int32_t handle , const AudioARCStatus arcStatus ) = 0;

        /** Get Stereo Mode  . */
        // @text getStereoMode
        // @brief Get Stereo Mode
        // @details Retrieves the persisted or effective stereo mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: mode
        // @example mode: AUDIO_STEREO_STEREO
        // @param persist: get the persisted mode (true) or effective runtime mode (false)
        // @example persist: false
        // @retval Core::ERROR_NONE: Stereo mode was retrieved successfully
        virtual Core::hresult GetStereoMode(const int32_t handle , StereoMode &mode /* @out */, const bool persist) = 0;

        /** Set Stereo Mode  . */
        // @text setStereoMode
        // @brief Set Stereo Mode
        // @details Sets the persisted or effective stereo mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: mode
        // @example mode: AUDIO_STEREO_STEREO
        // @param persist: persist the mode
        // @example persist: true
        // @retval Core::ERROR_NONE: Stereo mode was set successfully
        virtual Core::hresult SetStereoMode(const int32_t handle , const StereoMode mode , const bool persist ) = 0;

        /** Get Stereo Auto  . */
        // @text getStereoAuto
        // @brief Get Stereo Auto
        // @details Retrieves the automatic stereo mode setting for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: auto mode
        // @example mode: 1
        // @retval Core::ERROR_NONE: Automatic stereo mode was retrieved successfully
        virtual Core::hresult GetStereoAuto(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Set Stereo Auto  . */
        // @text setStereoAuto
        // @brief Set Stereo Auto
        // @details Sets the automatic stereo mode setting for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: auto mode
        // @example mode: 1
        // @param persist: persist the setting
        // @example persist: true
        // @retval Core::ERROR_NONE: Automatic stereo mode was set successfully
        virtual Core::hresult SetStereoAuto(const int32_t handle , const int32_t mode , const bool persist ) = 0;

        /** Set Audio Mute . */
        // @text setAudioMute
        // @brief Set Audio mute
        // @details Mutes or unmutes audio on the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mute: Mute (true) or Unmute (false)
        // @example mute: true
        // @retval Core::ERROR_NONE: Audio mute state was set successfully
        virtual Core::hresult SetAudioMute(const int32_t handle , const bool mute ) = 0;

        /** Audio Mute Status. */
        // @text isAudioMuted
        // @brief Audio mute status
        // @details Retrieves whether audio is muted on the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param muted: Muted (true) or not (false)
        // @example muted: true
        // @retval Core::ERROR_NONE: Audio mute state was retrieved successfully
        virtual Core::hresult IsAudioMuted(const int32_t handle , bool &muted /* @out */) = 0;

        /** Set Audio ducking */
        // @text setAudioDucking
        // @brief Set Audio ducking
        // @details Configures audio ducking behavior for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param duckingType: Audio ducking type
        // @example duckingType: AUDIO_DUCKINGTYPE_ABSOLUTE
        // @param duckingAction: Audio ducking action
        // @example duckingAction: AUDIO_DUCKINGACTION_START
        // @param level : Volume level when audio is ducked. 
        // @example level: 50
        // @retval Core::ERROR_NONE: Audio ducking was configured successfully
        virtual Core::hresult SetAudioDucking(const int32_t handle , const AudioDuckingType duckingType , const AudioDuckingAction duckingAction , const uint8_t level ) = 0;

        /** Set Audio Level */
        // @text setAudioLevel
        // @brief Set Audio Level
        // @details Sets the audio output level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioLevel: Audio level
        // @example audioLevel: 50.0
        // @retval Core::ERROR_NONE: Audio level was set successfully
        virtual Core::hresult SetAudioLevel(const int32_t handle , const float audioLevel ) = 0;

        /** Get Audio Level */
        // @text getAudioLevel
        // @brief Get Audio Level
        // @details Retrieves the current audio output level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioLevel: Audio level
        // @example audioLevel: 50.0
        // @retval Core::ERROR_NONE: Audio level was retrieved successfully
        virtual Core::hresult GetAudioLevel(const int32_t handle , float &audioLevel /* @out */) = 0;

        /** Set Audio Gain */
        // @text setAudioGain
        // @brief Set Audio Gain
        // @details Sets the audio gain for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param gainLevel: Gain level
        // @example gainLevel: 0.0
        // @retval Core::ERROR_NONE: Audio gain was set successfully
        virtual Core::hresult SetAudioGain(const int32_t handle , const float gainLevel ) = 0;

        /** Get Audio Gain */
        // @text getAudioGain
        // @brief Get Audio Gain
        // @details Retrieves the audio gain for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param gainLevel: Gain level
        // @example gainLevel: 0.0
        // @retval Core::ERROR_NONE: Audio gain was retrieved successfully
        virtual Core::hresult GetAudioGain(const int32_t handle , float &gainLevel /* @out */) = 0;

        /** Get Audio Format */
        // @text getAudioFormat
        // @brief Get Audio Format
        // @details Retrieves the current audio format for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioFormat: Audio format
        // @example audioFormat: AUDIO_FORMAT_PCM
        // @retval Core::ERROR_NONE: Audio format was retrieved successfully
        virtual Core::hresult GetAudioFormat(const int32_t handle , AudioFormat &audioFormat /* @out */) = 0;

        /** Get Audio encoding */
        // @text getAudioEncoding
        // @brief Get Audio encoding
        // @details Retrieves the current audio encoding for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param encoding: Audio encoding
        // @example encoding: AUDIO_ENCODING_PCM
        // @retval Core::ERROR_NONE: Audio encoding was retrieved successfully
        virtual Core::hresult GetAudioEncoding(const int32_t handle , AudioEncoding &encoding /* @out */) = 0;

        /** Get Audio Persistence status . */
        // @text getAudioEnablePersist
        // @brief Get Persistence status
        // @details Retrieves the audio persistence setting and associated port name.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enabled: Is persistence enabled or not
        // @example enabled: true
        // @param portName: portName for which persistence is enabled
        // @example portName: "HDMI0"
        // @retval Core::ERROR_NONE: Audio persistence settings were retrieved successfully
        virtual Core::hresult GetAudioEnablePersist(const int32_t handle , bool &enabled /* @out */, string &portName /* @out */) = 0;

        /** Set Audio Persistence status . */
        // @text setAudioEnablePersist
        // @brief Set Persistence status
        // @details Enables or disables audio persistence for the specified port name.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable :  persistence enable (true) or disable (false)
        // @example enable: true
        // @param portName: portName for which persistence is enabled
        // @example portName: "HDMI0"
        // @retval Core::ERROR_NONE: Audio persistence settings were updated successfully
        virtual Core::hresult SetAudioEnablePersist(const int32_t handle , const bool enable , const string& portName ) = 0;

        /** Audio MS decode Status. */
        // @text isAudioMSDecoded
        // @brief Audio MS decode status
        // @details Checks whether MS11 audio decoding is active on the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param hasms11Decode: true or false
        // @example hasms11Decode: true
        // @retval Core::ERROR_NONE: MS11 decode status was retrieved successfully
        virtual Core::hresult IsAudioMSDecoded(const int32_t handle , bool &hasms11Decode /* @out */) = 0;

        /** Audio MS12 decode Status. */
        // @text isAudioMS12Decoded
        // @brief Audio MS12 decode status
        // @details Checks whether MS12 audio decoding is active on the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param hasms12Decode: true or false
        // @example hasms12Decode: true
        // @retval Core::ERROR_NONE: MS12 decode status was retrieved successfully
        virtual Core::hresult IsAudioMS12Decoded(const int32_t handle , bool &hasms12Decode /* @out */) = 0;

        /** Get Audio LE config */
        // @text getAudioLEConfig
        // @brief Get Audio LE config
        // @details Retrieves whether the audio low-energy configuration is enabled for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enabled: true (enabled) or false (disabled)
        // @example enabled: true
        // @retval Core::ERROR_NONE: Audio low-energy configuration was retrieved successfully
        virtual Core::hresult GetAudioLEConfig(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Enable Audio LE config */
        // @text enableAudioLEConfig
        // @brief Audio LE config Enable
        // @details Enables or disables the audio low-energy configuration for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable: true (enabled) or false (disabled)
        // @example enable: true
        // @retval Core::ERROR_NONE: Audio low-energy configuration was updated successfully
        virtual Core::hresult EnableAudioLEConfig(const int32_t handle , const bool enable ) = 0;

        /** Set Audio Delay  */
        // @text setAudioDelay
        // @brief Set Audio Delay
        // @details Sets the audio delay for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioDelay: Audio delay in millisecs
        // @example audioDelay: 120
        // @retval Core::ERROR_NONE: Audio delay was set successfully
        virtual Core::hresult SetAudioDelay(const int32_t handle , const uint32_t audioDelay ) = 0;

        /** Get Audio Delay  */
        // @text getAudioDelay
        // @brief Get Audio Delay
        // @details Retrieves the audio delay configured for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioDelay: Audio delay in millisecs
        // @example audioDelay: 120
        // @retval Core::ERROR_NONE: Audio delay was retrieved successfully
        virtual Core::hresult GetAudioDelay(const int32_t handle , uint32_t &audioDelay /* @out */) = 0;

        /** Set Audio Delay Offset */
        // @text setAudioDelayOffset
        // @brief Set Audio Delay offset
        // @details Sets the audio delay offset for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param delayOffset: delay offset in millisecs
        // @example delayOffset: 20
        // @retval Core::ERROR_NONE: Audio delay offset was set successfully
        virtual Core::hresult SetAudioDelayOffset(const int32_t handle , const uint32_t delayOffset ) = 0;

        /** Get Audio Delay Offset */
        // @text getAudioDelayOffset
        // @brief Get Audio Delay offset
        // @details Retrieves the audio delay offset configured for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param delayOffset: delay offset in millisecs
        // @example delayOffset: 20
        // @retval Core::ERROR_NONE: Audio delay offset was retrieved successfully
        virtual Core::hresult GetAudioDelayOffset(const int32_t handle , uint32_t &delayOffset /* @out */) = 0;

        /** Get Audio Sink device Atmos capability */
        // @text getAudioSinkDeviceAtmosCapability
        // @brief Get Audio Sink device Atmos capability
        // @details Retrieves the Dolby Atmos capability reported by the audio sink connected to the specified port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param atmosCapability: Atmos capability
        // @example atmosCapability: AUDIO_DOLBY_ATMOS_METADATA
        // @retval Core::ERROR_NONE: Audio sink Dolby Atmos capability was retrieved successfully
        virtual Core::hresult GetAudioSinkDeviceAtmosCapability(const int32_t handle , DolbyAtmosCapability &atmosCapability /* @out */) = 0;

        /** Set Audio Atmos output mode */
        // @text setAudioAtmosOutputMode
        // @brief Set Audio Atmos output mode
        // @details Enables or disables Dolby Atmos output for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable: Enable audio atmos output mode
        // @example enable: true
        // @retval Core::ERROR_NONE: Dolby Atmos output mode was updated successfully
        virtual Core::hresult SetAudioAtmosOutputMode(const int32_t handle , const bool enable ) = 0;

        /** Set Audio Compression */
        // @text setAudioCompression
        // @brief Set Audio Compression
        // @details Sets the audio compression level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param compressionLevel: compression level
        // @example compressionLevel: 2
        // @retval Core::ERROR_NONE: Audio compression level was set successfully
        virtual Core::hresult SetAudioCompression(const int32_t handle , const int32_t compressionLevel ) = 0;

        /** Get Audio Compression */
        // @text getAudioCompression
        // @brief Get Audio Compression
        // @details Retrieves the audio compression level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param compressionLevel: compression level
        // @example compressionLevel: 2
        // @retval Core::ERROR_NONE: Audio compression level was retrieved successfully
        virtual Core::hresult GetAudioCompression(const int32_t handle , int32_t &compressionLevel /* @out */) = 0;

        /** Set Audio Dialog Enhancement */
        // @text setAudioDialogEnhancement
        // @brief Set Audio Dialog Enhancement
        // @details Sets the dialog enhancement level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param level: Enhancement level
        // @example level: 2
        // @retval Core::ERROR_NONE: Audio dialog enhancement level was set successfully
        virtual Core::hresult SetAudioDialogEnhancement(const int32_t handle , const int32_t level ) = 0;

        /** Get Audio Dialog Enhancement */
        // @text getAudioDialogEnhancement
        // @brief Get Audio Dialog Enhancement
        // @details Retrieves the dialog enhancement level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param level: Enhancement level
        // @example level: 2
        // @retval Core::ERROR_NONE: Audio dialog enhancement level was retrieved successfully
        virtual Core::hresult GetAudioDialogEnhancement(const int32_t handle , int32_t &level /* @out */) = 0;

        /** Set Audio Dolby Volume mode  */
        // @text setAudioDolbyVolumeMode
        // @brief Set Audio Dolby volume mode
        // @details Enables or disables Dolby Volume processing for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable: true (enable dolby volume mode) or false (disable dolby volume mode)
        // @example enable: true
        // @retval Core::ERROR_NONE: Dolby Volume mode was updated successfully
        virtual Core::hresult SetAudioDolbyVolumeMode(const int32_t handle , const bool enable ) = 0;

        /** Get Audio Dolby Volume mode  */
        // @text getAudioDolbyVolumeMode
        // @brief Get Audio Dolby volume mode
        // @details Retrieves whether Dolby Volume processing is enabled for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enabled: true (enabled dolby volume mode) or false (disabled dolby volume mode)
        // @example enabled: true
        // @retval Core::ERROR_NONE: Dolby Volume mode was retrieved successfully
        virtual Core::hresult GetAudioDolbyVolumeMode(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Set Audio Intelligent equalizer mode  */
        // @text setAudioIntelligentEqualizerMode
        // @brief Set Audio Intelligent equalizer mode
        // @details Sets the intelligent equalizer mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: mode
        // @example mode: 1
        // @retval Core::ERROR_NONE: Intelligent equalizer mode was set successfully
        virtual Core::hresult SetAudioIntelligentEqualizerMode(const int32_t handle , const int32_t mode ) = 0;

        /** Get Audio Intelligent equalizer mode  */
        // @text getAudioIntelligentEqualizerMode
        // @brief Get Audio Intelligent equalizer mode
        // @details Retrieves the intelligent equalizer mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: mode
        // @example mode: 1
        // @retval Core::ERROR_NONE: Intelligent equalizer mode was retrieved successfully
        virtual Core::hresult GetAudioIntelligentEqualizerMode(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Set Audio Volume leveller  */
        // @text setAudioVolumeLeveller
        // @brief Set Audio Volume leveller
        // @details Configures the volume leveller mode and level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param volumeLeveller: volume leveller (mode and a level)
        // @example volumeLeveller: {"mode": 1, "level": 5}
        // @retval Core::ERROR_NONE: Volume leveller settings were updated successfully
        virtual Core::hresult SetAudioVolumeLeveller(const int32_t handle , const VolumeLeveller volumeLeveller ) = 0;

        /** Get Audio Volume leveller  */
        // @text getAudioVolumeLeveller
        // @brief Get Audio Volume leveller
        // @details Retrieves the volume leveller mode and level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param volumeLeveller: volume leveller (mode and a level)
        // @example volumeLeveller: {"mode": 1, "level": 5}
        // @retval Core::ERROR_NONE: Volume leveller settings were retrieved successfully
        virtual Core::hresult GetAudioVolumeLeveller(const int32_t handle , VolumeLeveller &volumeLeveller /* @out */) = 0;

        /** Set Audio Bass Enhancer  */
        // @text setAudioBassEnhancer
        // @brief Set Audio Bass Enhancer
        // @details Sets the bass enhancement level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param boost: boost for bass
        // @example boost: 3
        // @retval Core::ERROR_NONE: Audio bass enhancement level was set successfully
        virtual Core::hresult SetAudioBassEnhancer(const int32_t handle , const int32_t boost ) = 0;

        /** Get Audio Bass Enhancer  */
        // @text getAudioBassEnhancer
        // @brief Get Audio Bass Enhancer
        // @details Retrieves the bass enhancement level for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param boost: boost for bass
        // @example boost: 3
        // @retval Core::ERROR_NONE: Audio bass enhancement level was retrieved successfully
        virtual Core::hresult GetAudioBassEnhancer(const int32_t handle , int32_t &boost /* @out */) = 0;

        /** Enable Audio Surround Decoder  */
        // @text enableAudioSurroundDecoder
        // @brief Enable Audio Surround Decoder
        // @details Enables or disables the surround decoder for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
         // @param enable: true (surround decoder enabled) or false (surround decoder disabled)
        // @example enable: true
        // @retval Core::ERROR_NONE: Surround decoder state was updated successfully
        virtual Core::hresult EnableAudioSurroundDecoder(const int32_t handle , const bool enable ) = 0;

        /** Is Audio Surround Decoder enabled? */
        // @text isAudioSurroundDecoderEnabled
        // @brief Audio Surround Decoder enabled or not
        // @details Checks whether the surround decoder is enabled for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enabled: true (surround decoder enabled) or false (surround decoder disabled)
        // @example enabled: true
        // @retval Core::ERROR_NONE: Surround decoder state was retrieved successfully
        virtual Core::hresult IsAudioSurroundDecoderEnabled(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Set Audio DRC mode  */
        // @text setAudioDRCMode
        // @brief Set Audio DRC mode
        // @details Sets the dynamic range compression mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param drcMode: mode
        // @example drcMode: 1
        // @retval Core::ERROR_NONE: Audio dynamic range compression mode was set successfully
        virtual Core::hresult SetAudioDRCMode(const int32_t handle , const int32_t drcMode ) = 0;

         /** Get Audio DRC mode  */
        // @text getAudioDRCMode
        // @brief Get Audio DRC mode
        // @details Retrieves the dynamic range compression mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param drcMode: mode
        // @example drcMode: 1
        // @retval Core::ERROR_NONE: Audio dynamic range compression mode was retrieved successfully
        virtual Core::hresult GetAudioDRCMode(const int32_t handle , int32_t &drcMode /* @out */) = 0;

        /** Set Audio Surround Virtualizer  */
        // @text setAudioSurroundVirtualizer
        // @brief Set Audio Surround Virtualizer
        // @details Configures the surround virtualizer mode and boost for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param surroundVirtualizer: virtualizer
        // @example surroundVirtualizer: {"mode": 1, "boost": 20}
        // @retval Core::ERROR_NONE: Surround virtualizer settings were updated successfully
        virtual Core::hresult SetAudioSurroundVirtualizer(const int32_t handle , const SurroundVirtualizer surroundVirtualizer ) = 0;

        /** Get Audio Surround Virtualizer  */
        // @text getAudioSurroundVirtualizer
        // @brief Get Audio Surround Virtualizer
        // @details Retrieves the surround virtualizer mode and boost for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param surroundVirtualizer: virtualizer
        // @example surroundVirtualizer: {"mode": 1, "boost": 20}
        // @retval Core::ERROR_NONE: Surround virtualizer settings were retrieved successfully
        virtual Core::hresult GetAudioSurroundVirtualizer(const int32_t handle , SurroundVirtualizer &surroundVirtualizer /* @out */) = 0;

        /** Set Audio MI Steering   */
        // @text setAudioMISteering
        // @brief Set Audio MI Steering
        // @details Enables or disables MI steering for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable: true (enable steering) or false (disable steering)
        // @example enable: true
        // @retval Core::ERROR_NONE: MI steering state was updated successfully
        virtual Core::hresult SetAudioMISteering(const int32_t handle , const bool enable ) = 0;

        /** Get Audio MI Steering   */
        // @text getAudioMISteering
        // @brief Get Audio MI Steering
        // @details Retrieves whether MI steering is enabled for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param enable: true (enable steering) or false (disable steering)
        // @example enable: true
        // @retval Core::ERROR_NONE: MI steering state was retrieved successfully
        virtual Core::hresult GetAudioMISteering(const int32_t handle , bool &enable /* @out */) = 0;

        /** Set Audio Graphic Equalizer Mode    */
        // @text setAudioGraphicEqualizerMode
        // @brief Set Audio Graphic Equalizer Mode
        // @details Sets the graphic equalizer mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: Equalizer mode
        // @example mode: 1
        // @retval Core::ERROR_NONE: Graphic equalizer mode was set successfully
        virtual Core::hresult SetAudioGraphicEqualizerMode(const int32_t handle , const int32_t mode ) = 0;

        /** Get Audio Graphic Equalizer Mode    */
        // @text getAudioGraphicEqualizerMode
        // @brief Get Audio Graphic Equalizer Mode
        // @details Retrieves the graphic equalizer mode for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mode: Equalizer mode
        // @example mode: 1
        // @retval Core::ERROR_NONE: Graphic equalizer mode was retrieved successfully
        virtual Core::hresult GetAudioGraphicEqualizerMode(const int32_t handle , int32_t &mode /* @out */) = 0;

        /** Get Audio MS12 profile list    */
        // @text getAudioMS12ProfileList
        // @brief Get Audio MS12 profile list
        // @details Retrieves the available MS12 audio profiles for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param ms12ProfileList: MS12 profile list iterator
        // @example ms12ProfileList: [{"audioProfile": "Movie"}, {"audioProfile": "Music"}]
        // @retval Core::ERROR_NONE: MS12 profile list was retrieved successfully
        virtual Core::hresult GetAudioMS12ProfileList(const int32_t handle , IDeviceSettingsAudioMS12AudioProfileIterator*& ms12ProfileList /* @out */) const = 0;

        /** Get Audio MS12 profile    */
        // @text getAudioMS12Profile
        // @brief Get Audio MS12 profile
        // @details Retrieves the active MS12 profile for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param profile: Name of the profile
        // @example profile: "Movie"
        // @retval Core::ERROR_NONE: Active MS12 profile was retrieved successfully
        virtual Core::hresult GetAudioMS12Profile(const int32_t handle , string &profile /* @out */) = 0;

        /** Set Audio MS12 profile    */
        // @text setAudioMS12Profile
        // @brief Set Audio MS12 profile
        // @details Selects the active MS12 profile for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param profile: Name of the profile
        // @example profile: "Movie"
        // @retval Core::ERROR_NONE: Active MS12 profile was set successfully
        virtual Core::hresult SetAudioMS12Profile(const int32_t handle , const string& profile ) = 0;

        /** Set Audio Mixer Levels     */
        // @text setAudioMixerLevels
        // @brief Set Audio Mixer levels
        // @details Sets the mixer volume for the selected audio input on the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param audioInput: AudioInput 
        // @example audioInput: AUDIO_INPUT_PRIMARY
        // @param volume: Volume level
        // @example volume: 50
        // @retval Core::ERROR_NONE: Audio mixer level was set successfully
        virtual Core::hresult SetAudioMixerLevels(const int32_t handle , const AudioInput audioInput , const int32_t volume ) = 0;


        /** Set Associated Audio Mixing values     */
        // @text setAssociatedAudioMixing
        // @brief Set Associated Audio Mixing values 
        // @details Enables or disables associated audio mixing for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mixing: true or false
        // @example mixing: true
        // @retval Core::ERROR_NONE: Associated audio mixing was updated successfully
        virtual Core::hresult SetAssociatedAudioMixing(const int32_t handle , const bool mixing ) = 0;

        /** Get Associated Audio Mixing values     */
        // @text getAssociatedAudioMixing
        // @brief Get Associated Audio Mixing values 
        // @details Retrieves whether associated audio mixing is enabled for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mixing: true or false
        // @example mixing: true
        // @retval Core::ERROR_NONE: Associated audio mixing state was retrieved successfully
        virtual Core::hresult GetAssociatedAudioMixing(const int32_t handle , bool &mixing /* @out */) = 0;

        /** Set Audio Fader control values     */
        // @text setAudioFaderControl
        // @brief Set Audio Fader control values 
        // @details Sets the mixer balance used by audio fader control for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mixerBalance: Mixer balance for fader control
        // @example mixerBalance: 50
        // @retval Core::ERROR_NONE: Audio fader balance was set successfully
        virtual Core::hresult SetAudioFaderControl(const int32_t handle , const int32_t mixerBalance ) = 0;

        /** Get Audio Fader control values     */
        // @text getAudioFaderControl
        // @brief Get Audio Fader control values 
        // @details Retrieves the mixer balance used by audio fader control for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param mixerBalance: Mixer balance for fader control
        // @example mixerBalance: 50
        // @retval Core::ERROR_NONE: Audio fader balance was retrieved successfully
        virtual Core::hresult GetAudioFaderControl(const int32_t handle , int32_t &mixerBalance /* @out */) = 0;

        /** Set Primary Audio language     */
        // @text setAudioPrimaryLanguage
        // @brief Set Primary Audio language
        // @details Sets the primary audio language for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param primaryAudioLanguage: Primary audio language
        // @example primaryAudioLanguage: "en"
        // @retval Core::ERROR_NONE: Primary audio language was set successfully
        virtual Core::hresult SetAudioPrimaryLanguage(const int32_t handle , const string& primaryAudioLanguage ) = 0;

        /** Get Primary Audio language     */
        // @text getAudioPrimaryLanguage
        // @brief Get Primary Audio language
        // @details Retrieves the primary audio language for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param primaryAudioLanguage: Primary audio language
        // @example primaryAudioLanguage: "en"
        // @retval Core::ERROR_NONE: Primary audio language was retrieved successfully
        virtual Core::hresult GetAudioPrimaryLanguage(const int32_t handle , string &primaryAudioLanguage /* @out */) = 0;

        /** Set Secondary Audio language     */
        // @text setAudioSecondaryLanguage
        // @brief Set Secondary Audio language
        // @details Sets the secondary audio language for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param secondaryAudioLanguage: Secondary audio language
        // @example secondaryAudioLanguage: "fr"
        // @retval Core::ERROR_NONE: Secondary audio language was set successfully
        virtual Core::hresult SetAudioSecondaryLanguage(const int32_t handle , const string& secondaryAudioLanguage ) = 0;

        /** Get Primary Audio language     */
        // @text getAudioSecondaryLanguage
        // @brief Get Secondary Audio language
        // @details Retrieves the secondary audio language for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param secondaryAudioLanguage: Secondary audio language
        // @example secondaryAudioLanguage: "fr"
        // @retval Core::ERROR_NONE: Secondary audio language was retrieved successfully
        virtual Core::hresult GetAudioSecondaryLanguage(const int32_t handle , string &secondaryAudioLanguage /* @out */) = 0;

        /** Get Audio Capabilities     */
        // @text getAudioCapabilities
        // @brief Get Audio capabilites
        // @details Retrieves the audio capability bitmask for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param capabilities: Capabilities
        // @example capabilities: 3
        // @retval Core::ERROR_NONE: Audio capabilities were retrieved successfully
        virtual Core::hresult GetAudioCapabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /** Get Audio MS12 Capabilities     */
        // @text getAudioMS12Capabilities
        // @brief Get Audio MS12 capabilites
        // @details Retrieves the MS12 capability bitmask for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param capabilities: Capabilities
        // @example capabilities: 3
        // @retval Core::ERROR_NONE: MS12 capabilities were retrieved successfully
        virtual Core::hresult GetAudioMS12Capabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /** Set Audio MS12 Settings override     */
        // @text setAudioMS12SettingsOverride
        // @brief Set Audio MS12 settings override
        // @details Adds or removes an MS12 profile setting override for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param profileName: Name of the profile
        // @example profileName: "Movie"
        // @param profileSettingsName: Name of the profile setting 
        // @example profileSettingsName: "dialogEnhancer"
        // @param profileSettingValue : value of the profile setting 
        // @example profileSettingValue: "2"
        // @param profileState: state of the profile operation (ADD or REMOVE)
        // @example profileState: AUDIO_MS12_PROFILE_STATE_ADD
        // @retval Core::ERROR_NONE: MS12 profile setting override was updated successfully
        virtual Core::hresult SetAudioMS12SettingsOverride(const int32_t handle , const string& profileName , const string& profileSettingsName , const string& profileSettingValue , const MS12ProfileState profileState ) = 0;

        /** Is Audio output connected?    */
        // @text isAudioOutputConnected
        // @brief Is Audio output connected?
        // @details Checks whether an audio output device is connected to the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param isConnected: connected (true) or not (false)
        // @example isConnected: true
        // @retval Core::ERROR_NONE: Audio output connection state was retrieved successfully
        virtual Core::hresult IsAudioOutputConnected(const int32_t handle , bool &isConnected /* @out */) = 0;


        /** Reset Audio Dialog enhancement    */
        // @text resetAudioDialogEnhancement
        // @brief Reset Audio Dialog enhancement
        // @details Resets dialog enhancement settings to their default values for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @retval Core::ERROR_NONE: Audio dialog enhancement was reset successfully
        virtual Core::hresult ResetAudioDialogEnhancement(const int32_t handle ) = 0;

        /** Reset Audio Bass enhancement    */
        // @text resetAudioBassEnhancer
        // @brief Reset Audio Bass enhancement
        // @details Resets bass enhancement settings to their default values for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @retval Core::ERROR_NONE: Audio bass enhancement was reset successfully
        virtual Core::hresult ResetAudioBassEnhancer(const int32_t handle ) = 0;

        /** Reset Audio Surround virtualizer   */
        // @text resetAudioSurroundVirtualizer
        // @brief Reset Audio Surround virtualizer
        // @details Resets surround virtualizer settings to their default values for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @retval Core::ERROR_NONE: Audio surround virtualizer was reset successfully
        virtual Core::hresult ResetAudioSurroundVirtualizer(const int32_t handle ) = 0;

        /** Reset Audio Volume leveller    */
        // @text resetAudioVolumeLeveller
        // @brief Reset Audio Volume leveller
        // @details Resets volume leveller settings to their default values for the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @retval Core::ERROR_NONE: Audio volume leveller was reset successfully
        virtual Core::hresult ResetAudioVolumeLeveller(const int32_t handle ) = 0;

        /** Get Audio HDMI ARC Port ID    */
        // @text getAudioHDMIARCPortId
        // @brief Get Audio HDMI ARC Port ID
        // @details Retrieves the HDMI ARC port identifier associated with the specified audio port.
        // @param handle: handle returned in GetAudioPort()
        // @example handle: 1
        // @param portId: Port Id
        // @example portId: 0
        // @retval Core::ERROR_NONE: HDMI ARC port identifier was retrieved successfully
        virtual Core::hresult GetAudioHDMIARCPortId(const int32_t handle , int32_t &portId /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
