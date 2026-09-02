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

                // @brief Triggered when the Miracast Service plugin receives a new connection request from a client
                // @text onClientConnectionRequest
                // @details Notifies listeners of an incoming Miracast connection request, identifying the requesting client so the application can prompt the user to accept or reject it via acceptClientConnection.
                // @param clientMac: MacAddress of the client device
                // @example clientMac: 00:11:22:33:44:55
                // @param clientName: Name of the client device
                // @example clientName: John's iPhone
                virtual void OnClientConnectionRequest(const string &clientMac /* @text mac */, const string &clientName /* @text name */) {};

                // @brief It is triggered when the Miracast Service plugin failed to connect with the source streaming device due to some error, like P2P related errors during activation or while streaming
                // @text onClientConnectionError
                // @details Notifies listeners that the connection to the source streaming device could not be established, providing the failing client's identity along with a reason code and description of the underlying P2P or streaming error.
                // @param clientMac: MacAddress of the client device
                // @example clientMac: 00:11:22:33:44:55
                // @param clientName: Name of the client device
                // @example clientName: John's iPhone
                // @param reasonCode: Error code for the connection failure
                // @example reasonCode: "1001"
                // @param reasonDescription: Description of the reason for the connection failure
                // @example reasonDescription: "P2P_CONNECT_FAILURE"
                virtual void OnClientConnectionError(const string &clientMac /* @text mac */, const string &clientName /* @text name */, const string &reasonCode /* @text error_code */, const ReasonCode reasonDescription /* @text reason */) {};

                // @brief Miracast Service Plugin raises this Event to request RA or MiracastWidget to launch the Miracast Player
                // @text onLaunchRequest
                // @details Triggered when the Miracast Service plugin needs the Resident Application or MiracastWidget to launch the Miracast Player, providing the source and sink device parameters required to start streaming.
                // @param deviceParameters: Contains Source and Sink Device related properties
                // @example deviceParameters: { sourceDeviceIP: "192.168.1.2", sinkDeviceIP: "192.168.1.3" }
                virtual void OnLaunchRequest(const DeviceParameters &deviceParameters/* @text device_parameters*/) {};
            };

            // @json:omit
            virtual Core::hresult Register(Exchange::IMiracastService::INotification *notification) = 0;
            // @json:omit
            virtual Core::hresult Unregister(Exchange::IMiracastService::INotification *notification) = 0;

            // @brief To enable or disable the Miracast feature
            // @text setEnable
            // @details Enables or disables the Miracast feature on the device. When enabled, the device will be discoverable by other Miracast devices and can accept connection requests. When disabled, the device will not be discoverable and will reject any incoming connection requests.
            // @param enabled: Is the MiracastService discovery enabled or not
            // @example enabled: true
            // @param result: Result of the set enable operation
            // @example result: { success: true }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetEnabled(const bool enabled /* @text enabled */, Result &result /* @out */) = 0;

            // @brief To get the enable status of the Miracast feature
            // @text getEnable
            // @details Retrieves the enable status of the Miracast feature on the device. If enabled, the device is discoverable by other Miracast devices and can accept connection requests. If disabled, the device is not discoverable and will reject any incoming connection requests.
            // @param enabled: Is the MiracastService discovery enabled or not
            // @example enabled: true
            // @param success: Is the operation successful or not
            // @example success: true
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;

            // @brief To accept or reject new client connection requests for the Miracast feature
            // @text acceptClientConnection
            // @details Accepts or rejects new client connection requests for the Miracast feature. If accepted, the Miracast Service plugin will establish a connection with the client device and start streaming. If rejected, the Miracast Service plugin will send a rejection response to the client device.
            // @param requestStatus: It should be "Accept" or "Reject"
            // @example requestStatus: Accept
            // @param result: Contains the result of the operation, including a message and a success flag
            // @example result: { message: "Connection accepted", success: true }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult AcceptClientConnection(const string &requestStatus /* @text requestStatus */, Result &result /* @out */) = 0;

            // @brief To abort the ongoing connection after accepted connection request
            // @text stopClientConnection
            // @details Aborts the ongoing connection after accepted connection request. This can be used to stop the streaming from the source device to the sink device.
            // @param clientMac: MacAddress of the client device
            // @example clientMac: 00:11:22:33:44:55
            // @param clientName: Name of the client device
            // @example clientName: John's iPhone
            // @param result: Contains the result of the operation, including a message and a success flag
            // @example result: { message: "Connection stopped", success: true }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult StopClientConnection(const string &clientMac /* @text mac */, const string &clientName /* @text name */, Result &result /* @out */) = 0;

            // @brief Update the Miracast Player State to the Miracast Service Plugin
            // @text updatePlayerState
            // @details Updates the Miracast Player State to the Miracast Service Plugin. This can be used to inform the plugin about the current state of the player, such as whether it is playing, paused, or stopped.
            // @param clientMac: MacAddress of the client device
            // @example clientMac: 00:11:22:33:44:55
            // @param playerState: Player state to be updated
            // @example playerState: PLAYER_STATE_PLAYING
            // @param reasonCode: Reason code for the player state update
            // @example reasonCode: 200
            // @param result: Contains the result of the operation, including a message and a success flag
            // @example result: { message: "Player state updated", success: true }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult UpdatePlayerState(const string &clientMac /* @text mac */, const PlayerState playerState /* @text state */, const int reasonCode /* @text reason_code */, Result &result /* @out */) = 0;

            // @brief Sets the status of the MiracastService backend discovery
            // @text setP2PBackendDiscovery
            // @details Sets the status of the MiracastService backend discovery. When enabled, the MiracastService will perform backend discovery to find available Miracast devices. When disabled, the backend discovery will be turned off.
            // @param enabled: Is the MiracastService backend discovery enabled or not
            // @example enabled: true
            // @param result: Contains the result of the operation, including a message and a success flag
            // @example result: { message: "Backend discovery status updated", success: true }
            // @retval Core::ERROR_NONE: Indicates success
            virtual Core::hresult SetP2PBackendDiscovery(const bool enabled /* @text enabled */, Result &result /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
