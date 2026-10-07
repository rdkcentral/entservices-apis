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

        struct EXTERNAL ISetStringCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETSTRING_CALLBACK };
            ~ISetStringCallback() override = default;
            // @brief Signals completion of SetString
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetStringCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETSTRING_CALLBACK };
            ~IGetStringCallback() override = default;
            // @brief Signals completion of GetString
            // @param value Retrieved string value
            virtual void Complete(const string& value /* @restrict:0..4M */) = 0;
        };
        struct EXTERNAL ISetArrayCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETARRAY_CALLBACK };
            ~ISetArrayCallback() override = default;
            // @brief Signals completion of SetArray
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetArrayCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETARRAY_CALLBACK };
            ~IGetArrayCallback() override = default;
            // @brief Signals completion of GetArray
            // @param value Retrieved byte array
            virtual void Complete(const std::vector<uint8_t>& value /* @restrict:0..256K */) = 0;
        };
        struct EXTERNAL ISetMixedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETMIXED_CALLBACK };
            ~ISetMixedCallback() override = default;
            // @brief Signals completion of SetMixedArray
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetMixedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETMIXED_CALLBACK };
            ~IGetMixedCallback() override = default;
            // @brief Signals completion of GetMixedArray
            // @param value Retrieved mixed-element array
            virtual void Complete(const std::vector<MixedElement>& value /* @restrict:0..4228 */) = 0;
        };
        struct EXTERNAL ISetNestedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETNESTED_CALLBACK };
            ~ISetNestedCallback() override = default;
            // @brief Signals completion of SetNestedObjects
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetNestedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETNESTED_CALLBACK };
            ~IGetNestedCallback() override = default;
            // @brief Signals completion of GetNestedObjects
            // @param value Retrieved nested-object array
            virtual void Complete(const std::vector<NestedObject>& value /* @restrict:0..1736 */) = 0;
        };
        struct EXTERNAL ISetUint32Callback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETUINT32_CALLBACK };
            ~ISetUint32Callback() override = default;
            // @brief Signals completion of SetUint32
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetUint32Callback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETUINT32_CALLBACK };
            ~IGetUint32Callback() override = default;
            // @brief Signals completion of GetUint32
            // @param value Retrieved value
            virtual void Complete(const uint32_t value) = 0;
        };
        struct EXTERNAL ISetUint64Callback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETUINT64_CALLBACK };
            ~ISetUint64Callback() override = default;
            // @brief Signals completion of SetUint64
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetUint64Callback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETUINT64_CALLBACK };
            ~IGetUint64Callback() override = default;
            // @brief Signals completion of GetUint64
            // @param value Retrieved value
            virtual void Complete(const uint64_t value) = 0;
        };
        struct EXTERNAL ISetBoolCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETBOOL_CALLBACK };
            ~ISetBoolCallback() override = default;
            // @brief Signals completion of SetBool
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetBoolCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETBOOL_CALLBACK };
            ~IGetBoolCallback() override = default;
            // @brief Signals completion of GetBool
            // @param value Retrieved value
            virtual void Complete(const bool value) = 0;
        };
        struct EXTERNAL ISetFloatCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETFLOAT_CALLBACK };
            ~ISetFloatCallback() override = default;
            // @brief Signals completion of SetFloat
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetFloatCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETFLOAT_CALLBACK };
            ~IGetFloatCallback() override = default;
            // @brief Signals completion of GetFloat
            // @param value Retrieved value
            virtual void Complete(const float value) = 0;
        };
        struct EXTERNAL ISetDoubleCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_SETDOUBLE_CALLBACK };
            ~ISetDoubleCallback() override = default;
            // @brief Signals completion of SetDouble
            virtual void Complete() = 0;
        };
        struct EXTERNAL IGetDoubleCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_GETDOUBLE_CALLBACK };
            ~IGetDoubleCallback() override = default;
            // @brief Signals completion of GetDouble
            // @param value Retrieved value
            virtual void Complete(const double value) = 0;
        };
        struct EXTERNAL IMeasureCopyCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_MEASURECOPY_CALLBACK };
            ~IMeasureCopyCallback() override = default;
            // @brief Signals completion of MeasureCopyCost
            // @param microseconds Measured operation cost
            virtual void Complete(const uint64_t microseconds) = 0;
        };
        struct EXTERNAL IMeasureStringCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_MEASURESTRING_CALLBACK };
            ~IMeasureStringCallback() override = default;
            // @brief Signals completion of MeasureStringResizeCost
            // @param microseconds Measured operation cost
            virtual void Complete(const uint64_t microseconds) = 0;
        };
        struct EXTERNAL IMeasureMixedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_MEASUREMIXED_CALLBACK };
            ~IMeasureMixedCallback() override = default;
            // @brief Signals completion of MeasureMixedAssignCost
            // @param microseconds Measured operation cost
            virtual void Complete(const uint64_t microseconds) = 0;
        };
        struct EXTERNAL IMeasureNestedCallback : virtual public Core::IUnknown {
            enum { ID = ID_ES1BENCHMARK_ASYNC_MEASURENESTED_CALLBACK };
            ~IMeasureNestedCallback() override = default;
            // @brief Signals completion of MeasureNestedAssignCost
            // @param microseconds Measured operation cost
            virtual void Complete(const uint64_t microseconds) = 0;
        };

        ~IES1BenchmarkAsync() override = default;

        // @text setstring
        // @async
        // @brief Sets the benchmark string value
        // @param value String payload to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetString(const string& value /* @in @restrict:0..4M */, ISetStringCallback* const callback) = 0;
        // @text getstring
        // @async
        // @brief Retrieves a string of the requested size
        // @param size Requested string length in bytes
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetString(const uint32_t size /* @in @restrict:0..4M */, IGetStringCallback* const callback) = 0;
        // @text setarray
        // @async
        // @brief Sets the benchmark byte array value
        // @param value Byte array payload to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetArray(const std::vector<uint8_t>& value /* @in @restrict:0..256K */, ISetArrayCallback* const callback) = 0;
        // @text getarray
        // @async
        // @brief Retrieves a byte array of the requested size
        // @param size Requested element count
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetArray(const uint32_t size /* @in @restrict:0..256K */, IGetArrayCallback* const callback) = 0;
        // @text setmixedarray
        // @async
        // @brief Sets the benchmark mixed-element array value
        // @param value Mixed-element array payload to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetMixedArray(const std::vector<MixedElement>& value /* @in @restrict:0..4228 */, ISetMixedCallback* const callback) = 0;
        // @text getmixedarray
        // @async
        // @brief Retrieves a mixed-element array of the requested count
        // @param count Requested element count
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetMixedArray(const uint32_t count /* @in @restrict:0..4228 */, IGetMixedCallback* const callback) = 0;
        // @text setnestedobjects
        // @async
        // @brief Sets the benchmark nested-object array value
        // @param value Nested-object array payload to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetNestedObjects(const std::vector<NestedObject>& value /* @in @restrict:0..1736 */, ISetNestedCallback* const callback) = 0;
        // @text getnestedobjects
        // @async
        // @brief Retrieves a nested-object array of the requested count
        // @param count Requested element count
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetNestedObjects(const uint32_t count /* @in @restrict:0..1736 */, IGetNestedCallback* const callback) = 0;
        // @text setuint32
        // @async
        // @brief Sets the benchmark uint32 value
        // @param value Value to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetUint32(const uint32_t value, ISetUint32Callback* const callback) = 0;
        // @text getuint32
        // @async
        // @brief Retrieves the benchmark uint32 value
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetUint32(IGetUint32Callback* const callback) = 0;
        // @text setuint64
        // @async
        // @brief Sets the benchmark uint64 value
        // @param value Value to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetUint64(const uint64_t value, ISetUint64Callback* const callback) = 0;
        // @text getuint64
        // @async
        // @brief Retrieves the benchmark uint64 value
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetUint64(IGetUint64Callback* const callback) = 0;
        // @text setbool
        // @async
        // @brief Sets the benchmark boolean value
        // @param value Value to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetBool(const bool value, ISetBoolCallback* const callback) = 0;
        // @text getbool
        // @async
        // @brief Retrieves the benchmark boolean value
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetBool(IGetBoolCallback* const callback) = 0;
        // @text setfloat
        // @async
        // @brief Sets the benchmark float value
        // @param value Value to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetFloat(const float value, ISetFloatCallback* const callback) = 0;
        // @text getfloat
        // @async
        // @brief Retrieves the benchmark float value
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetFloat(IGetFloatCallback* const callback) = 0;
        // @text setdouble
        // @async
        // @brief Sets the benchmark double value
        // @param value Value to store
        // @param callback Invoked when the operation completes
        virtual Core::hresult SetDouble(const double value, ISetDoubleCallback* const callback) = 0;
        // @text getdouble
        // @async
        // @brief Retrieves the benchmark double value
        // @param callback Invoked when the operation completes
        virtual Core::hresult GetDouble(IGetDoubleCallback* const callback) = 0;
        // @text measurecopycost
        // @async
        // @brief Measures the cost of copying a byte buffer of the given size
        // @param size Buffer size in bytes
        // @param callback Invoked when the operation completes
        virtual Core::hresult MeasureCopyCost(const uint32_t size /* @in @restrict:0..256K */, IMeasureCopyCallback* const callback) = 0;
        // @text measurestringresizecost
        // @async
        // @brief Measures the cost of resizing a string to the given size
        // @param size String size in bytes
        // @param callback Invoked when the operation completes
        virtual Core::hresult MeasureStringResizeCost(const uint32_t size /* @in @restrict:0..4M */, IMeasureStringCallback* const callback) = 0;
        // @text measuremixedassigncost
        // @async
        // @brief Measures the cost of assigning a mixed-element array of the given count
        // @param count Element count
        // @param callback Invoked when the operation completes
        virtual Core::hresult MeasureMixedAssignCost(const uint32_t count /* @in @restrict:0..4228 */, IMeasureMixedCallback* const callback) = 0;
        // @text measurenestedassigncost
        // @async
        // @brief Measures the cost of nested assignment operations
        // @param count Number of assignments to perform
        // @param callback Invoked when the operation completes
        virtual Core::hresult MeasureNestedAssignCost(const uint32_t count /* @in @restrict:0..1736 */, IMeasureNestedCallback* const callback) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
