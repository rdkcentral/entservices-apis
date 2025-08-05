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
        // @json @text:keep
        struct EXTERNAL IMiracastPlayer : virtual public Core::IUnknown
        {
            enum { ID = ID_MIRACAST_PLAYER };

            enum State : uint8_t
            {
                STATE_IDLE = 0  /* @text IDLE */,
                STATE_INITIATED = 1  /* @text INITIATED */,
                STATE_INPROGRESS = 2  /* @text INPROGRESS */,
                STATE_PLAYING = 3  /* @text PLAYING */,
                STATE_STOPPED = 4  /* @text STOPPED */,
                STATE_PAUSED = 5  /* @text PAUSED */
            };

            enum ReasonCode : uint8_t
            {
                REASON_CODE_SUCCESS	= 200  /* @text SUCCESS */,
                REASON_CODE_APP_REQ_TO_STOP = 201  /* @text APP_REQ_TO_STOP */,
                REASON_CODE_SRC_DEV_REQ_TO_STOP = 202  /* @text SRC_DEV_REQ_TO_STOP */,
                REASON_CODE_RTSP_ERROR = 203  /* @text RTSP_FAILURE */,
                REASON_CODE_RTSP_TIMEOUT = 204  /* @text RTSP_TIMEOUT */,
                REASON_CODE_RTSP_METHOD_NOT_SUPPORTED = 205  /* @text RTSP_NOT_SUPPORTED */,
                REASON_CODE_GST_ERROR = 206  /* @text GST_FAILURE */,
                REASON_CODE_INT_FAILURE = 207  /* @text INTERNAL_FAILURE */,
                REASON_CODE_NEW_SRC_DEV_CONNECT_REQ = 208  /* @text NEW_SRC_DEV_CONNECT_REQ */,
            };

            struct EXTERNAL DeviceParameters
            {
                string sourceDeviceIP  /* @text source_dev_ip */ /* @brief IP Address of Source Device */;
                string sourceDeviceMac /* @text source_dev_mac */ /* @brief MAC Address of Source Device */;
                string sourceDeviceName /* @text source_dev_name */ /* @brief Name of Source Device */;
                string sinkDeviceIP  /* @text sink_dev_ip */ /* @brief IP Address of Sink Device */;
            };

            struct EXTERNAL VideoRectangle
            {
                int startX /* @text X */ /* @brief X coordinate of the rectangle */;
                int startY  /* @text Y */ /* @brief Y coordinate of the rectangle */;
                int width  /* @text W */ /* @brief Width of the rectangle */;
                int height  /* @text H */ /* @brief Height of the rectangle */;
            };

            struct EXTERNAL Result
            {
                string message	/* @text message */ /* @brief reason for success or failure */;
                bool success;
            };

            struct EXTERNAL EnvArguments
            {
                string argName /* @text argName */ /* @brief environment argument name */;
                string argValue /* @text argValue */ /* @brief environment argument value */;
            };
            using IEnvArgumentsIterator = RPC::IIteratorType<EnvArguments, ID_MIRACAST_PLAYER_ENV_ARGUMENTS_ITERATOR>;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_MIRACAST_PLAYER_NOTIFICATION };

                // @brief Notifies when a Miracast source device wants to connect
                // @text onStateChange
                // @param clientName: Name of the client device
                // @param clientMac: MacAddress of the client device
                // @param playerState: Current state of the player (e.g., INITIATED | INPROGRESS | PLAYING | STOPPED/IDLE(Default State).)
                // @param reasonCode: Reason code for the player state update
                // @param reason: reason code Decription
                virtual void OnStateChange(const string &clientName /* @text name */, const string &clientMac /* @text mac */, const State playerState /* @text state */, const string &reasonCode /* @text reason_code */, const ReasonCode reasonDescription /* @text reason */) {};
            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IMiracastPlayer::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IMiracastPlayer::INotification *notification) = 0;

            // @brief To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback
            // @text playRequest
            // @param deviceParam: Contains Source and Sink Device related properties
            // @param videoRect: Video rectangle to be used for Miracast playback (x, y, width, height)
            // @param success: Is the operation successful or not
            virtual Core::hresult PlayRequest(const DeviceParameters &deviceParam /* @text device_parameters */, const VideoRectangle videoRect /* @text video_rectangle */, Result &result /* @out */) = 0;

            // @brief To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state
            // @text stopRequest
            // @param clientMac: MacAddress of the client device
            // @param clientName: Name of the client device
            // @param reasonCode: Reason code for the player stop request
            // @param reason: Reason for the player stop request
            // @param success: Is the operation successful or not
            virtual Core::hresult StopRequest(const string &clientMac /* @text mac */, const string &clientName /* @text name */, const int reasonCode /* @text reason_code */, Result &result /* @out */) = 0;

            // @brief Set the Video Rectangle.
            // @text setVideoRectangle
            // @param startX: X coordinate of the rectangle
            // @param startY: Y coordinate of the rectangle
            // @param width: Width of the rectangle
            // @param height: Height of the rectangle
            // @param success: Is the operation successful or not
            virtual Core::hresult SetVideoRectangle(const int startX /* @text X */, const int startY /* @text Y */, const int width /* @text W */, const int height /* @text H */, Result &result /* @out */) = 0;

            // @brief To configure the westeros environment arguments for the Miracast Player. This will be deprecated and SetEnvArguments will be used instead.
            // @text setWesterosEnvironment
            // @param westerosArgs: Westeros environment arguments to be set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetWesterosEnvironment( IEnvArgumentsIterator * const westerosArgs /* @text westerosArgs */, Result &result /* @out */) = 0;

            // @brief To reset the westeros environment arguments for the Miracast Player. This will be deprecated and UnsetEnvArguments will be used instead.
            // @text unsetWesterosEnvironment
            // @param success: Is the operation successful or not
            virtual Core::hresult UnsetWesterosEnvironment(Result &result /* @out */) = 0;

            // @brief To configure the environment arguments for the Miracast Player
            // @text setEnvArguments
            // @param envArgs: environment arguments to be set
            // @param success: Is the operation successful or not
            virtual Core::hresult SetEnvArguments( IEnvArgumentsIterator * const envArgs /* @text envArgs */, Result &result /* @out */) = 0;

            // @brief To reset the environment arguments for the Miracast Player
            // @text unsetEnvArguments
            // @param success: Is the operation successful or not
            virtual Core::hresult UnsetEnvArguments(Result &result /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework