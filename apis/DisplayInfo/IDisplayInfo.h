/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

    /* @json */
    struct EXTERNAL IGraphicsProperties : virtual public Core::IUnknown {
        enum { ID = ID_GRAPHICS_PROPERTIES };

        // @property
        // @brief Total GPU DRAM memory (in bytes)
        // @details Retrieves the total GPU DRAM memory (in bytes).
        // @param total: Total GPU RAM
        // @example total: 2147483648
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult TotalGpuRam(uint64_t& total /* @out */) const = 0;

        // @property
        // @brief Free GPU DRAM memory (in bytes)
        // @details Retrieves the free GPU DRAM memory (in bytes).
        // @param free: Free GPU RAM
        // @example free: 1073741824
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult FreeGpuRam(uint64_t& free /* @out */) const = 0;
    };

    /* @json @uncompliant:extended */  // NOTE: extended format is deprecated!! Do not just copy this line!
    struct EXTERNAL IConnectionProperties : virtual public Core::IUnknown {
        enum { ID = ID_CONNECTION_PROPERTIES };

        enum HDCPProtectionType : uint8_t {
            HDCP_UNENCRYPTED,
            HDCP_1X,
            HDCP_2X,
            HDCP_AUTO
        };

        /* @event @uncompliant:extended */  // NOTE: extended format is deprecated!! Do not just copy this line!
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_CONNECTION_PROPERTIES_NOTIFICATION };

            enum Source : uint8_t {
                PRE_RESOLUTION_CHANGE,
                POST_RESOLUTION_CHANGE,
                HDMI_CHANGE,
                HDCP_CHANGE,
            };

            virtual void Updated(const Source event) = 0;
        };

        virtual Core::hresult Register(INotification*) = 0;
        virtual Core::hresult Unregister(INotification*) = 0;

        // @property
        // @brief Current audio passthrough status on HDMI
        // @details Retrieves the current audio passthrough status on HDMI.
        // @param passthru: enabled/disabled
        // @example passthru: true
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult IsAudioPassthrough (bool& passthru /* @out */) const = 0;

        // @property
        // @brief Current HDMI connection status
        // @details Retrieves the current HDMI connection status.
        // @param isconnected: connected/disconnected
        // @example isconnected: true
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult Connected(bool& isconnected /* @out */) const = 0;

        // @property
        // @brief Horizontal resolution of TV
        // @details Retrieves the horizontal resolution of the TV.
        // @param width: Width of TV in pixels
        // @example width: 1920
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult Width(uint32_t& width /* @out */) const = 0;

        // @property
        // @brief Vertical resolution of TV
        // @details Retrieves the vertical resolution of the TV.
        // @param height: Height of TV in pixels
        // @example height: 1080
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult Height(uint32_t& height /* @out */) const = 0;

        // @property
        // @brief Vertical Frequency
        // @details Retrieves the vertical frequency of the TV.
        // @param vf: Vertical frequency
        // @example vf: 60
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult VerticalFreq(uint32_t& vf /* @out */) const = 0;

        // @brief TV's Extended Display Identification Data
        // @details Retrieves the TV's Extended Display Identification Data (EDID) as a byte string.
        // @param length: length of edid byte string
        // @example length: 2
		// @param data: EDID byte string
        // @example data: [0x00,0xFF,0xFF,0xFF]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult EDID (uint16_t& length /* @inout */, uint8_t data[] /* @out @length:length */) const = 0;

        // @brief Horizontal size in centimeters
        // @details Retrieves the horizontal size of the TV in centimeters.
        // @param width: Width in cm
        // @example width: 100
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult WidthInCentimeters(uint8_t& width /* @out */) const = 0;

        // @brief Vertical size in centimeters
        // @details Retrieves the vertical size of the TV in centimeters.
        // @param height: Height in cm
        // @example height: 50
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult HeightInCentimeters(uint8_t& height /* @out */) const = 0;

        // @property
        // @brief HDCP protocol used for transmission
        // @details Retrieves the HDCP protocol used for transmission.
        // @param value: Protocol
        // @example value: HDCP_2X
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult HDCPProtection (HDCPProtectionType& value /* @out */) const = 0;
        virtual Core::hresult HDCPProtection (const HDCPProtectionType value) = 0;

        // @property
        // @brief Video output port on the STB used for connection to TV
        // @details Retrieves the video output port on the STB used for connection to TV.
        // @param name: Video output port name
        // @example name: HDMI0
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult PortName (string& name /* @out */) const = 0;

    };

    /* @json */
    struct EXTERNAL IHDRProperties : virtual public Core::IUnknown {
        enum { ID = ID_HDR_PROPERTIES };

        enum HDRType : uint8_t {
            HDR_OFF,
            HDR_10,
            HDR_10PLUS,
            HDR_HLG,
            HDR_DOLBYVISION,
            HDR_TECHNICOLOR,
            HDR_SDR
        };

        typedef RPC::IIteratorType<HDRType, ID_HDR_ITERATOR> IHDRIterator;

        // @property
        // @brief HDR formats supported by TV
        // @details Retrieves the HDR formats supported by TV.
        // @param type: array of HDR formats
        // @example type: [HDR_10, HDR_10PLUS]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult TVCapabilities(IHDRIterator*& type /* @out */) const = 0;

        // @property
        // @brief HDR formats supported by STB
        // @details Retrieves the HDR formats supported by STB.
        // @param type: array of HDR formats
        // @example type: [HDR_10, HDR_10PLUS]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult STBCapabilities(IHDRIterator*& type /* @out */) const = 0;

        // @property
        // @brief HDR format in use
        // @details Retrieves the HDR format in use.
        // @param type: HDR format
        // @example type: HDR_10
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult HDRSetting(HDRType& type /* @out */) const = 0;
    };

    /* @json */
    struct EXTERNAL IDisplayProperties : virtual public Core::IUnknown {
        enum { ID = ID_DISPLAY_PROPERTIES };

        enum ColourSpaceType : uint8_t {
            FORMAT_UNKNOWN,
            FORMAT_OTHER,
            FORMAT_RGB_444,
            FORMAT_YCBCR_444,
            FORMAT_YCBCR_422,
            FORMAT_YCBCR_420
        };

        enum FrameRateType : uint8_t {
            FRAMERATE_UNKNOWN,
            FRAMERATE_23_976,
            FRAMERATE_24,
            FRAMERATE_25,
            FRAMERATE_29_97,
            FRAMERATE_30,
            FRAMERATE_47_952,
            FRAMERATE_48,
            FRAMERATE_50,
            FRAMERATE_59_94,
            FRAMERATE_60,
            FRAMERATE_119_88,
            FRAMERATE_120,
            FRAMERATE_144
        };

        enum ColourDepthType : uint8_t {
            COLORDEPTH_UNKNOWN,
            COLORDEPTH_8_BIT,
            COLORDEPTH_10_BIT,
            COLORDEPTH_12_BIT
        };

        enum QuantizationRangeType : uint8_t {
            QUANTIZATIONRANGE_UNKNOWN,
            QUANTIZATIONRANGE_LIMITED,
            QUANTIZATIONRANGE_FULL
        };

        enum ColorimetryType : uint8_t {
            COLORIMETRY_UNKNOWN,
            COLORIMETRY_OTHER,
            COLORIMETRY_SMPTE170M,
            COLORIMETRY_BT709,
            COLORIMETRY_XVYCC601,
            COLORIMETRY_XVYCC709,
            COLORIMETRY_SYCC601,
            COLORIMETRY_OPYCC601,
            COLORIMETRY_OPRGB,
            COLORIMETRY_BT2020YCCBCBRC,
            COLORIMETRY_BT2020RGB_YCBCR
        };

	struct EXTERNAL ColorimetryTypeInfo {
            ColorimetryType colorimetry;
        };

        enum EotfType : uint8_t {
            EOTF_UNKNOWN,
            EOTF_OTHER,
            EOTF_BT1886,
            EOTF_BT2100,
            EOTF_SMPTE_ST_2084
        };
        typedef RPC::IIteratorType<ColorimetryType, ID_COLORIMETRY_ITERATOR> IColorimetryIterator;

        // @property
        // @brief Provides access to the display's Colour space (chroma subsampling format)
        // @details Retrieves the display's Colour space (chroma subsampling format).
        // @param cs: Colour space
        // @example cs: FORMAT_YCBCR_422
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult ColorSpace(ColourSpaceType& cs /* @out */) const = 0;

	    // @text getCurrentColorimetry
        // @brief Returns the active colorimetry standard of the current connected video port
        // @details Retrieves the active colorimetry standard of the current connected video port. If no display is connected, COLORIMETRY_UNKNOWN is returned. If the colorimetry coefficient is not mapped to a known standard, COLORIMETRY_OTHER is returned.
        // @param info: current colorimetry info (colorimetryType is COLORIMETRY_UNKNOWN if no display connected, COLORIMETRY_OTHER if coefficient unmapped)
        // @example info: { colorimetry: COLORIMETRY_BT709 }
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult GetCurrentColorimetry(ColorimetryTypeInfo& info /* @out */) const = 0;

        // @property
        // @brief Provides access to Frame Rate
        // @details Retrieves the display's frame rate.
        // @param rate: Frame rate
        // @example rate: FRAMERATE_60
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult FrameRate(FrameRateType& rate /* @out */) const = 0;

        // @property
        // @brief Provides access to display's Colour Depth
        // @details Retrieves the display's Colour depth.
        // @param colour: Colour depth
        // @example colour: COLOURDEPTH_10_BIT
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult ColourDepth(ColourDepthType& colour /* @out */) const = 0;

        // @property
        // @brief Provides access to display's colorimetry
        // @details Retrieves the display's colorimetry.
        // @param colorimetry: display colorimetry
        // @example colorimetry: [COLORIMETRY_BT709, COLORIMETRY_BT2020YCCBCBRC]
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult Colorimetry(IColorimetryIterator*& colorimetry /* @out */) const = 0;

        // @property
        // @brief Provides access to display's Qauntization Range
        // @details Retrieves the display's quantization range.
        // @param qr: quantization range
        // @example qr: QUANTIZATIONRANGE_LIMITED
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult QuantizationRange(QuantizationRangeType& qr /* @out */) const = 0;

        // @property
        // @brief Provides access to display's Electro optical transfer function
        // @details Retrieves the display's Electro optical transfer function (EOTF).
        // @param eotf: display's EOTF
        // @example eotf: EOTF_BT2100
        // @retval Core::ERROR_NONE: Indicates success
        virtual Core::hresult EOTF(EotfType& eotf /* @out */) const = 0;
    };
}
}
