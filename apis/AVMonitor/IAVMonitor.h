/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
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

    /* @json */
    struct EXTERNAL IAVMonitor : virtual public Core::IUnknown {
        enum { ID = ID_AVMONITOR };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_AVMONITOR_NOTIFICATION };
            ~INotification() override = default;

            // @brief Notifies that new events have been retrieved
            // @text onnewevent
            virtual void OnNewEvent(const string& event) = 0;

            // @brief Notification with all events send after stop capture
            // @text onsummary
            virtual void OnSummary(const string& events) = 0;
        };

        ~IAVMonitor() override = default;

        virtual uint32_t Register(IAVMonitor::INotification* sink) = 0;
        virtual uint32_t Unregister(IAVMonitor::INotification* sink) = 0;

        enum CaptureMode: int {
            NONE = 0        /* @text: NONE */,
            LIVE = 1        /* @text: LIVE */,
            SUMMARY = 2     /* @text: SUMMARY */,
            MIXED = 3       /* @text: MIXED */,
        };
        // @brief Begin capture session
        // @text startcapture
        virtual uint32_t StartCapture(const uint32_t interval, const CaptureMode captureMode) = 0;

        // @brief End capture session
        // @text stopcapture
        virtual uint32_t StopCapture() = 0;

        /* @json:omit */
        virtual uint32_t RegisterEvent(const string& event /* @in */) = 0;

    };
}
}
