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

            // @brief Values stored are changed using setValue
            // @text onValueChanged
            // @details Triggered when the value of a key in the specified namespace changes.
            // @param scope: must be device or account
            // @example scope: DEVICE
            // @param key: key 
            // @example key: "language"
            // @param ns: name space
            // @example ns: "application"
            // @param value: value
            // @example value: "en-US"
            virtual void OnValueChanged(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value) {};
        };

        virtual Core::hresult Register(Exchange::ISharedStorage::INotification* notification) = 0;
        virtual Core::hresult Unregister(Exchange::ISharedStorage::INotification* notification) = 0;

        // @brief Sets the value of a key in the the specified namespace
        // @text setValue
        // @details Creates or updates a key-value pair within the specified scope and namespace. A time-to-live (TTL) value may be supplied to control automatic expiration of the stored entry.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space 
        // @example ns: "application"
        // @param key: key 
        // @example key: "language"
        // @param value: value
        // @example value: "en-US"
        // @param ttl: time to live (optional)
        // @example ttl: 3600
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value, const uint32_t ttl, Success& success /* @out */) = 0;

        // @brief Returns the value of a key from the specified namespace.
        // @text getValue
        // @details Retrieves the value associated with the specified key together with its remaining TTL information.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param key: key 
        // @example key: "language"
        // @param value: value out
        // @example value: "en-US"
        // @param ttl: time to live (optional)
        // @example ttl: 3580
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult GetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, string& value /* @out */, uint32_t& ttl /* @out */, bool& success /* @out */) = 0;

        // @brief Deletes a key from the specified namespace
        // @text deleteKey
        // @details Removes the specified key and its associated value from the given namespace and scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param key: key
        // @example key: "language"
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult DeleteKey(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, Success& success /* @out */) = 0;

        // @brief Deletes the specified namespace
        // @text deleteNamespace
        // @details Removes the specified namespace and all associated key-value pairs contained within it.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
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
        // @details Returns the keys that are stored in the specified namespace.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param keys: keys list
        // @example keys: ["language", "region"]
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult GetKeys(const ScopeType scope, const string& ns /* @text:namespace */, IStringIterator*& keys /* @out */, bool& success /* @out */) = 0;

        // @brief Returns the namespaces
        // @text getNamespaces
        // @details Returns the namespaces that are stored in the specified scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param namespaces: namespaces list
        // @example namespaces: ["application", "settings"]
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult GetNamespaces(const ScopeType scope, IStringIterator*& namespaces /* @out */, bool& success /* @out */) = 0;

        // @brief Returns the size occupied by each namespace
        // @text getStorageSizes
        // @details Returns the size occupied by each namespace in the specified scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param storageList: list of namespaces and their sizes
        // @example storageList: [{ "ns":"application", "size":1024 }]
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
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

        // @brief Sets the storage limit for a given namespace
        // @text setNamespaceStorageLimit
        // @details Sets the storage limit for the specified namespace in the given scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param storageLimit: size
        // @example storageLimit: 1024
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult SetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, const uint32_t storageLimit, bool& success /* @out */) = 0;

        // @brief Returns the storage limit for a given namespace
        // @text getNamespaceStorageLimit
        // @details Returns the storage limit for the specified namespace in the given scope.
        // @param scope: must be device or account
        // @example scope: DEVICE
        // @param ns: name space
        // @example ns: "application"
        // @param storageLimit: Size in bytes
        // @example storageLimit: 1024
        // @param success: success
        // @example success: true
        // @retval Core::ERROR_NONE: Indicates success
        // @retval Core::ERROR_GENERAL: Indicates failure
        virtual Core::hresult GetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, StorageLimit& storageLimit /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageCache : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_CACHE };

        // @brief Flushes the device cache
        // @text flushCache
        // @details Forces all pending shared-storage cache entries to be written to the underlying persistent storage backend.
        // @retval Core::ERROR_NONE - Cache flushed successfully.
        // @retval Core::ERROR_GENERAL - Failed to flush the cache.
        virtual Core::hresult FlushCache() = 0;
    };

} // namespace Exchange
} // namespace WPEFramework
