# Guidelines for Tagging C++ Methods with Doxygen Comments

## 1. Introduction

This document provides guidelines for using the `md_from_h` documentation tool. The tool works using Python version 3.8.10 and greater. Use of the tool requires tagging C++ methods and data structures with Doxygen comments to ensure proper documentation generation. The `HeaderFileStructure` class in the provided Python file first parses C++ header files, extracting information from Doxygen tags, declared structs, enums, iterators, methods, events, and properties, then uses this information to generate a markdown file documenting the headerfile. Many aspects of the markdown are automatically generated without relying on Doxygen comments (such as the table of contents), but method/property/event and parameter/result/value descriptions and JSON examples rely on Doxygen tags. This is intended for use on RDK Services and EntServices plugin APIs. Below are the details of the supported tags and additional features.

---
## 2. Running the Tool

The md_from_h tool is currently run automatically on a weekly basis from a Jenkins job. However, to run the tool locally on individual header files, navigate to the top level of the repo, and run:

`python3 ./tools/md_from_h_generator/generate_md_from_header.py ./apis/[header_file_folder]/[header_file]`

This will create a folder in the current directory named "generated_docs", where "generated_docs" contains the generated markdown file for the header file.

---

## 3. Supported Doxygen Tags

### 1. `@text` or `@alt`
- **Purpose**: Used to tell the program that all tags declared below the `@text` or `@alt` tag belong to the method
- **Required**: Yes (Mandatory tag for all methods/properties/events)
- **Usage**:
  - Use this tag to by following it with the name of the method/property/event.
  - Ensure the name following the tag matches the respective method/property/event name exactly.


### Example:

***Header File Example:***
```cpp
/**
 * @text initialize
 */
virtual uint32_t initialize();
```

---

### 2. `@brief`
- **Purpose**: Provides a concise summary of the method's functionality.
- **Required**: Yes (Mandatory tag for all methods/properties/events)
- **Usage**:
  - Use this tag for a short, one-line description of the method.
  - The description following this tag will be shown on the method/property/event table of contents

### Example:

***Header File Example:***
```cpp
/**
 * @text initialize
 * @brief This method initializes the system.
 */
virtual uint32_t initialize();
```

***Generated Markdown Example:***

> | Method | Description |
> | :-------- | :-------- |
> | [initialize](#method.initialize) | This method initializes the system. |


---

### 3. `@details`
- **Purpose**: Provides a detailed explanation of the method's behavior.
- **Required**: No (Optional tag)
- **Usage**:
  - Use this tag to elaborate on the method's functionality, including edge cases, assumptions, and any additional context.
  - The description following this tag will be shown in the method/property/event details.
  - Multi-line comments are supported for the details tag
  - This tag is optional but highly recommended for complex methods. If it is absent, the description from the `@brief` tag will be used in its place.

### Example:

***Header File Example:***
```cpp
/**
 * @text initialize
 * @brief This method initializes the system.
 * @details This method sets up the system by initializing all required components.
 * It must be called before any other method in the class.
 */
virtual uint32_t initialize();
```

***Generated Markdown Example:***
> <a id="method.GetCaptions"></a>
> ## *initialize [<sup>method</sup>](#head.Methods)*
> This method sets up the system by initializing all required components. It must be called before any other method in the class.

---

### 4. `@see`
- **Purpose**: Links the method to related methods or documentation.
- **Required**: No (Optional tag)
- **Usage**:
  - Use this tag to reference related methods, classes, or external documentation.
  - The linked event name should appear exactly as it is declared, without parenthesis
  - This tag is optional, but should be used if a corresponding event is defined in INotifications

### Example:

***Usage in the header file:***
```cpp
/**
 * @text initialize
 * @brief This method initializes the system.
 * @see onInitialize
 */
virtual uint32_t initialize();

...

/**
 * @text onInitialize
 * @brief Event triggered when system initialized
 */
virtual void onInitialize();
```

***Result in the markdown:***
>## *initialize [<sup>method</sup>](#head.Methods)*
> This method initializes the system.
> ### Events
> | Event | Description |
> | :-------- | :-------- |
> | [initialize](#event.OnAudioDescriptionChanged) | Event triggered when system initialized. |

---

### 5. `@param`
- **Purpose**: Documents the parameters of the method.
- **Required**: Yes (Mandatory tag for all methods/properties/events with params/results)
- **Usage**:
  - Use this tag for each parameter of the method. Each parameter and tag must be declared on a new line.
  - The description following the tag shall be listed in the parameters/results table
  - Optional parameters can be specified using `@param [param_name](optional)`
  - Parameter/symbol examples should be defined here (see [Providing Symbol Examples](#providing_examples), for providing examples and descriptions for `struct` as well)
  - Specify the parameter name and its description. Format can include colon i.e. `@param [param_name]: [description]` or `@param [para_name] [description]`
  - IMPORTANTLY, in addition to using the param tag, each parameter that is an output should be marked with an inline '@out' tag in the parameter list. The '@in' tag is optional for input parameters. If a parameter does not have inline in/out information, it defaults to 'in'.
  - Additionally a parameter name override can be specified by combining `@in` or `@out` followed by `@text:varible-override-name` in the function declaration.

### Example:

***Header File Example:***
```cpp
/**
 ...
 * @param configPath: The config file path for initialization e.g. "../build/test.conf"
 * @param status The status of the initialization. Set to true if completed.
 * @param configDetails(optional): Details of the configuration
 */
virtual uint32_t initialize(const string& configPath /* @in @text:config-path-override-name */, bool status /* @out @text:status-response */, string& configDetails /* @in */);
```

***Generated Markdown Example:***
> ### Parameters
> | Name | Type | Description |
> | :-------- | :-------- | :-------- |
> | config-path-override-name | string | The config file path for initialization |
> | configDetails | string | <sup>(optional)</sup> Details of the configuration |
> ### Results
> | Name | Type | Description |
> | :-------- | :-------- | :-------- |
> | status-response | bool | The status of the initialization. Set to true if completed. |

---

### 6. `@returns`
- **Purpose**: Describes the return value of the method.
- **Required**: No (Optional tag)
- **Usage**:
  - Use this tag to explain what the method returns.

**Example**:
```cpp
/**
 * @text initialize
 * @brief This method initializes the system.
 * @returns NULL if initialization was successful.
 */
virtual uint32_t initialize();
```

---

### 7. `@omit`
- **Purpose**: Indicates that the method should be omitted from the markdown.
- **Required**: No (Optional tag)
- **Usage**:
  - Use this tag for methods that should not appear in the generated documentation.
  - Omitted methods do not need to have any tags, like the `@text` or `@brief` tags
  - This tag is optional.

**Example**:
```cpp
/**
 * @omit
 */
virtual uint32_t internalMethod();
```

---

### 8. `@property`
- **Purpose**: Marks the method as a property (getter or setter).
- **Required**: No (Mandatory tag if method is a property)
- **Usage**:
  - Use this tag for methods that act as properties.

**Example**:
```cpp
/*
 * @property
 * @brief Video output port on the STB used for connection to TV
 * @param name: video output port name
 */
virtual uint32_t PortName (string& name /* @out */) const = 0;
```
---

### 9. `@plugindescription`
- **Purpose**: Provides option to override the generic plugin description text
- **Required**: No
- **Usage**:
  - Use this tag for overriding the generic plugin description.

**Example**:
```cpp
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        // @plugindescription This plugin provides so and so functionalities
        struct EXTERNAL IClassName : virtual public Core::IUnknown
    }
```

***Generated Markdown Example:***

> <a id="head.Description"></a>
> # Description
>
> This plugin provides so and so functionalities
>
> The plugin is designed to be loaded and executed within the Thunder framework. For more information about the framework refer > > to [[Thunder](#ref.Thunder)].
>
> <a id="head.Configuration"></a>

---

### 10. `@errors`
- **Purpose**: Describes the errors which this method can return.
- **Required**: No
- **Usage**:
  - Use this tag to detail the error code, error message type, and error description

**Example**:
```cpp
    namespace Exchange
    {
        // @errors 1 ERROR_GENERAL General Error
        virtual Core::hresult DefaultResolution(const string& videoDisplay /* @out */)
    }
```

***Generated Markdown Example:***
> ### Errors
> | Code | Messafe | Description |
> | :-------- | :-------- | :-------- |
> | 1 | `ERROR_GENERAL` | General error |

---

### 11. `@docs:configuration`
- **Purpose**: Provides option to include the plugin's configuration options
- **Required**: No
- **Usage**:
  - Use this to describe a configuration option for the plugin. Include the option's name, type, and description. Do not need to include options for the plugin's callsign, classname, locator, or autostart.

**Example**:
```cpp
    namespace Exchange
    {
        /* @json 1.0.0 @text:keep */
        // @plugindescription This plugin provides so and so functionalities
        // @docs:config configuration string 
        // @docs:config configuration.loggername string Logger name used by backend
        struct EXTERNAL IClassName : virtual public Core::IUnknown
    }
```

***Generated Markdown Example:***
> ### Configuration
> | Name	| Type	| Description |
> | :-------- | :-------- | :-------- |
> | callsign	| string	| Plugin instance name (default: *org.rdk.Analytics*) |
> | classname	| string	| Class name: *org.rdk.Analytics* |
> | locator	| string	| Library name: *libWPEFrameworkAnalytics.so* |
> | autostart	| boolean	| Determines if the plugin shall be started automatically along with the framework |
> | configuration	| object | |
> | configuration.loggername	| string	| Logger name used by backend |

---

## 4. Additional Features and Guidelines

<a id="providing_examples"></a>

### Providing Symbol Examples
In the RDK Services and Entservices APIs, plugins communicate using RPC. To facilitate this, the documentation includes relevant examples of request and response JSON structures. The md_from_h tool automates the creation of these examples by parsing enums, structs, iterators, and basic types declared in the header file, as well as extracting examples from @param Doxygen tags.

The tool maintains a global symbol registry to track the names and types of parameters declared in methods, properties, events, enums, and struct members. The goal of the global symbol registry is to make it easier and more consistent to provide examples for symbols which appear multiple times in a header file (such as preferredLanguages in IUserSettings.h). Examples are generated by analyzing the @param tags, where the tool uses a regular expression to extract text following the pattern `e.g. "(.*)"` in the parameter description. The value inside the quotes is then used as the example for that symbol. The pattern `ex: (.*)` is also matched in cases where examples have double-quotes. Additionally, examples can be derived from structs if their members include descriptive comments.

### Setting Examples for Method Parameters
The following demonstrates how examples are set for method parameters:

***Header File Example:***
```cpp
  /** Binds the respective driver for the device */
  // @text bindDriver
  // @brief Bind the respective driver for the device
  // @param deviceName: Name of the device e.g. "001/003"
  virtual uint32_t BindDriver(const string &deviceName /* @in */) const = 0;
```

***Generated Markdown Example:***
>#### Request
>```json
>{
>    "jsonrpc": "2.0",
>    "id": 42,
>    "method": "org.rdk.IUSBDevice.BindDriver",
>    "params": {
>        "deviceName": "001/003"
>    }
>}
>```

### Setting Examples for Struct Members
The following demonstrates how examples are set for struct members. Struct members can be commented with single-line comments (`//`) or block-comments (`/*...*/`).

***Header File Example:***
```cpp
struct USBDevice {
    uint8_t  deviceClass;    // @brief USB class of the device as per USB specification e.g. "10"
    uint8_t  deviceSubclass; // @brief USB sub class of the device as per USB specification e.g. "6"
    string   deviceName     /* @brief Name of the USB device e.g. "001/003"*/;
    string   devicePath     /* @brief the path to be used for the USB device e.g."/dev/sdX" */;
};
```

***Generated Markdown Example:***
>```json
>{
>    "jsonrpc": "2.0",
>    "id": 42,
>    "results": {
>        "devices": [
>            {
>                "deviceClass": "10",
>                "deviceSubclass": "6",
>                "deviceName": "001/003",
>                "devicePath": "/dev/sdX"
>            }
>        ]
>    }
>}
>```

#### Global and Greedy Example Generation
The process of generating examples is both global and greedy:
- Global: A global symbol registry ensures that once an example is defined for a symbol, it is reused wherever that symbol appears.
- Greedy: The first instance of a symbol in a header file with an example defined takes precedence globally. However, this can be overridden if a subsequent functions provide a new example for the same symbol using the @param tag with `e.g. "(.*)`.
For example, consider the preferredLanguages symbol:

***Header File Example***
```cpp
// @text onPreferredAudioLanguagesChanged
// @brief The preferredLanguages setting has changed.
// @param preferredLanguages: The preferred language for the device in ISO 639-2/B e.g. "fra"
virtual void OnPreferredAudioLanguagesChanged(const string& preferredLanguages /* in */) = 0;

// @text getPreferredAudioLanguages
// @brief Gets the preferred audio languages, in ISO 639-2/B code
// @param preferredLanguages: The preferred language for the device e.g. "eng"
virtual uint32_t GetPreferredAudioLanguages(string &preferredLanguages /* @out */) const = 0;

// @text getPreferredCaptionsLanguages
// @brief Gets the current PreferredCaptionsLanguages setting.
// @param preferredLanguages: The preferred language for the device
virtual uint32_t GetPreferredCaptionsLanguages(string &preferredLanguages /* @out */) const = 0;
```

***Generated Markdown Example:***
>## *OnPreferredAudioLanguagesChanged [<sup>event</sup>](#head.Notifications)*
>The preferredLanguages setting has changed.
>
>...
>#### Request
>```json
>{
>    "jsonrpc": "2.0",
>    "id": 42,
>    "method": "org.rdk.IUserSettings.OnPreferredAudioLanguagesChanged",
>    "params": {
>         "preferredLanguages": "fra" // first instance of symbol encountered, "fra" set as global example
>    }
>}
>```
>## *GetPreferredAudioLanguages [<sup>method</sup>](#head.Methods)*
>Gets the preferred audio languages, in ISO 639-2/B code
>
> ...
>#### Response
>```json
>{
>    "jsonrpc": "2.0",
>    "id": 42,
>    "results": {
>        "preferredLanguages": "eng" // Global example for preferredLanguages overridden
>    }
>}
>```
>## *GetPreferredCaptionsLanguages [<sup>method</sup>](#head.Methods)*
>Gets the current PreferredCaptionsLanguages setting.
>
> ...
>#### Response
>```json
>{
>    "jsonrpc": "2.0",
>    "id": 42,
>    "results": {
>        "preferredLanguages": "fra" // No e.g. provided in @param, so global example used
>    }
>}
>```

---

### General Guidelines
1. **Consistency**: All methods/properties/events should be tagged consistently, and should match their respective regexes mentioned above.
2. **Mandatory Tags**: Always include `@text`, `@brief` and `@params` (if applicable).
3. **Optional Tags**: Use `@details`, `@see`, and `@returns` as needed for clarity and completeness.
4. **Property and Event Methods**: Use `@property` for getter and setter methods to distinguish them from regular methods. Events are automatically distinguished because they are defined in the INotification struct in the headerfile.
5. **Parameter Documentation**: In addition to using `@param` for every parameter, specify whether it is an input or output parameter with inline comments in the method/property/event's parameter list. Make sure the parameter name in the Doxygen tag description matches exactly the name of the parameter declared in the parameter list.
#### Correct
```cpp
 ...
 /* @param configFile: path to config file for initialization */
 /* @param status true if initialization complete */
 virtual uint32_t initialize(const string& configFile /* @in */, bool status /* @out */)
```
#### Incorrect
```cpp
 ...
 /* @param string: path to config file */ # references type, not param name
 /* @param Status true if complete */     # does not match lower case of param name
 virtual uint32_t initialize(const string& configFile /* @in */, bool status) # missing `/* out */`
```
6. **Example Generation**: For generating examples for methods/properties/events which use iterators or structs as parameters or results, be sure to follow the guidelines stated in [Providing Symbol Examples](#providing_examples)
7. **Defining Structs in Header Files**: Nested structs and enums can complicate parsing and documentation generation. So, structs and enums should not be defined within another struct, as keeping them separate ensures better compatibility with the `md_to_h` tool (future versions may support nested definitions).
#### Correct - enums & structs not nested in definition
```cpp
struct USBDevice {
    uint8_t  deviceClass    /* @brief USB class of the device */ ;
    ...
};

enum USBDeviceFlags : uint8_t {
    DEVICE_FLAGS_DRIVER_AVAILABLE = 1  /* @brief AVAILABLE */,
    DEVICE_FLAGS_SWITCHABLE       = 2  /* @brief SWITCHABLE */
};

struct USBDeviceInfo {
            ...
            string           serialNumber   /* @brief Serial number of the device */;
            USBDevice	     device     	/* @brief Basic device information included */;
            USBDeviceFlags   flags          /* @brief Flags of the device */;
            ...
};
```
#### Incorrect - definitions for structs and enums should not be nested
```cpp
struct USBDeviceInfo {
    ...
    string serialNumber   /* @brief Serial number of the device */;
    struct USBDevice {
        uint8_t deviceClass    /* @brief USB class of the device */;
        ...
    } device;
    enum USBDeviceFlags : uint8_t {
        DEVICE_FLAGS_DRIVER_AVAILABLE = 1  /* @brief AVAILABLE */,
        DEVICE_FLAGS_SWITCHABLE       = 2  /* @brief SWITCHABLE */
    } flags;
    ...
};
```

---

### Miscellaneous Features
1. Multiline comments are supported.
2. Both `// ...` and `/* ... */` comments are supported for doxygen tags
3. Multi-line method parameter declaration is supported
4. The order in which Doxygen tags appear above a method (except for `@text`, which should always be the first tag) does not affect how the document is generated
5. All tags appearing above a method (between two methods) will be associated with that method

---
