/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 Metrological
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

    // This interface gives direct access to a Browser to change
    // Browser specific properties like displayed URL.

    struct EXTERNAL IBrowser : virtual public Core::IUnknown {
        enum { ID = ID_BROWSER };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_BROWSER_NOTIFICATION };

            // Signal changes on the subscribed namespace..
            // @brief Notifies that the browser finished loading a URL.
            // @details The notification is sent after the requested page has finished loading.
            // @param URL: URL that finished loading
            // @example URL: "https://example.com"
            virtual void LoadFinished(const string& URL) = 0;

            // @brief Notifies that the browser URL changed.
            // @details The new URL may represent a navigation request or the currently displayed page.
            // @param URL: Updated browser URL
            // @example URL: "https://example.com"
            virtual void URLChanged(const string& URL) = 0;

            // @brief Notifies that the browser visibility changed.
            // @details Indicates whether the browser is hidden or visible.
            // @param hidden: True when the browser is hidden
            // @example hidden: true
            virtual void Hidden(const bool hidden) = 0;

            // @brief Notifies that the browser window closed.
            // @details Sent when the browser reports closure.
            virtual void Closure() = 0;
        };

        virtual void Register(IBrowser::INotification* sink) = 0;
        virtual void Unregister(IBrowser::INotification* sink) = 0;

        // Change the currently displayed URL by the browser.
        // @brief Changes the URL displayed by the browser.
        // @details Requests navigation to the specified URL.
        // @param URL: URL to display
        // @example URL: "https://example.com"
        virtual void SetURL(const string& URL) = 0;

        // @brief Retrieves the URL displayed by the browser.
        // @details Returns the browser's current URL.
        virtual string GetURL() const = 0;

        // @brief Retrieves the browser rendering frame rate.
        // @details Reports the current frames per second value.
        virtual uint32_t GetFPS() const = 0;

        // @brief Sets browser hidden state.
        // @details Hides or shows the browser according to the supplied flag.
        // @param hidden: True to hide the browser; false to show it
        // @example hidden: true
        virtual void Hide(const bool hidden) = 0;
    };

    // @json @uncompliant:extended  // NOTE: extended format is deprecated!! Do not just copy this line!
    struct EXTERNAL IWebBrowser : virtual public Core::IUnknown {
        enum { ID = ID_WEB_BROWSER };

        enum VisibilityType : uint8_t {
            HIDDEN = 0 /* @text:hidden */,
            VISIBLE = 1 /* @text:visible */,
        };

        enum HTTPCookieAcceptPolicyType : uint8_t {
            ALWAYS = 0 /* @text:always */,
            NEVER  = 1 /* @text:never */,
            ONLY_FROM_MAIN_DOCUMENT_DOMAIN = 2 /* @text:onlyfrommaindocumentdomain */,
            EXCLUSIVELY_FROM_MAIN_DOCUMENT_DOMAIN = 3 /* @text:exclusivelyfrommaindocumentdomain */
        };
        
        // @event @uncompliant:extended  // NOTE: extended format is deprecated!! Do not just copy this line!
        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_WEBKITBROWSER_NOTIFICATION };

            // Signal changes on the subscribed namespace..
            // @brief Initial HTML document has been completely loaded and parsed
            // @details Indicates completion of loading and parsing the main HTML document.
            // @param URL: The URL that has been loaded (e.g. https://example.com)
            // @example URL: "https://example.com"
            // @param httpstatus: The response code of main resource request (e.g. 200)
            // @example httpstatus: 200
            virtual void LoadFinished(const string& URL, const int32_t httpstatus) = 0;
           
            // @brief Browser failed to load page
            // @details Indicates that navigation to the requested page did not complete successfully.
            // @param URL: The URL that has been failed to load (e.g. https://example.com)
            // @example URL: "https://example.com"
            virtual void LoadFailed(const string& URL) = 0;

            // @brief Signals a URL change in the browser
            // @details Reports the new URL and whether its content has finished loading.
            // @param URL: The URL that has been loaded or requested (e.g. https://example.com)
            // @example URL: "https://example.com"
            // @param loaded: loaded (true) or not (false)
            // @example loaded: true
            virtual void URLChange(const string& URL, const bool loaded) = 0;
            
            // @brief Signals a visibility change of the browser
            // @details Sent when the browser transitions between hidden and visible states.
            // @param hidden hidden (true) or visible (false)
            // @example hidden: false
            virtual void VisibilityChange(const bool hidden) = 0;

            // @brief Notifies that the web page requests to close its window
            // @details Indicates that the current web page requested closure of its window.
            virtual void PageClosure() = 0;

            /* @json:omit */
            // @brief Delivers a bridge query message.
            // @details Forwards a message received through the legacy browser bridge.
            // @param message Bridge query payload
            // @example message: "{\"id\":1}"
            virtual void BridgeQuery(const string& message) = 0;
        };

        virtual void Register(INotification* sink) = 0;
        virtual void Unregister(INotification* sink) = 0;

        // @property
        // @brief Page loaded in the browser
        // @details Retrieves the URL currently loaded in the browser.
        // @param url: Loaded URL (e.g. https://example.com)
        // @example url: "https://example.com"
        // @retval Core::ERROR_NONE: URL retrieved successfully
        virtual uint32_t URL(string& url /* @out */) const = 0;

        // @property
        // @brief Sets the page URL in the browser
        // @details Requests navigation to the specified URL.
        // @param url: URL to load (e.g. https://example.com)
        // @example url: "https://example.com"
        // @retval Core::ERROR_NONE: URL set successfully
        virtual uint32_t URL(const string& url) = 0;

        // @property
        // @brief Browser window visibility state
        // @details Retrieves whether the browser window is hidden or visible.
        // @param visible Visiblity state (e.g. )
        // @example visible: VISIBLE
        // @retval Core::ERROR_NONE: Visibility state retrieved successfully
        virtual uint32_t Visibility(VisibilityType& visible /* @out */) const = 0;
        
        // @property
        // @brief Sets the browser window visibility state
        // @details Changes the browser window to the specified visibility state.
        // @param visible: Visibility state to set
        // @example visible: VISIBLE
        // @retval Core::ERROR_NONE: Visibility state set successfully
        virtual uint32_t Visibility(const VisibilityType visible) = 0;

        // @property
        // @brief Current framerate the browser is rendering at
        // @details Retrieves the current browser rendering rate in frames per second.
        // @param fps: Current FPS
        // @example fps: 60
        // @retval Core::ERROR_NONE: Frame rate retrieved successfully
        virtual uint32_t FPS(uint8_t& fps /* @out */) const = 0;

        /* @json:omit */
        // @brief Retrieves the HTTP headers configured for browser requests.
        // @details Returns the configured request headers as a string.
        // @param headerlist: Receives the configured header list
        // @example headerlist: "Accept: text/html"
        // @retval Core::ERROR_NONE: Header list retrieved successfully
        virtual uint32_t HeaderList(string& headerlist /* @out */) const = 0;
        
        /* @json:omit */
        // @brief Sets the HTTP headers configured for browser requests.
        // @details Replaces the configured request header list.
        // @param headerlist: Header list to configure
        // @example headerlist: "Accept: text/html"
        // @retval Core::ERROR_NONE: Header list set successfully
        virtual uint32_t HeaderList(const string& headerlist ) = 0;

        // @property
        // @brief UserAgent string used by the browser
        // @details Retrieves the user-agent value sent by the browser.
        // @param useragent: UserAgent value (e.g. Mozilla/5.0 (Linux; x86_64 GNU/Linux) AppleWebKit/601.1 (KHTML, like Gecko) Version/8.0 Safari/601.1 WP)
        // @example useragent: "Mozilla/5.0"
        // @retval Core::ERROR_NONE: User-agent value retrieved successfully
        virtual uint32_t UserAgent(string& useragent /* @out */) const = 0;
        
        // @property
        // @brief Sets the browser user-agent string
        // @details Configures the user-agent value used for browser requests.
        // @param useragent: User-agent value to use
        // @example useragent: "Mozilla/5.0"
        // @retval Core::ERROR_NONE: User-agent value set successfully
        virtual uint32_t UserAgent(const string& useragent) = 0;

        // @property
        // @brief Controls the local storage availability
        // @details Retrieves whether browser local storage is enabled.
        // @param enabled: True if local storage is enabled, false otherwise
        // @example enabled: true
        // @retval Core::ERROR_NONE: Local-storage state retrieved successfully
        virtual uint32_t LocalStorageEnabled(bool& enabled /* @out */) const = 0;
        
        // @property
        // @brief Sets local storage availability
        // @details Enables or disables browser local storage.
        // @param enabled: True to enable local storage
        // @example enabled: true
        // @retval Core::ERROR_NONE: Local-storage state set successfully
        virtual uint32_t LocalStorageEnabled(const bool enabled) = 0;

        // @property
        // @brief HTTP cookies accept policy
        // @details Retrieves the policy that controls which HTTP cookies the browser accepts.
        // @param policy: HTTP Cookie Accept Policy Type (e.g. always)
        // @example policy: ALWAYS
        // @retval Core::ERROR_NONE: Cookie acceptance policy retrieved successfully
        virtual uint32_t HTTPCookieAcceptPolicy(HTTPCookieAcceptPolicyType& policy /* @out */) const = 0;
       
        // @property
        // @brief Sets the HTTP cookies accept policy
        // @details Configures which HTTP cookies the browser accepts.
        // @param policy: Cookie acceptance policy to set
        // @example policy: ONLY_FROM_MAIN_DOCUMENT_DOMAIN
        // @retval Core::ERROR_NONE: Cookie acceptance policy set successfully
        virtual uint32_t HTTPCookieAcceptPolicy(const HTTPCookieAcceptPolicyType policy) = 0;

        // @property
        // @brief Response for legacy $badger.
        // @details Delivers a response payload to the legacy $badger callback.
        // @param payload: base64 encoded JSON string response to be delivered to $badger.callback
        // @example payload: "eyJzdGF0dXMiOiJvayJ9"
        // @retval Core::ERROR_NONE: Bridge response delivered successfully
        virtual uint32_t BridgeReply(const string& payload) = 0;

        // @property
        // @brief Send legacy $badger event.
        // @details Sends an event payload to the legacy window.$badger.event handler.
        // @param payload: base64 encoded JSON string response to be delivered to window.$badger.event
        // @example payload: "eyJldmVudCI6ImNoYW5nZWQifQ=="
        // @retval Core::ERROR_NONE: Bridge event sent successfully
        virtual uint32_t BridgeEvent(const string& payload) = 0;

        // @brief Initiate garbage collection
        // @details Requests garbage collection in the browser process.
        // @retval Core::ERROR_NONE: Garbage collection request accepted
        virtual uint32_t CollectGarbage() = 0;
    };

    // @json @uncompliant:extended
    struct EXTERNAL IBrowserResources : virtual public Core::IUnknown {

        enum { ID = ID_BROWSER_RESOURCES };

        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // @property
        // @brief Headers to send on all requests that the browser makes
        // @details Retrieves the configured headers sent with browser requests.
        // @param header: Iterator receiving the configured header values
        // @example header: ["Accept: text/html"]
        // @retval Core::ERROR_NONE: Header iterator retrieved successfully
        // @json:omit
        virtual uint32_t Headers(IStringIterator*& header /* @out */) const = 0;
       
        // @brief Sets the headers sent on all browser requests.
        // @details Replaces the configured request headers with the supplied iterator values.
        // @param header: Iterator containing the headers to configure
        // @example header: ["Accept: text/html"]
        // @retval Core::ERROR_NONE: Request headers set successfully
        // @json:omit
        virtual uint32_t Headers(IStringIterator* const header) = 0;

        // @property
        // @brief User scripts used by the browser
        // @details Retrieves the URIs of user scripts configured for execution by the browser.
        // @param uris: JSON array containing URIs pointing to user scripts, supported protocols: file://
        // @example uris: ["file:///opt/app/script.js"]
        // @retval Core::ERROR_NONE: User-script list retrieved successfully
        virtual uint32_t UserScripts(IStringIterator*& uris /* @out */) const = 0;
       
        // @brief Sets the user scripts used by the browser.
        // @details Replaces the configured user-script URIs.
        // @param uris: Iterator containing user-script URIs
        // @example uris: ["file:///opt/app/script.js"]
        // @retval Core::ERROR_NONE: User-script list set successfully
        virtual uint32_t UserScripts(IStringIterator* const uris) = 0;

        // @property
        // @brief User style sheets used by the browser
        // @details Retrieves the URIs of user style sheets configured for the browser.
        // @param uris: JSON array containing URIs pointing to user style sheets, supported protocols: file://
        // @example uris: ["file:///opt/app/styles.css"]
        // @retval Core::ERROR_NONE: User style-sheet list retrieved successfully
        virtual uint32_t UserStyleSheets(IStringIterator*& uris /* @out */) const = 0;
       
        // @brief Sets the user style sheets used by the browser.
        // @details Replaces the configured user style-sheet URIs.
        // @param uris: Iterator containing user style-sheet URIs
        // @example uris: ["file:///opt/app/styles.css"]
        // @retval Core::ERROR_NONE: User style-sheet list set successfully
        virtual uint32_t UserStyleSheets(IStringIterator* const uris) = 0;
    };

    // @json @uncompliant:extended
    struct EXTERNAL IBrowserSecurity : virtual public Core::IUnknown {

        enum { ID = ID_BROWSER_SECURITY };

        // @property
        // @brief Security profile for secure connections
        // @details Retrieves the profile used to configure secure browser connections.
        // @param profile: Security profile for secure connections (e.g. compatible)
        // @example profile: "compatible"
        // @retval Core::ERROR_NONE: Security profile retrieved successfully
        virtual uint32_t SecurityProfile(string& profile /* @out */) const = 0;
        
        // @brief Sets the security profile for secure connections.
        // @details Configures the profile used for secure browser connections.
        // @param profile: Security profile to use (e.g. compatible)
        // @example profile: "compatible"
        // @retval Core::ERROR_NONE: Security profile set successfully
        virtual uint32_t SecurityProfile(const string& profile) = 0;

        enum MixedContentPolicyType : uint8_t {
            ALLOWED = 0 /* @text:allowed */,
            BLOCKED  = 1 /* @text:blocked */
        };

        // @property
        // @brief Mixed content policy
        // @details Retrieves whether mixed content is allowed or blocked.
        // @param policy: Mixed content policy type
        // @example policy: BLOCKED
        // @retval Core::ERROR_NONE: Mixed-content policy retrieved successfully
        virtual uint32_t MixedContentPolicy(MixedContentPolicyType& policy /* @out */) const = 0;
       
        // @brief Sets the mixed content policy.
        // @details Configures whether the browser allows or blocks mixed content.
        // @param policy: Mixed-content policy to set
        // @example policy: BLOCKED
        // @retval Core::ERROR_NONE: Mixed-content policy set successfully
        virtual uint32_t MixedContentPolicy(const MixedContentPolicyType policy) = 0;
    };

    /* @json */
    struct EXTERNAL IBrowserScripting : virtual public Core::IUnknown {
        enum { ID = ID_BROWSER_SCRIPTING };

        // @brief Run javascript in main frame.
        // @details Executes the supplied JavaScript source in the page's main frame.
        // @param script: Utf8 encoded JS code string.
        // @example script: "document.title"
        // @retval Core::ERROR_NONE: JavaScript execution request accepted
        virtual uint32_t RunJavaScript(const string& script) = 0;

        // @brief Add user script to be executed at document start.
        // @details Registers a script for execution when a document begins loading.
        // @param script: Utf8 encoded JS code string.
        // @example script: "window.appReady = true"
        // @param topFrameOnly: True to execute only in the top-level frame
        // @example topFrameOnly: true
        // @retval Core::ERROR_NONE: User script added successfully
        virtual uint32_t AddUserScript(const string& script, const bool topFrameOnly) = 0;

        // @brief Remove all user scripts.
        // @details Clears all user scripts previously registered through this interface.
        // @retval Core::ERROR_NONE: User scripts removed successfully
        virtual uint32_t RemoveAllUserScripts() = 0;
    };

    /* @json @uncompliant:extended */
    struct EXTERNAL IBrowserCookieJar : virtual public Core::IUnknown {
        enum { ID = ID_BROWSER_COOKIEJAR };

        /* @event */
        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_BROWSER_COOKIEJAR_NOTIFICATION };

            // @brief Notifies that cookies were added, removed or modified.
            // @details Signals that the browser cookie jar contents have changed.
            virtual void CookieJarChanged() = 0;
        };

        // @brief Registers a cookie-jar notification listener.
        // @details Subscribes the provided sink to cookie-jar change notifications.
        // @param sink: Notification interface to register
        // @example sink: IBrowserCookieJar::INotification implementation
        virtual void Register(INotification* sink) = 0;
        
        // @brief Unregisters a cookie-jar notification listener.
        // @details Removes the provided sink from cookie-jar notifications.
        // @param sink: Notification interface to unregister
        // @example sink: IBrowserCookieJar::INotification implementation
        virtual void Unregister(INotification* sink) = 0;

        /* @text getcoookiejar */
        // @brief Retrieves the cookie-jar snapshot.
        // @details Returns the cookie-jar version, checksum, and serialized payload.
        // @param version: Receives the cookie-jar version
        // @example version: 1
        // @param checksum: Receives the cookie-jar checksum
        // @example checksum: 12345
        // @param payload: Receives the serialized cookie-jar data
        // @example payload: "..."
        // @retval Core::ERROR_NONE: Cookie-jar snapshot retrieved successfully
        virtual uint32_t CookieJar(uint32_t& version /* @out */, uint32_t& checksum /* @out */, string& payload /* @out */) const = 0;
       
        /* @text setcoookiejar */
        // @brief Updates the cookie-jar snapshot.
        // @details Replaces cookie-jar data using its version, checksum, and serialized payload.
        // @param version: Cookie-jar version
        // @example version: 1
        // @param checksum: Cookie-jar checksum
        // @example checksum: 12345
        // @param payload: Serialized cookie-jar data
        // @example payload: "..."
        // @retval Core::ERROR_NONE: Cookie-jar snapshot updated successfully
        virtual uint32_t CookieJar(const uint32_t version, const uint32_t checksum, const string& payload) = 0;
    };

}
}
