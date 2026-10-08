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

// @stubgen:include <com/IIteratorType.h>

namespace WPEFramework {
namespace Exchange {
// @json 1.0.0 @text:keep
struct EXTERNAL IRDKWindowManager : virtual public Core::IUnknown {
  enum { ID = ID_RDK_WINDOW_MANAGER };
  using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
  // @event 
  struct EXTERNAL INotification : virtual public Core::IUnknown {
    enum { ID = ID_RDK_WINDOW_MANAGER_NOTIFICATION };
 
    // @brief Posting the client is inactive state
    // @details Notifies when the user has been inactive for a specified duration.
    // @text onUserInactivity
    // @param minutes: notify how long user is inactive state
    // @example minutes: 5
    virtual void OnUserInactivity(const double minutes){};

    // @brief Notifies when an application is disconnected
    // @details Notifies when an application is disconnected from the window manager.
    // @text onDisconnected
    // @param clientId: the identifier of the disconnected application
    // @example clientId: "application_123"
    virtual void OnDisconnected(const std::string& clientId){};

    // @brief Notifies when an application is ready for its first frame.
    // @details Indicates that the application has completed its initial setup and is ready to display its first frame.
    // @text onReady
    // @param clientId: notify first frame event received for client or application instance ID
    // @example clientId: "application_123"
    virtual void OnReady(const string &clientId){};

    // @brief Notifies when an application is connected
    // @details Indicates that the application has successfully connected to the window manager.
    // @text onConnected
    // @param clientId: the identifier of the connected application
    // @example clientId: "application_123"
    virtual void OnConnected(const std::string& clientId){};

    // @brief Notifies when an application is visible
    // @details Indicates that the application is currently visible in the window manager.
    // @text onVisible
    // @param clientId: the identifier of the visible application
    // @example clientId: "application_123"
    virtual void OnVisible(const std::string& clientId){};

    // @brief Notifies when an application is hidden
    // @details Indicates that the application is currently hidden in the window manager.
    // @text onHidden
    // @param clientId: the identifier of the hidden application
    // @example clientId: "application_123"
    virtual void OnHidden(const std::string& clientId){};

    // @brief Notifies when an application is in focus
    // @details Indicates that the application has gained focus in the window manager.
    // @text onFocus
    // @param clientId: the identifier of the focussed application
    // @example clientId: "application_123"
    virtual void OnFocus(const std::string& clientId){};

    // @brief Notifies when an application is blurred
    // @details Indicates that the application has lost focus in the window manager.
    // @text onBlur
    // @param clientId: the identifier of the blurred application
    // @example clientId: "application_123"
    virtual void OnBlur(const std::string& clientId){};

    // @brief Notifies when a screenshot capture is complete
    // @details Indicates that the screenshot capture process has completed, providing the success status and the captured image data.
    // @text onScreenshotComplete
    // @param success: Indicates whether the screenshot was captured successfully
    // @example success: true
    // @param imageData: Base64 encoded image data (PNG format)
    // @example imageData: "iVBORw0KGgoAAAANSUhEUgAA..."
    virtual void OnScreenshotComplete(const bool success, const std::string& imageData){};
  };

  /** Register notification interface */
  virtual Core::hresult Register(INotification *notification) = 0;
  /** Unregister notification interface */
  virtual Core::hresult Unregister(INotification *notification) = 0;

  /** Allow the plugin to initialize to use service object */
  // @brief Initializes the plugin using the host service.
  // @details Supplies the Thunder shell service required by the plugin during initialization.
  // @param service: Thunder plugin host shell service.
  // @example service: "ThunderShellService"
  // @retval Core::ERROR_NONE: The plugin was initialized successfully.
  // @json:omit
  virtual Core::hresult Initialize(PluginHost::IShell* service) = 0;

  /** Allow the plugin to deinitialize to use service object */
  // @brief Deinitializes the plugin using the host service.
  // @details Supplies the Thunder shell service while the plugin releases its initialized resources.
  // @param service: Thunder plugin host shell service.
  // @example service: "ThunderShellService"
  // @retval Core::ERROR_NONE: The plugin was deinitialized successfully.
  // @json:omit
  virtual Core::hresult Deinitialize(PluginHost::IShell* service) = 0;

  /** Create the display window */
  // @text createDisplay
  // @brief Create the display window
  // @details Creates a display window for the client with the specified parameters.
  // @param clientId: Client identifier
  // @example clientId: "org.example.app"
  // @param displayName: Name of Wayland display
  // @example displayName: "wayland-0"
  // @param displayWidth: Optional width of client window
  // @example displayWidth: 1280
  // @param displayHeight: Optional height of client window
  // @example displayHeight: 720
  // @param virtualDisplay: Optional flag indicating whether virtual display is enabled
  // @example virtualDisplay: false
  // @param virtualWidth: Optional width of display in framebuffer mode
  // @example virtualWidth: 0
  // @param virtualHeight: Optional height of display in framebuffer mode
  // @example virtualHeight: 0
  // @param ownerId: Optional UID of owner of Wayland socket
  // @example ownerId: 0
  // @param groupId: Optional group identifier of Wayland socket
  // @example groupId: 0
  // @param topmost: Optional flag indicating whether client window needs to be topmost
  // @example topmost: false
  // @param focus: Optional flag indicating whether the client needs focus
  // @example focus: true
  // @param capabilities: Optional JSON string containing the runtime capability tokens for the client
  // @example capabilities: "{}"
  // @retval Core::ERROR_NONE: Display window created successfully
  // @retval Core::ERROR_GENERAL: Failed to create the display window
  virtual Core::hresult CreateDisplay(const string &clientId, const string &displayName, const uint32_t displayWidth /* @optional */, const uint32_t displayHeight /* @optional */, const bool virtualDisplay /* @optional */, const uint32_t virtualWidth /* @optional */, const uint32_t virtualHeight /* @optional */, const uint32_t ownerId /* @optional */, const uint32_t groupId /* @optional */, const bool topmost /* @optional */, const bool focus /* @optional */, const string &capabilities /* @optional */) = 0;

  /** Get the list of active Apps */
  // @text getApps
  // @brief Get the list of Apps which are currently active and available
  // @details Returns identifiers for applications that are currently active and available to the window manager.
  // @param appsIds: Returns the list of active app IDs as a JSON array.
  // @example appsIds: ["org.example.app"]
  // @retval Core::ERROR_NONE: Active app IDs retrieved successfully
  // @retval Core::ERROR_GENERAL: Failed to retrieve active app IDs
  virtual Core::hresult GetApps(IStringIterator*& appsIds /* @out */) const = 0;

  /** Registers a key intercept for a specific key code and client */
  // @text addKeyIntercept
  // @brief Registers a key intercept for a specific key code and client
  // @details Configures a key intercept using the client and key information encoded in the JSON string.
  // @param intercept: JSON String format with the client/callSign, keyCode, modifiers
  // @example intercept: {"client":"org.example.app","keyCode":13,"modifiers":[]}
  // @retval Core::ERROR_NONE: The key intercept was registered successfully.
  virtual Core::hresult AddKeyIntercept(const string &intercept) = 0;
  
  /** Registers multiple key intercepts */
  // @text addKeyIntercepts
  // @brief Registers multiple key intercepts in a single operation for a specific client.
  // @details Registers the supplied set of key intercepts for the specified client in one operation.
  // @param clientId: The client identifier
  // @example clientId: "org.example.app"
  // @param intercepts: JSON String format containing the array of key intercepts (keyCode, modifiers, focusOnly, propagate) configuration
  // @example intercepts: [{"keyCode":13,"modifiers":[],"focusOnly":true,"propagate":false}]
  // @retval Core::ERROR_NONE: All provided key intercepts were registered successfully
  // @retval Core::ERROR_GENERAL: A general error occurred while registering one or more key intercepts
  virtual Core::hresult AddKeyIntercepts(const string &clientId, const string &intercepts) = 0;

  /** Removes a key intercept */
  // @text removeKeyIntercept
  // @brief Removes a key intercept for a specific key code and client.
  // @details Removes the key intercept matching the client, key code, and modifier configuration.
  // @param clientId: The client identifier
  // @example clientId: "org.example.app"
  // @param keyCode: The key code to remove
  // @example keyCode: 13
  // @param modifiers: JSON String format with one or more modifiers
  // @example modifiers: "CTRL"
  // @retval Core::ERROR_NONE: The key intercept was removed successfully.
  // @retval Core::ERROR_GENERAL: The intercept could not be removed due to an internal error.
  virtual Core::hresult RemoveKeyIntercept(const string& clientId, const uint32_t keyCode, const string& modifiers) = 0;
  
  /** Registers listeners for specific keys. */
  // @text addKeyListener
  // @brief Registers listeners for specific keys.
  // @details Registers the key listener definitions encoded in the supplied JSON string.
  // @param keyListeners: JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign
  // @example keyListeners: {"client":"org.example.app","keys":[{"keyCode":13}]}
  // @retval Core::ERROR_NONE: The key listeners were registered successfully.
  virtual Core::hresult AddKeyListener(const string &keyListeners) = 0;
  
  /** Removes listeners for specific keys. */
  // @text removeKeyListener
  // @brief Removes listeners for specific keys.
  // @details Removes the key listener definitions identified by the supplied JSON string.
  // @param keyListeners: JSON String format containing the keylisteneres with keys(keyCode,nativekeyCode,modifiers,activate,propagate) and client/callSign
  // @example keyListeners: {"client":"org.example.app","keys":[{"keyCode":13}]}
  // @retval Core::ERROR_NONE: The key listeners were removed successfully.
  virtual Core::hresult RemoveKeyListener(const string &keyListeners) = 0;
  
  /** Simulates a key press event with optional modifiers. */
  // @text injectKey
  // @brief Simulates a key press event with optional modifiers.
  // @details Injects the specified key code with the provided modifier configuration.
  // @param keyCode: Key code to inject.
  // @example keyCode: 13
  // @param modifiers: JSON string containing zero or more key modifiers.
  // @example modifiers: "CTRL"
  // @retval Core::ERROR_NONE: The key event was injected successfully.
  virtual Core::hresult InjectKey(uint32_t keyCode, const string &modifiers) = 0;

  /**  Generates a key event for the specified keys and client */
  // @text generateKey
  // @brief Generates a key event for the specified keys and client.
  // @details Generates the key events described by the JSON string on behalf of the specified client.
  // @param keys: JSON String format representing the key(s)(keyCode,modifiers,delay,client/callSign) to generate
  // @example keys: {"keys":[{"keyCode":13}]}
  // @param client: Name of the client/callSign requesting the key generation.
  // @example client: "org.example.app"
  // @retval Core::ERROR_NONE: The key event request was processed successfully.
  virtual Core::hresult GenerateKey(const string& keys, const string& client) = 0;

  /** Enables the inactivity reporting feature */
  // @text enableInactivityReporting
  // @brief Enables the inactivity reporting
  // @details Controls whether the window manager reports periods of user inactivity.
  // @param enable: flag to true/false the feature
  // @example enable: true
  // @retval Core::ERROR_NONE: The inactivity reporting setting was applied successfully.
  virtual Core::hresult EnableInactivityReporting(const bool enable) = 0;

  /** Set inactivity interval */
  // @text setInactivityInterval
  // @brief Sets inactivity interval if EnableUserInactivity feature is enabled
  // @details Sets the interval used to determine when the user is considered inactive.
  // @param interval: time interval set for inactivity
  // @example interval: 300
  // @retval Core::ERROR_NONE: The inactivity interval was set successfully.
  virtual Core::hresult SetInactivityInterval(const uint32_t interval) = 0;

  /** Resets inactivity interval */
  // @text resetInactivityTime
  // @brief Resets inactivity interval if EnableUserInactivity feature is enabled
  // @details Resets the inactivity timer so the current period starts over.
  // @retval Core::ERROR_NONE: The inactivity timer was reset successfully.
  virtual Core::hresult ResetInactivityTime() = 0;

  /** Enables/Disables key repeats */
  // @text enableKeyRepeats
  // @brief Key repeats are enabled/disabled
  // @details Enables or disables repeated key events while a key remains pressed.
  // @param enable: flag to true/false the key repeats
  // @example enable: true
  // @retval Core::ERROR_NONE: The key repeat setting was applied successfully.
  virtual Core::hresult EnableKeyRepeats(bool enable) = 0;

  /** Gets the keyrepeats enabled flag */
  // @text getKeyRepeatsEnabled
  // @brief Retrieves the flag determining whether keyRepeat true/false
  // @details Retrieves whether repeated key events are currently enabled.
  // @param keyRepeat: flag stating whether keyRepeat true/false
  // @example keyRepeat: true
  // @retval Core::ERROR_NONE: The key repeat setting was retrieved successfully.
  virtual Core::hresult GetKeyRepeatsEnabled(bool &keyRepeat /* @out */) const = 0;

  /** Ignore KeyInputs */
  // @text ignoreKeyInputs
  // @brief Ignore key inputs 
  // @details Sets whether key input events are ignored by the window manager.
  // @param ignore: flag stating whether key inputs ignored
  // @example ignore: true
  // @retval Core::ERROR_NONE: The key input handling setting was applied successfully.
  virtual Core::hresult IgnoreKeyInputs(bool ignore) = 0;

  /** Enables KeyInputEvents */
  // @text enableInputEvents
  // @brief Enables KeyInputEvents for list of clients specified
  // @details Enables or disables key input events for the specified clients.
  // @param clients: JSON string identifying the clients whose input events are controlled.
  // @example clients: "[\"org.example.app\"]"
  // @param enable: Whether to enable or disable input events for those clients.
  // @example enable: true
  // @retval Core::ERROR_NONE: The input event setting was applied successfully.
  virtual Core::hresult EnableInputEvents(const string &clients, bool enable) = 0;

  /** Configuration for keyrepeat */
  // @text keyRepeatConfig
  // @brief Enables KeyInputEvents for list of clients specified
  // @details Applies key repeat configuration for the specified input type.
  // @param input: input type (default/keyboard)
  // @example input: "keyboard"
  // @param keyConfig: JSON String format with enabled, initialDelay and repeatInterval
  // @example keyConfig: "{\"enabled\":true,\"initialDelay\":500,\"repeatInterval\":50}"
  // @retval Core::ERROR_NONE: The key repeat configuration was applied successfully.
  virtual Core::hresult KeyRepeatConfig(const string &input, const string &keyConfig) = 0;

  /** Sets the focus to the app with the app id */
  // @text setFocus
  // @brief Sets the focus to the app with the app id
  // @details Requests that the specified application receive input focus.
  // @param client: Client name or application instance ID
  // @example client: "rdkwmtestapp_13193"
  // @retval Core::ERROR_NONE: Focus was assigned successfully.
  virtual Core::hresult SetFocus(const string &client) = 0;

  /** Sets the visibility of the given client or appInstanceId */
  // @text setVisible
  // @brief Sets the visibility of the given client or appInstanceId
  // @details Shows or hides the specified client window.
  // @param client: client name or application instance ID
  // @example client: "org.example.app"
  // @param visible: boolean indicating the visibility status: `true` for visible, `false` for hide.
  // @example visible: true
  // @retval Core::ERROR_NONE: The client visibility was updated successfully.
  virtual Core::hresult SetVisible(const std::string &client, bool visible) = 0;

  /** Gets the visibility of the given client or appInstanceId */
  // @text getVisibility
  // @brief Gets the visibility of the given client or appInstanceId
  // @details Retrieves whether the specified client window is visible.
  // @param client: client name or application instance ID
  // @example client: "org.example.app", status: true
  // @param visible: boolean indicating the visibility status: `true` for visible, `false` for hide.
  // @example visible: true
  // @retval Core::ERROR_NONE on success
  virtual Core::hresult GetVisibility(const std::string &client, bool &visible /* @out */) = 0;

  /** Get the first-frame rendered status of the application */
  // @json:omit
  // @brief To get the status of first frame is rendered or not
  // @details Checks whether the specified application has rendered its first frame.
  // @param client: client name or application instance ID
  // @example client: "org.example.app" 
  // @param status: Returns true if the application has rendered first frame, false if it has not yet.
  // @example status: true
  // @retval Core::ERROR_NONE: The first-frame status was retrieved successfully.
  virtual Core::hresult RenderReady(const string& client, bool &status /* @out */) const = 0;

  /** To enable/disable the rendering of a Wayland display in the window manager */
  // @json:omit
  // @brief Enable or disable the rendering of a Wayland display
  // @details Controls whether rendering is enabled for the specified Wayland display.
  // @param client: client name or application instance ID
  // @example client: "org.example.app"
  // @param enable: flag to true/false for controlling the wayland render
  // @example enable: true
  // @retval Core::ERROR_NONE: The display rendering setting was applied successfully.
  virtual Core::hresult EnableDisplayRender(const string& client, bool enable) = 0;

  // @text getLastKeyInfo
  // @brief Retrieves information about the most recent key press event, including the key code, modifier flags, and the timestamp in seconds when the key was pressed.
  // @details Returns the key information recorded for the most recent key press.
  // @param keyCode: Output parameter. The key code of the last pressed key.
  // @example keyCode: 13
  // @param modifiers: Output parameter. The modifier flags (e.g., Shift, Ctrl) active during the last key press.
  // @example modifiers: 1
  // @param timestampInSeconds: Output parameter. The timestamp (in seconds) when the last key press occurred.
  // @example timestampInSeconds: 1710000000
  // @retval Core::ERROR_NONE: Successfully retrieved the last key press information.
  // @retval Core::ERROR_UNAVAILABLE: No key press information is available.
  virtual Core::hresult GetLastKeyInfo(uint32_t &keyCode /* @out */, uint32_t &modifiers /* @out */, uint64_t &timestampInSeconds /* @out */) const = 0;

  /** Sets the zOrder of the given client or appInstanceId */
  // @text setZOrder
  // @brief Sets the zOrder of the given client or appInstanceId
  // @details Assigns the specified stacking order to the client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param zOrder: integer value indicating the zOrder
  // @example zOrder: 2
  // @retval Core::ERROR_NONE on success
  virtual Core::hresult SetZOrder(const string& clientId, const int32_t zOrder) = 0;

  /** Gets the zOrder of the given client or appInstanceId */
  // @text getZOrder
  // @brief Gets the zOrder of the given client or appInstanceId
  // @details Retrieves the stacking order of the specified client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param zOrder: integer value indicating the zOrder of the client
  // @example zOrder: 2
  // @retval Core::ERROR_NONE on success
  virtual Core::hresult GetZOrder(const string& clientId, int32_t &zOrder /* @out */) = 0;

  /** Starts the VNC server */
  // @text startVncServer
  // @brief Starts the VNC server
  // @details Starts remote screen access through the VNC server.
  // @retval Core::ERROR_NONE on success
  virtual Core::hresult StartVncServer() = 0;

  /** Stops the VNC server */
  // @text stopVncServer
  // @brief Stops the VNC server
  // @details Stops remote screen access through the VNC server.
  // @retval Core::ERROR_NONE on success
  virtual Core::hresult StopVncServer() = 0;

  /** Gets the currently focused application */
  // @text getFocused
  // @brief Gets the identifier of the currently focused application
  // @details Retrieves the identifier of the application that currently has input focus.
  // @param client: Output parameter. The identifier of the currently focused application
  // @example client: "org.example.app"
  // @retval Core::ERROR_NONE: Successfully retrieved the focused application identifier
  // @retval Core::ERROR_GENERAL: Failed to retrieve the focused application identifier
  virtual Core::hresult GetFocused(string &client /* @out */) const = 0;

  /** Captures a screenshot of the current compositor output */
  // @text getScreenshot
  // @brief Captures the entire screen buffer as Base64 encoded image data (PNG format). The screenshot is returned asynchronously via the onScreenshotComplete event.
  // @details Starts an asynchronous screenshot capture; the result is delivered through the onScreenshotComplete notification.
  // @retval Core::ERROR_NONE on success
  // @retval Core::ERROR_GENERAL on failure
  virtual Core::hresult GetScreenshot() = 0;

  /** Sets an alias name for the given client identifier */
  // @text setAlias
  // @brief Sets the alias name for the given client identifier
  // @details Associates the specified alias with a client identifier.
  // @param clientId: client identifier
  // @example clientId: "org.example.app"
  // @param alias: alias name for the given client identifier
  // @example alias: "home-screen"
  // @retval Core::ERROR_NONE: Operation completed successfully
  // @retval Core::ERROR_GENERAL: Operation failed
  virtual Core::hresult SetAlias(const string& clientId, const string& alias) = 0;

  /** Show or hide the splash screen */
  // @text showSplashScreen
  // @brief Shows or hides the splash screen in the window manager
  // @details Sets the splash screen visibility according to the supplied flag.
  // @param show: boolean indicating whether to show (true) or hide (false) the splash screen
  // @example show: true
  // @retval Core::ERROR_NONE: Operation completed successfully
  // @retval Core::ERROR_GENERAL: Operation failed
  virtual Core::hresult ShowSplashScreen(const bool show) = 0;

  /** Sets the bounds (position and size) of the given client */
  // @text setBounds
  // @brief Sets the x, y position and width, height dimensions of the given client
  // @details Sets the position and dimensions of the specified client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param x: x coordinate of the client window
  // @example x: 0
  // @param y: y coordinate of the client window
  // @example y: 0
  // @param width: width of the client window in pixels
  // @example width: 1280
  // @param height: height of the client window in pixels
  // @example height: 720
  // @retval Core::ERROR_NONE: Bounds set successfully
  // @retval Core::ERROR_GENERAL: Failed to set bounds
  virtual Core::hresult SetBounds(const string& clientId, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height) = 0;

  /** Gets the bounds (position and size) of the given client */
  // @text getBounds
  // @brief Gets the x, y position and width, height dimensions of the given client
  // @details Retrieves the position and dimensions of the specified client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param x: x coordinate of the client window
  // @example x: 0
  // @param y: y coordinate of the client window
  // @example y: 0
  // @param width: width of the client window in pixels
  // @example width: 1280
  // @param height: height of the client window in pixels
  // @example height: 720
  // @retval Core::ERROR_NONE: Bounds retrieved successfully
  // @retval Core::ERROR_GENERAL: Failed to get bounds
  virtual Core::hresult GetBounds(const string& clientId, uint32_t& x /* @out */, uint32_t& y /* @out */, uint32_t& width /* @out */, uint32_t& height /* @out */) const = 0;

  /** Sets the scale of the given client */
  // @text setScale
  // @brief Sets the horizontal and vertical scale factors of the given client
  // @details Applies horizontal and vertical scale factors to the specified client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param scaleX: horizontal scale factor
  // @example scaleX: 1.0
  // @param scaleY: vertical scale factor
  // @example scaleY: 1.0
  // @retval Core::ERROR_NONE: Scale set successfully
  // @retval Core::ERROR_GENERAL: Failed to set scale
  virtual Core::hresult SetScale(const string& clientId, const double scaleX, const double scaleY) = 0;

  /** Gets the scale of the given client */
  // @text getScale
  // @brief Gets the horizontal and vertical scale factors of the given client
  // @details Retrieves the horizontal and vertical scale factors of the specified client window.
  // @param clientId: client name or application instance ID
  // @example clientId: "org.example.app"
  // @param scaleX: horizontal scale factor
  // @example scaleX: 1.0
  // @param scaleY: vertical scale factor
  // @example scaleY: 1.0
  // @retval Core::ERROR_NONE: Scale retrieved successfully
  // @retval Core::ERROR_GENERAL: Failed to get scale
  virtual Core::hresult GetScale(const string& clientId, double& scaleX /* @out */, double& scaleY /* @out */) const = 0;

};
} // namespace Exchange
} // namespace WPEFramework
