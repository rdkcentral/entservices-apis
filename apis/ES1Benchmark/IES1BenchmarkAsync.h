/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 */

#pragma once

#include "Module.h"

#include <vector>

namespace WPEFramework {
namespace Exchange {

    /* @json 1.0.0 */
    struct EXTERNAL IES1BenchmarkAsync : virtual public Core::IUnknown {

        enum { ID = ID_ES1BENCHMARK_ASYNC };

        struct MixedElement {
            uint32_t id /* @brief Element identifier */;
            string name /* @brief Element name */;
            double value /* @brief Element floating-point value */;
            bool flag /* @brief Element boolean flag */;
        };

        struct Level4Data {
            uint32_t value /* @brief Leaf integer value */;
            string name /* @brief Leaf string value */;
        };
        struct Level3Data {
            Level4Data inner /* @brief Level-4 nested object */;
            uint32_t count /* @brief Level-3 integer */;
        };
        struct Level2Data {
            Level3Data nested /* @brief Level-3 nested object */;
            string label /* @brief Level-2 string */;
        };
        struct NestedObject {
            uint32_t id /* @brief Object identifier */;
            bool flag /* @brief Object boolean flag */;
            double score /* @brief Object score */;
            Level2Data data /* @brief Level-2 nested object */;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_NOTIFICATION };

            // @text setstringcompleted
            virtual void SetStringCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getstringcompleted
            virtual void GetStringCompleted(const uint32_t requestId, const string& value /* @restrict:0..4M */) = 0;
            // @text setarraycompleted
            virtual void SetArrayCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getarraycompleted
            virtual void GetArrayCompleted(const uint32_t requestId, const std::vector<uint8_t>& value /* @restrict:0..256K */) = 0;
            // @text setmixedarraycompleted
            virtual void SetMixedArrayCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getmixedarraycompleted
            virtual void GetMixedArrayCompleted(const uint32_t requestId, const std::vector<MixedElement>& value /* @restrict:0..4228 */) = 0;
            // @text setnestedobjectscompleted
            virtual void SetNestedObjectsCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getnestedobjectscompleted
            virtual void GetNestedObjectsCompleted(const uint32_t requestId, const std::vector<NestedObject>& value /* @restrict:0..1736 */) = 0;
            // @text setuint32completed
            virtual void SetUint32Completed(const uint32_t requestId, const bool success) = 0;
            // @text getuint32completed
            virtual void GetUint32Completed(const uint32_t requestId, const uint32_t value) = 0;
            // @text setuint64completed
            virtual void SetUint64Completed(const uint32_t requestId, const bool success) = 0;
            // @text getuint64completed
            virtual void GetUint64Completed(const uint32_t requestId, const uint64_t value) = 0;
            // @text setboolcompleted
            virtual void SetBoolCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getboolcompleted
            virtual void GetBoolCompleted(const uint32_t requestId, const bool value) = 0;
            // @text setfloatcompleted
            virtual void SetFloatCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getfloatcompleted
            virtual void GetFloatCompleted(const uint32_t requestId, const float value) = 0;
            // @text setdoublecompleted
            virtual void SetDoubleCompleted(const uint32_t requestId, const bool success) = 0;
            // @text getdoublecompleted
            virtual void GetDoubleCompleted(const uint32_t requestId, const double value) = 0;
            // @text measurecopycostcompleted
            virtual void MeasureCopyCostCompleted(const uint32_t requestId, const uint64_t microseconds) = 0;
            // @text measurestringresizecostcompleted
            virtual void MeasureStringResizeCostCompleted(const uint32_t requestId, const uint64_t microseconds) = 0;
            // @text measuremixedassigncostcompleted
            virtual void MeasureMixedAssignCostCompleted(const uint32_t requestId, const uint64_t microseconds) = 0;
            // @text measurenestedassigncostcompleted
            virtual void MeasureNestedAssignCostCompleted(const uint32_t requestId, const uint64_t microseconds) = 0;
        };

        ~IES1BenchmarkAsync() override = default;

        virtual Core::hresult Register(INotification* const notification) = 0;
        virtual Core::hresult Unregister(const INotification* const notification) = 0;

        // @text setstring
        virtual Core::hresult SetString(const uint32_t requestId /* @in */, const string& value /* @in @restrict:0..4M */) = 0;
        // @text getstring
        virtual Core::hresult GetString(const uint32_t requestId /* @in */, const uint32_t size /* @in @restrict:0..4M */) = 0;
        // @text setarray
        virtual Core::hresult SetArray(const uint32_t requestId /* @in */, const std::vector<uint8_t>& value /* @in @restrict:0..256K */) = 0;
        // @text getarray
        virtual Core::hresult GetArray(const uint32_t requestId /* @in */, const uint32_t size /* @in @restrict:0..256K */) = 0;
        // @text setmixedarray
        virtual Core::hresult SetMixedArray(const uint32_t requestId /* @in */, const std::vector<MixedElement>& value /* @in @restrict:0..4228 */) = 0;
        // @text getmixedarray
        virtual Core::hresult GetMixedArray(const uint32_t requestId /* @in */, const uint32_t count /* @in @restrict:0..4228 */) = 0;
        // @text setnestedobjects
        virtual Core::hresult SetNestedObjects(const uint32_t requestId /* @in */, const std::vector<NestedObject>& value /* @in @restrict:0..1736 */) = 0;
        // @text getnestedobjects
        virtual Core::hresult GetNestedObjects(const uint32_t requestId /* @in */, const uint32_t count /* @in @restrict:0..1736 */) = 0;
        // @text setuint32
        virtual Core::hresult SetUint32(const uint32_t requestId /* @in */, const uint32_t value) = 0;
        // @text getuint32
        virtual Core::hresult GetUint32(const uint32_t requestId /* @in */) = 0;
        // @text setuint64
        virtual Core::hresult SetUint64(const uint32_t requestId /* @in */, const uint64_t value) = 0;
        // @text getuint64
        virtual Core::hresult GetUint64(const uint32_t requestId /* @in */) = 0;
        // @text setbool
        virtual Core::hresult SetBool(const uint32_t requestId /* @in */, const bool value) = 0;
        // @text getbool
        virtual Core::hresult GetBool(const uint32_t requestId /* @in */) = 0;
        // @text setfloat
        virtual Core::hresult SetFloat(const uint32_t requestId /* @in */, const float value) = 0;
        // @text getfloat
        virtual Core::hresult GetFloat(const uint32_t requestId /* @in */) = 0;
        // @text setdouble
        virtual Core::hresult SetDouble(const uint32_t requestId /* @in */, const double value) = 0;
        // @text getdouble
        virtual Core::hresult GetDouble(const uint32_t requestId /* @in */) = 0;
        // @text measurecopycost
        virtual Core::hresult MeasureCopyCost(const uint32_t requestId /* @in */, const uint32_t size /* @in @restrict:0..256K */) = 0;
        // @text measurestringresizecost
        virtual Core::hresult MeasureStringResizeCost(const uint32_t requestId /* @in */, const uint32_t size /* @in @restrict:0..4M */) = 0;
        // @text measuremixedassigncost
        virtual Core::hresult MeasureMixedAssignCost(const uint32_t requestId /* @in */, const uint32_t count /* @in @restrict:0..4228 */) = 0;
        // @text measurenestedassigncost
        virtual Core::hresult MeasureNestedAssignCost(const uint32_t requestId /* @in */, const uint32_t count /* @in @restrict:0..1736 */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
