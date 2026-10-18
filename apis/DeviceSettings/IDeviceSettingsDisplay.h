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

        enum DisplayPortType : uint8_t {
            DS_DISPLAY_PORT_TYPE_RF         = 0,
            DS_DISPLAY_PORT_TYPE_BB         = 1,
            DS_DISPLAY_PORT_TYPE_SVIDEO     = 2,
            DS_DISPLAY_PORT_TYPE_1394       = 3,
            DS_DISPLAY_PORT_TYPE_DVI        = 4,
            DS_DISPLAY_PORT_TYPE_COMPONENT  = 5,
            DS_DISPLAY_PORT_TYPE_HDMI       = 6,
            DS_DISPLAY_PORT_TYPE_HDMI_INPUT = 7,
            DS_DISPLAY_PORT_TYPE_INTERNAL   = 8,
            DS_DISPLAY_PORT_TYPE_MAX        = 9
        };

        enum DisplayAVIContentType : uint8_t {
            DS_DISPLAY_AVI_CONTENT_GRAPHICS      = 0,
            DS_DISPLAY_AVI_CONTENT_PHOTO         = 1,
            DS_DISPLAY_AVI_CONTENT_CINEMA        = 2,
            DS_DISPLAY_AVI_CONTENT_GAME          = 3,
            DS_DISPLAY_AVI_CONTENT_NOT_SIGNALLED = 4,
            DS_DISPLAY_AVI_CONTENT_MAX           = 5
        };

        enum DisplayAVIScanInformation : uint8_t {
            DS_DISPLAY_AVI_SCAN_NO_DATA    = 0,
            DS_DISPLAY_AVI_SCAN_OVERSCAN   = 1,
            DS_DISPLAY_AVI_SCAN_UNDERSCAN  = 2,
            DS_DISPLAY_AVI_SCAN_MAX        = 3
        };

        enum DisplayColoriMetryInformation: uint32_t {
            DS_DISPLAY_COLORIMETRY_INFO_NONE        = 0x00,
            DS_DISPLAY_COLORIMETRY_INFO_XVYCC601    = 0x01,
            DS_DISPLAY_COLORIMETRY_INFO_XVYCC709    = 0x02,
            DS_DISPLAY_COLORIMETRY_INFO_SYCC601     = 0x04,
            DS_DISPLAY_COLORIMETRY_INFO_ADOBEYCC601 = 0x08,
            DS_DISPLAY_COLORIMETRY_INFO_ADOBERGB    = 0x10,
            DS_DISPLAY_COLORIMETRY_INFO_BT2020CL    = 0x20,
            DS_DISPLAY_COLORIMETRY_INFO_BT2020NCL   = 0x40,
            DS_DISPLAY_COLORIMETRY_INFO_BT2020RGB   = 0x80,
            DS_DISPLAY_COLORIMETRY_INFO_DCI_P3      = 0x100,
            DS_DISPLAY_COLORIMETRY_INFO_MAX         = 0x200
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
            // @details Notifies clients when the display receiver sense signal turns on or off.
            // @param displayEvent: DS_DISPLAY_RXSENSE_ON or DS_DISPLAY_RXSENSE_OFF
            // @example displayEvent: DS_DISPLAY_RXSENSE_ON
            virtual void OnDisplayRxSense(const DisplayEvent displayEvent) {};

            // @brief Display HDCP Status
            // @text onDisplayHDCPStatus
            // @details Notifies clients when the display HDCP status changes.
            // @param hdcpStatus: Current HDCP status reported for the display.
            // @example hdcpStatus: 1
            virtual void OnDisplayHDCPStatus(const int32_t hdcpStatus) {};
            
        };

        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsDisplay::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsDisplay::INotification* notification ) = 0;

        // @event
        struct EXTERNAL IDisplayHDMIHotPlugNotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_DISPLAY_HOTPLUG_NOTIFICATION };

            // @brief Display HDMI Hot plug event
            // @text onDisplayHDMIHotPlug
            // @details Notifies clients when an HDMI display is connected or disconnected.
            // @param displayEvent: DS_DISPLAY_EVENT_CONNECTED or DS_DISPLAY_EVENT_DISCONNECTED
            // @example displayEvent: DS_DISPLAY_EVENT_CONNECTED
            virtual void OnDisplayHDMIHotPlug(const DisplayEvent displayEvent) {};

        };

        // @brief Register for HDMI hot-plug notifications.
        // @details Subscribes a client notification listener to HDMI display connection events.
        // @param clientName: Name identifying the client registering for notifications.
        // @example clientName: "DisplayHotPlugClient"
        // @param notification: Listener that receives HDMI hot-plug events.
        // @example notification: IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification instance
        // @retval Core::ERROR_NONE: HDMI hot-plug listener was registered successfully
        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification* notification ) = 0;

        // @brief Unregister from HDMI hot-plug notifications.
        // @details Removes a client notification listener from HDMI display connection events.
        // @param notification: Listener to remove from the subscription.
        // @example notification: IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification instance
        // @retval Core::ERROR_NONE: HDMI hot-plug listener was unregistered successfully
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsDisplay::IDisplayHDMIHotPlugNotification* notification ) = 0;

        /** Get Display EDID. */
        // @text getDisplayEdid
        // @brief Get Display EDID
        // @details Retrieves the display EDID information and the list of supported video resolutions.
        // @param handle: handle returned in GetDisplay
        // @example handle: 1
        // @param edId: EDID information
        // @example edId: {"productCode": 1234, "serialNumber": 5678, "manufactureYear": 2024, "manufactureWeek": 10, "hdmiDeviceType": true, "isRepeater": false}
        // @param supportedResolutionList: Iterator over resolutions supported by the display.
        // @example supportedResolutionList: ["1080p60", "2160p60"]
        // @retval Core::ERROR_NONE: Display EDID and supported resolutions were retrieved successfully
        virtual Core::hresult GetDisplayEdid(const int32_t handle , DisplayEDID &edId /* @out */, IDSVideoPortResolutionIterator*& supportedResolutionList /* @out */) = 0;

        /** Get Display EDID bytes. */
        // @text getDisplayEdidBytes
        // @brief Get Display EDID bytes
        // @details Retrieves the raw EDID byte sequence for the specified display.
        // @param handle: handle returned in GetDisplay
        // @example handle: 1
        // @param edIdBytes: EDID Bytes
        // @example edIdBytes: [0, 255, 255, 255, 255, 255, 255, 0]
        // @param edidLength: length of EDID bytes
        // @example edidLength: 128
        // @retval Core::ERROR_NONE: EDID bytes were retrieved successfully
        virtual Core::hresult GetDisplayEdidBytes(const int32_t handle , uint8_t edIdBytes[] /* @out @length:edidLength @maxlength:edidLength */, const uint16_t edidLength ) = 0;

        /** Get Display handle by port type and index. */
        // @text getDisplay
        // @brief Get Display handle by port type and index
        // @details Retrieves the handle for a display identified by its port type and index.
        // @param portType: Display port type
        // @example portType: DS_DISPLAY_PORT_TYPE_HDMI
        // @param index: Display index  
        // @example index: 0
        // @param handle: Display handle returned
        // @example handle: 1
        // @retval Core::ERROR_NONE: Display handle was retrieved successfully
        virtual Core::hresult GetDisplay(const DisplayPortType portType, const int32_t index, int32_t &handle /* @out */) = 0;

        /** Get Display Aspect Ratio. */
        // @text getDisplayAspectRatio
        // @brief Get Display Aspect Ratio
        // @details Retrieves the aspect ratio reported by the specified display.
        // @param handle: Display handle
        // @example handle: 1
        // @param aspectRatio: Display aspect ratio returned
        // @example aspectRatio: DS_DISPLAY_ASPECT_RATIO_16X9
        // @retval Core::ERROR_NONE: Display aspect ratio was retrieved successfully
        virtual Core::hresult GetDisplayAspectRatio(const int32_t handle, DisplayVideoAspectRatio &aspectRatio /* @out */) = 0;

        /** Set ALLM (Auto Low Latency Mode) enabled/disabled. */
        // @text setAllmEnabled 
        // @brief Set ALLM (Auto Low Latency Mode) enabled/disabled
        // @details Enables or disables Auto Low Latency Mode for the specified display.
        // @param handle: Display handle
        // @example handle: 1
        // @param enabled: Enable/disable ALLM
        // @example enabled: true
        // @retval Core::ERROR_NONE: ALLM state was updated successfully
        virtual Core::hresult SetAllmEnabled(const int32_t handle, const bool enabled) = 0;

        /** Set AVI Content Type. */
        // @text setAVIContentType
        // @brief Set AVI Content Type
        // @details Sets the AVI content type transmitted for the specified display.
        // @param handle: Display handle  
        // @example handle: 1
        // @param contentType: AVI content type to set
        // @example contentType: DS_DISPLAY_AVI_CONTENT_GRAPHICS
        // @retval Core::ERROR_NONE: AVI content type was set successfully
        virtual Core::hresult SetAVIContentType(const int32_t handle, const DisplayAVIContentType contentType) = 0;

        /** Set AVI Scan Information. */
        // @text setAVIScanInformation
        // @brief Set AVI Scan Information
        // @details Sets the AVI scan information transmitted for the specified display.
        // @param handle: Display handle
        // @example handle: 1
        // @param scanInfo: AVI scan information to set
        // @example scanInfo: DS_DISPLAY_AVI_SCAN_UNDERSCAN
        // @retval Core::ERROR_NONE: AVI scan information was set successfully
        virtual Core::hresult SetAVIScanInformation(const int32_t handle, const DisplayAVIScanInformation scanInfo) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
