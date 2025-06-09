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
		struct EXTERNAL IMiracastService : virtual public Core::IUnknown
		{
			enum { ID = ID_MIRACAST_SERVICE };

			enum PlayerReasonCode : uint8_t
			{
				REASON_CODE_SUCCESS	= 200  /* @text SUCCESS */,
				REASON_CODE_APP_REQ_TO_STOP = 201  /* @text APP REQUESTED TO STOP. */,
				REASON_CODE_SRC_DEV_REQ_TO_STOP = 202  /* @text SRC DEVICE REQUESTED TO STOP. */,
				REASON_CODE_RTSP_ERROR = 203  /* @text RTSP Failure. */,
				REASON_CODE_RTSP_TIMEOUT = 204  /* @text RTSP Timeout. */,
				REASON_CODE_RTSP_METHOD_NOT_SUPPORTED = 205  /* @text RTSP Method Not Supported. */,
				REASON_CODE_GST_ERROR = 206  /* @text GStreamer Failure. */,
				REASON_CODE_INT_FAILURE = 207  /* @text Internal Failure. */,
				REASON_CODE_NEW_SRC_DEV_CONNECT_REQ = 208  /* @text APP REQ TO STOP FOR NEW CONNECTION. */,
			};

			struct EXTERNAL DeviceParameters
			{
				string sourceDeviceIP  /* @text source_dev_ip */ /* @brief IP Address of Source Device */;
				string sourceDeviceMac /* @text source_dev_mac */ /* @brief MAC Address of Source Device */;
				string sourceDeviceName /* @text source_dev_name */ /* @brief Name of Source Device */;
				string sinkDeviceIP  /* @text sink_dev_ip */ /* @brief IP Address of Sink Device */;
			};

			struct EXTERNAL SeparateLogger
			{
				string logfileName  /* @text logfilename */ /* @brief Name of the logFile */;
				string logStatus /* @text status */ /* @brief Whether ENABLE or DISABLE the separate logging */;
			};

			struct EXTERNAL Result {
				string message	/* @text message */ /* @brief reason for success or failure */;
				bool success;
			};

			// @event
			struct EXTERNAL INotification : virtual public Core::IUnknown
			{
				enum { ID = ID_MIRACAST_SERVICE_NOTIFICATION };

				// @brief Notifies when a Miracast source device wants to connect
				// @text onClientConnectionRequest
				// @param clientMac: MacAddress of the client device
				// @param clientName: Name of the client device
				virtual void OnClientConnectionRequest(const string &clientMac /* @text mac */, const string &clientName /* @text name */) {};

				// @brief Notifies when a Miracast source device wants to connect
				// @text onClientConnectionError
				// @param clientMac: MacAddress of the client device
				// @param clientName: Name of the client device
				// @param errorCode: Error code for the connection failure
				// @param reason: Reason for the connection failure
				virtual void OnClientConnectionError(const string &clientMac /* @text mac */, const string &clientName /* @text name */, const string &errorCode /* @text error_code */, const string &reason /* @text reason */) {};

				// @text onLaunchRequest
				// @brief Triggered once P2P Group Started event received and further need to trigger MiracastPlayer's playRequest method
				// @param DeviceParameters: Contains Source and Sink Device related properties
				virtual void OnLaunchRequest(const DeviceParameters deviceParameters/* @text device_parameters*/) {};
			};

			// @json:omit
			virtual Core::hresult Register(Exchange::IMiracastService::INotification *notification) = 0;
			// @json:omit
			virtual Core::hresult Unregister(Exchange::IMiracastService::INotification *notification) = 0;
			// @json:omit
			virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;
			// @json:omit
			virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

			// @brief Sets the status of the MiracastService discovery
			// @text setEnabled
			// @param enabled: Is the MiracastService discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult SetEnabled(const bool &enabled /* @in */, Result &success /* @out */) = 0;

			// @brief Gets the status of the MiracastService discovery
			// @text getEnable
			// @param enabled: Is the MiracastService discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;

			// @brief To accept or reject client connection requests for the Miracast
			// @text acceptClientConnection
			// @param requestStatus: It should be "Accept" or "Reject"
			// @param success: Is the operation successful or not
			virtual Core::hresult AcceptClientConnection(const string &requestStatus /* @in */, Result &success /* @out */) = 0;

			// @brief To abort the ongoing connection after accepted connection request
			// @text stopClientConnection
			// @param clienMac: MacAddress of the client device
			// @param clienName: Name of the client device
			// @param success: Is the operation successful or not
			virtual Core::hresult StopClientConnection(const string &clienMac /* @in @text mac */, const string &clienName /* @in @text name */, Result &success /* @out */) = 0;

			// @brief To Update the Miracast Player State to the Miracast Service Plugin
			// @text updatePlayerState
			// @param clienMac: MacAddress of the client device
			// @param playerState: Player state to be updated
			// @param reasonCode: Reason code for the player state update
			// @param reason: Reason for the player state update
			// @param success: Is the operation successful or not
			virtual Core::hresult UpdatePlayerState(const string &clienMac /* @in @text mac */, const string &playerState /* @in @text state */, const PlayerReasonCode &reasonCode /* @in @text reason_code */, const string &reason /* @in @text reason */, Result &success /* @out */) = 0;

			// @brief To Enable/Disable/Reduce the Logging level for Miracast
			// @text setLogging
			// @param clienMac: MacAddress of the client device
			// @param clienName: Name of the client device
			// @param success: Is the operation successful or not
			virtual Core::hresult SetLogging(const string &logLevel /* @in @text level */, const SeparateLogger &separateLogger /* @in @text separate_logger */, Result &success /* @out */) = 0;

			// @brief Sets the status of the MiracastService backend discovery
			// @text setP2PBackendDiscovery
			// @param enabled: Is the MiracastService backend discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult SetP2PBackendDiscovery(const bool &enabled /* @in */, Result &success /* @out */) = 0;
		};
	} // namespace Exchange
} // namespace WPEFramework