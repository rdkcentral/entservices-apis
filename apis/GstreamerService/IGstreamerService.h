
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

#ifndef __IGSTREAMERSERVICE_H
#define __IGSTREAMERSERVICE_H

#include "Module.h"

namespace WPEFramework {
namespace Exchange {
        
    // @json 1.0.0 @text:keep
    struct EXTERNAL IGstreamerService : virtual public Core::IUnknown {
        enum { ID = ID_GSTREAMER_SERVICE };

        // @brief Starts the GStreamer pipeline
        // @text startPipeline
        // @param pipelineConfig: Configuration for the pipeline
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_GENERAL: Failed to start pipeline
        virtual Core::hresult StartPipeline(const string& pipelineConfig) = 0;

        // @brief Stops the GStreamer pipeline
        // @text stopPipeline
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_GENERAL: Failed to stop pipeline
        virtual Core::hresult StopPipeline() = 0;

        // @brief Gets the current pipeline status
        // @text getPipelineStatus
        // @param status: Output parameter with current status
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_GENERAL: Failed to get status
        virtual Core::hresult GetPipelineStatus(string& status /* @out */) const = 0;

        // @brief Toggle between play and pause states
        // @text playPause
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_ILLEGAL_STATE: No pipeline running
        // @retval Core::ERROR_GENERAL: Failed to change state
        virtual Core::hresult PlayPause() = 0;

        // @brief Seek forward or backward in the media
        // @text seek
        // @param offset: Seconds to seek (positive=forward, negative=backward)
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_ILLEGAL_STATE: No pipeline running
        // @retval Core::ERROR_GENERAL: Seek failed
        virtual Core::hresult Seek(const int64_t offset) = 0;

        // @brief Get current playback position and duration
        // @text getPosition
        // @param position: Current position in seconds (output)
        // @param duration: Total duration in seconds (output)
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_ILLEGAL_STATE: No pipeline running
        // @retval Core::ERROR_GENERAL: Query failed
        virtual Core::hresult GetPosition(int64_t& position /* @out */, int64_t& duration /* @out */) const = 0;

        // @brief Control video window visibility
        // @text setWindowVisible
        // @param visible: true to show window, false to hide
        // @retval Core::ERROR_NONE: Success
        // @retval Core::ERROR_ILLEGAL_STATE: No pipeline running
        virtual Core::hresult SetWindowVisible(const bool visible) = 0;


        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_GSTREAMER_SERVICE_NOTIFICATION };

            virtual ~INotification() = default;

            // @brief Triggered when pipeline state changes
            // @text onPipelineStateChanged
            // @param state: New pipeline state
            virtual void OnPipelineStateChanged(const string& state) {}

            // @brief Triggered when an error occurs
            // @text onError
            // @param errorMessage: Error description
            virtual void OnError(const string& errorMessage) {}
        };

        virtual ~IGstreamerService() = default;

        // Register/Unregister for notifications
        virtual Core::hresult Register(INotification* notification) = 0;
        virtual Core::hresult Unregister(INotification* notification) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

#endif // __IGSTREAMERSERVICE_H
