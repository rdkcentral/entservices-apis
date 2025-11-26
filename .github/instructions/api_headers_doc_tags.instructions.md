---
applyTo: "apis/**/I*.h"
---

## Documentation Tags Guidelines
      To ensure consistency and clarity in interface documentation, each method, event, and struct member must be annotated using the following tags. If any methods/events/struct members have not been annotated with the tags below, then they should be flagged as an error during PR review.
    
       ### Required Tags:
    
        - @brief — A concise description of the purpose or behavior.
        - @param — Description of each parameter, including its name and purpose.
        - @retval <ErrorCode>: <Description> — Used to describe each return code associated with a function or property. These descriptions will be included in the generated markdown documentation.
        - @details (optional) — Additional information or extended explanation.

      ### Method Example:
            // @text onApplicationStateChanged
            // @brief Triggered when the cast service receives an application state change notification from a client
            // @param applicationName: Registered application name
            // @param state: Application state
            // @param applicationId: Application instance ID
            // @param error: Error string, if any
            // @retval ErrorCode::NONE: Indicates successful state change
            // @retval ErrorCode::FORBIDDEN: Operation is not permitted
            // @retval ErrorCode::UNAVAILABLE: Requested resource is not available
            // @retval ErrorCode::INVALID: Provided state is not recognized
            // @retval ErrorCode::INTERNAL: Internal server error occurred
            virtual Core::hresult ApplicationStateChanged(
                const string& applicationName /* @text applicationName */,
                const State& state /* @text state */,
                const string& applicationId /* @text applicationId */,
                const ErrorCode& error /* @text error */
            ) = 0;

     ### Event Example:
             struct EXTERNAL INotification : virtual public Core::IUnknown {
             // @text onApplicationLaunchRequest
             // @brief Triggered when the cast service receives a launch request from a client with launch params
             // @param applicationName: Registered application name
             // @param strPayLoad: Payload string to be passed to the application
             // @param strQuery: Query string to be appended in launch request
             // @param strAddDataUrl: Additional data URL to be passed to the application
             virtual void OnApplicationLaunchRequestWithLaunchParam(
                 const string& appName /* @text applicationName */,
                 const string& strPayLoad /* @text strPayLoad */,
                 const string& strQuery /* @text strQuery */,
                 const string& strAddDataUrl /* @text strAddDataUrl */
             ) {}
         };

      ### Struct Member Example:
             struct EXTERNAL ApplicationInfo {
                   // @brief Group of acceptable names for a related application. Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail
                   string appName /* @text names */;
                   // @brief If the application name in request URI does not match the list of names, it must contain one of the prefixes. If the application name in request URI does not match any names or prefixes, then the request shall fail
                   string prefixes /* @text prefixes */;
                   // @brief A set of origins allowed for the application. This must not be empty
                   string cors /* @text cors */;
                   // @brief Query string that needs to be appended in launch request
                   string query /* @text query */;
                   // @brief Optional payload string that needs to be appended in launch request
                   string payload /* @text payload */;
                   // @brief Indicates whether the application (matching name list or prefix list) is allowed to stop (no PID presence) after launch
                   int allowStop /* @text allowStop */;
               };
