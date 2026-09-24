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

#pragma once

#include "Module.h"

namespace WPEFramework {
    namespace Exchange {

        struct EXTERNAL IHomeKitTV : virtual public Core::IUnknown {
            enum { ID = ID_HOMEKITTV};

            virtual ~IHomeKitTV() { }

            enum foregroundreason : uint16_t {
                AIRPLAY_FROM_HOME_BUTTON = 1,
                AIRPLAY_INPUT_SOURCE = 2
            };
            enum state : uint16_t {
                STARTED = 1,
                STOPPED = 2
            };

            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_HOMEKITTV_NOTIFICATION };

                // @brief Notifies when the state of the HomeKit TV changes.
                // @details This event is triggered whenever there is a change in the state of the HomeKit TV.
                // @param state: The new state of the HomeKit TV.
                // @example state: 1
                virtual void StateChange(const IHomeKitTV::state state) = 0;

                // @brief Notifies when the HomeKit TV exits.
                // @details This event is triggered when the HomeKit TV exits.
                // @param exitCode: The exit code of the HomeKit TV.
                // @example exitCode: 0
                virtual void Exit(const uint32_t exitCode) = 0;

                // @brief Notifies when there is a request to change the app state.
                // @details This event is triggered when there is a request to change the state of the app.
                // @param params: JSON string containing the details of the app state change request.
                // @example params: "{ \"state\": \"foreground\" }
                virtual void dispatchOnAppStateChangeRequest(const string& params) = 0;

                // @brief Notifies when the enabled status of the HomeKit TV changes.
                // @details This event is triggered whenever there is a change in the enabled status of the HomeKit TV.
                // @param params: JSON string containing the details of the enabled status change.
                // @example params: "{ \"enabled\": true }"
                virtual void dispatchOnEnabledStatusChanged(const string& params) = 0;

                // @brief Notifies when the input source of the HomeKit TV changes.
                // @details This event is triggered whenever there is a change in the input source of the HomeKit TV.
                // @param params: JSON string containing the details of the input source change.
                // @example params: "{ \"inputSource\": \"HDMI1\" }"
                virtual void dispatchOnInputSourceChanged(const string& params) = 0;

                // @brief Notifies when there is an Airplay error event.
                // @details This event is triggered whenever there is an Airplay error.
                // @param params: JSON string containing the details of the Airplay error event.
                // @example params: "{ \"error\": \"Connection lost\" }"
                virtual void dispatchAirplayErrorEvent(const string& params) = 0;

                // @brief Notifies when the connection status of the HomeKit TV changes.
                // @details This event is triggered whenever there is a change in the connection status of the HomeKit TV.
                // @param params: JSON string containing the details of the connection status change.
                // @example params: "{ \"connected\": true }"
		virtual void dispatchOnConnectionStatusChanged(const string& params) = 0;
            };

            virtual void Register(IHomeKitTV::INotification* homeKitTV) = 0;
            virtual void Unregister(IHomeKitTV::INotification* homeKitTV) = 0;
           
            // @brief Performs a factory reset of the HomeKit TV.
            // @details This method triggers a factory reset, restoring the HomeKit TV to its default settings. All user data and configurations will be lost.
            virtual void FactoryReset() = 0;

            // @brief Requests the launch of an app on the HomeKit TV.
            // @details This method triggers the launch of an app on the HomeKit TV based on the specified origin and reason.
            // @param origin: The origin of the app launch request.
            // @example origin: "com.example.myapp"
            // @param reason: The reason for the app launch request.
            // @example reason: "User initiated"
            // @param result: JSON string containing the result of the app launch request.
            // @example result: "{ \"success\": true }"
            virtual uint32_t requestAppLaunch(const string& origin, const string& reason, string& result /* @out */) = 0;

            // @brief Sets the current input source of the HomeKit TV.
            // @details This method changes the input source of the HomeKit TV to the specified value.
            // @param inputsource: The desired input source (e.g., "HDMI1").
            // @example inputsource: "HDMI1"
            // @param response: JSON string containing the result of the input source change request.
            // @example response: "{ \"success\": true }"
	    virtual uint32_t setCurrentInputSource(const string& inputsource, string& response /* @out */) = 0;
          
            // @brief Retrieves the enabled status of the HomeKit TV.
            // @details This method fetches the current enabled status of the HomeKit TV.
            // @param result: Boolean indicating whether the HomeKit TV is enabled.
            // @example result: "{ \"enabled\": true }"
        virtual void getEnabledStatus(bool& result /* @out */) = 0;
           
            // @brief Retrieves the connection status of the HomeKit TV.
            // @details This method fetches the current connection status of the HomeKit TV.
            // @param result: Boolean indicating whether the HomeKit TV is connected.
            // @example result: "{ \"connected\": true }"
	        virtual void getConnectionStatus(bool& result /* @out */) = 0;

            // @brief Sets the IP address of the app container on the HomeKit TV.
            // @details This method configures the IP address for the app container running on the HomeKit TV.
            // @param ipaddress: The IP address to be set for the app container.
            // @example ipaddress: "192.168.1.100"
	    virtual uint32_t setAppContainerIPAddress(const string& ipaddress) = 0;
        };
    }
}

