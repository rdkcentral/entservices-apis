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

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IDeviceSettingsCompositeIn : virtual public Core::IUnknown {
        enum { ID = ID_DEVICESETTINGS_COMPOSITEIN };

        enum CompositeInPort: int8_t {
            DS_COMPOSITE_IN_PORT_NONE    = -1  /* @text UNKNOWN */,
            DS_COMPOSITE_IN_PORT_0       = 0  /* @text CompositeIn Port 0 */,
            DS_COMPOSITE_IN_PORT_1       = 1  /* @text CompositeIn Port 1 */,
            DS_COMPOSITE_IN_PORT_MAX     = 2  /* @text CompositeIn Port MAX */,
        };

        enum CompositeInSignalStatus: int8_t {
            DS_COMPOSITE_IN_SIGNAL_STATUS_NONE          = -1 /* @text Signal Status None */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOSIGNAL      = 0 /* @text Signal Status No Signal */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_UNSTABLE      = 1 /* @text Signal Status Unstable */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_NOTSUPPORTED  = 2 /* @text Signal Status Not supported */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_STABLE        = 3 /* @text Signal Status Stable */,
            DS_COMPOSITE_IN_SIGNAL_STATUS_MAX           = 4 /* @text Signal Status MAX */
        };

        struct CompositeInStatus {
            bool isPresented;
            CompositeInPort activePort;
            bool isPort0Connected;
            bool isPort1Connected; /* Can't have array in structures..so separating the booleans */
        };

        struct VideoRectangle {
            int32_t x;
            int32_t y;
            int32_t width;
            int32_t height;
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
            DS_DISPLAY_ASPECT_RATIO_MAX         = 2  /* @text Video Aspect Ratio 16x9 */
        };

        enum DisplayInVideoStereoScopicMode : uint8_t {
            DS_DISPLAY_SSMODE_UNKNOWN           = 0,
            DS_DISPLAY_SSMODE_2D                = 1,
            DS_DISPLAY_SSMODE_3D_SIDE_BY_SIDE   = 2,
            DS_DISPLAY_SSMODE_3D_TOP_AND_BOTTOM = 3
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
            DisplayInVideoFrameRate frameRate;
            bool interlaced;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown
        {
            enum { ID = ID_DEVICESETTINGS_COMPOSITEIN_NOTIFICATION };

            // @brief Composite In Hotplug event
            // @text onCompositeInHotPlug
            // @details Notifies clients when a composite input port is connected or disconnected.
            // @param port: Port of the hotplug 
            // @example port: DS_COMPOSITE_IN_PORT_0
            // @param isConnected: Is it connected (true) or not(false)
            // @example isConnected: true
            virtual void OnCompositeInHotPlug(const CompositeInPort port, const bool isConnected) {};

            // @brief Composite In Signal status
            // @text onCompositeInSignalStatus
            // @details Notifies clients when the signal status of a composite input port changes.
            // @param port: Port of the hotplug 
            // @example port: DS_COMPOSITE_IN_PORT_0
            // @param signalStatus: Signal status
            // @example signalStatus: DS_COMPOSITE_IN_SIGNAL_STATUS_STABLE
            virtual void OnCompositeInSignalStatus(const CompositeInPort port, const CompositeInSignalStatus signalStatus) {};

            // @brief Composite In status
            // @text onCompositeInStatus
            // @details Notifies clients when the active composite input port or its presentation state changes.
            // @param activePort: Active port
            // @example activePort: DS_COMPOSITE_IN_PORT_0
            // @param isPresented: is it presented to user
            // @example isPresented: true
            virtual void OnCompositeInStatus(const CompositeInPort activePort, const bool isPresented) {};

            // @brief Composite In video mode update
            // @text onCompositeInVideoModeUpdate
            // @details Notifies clients when the video mode of the active composite input changes.
            // @param activePort: Active port
            // @example activePort: DS_COMPOSITE_IN_PORT_0
            // @param videoResolution: See DisplayVideoPortResolution
            // @example videoResolution: {"name": "480i", "pixelResolution": "DS_DISPLAY_RESOLUTION_480I", "aspectRatio": "DS_DISPLAY_ASPECT_RATIO_4X3", "frameRate": "DS_DISPLAY_FRAMERATE_60", "interlaced": true}
            virtual void OnCompositeInVideoModeUpdate(const CompositeInPort activePort, const DisplayVideoPortResolution& videoResolution) {};

        };

        virtual Core::hresult Register(const string clientName, Exchange::IDeviceSettingsCompositeIn::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsCompositeIn::INotification* notification ) = 0;

        /** Get number of composite inputs. */
        // @text getNrOfCompositeInputs
        // @brief Get Number of Composite Inputs in the platform
        // @details Retrieves the number of composite input ports available on the platform.
        // @param nrCompositeInputs: number of composite inputs
        // @example nrCompositeInputs: 2
        // @retval Core::ERROR_NONE: Number of composite input ports was retrieved successfully
        virtual Core::hresult GetNrOfCompositeInputs(int32_t &nrCompositeInputs /* @out */) = 0;

        /** Get Composite In port status. */
        // @text getCompositeInStatus
        // @brief Get Composite In port status
        // @details Retrieves the active composite input port and the current connection state of the ports.
        // @param status: Composite In status
        // @example status: {"isPresented": true, "activePort": "DS_COMPOSITE_IN_PORT_0", "isPort0Connected": true, "isPort1Connected": false}
        // @retval Core::ERROR_NONE: Composite input status was retrieved successfully
        virtual Core::hresult GetCompositeInStatus(CompositeInStatus &status /* @out */) = 0;

        /** Select Composite In port */
        // @text selectCompositeInPort
        // @brief Select Composite In port.
        // @details Selects the composite input port to use as the active video source.
        // @param port: port to be selected
        // @example port: DS_COMPOSITE_IN_PORT_0
        // @retval Core::ERROR_NONE: Composite input port was selected successfully
        virtual Core::hresult SelectCompositeInPort(const CompositeInPort port ) = 0;

        /** Scale composite video . */
        // @text scaleCompositeInVideo
        // @brief Scale composite video.
        // @details Sets the position and dimensions used to scale composite video.
        // @param videoRect: co-ordinates and width/height to scale to
        // @example videoRect: {"x": 0, "y": 0, "width": 1920, "height": 1080}
        // @retval Core::ERROR_NONE: Composite video scaling was updated successfully
        virtual Core::hresult ScaleCompositeInVideo(const VideoRectangle videoRect ) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
