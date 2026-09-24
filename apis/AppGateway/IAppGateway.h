/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management.
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
        struct EXTERNAL GatewayContext
        {
                uint32_t requestId;       /* @text requestId */ /* @brief Unique identifier for the request. */ 
                uint32_t connectionId;    /* @text connectionId */ /* @brief Unique identifier for the execution/session context. */
                string appId;             /* @text appId */ /* @brief Application identifier (Firebolt appId). */
                string version;           /* @text version */ /* @brief Version of the gateway request can be semantic version */
        };
        
        // @json 1.0.0 @text:keep
        struct EXTERNAL IAppGatewayResolver : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY
            };

            using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            // @text configure
            // @brief Adds additional Resolution paths to the gateway
            // @details Paths are evaluated in the supplied order, with later paths overriding earlier resolutions.
            // @param paths: Adds set of paths in the order of override to be used by gateway to update the resolutions
            // @example paths: ["/opt/gateway/resolutions", "/etc/gateway/resolutions"]
            // @retval Core::ERROR_NONE: Resolution paths configured successfully
            virtual Core::hresult Configure(IStringIterator *const& paths ) = 0;


            // @json:omit
            // @text resolve
            // @brief Provides support for other thunder plugins to use the resolver for processing requests.
            // @details Resolves a request on behalf of another Thunder plugin and returns the resolved response.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param origin: Origin of the request typically the callsign.
            // @example origin: "org.rdk.Example"
            // @param method: The method to resolve
            // @example method: "exampleMethod"
            // @param params (optional): the parameters to resolve
            // @example params: "{}"
            // @param result: Result of the resolution can be empty
            // @example result: "{}"
            // @retval Core::ERROR_NONE: Request resolved successfully
            virtual Core::hresult Resolve(const GatewayContext& context ,
                                          const string& origin ,
                                          const string& method ,
                                          const string& params /*@opaque */,
                                          string& result /*@out @opaque */) = 0;
        };

        // @text:keep
        struct EXTERNAL IAppGatewayAuthenticator : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_AUTHENTICATOR
            };

            // ---- Authenticate ----
            // @json:omit
            // @text authenticate
            // @brief Authenticate an incoming connection
            // @details Validates the session and returns the application identifier associated with it.
            // @param sessionId: Session Id provided by a given application.
            // @example sessionId: "session-12345"
            // @param appId: Application identifier associated with the session.
            // @example appId: "com.example.app"
            // @retval Core::ERROR_NONE: Connection authenticated successfully
            virtual Core::hresult Authenticate(const string& sessionId , string& appId /* @out */) = 0;

            // ---- GetSessionId ----
            // @json:omit
            // @text getSessionId
            // @brief Get the sessionId for a given application provided to the delegate
            // @details Retrieves the active session identifier associated with the application.
            // @param appId: AppId of the current application.
            // @example appId: "com.example.app"
            // @param sessionId: Session identifier associated with the application.
            // @example sessionId: "session-12345"
            // @retval Core::ERROR_NONE: Session identifier retrieved successfully
            virtual Core::hresult GetSessionId(const string& appId  , string& sessionId /* @out */) = 0;

            // ---- CheckPermissionGroup ----
            // @json:omit
            // @text checkPermissionGroup
            // @brief Check if the application belongs to a given permission group
            // @details Evaluates whether the application has the requested permission group.
            // @param appId: AppId of the current application.
            // @example appId: "com.example.app"
            // @param permissionGroup: Permission group to check
            // @example permissionGroup: "video"
            // @param allowed: Indicates whether the application is allowed the specified permission group.
            // @example allowed: true
            // @retval Core::ERROR_NONE: Permission check completed successfully
            virtual Core::hresult CheckPermissionGroup(const string& appId ,
                                                       const string& permissionGroup ,
                                                       bool& allowed /* @out */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayResponder : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_RESPONDER
            };

            // @json:omit
            // @text respond
            // @brief Provides support for responding to a given context
            // @details Sends a response payload to the client associated with the supplied gateway context.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param payload: the response payload
            // @example payload: "{\"result\":\"ok\"}"
            // @retval Core::ERROR_NONE: Response sent successfully
            virtual Core::hresult Respond(const GatewayContext& context ,
                                          const string& payload /*@opaque */) = 0;

            // @json:omit
            // @text emit
            // @brief Provides support for Emitting Notifications to a given context
            // @details Emits a notification payload to the client associated with the supplied gateway context.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param method: Notification method name
            // @example method: "onExampleEvent"
            // @param payload: the response payload
            // @example payload: "{\"state\":\"ready\"}"
            // @retval Core::ERROR_NONE: Notification emitted successfully
            virtual Core::hresult Emit(const GatewayContext& context ,
                const string& method , const string& payload /*@opaque */) = 0;

            // @json:omit
            // @text request
            // @brief Forwards a Request to the Client. Needed for App Provider Patterns.
            // @details Forwards a request to the client connected through the specified gateway connection.
            // @param connectionId: Connection Id
            // @example connectionId: 2
            // @param id: Request id
            // @example id: 1
            // @param method: Method
            // @example method: "exampleMethod"
            // @param params: Params string object
            // @example params: "{}"
            // @retval Core::ERROR_NONE: Request forwarded successfully
            virtual Core::hresult Request(const uint32_t connectionId , 
                const uint32_t id , const string& method , const string& params /*@opaque */) = 0;

            
            // @json:omit
            // @text getGatewayConnectionContext
            // @brief Gets any connection context parameter like headers, url params
            // @details Reads a value previously associated with the gateway connection context.
            // @param connectionId: Connection Id
            // @example connectionId: 2
            // @param contextKey: Context key
            // @example contextKey: "Authorization"
            // @param contextValue: response value
            // @example contextValue: "Bearer token"
            // @retval Core::ERROR_NONE: Connection context retrieved successfully
            virtual Core::hresult GetGatewayConnectionContext(const uint32_t connectionId ,
                const string& contextKey ,
                string& contextValue /* @out */) = 0;

            // @json:omit
            // @text recordGatewayConnectionContext
            // @brief Allows other Firebolt based plugins to update connection context back to Gateway Socket Connection
            // @details Stores or updates a value in the gateway connection context.
            // @param connectionId: Connection Id
            // @example connectionId: 2
            // @param contextKey: Context Key
            // @example contextKey: "Authorization"
            // @param contextValue: Context Value
            // @example contextValue: "Bearer token"
            // @retval Core::ERROR_NONE: Connection context recorded successfully
            virtual Core::hresult RecordGatewayConnectionContext(const uint32_t connectionId ,
                const string& contextKey ,
                const string& contextValue) = 0;


            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum { ID = ID_APP_GATEWAY_CONNECTION_NOTIFICATION };

                // @brief Notifies App has either started or stopped a connection. App can create multiple connections.
                // @text onAppConnectionChanged
                // @details Notifies observers whenever an application opens or closes a gateway connection.
                // @param appId: App identifier for the application
                // @example appId: "com.example.app"
                // @param connectionId Unique identifier for the connection
                // @example connectionId: 2
                // @param connected true if connection started, false if connection stopped
                // @example connected: true
                // @retval Core::ERROR_NONE: Connection state notification delivered successfully
                virtual void OnAppConnectionChanged(const string& appId, const uint32_t connectionId, const bool connected) {};
            };

            /** Register notification interface */
            virtual Core::hresult Register(INotification* notification) = 0;

            /** Unregister notification interface */
            virtual Core::hresult Unregister(INotification* notification) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayRequestHandler : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_REQUEST_HANDLER
            };

            // @json:omit
            // @text handleAppGatewayRequest
            // @brief Provides support for responding to a given context
            // @details Handles a request received through the AppGateway and produces a response payload.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param method: The method to handle
            // @example method: "exampleMethod"
            // @param payload: the request payload
            // @example payload: "{}"
            // @param result: Response for the given request. Can be empty.
            // @example result: "{\"result\":\"ok\"}"
            // @retval Core::ERROR_NONE: Request handled successfully
            // @retval Core::ERROR_GENERAL: Request could not be handled
            virtual Core::hresult HandleAppGatewayRequest(const GatewayContext& context ,
                                          const string& method ,
                                          const string& payload /*@opaque */,
                                          string& result /*@out @opaque */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayTelemetry : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_TELEMETRY
            };

            // @json:omit
            // @text recordTelemetryEvent
            // @brief Records a telemetry event with gateway context information
            // @details Records an event using the gateway context associated with the application.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param eventName: Name of the telemetry event to record
            // @example eventName: "playbackStarted"
            // @param eventData: JSON string containing telemetry event data
            // @example eventData: "{\"duration\":120}"
            // @retval Core::ERROR_NONE: Event recorded successfully
            // @retval Core::ERROR_GENERAL: Failed to record the event
            // @retval Core::ERROR_UNAVAILABLE: Telemetry service is not available
            // @returns Core::hresult
            virtual Core::hresult RecordTelemetryEvent(const GatewayContext& context /* @text context */,
                                                       const string& eventName /* @text eventName */,
                                                       const string& eventData /* @text eventData */ /*@opaque */) = 0;

            // @json:omit
            // @text recordTelemetryMetric
            // @brief Records a telemetry metric with gateway context information
            // @details Records a numeric metric using the gateway context associated with the application.
            // @param context: Execution context containing requestId, connectionId, appId
            // @example context: {"requestId": 1, "connectionId": 2, "appId": "com.example.app", "version": "1.0.0"}
            // @param metricName: Name of the telemetry metric to record
            // @example metricName: "bufferDuration"
            // @param metricValue: Numeric value of the metric
            // @example metricValue: 250.5
            // @param metricUnit: Unit of measurement for the metric
            // @example metricUnit: "milliseconds"
            // @retval Core::ERROR_NONE: Metric recorded successfully
            // @retval Core::ERROR_GENERAL: Failed to record the metric
            // @retval Core::ERROR_UNAVAILABLE: Telemetry service is not available
            // @returns Core::hresult
            virtual Core::hresult RecordTelemetryMetric(const GatewayContext& context /* @text context */,
                                                        const string& metricName /* @text metricName */,
                                                        const double metricValue /* @text metricValue */,
                                                        const string& metricUnit /* @text metricUnit */) = 0;

        };

        // @text:keep
        struct EXTERNAL IAppGatewayAppSessionGuard : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APP_GATEWAY_APP_SESSION_GUARD
            };

            // @json:omit
            // @text suspendTraffic
            // @brief Suspends all gateway traffic (incoming and outgoing) for a specific
            //        application, regardless of the underlying transport protocol.
            //        While suspended, incoming messages from the application are silently
            //        dropped and outgoing messages destined for the application are discarded
            //        without transmitting. No errors are surfaced to the application.
            // @details Stops incoming and outgoing gateway traffic for the specified application without reporting errors to it.
            // @param appId: Application identifier whose traffic should be suspended
            // @example appId: "com.example.app"
            // @retval Core::ERROR_NONE: Traffic suspended successfully
            // @retval Core::ERROR_GENERAL: Failed to suspend traffic
            // @retval Core::ERROR_UNAVAILABLE: Gateway service is not available
            // @returns Core::hresult
            virtual Core::hresult SuspendTraffic(const string& appId) = 0;

            // @json:omit
            // @text resumeTraffic
            // @brief Resumes gateway traffic for a specific application after a suspension.
            //        After calling this method the gateway will once again process and
            //        forward messages for the application normally.
            // @details Restores normal processing and forwarding of gateway traffic for the specified application.
            // @param appId: Application identifier whose traffic should be resumed
            // @example appId: "com.example.app"
            // @retval Core::ERROR_NONE: Traffic resumed successfully
            // @retval Core::ERROR_GENERAL: Failed to resume traffic
            // @retval Core::ERROR_UNAVAILABLE: Gateway service is not available
            // @returns Core::hresult
            virtual Core::hresult ResumeTraffic(const string& appId) = 0;
        };
    } // namespace Exchange
} // namespace WPEFramework
