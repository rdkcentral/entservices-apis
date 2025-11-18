# Entertainment Services API Governance 
API Governance model for RDK Entertainment Services in ENTOS Platforms.

# Table of Contents

- [Introduction](#introduction)
- [Key Objectives](#key-objectives)
- [Governance Structure](#governance-structure)
- [API Specification Guidelines](#api-specification-guidelines)
- [Governance Processes and Workflows](#governance-processes-and-workflows)

# Introduction
This document captures the API Governance model and workflows for RDK Entertainment Services in ENTOS Platforms

# Key Objectives
The key objective of the API governance is to ensure, the APIs are
- Open
  - The governance model allows the APIs to be defined in open and transparently
- Collaborative
  - The model allows collaborative way of developing APIs, thus providing opportunities to multiple parties (within as well as outside) to add and enhance APIs.
- Scalable
  - APIs SHALL be designed to scale efficiently in terms of both functionally as well performance wise.
- Maintainable
  - Establish practices that make APIs easy to maintain, update, and deprecate
- Consistent
  - Ensure all APIs adhere to the same standards for naming, versioning, error handling, and documentation.
- Secure
  - APIs consider robust security mechanisms, where needed.

# Governance Structure
- Governance Board
  - Governance Board outlines the structure of the team responsible for overseeing API design, approvals, and updates. This would include approving members that consists of System Architects, Component Architect and Component Maintainer and participating members that consists of plugin maintainers and, case by case basis, set of subject matter experts.
- Approval Process
  - Outline the process for approving new APIs, changes to existing ones, and deprecations
  - For more details, please refer the [APIs Proposal and Approval](#apis-proposal-and-approval) section of this document.
- Review Cycle / Window
  - Mix of spontaneous as well as periodic reviews for APIs intake to ensure APIs remain aligned with ENTOS needs and technical standards
  - For more details, please refer the [APIs Reviews and Audit](#apis-reviews-and-audit) section of this document.

# API Specification Guidelines
- Guidelines
  - RDK Entertainment Services APIs SHALL adhere to the Thunder Plugins Interface Guidelines outlined [here](https://rdkcentral.github.io/Thunder/plugin/interfaces/guidelines/) (and the implementation of these APIs SHALL be a single or group of Thunder Plugins within the RDK Entertainment Services middleware components).
- Naming Conventions
  - All RDK Entertainment Services MUST have a callsign with a prefix of org.rdk and each service name must use PascalCase (first letter of each word is capitalized). For example,
    > org.rdk.PersistentStore

  - All RDK Entertainment Services that are required to implement JSON RPC MUST have "@json 1.0.0" and "@text:keep" tags in the interface definition. For example,
    > /* @json 1.0.0 @text:keep */
      struct EXTERNAL ITextTrack : virtual public Core::IUnknown {
      ....
      }

  - All RDK Entertainment Services that implements "notification interface" SHALL have default implementation in the interface headers for all notifications, instead of keeping them as pure virtual functions. For example, 
    > /* @event */
      struct EXTERNAL INotification : virtual public Core::IUnknown {
      ......
      virtual void OnFontColorChanged(const string& color) {};
      .....
      }

  - All methods in the interface header file SHALL have "Core::hresult" as the return type. For example,
    > virtual Core::hresult BindDriver(const string& deviceName) const = 0;

  - APIs & Event Names in the Interface header file SHALL, by default, be defined using PascalCase and the same SHALL be used for COMRPC communication. For example, 
    > virtual Core::hresult BindDriver(const string& deviceName) const = 0;
    > virtual void OnDevicePluggedIn(const USBDevice& device) = {};

  - However (in reference to the previous point), API & Event Names for JSON RPC SHALL always use camelCase (first word is all lowercase & first letter of subsequent words are capitalized) by using the [annotations / tags](https://rdkcentral.github.io/Thunder/plugin/interfaces/tags/) provision offered by Thunder Framework for defining the interface. For example (note the @text annotations in the example),
    > // @text bindDriver
    > virtual Core::hresult BindDriver(const string& deviceName) const = 0;
    > // @text onDevicePluggedIn
    > virtual void OnDevicePluggedIn(const USBDevice& device) = {};

    > **Note:** Future releases of Thunder Tools (R5.x) supports this inherently, when "@text:keep" is mentioned at the interface level. Once RDK Entertainment Services moves to the release that has this feature, this guideline is no more valid / required to be followed (as this will be automatically taken care of)
    
  - Parameter names in request and response format for JSON RPC SHALL use camelCase and be valid ascii strings. Also, the output parameter SHALL be tagged using "@out" tag (refer:  [annotations / tags](https://rdkcentral.github.io/Thunder/plugin/interfaces/tags/) provision offered by Thunder Framework). Input parameters SHALL not be tagged with "@in" though the tag is supported by framework. For example, 
    > virtual Core::hresult GetPartitionInfo(const string& mountPath, USBStoragePartitionInfo& partitionInfo /* @out */) const = 0;

  - Enum names SHALL be in all ALL_UPPER_SNAKE_CASE (all uppercase, words are separated by underscore). For example,
    >  enum USBStorageMountFlags : uint8_t
    >  {
    >  READ_ONLY     = 1  /* READ ONLY */,
    >  READ_WRITE    = 2  /* READ WRITE */
    >  };

    > **Note:** There MAY be exceptions to the above in case of names used in standardization. For ex., kHz
    
  - API getters SHALL always start with get and Setters SHALL always start with set. For example, 
    > GetDefaultInterface and SetDefaultInterface (in Interface headers)
    > getDefaultInterface and setDefaultInterface (in JSON RPC)

  - Usage of documentation tags in Interface header
    > @brief -> It gives short description about the function, events and struct members.
    > @param -> It is associated with a function/property. This tag adds the description about the specified parameter in the generated code and in the generated document.
    > @details -> Just like @brief starts a brief description, @details starts the detailed description.There it will be captured in the description section for the method. 
    > @retval -> The syntax for this tag is @retval <ErrorCode>: <Description>. It is associated with function/property.It adds description about each return codes
    
  - Event names SHALL follow the convention: on[Object][Action].
    - Object SHALL be a noun and provide useful context on the event.
    - Action SHALL be a verb.
    - Use present and past tenses to indicate if the event is triggered before or after
    - For example, 
      > OnAppResumed and OnAppResuming (in Interface headers)
      > onAppResumed and onAppResuming (in JSON RPC)

  - JSON-RPC responses SHALL return either result object or error object on success or error respectively
    - Please refer to [JSON-RPC Spec](https://www.jsonrpc.org/specification#response_object) for more details on expected members in the response object. Highlighting important members below
    - result
      - This member is REQUIRED on success.
      - This member MUST NOT exist if there was an error invoking the method.
    - error
      - This member is REQUIRED on error.
      - This member MUST NOT exist if there was no error triggered during invocation.
      - The value for this member MUST be an Object as defined below.
        - code
          - A Number that indicates the error type that occurred.
          - This MUST be an integer.
        - message
          - A String providing a short description of the error.
          - The message SHOULD be limited to a concise single sentence.
    - Either the result member or error member MUST be included, but both members MUST NOT be included.
    - **Note:** One of the primary purpose behind creating "interface header" as defined in this document is to be able to "auto generate" code using Thunder Tools for both comrpc as well as json-rpc. When code generators are used in combination with the framework, the above guideline is handled automatically by the framework and hence no need to code for this explicitly.

  - To maintain uniformity in all text-editors, set TAB size to 4 spaces and replace TAB by SPACES

- Versioning
  - Please refer the [API versioning and deprecation](#api-versioning-and-deprecation) section of this document.
- Documentation
  - Please refer the document generation sub section under [APIs definitions and development](#apis-definitions-and-development) section of this document for more details.

# Governance Processes and Workflows
## APIs Definitions and Development  
- API Source Control
  - APIs are maintained at RDK Central org in a repo where you find this document.
- Licensing and CLAs
  - The API specification is licensed under Apache 2.0 open-source license
  - Necessary Contributor License Agreements (CLA) setup is in place to enable contribution from interested parties. 
- APIs definition 
  - APIs are defined in a header file as per [Thunder Interface guidelines](https://rdkcentral.github.io/Thunder/plugin/interfaces/guidelines/)
  - APIs definitions are grouped as per sub system under which they belong to, and kept inside a sub system specific directory
  - Each subsystems SHALL be accompanied by a sub system requirement document.  
  - Sufficient mechanisms / build methods are in place within the repository to generate JSON RPC and / or COMRPC proxy / client code using [Thunder Tools](https://github.com/rdkcentral/ThunderTools) 
- Document Generation
  - Documentation for an interface SHALL be generated from the IDL header file. The interface definition SHALL make use of the JSON tags present in the IDL (as explained in [Thunder Interface tags documentation](https://rdkcentral.github.io/Thunder/plugin/interfaces/tags/#json)) to influence the generated documentation.
  - **Note:** Documentation already generated using other methods (for the existing interface definition) SHALL be moved to this new method over a period of time with a defined target time

## APIs Proposal and Approval
- API Proposal
  - Teams or individuals proposing a new API or change must submit a Pull Request (Note: Practically, the submitter would be system architects or component architect on behalf of system architects or component architect or plugin maintainers or third parties outside the organization) 
    - PR to be raised to the "governance" branch and consists of 
      - Requirements update / addition to the existing sub system (or addition only, in case of new sub system)
      - APIs update / addition to the API Headers / new headers
    - The Header File SHALL have sufficient documentation to indicate API purpose, in and out parameters, and JSON RPC requirements.
- CI / CD process
  - APIs passes through the CI/CD process where the APIs are validated for 
    - Correctness and Compliance to the guidelines using code and document generation tools.
    - Contributor License Agreement (CLAs)
- Initial Review
  - The governance board reviews the API design for alignment with ENTOS API standards and guidelines (Refer [APIs Reviews and Audit](#apis-reviews-and-audit) Subsection for available "review window")
  - If the API follows the defined guidelines and does not introduce breaking changes, it moves to the next stage.
- Feedback and Revisions
  - If changes are required, the proposing team / individual revises the API specification based on feedback.
  - Resubmission for final approval once feedback is incorporated.
- Final Approval
  - Once approved, the APIs are accepted / merged to the governance branch

## API Versioning and Deprecation
- Versioning
  - RDK Entertainment Services APIs SHALL have the API versioning in the form of Major.Minor.Patch. For example, 1.0.3
  - APIs versioning would correspond to each release, and the release itself may be a major release, or minor release or patch release depending on the nature of the changes from previous release.
    - Major changes that break backward compatibility or changes that are substantial in nature require a new major version, while non breaking routine changes require a new minor version. Clinical changes require an increment in patch version.
    - Please refer the [APIs Reviews and Audit](#apis-reviews-and-audit) subsection of this document to understand the frequency of each of these releases.
  - The [APIs Reviews and Audit](#apis-reviews-and-audit) forum approves version increments and new branch is created with the branch name matching the version
  - **Note:** The versioning of RDK Entertainment Services APIs SHALL not be confused with the version of the plugin. The plugin version is not in the scope of this document.
- Deprecation
  - There is no requirement to maintain the backward compatibility with major version changes (ex: breaking changes or dropping of APIs) and it is expected that the implementers as well as consumers of RDK Entertainment services moves to the new version only when they could and afford. However, effort SHALL be taken to notify the consumers about these major changes through appropriate mechanisms (API Release Document over email distribution list?) 

## APIs Reviews and Audit 
- Monthly Strategic Meetings
  - Longer meetings focused on new set of APIs initiatives, larger version changes, and / or security/compliance
  - Often results in minor release of the APIs, and rarely results in major release.
  - To Do: Update here, who all needs to be part of this type of meeting
- Weekly Tactical Meetings
  - Short meetings to review and approve minor changes or patches
  - Often results in patch release of the APIs, and rarely results in minor release.
  - To Do: Update here, who all needs to be part of this type of meeting
- Impromptu Review Meeting
  - For emergency incidents, such as API outages or security vulnerabilities
  - May result in any type of release (major, minor or patch) depending on the type of changes.
  - To Do: Update here, who all needs to be part of this type of meeting
- Annual Policy Review 
  - Revisit the API governance policies annually to adapt to evolving technologies and business needs

## Communication Channels
- API Documentation Tool
  - API repo contains mechanisms to host the latest APIs documentation, versioning, and updates and SHALL remain be the first go to resource for API definition.
  - The Repo SHALL include changelog and deprecation notices.
- Developer Feedback mechanism
  - Feedback loops with internal and external developers via GitHub issues.
- Regular Updates
  - Use newsletters / emails to provide regular updates on the state of APIs (upcoming changes, performance, deprecations).

