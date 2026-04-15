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

#ifndef __IGStreamerPlayer_H
#define __IGStreamerPlayer_H

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IGStreamerPlayer : virtual public Core::IUnknown {
            enum { ID = ID_GSTREAMER_PLAYER };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_GSTREAMER_PLAYER_NOTIFICATION };

                // @text onPlayerInitialized
                // @brief Fired when the GStreamer pipeline has been created and playback has started.
                virtual void OnPlayerInitialized() {}

                // @text onPlayerStopped
                // @brief Fired when the player has been stopped and the pipeline is cleaned up.
                virtual void OnPlayerStopped() {}
            };

            virtual Core::hresult Register(IGStreamerPlayer::INotification* sink) = 0;
            virtual Core::hresult Unregister(IGStreamerPlayer::INotification* sink) = 0;

            // @text play
            // @brief Load and play media from the given URI.
            //        The plugin builds a manual GStreamer pipeline:
            //        uridecodebin -> (video) queue -> westerossink
            //                     -> (audio) queue -> autoaudiosink
            // @param uri: Media URI to play (e.g. "https://..." or "file:///...")
            // @retval Core::ERROR_NONE:         Playback started successfully.
            // @retval Core::ERROR_GENERAL:      A GStreamer element could not be created.
            virtual Core::hresult Play(const string& uri /* @text uri */) = 0;

            // @text pause
            // @brief Pause the current playback.
            // @retval Core::ERROR_NONE:          Paused successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            virtual Core::hresult Pause() = 0;

            // @text setResolution
            // @brief Set the video window position and size on screen.
            //        Internally calls g_object_set on the westerossink element.
            // @param x:      Horizontal position in pixels.
            // @param y:      Vertical position in pixels.
            // @param width:  Window width in pixels.
            // @param height: Window height in pixels.
            // @retval Core::ERROR_NONE:          Resolution updated successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline / video sink is available.
            virtual Core::hresult SetResolution(
                const uint32_t x      /* @text x */,
                const uint32_t y      /* @text y */,
                const uint32_t width  /* @text width */,
                const uint32_t height /* @text height */) = 0;

            // @text stop
            // @brief Stop playback and clean up the pipeline.
            // @retval Core::ERROR_NONE:          Stopped successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            virtual Core::hresult Stop() = 0;

            // @text seekForward
            // @brief Seek forward by 5 seconds in the current playback.
            // @retval Core::ERROR_NONE:          Seek operation completed successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            // @retval Core::ERROR_GENERAL:       Seek operation failed.
            virtual Core::hresult SeekForward() = 0;

            // @text seekBackward
            // @brief Seek backward by 5 seconds in the current playback.
            // @retval Core::ERROR_NONE:          Seek operation completed successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            // @retval Core::ERROR_GENERAL:       Seek operation failed.
            virtual Core::hresult SeekBackward() = 0;
        };

    } // namespace Exchange
} // namespace WPEFramework

#endif // __IGStreamerPlayer_H
