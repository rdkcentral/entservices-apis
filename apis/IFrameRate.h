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
                // @details This notification is raised when FPS data is available after FPS data collection has been started.
                // @param[in] average Average measured frame rate.
                // @param[in] min Minimum measured frame rate.
                // @param[in] max Maximum measured frame rate.
                // @example average: 60, min: 59, max: 61
                // @param success: Indicates whether the operation was successful
                // @example success: true
                virtual void OnFpsEvent(const int average, const int min, const int max) {};

                // @text onDisplayFrameRateChanging
                // @brief Triggered when the framerate changes started
                // @details This notification is raised when a display frame rate change has started and before the new frame rate is applied.
                // @param[in] displayFrameRate Display frame rate being applied.
                // @example displayFrameRate: "23.976"
                // @param success: Indicates whether the operation was successful
                // @example success: true
                virtual void OnDisplayFrameRateChanging(const string& displayFrameRate) {};

                // @text onDisplayFrameRateChanged
                // @brief Triggered when the framerate changed.
                // @details This notification is raised after the requested display frame rate has been applied.
                // @param[in] displayFrameRate Current display frame rate.
                // @example displayFrameRate: "59.94"
                // @param success: Indicates whether the operation was successful
                // @example success: true
                virtual void OnDisplayFrameRateChanged(const string& displayFrameRate) {};
            };

            virtual Core::hresult Register(IFrameRate::INotification* notification) = 0;
            virtual Core::hresult Unregister(IFrameRate::INotification* notification) = 0;

            /** Gets the Display Frame Rate*/
            // @text getDisplayFrameRate
            // @brief Gets the current display frame rate values.
            // @details This method returns the display frame rate currently configured for the device.
            // @param[out] framerate Current display frame rate.
            // @param[out] success Indicates whether the display frame rate was retrieved.
            // @example framerate: "59.94"
            // @example success: true
            // @retval Core::ERROR_NONE The display frame rate was retrieved successfully.
            // @retval Core::ERROR_GENERAL The display frame rate could not be retrieved.
            virtual Core::hresult GetDisplayFrameRate(string& framerate /* @out */, bool& success /* @out */) = 0;

            /** Gets framerate mode */
            // @text getFrmMode
            // @brief Gets the current auto framerate mode.
            // @details This method returns the current automatic frame-rate mode configured for display frame-rate handling.
            // @param[out] framerateMode Current automatic frame-rate mode.
            // @param[out] success Indicates whether the frame-rate mode was retrieved.
            // @example framerateMode: 1
            // @example success: true
            // @retval Core::ERROR_NONE The automatic frame-rate mode was retrieved successfully.
            // @retval Core::ERROR_GENERAL The automatic frame-rate mode could not be retrieved.
            virtual Core::hresult GetFrmMode(int &framerateMode /* @out @text:auto-frm-mode */, bool& success /* @out */) = 0;

            /** Sets the FPS data collection interval */
            // @text setCollectionFrequency
            // @brief Sets the FPS data collection interval.
            // @details This method configures the interval used to collect and report frames-per-second measurements.
            // @param[in] frequency FPS data collection interval.
            // @param[out] success Indicates whether the collection interval was updated.
            // @example frequency: 1000
            // @example success: true
            // @retval Core::ERROR_NONE The FPS collection interval was updated successfully.
            // @retval Core::ERROR_GENERAL The FPS collection interval could not be updated.
            virtual Core::hresult SetCollectionFrequency(const int frequency, bool& success /* @out */) = 0;

            /** Sets the display framerate values */
            // @text setDisplayFrameRate
            // @brief Sets the display framerate values.
            // @details This method requests the device to use the specified display frame rate. Frame-rate transition notifications may be generated.
            // @param[in] framerate Display frame rate to configure.
            // @param[out] success Indicates whether the display frame rate was updated.
            // @example framerate: "23.976"
            // @example success: true
            // @retval Core::ERROR_NONE The display frame rate was updated successfully.
            // @retval Core::ERROR_GENERAL The display frame rate could not be updated.
            virtual Core::hresult SetDisplayFrameRate(const string& framerate, bool& success /* @out */) = 0;

            /** Sets the auto framerate mode */
            // @text setFrmMode
            // @brief Set the Frm mode.
            // @details This method enables or disables the automatic frame-rate mode according to the supplied mode value.
            // @param[in] frmmode Automatic frame-rate mode to configure.
            // @param[out] success Indicates whether the frame-rate mode was updated.
            // @example frmmode: 1
            // @example success: true
            // @retval Core::ERROR_NONE The automatic frame-rate mode was updated successfully.
            // @retval Core::ERROR_GENERAL The automatic frame-rate mode could not be updated.
            virtual Core::hresult SetFrmMode(const int frmmode, bool& success /* @out */) = 0;

            /** Starts the FPS data collection */
            // @text startFpsCollection
            // @brief Starts the FPS data collection. Starts the FPS data collection
            // @details After collection starts, FPS measurements may be reported through the OnFpsEvent notification.
            // @param[out] success Indicates whether FPS data collection was started.            
            // @example success: true
            // @retval Core::ERROR_NONE FPS data collection was started successfully.
            // @retval Core::ERROR_GENERAL FPS data collection could not be started.
            virtual Core::hresult StartFpsCollection(bool& success /* @out */) = 0;

            /** Stops the FPS data collection */
            // @text stopFpsCollection
            // @brief Stops the FPS data collection
            // @details After collection stops, FPS measurement notifications are no longer generated until collection is started again.
            // @param[out] success Indicates whether FPS data collection was stopped.
            // @example success: true
            // @retval Core::ERROR_NONE FPS data collection was stopped successfully.
            // @retval Core::ERROR_GENERAL FPS data collection could not be stopped.
            virtual Core::hresult StopFpsCollection(bool& success /* @out */) = 0;

            /** Update the FPS value */
            // @text updateFps
            // @brief Update the FPS value
            // @details This method supplies a new FPS value to the frame-rate service for use by its frame-rate monitoring and reporting functionality.
            // @param[in] newFpsValue New FPS value.
            // @param[out] success Indicates whether the FPS value was updated.
            // @param newFpsValue: New FPS value to be set
            // @example newFpsValue: 60
            // @example success: true
            // @retval Core::ERROR_NONE The FPS value was updated successfully.
            // @retval Core::ERROR_GENERAL The FPS value could not be updated.
            virtual Core::hresult UpdateFps(const int newFpsValue, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
