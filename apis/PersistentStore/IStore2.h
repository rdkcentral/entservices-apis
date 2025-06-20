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
        virtual Core::hresult SetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, const string& value, const uint32_t ttl) = 0;
        // @alt getValue
        virtual Core::hresult GetValue(const ScopeType scope, const string& ns /* @text:namespace */, const string& key, string& value /* @out */, uint32_t& ttl /* @out */) = 0;
        // @alt deleteKey
        virtual Core::hresult DeleteKey(const ScopeType scope, const string& ns /* @text:namespace */, const string& key) = 0;
        // @alt deleteNamespace
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

        virtual Core::hresult GetKeys(const ScopeType scope, const string& ns, IStringIterator*& keys /* @out */) = 0;
        virtual Core::hresult GetNamespaces(const ScopeType scope, IStringIterator*& namespaces /* @out */) = 0;
        virtual Core::hresult GetStorageSizes(const ScopeType scope, INamespaceSizeIterator*& storageList /* @out */) = 0;
    };

    struct EXTERNAL IStoreLimit : virtual public Core::IUnknown {
        enum { ID = ID_STORE_LIMIT };

        ~IStoreLimit() override = default;

        using ScopeType = IStore2::ScopeType;

        virtual Core::hresult SetNamespaceStorageLimit(const ScopeType scope, const string& ns, const uint32_t size) = 0;
        virtual Core::hresult GetNamespaceStorageLimit(const ScopeType scope, const string& ns, uint32_t& size /* @out */) = 0;
    };

} // namespace Exchange
} // namespace WPEFramework

