/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Metrological
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

    /* @json 1.0.0 @text:keep */
    struct EXTERNAL IES1Benchmark : virtual public Core::IUnknown {
        enum { ID = ID_ES1BENCHMARK };

        ~IES1Benchmark() override = default;

        // Mixed element for heterogeneous array benchmark
        struct MixedElement {
            uint32_t id    /* @brief Element identifier */;
            string   name  /* @brief Element name */;
            double   value /* @brief Element floating-point value */;
            bool     flag  /* @brief Element boolean flag */;
        };

        // 4-level nested structs for deep container traversal benchmark
        struct Level4Data {
            uint32_t value /* @brief Leaf integer value */;
            string   name  /* @brief Leaf string value */;
        };

        struct Level3Data {
            Level4Data inner /* @brief Level-4 nested object */;
            uint32_t   count /* @brief Level-3 integer */;
        };

        struct Level2Data {
            Level3Data nested /* @brief Level-3 nested object */;
            string     label  /* @brief Level-2 string */;
        };

        struct NestedObject {
            uint32_t   id    /* @brief Object identifier */;
            bool       flag  /* @brief Object boolean */;
            double     score /* @brief Object score */;
            Level2Data data  /* @brief Level-2 nested object */;
        };

        // --- String ---

        // @text setstring
        // @brief Accept a string payload; measures pure deserialize/dispatch cost
        virtual Core::hresult SetString(const string& value /* @in */) = 0;

        // @text getstring
        // @brief Return a string payload of the requested size
        // @param size  - in  - requested string length
        // @param value - out - filled string, sized by 'size'
        virtual Core::hresult GetString(const uint32_t size /* @in @restrict:0..4M */,
                                        string& value /* @out */) = 0;

        // --- Array ---

        // @text setarray
        // @brief Accept a uint8 array payload (max 256 KB); measures pure deserialize/dispatch cost
        virtual Core::hresult SetArray(const std::vector<uint8_t>& value /* @in @restrict:0..256K */) = 0;

        // @text getarray
        // @brief Return a uint8 array of the requested size (max 256 KB)
        // @param size  - in  - requested array length
        // @param value - out - filled byte array, sized by 'size'
        virtual Core::hresult GetArray(const uint32_t size /* @in @restrict:0..256K */,
                                       std::vector<uint8_t>& value /* @out @restrict:0..256K */) = 0;

        // --- Mixed array ---

        // @text setmixedarray
        // @brief Accept a heterogeneous-element array (max 4228 elements, ~256 KB); measures pure deserialize/dispatch cost
        virtual Core::hresult SetMixedArray(const std::vector<MixedElement>& value /* @in @restrict:0..4228 */) = 0;

        // @text getmixedarray
        // @brief Return a heterogeneous-element array of the requested count (max 4228 elements, ~256 KB)
        // @param count - in  - requested element count
        // @param value - out - filled element array, sized by 'count'
        virtual Core::hresult GetMixedArray(const uint32_t count /* @in @restrict:0..4228 */,
                                            std::vector<MixedElement>& value /* @out @restrict:0..4228 */) = 0;

        // --- Nested objects ---

        // @text setnestedobjects
        // @brief Accept 4-level nested objects (max 1736 elements, ~256 KB); measures pure deserialize/dispatch cost
        virtual Core::hresult SetNestedObjects(const std::vector<NestedObject>& value /* @in @restrict:0..1736 */) = 0;

        // @text getnestedobjects
        // @brief Return 4-level nested objects of the requested count (max 1736 elements, ~256 KB)
        // @param count - in  - requested element count
        // @param value - out - filled nested object array, sized by 'count'
        virtual Core::hresult GetNestedObjects(const uint32_t count /* @in @restrict:0..1736 */,
                                               std::vector<NestedObject>& value /* @out @restrict:0..1736 */) = 0;

        // --- Scalars ---

        // @text setint32
        // @brief Accept a uint32 scalar value; measures pure deserialize/dispatch cost
        virtual Core::hresult SetUint32(const uint32_t value /* @in */) = 0;

        // @text getint32
        // @brief Return a uint32 scalar value
        virtual Core::hresult GetUint32(uint32_t& value /* @out */) = 0;

        // @text setint64
        // @brief Accept a uint64 scalar value; measures pure deserialize/dispatch cost
        virtual Core::hresult SetUint64(const uint64_t value /* @in */) = 0;

        // @text getint64
        // @brief Return a uint64 scalar value
        virtual Core::hresult GetUint64(uint64_t& value /* @out */) = 0;

        // @text setbool
        // @brief Accept a boolean scalar value; measures pure deserialize/dispatch cost
        virtual Core::hresult SetBool(const bool value /* @in */) = 0;

        // @text getbool
        // @brief Return a boolean scalar value
        virtual Core::hresult GetBool(bool& value /* @out */) = 0;

        // @text setfloat
        // @brief Accept a float scalar value; measures pure deserialize/dispatch cost
        virtual Core::hresult SetFloat(const float value /* @in */) = 0;

        // @text getfloat
        // @brief Return a float scalar value
        virtual Core::hresult GetFloat(float& value /* @out */) = 0;

        // @text setdouble
        // @brief Accept a double scalar value; measures pure deserialize/dispatch cost
        virtual Core::hresult SetDouble(const double value /* @in */) = 0;

        // @text getdouble
        // @brief Return a double scalar value
        virtual Core::hresult GetDouble(double& value /* @out */) = 0;

        // --- Calibration (not part of the Get*/Set* benchmark path) ---

        // @text measurecopycost
        // @brief One-off calibration: times a vector resize+memcpy of the given size, mirroring GetArray exactly.
        //        Call this separately from the Get*/Set* benchmark run, never interleaved with it.
        // @param size - in  - size in bytes to copy
        // @param us   - out - measured copy duration in microseconds
        virtual Core::hresult MeasureCopyCost(const uint32_t size /* @in @restrict:0..4M */,
                                              uint64_t& us /* @out */) = 0;

        // @text measurestringresizecost
        // @brief One-off calibration: times a string resize+memcpy of the given size,
        //        mirroring GetString exactly (same reasoning as MeasureCopyCost/GetArray,
        //        which resize() a std::vector before their memcpy too).
        //        Call this separately from the Get*/Set* benchmark run, never interleaved with it.
        // @param size - in  - size in bytes
        // @param us   - out - measured resize+copy duration in microseconds
        virtual Core::hresult MeasureStringResizeCost(const uint32_t size /* @in @restrict:0..4M */,
                                                       uint64_t& us /* @out */) = 0;

        // @text measuremixedassigncost
        // @brief One-off calibration: times a vector assign of 'count' mixed elements in isolation.
        //        Call this separately from the Get*/Set* benchmark run, never interleaved with it.
        // @param count - in  - element count to assign
        // @param us    - out - measured assign duration in microseconds
        virtual Core::hresult MeasureMixedAssignCost(const uint32_t count /* @in @restrict:0..4228 */,
                                                     uint64_t& us /* @out */) = 0;

        // @text measurenestedassigncost
        // @brief One-off calibration: times a vector assign of 'count' nested objects in isolation.
        //        Call this separately from the Get*/Set* benchmark run, never interleaved with it.
        // @param count - in  - element count to assign
        // @param us    - out - measured assign duration in microseconds
        virtual Core::hresult MeasureNestedAssignCost(const uint32_t count /* @in @restrict:0..1736 */,
                                                      uint64_t& us /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
