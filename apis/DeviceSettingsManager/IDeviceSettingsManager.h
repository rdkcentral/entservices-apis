/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

#include <cstdint>
#include <string>

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {
    struct EXTERNAL IDeviceSettingsManager : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_MANAGER };

        enum DisplayEvent {
            DS_DISPLAY_EVENT_CONNECTED     = 0, ///< Display connected event
            DS_DISPLAY_EVENT_DISCONNECTED  = 1, ///< Display disconnected event
            DS_DISPLAY_RXSENSE_ON          = 2, ///< Rx Sense ON event
            DS_DISPLAY_RXSENSE_OFF         = 3, ///< Rx Sense OFF event
            DS_DISPLAY_HDCPPROTOCOL_CHANGE = 4, ///< HDCP Protocol Version Change event
            DS_DISPLAY_EVENT_MAX           = 5  ///< MAX
        };

        struct ResolutionChange {
            uint32_t width;
            uint32_t height;
        };

        enum HDRStandard : uint16_t {
            DS_HDRSTANDARD_NONE             = 0x0,
            DS_HDRSTANDARD_HDR10            = 0x01,
            DS_HDRSTANDARD_HLG              = 0x02,
            DS_HDRSTANDARD_DOLBYVISION      = 0x04,
            DS_HDRSTANDARD_TECHNICOLORPRIME = 0x08,
            DS_HDRSTANDARD_HDR10PLUS        = 0x10,
            DS_HDRSTANDARD_SDR              = 0x20,
            DS_HDRSTANDARD_INVALID          = 0x80
        };

        enum HDCPStatus : uint8_t {
            DS_HDCP_STATUS_UNPOWERED             = 0,
            DS_HDCP_STATUS_UNAUTHENTICATED       = 1,
            DS_HDCP_STATUS_AUTHENTICATED         = 2,
            DS_HDCP_STATUS_AUTHENTICATIONFAILURE = 3,
            DS_HDCP_STATUS_INPROGRESS            = 4,
            DS_HDCP_STATUS_PORTDISABLED          = 5,
            DS_HDCP_STATUS_MAX                   = 6
        };

        enum HDCPProtocolVersion : uint8_t {
            DS_HDCP_VERSION_1X = 0,
            DS_HDCP_VERSION_2X = 1,
            DS_HDCP_VERSION_MAX = 2
        };

        enum VideoZoom : int8_t {
            DS_VIDEO_DEVICE_ZOOM_UNKNOWN           = -1,
            DS_VIDEO_DEVICE_ZOOM_NONE              = 0,
            DS_VIDEO_DEVICE_ZOOM_FULL              = 1,
            DS_VIDEO_DEVICE_ZOOM_LB_16_9           = 2,
            DS_VIDEO_DEVICE_ZOOM_LB_14_9           = 3,
            DS_VIDEO_DEVICE_ZOOM_CCO               = 4,
            DS_VIDEO_DEVICE_ZOOM_PAN_SCAN          = 5,
            DS_VIDEO_DEVICE_ZOOM_LB_2_21_1_ON_4_3  = 6,
            DS_VIDEO_DEVICE_ZOOM_LB_2_21_1_ON_16_9 = 7,
            DS_VIDEO_DEVICE_ZOOM_PLATFORM          = 8,
            DS_VIDEO_DEVICE_ZOOM_16_9_ZOOM         = 9,
            DS_VIDEO_DEVICE_ZOOM_PILLARBOX_4_3     = 10,
            DS_VIDEO_DEVICE_ZOOM_WIDE_4_3          = 11,
            DS_VIDEO_DEVICE_ZOOM_MAX               = 12
        };

        enum FPDTimeFormat : uint8_t {
            DS_FPD_TIMEFORMAT_12_HOUR = 0,
            DS_FPD_TIMEFORMAT_24_HOUR,
            DS_FPD_TIMEFORMAT_MAX
        };

        enum SleepMode : uint8_t {
            DS_HOST_SLEEPMODE_LIGHT = 0,
            DS_HOST_SLEEPMODE_DEEP,
            DS_HOST_SLEEPMODE_MAX
        };

        enum HDMIInPort : int8_t {
            DS_HDMI_IN_PORT_NONE = -1,
            DS_HDMI_IN_PORT_0    = 0,
            DS_HDMI_IN_PORT_1    = 1,
            DS_HDMI_IN_PORT_2    = 2,
            DS_HDMI_IN_PORT_3    = 3,
            DS_HDMI_IN_PORT_4    = 4
        };

        enum HDMIInSignalStatus : int8_t {
            DS_HDMI_IN_SIGNAL_STATUS_NONE         = -1,
            DS_HDMI_IN_SIGNAL_STATUS_NOSIGNAL     = 0,
            DS_HDMI_IN_SIGNAL_STATUS_UNSTABLE     = 1,
            DS_HDMI_IN_SIGNAL_STATUS_NOTSUPPORTED = 2,
            DS_HDMI_IN_SIGNAL_STATUS_STABLE       = 3,
            DS_HDMI_IN_SIGNAL_STATUS_MAX          = 4
        };

        enum HDMIInTVResolution : uint32_t {
            DS_HDMIIN_RESOLUTION_480I    = 0x000001,
            DS_HDMIIN_RESOLUTION_480P    = 0x000002,
            DS_HDMIIN_RESOLUTION_576I    = 0x000004,
            DS_HDMIIN_RESOLUTION_576P    = 0x000008,
            DS_HDMIIN_RESOLUTION_576P50  = 0x000010,
            DS_HDMIIN_RESOLUTION_720P    = 0x000020,
            DS_HDMIIN_RESOLUTION_720P50  = 0x000040,
            DS_HDMIIN_RESOLUTION_1080I   = 0x000080,
            DS_HDMIIN_RESOLUTION_1080P   = 0x000100,
            DS_HDMIIN_RESOLUTION_1080P24 = 0x000200,
            DS_HDMIIN_RESOLUTION_1080I25 = 0x000400,
            DS_HDMIIN_RESOLUTION_1080P25 = 0x000800,
            DS_HDMIIN_RESOLUTION_1080P30 = 0x001000,
            DS_HDMIIN_RESOLUTION_1080I50 = 0x002000,
            DS_HDMIIN_RESOLUTION_1080P50 = 0x004000,
            DS_HDMIIN_RESOLUTION_1080P60 = 0x008000,
            DS_HDMIIN_RESOLUTION_2160P24 = 0x010000,
            DS_HDMIIN_RESOLUTION_2160P25 = 0x020000,
            DS_HDMIIN_RESOLUTION_2160P30 = 0x040000,
            DS_HDMIIN_RESOLUTION_2160P50 = 0x080000,
            DS_HDMIIN_RESOLUTION_2160P60 = 0x100000
        };

        enum HDMIVideoAspectRatio : uint8_t {
            DS_HDMIIN_ASPECT_RATIO_4X3     = 0 /* @text Video Aspect Ratio 4X3 */,
            DS_HDMIIN_ASPECT_RATIO_16X9    = 1 /* @text Video Aspect Ratio 16x9 */,
            DS_HDMIIN_ASPECT_RATIO_MAX     = 2
        };

        enum HDMIInVideoStereoScopicMode : uint8_t {
            DS_HDMIIN_SSMODE_UNKNOWN           = 0,
            DS_HDMIIN_SSMODE_2D                = 1,
            DS_HDMIIN_SSMODE_3D_SIDE_BY_SIDE   = 2,
            DS_HDMIIN_SSMODE_3D_TOP_AND_BOTTOM = 3,
            DS_HDMIIN_SSMODE_MAX               = 4
        };

        enum HDMIInVideoFrameRate : uint8_t {
            DS_HDMIIN_FRAMERATE_UNKNOWN = 0,
            DS_HDMIIN_FRAMERATE_24      = 1,
            DS_HDMIIN_FRAMERATE_25      = 2,
            DS_HDMIIN_FRAMERATE_30      = 3,
            DS_HDMIIN_FRAMERATE_60      = 4,
            DS_HDMIIN_FRAMERATE_23_98   = 5,
            DS_HDMIIN_FRAMERATE_29_97   = 6,
            DS_HDMIIN_FRAMERATE_50      = 7,
            DS_HDMIIN_FRAMERATE_59_94   = 8,
            DS_HDMIIN_FRAMERATE_100     = 9,
            DS_HDMIIN_FRAMERATE_119_88  = 10,
            DS_HDMIIN_FRAMERATE_120     = 11,
            DS_HDMIIN_FRAMERATE_200     = 12,
            DS_HDMIIN_FRAMERATE_239_76  = 13,
            DS_HDMIIN_FRAMERATE_240     = 14,
            DS_HDMIIN_FRAMERATE_MAX     = 15
        };

        // AiW
        enum HDMIInAviContentType : uint8_t {
            DS_HDMIIN_AVICONTENT_TYPE_GRAPHICS      = 0,
            DS_HDMIIN_AVICONTENT_TYPE_PHOTO         = 1,
            DS_HDMIIN_AVICONTENT_TYPE_CINEMA        = 2,
            DS_HDMIIN_AVICONTENT_TYPE_GAME          = 3,
            DS_HDMIIN_AVICONTENT_TYPE_NOT_SIGNALLED = 4,
            DS_HDMIIN_AVICONTENT_TYPE_MAX           = 5
        };

        struct HDMIVideoPortResolution {
            string name;
            HDMIInTVResolution pixelResolution;
            HDMIVideoAspectRatio aspectRatio;
            HDMIInVideoStereoScopicMode stereoScopicMode;
            HDMIInVideoFrameRate frameRate;
            bool interlaced;
        };

        enum AudioPortType : uint8_t {
             
            AUDIO_PORT_TYPE_LR        = 0,
            AUDIO_PORT_TYPE_HDMI      = 1,
            AUDIO_PORT_TYPE_SPDIF     = 2,
            AUDIO_PORT_TYPE_SPEAKER   = 3,
            AUDIO_PORT_TYPE_HDMIARC   = 4,
            AUDIO_PORT_TYPE_HEADPHONE = 5,
            AUDIO_PORT_TYPE_MAX       = 6
        };

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
            AUDIO_FORMAT_DOLBY_MAT_ATMOS    = 0,
            AUDIO_FORMAT_DOLBY_AC4_ATMOS    = 10,
            AUDIO_FORMAT_AAC                = 11,
            AUDIO_FORMAT_VORBIS             = 12,
            AUDIO_FORMAT_WMA                = 13,
            AUDIO_FORMAT_UNKNOWN            = 14,
            AUDIO_FORMAT_MAX                = 15
        };

        enum AudioPortState : uint8_t {
            AUDIO_PORT_STATE_UNKNOWN       = 0,
            AUDIO_PORT_STATE_UNINITIALIZED = 1,
            AUDIO_PORT_STATE_INITIALIZED   = 2
        };

        enum DolbyAtmosCapability : uint8_t {
            AUDIO_DOLBYATMOS_NOT_SUPPORTED  = 0,
            AUDIO_DOLBYATMOS_DDPLUS_STREAM  = 1,
            AUDIO_DOLBYATMOS_ATMOS_METADATA = 2,
            AUDIO_DOLBYATMOS_MAX            = 3
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

        enum CompositeInPort : uint8_t {
            DS_COMPOSITE_IN_NONE         = 0 /* @text NONE */,
            DS_COMPOSITE_IN_PORT_0       = 1 /* @text CompositeIn Port 0 */,
            DS_COMPOSITE_IN_PORT_1       = 2 /* @text CompositeIn Port 1 */,
            DS_COMPOSITE_IN_PORT_MAX     = 3 /* @text CompositeIn Port Max*/
        };

        // AiW
        enum CompositeInSignalStatus : uint8_t {
            DS_COMPOSITE_IN_SIGNAL_STATUS_UNKNOWN      = 0 /* @text UNKNOWN */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NONE         = 1 /* @text Signal Status None */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOSIGNAL     = 2 /* @text Signal Status No Signal */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_UNSTABLE     = 3 /* @text Signal Status Unstable */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOTSUPPORTED = 4 /* @text Signal Status Not supported */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_STABLE       = 5 /* @text Signal Status Stable */
        };

        struct CompositeInStatus {
            bool isPresented;
            CompositeInPort activePort;
            /* Structure can not have array in this interface file. So separated the booleans. 
               https://github.com/rdkcentral/rdk-halif-device_settings/blob/16515f3b8fdbc683164dd58e50a0f7d6ff995d1f/include/dsCompositeInTypes.h#L120 */
            bool isPort0Connected;
            bool isPort1Connected; 
        };

        // @event
        struct EXTERNAL IHDMIHotPlugNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_HDMIHOTPLUG_NOTIFICATION };
            // @brief HDMI Hotplug event
            // @text OnHDMIHotPlug
            // @param displayEvent: CONNECTED or DISCONNECTED
            virtual void OnHDMIHotPlug(DisplayEvent displayEvent) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IHDMIHotPlugNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IHDMIHotPlugNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IRxSenseNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_RXSENSE_NOTIFICATION };
            // @brief RX Sense event
            // @text OnRxSense
            // @param displayEvent: RX Sense On or Off
            virtual void OnRxSense(DisplayEvent displayEvent) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IRxSenseNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IRxSenseNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IHDCPStatusNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_HDCP_STATUS_NOTIFICATION };
            // @brief HDCP Protocol version change
            // @text OnHDCPProtocolChangeStatus
            virtual void OnHDCPProtocolChangeStatus() { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IHDCPStatusNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IHDCPStatusNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSAudioNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_AUDIO_NOTIFICATION };

            // @brief Associated Audio mixing changed
            // @text onAssociatedAudioMixingChanged
            // @param mixing: true or false
            virtual void OnAssociatedAudioMixingChanged(bool mixing) { };

            // @brief Audio Fader balance changed
            // @text onAudioFaderControlChanged
            // @param mixerBalance: applied mixer balance value
            virtual void OnAudioFaderControlChanged(int mixerBalance) { };

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
            virtual void OnAudioOutHotPlug(AudioPortType portType, int uiPortNumber, bool isPortConnected) { };

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
            virtual void OnAudioLevelChangedEvent(int audioLevel) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSAudioNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSAudioNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IHDMIInNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_HDMIIN_NOTIFICATION };
            // @brief HDMI Event Hot Plug
            // @text onHDMIInEventHotPlug
            // @param port: port 0 or 1 et al
            // @param isConnected: is it connected (true) or not (false)
            virtual void OnHDMIInEventHotPlug(HDMIInPort port, bool isConnected) { };

            // @brief HDMI Event Signal status
            // @text OnHDMIInEventSignalStatus
            // @param port: port 0 or 1 et al
            // @param signalStatus: Signal Status
            virtual void OnHDMIInEventSignalStatus(HDMIInPort port, HDMIInSignalStatus signalStatus) { };

            // @brief HDMI Event Signal status
            // @text onHDMIInEventStatus
            // @param activePort: port 0 or 1 et al
            // @param isPresented: is it presented or not
            virtual void OnHDMIInEventStatus(HDMIInPort activePort, bool isPresented) { };

            // @brief HDMI Video Mode update
            // @text onHDMInVideoModeUpdate
            // @param port: port 0 or 1 et al
            // @param videoPortResolution: Video port resolution
            virtual void OnHDMInVideoModeUpdate(HDMIInPort port, const HDMIVideoPortResolution& videoPortResolution) { };

            // @brief HDMI ALLM (Auto Low Latency Mode) status
            // @text onHDMInAllmStatus
            // @param port: port 0 or 1 et al
            // @param allmStatus: allm status
            virtual void OnHDMInAllmStatus(HDMIInPort port, bool allmStatus) { };

            // @brief HDMI Event AVI content type
            // @text OnHDMInAVIContentType
            // @param port: port 0 or 1 et al
            // @param aviContentType: AVI content type
            virtual void OnHDMInAVIContentType(HDMIInPort port, HDMIInAviContentType aviContentType) { };

            // @brief HDMI Event AV Latency
            // @text OnHDMInAVLatency
            // @param audioDelay: audio delay (in millisecs)
            // @param videoDelay: video delay (in millisecs)
            virtual void OnHDMInAVLatency(int audioDelay, int videoDelay) { };
        };
        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IHDMIInNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IHDMIInNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSVideoPortStatusNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_VIDEOPORT_NOTIFICATION };
            // @brief On Resolution Pre changed
            // @text OnResolutionPreChange
            // @param resolution: resolution
            virtual void OnResolutionPreChange(const ResolutionChange& resolution) { };

            // @brief On Resolution Post change
            // @text onResolutionPostChange
            // @param resolution: resolution
            virtual void OnResolutionPostChange(const ResolutionChange& resolution) { };

            // @brief On HDCP Status change
            // @text OnHDCPStatusChange
            // @param hdcpStatus: HDCP Status
            virtual void OnHDCPStatusChange(HDCPStatus hdcpStatus) { };

            // @brief On Video Format update
            // @text OnVideoFormatUpdate
            // @param videoFormatHDR: Video format HDR standard
            virtual void OnVideoFormatUpdate(HDRStandard videoFormatHDR) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSVideoPortStatusNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSVideoPortStatusNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSVideoDeviceNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_VIDEODEVICE_NOTIFICATION };

            // @brief Zoom settings changed
            // @text OnZoomSettingsChanged
            // @param zoomSetting: Currently applied zoom setting
            virtual void OnZoomSettingsChanged(VideoZoom zoomSetting) { };

            // @brief Display Framerate Pre-change
            // @text OnDisplayFrameratePreChange
            // @param frameRate: PreChange framerate
            virtual void OnDisplayFrameratePreChange(const string& frameRate) { };

            // @brief Display Framerate Post-change
            // @text OnDisplayFrameratePostChange
            // @param frameRate:  framerate post change
            virtual void OnDisplayFrameratePostChange(const string& frameRate) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSVideoDeviceNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSVideoDeviceNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSHostNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_HOST_NOTIFICATION };

            // @brief Sleep mode changed
            // @text onSleepModeChanged
            // @param sleepMode: see SleepMode
            virtual void OnSleepModeChanged(SleepMode sleepMode) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSHostNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSHostNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSCompositeInNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_COMPOSITEIN_NOTIFICATION };

            // @brief Composite In Hotplug event
            // @text onCompositeInHotPlug
            // @param port: Port of the hotplug
            // @param isConnected: Is it connected (true) or not(false)
            virtual void OnCompositeInHotPlug(CompositeInPort port, bool isConnected) { };

            // @brief Composite In Signal status
            // @text onCompositeInSignalStatus
            // @param port: Port of the hotplug
            // @param signalStatus: Signal status
            virtual void OnCompositeInSignalStatus(CompositeInPort port, CompositeInSignalStatus signalStatus) { };

            // @brief Composite In status
            // @text onCompositeInStatus
            // @param activePort: Active port
            // @param isPresented: is it presented to user
            virtual void OnCompositeInStatus(CompositeInPort activePort, bool isPresented) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSCompositeInNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSCompositeInNotification* notification /* @in */) = 0;

        // @event
        struct EXTERNAL IDSFPDNotification : virtual public Core::IUnknown {
            enum { ID = ID_DEVICESETTINGS_MANAGER_FPD_NOTIFICATION };

            // @brief On Front Panel display time format changed
            // @text OnFPDTimeFormatChanged
            // @param timeFormat: current time format 12 or 24 hour
            virtual void OnFPDTimeFormatChanged(FPDTimeFormat timeFormat) { };
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsManager::IDSFPDNotification* notification /* @in */)   = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsManager::IDSFPDNotification* notification /* @in */) = 0;

        /** Execute API. */
        // @text Execute API
        // @brief Execute API.
        // @param reqBuf: request string (contains serialized parameters)
        // @param respBuf: response string (contains serialized parameters)
        virtual Core::hresult Execute(const string& reqBuf /* @in */, string& respBuf /* @out*/) = 0;
    };
    } // namespace Exchange
    } // namespace WPEFramework
