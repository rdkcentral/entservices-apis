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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0
    struct EXTERNAL IStore2 : virtual public Core::IUnknown {
        enum { ID = ID_STORE2 };

        ~IStore2() override = default;

        enum ScopeType : uint8_t {
            DEVICE,
            ACCOUNT
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_STORE2_NOTIFICATION };

            ~INotification() override = default;

            // @alt onValueChanged
            virtual void ValueChanged(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value) {}
        };

        virtual Core::hresult Register(Exchange::IStore2::INotification* notification) = 0;
        virtual Core::hresult Unregister(Exchange::IStore2::INotification* notification) = 0;

        // @alt setValue
        // @brief Stores a value in the persistent store.
        // @details Creates or updates a key-value pair within the specified scope and namespace. A time-to-live (TTL) value may be supplied to control automatic expiration of the stored entry.
        // @param scope: Storage scope (DEVICE or ACCOUNT).
        // @example scope: DEVICE
        // @param ns: Namespace used to group related entries.
        // @example ns: "application"
        // @param key: Key identifier.
        // @example key: "language"
        // @param value: Value associated with the key.
        // @example value: "en-US"
        // @param ttl: Time-to-live of the value in seconds.
        // @example ttl: 3600
        // @retval Core::ERROR_NONE: Value stored successfully.
        virtual Core::hresult SetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value, const uint32_t ttl) = 0;

        // @alt getValue
        // @brief Retrieves a value from the persistent store.
        // @details Returns the value associated with the specified key together with its remaining TTL information.
        // @param scope: Storage scope (DEVICE or ACCOUNT).
        // @example scope: DEVICE
        // @param ns: Namespace containing the key.
        // @example ns: "application"
        // @param key: Key identifier.
        // @example key: "language"
        // @param value: Retrieved value.
        // @example value: "en-US"
        // @param ttl: Remaining TTL value in seconds.
        // @example ttl: 3580
        // @retval Core::ERROR_NONE: Value retrieved successfully.
        virtual Core::hresult GetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, string& value /* @out */, uint32_t& ttl /* @out */) = 0;

        // @alt deleteKey
        // @brief Deletes a key-value pair.
        // @details Removes the specified key and its associated value from the given namespace and scope.
        // @param scope: Storage scope.
        // @example scope: DEVICE
        // @param ns: Namespace containing the key.
        // @example ns: "application"
        // @param key: Key to be removed.
        // @example key: "language"
        // @retval Core::ERROR_NONE: Key deleted successfully.
        virtual Core::hresult DeleteKey(const ScopeType scope, const string& ns /* @text:namespace */, const string& key) = 0;

        // @alt deleteNamespace
        // @brief Deletes an entire namespace.
        // @details Removes the specified namespace and all associated key-value pairs from the selected storage scope.
        // @param scope: Storage scope.
        // @example scope: DEVICE
        // @param ns: Namespace to remove.
        // @example ns: "application"
        // @retval Core::ERROR_NONE: Namespace deleted successfully.
        virtual Core::hresult DeleteNamespace(const ScopeType scope, const string& ns /* @text:namespace */) = 0;
    };

    struct EXTERNAL IStoreInspector : virtual public Core::IUnknown {
        enum { ID = ID_STORE_INSPECTOR };

        ~IStoreInspector() override = default;

        struct NamespaceSize {
            string ns;
            uint32_t size;
        };

        using ScopeType = IStore2::ScopeType;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        using INamespaceSizeIterator = RPC::IIteratorType<NamespaceSize, ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

        // @brief Retrieves all keys within a namespace.
        // @details Returns an iterator containing all keys stored in the specified namespace and scope.
        // @param scope: Storage scope.
        // @example scope: DEVICE
        // @param ns: Namespace whose keys are requested.
        // @example ns: "application"
        // @param keys: Iterator containing the retrieved keys.
        // @example keys: ["language", "region"]
        // @retval Core::ERROR_NONE: Keys retrieved successfully.
        virtual Core::hresult GetKeys(const ScopeType scope, const string& ns, IStringIterator*& keys /* @out */) = 0;

        // @brief Retrieves all available namespaces.
        // @details Returns an iterator containing the namespaces available within the specified storage scope.
        // @param scope: Storage scope.
        // @example scope: DEVICE
        // @param namespaces: Iterator containing namespace names.
        // @example namespaces: ["application", "network"]
        // @retval Core::ERROR_NONE: Namespaces retrieved successfully.
        virtual Core::hresult GetNamespaces(const ScopeType scope, IStringIterator*& namespaces /* @out */) = 0;

        // @brief Retrieves storage consumption information.
        // @details Returns namespace storage usage information for the specified storage scope, including namespace name and storage size.
        // @param scope: Storage scope.
        // @example scope: DEVICE
        // @param storageList: Iterator containing namespace storage sizes.
        // @example storageList: [{ "ns":"application", "size":1024 }]
        // @retval Core::ERROR_NONE: Storage information retrieved successfully.
        virtual Core::hresult GetStorageSizes(const ScopeType scope, INamespaceSizeIterator*& storageList /* @out */) = 0;
    };

    struct EXTERNAL IStoreLimit : virtual public Core::IUnknown {
        enum { ID = ID_STORE_LIMIT };

        ~IStoreLimit() override = default;

        using ScopeType = IStore2::ScopeType;

        // @brief Sets storage limit for a namespace.
        // @details Configures the maximum storage size allowed for the specified namespace within the selected storage scope.
        // @param scope: Storage scope (DEVICE or ACCOUNT).
        // @example scope: DEVICE
        // @param ns: Namespace to configure storage limit for.
        // @example ns: "application"
        // @param size: Maximum storage size in bytes.
        // @example size: 1048576
        // @retval Core::ERROR_NONE: Storage limit set successfully.
        virtual Core::hresult SetNamespaceStorageLimit(const ScopeType scope, const string& ns, const uint32_t size) = 0;

        // @brief Retrieves storage limit for a namespace.
        // @details Returns the maximum storage size configured for the specified namespace within the selected storage scope.
        // @param scope: Storage scope (DEVICE or ACCOUNT).
        // @example scope: DEVICE
        // @param ns: Namespace whose storage limit is requested.
        // @example ns: "application"
        // @param size: Maximum storage size in bytes.
        // @example size: 1048576
        // @retval Core::ERROR_NONE: Storage limit retrieved successfully.
        virtual Core::hresult GetNamespaceStorageLimit(const ScopeType scope, const string& ns, uint32_t& size /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

