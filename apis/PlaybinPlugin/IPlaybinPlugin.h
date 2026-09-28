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

#ifndef __IPlaybinPlugin_H
#define __IPlaybinPlugin_H

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {

        /* @json 1.0.0 @text:keep */
        struct EXTERNAL IPlaybinPlugin : virtual public Core::IUnknown {
            enum { ID = ID_PLAYBIN_PLUGIN };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_PLAYBIN_PLUGIN_NOTIFICATION };

                // @text onPlayerInitialized
                // @brief Fired when the playbin pipeline reaches PLAYING for the first time after creation.
                virtual void OnPlayerInitialized() {}

                // @text onPlayerStopped
                // @brief Fired when the player has been stopped and the pipeline is released.
                virtual void OnPlayerStopped() {}

                // @text onPlayerError
                // @brief Fired when the playbin pipeline reports a GStreamer bus error (e.g. unsupported/unreachable media).
                // @param message: Human readable description of the GStreamer error.
                virtual void OnPlayerError(const string& message /* @text message */) {}
            };

            virtual Core::hresult Register(IPlaybinPlugin::INotification* sink) = 0;
            virtual Core::hresult Unregister(IPlaybinPlugin::INotification* sink) = 0;

            // @text configure
            // @brief Configure the media to be played, without starting playback.
            //        Accepts a local file path, a file:// URI, an http(s):// URL, or any
            //        other URI scheme the underlying playbin/GStreamer install supports.
            //        A bare local path (no "://") is normalized to a file:// URI internally.
            //        If a pipeline is already PLAYING or PAUSED, it is stopped and released
            //        before the new media is stored.
            // @param media: Local file path or URI of the media to play.
            // @retval Core::ERROR_NONE:            Media configured successfully.
            // @retval Core::ERROR_GENERAL:         The media location is empty or could not be resolved to a valid URI.
            virtual Core::hresult Configure(const string& media /* @text media */) = 0;

            // @text play
            // @brief Start or resume playback using a single GStreamer playbin element.
            //        Creates the playbin pipeline on first call after Configure, sets its
            //        "uri" property to the configured media, and transitions it to PLAYING.
            //        If the pipeline already exists and is PAUSED, it is resumed to PLAYING
            //        without being recreated. If already PLAYING, this is a no-op success.
            // @retval Core::ERROR_NONE:          Playback started or resumed successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No media has been configured via Configure().
            // @retval Core::ERROR_GENERAL:       The playbin pipeline could not be created or set to PLAYING.
            virtual Core::hresult Play() = 0;

            // @text pause
            // @brief Pause the current playback. The pipeline is kept alive so playback
            //        can be resumed from the same position with Play().
            // @retval Core::ERROR_NONE:          Paused successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            virtual Core::hresult Pause() = 0;

            // @text stop
            // @brief Stop playback, transition the pipeline to NULL, and release/unref it.
            //        The last configured media location is preserved, so a subsequent
            //        Play() recreates a pipeline for it without requiring Configure() again.
            // @retval Core::ERROR_NONE:          Stopped successfully.
            // @retval Core::ERROR_ILLEGAL_STATE: No pipeline is running.
            virtual Core::hresult Stop() = 0;
        };

    } // namespace Exchange
} // namespace WPEFramework

#endif // __IPlaybinPlugin_H
