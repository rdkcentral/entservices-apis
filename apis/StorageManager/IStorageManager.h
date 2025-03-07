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
struct EXTERNAL IStorageManager : virtual public Core::IUnknown {

    enum { ID = ID_STORAGEMANAGER };

    /** Create Storage for a given appId */
    // @json:omit
    // @text createStorage
    // @brief Called by the Package Manager after installing an app and returns a storage path or an error
    // @param appId - in - string App identifier for the application.
    // @param userId - in -int
    // @param groupId - in - int
    // @param size -  uint (in KB)
    // @param path -out -string path to a directory or image file
    // @param errorReason - out - string error reason string
    virtual Core::hresult CreateStorage(const string& appId, const int32_t& userId, const int32_t& groupId, const uint32_t& size, string& path/* @out */, string& errorReason /* @out */) = 0;

    /** Get the storage location for a given app id */
    // @json:omit
    // @text getStorage
    // @brief Called by RuntimeManager and returns the storage location for a given app id
    // @param appId - in - string App identifier for the application.
    // @param path -out -string path to a directory or image file
    // @param userId - out -int
    // @param groupId - out - int
    // @param size - out - uint (in KB)
    // @param used - out - uint (in KB)
    virtual Core::hresult GetStorage(const string& appId, string& path/* @out */, int32_t& userId /*@out*/, int32_t& groupId /*@out*/, uint32_t& size /* @out*/, uint32_t& used /* @out*/) = 0;

    /** Deletes storage for a given app id */
    // @json:omit
    // @text deleteStorage
    // @brief Called by the Package Manager after uninstalling an appGet the state of container
    // @param appId - in - string App identifier for the application.
    // @param errorReason - out - string error reason string
    virtual Core::hresult DeleteStorage(const string& appId, string& errorReason /* @out */) = 0;

    /** Clears storage for a given app id */
    // @stubgen:stub
    // @text clear
    // @brief Called by IUI.  This also clears device storage as well
    // @param appId - in - string App identifier for the application.
    // @param errorReason - out - string error reason string
    virtual Core::hresult Clear(const string& appId, string& errorReason /* @out */) = 0;

    /** Clears all app data except for the exempt app ids */
    // @stubgen:stub
    // @text clearAll
    // @brief Called by IUI.  This also clears device storage as well
    // @param exemptionAppIds - in - string Clears all app data except for the exempt app ids as a json format
    // @param errorReason - out - string error reason string
    virtual Core::hresult ClearAll(const string& exemptionAppIds, string& errorReason /* @out */) = 0;
};
} // namespace Exchange
} // namespace WPEFramework

