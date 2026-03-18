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

#ifndef __IGSTREAMERPLAYER_H
#define __IGSTREAMERPLAYER_H

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {
        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IGStreamerPlayer : virtual public Core::IUnknown {
            enum { ID = ID_GSTREAMER_PLAYER };

            // @brief Pipeline states for GStreamer player
            enum PipelineState : uint8_t {
                STOPPED = 0 /* @text stopped */,
                PLAYING = 1 /* @text playing */,
                PAUSED = 2 /* @text paused */,
                ERROR = 3 /* @text error */
            };

            // @brief Error codes for GStreamer player operations
            enum ErrorCode : uint16_t {
                NONE = 200 /* @text none */,
                INVALID_URL = 400 /* @text invalidUrl */,
                PLAYBACK_ERROR = 500 /* @text playbackError */,
                NOT_READY = 503 /* @text notReady */
            };

            // @brief Success response structure
            struct EXTERNAL PlayerSuccess {
                bool success /* @text success */ /* @brief true if the request was successful, false otherwise */;
            };

            //@event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_GSTREAMER_PLAYER_NOTIFICATION };

                // @text onPipelineStateChanged
                // @brief Triggered when the GStreamer pipeline state changes
                // @param state: New pipeline state
                // @param error: Error code if state is ERROR, otherwise NONE
                virtual void OnPipelineStateChanged(const PipelineState& state /* @text state */, const ErrorCode& error /* @text error */) = 0;
            };

            virtual Core::hresult Register(IGStreamerPlayer::INotification* sink) = 0;
            virtual Core::hresult Unregister(IGStreamerPlayer::INotification* sink) = 0;

            /****************************************SetURL()*****************************/
            // @text setURL
            // @brief Sets the media URL to be played
            // @param url: Media URL (HTTP, HTTPS, or file:// URL)
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: URL set successfully
            // @retval ErrorCode::INVALID_URL: URL format is invalid
            virtual Core::hresult SetURL(const string& url /* @text url */, PlayerSuccess& success /* @out */) = 0;
            /****************************************SetURL()*****************************/

            /****************************************Play()*****************************/
            // @text play
            // @brief Starts or resumes playback
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Playback started successfully
            // @retval ErrorCode::NOT_READY: No URL set or pipeline not ready
            // @retval ErrorCode::PLAYBACK_ERROR: Failed to start playback
            virtual Core::hresult Play(PlayerSuccess& success /* @out */) = 0;
            /****************************************Play()*****************************/

            /****************************************Pause()*****************************/
            // @text pause
            // @brief Pauses playback
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Playback paused successfully
            // @retval ErrorCode::NOT_READY: Player not in playing state
            virtual Core::hresult Pause(PlayerSuccess& success /* @out */) = 0;
            /****************************************Pause()*****************************/

            /****************************************Stop()*****************************/
            // @text stop
            // @brief Stops playback and resets the pipeline
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: Playback stopped successfully
            virtual Core::hresult Stop(PlayerSuccess& success /* @out */) = 0;
            /****************************************Stop()*****************************/

            /****************************************GetState()*****************************/
            // @text getState
            // @brief Gets the current pipeline state
            // @param state: Current pipeline state
            // @param success: Whether the request succeeded
            // @retval ErrorCode::NONE: State retrieved successfully
            virtual Core::hresult GetState(PipelineState& state /* @out @text state */, bool& success /* @out */) = 0;
            /****************************************GetState()*****************************/
        };
    }
}

#endif // __IGSTREAMERPLAYER_H
