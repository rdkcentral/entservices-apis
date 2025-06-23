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

			struct EXTERNAL ApplicationInfo {
				string appName /* @text names */ /* @brief Group of acceptable names for a related application. Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail */;
				string prefixes /* @text prefixes */ /* @brief  If the application name in request URI does not match the list of names, it must contain one of the prefixes.If the application name in request URI does not match any names or prefixes, then the request shall fail */; 
				string cors /* @text cors */ /* @briefa set of origins allowed for the application. This must not be empty */;
				string query /* @text query */ /* @brief query string that need to be appended in launch request */;
				string payload /* @text payload */ /* @brief optional payload string that need to be appended in launch request */;
				int  allowStop /* @text allowStop */ /* @brief 	is the application (matching name list or prefix list) allowed to stop (no PID presence) after launched */;
			};

			using IApplicationInfoIterator = RPC::IIteratorType<ApplicationInfo,ID_XCAST_APPLICATION_INFO_ITERATOR>;
			
			//@event
			struct EXTERNAL INotification : virtual public Core::IUnknown {
				enum { ID = ID_XCAST_NOTIFICATION };


				// @text onApplicationLaunchRequest
				// @brief Triggered when the cast service receives a launch request from a client with launch params
				// @param appName: Registered application name
				// @param strPayLoad: Payload string to be passed to the application
				// @param strQuery: Query string to be appended in launch request
				// @param strAddDataUrl: Additional data URL to be passed to the application
				virtual void OnApplicationLaunchRequestWithLaunchParam(const string& appName, const string& strPayLoad, const string& strQuery, const string& strAddDataUrl) {};
				// @text onApplicationLaunchRequest
				// @brief Triggered when the cast service receives a launch request from a client with launch params
				// @param appName: Registered application name
				// @param parameter: Application launch string
				virtual void OnApplicationLaunchRequest(const string& appName, const string& parameter)  {};
				// @text onApplicationStopRequest
				// @brief 	Triggered when the cast service receives a stop request from a client
				// @param appName: 	Registered application name
				// @param appID: 	Application instance ID
				virtual void OnApplicationStopRequest(const string& appName, const string& appID)  {};
				// @text onApplicationHideRequest
				// @brief Triggered when the cast service receives a hide request from a client
				// @param appName: Registered application name
				// @param appID: Application instance ID
				virtual void OnApplicationHideRequest(const string& appName, const string& appID)  {};
				// @text onApplicationStateRequest
				// @brief 	Triggered when the cast service needs an update of the application state
				// @param appName: Registered application name
				// @param appID: Application instance ID
				virtual void OnApplicationStateRequest(const string& appName, const string& appID)  {};
				// @text onApplicationResumeRequest
				// @brief Triggered when the cast service receives a resume request from a client
				// @param appName: Registered application name
				// @param appID: Application instance ID
				virtual void OnApplicationResumeRequest(const string& appName, const string& appID)  {};
			};

			virtual Core::hresult Register(IXCast::INotification* sink /* @in */) = 0;
			virtual Core::hresult Unregister(IXCast::INotification* sink /* @in */) = 0;	

			/****************************************applicationStateChanged()*****************************/
			// @text applicationStateChanged
			// @brief Triggered when the cast service receives an application state change notification from a client
			// @param appName: Registered application name
			// @param state: Application state
			// @param appId: Application instance ID
			// @param error: Error string, if any
			virtual Core::hresult ApplicationStateChanged(const string& applicationName /* @in @text appName */, const string& state /* @in @text state */, const string& applicationId /* @in @text appId */, const string& error /* @in @text error */) = 0;
			/****************************************applicationStateChanged()*****************************/

			/****************************************getProtocolVersion()**********************************/
			// @text getProtocolVersion
			// @brief Returns the DIAL protocol version supported by the server
			// @param version: 	DIAL protocol version
			// @param success: 	Whether the request succeeded
			virtual Core::hresult GetProtocolVersion(string &protocolVersion /* @out @text version */, bool &success /* @out */) = 0;
			/***************************************** getProtocolVersion() **********************************/


			/****************************************setManufacturerName()**********************************/
			// @text setManufacturerName
			// @brief Sets the manufacturer name of the device
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			virtual Core::hresult SetManufacturerName(const string &manufacturername /* @in @text manufacturer */) = 0;
			/***************************************** setManufacturerName() **********************************/

			/****************************************getManufacturerName()**********************************/
			// @text getManufacturerName
			// @brief Returns the manufacturer name set by setManufacturerName API
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			// @param success: Whether the request succeeded
			virtual Core::hresult GetManufacturerName(string &manufacturername /* @out @text manufacturer */, bool &success /* @out */) = 0;
			/***************************************** getManufacturerName() *********************************/

			/****************************************setModelName()**********************************/
			// @text setModelName
			// @brief Sets the model name of the device
			// @param model: The Model name of the device which used to update in dd.xml
			virtual Core::hresult SetModelName(const string &modelname /* @in @text model */) = 0;
			/***************************************** setModelName() **********************************/

			/****************************************getModelName()**********************************/
			// @text getModelName
			// @brief Returns the model name set by setModelName API
			// @param model: The Model name of the device which used to update in dd.xml
			// @param success: Whether the request succeeded
			virtual Core::hresult GetModelName(string &modelname /* @out @text model */, bool &success /* @out */) = 0;
			/***************************************** getModelName() *********************************/


			/****************************************setEnabled()**********************************/
			// @text setEnabled
			// @brief Enable or disable XCAST service
			// @parm enabled: true for enabled or false for disabled
			virtual Core::hresult SetEnabled(const bool& enabled /* @in @text enabled */) = 0;
			/***************************************** setEnabled() **********************************/

			/****************************************getEnabled()**********************************/
			// @text getEnabled
			// @brief Reports whether xcast plugin is enabled or disabled
			// @param enabled: true for enabled or false for disabled
			// @param success: Whether the request succeeded
			virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;
			/***************************************** getEnabled() **********************************/


			/****************************************setStandbyBehavior()**********************************/
			// @text setStandbyBehavior
			// @brief Sets the expected xcast behavior in standby mode
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			virtual Core::hresult SetStandbyBehavior(const string &standbybehavior /* @in @text standbybehavior */) = 0;
			/***************************************** setStandbyBehavior() *********************************/


			/****************************************getStandbyBehavior()**********************************/
			// @text getStandbyBehavior
			// @brief Return current standby behavior option string set uisng setStandbyBehavior or default value
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			// @param success: Whether the request succeeded
			virtual Core::hresult GetStandbyBehavior(string &standbybehavior /* @out @text standbybehavior */, bool &success /* @out */) = 0;
			/***************************************** getStandbyBehavior() *********************************/

			/****************************************setFriendlyName()**********************************/
			// @text setFriendlyName
			// @brief Sets the friendly name of the device
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			virtual Core::hresult SetFriendlyName(const string &friendlyname /* @in @text friendlyname */) = 0;
			/***************************************** setFriendlyName() **********************************/

			/****************************************getFriendlyName()**********************************/
			// @text getFriendlyName
			// @brief Returns the friendly name set by setFriendlyName API
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			// @param success: Whether the request succeeded
			virtual Core::hresult GetFriendlyName(string &friendlyname /* @out @text friendlyname */, bool &success /* @out */) = 0;
			/***************************************** getFriendlyName() *********************************/


			/****************************************getApiVersionNumber()**********************************/
			// @text getApiVersionNumber
			// @brief Gets the API version number
			// @param version: a version number
			// @param success: Whether the request succeeded
			virtual Core::hresult GetApiVersionNumber(uint32_t &version /* @out @text version */, bool &success/* @out */) = 0;
			/****************************************getApiVersionNumber()**********************************/

			
			/****************************************registerApplications()**********************************/
			// @text registerApplications
			// @brief Registers an application
			// @param appInfoList: Json array with one or more application details to register
			virtual Core::hresult RegisterApplications(IApplicationInfoIterator* const appInfoList ) = 0;
			/****************************************registerApplications()**********************************/

			/****************************************unregisterApplications()**********************************/
			// @text unregisterApplications
			// @brief Unregisters an application
			// @param applications: One or more application name to unregister
			virtual Core::hresult UnregisterApplications(const string &appName /* @in @text applications */) = 0;
			/****************************************unregisterApplications()**********************************/
			

		};

	} // Exchange
} // WPEFramework

#endif //__IXCast_H
