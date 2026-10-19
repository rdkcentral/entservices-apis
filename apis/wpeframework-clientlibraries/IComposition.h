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

namespace WPEFramework {
namespace Exchange {

    struct EXTERNAL IComposition : virtual public Core::IUnknown {
        enum { ID = ID_COMPOSITION };

        ~IComposition() override = default;

        static constexpr uint32_t maxOpacity = 255;
        static constexpr uint32_t minOpacity = 0;

        static constexpr uint32_t maxZOrder = 255;
        static constexpr uint32_t minZOrder = 0;

        enum ScreenResolution : uint8_t {
            SCREENRESOLUTION_UNKNOWN = 0,
            SCREENRESOLUTION_480I = 1,
            SCREENRESOLUTION_480P = 2,
            SCREENRESOLUTION_576I = 3,
            SCREENRESOLUTION_576P = 4,
            SCREENRESOLUTION_576P50HZ = 5,
            SCREENRESOLUTION_720P = 6,
            SCREENRESOLUTION_720P50HZ = 7,
            SCREENRESOLUTION_768P60HZ = 8,
            SCREENRESOLUTION_1080I = 9,
            SCREENRESOLUTION_1080I25HZ = 10,
            SCREENRESOLUTION_1080I50HZ = 11,
            SCREENRESOLUTION_1080P = 12,
            SCREENRESOLUTION_1080P24HZ = 13,
            SCREENRESOLUTION_1080P25HZ = 14,
            SCREENRESOLUTION_1080P30HZ = 15,
            SCREENRESOLUTION_1080P50HZ = 16,
            SCREENRESOLUTION_1080P60HZ = 17,
            SCREENRESOLUTION_2160P24HZ = 18,
            SCREENRESOLUTION_2160P25HZ = 19,
            SCREENRESOLUTION_2160P30HZ = 20,
            SCREENRESOLUTION_2160P50HZ = 21,
            SCREENRESOLUTION_2160P60HZ = 22,
            SCREENRESOLUTION_4320P30HZ = 23,
            SCREENRESOLUTION_4320P60HZ = 24
        };

        /**
         * @brief factor to be used to remove the need of using float values on the interface.
         * @details Multiplying a refresh rate by this factor avoids floating-point values in the interface.
         */
        static constexpr uint16_t RefreshRateFactor = 1000;

        /**
         * @brief Get the refresh rate for a screen resolution.
         * @details Returns the refresh rate scaled by RefreshRateFactor so it can be represented as an integer.
         * @param resolution The screen resolution to inspect.
         * @example resolution: SCREENRESOLUTION_1080P60HZ
         * @retval refreshRate: Refresh rate multiplied by RefreshRateFactor (for example, 59940 represents 59.940 Hz).
         */
        static uint32_t RefreshRateFromResolution(const ScreenResolution resolution);

        /**
         * @brief Get the width for a screen resolution.
         * @details Returns the horizontal pixel count represented by the specified screen resolution.
         * @param resolution The screen resolution to inspect.
         * @example resolution: SCREENRESOLUTION_1080P60HZ
         * @retval width: Horizontal resolution in pixels.
         */
        static uint32_t WidthFromResolution(const ScreenResolution resolution);

        /**
         * @brief Get the height for a screen resolution.
         * @details Returns the vertical pixel count represented by the specified screen resolution.
         * @param resolution The screen resolution to inspect.
         * @example resolution: SCREENRESOLUTION_1080P60HZ
         * @retval height: Vertical resolution in pixels.
         */
        static uint32_t HeightFromResolution(const ScreenResolution resolution);

        /**
         * @brief Find a screen resolution from its dimensions.
         * @details Maps the requested height and width to the matching screen resolution enum value.
         * @param height Vertical resolution in pixels.
         * @example height: 1080
         * @param width Horizontal resolution in pixels.
         * @example width: 1920
         * @retval resolution: Matching screen resolution enum value, or SCREENRESOLUTION_UNKNOWN if unmatched.
         */
        static ScreenResolution ResolutionFromHeightWidth(const uint32_t height, const uint32_t width);

        struct Rectangle {
            uint32_t x;
            uint32_t y;
            uint32_t width;
            uint32_t height;
        };

        struct EXTERNAL IClient : virtual public Core::IUnknown {
            enum { ID = ID_COMPOSITION_CLIENT };

            ~IClient() override = default;

            struct EXTERNAL IProperties : virtual public Core::IUnknown {
                enum { ID = ID_COMPOSITION_CLIENTPROPERTIES };

                ~IProperties() override = default;

                // @brief Get the buffer stride.
                // @details Returns the number of bytes per row for the buffer.
                // @retval stride: Buffer row stride in bytes.
                virtual uint32_t Stride() = 0; // bytes per row [(bit-per-pixel/8) * width]

                // @brief Get the buffer pixel format.
                // @details Returns the pixel arrangement encoded as a FourCC value.
                // @retval format: FourCC pixel format identifier.
                virtual uint32_t Format() = 0; // pixel arrangement according the fourcc format

                // @brief Get the buffer data offset.
                // @details Returns the byte offset from the start of the buffer to the pixel data.
                // @retval offset: Pixel data offset in bytes.
                virtual uint32_t Offset() = 0;

                // @brief Get the buffer format modifier.
                // @details Returns the modifier describing the buffer's pixel layout.
                // @retval modifier: Buffer layout modifier value.
                virtual uint64_t Modifier() = 0;
            };

            // @brief Get the native client identifier.
            // @details Returns the platform-native identifier associated with this client, or zero when unavailable.
            virtual WPEFramework::Core::instance_id Native() const { return 0; };

            // @brief Get the client name.
            // @details Returns the name assigned to this composition client.
            // @retval name: Client name.
            virtual string Name() const = 0;

            // @brief Set client opacity.
            // @details Sets the opacity of the client, where minOpacity is transparent and maxOpacity is opaque.
            // @param value Opacity value from minOpacity through maxOpacity.
            // @example value: 255
            virtual void Opacity(const uint32_t value) = 0;

            // @brief Get client opacity.
            // @details Returns the current opacity of the client.
            // @retval opacity: Current opacity value from minOpacity through maxOpacity.
            virtual uint32_t Opacity() const { return 0; };

            // @brief Set client geometry.
            // @details Sets the client position and dimensions on the composition display.
            // @param rectangle: Client bounds in display coordinates.
            // @example rectangle: {"x": 0, "y": 0, "width": 1920, "height": 1080}
            // @retval Core::ERROR_NONE: Client geometry was set successfully.
            virtual uint32_t Geometry(const Rectangle& rectangle) = 0;

            // @brief Get client geometry.
            // @details Returns the current client position and dimensions on the composition display.
            virtual Rectangle Geometry() const = 0;

            // @brief Set the client stacking order.
            // @details Sets the client position in the display stacking order.
            // @param index Stacking index from minZOrder through maxZOrder.
            // @example index: 10
            // @retval Core::ERROR_NONE: Client stacking order was set successfully.
            virtual uint32_t ZOrder(const uint16_t index) = 0;

            // @brief Get the client stacking order.
            // @details Returns the current position of the client in the display stacking order.
            // @retval index: Current stacking index.
            virtual uint32_t ZOrder() const = 0;
        };

        struct EXTERNAL IRender : virtual public Core::IUnknown {
            enum { ID = ID_COMPOSITION_RENDER };

            ~IRender() override = default;

            // @brief Scan out the render surface.
            // @details Presents the prepared render surface to the display.
            virtual void ScanOut() = 0;

            // @brief Prepare the render surface for scan-out.
            // @details Performs any work required immediately before the render surface is scanned out.
            virtual void PreScanOut() {};

            // @brief Complete render-surface scan-out.
            // @details Performs any work required immediately after the render surface has been scanned out.
            virtual void PostScanOut() {};
        };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_COMPOSITION_NOTIFICATION };

            ~INotification() override = default;

            // @brief Notify that a client was attached.
            // @details Reports a newly attached composition client and provides its client interface.
            // @param name Name of the attached client.
            // @example name: "video-plane"
            // @param client Interface of the attached composition client.
            // @example client: IComposition::IClient instance
            virtual void Attached(const string& name, IClient* client) = 0;

            // @brief Notify that a client was detached.
            // @details Reports that the named composition client is no longer attached.
            // @param name: Name of the detached client.
            // @example name: "video-plane"
            virtual void Detached(const string& name) = 0;
        };

        struct EXTERNAL IDisplay : virtual public Core::IUnknown {
            enum { ID = ID_COMPOSITION_DISPLAY };

            ~IDisplay() override = default;

            // @brief Get the native display identifier.
            // @details Returns the platform-native identifier associated with this display.
            // @retval instanceId Native display identifier.
            virtual WPEFramework::Core::instance_id Native() const = 0;

            // @brief Get the display port name.
            // @details Returns the port name associated with this display.
            // @retval portName Display port name.
            virtual string Port() const = 0;

            // @brief Create a composition client.
            // @details Creates a client surface with the requested dimensions on this display.
            // @param name: Name to assign to the client.
            // @example name: "video-plane"
            // @param width Client surface width in pixels.
            // @example width: 1920
            // @param height Client surface height in pixels.
            // @example height: 1080
            // @retval client Newly created composition client, or nullptr if creation fails.
            virtual IClient* CreateClient(const string& name, const uint32_t width, const uint32_t height) = 0;

            // Set and get output resolution
            // @brief Set the display output resolution.
            // @details Sets the output resolution for this display.
            // @retval Core::ERROR_NONE: Display resolution was set successfully.
            virtual uint32_t Resolution(const ScreenResolution) = 0;

            // @brief Get the display output resolution.
            // @details Returns the current output resolution for this display.
            virtual ScreenResolution Resolution() const = 0;
        };

        // @brief Register for composition notifications.
        // @details Subscribes the callback interface to notifications from the composition service.
        // @param notification: Callback interface that receives composition notifications.
        virtual void Register(IComposition::INotification* notification) = 0;

        // @brief Unregister from composition notifications.
        // @details Removes the callback interface's subscription to composition notifications.
        // @param notification: Callback interface previously registered for composition notifications.
        virtual void Unregister(IComposition::INotification* notification) = 0;

        // @brief Configure the composition service.
        // @details Initializes composition using the framework service interface.
        // @param service: Framework service interface used to configure composition.
        // @example service: PluginHost::IShell instance
        // @retval Core::ERROR_NONE: Composition was configured successfully.
        virtual uint32_t Configure(PluginHost::IShell* service) = 0;

        // Set and get output resolution
        // @brief Set the output resolution.
        // @details Sets the output resolution for the composition display.
        // @retval Core::ERROR_NONE: Output resolution was set successfully.
        virtual uint32_t Resolution(const ScreenResolution) = 0;

        // @brief Get the output resolution.
        // @details Returns the current output resolution for the composition display.
        // @retval resolution Current output resolution.
        virtual ScreenResolution Resolution() const = 0;
    };

    struct EXTERNAL IBrightness : virtual public Core::IUnknown {
        enum { ID = ID_BRIGHTNESS };

        // Brightness of SDR graphics in HDR display
        enum Brightness : uint8_t {
            SdrToHdrGraphicsBrightness_Default = 0, /* peak luminance of SDR graphics in HDR display might be less bright than SDR video in HDR display */
            SdrToHdrGraphicsBrightness_MatchVideo = 1, /* peak luminance of SDR graphics in HDR display will be as bright as SDR video in HDR display */
            SdrToHdrGraphicsBrightness_Max = 2 /* peak luminance of SDR graphics in HDR display might be more bright than SDR video in HDR display */
        };

        // @brief Get SDR graphics brightness in HDR mode.
        // @details Retrieves the configured brightness relationship between SDR graphics and SDR video on an HDR display.
        // @param brightness: Receives the current SDR-to-HDR graphics brightness setting.
        // @example brightness: SdrToHdrGraphicsBrightness_MatchVideo
        // @retval Core::ERROR_NONE: Brightness setting was retrieved successfully.
        virtual uint32_t SdrToHdrGraphicsBrightness(Brightness& brightness /* @out */) const = 0;

        // @brief Set SDR graphics brightness in HDR mode.
        // @details Sets the brightness relationship between SDR graphics and SDR video on an HDR display.
        // @param brightness: Brightness setting to apply.
        // @example brightness: SdrToHdrGraphicsBrightness_MatchVideo
        // @retval Core::ERROR_NONE: Brightness setting was updated successfully.
        virtual uint32_t SdrToHdrGraphicsBrightness(const Brightness& brightness) = 0;
    };
}
}
