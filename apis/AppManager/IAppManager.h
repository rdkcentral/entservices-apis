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
    std::string logLevels /* @text logLevels */ /* @brief JSON array of strings representing enabled log levels */;
    bool mapi {false};
    std::string fkpsFiles /* @text fkpsFiles */ /* @brief JSON array of strings identifying FKPS files */;
    std::string capabilities /* @text capabilities */ /* @brief Comma-separated lowercase runtime capability tokens */;
    std::string ralfPkgPath /* @text ralfPkgPath */ /* @brief Filesystem path containing metadata information for RALF packages */;

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

  struct EXTERNAL LoadedAppInfo {
          string appId /* @text appId */
              /* @brief App identifier for the application */;

          string appInstanceId /* @text appInstanceId */
              /* @brief A numerical identifier for a specific instance of the application */;

          string activeSessionId /* @text activeSessionId */
              /* @brief Identifier for the active session associated with the application instance */;

          string type /* @text type */
              /* @brief The type or category of the application */;

          AppLifecycleState targetLifecycleState /* @text targetLifecycleState */
              /* @brief The desired lifecycle state that the application is transitioning to */;

          AppLifecycleState lifecycleState /* @text lifecycleState */
              /* @brief The current lifecycle state of the application instance */;
      };
  using ILoadedAppInfoIterator = RPC::IIteratorType<LoadedAppInfo,ID_LOADED_APP_INFO_ITERATOR>;

  // @event
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_APPMANAGER_NOTIFICATION };

    // @text onAppInstalled
    // @brief Triggered whenever the App is installed.
    // @details This event is triggered whenever a new application is successfully installed on the system.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.myapp"
    // @param version: The version number of the application in string format
    // @example version: "1.0.0"   
    virtual void OnAppInstalled(const string& appId, const string& version){};

    // @text onAppUninstalled
    // @brief Triggered whenever the App is uninstalled.
    // @details This event is triggered whenever an application is successfully uninstalled from the system.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.myapp"
    virtual void OnAppUninstalled(const string& appId){};

    // @text onAppLifecycleStateChanged
    // @brief Triggered whenever there is a change in the lifecycle state of a running app.
    // @details This event is triggered whenever there is a change in the lifecycle state of a running application.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.myapp"
    // @param appInstanceId:A numerical identifier for a specific instance of the application.
    // @example appInstanceId: "12345"
    // @param newState:The new state to transition the application.
    // @example newState: AppLifecycleState::Running
    // @param oldState:The previous state of the application instance before the update.
    // @example oldState: AppLifecycleState::Stopped
    // @param errorReason:The reason for any error encountered during the state transition
    // @example errorReason: AppErrorReason::None
    virtual void OnAppLifecycleStateChanged(const string& appId, const string& appInstanceId, const AppLifecycleState newState, const AppLifecycleState oldState, const AppErrorReason errorReason){};

    // @text onAppLaunchRequest
    // @brief Triggered whenever there is a request for App Launch.
    // @details This event is triggered whenever there is a request to launch an application.
    // @param appId:App identifier for the application.
    // @example appId: "com.example.myapp"
    // @param intent:A reference to the intent string that specifies the action or request to be processed.
    // @example intent: "com.example.myapp.action.VIEW"
    // @param source:A string indicating the source of the intent
    // @example source: "com.example.myapp"
    virtual void OnAppLaunchRequest(const string& appId, const string& intent, const string& source){};

    // @text onAppUnloaded
    // @brief Triggered whenever the App is unloaded(terminated).
    // @details This event is triggered whenever an application is unloaded (terminated).
    // @param appId:App identifier for the application.
    // @example appId: "com.example.myapp"
    // @param appInstanceId:A numerical identifier for a specific instance of the application.
    // @example appInstanceId: "12345"
    virtual void OnAppUnloaded(const string& appId, const string& appInstanceId){};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  /** Retrieves a list of all installed applications on the system. **/
  // @text getInstalledApps
  // @brief Function fetches the details of all applications currently installed
  // @details This function retrieves the details of all applications currently installed on the system.
  // @param apps A list containing the details of installed applications.
  // @example apps: "[{\"appId\": \"com.example.myapp\", \"name\": \"My App\"}]"
  // @retval Core::ERROR_NONE: Successfully retrieved the list of installed applications
  virtual Core::hresult GetInstalledApps(string& apps /* @out @opaque */) = 0;

  /** Check the specific application is installed on the system. **/
  // @text isInstalled
  // @brief check whether the Application is installed or not
  // @details This function checks whether a specific application is installed on the system.
  // @param appId: App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param installed : If it is installed then return true otherwise false
  // @example installed: true
  // @retval Core::ERROR_NONE: Successfully determined if the application is installed
  virtual Core::hresult IsInstalled(const string& appId, bool& installed /* @out */) = 0;

  /** Retrieves a list of all Loaded applications on the system. **/
  // @text getLoadedApps
  // @brief Retrieves a list of applications currently loaded on the system.
  // @details This function retrieves the details of all applications currently loaded on the system.
  // @param apps A list containing the details of loaded applications
  // @example apps: "[{\"appId\": \"com.example.myapp\", \"name\": \"My App\"}]"
  // @retval Core::ERROR_NONE: Successfully retrieved the list of loaded applications
  virtual Core::hresult GetLoadedApps(ILoadedAppInfoIterator*& apps /* @out */) = 0;

  /** Launches an Application **/
  // @text launchApp
  // @brief Launch an Application and app will be in ACTIVE state.
  // @details This function launches the specified application and moves it to the ACTIVE state.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param intent(optional) Specifies the intent or message to be executed.
  // @example intent: "com.example.myapp.intent"
  // @param launchArgs(optional) Additional parameters passed to the application.
  // @example launchArgs: "--fullscreen"
  // @retval Core::ERROR_NONE: Successfully launched the application
  virtual Core::hresult LaunchApp(const string& appId, const string& intent, const string& launchArgs) = 0;

  /** Preloads an Application **/
  // @text preloadApp
  // @brief Preloads an Application and app will be in the RUNNING state (hidden).
  // @details This function preloads the specified application and moves it to the RUNNING state (hidden).
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param intent(optional) Specifies the intent or message to be available during preload.
  // @example intent: "com.example.myapp.intent"
  // @param launchArgs(optional) Additional parameters passed to the application.
  // @example launchArgs: "--fullscreen"
  // @param error: Output parameter populated with the error reason when the method returns a failure through Core::hresult
  // @example error: "Failed to preload application due to missing resources."
  // @retval Core::ERROR_NONE: Application was preloaded successfully.
  // @retval Core::ERROR_GENERAL: Preload failed.
  virtual Core::hresult PreloadApp(const string& appId, const string& intent, const string& launchArgs, string& error /* @out */) = 0;

  /** CloseApp moves the application from Active to Running state **/
  // @text closeApp
  // @brief closeApp moves the state from Active to Running state
  // @details This function closes the specified application and moves it from the Active state to the Running state (hidden).
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: Application was closed successfully.
  virtual Core::hresult CloseApp(const string& appId) = 0;

  /** Terminate an Application gracefully **/
  // @text terminateApp
  // @brief TerminateApp will terminate gracefully
  // @details This function terminates the specified application gracefully.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: Application was terminated successfully.
  virtual Core::hresult TerminateApp(const string& appId) = 0;

  /** Start the system Application **/
  // @text startSystemApp
  // @brief Start the System Application
  // @details This function starts the specified system application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: System application was started successfully.
  virtual Core::hresult StartSystemApp(const string& appId) = 0;

  /** Stop the system Application **/
  // @text stopSystemApp
  // @brief Stop the System Application
  // @details This function stops the specified system application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: System application was stopped successfully.
  virtual Core::hresult StopSystemApp(const string& appId) = 0;

  /** Kill an application forcefully **/
  // @text killApp
  // @brief killApp will terminate forcefully
  // @details This function forcefully terminates the specified application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: Application was killed successfully.
  virtual Core::hresult KillApp(const string& appId) = 0;

  /** Sends an intent to a loaded app **/
  // @text sendIntent
  // @brief Sends an intent to a loaded app.
  // @details This function sends an intent or message to the specified application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param intent Specifies the intent or message to be executed.
  // @example intent: "com.example.myapp.ACTION_DO_SOMETHING"
  // @retval Core::ERROR_NONE: Intent was sent successfully.
  virtual Core::hresult SendIntent(const string& appId, const string& intent) = 0;

  /** Clears all persistent data for a given app. **/
  // @text clearAppData
  // @brief Clears all persistent data for a given appId.
  // @details This function clears all persistent data for the specified application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @retval Core::ERROR_NONE: App data was cleared successfully.
  virtual Core::hresult ClearAppData(const string& appId) = 0;

  /** Clears all persistent data for all apps **/
  // @text clearAllAppData
  // @brief Clears all persistent data for all apps.
  // @details This function clears all persistent data for all installed applications.
  // @retval Core::ERROR_NONE: All app data was cleared successfully.
  virtual Core::hresult ClearAllAppData() = 0;

  /** Retrieves meta data about an installed app **/
  // @text getAppMetadata
  // @brief Retrieves meta data about an installed app
  // @details This function retrieves meta data about the specified application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param metaData the name of the meta-data
  // @example metaData: "com.example.myapp.META_DATA_KEY"
  // @param result string holding json formatted app metadata
  // @example result: "{\"key\":\"value\"}"
  // @retval Core::ERROR_NONE: Metadata was retrieved successfully.
  virtual Core::hresult GetAppMetadata(const string& appId, const string& metaData, string& result /* @out */) = 0;

  /** Gets a property for a given app **/
  // @text getAppProperty
  // @brief Gets a property for a given app.
  // @details This function retrieves the value of the specified property for the given application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param key the name of the property to get
  // @example key: "com.example.myapp.PROPERTY_KEY"
  // @param value the value of the key
  // @example value: "some_value"
  // @retval Core::ERROR_NONE: Property was retrieved successfully.
  virtual Core::hresult GetAppProperty(const string& appId, const string& key, string& value /* @out */) = 0;

  /** Sets a property for a given app **/
  // @text setAppProperty
  // @brief Sets a property for a given app
  // @details This function sets the value of the specified property for the given application.
  // @param appId App identifier for the application.
  // @example appId: "com.example.myapp"
  // @param key the name of the property to get
  // @example key: "com.example.myapp.PROPERTY_KEY"
  // @param value  the property value to set, this can be a boolean,number, string or object type
  // @example value: "some_value"
  // @retval Core::ERROR_NONE: Property was set successfully.
  virtual Core::hresult SetAppProperty(const string& appId, const string& key, const string& value) = 0;

  /** Gets the maximum number of apps to maintain in the running or suspended state **/
  // @property
  // @text getMaxRunningApps
  // @brief Gets the maximum number of apps to maintain in the running or suspended state
  // @details This function retrieves the maximum number of apps that can be maintained in the running or suspended state.
  // @param maxRunningApps: max number of apps to maintain in the running or suspended state
  // @example maxRunningApps: 10
  // @retval Core::ERROR_NONE: Property was retrieved successfully.
  virtual Core::hresult GetMaxRunningApps(int32_t& maxRunningApps /* @out */) const = 0;

  /** Get the maximum number of apps to maintain in the hibernated state **/
  // @property
  // @text getMaxHibernatedApps
  // @brief Get the maximum number of apps to maintain in the hibernated state
  // @details This function retrieves the maximum number of apps that can be maintained in the hibernated state.
  // @param maxHibernatedApps: max number of apps to maintain in the hibernated state
  // @example maxHibernatedApps: 5
  // @retval Core::ERROR_NONE: Property was retrieved successfully. 
  virtual Core::hresult GetMaxHibernatedApps(int32_t& maxHibernatedApps /* @out */) const = 0;

  /** Gets the max size of flash to use for hibernated apps. The value is in mebibytes **/
  // @property
  // @text getMaxHibernatedFlashUsage
  // @brief Gets the max size of flash to use for hibernated apps (in mebibytes)
  // @details This function retrieves the maximum size of flash that can be used for hibernated apps. 
  // @param maxHibernatedFlashUsage: max size of flash to use for hibernated apps (in mebibytes)
  // @example maxHibernatedFlashUsage: 1024
  // @retval Core::ERROR_NONE: Property was retrieved successfully.
  virtual Core::hresult GetMaxHibernatedFlashUsage(int32_t& maxHibernatedFlashUsage /* @out */) const = 0;

  /** Gets the max amount of ram available for inactive apps. The value is in mebibytes **/
  // @property
  // @text getMaxInactiveRamUsage
  // @brief Gets the max amount of ram available for inactive apps (in mebibytes)
  // @details This function retrieves the maximum amount of RAM that can be used for inactive apps.
  // @param maxInactiveRamUsage: max ram available for inactive apps (in mebibytes)
  // @example maxInactiveRamUsage: 512
  // @retval Core::ERROR_NONE: Property was retrieved successfully.
  virtual Core::hresult GetMaxInactiveRamUsage(int32_t& maxInactiveRamUsage /* @out */) const = 0;
};
} // namespace Exchange
} // namespace WPEFramework
