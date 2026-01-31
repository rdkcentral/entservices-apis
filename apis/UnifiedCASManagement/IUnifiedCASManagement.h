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
        struct EXTERNAL IUnifiedCASManagement : virtual public Core::IUnknown 
        {
            enum { ID = ID_UNIFIEDCASMANAGEMENT };

            struct EXTERNAL SuccessResult {
                bool success;
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_UNIFIEDCASMANAGEMENT_NOTIFICATION };

                // @text data
                // @brief Sent when the CAS needs to send data to the caller  
                // @param payload - in - string - Data to transfer. Can be base64 coded if required
                // @param source - in - string - Origin of the data (PUBLIC or PRIVATE)
                virtual void Event_data(const string& payload, const string& source) {}
            };

            virtual Core::hresult Register(IUnifiedCASManagement::INotification* notification) = 0;
            virtual Core::hresult Unregister(IUnifiedCASManagement::INotification* notification) = 0;

            /**********************manage() - start****************************/
            // @text manage
            // @brief Manage a well-known CAS (setup CAS management session)
            // @param mediaurl - in - string - The URL to tune to (tune://, ocap://, http://, https://)
            // @param mode - in - string - The use of the tune request (MODE_NONE, MODE_LIVE, MODE_RECORD, MODE_PLAYBACK)
            // @param managementType - in - string - Type of CAS management (MANAGE_NONE, MANAGE_FULL, MANAGE_NO_PSI, MANAGE_NO_TUNER)
            // @param casinitdata - in - string - CAS specific initdata for the selected media
            // @param casocdmid - in - string - The well-known OCDM ID of the CAS to use
            // @param successResult - out - struct
            virtual Core::hresult Manage(const string& mediaurl, 
                                       const string& mode, 
                                       const string& managementType, 
                                       const string& casinitdata, 
                                       const string& casocdmid,
                                       SuccessResult& successResult /* @out */) = 0;
            /**********************manage() - end******************************/

            /**********************unmanage() - start***************************/
            // @text unmanage
            // @brief Destroy a management session
            // @param successResult - out - struct
            virtual Core::hresult Unmanage(SuccessResult& successResult /* @out */) = 0;
            /**********************unmanage() - end*****************************/

            /**********************send() - start*******************************/
            // @text send 
            // @brief Sends data to the remote CAS
            // @param payload - in - string - Data to transfer. Can be base64 coded if required
            // @param source - in - string - Origin of the data (PUBLIC or PRIVATE)
            // @param successResult - out - struct
            virtual Core::hresult Send(const string& payload, const string& source, SuccessResult& successResult /* @out */) = 0;
            /**********************send() - end*********************************/
        };
    } // namespace Exchange
} // namespace WPEFramework