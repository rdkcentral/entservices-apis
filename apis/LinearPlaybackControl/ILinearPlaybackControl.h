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
        struct EXTERNAL ILinearPlaybackControl : virtual public Core::IUnknown
        {
            enum { ID = ID_LINEAR_PLAYBACK_CONTROL };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_LINEAR_PLAYBACK_CONTROL_NOTIFICATION };

                // @text speedchanged
                // @brief Triggered when the trick play speed has changed
                // @param speed: New trick play speed (negative=rewind, positive=fast forward)
                // @param muxId: Stream muxId
                virtual void OnSpeedChanged(const int16_t speed, const uint8_t muxId) { }
            };

            virtual Core::hresult Register(ILinearPlaybackControl::INotification* notification) = 0;
            virtual Core::hresult Unregister(ILinearPlaybackControl::INotification* notification) = 0;

            /** Sets the channel URI for a demuxer */
            // @text setChannel
            // @brief Sets channel URI for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param channel: Channel address
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_BAD_REQUEST: Bad request
            virtual Core::hresult SetChannel(const string& demuxerId, const string& channel, uint32_t& result /* @out */) = 0;

            /** Gets the channel URI for a demuxer */
            // @text getChannel
            // @brief Gets channel URI for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param channel: Channel address
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_READ_ERROR: Error reading channel information
            virtual Core::hresult GetChannel(const string& demuxerId, string& channel /* @out */, uint32_t& result /* @out */) = 0;

            /** Sets the seek position for current stream */
            // @text setSeek
            // @brief Sets seek position for current stream for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param seekPosInSeconds: TSB seek position offset from live in seconds
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_BAD_REQUEST: Bad request
            // @retval ERROR_WRITE_ERROR: Error writing seek position
            virtual Core::hresult SetSeek(const string& demuxerId, const uint64_t seekPosInSeconds, uint32_t& result /* @out */) = 0;

            /** Gets the seek position for current stream */
            // @text getSeek
            // @brief Gets seek position for current stream for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param seekPosInSeconds: TSB seek position offset from live in seconds
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_READ_ERROR: Error reading seek position
            virtual Core::hresult GetSeek(const string& demuxerId, uint64_t& seekPosInSeconds /* @out */, uint32_t& result /* @out */) = 0;

            /** Sets the trick play speed for current stream */
            // @text setTrickPlay
            // @brief Sets trick play speed and direction for current stream for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param speed: Trick play speed (negative=rewind, positive=fast forward)
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_BAD_REQUEST: Bad request
            // @retval ERROR_WRITE_ERROR: Error setting trick play speed
            virtual Core::hresult SetTrickPlay(const string& demuxerId, const int16_t speed, uint32_t& result /* @out */) = 0;

            /** Gets the trick play speed for current stream */
            // @text getTrickPlay
            // @brief Gets trick play speed and direction for current stream for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param speed: Trick play speed (negative=rewind, positive=fast forward)
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_READ_ERROR: Error reading trick play speed
            virtual Core::hresult GetTrickPlay(const string& demuxerId, int16_t& speed /* @out */, uint32_t& result /* @out */) = 0;

            /** Gets the TSB status information */
            // @text getStatus
            // @brief Gets TSB status (seek position, TSB size and health info) for a certain demuxer ID
            // @param demuxerId: Demuxer ID (default is "0")
            // @param maxSizeInBytes: Maximum TSB size in bytes
            // @param currentSizeInBytes: Current TSB size in bytes
            // @param currentSizeInSeconds: Current TSB size in seconds
            // @param seekPosInBytes: Current TSB seek position offset from live in bytes
            // @param seekPosInSeconds: Current TSB seek position offset from live in seconds
            // @param trickPlaySpeed: Current trick play speed and direction
            // @param streamSourceLost: Boolean indicating if the buffer source is lost
            // @param streamSourceLossCount: Number of times streaming was lost
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_READ_ERROR: Error reading TSB status
            virtual Core::hresult GetStatus(const string& demuxerId, 
                                           uint64_t& maxSizeInBytes /* @out */,
                                           uint64_t& currentSizeInBytes /* @out */,
                                           uint64_t& currentSizeInSeconds /* @out */,
                                           uint64_t& seekPosInBytes /* @out */,
                                           uint64_t& seekPosInSeconds /* @out */,
                                           int16_t& trickPlaySpeed /* @out */,
                                           bool& streamSourceLost /* @out */,
                                           uint64_t& streamSourceLossCount /* @out */,
                                           uint32_t& result /* @out */) = 0;

            /** Sets the tracing flag */
            // @text setTracing
            // @brief Sets tracing enabled/disabled
            // @param tracing: Tracing enable (true) / disable (false)
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_GENERAL: General failure
            virtual Core::hresult SetTracing(const bool tracing, uint32_t& result /* @out */) = 0;

            /** Gets the tracing flag */
            // @text getTracing
            // @brief Gets tracing enabled/disabled
            // @param tracing: Tracing enable (true) / disable (false)
            // @param result: Result code
            // @retval ERROR_NONE: Success
            // @retval ERROR_GENERAL: General failure
            virtual Core::hresult GetTracing(bool& tracing /* @out */, uint32_t& result /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
