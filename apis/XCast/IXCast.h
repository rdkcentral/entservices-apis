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
				// @brief Incoming application launch request with extended parameters
				// @details Signals an incoming launch directive from a casting client containing comprehensive launch data including payload, query parameters, and additional data URL. The receiver must parse and route this request to the appropriate application instance.
				// @param applicationName: Registered application name
				// @example applicationName: "YouTube"
				// @param strPayLoad: Payload string to be passed to the 
				// @example strPayLoad: "videoId=abcd1234"
				// @param strQuery: Query string to be appended in launch request
				// @example strQuery: "autoplay=true"
				// @param strAddDataUrl: Additional data URL to be passed to the application
				// @example strAddDataUrl: "https://example.com/additionalData"
				virtual void OnApplicationLaunchRequestWithParam(const string& appName /* @text applicationName */ , const string& strPayLoad /* @text strPayLoad */, const string& strQuery /* @text strQuery */, const string& strAddDataUrl /* @text strAddDataUrl */) {};

				// @text onApplicationLaunchRequest
				// @brief Basic application launch directive received
				// @details Notifies that a casting client has requested application launch with combined launch parameters in a single string. This simpler variant contains app identification and launch arguments in unified format.
				// @param applicationName: Registered application name
				// @example applicationName: "YouTube"
				// @param parameter: Application launch string
				// @example parameter: "videoId=abcd1234&autoplay=true"
				virtual void OnApplicationLaunchRequest(const string& appName /* @text applicationName */ , const string& parameter /* @text parameter */ )  {};

				// @text onApplicationStopRequest
				// @brief Application termination request from client
				// @details Indicates that a casting client has issued a request to stop a running application instance. The notification includes the application name and instance ID to identify which running application should be terminated.
				// @param applicationName: 	Registered application name
				// @example applicationName: "YouTube"
				// @param applicationId: 	Application instance ID
				// @example applicationId: "abcd1234"
				virtual void OnApplicationStopRequest(const string& appName /* @text applicationName */, const string& appID /* @text applicationId */)  {};

				// @text onApplicationHideRequest
				// @brief Request to conceal active application
				// @details Notifies that a casting client has requested to hide or background a currently running application instance. The application continues execution but is not visible to the user.
				// @param applicationName: Registered application name
				// @example applicationName: "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId: "abcd1234"
				virtual void OnApplicationHideRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */ )  {};

				// @text onApplicationStateRequest
				// @brief Query for running application state update
				// @details Requests the current state of a running application instance. The service must retrieve and report the application's operational state in response to this query.
				// @param applicationName: Registered application name
				// @example applicationName: "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId: "abcd1234"
				virtual void OnApplicationStateRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */ )  {};
				
				// @text onApplicationResumeRequest
				// @brief Request to restore backgrounded application
				// @details Signals that a casting client wants to resume a previously hidden or backgrounded application instance. The application should become visible and active again.
				// @param applicationName: Registered application name
				// @example applicationName: "YouTube"
				// @param applicationId: Application instance ID
				// @example applicationId: "abcd1234"
				virtual void OnApplicationResumeRequest(const string& appName /* @text applicationName */ , const string& appID /* @text applicationId */)  {};
			};

			virtual Core::hresult Register(IXCast::INotification* sink ) = 0;
			virtual Core::hresult Unregister(IXCast::INotification* sink) = 0;	

			/****************************************SetApplicationState()*****************************/
			// @text setApplicationState
			// @brief Update application state with status notification
			// @details Communicates a state change for a running application instance back to the system. Includes the application identifier, new state, error code if applicable, and success status for the operation.
			// @param applicationName: Registered application name
			// @example applicationName: "YouTube"
			// @param state: Application state
			// @example state: 0
			// @param applicationId: Application instance ID
			// @example applicationId: "abcd1234"
			// @param error: Error string, if any
			// @example error: "Application not found"
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Application state change notification processed successfully.
			// @retval Core::ERROR_GENERAL - Application state change notification processing failed.
			virtual Core::hresult SetApplicationState(const string& applicationName /* @text applicationName */, const State& state /* @text state */, const string& applicationId /* @text applicationId */, const ErrorCode& error /* @text error */, XCastSuccess& success /* @out */) = 0;
			/****************************************SetApplicationState()*****************************/

			/****************************************getProtocolVersion()**********************************/
			// @text getProtocolVersion
			// @brief Retrieve DIAL protocol version information
			// @details Queries the DIAL protocol version that the server supports and implements. The version is returned as a semantic version string in major.minor format.
			// @param version: 	DIAL protocol version
			// @example version: "1.7"
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Protocol version retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve the protocol version.
			virtual Core::hresult GetProtocolVersion(string &protocolVersion /* @out @text version */, bool &success /* @out */) = 0;
			/***************************************** getProtocolVersion() **********************************/

			/****************************************setManufacturerName()**********************************/
			// @text setManufacturerName
			// @brief Configure device manufacturer identity
			// @details Updates the manufacturer field in the device description (dd.xml) file with the provided manufacturer identifier. This value is exposed to casting clients for device identification purposes.
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			// @example manufacturer: "MyCompany"
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Manufacturer name set successfully.
			// @retval Core::ERROR_GENERAL - Failed to set the manufacturer name.
			virtual Core::hresult SetManufacturerName(const string &manufacturername /* @text manufacturer */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setManufacturerName() **********************************/

			/****************************************getManufacturerName()**********************************/
			// @text getManufacturerName
			// @brief Query current device manufacturer
			// @details Retrieves the manufacturer name currently stored in the device description (dd.xml) file. This reflects the last value set via setManufacturerName or the factory default if not yet configured.
			// @param manufacturer: The Manufacturer name of the device which used to update in dd.xml
			// @example manufacturer: "MyCompany"
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Manufacturer name retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve the manufacturer name.
			virtual Core::hresult GetManufacturerName(string &manufacturername /* @out @text manufacturer */, bool &success /* @out */) = 0;
			/***************************************** getManufacturerName() *********************************/

			/****************************************setModelName()**********************************/
			// @text setModelName
			// @brief Update device model identifier
			// @details Assigns a model name to the device and persists it in the device description (dd.xml) file. Casting clients use this identifier to recognize and manage device capabilities.
			// @param model: The Model name of the device which used to update in dd.xml
			// @example model: "MyModel"
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Model name set successfully.
			// @retval Core::ERROR_GENERAL - Failed to set the model name.
			virtual Core::hresult SetModelName(const string &modelname /* @text model */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setModelName() **********************************/

			/****************************************getModelName()**********************************/
			// @text getModelName
			// @brief Retrieve configured device model
			// @details Fetches the device model name from the device description (dd.xml) file. Returns the previously configured model identifier set via setModelName, or the factory default if unconfigured.
			// @param model: The Model name of the device which used to update in dd.xml
			// @example model: "MyModel"
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - Model name retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve the model name.
			virtual Core::hresult GetModelName(string &modelname /* @out @text model */, bool &success /* @out */) = 0;
			/***************************************** getModelName() *********************************/

			/****************************************setEnabled()**********************************/
			// @text setEnabled
			// @brief Control XCAST service activation state
			// @details Activates or deactivates the XCAST service. When disabled, all incoming client requests are rejected and the service remains dormant. Enable to activate service functionality.
			// @param enabled: true for enabled or false for disabled
			// @example enabled: true
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - XCAST service enabled/disabled successfully.
			// @retval Core::ERROR_GENERAL - Failed to enable/disable XCAST service.
			virtual Core::hresult SetEnabled(const bool& enabled /* @text enabled */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setEnabled() **********************************/

			/****************************************getEnabled()**********************************/
			// @text getEnabled
			// @brief Check XCAST service operational status
			// @details Queries the current operational state of the XCAST service. Returns whether the service is active and accepting client requests, or inactive and rejecting all requests.
			// @param enabled: true for enabled or false for disabled
			// @example enabled: true
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE - XCAST service enabled/disabled status retrieved successfully.
			// @retval Core::ERROR_GENERAL - Failed to retrieve XCAST service enabled/disabled
			virtual Core::hresult GetEnabled(bool &enabled /* @out @text enabled */, bool &success /* @out */) = 0;
			/***************************************** getEnabled() **********************************/

			/****************************************setStandbyBehavior()**********************************/
			// @text setStandbyBehavior
			// @brief Configure XCAST service standby mode behavior
			// @details Defines how the XCAST service should operate when the device enters standby mode. Active mode allows continued service operation for casting, while inactive mode suspends the service to conserve power.
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			// @example standbybehavior: active
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult SetStandbyBehavior(const StandbyBehavior &standbybehavior /* @text standbybehavior */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setStandbyBehavior() *********************************/

			/****************************************getStandbyBehavior()**********************************/
			// @text getStandbyBehavior
			// @brief Retrieve current standby mode configuration
			// @details Returns the standby behavior setting currently in effect. The value reflects either a previously configured setting via setStandbyBehavior or the system default. Indicates whether the service remains active or suspended during standby.
			// @param standbybehavior: whether to remain active or inactive during standby mode (must be one of the following: active, inactive)
			// @example standbybehavior: active
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult GetStandbyBehavior(StandbyBehavior &standbybehavior /* @out @text standbybehavior */, bool &success /* @out */) = 0;
			/***************************************** getStandbyBehavior() *********************************/

			/****************************************setFriendlyName()**********************************/
			// @text setFriendlyName
			// @brief Assign user-readable device name
			// @details Sets a human-friendly name for the device that will be displayed in casting client interfaces and device discovery lists. This name enhances user experience by providing an identifiable label.
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult SetFriendlyName(const string &friendlyname /* @text friendlyname */, XCastSuccess& success /* @out */) = 0;
			/***************************************** setFriendlyName() **********************************/

			/****************************************getFriendlyName()**********************************/
			// @text getFriendlyName
			// @brief Fetch device display name
			// @details Obtains the friendly name currently assigned to the device. Returns the value previously configured via setFriendlyName, which is shown to users in casting client applications.
			// @param friendlyname: The friendly name of the device which used to display on the client device list
			// @param success: Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult GetFriendlyName(string &friendlyname /* @out @text friendlyname */, bool &success /* @out */) = 0;
			/***************************************** getFriendlyName() *********************************/

			/****************************************registerApplications()**********************************/
			// @text registerApplications
			// @brief Register one or more castable applications
			// @details Registers applications that can be launched via casting. Each application entry specifies its name, launch prefixes, CORS policy, launch parameters, and whether it can be stopped by remote clients.
			// @param applications: Json array with one or more application details to register
			// @example applications: [{"appName":"YouTube","prefixes":"yt","cors":"*","query":"autoplay=true","payload":"videoId=abcd1234","allowStop":true}]
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult RegisterApplications(IApplicationInfoIterator* const appInfoList /* @text applications */ , XCastSuccess& success /* @out */) = 0;
			/****************************************registerApplications()**********************************/

			/****************************************unregisterApplications()**********************************/
			// @text unregisterApplications
			// @brief Deregister applications from casting support
			// @details Removes one or more previously registered applications from the castable application list. The application names must match registered application names or their prefixes.
			// @param applications: One or more application name to unregister
			// @example applications: ["YouTube","yt"]
			// @param success: 	Whether the request succeeded
			// @example success: true
			// @retval Core::ERROR_NONE: Indicates success
			// @retval Core::ERROR_GENERAL: Indicates failure
			virtual Core::hresult UnregisterApplications(IStringIterator* const applications /* @text applications */, XCastSuccess& success /* @out */) = 0;
			/****************************************unregisterApplications()**********************************/
			

		};

	} // Exchange
} // WPEFramework

#endif //__IXCast_H
