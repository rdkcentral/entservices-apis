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

#define ITEXTTRACK_VERSION 4

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
         * @text onClosedCaptionsStyleChanged
         */
        virtual void OnClosedCaptionsStyleChanged(const ClosedCaptionsStyle &style) = 0; // Works with ThunderTools >= 4.4.3

        /**
         * @brief Notify fontFamily Changed
         * @text onFontFamilyChanged
         */
        virtual void OnFontFamilyChanged(const FontFamily font) {};
        /**
         * @brief Notify fontSize Changed
         * @text onFontSizeChanged
         */
        virtual void OnFontSizeChanged(const FontSize size) {};
        /**
         * @brief Notify fontColor Changed
         * @text onFontColorChanged
         */
        virtual void OnFontColorChanged(const string &color) {};
        /**
         * @brief Notify fontOpacity Changed
         * @text onFontOpacityChanged
         */
        virtual void OnFontOpacityChanged(const int8_t opacity) {};
        /**
         * @brief Notify fontEdge Changed
         * @text onFontEdgeChanged
         */
        virtual void OnFontEdgeChanged(const FontEdge edge) {};
        /**
         * @brief Notify fontEdgeColor Changed
         * @text onFontEdgeColorChanged
         */
        virtual void OnFontEdgeColorChanged(const string &color) {};
        /**
         * @brief Notify backgroundColor Changed
         * @text onBackgroundColorChanged
         */
        virtual void OnBackgroundColorChanged(const string &color) {};
        /**
         * @brief Notify backgroundOpacity Changed
         * @text onBackgroundOpacityChanged
         */
        virtual void OnBackgroundOpacityChanged(const int8_t opacity) {};
        /**
         * @brief Notify windowColor Changed
         * @text onWindowColorChanged
         */
        virtual void OnWindowColorChanged(const string &color) {};
        /**
         * @brief Notify windowOpacity Changed
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
     * @text setClosedCaptionsStyle
     */
    virtual Core::hresult SetClosedCaptionsStyle(const ClosedCaptionsStyle &style) = 0;
    /**
     * @brief Gets the current ClosedCaptionsStyle settings.
     * @text getClosedCaptionsStyle
     */
    virtual Core::hresult GetClosedCaptionsStyle(ClosedCaptionsStyle &style /* @out */) const = 0;

    /**
     * @{
     * @group Individual getter and setter Methods to facilitate easier Firebolt mapping
     */

    /**
     * @brief Setter for FontFamily
     * @text setFontFamily
     */
    virtual Core::hresult SetFontFamily(const FontFamily font) = 0;
    /**
     * @brief Getter for FontFamily
     * @text getFontFamily
     */
    virtual Core::hresult GetFontFamily(FontFamily &font /* @out */) const = 0;

    /**
     * @brief Setter for FontSize
     * @text setFontSize
     */
    virtual Core::hresult SetFontSize(const FontSize size) = 0;
    /**
     * @brief Getter for FontSize
     * @text getFontSize
     */
    virtual Core::hresult GetFontSize(FontSize &size /* @out */) const = 0;
    /**
     * @brief Setter for FontColor
     * @text setFontColor
     */
    virtual Core::hresult SetFontColor(const string &color) = 0;

    /**
     * @brief Getter for FontColor
     * @text getFontColor
     */
    virtual Core::hresult GetFontColor(string &color /* @out */) const = 0;
    /**
     * @brief Setter for FontOpacity
     * @text setFontOpacity
     */
    virtual Core::hresult SetFontOpacity(const int8_t opacity) = 0;

    /**
     * @brief Getter for FontOpacity
     * @text getFontOpacity
     */
    virtual Core::hresult GetFontOpacity(int8_t &opacity /* @out */) const = 0;
    /**
     * @brief Setter for FontEdge
     * @text setFontEdge
     */
    virtual Core::hresult SetFontEdge(const FontEdge edge) = 0;
    /**
     * @brief Getter for FontEdge
     * @text getFontEdge
     */
    virtual Core::hresult GetFontEdge(FontEdge &edge /* @out */) const = 0;

    /**
     * @brief Setter for FontEdgeColor
     * @text setFontEdgeColor
     */
    virtual Core::hresult SetFontEdgeColor(const string &color) = 0;
    /**
     * @brief Getter for FontEdgeColor
     * @text getFontEdgeColor
     */
    virtual Core::hresult GetFontEdgeColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for BackgroundColor
     * @text setBackgroundColor
     */
    virtual Core::hresult SetBackgroundColor(const string &color) = 0;
    /**
     * @brief Getter for BackgroundColor
     * @text getBackgroundColor
     */
    virtual Core::hresult GetBackgroundColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for BackgroundOpacity
     * @text setBackgroundOpacity
     */
    virtual Core::hresult SetBackgroundOpacity(const int8_t opacity) = 0;
    /**
     * @brief Getter for BackgroundOpacity
     * @text getBackgroundOpacity
     */
    virtual Core::hresult GetBackgroundOpacity(int8_t &opacity /* @out */) const = 0;

    /**
     * @brief Setter for WindowColor
     * @text setWindowColor
     */
    virtual Core::hresult SetWindowColor(const string &color) = 0;
    /**
     * @brief Getter for WindowColor
     * @text getWindowColor
     */
    virtual Core::hresult GetWindowColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for WindowOpacity
     * @text setWindowOpacity
     */
    virtual Core::hresult SetWindowOpacity(const int8_t opacity) = 0;
    /**
     * @brief Getter for WindowOpacity
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
         * @text onTtmlStyleOverridesChanged
         */
        virtual void OnTtmlStyleOverridesChanged(const string &style) {};
    };

    /** Register notification interface.
     * The callback will be called with the current settings.
     */
    virtual Core::hresult Register(INotification *notification) = 0;
    /** Unregister notification interface */
    virtual Core::hresult Unregister(const INotification *notification) = 0;

    /**
     * @brief Sets global TTML override style.
     * @details The styles given here (as "attr:value;attr:value") will be applied last to TTML sessions, meaning
     * that they will override styles given in the content.
     * The value will be persisted in the system.
     * The style setting will take effect immediately in all running (TTML) sessions, which has not applied a custom style.
     * @param style Contains the chosen override for styles
     * @text setTtmlStyleOverrides
     */
    virtual Core::hresult SetTtmlStyleOverrides(const string& style) = 0;

    /**
     * @brief Gets the global TTML style overrides
     * @param style will receive the style overrides
     * @text getTtmlStyleOverrides
     */
    virtual Core::hresult GetTtmlStyleOverrides(string& style /* @out */) const = 0;

};

/*
    This is the COM-RPC interface for handling TextTrack sessions.
*/
/* @json 1.4.0 @text:keep */
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

    // Sessions
    /**
     * @brief Opens a new renderSession.
     * @details If a session is already running on the supplied displayHandle, the sessionId for this session is
     * returned. If the session is instead newly opened, the session type is not set and display is muted. Use one
     * of the "selection" functions to select a session type, and UnMuteSession() to get subtitles displayed.
     * @param displayHandle is an encoding of the wayland display name
     * @param sessionId On success the returned session id
     * @text openSession
     */
    virtual Core::hresult OpenSession(const string &displayHandle, uint32_t &sessionId /* @out */) = 0;
    /**
     * @brief Closes a previously opened render session.
     * @details Any created windows and surfaces is destroyed
     * @param sessionId Is the session to close
     * @text closeSession
     */
    virtual Core::hresult CloseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resets a previously opened render session back to its opened state.
     * @details The state will be like after calling OpenSession()
     * @param sessionId Is the session to reset
     * @text resetSession
     */
    virtual Core::hresult ResetSession(const uint32_t sessionId) = 0;
    /**
     * @brief Pauses a render session.
     * @details Any text rendered remains on screen and any text due to be rendered soon
     * is held until the render session is resumed.
     * @param sessionId Is the session
     * @text pauseSession
     */
    virtual Core::hresult PauseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resumed a paused session
     * @param sessionId Is the session
     * @text resumeSession
     */
    virtual Core::hresult ResumeSession(const uint32_t sessionId) = 0;
    /**
     * @brief Mute will hide rendering of Captions
     * @param sessionId Is the session
     * @text muteSession
     */
    virtual Core::hresult MuteSession(const uint32_t sessionId) = 0;
    /**
     * @brief UnMute will unhide the rendering of Captions.
     * @details A newly created session is muted and should be unmuted to me visible
     * @param sessionId Is the session
     * @text unMuteSession
     */
    virtual Core::hresult UnMuteSession(const uint32_t sessionId) = 0;

    /**
     * @brief Sends data of Closed Captions, Captions or Timed Text data to a render session.
     * @param sessionId Is the session
     * @param type Is the type of data
     * @param displayOffsetMs Is currently unused
     * @param data Is the data to display, properly formatted as per the expectations of the type used
     * @text sendSessionData
     */
    virtual Core::hresult SendSessionData(const uint32_t sessionId, const DataType type, const int64_t displayOffsetMs, const string &data) = 0;
    /**
     * @brief Sends the current timestamp from a media player to a render session.
     * @details The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.
     * @param sessionId Is the session
     * @param mediaTimestampMs Is a timestamp
     * @text sendSessionTimestamp
     */
    virtual Core::hresult SendSessionTimestamp(const uint32_t sessionId, const uint64_t mediaTimestampMs) = 0;

    /**
     * @brief  Applies a custom ClosedCaptionsStyle on a single session.
     * @details When a custom style is applied on a specific session we will not update the style for this session if the global style setting change.
     * The style setting will take effect immediately.
     * @param sessionId Is the session as returned in the ITextTrack interface.
     * @param style Contains the chosen styles
     * @json:omit
     * @text applyCustomClosedCaptionsStyleToSession
     */
    virtual Core::hresult ApplyCustomClosedCaptionsStyleToSession(const uint32_t sessionId, const ITextTrackClosedCaptionsStyle::ClosedCaptionsStyle &style) = 0;

    /**
     * @brief Sets a static text in the display for preview purposes.
     * @details The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.
     * @param text Is the text to display
     * @returns Core::ERROR_OK if preview is shown
     * @returns Core::ERROR_NOT_SUPPORTED if preview is not supported
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
     * @param service Identifies the service to display e.g. "CC3"
     * @text setSessionClosedCaptionsService
     */
    virtual Core::hresult SetSessionClosedCaptionsService(const uint32_t sessionId, const string &service) = 0;
    /**
     * @brief Set the render session into Teletext mode, providing the teletext caption page for presentation
     * @param sessionId Is the session
     * @param page The user selected teletext caption page 100-899
     * @text setSessionTeletextSelection
     */
    virtual Core::hresult SetSessionTeletextSelection(const uint32_t sessionId, const uint16_t page) = 0;
    /**
     * @brief Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)
     * @param sessionId Is the session
     * @param compositionPageId Is the one Id
     * @param ancillaryPageId Is the other Id
     * @text setSessionDvbSubtitleSelection
     */
    virtual Core::hresult SetSessionDvbSubtitleSelection(const uint32_t sessionId, const uint16_t compositionPageId, const uint16_t ancillaryPageId) = 0;
    /**
     * @brief Set the render session into WebVTT mode
     * @param sessionId Is the session
     * @text setSessionWebVTTSelection
     */
    virtual Core::hresult SetSessionWebVTTSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into TTML mode
     * @param sessionId Is the session
     * @text setSessionTTMLSelection
     */
    virtual Core::hresult SetSessionTTMLSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into SCTE mode
     * @param sessionId Is the session
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
     * @param style Contains the list of styles to be overridden
     * @text applyCustomTtmlStyleOverridesToSession
     */
    virtual Core::hresult ApplyCustomTtmlStyleOverridesToSession(const uint32_t sessionId, const string &style) { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Associate a video decoder with the given session
     * @details This will ask TextTrack to subscribe to Closed Captions data from the decoder and display
     * these in the given session. Depending on the support on the platform, this may not be possible to do.
     * The assocation is active until CloseSession() or ResetSession() is called, and can also be
     * cancelled by calling AssociateVideoDecoder() with an empty string for handle.
     * After associating the video decoder, further calls to SendSessionData will be ignored.
     * Added in version 3
     * @param sessionId is the session
     * @param handle is a textual representation of the video decoder handle
     * @text associateVideoDecoder
     * @returns ERROR_NOT_SUPPORTED if the function is not implemented
     * @returns ERROR_GENERAL if the association failed (whether bad handle is used or lack of support on the platform).
     * @returns ERROR_OK on success
     */
    virtual Core::hresult AssociateVideoDecoder(const uint32_t sessionId, const string &handle) { return Core::ERROR_NOT_SUPPORTED; }

    /**
     * @brief Return the interface version implemented
     * @details This allows to query the running plugin for the version of the interface
     * it was compiled to support. This information can be helpful in determining whether
     * a certain functionality can be expected to be present.
     * Added in version 4
     * @param version will receive the version number
     * @text getInterfaceVersion
     * @returns ERROR_NOT_SUPPORTED if the function is not implemented
     * @returns ERROR_OK on success
     */
    virtual Core::hresult GetInterfaceVersion(uint32_t& version /* @out */) { return Core::ERROR_NOT_SUPPORTED; }
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
        UNSET = 0 /* @text UNSET */, //< Filler
        FIREBOLT_MIGRATION = 1 /* @text FIREBOLT_MIGRATION */, //< Have the CC style settings from Firebolt been migrated into TextTrack?
    };

    using IIterator = RPC::IIteratorType<Capability, RPC::ID_VALUEITERATOR>;

    /**
     * @text getCapability
     * @brief Queries whether a specific text track capability is supported by the implementation.
     * @param capability: The capability to query.
     * @param hasCapability: Indicates whether the queried capability is supported.
     * @retval Core::ERROR_NONE: The capability query completed successfully.
     * @retval Core::ERROR_UNAVAILABLE: The capability information is not available.
     * @retval Core::ERROR_NOT_SUPPORTED: Capability querying is not supported.
     */
    virtual Core::hresult GetCapability(Capability capability, bool &hasCapability /* @out */) = 0;

    /**
     * @text getCapabilities
     * @brief Retrieves an iterator over all supported text track capabilities.
     * @param capabilities: Iterator providing the list of supported capabilities.
     * @retval Core::ERROR_NONE: The list of capabilities was retrieved successfully.
     * @retval Core::ERROR_UNAVAILABLE: The list of capabilities is not available.
     * @retval Core::ERROR_NOT_SUPPORTED: Retrieving capabilities is not supported.
     */
    virtual Core::hresult GetCapabilities(IIterator *&capabilities /* @out */) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
