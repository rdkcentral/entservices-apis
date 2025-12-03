---
applyTo: "apis/**/I*.h"
---

## JSON RPC Tagging
   ### Requirement:
      If an interface implements JSON-RPC and includes the @json tag, then:
         
         The interface must specify a version (e.g., @json 1.0.0).
   
         The interface must also include the @text:keep tag.

   ### Example:
            /* @json 1.0.0 @text:keep */
            struct EXTERNAL ITextTrack : virtual public Core::IUnknown {
                // ...
            };


 ## Parameter Naming & Tagging
    ### camelCase for JSON RPC:
       - All parameter names in JSON RPC requests/responses SHOULD use camelCase and be valid ASCII strings.
       - Flag as errors any parameter names that are defined in different cases other than camelCase.
       - In camelCase, the first letter must be lowercase, followed by the first letter of each subsequent word in uppercase.
         
    ### @out Tag for Output Parameters:
       - Use @out tag for output parameters.
       - Input parameters are usually defined with const.
       - SHOULD NOT use @in for input parameters.

    ### Example
       - virtual Core::hresult GetPartitionInfo(const string& mountPath, USBStoragePartitionInfo& **partitionInfo** /* @out */) const = 0;
