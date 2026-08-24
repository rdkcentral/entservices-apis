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
        // @return total: Total GPU RAM
        virtual Core::hresult TotalGpuRam(uint64_t& total /* @out */) const = 0;

        // @property
        // @brief Free GPU DRAM memory (in bytes)
        // @return free: Free GPU RAM
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
        // @details Retrieves whether HDMI audio passthrough is currently enabled.
        // @param passthru: enabled/disabled
        // @example passthru: true
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult IsAudioPassthrough (bool& passthru /* @out */) const = 0;

        // @property
        // @brief Current HDMI connection status
        // @details Retrieves the current HDMI connection state.
        // @param isconnected: connected/disconnected
        // @example isconnected: true
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Connected(bool& isconnected /* @out */) const = 0;

        // @property
        // @brief Horizontal resolution of TV
        // @details Retrieves the horizontal resolution of the connected TV in pixels.
        // @param width:  width of TV in pixels
        // @example width: 1920
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Width(uint32_t& width /* @out */) const = 0;

        // @property
        // @brief Vertical resolution of TV
        // @details Retrieves the vertical resolution of the connected TV in pixels.
        // @param height:  height of TV in pixels
        // @example height: 1080
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Height(uint32_t& height /* @out */) const = 0;

        // @property
        // @brief Vertical Frequency
        // @details Retrieves the display refresh frequency.
        // @param vf: vertical freq
        // @example vf: 60
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult VerticalFreq(uint32_t& vf /* @out */) const = 0;

        // @brief TV's Extended Display Identification Data
        // @details Retrieves the EDID data of the connected display.
        // @param length: EDID*data length
        // @example length: 25*
        // @param data: EDID byte string
        // @example data: [0x00,0xFF,0xFF,0xFF]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EDID (uint16_t& length /* @inout */, uint8_t data[] /* @out @length:length */) const = 0;

        // @brief Horizontal size in centimeters
        // @details Returns the physical width of the connected display panel.
        // The value is expressed in centimeters and is typically obtained from the display EDID information.
        // A value of 0 may indicate that the display size information is unavailable or not reported by the connected display.
        // @param width: width in cm
        // @example width: 143
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Display width retrieved successfully.
        // @retval Core::ERROR_GENERAL Display width information is unavailable or not reported by the connected display.
        virtual Core::hresult WidthInCentimeters(uint8_t& width /* @out */) const = 0;

        // @brief Vertical size in centimeters
        // @details Returns the physical height of the connected display panel.
        // The value is expressed in centimeters and is typically obtained from the display EDID information.
        // A value of 0 may indicate that the display size information is unavailable or not reported by the connected display.
        // @param height: height in cm
        // @example height: 81
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE Display height retrieved successfully.
        // @retval Core::ERROR_GENERAL Display height information is unavailable or not reported by the connected display.
        virtual Core::hresult HeightInCentimeters(uint8_t& height /* @out */) const = 0;

        // @property
        // @brief HDCP protocol used for transmission
        // @details Returns the HDCP protocol used for transmission.
        // @param value: protocol
        // @example value: HDCP_2X
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult HDCPProtection (HDCPProtectionType& value /* @out */) const = 0;
        virtual Core::hresult HDCPProtection (const HDCPProtectionType value) = 0;

        // @property
        // @brief Video output port on the STB used for connection to TV
        // @details Returns the name of the video output port on the STB used for connection to the TV.
        // @param name: video output port name
        // @example name: HDMI1
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
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
        // @details Returns the HDR formats supported by the TV.
        // @param type: array of HDR formats
        // @example type: [HDR_10, HDR_10PLUS]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        // @return HDRType: array of HDR formats
        virtual Core::hresult TVCapabilities(IHDRIterator*& type /* @out */) const = 0;

        // @property
        // @brief HDR formats supported by STB
        // @details Returns the HDR formats supported by the STB.
        // @param type: array of HDR formats
        // @example type: [HDR_10, HDR_10PLUS]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        // @return HDRType: array of HDR formats
        virtual Core::hresult STBCapabilities(IHDRIterator*& type /* @out */) const = 0;

        // @property
        // @brief HDR format in use
        // @param type: HDR format
        // @example type: HDR_10
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
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
        // @details Returns the colour space (chroma subsampling format) of the connected display.
        // @param cs: colour space
        // @example cs: FORMAT_YCBCR_444
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ColorSpace(ColourSpaceType& cs /* @out */) const = 0;

	    // @text getCurrentColorimetry
        // @brief Returns the active colorimetry standard of the current connected video port
        // @details Returns the active colorimetry standard of the current connected video port. If no display is connected, COLORIMETRY_UNKNOWN is returned. If the colorimetry coefficient is not mapped to a known standard, COLORIMETRY_OTHER is returned.
        // @param info: current colorimetry info (colorimetryType is COLORIMETRY_UNKNOWN if no display connected, COLORIMETRY_OTHER if coefficient unmapped)
        // @example info: { colorimetryType: COLORIMETRY_BT709 }
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        // @param info: current colorimetry info (colorimetryType is COLORIMETRY_UNKNOWN if no display connected, COLORIMETRY_OTHER if coefficient unmapped)
        virtual Core::hresult GetCurrentColorimetry(ColorimetryTypeInfo& info /* @out */) const = 0;

        // @property
        // @brief Provides access to Frame Rate
        // @details Returns the frame rate of the connected display.
        // @param rate: frame rate
        // @example rate: { numerator: 60, denominator: 1 }
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult FrameRate(FrameRateType& rate /* @out */) const = 0;

        // @property
        // @brief Provides access to display's colour Depth
        // @details Returns the colour depth of the connected display.
        // @param colour: colour depth
        // @example colour: COLORDEPTH_10_BIT
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult ColourDepth(ColourDepthType& colour /* @out */) const = 0;

        // @property
        // @brief Provides access to display's colorimetry
        // @details Returns the colorimetry information of the connected display.
        // @param colorimetry: display colorimetry
        // @example colorimetry: [COLORIMETRY_BT709, COLORIMETRY_BT2020YCCBCBRC]
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult Colorimetry(IColorimetryIterator*& colorimetry /* @out */) const = 0;

        // @property
        // @brief Provides access to display's Quantization Range
        // @details Returns the quantization range of the connected display.
        // @param qr: quantization range
        // @example qr: QUANTIZATION_RANGE_FULL
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult QuantizationRange(QuantizationRangeType& qr /* @out */) const = 0;

        // @property
        // @brief Provides access to display's Electro optical transfer function
        // @details Returns the EOTF of the connected display.
        // @param eotf: display's EOTF
        // @example eotf: EOTF_HDR10
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult EOTF(EotfType& eotf /* @out */) const = 0;
    };
}
}
