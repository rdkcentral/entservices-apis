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
// @json 1.0.0 @text:keep
struct EXTERNAL IRDKWindowManager : virtual public Core::IUnknown {
  enum { ID = ID_RDK_WINDOW_MANAGER };

  // @event 
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_RDK_WINDOW_MANAGER_NOTIFICATION };
 
    // @brief Posting the client is inactive state
    // @text onUserInactivity
    // @param minutes: notify how long user is inactive state
    virtual void OnUserInactivity(const double minutes){};

    // @brief Notifies when an application is disconnected
    // @text onDisconnected
    // @param client: the identifier of the disconnected application
    virtual void OnDisconnected(const std::string& client){};

    // @brief Posting the client for first frame ready.
    // @text onReady
    // @param client: notify first frame event received for client or application instance ID
    virtual void OnReady(const string &client){};

    // @brief Notifies when an application is connected
    // @text onConnected
    // @param appInstanceId: the identifier of the connected application
    virtual void OnConnected(const std::string& appInstanceId){};

    // @brief Notifies when an application is visible
    // @text onVisible
    // @param appInstanceId: the identifier of the visible application
    virtual void OnVisible(const std::string& appInstanceId){};

    // @brief Notifies when an application is hidden
    // @text OnHidden
    // @param appInstanceId: the identifier of the hidden application
    virtual void OnHidden(const std::string& appInstanceId){};

    // @brief Notifies when an application is in focus
    // @text OnFocus
    // @param appInstanceId: the identifier of the focussed application
    virtual void OnFocus(const std::string& appInstanceId){};

    // @brief Notifies when an application is blurred
    // @text OnBlur
    // @param appInstanceId: the identifier of the blurred application
    virtual void OnBlur(const std::string& appInstanceId){};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  /** Allow the plugin to initialize to use service object */
  // @json:omit
  virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

  /** Allow the plugin to deinitialize to use service object */
  // @json:omit
  virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

  /** Create the display window */
  // @text createDisplay
  // @brief Create the display window
  // @param displayParams: JSON String format with client,displayName,displayWidth,displayHeight,virtualDisplay,virtualWidth,virtualHeight,topmost,focus
  virtual Core::hresult CreateDisplay(const string& displayParams) = 0;

  /** Get the list of active Apps */
  // @text getApps
  // @brief Get the list of Apps which are currently active and available
  // @param appsIds: Returns the list of app IDs as a JSON string.
  virtual Core::hresult GetApps(string &appsIds /* @out */) const = 0;

  /** Registers a key intercept for a specific key code and client */
  // @text addKeyIntercept
  // @brief Registers a key intercept for a specific key code and client
  // @param intercept: JSON String format with the client/callSign, keyCode, modifiers
  virtual Core::hresult AddKeyIntercept(const string &intercept) = 0;
  
  /** Registers multiple key intercepts */
  // @text addKeyIntercepts
  // @brief Registers multiple key intercepts in a single operation.
  // @param intercepts: JSON String format containing the array of key intercept(client/callSign, keyCode, modifiers) configuration 
  virtual Core::hresult AddKeyIntercepts(const string &intercepts) = 0;

  /** Removes a key intercept */
  // @text removeKeyIntercept
  // @brief Removes a key intercept for a specific key code and client.
  // @param intercept: JSON String format with the client/callSign, keyCode, modifiers
  virtual Core::hresult RemoveKeyIntercept(const string &intercept) = 0;
  
  /** Registers listeners for specific keys. */
  // @text addKeyListener
  // @brief Registers listeners for specific keys.
  // @param keyListeners: JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign
  virtual Core::hresult AddKeyListener(const string &keyListeners) = 0;
  
  /** Removes listeners for specific keys. */
  // @text removeKeyListener
  // @brief Removes listeners for specific keys.
  // @param keyListeners: JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign
  virtual Core::hresult RemoveKeyListener(const string &keyListeners) = 0;
  
  /** Simulates a key press event with optional modifiers. */
  // @text injectKey
  // @brief Simulates a key press event with optional modifiers.
  // @param keyCode: Key code to be injected, modifiers :  JSON String format with one or more modifiers
  virtual Core::hresult InjectKey(uint32_t keyCode, const string &modifiers) = 0;

  /**  Generates a key event for the specified keys and client */
  // @text generateKey
  // @brief Generates a key event for the specified keys and client.
  // @param keys: JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate
  // @param client: Name of the client/callSign requesting the key generation.
  virtual Core::hresult GenerateKey(const string& keys, const string& client) = 0;

  /** Enables the inactivity reporting feature */
  // @text enableInactivityReporting
  // @brief Enables the inactivity reporting
  // @param enable: flag to true/false the feature
  virtual Core::hresult EnableInactivityReporting(const bool enable) = 0;

  /** Set inactivity interval */
  // @text setInactivityInterval
  // @brief Sets inactivity interval if EnableUserInactivity feature is enabled
  // @param interval: time interval set for inactivity
  virtual Core::hresult SetInactivityInterval(const uint32_t interval) = 0;

  /** Resets inactivity interval */
  // @text resetInactivityTime
  // @brief Resets inactivity interval if EnableUserInactivity feature is enabled
  virtual Core::hresult ResetInactivityTime() = 0;

  /** Enables/Disables key repeats */
  // @text enableKeyRepeats
  // @brief Key repeats are enabled/disabled
  // @param enable: flag to true/false the key repeats
  virtual Core::hresult EnableKeyRepeats(bool enable) = 0;

  /** Gets the keyrepeats enabled flag */
  // @text getKeyRepeatsEnabled
  // @brief Retrieves the flag determining whether keyRepeat true/false
  // @param keyRepeat: flag stating whether keyRepeat true/false
  virtual Core::hresult GetKeyRepeatsEnabled(bool &keyRepeat /* @out */) const = 0;

  /** Ignore KeyInputs */
  // @text ignoreKeyInputs
  // @brief Ignore key inputs 
  // @param ignore: flag stating whether key inputs ignored
  virtual Core::hresult IgnoreKeyInputs(bool ignore) = 0;

  /** Enables KeyInputEvents */
  // @text enableInputEvents
  // @brief Enables KeyInputEvents for list of clients specified
  // @param clients: JSON String format with number of clients, enable:Flag to enable input events
  virtual Core::hresult EnableInputEvents(const string &clients, bool enable) = 0;

  /** Configuration for keyrepeat */
  // @text keyRepeatConfig
  // @brief Enables KeyInputEvents for list of clients specified
  // @param input: input type (default/keyboard)
  // @param keyConfig: JSON String format with enabled, initialDelay and repeatInterval
  virtual Core::hresult KeyRepeatConfig(const string &input, const string &keyConfig) = 0;

  /** Sets the focus to the app with the app id */
  // @text setFocus
  // @brief Sets the focus to the app with the app id
  // @param client/appInstanceId: Client/Application instance ID as a plain string (e.g., "rdkwmtestapp_13193")
  virtual Core::hresult SetFocus(const string &client) = 0;

  /** Sets the visibility of the given client or appInstanceId */
  // @text setVisible
  // @brief Sets the visibility of the given client or appInstanceId
  // @param client: client name or application instance ID
  // @param visible: boolean indicating the visibility status: `true` for visible, `false` for hide.
  virtual Core::hresult SetVisible(const std::string &client, bool visible) = 0;

  /** Get the first-frame rendered status of the application */
  // @text renderReady
  // @brief To get the status of first frame is rendered or not
  // @param client: client name or application instance ID
  // @param status: Returns true if the application has rendered first frame, false if it has not yet.
  virtual Core::hresult RenderReady(const string& client, bool &status /* @out */) const = 0;

  /** To enable/disable the rendering of a Wayland display in the window manager */
  // @text enableDisplayRender
  // @brief Enable or disable the rendering of a Wayland display
  // @param client: client name or application instance ID
  // @param enable: flag to true/false for controlling the wayland render
  virtual Core::hresult EnableDisplayRender(const string& client, bool enable) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
