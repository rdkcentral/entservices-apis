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

namespace WPEFramework
{
    namespace Exchange
    {
        // @json @text:keep
        struct EXTERNAL IMiracastService : virtual public Core::IUnknown
        {
            enum { ID = ID_MIRACAST_SERVICE };

            enum ReasonCode : uint8_t
            {
                REASON_CODE_SUCCESS = 100  /* @text SUCCESS */,
                REASON_CODE_P2P_CONNECT_FAILURE = 101  /* @text P2P_CONNECT_FAILURE */,
                REASON_CODE_P2P_GROUP_NEGOTIATION_FAILURE = 102  /* @text P2P_GROUP_NEGOTIATION_FAILURE */,
                REASON_CODE_P2P_GROUP_FORMATION_FAILURE = 103  /* @text P2P_GROUP_FORMATION_FAILURE */,
                REASON_CODE_GENERIC_FAILURE = 104  /* @text GENERIC_FAILURE */
            };

            enum PlayerState : uint8_t
            {
                PLAYER_STATE_IDLE = 0  /* @text IDLE */,
                PLAYER_STATE_INITIATED = 1  /* @text INITIATED */,
                PLAYER_STATE_INPROGRESS = 2  /* @text INPROGRESS */,
                PLAYER_STATE_PLAYING = 3  /* @text PLAYING */,
                PLAYER_STATE_STOPPED = 4  /* @text STOPPED */
            };

            enum PlayerReasonCode : uint8_t
            {
                PLAYER_REASON_CODE_SUCCESS	= 200  /* @text SUCCESS */,
                PLAYER_REASON_CODE_APP_REQ_TO_STOP = 201  /* @text APP_REQ_TO_STOP */,
                PLAYER_REASON_CODE_SRC_DEV_REQ_TO_STOP = 202  /* @text SRC_DEV_REQ_TO_STOP */,
                PLAYER_REASON_CODE_RTSP_ERROR = 203  /* @text RTSP_FAILURE */,
                PLAYER_REASON_CODE_RTSP_TIMEOUT = 204  /* @text RTSP_TIMEOUT */,
                PLAYER_REASON_CODE_RTSP_METHOD_NOT_SUPPORTED = 205  /* @text RTSP_NOT_SUPPORTED */,
                PLAYER_REASON_CODE_GST_ERROR = 206  /* @text GST_FAILURE */,
                PLAYER_REASON_CODE_INT_FAILURE = 207  /* @text INTERNAL_FAILURE */,
                PLAYER_REASON_CODE_NEW_SRC_DEV_CONNECT_REQ = 208  /* @text NEW_SRC_DEV_CONNECT_REQ */,
            };

            struct EXTERNAL DeviceParameters
            {
                string sourceDeviceIP  /* @text source_dev_ip */ /* @brief IP Address of Source Device */;
                string sourceDeviceMac /* @text source_dev_mac */ /* @brief MAC Address of Source Device */;
                string sourceDeviceName /* @text source_dev_name */ /* @brief Name of Source Device */;
                string sinkDeviceIP  /* @text sink_dev_ip */ /* @brief IP Address of Sink Device */;
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

                // @text onClientConnectionRequest
                // @brief Triggered when the Miracast Service plugin receives a new connection request from a client
                // @details This event is generated when a Miracast source device discovers the sink device and requests a Miracast session. Applications can use this notification to accept or reject the incoming connection request.
                // @param clientMac: MacAddress of the client device
                // @example clientMac - "00:11:22:33:44:55"
                // @param clientName: Name of the client device
                // @example clientName - "AndroidPhone"
                virtual void OnClientConnectionRequest(const string &clientMac /* @text mac */, const string &clientName /* @text name */) {};

                // @brief It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming
                // @text onClientConnectionError
                // @details This event is generated when Miracast session establishment or streaming fails due to P2P connection failures, group negotiation errors, group formation failures, or other service-related issues.
                // @param clientMac: MacAddress of the client device
                // @example clientMac - "00:11:22:33:44:55"
                // @param clientName: Name of the client device
                // @example clientName - "AndroidPhone"
                // @param errorCode: Error code for the connection failure
                // @example errorCode - "200"
                // @param reason: Reason for the connection failure
                // @example reason - "P2P_CONNECTION_FAILED"
                // @param reasonDescription: Reason for the connection failure
                // @example reasonDescription: "P2P_CONNECTION_FAILED"
                virtual void OnClientConnectionError(const string &clientMac /* @text mac */, const string &clientName /* @text name */, const string &reasonCode /* @text error_code */, const ReasonCode reasonDescription /* @text reason */) {};

                // @text onLaunchRequest
                // @brief Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player
                // @details This event is generated when the Miracast Service has completed the connection setup and requires the Miracast Player to initialize the streaming session using the supplied device information.
                // @param DeviceParameters: Contains Source and Sink Device related properties
                // @example deviceParameters.sourceDeviceName - "AndroidPhone"
                virtual void OnLaunchRequest(const DeviceParameters &deviceParameters/* @text device_parameters*/) {};
            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IMiracastService::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IMiracastService::INotification *notification) = 0;

            // @text setEnable
            // @brief To enable or disable the Miracast feature
            // @details Controls Miracast device discovery and connection handling. When enabled, the device becomes discoverable to compatible Miracast source devices. When disabled, discovery and connection requests are blocked.
            // @param enabled: Is the MiracastService discovery enabled or not
            // @example enabled - true
            // @param success: Is the operation successful or not
            // @param result - out - Result of the operation.
            // @example result.success - true
            // @retval Core::ERROR_NONE - Miracast feature state updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the Miracast feature state.
            virtual Core::hresult SetEnabled(const bool enabled /* @text enabled */, Result &result /* @out */) = 0;

            // @brief To get the enable status of the Miracast feature
            // @text getEnable
            // @details Retri*ves the current Miracast discovery*state maintained by the Miracas* Service plugin.
            // @param enabled: Is the MiracastService discovery enabled or not
            // @example enabled - true
            // @param success: Is the operation successful or not
            // @example succe*s - true
            // @retval Core::ERROR*NONE - Status retrieved successful*y.
            // @retval Core::ERROR_GENERAL * Failed to retrieve the status.
            virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;

            // @text acceptClientConnection
            // @brief To accept or reject new client connection requests for the Miracast feature
            // @details Processes a pending Miracast connection request from a source device. The request can either be accepted to continue session setup or rejected to terminate the request.
            // @param requestStatus: It should be "Accept" or "Reject"
            // @example requestStatus - "Accept"
            // @param success: Is the operation successful or not
            // @param result * out - Result of the operation.
            //*@example result.success - true
            */ @retval Core::ERROR_NONE - Reque*t processed successfully.
            // @retval Core::ERROR_GENERAL - Failed to process the request.
            virtual Core::hresult AcceptClientConnection(const string &requestStatus /* @text requestStatus */, Result &result /* @out */) = 0;

            // @text stopClientConnection
            // @brief To abort the ongoing connection after accepted connection request
            // @details Terminates an ongoing Miracast connection attempt or active session associated with the specified client device.
            // @param clientMac: MacAddress of the client device
            // @example clientMac - "00:11:22:33:44:55"
            // @param clientName: Name of the client device
            // @example clientName - "AndroidPhone"
            // @param success: Is the operation successful or not
            // @param result - out - Result of the operation.
            // @example result.success - true
            // @retval Core::ERROR_NONE - Connection stopped successfully.
            // @retval Core::ERROR_GENERAL - Failed to stop the connection.
            virtual Core::hresult StopClientConnection(const string &clientMac /* @text mac */, const string &clientName /* @text name */, Result &result /* @out */) = 0;

            // @brief Update the Miracast Player State to the Miracast Service Plugin
            // @text updatePlayerState
            // @details Receives state updates from the Miracast Player and synchronizes the service state machine with the current playback status and termination reason.
            // @param clientMac: MacAddress of the client device
            // @example clientMac - "00:11:22:33:44:55"
            // @param playerState: Player state to be updated
            // @example playerState - PLAYER_STATE_PLAYING
            // @param reasonCode: Reason code for the player state update
            // @example reasonCode - 200
            // @param success: Is the operation successful or not
            // @param result - out - Result of the operation.
            // @example result.success - true
            // @retval Core::ERROR_NONE - Player state updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update the player state.
            virtual Core::hresult UpdatePlayerState(const string &clientMac /* @text mac */, const PlayerState playerState /* @text state */, const int reasonCode /* @text reason_code */, Result &result /* @out */) = 0;

            // @brief Sets the status of the MiracastService backend discovery
            // @text setP2PBackendDiscovery
            // @details Enables or disables backend Wi‑Fi Direct (P2P) discovery used by the Miracast Service for device detection and connection establishment.
            // @param enabled: Is the MiracastService backend discovery enabled or not
            // @example enabled - true
            // @param success: Is the operation successful or not
            // @example result.success - true
            // @param result - out - Result of the operation.
            // @example result.success - true
            // @retval Core::ERROR_NONE - Backend discovery status updated successfully.
            // @retval Core::ERROR_GENERAL - Failed to update backend discovery status.
            virtual Core::hresult SetP2PBackendDiscovery(const bool enabled /* @text enabled */, Result &result /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework