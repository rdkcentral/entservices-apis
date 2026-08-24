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

			enum State : uint8_t {
				RUNNING = 0 /* @text running */,
				STOPPED = 1/* @text stopped */,
				HIDDEN = 2 /* @text suspended */
     	 	};

			enum StandbyBehavior : uint8_t {
				ACTIVE = 0 /* @text active */,
				INACTIVE = 1 /* @text inactive */
			};
			
			enum ErrorCode : uint16_t {
				NONE = 200 /* @text none */ ,
				FORBIDDEN = 403 /* @text forbidden */ ,
				UNAVAILABLE = 404 /* @text unavailable */ ,
				INVALID = 400 /* @text invalid */,
				INTERNAL = 500 /* @text internal */
			};

			struct EXTERNAL XCastSuccess {
				bool success /* @text success */ /* @brief  true if the request was successful, false otherwise */;
			};

			struct EXTERNAL ApplicationInfo {
				string appName /* @text name */ /* @brief  Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail */;
				string prefixes /* @text prefix */ /* @brief  If the application name in request URI does not match the appname given here, it must contain some prefix.If the application name in request URI does not match the appnames or prefix, then the request shall fail */; 
				string cors /* @text cors */ /* @brief origin allowed for the application. This must not be empty */;
				string query /* @text query */ /* @brief query string that need to be appended in launch request */;
				string payload /* @text payload */ /* @brief optional payload string that need to be appended in launch request */;
				int  allowStop /* @text allowStop */ /* @brief 	is the application (matching name list or prefix list) allowed to stop (no PID presence) after launched */;
			};

			using IApplicationInfoIterator = RPC::IIteratorType<ApplicationInfo,ID_XCAST_APPLICATION_INFO_ITERATOR>;
			using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

			//@event
			struct EXTERNAL INotification : virtual public Core::IUnknown {
				enum { ID = ID_XCAST_NOTIFICATION };

				// @text onApplicationLaunchRequestWithParam
				// @brief Triggered when the cast service receives a launch request from a client with launch params
				// @details This notification is generated when a DIAL/XCast client requests application launch with
				// additional payload, query information, or data URL. Applications should process the request and 
				// launch the target application using the supplied parameters.
				// @param applicationName: Registered application name
				// @example applicationName - "YouTube"
				// @param strPayLoad: Payload string to be passed to the application
				// @example strPayLoad - "payload_data"
				// @param strQuery: Query string to be appended in launch request
				// @example strQuery - "query_data"
				// @param strAddDataUrl: Additional data URL to be passed to the application
				// @example strAddDataUrl - "http://example.com/data"
				virtual void OnApplicationLaunchRequestWithParam(const string& appName /* @text applicationName */ , const string& strPayLoad /* @text strPayLoad */, const string& strQuery /* @text strQuery */, const string& strAddDataUrl /* @text strAddDataUrl */) {};

				// @text onApplicationLaunchRequest
				// @brief Triggered when the cast service receives a launch request from a client with launch params
				// @details This notification is generated when a DIAL/XCast client requests
				// the launch of a registered application. The application should process
				// the supplied launch parameter and initiate the requested casting session.
				// @param applicationName: Registered application name
				// @example applicationName - "YouTube"
				// @param parameter: Application launch string
				// @example parameter - "launch"
				virtual void OnApplicationLaunchRequest(const string& appName /* @text applicationName */ , const string& parameter /* @text parameter */ )  {};

				// @text onApplicationStopRequest
				// @brief Triggered when the cast service receives a stop request from a client
				// @details This notification is generated when a DIAL/XCast client requests
				// termination of a running application. Applications should stop the
				// corresponding application instance, release any associated resources,
				// and update their state so that the XCast service can inform connected
				// client devices of the change.
				// @param applicationName: 	Registered application name
				// @example applicationName - "YouTube"
				// @param applicationId: 	Application instance ID
				// @example applicationId - "12345"
				virtual void OnApplicationStopRequest(const string& appName /* @text applicationName */, const string& appID /* @text applicationId */)  {};

				// @text onApplicationHideRequest
				// @brief Triggered when the cast service receives a hide request from a client
				// @details This notification is generated when a DIAL/XCast client requests
				// that a running application be hidden or suspended without being terminated.
				// Applications should preserve their current execution context and transition
				// to a hidden or background state while remaining resumable.
				// @param applicationName: Registered application name
				// @example applicationName - "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId - "12345"
				virtual void OnApplicationHideRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */ )  {};

				// @text onApplicationStateRequest
				// @brief 	Triggered when the cast service needs an update of the application state
				// @details This notification is generated when the XCast/DIAL service
				// requires the current state of a running application. Applications should
				// respond by reporting their latest execution state so that the XCast
				// service can synchronize status information with connected client devices.
				// @param applicationName: Registered application name
				// @example applicationName - "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId - "12345"
				virtual void OnApplicationStateRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */ )  {};

				// @text onApplicationResumeRequest
				// @brief Triggered when the cast service receives a resume request from a client
				// @details This notification is generated when a DIAL/XCast client requests
				// that a previously suspended or hidden application resume execution.
				// Applications should restore their active state and continue servicing
				// the casting session associated with the specified application instance.
				// @param applicationName: Registered application name
				// @example applicationName - "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId - "12345"
				virtual void OnApplicationResumeRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */)  {};
			};

			virtual Core::hresult Register(IXCast::INotification* sink ) = 0;
			virtual Core::hresult Unregister(IXCast::INotification* sink) = 0;	

			/****************************************SetApplicationState()*****************************/
			// @text setApplicationState
			// @brief Triggered when the cast service receives an application state change notification from a client
			// @details Updates the current execution state of a DIAL/XCast application.
			// This API is used by applications to inform the XCast service about state
			// transitions such as running, stopped, or suspended, allowing the service
			// to maintain accurate status information for connected client devices.
			// @param applicationName: Registered application name
			// @example applicationName - "YouTube"
			// @param state: Application state
			// @example state - RUNNING
			// @param applicationId: Application instance ID
			// @example applicationId - "12345"
			// @param error: Error string, if any
			// @example error - NONE
			// @param success: 	Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - Application state updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update application state.
			virtual Core::hresult SetApplicationState(const string& applicationName /* @text applicationName */, const State& state /* @text state */, const string& applicationId /* @text applicationId */, const ErrorCode& error /* @text error */, XCastSuccess& success /* @out */) = 0;
			/****************************************SetApplicationState()*****************************/

			/****************************************getProtocolVersion()**********************************/
			// @text getProtocolVersion
			// @brief Returns the DIAL protocol version supported by the server
			// @details Retrieves the DIAL protocol version currently supported by the
			// XCast service. This version identifies the protocol capabilities exposed
			// to DIAL/XCast compatible client devices during discovery and application
			// launch operations.
			// @param version: 	DIAL protocol version
			// @example version - "2.2"
			// @param success: 	Whether the request succeeded
			// @example success - true
			// @retval Core::ERROR_NONE - Protocol version retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve protocol version.
			virtual Core::hresult GetProtocolVersion(string &protocolVersion /* @out @text version */, bool &success /* @out */) = 0;
			/***************************************** getProtocolVersion() **********************************/

			/****************************************setManufacturerName()**********************************/
			// @text setManufacturerName
			// @brief Sets the manufacturer name of the device
			// @details Updates the manufacturer name advertised by the XCast/DIAL
			// service. The manufacturer name is included in the device description
			// information returned during device discovery and identification by
			// compatible casting clients.
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			// @example manufacturer - "RDK Management"
			// @param success: 	Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - Manufacturer name updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update manufacturer name.
			virtual Core::hresult SetManufacturerName(const string &manufacturername /* @text manufacturer */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setManufacturerName() **********************************/

			/****************************************getManufacturerName()**********************************/
			// @text getManufacturerName
			// @brief Returns the manufacturer name set by setManufacturerName API
			// @details Retrieves the manufacturer name currently advertised by the
			// XCast/DIAL service. This value is included in the device description
			// information and is made available to client devices during discovery.
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			// @example manufacturer - "RDK Management"
			// @param success: Whether the request succeeded
			// @example success - true
			// @retval Core::ERROR_NONE - Manufacturer name retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve manufacturer name.
			virtual Core::hresult GetManufacturerName(string &manufacturername /* @out @text manufacturer */, bool &success /* @out */) = 0;
			/***************************************** getManufacturerName() *********************************/

			/****************************************setModelName()**********************************/
			// @text setModelName
			// @brief Sets the model name of the device
			// @details Updates the model name advertised by the XCast/DIAL service.
			// The model name is included in the device description information and
			// is used by client devices during discovery and identification.
			// @param model: The Model name of the device which used to update in dd.xml
			// @example model - "X1-4K"
			// @param success: Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - Model name updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update model name.
			virtual Core::hresult SetModelName(const string &modelname /* @text model */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setModelName() **********************************/

			/****************************************getModelName()**********************************/
			// @text getModelName
			// @brief Returns the model name set by setModelName API
			// @details Retrieves the model name currently advertised by the XCast/DIAL
			// service. The model name is included in the device description metadata
			// used by client devices during discovery and identification.
			// @param model: The Model name of the device which used to update in dd.xml
			// @example model - "X1-4K"
			// @param success: Whether the request succeeded
			// @example success - true
			// @retval Core::ERROR_NONE - Model name retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve model name.
			virtual Core::hresult GetModelName(string &modelname /* @out @text model */, bool &success /* @out */) = 0;
			/***************************************** getModelName() *********************************/

			/****************************************setEnabled()**********************************/
			// @text setEnabled
			// @brief Enable or disable XCAST service
			// @details Enables or disables the XCast/DIAL service on the device.
			// When enabled, the device can be discovered by supported casting clients and can accept application
			// @launch requests. When disabled, XCast discovery and casting functionality are unavailable.
			// @param enabled: true for enabled or false for disabled
			// @example enabled - true
			// @param success: 	Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - XCast service state updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update XCast service state.
			virtual Core::hresult SetEnabled(const bool& enabled /* @text enabled */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setEnabled() **********************************/

			/****************************************getEnabled()**********************************/
			// @text getEnabled
			// @brief Reports whether xcast plugin is enabled or disabled
			// @details Retrieves the current operational status of the XCast service.
			// When enabled, the device is available for XCast/DIAL discovery and can
			// accept cast application requests from supported client devices.
			// @param enabled: true for enabled or false for disabled
			// @example enabled - true
			// @param success: Whether the request succeeded
			// @example success - true
			// @retval Core::ERROR_NONE - XCast enabled state retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve XCast enabled state.
			virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;
			/***************************************** getEnabled() **********************************/

			/****************************************setStandbyBehavior()**********************************/
			// @text setStandbyBehavior
			// @brief Sets the expected xcast behavior in standby mode
			// @details Configures how the XCast service behaves when the device enters standby mode.
			// Depending on the selected option, the XCast service can remain available for discovery and
			// casting requests or become inactive while the device is in standby.
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			// @example standbybehavior - ACTIVE
			// @param success: 	Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - Standby behavior updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update standby behavior.
			virtual Core::hresult SetStandbyBehavior(const StandbyBehavior &standbybehavior /* @text standbybehavior */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setStandbyBehavior() *********************************/

			/****************************************getStandbyBehavior()**********************************/
			// @text getStandbyBehavior
			// @brief Return current standby behavior option string set uisng setStandbyBehavior or default value
			// @details Retrieves the current XCast standby behavior configuration.The returned value indicates 
			// whether the XCast service remains active or becomes inactive while the device is in standby mode.
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			// @example standbybehavior - ACTIVE
			// @param success: Whether the request succeeded
			// @example success - true
			// @retval Core::ERROR_NONE - Standby behavior retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve standby behavior.
			virtual Core::hresult GetStandbyBehavior(StandbyBehavior &standbybehavior /* @out @text standbybehavior */, bool &success /* @out */) = 0;
			/***************************************** getStandbyBehavior() *********************************/

			/****************************************setFriendlyName()**********************************/
			// @text setFriendlyName
			// @brief Sets the friendly name of the device
			// @details Updates the friendly device name advertised by the XCast/DIAL
			// service. The friendly name is presented to client devices during device
			// discovery and selection for casting sessions.
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			// @example friendlyname - "Living Room TV"
			// @param success: 	Whether the request succeeded
			// @example success.success - true
			// @retval Core::ERROR_NONE - Friendly name updated successfully.
			// @retval Core::ERROR_GENERAL - Failed to update friendly name.
			virtual Core::hresult SetFriendlyName(const string &friendlyname /* @text friendlyname */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setFriendlyName() **********************************/

			/****************************************getFriendlyName()**********************************/
			// @text getFriendlyName
			// @brief Returns the friendly name set by setFriendlyName API
			// @details Retrieves the current friendly name advertised by the XCast/DIAL
			// service. The friendly name is displayed to client devices when discovering
			// the device for casting purposes.
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			// @example friendlyname - "Living Room TV"
			// @param success - out - Indicates whether the request succeeded.
			// @example success - true
			// @retval Core::ERROR_NONE - Friendly name retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed
			virtual Core::hresult GetFriendlyName(string &friendlyname /* @out @text friendlyname */, bool &success /* @out */) = 0;
			/***************************************** getFriendlyName() *********************************/

			/****************************************registerApplications()**********************************/
			// @text registerApplications
			// @brief Registers an application
			// @param applications: Json array with one or more application details to register
			// @param success: 	Whether the request succeeded
			virtual Core::hresult RegisterApplications(IApplicationInfoIterator* const appInfoList /* @text applications */ , XCastSuccess& success /* @out */) = 0;
			/****************************************registerApplications()**********************************/

			/****************************************unregisterApplications()**********************************/
			// @text unregisterApplications
			// @brief Unregisters an application
			// @param applications: One or more application name to unregister
			// @param success: 	Whether the request succeeded
			virtual Core::hresult UnregisterApplications(IStringIterator* const applications /* @text applications */, XCastSuccess& success /* @out */) = 0;
			/****************************************unregisterApplications()**********************************/
			

		};

	} // Exchange
} // WPEFramework

#endif //__IXCast_H
