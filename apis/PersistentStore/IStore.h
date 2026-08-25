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

namespace WPEFramework {
namespace Exchange {

struct EXTERNAL IStore : virtual public Core::IUnknown {
    enum { ID = ID_STORE };

    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_STORE_NOTIFICATION };

        virtual void ValueChanged(const string &ns, const string &key, const string &value) {}
        virtual void StorageExceeded() {}
    };

    virtual Core::hresult Register(Exchange::IStore::INotification *notification) = 0;
    virtual Core::hresult Unregister(Exchange::IStore::INotification *notification) = 0;

    // @brief Stores a value associated with a namespace and key.
    // @details Creates or updates a key/value pair within the specified namespace. If the key already exists, its value is replaced with the supplied value.
    // @param ns - in - Namespace used to group related key/value pairs.
    // @example ns - "application"
    // @param key - in - Unique key identifier.
    // @example key - "language"
    // @param value - in - Value associated with the specified key.
    // @example value - "en-US"
    // @retval Core::ERROR_NONE - Value stored successfully.
    // @retval Core::ERROR_GENERAL - Failed to store the value.
    virtual Core::hresult SetValue(const string &ns, const string &key, const string &value) = 0;

    // @brief Retrieves a value associated with a namespace and key.
    // @details Looks up a previously stored key/value pair within the specified namespace and returns the associated value if found.
    // @param ns - in - Namespace containing the key.
    // @example ns - "application"
    // @param key - in - Key identifier whose value is requested.
    // @example key - "language"
    // @param value - out - Value associated with the specified key.
    // @example value - "en-US"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Value retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve the value.
    virtual Core::hresult GetValue(const string &ns, const string &key, string &value /* @out */) = 0;

    // @brief Deletes a key/value pair from a namespace.
    // @details Removes the specified key and its associated value from the
    // given namespace. Only the requested key is removed.
    // @param ns - in - Namespace containing the key.
    // @example ns - "application"
    // @param key - in - Key identifier to delete.
    // @example key - "language"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Key deleted successfully.
    // @retval Core::ERROR_GENERAL - Failed to delete the key.
    virtual Core::hresult DeleteKey(const string &ns, const string &key) = 0;

    // @brief Deletes an entire namespace and all its key/value pairs.
    // @details Removes the specified namespace and all associated key/value pairs contained within it.
    // @param ns - in - Namespace to delete.
    // @example ns - "application"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Namespace deleted successfully.
    // @retval Core::ERROR_GENERAL - Failed to delete the namespace.
    virtual Core::hresult DeleteNamespace(const string &ns) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
