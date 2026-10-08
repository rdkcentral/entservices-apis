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

    // @stubgen:omit
    struct EXTERNAL ICapture : virtual public Core::IUnknown {
        enum { ID = ID_CAPTURE };

        struct EXTERNAL IStore {
            virtual ~IStore() = default;
            // @brief Receives captured image pixels in RGBA byte order.
            // @details Provides the pixel buffer and its dimensions to the image storage implementation.
            // @param buffer: Pointer to the captured image pixel data.
            // @example buffer: pointer to pixel data
            // @param width: Width of the captured image in pixels.
            // @example width: 1920
            // @param height: Height of the captured image in pixels.
            // @example height: 1080
            // @retval true: The pixel data was stored successfully.
            // @retval false: The pixel data could not be stored.
            virtual bool R8_G8_B8_A8(const unsigned char* buffer, const unsigned int width, const unsigned int height) = 0;
        };

        // @brief Returns the name of this capture provider.
        // @details Identifies the implementation used to capture the screen.
        // @retval const TCHAR*: Name of the capture provider.
        virtual const TCHAR* Name() const = 0;

        // @brief Captures the screen and passes its pixels to a storer.
        // @details The capture implementation supplies the captured image and dimensions through the IStore callback.
        // @param storer: IStore implementation that receives the captured pixel data.
        // @example storer: An instance of a class implementing the IStore interface.
        // @retval true: The screen was captured and delivered to the storer.
        // @retval false: The screen could not be captured or delivered to the storer.
        virtual bool Capture(ICapture::IStore& storer) = 0;

        // Get the interface so we can Capture a screen
        static ICapture* Instance();
    };
}
}

