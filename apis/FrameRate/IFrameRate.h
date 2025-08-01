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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IFrameRate : virtual public Core::IUnknown
        {
            enum { ID = ID_FRAMERATE };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_FRAMERATE_NOTIFICATION };

                // @text onFpsEvent
                // @brief Triggered by callback from FrameRate after onFpsEvent
                // @param average - in - int
                // @param min - in - int
                // @param max - in - int
                virtual void OnFpsEvent(const int average, const int min, const int max) {};

                // @text onDisplayFrameRateChanging
                // @brief Triggered when the framerate changes started
                // @param displayFrameRate - in - string
                virtual void OnDisplayFrameRateChanging(const string& displayFrameRate) {};

                // @text onDisplayFrameRateChanged
                // @brief Triggered when the framerate changed.
                // @param displayFrameRate - in - string
                virtual void OnDisplayFrameRateChanged(const string& displayFrameRate) {};
            };

            virtual Core::hresult Register(IFrameRate::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFrameRate::INotification* notification) = 0;

            /** Gets the Display Frame Rate*/
            // @text getDisplayFrameRate
            // @brief Gets the current display frame rate values.
            // @param framerate - out - string
            // @param success - out - boolean
            virtual Core::hresult GetDisplayFrameRate(string& framerate /* @out */, bool& success /* @out */) = 0;

            /** Gets framerate mode */
            // @text getFrmMode
            // @brief Gets the current auto framerate mode.
            // @param frmmode - out - int
            // @param success - out - boolean
            virtual Core::hresult GetFrmMode(int &framerateMode /* @out @text:auto-frm-mode */, bool& success /* @out */) = 0;

            /** Sets the FPS data collection interval */
            // @text setCollectionFrequency
            // @brief Sets the FPS data collection interval.
            // @param frequency - in -  int
            // @param success - out - boolean
            virtual Core::hresult SetCollectionFrequency(const int frequency, bool& success /* @out */) = 0;

            /** Sets the display framerate values */
            // @text setDisplayFrameRate
            // @brief Sets the display framerate values.
            // @param framerate - in - string
            // @param success - out - boolean
            virtual Core::hresult SetDisplayFrameRate(const string& framerate, bool& success /* @out */) = 0;

            /** Sets the auto framerate mode */
            // @text setFrmMode
            // @brief Set the Frm mode.
            // @param frmmode - in - int
            // @param success - out - boolean
            virtual Core::hresult SetFrmMode(const int frmmode /* @in */, bool& success /* @out */) = 0;

            /** Starts the FPS data collection */
            // @text startFpsCollection
            // @brief Starts the FPS data collection. Starts the FPS data collection
            // @param success - out - boolean
            virtual Core::hresult StartFpsCollection(bool& success /* @out */) = 0;

            /** Stops the FPS data collection */
            // @text stopFpsCollection
            // @brief Stops the FPS data collection
            // @param success - out - boolean
            virtual Core::hresult StopFpsCollection(bool& success /* @out */) = 0;

            /** Update the FPS value */
            // @text updateFps
            // @brief Update the FPS value
            // @param newFpsValue - in - int
            // @param success - out - boolean
            virtual Core::hresult UpdateFps(const int newFpsValue, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
