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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    // @json
    struct EXTERNAL IES1Benchmark : virtual public Core::IUnknown {
        enum { ID = ID_ES1BENCHMARK };

        // using IUInt8Iterator = RPC::IIteratorType<uint8_t, ID_ES1BENCHMARK_UINT8ITERATOR>;

        ~IES1Benchmark() override = default;

        struct MixedElement {
            uint32_t id    /* @brief Element identifier */;
            string   name  /* @brief Element name */;
            double   value /* @brief Element floating-point value */;
            bool     flag  /* @brief Element boolean flag */;
        };

        // Nested structs for deep container traversal benchmark (4 levels)
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

        // @text setstring
        virtual uint32_t SetString(const string& value /* @in @restrict:0..4M */) = 0;

        // @text getstring
        virtual uint32_t GetString(const uint32_t size /* @in @restrict:0..4M */, string& value /* @out @restrict:0..4M */) = 0;

        // @text setarray
        virtual uint32_t SetArray(const std::vector<uint8_t>& value /* @in @restrict:0..256K */) = 0;

        // @text getarray
        virtual uint32_t GetArray(const uint32_t size /* @in @restrict:0..256K */, std::vector<uint8_t>& value /* @out @restrict:0..256K */) = 0;

        // @text setmixedarray
        virtual uint32_t SetMixedArray(const std::vector<MixedElement>& value /* @in @restrict:0..4228 */) = 0;

        // @text getmixedarray
        virtual uint32_t GetMixedArray(const uint32_t count /* @in @restrict:0..4228 */, std::vector<MixedElement>& value /* @out @restrict:0..4228 */) = 0;

        // @text setnestedobjects
        virtual uint32_t SetNestedObjects(const std::vector<NestedObject>& value /* @in @restrict:0..1736 */) = 0;

        // @text getnestedobjects
        virtual uint32_t GetNestedObjects(const uint32_t count /* @in @restrict:0..1736 */, std::vector<NestedObject>& value /* @out @restrict:0..1736 */) = 0;

        // @text setuint32
        virtual uint32_t SetUint32(const uint32_t value /* @in */) = 0;

        // @text getuint32
        virtual uint32_t GetUint32(uint32_t& value /* @out */) = 0;

        // @text setuint64
        virtual uint32_t SetUint64(const uint64_t value /* @in */) = 0;

        // @text getuint64
        virtual uint32_t GetUint64(uint64_t& value /* @out */) = 0;

        // @text setbool
        virtual uint32_t SetBool(const bool value /* @in */) = 0;

        // @text getbool
        virtual uint32_t GetBool(bool& value /* @out */) = 0;

        // @text setfloat
        virtual uint32_t SetFloat(const float value /* @in */) = 0;

        // @text getfloat
        virtual uint32_t GetFloat(float& value /* @out */) = 0;

        // @text setdouble
        virtual uint32_t SetDouble(const double value /* @in */) = 0;

        // @text getdouble
        virtual uint32_t GetDouble(double& value /* @out */) = 0;

        // @text measurecopycost
        virtual uint32_t MeasureCopyCost(const uint32_t size /* @in @restrict:0..256K */, uint64_t& us /* @out */) = 0;

        // @text measurestringresizecost
        virtual uint32_t MeasureStringResizeCost(const uint32_t size /* @in @restrict:0..4M */, uint64_t& us /* @out */) = 0;

        // @text measuremixedassigncost
        virtual uint32_t MeasureMixedAssignCost(const uint32_t count /* @in @restrict:0..4228 */, uint64_t& us /* @out */) = 0;

        // @text measurenestedassigncost
        virtual uint32_t MeasureNestedAssignCost(const uint32_t count /* @in @restrict:0..1736 */, uint64_t& us /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework