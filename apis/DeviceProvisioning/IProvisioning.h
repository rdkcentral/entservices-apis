/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

namespace WPEFramework {
namespace Exchange {
/* @json 1.0.0 @text:keep */    
    struct EXTERNAL IProvisioning : virtual public Core::IUnknown {
        enum { ID = ID_PROVISIONING };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_PROVISIONING_NOTIFICATION };

            // @text provisioned
            // @brief Signal changes on the subscribed namespace.
            // @param labels   - in - RPC::IStringIterator
            virtual void Provisioned(const RPC::IStringIterator* labels) {};
        };

        virtual Core::hresult Register(IProvisioning::INotification* notification /* @in */) = 0;
        virtual Core::hresult Unregister(IProvisioning::INotification* notification /* @in */) = 0;


        struct EXTERNAL VersionResult {
            string version /* @text version */;
            bool success /* @text success */;
        };
        struct EXTERNAL NetflixESNResult {
            string esn /* @text esn */;
            bool success /* @text success */;
            string error /* @text error */;
        };

        struct EXTERNAL SOCIdResult {
            string socid /* @text socid */;
            bool success /* @text success */;
        };

        struct EXTERNAL ProvisionTypes {
            string provisionType /* @text provisionType */;
            string provisionKind /* @text provisionKind */;
            string state /* @text state */;
            string reason /* @text reason */;
        };

        struct EXTERNAL ProvisionTypesResult {
            ProvisionTypes provisionTypes /* @text provisionTypes */;
            bool success /* @text success */;
        };



        /**********************DeviceId() - start****************************/
        // @text deviceId
        // @brief get deviceId of the device
        // @param status - out - string
        virtual Core::hresult DeviceId (string& deviceId /* @out */) const = 0;
        /**********************DeviceId() - end******************************/

        /**********************DRMId() - start****************************/
        // @text drmId
        // @brief get DRMId
        // @param label  - in - string
        // @param size   - inout - uint16_t
        // @param data[] - out - uint8_t
        virtual Core::hresult DRMId (const string& label /* @in */, uint16_t& size /* @inout */, uint8_t data[] /* @length:size @out */) const = 0;
        /**********************DRMId() - end******************************/


        /**********************getApiVersionNumber() - start****************************/
        // @text getApiVersionNumber
        // @brief Gets the current API version number.
        // @param VersionResult - out - versionResult
        virtual Core::hresult GetApiVersionNumber(VersionResult& versionResult /* @out */) = 0;
        /**********************getApiVersionNumber() - end******************************/


        /**********************getNetflixESN() - start****************************/
        // @text getNetflixESN
        // @brief Returns the Netflix Electronic Serial Number (ESN).
        // @param NetflixESNResult - out - netflixESNResult
        virtual Core::hresult GetNetflixESN(NetflixESNResult& netflixESNResult /* @out */) = 0;
        /**********************getNetflixESN() - end******************************/


        /**********************getSOCId() - start****************************/
        // @text getSOCId
        // @brief Returns the SOC ID based on the provisioning type.
        // @param SOCIdResult - out - socIdResult
        virtual Core::hresult GetSOCId(SOCIdResult& socIdResult /* @out */) = 0;
        /**********************setReportProfileStatus() - end******************************/


        /**********************provisionCheck() - start****************************/
        // @text provisionCheck
        // @brief Checks the provisioning condition of the selected device.
        // @param ProvisionTypesResult - out - provisionTypesResult
        virtual Core::hresult ProvisionCheck(ProvisionTypesResult& provisionTypesResult /* @out */) = 0;
        /********************** provisionCheck() - end******************************/

        /********************** reprovision() - start****************************/
        // @text reprovision
        // @brief Sets the status of telemetry reporting
        // @param provisionType - in - string
        // @param fetchCredentials - in - bool
        // @param ProvisionTypesResult - out - provisionTypesResult
        virtual Core::hresult Reprovision( const string& provisionType /* @in */, const bool& fetchCredentials /* @in */, ProvisionTypesResult& provisionTypesResult /* @out */) = 0;
        /**********************reprovision() - end******************************/

    };
}
}

