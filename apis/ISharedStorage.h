/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2025 RDK Management
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

    /* @json @text:keep */
    struct EXTERNAL ISharedStorage : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE };

        ~ISharedStorage() override = default;

        enum ScopeType : uint8_t {
            DEVICE      /* @text device */,
            ACCOUNT     /* @text account */
        };
        struct EXTERNAL Success {
            bool success;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_SHARED_STORAGE_NOTIFICATION };

            ~INotification() override = default;

            // @text onValueChanged
            // @brief Values stored are changed using setValue
            // @details This event is generated whenever a key-value pair is created or updated in the shared storage. The notification contains the storage scope, namespace, key, and updated value.
            // @param scope: must be device or account
            // @example scope - DEVICE
            // @param ns - in - Namespace containing the modified key.
            // @example ns - "application"
            // @param key: key 
            // @example key - "language"
            // @param value: value
            // @example value - "en-US"
            virtual void OnValueChanged(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value) {};
        };

        virtual Core::hresult Register(Exchange::ISharedStorage::INotification* notification) = 0;
        virtual Core::hresult Unregister(Exchange::ISharedStorage::INotification* notification) = 0;

        // @brief Sets the value of a key in the the specified namespace
        // @text setValue
        // @details Creates or updates a key-value pair in the selected storage scope and namespace. An optional TTL can be provided to control the lifetime of the stored value.
        // @param scope: must be device or account
        // @example scope - DEVICE
        // @param ns: name space 
        // @example ns - "application"
        // @param key: key 
        // @example key - "language"
        // @param value: value
        // @example value - "en-US"
        // @param ttl: time to live (optional)
        // @example ttl - 3600
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Value stored successfully.
        // @retval Core::ERROR_GENERAL - Failed to store the value.
        virtual Core::hresult SetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value, const uint32_t ttl, Success& success /* @out */) = 0;

        // @brief Returns the value of a key from the specified namespace.
        // @text getValue
        // @details Retrieves a stored value and its associated TTL information from the specified scope and namespace.
        // @param scope: must be device or account
        // @example scope - DEVICE
        // @param ns: name space
        // @example ns - "application"
        // @param key: key 
        // @example key - "language"
        // @param value: value out
        // @example value - "en-US"
        // @param ttl: time to live (optional)
        // @example ttl - 3580
        // @param success: Indicates whether the operation was successful
        // @example success - true
        // @retval Core::ERROR_NONE - Value retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve the value.
        virtual Core::hresult GetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, string& value /* @out */, uint32_t& ttl /* @out */, bool& success /* @out */) = 0;

        // @brief Deletes a key from the specified namespace
        // @text deleteKey
        // @param scope: must be device or account
        // @details Removes the specified key and its associated value from the selected namespace and scope.
        // @param ns: name space
        // @example ns - "application"
        // @param key: key
        // @example key - "language"
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Key deleted successfully.
        // @retval Core::ERROR_GENERAL - Failed to delete the key.
        virtual Core::hresult DeleteKey(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, Success& success /* @out */) = 0;

        // @text deleteNamespace
        // @brief Deletes the specified namespace
        // @details Removes a namespace and all associated key-value pairs from the selected storage scope.
        // @param scope: must be device or account
        // @example scope - DEVICE
        // @param ns: name space
        // @example ns - "application"
        // @param success: Indicates whether the operation was successful
        // @example success: true
        // @retval Core::ERROR_NONE - Namespace deleted successfully.
        // @retval Core::ERROR_GENERAL - Failed to delete the namespace.
        virtual Core::hresult DeleteNamespace(const ScopeType scope, const string& ns /* @text:namespace */, Success& success /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageInspector : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_INSPECTOR };

        ~ISharedStorageInspector() override = default;

        struct NamespaceSize {
            string ns /* @text:namespace */;
            uint32_t size;
        };

        using ScopeType = ISharedStorage::ScopeType;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        using INamespaceSizeIterator = RPC::IIteratorType<NamespaceSize, ID_SHARED_STORAGE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

        // @brief Returns the keys that are stored in the specified namespace
        // @text getKeys
        // @details Retrieves all keys available in the specified namespace and scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns : "application"
        // @param keys: keys list
        // @example keys : ["language","region"]
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE - Keys retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve keys.
        virtual Core::hresult GetKeys(const ScopeType scope, const string& ns /* @text:namespace */, IStringIterator*& keys /* @out */, bool& success /* @out */) = 0;

        // @text getNamespaces
        // @brief Returns the namespaces
        // @details Retrieves all namespaces available in the selected storage scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param namespaces: namespaces list
        // @example namespaces : ["application","network"]
        // @param success: success
        // @example success - true
        // @retval Core::ERROR_NONE - Namespaces retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve namespaces.
        virtual Core::hresult GetNamespaces(const ScopeType scope, IStringIterator*& namespaces /* @out */, bool& success /* @out */) = 0;

        // @text getStorageSizes
        // @brief Returns the size occupied by each namespace
        // @details Retrieves the storage sizes for all namespaces in the selected storage scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param storageList: list of namespaces and their sizes
        // @example storageList : [{"namespace":"application","size":1024},{"namespace":"network","size":2048}]
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE - Storage sizes retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve storage sizes.
        virtual Core::hresult GetStorageSizes(const ScopeType scope, INamespaceSizeIterator*& storageList /* @out */, bool& success /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageLimit : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_LIMIT };

        ~ISharedStorageLimit() override = default;

        using ScopeType = ISharedStorage::ScopeType;
        struct StorageLimit {
            uint32_t storageLimit;
        };

        // @text setNamespaceStorageLimit
        // @brief Sets the storage limit for a given namespace
        // @details Configures the maximum storage size allowed for the specified namespace in the selected scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param storageLimit: size
        // @example storageLimit: 1024
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE - Storage limit updated successfully.
        // @retval Core::ERROR_GENERAL - Failed to update the storage limit.
        virtual Core::hresult SetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, const uint32_t storageLimit, bool& success /* @out */) = 0;

        // @text getNamespaceStorageLimit
        // @brief Returns the storage limit for a given namespace
        // @brief Returns the storage limit for a given namespace
        // @details Retrieves the maximum storage size allowed for the specified namespace in the selected scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param storageLimit: Size in bytes
        // @example storageLimit: 1048576
        // @retval Core::ERROR_NONE - Storage limit retrieved successfully.
        // @retval Core::ERROR_GENERAL - Failed to retrieve the storage limit.
        virtual Core::hresult GetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, StorageLimit& storageLimit /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageCache : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_CACHE };

        // @text flushCache
        // @brief Flushes the device cache
        // @details Forces all pending shared-storage cache entries to be written to the underlying persistent storage backend.
        // @retval Core::ERROR_NONE - Cache flushed successfully.
        // @retval Core::ERROR_GENERAL - Failed to flush the cache.
        virtual Core::hresult FlushCache() = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
