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
                virtual void ResetDone(const bool& success, const string& error) {};
            };

            virtual Core::hresult Register(IWarehouse::INotification* notification) = 0;
            virtual Core::hresult Unregister(IWarehouse::INotification* notification) = 0;

            // @text executeHardwareTest
            // @brief Starts a hardware test on the device
            // @param WarehouseSuccess - out
            virtual Core::hresult ExecuteHardwareTest(WarehouseSuccess& success /* @out */) = 0;

            // @text getHardwareTestResults
            // @brief Returns the results of the last hardware test.
            // @param testResults - out - string
            // @param WarehouseSuccess - out 
            virtual Core::hresult GetHardwareTestResults(string& testResults /* @out */, WarehouseSuccess& success /* @out */) = 0;

            // @text internalReset
            // @brief Invokes the internal reset script, which reboots the Warehouse service
            // @param passPhrase - in - string
            // @param WarehouseSuccessErr - out
            virtual Core::hresult InternalReset(const string& passPhrase, WarehouseSuccessErr& successErr /* @out */) = 0;

            // @text isClean
            // @brief Checks the locations on the device where customer data may be stored.
            // @param age - in - integer
            // @param clean - out - boolean
            // @param files - out - string [] of file locations for each file
            // @param success - out - boolean
            virtual Core::hresult IsClean(const int age, bool &clean /* @out */, IStringIterator*& files /* @out */, bool &success /* @out */) = 0;
            
            // @text lightReset
            // @brief Resets the application data.
            // @param WarehouseSuccessErr - out
            virtual Core::hresult LightReset(WarehouseSuccessErr& successErr /* @out */) = 0;
            
            // @text resetDevice
            // @brief Resets the STB to the warehouse state.
            // @param suppressReboot - in - bool
            // @param resetType - in - string
            // @param WarehouseSuccessErr - out
            virtual Core::hresult ResetDevice(const bool suppressReboot, const string& resetType, WarehouseSuccessErr& successErr /* @out */) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
