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
    struct EXTERNAL IDeviceProvisioning : virtual public Core::IUnknown {
        enum { ID = ID_DEVICEPROVISIONING };

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

        /** Allow the plugin to initialize to use service object */
        // @json:omit
        virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

        /** Allow the plugin to deinitialize to use service object */
        // @json:omit
        virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

        /**********************getSOCId() - start****************************/
        // @text getSOCId
        // @brief Returns the SOC ID based on the provisioning type.
        // @param socIdResult - out - SOCIdResult
        virtual Core::hresult GetSOCId(SOCIdResult& socIdResult /* @out */) = 0;
        /**********************getSOCId() - end******************************/

        /********************** reprovision() - start****************************/
        // @text reprovision
        // @brief Sets the status of telemetry reporting
        // @param provisionType - in - string
        // @param fetchCredentials - in - bool
        // @param provisionTypes - out - ProvisionTypes
        // @param success - out - bool
        virtual Core::hresult Reprovision( const string& provisionType /* @in */, const bool& fetchCredentials /* @in */, ProvisionTypes& provisionTypes /* @out */ , bool& success /* @out */) = 0;
        /**********************reprovision() - end******************************/

    };
}
}

