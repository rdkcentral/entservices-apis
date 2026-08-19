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

        // @text echostring
        // @brief Echo a string payload; the same field carries the request value and the echoed response
        // @param value - inout - string payload; echoed back unchanged in the response
        virtual Core::hresult EchoString(string& value /* @inout */) = 0;

        // @text echoarray
        // @brief Echo a uint8 array payload (max 256 KB); the same field carries the request value and the echoed response
        // @param values - inout - byte array; echoed back unchanged in the response
        virtual Core::hresult EchoArray(std::vector<uint8_t>& values /* @inout @restrict:0..256K */) = 0;

        // @text echomixedarray
        // @brief Echo a heterogeneous-element array (max 4228 elements, ~256 KB); the same field carries the request value and the echoed response
        // @param elements - inout - array of mixed elements; echoed back unchanged in the response
        virtual Core::hresult EchoMixedArray(std::vector<MixedElement>& elements /* @inout @restrict:0..4228 */) = 0;

        // @text echonestedobjects
        // @brief Echo 4-level nested objects (max 1736 elements, ~256 KB); the same field carries the request value and the echoed response
        // @param objects - inout - array of 4-level nested objects; echoed back unchanged in the response
        virtual Core::hresult EchoNestedObjects(std::vector<NestedObject>& objects /* @inout @restrict:0..1736 */) = 0;

        // @text echoint32
        // @brief Echo a uint32 scalar value; the same field carries the request value and the echoed response
        virtual Core::hresult EchoUint32(uint32_t& value /* @inout */) = 0;

        // @text echoint64
        // @brief Echo a uint64 scalar value; the same field carries the request value and the echoed response
        virtual Core::hresult EchoUint64(uint64_t& value /* @inout */) = 0;

        // @text echobool
        // @brief Echo a boolean scalar value; the same field carries the request value and the echoed response
        virtual Core::hresult EchoBool(bool& value /* @inout */) = 0;

        // @text echofloat
        // @brief Echo a float scalar value; the same field carries the request value and the echoed response
        virtual Core::hresult EchoFloat(float& value /* @inout */) = 0;

        // @text echodouble
        // @brief Echo a double scalar value; the same field carries the request value and the echoed response
        virtual Core::hresult EchoDouble(double& value /* @inout */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
