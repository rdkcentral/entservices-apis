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
            // @param port: Port of the hotplug 
            // @param isConnected: Is it connected (true) or not(false)
            virtual void OnCompositeInHotPlug(const CompositeInPort port, const bool isConnected) {};

            // @brief Composite In Signal status
            // @text onCompositeInSignalStatus
            // @param port: Port of the hotplug 
            // @param signalStatus: Signal status
            virtual void OnCompositeInSignalStatus(const CompositeInPort port, const CompositeInSignalStatus signalStatus) {};

            // @brief Composite In status
            // @text onCompositeInStatus
            // @param activePort: Active port
            // @param isPresented: is it presented to user
            virtual void OnCompositeInStatus(const CompositeInPort activePort, const bool isPresented) {};

            // @brief Composite In status
            // @text onCompositeInStatus
            // @param activePort: Active port
            // @param videoResolution: See DisplayVideoPortResolution
            virtual void OnCompositeInVideoModeUpdate(const CompositeInPort activePort, const DisplayVideoPortResolution videoResolution) {};

        };

        virtual Core::hresult Register(Exchange::IDeviceSettingsCompositeIn::INotification* notification ) = 0;
        virtual Core::hresult Unregister(Exchange::IDeviceSettingsCompositeIn::INotification* notification ) = 0;

        /** Get number of composite inputs. */
        // @text getNrOfCompositeInputs
        // @brief Get Preferred Sleep mode.
        // @param nrCompositeInputs: number of composite inputs
        virtual Core::hresult GetNrOfCompositeInputs(int32_t &nrCompositeInputs /* @out */) = 0;

        /** Get Composite In port status. */
        // @text getCompositeInStatus
        // @brief Get Composite In port status
        // @param status: Composite In status
        virtual Core::hresult GetCompositeInStatus(CompositeInStatus &status /* @out */) = 0;

        /** Select Composite In port */
        // @text selectCompositeInPort
        // @brief Select Composite In port.
        // @param port: port to be selected
        virtual Core::hresult SelectCompositeInPort(const CompositeInPort port ) = 0;

        /** Scale composite video . */
        // @text scaleCompositeInVideo
        // @brief Scale composite video.
        // @param videoRect: co-ordinates and width/height to scale to
        virtual Core::hresult ScaleCompositeInVideo(const VideoRectangle videoRect ) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
