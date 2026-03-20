/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2022 Liberty Global Service B.V.
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

    struct EXTERNAL ILISA : virtual public Core::IUnknown {

        enum { ID = ID_LISA };

        /* @brief Download the application bundle. */
        virtual Core::hresult Install(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& url,
                const std::string& appName,
                const std::string& category,
                std::string& handle /* @out */) = 0;

        /* @brief Uninstall the application. */
        virtual Core::hresult Uninstall(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& uninstallType,
                std::string& handle /* @out */) = 0;

        /* @brief Download arbitrary application's resource file. */
        virtual Core::hresult Download(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& resKey,
                const std::string& url,
                std::string& handle /* @out */) = 0;

        /* @brief Delete persistent data stored locally. */
        virtual Core::hresult Reset(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& resetType) = 0;

        struct EXTERNAL IStorage : virtual public Core::IUnknown
        {
            enum { ID = ID_LISA_STORAGE };

            virtual Core::hresult Path(string& path /* @out */) const = 0;
            virtual Core::hresult QuotaKB(string& quotaKB /* @out */) const = 0;
            virtual Core::hresult UsedKB(string& usedKB /* @out */) const = 0;
        };

        struct EXTERNAL IStoragePayload : virtual public Core::IUnknown {
            enum { ID = ID_LISA_STORAGE_PAYLOAD };

            virtual Core::hresult Apps(ILISA::IStorage*& storage /* @out */) const = 0;
            virtual Core::hresult Persistent(ILISA::IStorage*& storage /* @out */) const = 0;
        };

        /* @brief Information on the storage usage. */
        virtual Core::hresult GetStorageDetails(const std::string& type,
                const std::string& id,
                const std::string& version,
                ILISA::IStoragePayload*& result /* @out */) = 0;

        struct EXTERNAL IKeyValue : virtual public Core::IUnknown {
            enum { ID = ID_LISA_KEY_VALUE };

            virtual Core::hresult Key(string& key /* @out */) const = 0;
            virtual Core::hresult Value(string& value /* @out */) const = 0;
        };

        struct EXTERNAL IKeyValueIterator : virtual public Core::IUnknown {
            enum { ID = ID_LISA_KEY_VALUE_ITERATOR };

            virtual Core::hresult Reset() = 0;
            virtual Core::hresult IsValid(bool& isValid /* @out */) const = 0;
            virtual Core::hresult Next(bool& hasNext /* @out */) = 0;
            virtual Core::hresult Current(ILISA::IKeyValue*& keyValue /* @out */) const = 0;
        };

        struct EXTERNAL IMetadataPayload : virtual public Core::IUnknown {
            enum { ID = ID_LISA_METADATA_PAYLOAD };

            virtual Core::hresult AppName(std::string& appName /* @out */) const = 0;
            virtual Core::hresult Category(std::string& category /* @out */) const = 0;
            virtual Core::hresult Url(std::string& url /* @out */) const = 0;
            virtual Core::hresult Resources(ILISA::IKeyValueIterator*& resources /* @out */) const = 0;
            virtual Core::hresult AuxMetadata(ILISA::IKeyValueIterator*& auxMetadata /* @out */) const = 0;
        };

        /* @brief Set an arbitrary metadata. */
        virtual Core::hresult SetAuxMetadata(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& key,
                const std::string& value) = 0;

        /* @brief Clears an arbitrary metadata. */
        virtual Core::hresult ClearAuxMetadata(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& key) = 0;

        /* @brief Get application metadata. */
        virtual Core::hresult GetMetadata(const std::string& type,
                const std::string& id,
                const std::string& version,
                ILISA::IMetadataPayload*& result /* @out */) = 0;

        /* @brief Cancel asynchronous request. */
        virtual Core::hresult Cancel(const std::string& handle) = 0;

        /* @brief Estimated progress of a request. */
        virtual Core::hresult GetProgress(const std::string& handle, uint32_t& progress /* @out */) = 0;

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {

            enum {ID = ID_LISA_NOTIFICATION};

            /* @brief Completion of asynchronous operation. */
            virtual void OperationStatus(const string& handle, const string& operation, const string& type, const string& id,
                                         const string& version, const string& status, const string& details) = 0;
        };

        virtual Core::hresult Register(ILISA::INotification* notification) = 0;
        virtual Core::hresult Unregister(ILISA::INotification* notification) = 0;
        virtual Core::hresult Configure(const std::string& config) = 0;

        struct EXTERNAL IAppVersion : virtual public Core::IUnknown {
            enum { ID = ID_LISA_APP_VERSION };

            struct EXTERNAL IIterator : virtual public Core::IUnknown {
                enum { ID = ID_LISA_APP_VERSION_ITERATOR };

                virtual Core::hresult Reset() = 0;
                virtual Core::hresult IsValid(bool& isValid /* @out */) const = 0;
                virtual Core::hresult Next(bool& hasNext /* @out */) = 0;
                virtual Core::hresult Current(ILISA::IAppVersion*& app /* @out */) const = 0;
            };

            virtual Core::hresult Version(string& version /* @out */) const = 0;
            virtual Core::hresult AppName(string& appName /* @out */) const = 0;
            virtual Core::hresult Category(string& category /* @out */) const = 0;
            virtual Core::hresult Url(string& url /* @out */) const = 0;
        };

        struct EXTERNAL IApp : virtual public Core::IUnknown {
            enum { ID = ID_LISA_APP };

            struct EXTERNAL IIterator : virtual public Core::IUnknown {
                enum { ID = ID_LISA_APP_ITERATOR };

                virtual Core::hresult Reset() = 0;
                virtual Core::hresult IsValid(bool& isValid /* @out */) const = 0;
                virtual Core::hresult Next(bool& hasNext /* @out */) = 0;
                virtual Core::hresult Current(ILISA::IApp*& app /* @out */) const = 0;
            };

            virtual Core::hresult Type(string& type /* @out */) const = 0;
            virtual Core::hresult Id(string& id /* @out */) const = 0;
            virtual Core::hresult Installed(ILISA::IAppVersion::IIterator*& versions /* @out */) const = 0;
        };

        struct EXTERNAL IAppsPayload : virtual public Core::IUnknown {
            enum { ID = ID_LISA_APPS_PAYLOAD };

            virtual Core::hresult Apps(ILISA::IApp::IIterator*& apps /* @out */) const = 0;
        };

        /* @brief List installed applications. */
        virtual Core::hresult GetList(
                const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& appName,
                const std::string& category,
                IAppsPayload*& result /* @out */) const = 0;

        struct EXTERNAL IHandleResult : virtual public Core::IUnknown {
            enum { ID = ID_LISA_HANDLE_RESULT };

            virtual Core::hresult Handle(std::string& handle /* @out */) const = 0;
        };

        /* @brief Lock the application. Preventing uninstallation. */
        virtual Core::hresult Lock(const std::string& type,
                const std::string& id,
                const std::string& version,
                const std::string& reason,
                const std::string& owner,
                ILISA::IHandleResult*& result /* @out */) = 0;


        /* @brief Unlock application. */
        virtual Core::hresult Unlock(const std::string& handle) = 0;

        struct EXTERNAL ILockInfo : virtual public Core::IUnknown {
            enum { ID = ID_LISA_LOCK_INFO };

            virtual Core::hresult Reason(std::string& reason /* @out */) const = 0;
            virtual Core::hresult Owner(std::string& owner /* @out */) const = 0;
        };

        /* @brief Get lock info. */
        virtual Core::hresult GetLockInfo(const std::string& type,
                const std::string& id,
                const std::string& version,
                ILISA::ILockInfo*& result /* @out */) = 0;
    };

}
}
