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

namespace WPEFramework {
namespace Exchange {
// @json 1.0.0 @text:keep
struct EXTERNAL IAppStorageManager : virtual public Core::IUnknown {

    enum { ID = ID_APPSTORAGEMANAGER };

    /** Create Storage for a given appId */
    // @json:omit
    // @text createStorage
    // @brief Called by the Package Manager after installing an app and returns a storage path or an error
    // @details Creates storage for the specified application with the given size. Returns the path to the storage and an error reason if the operation fails.
    // @param appId: String App identifier for the application.
    // @example appId: "com.example.app"
    // @param size: uint (in KB)
    // @example size: 1024
    // @param path: String path to a directory or image file
    // @example path: "/storage/com.example.app"
    // @param errorReason: String error reason string
    // @example errorReason: "Insufficient storage space"
    // @retval Core::ERROR_NONE: Successfully created storage
    virtual Core::hresult CreateStorage(const string& appId, const uint32_t& size, string& path/* @out */, string& errorReason /* @out */) = 0;

    /** Get the storage location for a given app id */
    // @json:omit
    // @text getStorage
    // @brief Called by RuntimeManager and returns the storage location for a given app id
    // @details Retrieves the storage location and usage information for the specified application.
    // @param appId: String App identifier for the application.
    // @example appId: "com.example.app"
    // @param userId: int
    // @example userId: 1001
    // @param groupId: int
    // @example groupId: 1001
    // @param path: string path to a directory or image file
    // @example path: "/storage/com.example.app"
    // @param size: uint (in KB)
    // @example size: 1024
    // @param used: uint (in KB)
    // @example used: 512
    // @retval Core::ERROR_NONE: Successfully retrieved storage information
    virtual Core::hresult GetStorage(const string& appId, const int32_t& userId, const int32_t& groupId, string& path/* @out */, uint32_t& size /* @out*/, uint32_t& used /* @out*/) = 0;

    /** Deletes storage for a given app id */
    // @json:omit
    // @text deleteStorage
    // @brief Called by the Package Manager after uninstalling an appGet the state of container
    // @details Deletes the storage associated with the specified application.
    // @param appId: String App identifier for the application.
    // @example appId: "com.example.app"
    // @param errorReason: String error reason string
    // @example errorReason: "Insufficient storage space"
    // @retval Core::ERROR_NONE: Successfully deleted storage
    virtual Core::hresult DeleteStorage(const string& appId, string& errorReason /* @out */) = 0;

    /** Clears storage for a given app id */
    // @stubgen:stub
    // @text clear
    // @brief Called by IUI.  This also clears device storage as well
    // @details Clears the storage associated with the specified application.
    // @param appId: string App identifier for the application.
    // @example appId: "com.example.app"
    // @param errorReason: String error reason string
    // @example errorReason: "Insufficient storage space"
    // @retval Core::ERROR_NONE: Successfully cleared storage
    virtual Core::hresult Clear(const string& appId, string& errorReason /* @out */) = 0;

    /** Clears all app data except for the exempt app ids */
    // @stubgen:stub
    // @text clearAll
    // @brief Called by IUI.  This also clears device storage as well
    // @details Clears all app data except for the exempt app ids.
    // @param exemptionAppIds: String Clears all app data except for the exempt app ids as a json format
    // @example exemptionAppIds: "[\"com.example.app1\", \"com.example.app2\"]"
    // @param errorReason: String error reason string
    // @example errorReason: "Insufficient storage space"
    // @retval Core::ERROR_NONE: Successfully cleared all storage
    virtual Core::hresult ClearAll(const string& exemptionAppIds, string& errorReason /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework

