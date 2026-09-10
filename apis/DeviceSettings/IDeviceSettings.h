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

#include <vector>

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IDeviceSettings : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS };

        // Audio config structs
        struct AudioTypeConfigInfo {
            int32_t  typeId;
            string   name;
            uint32_t supportedCompressionMask;
            uint32_t supportedEncodingMask;
            uint32_t supportedStereoModeMask;
        };

        struct AudioPortConfigInfo {
            int32_t audioPortType;           /* @brief AudioPortType enum value */
            int32_t audioPortIndex;
            int32_t connectedVideoPortType;
            int32_t connectedVideoPortIndex;
        };

        // Front Panel Display config structs
        struct FPDColorConfig {
            int32_t  id;
            uint32_t color;
        };

        struct FPDIndicatorConfig {
            int32_t id;
            int32_t maxBrightness;
            int32_t maxCycleRate;
            int32_t minBrightness;
            int32_t levels;
            int32_t colorMode;
        };

        struct FPDColorBinding {
            int32_t targetType;
            int32_t targetId;
            int32_t colorId;
        };

        struct FPDTextDisplayConfig {
            int32_t id;
            string  name;
            int32_t maxBrightness;
            int32_t maxCycleRate;
            string  supportedCharacters;
            int32_t columns;
            int32_t rows;
            int32_t maxHorizontalIterations;
            int32_t maxVerticalIterations;
            int32_t levels;
            int32_t colorMode;
        };

        // Video device config struct
        struct VideoDeviceConfigInfo {
            uint32_t numSupportedDFCs;
            uint32_t supportedDFCsMask;
            int32_t  defaultDFC;             /* @brief VideoZoom enum value */
        };

        // Video port config structs
        struct VideoPortTypeConfig {
            int32_t typeId;                  /* @brief VideoPort enum value */
            string  name;
            bool    dtcpSupported;
            bool    hdcpSupported;
            int32_t restrictedResolution;
            string  supportedResolutionNames;
        };

        struct VideoPortPortConfig {
            int32_t videoPortType;           /* @brief VideoPort enum value */
            int32_t videoPortIndex;
            int32_t connectedAudioPortType;
            int32_t connectedAudioPortIndex;
            string  defaultResolution;
        };

        // Video port resolution config struct (populated from the 0th video port type;
        // callers needing resolutions for other types must use GetVideoPortResolutionConfig).
        // SoC configs define dsVideoPortRESOLUTION_NUMMAX = 32 as the absolute ceiling.
        struct VideoPortResolutionConfig {
            string  name;
            int32_t pixelResolution;   /* @brief VideoResolution enum value */
            int32_t aspectRatio;       /* @brief VideoAspectRatio enum value */
            int32_t stereoScopicMode;  /* @brief VideoStereoScopicMode enum value */
            int32_t frameRate;         /* @brief VideoFrameRate enum value */
            bool    interlaced;
        };

        // Consolidated config structure — all static configuration in one place.
        // @restrict values are derived from SoC HAL configs (SoC_A / SoC_B / SoC_R):
        //   audioTypes/audioPorts : SoC_A up to 4 (SPEAKER+ARC+opt SPDIF+HEADPHONE), others 1 → 8
        //   textDisplays          : all SoCs 0 (unused)                                        → 4
        //   indicators            : all SoCs 1 (POWER indicator)                               → 8
        //   colors                : SoC_A up to 6 (HAS_MULTICOLOR_SUPPORT), others 4           → 8
        //   colorBindings         : derived from indicators × colors                           → 16
        //   videoConfigs          : all SoCs 1 device                                          → 4
        //   videoPortTypes/Ports  : all SoCs 1 (HDMI or INTERNAL)                             → 4
        //   videoPortResolutions  : max 18 with 4K; SoC NUMMAX = 32                           → 32
        struct DeviceSettingConfigs {
            std::vector<AudioTypeConfigInfo>        audioTypes            /* @restrict:8 */ ;
            std::vector<AudioPortConfigInfo>        audioPorts            /* @restrict:8 */ ;
            std::vector<FPDTextDisplayConfig>       textDisplays          /* @restrict:4 */ ;
            std::vector<FPDIndicatorConfig>         indicators            /* @restrict:8 */ ;
            std::vector<FPDColorConfig>             colors                /* @restrict:8 */ ;
            std::vector<FPDColorBinding>            colorBindings         /* @restrict:16 */ ;
            std::vector<VideoDeviceConfigInfo>      videoConfigs          /* @restrict:4 */ ;
            std::vector<VideoPortTypeConfig>        videoPortTypes        /* @restrict:4 */ ;
            std::vector<VideoPortPortConfig>        videoPorts            /* @restrict:4 */ ;
            std::vector<VideoPortResolutionConfig>  videoPortResolutions  /* @restrict:32 */ ;
        };

        // @json:omit
        // @text configure
        // @brief Configure DeviceSettings plugin
        // @param service: Framework service interface instance
        // @retval Core::NONE: Indicates successful configuration
        virtual Core::hresult Configure(PluginHost::IShell* service) = 0;

        /** Get all DeviceSettings static configuration in a single call. */
        // @text getDeviceSettingConfigs
        // @brief Get all DeviceSettings static configuration loaded by DeviceSettings plugin.
        // @param configs: structure holding audio, FPD, video device and video port config arrays
        virtual Core::hresult GetDeviceSettingConfigs(DeviceSettingConfigs& configs /* @out */) = 0;

    };

} // namespace Exchange
} // namespace WPEFramework
