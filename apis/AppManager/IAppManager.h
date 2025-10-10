/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management
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

#ifndef RUNTIME_CONFIG
struct RuntimeConfig
{
    bool dial{false};
    bool wanLanAccess{false};
    bool thunder{false};
    int32_t systemMemoryLimit{0};
    int32_t gpuMemoryLimit{0};
    std::string envVariables{};
    uint32_t userId{0};
    uint32_t groupId{0};
    uint32_t dataImageSize{0};

    bool resourceManagerClientEnabled{false};
    std::string dialId;
    std::string command;
    std::string appType;
    std::string appPath;
    std::string runtimePath;

    std::string logFilePath;
    uint32_t logFileMaxSize{0};
    std::string logLevels;          //json array of strings
    bool mapi {false};
    std::string fkpsFiles;          //json array of strings

    std::string fireboltVersion;
    bool enableDebugger{false};
    std::string unpackedPath;
};
#define RUNTIME_CONFIG
#endif

// @stubgen:include <com/IIteratorType.h>

// @json 1.0.0 @text:keep
struct EXTERNAL IAppManager : virtual public Core::IUnknown {
  enum { ID = ID_APPMANAGER };

  enum AppLifecycleState : uint8_t {
          APP_STATE_UNKNOWN       = 0   /* @text APP_STATE_UNKNOWN */,
          APP_STATE_UNLOADED      = 1   /* @text APP_STATE_UNLOADED */,
          APP_STATE_LOADING       = 2   /* @text APP_STATE_LOADING */,
          APP_STATE_INITIALIZING  = 3   /* @text APP_STATE_INITIALIZING */,
          APP_STATE_PAUSED        = 4   /* @text APP_STATE_PAUSED */,
          APP_STATE_RUNNING       = 5   /* @text APP_STATE_RUNNING */,
          APP_STATE_ACTIVE        = 6   /* @text APP_STATE_ACTIVE */,
          APP_STATE_SUSPENDED     = 7   /* @text APP_STATE_SUSPENDED */,
          APP_STATE_HIBERNATED    = 8   /* @text APP_STATE_HIBERNATED */,
          APP_STATE_TERMINATING   = 9   /* @text APP_STATE_TERMINATING */
      };

  enum AppErrorReason : uint8_t {
          APP_ERROR_NONE             = 0     /* @text APP_ERROR_NONE */,
          APP_ERROR_UNKNOWN          = 1     /* @text APP_ERROR_UNKNOWN */,
          APP_ERROR_STATE_TIMEOUT    = 2     /* @text APP_ERROR_STATE_TIMEOUT */,
          APP_ERROR_ABORT            = 3     /* @text APP_ERROR_ABORT */,
          APP_ERROR_INVALID_PARAM    = 4     /* @text APP_ERROR_INVALID_PARAM */,
          APP_ERROR_CREATE_DISPLAY   = 5     /* @text APP_ERROR_CREATE_DISPLAY */,
          APP_ERROR_DOBBY_SPEC       = 6     /* @text APP_ERROR_DOBBY_SPEC */,
          APP_ERROR_NOT_INSTALLED    = 7     /* @text APP_ERROR_NOT_INSTALLED */,
          APP_ERROR_PACKAGE_LOCK     = 8     /* @text APP_ERROR_PACKAGE_LOCK */
      };

  struct LoadedAppInfo
    {
        string appId ;
        string appInstanceId ;
        string activeSessionId;
        AppLifecycleState targetLifecycleState;
        AppLifecycleState currentLifecycleState;
    };
  using ILoadedAppInfoIterator = RPC::IIteratorType<LoadedAppInfo,ID_LOADED_APP_INFO_ITERATOR>;

  // @event
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_APPMANAGER_NOTIFICATION };

    // @text onAppInstalled
    // @brief Triggered whenever the App is installed.
    // @param appId:App identifier for the application.
    // @param version: The version number of the application in string format
    virtual void OnAppInstalled(const string& appId, const string& version){};

    // @text onAppUninstalled
    // @brief Triggered whenever the App is uninstalled.
    // @param appId:App identifier for the application.
    virtual void OnAppUninstalled(const string& appId){};

    // @text onAppLifecycleStateChanged
    // @brief Triggered whenever there is a change in the lifecycle state of a running app.
    // @param appId:App identifier for the application.
    // @param appInstanceId:A numerical identifier for a specific instance of the application.
    // @param newState:The new state to transition the application.
    // @param oldState:The previous state of the application instance before the update.
    // @param errorReason:The reason for any error encountered during the state transition
    virtual void OnAppLifecycleStateChanged(const string& appId, const string& appInstanceId, const AppLifecycleState newState, const AppLifecycleState oldState, const AppErrorReason errorReason){};

    // @text onAppLaunchRequest
    // @brief Triggered whenever there is a request for App Launch.
    // @param appId:App identifier for the application.
    // @param intent:A reference to the intent string that specifies the action or request to be processed.
    // @param source:A string indicating the source of the intent
    virtual void OnAppLaunchRequest(const string& appId, const string& intent, const string& source){};

    // @text onAppUnloaded
    // @brief Triggered whenever the App is unloaded(terminated).
    // @param appId:App identifier for the application.
    // @param appInstanceId:A numerical identifier for a specific instance of the application.
    virtual void OnAppUnloaded(const string& appId, const string& appInstanceId){};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  /** Retrieves a list of all installed applications on the system. **/
  // @text getInstalledApps
  // @brief Function fetches the details of all applications currently installed
  // @param apps A list containing the details of installed applications.
  virtual Core::hresult GetInstalledApps(string& apps /* @out @opaque */) = 0;

  /** Check the specific application is installed on the system. **/
  // @text isInstalled
  // @brief check whether the Application is installed or not
  // @param installed : if it is installed then return true otherwise false
  virtual Core::hresult IsInstalled(const string& appId, bool& installed /* @out */) = 0;

  /** Retrieves a list of all Loaded applications on the system. **/
  // @text getLoadedApps
  // @brief Retrieves a list of applications currently loaded on the system.
  // @param apps A list containing the details of loaded applications
  virtual Core::hresult GetLoadedApps(ILoadedAppInfoIterator*& apps /* @out */) = 0;

  /** Launches an Application **/
  // @text launchApp
  // @brief Launch an Application and app will be in ACTIVE state.
  // @param appId App identifier for the application.
  // @param intent(optional) Specifies the intent or message to be executed.
  // @param launchArgs(optional) Additional parameters passed to the application.
  virtual Core::hresult LaunchApp(const string& appId, const string& intent, const string& launchArgs) = 0;

  /** Preloads an Application **/
  // @text preloadApp
  // @brief Preloads an Application and app will be in the RUNNING state (hidden).
  // @param appId App identifier for the application.
  // @param launchArgs(optional) Additional parameters passed to the application.
  // @param error if success = false it holds the appropriate error reason.
  virtual Core::hresult PreloadApp(const string& appId, const string& launchArgs, string& error /* @out */) = 0;

  /** CloseApp moves the application from Active to Running state **/
  // @text closeApp
  // @brief closeApp moves the state from Active to Running state
  // @param appId App identifier for the application.
  virtual Core::hresult CloseApp(const string& appId) = 0;

  /** Terminate an Application gracefully **/
  // @text terminateApp
  // @brief TerminateApp will terminate gracefully
  // @param appId App identifier for the application.
  virtual Core::hresult TerminateApp(const string& appId) = 0;

  /** Start the system Application **/
  // @text startSystemApp
  // @brief Start the System Application
  // @param appId App identifier for the application.
  virtual Core::hresult StartSystemApp(const string& appId) = 0;

  /** Stop the system Application **/
  // @text stopSystemApp
  // @brief Stop the System Application
  // @param appId App identifier for the application.
  virtual Core::hresult StopSystemApp(const string& appId) = 0;

  /** Kill an application forcefully **/
  // @text killApp
  // @brief killApp will terminate forcefully
  // @param appId App identifier for the application.
  virtual Core::hresult KillApp(const string& appId) = 0;

  /** Sends an intent to a loaded app **/
  // @text sendIntent
  // @brief Sends an intent to a loaded app.
  // @param appId App identifier for the application.
  // @param intent Specifies the intent or message to be executed.
  virtual Core::hresult SendIntent(const string& appId, const string& intent) = 0;

  /** Clears all persistent data for a given app. **/
  // @text clearAppData
  // @brief Clears all persistent data for a given appId.
  // @param appId App identifier for the application.
  virtual Core::hresult ClearAppData(const string& appId) = 0;

  /** Clears all persistent data for all apps **/
  // @text clearAllAppData
  // @brief Clears all persistent data for all apps.
  virtual Core::hresult ClearAllAppData() = 0;

  /** Retrieves meta data about an installed app **/
  // @text getAppMetadata
  // @brief Retrieves meta data about an installed app
  // @param appId App identifier for the application.
  // @param metaData the name of the meta-data
  // @param result string holding json formatted app metadata
  virtual Core::hresult GetAppMetadata(const string& appId, const string& metaData, string& result /* @out */) = 0;

  /** Gets a property for a given app **/
  // @text getAppProperty
  // @brief Gets a property for a given app.
  // @param appId App identifier for the application.
  // @param key the name of the property to get
  // @param value the value of the key
  virtual Core::hresult GetAppProperty(const string& appId, const string& key, string& value /* @out */) = 0;

  /** Sets a property for a given app **/
  // @text setAppProperty
  // @brief Sets a property for a given app
  // @param appId App identifier for the application.
  // @param key the name of the property to get
  // @param value  the property value to set, this can be a boolean,number, string or object type
  virtual Core::hresult SetAppProperty(const string& appId, const string& key, const string& value) = 0;

  /** Gets the maximum number of apps to maintain in the running or suspended state **/
  // @property
  // @text getMaxRunningApps
  // @brief Gets the maximum number of apps to maintain in the running or suspended state
  // @param maxRunningApps max number of apps to maintain in the running or suspended state
  virtual Core::hresult GetMaxRunningApps(int32_t& maxRunningApps /* @out */) const = 0;

  /** Get the maximum number of apps to maintain in the hibernated state **/
  // @property
  // @text getMaxHibernatedApps
  // @brief Get the maximum number of apps to maintain in the hibernated state
  // @param maxHibernatedApps max number of apps to maintain in the hibernated state
  virtual Core::hresult GetMaxHibernatedApps(int32_t& maxHibernatedApps /* @out */) const = 0;

  /** Gets the max size of flash to use for hibernated apps. The value is in mebibytes **/
  // @property
  // @text getMaxHibernatedFlashUsage
  // @brief Gets the max size of flash to use for hibernated apps (in mebibytes)
  // @param maxHibernatedFlashUsage max size of flash to use for hibernated apps (in mebibytes)
  virtual Core::hresult GetMaxHibernatedFlashUsage(int32_t& maxHibernatedFlashUsage /* @out */) const = 0;

  /** Gets the max amount of ram available for inactive apps. The value is in mebibytes **/
  // @property
  // @text getMaxInactiveRamUsage
  // @brief Gets the max amount of ram available for inactive apps (in mebibytes)
  // @param maxInactiveRamUsage max ram available for inactive apps (in mebibytes)
  virtual Core::hresult GetMaxInactiveRamUsage(int32_t& maxInactiveRamUsage /* @out */) const = 0;
};
} // namespace Exchange
} // namespace WPEFramework
