---
applyTo: "apis/**/I*.h"
---

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



## Notification Naming for Interface and JSON RPC

    ### PascalCase in Interface Header and COMRPC:
       - Notification names SHOULD be in Pascal Case.
    
    ### Example    
       virtual void **OnDevicePluggedIn**(const USBDevice& device) {}

    ### camelCase for JSON RPC (using @text annotation):
       - Notification names SHOULD be defined in camel case for json-rpc definition via Thunder Framework tags.
	   
    ### Example
      **// @text onDevicePluggedIn**
      virtual void OnDevicePluggedIn(const USBDevice& device) {};



## Notification Name Formatting 
    ### Format:
       - Notification names SHOULD follow on[Object][Action].
       - Notification names not starting with on and not following this naming convention order should be flagged as errors during code review.
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
