---
applyTo: "apis/**/I*.h"
---
      
# Interface Header Specification Instructions(apis/**/I*.h)
This document details the guidelines for defining interface headers for RDK Entertainment Services APIs, to ensure consistency and compliance with Thunder Plugins Interface standards. These guidelines have to be taken into account for each review. All interface headers MUST adhere to below Thunder Plugins Interface Guidelines.


## Notification Interfaces
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

##  Method Return Type
    ### Requirement:
       - All methods MUST return Core::hresult.
       - Notification Methods need not return Core::hresult.
    ### Example:
       virtual Core::hresult BindDriver(const string& deviceName) const = 0;

##  API & Event Naming for Interface and JSON RPC
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
   
## Enum Naming
   ### Requirement:
      - Enum names SHOULD be ALL_UPPER_SNAKE_CASE.
      - Enum names SHOULD NOT contain any special characters other than underscore.
        
   ### Example:
      enum USBStorageMountFlags : uint8_t {
          READ_ONLY  = 1,  // READ ONLY
          READ_WRITE = 2   // READ WRITE
      };
      #### Exception:
            Standardized names (e.g., kHz) MAY be exempt.

## Getter/Setter Naming
   ### Requirement:
      - API getters SHALL always start with get and Setters SHALL always start with set.
      - All the getter and setter method names should be in PascalCase.
      - All the getter and setter method names should be in camelCase when defining via @text annotations/tags.
   ### Example:
         // @text getDefaultInterface
         virtual Core::hresult GetDefaultInterface(/* ... */) const = 0; 
         // @text setDefaultInterface
         virtual Core::hresult SetDefaultInterface(/* ... */) = 0;

## Event Naming Convention
    ### Format:
       - Event names SHOULD follow on[Object][Action].
       - Event names not starting with on and not following this naming convention order should be flagged as errors during code review.
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

## Acronym Capitalization
    ### Requirement:
       - Acronyms SHOULD be fully capitalized.

    ### Example:
       virtual Core::hresult SetHDMIEnabled(bool enabled) = 0;
       // NOT: SetHdmiEnabled
