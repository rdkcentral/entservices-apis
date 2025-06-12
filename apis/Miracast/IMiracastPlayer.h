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

			enum PlayerReasonCode : uint32_t
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

			enum PlayerStopReasonCode : uint32_t
			{
				MIRACAST_PLAYER_APP_REQ_TO_STOP_ON_EXIT = 301  /* @text APP_REQ_TO_STOP_ON_EXIT */,
				MIRACAST_PLAYER_APP_REQ_TO_STOP_ON_NEW_CONNECTION = 302  /* @text APP_REQ_TO_STOP_ON_NEW_CONNECTION */
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
				int32_t startX /* @text X */ /* @brief X coordinate of the rectangle */;
				int32_t startY  /* @text Y */ /* @brief Y coordinate of the rectangle */;
				int32_t width  /* @text W */ /* @brief Width of the rectangle */;
				int32_t height  /* @text H */ /* @brief Height of the rectangle */;
			};

			struct EXTERNAL SeparateLogger
			{
				string logfileName  /* @text logfilename */ /* @brief Name of the logFile */;
				string logStatus /* @text status */ /* @brief Whether ENABLE or DISABLE the separate logging */;
			};

			struct EXTERNAL Result
			{
				string message	/* @text message */ /* @brief reason for success or failure */;
				bool success;
			};

			struct EXTERNAL WesterosEnvArguments
			{
				string argName /* @text argName */ /* @brief Westeros argument name */;
				string argValue /* @text argValue */ /* @brief Westeros argument value */;
			};
			using IWesterosEnvArgumentsIterator = RPC::IIteratorType<WesterosEnvArguments, ID_MIRACAST_PLAYER_WESTEROS_ENV_ARGS_ITERATOR>;

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
				virtual void OnStateChange(const string &clientName /* @text name */, const string &clientMac /* @text mac */, const string &playerState /* @text state */, const PlayerReasonCode &reasonCode /* @text reason_code */, const string &reason /* @text reason */) {};
			};

			// @json:omit
			virtual Core::hresult Register(Exchange::IMiracastPlayer::INotification *notification) = 0;
			// @json:omit
			virtual Core::hresult Unregister(Exchange::IMiracastPlayer::INotification *notification) = 0;
			// @json:omit
			virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;
			// @json:omit
			virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

			// @brief To set the Miracast Player State to Play after the Miracast session like RTSP communication and GStreamer Playback
			// @text playRequest
			// @param deviceParam: Contains Source and Sink Device related properties
			// @param videoRect: Video rectangle to be used for Miracast playback (x, y, width, height)
			// @param success: Is the operation successful or not
			virtual Core::hresult PlayRequest(const DeviceParameters &deviceParam /* @in @text device_parameters */, const VideoRectangle &videoRect /* @in @text video_rectangle */, Result &returnPayload /* @out */) = 0;

			// @brief To stop the Miracast Player to tear down the RTSP communication, stop/close the GStreamer pipeline, clean up, and reset the player state
			// @text stopRequest
			// @param clientMac: MacAddress of the client device
			// @param clientName: Name of the client device
			// @param reasonCode: Reason code for the player stop request
			// @param reason: Reason for the player stop request
			// @param success: Is the operation successful or not
			virtual Core::hresult StopRequest(const string &clientMac /* @in @text mac */, const string &clientName /* @in @text name */, const PlayerStopReasonCode &reasonCode /* @in @text reason_code */, Result &returnPayload /* @out */) = 0;

			// @brief Set the Video Rectangle.
			// @text setVideoRectangle
			// @param startX: X coordinate of the rectangle
			// @param startY: Y coordinate of the rectangle
			// @param width: Width of the rectangle
			// @param height: Height of the rectangle
			// @param success: Is the operation successful or not
			virtual Core::hresult SetVideoRectangle(const int32_t &startX /* @in @text X */, const int32_t &startY /* @in @text Y */, const int32_t &width /* @in @text W */, const int32_t &height /* @in @text H */, Result &returnPayload /* @out */) = 0;

			// @brief To Enable/Disable/Reduce the Logging level for Miracast
			// @text setLogging
			// @param clienMac: MacAddress of the client device
			// @param clienName: Name of the client device
			// @param success: Is the operation successful or not
			virtual Core::hresult SetLogging(const string &logLevel /* @in @text level */, const SeparateLogger &separateLogger /* @in @text separate_logger */, Result &returnPayload /* @out */) = 0;

			// @brief To configure the westeros environment arguments for the Miracast Player
			// @text setWesterosEnvironment
			// @param westerosArgs: Westeros environment arguments to be set
			// @param success: Is the operation successful or not
			virtual Core::hresult SetWesterosEnvironment( IWesterosEnvArgumentsIterator * const westerosArgs /* @in @text westerosArgs */, Result &returnPayload /* @out */) = 0;

			// @brief To reset the westeros environment arguments for the Miracast Player
			// @text unsetWesterosEnvironment
			// @param success: Is the operation successful or not
			virtual Core::hresult UnsetWesterosEnvironment(Result &returnPayload /* @out */) = 0;
		};
	} // namespace Exchange
} // namespace WPEFramework