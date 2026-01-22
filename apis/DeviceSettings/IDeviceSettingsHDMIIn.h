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

    struct EXTERNAL IDeviceSettingsHDMIIn : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_HDMIIN };

        enum HDMIInPort : int8_t {
            DS_HDMI_IN_PORT_NONE    = -1,
            DS_HDMI_IN_PORT_0       = 0,
            DS_HDMI_IN_PORT_1       = 1,
            DS_HDMI_IN_PORT_2       = 2,
            DS_HDMI_IN_PORT_3       = 3,
            DS_HDMI_IN_PORT_4       = 4,
            DS_HDMI_IN_PORT_MAX     = 5
        };

        enum HDMIInSignalStatus: int8_t {
            DS_HDMI_IN_SIGNAL_STATUS_NONE        = -1,
            DS_HDMI_IN_SIGNAL_STATUS_NOSIGNAL     = 0,
            DS_HDMI_IN_SIGNAL_STATUS_UNSTABLE     = 1,
            DS_HDMI_IN_SIGNAL_STATUS_NOTSUPPORTED = 2,
            DS_HDMI_IN_SIGNAL_STATUS_STABLE       = 3,
            DS_HDMI_IN_SIGNAL_STATUS_MAX          = 4
        };

        struct HDMIPortConnectionStatus {
            bool isPortConnected;
        };
        using IHDMIInPortConnectionStatusIterator = RPC::IIteratorType<HDMIPortConnectionStatus, ID_DEVICESETTINGS_HDMIIN_PORTCONNECTION_ITERATOR>;

        struct HDMIInStatus {
            bool isPresented;
            HDMIInPort activePort;
        };

        struct HDMIInCapabilities {
            bool isPortArcCapable;
        };

        struct HDMIInGameFeatureList {
            string gameFeature;
        };

        using IHDMIInGameFeatureListIterator = RPC::IIteratorType<HDMIInGameFeatureList, ID_DEVICESETTINGS_HDMIIN_GAMELIST_ITERATOR>;

        struct HDMIInSpdInfoFrame {
            uint8_t pktType;            /*!< Package type */
            uint8_t version;            /*!< Version */
            uint8_t length;             /*!< max length 25, min length 0 */
            uint8_t rsd;                /*!< Repetition of static data */
            uint8_t checkSum;           /*!< Checksum for spd info frame */
            string  vendorName;        /*!< Vendor Name string. Min length 0 */
            string  productDes;       /*!< Product Description string. Min length 0 */
            uint8_t sourceInfo;        /*!< Source info of the frame  */
        };

        enum HDMIInEdidVersion : uint8_t {
            HDMI_EDID_VER_14      = 0,
            HDMI_EDID_VER_20      = 1,
            HDMI_EDID_VER_MAX     = 2
        };

        enum HDMIVideoPlaneType: uint8_t {
            DS_HDMIIN_VIDEOPLANE_PRIMARY   = 0,
            DS_HDMIIN_VIDEOPLANE_SECONDARY = 1,
            DS_HDMIIN_VIDEOPLANE_MAX       = 2
        };

        enum HDMIInCapabilityVersion {
            HDMI_COMPATIBILITY_VERSION_14  = 0,
            HDMI_COMPATIBILITY_VERSION_20  = 1,
            HDMI_COMPATIBILITY_VERSION_21  = 2,
            HDMI_COMPATIBILITY_VERSION_MAX = 3
        };

        struct HDMIInVideoRectangle {
            int32_t x;
            int32_t y;
            int32_t width;
            int32_t height;
        };

        enum HDMIInVideoZoom : int8_t {
            DS_HDMIIN_VIDEO_ZOOM_UNKNOWN           = -1,
            DS_HDMIIN_VIDEO_ZOOM_NONE              = 0,
            DS_HDMIIN_VIDEO_ZOOM_FULL              = 1,
            DS_HDMIIN_VIDEO_ZOOM_LB_16_9           = 2,
            DS_HDMIIN_VIDEO_ZOOM_LB_14_9           = 3,
            DS_HDMIIN_VIDEO_ZOOM_CCO               = 4,
            DS_HDMIIN_VIDEO_ZOOM_PAN_SCAN          = 5,
            DS_HDMIIN_VIDEO_ZOOM_LB_2_21_1_ON_4_3  = 6,
            DS_HDMIIN_VIDEO_ZOOM_LB_2_21_1_ON_16_9 = 7,
            DS_HDMIIN_VIDEO_ZOOM_PLATFORM          = 8,
            DS_HDMIIN_VIDEO_ZOOM_16_9_ZOOM         = 9,
            DS_HDMIIN_VIDEO_ZOOM_PILLARBOX_4_3     = 10,
            DS_HDMIIN_VIDEO_ZOOM_WIDE_4_3          = 11,
            DS_HDMIIN_VIDEO_ZOOM_MAX               = 12
        };

        enum HDMIInVRRType: uint8_t {
            DS_HDMIIN_VRR_NONE                  = 0,
            DS_HDMIIN_HDMI_VRR                  = 1,
            DS_HDMIIN_AMD_FREESYNC              = 2,
            DS_HDMIIN_AMD_FREESYNC_PREMIUM      = 3,
            DS_HDMIIN_AMD_FREESYNC_PREMIUM_PRO  = 4
        };

        struct HDMIInVRRStatus {
            HDMIInVRRType vrrType;
            double vrrFreeSyncFramerateHz;
        };

        enum HDMIInTVResolution: uint32_t {
            DS_HDMIIN_RESOLUTION_480I     = 0x000001,
            DS_HDMIIN_RESOLUTION_480P     = 0x000002,
            DS_HDMIIN_RESOLUTION_576I     = 0x000004,
            DS_HDMIIN_RESOLUTION_576P     = 0x000008,
            DS_HDMIIN_RESOLUTION_576P50   = 0x000010,
            DS_HDMIIN_RESOLUTION_720P     = 0x000020,
            DS_HDMIIN_RESOLUTION_720P50   = 0x000040,
            DS_HDMIIN_RESOLUTION_1080I    = 0x000080,
            DS_HDMIIN_RESOLUTION_1080P    = 0x000100,
            DS_HDMIIN_RESOLUTION_1080P24  = 0x000200,
            DS_HDMIIN_RESOLUTION_1080I25  = 0x000400,
            DS_HDMIIN_RESOLUTION_1080P30  = 0x001000,
            DS_HDMIIN_RESOLUTION_1080I50  = 0x002000,
            DS_HDMIIN_RESOLUTION_1080P50  = 0x004000,
            DS_HDMIIN_RESOLUTION_1080P60  = 0x008000,
            DS_HDMIIN_RESOLUTION_2160P24  = 0x010000,
            DS_HDMIIN_RESOLUTION_2160P25  = 0x020000,
            DS_HDMIIN_RESOLUTION_2160P30  = 0x040000,
            DS_HDMIIN_RESOLUTION_2160P50  = 0x080000,
            DS_HDMIIN_RESOLUTION_2160P60  = 0x100000
        };

        enum HDMIVideoAspectRatio : uint8_t {
            DS_HDMIIN_ASPECT_RATIO_4X3         = 0  /* @text Video Aspect Ratio 4X3 */,
            DS_HDMIIN_ASPECT_RATIO_16X9        = 1  /* @text Video Aspect Ratio 16x9 */,
            DS_HDMIIN_ASPECT_RATIO_MAX         = 2  /* @text Video Aspect Ratio MAX */
        };

        enum HDMIInVideoStereoScopicMode : uint8_t {
            DS_HDMIIN_SSMODE_UNKNOWN           = 0,
            DS_HDMIIN_SSMODE_2D                = 1,
            DS_HDMIIN_SSMODE_3D_SIDE_BY_SIDE   = 2,
            DS_HDMIIN_SSMODE_3D_TOP_AND_BOTTOM = 3,
            DS_HDMIIN_SSMODE_MAX               = 4
        };

        enum HDMIInVideoFrameRate: uint8_t {
            DS_HDMIIN_FRAMERATE_UNKNOWN   = 0,
            DS_HDMIIN_FRAMERATE_24        = 1,
            DS_HDMIIN_FRAMERATE_25        = 2,
            DS_HDMIIN_FRAMERATE_30        = 3,
            DS_HDMIIN_FRAMERATE_60        = 4,
            DS_HDMIIN_FRAMERATE_23_98     = 5,
            DS_HDMIIN_FRAMERATE_29_97     = 6,
            DS_HDMIIN_FRAMERATE_50        = 7,
            DS_HDMIIN_FRAMERATE_59_94     = 8,
            DS_HDMIIN_FRAMERATE_100       = 9,
            DS_HDMIIN_FRAMERATE_119_88    = 10,
            DS_HDMIIN_FRAMERATE_120       = 11,
            DS_HDMIIN_FRAMERATE_200       = 12,
            DS_HDMIIN_FRAMERATE_239_76    = 13,
            DS_HDMIIN_FRAMERATE_240       = 14,
            DS_HDMIIN_FRAMERATE_MAX       = 15
        };

        enum HDMIInAviContentType: uint8_t {
            DS_HDMIIN_AVICONTENT_TYPE_GRAPHICS      =0,
            DS_HDMIIN_AVICONTENT_TYPE_PHOTO         =1,
            DS_HDMIIN_AVICONTENT_TYPE_CINEMA        =2,
            DS_HDMIIN_AVICONTENT_TYPE_GAME          =3,
            DS_HDMIIN_AVICONTENT_TYPE_NOT_SIGNALLED =4,
            DS_HDMIIN_AVICONTENT_TYPE_MAX           =5
        };
          
        struct HDMIVideoPortResolution {
            string name;
            HDMIInTVResolution pixelResolution;
            HDMIVideoAspectRatio aspectRatio;
            HDMIInVideoStereoScopicMode stereoScopicMode;
            HDMIInVideoFrameRate frameRate;
            bool interlaced;
        };
        
        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_HDMIIN_NOTIFICATION };

            // @brief HDMI Event Hot Plug
            // @text onHDMIInEventHotPlug
            // @param port: port 0 or 1 et al
            // @param isConnected: is it connected (true) or not (false)
            virtual void OnHDMIInEventHotPlug(const HDMIInPort port, const bool isConnected) {};

            // @brief HDMI Event Signal status
            // @text OnHDMIInEventSignalStatus
            // @param port: port 0 or 1 et al
            // @param signalStatus: Signal Status
            virtual void OnHDMIInEventSignalStatus(const HDMIInPort port, const HDMIInSignalStatus signalStatus) {};

            // @brief HDMI Event Signal status
            // @text onHDMIInEventStatus
            // @param activePort: port 0 or 1 et al
            // @param isPresented: is it presented or not
            virtual void OnHDMIInEventStatus(const HDMIInPort activePort, const bool isPresented) {};

            // @brief HDMI Video Mode update
            // @text onHDMIInVideoModeUpdate
            // @param port: port 0 or 1 et al
            // @param videoPortResolution: Video port resolution
            virtual void OnHDMIInVideoModeUpdate(const HDMIInPort port, const HDMIVideoPortResolution videoPortResolution) {};
            
            // @brief HDMI ALLM status
            // @text onHDMIInAllmStatus
            // @param port: port 0 or 1 et al
            // @param allmStatus: allm status
            virtual void OnHDMIInAllmStatus(const HDMIInPort port, const bool allmStatus) {};

            // @brief HDMI Event AVI content type
            // @text onHDMIInAVIContentType
            // @param port: port 0 or 1 et al
            // @param aviContentType: AVI content type
            virtual void OnHDMIInAVIContentType(const HDMIInPort port, const HDMIInAviContentType aviContentType) {};

            // @brief HDMI Event AV Latency
            // @text onHDMIInAVLatency
            // @param port: port 0 or 1 et al
            // @param audioDelay: audio delay
            // @param videoDelay: video delay
            virtual void OnHDMIInAVLatency(const int32_t audioDelay, const int32_t videoDelay) {};

            // @brief HDMI VRR status
            // @text onHDMIInVRRStatus
            // @param port: port 0 or 1 et al
            // @param vrrType: VRR type
            virtual void OnHDMIInVRRStatus(const HDMIInPort port, const HDMIInVRRType vrrType) {};
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsHDMIIn::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsHDMIIn::INotification* notification ) = 0;

        /** Get Number of HDMI Inputs in the platform. */
        // @text getHDMIInNumbefOfInputs
        // @brief Get Number of HDMI Inputs in the platform
        // @param count: number of inputs
        virtual Core::hresult GetHDMIInNumbefOfInputs(int32_t &count /* @out */) = 0;

        /** Get HDMIIn Status. */
        // @text getHDMIInStatus
        // @brief Get HDMIIn Status
        // @param hdmiStatus: HDMI Status
        virtual Core::hresult GetHDMIInStatus(HDMIInStatus &hdmiStatus /* @out */, IHDMIInPortConnectionStatusIterator*& portConnectionStatus /* @out */) = 0;

        /** Select HDMIIn Port. */
        // @text selectHDMIInPort
        // @brief Get HDMIIn Status
        // @param port: Port to select 
        // @param requestAudioMix: Should audio be mixed on this port
        // @param topMostPlane: Should this be on top for display
        // @param videoPlaneType: Primary or secondary
        virtual Core::hresult SelectHDMIInPort(const HDMIInPort port , const bool requestAudioMix , const bool topMostPlane , const HDMIVideoPlaneType videoPlaneType ) = 0;

        /** Scale HDMIIn Video. */
        // @text scaleHDMIInVideo
        // @brief Scale HDMIIn Video
        // @param videoPosition: co-ordinates to scale
        virtual Core::hresult ScaleHDMIInVideo(const HDMIInVideoRectangle videoPosition ) = 0;

        /** Select HDMIIn Zoom mode. */
        // @text selectHDMIZoomMode
        // @brief Select HDMIIn Zoom mode
        // @param zoomMode: zoom mode
        virtual Core::hresult SelectHDMIZoomMode(const HDMIInVideoZoom zoomMode ) = 0;

        /** Get Supported Game feature list. */
        // @text getSupportedGameFeaturesList
        // @brief Get Supported Game feature list
        // @param gameFeatureList: game feature list
        virtual Core::hresult GetSupportedGameFeaturesList(IHDMIInGameFeatureListIterator *& gameFeatureList /* @out */) = 0;

        /** Get AV latency. */
        // @text getHDMIInAVLatency
        // @brief Get AV latency
        // @param videoLatency: video latency
        // @param audioLatency: audio latency
        virtual Core::hresult GetHDMIInAVLatency(uint32_t &videoLatency /* @out */, uint32_t &audioLatency /* @out*/) = 0;

        /** Get ALLM Status. */
        // @text getHDMIInAllmStatus
        // @brief Get ALLM Status
        // @param port: Port number
        // @param allmStatus: ALLM status
        virtual Core::hresult GetHDMIInAllmStatus(const HDMIInPort port , bool &allmStatus /* @out*/) = 0;

        /** Get EDID to ALLM Supported or not. */
        // @text getHDMIInEdid2AllmSupport
        // @brief Get EDID to ALLM Supported or not
        // @param port: Port number
        // @param allmSupport: ALLM supported (true) or not (false)
        virtual Core::hresult GetHDMIInEdid2AllmSupport(const HDMIInPort port , bool &allmSupport /* @out*/) = 0;

        /** Set EDID to ALLM Supported or not. */
        // @text setHDMIInEdid2AllmSupport
        // @brief Get EDID to ALLM Supported or not
        // @param port: Port number
        // @param allmSupport: ALLM supported (true) or not (false)
        virtual Core::hresult SetHDMIInEdid2AllmSupport(const HDMIInPort port , bool allmSupport) = 0;

        /** Get EDID bytes. */
        // @text getEdidBytes
        // @brief Get EDID bytes.
        // @param port: Port number
        // @param edidBytesLength: number of bytes in the edidBytes array
        // @param edidBytes: EDID information
        virtual Core::hresult GetEdidBytes(const HDMIInPort port , const uint16_t edidBytesLength ,  uint8_t edidBytes[] /* @out @length:edidBytesLength @maxlength:edidBytesLength */) = 0;

        /** Get HDMI SPD Information. */
        // @text getHDMISPDInformation
        // @brief Get HDMI SPD Information.
        // @param port: Port number
        // @param spdBytesLength: number of bytes in the spdBytes array
        // @param spdBytes: SPD information
        virtual Core::hresult GetHDMISPDInformation(const HDMIInPort port , const uint16_t spdBytesLength ,  uint8_t spdBytes[] /* @out @length:spdBytesLength @maxlength:spdBytesLength */) = 0;

        /** Get HDMI Port EDID version. */
        // @text getHDMIEdidVersion
        // @brief Get HDMI Port EDID version.
        // @param port: Port number
        // @param edidVersion: EDID version
        virtual Core::hresult GetHDMIEdidVersion(const HDMIInPort port , HDMIInEdidVersion &edidVersion /* @out */) = 0;

        /** Set HDMI Port EDID version. */
        // @text setHDMIEdidVersion
        // @brief Set HDMI Port EDID version.
        // @param port: Port number
        // @param edidVersion: EDID version
        virtual Core::hresult SetHDMIEdidVersion(const HDMIInPort port , const HDMIInEdidVersion edidVersion ) = 0;

        /** Get HDMI Video mode. */
        // @text getHDMIVideoMode
        // @brief Get HDMI Video mode.
        // @param videoPortResolution: Video port resolution structure
        virtual Core::hresult GetHDMIVideoMode( HDMIVideoPortResolution &videoPortResolution /* @out */) = 0;

        /** Get HDMI Supported version. */
        // @text getHDMIVersion
        // @brief Get HDMI Supported Version
        // @param port: Port number
        // @param capabilityVersion: supported capability version
        virtual Core::hresult GetHDMIVersion(const HDMIInPort port , HDMIInCapabilityVersion capabilityVersion /* @out */) = 0;

        /** Set HDMI VRR Support. */
        // @text setVRRSupport
        // @brief Set HDMI VRR Support.
        // @param port: Port number
        // @param vrrSupport: enable (true) or disable (false)
        virtual Core::hresult SetVRRSupport(const HDMIInPort port , const bool vrrSupport ) = 0;

        /** Get HDMI VRR Support. */
        // @text getVRRSupport
        // @brief Get HDMI VRR Support.
        // @param port: Port number
        // @param vrrSupport: enabled (true) or disable (false)
        virtual Core::hresult GetVRRSupport(const HDMIInPort port , bool &vrrSupport /* @out */) = 0;

        /** Get HDMI VRR Status. */
        // @text getVRRStatus
        // @brief Get HDMI VRR Status.
        // @param port: Port number
        // @param vrrStatus: VRR Status
        virtual Core::hresult GetVRRStatus(const HDMIInPort port , HDMIInVRRStatus &vrrStatus /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
