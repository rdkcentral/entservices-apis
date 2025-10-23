/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2023 RDK Management
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

// This interface is based on the LGI ILISA interface with smal changes to enable JSON RPC code generation from the interface and extensions for improved Firebolt support

#pragma once
#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {

    // @json 1.0.0 @text:keep
    struct EXTERNAL IPackageManager : virtual public Core::IUnknown {

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        enum { ID = ID_PACKAGEMANAGER };

        /** Install an application bundle */
        // @text install
        // @brief Downloads and installs an application bundle.
        virtual Core::hresult Install(const string& type,
                const string& id,
                const string& version,
                const string& url,
                const string& appName,
                const string& category,
                string& handle /* @out */) = 0;

        /** Uninstall an application */
        // @text uninstall
        // @brief Uninstalls an application.
        virtual Core::hresult Uninstall(const string& type,
                const string& id,
                const string& version,
                const string& uninstallType,
                string& handle /* @out */) = 0;

        /** Download a resource for an app */
        // @text download
        // @brief Downloads a resource file for an application.
        virtual Core::hresult Download(const string& type,
                const string& id,
                const string& version,
                const string& resKey,
                const string& url,
                string& handle /* @out */) = 0;

        /** Reset application state */
        // @text reset
        // @brief Deletes all persistent local data of the application.
        virtual Core::hresult Reset(const string& type,
                const string& id,
                const string& version,
                const string& resetType) = 0;

        struct EXTERNAL StorageInfo 
        {
                struct EXTERNAL StorageDetails 
                {
                        string path;
                        string quotaKB;
                        string usedKB;
                };
                
                StorageDetails apps;
                StorageDetails persistent;
        };

        /** Get application storage usage */
        // @text getStorageDetails
        // @brief Retrieves details about app and persistent storage usage.
        virtual Core::hresult GetStorageDetails(const string& type,
                const string& id,
                const string& version,
                StorageInfo& storageinfo /* @out */) const = 0;

        struct EXTERNAL KeyValue  {
            string key;
            string value;
        };
        using IKeyValueIterator = RPC::IIteratorType<KeyValue, ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

        struct MetadataPayload {
            string appName;
            string type;
            string category;
            string url;
        };

        /** Set custom metadata */
        // @text setAuxMetadata
        // @brief Sets a key-value pair of metadata for the application.
        virtual Core::hresult SetAuxMetadata(const string& type,
                const string& id,
                const string& version,
                const string& key,
                const string& value) = 0;

        /** Clear custom metadata */
        // @text clearAuxMetadata
        // @brief Clears the specified metadata key.
        virtual Core::hresult ClearAuxMetadata(const string& type,
                const string& id,
                const string& version,
                const string& key) = 0;

        /** Get all metadata and resources */
        // @text getMetadata
        // @brief Retrieves metadata and auxiliary resource list for an application.
        virtual Core::hresult GetMetadata(const string& type,
                const string& id,
                const string& version,
                MetadataPayload& metadata /* @out */,
                IPackageManager::IKeyValueIterator*& resources /* @out */,
                IPackageManager::IKeyValueIterator*& auxMetadata /* @out */) const = 0;

        /** Cancel an ongoing operation */
        // @text cancel
        // @brief Cancels a previously issued asynchronous request.
        virtual Core::hresult Cancel(const string& handle) = 0;

        /** Get progress of an operation */
        // @text getProgress
        // @brief Provides the current progress of an ongoing operation.
        virtual Core::hresult GetProgress(const string& handle, uint32_t& progress /* @out */) const = 0;

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {

            enum {ID = ID_PACKAGEMANAGER_NOTIFICATION};

            // @text operationStatus
            // @brief Notifies completion of an asynchronous operation.
            virtual void OperationStatus(const string& handle, const string& operation, const string& type, const string& id,
                                         const string& version, const string& status, const string& details) = 0;
        };

        /** Register for notifications */
        virtual Core::hresult Register(IPackageManager::INotification* notification) = 0;
        /** Unregister from notifications */
        virtual Core::hresult Unregister(IPackageManager::INotification* notification) = 0;

        struct EXTERNAL PackageKey {            
            string id;
            string version;
        };

        using IPackageKeyIterator = RPC::IIteratorType<PackageKey, ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

        /** List installed apps */
        // @text getList
        // @brief Retrieves list of installed apps matching given filters.
        virtual Core::hresult GetList(
                const string& type,
                const string& id,
                const string& version,
                const string& appName,
                const string& category,
                IPackageKeyIterator*& installedIds /* @out */) const = 0; 

        /** Lock application from uninstalling */
        // @text lock
        // @brief Locks an application to prevent uninstallation.
        virtual Core::hresult Lock(const string& type,
                const string& id,
                const string& version,
                const string& reason,
                const string& owner,
                string& handle /* @out */) = 0;


        /** Unlock application */
        // @text unlock
        // @brief Unlocks a previously locked application.
        virtual Core::hresult Unlock(const string& handle) = 0;

        struct LockInfo {
            string reason;
            string owner;
        };

        /** Get lock details */
        // @text getLockInfo
        // @brief Provides lock reason and owner for an app.
        virtual Core::hresult GetLockInfo(const string& type,
                const string& id,
                const string& version,
                LockInfo& result /* @out */) const = 0;

    };

    struct EXTERNAL IPackageManagerBroker : virtual public Core::IUnknown {

                enum { ID = ID_PACKAGEMANAGER_BROKER };

                virtual Core::hresult Offer(IPackageManager* packagemanager) = 0;
                virtual Core::hresult Revoke(const IPackageManager* packagemanager) = 0;

    };

    struct EXTERNAL IPackageManagerCallback : virtual public Core::IUnknown {

                enum { ID = ID_PACKAGEMANAGER_CALLBACK };
                // @see OperationStatus : Triggered upon completion of an asynchronous operation.
                virtual void OperationStatusUpdate(const string& handle, const string& operation, const string& type, const string& id,
                                         const string& version, const string& status, const string& details) = 0;

    };
}
}
