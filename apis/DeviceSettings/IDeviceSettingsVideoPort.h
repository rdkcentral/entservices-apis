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

    struct EXTERNAL IDeviceSettingsVideoPort : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_VIDEOPORT };

        enum VideoPort : uint8_t {
            DS_VIDEO_PORT_TYPE_RF          = 0,
            DS_VIDEO_PORT_TYPE_BB          = 1,
            DS_VIDEO_PORT_TYPE_SVIDEO      = 2,
            DS_VIDEO_PORT_TYPE_1394        = 3,
            DS_VIDEO_PORT_TYPE_DVI         = 4,
            DS_VIDEO_PORT_TYPE_COMPONENT   = 5,
            DS_VIDEO_PORT_TYPE_HDMI        = 6,
            DS_VIDEO_PORT_TYPE_HDMI_INPUT  = 7,
            DS_VIDEO_PORT_TYPE_INTERNAL    = 8,
            DS_VIDEO_PORT_TYPE_MAX         = 9
        };

        enum VideoPortSurroundMode: uint8_t {
            DS_VIDEO_PORT_SURROUNDMODE_NONE    = 0,
            DS_VIDEO_PORT_SURROUNDMODE_DD      = 1,
            DS_VIDEO_PORT_SURROUNDMODE_DDPLUS  = 2,
            DS_VIDEO_PORT_SURROUNDMODE_MAX     = 3
        };

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
            DS_TV_RESOLUTION_1080P30  = 0x001000,
            DS_TV_RESOLUTION_1080I50  = 0x002000,
            DS_TV_RESOLUTION_1080P50  = 0x004000,
            DS_TV_RESOLUTION_1080P60  = 0x008000,
            DS_TV_RESOLUTION_2160P24  = 0x010000,
            DS_TV_RESOLUTION_2160P25  = 0x020000,
            DS_TV_RESOLUTION_2160P30  = 0x040000,
            DS_TV_RESOLUTION_2160P50  = 0x080000,
            DS_TV_RESOLUTION_2160P60  = 0x100000
        };

        enum VideoResolution: uint8_t {
            DS_VIDEO_PIXELRES_720X480    = 0,
            DS_VIDEO_PIXELRES_720X576    = 1,
            DS_VIDEO_PIXELRES_1280X720   = 2,
            DS_VIDEO_PIXELRES_1366X768   = 3,
            DS_VIDEO_PIXELRES_1920X1080  = 4,
            DS_VIDEO_PIXELRES_3840X2160  = 5,
            DS_VIDEO_PIXELRES_4096X2160  = 6,
            DS_VIDEO_PIXELRES_MAX        = 7
        };

        enum VideoAspectRatio: uint8_t {
            DS_VIDEO_ASPECT_RATIO_4X3    = 0,
            DS_VIDEO_ASPECT_RATIO_16X9   = 1,
            DS_VIDEO_ASPECT_RATIO_MAX    = 2
        };

        enum VideoStereoScopicMode : uint8_t {
            DS_VIDEO_SSMODE_UNKNOWN           = 0,
            DS_VIDEO_SSMODE_2D                = 1,
            DS_VIDEO_SSMODE_3D_SIDE_BY_SIDE   = 2,
            DS_VIDEO_SSMODE_3D_TOP_AND_BOTTOM = 3,
            DS_VIDEO_SSMODE_MAX               = 4
        };

        enum VideoFrameRate: uint8_t {
            DS_VIDEO_FRAMERATE_UNKNOWN   = 0,
            DS_VIDEO_FRAMERATE_24        = 1,
            DS_VIDEO_FRAMERATE_25        = 2,
            DS_VIDEO_FRAMERATE_30        = 3,
            DS_VIDEO_FRAMERATE_60        = 4,
            DS_VIDEO_FRAMERATE_23_98     = 5,
            DS_VIDEO_FRAMERATE_29_97     = 6,
            DS_VIDEO_FRAMERATE_50        = 7,
            DS_VIDEO_FRAMERATE_59_94     = 8,
            DS_VIDEO_FRAMERATE_100       = 9,
            DS_VIDEO_FRAMERATE_119_88    = 10,
            DS_VIDEO_FRAMERATE_120       = 11,
            DS_VIDEO_FRAMERATE_200       = 12,
            DS_VIDEO_FRAMERATE_239_76    = 13,
            DS_VIDEO_FRAMERATE_240       = 14,
            DS_VIDEO_FRAMERATE_MAX       = 15
        };

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
            DS_HDCP_STATUS_PORTDISABLED           = 5,
            DS_HDCP_STATUS_MAX                    = 6
        };

        enum HDCPProtocolVersion: uint8_t {
            DS_HDCP_VERSION_1X  = 0,  
            DS_HDCP_VERSION_2X  = 1,
            DS_HDCP_VERSION_MAX = 2
        };

        enum HDRStandard: uint16_t {
            DS_HDRSTANDARD_NONE             = 0x0,
            DS_HDRSTANDARD_HDR10            = 0x01,
            DS_HDRSTANDARD_HLG              = 0x02,
            DS_HDRSTANDARD_DOLBYVISION      = 0x04,
            DS_HDRSTANDARD_TECHNICOLORPRIME = 0x08,
            DS_HDRSTANDARD_HDR10PLUS        = 0x10,
            DS_HDRSTANDARD_SDR              = 0x20,
            DS_HDRSTANDARD_INVALID          = 0x80
        };

        enum DisplayMatrixCoefficients: uint8_t {
            DS_DISPLAY_MATRIXCOEFFICIENT_UNKNOWN        = 0,
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_709         = 1,
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_470_2_BG    = 2,
            DS_DISPLAY_MATRIXCOEFFICIENT_SMPTE_170M     = 3,
            DS_DISPLAY_MATRIXCOEFFICIENT_XVYCC_709      = 4,
            DS_DISPLAY_MATRIXCOEFFICIENT_EXVYCC_601     = 5,
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_2020_NCL    = 6,
            DS_DISPLAY_MATRIXCOEFFICIENT_BT_2020_CL     = 7,
            DS_DISPLAY_MATRIXCOEFFICIENT_EDVI_FR_RGB    = 8,
            DS_DISPLAY_MATRIXCOEFFICIENT_EHDMI_RGB      = 9,
            DS_DISPLAY_MATRIXCOEFFICIENT_EFCC           = 10,
            DS_DISPLAY_MATRIXCOEFFICIENT_ESMPTE_240M    = 11,
            DS_DISPLAY_MATRIXCOEFFICIENT_EHDMI_FR_YCBCR = 12,
            DS_DISPLAY_MATRIXCOEFFICIENT_MAX            = 13
        };

        enum DisplayColorSpace: uint8_t {
            DS_DISPLAY_COLORSPACE_UNKNOWN  = 0,
            DS_DISPLAY_COLORSPACE_RGB      = 1,
            DS_DISPLAY_COLORSPACE_YCBCR422 = 2,
            DS_DISPLAY_COLORSPACE_YCBCR444 = 3,
            DS_DISPLAY_COLORSPACE_YCBCR420 = 4,
            DS_DISPLAY_COLORSPACE_AUTO     = 5,
            DS_DISPLAY_COLORSPACE_MAX      = 6
        };

        enum DisplayQuantizationRange: uint8_t {
            DS_DISPLAY_QUANTIZATIONRANGE_UNKNOWN = 0,
            DS_DISPLAY_QUANTIZATIONRANGE_LIMITED = 1,
            DS_DISPLAY_QUANTIZATIONRANGE_FULL    = 2,
            DS_DISPLAY_QUANTIZATIONRANGE_MAX     = 3
        };

        enum DisplayColorDepth : uint8_t {
            DS_DISPLAY_COLORDEPTH_UNKNOWN = 0x0,
            DS_DISPLAY_COLORDEPTH_8BIT    = 0x01,
            DS_DISPLAY_COLORDEPTH_10BIT   = 0x02,
            DS_DISPLAY_COLORDEPTH_12BIT   = 0x04,
            DS_DISPLAY_COLORDEPTH_AUTO    = 0x08,
            DS_DISPLAY_COLORDEPTH_MAX     = 0x10
        };

        struct DSOutputSettings {
            HDRStandard videoEotf;
            DisplayMatrixCoefficients matrixCoefficients;
            uint32_t colorDepth;
            DisplayColorSpace colorSpace;
            DisplayQuantizationRange quantizationRange;
        };

         enum VideoBackgroundColor : uint8_t {
            DS_VIDEO_BGCOLOR_BLUE   = 0,
            DS_VIDEO_BGCOLOR_BLACK  = 1,
            DS_VIDEO_BGCOLOR_NONE   = 2,
            DS_VIDEO_BGCOLOR_MAX    = 3
        };

        enum VideoScanMode: uint8_t {
            DS_VIDEO_SCAN_MODE_INTERLACED = 0,
            DS_VIDEO_SCAN_MODE_PROGRESSIVE = 1
        };

        struct ResolutionChange {
            uint32_t width;
            uint32_t height;
        };

        struct VideoPortTypeConfig {
            VideoPort typeId;
            string name;
            bool dtcpSupported;
            bool hdcpSupported;
            int32_t restrictedResolution;
            string supportedResolutionNames;
        };

        struct VideoPortPortConfig {
            VideoPort videoPortType;
            int32_t videoPortIndex;
            int32_t connectedAudioPortType;
            int32_t connectedAudioPortIndex;
            string defaultResolution;
        };


        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_VIDEOPORT_NOTIFICATION };

            // @brief On Resolution Post change
            // @text onResolutionPostChange
            // @details Notifies clients after the video output resolution changes.
            // @param resolution: resolution
            // @example resolution: {"width": 1920, "height": 1080}
            virtual void OnResolutionPostChange(const ResolutionChange& resolution) {};

            // @brief On Resolution Pre change
            // @text onResolutionPreChange
            // @details Notifies clients before the video output resolution changes.
            // @param resolution: resolution
            // @example resolution: {"width": 1920, "height": 1080}
            virtual void OnResolutionPreChange(const ResolutionChange& resolution) {};

            // @brief On HDCP Status change 
            // @text onHDCPStatusChange
            // @details Notifies clients when the HDCP authentication status changes.
            // @param hdcpStatus: HDCP Status
            // @example hdcpStatus: DS_HDCP_STATUS_AUTHENTICATED
            virtual void OnHDCPStatusChange(const HDCPStatus hdcpStatus) {};

            // @brief On Video Format update 
            // @text onVideoFormatUpdate
            // @details Notifies clients when the HDR video format changes.
            // @param videoFormatHDR: Video format HDR standard
            // @example videoFormatHDR: DS_HDRSTANDARD_HDR10
            virtual void OnVideoFormatUpdate(const HDRStandard videoFormatHDR) {};
        };

        // @brief Register for video port notifications.
        // @details Subscribes a client notification listener to video port events.
        // @param clientName: Name identifying the client registering for notifications.
        // @example clientName: "VideoPortClient"
        // @param notification: Listener that receives video port events.
        // @example notification: IDeviceSettingsVideoPort::INotification instance
        // @retval Core::ERROR_NONE: Notification listener was registered successfully
        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsVideoPort::INotification* notification ) = 0;

        // @brief Unregister from video port notifications.
        // @details Removes a client notification listener from video port events.
        // @param notification: Listener to remove from the subscription.
        // @example notification: IDeviceSettingsVideoPort::INotification instance
        // @retval Core::ERROR_NONE: Notification listener was unregistered successfully
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsVideoPort::INotification* notification ) = 0;

        /** Get Video Port handle. */
        // @text getVideoPort
        // @brief Get Video Port handle
        // @details Retrieves the handle for a video port identified by its type and index.
        // @param videoPort: Type of port
        // @example videoPort: DS_VIDEO_PORT_TYPE_HDMI
        // @param index: index of the port (there can be multiple number of ports)
        // @example index: 0
        // @param handle: handle to the port
        // @example handle: 1
        // @retval Core::ERROR_NONE: Video port handle was retrieved successfully
        virtual Core::hresult GetVideoPort(const VideoPort videoPort , const int32_t index , int32_t &handle /* @out */) = 0;

        using IVideoPortResolutionIterator = RPC::IIteratorType<VideoPortResolution, ID_DEVICESETTINGS_VIDEOPORT_RESOLUTION_ITERATOR>;

        /** Get Video Port Resolution static configuration for a specific port type. */
        // @text getVideoPortResolutionConfig
        // @brief Get VideoPort resolution static configuration for a given port type.
        //        GetDeviceSettingConfigs() only returns resolutions for the 0th port type;
        //        callers needing resolutions for other types must use this method.
        // @details Retrieves the supported static resolution configurations for the specified video port type.
        // @param videoPortType: video port type to query
        // @example videoPortType: DS_VIDEO_PORT_TYPE_HDMI
        // @param videoPortResolutions: iterator of supported resolution settings
        // @example videoPortResolutions: [{"name": "1920x1080p60", "pixelResolution": "DS_VIDEO_PIXELRES_1920X1080", "aspectRatio": "DS_VIDEO_ASPECT_RATIO_16X9", "stereoScopicMode": "DS_VIDEO_SSMODE_2D", "frameRate": "DS_VIDEO_FRAMERATE_60", "interlaced": false}]
        // @retval Core::ERROR_NONE: Video port resolution configurations were retrieved successfully
        virtual Core::hresult GetVideoPortResolutionConfig(VideoPort videoPortType,
                             IVideoPortResolutionIterator*& videoPortResolutions /* @out */) const = 0;

        /** Video Port Enabled or not. */
        // @text isVideoPortEnabled
        // @brief Is Video Port enabled
        // @details Checks whether the specified video port is enabled.
        // @param handle: handle to the port
        // @example handle: 1
        // @param enabled: enabled (true) or disabled (false)
        // @example enabled: true
        // @retval Core::ERROR_NONE: Video port enabled state was retrieved successfully
        virtual Core::hresult IsVideoPortEnabled(const int32_t handle , bool &enabled /* @out */) = 0;

        /** Video Port connected to display or not. */
        // @text isVideoPortDisplayConnected
        // @brief Is Video Port connected to display or not
        // @details Checks whether a display is connected to the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param connected: connected (true) or not connected (false)
        // @example connected: true
        // @retval Core::ERROR_NONE: Video port display connection state was retrieved successfully
        virtual Core::hresult IsVideoPortDisplayConnected(const int32_t handle , bool &connected /* @out */) = 0;

        /** Video port display supports surround or not. */
        // @text isVideoPortDisplaySurround
        // @brief Does Video Port display support surround or not
        // @details Checks whether the display connected to the specified video port supports surround audio.
        // @param handle: handle to the port
        // @example handle: 1
        // @param surround: supports surround (true) or not (false)
        // @example surround: true
        // @retval Core::ERROR_NONE: Display surround support was retrieved successfully
        virtual Core::hresult IsVideoPortDisplaySurround(const int32_t handle , bool &surround /* @out */) = 0;

        /** Get Video port displays surround mode. */
        // @text getVideoPortDisplaySurroundMode
        // @brief Get Video port displays surround mode
        // @details Retrieves the surround audio mode reported by the display connected to the video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param surroundMode: surround mode
        // @example surroundMode: DS_VIDEO_PORT_SURROUNDMODE_DDPLUS
        // @retval Core::ERROR_NONE: Display surround mode was retrieved successfully
        virtual Core::hresult GetVideoPortDisplaySurroundMode(const int32_t handle , VideoPortSurroundMode &surroundMode /* @out */) = 0;

        /** Enable Video port. */
        // @text enableVideoPort
        // @brief Enable video port
        // @details Enables or disables the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param enable: enable (true) or disable (false) 
        // @example enable: true
        // @retval Core::ERROR_NONE: Video port state was updated successfully
        virtual Core::hresult EnableVideoPort(const int32_t handle , const bool enable ) = 0;

        /** Get Video port resolution. */
        // @text getVideoPortResolution
        // @brief Get Video port resolution
        // @details Retrieves the current resolution configured for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param videoPortResolution: video port resolution
        // @example videoPortResolution: {"name": "1920x1080p60", "pixelResolution": "DS_VIDEO_PIXELRES_1920X1080", "aspectRatio": "DS_VIDEO_ASPECT_RATIO_16X9", "stereoScopicMode": "DS_VIDEO_SSMODE_2D", "frameRate": "DS_VIDEO_FRAMERATE_60", "interlaced": false}
        // @retval Core::ERROR_NONE: Video port resolution was retrieved successfully
        virtual Core::hresult GetVideoPortResolution(const int32_t handle , VideoPortResolution &videoPortResolution /* @out */) = 0;

        /** Set Video port resolution. */
        // @text setVideoPortResolution
        // @brief Set Video port resolution
        // @details Sets the resolution for the specified video port, optionally persisting it or forcing compatibility.
        // @param handle: handle to the port
        // @example handle: 1
        // @param videoPortResolution: video port resolution 
        // @example videoPortResolution: {"name": "1920x1080p60", "pixelResolution": "DS_VIDEO_PIXELRES_1920X1080", "aspectRatio": "DS_VIDEO_ASPECT_RATIO_16X9", "stereoScopicMode": "DS_VIDEO_SSMODE_2D", "frameRate": "DS_VIDEO_FRAMERATE_60", "interlaced": false}
        // @param persist: persist this setting
        // @example persist: true
        // @param forceCompatibility: force compatibility
        // @example forceCompatibility: false
        // @retval Core::ERROR_NONE: Video port resolution was set successfully
        virtual Core::hresult SetVideoPortResolution(const int32_t handle , const VideoPortResolution& videoPortResolution , const bool persist , const bool forceCompatibility ) = 0;

        /** Enable HDCP Video port. */
        // @text enableHDCPOnVideoPort
        // @brief Enable HDCP on video port
        // @details Enables or disables HDCP on the specified video port using the supplied key data.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpEnable: enable (true) or disable (false) 
        // @example hdcpEnable: true
        // @param hdcpKey: hdcp key 
        // @example hdcpKey: [0, 1, 2, 3]
        // @param hdcpKeySize: number of bytes in hdcpKey array
        // @example hdcpKeySize: 4
        // @retval Core::ERROR_NONE: HDCP state was updated successfully
        virtual Core::hresult EnableHDCPOnVideoPort(const int32_t handle , const bool hdcpEnable , const uint8_t hdcpKey[] /* @length:hdcpKeySize */, const uint16_t hdcpKeySize ) = 0;

        /** Is HDCP enabled on Video port. */
        // @text isHDCPEnabledOnVideoPort
        // @brief Is HDCP enabled on Video port
        // @details Checks whether HDCP is enabled on the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpEnabled: enabled (true) or disabled (false) 
        // @example hdcpEnabled: true
        // @retval Core::ERROR_NONE: HDCP enabled state was retrieved successfully
        virtual Core::hresult IsHDCPEnabledOnVideoPort(const int32_t handle , bool &hdcpEnabled /* @out */) = 0;

        /**  Get HDCP Status on Video port. */
        // @text getHDCPStatusOnVideoPort
        // @brief Get HDCP Status on Video port
        // @details Retrieves the current HDCP authentication status of the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpStatus: HDCP status
        // @example hdcpStatus: DS_HDCP_STATUS_AUTHENTICATED
        // @retval Core::ERROR_NONE: HDCP status was retrieved successfully
        virtual Core::hresult GetHDCPStatusOnVideoPort(const int32_t handle , HDCPStatus &hdcpStatus /* @out */) = 0;

        /**  Get HDCP Protocol version on Video port. */
        // @text getHDCPProtocolVersionOnVideoPort
        // @brief Get HDCP Protocol version on Video port
        // @details Retrieves the configured HDCP protocol version for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpVersion: HDCP version
        // @example hdcpVersion: DS_HDCP_VERSION_2X
        // @retval Core::ERROR_NONE: HDCP protocol version was retrieved successfully
        virtual Core::hresult GetHDCPProtocolVersionOnVideoPort(const int32_t handle , HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Get HDCP Receiver Protocol version on Video port. */
        // @text getHDCPReceiverProtocolVersionOnVideoPort
        // @brief Get HDCP Receiver Protocol version on Video port
        // @details Retrieves the HDCP protocol version supported by the receiver connected to the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpVersion: HDCP version
        // @example hdcpVersion: DS_HDCP_VERSION_2X
        // @retval Core::ERROR_NONE: Receiver HDCP protocol version was retrieved successfully
        virtual Core::hresult GetHDCPReceiverProtocolVersionOnVideoPort(const int32_t handle , HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Get HDCP Current Protocol version on Video port. */
        // @text getHDCPCurrentProtocolVersionOnVideoPort
        // @brief Get HDCP Current Protocol version on Video port
        // @details Retrieves the HDCP protocol version currently active on the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpVersion: HDCP version
        // @example hdcpVersion: DS_HDCP_VERSION_2X
        // @retval Core::ERROR_NONE: Current HDCP protocol version was retrieved successfully
        virtual Core::hresult GetHDCPCurrentProtocolVersionOnVideoPort(const int32_t handle , HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /** Is Video port active. */
        // @text isVideoPortActive
        // @brief Is Video port active
        // @details Checks whether the specified video port is active.
        // @param handle: handle to the port
        // @example handle: 1
        // @param active: active (true) or inactive (false) 
        // @example active: true
        // @retval Core::ERROR_NONE: Video port active state was retrieved successfully
        virtual Core::hresult IsVideoPortActive(const int32_t handle , bool &active /* @out */) = 0;

        /**  Get TVs HDR capabilities. */
        // @text getTVHDRCapabilities
        // @brief Get TVs HDR capabilities
        // @details Retrieves the HDR standards supported by the display connected to the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param capabilities: capabilities (masked value) - see HDRStandard
        // @example capabilities: 3
        // @retval Core::ERROR_NONE: Display HDR capabilities were retrieved successfully
        virtual Core::hresult GetTVHDRCapabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /**  Get TVs supported resolutions. */
        // @text getTVSupportedResolutions
        // @brief  Get TVs supported resolutions
        // @details Retrieves the resolutions supported by the display connected to the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param resolutions: resolutions (masked value) - see TVResolution
        // @example resolutions: 98304
        // @retval Core::ERROR_NONE: Display supported resolutions were retrieved successfully
        virtual Core::hresult GetTVSupportedResolutions(const int32_t handle , int32_t &resolutions /* @out */) = 0;

        /** Set Disable 4K. */
        // @text setForceDisable4K
        // @brief Force disable 4K
        // @details Enables or disables the forced restriction of 4K output on the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param disable: disable (true) or enable (false) 
        // @example disable: true
        // @retval Core::ERROR_NONE: Force-disable-4K setting was updated successfully
        virtual Core::hresult SetForceDisable4K(const int32_t handle , const bool disable ) = 0;

        /** Get Disable 4K status. */
        // @text getForceDisable4K
        // @brief Get Force disable 4K value
        // @details Retrieves whether 4K output is forcibly disabled on the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param disabled: disabled (true) or enabled (false) 
        // @example disabled: true
        // @retval Core::ERROR_NONE: Force-disable-4K state was retrieved successfully
        virtual Core::hresult GetForceDisable4K(const int32_t handle , bool &disabled /* @out */) = 0;

        /** Is Video port output HDR?. */
        // @text isVideoPortOutputHDR
        // @brief Is Video port output HDR?
        // @details Checks whether the specified video port is currently outputting HDR video.
        // @param handle: handle to the port
        // @example handle: 1
        // @param isHDR: yes (true) or no (false) 
        // @example isHDR: true
        // @retval Core::ERROR_NONE: Video port HDR output state was retrieved successfully
        virtual Core::hresult IsVideoPortOutputHDR(const int32_t handle , bool &isHDR /* @out */) = 0;

        /** Reset Video port output to SDR. */
        // @text resetVideoPortOutputToSDR
        // @brief Reset Video port output to SDR
        // @details Resets video output to standard dynamic range (SDR).
        // @retval Core::ERROR_NONE: Video output was reset to SDR successfully
        virtual Core::hresult ResetVideoPortOutputToSDR() = 0;

        /**  Get HDMI preferred HDCP protocol version. */
        // @text getHDMIPreference
        // @brief Get HDMI preferred HDCP protocol version
        // @details Retrieves the preferred HDCP protocol version for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpVersion: HDCP version
        // @example hdcpVersion: DS_HDCP_VERSION_2X
        // @retval Core::ERROR_NONE: Preferred HDCP protocol version was retrieved successfully
        virtual Core::hresult GetHDMIPreference(const int32_t handle , HDCPProtocolVersion &hdcpVersion /* @out */) = 0;

        /**  Set HDMI preferred HDCP protocol version. */
        // @text setHDMIPreference
        // @brief Set HDMI preferred HDCP protocol version
        // @details Sets the preferred HDCP protocol version for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdcpVersion: HDCP version
        // @example hdcpVersion: DS_HDCP_VERSION_2X
        // @retval Core::ERROR_NONE: Preferred HDCP protocol version was set successfully
        virtual Core::hresult SetHDMIPreference(const int32_t handle , const HDCPProtocolVersion hdcpVersion ) = 0;

        /**  Get Video EOTF. */
        // @text getVideoEOTF
        // @brief Get video EOTF
        // @details Retrieves the electro-optical transfer function (EOTF) HDR standard for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdrStandard: see HDRStandard
        // @example hdrStandard: DS_HDRSTANDARD_HDR10
        // @retval Core::ERROR_NONE: Video EOTF was retrieved successfully
        virtual Core::hresult GetVideoEOTF(const int32_t handle , HDRStandard &hdrStandard /* @out */) = 0;

        /**  Get Matrix coefficients. */
        // @text getMatrixCoefficients
        // @brief Get Matrix coefficients
        // @details Retrieves the display matrix coefficients for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param matrixCoefficients: see DisplayMatrixCoefficients
        // @example matrixCoefficients: DS_DISPLAY_MATRIXCOEFFICIENT_BT_709
        // @retval Core::ERROR_NONE: Display matrix coefficients were retrieved successfully
        virtual Core::hresult GetMatrixCoefficients(const int32_t handle , DisplayMatrixCoefficients &matrixCoefficients /* @out */) = 0;
                
        /**  Get Color Depth. */
        // @text getColorDepth
        // @brief Get Color Depth
        // @details Retrieves the current color depth for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param colorDepth: color depth See DisplayColorDepth (masked)
        // @example colorDepth: 2
        // @retval Core::ERROR_NONE: Color depth was retrieved successfully
        virtual Core::hresult GetColorDepth(const int32_t handle , uint32_t &colorDepth /* @out */) = 0;

        /**  Get Color Space. */
        // @text getColorSpace
        // @brief Get Color Space
        // @details Retrieves the current color space for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param colorSpace: color space
        // @example colorSpace: DS_DISPLAY_COLORSPACE_RGB
        // @retval Core::ERROR_NONE: Color space was retrieved successfully
        virtual Core::hresult GetColorSpace(const int32_t handle , DisplayColorSpace &colorSpace /* @out */) = 0;

        /**  Get Quantization Range. */
        // @text getQuantizationRange
        // @brief Get Quantization range
        // @details Retrieves the current quantization range for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param quantizationRange: quantization range
        // @example quantizationRange: DS_DISPLAY_QUANTIZATIONRANGE_FULL
        // @retval Core::ERROR_NONE: Quantization range was retrieved successfully
        virtual Core::hresult GetQuantizationRange(const int32_t handle , DisplayQuantizationRange &quantizationRange /* @out */) = 0;

        /**  Get Current output settings. */
        // @text getCurrentOutputSettings
        // @brief Get Current output settings
        // @details Retrieves the current HDR and color output settings for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param outputSettings: Output settings 
        // @example outputSettings: {"videoEotf": "DS_HDRSTANDARD_HDR10", "matrixCoefficients": "DS_DISPLAY_MATRIXCOEFFICIENT_BT_709", "colorDepth": 2, "colorSpace": "DS_DISPLAY_COLORSPACE_RGB", "quantizationRange": "DS_DISPLAY_QUANTIZATIONRANGE_FULL"}
        // @retval Core::ERROR_NONE: Current output settings were retrieved successfully
        virtual Core::hresult GetCurrentOutputSettings(const int32_t handle , DSOutputSettings &outputSettings /* @out */) = 0;

        /**  Set Video background color. */
        // @text setBackgroundColor
        // @brief Set Video background color.
        // @details Sets the background color used by the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param backgroundColor: video background color
        // @example backgroundColor: DS_VIDEO_BGCOLOR_BLACK
        // @retval Core::ERROR_NONE: Video background color was set successfully
        virtual Core::hresult SetBackgroundColor(const int32_t handle , const VideoBackgroundColor backgroundColor ) = 0;

        /**  Set HDR mode. */
        // @text setForceHDRMode
        // @brief Set HDR mode 
        // @details Forces the specified HDR standard on the video output for the selected port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param hdrMode: see HDRStandard
        // @example hdrMode: DS_HDRSTANDARD_HDR10
        // @retval Core::ERROR_NONE: Forced HDR mode was set successfully
        virtual Core::hresult SetForceHDRMode(const int32_t handle , const HDRStandard hdrMode ) = 0;

        /**  Get Color Depth capabilities. */
        // @text getColorDepthCapabilities
        // @brief Get Color Depth capabilities
        // @details Retrieves the color depths supported by the display connected to the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param colorDepthCapabilities: color depth capabilities See DisplayColorDepth (masked)
        // @example colorDepthCapabilities: 7
        // @retval Core::ERROR_NONE: Color depth capabilities were retrieved successfully
        virtual Core::hresult GetColorDepthCapabilities(const int32_t handle , uint32_t &colorDepthCapabilities /* @out */) = 0;

        /**  Get Preferred Color Depth. */
        // @text getPreferredColorDepth
        // @brief Get Preferred Color Depth
        // @details Retrieves the persisted or active preferred color depth for the specified video port.
        // @param handle: handle to the port
        // @example handle: 1
        // @param colorDepth: color depth See DisplayColorDepth 
        // @example colorDepth: DS_DISPLAY_COLORDEPTH_10BIT
        // @param persist: return persisted value (true) or not (false)
        // @example persist: true
        // @retval Core::ERROR_NONE: Preferred color depth was retrieved successfully
        virtual Core::hresult GetPreferredColorDepth(const int32_t handle , DisplayColorDepth &colorDepth /* @out */, const bool persist ) = 0;
        
        /**  Set Preferred Color Depth. */
        // @text setPreferredColorDepth
        // @brief Set Preferred Color Depth
        // @details Sets the preferred color depth for the specified video port, optionally persisting the setting.
        // @param handle: handle to the port
        // @example handle: 1
        // @param colorDepth: color depth See DisplayColorDepth 
        // @example colorDepth: DS_DISPLAY_COLORDEPTH_10BIT
        // @param persist:  persist value (true) or not (false)
        // @example persist: true
        // @retval Core::ERROR_NONE: Preferred color depth was set successfully
        virtual Core::hresult SetPreferredColorDepth(const int32_t handle , const DisplayColorDepth colorDepth , const bool persist ) = 0;

    };

} // namespace Exchange
} // namespace WPEFramework
