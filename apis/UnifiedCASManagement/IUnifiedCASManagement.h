/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 RDK Management
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
        struct EXTERNAL IUnifiedCASManagement : virtual public Core::IUnknown 
        {
            enum { ID = ID_UNIFIEDCASMANAGEMENT };

            // @text tunemode
            enum TuneMode : uint8_t {
                MODE_NONE = 0,
                MODE_LIVE = 1,
                MODE_RECORD = 2,
                MODE_PLAYBACK = 3
            };

            // @text managementtype
            enum ManagementType : uint8_t {
                MANAGE_FULL = 0,
                MANAGE_NO_PSI = 1,
                MANAGE_NO_TUNER = 2
            };

            // @text datasource
            enum DataSource : uint8_t {
                PUBLIC = 0,
                PRIVATE = 1
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_UNIFIEDCASMANAGEMENT_NOTIFICATION };

                // @text onDataReceived
                // @alt data
                // @brief Sent when the CAS needs to send data to the caller  
                // @details Forwards data received from the CAS to the registered notification callback. The payload may be base64 encoded when required.
                // @param payload Data to transfer. Can be base64 coded if required
                // @example payload: "AQID"
                // @param source Origin of the data
                // @example source: PUBLIC
                virtual void OnDataReceived(const string& payload, const DataSource& source) {}
            };

            // @brief Register a notification callback
            // @param notification: The notification callback object
            // @retval Core::ERROR_NONE: Registration successful
            // @retval Core::ERROR_ALREADY_CONNECTED: Callback already registered
            virtual Core::hresult Register(IUnifiedCASManagement::INotification* notification) = 0;
            
            // @brief Unregister a notification callback
            // @param notification: The notification callback object to remove
            // @retval Core::ERROR_NONE: Unregistration successful
            // @retval Core::ERROR_UNKNOWN_KEY: Callback not found
            virtual Core::hresult Unregister(IUnifiedCASManagement::INotification* notification) = 0;

            // @text manage
            // @brief Manage a well-known CAS (setup CAS management session)
            // @details Creates a management session for the selected CAS using the media URL, tune mode, management type, and CAS-specific initialization data.
            // @param mediaurl The URL to tune to (tune://, ocap://, http://, https://)
            // @example mediaurl: "ocap://channel"
            // @param mode The use of the tune request
            // @example mode: MODE_LIVE
            // @param managementType Type of CAS management
            // @example managementType: MANAGE_FULL
            // @param casinitdata CAS specific initdata for the selected media
            // @example casinitdata: ""
            // @param casocdmid The well-known OCDM ID of the CAS to use
            // @example casocdmid: "com.example.cas"
            // @param success Returns true if the operation succeeded, false otherwise
            // @example success: true
            // @retval Core::ERROR_NONE: Operation successful
            // @retval Core::ERROR_GENERAL: Operation failed
            virtual Core::hresult Manage(const string& mediaurl, 
                                       const TuneMode& mode, 
                                       const ManagementType& managementType, 
                                       const string& casinitdata, 
                                       const string& casocdmid,
                                       bool& success /* @out */) = 0;

            // @text unmanage
            // @brief Destroy a management session
            // @details Ends the active CAS management session.
            // @param success Returns true if the operation succeeded, false otherwise
            // @example success: true
            // @retval Core::ERROR_NONE: Operation successful
            // @retval Core::ERROR_GENERAL: Operation failed
            virtual Core::hresult Unmanage(bool& success /* @out */) = 0;

            // @text send 
            // @brief Sends data to the remote CAS
            // @details Transfers the supplied payload to the remote CAS and identifies whether the data source is public or private.
            // @param payload Data to transfer. Can be base64 coded if required
            // @example payload: "AQID"
            // @param source Origin of the data
            // @example source: PUBLIC
            // @param success Returns true if the operation succeeded, false otherwise
            // @example success: true
            // @retval Core::ERROR_NONE: Operation successful
            // @retval Core::ERROR_GENERAL: Operation failed
            virtual Core::hresult Send(const string& payload, const DataSource& source, bool& success /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
