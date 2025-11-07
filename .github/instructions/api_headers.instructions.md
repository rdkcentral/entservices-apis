---
applyTo: "apis/**/I*.h"
---

# Interface Header Specification Instructions(apis/**/I*.h)
This document details the guidelines for defining interface headers for RDK Entertainment Services APIs, to ensure consistency and compliance with Thunder Plugins Interface standards. These guidelines have to be taken into account for each review.


1. Thunder Plugins Interface Compliance:
   
   ### Requirement:
      All interface headers MUST adhere to below Thunder Plugins Interface Guidelines.
   ### Implementation:
      The APIs SHOULD be implemented as Thunder Plugins within RDK Entertainment Services middleware.

2. JSON RPC Tagging
   ### Requirement:
      If an interface implements JSON-RPC and includes the @json tag, then:
         
         The interface must specify a version (e.g., @json 1.0.0).
   
         The interface must also include the @text:keep tag.

   ### Example:
            /* @json 1.0.0 @text:keep */
            struct EXTERNAL ITextTrack : virtual public Core::IUnknown {
                // ...
            };

4. Notification Interfaces
   ### Requirement:
      - Notification interfaces MUST provide default (empty) implementations for notification methods;
      - Do NOT use pure virtual methods.
      - A single method can be defined in more than one line for code readability.
   ### Example:
      /* @event */
      struct EXTERNAL INotification : virtual public Core::IUnknown {
          // ...
          virtual void OnFontColorChanged(const string& color) {}; // Default implementation
          // ...
      };
   ### Incorrect Example:
      /* @event */
      struct EXTERNAL INotification : virtual public Core::IUnknown {
          // ...
          virtual void OnFontColorChanged(const string& color) = 0; // Pure virtual method
          // ...
      };


5.  Method Return Type
    ### Requirement:
       - All methods MUST return Core::hresult.
       - Notification Methods need not to return Core::hresult.
    ### Example:
       virtual Core::hresult BindDriver(const string& deviceName) const = 0;

6.  API & Event Naming for Interface and JSON RPC
    ### PascalCase in Interface Header and COMRPC:
       - Method & Event names SHOULD be in Pascal Case.
    
    ### Example
       virtual Core::hresult **BindDriver**(const string& deviceName) const = 0;
    
       virtual void **OnDevicePluggedIn**(const USBDevice& device) {}

    ### camelCase for JSON RPC (using @text annotation):
       - API & Event names SHOULD be defined in camel case for json-rpc definition via Thunder Framework tags.
    ### Example
       **// @text bindDriver**
    
      virtual Core::hresult BindDriver(const string& deviceName) const = 0;
      
      **// @text onDevicePluggedIn**
    
      virtual void OnDevicePluggedIn(const USBDevice& device) {};

 7. Parameter Naming & Tagging
    ### camelCase for JSON RPC:
       - All parameter names in JSON RPC requests/responses SHOULD use camelCase and be valid ASCII strings.
       - Error out the parameter names that are defined in different cases other than camelCase.
       - camelCase is the first letter must be the small-case followed by the first-letter of each words in capital case.
         
    ### @out Tag for Output Parameters:
       - Use @out tag for output parameters.
       - Input parameters are usually defined with const.
       - SHOULD NOT use @in for input parameters.

    ### Example
       - virtual Core::hresult GetPartitionInfo(const string& mountPath, USBStoragePartitionInfo& **partitionInfo** /* @out */) const = 0;
   
8. Enum Naming
   ### Requirement:
      - Enum names SHOULD be ALL_UPPER_SNAKE_CASE.
      - Enum names SHOULD NOT contain any special characters other than underscore.
        
   ### Example:
      enum USBStorageMountFlags : uint8_t {
          READ_ONLY  = 1,  // READ ONLY
          READ-WRITE = 2   // READ WRITE
      };

      #### Exception:
            Standardized names (e.g., kHz) MAY be exempt.

9. Getter/Setter Naming
   ### Requirement:
      - All the getter and setter method names should be in PascalCase.
      - All the getter and setter method names should be in camelCase when defining via annotations/tags.
   ### Example:
      virtual Core::hresult GetDefaultInterface(/* ... */) const = 0;
      virtual Core::hresult SetDefaultInterface(/* ... */) = 0;

10. Event Naming Convention
    ### Format:
       - Event names SHOULD follow on[Object][Action].
       - Event names not starting with on and not following this naming convention order SHOULD BE FLAGGED AS ERRORS during code review.
         
          - Object: Noun giving context.
          - Action: Verb (present/past tense for timing).
    ### Interface Header Example (PascalCase):
         struct EXTERNAL INotification : virtual public Core::IUnknown {
          // ...
          virtual void **OnAppResumed**() {}
          // ...
         }

           struct EXTERNAL INotification : virtual public Core::IUnknown {
             // ...
             virtual void **OnAppResuming**() {}
             //...
           }

   ### JSON RPC Example (camelCase via annotation):
         struct EXTERNAL INotification : virtual public Core::IUnknown {
            // ...
            // @text **onAppResumed**
            virtual void OnAppResumed() {};
            // ...
         }

         struct EXTERNAL INotification : virtual public Core::IUnknown {
             // ...
            // @text **onAppResuming**
             virtual void OnAppResuming() {};
            // ...
         }

11. Acronym Capitalization
    ### Requirement:
       - Acronyms SHOULD be fully capitalized.

    ### Example:
       virtual Core::hresult SetHDMIEnabled(bool enabled) = 0;
       // NOT: SetHdmiEnabled


12. ### Documentation Tags Guidelines
      To ensure consistency and clarity in interface documentation, each method, event, and struct member must be annotated using the following tags. If any methods/events/struct members have not been annotated with the tags below, then they should be flagged as an error during PR review.
    
       ### Required Tags:
    
          @brief — A concise description of the purpose or behavior.
    
          @param — Description of each parameter, including its name and purpose.
    
          @retval <ErrorCode>: <Description> — Used to describe each return code associated with a function or property. These descriptions will be included in the generated markdown documentation.
    
          @details (optional) — Additional information or extended explanation.

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
                const string& applicationName /* @in @text applicationName */,
                const State& state /* @in @text state */,
                const string& applicationId /* @in @text applicationId */,
                const ErrorCode& error /* @in @text error */
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
                   string appName /* @text names */ 
                                /* @brief Group of acceptable names for a related application. Application name in request URI must have exact match to one of the names. Otherwise, matching prefix is needed. If the application name in request URI does not match any names or prefixes, then the request shall fail */;
                   
                   string prefixes /* @text prefixes */ 
                                   /* @brief If the application name in request URI does not match the list of names, it must contain one of the prefixes. If the application name in request URI does not match any names or prefixes, then the request shall fail */;
                   
                   string cors /* @text cors */ 
                               /* @brief A set of origins allowed for the application. This must not be empty */;
                   
                   string query /* @text query */ 
                                /* @brief Query string that needs to be appended in launch request */;
                   
                   string payload /* @text payload */ 
                                  /* @brief Optional payload string that needs to be appended in launch request */;
                   
                   int allowStop /* @text allowStop */ 
                                 /* @brief Indicates whether the application (matching name list or prefix list) is allowed to stop (no PID presence) after launch */;
               };
    
