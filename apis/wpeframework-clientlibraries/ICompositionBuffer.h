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
    struct EXTERNAL ICompositionBuffer {
        /**
         * @brief   frame buffer interface with hardware optimisation in mind
         */

        using buffer_id = uintptr_t;

        enum DataType : uint8_t {
            TYPE_INVALID = 0x00, // Invalid buffer
            TYPE_DMA = 0x01, // DMA buffer  
            TYPE_RAW = 0x02 // Raw buffer
        };

        virtual ~ICompositionBuffer() = default;

        struct IPlane {
            virtual ~IPlane() = default;

            virtual buffer_id Accessor() const = 0; // Access to the actual data.

            virtual uint32_t Stride() const = 0; // Bytes per row for a plane [(bit-per-pixel/8) * width]
            virtual uint32_t Offset() const = 0; // Offset of the plane from where the pixel data starts in the buffer.
        };

        struct IIterator {
            virtual ~IIterator() = default;

            // @brief Check whether the iterator refers to a valid plane.
            // @details Reports whether the iterator is positioned on a valid plane.
            // @retval valid: True when the iterator refers to a valid plane; otherwise false.
            virtual bool IsValid() const = 0;

            // @brief Reset the plane iterator.
            // @details Resets the iterator to its initial position before the first plane.
            virtual void Reset() = 0;

            // @brief Advance the plane iterator.
            // @details Advances the iterator to the next plane and reports whether one exists.
            // @retval hasNext: True when the iterator advanced to another plane; otherwise false.
            virtual bool Next() = 0;

            // @brief Get the current plane.
            // @details Returns the plane at the iterator's current position.
            // @retval plane: Current plane, or nullptr when no valid plane is selected.
            virtual IPlane* Plane() = 0;
        };

        // @brief Add a reference to the buffer.
        // @details Increments the buffer's reference count to keep it alive.
        virtual void AddRef() const = 0;

        // @brief Release a reference to the buffer.
        // @details Decrements the buffer's reference count and reports the remaining count.
        // @retval referenceCount: Number of references remaining after release.
        virtual uint32_t Release() const = 0;

        // @brief Get the buffer identifier.
        // @details Returns the identifier assigned to this composition buffer.
        // @retval identifier: Buffer identifier.
        virtual uint32_t Identifier() const = 0;

        virtual IIterator* Planes(const uint32_t timeoutMs) = 0; // Access the planes.
        
        // @brief Complete access to the buffer planes.
        // @details Signals that the caller has finished using the planes and indicates whether the buffer contents changed.
        // @param dirty True if the buffer contents were modified; otherwise false.
        // @example dirty: true
        // @retval Core::ERROR_NONE: Plane access was completed successfully.
        virtual uint32_t Completed(const bool dirty) = 0;

        // @brief Submit the buffer for rendering.
        // @details Marks the buffer for scan-out by the display.
        virtual void Render() = 0;

        // @brief Get the buffer width.
        // @details Returns the allocated buffer width in pixels.
        // @retval width: Buffer width in pixels.
        virtual uint32_t Width() const = 0;

        // @brief Get the buffer height.
        // @details Returns the allocated buffer height in pixels.
        // @retval height: Buffer height in pixels.
        virtual uint32_t Height() const = 0;

        // @brief Get the buffer pixel format.
        // @details Returns the pixel layout encoded using a FourCC format.
        // @retval format: FourCC pixel format value.
        virtual uint32_t Format() const = 0;

        // @brief Get the buffer modifier.
        // @details Returns the modifier describing the buffer's pixel arrangement for hardware optimization.
        // @retval modifier: Buffer layout modifier value.
        virtual uint64_t Modifier() const = 0;

        // @brief Get the buffer data type.
        // @details Returns whether this buffer contains DMA data, raw data, or an invalid type.
        // @retval type: Buffer data type.
        virtual DataType Type() const = 0;
    }; // struct ICompositionBuffer

} // namespace Exchange

} // namespace WPEFramework
