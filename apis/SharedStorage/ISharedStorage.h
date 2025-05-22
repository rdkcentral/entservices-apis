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
            // @param scope: must be device or account
            // @param ns: namespace
            // @param key: key 
            // @param value: value
            virtual void ValueChanged(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value) {};
        };

        virtual Core::hresult Register(Exchange::ISharedStorage::INotification* notification) = 0;
        virtual Core::hresult Unregister(Exchange::ISharedStorage::INotification* notification) = 0;

        // @brief Sets the value of a key in the the specified namespace
        // @text setValue
        // @param scope: must be device or account
        // @param ns: namespace
        // @param key: key 
        // @param value: value
        // @param ttl: time to live (optional)
        // @param success: success
        virtual Core::hresult SetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value, const uint32_t ttl, Success& success /* @out */) = 0;
        // @brief Returns the value of a key from the specified namespace.
        // @text getValue
        // @param scope: must be device or account
        // @param ns: namespace
        // @param key: key 
        // @param value: value out
        // @param ttl: time to live (optional)
        // @param success: success
        virtual Core::hresult GetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, string& value /* @out */, uint32_t& ttl /* @out */, bool success /* @out */) = 0;
        // @brief Deletes a key from the specified namespace
        // @text deleteKey
        // @param scope: must be device or account
        // @param ns: namespace
        // @param key: key
        // @param success: success
        virtual Core::hresult DeleteKey(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, Success& success /* @out */) = 0;
        // @brief Deletes the specified namespace
        // @text deleteNamespace
        // @param scope: must be device or account
        // @param ns: namespace
        // @param success: success
        virtual Core::hresult DeleteNamespace(const ScopeType scope, const string& ns /* @text:namespace */, Success& success /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageInspector : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_INSPECTOR };

        ~ISharedStorageInspector() override = default;

        struct NamespaceSize {
            string ns;
            uint32_t size;
        };

        using ScopeType = ISharedStorage::ScopeType;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        using INamespaceSizeIterator = RPC::IIteratorType<NamespaceSize, ID_SHARED_STORAGE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

        // @brief Returns the keys that are stored in the specified namespace
        // @text getKeys
        // @param scope: must be device or account
        // @param ns: namespace
        // @param keys: keys list
        // @param success: success
        virtual Core::hresult GetKeys(const ScopeType scope, const string& ns /* @text:namespace */, IStringIterator*& keys /* @out */, bool success /* @out */) = 0;
        // @brief Returns the namespaces
        // @text getNamespaces
        // @param scope: must be device or account
        // @param namespaces: namespaces list
        // @param success: success
        virtual Core::hresult GetNamespaces(const ScopeType scope, IStringIterator*& namespaces /* @out */, bool success /* @out */) = 0;
        // @brief Returns the size occupied by each namespace
        // @text getStorageSizes
        // @param scope: must be device or account
        // @param storageList: list of namespaces and their sizes
        // @param success: success
        virtual Core::hresult GetStorageSizes(const ScopeType scope, INamespaceSizeIterator*& storageList /* @out */, bool success /* @out */) = 0;
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
        // @param scope: must be device or account
        // @param ns: namespace
        // @param size: size
        // @param success: success
        virtual Core::hresult SetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, const uint32_t size, bool success /* @out */) = 0;
        // @brief Returns the storage limit for a given namespace
        // @text getNamespaceStorageLimit
        // @param scope: must be device or account
        // @param ns: namespace
        // @param storageLimit: Size in bytes
        virtual Core::hresult GetNamespaceStorageLimit(const ScopeType scope, const string& ns /* @text:namespace */, StorageLimit& storageLimit /* @out */) = 0;
    };

    /* @json @text:keep */
    struct EXTERNAL ISharedStorageCache : virtual public Core::IUnknown {
        enum { ID = ID_SHARED_STORAGE_CACHE };

        // @brief Flushes the device cache
        // @text flushCache
        virtual Core::hresult FlushCache() = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

