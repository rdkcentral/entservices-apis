/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

// @text:keep
struct EXTERNAL ITelemetryMetrics : virtual public Core::IUnknown {
    enum { ID = ID_TELEMETRYMETRICS };

    /** @brief Record the telementryMetrics add new hash values to existing hash */
    // @text record
    // @param id  string identifier for the telemetry record.
    // @param telemetryMetrics  jsonString hash  contains key value pair of telemetryData
    // @param markerName Groups related metrics
    virtual Core::hresult Record(const string& id, const string& telemetryMetrics, const string& markerName) = 0;

    /** @brief Publish the Telemetry Data 
            makes a T2 call that records all the key / value pairs in 
            hash. The existing id and hash are cleared after publish.*/
    // @text publish
    // @param id string identifier for the telemetry record.
    // @param markerName Groups related metrics
    virtual Core::hresult Publish(const string& id, const string& markerName) = 0;
};
}// namespace Exchange
}// namespace WPEFramework
