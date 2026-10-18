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
            bool isPresented /* @brief True when HDMI-In content is currently presented */;
            HDMIInPort activePort /* @brief Currently active HDMI-In port */;
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

        enum HDMIInCapabilityVersion : uint8_t {
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

        enum HDMIInAviContentType: uint8_t {
            DS_HDMIIN_AVICONTENT_TYPE_GRAPHICS      =0,
            DS_HDMIIN_AVICONTENT_TYPE_PHOTO         =1,
            DS_HDMIIN_AVICONTENT_TYPE_CINEMA        =2,
            DS_HDMIIN_AVICONTENT_TYPE_GAME          =3,
            DS_HDMIIN_AVICONTENT_TYPE_NOT_SIGNALLED =4,
            DS_HDMIIN_AVICONTENT_TYPE_MAX           =5
        };

        enum HDMIInVideoResolution : uint8_t {
            DS_HDMIIN_PIXELRES_720X480    = 0,
            DS_HDMIIN_PIXELRES_720X576    = 1,
            DS_HDMIIN_PIXELRES_1280X720   = 2,
            DS_HDMIIN_PIXELRES_1366X768   = 3,
            DS_HDMIIN_PIXELRES_1920X1080  = 4,
            DS_HDMIIN_PIXELRES_3840X2160  = 5,
            DS_HDMIIN_PIXELRES_4096X2160  = 6,
            DS_HDMIIN_PIXELRES_MAX        = 7
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

        // Self-contained struct matching dsVideoPortResolution_t (shared by VideoPort and HdmiIn HAL).
        // pixelResolution uses pixel-dimension enum (HDMIInVideoResolution) not TV-standard bitmask.
        struct HDMIVideoPortResolution {
            string name;
            HDMIInVideoResolution pixelResolution;
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
            // @details Notifies clients when an HDMI input port is connected or disconnected.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param isConnected: is it connected (true) or not (false)
            // @example isConnected: true
            virtual void OnHDMIInEventHotPlug(const HDMIInPort port, const bool isConnected) {};

            // @brief HDMI Event Signal status
            // @text onHDMIInEventSignalStatus
            // @details Notifies clients when the signal status of an HDMI input port changes.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param signalStatus: Signal Status
            // @example signalStatus: DS_HDMI_IN_SIGNAL_STATUS_STABLE
            virtual void OnHDMIInEventSignalStatus(const HDMIInPort port, const HDMIInSignalStatus signalStatus) {};

            // @brief HDMI Event Signal status
            // @text onHDMIInEventStatus
            // @details Notifies clients when the active HDMI input port or its presentation state changes.
            // @param activePort: port 0 or 1 et al
            // @example activePort: DS_HDMI_IN_PORT_0
            // @param isPresented: is it presented or not
            // @example isPresented: true
            virtual void OnHDMIInEventStatus(const HDMIInPort activePort, const bool isPresented) {};

            // @brief HDMI Video Mode update
            // @text onHDMIInVideoModeUpdate
            // @details Notifies clients when the video mode of an HDMI input port changes.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param videoPortResolution: Video port resolution
            // @example videoPortResolution: {"name": "1920x1080p60", "pixelResolution": "DS_HDMIIN_PIXELRES_1920X1080", "aspectRatio": "DS_HDMIIN_ASPECT_RATIO_16X9", "frameRate": "DS_HDMIIN_FRAMERATE_60", "interlaced": false}
            virtual void OnHDMIInVideoModeUpdate(const HDMIInPort port, const HDMIVideoPortResolution& videoPortResolution) {};
            
            // @brief HDMI ALLM status
            // @text onHDMIInAllmStatus
            // @details Notifies clients when Auto Low Latency Mode status changes on an HDMI input port.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param allmStatus: allm status
            // @example allmStatus: true
            virtual void OnHDMIInAllmStatus(const HDMIInPort port, const bool allmStatus) {};

            // @brief HDMI Event AVI content type
            // @text onHDMIInAVIContentType
            // @details Notifies clients when the AVI content type for an HDMI input port changes.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param aviContentType: AVI content type
            // @example aviContentType: DS_HDMIIN_AVICONTENT_TYPE_GAME
            virtual void OnHDMIInAVIContentType(const HDMIInPort port, const HDMIInAviContentType aviContentType) {};

            // @brief HDMI Event AV Latency
            // @text onHDMIInAVLatency
            // @details Notifies clients when the audio and video latency values change.
            // @param audioDelay: Audio latency in milliseconds.
            // @example audioDelay: 40
            // @param videoDelay: Video latency in milliseconds.
            // @example videoDelay: 20
            virtual void OnHDMIInAVLatency(const int32_t audioDelay, const int32_t videoDelay) {};

            // @brief HDMI VRR status
            // @text onHDMIInVRRStatus
            // @details Notifies clients when the Variable Refresh Rate type changes on an HDMI input port.
            // @param port: port 0 or 1 et al
            // @example port: DS_HDMI_IN_PORT_0
            // @param vrrType: VRR type
            // @example vrrType: DS_HDMIIN_HDMI_VRR
            virtual void OnHDMIInVRRStatus(const HDMIInPort port, const HDMIInVRRType vrrType) {};
        };

        // @brief Register for HDMI input notifications.
        // @details Subscribes a client notification listener to HDMI input events.
        // @param clientName: Name identifying the client registering for notifications.
        // @example clientName: "HDMIInputClient"
        // @param notification: Listener that receives HDMI input events.
        // @example notification: IDeviceSettingsHDMIIn::INotification instance
        // @retval Core::ERROR_NONE: Notification listener was registered successfully
        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsHDMIIn::INotification* notification ) = 0;

        // @brief Unregister from HDMI input notifications.
        // @details Removes a client notification listener from HDMI input events.
        // @param notification: Listener to remove from the subscription.
        // @example notification: IDeviceSettingsHDMIIn::INotification instance
        // @retval Core::ERROR_NONE: Notification listener was unregistered successfully
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsHDMIIn::INotification* notification ) = 0;

        /** Get Number of HDMI Inputs in the platform. */
        // @text getHDMIInNumberOfInputs
        // @brief Get Number of HDMI Inputs in the platform
        // @details Retrieves the number of HDMI input ports available on the platform.
        // @param count: number of inputs
        // @example count: 4
        // @retval Core::ERROR_NONE: Number of HDMI input ports was retrieved successfully
        virtual Core::hresult GetHDMIInNumberOfInputs(int32_t &count /* @out */) = 0;

        /** Get HDMIIn Status. */
        // @text getHDMIInStatus
        // @brief Get HDMIIn Status
        // @details Retrieves the active HDMI input state and connection status for the HDMI input ports.
        // @param hdmiStatus: HDMI Status
        // @example hdmiStatus: {"isPresented": true, "activePort": "DS_HDMI_IN_PORT_0"}
        // @param portConnectionStatus: Iterator containing the connection status of each HDMI input port.
        // @example portConnectionStatus: [{"isPortConnected": true}, {"isPortConnected": false}]
        // @retval Core::ERROR_NONE: HDMI input status was retrieved successfully
        virtual Core::hresult GetHDMIInStatus(HDMIInStatus &hdmiStatus /* @out */, IHDMIInPortConnectionStatusIterator*& portConnectionStatus /* @out */) = 0;

        /** Select HDMIIn Port. */
        // @text selectHDMIInPort
        // @brief Select HDMIIn Port
        // @details Selects the HDMI input port to use and configures its audio mixing and display plane behavior.
        // @param port: Port to select 
        // @example port: DS_HDMI_IN_PORT_0
        // @param requestAudioMix: Should audio be mixed on this port
        // @example requestAudioMix: true
        // @param topMostPlane: Should this be on top for display
        // @example topMostPlane: true
        // @param videoPlaneType: Primary or secondary
        // @example videoPlaneType: DS_HDMIIN_VIDEOPLANE_PRIMARY
        // @retval Core::ERROR_NONE: HDMI input port was selected successfully
        virtual Core::hresult SelectHDMIInPort(const HDMIInPort port , const bool requestAudioMix , const bool topMostPlane , const HDMIVideoPlaneType videoPlaneType ) = 0;

        /** Scale HDMIIn Video. */
        // @text scaleHDMIInVideo
        // @brief Scale HDMIIn Video
        // @details Sets the position and dimensions used to scale HDMI input video.
        // @param videoPosition: co-ordinates to scale
        // @example videoPosition: {"x": 0, "y": 0, "width": 1920, "height": 1080}
        // @retval Core::ERROR_NONE: HDMI input video scaling was updated successfully
        virtual Core::hresult ScaleHDMIInVideo(const HDMIInVideoRectangle videoPosition ) = 0;

        /** Select HDMIIn Zoom mode. */
        // @text selectHDMIZoomMode
        // @brief Select HDMIIn Zoom mode
        // @details Selects the zoom mode applied to HDMI input video.
        // @param zoomMode: zoom mode
        // @example zoomMode: DS_HDMIIN_VIDEO_ZOOM_FULL
        // @retval Core::ERROR_NONE: HDMI input zoom mode was selected successfully
        virtual Core::hresult SelectHDMIZoomMode(const HDMIInVideoZoom zoomMode ) = 0;

        /** Get Supported Game feature list. */
        // @text getSupportedGameFeaturesList
        // @brief Get Supported Game feature list
        // @details Retrieves the game features supported by the HDMI input implementation.
        // @param gameFeatureList: game feature list
        // @example gameFeatureList: ["ALLM", "VRR"]
        // @retval Core::ERROR_NONE: Supported game features were retrieved successfully
        virtual Core::hresult GetSupportedGameFeaturesList(IHDMIInGameFeatureListIterator *& gameFeatureList /* @out */) = 0;

        /** Get AV latency. */
        // @text getHDMIInAVLatency
        // @brief Get AV latency
        // @details Retrieves the current audio and video latency values for HDMI input.
        // @param videoLatency: video latency
        // @example videoLatency: 20
        // @param audioLatency: audio latency
        // @example audioLatency: 40
        // @retval Core::ERROR_NONE: HDMI input audio and video latency values were retrieved successfully
        virtual Core::hresult GetHDMIInAVLatency(uint32_t &videoLatency /* @out */, uint32_t &audioLatency /* @out*/) = 0;

        /** Get ALLM Status. */
        // @text getHDMIInAllmStatus
        // @brief Get ALLM Status
        // @details Retrieves whether Auto Low Latency Mode is active on the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param allmStatus: ALLM status
        // @example allmStatus: true
        // @retval Core::ERROR_NONE: ALLM status was retrieved successfully
        virtual Core::hresult GetHDMIInAllmStatus(const HDMIInPort port , bool &allmStatus /* @out*/) = 0;

        /** Get EDID to ALLM Supported or not. */
        // @text getHDMIInEdid2AllmSupport
        // @brief Get EDID to ALLM Supported or not
        // @details Retrieves whether the EDID advertises ALLM support for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param allmSupport: ALLM supported (true) or not (false)
        // @example allmSupport: true
        // @retval Core::ERROR_NONE: EDID ALLM support status was retrieved successfully
        virtual Core::hresult GetHDMIInEdid2AllmSupport(const HDMIInPort port , bool &allmSupport /* @out*/) = 0;

        /** Set EDID to ALLM Supported or not. */
        // @text setHDMIInEdid2AllmSupport
        // @brief Set EDID ALLM support
        // @details Enables or disables the ALLM support flag advertised in the EDID for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param allmSupport: ALLM supported (true) or not (false)
        // @example allmSupport: true
        // @retval Core::ERROR_NONE: EDID ALLM support setting was updated successfully
        virtual Core::hresult SetHDMIInEdid2AllmSupport(const HDMIInPort port , bool allmSupport) = 0;

        /** Get EDID bytes. */
        // @text getEdidBytes
        // @brief Get EDID bytes.
        // @details Retrieves the raw EDID byte sequence for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param edidBytesLength: number of bytes in the edidBytes array
        // @example edidBytesLength: 128
        // @param edidBytes: EDID information
        // @example edidBytes: [0, 255, 255, 255, 255, 255, 255, 0]
        // @retval Core::ERROR_NONE: EDID bytes were retrieved successfully
        virtual Core::hresult GetEdidBytes(const HDMIInPort port , const uint16_t edidBytesLength ,  uint8_t edidBytes[] /* @out @length:edidBytesLength @maxlength:edidBytesLength */) = 0;

        /** Get HDMI SPD Information. */
        // @text getHDMISPDInformation
        // @brief Get HDMI SPD Information.
        // @details Retrieves the Source Product Description information frame bytes for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param spdBytesLength: number of bytes in the spdBytes array
        // @example spdBytesLength: 31
        // @param spdBytes: SPD information
        // @example spdBytes: [131, 1, 8, 0]
        // @retval Core::ERROR_NONE: HDMI SPD information was retrieved successfully
        virtual Core::hresult GetHDMISPDInformation(const HDMIInPort port , const uint16_t spdBytesLength ,  uint8_t spdBytes[] /* @out @length:spdBytesLength @maxlength:spdBytesLength */) = 0;

        /** Get HDMI Port EDID version. */
        // @text getHDMIEdidVersion
        // @brief Get HDMI Port EDID version.
        // @details Retrieves the EDID version configured for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param edidVersion: EDID version
        // @example edidVersion: HDMI_EDID_VER_20
        // @retval Core::ERROR_NONE: HDMI EDID version was retrieved successfully
        virtual Core::hresult GetHDMIEdidVersion(const HDMIInPort port , HDMIInEdidVersion &edidVersion /* @out */) = 0;

        /** Set HDMI Port EDID version. */
        // @text setHDMIEdidVersion
        // @brief Set HDMI Port EDID version.
        // @details Sets the EDID version used by the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param edidVersion: EDID version
        // @example edidVersion: HDMI_EDID_VER_20
        // @retval Core::ERROR_NONE: HDMI EDID version was set successfully
        virtual Core::hresult SetHDMIEdidVersion(const HDMIInPort port , const HDMIInEdidVersion edidVersion ) = 0;

        /** Get HDMI Video mode. */
        // @text getHDMIVideoMode
        // @brief Get HDMI Video mode.
        // @details Retrieves the current video mode reported for HDMI input.
        // @param videoPortResolution: Video port resolution structure
        // @example videoPortResolution: {"name": "1920x1080p60", "pixelResolution": "DS_HDMIIN_PIXELRES_1920X1080", "aspectRatio": "DS_HDMIIN_ASPECT_RATIO_16X9", "stereoScopicMode": "DS_HDMIIN_SSMODE_2D", "frameRate": "DS_HDMIIN_FRAMERATE_60", "interlaced": false}
        // @retval Core::ERROR_NONE: HDMI video mode was retrieved successfully
        virtual Core::hresult GetHDMIVideoMode( HDMIVideoPortResolution &videoPortResolution /* @out */) = 0;

        /** Get HDMI Supported version. */
        // @text getHDMIVersion
        // @brief Get HDMI Supported Version
        // @details Retrieves the HDMI capability version supported by the specified input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param capabilityVersion: supported capability version
        // @example capabilityVersion: HDMI_COMPATIBILITY_VERSION_21
        // @retval Core::ERROR_NONE: HDMI capability version was retrieved successfully
        virtual Core::hresult GetHDMIVersion(const HDMIInPort port , HDMIInCapabilityVersion &capabilityVersion /* @out */) = 0;

        /** Set HDMI VRR Support. */
        // @text setVRRSupport
        // @brief Set HDMI VRR Support.
        // @details Enables or disables Variable Refresh Rate support for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param vrrSupport: enable (true) or disable (false)
        // @example vrrSupport: true
        // @retval Core::ERROR_NONE: HDMI VRR support was updated successfully
        virtual Core::hresult SetVRRSupport(const HDMIInPort port , const bool vrrSupport ) = 0;

        /** Get HDMI VRR Support. */
        // @text getVRRSupport
        // @brief Get HDMI VRR Support.
        // @details Retrieves whether Variable Refresh Rate support is enabled for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param vrrSupport: enabled (true) or disable (false)
        // @example vrrSupport: true
        // @retval Core::ERROR_NONE: HDMI VRR support status was retrieved successfully
        virtual Core::hresult GetVRRSupport(const HDMIInPort port , bool &vrrSupport /* @out */) = 0;

        /** Get HDMI VRR Status. */
        // @text getVRRStatus
        // @brief Get HDMI VRR Status.
        // @details Retrieves the Variable Refresh Rate type and frame rate for the specified HDMI input port.
        // @param port: Port number
        // @example port: DS_HDMI_IN_PORT_0
        // @param vrrStatus: VRR Status
        // @example vrrStatus: {"vrrType": "DS_HDMIIN_AMD_FREESYNC", "vrrFreeSyncFramerateHz": 60.0}
        // @retval Core::ERROR_NONE: HDMI VRR status was retrieved successfully
        virtual Core::hresult GetVRRStatus(const HDMIInPort port , HDMIInVRRStatus &vrrStatus /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
