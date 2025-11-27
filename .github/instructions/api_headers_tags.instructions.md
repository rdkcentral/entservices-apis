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


 ## Naming & Tagging
    ### camelCase for JSON RPC:
       - All parameter names in JSON RPC requests/responses SHOULD use camelCase and be valid ASCII strings.Flag as errors any parameter names that are defined in different cases other than camelCase.
       - Name of each member of a structure should be in camelCase (unless overridden by any other guidelines later in this document. For ex., acronyms are always in ALL_CAPS)
       - For each struct member/method parameter, if the JSON RPC name is different from struct member name or method parameter name, add a @text annotation to indicate the same (ex: appNames /* @text apps */). 
       - While it is not required to add @text annotation when the JSON RPC name is same as actual struct/parameter name, do not treat that as error, if mentioned).
       - It is always recommended to have @brief annotation to capture a brief explanation for each struct member and method paramerters.
       - In camelCase, the first letter must be lowercase, followed by the first letter of each subsequent word in uppercase.
         
    ### @out Tag for Output Parameters:
       - Use @out tag for output parameters.
       - Input parameters are usually defined with const.
       - SHOULD NOT use @in for input parameters.

    ### Example
       - virtual Core::hresult GetPartitionInfo(const string& mountPath, USBStoragePartitionInfo& **partitionInfo** /* @out */) const = 0;
