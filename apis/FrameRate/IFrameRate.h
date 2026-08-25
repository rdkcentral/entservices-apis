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
                // @details Triggered by callback from FrameRate after onFpsEvent
                // @param average - in - int
                // @example average: 60
                // @param min - in - int
                // @example min: 30
                // @param max - in - int
                // @example max: 120
                virtual void OnFpsEvent(const int average, const int min, const int max) {};

                // @text onDisplayFrameRateChanging
                // @brief Triggered when the framerate changes started
                // @details This event is triggered when the system begins transitioning to a new display framerate.
                // transition and before the new framerate is fully applied.
                // @param displayFrameRate - in - string
                // @example displayFrameRate: "60"
                virtual void OnDisplayFrameRateChanging(const string& displayFrameRate) {};

                // @text onDisplayFrameRateChanged
                // @brief Triggered when the framerate changed.
                // @details This event is triggered after a display framerate transition is completed
                // and the new framerate value becomes active.
                // @param displayFrameRate - in - string
                // @example displayFrameRate: "60"
                virtual void OnDisplayFrameRateChanged(const string& displayFrameRate) {};
            };

            virtual Core::hresult Register(IFrameRate::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFrameRate::INotification* notification) = 0;

            /** Gets the Display Frame Rate*/
            // @text getDisplayFrameRate
            // @brief Gets the current display frame rate values.
            // @details Obtains the display framerate values currently configured for the system. 
            // The returned information can be used to determine the active display framerate settings.
            // @param framerate - out - string
            // @example framerate: "60"
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetDisplayFrameRate(string& framerate /* @out */, bool& success /* @out */) = 0;

            /** Gets framerate mode */
            // @text getFrmMode
            // @brief Gets the current auto framerate mode.
            // @details Returns the auto framerate mode currently configured in the system. 
            // The retrieved value indicates the active framerate management setting.
            // @param frmmode - out - int
            // @example frmmode: 1
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult GetFrmMode(int &framerateMode /* @out @text:auto-frm-mode */, bool& success /* @out */) = 0;

            /** Sets the FPS data collection interval */
            // @text setCollectionFrequency
            // @brief Sets the FPS data collection interval.
            // @details Specifies how frequently FPS metrics are collected during an active monitoring session. 
            // The configured interval determines the time gap between consecutive FPS measurements.
            // @param frequency - in -  int
            // @example frequency: 1000
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetCollectionFrequency(const int frequency, bool& success /* @out */) = 0;

            /** Sets the display framerate values */
            // @text setDisplayFrameRate
            // @brief Sets the display framerate values.
            // @details Updates the display framerate setting using the specified value. The new framerate is applied
            // to subsequent display operations if the request is processed successfully.
            // @param framerate - in - string
            // @example framerate: "60"
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetDisplayFrameRate(const string& framerate, bool& success /* @out */) = 0;

            /** Sets the auto framerate mode */
            // @text setFrmMode
            // @brief Set the Frm mode.
            // @details Updates the auto framerate mode to the specified value. The operation applies the new mode 
            // setting and indicates whether the update was completed successfully.
            // @param frmmode - in - int
            // @example frmmode: 1
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult SetFrmMode(const int frmmode, bool& success /* @out */) = 0;

            /** Starts the FPS data collection */
            // @text startFpsCollection
            // @brief Starts the FPS data collection. Starts the FPS data collection
            // @details Starts gathering FPS metrics for monitoring and analysis. 
            // Once enabled, FPS samples are collected until the collection process is explicitly stopped.
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult StartFpsCollection(bool& success /* @out */) = 0;

            /** Stops the FPS data collection */
            // @text stopFpsCollection
            // @brief Stops the FPS data collection
            // @details Terminates the ongoing FPS data collection process and prevents 
            // any additional FPS metrics from being captured until data collection is started again.
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult StopFpsCollection(bool& success /* @out */) = 0;

            /** Update the FPS value */
            // @text updateFps
            // @brief Update the FPS value
            // @details Allows a client to specify a new FPS value to be used by the service.
            // On successful completion, the updated setting becomes active and the success parameter is set accordingly.            
            // @param newFpsValue - in - int
            // @example newFpsValue: 60
            // @param success - out - boolean
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            // @retval Core::ERROR_GENERAL: Indicates failure
            virtual Core::hresult UpdateFps(const int newFpsValue, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
