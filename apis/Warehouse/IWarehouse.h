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
        struct EXTERNAL IWarehouse : virtual public Core::IUnknown
        {
            enum { ID = ID_WAREHOUSE };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
            
            struct EXTERNAL WarehouseSuccessErr {
                bool success;
                string error;
            };
            
            struct EXTERNAL WarehouseSuccess {
                bool success;
            };

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown 
            {
                enum { ID = ID_WAREHOUSE_NOTIFICATION };

                // @text resetDone
                // @brief Notifies subscribers about the status of the warehouse reset operation
                // @param success - in - boolean
                // @param error - in - string
                virtual void ResetDone(const bool success, const string& error) {};
            };

            virtual Core::hresult Register(IWarehouse::INotification* notification) = 0;
            virtual Core::hresult Unregister(IWarehouse::INotification* notification) = 0;

            // @text internalReset
            // @brief Invokes the internal reset script, which reboots the Warehouse service
            // @details Invokes the internal reset script, which reboots the Warehouse service. The internal reset script will check for a valid passphrase before proceeding with the reset operation.
            // @param passPhrase - in - string
            // @example passPhrase - "mySecretPassphrase"
            // @param successErr - out - Result of the operation including success state
            // @example successErr: {"success": true, "error": ""}
            // @example success: true
            // @retval Core::ERROR_NONE - Internal reset operation completed successfully.
            // @retval Core::ERROR_GENERAL - Internal reset operation failed.
            virtual Core::hresult InternalReset(const string& passPhrase, WarehouseSuccessErr& successErr /* @out */) = 0;

            // @text isClean
            // @brief Checks the locations on the device where customer data may be stored.
            // @details Checks the locations on the device where customer data may be stored. If any of these locations contain files that are older than the specified age, the clean flag will be set to false and the file locations will be returned.
            // @param age - in - integer
            // @example age - 30
            // @param clean - out - boolean
            // @example clean - true
            // @param files - out - string [] of file locations for each file
            // @example files - ["/opt/persistentStore/application/language","/opt/persistentStore/network/region"]
            // @param success - out - boolean
            // @param error -out - string
            // @example success - true
            // @example error - ""
            // @retval Core::ERROR_NONE - Clean check operation completed successfully.
            // @retval Core::ERROR_GENERAL - Clean check operation failed.
            virtual Core::hresult IsClean(const int age, bool &clean /* @out */, IStringIterator*& files /* @out */, bool &success /* @out */, string& error /* @out */) = 0;
            
            // @text lightReset
            // @brief Resets the application data.
            // @details Resets the application data. This operation will delete all the application data and reset the application to its default state.
            // @param WarehouseSuccessErr - out
            // @example WarehouseSuccessErr - {"success":true,"error":""}
            // @example success: true
            // @retval Core::ERROR_NONE - Light reset operation completed successfully.
            // @retval Core::ERROR_GENERAL - Light reset operation failed.
            virtual Core::hresult LightReset(WarehouseSuccessErr& successErr /* @out */) = 0;
            
            // @text resetDevice
            // @brief Resets the STB to the warehouse state.
            // @details Resets the STB to the warehouse state. This operation will delete all the data on the device and reset the device to its default state.
            // @param suppressReboot - in - bool
            // @example suppressReboot - true
            // @param resetType - in - string
            // @example resetType - "factory"
            // @param WarehouseSuccessErr - out
            // @example WarehouseSuccessErr - {"success":true,"error":""}
            // @example success: true
            // @retval Core::ERROR_NONE - Reset device operation completed successfully.
            // @retval Core::ERROR_GENERAL - Reset device operation failed.
            virtual Core::hresult ResetDevice(const bool suppressReboot, const string& resetType, WarehouseSuccessErr& successErr /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
