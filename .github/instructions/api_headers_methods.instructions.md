---
applyTo: "apis/**/I*.h"
---

##  Method Return Type
   ### Requirement:
      - All methods MUST return Core::hresult.
      - Notification Methods MUST not return anything (i.e., return type MUST be void).
   ### Example:
      virtual Core::hresult BindDriver(const string& deviceName) const = 0;
      virtual void OnAudioDescriptionChanged(const bool enabled) {};
	   

##  API & Notification Naming for Interface and JSON RPC
   ### PascalCase in Interface Header and COMRPC:
      - Method names SHOULD be in Pascal Case.
    
   ### Example
      virtual Core::hresult **BindDriver**(const string& deviceName) const = 0;
    

   ### camelCase for JSON RPC (using @text annotation):
      - API & Event names SHOULD be defined in camel case for json-rpc definition via Thunder Framework tags.
	   
   ### Example
      **// @text bindDriver**
      virtual Core::hresult BindDriver(const string& deviceName) const = 0;


## Getter/Setter Method Naming
   ### Requirement:
      - API getters SHALL always start with get and Setters SHALL always start with set.
      - All the getter and setter method names should be in PascalCase.
      - All the getter and setter method names should be in camelCase when defining via @text annotations/tags.
   ### Example:
      // @text getDefaultInterface
      virtual Core::hresult GetDefaultInterface(/* ... */) const = 0; 
      // @text setDefaultInterface
      virtual Core::hresult SetDefaultInterface(/* ... */) = 0;
		 
		 


## Parameter Naming & Tagging
   ### camelCase for JSON RPC:
      - All parameter names in JSON RPC requests/responses SHOULD use camelCase and be valid ASCII strings.Flag as errors any parameter names that are defined in different cases other than camelCase.
	   - For each parameter name , if the JSON RPC name is different from actual parameter name, add a @text annotation to indicate the same (ex: appNames /* @text apps */). 
	   - While it is not required to add @text annotation when the JSON RPC name is same as actual struct name, do not treat that as error, if mentioned).
	   - It is always recommended to have @param annotation to capture a brief explanation about the param.
       - In camelCase, the first letter must be lowercase, followed by the first letter of each subsequent word in uppercase.
         
   ### @out Tag for Output Parameters:
      - Use @out tag for output parameters.
      - Input parameters are usually defined with const.
      - SHOULD NOT use @in for input parameters.

   ### Example
      /**********************getHDCPStatus() - start****************************/
		// @text getHDCPStatus
		// @brief Returns HDCP-related data.
		// @param HDCPStatus: Contains HDCP-related data as separate properties
		// @param success: Indicates whether the operation was successful
		virtual Core::hresult GetHDCPStatus(HDCPStatus& hdcpStatus /* @out @text HDCPStatus*/,bool& success  /* @out */) = 0;           
		/**********************getHDCPStatus() - end******************************/




## Special considerations for Enum and String parameters
   ### Always use "enum" type instead of string when the possible values are known and limited:
      - Use Enum type for parameters that have a predefined set of possible values.
      - Use string type only when the parameter can accept a wide range of values or is not limited to a specific set.
         
   ### Example 1: Enum for known set of values (in structs)
      enum USBStorageMountFlags : uint8_t
      {
         READ_ONLY      = 1  /* @text READ_ONLY */,
         READ_WRITE     = 2  /* @text READ_WRITE */
      };

      enum USBStorageFileSystem : uint8_t
      {
         UNKNOWN        = 0  /* @text UNKNOWN file system */,
         MSDOS          = 1  /* @text MSDOS file system driver  */,
         VFAT           = 2  /* @text VFAT file system driver  */,
         EXT4           = 3  /* @text EXT4 file system */,
         EXFAT          = 4  /* @text EXFAT file system */
      };
      
      struct USBStorageMountInfo
      {
         USBStorageMountFlags    mountFlags     /* @brief Mount flags used for mounting the device / partition */;
         USBStorageFileSystem    fileSystem     /* @brief file system of the partition */;
      };

   ### Example 2: Enum for known set of values (in method / Notification parameters)
      enum State : uint8_t {
         VALIDATION_FAILED  = 1 /* @text VALIDATION_FAILED */,
         FLASHING_STARTED   = 2 /* @text FLASHING_STARTED */,
         FLASHING_FAILED    = 3 /* @text FLASHING_FAILED */,
         FLASHING_SUCCEEDED = 4 /* @text FLASHING_SUCCEEDED */
      };

      enum SubState : uint8_t {
         NOT_APPLICABLE = 0 /* @text NOT_APPLICABLE */,
         FIRMWARE_NOT_FOUND = 1 /* @text FIRMWARE_NOT_FOUND */,
         FIRMWARE_INVALID = 2 /* @text FIRMWARE_INVALID */,
         FIRMWARE_OUTDATED = 3 /* @text FIRMWARE_OUTDATED */,
         FIRMWARE_UPTODATE = 4 /* @text FIRMWARE_UPTODATE */
      };
      
      // @brief notify Firmware update state change.
      // @param State   : State
      // @param SubState: SubState
      // @text onUpdateStateChange
      virtual void OnUpdateStateChange (const State state , const SubState substate ) {};

   ### Example 3: String for wide range of values
      // @brief Initiates a firmware update.
      // @param[in] firmwareFilepath The complete path of the firmware file to which the device needs to be updated to.
      // @param[in] firmwareType     Type of firmware. One of the following (PCI,DRI)
      // @text updateFirmware
      virtual Core::hresult UpdateFirmware(const string& firmwareFilepath, const string& firmwareType, Result &result /* @out  */ ) = 0;
