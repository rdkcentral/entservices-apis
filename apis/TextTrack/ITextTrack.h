/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024-2025 RDK Management.
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

#define ITEXTTRACK_VERSION 5

namespace WPEFramework {
namespace Exchange {

/*
    This is the COM-RPC interface for managing Closed Captions styles.
*/
/* @json 1.0.0 @text:keep */
struct EXTERNAL ITextTrackClosedCaptionsStyle : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE
    };

    /** Values are taken from CEA-708 standard */
    enum class FontFamily : uint8_t {
        CONTENT_DEFAULT = 0,
        MONOSPACED_SERIF = 1,
        PROPORTIONAL_SERIF = 2,
        MONOSPACE_SANS_SERIF = 3,
        PROPORTIONAL_SANS_SERIF = 4,
        CASUAL = 5,
        CURSIVE = 6,
        SMALL_CAPITAL = 7
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    enum class FontSize : int8_t {
        CONTENT_DEFAULT = -1,
        SMALL = 0,
        REGULAR = 1,
        LARGE = 2,
        EXTRA_LARGE = 3
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    enum class FontEdge : int8_t {
        CONTENT_DEFAULT = -1,
        NONE = 0,
        RAISED = 1,
        DEPRESSED = 2,
        UNIFORM = 3,
        LEFT_DROP_SHADOW = 4,
        RIGHT_DROP_SHADOW = 5
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    struct ClosedCaptionsStyle {
        // @brief Selected fontFamily
        FontFamily fontFamily;
        // @brief Selected fontSize
        FontSize fontSize;

        // @brief #rrggbb Empty string implies - use stream default
        // @restrict:7
        string fontColor;
        // @brief 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t fontOpacity;

        // @brief Selected fontEdge
        FontEdge fontEdge;
        // @brief #rrggbb Empty string implies - use stream default
        // @restrict:7
        string fontEdgeColor;

        // @brief #rrggbb Empty string implies - use stream default
        // @restrict:7
        string backgroundColor;
        // @brief 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t backgroundOpacity;

        // @brief #rrggbb Empty string implies - use stream default
        // @restrict:7
        string windowColor;
        // @brief 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t windowOpacity;
    };

    /* @event */
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum {
            ID = ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE_NOTIFICATION
        };

        /**
         * @brief The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings.
         * @details The notification carries the updated global style values.
         * @param style Updated closed-caption style.
         * @example style: {fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}
         * @text onClosedCaptionsStyleChanged
         */
        virtual void OnClosedCaptionsStyleChanged(const ClosedCaptionsStyle &style) = 0; // Works with ThunderTools >= 4.4.3

        /**
         * @brief Notifies that the configured font family changed.
         * @details The new value can be retrieved with GetFontFamily().
         * @param font Updated font family.
         * @example font: PROPORTIONAL_SANS_SERIF
         * @text onFontFamilyChanged
         */
        virtual void OnFontFamilyChanged(const FontFamily font) {};
        /**
         * @brief Notifies that the configured font size changed.
         * @details The new value can be retrieved with GetFontSize().
         * @param size Updated font size.
         * @example size: REGULAR
         * @text onFontSizeChanged
         */
        virtual void OnFontSizeChanged(const FontSize size) {};
        /**
         * @brief Notifies that the configured font color changed.
         * @details The new value can be retrieved with GetFontColor().
         * @param color Updated font color.
         * @example color: "#ffffff"
         * @text onFontColorChanged
         */
        virtual void OnFontColorChanged(const string &color) {};
        /**
         * @brief Notifies that the configured font opacity changed.
         * @details The new value can be retrieved with GetFontOpacity().
         * @param opacity Updated font opacity percentage, or -1 for the stream default.
         * @example opacity: 100
         * @text onFontOpacityChanged
         */
        virtual void OnFontOpacityChanged(const int8_t opacity) {};
        /**
         * @brief Notifies that the configured font edge changed.
         * @details The new value can be retrieved with GetFontEdge().
         * @param edge Updated font edge effect.
         * @example edge: RAISED
         * @text onFontEdgeChanged
         */
        virtual void OnFontEdgeChanged(const FontEdge edge) {};
        /**
         * @brief Notifies that the configured font edge color changed.
         * @details The new value can be retrieved with GetFontEdgeColor().
         * @param color Updated font edge color.
         * @example color: "#000000"
         * @text onFontEdgeColorChanged
         */
        virtual void OnFontEdgeColorChanged(const string &color) {};
        /**
         * @brief Notifies that the configured background color changed.
         * @details The new value can be retrieved with GetBackgroundColor().
         * @param color Updated background color.
         * @example color: "#000000"
         * @text onBackgroundColorChanged
         */
        virtual void OnBackgroundColorChanged(const string &color) {};
        /**
         * @brief Notifies that the configured background opacity changed.
         * @details The new value can be retrieved with GetBackgroundOpacity().
         * @param opacity Updated background opacity percentage, or -1 for the stream default.
         * @example opacity: 50
         * @text onBackgroundOpacityChanged
         */
        virtual void OnBackgroundOpacityChanged(const int8_t opacity) {};
        /**
         * @brief Notifies that the configured window color changed.
         * @details The new value can be retrieved with GetWindowColor().
         * @param color Updated window color.
         * @example color: "#000000"
         * @text onWindowColorChanged
         */
        virtual void OnWindowColorChanged(const string &color) {};
        /**
         * @brief Notifies that the configured window opacity changed.
         * @details The new value can be retrieved with GetWindowOpacity().
         * @param opacity Updated window opacity percentage, or -1 for the stream default.
         * @example opacity: 50
         * @text onWindowOpacityChanged
         */
        virtual void OnWindowOpacityChanged(const int8_t opacity) {};
    };

    /** Register notification interface.
     * The callback will be called with the current settings.
     */
    virtual Core::hresult Register(INotification *notification) = 0;
    /** Unregister notification interface */
    virtual Core::hresult Unregister(const INotification *notification) = 0;

    // Settings

    /**
     * @brief Sets the ClosedCaptionsStyle.
     * @details For all values it is possible to keep or override the stream default.
     * The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.
     * @param style Contains the chosen styles
     * @example style: {fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR, fontColor: "#ffffff"}
     * @retval Core::ERROR_NONE: Style updated successfully.
     * @retval Core::ERROR_GENERAL: Style could not be updated.
     * @text setClosedCaptionsStyle
     */
    virtual Core::hresult SetClosedCaptionsStyle(const ClosedCaptionsStyle &style) = 0;
    /**
     * @brief Gets the current ClosedCaptionsStyle settings.
     * @details Returns the global closed-caption style configuration.
     * @param style Receives the current style settings.
     * @example style: {fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR, fontColor: "#ffffff"}
     * @retval Core::ERROR_NONE: Style retrieved successfully.
     * @retval Core::ERROR_GENERAL: Style could not be retrieved.
     * @text getClosedCaptionsStyle
     */
    virtual Core::hresult GetClosedCaptionsStyle(ClosedCaptionsStyle &style /* @out */) const = 0;

    /**
     * @{
     * @group Individual getter and setter Methods to facilitate easier Firebolt mapping
     */

    /**
    * @brief Sets the closed-caption font family.
    * @details The selected family is applied unless the stream or a session-specific style overrides it.
    * @param font Font family to apply.
    * @example font: PROPORTIONAL_SANS_SERIF
    * @retval Core::ERROR_NONE: Font family updated successfully.
    * @retval Core::ERROR_GENERAL: Font family could not be updated.
     * @text setFontFamily
     */
    virtual Core::hresult SetFontFamily(const FontFamily font) = 0;
    /**
    * @brief Gets the closed-caption font family.
    * @details Returns the currently configured global font family.
    * @param font Receives the configured font family.
    * @example font: PROPORTIONAL_SANS_SERIF
    * @retval Core::ERROR_NONE: Font family retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font family could not be retrieved.
     * @text getFontFamily
     */
    virtual Core::hresult GetFontFamily(FontFamily &font /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption font size.
    * @details The size can use the content default or a configured caption size.
    * @param size Font size to apply.
    * @example size: REGULAR
    * @retval Core::ERROR_NONE: Font size updated successfully.
    * @retval Core::ERROR_GENERAL: Font size could not be updated.
     * @text setFontSize
     */
    virtual Core::hresult SetFontSize(const FontSize size) = 0;
    /**
    * @brief Gets the closed-caption font size.
    * @details Returns the currently configured global font size.
    * @param size Receives the configured font size.
    * @example size: REGULAR
    * @retval Core::ERROR_NONE: Font size retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font size could not be retrieved.
     * @text getFontSize
     */
    virtual Core::hresult GetFontSize(FontSize &size /* @out */) const = 0;
    /**
    * @brief Sets the closed-caption font color.
    * @details Provide a #rrggbb color or an empty string to use the stream default.
    * @param color Font color to apply.
    * @example color: "#ffffff"
    * @retval Core::ERROR_NONE: Font color updated successfully.
    * @retval Core::ERROR_GENERAL: Font color could not be updated.
     * @text setFontColor
     */
    virtual Core::hresult SetFontColor(const string &color) = 0;

    /**
    * @brief Gets the closed-caption font color.
    * @details Returns the configured #rrggbb color or an empty string when using the stream default.
    * @param color Receives the configured font color.
    * @example color: "#ffffff"
    * @retval Core::ERROR_NONE: Font color retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font color could not be retrieved.
     * @text getFontColor
     */
    virtual Core::hresult GetFontColor(string &color /* @out */) const = 0;
    /**
    * @brief Sets the closed-caption font opacity.
    * @details Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.
    * @param opacity Font opacity to apply.
    * @example opacity: 100
    * @retval Core::ERROR_NONE: Font opacity updated successfully.
    * @retval Core::ERROR_GENERAL: Font opacity could not be updated.
     * @text setFontOpacity
     */
    virtual Core::hresult SetFontOpacity(const int8_t opacity) = 0;

    /**
    * @brief Gets the closed-caption font opacity.
    * @details Returns the configured opacity percentage, or -1 when using the stream default.
    * @param opacity Receives the configured font opacity.
    * @example opacity: 100
    * @retval Core::ERROR_NONE: Font opacity retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font opacity could not be retrieved.
     * @text getFontOpacity
     */
    virtual Core::hresult GetFontOpacity(int8_t &opacity /* @out */) const = 0;
    /**
    * @brief Sets the closed-caption font edge effect.
    * @details The edge effect improves the visual separation of caption text from its background.
    * @param edge Font edge effect to apply.
    * @example edge: RAISED
    * @retval Core::ERROR_NONE: Font edge updated successfully.
    * @retval Core::ERROR_GENERAL: Font edge could not be updated.
     * @text setFontEdge
     */
    virtual Core::hresult SetFontEdge(const FontEdge edge) = 0;
    /**
    * @brief Gets the closed-caption font edge effect.
    * @details Returns the currently configured global font edge effect.
    * @param edge Receives the configured font edge effect.
    * @example edge: RAISED
    * @retval Core::ERROR_NONE: Font edge retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font edge could not be retrieved.
     * @text getFontEdge
     */
    virtual Core::hresult GetFontEdge(FontEdge &edge /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption font edge color.
    * @details Provide a #rrggbb color or an empty string to use the stream default.
    * @param color Font edge color to apply.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Font edge color updated successfully.
    * @retval Core::ERROR_GENERAL: Font edge color could not be updated.
     * @text setFontEdgeColor
     */
    virtual Core::hresult SetFontEdgeColor(const string &color) = 0;
    /**
    * @brief Gets the closed-caption font edge color.
    * @details Returns the configured #rrggbb color or an empty string when using the stream default.
    * @param color Receives the configured font edge color.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Font edge color retrieved successfully.
    * @retval Core::ERROR_GENERAL: Font edge color could not be retrieved.
     * @text getFontEdgeColor
     */
    virtual Core::hresult GetFontEdgeColor(string &color /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption background color.
    * @details Provide a #rrggbb color or an empty string to use the stream default.
    * @param color Background color to apply.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Background color updated successfully.
    * @retval Core::ERROR_GENERAL: Background color could not be updated.
     * @text setBackgroundColor
     */
    virtual Core::hresult SetBackgroundColor(const string &color) = 0;
    /**
    * @brief Gets the closed-caption background color.
    * @details Returns the configured #rrggbb color or an empty string when using the stream default.
    * @param color Receives the configured background color.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Background color retrieved successfully.
    * @retval Core::ERROR_GENERAL: Background color could not be retrieved.
     * @text getBackgroundColor
     */
    virtual Core::hresult GetBackgroundColor(string &color /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption background opacity.
    * @details Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.
    * @param opacity Background opacity to apply.
    * @example opacity: 50
    * @retval Core::ERROR_NONE: Background opacity updated successfully.
    * @retval Core::ERROR_GENERAL: Background opacity could not be updated.
     * @text setBackgroundOpacity
     */
    virtual Core::hresult SetBackgroundOpacity(const int8_t opacity) = 0;
    /**
    * @brief Gets the closed-caption background opacity.
    * @details Returns the configured opacity percentage, or -1 when using the stream default.
    * @param opacity Receives the configured background opacity.
    * @example opacity: 50
    * @retval Core::ERROR_NONE: Background opacity retrieved successfully.
    * @retval Core::ERROR_GENERAL: Background opacity could not be retrieved.
     * @text getBackgroundOpacity
     */
    virtual Core::hresult GetBackgroundOpacity(int8_t &opacity /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption window color.
    * @details Provide a #rrggbb color or an empty string to use the stream default.
    * @param color Window color to apply.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Window color updated successfully.
    * @retval Core::ERROR_GENERAL: Window color could not be updated.
     * @text setWindowColor
     */
    virtual Core::hresult SetWindowColor(const string &color) = 0;
    /**
    * @brief Gets the closed-caption window color.
    * @details Returns the configured #rrggbb color or an empty string when using the stream default.
    * @param color Receives the configured window color.
    * @example color: "#000000"
    * @retval Core::ERROR_NONE: Window color retrieved successfully.
    * @retval Core::ERROR_GENERAL: Window color could not be retrieved.
     * @text getWindowColor
     */
    virtual Core::hresult GetWindowColor(string &color /* @out */) const = 0;

    /**
    * @brief Sets the closed-caption window opacity.
    * @details Opacity is a percentage from 0 (transparent) to 100 (solid); -1 uses the stream default.
    * @param opacity Window opacity to apply.
    * @example opacity: 50
    * @retval Core::ERROR_NONE: Window opacity updated successfully.
    * @retval Core::ERROR_GENERAL: Window opacity could not be updated.
     * @text setWindowOpacity
     */
    virtual Core::hresult SetWindowOpacity(const int8_t opacity) = 0;
    /**
    * @brief Gets the closed-caption window opacity.
    * @details Returns the configured opacity percentage, or -1 when using the stream default.
    * @param opacity Receives the configured window opacity.
    * @example opacity: 50
    * @retval Core::ERROR_NONE: Window opacity retrieved successfully.
    * @retval Core::ERROR_GENERAL: Window opacity could not be retrieved.
     * @text getWindowOpacity
     */
    virtual Core::hresult GetWindowOpacity(int8_t &opacity /* @out */) const = 0;

    /* @} */
};

/*
 * This is the COM-RPC interface for global TTML style overrides.
 * Added in version 2
 */
/* @json 1.0.0 @text:keep */
struct EXTERNAL ITextTrackTtmlStyle : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK_TTML_STYLE
    };

    /* @event */
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum {
            ID = ID_TEXT_TRACK_TTML_STYLE_NOTIFICATION
        };

        /**
         * @brief The TTML Style override settings has changed.
         * @details The notification contains the updated global TTML style override string.
         * @param style Updated TTML style overrides.
         * @example style: "color: white;fontSize: 1.2em"
         * @text onTtmlStyleOverridesChanged
         */
        virtual void OnTtmlStyleOverridesChanged(const string &style) {};
    };

    /**
     * @brief Registers a listener for TTML style override changes.
     * @details The listener receives a notification when the global TTML style overrides change.
     * @param notification Listener to register.
     * @example notification: ITextTrackTtmlStyle::INotification implementation
     * @retval Core::ERROR_NONE: Listener registered successfully.
     * @retval Core::ERROR_GENERAL: Listener could not be registered.
     */
    virtual Core::hresult Register(INotification *notification) = 0;
    /**
     * @brief Unregisters a listener for TTML style override changes.
     * @details The listener will no longer receive TTML style-change notifications.
     * @param notification Listener to unregister.
     * @example notification: ITextTrackTtmlStyle::INotification implementation
     * @retval Core::ERROR_NONE: Listener unregistered successfully.
     * @retval Core::ERROR_GENERAL: Listener could not be unregistered.
     */
    virtual Core::hresult Unregister(const INotification *notification) = 0;

    /**
     * @brief Sets global TTML override style.
     * @details The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning
     * that they will override styles given in the content.
     * The value will be persisted in the system.
     * The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.
     * @param style Contains the chosen override for styles
     * @example style: "color: white;fontSize: 1.2em"
     * @retval Core::ERROR_NONE: TTML style overrides updated successfully.
     * @retval Core::ERROR_GENERAL: TTML style overrides could not be updated.
     * @text setTtmlStyleOverrides
     */
    virtual Core::hresult SetTtmlStyleOverrides(const string& style) = 0;

    /**
     * @brief Gets the global TTML style overrides
     * @details Returns the persisted global override string applied to TTML sessions.
     * @param style Will receive the style overrides
     * @example style: "color: white;fontSize: 1.2em"
     * @retval Core::ERROR_NONE: TTML style overrides retrieved successfully.
     * @retval Core::ERROR_GENERAL: TTML style overrides could not be retrieved.
     * @text getTtmlStyleOverrides
     */
    virtual Core::hresult GetTtmlStyleOverrides(string& style /* @out */) const = 0;
};

/*
 * This is the COM-RPC interface for querying TextTrack capabilities.
 * The list of capabilities can be extended over time and future versions.
 * Added in version 4
 */
/* @json 1.0.0 @text:keep */
struct EXTERNAL ITextTrackCapabilities : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK_CAPABILITIES
    };

    enum class Capability : uint32_t {
        UNSET = 0, //< Filler value; will never be used as a capability
        FIREBOLT_MIGRATION = 1, //< Have the CC style settings from Firebolt been migrated into TextTrack?
    };

    using IIterator = RPC::IIteratorType<Capability, RPC::ID_VALUEITERATOR>;

    // @text getCapability
    // @brief Queries whether a specific TextTrack capability is supported by the implementation.
    // @details Query support before relying on optional TextTrack functionality.
    // @param capability The capability to query ex: FIREBOLT_MIGRATION
    // @param hasCapability Indicates whether the queried capability is supported.
    // @example capability: FIREBOLT_MIGRATION, hasCapability: true
    // @retval Core::ERROR_NONE The capability query completed successfully.
    // @retval Core::ERROR_NOT_SUPPORTED Capability querying is not supported.
    virtual Core::hresult GetCapability(const Capability capability, bool &hasCapability /* @out */) const = 0;

    // @text getCapabilities
    // @brief Retrieves an iterator over all supported TextTrack capabilities.
    // @details Enumerates the capabilities supported by this implementation.
    // @param capabilities Iterator providing the list of supported capabilities.
    // @example capabilities: [FIREBOLT_MIGRATION]
    // @retval Core::ERROR_NONE The list of capabilities was retrieved successfully.
    // @retval Core::ERROR_NOT_SUPPORTED Retrieving capabilities is not supported.
    virtual Core::hresult GetCapabilities(IIterator *&capabilities /* @out */) const = 0;
};

/*
    This is the COM-RPC interface for handling TextTrack sessions.
*/
/* @json 1.5.0 @text:keep */
struct EXTERNAL ITextTrack : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK
    };

    enum class DataType : uint8_t {
        PES = 0,
        TTML = 1,
        CC = 2,
        WEBVTT = 3
    };

    enum class SubtitleFormat : uint8_t {
        NONE = 0,
        TTML = 1,
        CC = 2,
        WEBVTT = 3,
        TELETEXT = 4, // USES PES DATA
        DVBSUB = 5,   // USES PES DATA
        SCTE = 6      // USES PES DATA
    };

    // Structured information about a session, returned by GetSessions().
    struct EXTERNAL SessionInfo {
        uint32_t sessionId /* @brief The session ID */;
        string whoAmI /* @brief An identifier for the caller that created the session. May be empty if created via OpenSession. */;
        string displayHandle /* @brief The display handle of the session */;
        SubtitleFormat format /* @brief The type of the session (CC, TTML, etc). Can be NONE if not yet set. */;
        bool isPreview /* @brief Whether the session is a preview session or not */;
        bool isMuted /* @brief Whether the session is currently muted or not */;
        bool isPaused /* @brief Whether the session is currently paused or not */;
        uint64_t dataCount /* @brief The number of data packets sent to this session, for debugging purposes. The count is the number of times SendSessionData() has been called. */;
        string info /* @brief Opaque debug information about the session */;
    };
    using ISessionInfoIterator = RPC::IIteratorType<SessionInfo, ID_TEXT_TRACK_SESSION_INFO_ITERATOR>;

    // Sessions
    /**
     * @brief Opens a new renderSession.
     * @details If a session is already running on the supplied displayHandle, the sessionId for this session is
     * returned. If the session is instead newly opened, the session type is not set and display is muted. Use one
     * of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.
     * @param displayHandle Is an encoding of the wayland display name
     * @example displayHandle: "wayland-0"
     * @param sessionId On success the returned session id ex: 1
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session opened successfully.
     * @retval Core::ERROR_GENERAL: Session could not be opened.
     * @text openSession
     */
    virtual Core::hresult OpenSession(const string &displayHandle, uint32_t &sessionId /* @out */) = 0;
    /**
     * @brief Closes a previously opened render session.
     * @details Any created windows and surfaces is destroyed
     * @param sessionId Is the session to close
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session closed successfully.
     * @retval Core::ERROR_GENERAL: Session could not be closed.
     * @text closeSession
     */
    virtual Core::hresult CloseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resets a previously opened render session back to its opened state.
     * @details The state will be like after calling OpenSession()
     * @param sessionId Is the session to reset
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session reset successfully.
     * @retval Core::ERROR_GENERAL: Session could not be reset.
     * @text resetSession
     */
    virtual Core::hresult ResetSession(const uint32_t sessionId) = 0;
    /**
     * @brief Pauses a render session.
     * @details Any text rendered remains on screen and any text due to be rendered soon
     * is held until the render session is resumed.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session paused successfully.
     * @retval Core::ERROR_GENERAL: Session could not be paused.
     * @text pauseSession
     */
    virtual Core::hresult PauseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resumes a paused render session.
     * @details Rendering continues for the session after it has been resumed.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session resumed successfully.
     * @retval Core::ERROR_GENERAL: Session could not be resumed.
     * @text resumeSession
     */
    virtual Core::hresult ResumeSession(const uint32_t sessionId) = 0;
    /**
     * @brief Mutes a render session.
     * @details Caption rendering is hidden until the session is unmuted.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session muted successfully.
     * @retval Core::ERROR_GENERAL: Session could not be muted.
     * @text muteSession
     */
    virtual Core::hresult MuteSession(const uint32_t sessionId) = 0;
    /**
     * @brief UnMute will unhide the rendering of Captions.
     * @details A newly created session is muted and should be unmuted to me visible
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: Session unmuted successfully.
     * @retval Core::ERROR_GENERAL: Session could not be unmuted.
     * @text unMuteSession
     */
    virtual Core::hresult UnMuteSession(const uint32_t sessionId) = 0;

    /**
     * @brief Sends data of Closed Captions, Captions or Timed Text data to a render session.
     * @details Data is decoded according to the selected session type and rendered according to its presentation timestamps.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param type Is the type of data
     * @example type: TTML
     * @param displayOffsetMs Is added to a timestamp in the data to determine when to display it. The offset is in milliseconds and can be negative. Not all types support this.
     * @example displayOffsetMs: 0
     * @param data Is the data to display, properly formatted as per the expectations of the type used
     * @example data: "<tt>Caption</tt>"
     * @retval Core::ERROR_NONE: Session data sent successfully.
     * @retval Core::ERROR_GENERAL: Session data could not be sent.
     * @text sendSessionData
     */
    virtual Core::hresult SendSessionData(const uint32_t sessionId, const DataType type, const int64_t displayOffsetMs, const string &data) = 0;
    /**
     * @brief Sends the current timestamp from a media player to a render session.
     * @details The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param mediaTimestampMs Is a timestamp
     * @example mediaTimestampMs: 123456
     * @retval Core::ERROR_NONE: Session timestamp sent successfully.
     * @retval Core::ERROR_GENERAL: Session timestamp could not be sent.
     * @text sendSessionTimestamp
     */
    virtual Core::hresult SendSessionTimestamp(const uint32_t sessionId, const uint64_t mediaTimestampMs) = 0;

    /**
     * @brief  Applies a custom ClosedCaptionsStyle on a single session.
     * @details When a custom style is applied on a specific session we will not update the style for this session if the global style setting change.
     * The style setting will take effect immediately.
     * @param sessionId Is the session as returned in the ITextTrack interface.
     * @example sessionId: 1
     * @param style Contains the chosen styles
     * @example style: {fontFamily: PROPORTIONAL_SANS_SERIF, fontSize: REGULAR}
     * @retval Core::ERROR_NONE: Custom style applied successfully.
     * @retval Core::ERROR_GENERAL: Custom style could not be applied.
     * @json:omit
     * @text applyCustomClosedCaptionsStyleToSession
     */
    virtual Core::hresult ApplyCustomClosedCaptionsStyleToSession(const uint32_t sessionId, const ITextTrackClosedCaptionsStyle::ClosedCaptionsStyle &style) = 0;

    /**
     * @brief Sets a static text in the display for preview purposes.
     * @details The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param text Is the text to display
     * @example text: "Sample captions"
     * @retval Core::ERROR_NONE if preview is shown
     * @retval Core::ERROR_NOT_SUPPORTED if preview is not supported
     * @text setPreviewText
     */
    virtual Core::hresult SetPreviewText(const uint32_t sessionId, const string &text) = 0;

    /*
     * The following methods initialize the mode of the TextTrack engine. All sessions are muted after
     * this call and it is the player's responsibility to unmute it.
     */

    /**
     * @brief Sets the render session into CC mode.
     * @details Selecting the specified CC service to decode and display in the specified render session.
     * This should be done before starting the injection of data.
     * Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param service Identifies the service to display e.g. "CC3"
     * @example service: "CC3"
     * @retval Core::ERROR_NONE: Closed-caption service selected successfully.
     * @retval Core::ERROR_GENERAL: Closed-caption service could not be selected.
     * @text setSessionClosedCaptionsService
     */
    virtual Core::hresult SetSessionClosedCaptionsService(const uint32_t sessionId, const string &service) = 0;
    /**
     * @brief Set the render session into Teletext mode, providing the teletext caption page for presentation
     * @details Selects the requested Teletext page for decoding and presentation in the render session.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param page The user selected teletext caption page 100-899
     * @example page: 100
     * @retval Core::ERROR_NONE: Teletext page selected successfully.
     * @retval Core::ERROR_GENERAL: Teletext page could not be selected.
     * @text setSessionTeletextSelection
     */
    virtual Core::hresult SetSessionTeletextSelection(const uint32_t sessionId, const uint16_t page) = 0;
    /**
     * @brief Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)
     * @details Selects the composition and ancillary pages used to decode and present DVB subtitles in the render session.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param compositionPageId Is the one Id
     * @example compositionPageId: 1
     * @param ancillaryPageId Is the other Id
     * @example ancillaryPageId: 1
     * @retval Core::ERROR_NONE: DVB subtitle pages selected successfully.
     * @retval Core::ERROR_GENERAL: DVB subtitle pages could not be selected.
     * @text setSessionDvbSubtitleSelection
     */
    virtual Core::hresult SetSessionDvbSubtitleSelection(const uint32_t sessionId, const uint16_t compositionPageId, const uint16_t ancillaryPageId) = 0;
    /**
     * @brief Set the render session into WebVTT mode
     * @details Selects WebVTT data for decoding and presentation in the render session.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: WebVTT mode selected successfully.
     * @retval Core::ERROR_GENERAL: WebVTT mode could not be selected.
     * @text setSessionWebVTTSelection
     */
    virtual Core::hresult SetSessionWebVTTSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into TTML mode
     * @details Selects TTML data for decoding and presentation in the render session.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: TTML mode selected successfully.
     * @retval Core::ERROR_GENERAL: TTML mode could not be selected.
     * @text setSessionTTMLSelection
     */
    virtual Core::hresult SetSessionTTMLSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into SCTE mode
     * @details Selects SCTE data for decoding and presentation in the render session.
     * @param sessionId Is the session
     * @example sessionId: 1
     * @retval Core::ERROR_NONE: SCTE mode selected successfully.
     * @retval Core::ERROR_GENERAL: SCTE mode could not be selected.
     * @text setSessionSCTESelection
     */
    virtual Core::hresult SetSessionSCTESelection(const uint32_t sessionId) = 0;

    /**
     * @brief Applies a custom TTML styling with overrides that is applied on all elements
     * @details When a custom styling override is applied on a specific TTML session, the styling carried on the data for the specified element is
     * overridden. For styling options, see https://www.w3.org/TR/2018/REC-ttml1-20181108/#styling-vocabulary-style
     * The format of the styling string is "attr:value;attr:value;attr:value" (see vocabulary; NB: not all styling is supported)
     * Styles not mentioned in the list will not be affected.
     * Added in version 2
     * @param sessionId Is the session as returned in the ITextTrack interface.
     * @example sessionId: 1
     * @param style Contains the list of styles to be overridden
     * @example style: "color: white;fontSize: 1.2em"
     * @retval Core::ERROR_NOT_SUPPORTED: The method is not implemented.
     * @text applyCustomTtmlStyleOverridesToSession
     */
    virtual Core::hresult ApplyCustomTtmlStyleOverridesToSession(const uint32_t sessionId, const string &style) { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Associate a video decoder with the given session
     * @details This will ask TextTrack to subscribe to Closed Captions data from the decoder and display
     * these in the given session. Depending on the support on the platform, this may not be possible to do.
     * The association is active until CloseSession() or ResetSession() is called, and can also be
     * cancelled by calling AssociateVideoDecoder() with an empty string for handle.
     * After associating the video decoder, further calls to SendSessionData will be ignored.
     * Added in version 3
     * @param sessionId Is the session
     * @example sessionId: 1
     * @param handle Is a textual representation of the video decoder handle
     * @example handle: "decoder-0"
     * @text associateVideoDecoder
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_GENERAL if the association failed (whether bad handle is used or lack of support on the platform).
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult AssociateVideoDecoder(const uint32_t sessionId, const string &handle) { return Core::ERROR_NOT_SUPPORTED; }

    // @brief Return the interface version implemented
    // @details This allows to query the running plugin for the version of the interface
    // it was compiled to support. This information can be helpful in determining whether
    // a certain functionality can be expected to be present. There is no guarantee that the plugin has implemented
    // all functions of that version.
    // Added in version 4
    // @param version Will receive the version number ex: 4
    // @example version: 5
    // @text getInterfaceVersion
    // @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
    // @retval Core::ERROR_NONE on success
    virtual Core::hresult GetInterfaceVersion(uint32_t& version /* @out */) const { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Creates a new rendering session.
     * @details The session is newly opened, the session type is not set and display is muted. Use one
     * of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.
     * In contrast to OpenSession(), this function will not return an existing session if the displayHandle is
     * already in use, but will always create a new session. This allows multiple sessions to be created for
     * the same displayHandle, which can be useful for example for preview purposes.
     * Added in version 5
     * @text createSession
     * @param displayHandle Is an encoding of the wayland display name
     * @example displayHandle: "wayland-0"
     * @param whoAmI Identifier for the caller; must not be empty.
     * @example whoAmI: "org.example.player"
     * @param sessionId On success the returned session id ex: 1
     * @example sessionId: 1
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_GENERAL if we were unable to create the session
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult CreateSession(const string &displayHandle, const string &whoAmI, uint32_t &sessionId /* @out */) { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Get a list of active sessions.
     * @details Returns session metadata through an iterator; the iterator may be empty when no sessions are active.
     * Added in version 5
     * @text getSessions
     * @param sessions On success, will contain an iterator to the list of active sessions (see SessionInfo struct)
     * @example sessions: [{sessionId: 1, displayHandle: "wayland-0", format: CC}]
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult GetSessions(ISessionInfoIterator *&sessions /* @out */) const { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Create a preview session for purposes of previewing style settings.
     * @details Like CreateSession(), except: the preview session will be created as a CC type session and unmuted.
     * There can only be one active preview session.
     * Creating a preview session will cause all other sessions to be muted automatically until the preview session is closed.
     * Use ApplyCustomClosedCaptionsStyleToSession() to preview style changes.
     * Given a blank displayHandle, we will create a preview session on the standard display (from the configuration file).
     * Use SetPreviewText() to set the text to display in the preview session.
     * Use SetPreviewGeometry() to set the position of the preview session.
     * Added in version 5
     * @text createPreviewSession
     * @param displayHandle Is an encoding of the wayland display name; may be empty
     * @example displayHandle: "wayland-0"
     * @param whoAmI Identifier for the caller; must not be empty.
     * @example whoAmI: "org.example.player"
     * @param sessionId On success the returned session id ex: 1
     * @example sessionId: 2
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_GENERAL if we were unable to create the session
     * @retval Core::ERROR_GENERAL if a preview session is already running on the display
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult CreatePreviewSession(const string &displayHandle, const string &whoAmI, uint32_t &sessionId /* @out */) { return Core::ERROR_NOT_SUPPORTED; }

    enum class Anchor : uint8_t {
        CENTER = 0,
        TOP = 1,
        BOTTOM = 2,
        LEFT = 3,
        RIGHT = 4,
        TOP_LEFT = 5,
        TOP_RIGHT = 6,
        BOTTOM_LEFT = 7,
        BOTTOM_RIGHT = 8
    };

    /**
     * @brief Set the position of the preview session.
     * @details The positions are given as percentage of the subtitle drawing area, so 0.5 means centre and 0.0 means top or left, 1.0 is bottom or right.
     * The anchor value indicates which point of the text the positions refer to, so for example if the anchor is TOP_LEFT, the text will be positioned
     * in such a way that the top left of the text is at the given position. If the anchor is CENTER, the text will be centered on
     * the given position. This allows for more flexible positioning of the preview text.
     * The default geometry is centred on the display/drawing area (0.5, 0.5, Anchor::CENTER).
     * Added in version 5
     * @text setPreviewGeometry
     * @param sessionId Is the session
     * @example sessionId: 2
     * @param xPos Is the horizontal position (0..1) for the preview text
     * @example xPos: 0.5
     * @param yPos Is the vertical position (0..1) for the preview text
     * @example yPos: 0.5
     * @param anchor Indicates the anchor point of the preview text, i.e. which point of the text the positions refer to.
     * @example anchor: CENTER
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_GENERAL if the geometry could not be set
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult SetPreviewGeometry(const uint32_t sessionId, const float xPos /* @restrict:0.0..1.0 */, const float yPos /* @restrict:0.0..1.0 */, const Anchor anchor) { return Core::ERROR_NOT_SUPPORTED; }

    using ISubtitleFormatIterator = RPC::IIteratorType<SubtitleFormat, ID_TEXT_TRACK_SUBTITLE_FORMAT_ITERATOR>;

    /**
     * @brief Sets whether the global ClosedCaptionsStyle applies to a given session type.
     * @details When set to true, the global ClosedCaptionsStyle will be converted and applied to all sessions of the given type. The conversion
     * will be done according to the best effort conversion rules for the given type. When set to false, the global ClosedCaptionsStyle will not be applied.
     * Added in version 5
     * @text setClosedCaptionsStyleAppliesTo
     * @param format The session type to configure
     * @example format: CC
     * @param applies If true, the global ClosedCaptionsStyle applies to sessions of this type
     * @example applies: true
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_GENERAL if the session type is not supported
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult SetClosedCaptionsStyleAppliesTo(const SubtitleFormat format, const bool applies) { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Gets whether the global ClosedCaptionsStyle applies to a given session type.
     * @details Returns whether global caption styling is applied to sessions of this type. Added in version 5.
     * @text getClosedCaptionsStyleAppliesTo
     * @param format The session type to query
     * @example format: CC
     * @param applies On success, true if the global ClosedCaptionsStyle applies to sessions of this type
     * @example applies: true
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult GetClosedCaptionsStyleAppliesTo(const SubtitleFormat format, bool &applies /* @out */) const { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Gets the list of session types for which the global ClosedCaptionsStyle applies.
     * @details Added in version 5
     * @text getClosedCaptionsStyleAppliesToList
     * @param iterator On success, an iterator over the session types for which the global ClosedCaptionsStyle applies
     * @example iterator: [CC, TTML]
     * @retval Core::ERROR_NOT_SUPPORTED if the function is not implemented
     * @retval Core::ERROR_NONE on success
     */
    virtual Core::hresult GetClosedCaptionsStyleAppliesToList(ISubtitleFormatIterator *&iterator /* @out */) const { return Core::ERROR_NOT_SUPPORTED; }
};

} // namespace Exchange
} // namespace WPEFramework
