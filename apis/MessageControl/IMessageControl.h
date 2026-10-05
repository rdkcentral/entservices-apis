/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2022 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

// @insert <com/IIteratorType.h>

namespace WPEFramework {

namespace Exchange {

// @json
struct EXTERNAL IMessageControl : virtual public Core::IUnknown {

    enum { ID = ID_MESSAGE_CONTROL };

    enum MessageType : uint8_t {
        TRACING        = 1,
        LOGGING        = 2,
        REPORTING      = 3,
        STANDARD_OUT   = 4,
        STANDARD_ERROR = 5
    };

    struct Control {
        MessageType type /* @brief Type of message */;
        string category /* @brief Name of the message category (e.g. Information) */;
        string module /* @brief Name of the module the message is originating from (e.g. Plugin_BluetoothControl) */;
        bool enabled /* @brief Denotes if the control is enabled (true) or disabled (false) */;
    };

    using IControlIterator = RPC::IIteratorType<Control, ID_MESSAGE_CONTROL_ITERATOR>;

    // @brief Enables or disables a message control for a given message type, module, and category.
    // @details This method updates the runtime filtering configuration for a message source. When enabled is set to true, matching messages are allowed through; when false, they are suppressed.
    // @param type: Message type to configure, such as tracing, logging, reporting, or standard output/error.
    // @example type: LOGGING
    // @param category: Name of the message category (e.g. Information).
    // @example category: "Information"
    // @param module: Name of the module the message is originating from (e.g. Plugin_BluetoothControl).
    // @example module: "Plugin_BluetoothControl"
    // @param enabled: Denotes whether the control should be enabled (true) or disabled (false).
    // @example enabled: true
    // @retval Core::ERROR_NONE: The message control was updated successfully.
    virtual Core::hresult Enable(const MessageType type, const string& category, const string& module, const bool enabled) = 0;

    // @property
    // @brief Retrieves the current message control configuration.
    // @details This method returns the list of message controls currently configured for the system so callers can inspect which message types, categories, and modules are enabled or disabled.
    // @param control:List of current message controls returned by the call.
    // @example control: nullptr
    // @retval Core::ERROR_NONE: The current controls were retrieved successfully.
    virtual Core::hresult Controls(IControlIterator*& control /* @out */) const = 0;
  };

} // namespace Exchange
} // namespace WPEFramework
