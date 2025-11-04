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
                STOPPED = 2,
                paused = 3,
                RE-START = 4 
            };

            struct EXTERNAL INotification : virtual public Core::IUnknown {
                enum { ID = ID_HOMEKITTV_NOTIFICATION };
                virtual void StateChange(const IHomeKitTV::state state) =  0;
                virtual void Exit(const uint32_t exitCode) = 0;
                virtual void dispatchOnAppStateChangeRequest(const string& params) = 0;
                virtual void dispatchOnEnabledStatusChanged(const string& params) = 0;
                virtual void dispatchOnInputSourceChanged(const string& params) = 0;
                virtual void dispatchAirplayErrorEvent(const string& params)= 0;
			    virtual void dispatchOnConnectionStatusChanged
						(const string& params) = 0;
            };

            virtual void Register(IHomeKitTV::INotification* homeKitTV) = 0;
            virtual void Unregister(IHomeKitTV::INotification* homeKitTV) = 0;

            virtual void FactoryReset() = 0;
            virtual uint32_t requestAppLaunch(const string& origin, const string& reason, string& result /* @out */) = 0;
	        virtual uint32_t setCurrentInputSource(const string& inputsource, string& response /* @out */) = 0;
            virtual void GetEnabledStatus(bool& result /* @out */) = 0;
	        virtual void getConnectionStatus(bool& result /* @out */) =0;

	        virtual uint32_t setAppContainerIPAddress(const string& ipaddress) = 0;
        };
    }
}

