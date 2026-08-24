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

/* @json 1.0.0 @text:keep */
struct EXTERNAL IUserSettings : virtual public Core::IUnknown
{
    enum { ID = ID_USER_SETTINGS };

    // @event
    struct EXTERNAL INotification : virtual public Core::IUnknown
    {
        enum { ID = ID_USER_SETTINGS_NOTIFICATION };

        // Constructor
        INotification() {};

        // Destructor
        virtual ~INotification() {};

        // copy constructor
        INotification & operator=(const INotification &) = delete;

        // @text onAudioDescriptionChanged
        // @brief The AudioDescription setting has changed.
        // @details This event is triggered when the AudioDescription setting is updated. 
        // Applications can listen to this event to react to changes in the audio description preference.
        // @param enabled: audioDescription enabled or not
        // @example enabled: true
        virtual void OnAudioDescriptionChanged(const bool enabled) {};

        // @text onPreferredAudioLanguagesChanged
        // @brief The preferredLanguages setting has changed.
        // @details This event is triggered when the preferred audio languages setting is updated. 
        // @param preferredLanguages: the changed preferredLanguages.
        // @example preferredLanguages: ["en", "fr"]
        virtual void OnPreferredAudioLanguagesChanged(const string& preferredLanguages /* @text preferredLanguages */) {};

        // @text onPresentationLanguageChanged
        // @brief The PresentationLanguages setting has changed.
        // @details This event is triggered when the presentation language setting is updated. 
        // @param presentationLanguage: the changed presentationLanguage.
        // @example presentationLanguage: "en"
        virtual void OnPresentationLanguageChanged(const string& presentationLanguage /* @text presentationLanguage */) {};

        // @text onCaptionsChanged
        // @brief The Captions setting has changed.
        // @details This event is triggered when the Captions setting is updated. 
        // Applications can listen to this event to react to changes in the captions preference.
        // @param enabled: Captions enabled or not.
        // @example enabled: true
        virtual void OnCaptionsChanged(const bool enabled) {};

        // @text onPreferredCaptionsLanguagesChanged
        // @brief The PreferredCaptionsLanguages setting has changed.
        // @details This event is triggered when the preferred captions languages setting is updated. 
        // @param preferredLanguages: the changed preferredLanguages.
        // @example preferredLanguages: ["en", "fr"]
        virtual void OnPreferredCaptionsLanguagesChanged(const string& preferredLanguages /* @text preferredLanguages */) {};

        // @text onPreferredClosedCaptionServiceChanged
        // @brief The PreferredClosedCaptionService setting has changed.Eg: "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]".
        // @details This event is triggered when the preferred closed caption service setting is updated. 
        // @param service: the changed preferredClosedCaptionService.
        // @example service: "CC3"
        virtual void OnPreferredClosedCaptionServiceChanged(const string& service) {};

        // @text onPrivacyModeChanged
        // @brief The PrivacyMode setting has changed.
        // @details This event is triggered when the privacy mode setting is updated. 
        // @param privacyMode: "SHARE", "DO_NOT_SHARE".
        // @example privacyMode: "SHARE"
        virtual void OnPrivacyModeChanged(const string& privacyMode /* @text privacyMode */) {};

        // @alt onPinControlChanged
        // @brief The PinControl setting has changed.
        // @details This event is triggered when the pin control setting is updated.
        // @param pinControl: pinControl enabled or not.
        // @example pinControl: true
        virtual void OnPinControlChanged(const bool pinControl) {};

        // @text onViewingRestrictionsChanged
        // @brief The ViewingRestrictions setting has changed.
        // @details This event is triggered when the viewing restrictions setting is updated.
        // @param viewingRestrictions: the changed viewingRestrictions.
        // @example viewingRestrictions: "{\"scheme\":\"US_TV\",\"ratings\":[\"TV-14\"]}"
        virtual void OnViewingRestrictionsChanged(const string& viewingRestrictions /* @text viewingRestrictions */) {};

        // @text onViewingRestrictionsWindowChanged
        // @brief The ViewingRestrictionsWindow setting has changed.
        // @details This event is triggered when the viewing restrictions window setting is updated.
        // @param viewingRestrictionsWindow: the changed viewingRestrictionsWindow.
        // @example viewingRestrictionsWindow: "ALWAYS"
        virtual void OnViewingRestrictionsWindowChanged(const string& viewingRestrictionsWindow /* @text viewingRestrictionsWindow */) {};

        // @text onLiveWatershedChanged
        // @brief The LiveWatershed setting has changed.
        // @details This event is triggered when the live watershed setting is updated.
        // @param liveWatershed: liveWatershed enabled or not.
        // @example liveWatershed: true
        virtual void OnLiveWatershedChanged(const bool liveWatershed) {};

        // @text onPlaybackWatershedChanged
        // @brief The PlaybackWatershed setting has changed.
        // @details This event is triggered when the playback watershed setting is updated.
        // @param playbackWatershed: playbackWatershed enabled or not.
        // @example playbackWatershed: true
        virtual void OnPlaybackWatershedChanged(const bool playbackWatershed) {};

        // @text onBlockNotRatedContentChanged
        // @brief The BlockNotRatedContent setting has changed.
        // @details This event is triggered when the block not rated content setting is updated.
        // @param blockNotRatedContent: blockNotRatedContent enabled or not.
        // @example blockNotRatedContent: true
        virtual void OnBlockNotRatedContentChanged(const bool blockNotRatedContent) {};

        // @text onPinOnPurchaseChanged
        // @brief The PinOnPurchase setting has changed.
        // @details This event is triggered when the pin on purchase setting is updated.
        // @param pinOnPurchase: pinOnPurchase enabled or not.
        // @example pinOnPurchase: true
        virtual void OnPinOnPurchaseChanged(const bool pinOnPurchase) {};

        // @text onHighContrastChanged
        // @brief Triggered after the high contrast settings changes.
        // @param enabled: high contrast enabled or not.
        // @example enabled: true
        virtual void OnHighContrastChanged(const bool enabled) {};

        // @text onVoiceGuidanceChanged
        // @brief Triggered after the voice guidance enabled settings changes.
        // @details This event is triggered when the voice guidance setting is updated.
        // @param enabled: voice guidance enabled or not.
        // @example enabled: true
        virtual void OnVoiceGuidanceChanged(const bool enabled) {};

        // @text onVoiceGuidanceRateChanged
        // @brief Triggered after the voice guidance rate changed.
        // @details This event is triggered when the voice guidance rate setting is updated.
        // @param rate: the changed voice guidance rate.
        // @example rate: 1.5
        virtual void OnVoiceGuidanceRateChanged(const double rate) {};

        // @text onVoiceGuidanceHintsChanged
        // @brief Triggered after the voice guidance hints changes.
        // @details This event is triggered when the voice guidance hints setting is updated.
        // @param hints: voice guidance hints enabled or not.
        // @example hints: true
        virtual void OnVoiceGuidanceHintsChanged(const bool hints) {};

        // @text onContentPinChanged
        // @brief The ContentPin setting has changed.
        // @details This event is triggered when the content pin setting is updated.
        // @param contentPin: The changed contentPin.
        // @example contentPin: "1234"
        virtual void OnContentPinChanged(const string& contentPin) {};

    };

    virtual Core::hresult Register(Exchange::IUserSettings::INotification* notification ) = 0;
    virtual Core::hresult Unregister(Exchange::IUserSettings::INotification* notification ) = 0;

    // @text setAudioDescription
    // @brief Sets AudioDescription ON/OFF. Players should preferred Audio Descriptive tracks over normal audio track when enabled
    // @details Updates the persistent user preference for this setting. Changes are stored by the UserSettings service and may trigger the corresponding notification event so that applications can react to runtime configuration changes.
    // @param enabled: Enabled/Disabled
    // @example usersettings:SetAudioDescription(enabled);
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update the setting.
    virtual Core::hresult SetAudioDescription(const bool enabled ) = 0;

    // @text getAudioDescription
    // @brief Gets the current AudioDescription setting
    // @details Retrieves the persistent user preference for this setting.
    // @param enabled: Enabled/Disabled
    // @example usersettings:GetAudioDescription(enabled);
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve the setting
    virtual Core::hresult GetAudioDescription(bool &enabled /* @out */) const = 0;

    // @text setPreferredAudioLanguages
    // @brief A prioritized list of ISO 639-2/B codes for the preferred audio languages,
    // expressed as a comma separated lists of languages of zero of more elements.
    // The players will pick the audio track that has the best match compared with
    // this list. In the absence of a matching track, the player should by best
    // effort select the preferred audio track.
    // @details Stores the user's preferred audio language order. Media players
    // can use this preference to automatically select the most appropriate audio
    // track when multiple language tracks are available.
    // @param preferredLanguages: PreferredLanguages
    // @example preferredLanguages - "eng,fra,spa"
    // @example userSettings:SetPreferredAudioLanguages("eng,fra,spa");
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred audio languages updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update preferred audio languages.
    virtual Core::hresult SetPreferredAudioLanguages(const string& preferredLanguages  /* @text preferredLanguages */) = 0;

    // @text getPreferredAudioLanguages
    // @brief Gets the current PreferredAudioLanguages setting
    // @details Retrieves the persistent user preference for this setting.
    // @param preferredLanguages: PreferredLanguages
    // @example preferredLanguages - "eng,fra,spa"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred audio languages retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve preferred audio languages.
    virtual Core::hresult GetPreferredAudioLanguages(string &preferredLanguages /* @out @text preferredLanguages */) const = 0;

    // @text setPresentationLanguage
    // @brief Sets the presentationLanguage in a full BCP 47 value, including script, region, variant
    // @details Stores the user's preferred presentation language. Media players and applications
    // can use this preference to automatically select the most appropriate language for presentation.
    // @param presentationLanguage: Preferred presentation language.
    // @example presentationLanguage - "en-US", "es-US", "en-CA", "fr-CA"
    // @example userSettings:SetPresentationLanguage("en-US");
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Presentation language updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update presentation language.
    virtual Core::hresult SetPresentationLanguage(const string& presentationLanguage /* @text presentationLanguage */) = 0;

    // @text getPresentationLanguage
    // @brief Gets the presentationLanguage
    // @details Retrieves the user's preferred presentation language.
    // @param presentationLanguage: Preferred presentation language, e.g., "en-US", "es-US", "en-CA", "fr-CA"
    // @example presentationLanguage - "en-US"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Presentation language retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve presentation language.
    virtual Core::hresult GetPresentationLanguage(string &presentationLanguage /* @out @text presentationLanguage */) const = 0;

    // @text setCaptions
    // @brief brief Sets Captions ON/OFF.
    // @details A setting of ON indicates that Players should select a subtitle track for presentation
    // The Setting does not influence any running sessions. It is up to the player to enforce the setting.
    // This is a global state persisted by the TextTrack plug-in applying to all forms of text; closed captions, Captions
    // and timed text types.
    // Media players should to listen to OnCaptionsChanged notifications to react to platform wide dynamic state changes
    // of this state while a playback is active.
    // When media players start playback, they should also call the GetCaptions method to retrieve the current enabled state.
    // This holds true for media players that utilize TextTrack render sessions for text track decode-display and also for media
    // players or apps that decode-display internally 
    // @param enabled: Sets the state(Enables or disables captions globally)
    // @example enabled - true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Captions setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update captions setting.
    virtual Core::hresult SetCaptions(const bool enabled  ) = 0;

    // @text getCaptions
    // @brief Gets the Captions setting.
    // @details Retrieves the current captions preference configured in the
    // UserSettings service. A value of true indicates that captions should be
    // enabled by default when supported by the media being played.
    // @param enabled: Receives the state
    // @example enabled - true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Captions setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve captions setting.
    virtual Core::hresult GetCaptions(bool &enabled /* @out */) const = 0;

    // @text setPreferredCaptionsLanguages
    // @brief Set preferred languages for captions.
    // @details A prioritized list of ISO 639-2/B codes for the preferred Captions languages,
    // expressed as a comma separated lists of languages of zero of more elements.
    // The players will pick the subtitle track that has the best match compared with
    // this list. In the absence of a matching track, the player should by best
    // effort select the preferred subtitle track. 
    // @param preferredLanguages: Is the list to set (e.g. "eng,fra")
    // @example preferredLanguages - "eng,fra"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred captions languages updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update preferred captions languages.
    virtual Core::hresult SetPreferredCaptionsLanguages(const string& preferredLanguages  /* @text preferredLanguages */) = 0;

    // @text getPreferredCaptionsLanguages
    // @brief Gets the current PreferredCaptionsLanguages setting.
    // @details Retrieves the currently configured list of preferred caption
    // languages. Media players can use this list to select the most appropriate
    // subtitle or caption track when multiple language options are available.
    // @param preferredLanguages: Receives the list (e.g. "eng,fra")
    // @example preferredLanguages - "eng,fra"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred captions languages retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve preferred captions languages.
    virtual Core::hresult GetPreferredCaptionsLanguages(string &preferredLanguages /* @out @text preferredLanguages */) const = 0;

    // @text setPreferredClosedCaptionService
    // @brief Sets the PreferredClosedCaptionService.
    // @details The setting should be honored by the player. The behaviour of AUTO may be player specific.
    // Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]" 
    // @param service: Identifies the closed caption service to display.
    // @example service - "CC3"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred closed caption service updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update preferred closed caption service.
    virtual Core::hresult SetPreferredClosedCaptionService(const string& service  ) = 0;

    // @text getPreferredClosedCaptionService
    // @brief Gets the current PreferredClosedCaptionService setting.
    // @details Retrieves the currently configured preferred closed caption service.
    // @param service: Identifies the service to display e.g. "CC3".
    // @example service - "CC3"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Preferred closed caption service retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve preferred closed caption service.
    virtual Core::hresult GetPreferredClosedCaptionService(string &service /* @out */) const = 0;

    // @text setPrivacyMode
    // @brief Sets the PrivacyMode.
    // @details The setting should be honored by the Telemetry.
    // If privacyMode is "DO_NOT_SHARE", logs and crash report should not be uploaded.
    // @param privacyMode: Privacy mode preference.
    // @example privacyMode - "DO_NOT_SHARE"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Privacy mode updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update privacy mode.
    virtual Core::hresult SetPrivacyMode(const string& privacyMode /* @text privacyMode*/) = 0;

    // @text getPrivacyMode
    // @brief Gets the current PrivacyMode setting.
    // @details Retrieves the currently configured privacy mode.
    // @param privacyMode: Current privacy mode.
    // @example privacyMode - "SHARE"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Privacy mode retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve privacy mode.
    virtual Core::hresult GetPrivacyMode(string &privacyMode /* @out @text privacyMode */) const = 0;

    // @alt setPinControl
    // @brief Sets PinControl ON/OFF. Parental Control as a whole is enabled or disabled.
    // @details Enables or disables parental control functionality across the
    // platform. When disabled, parental-control related restrictions and PIN
    // validation requirements should not be enforced.
    // @param pinControl: Enabled/Disabled
    // @example pinControl : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Pin control setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update pin control setting.
    virtual Core::hresult SetPinControl(const bool pinControl ) = 0;

    // @text getPinControl
    // @brief Gets the PinControl setting
    // @details Retrieves whether parental controls are currently enabled.
    // @param pinControl - out - Current pin control setting.
    // @example pinControl : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Pin control setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve pin control setting.
    virtual Core::hresult GetPinControl(bool &pinControl /* @out */) const = 0;

    // @text setViewingRestrictions
    // @brief Sets the ViewingRestrictions.
    // @details A JSON document that describes the rating scheme(s) and ratings that are blocked. 
    // @param viewingRestrictions: A JSON document that describes the rating scheme(s) and ratings that are blocked.
    // @example viewingRestrictions - "{\"scheme\":\"US_*V\",\"ratings\":[\"TV-14\"]}"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Viewing restrictions updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update viewing restrictions.
    virtual Core::hresult SetViewingRestrictions(const string& viewingRestrictions /* @text viewingRestrictions */) = 0;

    // @text getViewingRestrictions
    // @brief Gets the current ViewingRestrictions.
    // @details Retrieves the current viewing restrictions.
    // @param viewingRestrictions: A JSON document that describes the rating scheme(s) and ratings that are blocked.
    // @example viewingRestrictions - "{\"scheme\":\"US_TV\",\"ratings\":[\"TV-14\"]}"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Viewing restrictions retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve viewing restrictions.
    virtual Core::hresult GetViewingRestrictions(string &viewingRestrictions /* @out @text viewingRestrictions */) const = 0;

    // @text setViewingRestrictionsWindow
    // @brief Sets the ViewingRestrictionsWindow.
    // @details A project-specific representation of the time interval when viewing
    // restrictions are to be applied, if applicable for the project
    // @param viewingRestrictionsWindow: A project-specific representation of the time interval.Eg: "ALWAYS"
    // @example viewingRestrictionsWindow - "ALWAYS"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Viewing restrictions window updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update viewing restrictions window.
    virtual Core::hresult SetViewingRestrictionsWindow(const string &viewingRestrictionsWindow /* @text viewingRestrictionsWindow */) = 0;

    // @text getViewingRestrictionsWindow
    // @brief Gets the current ViewingRestrictionsWindow.
    // @details Retrieves the current ViewingRestrictionsWindow.
    // @param viewingRestrictionsWindow: A project-specific representation of the time interval.Eg: "ALWAYS"
    // @example viewingRestrictionsWindow - "ALWAYS"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - Viewing restrictions window retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve viewing restrictions window.
    virtual Core::hresult GetViewingRestrictionsWindow(string &viewingRestrictionsWindow /* @out @text viewingRestrictionsWindow */) const = 0;

    // @text setLiveWatershed
    // @brief Sets LiveWatershed ON/OFF.Whether project-specific watershed rules
    // should be applied for live content, if applicable for the project.
    // @details Controls whether live content is subject to project-defined
    // watershed restrictions based on policy or regulatory requirements.
    // @param liveWatershed: Enabled/Disabled
    // @example liveWatershed : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - LiveWatershed setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update LiveWatershed setting.
    virtual Core::hresult SetLiveWatershed(const bool liveWatershed ) = 0;

    // @text getLiveWatershed
    // @brief Gets the LiveWatershed setting
    // @details Retrieves the current LiveWatershed setting.configuration. When enabled,
    // project-specific watershed rules are applied to live content according
    // to platform policy and regulatory requirements.
    // @param liveWatershed: Enabled/Disabled
    // @example liveWatershed : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - LiveWatershed setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve LiveWatershed setting.
    virtual Core::hresult GetLiveWatershed(bool &liveWatershed /* @out */) const = 0;

    // @text setPlaybackWatershed
    // @brief Sets PlaybackWatershed ON/OFF. Whether project-specific watershed rules
    // should be applied for non-live content, if applicable for the project.
    // @details Controls whether watershed restrictions are enforced for
    // recorded, on-demand, or other non-live content. The setting is persisted
    // by the UserSettings service and should be honored by content playback applications.
    // @param playbackWatershed: Enabled/Disabled
    // @example playbackWatershed : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - PlaybackWatershed setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update PlaybackWatershed setting.
    virtual Core::hresult SetPlaybackWatershed(const bool playbackWatershed ) = 0;

    // @text getPlaybackWatershed
    // @brief Gets the PlaybackWatershed setting
    // @details Retrieves the current PlaybackWatershed setting.
    // @param playbackWatershed: Enabled/Disabled
    // @example playbackWatershed : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - PlaybackWatershed setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve PlaybackWatershed setting.
    virtual Core::hresult GetPlaybackWatershed(bool &playbackWatershed /* @out */) const = 0;

    // @text setBlockNotRatedContent
    // @brief Sets BlockNotRatedContent ON/OFF. Whether content that is not rated should be
    // blocked, if applicable for the project.
    // @details Controls whether content that is not rated should be blocked.
    // @param blockNotRatedContent - in - Enables or disables blocking of not rated content.
    // @example blockNotRatedContent : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - BlockNotRatedContent setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update BlockNotRatedContent setting.
    virtual Core::hresult SetBlockNotRatedContent(const bool blockNotRatedContent ) = 0;

    // @text getBlockNotRatedContent
    // @brief Gets the BlockNotRatedContent setting
    // @details Retrieves the current BlockNotRatedContent setting.
    // @param blockNotRatedContent - out - Indicates whether blocking of not rated content is enabled.
    // @example blockNotRatedContent : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - BlockNotRatedContent setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve BlockNotRatedContent setting.
    virtual Core::hresult GetBlockNotRatedContent(bool &blockNotRatedContent /* @out */) const = 0;

    // @text setPinOnPurchase
    // @brief Sets PinOnPurchase ON/OFF.Whether a PIN challenge should be made
    // when a purchase is attempted.
    // @details Controls whether a PIN challenge should be made when a purchase is attempted.
    // @param pinOnPurchase - in - Enables or disables PIN challenge on purchase.
    // @example pinOnPurchase : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - PinOnPurchase setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update PinOnPurchase setting.
    virtual Core::hresult SetPinOnPurchase(const bool pinOnPurchase ) = 0;

    // @text getPinOnPurchase
    // @brief Gets the PinOnPurchase setting
    // @details Retrieves the current PinOnPurchase setting.
    // @param pinOnPurchase - out - Indicates whether PIN challenge on purchase is enabled.
    // @example pinOnPurchase : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - PinOnPurchase setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve PinOnPurchase setting.
    virtual Core::hresult GetPinOnPurchase(bool &pinOnPurchase /* @out */) const = 0;

    // @text setHighContrast
    // @brief Sets highContrast. Whether the app should display with high contrast or not.
    // @details Updates the user's high-contrast accessibility preference.
    // Applications should honor this setting by presenting content with
    // enhanced contrast to improve readability and visibility.
    // @param enabled - in - Enables or disables high contrast mode.
    // @example enabled : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - HighContrast setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update HighContrast setting.
    virtual Core::hresult SetHighContrast(const bool enabled ) = 0;

    // @text getHighContrast
    // @brief Gets the current highContrast setting.
    // @details Retrieves the current high-contrast accessibility preference.
    // @param enabled - out - Indicates whether high contrast mode is enabled.
    // @example enabled : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - HighContrast setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve HighContrast setting.
    virtual Core::hresult GetHighContrast(bool &enabled /* @out */) const = 0;

    // @text setVoiceGuidance
    // @brief Sets voiceGuidance. Whether Voice Guidance is enabled or not.
    // @details Updates the user's voice guidance accessibility preference.
    // When enabled, applications and platform components can provide spoken
    // guidance and navigation assistance for visually impaired users.
    // @param enabled - in - Enables or disables voice guidance.
    // @example enabled : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidance setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update VoiceGuidance setting.
    virtual Core::hresult SetVoiceGuidance(const bool enabled ) = 0;

    // @text getVoiceGuidance
    // @brief Gets the current voiceGuidance setting.
    // @details Retrieves the current voice guidance accessibility preference.
    // @param enabled - out - Indicates whether voice guidance is enabled.
    // @example enabled : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidance setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve VoiceGuidance setting.
    virtual Core::hresult GetVoiceGuidance(bool &enabled /* @out */) const = 0;

    // @text setVoiceGuidanceRate
    // @brief Sets voiceGuidanceRate. Setting voice guidance rate value. from 0.1 to 10 inclusive.
    // @details Updates the user's voice guidance rate preference.
    // @param rate - in - Sets Voice Guidance rate. Valid range is 0.1 to 10 inclusive.
    // @example rate : 1.5
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidanceRate setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update VoiceGuidanceRate setting.
    virtual Core::hresult SetVoiceGuidanceRate(const double rate ) = 0;

    // @text getVoiceGuidanceRate
    // @brief Gets the current voiceGuidanceRate setting.
    // @details Retrieves the current voice guidance rate preference.
    // @param rate - out - Gets Voice Guidance rate.
    // @example rate : 1.5
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidanceRate setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve VoiceGuidanceRate setting.
    virtual Core::hresult GetVoiceGuidanceRate(double &rate /* @out */) const = 0;

    // @text setVoiceGuidanceHints
    // @brief Sets voiceGuidanceHints ON/OFF. Whether Voice Guidance hints setting is switched on or not.
    // @details Updates the user's voice guidance hints preference.
    // @param hints - in - Enables or disables voice guidance hints.
    // @example hints : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidanceHints setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update VoiceGuidanceHints setting.
    virtual Core::hresult SetVoiceGuidanceHints(const bool hints ) = 0;

    // @text getVoiceGuidanceHints
    // @brief Gets the current voiceGuidanceHints setting.
    // @details Retrieves the current voice guidance hints preference.
    // @param hints - out - Indicates whether voice guidance hints are enabled.
    // @example hints : true
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - VoiceGuidanceHints setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve VoiceGuidanceHints setting.
    virtual Core::hresult GetVoiceGuidanceHints(bool &hints /* @out */) const = 0;

    // @text setContentPin
    // @brief Sets the ContentPin.
    // @details ContentPin is a string of four decimal digits that represents the PIN code which is used to unlock access to restricted AV content.
    // @param contentPin - in - A string of four decimal digits that represents the content PIN.
    // @example contentPin : "1234"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - ContentPin setting updated successfully.
    // @retval Core::ERROR_GENERAL - Failed to update ContentPin setting. 
    virtual Core::hresult SetContentPin(const string& contentPin) = 0;

    // @text getContentPin
    // @brief Gets the ContentPin.
    // @details Retrieves the currently configured content PIN used to control
    // access to restricted content. The PIN is represented as a string of four
    // decimal digits and is used by parental control features to authorize
    // access to protected content.
    // @param contentPin - out - A string of four decimal digits that represents the content PIN.
    // @example contentPin : "1234"
    // @param success: Indicates whether the operation was successful
    // @example success: true
    // @retval Core::ERROR_NONE - ContentPin setting retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve ContentPin setting.
    virtual Core::hresult GetContentPin(string& contentPin /* @out */) const = 0;

};

/**
 * If a setting was owned by an other component prior to being migrated into UserSettings,
 * we require the ability to detect when this migration has completed.
 * The component which was the previous owner of a given setting has the responsibility
 * to always set the setting on UserSettings interface (During migration AND during first time install).
 * Until this is done the setting is not considered valid, meaning the the MigrationState will contain requiresMigration=true
 * All settings not requiring migration would immediately be valid.
 */

/* @json 1.0.0 @text:keep */
struct EXTERNAL IUserSettingsInspector : virtual public Core::IUnknown
{
    enum { ID = ID_USER_SETTINGS_INSPECTOR };

    ~IUserSettingsInspector() override = default;

    enum SettingsKey : uint32_t
    {
        PREFERRED_AUDIO_LANGUAGES = 1,
        AUDIO_DESCRIPTION = 2,
        CAPTIONS = 3,
        PREFERRED_CAPTIONS_LANGUAGES = 4,
        PREFERRED_CLOSED_CAPTION_SERVICE = 5,
        PRESENTATION_LANGUAGE = 6,
        HIGH_CONTRAST = 7,
        PIN_CONTROL = 8,
        VIEWING_RESTRICTIONS = 9,
        VIEWING_RESTRICTIONS_WINDOW = 10,
        LIVE_WATERSHED = 11,
        PLAYBACK_WATERSHED = 12,
        BLOCK_NOT_RATED_CONTENT = 13,
        PIN_ON_PURCHASE = 14,
        VOICE_GUIDANCE = 15,
        VOICE_GUIDANCE_RATE = 16,
        VOICE_GUIDANCE_HINTS = 17,
        CONTENT_PIN = 18,
        PRIVACY_MODE = 19
    };

    struct SettingsMigrationState
    {
        SettingsKey key;
        bool requiresMigration;
    };

    using IUserSettingsMigrationStateIterator = RPC::IIteratorType<SettingsMigrationState, ID_USER_SETTINGS_MIGRATION_STATE_ITERATOR>;

    /** Get the migration state of the respective key */
    // @text getMigrationState
    // @brief Get the migration state of the respective keys
    // @details Retrieves the migration status for a specific UserSettings key. A setting requires migration when its value has not yet been transferred from its previous owner into the UserSettings service. Until migration is complete, the setting is not considered valid.
    // @param key: one of UserSettingsKey
    // @example key - AUDIO_DESCRIPTION
    // @param requiresMigration - out - Indicates whether the setting still requires migration.
    // @example requiresMigration : false
    // @retval Core::ERROR_NONE - Migration state retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve migration state.
    virtual Core::hresult GetMigrationState(const SettingsKey key, bool &requiresMigration /* @out */) const = 0;

    /** Get the migration state of all the defined keys */
    // @text getMigrationStates
    // @brief Get the migration state of all the defined keys
    // @details Retrieves migration status information for all UserSettings keys supported by the platform. Each returned entry contains the setting key and an indication of whether migration is still required.
    // @param states: array of migration status.
    // @example states[0].requiresMigration - false
    // @retval Core::ERROR_NONE - Migration states retrieved successfully.
    // @retval Core::ERROR_GENERAL - Failed to retrieve migration states.
    virtual Core::hresult GetMigrationStates(IUserSettingsMigrationStateIterator*& states /* @out */) const = 0;

};

} // namespace Exchange
} // namespace WPEFramework

