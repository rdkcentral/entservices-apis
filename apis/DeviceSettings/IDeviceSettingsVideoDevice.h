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

    struct EXTERNAL IDeviceSettingsVideoDevice : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_VIDEODEVICE };

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

        enum VideoCodec: uint8_t {
            DS_VIDEO_CODEC_MPEGHPART2  = 0x01,
            DS_VIDEO_CODEC_MPEG4PART10 = 0x02,
            DS_VIDEO_CODEC_MPEG2       = 0x04,
            DS_VIDEO_CODEC_MAX         = 0x08
        };

        enum VideoCodecHEVCProfile: uint8_t {
            DS_VIDEO_CODEC_HEVC_PROFILE_MAIN              = 0x01,
            DS_VIDEO_CODEC_HEVC_PROFILE_MAIN10            = 0x02,
            DS_VIDEO_CODEC_HEVC_PROFILE_MAIN_STILLPICTURE = 0x04,
            DS_VIDEO_CODEC_HEVC_PROFILE_MAX               = 0x08
        };

        struct VideoCodecProfileSupport {
            VideoCodecHEVCProfile profile;
            float level;
        };

        using IDeviceSettingsVideoCodecProfileSupportIterator = RPC::IIteratorType<VideoCodecProfileSupport, ID_DEVICESETTINGS_VIDEO_CODEC_PROFILE_ITERATOR>;

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_VIDEODEVICE_NOTIFICATION };

            // @brief Zoom settings changed
            // @text OnZoomSettingsChanged
            // @param zoomSetting: Currently applied zoom setting
            virtual void OnZoomSettingsChanged(const VideoZoom zoomSetting) {};

            // @brief Display Framerate Pre-change
            // @text OnDisplayFrameratePreChange
            // @param frameRate: PreChange framerate
            virtual void OnDisplayFrameratePreChange(const string frameRate) {};

            // @brief Display Framerate Post-change
            // @text OnDisplayFrameratePostChange
            // @param frameRate:  framerate post change
            virtual void OnDisplayFrameratePostChange(const string frameRate) {};

        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsVideoDevice::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsVideoDevice::INotification* notification ) = 0;

        /** Get Video Device handle. */
        // @text getVideoDeviceHandle
        // @brief Get Video device handle
        // @param index: index (can be multiple instances)
        // @param handle: video device handle (to be used for other APIs)
        virtual Core::hresult GetVideoDeviceHandle(const int32_t index , int32_t &handle /* @out */) = 0;

        /** Set Video Device DFC. */
        // @text setVideoDeviceDFC
        // @brief Set Video Device DFC
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param zoomSetting: Zoom setting to apply
        virtual Core::hresult SetVideoDeviceDFC(const int32_t handle , const VideoZoom zoomSetting ) = 0;

        /** Get Video Device DFC. */
        // @text getVideoDeviceDFC
        // @brief Get Video Device DFC
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param zoomSetting: current Zoom setting
        virtual Core::hresult GetVideoDeviceDFC(const int32_t handle , VideoZoom &zoomSetting /* @out */) = 0;

        /** Get Video Device HDR capabilities. */
        // @text getHDRCapabilities
        // @brief Get Video Device HDR capabilities
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param capabilities: Capabilities
        virtual Core::hresult GetHDRCapabilities(const int32_t handle , int32_t &capabilities /* @out */) = 0;

        /** Get Video Device Supported . */
        // @text getSupportedVideoCodingFormats
        // @brief Get Video Zoom setting
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param supportedFormats: Supported Formats
        virtual Core::hresult GetSupportedVideoCodingFormats(const int32_t handle , int32_t &supportedFormats /* @out */) = 0;

        /** Get Video Device Codec Information  */
        // @text getCodecInfo
        // @brief Get Video Device Codec Information
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param videoCodec: Video codec for which information is needed
        // @param videoCodecInfo: Video codec information
        virtual Core::hresult GetCodecInfo(const int32_t handle , const VideoCodec videoCodec , IDeviceSettingsVideoCodecProfileSupportIterator *&codecInfo /* @out */) = 0;

        /** Video Device Disable HDR */
        // @text disableHDR
        // @brief Video Device Disable HDR
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param disable: disable (true) or enable (false)
        virtual Core::hresult DisableHDR(const int32_t handle , const bool disable ) = 0;

        /** Set Video Device FRF mode. */
        // @text setFRFMode
        // @brief Set FRF mode
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult SetFRFMode(const int32_t handle , const int32_t frfmode ) = 0;

        /** Get Video Device FRF mode. */
        // @text getFRFMode
        // @brief Get FRF mode
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param frfmode: FRF mode
        virtual Core::hresult GetFRFMode(const int32_t handle , int32_t &frfmode /* @out */) = 0;

        /** Get Video Device display frame rate */
        // @text getCurrentDisplayFrameRate
        // @brief Get current display frame rate
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param framerate: frame rate
        virtual Core::hresult GetCurrentDisplayFrameRate(const int32_t handle , string &framerate /* @out */) = 0;

        /** Set Video Device display frame rate */
        // @text setDisplayFrameRate
        // @brief Set current display frame rate
        // @param handle: video device handle (returned in GetVideoDeviceHandle)
        // @param framerate: frame rate
        virtual Core::hresult SetDisplayFrameRate(const int32_t handle , const string framerate ) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
