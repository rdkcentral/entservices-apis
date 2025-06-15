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
#include "IMiracastPlayer.h"
// @stubgen:include "IMiracastPlayer.h"
// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework
{
	namespace Exchange
	{
		// @json @text:keep
		struct EXTERNAL IMiracastService : virtual public Core::IUnknown
		{
			enum { ID = ID_MIRACAST_SERVICE };

			enum ErrorCode : uint8_t
			{
				ERROR_CODE_SUCCESS = 100  /* @text SUCCESS */,
				ERROR_CODE_P2P_CONNECT_FAILURE = 101  /* @text P2P_CONNECT_FAILURE */,
				ERROR_CODE_P2P_GROUP_NEGOTIATION_FAILURE = 102  /* @text P2P_GROUP_NEGOTIATION_FAILURE */,
				ERROR_CODE_P2P_GROUP_FORMATION_FAILURE = 103  /* @text P2P_GROUP_FORMATION_FAILURE */,
				ERROR_CODE_GENERIC_FAILURE = 104  /* @text GENERIC_FAILURE */
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

			struct EXTERNAL Result
			{
				string message	/* @text message */ /* @brief reason for success or failure */;
				bool success;
			};

			// @event
			struct EXTERNAL INotification : virtual public Core::IUnknown
			{
				enum { ID = ID_MIRACAST_SERVICE_NOTIFICATION };

				// @brief Triggered when the Miracast Service plugin receives a new connection request from a client
				// @text onClientConnectionRequest
				// @param clientMac: MacAddress of the client device
				// @param clientName: Name of the client device
				virtual void OnClientConnectionRequest(const string &clientMac /* @text mac */, const string &clientName /* @text name */) {};

				// @brief It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming
				// @text onClientConnectionError
				// @param clientMac: MacAddress of the client device
				// @param clientName: Name of the client device
				// @param errorCode: Error code for the connection failure
				// @param reason: Reason for the connection failure
				virtual void OnClientConnectionError(const string &clientMac /* @text mac */, const string &clientName /* @text name */, const ErrorCode &reason /* @text reason */, const string &errorCodeStr /* @text error_code */) {};

				// @brief Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player
				// @text onLaunchRequest
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

			// @brief To enable or disable the Miracast feature
			// @text setEnable
			// @param enabled: Is the MiracastService discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult SetEnabled(const bool &enabled /* @in @text enabled */, Result &returnPayload /* @out */) = 0;

			// @brief To get the enable status of the Miracast feature
			// @text getEnable
			// @param enabled: Is the MiracastService discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;

			// @brief To accept or reject new client connection requests for the Miracast feature
			// @text acceptClientConnection
			// @param requestStatus: It should be "Accept" or "Reject"
			// @param success: Is the operation successful or not
			virtual Core::hresult AcceptClientConnection(const string &requestStatus /* @in @text requestStatus */, Result &returnPayload /* @out */) = 0;

			// @brief To abort the ongoing connection after accepted connection request
			// @text stopClientConnection
			// @param clientMac: MacAddress of the client device
			// @param clientName: Name of the client device
			// @param success: Is the operation successful or not
			virtual Core::hresult StopClientConnection(const string &clientMac /* @in @text mac */, const string &clientName /* @in @text name */, Result &returnPayload /* @out */) = 0;

			// @brief Update the Miracast Player State to the Miracast Service Plugin
			// @text updatePlayerState
			// @param clientMac: MacAddress of the client device
			// @param playerState: Player state to be updated
			// @param reasonCode: Reason code for the player state update
			// @param reason: Reason for the player state update
			// @param success: Is the operation successful or not
			virtual Core::hresult UpdatePlayerState(const string &clientMac /* @in @text mac */, const IMiracastPlayer::State &playerState /* @in @text state */, const IMiracastPlayer::ErrorCode &reasonCode /* @in @text reason_code */, Result &returnPayload /* @out */) = 0;

			// @brief Enable or Disable or Reduce the Logging level for Miracast
			// @text setLogging
			// @param logLevel: The logging level to be set (e.g., "DEBUG", "INFO", "WARN", "ERROR")
			// @param separateLogger: Contains the separate logger properties
			// @param success: Is the operation successful or not
			virtual Core::hresult SetLogging(const IMiracastPlayer::LogLevel &logLevel /* @in @text level */, const SeparateLogger &separateLogger /* @in @text separate_logger */, Result &returnPayload /* @out */) = 0;

			// @brief Sets the status of the MiracastService backend discovery
			// @text setP2PBackendDiscovery
			// @param enabled: Is the MiracastService backend discovery enabled or not
			// @param success: Is the operation successful or not
			virtual Core::hresult SetP2PBackendDiscovery(const bool &enabled /* @in @text enabled */, Result &returnPayload /* @out */) = 0;
		};
	} // namespace Exchange
} // namespace WPEFramework