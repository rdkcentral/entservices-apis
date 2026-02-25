//
// IApplicationService.h
// Thunder RPC interface definitions for AS Services
// Uses Thunder header-based code generation approach
//
// USAGE:
//   Run Thunder ProxyStubGenerator or JsonGenerator on this file to generate:
//   - JSON-RPC proxy classes (client-side for asproxy)
//   - JSON-RPC stub registration (server-side for services)
//   - Marshalling/unmarshalling code
//

#pragma once

#include "Module.h"

namespace WPEFramework
{
    namespace Exchange
    {

        // @json 1.0.0 @text:keep
        // @brief Request interface for HTTP-style requests
        // This interface handles GET/POST/DELETE requests similar to HTTP REST APIs
        struct EXTERNAL IApplicationServiceRequest : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_REQUEST
            };

            // @brief Process an HTTP-style request
            // @param flags Request type flags: GET=0x01, POST=0x02, DELETE=0x04
            // @param url Request URL path (e.g., "/as/network/ipconfig/settings")
            // @param headers HTTP headers as JSON object string
            // @param queryParams Query parameters as JSON object string
            // @param body Request body (for POST requests)
            // @param code HTTP status code (output)
            // @param responseHeaders Response headers as JSON object string (output)
            // @param responseBody Response body as JSON string (output)
            // @return Error code: ERROR_NONE on success
            // @text:request
            virtual Core::hresult Request(
                const uint32_t flags,
                const string &url,
                const string &headers,
                const string &queryParams,
                const string &body,
                uint32_t &code /* @out */,
                string &responseHeaders /* @out */,
                string &responseBody /* @out */) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief Configuration interface
        // Returns service configuration JSON
        struct EXTERNAL IApplicationServiceConfig : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_CONFIG
            };

            // @brief Get service configuration
            // @param config Service configuration as JSON string (output)
            // @return Error code: ERROR_NONE on success
            // @text:config
            virtual Core::hresult Config(string &config /* @out */) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief Listener registration interface
        // Manages WebSocket, Updates, and System Status listeners
        struct EXTERNAL IApplicationServiceListener : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_LISTENER
            };

            // @brief Register WebSocket listener
            // @param url WebSocket URL to monitor
            // @param clientId Client identifier
            // @param listenerId Generated listener ID (output)
            // @return Error code: ERROR_NONE on success
            // @text:registerWebSocketListener
            virtual Core::hresult RegisterWebSocketListener(
                const string &url,
                const string &clientId,
                string &listenerId /* @out */) = 0;

            // @brief Unregister WebSocket listener
            // @param listenerId Listener ID to unregister
            // @return Error code: ERROR_NONE on success
            // @text:unregisterWebSocketListener
            virtual Core::hresult UnregisterWebSocketListener(
                const string &listenerId) = 0;

            // @brief Register Updates listener
            // @param url URL to monitor for updates
            // @param clientId Client identifier
            // @param listenerId Generated listener ID (output)
            // @return Error code: ERROR_NONE on success
            // @text:registerUpdatesListener
            virtual Core::hresult RegisterUpdatesListener(
                const string &url,
                const string &clientId,
                string &listenerId /* @out */) = 0;

            // @brief Unregister Updates listener
            // @param listenerId Listener ID to unregister
            // @return Error code: ERROR_NONE on success
            // @text:unregisterUpdatesListener
            virtual Core::hresult UnregisterUpdatesListener(
                const string &listenerId) = 0;

            // @brief Register System Status listener
            // @param clientId Client identifier
            // @param listenerId Generated listener ID (output)
            // @return Error code: ERROR_NONE on success
            // @text:registerSysStatusListener
            virtual Core::hresult RegisterSysStatusListener(
                const string &clientId,
                string &listenerId /* @out */) = 0;

            // @brief Unregister System Status listener
            // @param listenerId Listener ID to unregister
            // @return Error code: ERROR_NONE on success
            // @text:unregisterSysStatusListener
            virtual Core::hresult UnregisterSysStatusListener(
                const string &listenerId) = 0;

            // @event
            struct EXTERNAL INotification : virtual public Core::IUnknown
            {
                enum
                {
                    ID = ID_APPLICATION_SERVICE_LISTENER_NOTIFICATION
                };

                // @brief WebSocket update notification
                // @param url WebSocket URL that sent update
                // @param message Update message content
                // @text:onNotifyWebSocketUpdate
                virtual void OnNotifyWebSocketUpdate(const string &url, const string &message) = 0;

                // @brief HTTP update notification
                // @param url HTTP endpoint that sent update
                // @param code HTTP status code
                // @text:onNotifyHttpUpdate
                virtual void OnNotifyHttpUpdate(const string &url, const uint32_t code) = 0;

                // @brief System status update notification
                // @param status Status message as JSON string
                // @text:onNotifySysStatusUpdate
                virtual void OnNotifySysStatusUpdate(const string &status) = 0;
            };
            virtual Core::hresult Register(IApplicationServiceListener::INotification *notification) = 0;
            virtual Core::hresult Unregister(IApplicationServiceListener::INotification *notification) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief System information interface
        // Returns aggregated system information from all services
        struct EXTERNAL IApplicationServiceSystemInfo : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_SYSTEMINFO
            };

            // @brief Get system information
            // @param info System information as JSON string (output)
            // @return Error code: ERROR_NONE on success
            // @text:getSystemInfo
            virtual Core::hresult GetSystemInfo(string &info /* @out */) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief System settings interface
        // Get/Set system-wide settings
        struct EXTERNAL IApplicationServiceSystemSettings : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_SYSTEMSETTINGS
            };

            // @brief Get system setting value
            // @param name Setting name
            // @param value Setting value (output)
            // @return Error code: ERROR_NONE on success, ERROR_UNKNOWN_KEY if not found
            // @text:getSystemSetting
            virtual Core::hresult GetSystemSetting(
                const string &name,
                string &value /* @out */) = 0;

            // @brief Set system setting value
            // @param name Setting name
            // @param value Setting value
            // @return Error code: ERROR_NONE on success
            // @text:setSystemSetting
            virtual Core::hresult SetSystemSetting(
                const string &name,
                const string &value) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief Test preferences interface
        // Get/Set test preferences (requires PIN for set operations)
        struct EXTERNAL IApplicationServiceTestPreferences : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_TESTPREFS
            };

            // @brief Get test preference value
            // @param name Preference name
            // @param value Preference value (output)
            // @return Error code: ERROR_NONE on success, ERROR_UNKNOWN_KEY if not found
            // @text:getTestPreference
            virtual Core::hresult GetTestPreference(
                const string &name,
                string &value /* @out */) = 0;

            // @brief Set test preference value
            // @param name Preference name
            // @param value Preference value
            // @param pin Security PIN
            // @return Error code: ERROR_NONE on success, ERROR_PRIVILEGED_REQUEST if PIN invalid
            // @text:setTestPreference
            virtual Core::hresult SetTestPreference(
                const string &name,
                const string &value,
                const uint32_t pin) = 0;
        };

        // @json 1.0.0 @text:keep
        // @brief Diagnostics interface
        // Get/Set diagnostic logging contexts
        struct EXTERNAL IApplicationServiceDiagnostics : virtual public Core::IUnknown
        {
            enum
            {
                ID = ID_APPLICATION_SERVICE_DIAGNOSTICS
            };

            // @brief Get diagnostic contexts
            // @param contexts Diagnostic contexts as JSON string (output)
            // @return Error code: ERROR_NONE on success
            // @text:getDiagContexts
            virtual Core::hresult GetDiagContexts(string &contexts /* @out */) = 0;

            // @brief Set diagnostic contexts
            // @param contexts Diagnostic contexts as JSON string
            // @param updated Number of contexts updated (output)
            // @return Error code: ERROR_NONE on success
            // @text:setDiagContexts
            virtual Core::hresult SetDiagContexts(
                const string &contexts,
                uint32_t &updated /* @out */) = 0;

            // @brief Test/Debug: Trigger WebSocket event manually
            // @param url Event URL
            // @param message Event message
            // @return Error code: ERROR_NONE on success
            // @text:testTriggerWebSocketEvent
            virtual Core::hresult TestTriggerWebSocketEvent(
                const string &url,
                const string &message) = 0;

            // @brief Test/Debug: Trigger HTTP event manually
            // @param url Event URL
            // @param code HTTP status code
            // @return Error code: ERROR_NONE on success
            // @text:testTriggerHttpEvent
            virtual Core::hresult TestTriggerHttpEvent(
                const string &url,
                uint32_t code) = 0;

            // @brief Test/Debug: Trigger System Status event manually
            // @param status Status message
            // @return Error code: ERROR_NONE on success
            // @text:testTriggerSysStatusEvent
            virtual Core::hresult TestTriggerSysStatusEvent(
                const string &status) = 0;
        };

    } // namespace Exchange
} // namespace WPEFramework

// NOTE: Backward compatibility helpers have been moved to ASServiceThunderHelpers.h
// Include that header if you need RequestParams, RequestResult, or convenience type aliases.
