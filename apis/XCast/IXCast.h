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

			struct INotification : virtual public Core::IUnknown {
				enum { ID = ID_XCAST_NOTIFICATION };

				~INotification() override = default;

				virtual void onApplicationLaunchRequestWithLaunchParam(const string& appName, const string& strPayLoad, const string& strQuery, const string& strAddDataUrl) = 0;
				virtual void onApplicationLaunchRequest(const string& appName, const string& parameter) = 0;
				virtual void onApplicationStopRequest(const string& appName, const string& appID) = 0;
				virtual void onApplicationHideRequest(const string& appName, const string& appID) = 0;
				virtual void onApplicationStateRequest(const string& appName, const string& appID) = 0;
				virtual void onApplicationResumeRequest(const string& appName, const string& appID) = 0;
				virtual void onUpdatePowerStateRequest(const string& powerState) = 0;
			};

			~IXCast() override = default;

			virtual void Register(IXCast::INotification* sink) = 0;
			virtual void Unregister(IXCast::INotification* sink) = 0;

			virtual uint32_t Initialize(bool networkStandbyMode) = 0;
			virtual void Deinitialize(void) = 0;

			virtual uint32_t applicationStateChanged(const string& applicationName, const string& state, const string& applicationId, const string& error) const = 0;
			virtual uint32_t enableCastService(string friendlyname,bool enableService) const = 0;
			virtual uint32_t getProtocolVersion(string &protocolVersion /* @out */ ) const = 0;
			virtual uint32_t registerApplications(IApplicationInfoIterator * const appInfoList /* @in */ ) = 0;
			virtual uint32_t setNetworkStandbyMode(bool networkStandbyMode) = 0;
			virtual uint32_t setManufacturerName(string manufacturername) const = 0;
			virtual uint32_t getManufacturerName(string &manufacturername /* @out */ ) const = 0;
			virtual uint32_t setModelName(string modelname) const = 0;
			virtual uint32_t getModelName(string &modelname /* @out */ ) const = 0;
		};

	} // Exchange
} // WPEFramework

#endif //__IXCast_H
