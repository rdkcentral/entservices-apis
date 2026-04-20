---
applyTo: "apis/**/I*.h"
---


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
			
			
			
## Struct Naming convention
   ### Requirement:
      - Name of each member of a structure should be in camelCase (unless overridden by any other guidelines For ex., acronyms are always in ALL_CAPS)
	  - For each member of a structure, if the JSON RPC name is different from struct member name, add a @text annotation to indicate the same (ex: appNames /* @text apps */). 
	  - While it is not required to add @text annotation when the JSON RPC name is same as actual struct name, do not treat that as error, if mentioned).
	  - It is always recommended to have @brief annotation to capture a brief explanation for each member of a structure.
        
   ### Example:
		
		struct EXTERNAL HDCPStatus
        {
            bool isConnected /* @text isConnected */ /* @brief Indicates whether a display is connected */;
            bool isHDCPCompliant  /* @text isHDCPCompliant */ /* @brief Indicates whether the display is HDCP compliant */;
            bool isHDCPEnabled  /* @text isHDCPEnabled *//* @brief Indicates whether content is protected */;
            uint32_t hdcpReason  /* @text hdcpReason *//* @brief The HDCP status reason */;
            string supportedHDCPVersion  /* @text supportedHDCPVersion */ /* @brief Supported HDCP protocol version by the host device */;
            string receiverHDCPVersion  /* @text receiverHDCPVersion */ /* @brief Supported HDCP protocol version by the receiver device (display) */;
            string currentHDCPVersion  /* @text currentHDCPVersion */ /* @brief Currently used HDCP protocol version */;
        }
			
				
