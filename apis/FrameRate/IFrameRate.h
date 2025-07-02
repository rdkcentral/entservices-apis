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
		// @plugindescription This plugin allows to collect FPS related data on TV profile stack.
        struct EXTERNAL IFrameRate : virtual public Core::IUnknown
        {
            enum { ID = ID_FRAMERATE };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_FRAMERATE_NOTIFICATION };

                // @text onFpsEvent
                // @details Triggered at the end of each interval as defined by the `setCollectionFrequency` method
                // after `startFpsCollection` method and once after the `stopFpsCollection` method is invoked
                // @param average: The average FPS e.g. 60
                // @param min: The minimum FPS e.g. 30
                // @param max: The maximum FPS e.g. 120
                virtual void OnFpsEvent(const int average /* @in */, const int min /* @in */, const int max /* @in */) {};

                // @text onDisplayFrameRateChanging
                // @details This event is triggered when the display frame rate is about to change
				// and represented as "WIDTHxHEIGHTxFPS".
                // @param displayFrameRate: The new display frame rate e.g. "1920x1080x60"
                virtual void OnDisplayFrameRateChanging(const string& displayFrameRate /* @in */) {};

                // @text onDisplayFrameRateChanged
                // @details This event is triggered after the display frame rate has changed
				// and represented as "WIDTHxHEIGHTxFPS".
                // @param displayFrameRate: The new display frame rate e.g. "1920x1080x60"
                virtual void OnDisplayFrameRateChanged(const string& displayFrameRate /* @in */) {};
            };

			// @omit
            virtual Core::hresult Register(IFrameRate::INotification* notification) = 0;
			// @omit
            virtual Core::hresult Unregister(IFrameRate::INotification* notification) = 0;

            /** Gets the Display Frame Rate*/
            // @text getDisplayFrameRate
            // @details Retrieves the current display frame rate as a string in the format "WIDTHxHEIGHTpxFPS"
            // @param framerate: The current display frame rate. e.g. "3840x2160px60"
            // @param success: Indicates if the operation was successful e.g. True
            // @returns Core::hresult
            virtual Core::hresult GetDisplayFrameRate(string& framerate /* @out */, bool& success /* @out */) = 0;

            /** Gets framerate mode */
            // @text getFrmMode
            // @details Retrieves the current auto framerate mode as an integer. Expeted values are 0 or 1.
            // @param auto-frm-mode: The current auto framerate mode. e.g. 1
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult GetFrmMode(int &framerateMode /* @out @text:auto-frm-mode */, bool& success /* @out */) = 0;

            /** Sets the FPS data collection interval */
            // @text setCollectionFrequency
            // @details Sets the interval for FPS data collection in milliseconds. Default is 10000ms and min is 100ms
            // @param frequency: The collection frequency in ms. e.g. 1000
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult SetCollectionFrequency(const int frequency /* @in */, bool& success /* @out */) = 0;

            /** Sets the display framerate values */
            // @text setDisplayFrameRate
            // @details Sets the display framerate to the specified value in the format "WIDTHxHEIGHTpxFPS".
            // @param framerate: The display framerate to set. e.g. "3840px2160px30"
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult SetDisplayFrameRate(const string& framerate /* @in */, bool& success /* @out */) = 0;

            /** Sets the auto framerate mode */
            // @text setFrmMode
            // @details Sets the auto framerate mode to the specified value. Expected values are 0(disable) or 1(enable).
            // @param frmmode: The framerate mode to set. e.g. 1
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult SetFrmMode(const int frmmode /* @in */, bool& success /* @out */) = 0;

            /** Starts the FPS data collection */
            // @text startFpsCollection
            // @details Starts collecting FPS data at the configured interval set by the method `SetCollectionFrequency`.
            // @see onFpsEvent
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult StartFpsCollection(bool& success /* @out */) = 0;

            /** Stops the FPS data collection */
            // @text stopFpsCollection
            // @details Stops the FPS data collection.
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult StopFpsCollection(bool& success /* @out */) = 0;

            /** Update the FPS value */
            // @text updateFps
            // @details Updates the current FPS value to the specified value represented as integer.
            // @see onFpsEvent
            // @param newFpsValue: The new FPS value. e.g. 60
            // @param success: Indicates if the operation was successful. e.g. True
            // @returns Core::hresult
            virtual Core::hresult UpdateFps(const int newFpsValue /* @in */, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
