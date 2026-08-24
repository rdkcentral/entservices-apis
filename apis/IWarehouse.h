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
                // @details Triggered when a warehouse reset operation completes. The event
                // includes the outcome of the operation and any associated error message.
                // @param success - in - boolean
                // @example success - true
                // @param error - in - string
                // @example error - ""
                virtual void ResetDone(const bool success, const string& error) {};
            };

            virtual Core::hresult Register(IWarehouse::INotification* notification) = 0;
            virtual Core::hresult Unregister(IWarehouse::INotification* notification) = 0;

            // @text internalReset
            // @brief Invokes the internal reset script, which reboots the Warehouse service
            // @details Executes the internal warehouse reset procedure. The operation
            // performs the required cleanup actions and restarts the warehouse service.
            // @param passPhrase - in - string
            // @example passPhrase - "warehouse-reset"
            // @param WarehouseSuccessErr - out -Result of the operation including success state
            // and error details.
            // @example WarehouseSuccessErr - success: true, error: ""
            // @retval Core::ERROR_NONE - Internal reset initiated successfully.
            // @retval Core::ERROR_GENERAL - Failed to initiate internal reset.
            virtual Core::hresult InternalReset(const string& passPhrase, WarehouseSuccessErr& successErr /* @out */) = 0;

            // @text isClean
            // @brief Checks the locations on the device where customer data may be stored.
            // @details Scans known storage locations and determines whether customer
            // data remains on the device. Returns the list of detected files and the
            // overall cleanup status.
            // @param age - in - integer
            // @example age - 30
            // @param clean - out - boolean
            // @example clean - true
            // @param files - out - string [] of file locations for each file
            // @example files - ["/path/to/file1", "/path/to/file2"]
            // @param success - out - boolean
            // @example success - true
            // @param error -out - string
            // @example error - ""
            // @retval Core::ERROR_NONE - Device cleanup status retrieved successfully.
            // @retval Core::ERROR_GENERAL - Failed to perform cleanup verification.
            virtual Core::hresult IsClean(const int age, bool &clean /* @out */, IStringIterator*& files /* @out */, bool &success /* @out */, string& error /* @out */) = 0;
            
            // @text lightReset
            // @brief Resets the application data.
            // @details Performs a light warehouse reset operation by clearing
            // application-specific data without performing a full device reset.
            // @param WarehouseSuccessErr - out
            // @param successErr - out - Result of the operation including success state
            // and error details.
            // @example successErr.success - true
            // @retval Core::ERROR_NONE - Light reset completed successfully.
            // @retval Core::ERROR_GENERAL - Failed to perform light reset.
            virtual Core::hresult LightReset(WarehouseSuccessErr& successErr /* @out */) = 0;
            
            // @text resetDevice
            // @brief Resets the STB to the warehouse state.
            // @details Performs a full device reset, returning the device to the warehouse state.
            // @param suppressReboot - in - bool
            // @example suppressReboot - false
            // @param resetType - in - string
            // @example resetType - "WAR*HOUSE"
            // @param WarehouseSuccessErr - out
            // @example WarehouseSuccessErr.success - true
            // @param successErr - out - Result of the operation including success state
            // and error details.
            // @example successErr.success - true
            // @retval Core::ERROR_NONE - Device reset completed successfully.
            // @retval Core::ERROR_GENERAL - Failed to perform device reset.

            virtual Core::hresult ResetDevice(const bool suppressReboot, const string& resetType, WarehouseSuccessErr& successErr /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
