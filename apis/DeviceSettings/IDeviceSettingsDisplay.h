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

    struct EXTERNAL IDeviceSettingsDisplay : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_DISPLAY };

        enum DisplayEvent: uint8_t {
            DS_DISPLAY_EVENT_CONNECTED     = 0,  ///< Display connected event
            DS_DISPLAY_EVENT_DISCONNECTED  = 1,  ///< Display disconnected event
            DS_DISPLAY_RXSENSE_ON          = 2,  ///< Rx Sense ON event
            DS_DISPLAY_RXSENSE_OFF         = 3,  ///< Rx Sense OFF event
            DS_DISPLAY_HDCPPROTOCOL_CHANGE = 4,  ///< HDCP Protocol Version Change event
            DS_DISPLAY_EVENT_MAX           = 5 ///< Display max event
        };

        enum DisplayTVResolution: uint32_t {
            DS_DISPLAY_RESOLUTION_480I     = 0x000001,     
            DS_DISPLAY_RESOLUTION_480P     = 0x000002,     
            DS_DISPLAY_RESOLUTION_576I     = 0x000004,     
            DS_DISPLAY_RESOLUTION_576P     = 0x000008,     
            DS_DISPLAY_RESOLUTION_576P50   = 0x000010,   
            DS_DISPLAY_RESOLUTION_720P     = 0x000020,     
            DS_DISPLAY_RESOLUTION_720P50   = 0x000040,   
            DS_DISPLAY_RESOLUTION_1080I    = 0x000080,    
            DS_DISPLAY_RESOLUTION_1080P    = 0x000100,    
            DS_DISPLAY_RESOLUTION_1080P24  = 0x000200,  
            DS_DISPLAY_RESOLUTION_1080I25  = 0x000400,  
            DS_DISPLAY_RESOLUTION_1080P30  = 0x001000,  
            DS_DISPLAY_RESOLUTION_1080I50  = 0x002000,  
            DS_DISPLAY_RESOLUTION_1080P50  = 0x004000,  
            DS_DISPLAY_RESOLUTION_1080P60  = 0x008000,  
            DS_DISPLAY_RESOLUTION_2160P24  = 0x010000,  
            DS_DISPLAY_RESOLUTION_2160P25  = 0x020000,  
            DS_DISPLAY_RESOLUTION_2160P30  = 0x040000,  
            DS_DISPLAY_RESOLUTION_2160P50  = 0x080000,  
            DS_DISPLAY_RESOLUTION_2160P60  = 0x100000  
        };

        enum DisplayVideoAspectRatio : uint8_t {
            DS_DISPLAY_ASPECT_RATIO_4X3         = 0  /* @text Video Aspect Ratio 4X3 */,
            DS_DISPLAY_ASPECT_RATIO_16X9        = 1  /* @text Video Aspect Ratio 16x9 */,
            DS_DISPLAY_ASPECT_RATIO_MAX         = 2
        };

        enum DisplayInVideoStereoScopicMode : uint8_t {
            DS_DISPLAY_SSMODE_UNKNOWN           = 0,
            DS_DISPLAY_SSMODE_2D                = 1,
            DS_DISPLAY_SSMODE_3D_SIDE_BY_SIDE   = 2,
            DS_DISPLAY_SSMODE_3D_TOP_AND_BOTTOM = 3,
            DS_DISPLAY_SSMODE_MAX               = 4
        };

        enum DisplayInVideoFrameRate: uint8_t {
            DS_DISPLAY_FRAMERATE_UNKNOWN   = 0, 
            DS_DISPLAY_FRAMERATE_24        = 1,
            DS_DISPLAY_FRAMERATE_25        = 2,
            DS_DISPLAY_FRAMERATE_30        = 3,
            DS_DISPLAY_FRAMERATE_60        = 4,
            DS_DISPLAY_FRAMERATE_23_98     = 5,
            DS_DISPLAY_FRAMERATE_29_97     = 6,
            DS_DISPLAY_FRAMERATE_50        = 7,
            DS_DISPLAY_FRAMERATE_59_94     = 8,
            DS_DISPLAY_FRAMERATE_100       = 9,
            DS_DISPLAY_FRAMERATE_119_88    = 10,
            DS_DISPLAY_FRAMERATE_120       = 11,
            DS_DISPLAY_FRAMERATE_200       = 12,
            DS_DISPLAY_FRAMERATE_239_76    = 13,
            DS_DISPLAY_FRAMERATE_240       = 14,
            DS_DISPLAY_FRAMERATE_MAX       = 15
        };

        struct DisplayVideoPortResolution {
            string name;
            DisplayTVResolution pixelResolution;
            DisplayVideoAspectRatio aspectRatio;
            DisplayInVideoStereoScopicMode stereoScopicMode;
            DisplayInVideoFrameRate frameRate;
            bool interlaced;
        };

        using IDSVideoPortResolutionIterator = RPC::IIteratorType<DisplayVideoPortResolution, ID_DEVICESETTINGS_DISPLAY_RESOLUTION_ITERATOR>;

        struct DisplayEDID {
            int32_t productCode;               ///< Product code of the display device
            int32_t serialNumber;              ///< Serial number of the display device
            int32_t manufactureYear;           ///< Year of manufacture of the display device
            int32_t manufactureWeek;           ///< Week of manufacture of the display device
            bool hdmiDeviceType;               ///< Device type  @a true if HDMI, @a false if DVI device
            bool  isRepeater;                  ///<  Receiver is a repeater   @a true if Repeater, @a false if connected Receiver is not a repeater
            uint8_t physicalAddressA;          ///<  Physical Address for HDMI nodeA
            uint8_t physicalAddressB;          ///<  Physical Address for HDMI nodeB
            uint8_t physicalAddressC;          ///<  Physical Address for HDMI nodeC
            uint8_t physicalAddressD;          ///<  Physical Address for HDMI nodeD
            int32_t numOfSupportedResolution;  ///<  Number of Supported resolution
            string monitorName;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_DISPLAY_NOTIFICATION };

            // @brief Display RX Sense event
            // @text onDisplayRxSense
            // @param displayEvent: DS_DISPLAY_RXSENSE_ON or DS_DISPLAY_RXSENSE_OFF
            virtual void OnDisplayRxSense(const DisplayEvent displayEvent) {};

            // @brief Display HDCP Status
            // @text OnDisplayHDCPStatus
            virtual void OnDisplayHDCPStatus() {};
            
        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsDisplay::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsDisplay::INotification* notification ) = 0;

        // @event
        struct EXTERNAL IDisplayHDMIHotPlugNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_DISPLAY_HOTPLUG_NOTIFICATION };

            // @brief Display HDMI Hot plug event
            // @text onDisplayHDMIHotPlug
            // @param displayEvent: DS_DISPLAY_EVENT_CONNECTED or DS_DISPLAY_EVENT_DISCONNECTED
            virtual void OnDisplayHDMIHotPlug(const DisplayEvent displayEvent) {};

        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification* notification ) = 0;

        /** Get Display EDID. */
        // @text getDisplayEdid
        // @brief Get Display EDID
        // @param handle: handle returned in GetDisplay
        // @param edId: EDID information
        virtual Core::hresult GetDisplayEdid(const int32_t handle , DisplayEDID &edId /* @out */, IDSVideoPortResolutionIterator*& supportedResolutionList /* @out */) = 0;

        /** Get Display EDID bytes. */
        // @text getDisplayEdidBytes
        // @brief Get Display EDID bytes
        // @param handle: handle returned in GetDisplay
        // @param edIdBytes: EDID Bytes
        // @param edidLength: length of EDID bytes
        virtual Core::hresult GetDisplayEdidBytes(const int32_t handle , uint8_t edIdBytes[] /* @out @length:edidLength @maxlength:edidLength */, const uint16_t edidLength ) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
