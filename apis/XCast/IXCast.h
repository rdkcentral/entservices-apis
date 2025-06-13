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

#ifndef __IXCast_H
#define __IXCast_H

#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
	namespace Exchange {
		/* @json 1.0.0 @text:keep */
		struct EXTERNAL IXCast : virtual public Core::IUnknown {
			enum { ID = ID_XCAST };

			struct ApplicationInfo {
				string appName;
				string prefixes;
				string cors;
				string query;
				string payload;
				int  allowStop;
			};

			using IApplicationInfoIterator = RPC::IIteratorType<ApplicationInfo,ID_XCAST_APPLICATION_INFO_ITERATOR>;
			
			//@event
			struct EXTERNAL INotification : virtual public Core::IUnknown {
				enum { ID = ID_XCAST_NOTIFICATION };

				// ~INotification() override = default;

				virtual void OnApplicationLaunchRequestWithLaunchParam(const string& appName, const string& strPayLoad, const string& strQuery, const string& strAddDataUrl) {};
				virtual void OnApplicationLaunchRequest(const string& appName, const string& parameter)  {};
				virtual void OnApplicationStopRequest(const string& appName, const string& appID)  {};
				virtual void OnApplicationHideRequest(const string& appName, const string& appID)  {};
				virtual void OnApplicationStateRequest(const string& appName, const string& appID)  {};
				virtual void OnApplicationResumeRequest(const string& appName, const string& appID)  {};
				virtual void OnUpdatePowerStateRequest(const string& powerState)  {};
			};

			// ~IXCast() override = default;

			virtual Core::hresult Register(IXCast::INotification* sink /* @in */) = 0;
			virtual Core::hresult Unregister(IXCast::INotification* sink /* @in */) = 0;	

			virtual Core::hresult ApplicationStateChanged(const string& applicationName, const string& state, const string& applicationId, const string& error) = 0;
			virtual Core::hresult GetProtocolVersion(string &protocolVersion /* @out */ ) = 0;
			virtual Core::hresult SetNetworkStandbyMode(bool networkStandbyMode) = 0;
			virtual Core::hresult SetManufacturerName(string manufacturername) = 0;
			virtual Core::hresult GetManufacturerName(string &manufacturername /* @out */ ) = 0;
			virtual Core::hresult SetModelName(string modelname) = 0;
			virtual Core::hresult GetModelName(string &modelname /* @out */ ) = 0;

			virtual Core::hresult SetEnabled(bool enabled) = 0;
			virtual Core::hresult GetEnabled(bool &enabled /* @out */, bool &success /* @out */) = 0;
			virtual Core::hresult SetStandbyBehavior(string standbybehavior) = 0;
			virtual Core::hresult GetStandbyBehavior(string &standbybehavior /* @out */, bool &success /* @out */ ) = 0;
			virtual Core::hresult SetFriendlyName(string friendlyname) = 0;
			virtual Core::hresult GetFriendlyName(string &friendlyname /* @out */, bool &success /* @out */) = 0;
			virtual Core::hresult GetApiVersionNumber(uint32_t &version /* @out */, bool &success/* @out */) = 0;

			virtual Core::hresult RegisterApplications(IApplicationInfoIterator* const appInfoList /* @in @opaque */) = 0;

		};

	} // Exchange
} // WPEFramework

#endif //__IXCast_H
